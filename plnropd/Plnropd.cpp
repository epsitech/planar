/**
  * \file Plnropd.cpp
  * inter-thread exchange object for Plnr operation daemon plnropd (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnropd.h"

/******************************************************************************
 class DpchPlnrdReg
 ******************************************************************************/

DpchPlnrdReg::DpchPlnrdReg() : DpchPlnr(VecPlnrVDpch::DPCHPLNRDREG) {
};

bool DpchPlnrdReg::all(
			const set<uint>& items
		) {
	if (!find(items, SCRNREF)) return false;

	return true;
};

void DpchPlnrdReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchPlnrdReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) add(SCRNREF);
	};
};

/******************************************************************************
 namespace DpchPlnropdAck
 ******************************************************************************/

void DpchPlnropdAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchPlnropdAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchPlnropdReg
 ******************************************************************************/

void DpchPlnropdReg::writeXML(
			xmlTextWriter* wr
			, const usmallint port
			, const vector<string>& srefsOpk
			, const usmallint opprcn
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchPlnropdReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeUsmallint(wr, "port", port);
		writeStringvec(wr, "srefsOpk", srefsOpk);
		writeUsmallint(wr, "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchPlnropdUnreg
 ******************************************************************************/

void DpchPlnropdUnreg::writeXML(
			xmlTextWriter* wr
			, const string& scrNref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchPlnropdUnreg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrNref", scrNref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class StgPlnrDatabase
 ******************************************************************************/

StgPlnrDatabase::StgPlnrDatabase(
			const uint ixDbsVDbstype
			, const string& dbspath
			, const string& dbsname
			, const string& username
			, const string& password
			, const string& ip
			, const usmallint port
		) : Block() {
	this->ixDbsVDbstype = ixDbsVDbstype;
	this->dbspath = dbspath;
	this->dbsname = dbsname;
	this->username = username;
	this->password = password;
	this->ip = ip;
	this->port = port;
	mask = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
};

bool StgPlnrDatabase::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxDbsVDbstype;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgPlnrDatabase");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemPlnrDatabase";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxDbsVDbstype", srefIxDbsVDbstype)) {
			ixDbsVDbstype = VecDbsVDbstype::getIx(srefIxDbsVDbstype);
			add(IXDBSVDBSTYPE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbspath", dbspath)) add(DBSPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dbsname", dbsname)) add(DBSNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ip", ip)) add(IP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "port", port)) add(PORT);
	};

	return basefound;
};

void StgPlnrDatabase::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgPlnrDatabase";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemPlnrDatabase";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "srefIxDbsVDbstype", VecDbsVDbstype::getSref(ixDbsVDbstype));
		writeStringAttr(wr, itemtag, "sref", "dbspath", dbspath);
		writeStringAttr(wr, itemtag, "sref", "dbsname", dbsname);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
		writeStringAttr(wr, itemtag, "sref", "ip", ip);
		writeUsmallintAttr(wr, itemtag, "sref", "port", port);
	xmlTextWriterEndElement(wr);
};

set<uint> StgPlnrDatabase::comm(
			const StgPlnrDatabase* comp
		) {
	set<uint> items;

	if (ixDbsVDbstype == comp->ixDbsVDbstype) insert(items, IXDBSVDBSTYPE);
	if (dbspath == comp->dbspath) insert(items, DBSPATH);
	if (dbsname == comp->dbsname) insert(items, DBSNAME);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);
	if (ip == comp->ip) insert(items, IP);
	if (port == comp->port) insert(items, PORT);

	return(items);
};

set<uint> StgPlnrDatabase::diff(
			const StgPlnrDatabase* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXDBSVDBSTYPE, DBSPATH, DBSNAME, USERNAME, PASSWORD, IP, PORT};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgPlnropd
 ******************************************************************************/

StgPlnropd::StgPlnropd(
			const string& engcliip
			, const usmallint engcliport
			, const usmallint engsrvport
			, const usmallint opprcn
		) : Block() {
	this->engcliip = engcliip;
	this->engcliport = engcliport;
	this->engsrvport = engsrvport;
	this->opprcn = opprcn;
	mask = {ENGCLIIP, ENGCLIPORT, ENGSRVPORT, OPPRCN};
};

bool StgPlnropd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgPlnropd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemPlnropd";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engcliip", engcliip)) add(ENGCLIIP);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engcliport", engcliport)) add(ENGCLIPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engsrvport", engsrvport)) add(ENGSRVPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opprcn", opprcn)) add(OPPRCN);
	};

	return basefound;
};

void StgPlnropd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgPlnropd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemPlnropd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engcliip", engcliip);
		writeUsmallintAttr(wr, itemtag, "sref", "engcliport", engcliport);
		writeUsmallintAttr(wr, itemtag, "sref", "engsrvport", engsrvport);
		writeUsmallintAttr(wr, itemtag, "sref", "opprcn", opprcn);
	xmlTextWriterEndElement(wr);
};

set<uint> StgPlnropd::comm(
			const StgPlnropd* comp
		) {
	set<uint> items;

	if (engcliip == comp->engcliip) insert(items, ENGCLIIP);
	if (engcliport == comp->engcliport) insert(items, ENGCLIPORT);
	if (engsrvport == comp->engsrvport) insert(items, ENGSRVPORT);
	if (opprcn == comp->opprcn) insert(items, OPPRCN);

	return(items);
};

set<uint> StgPlnropd::diff(
			const StgPlnropd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ENGCLIIP, ENGCLIPORT, ENGSRVPORT, OPPRCN};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class StgPlnrPath
 ******************************************************************************/

StgPlnrPath::StgPlnrPath(
			const string& acvpath
			, const string& tmppath
			, const string& webpath
			, const string& helpurl
		) : Block() {
	this->acvpath = acvpath;
	this->tmppath = tmppath;
	this->webpath = webpath;
	this->helpurl = helpurl;
	mask = {ACVPATH, TMPPATH, WEBPATH, HELPURL};
};

bool StgPlnrPath::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgPlnrPath");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemPlnrPath";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "acvpath", acvpath)) add(ACVPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "tmppath", tmppath)) add(TMPPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "webpath", webpath)) add(WEBPATH);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "helpurl", helpurl)) add(HELPURL);
	};

	return basefound;
};

void StgPlnrPath::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgPlnrPath";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemPlnrPath";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "acvpath", acvpath);
		writeStringAttr(wr, itemtag, "sref", "tmppath", tmppath);
		writeStringAttr(wr, itemtag, "sref", "webpath", webpath);
		writeStringAttr(wr, itemtag, "sref", "helpurl", helpurl);
	xmlTextWriterEndElement(wr);
};

set<uint> StgPlnrPath::comm(
			const StgPlnrPath* comp
		) {
	set<uint> items;

	if (acvpath == comp->acvpath) insert(items, ACVPATH);
	if (tmppath == comp->tmppath) insert(items, TMPPATH);
	if (webpath == comp->webpath) insert(items, WEBPATH);
	if (helpurl == comp->helpurl) insert(items, HELPURL);

	return(items);
};

set<uint> StgPlnrPath::diff(
			const StgPlnrPath* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ACVPATH, TMPPATH, WEBPATH, HELPURL};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class ReqopPlnr
 ******************************************************************************/

ReqopPlnr::ReqopPlnr(
			const uint ixVState
		) {
	this->ixVState = ixVState;

	pp = NULL;

	Mutex::init(&mcReady, false, "mcReady", "ReqopPlnr", "ReqopPlnr");
	Cond::init(&cReady, "cReady", "ReqopPlnr", "ReqopPlnr");

	request = NULL;
	requestlen = 0;

	dpchinv = NULL;

	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopPlnr::~ReqopPlnr() {
	if (pp) MHD_destroy_post_processor(pp);

	Mutex::destroy(&mcReady, false, "mcReady", "ReqopPlnr", "~ReqopPlnr");
	Cond::destroy(&cReady, "cReady", "ReqopPlnr", "~ReqopPlnr");

	if (request) delete[] request;

	if (dpchinv) delete dpchinv;

	if (dpchret) delete dpchret;

	if (reply) delete[] reply;
};

/******************************************************************************
 class XchgdataPlnrOpprc
 ******************************************************************************/

XchgdataPlnrOpprc::XchgdataPlnrOpprc() {
};

/******************************************************************************
 class XchgPlnropd
 ******************************************************************************/

XchgPlnropd::XchgPlnropd() {
// IP constructor.data --- INSERT

	// log file
	Mutex::init(&mLogfile, true, "mLogfile", "XchgPlnropd", "XchgPlnropd");

	// condition for termination
	Mutex::init(&mcTerm, true, "mcTerm", "XchgPlnropd", "XchgPlnropd");
	Cond::init(&cTerm, "cTerm", "XchgPlnropd", "XchgPlnropd");

	// condition for op processors
	Mutex::init(&mcOpprcs, true, "mcOpprcs", "XchgPlnropd", "XchgPlnropd");
	Cond::init(&cOpprcs, "cOpprcs", "XchgPlnropd", "XchgPlnropd");

	// request list
	Mutex::init(&mReqs, true, "mReqs", "XchgPlnropd", "XchgPlnropd");
};

XchgPlnropd::~XchgPlnropd() {
	// empty out lists
	for (auto it=reqs.begin();it!=reqs.end();it++) delete(*it);

	// condition for termination
	Mutex::destroy(&mcTerm, true, "mcTerm", "XchgPlnropd", "~XchgPlnropd");
	Cond::destroy(&cTerm, "cTerm", "XchgPlnropd", "~XchgPlnropd");

	// condition for op processors
	Mutex::destroy(&mcOpprcs, true, "mcOpprcs", "XchgPlnropd", "~XchgPlnropd");
	Cond::destroy(&cOpprcs, "cOpprcs", "XchgPlnropd", "~XchgPlnropd");

	// request list
	Mutex::destroy(&mReqs, true, "mReqs", "XchgPlnropd", "~XchgPlnropd");
};

// IP cust --- INSERT

void XchgPlnropd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	Mutex::lock(&mLogfile, "mLogfile", "XchgPlnropd", "appendToLogfile");

	time(&rawtime);

	logfile.open("./log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	Mutex::unlock(&mLogfile, "mLogfile", "XchgPlnropd", "appendToLogfile");
};

void XchgPlnropd::addReq(
			ReqopPlnr* req
		) {
	Mutex::lock(&mReqs, "mReqs", "XchgPlnropd", "addReq");

	req->ixVState = ReqopPlnr::VecVState::WAITPRC;
	reqs.push_back(req);

	Mutex::unlock(&mReqs, "mReqs", "XchgPlnropd", "addReq");

	Cond::broadcast(&cOpprcs, "cOpprcs", "XchgPlnropd", "addReq");
};

ReqopPlnr* XchgPlnropd::pullFirstReq() {
	ReqopPlnr* req;

	// get first element from list
	Mutex::lock(&mReqs, "mReqs", "XchgPlnropd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqopPlnr::VecVState::PRC;
		reqs.pop_front();
	};

	Mutex::unlock(&mReqs, "mReqs", "XchgPlnropd", "pullFirstReq");

	return req;
};


