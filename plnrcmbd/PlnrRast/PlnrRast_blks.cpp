/**
  * \file PlnrRast_blks.cpp
  * invocation / return data blocks for operation pack PlnrRast (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRast_blks.h"

/******************************************************************************
 class DpchInvPlnrRastCub
 ******************************************************************************/

DpchInvPlnrRastCub::DpchInvPlnrRastCub(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDesign
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRRASTCUB, oref, jref) {
	this->refPlnrMDesign = refPlnrMDesign;
};

void DpchInvPlnrRastCub::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrRastCub");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
	};
};

void DpchInvPlnrRastCub::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrRastCub");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrRastCub
 ******************************************************************************/

DpchRetPlnrRastCub::DpchRetPlnrRastCub(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const ubigint refPlnrMFile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRRASTCUB, scrOref, scrJref) {
	this->success = success;
	this->refPlnrMFile = refPlnrMFile;
};

void DpchRetPlnrRastCub::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrRastCub");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMFile", "", refPlnrMFile)) add(REFPLNRMFILE);
	};
};

void DpchRetPlnrRastCub::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrRastCub");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeUbigint(wr, "refPlnrMFile", refPlnrMFile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrRastXybox
 ******************************************************************************/

DpchInvPlnrRastXybox::DpchInvPlnrRastXybox(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDesign
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRRASTXYBOX, oref, jref) {
	this->refPlnrMDesign = refPlnrMDesign;
};

void DpchInvPlnrRastXybox::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrRastXybox");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
	};
};

void DpchInvPlnrRastXybox::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrRastXybox");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrRastXybox
 ******************************************************************************/

DpchRetPlnrRastXybox::DpchRetPlnrRastXybox(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const ubigint refPlnrMFile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRRASTXYBOX, scrOref, scrJref) {
	this->success = success;
	this->refPlnrMFile = refPlnrMFile;
};

void DpchRetPlnrRastXybox::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrRastXybox");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMFile", "", refPlnrMFile)) add(REFPLNRMFILE);
	};
};

void DpchRetPlnrRastXybox::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrRastXybox");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeUbigint(wr, "refPlnrMFile", refPlnrMFile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrRastZline
 ******************************************************************************/

DpchInvPlnrRastZline::DpchInvPlnrRastZline(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMDesign
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRRASTZLINE, oref, jref) {
	this->refPlnrMDesign = refPlnrMDesign;
};

void DpchInvPlnrRastZline::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrRastZline");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
	};
};

void DpchInvPlnrRastZline::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrRastZline");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrRastZline
 ******************************************************************************/

DpchRetPlnrRastZline::DpchRetPlnrRastZline(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const ubigint refPlnrMFile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRRASTZLINE, scrOref, scrJref) {
	this->success = success;
	this->refPlnrMFile = refPlnrMFile;
};

void DpchRetPlnrRastZline::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrRastZline");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMFile", "", refPlnrMFile)) add(REFPLNRMFILE);
	};
};

void DpchRetPlnrRastZline::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrRastZline");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeUbigint(wr, "refPlnrMFile", refPlnrMFile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT


