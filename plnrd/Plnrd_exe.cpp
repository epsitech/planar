/**
  * \file Plnrd_exe.cpp
  * Plnr daemon main (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnrd.h"

#include "Plnrd_exe.h"

/******************************************************************************
 class PrefPlnrd
 ******************************************************************************/

PrefPlnrd::PrefPlnrd(
			StgPlnrd* stgplnrd
			, StgPlnrDatabase* stgplnrdatabase
			, StgPlnrPath* stgplnrpath
			, const set<uint>& mask
		) : Block() {
	if (stgplnrd) this->stgplnrd = *stgplnrd;
	if (stgplnrdatabase) this->stgplnrdatabase = *stgplnrdatabase;
	if (stgplnrpath) this->stgplnrpath = *stgplnrpath;

	if (find(mask, ALL)) this->mask = {STGPLNRD, STGPLNRDATABASE, STGPLNRPATH};
	else this->mask = mask;
};

bool PrefPlnrd::all(
			const set<uint>& items
		) {
	if (!find(items, STGPLNRD)) return false;
	if (!find(items, STGPLNRDATABASE)) return false;
	if (!find(items, STGPLNRPATH)) return false;

	return true;
};

void PrefPlnrd::readXMLFromFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/", true);

	closeParsed(doc, docctx);
};

void PrefPlnrd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PrefPlnrd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (stgplnrd.readXML(docctx, basexpath, true)) add(STGPLNRD);
		if (stgplnrdatabase.readXML(docctx, basexpath, true)) add(STGPLNRDATABASE);
		if (stgplnrpath.readXML(docctx, basexpath, true)) add(STGPLNRPATH);
	} else {
		stgplnrd = StgPlnrd();
		stgplnrdatabase = StgPlnrDatabase();
		stgplnrpath = StgPlnrPath();
	};
};

void PrefPlnrd::writeXMLToFile(
			const string& fullpath
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr);
	closewriteFile(wr);
};

void PrefPlnrd::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "PrefPlnrd");
		if (has(STGPLNRD)) stgplnrd.writeXML(wr);
		if (has(STGPLNRDATABASE)) stgplnrdatabase.writeXML(wr);
		if (has(STGPLNRPATH)) stgplnrpath.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class Plnrd
 ******************************************************************************/

Plnrd::Plnrd(
			const string& exedir
		) {
	this->exedir = exedir;

	jrefCmd = 0;

	xchg = NULL;
	
	root = NULL;

	opengconsrv = NULL;
	appsrv = NULL;

	curlrecv = NULL;
	curlrecvlen = 0;

	initdone = false;
	init();
};

Plnrd::~Plnrd() {
	term();
};

void Plnrd::init() {
	pthread_attr_t attr;

	srand(time(NULL));

	// 1. create exchange object
	xchg = new XchgPlnrd();

	// 2. establish root job
	root = new RootPlnr(xchg);
	xchg->jrefRoot = root->jref;
	jrefCmd = xchg->jrefRoot;

	// 3. load preferences
	loadPref();

	// 4. initialize exchange data objects
	initXchgdataJobprc();

	// 5. connect to database
	dbsplnr.init(xchg->stgplnrdatabase.ixDbsVDbstype, "", xchg->stgplnrdatabase.dbsname, xchg->stgplnrdatabase.ip
			, xchg->stgplnrdatabase.port, xchg->stgplnrdatabase.username, xchg->stgplnrdatabase.password);

	// 6. clear query tables (within root job)
	root->clearQtb(&dbsplnr);

	// 7. start op engine client thread
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&opengcli, &attr, &PlnrdOpengcli::run, (void*) xchg);

	// 8. start job processor threads
	for (unsigned int i=0;i<xchg->stgplnrd.jobprcn;i++) {
		// thread
		jobprcs.push_back(0);
		pthread_create(&(jobprcs[i]), &attr, &PlnrdJobprc::run, (void*) xchg);
	};

	pthread_attr_destroy(&attr);

	// 9. start op engine connect server
	opengconsrv = PlnrdOpengconsrv::start(xchg);

	// 10. start web server
	appsrv = PlnrdAppsrv::start(xchg);

	initdone = true;
};

void Plnrd::term() {
	NodePlnr* node = NULL;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	if (initdone) {
		// 1. stop web server
		PlnrdAppsrv::stop(appsrv);

		// 2. stop op engine connect server
		PlnrdOpengconsrv::stop(opengconsrv);

		// 3. cURL to all nodes (PlnropdEngsrv) with DpchPlnrdQuit
		for (auto it=xchg->nodes.begin();it!=xchg->nodes.end();it++) {
			node = it->second;

			// POST content (DpchPlnrdQuit)
			Xmlio::startwriteBuffer(&wr, &xbuf);
				DpchPlnrdQuit::writeXML(wr);
			Xmlio::closewriteBuffer(wr);

			if (CurlPostDpch("http://" + node->ip + ":" + to_string(node->port) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
				// evaluate reply
				if (rplydpch.compare("dpchplnropdack") == 0) {
					// acknowledged
				};

			} else {
				// cout << "\terror notifying op engine!" << endl;
			};

			if (docctx) xmlXPathFreeContext(docctx);
			if (doc) xmlFreeDoc(doc);
			xmlBufferFree(xbuf);
		};

		// 4. end job processor threads
		for (unsigned int i=0;i<jobprcs.size();i++) {
			//if (jobprcs[i]) {
				pthread_cancel(jobprcs[i]);
				pthread_join(jobprcs[i], NULL);
			//};
		};

		// 5. end op engine client thread
		pthread_cancel(opengcli);
		pthread_join(opengcli, NULL);

		// 6. clean-up exchange data objects
		termXchgdataJobprc();

		// 7. store preferences
		storePref();

		// 8. delete root job
		delete root;
		root = NULL;
		xchg->jrefRoot = 0;

		// 9. delete exchange object
		delete xchg;
	};
};

uint Plnrd::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _inst
		) {
	Plnrd* inst = (Plnrd*) _inst;

	char* olddata;

	if (size > 0) {
		if (!inst->curlrecv) {
			inst->curlrecv = new char[size*blocksize];
			memcpy(inst->curlrecv, data, size*blocksize);
			inst->curlrecvlen = size*blocksize;

		} else {
			olddata = inst->curlrecv;

			inst->curlrecv = new char[inst->curlrecvlen + size*blocksize];
			memcpy(inst->curlrecv, olddata, inst->curlrecvlen);
			memcpy(&(inst->curlrecv[inst->curlrecvlen]), data, size*blocksize);
			inst->curlrecvlen = inst->curlrecvlen + size*blocksize;

			delete[] olddata;
		};
	};

  return(size*blocksize);
};

bool Plnrd::CurlPostDpch(
			const string& url
			, xmlBuffer* xbuf
			, xmlDoc** rplydoc
			, xmlXPathContext** rplydocctx
			, string& rplydpch
		) {
	CURL* curl;
	CURLcode res;

	bool retval = false;

	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		// receive buffer
		if (curlrecv) delete[] curlrecv;
		curlrecv = NULL;
		curlrecvlen = 0;

		// string to be sent is "xml=<xbuf>"
		size_t buflen = xbuf->use + 4;
		char* buf = new char[buflen];

		buf[0] = 'x'; buf[1] = 'm'; buf[2] = 'l'; buf[3] = '=';
		memcpy(&(buf[4]), xbuf->content, xbuf->use);

		// strip '\r' and '\n' characters
		for (size_t i=0;i<buflen;) {
			if ((buf[i] == '\r') || (buf[i] == '\n')) {
				memmove(&(buf[i]), &(buf[i+1]), buflen-i-1);
				buflen--;
			} else i++;
		};

		// curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, buf);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, buflen);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);

		res = curl_easy_perform(curl);

		delete[] buf;

		curl_easy_cleanup(curl);

		// evaluate result
		if (curlrecv) {
			if (res == 0) {
				// check for root XML node
				Xmlio::parseBuffer(curlrecv, curlrecvlen, rplydoc, rplydocctx);
				rplydpch = StrMod::lc(Xmlio::extractRoot(*rplydoc));
				retval = true;
			};

			delete[] curlrecv;
			curlrecv = NULL;
			curlrecvlen = 0;
		};
	};

	return retval;
};

void Plnrd::loadPref() {
	PrefPlnrd pref;

	pref.readXMLFromFile(exedir + "/PrefPlnrd.xml");

	xchg->stgplnrd = pref.stgplnrd;
	xchg->stgplnrdatabase = pref.stgplnrdatabase;
	xchg->stgplnrpath = pref.stgplnrpath;

	xchg->acvpath = xchg->stgplnrpath.acvpath;
	xchg->tmppath = xchg->stgplnrpath.tmppath;
	xchg->helpurl = xchg->stgplnrpath.helpurl;
};

void Plnrd::storePref() {
	PrefPlnrd pref(&(xchg->stgplnrd), &(xchg->stgplnrdatabase), &(xchg->stgplnrpath));

	pref.writeXMLToFile(exedir + "/PrefPlnrd.xml");
};

void Plnrd::initXchgdataJobprc() {
// IP initXchgdataJobprc --- INSERT
};

void Plnrd::termXchgdataJobprc() {
// IP termXchgdataJobprc --- INSERT
};

/******************************************************************************
 main program
 ******************************************************************************/

void showSubjobs(
			XchgPlnrd* xchg
			, JobPlnr* job
			, bool clstns
			, bool ops
			, bool presets
			, bool dcolcont
			, bool stmgrcont
			, unsigned int indent
		) {
	string id;

	// http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	DcolPlnr* dcol = NULL;
	StmgrPlnr* stmgr = NULL;

	vector<uint> icsPlnrVCall;
	vector<uint> icsVJobmask;

	vector<uint> icsPlnrVPreset;
	vector<Arg> args;

	// indentation
	for (unsigned int i=0;i<indent;i++) id = id + "\t";

	// actual entry
	if (job->jrefsSub.empty()) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";
	cout << VecPlnrVJob::getSref(job->ixPlnrVJob);

	if (job->jrefMast == job->jref) cout << "/M";
	else if (job->jrefMast != 0) cout << "/S";

	cout << " (" << job->jref;

	dcol = xchg->getDcolByJref(job->jref, false);
	if (dcol) {
		cout << ", dcol";
		dcol->unlockAccess("", "showSubjobs");
	};

	stmgr = xchg->getStmgrByJref(job->jref);
	if (stmgr) {
		cout << ", stmgr";
		stmgr->unlockAccess("", "showSubjobs");
	};

	cout << ")" << endl;

	if (clstns) {
		// call listeners
		cout << setgray;

		xchg->getClstnsByJref(job->jref, false, icsPlnrVCall, icsVJobmask);
		for (unsigned int i=0;i<icsPlnrVCall.size();i++)
					cout << "\t\t" << id << VecPlnrVCall::getSref(icsPlnrVCall[i]) << " (" << Clstn::VecVJobmask::getSref(icsVJobmask[i]) << ")" << endl;

		xchg->getClstnsByJref(job->jref, true, icsPlnrVCall, icsVJobmask);
		for (unsigned int i=0;i<icsPlnrVCall.size();i++)
					cout << "\t\t" << id << "stmgr: " << VecPlnrVCall::getSref(icsPlnrVCall[i]) << endl;

		cout << reset;
	};

	if (ops) {
		// ops
		cout << setgray;

		Mutex::lock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		for (auto it=job->ops.begin();it!=job->ops.end();it++)
					cout << "\t\t" << id << VecPlnrVDpch::getSref((*it)->ixVDpch).substr(4+3) << " (" << to_string((*it)->oref) << "): " << (*it)->squawk << endl;

		Mutex::unlock(&(job->mOps), "job(" + to_string(job->jref) + ")->mOps", "", "showSubjobs");

		cout << reset;
	};

	if (presets) {
		// presettings
		cout << setgray;

		xchg->getPresetsByJref(job->jref, icsPlnrVPreset, args);

		for (unsigned int i=0;i<icsPlnrVPreset.size();i++)
					cout << "\t\t" << id << VecPlnrVPreset::getSref(icsPlnrVPreset[i]) << ": " << args[i].writeText() << endl;

		cout << reset;
	};

	if (dcolcont) {
		// dispatch collector content
		dcol = xchg->getDcolByJref(job->jref, false);

		if (dcol) {
			cout << setgray;

			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();it++)
						cout << "\t\t" << id << VecPlnrVDpch::getSref((*it)->ixPlnrVDpch) << " (" << (*it)->jref << ")" << endl;

			dcol->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	if (stmgrcont) {
		// stub manager content
		stmgr = xchg->getStmgrByJref(job->jref);

		if (stmgr) {
			cout << setgray;

			for (auto it=stmgr->stcch->nodes.begin();it!=stmgr->stcch->nodes.end();it++)
						cout << "\t\t" << id << VecPlnrVStub::getSref(it->second->stref.ixVStub) << " (" << it->second->stref.ref << "): " << it->second->stub << endl;

			stmgr->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	// sub-entries
	JobPlnr* subjob;
	for (auto it=job->jrefsSub.begin();it!=job->jrefsSub.end();it++) {
		subjob = xchg->getJobByJref(*it);
		if (subjob) showSubjobs(xchg, subjob, clstns, ops, presets, dcolcont, stmgrcont, indent+1);
	};
};

void handleSignal(
			int sig
		) {
	// deleting plnrd forces PrefPlnrd to be written
	if (plnrd) delete plnrd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	bool nocp = false;

	char* buf = NULL;
	string exedir;
	size_t ptr;

	pthread_mutex_t mcDummy;
	pthread_cond_t cDummy;

	string cmd;

	string input;
	int iinput;

	string s, s_backup;

	XchgPlnrd* xchg;

	JobPlnr* job;

	ReqPlnr* req;

	timeval now;
	timespec nexttime;

	plnrd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// evaluate command-line options
	for (int i=1;i<argc;i++) if (!nocp) if (strcmp(argv[i], "-nocp") == 0) nocp = true;

	try {
		// determine executable path
		buf = new char[4096];

		if (readlink("/proc/self/exe", buf, 4096) >= 1) {
			exedir = buf;

		} else {
			if (strlen(argv[0]) >= 1) {
				exedir = argv[0];

				if (exedir[0] != '/') {
					if (getcwd(buf, 4096)) {
						exedir = "/" + exedir;
						exedir = buf + exedir;
					};
				};
			};
		};

		delete[] buf;

		ptr = exedir.rfind('/');
		if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);

		// calls plnrd.init()
		plnrd = new Plnrd(exedir);
		xchg = plnrd->xchg;

		if (nocp) {
			// wait on a dummy condition
			Mutex::init(&mcDummy, false, "mcDummy", "", "main");
			Cond::init(&cDummy, "cDummy", "", "main");
			Mutex::lock(&mcDummy, "mcDummy", "", "main");
			Cond::wait(&cDummy, &mcDummy, "cDummy", "", "main");
			Mutex::unlock(&mcDummy, "mcDummy", "", "main");
			Mutex::destroy(&mcDummy, false, "mcDummy", "", "main");
			Cond::destroy(&cDummy, "cDummy", "", "main");

		} else {
			// main command loop
			while (cmd.compare("quit") != 0) {
				cout << "Plnrd >> ";
				cin >> cmd;

				if (cmd.compare("quit") == 0) {

				} else if (cmd.compare("cmdsetStd") == 0) {
					cout << "\tquit" << endl;
					cout << "\tshowNodes" << endl;

					cout << "\tshowJobs" << endl;
					cout << "\tshowSubjobs" << endl;

					cout << "\tgotoJob" << endl;
					cout << "\tgotoSupjob" << endl;

					cout << "\tshowClstns" << endl;
					cout << "\tshowOps" << endl;
					cout << "\tshowPresets" << endl;

					cout << "\tshowDcolContent" << endl;
					cout << "\tshowStmgrContent" << endl;

				} else if (cmd.compare("showNodes") == 0) {
					NodePlnr* node = NULL;

					Mutex::lock(&(xchg->mNodes), "xchg->mNodes", "", "main");

					for (auto it=xchg->nodes.begin();it!=xchg->nodes.end();it++) {
						node = it->second;
						cout << "\tnode " << node->nref << " at " << node->ip << ":" << node->port << " running " << node->opprcn << " op processors" << endl;
					};

					Mutex::unlock(&(xchg->mNodes), "xchg->mNodes", "", "main");

				} else if (cmd.compare("showJobs") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd.compare("showSubjobs") == 0) {
					job = xchg->getJobByJref(xchg->jrefCmd);
					if (job) showSubjobs(xchg, job, false, false, false, false, false, 0);

				} else if (cmd.compare("gotoJob") == 0) {
					cout << "\tjob reference: ";
					cin >> input;
					iinput = atoi(input.c_str());

					job = xchg->getJobByJref(iinput);

					if (job) xchg->jrefCmd = job->jref;
					else cout << "\tjob reference doesn't exist!" << endl;

				} else if (cmd.compare("gotoSupjob") == 0) {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						job = xchg->getJobByJref(job->jrefSup);

						if (job) xchg->jrefCmd = job->jref;
						else cout << "\talready at topmost job!" << endl;
					};

				} else if (cmd.compare("showClstns") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, true, false, false, false, false, 0);

				} else if (cmd.compare("showOps") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, true, false, false, false, 0);

				} else if (cmd.compare("showPresets") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, true, false, false, 0);

				} else if (cmd.compare("showDcolContent") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, true, false, 0);

				} else if (cmd.compare("showStmgrContent") == 0) {
					job = xchg->getJobByJref(xchg->jrefRoot);
					if (job) showSubjobs(xchg, job, false, false, false, false, true, 0);

				} else {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						req = new ReqPlnr(ReqPlnr::VecVBasetype::CMD, ReqPlnr::VecVState::RECEIVE);
						req->cmd = cmd;
						req->jref = xchg->jrefCmd;

						gettimeofday(&now, NULL);
						nexttime.tv_sec = now.tv_sec + 1;
						nexttime.tv_nsec = 1000*now.tv_usec;

						xchg->addReq(req);

						s_backup = "";

						while (req->ixVState != ReqPlnr::VecVState::REPLY) {
							// wait for job processor to finish or to time out
							Mutex::lock(&(req->mcReady), "req->mcReady", "", "main");
							Cond::timedwait(&(req->cReady), &(req->mcReady), &nexttime, "req->cReady", "", "main");
							Mutex::unlock(&(req->mcReady), "req->mcReady", "", "main");

							if (req->ixVState == ReqPlnr::VecVState::WAITPRC) {
								cout << "\twaiting for processing" << endl;

							} else if (req->ixVState == ReqPlnr::VecVState::PRC) {
								s = job->getSquawk(&(plnrd->dbsplnr));
								if (s.compare(s_backup) != 0) {
									cout << "\t" << s << endl;
									s_backup = s;
								};
							};
							nexttime.tv_sec += 1;
						};

						delete req;
					};
				};
			};
		};

		delete plnrd;

	} catch (DbsException e) {
		cout << e.err << endl;
	};
	
	return(0);
};


