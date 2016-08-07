/**
  * \file PlnrcmbdAppsrv.cpp
  * application server for Plnr combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnrcmbd.h"

#include "PlnrcmbdAppsrv.h"

/******************************************************************************
 namespace PlnrcmbdAppsrv
 ******************************************************************************/

MHD_Daemon* PlnrcmbdAppsrv::start(
			XchgPlnrcmbd* xchg
		) {
//	return MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, xchg->stgplnrcmbd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_THREAD_POOL_SIZE, 16, MHD_OPTION_END);
	return MHD_start_daemon(MHD_USE_THREAD_PER_CONNECTION, xchg->stgplnrcmbd.appsrvport, &MhdAccept, (void*) xchg, &MhdCallback, (void*) xchg, MHD_OPTION_NOTIFY_COMPLETED, &MhdComplete, (void*) xchg, MHD_OPTION_END);
};

void PlnrcmbdAppsrv::stop(
			MHD_Daemon* d
		) {
	MHD_stop_daemon(d);
};

int PlnrcmbdAppsrv::MhdAccept(
			void* cls
			, const sockaddr* addr
			, socklen_t addrlen
		) {
	return MHD_YES;
};

int PlnrcmbdAppsrv::MhdCallback(
			void* cls
			, MHD_Connection* connection
			, const char* url
			, const char* method
			, const char* version
			, const char* upload_data
			, size_t* upload_data_size
			, void** con_cls
		) {
	XchgPlnr* xchg = (XchgPlnr*) cls;

  MHD_Response* response;
	int retval = MHD_YES;

	ReqPlnr* req;
	uint ixVBasetype = ReqPlnr::VecVBasetype::NONE;

	sockaddr* addr;

	string ip;
#ifndef _WIN32
	char ipstr[64];
#endif

	string mimetype;
	size_t ptr;

	timeval now;
	timespec nexttime;

	uint ixPlnrVDpch;

	DcolPlnr* dcol;

	char empty[] = "\n";
	char invalid[] = "<html><head><title>Invalid request</title></head><body><p>Invalid request!</p></body></html>";

	string s, s2;

	bool valid;

	if (*con_cls == NULL) {
		// new request
		s = string(url);

		if (strcmp(method, "GET") == 0) {
			// cout << "have GET request, url is '" << s << "'" << endl;

			if (s.find("/web/") != string::npos) {
				// cout << "request for '" << s.substr(4) << "' by html transfer" << endl;

				// ex. "/html/CrdPlnrNav/CrdPlnrNav.html" ; note that eventual parameters such as "?scrJref=abcd1234efgh5678" are not included in url

				// inhibit requests to ../ directories
				if (s.find("../") == string::npos) {

					// check if file exists
					s2 = xchg->stgplnrpath.webpath + s.substr(4);
					if (access(s2.c_str(), R_OK) == 0) {
						ixVBasetype = ReqPlnr::VecVBasetype::WEB;
						// cout << "MhdCallback() HTML request for '" << s2 << "'" << endl;
					};
				};

			} else if (s.find("/notify") != string::npos) {
				// always "/notify/abcd1234efgh5678/..."
				ixVBasetype = ReqPlnr::VecVBasetype::NOTIFY;

			} else if (s.find("/poll") != string::npos) {
				// always "/poll/abcd1234efgh5678/..."
				ixVBasetype = ReqPlnr::VecVBasetype::POLL;

			} else if (s.find("/download/") != string::npos) {
				// ex. "/download/abcd1234efgh5678/..."
				ixVBasetype = ReqPlnr::VecVBasetype::DOWNLOAD;
			};

		} else if (strcmp(method, "POST") == 0) {
			if (s.find("/dpch") != string::npos) {
				// always "/dpch"
				ixVBasetype = ReqPlnr::VecVBasetype::REGULAR;

			} else if (s.find("/upload/") != string::npos) {
				// ex. "/upload/abcd1234efgh5678"
				ixVBasetype = ReqPlnr::VecVBasetype::UPLOAD;
			};
		};

		if (ixVBasetype == ReqPlnr::VecVBasetype::NONE) {
			// not a valid request
			response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
			//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
			retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
			MHD_destroy_response(response);

		} else {
			addr = MHD_get_connection_info(connection, MHD_CONNECTION_INFO_CLIENT_ADDRESS)->client_addr;

			if (addr->sa_family == AF_INET) {
#ifdef _WIN32
				ip = inet_ntoa(((sockaddr_in*)addr)->sin_addr);
#else
				inet_ntop(AF_INET, &(((sockaddr_in*)addr)->sin_addr), ipstr, 64);
				ip = ipstr;
#endif
			};

			req = new ReqPlnr(ixVBasetype, ReqPlnr::VecVState::RECEIVE, ip);

			*con_cls = req;

			if (req->ixVBasetype == ReqPlnr::VecVBasetype::WEB) {
				// --- open file and initiate transmission
				req->filename = xchg->stgplnrpath.webpath + s.substr(4);

				req->file = new fstream();
				req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

				// get file length
				req->file->seekg(0, ios::end);
				req->filelen = req->file->tellg();
				req->file->seekg(0, ios::beg);

				if (req->filelen == 0) {
					// empty files require special handling
					response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);

				} else {
					response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);

					// determine MIME type from file extension
					ptr = req->filename.rfind('.');
					if (ptr != string::npos) mimetype = VecPlnrVMimetype::getTitle(VecPlnrVMimetype::getIx(req->filename.substr(ptr+1)));
					if (mimetype.length() == 0) mimetype = VecPlnrVMimetype::getTitle(VecPlnrVMimetype::TXT);
					MHD_add_response_header(response, "Content-Type", mimetype.c_str());					

					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
				// --- prepare POST processor
				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::NOTIFY) {
				// --- notify on dispatch in dispatch collector
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/notify/")+8));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixPlnrVLocale = dcol->ixPlnrVLocale;

					if (dcol->dpchs.empty()) {
						if (dcol->hot) {
							// send default reply immediately
							req->dpcheng = new DpchEngPlnrAck(req->jref);

							dcol->hot = false;
							dcol->unlockAccess("PlnrcmbdAppsrv", "MhdCallback[1]");

						} else if (!validateJrefNotify(xchg, req, false)) {
							// ask client to resort to POLL mode
							req->dpcheng = new DpchEngPlnrSuspend(req->jref);

							dcol->unlockAccess("PlnrcmbdAppsrv", "MhdCallback[2]");

						} else {
							// wait for next notification to arrive in dispatch collector
							
							// default req->dpcheng to be overwritten
							req->dpcheng = new DpchEngPlnrAck(req->jref);
							dcol->req = req;

							gettimeofday(&now, NULL);
							nexttime.tv_sec = now.tv_sec + 15;
							nexttime.tv_nsec = 1000*now.tv_usec;

							// note: when dcol with req != NULL is deleted, req->cReady will be broadcast
							Mutex::lock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[1]");
							dcol->unlockAccess("PlnrcmbdAppsrv", "MhdCallback[3]");
							Cond::timedwait(&(req->cReady), &(req->mcReady), &nexttime, "req->cReady", "PlnrcmbdAppsrv", "MhdCallback");
							// cout << "got one after timedwait" << endl;
							Mutex::unlock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[1]");

							dcol = xchg->getDcolByJref(req->jref);
							if (dcol) {
								// note: the destructor of dcol is called after dcol is removed from the list from which it can be found by getDcolByJref()
								dcol->req = NULL;
								dcol->unlockAccess("PlnrcmbdAppsrv", "MhdCallback[4]");

							} else {
								delete req->dpcheng;
								req->dpcheng = new DpchEngPlnrConfirm(false, req->jref);
							};
						};

						writeDpchEng(xchg, req);
						req->ixVState = ReqPlnr::VecVState::REPLY;

						// send reply ; note that the result of Cond::timedwait() doesn't matter
						response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;

						dcol->hot = true;
						dcol->unlockAccess("PlnrcmbdAppsrv", "MhdCallback[5]");

						writeDpchEng(xchg, req);
						req->ixVState = ReqPlnr::VecVState::REPLY;

						// send first dispatch available in dispatch collector
						response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::POLL) {
				// --- send first dispatch available in dispatch collector
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/poll/")+6));
				valid = (req->jref != 0);

				if (valid) valid = validateIp(xchg, req);

				if (valid) {
					dcol = xchg->getDcolByJref(req->jref);
					if (!dcol) dcol = xchg->addDcol(req->jref);

					valid = dcol;
				};

				if (valid) {
					req->ixPlnrVLocale = dcol->ixPlnrVLocale;
					dcol->hot = false;

					if (dcol->dpchs.empty()) {
						// send default reply
						req->dpcheng = new DpchEngPlnrAck(req->jref);

					} else {
						req->dpcheng = xchg->pullFirstDpch(dcol);
						// cout << "pulled one" << endl;
					};

					dcol->unlockAccess("PlnrcmbdAppsrv", "MhdCallback[6]");

					writeDpchEng(xchg, req);
					req->ixVState = ReqPlnr::VecVState::REPLY;

					// send reply
					response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
					retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
					MHD_destroy_response(response);
				};

				if (!valid) {
					response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::UPLOAD) {
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/upload/")+8));

				// generate file in tmp directory, and open it
				req->filename = xchg->stgplnrpath.tmppath + "/" + Tmp::newfile(xchg->stgplnrpath.tmppath, "");

				req->pp = MHD_create_post_processor(connection, 8*1024, MhdPostrecv, req);

			} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::DOWNLOAD) {
				// --- pass request to jobprc, to ask for filename in tmp directory ; then proceed sending - same procedure as for HTML
				req->jref = Scr::descramble(&(xchg->mScr), xchg->descr, s.substr(s.find("/download/")+10));
				valid = validateIp(xchg, req);

				if (valid) {
					validateJrefNotify(xchg, req, true);

					xchg->addReq(req);

					// wait for reply
					Mutex::lock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[2]");
					Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "PlnrcmbdAppsrv", "MhdCallback[1]");
					Mutex::unlock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[2]");

					// cout << "preparing '" << req->filename << "' for download transfer" << endl;

					valid = (access(req->filename.c_str(), R_OK) == 0);
				};

				if (valid) {
					req->file = new fstream();
					req->file->open(req->filename.c_str(), fstream::in | fstream::binary);

					// get file length
					req->file->seekg(0, ios::end);
					req->filelen = req->file->tellg();
					req->file->seekg(0, ios::beg);

					if (req->filelen == 0) {
						// empty files require special handling
						response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);

					} else {
						response = MHD_create_response_from_callback(req->filelen, 8*1024, &MhdFilesend, req, NULL);
						//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
						retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
						MHD_destroy_response(response);
					};
				};

				if (!valid) {
					response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
					//MHD_add_response_header(response, MHD_HTTP_HEADER_CONNECTION, "close");
					retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
					MHD_destroy_response(response);
				};
			};
		};

	} else {
		// active/old request (GET: should not go through here ; POST: REGULAR, UPLOAD)
		req = (ReqPlnr*) *con_cls;

		if (strcmp(method, "POST") == 0) {
			if (*upload_data_size != 0) {
				MHD_post_process(req->pp, upload_data, *upload_data_size);
				*upload_data_size = 0;

			} else {
				// POST done
				if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
					// --- read dispatch, pass on to job processor, and wait for reply to be transmitted
					// cout << "MhdCallback() REGULAR request complete" << endl;
					valid = req->request;
					
					if (valid) {
						//cout << req->request << endl;
						ixPlnrVDpch = readDpchApp(xchg, req);
						valid = req->dpchapp;
					};

					if (valid) {
						req->jref = req->dpchapp->jref;
						valid = validateIp(xchg, req);

						if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPROOTPLNRLOGIN) req->jref = xchg->jrefRoot;
					};

					if (valid) {
						validateJrefNotify(xchg, req, true);

						xchg->addReq(req);

						// wait for reply
						Mutex::lock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[3]");
						if (req->ixVState != ReqPlnr::VecVState::REPLY) Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "PlnrcmbdAppsrv", "MhdCallback[2]");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[3]");

						if (req->dpcheng) {
							writeDpchEng(xchg, req);
							response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};
					
					if (!valid) {
						response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};

				} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::UPLOAD) {
					// --- pass notification concerning uploaded file to job processor, and wait for acknowledgement
					valid = validateIp(xchg, req);

					if (valid) {
						validateJrefNotify(xchg, req, true);

						xchg->addReq(req);

						// wait for reply (usually empty)
						Mutex::lock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[4]");
						Cond::wait(&(req->cReady), &(req->mcReady), "req->cReady", "PlnrcmbdAppsrv", "MhdCallback[3]");
						Mutex::unlock(&(req->mcReady), "req->mcReady", "PlnrcmbdAppsrv", "MhdCallback[4]");

						if (req->reply) {
							response = MHD_create_response_from_data(req->replylen, req->reply, MHD_NO, MHD_NO);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						} else {
							response = MHD_create_response_from_data(strlen(empty), empty, MHD_YES, MHD_YES);
							retval = MHD_queue_response(connection, MHD_HTTP_OK, response);
							MHD_destroy_response(response);
						};
					};

					if (!valid) {
						response = MHD_create_response_from_data(strlen(invalid), invalid, MHD_YES, MHD_YES);
						retval = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
						MHD_destroy_response(response);
					};
				};
			};
		};
	};

	return retval;
};

#ifdef _WIN32
int PlnrcmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, int max
		) {
#else
ssize_t PlnrcmbdAppsrv::MhdFilesend(
			void* con_cls
			, uint64_t pos
			, char* buf
			, size_t max
		) {
#endif
	ReqPlnr* req = (ReqPlnr*) con_cls;

	int64_t spos = pos;
	int64_t len;

	if (req) {
		// determine length remaining
		req->file->seekg(0, ios::end);
		len = req->file->tellg();
		if (len != -1) {

			if (len > spos) {
				req->file->seekg(spos);
				req->file->read(buf, max);

				// check for errors
				if (req->file->bad()) return 0;

				if (len < (max+spos))
					return (len-spos);
				else
					return max;
			};
		};
	};

	return 0;
};

int PlnrcmbdAppsrv::MhdPostrecv(
			void* con_cls
			, MHD_ValueKind kind
			, const char* key
			, const char* filename
			, const char* content_type
			, const char* transfer_encoding
			, const char* data
			, uint64_t off
			, size_t size
		) {
	ReqPlnr* req = (ReqPlnr*) con_cls;

	//cout << "MhdPostrecv() with size = " << ((unsigned int) size) << endl;

	char* olddata;

	if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
		// --- copy data into req->request (append if required)
		if (strcmp(key, "xml") != 0) return MHD_NO;

		if (size > 0) {
			if (!req->request) {
				req->request = new char[size];
				memcpy(req->request, data, size);
				req->requestlen = size;

			} else {
				olddata = req->request;

				req->request = new char[req->requestlen + size];
				memcpy(req->request, olddata, req->requestlen);
				memcpy(&(req->request[req->requestlen]), data, size);
				req->requestlen = req->requestlen + size;

				delete[] olddata;
			};
		};

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::UPLOAD) {
		// --- write data into file
		if (strcmp(key, "file") != 0) return MHD_NO;

		if (size > 0) {
			req->file = new fstream();

			req->file->open(req->filename.c_str(), fstream::app | fstream::out | fstream::binary);
			req->file->write(data, size);
			req->file->close();

			delete(req->file);
			req->file = NULL;
		};

	} else {
		return MHD_NO;
	};

	return MHD_YES;
};

void PlnrcmbdAppsrv::MhdComplete(
			void* cls
			, MHD_Connection* connection
			, void** con_cls
			, MHD_RequestTerminationCode toe
		) {
	ReqPlnr* req;

	//cout << "MhdComplete()" << endl;

	if (*con_cls != NULL) {
		req = (ReqPlnr*) *con_cls;
		delete req;
	};

	*con_cls = NULL;
};

bool PlnrcmbdAppsrv::validateIp(
			XchgPlnrcmbd* xchg
			, ReqPlnr* req
		) {
	bool retval = true;

	string ip;

	if (req->jref != 0) {
		ip = xchg->getTxtvalPreset(VecPlnrVPreset::PREPLNRIP, req->jref);
		if (ip.compare(req->ip) != 0) retval = false;
	};

	return retval;
};

bool PlnrcmbdAppsrv::validateJrefNotify(
			XchgPlnrcmbd* xchg
			, ReqPlnr* req
			, const bool update
		) {
	bool retval = false;

	ubigint jrefNotify;

	DcolPlnr* dcol = NULL;

	jrefNotify = xchg->getRefPreset(VecPlnrVPreset::PREPLNRJREFNOTIFY, req->jref);

	dcol = xchg->getDcolByJref(req->jref);

	if (dcol) {
		retval = (jrefNotify == dcol->jref);
		if (!retval && update) xchg->triggerIxRefCall(NULL, VecPlnrVCall::CALLPLNRREFPRESET, dcol->jref, VecPlnrVPreset::PREPLNRJREFNOTIFY, dcol->jref);

		dcol->unlockAccess("PlnrcmbdAppsrv", "validateJrefNotify");
	};

	return retval;
};

uint PlnrcmbdAppsrv::readDpchApp(
			XchgPlnrcmbd* xchg
			, ReqPlnr* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->request, req->requestlen, &doc, &docctx);

	uint ixPlnrVDpch = VecPlnrVDpch::getIx(extractRoot(doc));

	if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCEXPRTXDO) {
		req->dpchapp = new DlgPlnrClcExprtx::DpchAppDo();
		((DlgPlnrClcExprtx::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCGENRPVDO) {
		req->dpchapp = new DlgPlnrClcGenrpv::DpchAppDo();
		((DlgPlnrClcGenrpv::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDATA) {
		req->dpchapp = new DlgPlnrClcUsecase::DpchAppData();
		((DlgPlnrClcUsecase::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRCLCUSECASEDO) {
		req->dpchapp = new DlgPlnrClcUsecase::DpchAppDo();
		((DlgPlnrClcUsecase::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRDSNGENPLTDO) {
		req->dpchapp = new DlgPlnrDsnGenplt::DpchAppDo();
		((DlgPlnrDsnGenplt::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRFILDLDCPYDO) {
		req->dpchapp = new DlgPlnrFilDldcpy::DpchAppDo();
		((DlgPlnrFilDldcpy::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRNAVLOAINIDATA) {
		req->dpchapp = new DlgPlnrNavLoaini::DpchAppData();
		((DlgPlnrNavLoaini::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRNAVLOAINIDO) {
		req->dpchapp = new DlgPlnrNavLoaini::DpchAppDo();
		((DlgPlnrNavLoaini::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDATA) {
		req->dpchapp = new DlgPlnrTpoUsecase::DpchAppData();
		((DlgPlnrTpoUsecase::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPDLGPLNRTPOUSECASEDO) {
		req->dpchapp = new DlgPlnrTpoUsecase::DpchAppDo();
		((DlgPlnrTpoUsecase::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRALERT) {
		req->dpchapp = new DpchAppPlnrAlert();
		((DpchAppPlnrAlert*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIAMARRAYENVDATA) {
		req->dpchapp = new PnlPlnrAriAMArrayEnv::DpchAppData();
		((PnlPlnrAriAMArrayEnv::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIAMARRAYENVDO) {
		req->dpchapp = new PnlPlnrAriAMArrayEnv::DpchAppDo();
		((PnlPlnrAriAMArrayEnv::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIDETAILDATA) {
		req->dpchapp = new PnlPlnrAriDetail::DpchAppData();
		((PnlPlnrAriDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIDETAILDO) {
		req->dpchapp = new PnlPlnrAriDetail::DpchAppDo();
		((PnlPlnrAriDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIDO) {
		req->dpchapp = new CrdPlnrAri::DpchAppDo();
		((CrdPlnrAri::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARILISTDATA) {
		req->dpchapp = new PnlPlnrAriList::DpchAppData();
		((PnlPlnrAriList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARILISTDO) {
		req->dpchapp = new PnlPlnrAriList::DpchAppDo();
		((PnlPlnrAriList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARIRECDO) {
		req->dpchapp = new PnlPlnrAriRec::DpchAppDo();
		((PnlPlnrAriRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARR1NARRAYITEMDATA) {
		req->dpchapp = new PnlPlnrArr1NArrayitem::DpchAppData();
		((PnlPlnrArr1NArrayitem::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARR1NARRAYITEMDO) {
		req->dpchapp = new PnlPlnrArr1NArrayitem::DpchAppDo();
		((PnlPlnrArr1NArrayitem::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRAENVDATA) {
		req->dpchapp = new PnlPlnrArrAEnv::DpchAppData();
		((PnlPlnrArrAEnv::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRAENVDO) {
		req->dpchapp = new PnlPlnrArrAEnv::DpchAppDo();
		((PnlPlnrArrAEnv::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRDETAILDATA) {
		req->dpchapp = new PnlPlnrArrDetail::DpchAppData();
		((PnlPlnrArrDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRDETAILDO) {
		req->dpchapp = new PnlPlnrArrDetail::DpchAppDo();
		((PnlPlnrArrDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRDO) {
		req->dpchapp = new CrdPlnrArr::DpchAppDo();
		((CrdPlnrArr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRHK1NRETICLEDATA) {
		req->dpchapp = new PnlPlnrArrHk1NReticle::DpchAppData();
		((PnlPlnrArrHk1NReticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRHK1NRETICLEDO) {
		req->dpchapp = new PnlPlnrArrHk1NReticle::DpchAppDo();
		((PnlPlnrArrHk1NReticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRKENVKEYDATA) {
		req->dpchapp = new PnlPlnrArrKEnvKey::DpchAppData();
		((PnlPlnrArrKEnvKey::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRKENVKEYDO) {
		req->dpchapp = new PnlPlnrArrKEnvKey::DpchAppDo();
		((PnlPlnrArrKEnvKey::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRLISTDATA) {
		req->dpchapp = new PnlPlnrArrList::DpchAppData();
		((PnlPlnrArrList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRLISTDO) {
		req->dpchapp = new PnlPlnrArrList::DpchAppDo();
		((PnlPlnrArrList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRARRRECDO) {
		req->dpchapp = new PnlPlnrArrRec::DpchAppDo();
		((PnlPlnrArrRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLC1NMATERIALDATA) {
		req->dpchapp = new PnlPlnrClc1NMaterial::DpchAppData();
		((PnlPlnrClc1NMaterial::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLC1NMATERIALDO) {
		req->dpchapp = new PnlPlnrClc1NMaterial::DpchAppDo();
		((PnlPlnrClc1NMaterial::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCAENVDATA) {
		req->dpchapp = new PnlPlnrClcAEnv::DpchAppData();
		((PnlPlnrClcAEnv::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCAENVDO) {
		req->dpchapp = new PnlPlnrClcAEnv::DpchAppDo();
		((PnlPlnrClcAEnv::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCAPARDATA) {
		req->dpchapp = new PnlPlnrClcAPar::DpchAppData();
		((PnlPlnrClcAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCAPARDO) {
		req->dpchapp = new PnlPlnrClcAPar::DpchAppDo();
		((PnlPlnrClcAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCCAL1NCALCITEMDATA) {
		req->dpchapp = new PnlPlnrClcCal1NCalcitem::DpchAppData();
		((PnlPlnrClcCal1NCalcitem::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCCAL1NCALCITEMDO) {
		req->dpchapp = new PnlPlnrClcCal1NCalcitem::DpchAppDo();
		((PnlPlnrClcCal1NCalcitem::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCDETAILDATA) {
		req->dpchapp = new PnlPlnrClcDetail::DpchAppData();
		((PnlPlnrClcDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCDETAILDO) {
		req->dpchapp = new PnlPlnrClcDetail::DpchAppDo();
		((PnlPlnrClcDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCDO) {
		req->dpchapp = new CrdPlnrClc::DpchAppDo();
		((CrdPlnrClc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCLISTDATA) {
		req->dpchapp = new PnlPlnrClcList::DpchAppData();
		((PnlPlnrClcList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCLISTDO) {
		req->dpchapp = new PnlPlnrClcList::DpchAppDo();
		((PnlPlnrClcList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCMNDOMAINDATA) {
		req->dpchapp = new PnlPlnrClcMNDomain::DpchAppData();
		((PnlPlnrClcMNDomain::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCMNDOMAINDO) {
		req->dpchapp = new PnlPlnrClcMNDomain::DpchAppDo();
		((PnlPlnrClcMNDomain::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCMNFILEDATA) {
		req->dpchapp = new PnlPlnrClcMNFile::DpchAppData();
		((PnlPlnrClcMNFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCMNFILEDO) {
		req->dpchapp = new PnlPlnrClcMNFile::DpchAppDo();
		((PnlPlnrClcMNFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCRECDO) {
		req->dpchapp = new PnlPlnrClcRec::DpchAppDo();
		((PnlPlnrClcRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCREF1NFILEDATA) {
		req->dpchapp = new PnlPlnrClcRef1NFile::DpchAppData();
		((PnlPlnrClcRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCREF1NFILEDO) {
		req->dpchapp = new PnlPlnrClcRef1NFile::DpchAppDo();
		((PnlPlnrClcRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCSUP1NCALCDATA) {
		req->dpchapp = new PnlPlnrClcSup1NCalc::DpchAppData();
		((PnlPlnrClcSup1NCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLCSUP1NCALCDO) {
		req->dpchapp = new PnlPlnrClcSup1NCalc::DpchAppDo();
		((PnlPlnrClcSup1NCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCENVDATA) {
		req->dpchapp = new PnlPlnrCliAAMCalcEnv::DpchAppData();
		((PnlPlnrCliAAMCalcEnv::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCENVDO) {
		req->dpchapp = new PnlPlnrCliAAMCalcEnv::DpchAppDo();
		((PnlPlnrCliAAMCalcEnv::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCPARDATA) {
		req->dpchapp = new PnlPlnrCliAAMCalcPar::DpchAppData();
		((PnlPlnrCliAAMCalcPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIAAMCALCPARDO) {
		req->dpchapp = new PnlPlnrCliAAMCalcPar::DpchAppDo();
		((PnlPlnrCliAAMCalcPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIDETAILDATA) {
		req->dpchapp = new PnlPlnrCliDetail::DpchAppData();
		((PnlPlnrCliDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIDETAILDO) {
		req->dpchapp = new PnlPlnrCliDetail::DpchAppDo();
		((PnlPlnrCliDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIDO) {
		req->dpchapp = new CrdPlnrCli::DpchAppDo();
		((CrdPlnrCli::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLILISTDATA) {
		req->dpchapp = new PnlPlnrCliList::DpchAppData();
		((PnlPlnrCliList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLILISTDO) {
		req->dpchapp = new PnlPlnrCliList::DpchAppDo();
		((PnlPlnrCliList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIRECDO) {
		req->dpchapp = new PnlPlnrCliRec::DpchAppDo();
		((PnlPlnrCliRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIREF1NFILEDATA) {
		req->dpchapp = new PnlPlnrCliRef1NFile::DpchAppData();
		((PnlPlnrCliRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCLIREF1NFILEDO) {
		req->dpchapp = new PnlPlnrCliRef1NFile::DpchAppDo();
		((PnlPlnrCliRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPAENVDATA) {
		req->dpchapp = new PnlPlnrCtpAEnv::DpchAppData();
		((PnlPlnrCtpAEnv::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPAENVDO) {
		req->dpchapp = new PnlPlnrCtpAEnv::DpchAppDo();
		((PnlPlnrCtpAEnv::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPAPARDATA) {
		req->dpchapp = new PnlPlnrCtpAPar::DpchAppData();
		((PnlPlnrCtpAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPAPARDO) {
		req->dpchapp = new PnlPlnrCtpAPar::DpchAppDo();
		((PnlPlnrCtpAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPDETAILDATA) {
		req->dpchapp = new PnlPlnrCtpDetail::DpchAppData();
		((PnlPlnrCtpDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPDETAILDO) {
		req->dpchapp = new PnlPlnrCtpDetail::DpchAppDo();
		((PnlPlnrCtpDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPDO) {
		req->dpchapp = new CrdPlnrCtp::DpchAppDo();
		((CrdPlnrCtp::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKCALCDOMPRPDATA) {
		req->dpchapp = new PnlPlnrCtpKCalcdomprp::DpchAppData();
		((PnlPlnrCtpKCalcdomprp::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKCALCDOMPRPDO) {
		req->dpchapp = new PnlPlnrCtpKCalcdomprp::DpchAppDo();
		((PnlPlnrCtpKCalcdomprp::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKCALCVARDATA) {
		req->dpchapp = new PnlPlnrCtpKCalcvar::DpchAppData();
		((PnlPlnrCtpKCalcvar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKCALCVARDO) {
		req->dpchapp = new PnlPlnrCtpKCalcvar::DpchAppDo();
		((PnlPlnrCtpKCalcvar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKENVKEYDATA) {
		req->dpchapp = new PnlPlnrCtpKEnvKey::DpchAppData();
		((PnlPlnrCtpKEnvKey::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKENVKEYDO) {
		req->dpchapp = new PnlPlnrCtpKEnvKey::DpchAppDo();
		((PnlPlnrCtpKEnvKey::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKPARCATDATA) {
		req->dpchapp = new PnlPlnrCtpKParCat::DpchAppData();
		((PnlPlnrCtpKParCat::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKPARCATDO) {
		req->dpchapp = new PnlPlnrCtpKParCat::DpchAppDo();
		((PnlPlnrCtpKParCat::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKPARPROPDATA) {
		req->dpchapp = new PnlPlnrCtpKParProp::DpchAppData();
		((PnlPlnrCtpKParProp::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPKPARPROPDO) {
		req->dpchapp = new PnlPlnrCtpKParProp::DpchAppDo();
		((PnlPlnrCtpKParProp::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPLISTDATA) {
		req->dpchapp = new PnlPlnrCtpList::DpchAppData();
		((PnlPlnrCtpList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPLISTDO) {
		req->dpchapp = new PnlPlnrCtpList::DpchAppDo();
		((PnlPlnrCtpList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPRECDO) {
		req->dpchapp = new PnlPlnrCtpRec::DpchAppDo();
		((PnlPlnrCtpRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPREF1NFILEDATA) {
		req->dpchapp = new PnlPlnrCtpRef1NFile::DpchAppData();
		((PnlPlnrCtpRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPREF1NFILEDO) {
		req->dpchapp = new PnlPlnrCtpRef1NFile::DpchAppDo();
		((PnlPlnrCtpRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPSUP1NCALCDATA) {
		req->dpchapp = new PnlPlnrCtpSup1NCalc::DpchAppData();
		((PnlPlnrCtpSup1NCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPSUP1NCALCDO) {
		req->dpchapp = new PnlPlnrCtpSup1NCalc::DpchAppDo();
		((PnlPlnrCtpSup1NCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPTPL1NCALCDATA) {
		req->dpchapp = new PnlPlnrCtpTpl1NCalc::DpchAppData();
		((PnlPlnrCtpTpl1NCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRCTPTPL1NCALCDO) {
		req->dpchapp = new PnlPlnrCtpTpl1NCalc::DpchAppDo();
		((PnlPlnrCtpTpl1NCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDATA) {
		req->dpchapp = new PnlPlnrDgdDetail::DpchAppData();
		((PnlPlnrDgdDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDDETAILDO) {
		req->dpchapp = new PnlPlnrDgdDetail::DpchAppDo();
		((PnlPlnrDgdDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDDO) {
		req->dpchapp = new CrdPlnrDgd::DpchAppDo();
		((CrdPlnrDgd::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDLISTDATA) {
		req->dpchapp = new PnlPlnrDgdList::DpchAppData();
		((PnlPlnrDgdList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDLISTDO) {
		req->dpchapp = new PnlPlnrDgdList::DpchAppDo();
		((PnlPlnrDgdList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDGDRECDO) {
		req->dpchapp = new PnlPlnrDgdRec::DpchAppDo();
		((PnlPlnrDgdRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDATA) {
		req->dpchapp = new PnlPlnrDomDetail::DpchAppData();
		((PnlPlnrDomDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMDETAILDO) {
		req->dpchapp = new PnlPlnrDomDetail::DpchAppDo();
		((PnlPlnrDomDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMDO) {
		req->dpchapp = new CrdPlnrDom::DpchAppDo();
		((CrdPlnrDom::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMLISTDATA) {
		req->dpchapp = new PnlPlnrDomList::DpchAppData();
		((PnlPlnrDomList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMLISTDO) {
		req->dpchapp = new PnlPlnrDomList::DpchAppDo();
		((PnlPlnrDomList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMMNCALCDATA) {
		req->dpchapp = new PnlPlnrDomMNCalc::DpchAppData();
		((PnlPlnrDomMNCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMMNCALCDO) {
		req->dpchapp = new PnlPlnrDomMNCalc::DpchAppDo();
		((PnlPlnrDomMNCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDOMRECDO) {
		req->dpchapp = new PnlPlnrDomRec::DpchAppDo();
		((PnlPlnrDomRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSN1NBLOCKDATA) {
		req->dpchapp = new PnlPlnrDsn1NBlock::DpchAppData();
		((PnlPlnrDsn1NBlock::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSN1NBLOCKDO) {
		req->dpchapp = new PnlPlnrDsn1NBlock::DpchAppDo();
		((PnlPlnrDsn1NBlock::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSN1NRETICLEDATA) {
		req->dpchapp = new PnlPlnrDsn1NReticle::DpchAppData();
		((PnlPlnrDsn1NReticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSN1NRETICLEDO) {
		req->dpchapp = new PnlPlnrDsn1NReticle::DpchAppDo();
		((PnlPlnrDsn1NReticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDATA) {
		req->dpchapp = new PnlPlnrDsnDetail::DpchAppData();
		((PnlPlnrDsnDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDETAILDO) {
		req->dpchapp = new PnlPlnrDsnDetail::DpchAppDo();
		((PnlPlnrDsnDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDO) {
		req->dpchapp = new CrdPlnrDsn::DpchAppDo();
		((CrdPlnrDsn::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDRV1NDESIGNDATA) {
		req->dpchapp = new PnlPlnrDsnDrv1NDesign::DpchAppData();
		((PnlPlnrDsnDrv1NDesign::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDRV1NDESIGNDO) {
		req->dpchapp = new PnlPlnrDsnDrv1NDesign::DpchAppDo();
		((PnlPlnrDsnDrv1NDesign::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NDEVICEDATA) {
		req->dpchapp = new PnlPlnrDsnDsn1NDevice::DpchAppData();
		((PnlPlnrDsnDsn1NDevice::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NDEVICEDO) {
		req->dpchapp = new PnlPlnrDsnDsn1NDevice::DpchAppDo();
		((PnlPlnrDsnDsn1NDevice::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NDOMAINDATA) {
		req->dpchapp = new PnlPlnrDsnDsn1NDomain::DpchAppData();
		((PnlPlnrDsnDsn1NDomain::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NDOMAINDO) {
		req->dpchapp = new PnlPlnrDsnDsn1NDomain::DpchAppDo();
		((PnlPlnrDsnDsn1NDomain::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NDOMAINGDDATA) {
		req->dpchapp = new PnlPlnrDsnDsn1NDomaingd::DpchAppData();
		((PnlPlnrDsnDsn1NDomaingd::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NDOMAINGDDO) {
		req->dpchapp = new PnlPlnrDsnDsn1NDomaingd::DpchAppDo();
		((PnlPlnrDsnDsn1NDomaingd::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NSTACKDATA) {
		req->dpchapp = new PnlPlnrDsnDsn1NStack::DpchAppData();
		((PnlPlnrDsnDsn1NStack::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNDSN1NSTACKDO) {
		req->dpchapp = new PnlPlnrDsnDsn1NStack::DpchAppDo();
		((PnlPlnrDsnDsn1NStack::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NARCGUIDEDATA) {
		req->dpchapp = new PnlPlnrDsnHk1NArcguide::DpchAppData();
		((PnlPlnrDsnHk1NArcguide::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NARCGUIDEDO) {
		req->dpchapp = new PnlPlnrDsnHk1NArcguide::DpchAppDo();
		((PnlPlnrDsnHk1NArcguide::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLAYERDATA) {
		req->dpchapp = new PnlPlnrDsnHk1NLayer::DpchAppData();
		((PnlPlnrDsnHk1NLayer::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLAYERDO) {
		req->dpchapp = new PnlPlnrDsnHk1NLayer::DpchAppDo();
		((PnlPlnrDsnHk1NLayer::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLEVELDATA) {
		req->dpchapp = new PnlPlnrDsnHk1NLevel::DpchAppData();
		((PnlPlnrDsnHk1NLevel::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLEVELDO) {
		req->dpchapp = new PnlPlnrDsnHk1NLevel::DpchAppDo();
		((PnlPlnrDsnHk1NLevel::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLINEGUIDEDATA) {
		req->dpchapp = new PnlPlnrDsnHk1NLineguide::DpchAppData();
		((PnlPlnrDsnHk1NLineguide::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NLINEGUIDEDO) {
		req->dpchapp = new PnlPlnrDsnHk1NLineguide::DpchAppDo();
		((PnlPlnrDsnHk1NLineguide::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NSTRUCTUREDATA) {
		req->dpchapp = new PnlPlnrDsnHk1NStructure::DpchAppData();
		((PnlPlnrDsnHk1NStructure::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NSTRUCTUREDO) {
		req->dpchapp = new PnlPlnrDsnHk1NStructure::DpchAppDo();
		((PnlPlnrDsnHk1NStructure::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NVERTEXDATA) {
		req->dpchapp = new PnlPlnrDsnHk1NVertex::DpchAppData();
		((PnlPlnrDsnHk1NVertex::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNHK1NVERTEXDO) {
		req->dpchapp = new PnlPlnrDsnHk1NVertex::DpchAppDo();
		((PnlPlnrDsnHk1NVertex::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNLISTDATA) {
		req->dpchapp = new PnlPlnrDsnList::DpchAppData();
		((PnlPlnrDsnList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNLISTDO) {
		req->dpchapp = new PnlPlnrDsnList::DpchAppDo();
		((PnlPlnrDsnList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNMOD1NDESIGNDATA) {
		req->dpchapp = new PnlPlnrDsnMod1NDesign::DpchAppData();
		((PnlPlnrDsnMod1NDesign::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNMOD1NDESIGNDO) {
		req->dpchapp = new PnlPlnrDsnMod1NDesign::DpchAppDo();
		((PnlPlnrDsnMod1NDesign::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNRECDO) {
		req->dpchapp = new PnlPlnrDsnRec::DpchAppDo();
		((PnlPlnrDsnRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPAPARDATA) {
		req->dpchapp = new PnlPlnrDtpAPar::DpchAppData();
		((PnlPlnrDtpAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPAPARDO) {
		req->dpchapp = new PnlPlnrDtpAPar::DpchAppDo();
		((PnlPlnrDtpAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPDETAILDATA) {
		req->dpchapp = new PnlPlnrDtpDetail::DpchAppData();
		((PnlPlnrDtpDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPDETAILDO) {
		req->dpchapp = new PnlPlnrDtpDetail::DpchAppDo();
		((PnlPlnrDtpDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPDO) {
		req->dpchapp = new CrdPlnrDtp::DpchAppDo();
		((CrdPlnrDtp::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPHK1NSTRUCTUREDATA) {
		req->dpchapp = new PnlPlnrDtpHk1NStructure::DpchAppData();
		((PnlPlnrDtpHk1NStructure::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPHK1NSTRUCTUREDO) {
		req->dpchapp = new PnlPlnrDtpHk1NStructure::DpchAppDo();
		((PnlPlnrDtpHk1NStructure::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPKPARKEYDATA) {
		req->dpchapp = new PnlPlnrDtpKParKey::DpchAppData();
		((PnlPlnrDtpKParKey::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPKPARKEYDO) {
		req->dpchapp = new PnlPlnrDtpKParKey::DpchAppDo();
		((PnlPlnrDtpKParKey::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPLISTDATA) {
		req->dpchapp = new PnlPlnrDtpList::DpchAppData();
		((PnlPlnrDtpList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPLISTDO) {
		req->dpchapp = new PnlPlnrDtpList::DpchAppDo();
		((PnlPlnrDtpList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPRECDO) {
		req->dpchapp = new PnlPlnrDtpRec::DpchAppDo();
		((PnlPlnrDtpRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPSUP1NDEVICEDATA) {
		req->dpchapp = new PnlPlnrDtpSup1NDevice::DpchAppData();
		((PnlPlnrDtpSup1NDevice::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPSUP1NDEVICEDO) {
		req->dpchapp = new PnlPlnrDtpSup1NDevice::DpchAppDo();
		((PnlPlnrDtpSup1NDevice::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPTPL1NDEVICEDATA) {
		req->dpchapp = new PnlPlnrDtpTpl1NDevice::DpchAppData();
		((PnlPlnrDtpTpl1NDevice::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDTPTPL1NDEVICEDO) {
		req->dpchapp = new PnlPlnrDtpTpl1NDevice::DpchAppDo();
		((PnlPlnrDtpTpl1NDevice::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCAPARDATA) {
		req->dpchapp = new PnlPlnrDvcAPar::DpchAppData();
		((PnlPlnrDvcAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCAPARDO) {
		req->dpchapp = new PnlPlnrDvcAPar::DpchAppDo();
		((PnlPlnrDvcAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCDETAILDATA) {
		req->dpchapp = new PnlPlnrDvcDetail::DpchAppData();
		((PnlPlnrDvcDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCDETAILDO) {
		req->dpchapp = new PnlPlnrDvcDetail::DpchAppDo();
		((PnlPlnrDvcDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCDO) {
		req->dpchapp = new CrdPlnrDvc::DpchAppDo();
		((CrdPlnrDvc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NARCGUIDEDATA) {
		req->dpchapp = new PnlPlnrDvcHk1NArcguide::DpchAppData();
		((PnlPlnrDvcHk1NArcguide::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NARCGUIDEDO) {
		req->dpchapp = new PnlPlnrDvcHk1NArcguide::DpchAppDo();
		((PnlPlnrDvcHk1NArcguide::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NLINEGUIDEDATA) {
		req->dpchapp = new PnlPlnrDvcHk1NLineguide::DpchAppData();
		((PnlPlnrDvcHk1NLineguide::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NLINEGUIDEDO) {
		req->dpchapp = new PnlPlnrDvcHk1NLineguide::DpchAppDo();
		((PnlPlnrDvcHk1NLineguide::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NSTRUCTUREDATA) {
		req->dpchapp = new PnlPlnrDvcHk1NStructure::DpchAppData();
		((PnlPlnrDvcHk1NStructure::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NSTRUCTUREDO) {
		req->dpchapp = new PnlPlnrDvcHk1NStructure::DpchAppDo();
		((PnlPlnrDvcHk1NStructure::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NVERTEXDATA) {
		req->dpchapp = new PnlPlnrDvcHk1NVertex::DpchAppData();
		((PnlPlnrDvcHk1NVertex::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCHK1NVERTEXDO) {
		req->dpchapp = new PnlPlnrDvcHk1NVertex::DpchAppDo();
		((PnlPlnrDvcHk1NVertex::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCLISTDATA) {
		req->dpchapp = new PnlPlnrDvcList::DpchAppData();
		((PnlPlnrDvcList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCLISTDO) {
		req->dpchapp = new PnlPlnrDvcList::DpchAppDo();
		((PnlPlnrDvcList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCRECDO) {
		req->dpchapp = new PnlPlnrDvcRec::DpchAppDo();
		((PnlPlnrDvcRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCSUP1NDEVICEDATA) {
		req->dpchapp = new PnlPlnrDvcSup1NDevice::DpchAppData();
		((PnlPlnrDvcSup1NDevice::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDVCSUP1NDEVICEDO) {
		req->dpchapp = new PnlPlnrDvcSup1NDevice::DpchAppDo();
		((PnlPlnrDvcSup1NDevice::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILDETAILDATA) {
		req->dpchapp = new PnlPlnrFilDetail::DpchAppData();
		((PnlPlnrFilDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILDETAILDO) {
		req->dpchapp = new PnlPlnrFilDetail::DpchAppDo();
		((PnlPlnrFilDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILDO) {
		req->dpchapp = new CrdPlnrFil::DpchAppDo();
		((CrdPlnrFil::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILLISTDATA) {
		req->dpchapp = new PnlPlnrFilList::DpchAppData();
		((PnlPlnrFilList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILLISTDO) {
		req->dpchapp = new PnlPlnrFilList::DpchAppDo();
		((PnlPlnrFilList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILMNCALCDATA) {
		req->dpchapp = new PnlPlnrFilMNCalc::DpchAppData();
		((PnlPlnrFilMNCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILMNCALCDO) {
		req->dpchapp = new PnlPlnrFilMNCalc::DpchAppDo();
		((PnlPlnrFilMNCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRFILRECDO) {
		req->dpchapp = new PnlPlnrFilRec::DpchAppDo();
		((PnlPlnrFilRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRINIT) {
		req->dpchapp = new DpchAppPlnrInit();
		((DpchAppPlnrInit*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYR1NBLOCKDATA) {
		req->dpchapp = new PnlPlnrLyr1NBlock::DpchAppData();
		((PnlPlnrLyr1NBlock::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYR1NBLOCKDO) {
		req->dpchapp = new PnlPlnrLyr1NBlock::DpchAppDo();
		((PnlPlnrLyr1NBlock::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYR1NRETICLEDATA) {
		req->dpchapp = new PnlPlnrLyr1NReticle::DpchAppData();
		((PnlPlnrLyr1NReticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYR1NRETICLEDO) {
		req->dpchapp = new PnlPlnrLyr1NReticle::DpchAppDo();
		((PnlPlnrLyr1NReticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDATA) {
		req->dpchapp = new PnlPlnrLyrDetail::DpchAppData();
		((PnlPlnrLyrDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRDETAILDO) {
		req->dpchapp = new PnlPlnrLyrDetail::DpchAppDo();
		((PnlPlnrLyrDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRDO) {
		req->dpchapp = new CrdPlnrLyr::DpchAppDo();
		((CrdPlnrLyr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRLISTDATA) {
		req->dpchapp = new PnlPlnrLyrList::DpchAppData();
		((PnlPlnrLyrList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRLISTDO) {
		req->dpchapp = new PnlPlnrLyrList::DpchAppDo();
		((PnlPlnrLyrList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRMNSTRUCTUREDATA) {
		req->dpchapp = new PnlPlnrLyrMNStructure::DpchAppData();
		((PnlPlnrLyrMNStructure::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRMNSTRUCTUREDO) {
		req->dpchapp = new PnlPlnrLyrMNStructure::DpchAppDo();
		((PnlPlnrLyrMNStructure::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRLYRRECDO) {
		req->dpchapp = new PnlPlnrLyrRec::DpchAppDo();
		((PnlPlnrLyrRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMAT1NLAYERDATA) {
		req->dpchapp = new PnlPlnrMat1NLayer::DpchAppData();
		((PnlPlnrMat1NLayer::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMAT1NLAYERDO) {
		req->dpchapp = new PnlPlnrMat1NLayer::DpchAppDo();
		((PnlPlnrMat1NLayer::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATAPARDATA) {
		req->dpchapp = new PnlPlnrMatAPar::DpchAppData();
		((PnlPlnrMatAPar::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATAPARDO) {
		req->dpchapp = new PnlPlnrMatAPar::DpchAppDo();
		((PnlPlnrMatAPar::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATDETAILDATA) {
		req->dpchapp = new PnlPlnrMatDetail::DpchAppData();
		((PnlPlnrMatDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATDETAILDO) {
		req->dpchapp = new PnlPlnrMatDetail::DpchAppDo();
		((PnlPlnrMatDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATDO) {
		req->dpchapp = new CrdPlnrMat::DpchAppDo();
		((CrdPlnrMat::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATLISTDATA) {
		req->dpchapp = new PnlPlnrMatList::DpchAppData();
		((PnlPlnrMatList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATLISTDO) {
		req->dpchapp = new PnlPlnrMatList::DpchAppDo();
		((PnlPlnrMatList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATMOD1NMATERIALDATA) {
		req->dpchapp = new PnlPlnrMatMod1NMaterial::DpchAppData();
		((PnlPlnrMatMod1NMaterial::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATMOD1NMATERIALDO) {
		req->dpchapp = new PnlPlnrMatMod1NMaterial::DpchAppDo();
		((PnlPlnrMatMod1NMaterial::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATRECDO) {
		req->dpchapp = new PnlPlnrMatRec::DpchAppDo();
		((PnlPlnrMatRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATREF1NFILEDATA) {
		req->dpchapp = new PnlPlnrMatRef1NFile::DpchAppData();
		((PnlPlnrMatRef1NFile::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRMATREF1NFILEDO) {
		req->dpchapp = new PnlPlnrMatRef1NFile::DpchAppDo();
		((PnlPlnrMatRef1NFile::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVADMINDATA) {
		req->dpchapp = new PnlPlnrNavAdmin::DpchAppData();
		((PnlPlnrNavAdmin::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVADMINDO) {
		req->dpchapp = new PnlPlnrNavAdmin::DpchAppDo();
		((PnlPlnrNavAdmin::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVCALCDATA) {
		req->dpchapp = new PnlPlnrNavCalc::DpchAppData();
		((PnlPlnrNavCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVCALCDO) {
		req->dpchapp = new PnlPlnrNavCalc::DpchAppDo();
		((PnlPlnrNavCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDATA) {
		req->dpchapp = new PnlPlnrNavDesign::DpchAppData();
		((PnlPlnrNavDesign::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVDESIGNDO) {
		req->dpchapp = new PnlPlnrNavDesign::DpchAppDo();
		((PnlPlnrNavDesign::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVDO) {
		req->dpchapp = new CrdPlnrNav::DpchAppDo();
		((CrdPlnrNav::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDATA) {
		req->dpchapp = new PnlPlnrNavGlobal::DpchAppData();
		((PnlPlnrNavGlobal::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVGLOBALDO) {
		req->dpchapp = new PnlPlnrNavGlobal::DpchAppDo();
		((PnlPlnrNavGlobal::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDATA) {
		req->dpchapp = new PnlPlnrNavLayout::DpchAppData();
		((PnlPlnrNavLayout::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVLAYOUTDO) {
		req->dpchapp = new PnlPlnrNavLayout::DpchAppDo();
		((PnlPlnrNavLayout::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRNAVPREDO) {
		req->dpchapp = new PnlPlnrNavPre::DpchAppDo();
		((PnlPlnrNavPre::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJ1NCALCDATA) {
		req->dpchapp = new PnlPlnrPrj1NCalc::DpchAppData();
		((PnlPlnrPrj1NCalc::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJ1NCALCDO) {
		req->dpchapp = new PnlPlnrPrj1NCalc::DpchAppDo();
		((PnlPlnrPrj1NCalc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJ1NDESIGNDATA) {
		req->dpchapp = new PnlPlnrPrj1NDesign::DpchAppData();
		((PnlPlnrPrj1NDesign::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJ1NDESIGNDO) {
		req->dpchapp = new PnlPlnrPrj1NDesign::DpchAppDo();
		((PnlPlnrPrj1NDesign::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJDETAILDATA) {
		req->dpchapp = new PnlPlnrPrjDetail::DpchAppData();
		((PnlPlnrPrjDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJDETAILDO) {
		req->dpchapp = new PnlPlnrPrjDetail::DpchAppDo();
		((PnlPlnrPrjDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJDO) {
		req->dpchapp = new CrdPlnrPrj::DpchAppDo();
		((CrdPlnrPrj::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJLISTDATA) {
		req->dpchapp = new PnlPlnrPrjList::DpchAppData();
		((PnlPlnrPrjList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJLISTDO) {
		req->dpchapp = new PnlPlnrPrjList::DpchAppDo();
		((PnlPlnrPrjList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJMNTAPEOUTDATA) {
		req->dpchapp = new PnlPlnrPrjMNTapeout::DpchAppData();
		((PnlPlnrPrjMNTapeout::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJMNTAPEOUTDO) {
		req->dpchapp = new PnlPlnrPrjMNTapeout::DpchAppDo();
		((PnlPlnrPrjMNTapeout::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRJRECDO) {
		req->dpchapp = new PnlPlnrPrjRec::DpchAppDo();
		((PnlPlnrPrjRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSADETAILDATA) {
		req->dpchapp = new PnlPlnrPrsADetail::DpchAppData();
		((PnlPlnrPrsADetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSADETAILDO) {
		req->dpchapp = new PnlPlnrPrsADetail::DpchAppDo();
		((PnlPlnrPrsADetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSDETAILDATA) {
		req->dpchapp = new PnlPlnrPrsDetail::DpchAppData();
		((PnlPlnrPrsDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSDETAILDO) {
		req->dpchapp = new PnlPlnrPrsDetail::DpchAppDo();
		((PnlPlnrPrsDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSDO) {
		req->dpchapp = new CrdPlnrPrs::DpchAppDo();
		((CrdPlnrPrs::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSLISTDATA) {
		req->dpchapp = new PnlPlnrPrsList::DpchAppData();
		((PnlPlnrPrsList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSLISTDO) {
		req->dpchapp = new PnlPlnrPrsList::DpchAppDo();
		((PnlPlnrPrsList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRPRSRECDO) {
		req->dpchapp = new PnlPlnrPrsRec::DpchAppDo();
		((PnlPlnrPrsRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRESUME) {
		req->dpchapp = new DpchAppPlnrResume();
		((DpchAppPlnrResume*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDATA) {
		req->dpchapp = new PnlPlnrRtcDetail::DpchAppData();
		((PnlPlnrRtcDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCDETAILDO) {
		req->dpchapp = new PnlPlnrRtcDetail::DpchAppDo();
		((PnlPlnrRtcDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCDO) {
		req->dpchapp = new CrdPlnrRtc::DpchAppDo();
		((CrdPlnrRtc::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCLISTDATA) {
		req->dpchapp = new PnlPlnrRtcList::DpchAppData();
		((PnlPlnrRtcList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCLISTDO) {
		req->dpchapp = new PnlPlnrRtcList::DpchAppDo();
		((PnlPlnrRtcList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRRTCRECDO) {
		req->dpchapp = new PnlPlnrRtcRec::DpchAppDo();
		((PnlPlnrRtcRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRU1NBLOCKDATA) {
		req->dpchapp = new PnlPlnrSru1NBlock::DpchAppData();
		((PnlPlnrSru1NBlock::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRU1NBLOCKDO) {
		req->dpchapp = new PnlPlnrSru1NBlock::DpchAppDo();
		((PnlPlnrSru1NBlock::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUDETAILDATA) {
		req->dpchapp = new PnlPlnrSruDetail::DpchAppData();
		((PnlPlnrSruDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUDETAILDO) {
		req->dpchapp = new PnlPlnrSruDetail::DpchAppDo();
		((PnlPlnrSruDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUDO) {
		req->dpchapp = new CrdPlnrSru::DpchAppDo();
		((CrdPlnrSru::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRULISTDATA) {
		req->dpchapp = new PnlPlnrSruList::DpchAppData();
		((PnlPlnrSruList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRULISTDO) {
		req->dpchapp = new PnlPlnrSruList::DpchAppDo();
		((PnlPlnrSruList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUMNLAYERDATA) {
		req->dpchapp = new PnlPlnrSruMNLayer::DpchAppData();
		((PnlPlnrSruMNLayer::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUMNLAYERDO) {
		req->dpchapp = new PnlPlnrSruMNLayer::DpchAppDo();
		((PnlPlnrSruMNLayer::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUMNSTACKDATA) {
		req->dpchapp = new PnlPlnrSruMNStack::DpchAppData();
		((PnlPlnrSruMNStack::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUMNSTACKDO) {
		req->dpchapp = new PnlPlnrSruMNStack::DpchAppDo();
		((PnlPlnrSruMNStack::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRURECDO) {
		req->dpchapp = new PnlPlnrSruRec::DpchAppDo();
		((PnlPlnrSruRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUSRU1NFACEDATA) {
		req->dpchapp = new PnlPlnrSruSru1NFace::DpchAppData();
		((PnlPlnrSruSru1NFace::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSRUSRU1NFACEDO) {
		req->dpchapp = new PnlPlnrSruSru1NFace::DpchAppDo();
		((PnlPlnrSruSru1NFace::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDATA) {
		req->dpchapp = new PnlPlnrStkDetail::DpchAppData();
		((PnlPlnrStkDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKDETAILDO) {
		req->dpchapp = new PnlPlnrStkDetail::DpchAppDo();
		((PnlPlnrStkDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKDO) {
		req->dpchapp = new CrdPlnrStk::DpchAppDo();
		((CrdPlnrStk::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKHK1NLAYERDATA) {
		req->dpchapp = new PnlPlnrStkHk1NLayer::DpchAppData();
		((PnlPlnrStkHk1NLayer::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKHK1NLAYERDO) {
		req->dpchapp = new PnlPlnrStkHk1NLayer::DpchAppDo();
		((PnlPlnrStkHk1NLayer::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKHK1NLEVELDATA) {
		req->dpchapp = new PnlPlnrStkHk1NLevel::DpchAppData();
		((PnlPlnrStkHk1NLevel::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKHK1NLEVELDO) {
		req->dpchapp = new PnlPlnrStkHk1NLevel::DpchAppDo();
		((PnlPlnrStkHk1NLevel::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKLISTDATA) {
		req->dpchapp = new PnlPlnrStkList::DpchAppData();
		((PnlPlnrStkList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKLISTDO) {
		req->dpchapp = new PnlPlnrStkList::DpchAppDo();
		((PnlPlnrStkList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKMNSTRUCTUREDATA) {
		req->dpchapp = new PnlPlnrStkMNStructure::DpchAppData();
		((PnlPlnrStkMNStructure::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKMNSTRUCTUREDO) {
		req->dpchapp = new PnlPlnrStkMNStructure::DpchAppDo();
		((PnlPlnrStkMNStructure::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRSTKRECDO) {
		req->dpchapp = new PnlPlnrStkRec::DpchAppDo();
		((PnlPlnrStkRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPO1NARRAYDATA) {
		req->dpchapp = new PnlPlnrTpo1NArray::DpchAppData();
		((PnlPlnrTpo1NArray::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPO1NARRAYDO) {
		req->dpchapp = new PnlPlnrTpo1NArray::DpchAppDo();
		((PnlPlnrTpo1NArray::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPODETAILDATA) {
		req->dpchapp = new PnlPlnrTpoDetail::DpchAppData();
		((PnlPlnrTpoDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPODETAILDO) {
		req->dpchapp = new PnlPlnrTpoDetail::DpchAppDo();
		((PnlPlnrTpoDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPODO) {
		req->dpchapp = new CrdPlnrTpo::DpchAppDo();
		((CrdPlnrTpo::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPOHK1NRETICLEDATA) {
		req->dpchapp = new PnlPlnrTpoHk1NReticle::DpchAppData();
		((PnlPlnrTpoHk1NReticle::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPOHK1NRETICLEDO) {
		req->dpchapp = new PnlPlnrTpoHk1NReticle::DpchAppDo();
		((PnlPlnrTpoHk1NReticle::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPOLISTDATA) {
		req->dpchapp = new PnlPlnrTpoList::DpchAppData();
		((PnlPlnrTpoList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPOLISTDO) {
		req->dpchapp = new PnlPlnrTpoList::DpchAppDo();
		((PnlPlnrTpoList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPOMNPROJECTDATA) {
		req->dpchapp = new PnlPlnrTpoMNProject::DpchAppData();
		((PnlPlnrTpoMNProject::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPOMNPROJECTDO) {
		req->dpchapp = new PnlPlnrTpoMNProject::DpchAppDo();
		((PnlPlnrTpoMNProject::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRTPORECDO) {
		req->dpchapp = new PnlPlnrTpoRec::DpchAppDo();
		((PnlPlnrTpoRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGAACCESSDATA) {
		req->dpchapp = new PnlPlnrUsgAAccess::DpchAppData();
		((PnlPlnrUsgAAccess::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGAACCESSDO) {
		req->dpchapp = new PnlPlnrUsgAAccess::DpchAppDo();
		((PnlPlnrUsgAAccess::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGDETAILDATA) {
		req->dpchapp = new PnlPlnrUsgDetail::DpchAppData();
		((PnlPlnrUsgDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGDETAILDO) {
		req->dpchapp = new PnlPlnrUsgDetail::DpchAppDo();
		((PnlPlnrUsgDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGDO) {
		req->dpchapp = new CrdPlnrUsg::DpchAppDo();
		((CrdPlnrUsg::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGLISTDATA) {
		req->dpchapp = new PnlPlnrUsgList::DpchAppData();
		((PnlPlnrUsgList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGLISTDO) {
		req->dpchapp = new PnlPlnrUsgList::DpchAppDo();
		((PnlPlnrUsgList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGMNUSERDATA) {
		req->dpchapp = new PnlPlnrUsgMNUser::DpchAppData();
		((PnlPlnrUsgMNUser::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGMNUSERDO) {
		req->dpchapp = new PnlPlnrUsgMNUser::DpchAppDo();
		((PnlPlnrUsgMNUser::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSGRECDO) {
		req->dpchapp = new PnlPlnrUsgRec::DpchAppDo();
		((PnlPlnrUsgRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSR1NSESSIONDATA) {
		req->dpchapp = new PnlPlnrUsr1NSession::DpchAppData();
		((PnlPlnrUsr1NSession::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSR1NSESSIONDO) {
		req->dpchapp = new PnlPlnrUsr1NSession::DpchAppDo();
		((PnlPlnrUsr1NSession::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRAACCESSDATA) {
		req->dpchapp = new PnlPlnrUsrAAccess::DpchAppData();
		((PnlPlnrUsrAAccess::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRAACCESSDO) {
		req->dpchapp = new PnlPlnrUsrAAccess::DpchAppDo();
		((PnlPlnrUsrAAccess::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRDETAILDATA) {
		req->dpchapp = new PnlPlnrUsrDetail::DpchAppData();
		((PnlPlnrUsrDetail::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRDETAILDO) {
		req->dpchapp = new PnlPlnrUsrDetail::DpchAppDo();
		((PnlPlnrUsrDetail::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRDO) {
		req->dpchapp = new CrdPlnrUsr::DpchAppDo();
		((CrdPlnrUsr::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRLISTDATA) {
		req->dpchapp = new PnlPlnrUsrList::DpchAppData();
		((PnlPlnrUsrList::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRLISTDO) {
		req->dpchapp = new PnlPlnrUsrList::DpchAppDo();
		((PnlPlnrUsrList::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRMNUSERGROUPDATA) {
		req->dpchapp = new PnlPlnrUsrMNUsergroup::DpchAppData();
		((PnlPlnrUsrMNUsergroup::DpchAppData*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRMNUSERGROUPDO) {
		req->dpchapp = new PnlPlnrUsrMNUsergroup::DpchAppDo();
		((PnlPlnrUsrMNUsergroup::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRRECDO) {
		req->dpchapp = new PnlPlnrUsrRec::DpchAppDo();
		((PnlPlnrUsrRec::DpchAppDo*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHAPPROOTPLNRLOGIN) {
		req->dpchapp = new RootPlnr::DpchAppLogin();
		((RootPlnr::DpchAppLogin*) (req->dpchapp))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixPlnrVDpch;
};

void PlnrcmbdAppsrv::writeDpchEng(
			XchgPlnrcmbd* xchg
			, ReqPlnr* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);

	if (req->dpcheng) {
		req->dpcheng->writeXML(req->ixPlnrVLocale, &(xchg->mScr), xchg->scr, xchg->descr, wr);
	} else {
		DpchEngPlnrConfirm dpchconfirm(false, req->jref, "");
		dpchconfirm.writeXML(req->ixPlnrVLocale, &(xchg->mScr), xchg->scr, xchg->descr, wr);
	};

	closewriteBuffer(wr);

	req->replylen = buf->use;
	req->reply = new char[req->replylen];
	memcpy(req->reply, buf->content, req->replylen);

	xmlBufferFree(buf);
};


