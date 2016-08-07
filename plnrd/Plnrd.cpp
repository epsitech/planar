/**
  * \file Plnrd.cpp
  * inter-thread exchange object for Plnr daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnrd.h"

/******************************************************************************
 namespace DpchPlnrdAck
 ******************************************************************************/

void DpchPlnrdAck::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchPlnrdAck");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchPlnrdQuit
 ******************************************************************************/

void DpchPlnrdQuit::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchPlnrdQuit");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 namespace DpchPlnrdReg
 ******************************************************************************/

void DpchPlnrdReg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
			, const ubigint nref
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchPlnrdReg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrNref", Scr::scramble(mScr, scr, descr, nref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchPlnropdReg
 ******************************************************************************/

DpchPlnropdReg::DpchPlnropdReg() : DpchPlnr(VecPlnrVDpch::DPCHPLNROPDREG) {
};

bool DpchPlnropdReg::all(
			const set<uint>& items
		) {
	if (!find(items, PORT)) return false;
	if (!find(items, SREFSOPK)) return false;
	if (!find(items, OPPRCN)) return false;

	return true;
};

void DpchPlnropdReg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchPlnropdReg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractUsmallintUclc(docctx, basexpath, "port", "", port)) add(PORT);
		if (extractStringvecUclc(docctx, basexpath, "srefsOpk", "", srefsOpk)) add(SREFSOPK);
		if (extractUsmallintUclc(docctx, basexpath, "opprcn", "", opprcn)) add(OPPRCN);
	};
};

/******************************************************************************
 class DpchPlnropdUnreg
 ******************************************************************************/

DpchPlnropdUnreg::DpchPlnropdUnreg() : DpchPlnr(VecPlnrVDpch::DPCHPLNROPDUNREG) {
};

bool DpchPlnropdUnreg::all(
			const set<uint>& items
		) {
	if (!find(items, NREF)) return false;

	return true;
};

void DpchPlnropdUnreg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrNref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchPlnropdUnreg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrNref", "", scrNref)) {
			nref = Scr::descramble(mScr, descr, scrNref);
			add(NREF);
		};
	};
};

/******************************************************************************
 class DpchAppPlnr
 ******************************************************************************/

DpchAppPlnr::DpchAppPlnr(
			const uint ixPlnrVDpch
		) : DpchPlnr(ixPlnrVDpch) {
	jref = 0;
};

DpchAppPlnr::~DpchAppPlnr() {
};

bool DpchAppPlnr::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

void DpchAppPlnr::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	string scrJref;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, VecPlnrVDpch::getSref(ixPlnrVDpch));
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
	};
};

/******************************************************************************
 class DpchAppPlnrAlert
 ******************************************************************************/

DpchAppPlnrAlert::DpchAppPlnrAlert() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRALERT) {
};

bool DpchAppPlnrAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, NUMFMCB)) return false;

	return true;
};

void DpchAppPlnrAlert::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string scrJref;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchAppPlnrAlert");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractUintUclc(docctx, basexpath, "numFMcb", "", numFMcb)) add(NUMFMCB);
	} else {
	};
};

/******************************************************************************
 class DpchAppPlnrInit
 ******************************************************************************/

DpchAppPlnrInit::DpchAppPlnrInit() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRINIT) {
};

/******************************************************************************
 class DpchAppPlnrResume
 ******************************************************************************/

DpchAppPlnrResume::DpchAppPlnrResume() : DpchAppPlnr(VecPlnrVDpch::DPCHAPPPLNRRESUME) {
};

/******************************************************************************
 class DpchEngPlnr
 ******************************************************************************/

DpchEngPlnr::DpchEngPlnr(
			const uint ixPlnrVDpch
			, const ubigint jref
		) : DpchPlnr(ixPlnrVDpch) {
	this->jref = jref;

	mask = {JREF};
};

DpchEngPlnr::~DpchEngPlnr() {
};

bool DpchEngPlnr::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;

	return true;
};

void DpchEngPlnr::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngPlnr* src = dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
};

void DpchEngPlnr::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	string tag = VecPlnrVDpch::getSref(ixPlnrVDpch);

	xmlTextWriterStartElement(wr, BAD_CAST tag.c_str());
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngPlnrAck
 ******************************************************************************/

DpchEngPlnrAck::DpchEngPlnrAck(
			const ubigint jref
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRACK, jref) {
};

/******************************************************************************
 class DpchEngPlnrAlert
 ******************************************************************************/

DpchEngPlnrAlert::DpchEngPlnrAlert(
			const ubigint jref
			, ContInfPlnrAlert* continf
			, Feed* feedFMcb
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRALERT, jref) {
	if (continf) this->continf = *continf;
	if (feedFMcb) this->feedFMcb = *feedFMcb;

	if (find(mask, ALL)) this->mask = {JREF, CONTINF, FEEDFMCB};
	else this->mask = mask;
};

bool DpchEngPlnrAlert::all(
			const set<uint>& items
		) {
	if (!find(items, JREF)) return false;
	if (!find(items, CONTINF)) return false;
	if (!find(items, FEEDFMCB)) return false;

	return true;
};

void DpchEngPlnrAlert::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngPlnrAlert* src = (DpchEngPlnrAlert*) dpcheng;

	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(CONTINF)) {continf = src->continf; add(CONTINF);};
	if (src->has(FEEDFMCB)) {feedFMcb = src->feedFMcb; add(FEEDFMCB);};
};

void DpchEngPlnrAlert::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrAlert");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(CONTINF)) continf.writeXML(wr);
		if (has(FEEDFMCB)) feedFMcb.writeXML(wr);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngPlnrConfirm
 ******************************************************************************/

DpchEngPlnrConfirm::DpchEngPlnrConfirm(
			const bool accepted
			, const ubigint jref
			, const string& sref
			, const set<uint>& mask
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRCONFIRM, jref) {
	this->accepted = accepted;
	this->jref = jref;
	this->sref = sref;

	if (find(mask, ALL)) this->mask = {ACCEPTED, JREF, SREF};
	else this->mask = mask;
};

bool DpchEngPlnrConfirm::all(
			const set<uint>& items
		) {
	if (!find(items, ACCEPTED)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SREF)) return false;

	return true;
};

void DpchEngPlnrConfirm::merge(
			DpchEngPlnr* dpcheng
		) {
	DpchEngPlnrConfirm* src = (DpchEngPlnrConfirm*) dpcheng;

	if (src->has(ACCEPTED)) {accepted = src->accepted; add(ACCEPTED);};
	if (src->has(JREF)) {jref = src->jref; add(JREF);};
	if (src->has(SREF)) {sref = src->sref; add(SREF);};
};

void DpchEngPlnrConfirm::writeXML(
			const uint ixPlnrVLocale
			, pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchEngPlnrConfirm");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(ACCEPTED)) writeBool(wr, "accepted", accepted);
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		if (has(SREF)) writeString(wr, "sref", sref);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchEngPlnrSuspend
 ******************************************************************************/

DpchEngPlnrSuspend::DpchEngPlnrSuspend(
			const ubigint jref
		) : DpchEngPlnr(VecPlnrVDpch::DPCHENGPLNRSUSPEND, jref) {
};

/******************************************************************************
 class StgPlnrd
 ******************************************************************************/

StgPlnrd::StgPlnrd(
			const usmallint jobprcn
			, const usmallint opengsrvport
			, const usmallint appsrvport
			, const usmallint histlength
		) : Block() {
	this->jobprcn = jobprcn;
	this->opengsrvport = opengsrvport;
	this->appsrvport = appsrvport;
	this->histlength = histlength;
	mask = {JOBPRCN, OPENGSRVPORT, APPSRVPORT, HISTLENGTH};
};

bool StgPlnrd::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgPlnrd");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemPlnrd";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "jobprcn", jobprcn)) add(JOBPRCN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "opengsrvport", opengsrvport)) add(OPENGSRVPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "appsrvport", appsrvport)) add(APPSRVPORT);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "histlength", histlength)) add(HISTLENGTH);
	};

	return basefound;
};

void StgPlnrd::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgPlnrd";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemPlnrd";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "jobprcn", jobprcn);
		writeUsmallintAttr(wr, itemtag, "sref", "opengsrvport", opengsrvport);
		writeUsmallintAttr(wr, itemtag, "sref", "appsrvport", appsrvport);
		writeUsmallintAttr(wr, itemtag, "sref", "histlength", histlength);
	xmlTextWriterEndElement(wr);
};

set<uint> StgPlnrd::comm(
			const StgPlnrd* comp
		) {
	set<uint> items;

	if (jobprcn == comp->jobprcn) insert(items, JOBPRCN);
	if (opengsrvport == comp->opengsrvport) insert(items, OPENGSRVPORT);
	if (appsrvport == comp->appsrvport) insert(items, APPSRVPORT);
	if (histlength == comp->histlength) insert(items, HISTLENGTH);

	return(items);
};

set<uint> StgPlnrd::diff(
			const StgPlnrd* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {JOBPRCN, OPENGSRVPORT, APPSRVPORT, HISTLENGTH};
	for (auto it=commitems.begin();it!=commitems.end();it++) diffitems.erase(*it);

	return(diffitems);
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
 namespace AlrPlnr
 ******************************************************************************/

DpchEngPlnrAlert* AlrPlnr::prepareAlrAbt(
			const ubigint jref
			, const uint ixPlnrVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfPlnrAlert continf;
// IP prepareAlrAbt --- BEGIN
	continf.TxtCpt = VecPlnrVTag::getTitle(VecPlnrVTag::ABOUT, ixPlnrVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		continf.TxtMsg1 = "Planar version 0.1.22 released on 4-12-2015";
		continf.TxtMsg3 = "contributors: Alexander Wirthmueller";
		continf.TxtMsg5 = "libraries: libxml2 2.7.8, libMHD 0.9.16, libcurl 7.24, libmysqlclient 5.5.28, libpq 9.x, libpng 1.5.12, netcdf 4.2.1.1 and meep 1.3";
		continf.TxtMsg7 = "Planar offers parametric design of microelectronic and photonic structures. Both patterns for e-beam lithography (single reticle) and photolithography (multi-dimensional arrays) can be extracted.";
		continf.TxtMsg8 = "Additionally, numerical simulations (including parameter scans) can be run on top of the structures. Currently implemented are Schr\\u00f6dinger-Poisson, FDTD and waveguide mode algorithms.";
		continf.TxtMsg9 = "A material library with hierarchical paramrter inheritance allows for the comparison of various material models / material properties extracred from actual measurements.";
	};

	feedFMcbAlert.clear();

	VecPlnrVTag::appendToFeed(VecPlnrVTag::CLOSE, ixPlnrVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
// IP prepareAlrAbt --- END
	return(new DpchEngPlnrAlert(jref, &continf, &feedFMcbAlert, {DpchEngPlnrAlert::ALL}));
};

DpchEngPlnrAlert* AlrPlnr::prepareAlrPer(
			const ubigint jref
			, const uint ixPlnrVLocale
			, const string& lineno
			, Feed& feedFMcbAlert
		) {
	ContInfPlnrAlert continf;
// IP prepareAlrPer --- BEGIN
	continf.TxtCpt = VecPlnrVTag::getTitle(VecPlnrVTag::ERROR, ixPlnrVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		continf.TxtMsg1 = "Parse error in line " + lineno + ".";
	};

	feedFMcbAlert.clear();

	VecPlnrVTag::appendToFeed(VecPlnrVTag::OK, ixPlnrVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
// IP prepareAlrPer --- END
	return(new DpchEngPlnrAlert(jref, &continf, &feedFMcbAlert, {DpchEngPlnrAlert::ALL}));
};

DpchEngPlnrAlert* AlrPlnr::prepareAlrSav(
			const ubigint jref
			, const uint ixPlnrVLocale
			, Feed& feedFMcbAlert
		) {
	ContInfPlnrAlert continf;
// IP prepareAlrSav --- BEGIN
	continf.TxtCpt = VecPlnrVTag::getTitle(VecPlnrVTag::QUEST, ixPlnrVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (ixPlnrVLocale == VecPlnrVLocale::ENUS) {
		continf.TxtMsg1 = "Save changes?";
	};

	feedFMcbAlert.clear();

	VecPlnrVTag::appendToFeed(VecPlnrVTag::CANCEL, ixPlnrVLocale, feedFMcbAlert);
	VecPlnrVTag::appendToFeed(VecPlnrVTag::FLS, ixPlnrVLocale, feedFMcbAlert);
	VecPlnrVTag::appendToFeed(VecPlnrVTag::TRU, ixPlnrVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();
// IP prepareAlrSav --- END
	return(new DpchEngPlnrAlert(jref, &continf, &feedFMcbAlert, {DpchEngPlnrAlert::ALL}));
};

/******************************************************************************
 class ReqPlnr
 ******************************************************************************/

ReqPlnr::ReqPlnr(
			const uint ixVBasetype
			, const uint ixVState
			, const string& ip
		) {
	this->ixVBasetype = ixVBasetype;
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD)) {
		retain = false;
		Mutex::init(&mcReady, false, "mcReady", "ReqPlnr", "ReqPlnr");
		Cond::init(&cReady, "cReady", "ReqPlnr", "ReqPlnr");

	} else {
		retain = true;
	};

	file = NULL;
	filelen = 0;

	request = NULL;
	requestlen = 0;

	jref = 0;

	wref = 0;

	weak = false;

	dpchapp = NULL;

	dpcheng = NULL;
	ixPlnrVLocale = VecPlnrVLocale::ENUS;

	dpchinv = NULL;
	dpchret = NULL;

	reply = NULL;
	replylen = 0;
};

ReqPlnr::~ReqPlnr() {
	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	if (pp) MHD_destroy_post_processor(pp);

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD
	if ((ixVBasetype == VecVBasetype::CMD) || (ixVBasetype == VecVBasetype::REGULAR) || (ixVBasetype == VecVBasetype::NOTIFY)
					|| (ixVBasetype == VecVBasetype::UPLOAD) || (ixVBasetype == VecVBasetype::DOWNLOAD)) {
		Mutex::destroy(&mcReady, false, "mcReady", "ReqPlnr", "~ReqPlnr");
		Cond::destroy(&cReady, "cReady", "ReqPlnr", "~ReqPlnr");
	};

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	if (file) {
		if (file->is_open()) file->close();
		delete file;
	};

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	if (request) delete[] request;

	// specific data for base types REGULAR
	if (dpchapp) delete dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	if (dpcheng) delete dpcheng;

	// specific data for base types RET
	if (dpchinv) delete dpchinv;
	if (dpchret) delete dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL
	if (reply) delete[] reply;
};

void ReqPlnr::setStateReply() {
	Mutex::lock(&mcReady, "mcReady", "ReqPlnr", "setStateReply");

	ixVState = VecVState::REPLY;

	Cond::broadcast(&cReady, "cReady", "ReqPlnr", "setStateReply");
	Mutex::unlock(&mcReady, "mcReady", "ReqPlnr", "setStateReply");
};

/******************************************************************************
 class ReqopengconPlnr
 ******************************************************************************/

ReqopengconPlnr::ReqopengconPlnr(
			const uint ixVState
			, const string& ip
		) {
	this->ixVState = ixVState;
	this->ip = ip;

	pp = NULL;

	request = NULL;
	requestlen = 0;

	dpchopd = NULL;

	reply = NULL;
	replylen = 0;
};

ReqopengconPlnr::~ReqopengconPlnr() {
	if (pp) MHD_destroy_post_processor(pp);

	if (request) delete[] request;

	if (dpchopd) delete dpchopd;

	if (reply) delete[] reply;
};

/******************************************************************************
 class DcolPlnr
 ******************************************************************************/

DcolPlnr::DcolPlnr(
			const ubigint jref
			, const uint ixPlnrVLocale
		) {
	this->jref = jref;
	this->ixPlnrVLocale = ixPlnrVLocale;

	// multiple lock's by the same thread need to be possible
	Mutex::init(&mAccess, true, "mAccess", "DcolPlnr", "DcolPlnr");

	hot = false;

	req = NULL;
};

DcolPlnr::~DcolPlnr() {
	Mutex::lock(&mAccess, "mAccess", "DcolPlnr", "~DcolPlnr");
	Mutex::unlock(&mAccess, "mAccess", "DcolPlnr", "~DcolPlnr");
	Mutex::destroy(&mAccess, true, "mAccess", "DcolPlnr", "~DcolPlnr");

	for (auto it=dpchs.begin();it!=dpchs.end();it++) delete(*it);

	if (req) Cond::broadcast(&(req->cReady), "req->cReady", "DcolPlnr", "~DcolPlnr");
};

int DcolPlnr::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int DcolPlnr::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "dcol(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class JobPlnr
 ******************************************************************************/

JobPlnr::JobPlnr(
			XchgPlnr* xchg
			, const uint ixPlnrVJob
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
			, const bool prefmast
		) {
	this->xchg = xchg;

	jref = 0;

	this->ixPlnrVJob = ixPlnrVJob;

	this->jrefSup = jrefSup;

	this->ixPlnrVLocale = ixPlnrVLocale;

	jrefMast = 0;

	this->prefmast = prefmast;

	Mutex::init(&mAccess, true, "mAccess", VecPlnrVJob::getSref(ixPlnrVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecPlnrVJob::getSref(ixPlnrVJob));

	ixVSge = 1;
	nextIxVSge = 1;

	opNdone = 0;
	opN = 0;

	Mutex::init(&mOps, true, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(jrefSup=" + to_string(jrefSup) + ")", VecPlnrVJob::getSref(ixPlnrVJob));

	wrefLast = 0;
	wrefMin = 0;

	reqCmd = NULL;
};

JobPlnr::~JobPlnr() {
	Mutex::lock(&mAccess, "mAccess", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "~" + VecPlnrVJob::getSref(ixPlnrVJob));
	Mutex::unlock(&mAccess, "mAccess", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "~" + VecPlnrVJob::getSref(ixPlnrVJob));
	Mutex::destroy(&mAccess, true, "mAccess", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "~" + VecPlnrVJob::getSref(ixPlnrVJob));

	Mutex::destroy(&mOps, true, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "~" + VecPlnrVJob::getSref(ixPlnrVJob));

	if (reqCmd) delete reqCmd;
};

string JobPlnr::getSquawk(
			DbsPlnr* dbsplnr
		) {
	return "";
};

void JobPlnr::giveupMaster(
			DbsPlnr* dbsplnr
		) {
};

void JobPlnr::giveupSlave(
			DbsPlnr* dbsplnr
		) {
};

void JobPlnr::becomeMaster(
			DbsPlnr* dbsplnr
		) {
};

void JobPlnr::becomeSlave(
			DbsPlnr* dbsplnr
		) {
};

bool JobPlnr::handleClaimMaster(
			DbsPlnr* dbsplnr
		) {
	return false;
};

void JobPlnr::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
};

void JobPlnr::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
};

int JobPlnr::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobPlnr::trylockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::trylock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobPlnr::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "job(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int JobPlnr::lockAccess(
			const string& srefMember
		) {
	return Mutex::lock(&mAccess, "mAccess", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", srefMember);
};

int JobPlnr::unlockAccess(
			const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "mAccess", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", srefMember);
};

void JobPlnr::clearInvs() {
	for (unsigned int i=0;i<invs.size();i++) delete invs[i];
	invs.clear();
};

void JobPlnr::addInv(
			DpchInvPlnr* inv
		) {
	inv->oref = xchg->orefseq->getNewRef();
	inv->jref = jref;

	invs.push_back(inv);

	opN++;
};

void JobPlnr::addInvs(
			vector<DpchInvPlnr*>& _invs
		) {
	for (unsigned int i=0;i<_invs.size();i++) addInv(_invs[i]);
};

void JobPlnr::submitInvs(
			DbsPlnr* dbsplnr
			, const uint emptyIxVSge
			, uint& _ixVSge
		) {
	if (opN == 0) {
		_ixVSge = emptyIxVSge;

	} else {
		xchg->addInvs(dbsplnr, jref, invs);
		invs.clear();
	};
};

void JobPlnr::clearOps() {
	Mutex::lock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "clearOps");

	for (auto it=ops.begin();it!=ops.end();it++) delete(*it);
	ops.clear();

	Mutex::unlock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "clearOps");
};

void JobPlnr::addOp(
			DbsPlnr* dbsplnr
			, DpchInvPlnr* inv
		) {
	string squawk;

	Mutex::lock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "addOp");

	// generate squawk
	if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCOLLDEV) {
		squawk = SqkPlnrExp::getSquawkColldev(dbsplnr, (DpchInvPlnrExpColldev*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCOLLDSN) {
		squawk = SqkPlnrExp::getSquawkColldsn(dbsplnr, (DpchInvPlnrExpColldsn*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCOLLSTK) {
		squawk = SqkPlnrExp::getSquawkCollstk(dbsplnr, (DpchInvPlnrExpCollstk*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCORNER) {
		squawk = SqkPlnrExp::getSquawkCorner(dbsplnr, (DpchInvPlnrExpCorner*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCROSS) {
		squawk = SqkPlnrExp::getSquawkCross(dbsplnr, (DpchInvPlnrExpCross*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDIRCOUP) {
		squawk = SqkPlnrExp::getSquawkDircoup(dbsplnr, (DpchInvPlnrExpDircoup*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDISCRES) {
		squawk = SqkPlnrExp::getSquawkDiscres(dbsplnr, (DpchInvPlnrExpDiscres*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDOTTEXT) {
		squawk = SqkPlnrExp::getSquawkDottext(dbsplnr, (DpchInvPlnrExpDottext*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDSN) {
		squawk = SqkPlnrExp::getSquawkDsn(dbsplnr, (DpchInvPlnrExpDsn*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPGRATCPL) {
		squawk = SqkPlnrExp::getSquawkGratcpl(dbsplnr, (DpchInvPlnrExpGratcpl*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPGRAY) {
		squawk = SqkPlnrExp::getSquawkGray(dbsplnr, (DpchInvPlnrExpGray*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPIMAGE) {
		squawk = SqkPlnrExp::getSquawkImage(dbsplnr, (DpchInvPlnrExpImage*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPMARKER) {
		squawk = SqkPlnrExp::getSquawkMarker(dbsplnr, (DpchInvPlnrExpMarker*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPAD) {
		squawk = SqkPlnrExp::getSquawkPad(dbsplnr, (DpchInvPlnrExpPad*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCSQ) {
		squawk = SqkPlnrExp::getSquawkPhcsq(dbsplnr, (DpchInvPlnrExpPhcsq*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCSQNEG) {
		squawk = SqkPlnrExp::getSquawkPhcsqneg(dbsplnr, (DpchInvPlnrExpPhcsqneg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCTRIG) {
		squawk = SqkPlnrExp::getSquawkPhctrig(dbsplnr, (DpchInvPlnrExpPhctrig*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCTRIGNEG) {
		squawk = SqkPlnrExp::getSquawkPhctrigneg(dbsplnr, (DpchInvPlnrExpPhctrigneg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHOTDET) {
		squawk = SqkPlnrExp::getSquawkPhotdet(dbsplnr, (DpchInvPlnrExpPhotdet*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPIE) {
		squawk = SqkPlnrExp::getSquawkPie(dbsplnr, (DpchInvPlnrExpPie*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPINOUT) {
		squawk = SqkPlnrExp::getSquawkPinout(dbsplnr, (DpchInvPlnrExpPinout*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPROICADP) {
		squawk = SqkPlnrExp::getSquawkRoicadp(dbsplnr, (DpchInvPlnrExpRoicadp*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPRTRESNEG) {
		squawk = SqkPlnrExp::getSquawkRtresneg(dbsplnr, (DpchInvPlnrExpRtresneg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPSPRING) {
		squawk = SqkPlnrExp::getSquawkSpring(dbsplnr, (DpchInvPlnrExpSpring*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPSTKPERTPL) {
		squawk = SqkPlnrExp::getSquawkStkpertpl(dbsplnr, (DpchInvPlnrExpStkpertpl*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPSTKREGFILL) {
		squawk = SqkPlnrExp::getSquawkStkregfill(dbsplnr, (DpchInvPlnrExpStkregfill*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPVANDERPAUW) {
		squawk = SqkPlnrExp::getSquawkVanderpauw(dbsplnr, (DpchInvPlnrExpVanderpauw*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWG) {
		squawk = SqkPlnrExp::getSquawkWg(dbsplnr, (DpchInvPlnrExpWg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGBEND) {
		squawk = SqkPlnrExp::getSquawkWgbend(dbsplnr, (DpchInvPlnrExpWgbend*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGBENDNEG) {
		squawk = SqkPlnrExp::getSquawkWgbendneg(dbsplnr, (DpchInvPlnrExpWgbendneg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGNEG) {
		squawk = SqkPlnrExp::getSquawkWgneg(dbsplnr, (DpchInvPlnrExpWgneg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGSUSP) {
		squawk = SqkPlnrExp::getSquawkWgsusp(dbsplnr, (DpchInvPlnrExpWgsusp*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGTAP) {
		squawk = SqkPlnrExp::getSquawkWgtap(dbsplnr, (DpchInvPlnrExpWgtap*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGTAPNEG) {
		squawk = SqkPlnrExp::getSquawkWgtapneg(dbsplnr, (DpchInvPlnrExpWgtapneg*) inv);
	};
	if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRMEEPTRF2D) {
		squawk = SqkPlnrMeep::getSquawkTrf2d(dbsplnr, (DpchInvPlnrMeepTrf2d*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRMEEPTRF3D) {
		squawk = SqkPlnrMeep::getSquawkTrf3d(dbsplnr, (DpchInvPlnrMeepTrf3d*) inv);
	};
	if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNU) {
		squawk = SqkPlnrPlot::getSquawkDat1dgnu(dbsplnr, (DpchInvPlnrPlotDat1dgnu*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNUMULT) {
		squawk = SqkPlnrPlot::getSquawkDat1dgnumult(dbsplnr, (DpchInvPlnrPlotDat1dgnumult*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDEVSVG) {
		squawk = SqkPlnrPlot::getSquawkDevsvg(dbsplnr, (DpchInvPlnrPlotDevsvg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT1DGNU) {
		squawk = SqkPlnrPlot::getSquawkDomdat1dgnu(dbsplnr, (DpchInvPlnrPlotDomdat1dgnu*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DGNU) {
		squawk = SqkPlnrPlot::getSquawkDomdat2dgnu(dbsplnr, (DpchInvPlnrPlotDomdat2dgnu*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DPNG) {
		squawk = SqkPlnrPlot::getSquawkDomdat2dpng(dbsplnr, (DpchInvPlnrPlotDomdat2dpng*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DVID) {
		squawk = SqkPlnrPlot::getSquawkDomdat2dvid(dbsplnr, (DpchInvPlnrPlotDomdat2dvid*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMZCSSVG) {
		squawk = SqkPlnrPlot::getSquawkDomzcssvg(dbsplnr, (DpchInvPlnrPlotDomzcssvg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDSNXYSVG) {
		squawk = SqkPlnrPlot::getSquawkDsnxysvg(dbsplnr, (DpchInvPlnrPlotDsnxysvg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDSNZSVG) {
		squawk = SqkPlnrPlot::getSquawkDsnzsvg(dbsplnr, (DpchInvPlnrPlotDsnzsvg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTSTKSVG) {
		squawk = SqkPlnrPlot::getSquawkStksvg(dbsplnr, (DpchInvPlnrPlotStksvg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTTPOSVG) {
		squawk = SqkPlnrPlot::getSquawkTposvg(dbsplnr, (DpchInvPlnrPlotTposvg*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTTPOTXT) {
		squawk = SqkPlnrPlot::getSquawkTpotxt(dbsplnr, (DpchInvPlnrPlotTpotxt*) inv);
	};
	if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRRASTCUB) {
		squawk = SqkPlnrRast::getSquawkCub(dbsplnr, (DpchInvPlnrRastCub*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRRASTXYBOX) {
		squawk = SqkPlnrRast::getSquawkXybox(dbsplnr, (DpchInvPlnrRastXybox*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRRASTZLINE) {
		squawk = SqkPlnrRast::getSquawkZline(dbsplnr, (DpchInvPlnrRastZline*) inv);
	};
	if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFD1D) {
		squawk = SqkPlnrWgmode::getSquawkFd1d(dbsplnr, (DpchInvPlnrWgmodeFd1d*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFD2D) {
		squawk = SqkPlnrWgmode::getSquawkFd2d(dbsplnr, (DpchInvPlnrWgmodeFd2d*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFEM1D) {
		squawk = SqkPlnrWgmode::getSquawkFem1d(dbsplnr, (DpchInvPlnrWgmodeFem1d*) inv);
	} else if (inv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFEM2D) {
		squawk = SqkPlnrWgmode::getSquawkFem2d(dbsplnr, (DpchInvPlnrWgmodeFem2d*) inv);
	};

	// append to op list
	ops.push_back(new Op(inv->oref, inv->ixPlnrVDpch, squawk));

	Mutex::unlock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "addOp");
};

void JobPlnr::removeOp(
			const ubigint oref
		) {
	Op* op = NULL;

	Mutex::lock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "removeOp");

	for (auto it=ops.begin();it!=ops.end();it++) {
		op = *it;

		if (op->oref == oref) {
			// found
			ops.erase(it);

			// keep squawk of this op
			opsqkLast = op->squawk;

			delete op;
			
			break;
		};
	};

	Mutex::unlock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "removeOp");
};

string JobPlnr::getOpsqkLast() {
	string retval;

	Mutex::lock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	retval = opsqkLast;

	Mutex::unlock(&mOps, "mOps", VecPlnrVJob::getSref(ixPlnrVJob) + "(" + to_string(jref) + ")", "getOpsqkLast");

	return retval;
};

void JobPlnr::callback(
			const uint _nextIxVSge
		) {
	nextIxVSge = _nextIxVSge;
	wrefLast = xchg->addWakeup(jref, "callback", 0);
};

void JobPlnr::invalidateWakeups() {
	wrefMin = wrefLast + 1;
};

/******************************************************************************
 class StmgrPlnr
 ******************************************************************************/

StmgrPlnr::StmgrPlnr(
			XchgPlnr* xchg
			, const ubigint jref
			, const uint ixVNonetype
		) {
	this->xchg = xchg;

	this->jref = jref;
	this->ixVNonetype = ixVNonetype;

	stcch = new Stcch(true);

	Mutex::init(&mAccess, true, "mAccess", "StmgrPlnr(" + to_string(jref) + ")", "StmgrPlnr");
};

StmgrPlnr::~StmgrPlnr() {
	Mutex::lock(&mAccess, "mAccess", "StmgrPlnr(" + to_string(jref) + ")", "~StmgrPlnr");
	Mutex::unlock(&mAccess, "mAccess", "StmgrPlnr(" + to_string(jref) + ")", "~StmgrPlnr");
	Mutex::destroy(&mAccess, true, "mAccess", "StmgrPlnr(" + to_string(jref) + ")", "~StmgrPlnr");

	delete stcch;
};

void StmgrPlnr::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	set<uint> icsPlnrVStub;
	pair<multimap<stref_t,Stcchitem*>::iterator,multimap<stref_t,Stcchitem*>::iterator> rng;

	bool notif = false;

	begin();

	if (call->ixVCall == VecPlnrVCall::CALLPLNRAGDUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRAGDSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRARIUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRARISTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRARRUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRARRSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRBLKUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRBLKSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCALUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRCTPSTD);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRCALSTD);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRCLCSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCLIUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRCLISTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDEVUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDEVSHORT);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDEVSTD);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDTPSTD);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDVCSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDGDUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDGDSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDOMUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDOMSHORT);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDOMSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSNUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRDSNSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFCEUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRFCESTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRFILUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRFILSHORT);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRFILSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLGDUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRLGDSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLVLUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRLVLSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLYRUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRLYRSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRMATUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRMATSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRJUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRPRJSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRPRSUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRPRSSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRRTCUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRRTCSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSESUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRSESMENU);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRSESSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSRUUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRSRUSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRSTKUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRSTKSTD);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRSTKSHORT);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRTPOUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRTPOSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSGUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRGRP);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRUSGSTD);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRUSRSTD);
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNROWN);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRVTXUPD_REFEQ) {
		insert(icsPlnrVStub, VecPlnrVStub::STUBPLNRVTXSTD);
	};

	for (auto it=icsPlnrVStub.begin();it!=icsPlnrVStub.end();it++) {
		rng = stcch->nodes.equal_range(stref_t(*it, call->argInv.ref, 0));
		for (auto it2=rng.first;it2!=rng.second;it2++) if (refresh(dbsplnr, it2->second)) notif = true;
	};

	commit();

	if (notif) xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRSTUBCHG, jref);
};

bool StmgrPlnr::refresh(
			DbsPlnr* dbsplnr
			, Stcchitem* stit
		) {
	set<stref_t> strefsSub_backup;
	string stub_backup;

	while (!stit->strefsSup.empty()) stcch->unlink(*stit->strefsSup.begin(), stit->stref);

	strefsSub_backup = stit->strefsSub;
	stub_backup = stit->stub;

	StubPlnr::getStub(dbsplnr, stit->stref.ixVStub, stit->stref.ref, stit->stref.ixVLocale, ixVNonetype, stcch, NULL, true);

	if (stit->stub != stub_backup) {
		for (auto it=strefsSub_backup.begin();it!=strefsSub_backup.end();it++) refresh(dbsplnr, stcch->getStitByStref(*it));
		return true;
	} else return false;
};

void StmgrPlnr::begin() {
	stcch->begin();
};

void StmgrPlnr::commit() {
	for (auto it=stcch->icsVStubNew.begin();it!=stcch->icsVStubNew.end();it++) {
		if (*it == VecPlnrVStub::STUBPLNRAGDSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRAGDUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRARISTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRARIUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRARRSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRARRUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRBLKSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRBLKUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRCALSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRCLCSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRCLISTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRCLIUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRCTPSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRCALUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDEVSHORT) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDEVSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDGDSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDGDUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDOMSHORT) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDOMUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDOMSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDOMUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDSNSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDSNUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDTPSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRDVCSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRDEVUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRFCESTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRFCEUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRFILSHORT) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRFILUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRFILSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRFILUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRGRP) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRUSGUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRLGDSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRLGDUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRLVLSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRLVLUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRLYRSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRLYRUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRMATSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRMATUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNROWN) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRUSRUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRPRJSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRPRJUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRPRSSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRPRSUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRRTCSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRRTCUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRSESMENU) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRSESUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRSESSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRSESUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRSRUSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRSRUUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRSTKSHORT) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRSTKUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRSTKSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRSTKUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRTPOSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRTPOUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRUSGSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRUSGUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRUSRSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRUSRUPD_REFEQ, jref);
		} else if (*it == VecPlnrVStub::STUBPLNRVTXSTD) {
			xchg->addClstnStmgr(VecPlnrVCall::CALLPLNRVTXUPD_REFEQ, jref);
		};
	};

	stcch->commit();
};

int StmgrPlnr::lockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::lock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

int StmgrPlnr::unlockAccess(
			const string& srefObject
			, const string& srefMember
		) {
	return Mutex::unlock(&mAccess, "stmgr(" + to_string(jref) + ")->mAccess", srefObject, srefMember);
};

/******************************************************************************
 class WakeupPlnr
 ******************************************************************************/

WakeupPlnr::WakeupPlnr(
			XchgPlnr* xchg
			, const ubigint wref
			, const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	this->xchg = xchg;
	this->wref = wref;
	this->jref = jref;
	this->sref = sref;
	this->deltat = deltat;
	this->weak = weak;
};

/******************************************************************************
 class ConopengPlnr
 ******************************************************************************/

ConopengPlnr::ConopengPlnr(
			const string& ip
			, const uint port
		) {
	string url;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
		url = "http://" + ip + ":" + to_string(port) + "/dpch";
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	};

	busy = true;
};

ConopengPlnr::~ConopengPlnr() {
	if (curl) curl_easy_cleanup(curl);
};

/******************************************************************************
 class NodePlnr
 ******************************************************************************/

NodePlnr::NodePlnr(
			const ubigint nref
			, const string& ip
			, const uint port
			, const uint opprcn
			, const vector<string>& srefsOpk
		) {
	this->nref = nref;
	this->ip = ip;
	this->port = port;
	this->opprcn = opprcn;

	// break srefsOpk into acceptable invocation dispatches
	for (unsigned int i=0;i<srefsOpk.size();i++) {
		if (srefsOpk[i].compare("PlnrExp") == 0) {
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPCOLLDEV);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPCOLLDSN);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPCOLLSTK);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPCORNER);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPCROSS);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPDIRCOUP);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPDISCRES);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPDOTTEXT);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPDSN);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPGRATCPL);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPGRAY);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPIMAGE);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPMARKER);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPAD);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPHCSQ);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPHCSQNEG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPHCTRIG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPHCTRIGNEG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPHOTDET);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPIE);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPPINOUT);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPROICADP);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPRTRESNEG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPSPRING);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPSTKPERTPL);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPSTKREGFILL);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPVANDERPAUW);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWGBEND);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWGBENDNEG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWGNEG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWGSUSP);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWGTAP);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNREXPWGTAPNEG);
		} else if (srefsOpk[i].compare("PlnrMeep") == 0) {
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRMEEPTRF2D);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRMEEPTRF3D);
		} else if (srefsOpk[i].compare("PlnrPlot") == 0) {
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNU);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNUMULT);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDEVSVG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT1DGNU);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DGNU);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DPNG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DVID);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDOMZCSSVG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDSNXYSVG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTDSNZSVG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTSTKSVG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTTPOSVG);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRPLOTTPOTXT);
		} else if (srefsOpk[i].compare("PlnrRast") == 0) {
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRRASTCUB);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRRASTXYBOX);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRRASTZLINE);
		} else if (srefsOpk[i].compare("PlnrWgmode") == 0) {
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRWGMODEFD1D);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRWGMODEFD2D);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRWGMODEFEM1D);
			icsPlnrVDpch.insert(VecPlnrVDpch::DPCHINVPLNRWGMODEFEM2D);
		};
	};

	opprcbusy = 0;

	Mutex::init(&mCons, false, "mCons", "NodePlnr", "NodePlnr");
};

NodePlnr::~NodePlnr() {
	Mutex::destroy(&mCons, false, "mCons", "NodePlnr", "~NodePlnr");

	for (unsigned int i=0;i<cons.size();i++) delete cons[i];
};

ConopengPlnr* NodePlnr::getCon() {
	ConopengPlnr* con;

	Mutex::lock(&mCons, "mCons", "NodePlnr", "getCon");

	con = NULL;

	// look for existing connections that are idle
	for (unsigned int i=0;i<cons.size();i++) {
		if (!cons[i]->busy) {
			con = cons[i];
			con->busy = true;
			break;
		};
	};

	if (!con) {
		// create new connection
		con = new ConopengPlnr(ip, port);
		cons.push_back(con);
	};

	Mutex::unlock(&mCons, "mCons", "NodePlnr", "getCon");

	return con;
};

/******************************************************************************
 class XchgdataPlnrJobprc
 ******************************************************************************/

XchgdataPlnrJobprc::XchgdataPlnrJobprc() {
};

/******************************************************************************
 class XchgPlnrd
 ******************************************************************************/

XchgPlnrd::XchgPlnrd() {
	// root job
	jrefRoot = 0;

	// job receiving commands
	jrefCmd = 0;

	// scrambled ref codes
	Mutex::init(&mScr, true, "mScr", "XchgPlnrd", "XchgPlnrd");

	// log file
	Mutex::init(&mLogfile, true, "mLogfile", "XchgPlnrd", "XchgPlnrd");

	// condition for op engine client
	Mutex::init(&mcOpengcli, true, "mcOpengcli", "XchgPlnrd", "XchgPlnrd");
	Cond::init(&cOpengcli, "cOpengcli", "XchgPlnrd", "XchgPlnrd");

	// condition for job processors
	Mutex::init(&mcJobprcs, true, "mcJobprcs", "XchgPlnrd", "XchgPlnrd");
	Cond::init(&cJobprcs, "cJobprcs", "XchgPlnrd", "XchgPlnrd");

	// request list
	Mutex::init(&mReqs, true, "mReqs", "XchgPlnrd", "XchgPlnrd");

	// operation invocation list
	orefseq = new Refseq("orefseq");
	Mutex::init(&mInvs, true, "mInvs", "XchgPlnrd", "XchgPlnrd");

	// presetting list
	Mutex::init(&mPresets, true, "mPresets", "XchgPlnrd", "XchgPlnrd");

	// stub manager list
	Mutex::init(&mStmgrs, true, "mStmgrs", "XchgPlnrd", "XchgPlnrd");

	// call listener list
	Mutex::init(&mClstns, true, "mClstns", "XchgPlnrd", "XchgPlnrd");

	// dispatch collector list
	Mutex::init(&mDcols, true, "mDcols", "XchgPlnrd", "XchgPlnrd");

	// job list
	jrefseq = new Refseq("jrefseq");
	Mutex::init(&mJobs, true, "mJobs", "XchgPlnrd", "XchgPlnrd");

	// sequence for wakeup references
	wrefseq = new Refseq("wrefseq");

	// node list
	nrefseq = new Refseq("nrefseq");
	Mutex::init(&mNodes, true, "mNodes", "XchgPlnrd", "XchgPlnrd");
};

XchgPlnrd::~XchgPlnrd() {
	// empty out lists
	for (auto it=reqs.begin();it!=reqs.end();it++) delete(*it);
	for (auto it=invs.begin();it!=invs.end();it++) delete(*it);
	for (auto it=presets.begin();it!=presets.end();it++) delete(it->second);
	for (auto it=stmgrs.begin();it!=stmgrs.end();it++) delete(it->second);
	for (auto it=clstns.begin();it!=clstns.end();it++) delete(it->second);
	for (auto it=dcols.begin();it!=dcols.end();it++) delete(it->second);
	for (auto it=jobs.begin();it!=jobs.end();it++) delete(it->second);
	for (auto it=nodes.begin();it!=nodes.end();it++) delete(it->second);

	// log file
	Mutex::destroy(&mLogfile, true, "mLogfile", "XchgPlnrd", "~XchgPlnrd");

	// scrambled ref codes
	Mutex::destroy(&mScr, true, "mScr", "XchgPlnrd", "~XchgPlnrd");

	// condition for op engine client
	Mutex::destroy(&mcOpengcli, true, "mcOpengcli", "XchgPlnrd", "~XchgPlnrd");
	Cond::destroy(&cOpengcli, "cOpengcli", "XchgPlnrd", "~XchgPlnrd");

	// condition for job processors
	Mutex::destroy(&mcJobprcs, true, "mcJobprcs", "XchgPlnrd", "~XchgPlnrd");
	Cond::destroy(&cJobprcs, "cJobprcs", "XchgPlnrd", "~XchgPlnrd");

	// request list
	Mutex::destroy(&mReqs, true, "mReqs", "XchgPlnrd", "~XchgPlnrd");

	// operation invocation list
	delete orefseq;
	Mutex::destroy(&mInvs, true, "mInvs", "XchgPlnrd", "~XchgPlnrd");

	// presetting list
	Mutex::destroy(&mPresets, true, "mPresets", "XchgPlnrd", "~XchgPlnrd");

	// stub manager list
	Mutex::destroy(&mStmgrs, true, "mStmgrs", "XchgPlnrd", "~XchgPlnrd");

	// call listener list
	Mutex::destroy(&mClstns, true, "mClstns", "XchgPlnrd", "~XchgPlnrd");

	// dispatch collector list
	Mutex::destroy(&mDcols, true, "mDcols", "XchgPlnrd", "~XchgPlnrd");

	// job list
	delete jrefseq;
	Mutex::destroy(&mJobs, true, "mJobs", "XchgPlnrd", "~XchgPlnrd");

	// sequence for wakeup references
	delete wrefseq;

	// node list
	delete nrefseq;
	Mutex::destroy(&mJobs, true, "mNodes", "XchgPlnrd", "~XchgPlnrd");
};

// IP cust --- INSERT

void XchgPlnrd::appendToLogfile(
			const string& str
		) {
	time_t rawtime;
	fstream logfile;

	Mutex::lock(&mLogfile, "mLogfile", "XchgPlnrd", "appendToLogfile");

	time(&rawtime);

	logfile.open("./log.txt", ios::out | ios::app);
	logfile << Ftm::stamp(rawtime) << ": " << str << endl;
	logfile.close();

	Mutex::unlock(&mLogfile, "mLogfile", "XchgPlnrd", "appendToLogfile");
};

void XchgPlnrd::addReq(
			ReqPlnr* req
		) {
	Mutex::lock(&mReqs, "mReqs", "XchgPlnrd", "addReq");

	req->ixVState = ReqPlnr::VecVState::WAITPRC;
	reqs.push_back(req);

	Mutex::unlock(&mReqs, "mReqs", "XchgPlnrd", "addReq");

	Cond::broadcast(&cJobprcs, "cJobprcs", "XchgPlnrd", "addReq");
};

ReqPlnr* XchgPlnrd::pullFirstReq() {
	ReqPlnr* req;

	// get first element from list
	Mutex::lock(&mReqs, "mReqs", "XchgPlnrd", "pullFirstReq");

	req = NULL;

	if (!reqs.empty()) {
		req = *(reqs.begin());
		req->ixVState = ReqPlnr::VecVState::PRC;
		reqs.pop_front();
	};

	Mutex::unlock(&mReqs, "mReqs", "XchgPlnrd", "pullFirstReq");

	return req;
};

void XchgPlnrd::addInvs(
			DbsPlnr* dbsplnr
			, const ubigint jref
			, vector<DpchInvPlnr*>& dpchinvs
		) {
	JobPlnr* job;

	job = getJobByJref(jref);

	if (job != NULL) {
		// append to inv list and broadcast the news (note the double-lock)
		Mutex::lock(&mInvs, "mInvs", "XchgPlnrd", "addInvs");
		Mutex::lock(&(job->mOps), "job->mOps", "XchgPlnrd", "addInvs");

		for (unsigned int i=0;i<dpchinvs.size();i++) {
			job->addOp(dbsplnr, dpchinvs[i]);

			invs.push_back(dpchinvs[i]);
		};

		Mutex::unlock(&(job->mOps), "job->mOps", "XchgPlnrd", "addInvs");
		Mutex::unlock(&mInvs, "mInvs", "XchgPlnrd", "addInvs");

		Cond::broadcast(&cOpengcli, "cOpengcli", "XchgPlnrd", "addInvs");
	};
};

bool XchgPlnrd::pullFirstInv(
			DpchInvPlnr** dpchinv
			, NodePlnr** node
		) {
	bool match = false;

	// retrieve first match inv-node
	Mutex::lock(&mInvs, "mInvs", "XchgPlnrd", "pullFirstInv");
	Mutex::lock(&mNodes, "mNodes", "XchgPlnrd", "pullFirstInv");

	for (auto it=invs.begin();it!=invs.end();it++) {
		*dpchinv = *it;

		for (auto it2=nodes.begin();it2!=nodes.end();it2++) {
			*node = it2->second;

			if ((*node)->opprcbusy < (*node)->opprcn) {

				// node available ; check compatibility with inv

				if ((*node)->icsPlnrVDpch.find((*dpchinv)->ixPlnrVDpch) != (*node)->icsPlnrVDpch.end()) {
					// match found

					// remove inv from list
					invs.erase(it);

					// increase busy count for node
					(*node)->opprcbusy++;

					match = true;
					break;
				};
			};

			if (match) break;
		};
		if (match) break;
	};

	if (!match) {
		*dpchinv = NULL;
		*node = NULL;
	};

	Mutex::unlock(&mNodes, "mNodes", "XchgPlnrd", "pullFirstInv");
	Mutex::unlock(&mInvs, "mInvs", "XchgPlnrd", "pullFirstInv");

	return(match);
};

void XchgPlnrd::returnInv(
			DpchInvPlnr* dpchinv
		) {
	// un-successful execution of op returns

	// append to inv list and broadcast the news
	Mutex::lock(&mInvs, "mInvs", "XchgPlnrd", "returnInv");

	invs.push_back(dpchinv);

	Mutex::unlock(&mInvs, "mInvs", "XchgPlnrd", "returnInv");

	Cond::broadcast(&cOpengcli, "cOpengcli", "XchgPlnrd", "returnInv");
};

Preset* XchgPlnrd::addPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const Arg& arg
		) {
	pref_t pref(jref, ixPlnrVPreset);
	Preset* preset;

	// create new presetting (override value if exists) and append to presetting list
	Mutex::lock(&mPresets, "mPresets", "XchgPlnrd", "addPreset");

	preset = getPresetByPref(pref);

	if (preset) {
		preset->arg = arg;

	} else {
		preset = new Preset(pref, arg);
		presets.insert(pair<pref_t,Preset*>(pref, preset));
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgPlnrd", "addPreset");

	return(preset);
};

Preset* XchgPlnrd::addIxPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const uint ix
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(ix, 0, {}, "", 0, 0.0, false, "", Arg::IX)));
};

Preset* XchgPlnrd::addRefPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const ubigint ref
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(0, ref, {}, "", 0, 0.0, false, "", Arg::REF)));
};

Preset* XchgPlnrd::addRefsPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const vector<ubigint>& refs
		) {
	Arg arg(0, 0, refs, "", 0, 0.0, false, "", Arg::REFS);

	return(addPreset(ixPlnrVPreset, jref, arg));
};

Preset* XchgPlnrd::addSrefPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const string& sref
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(0, 0, {}, sref, 0, 0.0, false, "", Arg::SREF)));
};

Preset* XchgPlnrd::addIntvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const int intval
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(0, 0, {}, "", intval, 0.0, false, "", Arg::INTVAL)));
};

Preset* XchgPlnrd::addDblvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const double dblval
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(0, 0, {}, "", 0, dblval, false, "", Arg::DBLVAL)));
};

Preset* XchgPlnrd::addBoolvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const bool boolval
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, boolval, "", Arg::BOOLVAL)));
};

Preset* XchgPlnrd::addTxtvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
			, const string& txtval
		) {
	return(addPreset(ixPlnrVPreset, jref, Arg(0, 0, {}, "", 0, 0.0, false, txtval, Arg::TXTVAL)));
};

Preset* XchgPlnrd::getPresetByPref(
			const pref_t& pref
		) {
	Preset* preset = NULL;

	Mutex::lock(&mPresets, "mPresets", "XchgPlnrd", "getPresetByPref");

	auto it = presets.find(pref);
	if (it != presets.end()) preset = it->second;

	Mutex::unlock(&mPresets, "mPresets", "XchgPlnrd", "getPresetByPref");

	return preset;
};

Arg XchgPlnrd::getPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg;

	JobPlnr* job = NULL;
	Preset* preset = NULL;

	if ( (ixPlnrVPreset == VecPlnrVPreset::PREPLNRSYSDATE) || (ixPlnrVPreset == VecPlnrVPreset::PREPLNRSYSTIME) || (ixPlnrVPreset == VecPlnrVPreset::PREPLNRSYSSTAMP) ) {
		time_t rawtime;
		time(&rawtime);

		arg.mask = Arg::INTVAL;

		if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRSYSDATE) arg.intval = (rawtime-rawtime%(3600*24))/(3600*24);
		else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRSYSTIME) arg.intval = rawtime%(3600*24);
		else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRSYSSTAMP) arg.intval = rawtime;

	} else {
		Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "getPreset");
		Mutex::lock(&mPresets, "mPresets", "XchgPlnrd", "getPreset");
		
		job = getJobByJref(jref);

		if ( (job != NULL) && (ixPlnrVPreset == VecPlnrVPreset::PREPLNRIXLCL) ) {
			arg.mask = Arg::IX;
			arg.ix = job->ixPlnrVLocale;

		} else {
			while (job && !preset) {
				preset = getPresetByPref(pref_t(job->jref, ixPlnrVPreset));

				if (preset) arg = preset->arg;
				else job = getJobByJref(job->jrefSup);
			};
		};

		Mutex::unlock(&mPresets, "mPresets", "XchgPlnrd", "getPreset");
		Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "getPreset");
	};

	return(arg);
};

uint XchgPlnrd::getIxPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::IX) return(arg.ix);
	else return(0);
};

ubigint XchgPlnrd::getRefPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::REF) return(arg.ref);
	else return(0);
};

vector<ubigint> XchgPlnrd::getRefsPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);
	vector<ubigint> empty;

	if (arg.mask & Arg::REFS) return(arg.refs);
	else return(empty);
};

string XchgPlnrd::getSrefPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::SREF) return(arg.sref);
	else return("");
};

int XchgPlnrd::getIntvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::INTVAL) return(arg.intval);
	else return(intvalInvalid);
};

double XchgPlnrd::getDblvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::DBLVAL) return(arg.dblval);
	else return(dblvalInvalid);
};

bool XchgPlnrd::getBoolvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::BOOLVAL) return(arg.boolval);
	else return(false);
};

string XchgPlnrd::getTxtvalPreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Arg arg = getPreset(ixPlnrVPreset, jref);

	if (arg.mask & Arg::TXTVAL) return(arg.txtval);
	else return("");
};

void XchgPlnrd::getPresetsByJref(
			const ubigint jref
			, vector<uint>& icsPlnrVPreset
			, vector<Arg>& args
		) {
	Preset* preset = NULL;

	icsPlnrVPreset.clear();
	args.clear();

	Mutex::lock(&mPresets, "mPresets", "XchgPlnrd", "getPresetsByJref");

	auto rng = presets.equal_range(pref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		preset = it->second;

		icsPlnrVPreset.push_back(preset->pref.ixVPreset);
		args.push_back(preset->arg);
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgPlnrd", "getPresetsByJref");
};

void XchgPlnrd::removePreset(
			const uint ixPlnrVPreset
			, const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgPlnrd", "removePreset");

	auto it = presets.find(pref_t(jref, ixPlnrVPreset));
	if (it != presets.end()) {
		delete it->second;
		presets.erase(it);
	};

	Mutex::unlock(&mPresets, "mPresets", "XchgPlnrd", "removePreset");
};

void XchgPlnrd::removePresetsByJref(
			const ubigint jref
		) {
	Mutex::lock(&mPresets, "mPresets", "XchgPlnrd", "removePresetsByJref");

	auto rng = presets.equal_range(pref_t(jref, 0));
	for (auto it=rng.first;it!=rng.second;it++) delete it->second;
	presets.erase(rng.first, rng.second);

	Mutex::unlock(&mPresets, "mPresets", "XchgPlnrd", "removePresetsByJref");
};

StmgrPlnr* XchgPlnrd::addStmgr(
			const ubigint jref
			, const uint ixVNonetype
		) {
	StmgrPlnr* stmgr = NULL;

	// create new stmgr and append to stmgr list
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgPlnrd", "addStmgr");

	stmgr = getStmgrByJref(jref);

	if (!stmgr) {
		stmgr = new StmgrPlnr(this, jref, ixVNonetype);
		stmgrs[jref] = stmgr;
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgPlnrd", "addStmgr");

	return(stmgr);
};

StmgrPlnr* XchgPlnrd::getStmgrByJref(
			const ubigint jref
		) {
	StmgrPlnr* stmgr = NULL;

	Mutex::lock(&mStmgrs, "mStmgrs", "XchgPlnrd", "getStmgrByJref");

	auto it = stmgrs.find(jref);

	if (it != stmgrs.end()) {
		stmgr = it->second;
		stmgr->lockAccess("XchgPlnrd", "getStmgrByJref");
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgPlnrd", "getStmgrByJref");

	return(stmgr);
};

void XchgPlnrd::removeStmgrByJref(
			const ubigint jref
		) {
	Mutex::lock(&mStmgrs, "mStmgrs", "XchgPlnrd", "removeStmgrByJref");

	removeClstnsByJref(jref, true);

	auto it = stmgrs.find(jref);
	if (it != stmgrs.end()) {
		delete it->second;
		stmgrs.erase(it);
	};

	Mutex::unlock(&mStmgrs, "mStmgrs", "XchgPlnrd", "removeStmgrByJref");
};

Clstn* XchgPlnrd::addClstn(
			const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const Arg& argMask
			, const uint ixVJactype
		) {
	cref_t cref(ixPlnrVCall, jref, false, ixVJobmask, jrefTrig);
	cref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "addClstn");

	clstn = getClstnByCref(cref);

	if (clstn) {
		clstn->argMask = argMask;
		clstn->ixVJactype = ixVJactype;

	} else {
		clstn = new Clstn(cref, argMask, ixVJactype);
		clstns.insert(pair<cref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<cref2_t,cref_t>(cref2, cref));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "addClstn");

	return(clstn);
};

Clstn* XchgPlnrd::addIxClstn(
			const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, 0, {}, "", 0, 0.0, false, "", Arg::IX);

	return(addClstn(ixPlnrVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgPlnrd::addRefClstn(
			const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(0, refMask, {}, "", 0, 0.0, false, "", Arg::REF);

	return(addClstn(ixPlnrVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgPlnrd::addIxRefClstn(
			const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);

	return(addClstn(ixPlnrVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgPlnrd::addIxRefSrefClstn(
			const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixVJobmask
			, const ubigint jrefTrig
			, const uint ixMask
			, const ubigint refMask
			, const string& srefMask
			, const uint ixVJactype
		) {
	Arg argMask(ixMask, refMask, {}, srefMask, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);

	return(addClstn(ixPlnrVCall, jref, ixVJobmask, jrefTrig, argMask, ixVJactype));
};

Clstn* XchgPlnrd::addClstnStmgr(
			const uint ixPlnrVCall
			, const ubigint jref
		) {
	cref_t cref(ixPlnrVCall, jref, true, Clstn::VecVJobmask::ALL, 0);
	cref2_t cref2(cref);
	Clstn* clstn;

	// create new clstn and append to clstn list
	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "addClstnStmgr");

	clstn = getClstnByCref(cref);

	if (!clstn) {
		clstn = new Clstn(cref, Arg(), Clstn::VecVJactype::LOCK);
		clstns.insert(pair<cref_t,Clstn*>(cref, clstn));
		cref2sClstns.insert(pair<cref2_t,cref_t>(cref2, cref));
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "addClstnStmgr");

	return(clstn);
};

Clstn* XchgPlnrd::getClstnByCref(
			const cref_t& cref
		) {
	Clstn* clstn = NULL;

	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "getClstnByCref");

	auto it = clstns.find(cref);
	if (it != clstns.end()) clstn = it->second;

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "getClstnByCref");

	return clstn;
};

void XchgPlnrd::getClstnsByJref(
			const ubigint jref
			, const bool stmgr
			, vector<uint>& icsPlnrVCall
			, vector<uint>& icsVJobmask
		) {
	Clstn* clstn = NULL;

	icsPlnrVCall.clear();
	icsVJobmask.clear();

	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "getClstnsByJref");

	auto rng = cref2sClstns.equal_range(cref2_t(jref, stmgr, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = getClstnByCref(it->second);

		if (clstn) {
			icsPlnrVCall.push_back(clstn->cref.ixVCall);
			icsVJobmask.push_back(clstn->cref.ixVJobmask);
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "getClstnsByJref");
};

void XchgPlnrd::removeClstns(
			const uint ixPlnrVCall
			, const ubigint jref
			, const bool stmgr
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "removeClstns");

	auto rng = clstns.equal_range(cref_t(ixPlnrVCall, jref, stmgr));
	for (auto it=rng.first;it!=rng.second;it++) {
		cref2sClstns.erase(cref2_t(it->first));
		delete it->second;
	};
	clstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "removeClstns");
};

void XchgPlnrd::removeClstnsByJref(
			const ubigint jref
			, const bool stmgr
		) {
	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "removeClstnsByJref");

	auto rng = cref2sClstns.equal_range(cref2_t(jref, stmgr));
	for (auto it=rng.first;it!=rng.second;it++) {
		auto it2 = clstns.find(it->second);
		delete it2->second;
		clstns.erase(it2);
	};
	cref2sClstns.erase(rng.first, rng.second);

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "removeClstnsByJref");
};

void XchgPlnrd::findJrefsByCall(
			Call* call
			, vector<ubigint>& jrefs
			, vector<bool>& stmgrs
			, vector<uint>& icsVJactype
		) {
	Clstn* clstn = NULL;

	JobPlnr* job = NULL;

	bool match;

	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "findJrefsByCall");
	Mutex::lock(&mClstns, "mClstns", "XchgPlnrd", "findJrefsByCall");

	auto rng = clstns.equal_range(cref_t(call->ixVCall, 0));
	for (auto it=rng.first;it!=rng.second;it++) {
		clstn = it->second;

		if (clstn->cref.stmgr) {
			jrefs.push_back(clstn->cref.jref);
			stmgrs.push_back(true);
			icsVJactype.push_back(0);

		} else {
			match = true;

			if (clstn->argMask.mask & Arg::IX) if (clstn->argMask.ix != call->argInv.ix) match = false;
			if (clstn->argMask.mask & Arg::REF) if (clstn->argMask.ref != call->argInv.ref) match = false;
			if (clstn->argMask.mask & Arg::SREF) if (clstn->argMask.sref.compare(call->argInv.sref) != 0) match = false;
			if (clstn->argMask.mask & Arg::INTVAL) if (clstn->argMask.intval != call->argInv.intval) match = false;
			if (clstn->argMask.mask & Arg::DBLVAL) if (clstn->argMask.dblval != call->argInv.dblval) match = false;
			if (clstn->argMask.mask & Arg::BOOLVAL) if (clstn->argMask.boolval != call->argInv.boolval) match = false;
			if (clstn->argMask.mask & Arg::TXTVAL) if (clstn->argMask.txtval.compare(call->argInv.txtval) != 0) match = false;

			if (match) {
				match = false;

				if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::ALL) {
					// don't care about call->jref
					match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::IMM) {
					// check if trigger job is immediate sub-job to listener job
					job = getJobByJref(call->jref);
					if (job) if (job->jrefSup == clstn->cref.jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::MAST) {
					// check if trigger job is master-job to listener job
					if (call->jref != clstn->cref.jref) {
						job = getJobByJref(clstn->cref.jref);
						if (job) if (call->jref == job->jrefMast) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SLV) {
					// check if listener job is master-job to trigger job
					if (call->jref != clstn->cref.jref) {
						job = getJobByJref(call->jref);
						if (job) if (clstn->cref.jref == job->jrefMast) match = true;
					};

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::SPEC) {
					// require specific jref
					if (clstn->cref.jrefTrig == call->jref) match = true;

				} else if (clstn->cref.ixVJobmask == Clstn::VecVJobmask::TREE) {
					// check if trigger job is down the tree from listener job ; note that the order in jobs is unordered (unfortunately)
					job = getJobByJref(call->jref);

					while (job != NULL) {
						if (job->jref == clstn->cref.jref) {
							// add
							match = true;
							break;
						};

						job = getJobByJref(job->jrefSup);
					};
				};
			};

			if (match) {
				jrefs.push_back(clstn->cref.jref);
				stmgrs.push_back(false);
				icsVJactype.push_back(clstn->ixVJactype);
			};
		};
	};

	Mutex::unlock(&mClstns, "mClstns", "XchgPlnrd", "findJrefsByCall");
	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "findJrefsByCall");
};

void XchgPlnrd::triggerCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	vector<ubigint> jrefs;
	vector<bool> stmgrs;
	vector<uint> icsVJactype;

	ubigint jref;
	uint ixVJactype;

	StmgrPlnr* stmgr = NULL;

	JobPlnr* job = NULL;

	findJrefsByCall(call, jrefs, stmgrs, icsVJactype);

	for (unsigned int i=0;i<jrefs.size();i++) {
		jref = jrefs[i];
		ixVJactype = icsVJactype[i];

		if (stmgrs[i]) {
			stmgr = getStmgrByJref(jref);

			if (stmgr) {
				stmgr->handleCall(dbsplnr, call);
				stmgr->unlockAccess("XchgPlnrd", "triggerCall");
			};

		} else {
			job = getJobByJref(jref);
			if (job) {
				if (ixVJactype != Clstn::VecVJactype::WEAK) {
					if (ixVJactype == Clstn::VecVJactype::LOCK) {
						job->lockAccess("XchgPlnrd", "triggerCall");

					} else if (ixVJactype == Clstn::VecVJactype::TRY) {
						if (Mutex::trylock(&(job->mAccess), "job(" + to_string(jref) + ")->mAccess", "XchgPlnrd", "triggerCall") == EBUSY) continue;
					};
				};

				job->handleCall(dbsplnr, call);
			};

			if (ixVJactype != Clstn::VecVJactype::WEAK) {
				job = getJobByJref(jref);
				if (job) job->unlockAccess("XchgPlnrd", "triggerCall");
			};
		};

		if (call->abort) break;
	};
};

bool XchgPlnrd::triggerArgToArgCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const Arg& argInv
			, Arg& argRet
		) {
	Call* call;
	ubigint retval;

  call = new Call(ixPlnrVCall, jref, argInv);
	triggerCall(dbsplnr, call);

	argRet = call->argRet;
	retval = call->abort;

  delete call;
	return retval;
};

bool XchgPlnrd::triggerCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
		) {
	Arg argInv;
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerIxCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerRefCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const ubigint refInv
		) {
	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerIntvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const int intvalInv
		) {
	Arg argInv(0, 0, {}, "", intvalInv, 0.0, false, "", Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerBoolvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const bool boolvalInv
		) {
	Arg argInv(0, 0, {}, "", 0, 0.0, boolvalInv, "", Arg::BOOLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerIxRefCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
		) {
	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerIxSrefCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const string& srefInv
		) {
	Arg argInv(ixInv, 0, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::SREF);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerIxIntvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const int intvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", intvalInv, 0.0, false, "", Arg::IX + Arg::INTVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerIxDblvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const double dblvalInv
		) {
	Arg argInv(ixInv, 0, {}, "", 0, dblvalInv, false, "", Arg::IX + Arg::DBLVAL);
	Arg argRet;

	return(triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet));
};

bool XchgPlnrd::triggerToBoolvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv;
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgPlnrd::triggerIxToBoolvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(ixInv, 0, {}, "", 0, 0.0, false, "", Arg::IX);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgPlnrd::triggerRefToBoolvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) boolvalRet = argRet.boolval;

	return(retval);
};

bool XchgPlnrd::triggerIxRefToIxCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

bool XchgPlnrd::triggerIxRefToRefCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, "", 0, 0.0, false, "", Arg::IX + Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgPlnrd::triggerIxRefSrefCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, 0, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgPlnrd::triggerIxRefSrefIntvalCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	return(retval);
};

bool XchgPlnrd::triggerIxRefSrefIntvalToRefCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval;

	Arg argInv(ixInv, refInv, {}, srefInv, intvalInv, 0.0, false, "", Arg::IX + Arg::REF + Arg::SREF + Arg::INTVAL);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) refRet = argRet.ref;

	return(retval);
};

bool XchgPlnrd::triggerRefToIxCall(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCall
			, const ubigint jref
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval;

	Arg argInv(0, refInv, {}, "", 0, 0.0, false, "", Arg::REF);
	Arg argRet;

	retval = triggerArgToArgCall(dbsplnr, ixPlnrVCall, jref, argInv, argRet);

	if (!retval) ixRet = argRet.ix;

	return(retval);
};

DcolPlnr* XchgPlnrd::addDcol(
			const ubigint jref
		) {
	JobPlnr* job = NULL;

	DcolPlnr* dcol = NULL;

	// create new dcol and append to dcol list
	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "addDcol");
	Mutex::lock(&mDcols, "mDcols", "XchgPlnrd", "addDcol");

	job = getJobByJref(jref);

	if (job) {
		dcol = getDcolByJref(jref);

		if (!dcol) {
			dcol = new DcolPlnr(jref, job->ixPlnrVLocale);
			dcols[jref] = dcol;

			dcol->lockAccess("XchgPlnrd", "addDcol");
		};

		// make dcol the session's active notify dcol
		triggerIxRefCall(NULL, VecPlnrVCall::CALLPLNRREFPRESET, jref, VecPlnrVPreset::PREPLNRJREFNOTIFY, jref);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgPlnrd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "addDcol");

	return(dcol);
};

DcolPlnr* XchgPlnrd::getDcolByJref(
			const ubigint jref
			, const bool tree
		) {
	JobPlnr* job = NULL;

	DcolPlnr* dcol = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "getDcolByJref");
	Mutex::lock(&mDcols, "mDcols", "XchgPlnrd", "getDcolByJref");

	job = getJobByJref(jref);

	while (job != NULL) {
		auto it = dcols.find(job->jref);

		if (it != dcols.end()) {
			dcol = it->second;
			dcol->lockAccess("XchgPlnrd", "getDcolByJref");

			break;
		};

		if (!tree) break;

		job = getJobByJref(job->jrefSup);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgPlnrd", "addDcol");
	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "addDcol");

	return(dcol);
};

void XchgPlnrd::removeDcolByJref(
			const ubigint jref
		) {
	Mutex::lock(&mDcols, "mDcols", "XchgPlnrd", "removeDcolByJref");

	auto it = dcols.find(jref);
	if (it != dcols.end()) {
		delete it->second;
		dcols.erase(it);
	};

	Mutex::unlock(&mDcols, "mDcols", "XchgPlnrd", "removeDcolByJref");
};

void XchgPlnrd::submitDpch(
			DpchEngPlnr* dpcheng
		) {
	DcolPlnr* dcol = NULL;
	pthread_cond_t* cReady_backup;

	DpchEngPlnr* dpchtest;

	// find dcol in charge
	dcol = getDcolByJref(dpcheng->jref);

	if (dcol) {
		if (dcol->req != NULL) {
			// a request is waiting
			delete dcol->req->dpcheng;
			dcol->req->dpcheng = dpcheng;

			cReady_backup = &(dcol->req->cReady);
			dcol->req = NULL;
			//cout << "XchgPlnrd::submitDpch() waiting request for ixPlnrVDpch = " << dpcheng->ixPlnrVDpch << ", jref = " << dpcheng->jref << endl;

			Cond::broadcast(cReady_backup, "dcol(" + to_string(dcol->jref) + ")->req->cReady", "XchgPlnrd", "submitDpch");

			dcol->unlockAccess("XchgPlnrd", "submitDpch");

		} else {
			// merge with similar dispatch if available
			for (auto it=dcol->dpchs.begin();it!=dcol->dpchs.end();) {
				dpchtest = *it;

				if ((dpchtest->ixPlnrVDpch == dpcheng->ixPlnrVDpch) && (dpchtest->jref == dpcheng->jref)) {
					dpchtest->merge(dpcheng);
					//cout << "XchgPlnrd::submitDpch() merge for ixPlnrVDpch = " << dpcheng->ixPlnrVDpch << ", jref = " << dpcheng->jref << endl;

					delete dpcheng;
					dpcheng = NULL;

					break;

				} else it++;
			};

			// append to list of dispatches
			if (dpcheng) {
				dcol->dpchs.push_back(dpcheng);
				//cout << "XchgPlnrd::submitDpch() append for ixPlnrVDpch = " << dpcheng->ixPlnrVDpch << ", jref = " << dpcheng->jref << endl;
			};

			dcol->unlockAccess("XchgPlnrd", "submitDpch");
		};

	} else {
		delete dpcheng;
	};
};

DpchEngPlnr* XchgPlnrd::pullFirstDpch(
			DcolPlnr* dcol
		) {
	DpchEngPlnr* dpcheng = NULL;

	// get first element from list ; assume access is locked
	if (!dcol->dpchs.empty()) {
		dpcheng = *(dcol->dpchs.begin());
		dcol->dpchs.pop_front();
	};

	return dpcheng;
};

ubigint XchgPlnrd::addJob(
			JobPlnr* job
		) {
	JobPlnr* supjob = NULL;

	// get new jref and append to job list
	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "addJob");

	return(job->jref);
};

ubigint XchgPlnrd::addJob(
			DbsPlnr* dbsplnr
			, JobPlnr* job
		) {
	JobPlnr* supjob = NULL;

	JobPlnr* mastjob = NULL;

	// get new jref, append to job list and integrate into master/slave structure
	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "addJob");

	job->jref = jrefseq->getNewRef();
	jobs[job->jref] = job;

	supjob = getJobByJref(job->jrefSup);
	if (supjob) supjob->jrefsSub.insert(job->jref);

	// find current master job
	for (auto it=jobs.begin();it!=jobs.end();it++) {
		if (it->second->ixPlnrVJob == job->ixPlnrVJob) {
			mastjob = getJobByJref(it->second->jrefMast);
			break;
		};
	};

	if (mastjob) {
		job->jrefMast = mastjob->jref;

		if (job->prefmast) {
			// priority for becoming new master
			mastjob->jrefsSlv.push_front(job->jref);
			job->becomeSlave(dbsplnr);

			claimMaster(dbsplnr, job->jref);

		} else {
			mastjob->jrefsSlv.push_back(job->jref);
			job->becomeSlave(dbsplnr);
		};

	} else {
		// only job of its type
		job->jrefMast = job->jref;
		job->becomeMaster(dbsplnr);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "addJob");

	return(job->jref);
};

JobPlnr* XchgPlnrd::getJobByJref(
			const ubigint jref
		) {
	JobPlnr* job = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "getJobByJref");

	auto it = jobs.find(jref);
	if (it != jobs.end()) job = it->second;

	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "getJobByJref");

	return job;
};

void XchgPlnrd::removeJobByJref(
			const ubigint jref
		) {
	JobPlnr* supjob = NULL;
	JobPlnr* job = NULL;
	JobPlnr* subjob = NULL;

	JobPlnr* mastjob = NULL;
	JobPlnr* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "removeJobByJref");

	job = getJobByJref(jref);

	if (job) {
		job->invalidateWakeups();

		removePresetsByJref(jref);
		removeStmgrByJref(jref);
		removeClstnsByJref(jref);
		removeDcolByJref(jref);

		// remove from master/slave structure
		if (job->jrefMast != 0) {
			if (job->jref == job->jrefMast) {
				mastjob = NULL;

				if (!job->jrefsSlv.empty()) {
					job->giveupMaster(NULL);
					mastjob = getJobByJref(job->jrefsSlv.front());
				};

				if (mastjob) {
					mastjob->giveupSlave(NULL);
					job->giveupMaster(NULL);

					mastjob->jrefsSlv = job->jrefsSlv;
					mastjob->jrefsSlv.pop_front();

					mastjob->jrefMast = mastjob->jref;

					for (auto it=mastjob->jrefsSlv.begin();it!=mastjob->jrefsSlv.end();it++) {
						slvjob = getJobByJref(*it);
						if (slvjob) slvjob->jrefMast = mastjob->jref;
					};

					mastjob->becomeMaster(NULL);
					triggerCall(NULL, VecPlnrVCall::CALLPLNRMASTSLVCHG, mastjob->jref);

				} else {
					job->giveupMaster(NULL);
				};

			} else {
				job->giveupSlave(NULL);

				mastjob = getJobByJref(job->jrefMast);
				if (mastjob) mastjob->jrefsSlv.remove(job->jref);
			};
		};

		// super-job
		supjob = getJobByJref(job->jrefSup);
		if (supjob) supjob->jrefsSub.erase(jref);

		// sub-jobs
		while (job->jrefsSub.size() > 0) {
			subjob = getJobByJref(*(job->jrefsSub.begin()));
			if (subjob) delete subjob;
		};

		// remove job from list only here otherwise sub-job delete will loop forever
		jobs.erase(jref);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "removeJobByJref");
};

void XchgPlnrd::transferMaster(
			DbsPlnr* dbsplnr
			, JobPlnr* fromjob
			, JobPlnr* tojob
		) {
	// requires mJobs locked and tojob at first position in fromjob->jrefsSlv
	JobPlnr* job = NULL;

	tojob->giveupSlave(dbsplnr);
	fromjob->giveupMaster(dbsplnr);

	tojob->jrefsSlv = fromjob->jrefsSlv;
	fromjob->jrefsSlv.clear();
	tojob->jrefsSlv.pop_front();

	if (fromjob->prefmast) tojob->jrefsSlv.push_front(fromjob->jref);
	else tojob->jrefsSlv.push_back(fromjob->jref);

	tojob->jrefMast = tojob->jref;

	for (auto it=tojob->jrefsSlv.begin();it!=tojob->jrefsSlv.end();it++) {
		job = getJobByJref(*it);
		if (job) job->jrefMast = tojob->jref;
	};

	tojob->becomeMaster(dbsplnr);
	fromjob->becomeSlave(dbsplnr);

	triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRMASTSLVCHG, tojob->jref);
	triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRMASTSLVCHG, fromjob->jref);
};

void XchgPlnrd::offerMaster(
			DbsPlnr* dbsplnr
			, const ubigint jref
		) {
	JobPlnr* mastjob = NULL;
	JobPlnr* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "offerMaster");

	mastjob = getJobByJref(jref);

	if (mastjob) {
		if (!mastjob->jrefsSlv.empty()) {
			slvjob = getJobByJref(mastjob->jrefsSlv.front());

			if (slvjob) if (slvjob->prefmast) transferMaster(dbsplnr, mastjob, slvjob);
		};
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "offerMaster");
};

bool XchgPlnrd::claimMaster(
			DbsPlnr* dbsplnr
			, const ubigint jref
		) {
	bool retval = false;

	JobPlnr* mastjob = NULL;
	JobPlnr* slvjob = NULL;

	Mutex::lock(&mJobs, "mJobs", "XchgPlnrd", "claimMaster");

	slvjob = getJobByJref(jref);

	if (slvjob) {
		if (slvjob->jref != slvjob->jrefMast) {
			mastjob = getJobByJref(slvjob->jrefMast);

			if (mastjob) {
				for (auto it=mastjob->jrefsSlv.begin();it!=mastjob->jrefsSlv.end();it++) {
					// put slvjob first
					if (*it == jref) {
						*it = mastjob->jrefsSlv.front();
						mastjob->jrefsSlv.pop_front();
						mastjob->jrefsSlv.push_front(jref);

						break;
					};
				};

				if (mastjob->handleClaimMaster(dbsplnr)) transferMaster(dbsplnr, mastjob, slvjob);
			};
		};

		retval = (slvjob->jref == slvjob->jrefMast);
	};

	Mutex::unlock(&mJobs, "mJobs", "XchgPlnrd", "claimMaster");

	return retval;
};

ubigint XchgPlnrd::addWakeup(
			const ubigint jref
			, const string sref
			, const unsigned int deltat
			, const bool weak
		) {
	int res;

	ubigint wref;

	pthread_t timer;

	wref = wrefseq->getNewRef();

	if (deltat == 0) {
		// immediate callback: generate request to be treated by job processor
		ReqPlnr* req = new ReqPlnr(ReqPlnr::VecVBasetype::TIMER);
		req->jref = jref;
		req->wref = wref;
		req->sref = sref;
		req->weak = false;

		addReq(req);

	} else {
		// delayed callback: generate dedicated wait thread
		WakeupPlnr* wakeup = new WakeupPlnr(this, wref, jref, sref, deltat, weak);

		res = pthread_create(&timer, NULL, &runWakeup, (void*) wakeup);
		if (res != 0) cout << "XchgPlnrd::addWakeup() error creating timer thread (" << res << ")" << endl;
		res = pthread_detach(timer);
		if (res != 0) cout << "XchgPlnrd::addWakeup() error detaching timer thread (" << res << ")" << endl;
	};

	return(wref);
};

void* XchgPlnrd::runWakeup(
			void* arg
		) {
	WakeupPlnr* wakeup = (WakeupPlnr*) arg;

	// wait for time specified in microseconds
	timespec deltat;
	deltat.tv_sec = wakeup->deltat / 1000000;
	deltat.tv_nsec = 1000 * (wakeup->deltat%1000000);
#ifdef _WIN32
	usleep(wakeup->deltat);
#else
	nanosleep(&deltat, NULL);
#endif

	// generate request to be treated by job processor
	ReqPlnr* req = new ReqPlnr(ReqPlnr::VecVBasetype::TIMER);
	req->jref = wakeup->jref;
	req->wref = wakeup->wref;
	req->sref = wakeup->sref;
	req->weak = wakeup->weak;

	wakeup->xchg->addReq(req);

	delete wakeup;

	return(NULL);
};

NodePlnr* XchgPlnrd::addNode(
			const string& ip
			, const uint port
			, const uint opprcn
			, const vector<string>& srefsOpk
		) {
	NodePlnr* node = NULL;

	Mutex::lock(&mNodes, "mNodes", "XchgPlnrd", "addNode");

	node = new NodePlnr(nrefseq->getNewRef(), ip, port, opprcn, srefsOpk);
	nodes[node->nref] = node;

	Mutex::unlock(&mNodes, "mNodes", "XchgPlnrd", "addNode");

	Cond::broadcast(&cOpengcli, "cOpengcli", "XchgPlnrd", "addNode");

	return(node);
};

NodePlnr* XchgPlnrd::getNodeByNref(
			const ubigint nref
		) {
	NodePlnr* node = NULL;

	Mutex::lock(&mNodes, "mNodes", "XchgPlnrd", "getNodeByNref");

	auto it = nodes.find(nref);
	if (it != nodes.end()) node = it->second;

	Mutex::unlock(&mNodes, "mNodes", "XchgPlnrd", "getNodeByNref");

	return(node);
};

void XchgPlnrd::removeNodeByNref(
			const ubigint nref
		) {
	Mutex::lock(&mNodes, "mNodes", "XchgPlnrd", "removeNodeByNref");

	auto it = nodes.find(nref);
	if (it != nodes.end()) {
		delete it->second;
		nodes.erase(it);
	};

	Mutex::unlock(&mNodes, "mNodes", "XchgPlnrd", "removeNodeByNref");
};


