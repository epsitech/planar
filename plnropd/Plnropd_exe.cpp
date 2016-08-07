/**
  * \file Plnropd_exe.cpp
  * Plnr operation daemon plnropd main (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnropd.h"

#include "Plnropd_exe.h"

/******************************************************************************
 class PrefPlnropd
 ******************************************************************************/

PrefPlnropd::PrefPlnropd(
			StgPlnrDatabase* stgplnrdatabase
			, StgPlnropd* stgplnropd
			, StgPlnrPath* stgplnrpath
			, const set<uint>& mask
		) : Block() {
	if (stgplnrdatabase) this->stgplnrdatabase = *stgplnrdatabase;
	if (stgplnropd) this->stgplnropd = *stgplnropd;
	if (stgplnrpath) this->stgplnrpath = *stgplnrpath;

	if (find(mask, ALL)) this->mask = {STGPLNRDATABASE, STGPLNROPD, STGPLNRPATH};
	else this->mask = mask;
};

bool PrefPlnropd::all(
			const set<uint>& items
		) {
	if (!find(items, STGPLNRDATABASE)) return false;
	if (!find(items, STGPLNROPD)) return false;
	if (!find(items, STGPLNRPATH)) return false;

	return true;
};

void PrefPlnropd::readXMLFromFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/", true);

	closeParsed(doc, docctx);
};

void PrefPlnropd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "PrefPlnropd");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (stgplnrdatabase.readXML(docctx, basexpath, true)) add(STGPLNRDATABASE);
		if (stgplnropd.readXML(docctx, basexpath, true)) add(STGPLNROPD);
		if (stgplnrpath.readXML(docctx, basexpath, true)) add(STGPLNRPATH);
	} else {
		stgplnrdatabase = StgPlnrDatabase();
		stgplnropd = StgPlnropd();
		stgplnrpath = StgPlnrPath();
	};
};

void PrefPlnropd::writeXMLToFile(
			const string& fullpath
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr);
	closewriteFile(wr);
};

void PrefPlnropd::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "PrefPlnropd");
		if (has(STGPLNRDATABASE)) stgplnrdatabase.writeXML(wr);
		if (has(STGPLNROPD)) stgplnropd.writeXML(wr);
		if (has(STGPLNRPATH)) stgplnrpath.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class Plnropd
 ******************************************************************************/

Plnropd::Plnropd(
			const string& exedir
		) {
	this->exedir = exedir;

	xchg = NULL;

	engsrv = NULL;

	curlrecv = NULL;
	curlrecvlen = 0;

	initdone = false;
	init();
};

Plnropd::~Plnropd() {
	term();
};

void Plnropd::init() {
	pthread_attr_t attr;

	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	srand(time(NULL));

	// 1. create exchange object
	xchg = new XchgPlnropd();

	// 3. load preferences
	loadPref();

	// 4. initialize exchange data objects
	initXchgdataOpprc();

	// 5. start op processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (unsigned int i=0;i<xchg->stgplnropd.opprcn;i++) {
		// thread
		opprcs.push_back(0);
		pthread_create(&(opprcs[i]), &attr, &PlnropdOpprc::run, (void*) xchg);
	};

	pthread_attr_destroy(&attr);

	// 6. start engine server
	engsrv = PlnropdEngsrv::start(xchg);

	// 7. cURL to PlnrdOpengconsrv with DpchPlnropdReg to retrieve scrNref (note that this might fail)

	Xmlio::startwriteBuffer(&wr, &xbuf);
		DpchPlnropdReg::writeXML(wr, xchg->stgplnropd.engsrvport, {"PlnrExp","PlnrMeep","PlnrMesh","PlnrPlot","PlnrRast","PlnrWgmode"}, xchg->stgplnropd.opprcn);
	Xmlio::closewriteBuffer(wr);

	if (CurlPostDpch("http://" + xchg->stgplnropd.engcliip + ":" + to_string(xchg->stgplnropd.engcliport) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
		// evaluate reply
		if (rplydpch.compare("dpchplnrdreg") == 0) {
			DpchPlnrdReg* dpchplnrdreg = new DpchPlnrdReg();
			dpchplnrdreg->readXML(docctx, "/", true);

			xchg->scrNref = dpchplnrdreg->scrNref;

			delete dpchplnrdreg;
		};

	} else {
		cout << "\terror connecting to engine!" << endl;
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	xmlBufferFree(xbuf);

	initdone = true;
};

void Plnropd::term() {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;
	string rplydpch;

	if (initdone) {
		// 1. cURL to PlnrdOpengconsrv with DpchPlnrOpengUnreg ; note that this will fail in case the termination was initiated by the engine

		// POST content (DpchPlnropdUnreg)
		Xmlio::startwriteBuffer(&wr, &xbuf);
			DpchPlnropdUnreg::writeXML(wr, xchg->scrNref);
		Xmlio::closewriteBuffer(wr);

		if (CurlPostDpch("http://" + xchg->stgplnropd.engcliip + ":" + to_string(xchg->stgplnropd.engcliport) + "/dpch", xbuf, &doc, &docctx, rplydpch)) {
			// evaluate reply
			if (rplydpch.compare("dpchplnrdack") == 0) {
				// acknowledged
			};

		} else {
			// cout << "\terror disconnecting from engine!" << endl;
		};

		if (docctx) xmlXPathFreeContext(docctx);
		if (doc) xmlFreeDoc(doc);
		xmlBufferFree(xbuf);

		// 2. stop engine server
		PlnropdEngsrv::stop(engsrv);

		// 3. end op processor threads
		for (unsigned int i=0;i<opprcs.size();i++) {
			//if (opprcs[i]) {
				pthread_cancel(opprcs[i]);
				pthread_join(opprcs[i], NULL);
			//};
		};

		// 4. clean-up exchange data objects
		termXchgdataOpprc();

		// 5. store preferences
		storePref();

		// 6. delete exchange object
		delete xchg;
	};
};

uint Plnropd::CurlPostrecv(
			void* data
			, uint size
			, uint blocksize
			, void* _inst
		) {
	Plnropd* inst = (Plnropd*) _inst;

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

bool Plnropd::CurlPostDpch(
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

		//curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

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

void Plnropd::loadPref() {
	PrefPlnropd pref;

	pref.readXMLFromFile(exedir + "/PrefPlnropd.xml");

	xchg->stgplnrdatabase = pref.stgplnrdatabase;
	xchg->stgplnropd = pref.stgplnropd;
	xchg->stgplnrpath = pref.stgplnrpath;

	xchg->acvpath = xchg->stgplnrpath.acvpath;
	xchg->tmppath = xchg->stgplnrpath.tmppath;
	xchg->helpurl = xchg->stgplnrpath.helpurl;
};

void Plnropd::storePref() {
	PrefPlnropd pref(&(xchg->stgplnrdatabase), &(xchg->stgplnropd), &(xchg->stgplnrpath));

	pref.writeXMLToFile(exedir + "/PrefPlnropd.xml");
};

void Plnropd::initXchgdataOpprc() {
// IP initXchgdataOpprc --- INSERT
};

void Plnropd::termXchgdataOpprc() {
// IP termXchgdataOpprc --- INSERT
};

/******************************************************************************
 main program
 ******************************************************************************/

void handleSignal(
			int sig
		) {
	// deleting plnrd forces PrefPlnropd to be written
	if (plnropd) delete plnropd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	char* buf = NULL;
	string exedir;
	size_t ptr;

	XchgPlnropd* xchg;

	plnropd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

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

		// calls plnropd.init()
		plnropd = new Plnropd(exedir);
		xchg = plnropd->xchg;

		// wait on term condition (triggered on termination of plnrd and signals) 
		Mutex::lock(&(xchg->mcTerm), "xchg->mcTerm", "", "main");
		Cond::wait(&(xchg->cTerm), &(xchg->mcTerm), "xchg->cTerm", "", "main");
		Mutex::unlock(&(xchg->mcTerm), "xchg->mcTerm", "", "main");

		delete plnropd;

	} catch (DbsException e) {
		cout << e.err << endl;
	};
	
	return(0);
};


