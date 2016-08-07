/**
  * \file PlnrdOpengcli.cpp
  * operation engine client for Plnr daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnrd.h"

#include "PlnrdOpengcli.h"

/******************************************************************************
 namespace PlnrdOpengcli
 ******************************************************************************/

void* PlnrdOpengcli::run(
			void* arg
		) {
	XchgPlnrd* xchg = (XchgPlnrd*) arg;

	DpchInvPlnr* inv = NULL;
	NodePlnr* node = NULL;

	pthread_t sub = 0;
	PlnrdOpengcli_argsub* argsub = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// main loop: wait for ops in execution list
	while (true) {
		// see if an inv is already here
		xchg->pullFirstInv(&inv, &node);

		while (inv == NULL) {
			// no inv is here ; wait for it
			Mutex::lock(&(xchg->mcOpengcli), "xchg->mcOpengcli", "PlnrdOpengcli", "run");
			Cond::wait(&(xchg->cOpengcli), &(xchg->mcOpengcli), "xchg->cOpengcli", "PlnrdOpengcli", "run");

			xchg->pullFirstInv(&inv, &node);

			Mutex::unlock(&(xchg->mcOpengcli), "xchg->mcOpengcli", "PlnrdOpengcli", "run");
		};

		// launch thread to perform op remotely
		argsub = new PlnrdOpengcli_argsub;
		argsub->xchg = xchg;
		argsub->inv = inv;
		argsub->node = node;

		// the sub-thread will not be joined, thus no corresponding attribute
		pthread_create(&sub, 0, &PlnrdOpengcli_sub::run, (void*) argsub);
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void PlnrdOpengcli::cleanup(
			void* arg
		) {
	XchgPlnrd* xchg = (XchgPlnrd*) arg;

	Mutex::unlock(&(xchg->mcOpengcli), "xchg->mcOpengcli", "PlnrdOpengcli", "cleanup");
};

/******************************************************************************
 namespace PlnrdOpengcli_sub
 ******************************************************************************/

void* PlnrdOpengcli_sub::run(
			void* _arg
		) {
	PlnrdOpengcli_argsub* arg = (PlnrdOpengcli_argsub*) _arg;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);

	// copy content of arg and delete wrapping structure
	XchgPlnrd* xchg = arg->xchg;
	NodePlnr* node = arg->node;
	DpchInvPlnr* inv = arg->inv;

	delete arg;

	// get connection (existing if possible)
	ConopengPlnr* con = node->getCon();

	// reply of cURL operation is to be written in ret
	ReqPlnr* req = new ReqPlnr(ReqPlnr::VecVBasetype::RET);

	req->dpchinv = inv;
	writeDpchInv(xchg, req);

	CURLcode curlres;

	// curl_easy_setopt(con->curl, CURLOPT_VERBOSE, 1);

	curl_easy_setopt(con->curl, CURLOPT_POST, 1);
	curl_easy_setopt(con->curl, CURLOPT_POSTFIELDS, req->request);
	curl_easy_setopt(con->curl, CURLOPT_POSTFIELDSIZE, req->requestlen);

	curl_easy_setopt(con->curl, CURLOPT_WRITEFUNCTION, CurlPostrecv);
	curl_easy_setopt(con->curl, CURLOPT_WRITEDATA, req);

	curlres = curl_easy_perform(con->curl);

	// on transfer done, un-busy connection and node
	Mutex::lock(&(xchg->mNodes), "xchg->mNodes", "PlnrdOpengcli_sub", "run");
	Mutex::lock(&(node->mCons), "node->mCons", "PlnrdOpengcli_sub", "run");

	con->busy = false;
	node->opprcbusy--;

	Mutex::unlock(&(node->mCons), "node->mCons", "PlnrdOpengcli_sub", "run");
	Mutex::unlock(&(xchg->mNodes), "xchg->mNodes", "PlnrdOpengcli_sub", "run");

	// an additional node is available for pending ops
	Cond::broadcast(&(xchg->cOpengcli), "xchg->cOpengcli", "PlnrdOpengcli_sub", "run");

	if ((curlres == 0) && req->reply) {
		// cout << req->reply << endl;
		readDpchRet(xchg, req);
		req->jref = req->dpchret->jref;
		xchg->addReq(req);

	} else {
		// something went wrong, return inv to list
		xchg->returnInv(inv);

		req->dpchinv = NULL;
		delete req;
	};

	return(NULL);
};

uint PlnrdOpengcli_sub::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _req
		) {
	ReqPlnr* req = (ReqPlnr*) _req;

	char* olddata;

	if (size > 0) {
		if (!req->reply) {
			req->reply = new char[size*blocksize];
			memcpy(req->reply, data, size*blocksize);
			req->replylen = size*blocksize;

		} else {
			olddata = req->reply;

			req->reply = new char[req->replylen + size*blocksize];
			memcpy(req->reply, olddata, req->replylen);
			memcpy(&(req->reply[req->replylen]), data, size*blocksize);
			req->replylen = req->replylen + size*blocksize;

			delete[] olddata;
		};
	};

  return(size*blocksize);
};

uint PlnrdOpengcli_sub::readDpchRet(
			XchgPlnrd* xchg
			, ReqPlnr* req
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseBuffer(req->reply, req->replylen, &doc, &docctx);

	uint ixPlnrVDpch = VecPlnrVDpch::getIx(extractRoot(doc));

	if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNR) {
		req->dpchret = new DpchRetPlnr();
		((DpchRetPlnr*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDAT1DGNU) {
		req->dpchret = new DpchRetPlnrPlotDat1dgnu();
		((DpchRetPlnrPlotDat1dgnu*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDAT1DGNUMULT) {
		req->dpchret = new DpchRetPlnrPlotDat1dgnumult();
		((DpchRetPlnrPlotDat1dgnumult*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDEVSVG) {
		req->dpchret = new DpchRetPlnrPlotDevsvg();
		((DpchRetPlnrPlotDevsvg*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT1DGNU) {
		req->dpchret = new DpchRetPlnrPlotDomdat1dgnu();
		((DpchRetPlnrPlotDomdat1dgnu*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DGNU) {
		req->dpchret = new DpchRetPlnrPlotDomdat2dgnu();
		((DpchRetPlnrPlotDomdat2dgnu*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DPNG) {
		req->dpchret = new DpchRetPlnrPlotDomdat2dpng();
		((DpchRetPlnrPlotDomdat2dpng*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DVID) {
		req->dpchret = new DpchRetPlnrPlotDomdat2dvid();
		((DpchRetPlnrPlotDomdat2dvid*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDOMZCSSVG) {
		req->dpchret = new DpchRetPlnrPlotDomzcssvg();
		((DpchRetPlnrPlotDomzcssvg*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDSNXYSVG) {
		req->dpchret = new DpchRetPlnrPlotDsnxysvg();
		((DpchRetPlnrPlotDsnxysvg*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTDSNZSVG) {
		req->dpchret = new DpchRetPlnrPlotDsnzsvg();
		((DpchRetPlnrPlotDsnzsvg*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTSTKSVG) {
		req->dpchret = new DpchRetPlnrPlotStksvg();
		((DpchRetPlnrPlotStksvg*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTTPOSVG) {
		req->dpchret = new DpchRetPlnrPlotTposvg();
		((DpchRetPlnrPlotTposvg*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRPLOTTPOTXT) {
		req->dpchret = new DpchRetPlnrPlotTpotxt();
		((DpchRetPlnrPlotTpotxt*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRRASTCUB) {
		req->dpchret = new DpchRetPlnrRastCub();
		((DpchRetPlnrRastCub*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRRASTXYBOX) {
		req->dpchret = new DpchRetPlnrRastXybox();
		((DpchRetPlnrRastXybox*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRRASTZLINE) {
		req->dpchret = new DpchRetPlnrRastZline();
		((DpchRetPlnrRastZline*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRWGMODEFD1D) {
		req->dpchret = new DpchRetPlnrWgmodeFd1d();
		((DpchRetPlnrWgmodeFd1d*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	} else if (ixPlnrVDpch == VecPlnrVDpch::DPCHRETPLNRWGMODEFD2D) {
		req->dpchret = new DpchRetPlnrWgmodeFd2d();
		((DpchRetPlnrWgmodeFd2d*) (req->dpchret))->readXML(&(xchg->mScr), xchg->descr, docctx, "/", true);
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixPlnrVDpch;
};

void PlnrdOpengcli_sub::writeDpchInv(
			XchgPlnrd* xchg
			, ReqPlnr* req
		) {
	xmlBuffer* buf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &buf);
		req->dpchinv->writeXML(&(xchg->mScr), xchg->scr, xchg->descr, wr);
	closewriteBuffer(wr);

	req->requestlen = buf->use;
	req->request = new char[req->requestlen];
	memcpy(req->request, buf->content, req->requestlen);

		// string to be sent is "xml=<xbuf>"
	req->requestlen = buf->use + 4;
	req->request = new char[req->requestlen];
	req->request[0] = 'x'; req->request[1] = 'm'; req->request[2] = 'l'; req->request[3] = '=';
	memcpy(&(req->request[4]), buf->content, buf->use);

	// strip '\r' and '\n' characters
	for (size_t i=0;i<req->requestlen;) {
		if ((req->request[i] == '\r') || (req->request[i] == '\n')) {
			memmove(&(req->request[i]), &(req->request[i+1]), req->requestlen-i-1);
			req->requestlen--;
		} else i++;
	};

	xmlBufferFree(buf);
};


