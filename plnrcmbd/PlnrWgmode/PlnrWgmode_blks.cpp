/**
  * \file PlnrWgmode_blks.cpp
  * invocation / return data blocks for operation pack PlnrWgmode (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrWgmode_blks.h"

/******************************************************************************
 class DpchInvPlnrWgmodeFd1d
 ******************************************************************************/

DpchInvPlnrWgmodeFd1d::DpchInvPlnrWgmodeFd1d(
			const ubigint oref
			, const ubigint jref
			, const bool lossmat
			, const string& prefix
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
			, const ubigint refRastfile
			, const string& srefDom
			, const vector<string>& srefsDomEval
			, const bool te
			, const bool tm
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRWGMODEFD1D, oref, jref) {
	this->lossmat = lossmat;
	this->prefix = prefix;
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMCalcitem = refPlnrMCalcitem;
	this->refRastfile = refRastfile;
	this->srefDom = srefDom;
	this->srefsDomEval = srefsDomEval;
	this->te = te;
	this->tm = tm;
};

void DpchInvPlnrWgmodeFd1d::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrWgmodeFd1d");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "lossmat", "", lossmat)) add(LOSSMAT);
		if (extractStringUclc(docctx, basexpath, "prefix", "", prefix)) add(PREFIX);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalc", "", refPlnrMCalc)) add(REFPLNRMCALC);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalcitem", "", refPlnrMCalcitem)) add(REFPLNRMCALCITEM);
		if (extractUbigintUclc(docctx, basexpath, "refRastfile", "", refRastfile)) add(REFRASTFILE);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringvecUclc(docctx, basexpath, "srefsDomEval", "", srefsDomEval)) add(SREFSDOMEVAL);
		if (extractBoolUclc(docctx, basexpath, "te", "", te)) add(TE);
		if (extractBoolUclc(docctx, basexpath, "tm", "", tm)) add(TM);
	};
};

void DpchInvPlnrWgmodeFd1d::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrWgmodeFd1d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "lossmat", lossmat);
		writeString(wr, "prefix", prefix);
		writeUbigint(wr, "refPlnrMCalc", refPlnrMCalc);
		writeUbigint(wr, "refPlnrMCalcitem", refPlnrMCalcitem);
		writeUbigint(wr, "refRastfile", refRastfile);
		writeString(wr, "srefDom", srefDom);
		writeStringvec(wr, "srefsDomEval", srefsDomEval);
		writeBool(wr, "te", te);
		writeBool(wr, "tm", tm);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrWgmodeFd1d
 ******************************************************************************/

DpchRetPlnrWgmodeFd1d::DpchRetPlnrWgmodeFd1d(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const uint teN
			, const uint tmN
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRWGMODEFD1D, scrOref, scrJref) {
	this->success = success;
	this->teN = teN;
	this->tmN = tmN;
};

void DpchRetPlnrWgmodeFd1d::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrWgmodeFd1d");
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
		if (extractUintUclc(docctx, basexpath, "teN", "", teN)) add(TEN);
		if (extractUintUclc(docctx, basexpath, "tmN", "", tmN)) add(TMN);
	};
};

void DpchRetPlnrWgmodeFd1d::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrWgmodeFd1d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeUint(wr, "teN", teN);
		writeUint(wr, "tmN", tmN);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrWgmodeFd2d
 ******************************************************************************/

DpchInvPlnrWgmodeFd2d::DpchInvPlnrWgmodeFd2d(
			const ubigint oref
			, const ubigint jref
			, const bool lossmat
			, const string& prefix
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
			, const ubigint refRastfile
			, const string& srefDom
			, const vector<string>& srefsDomEval
			, const bool te
			, const bool tm
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRWGMODEFD2D, oref, jref) {
	this->lossmat = lossmat;
	this->prefix = prefix;
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMCalcitem = refPlnrMCalcitem;
	this->refRastfile = refRastfile;
	this->srefDom = srefDom;
	this->srefsDomEval = srefsDomEval;
	this->te = te;
	this->tm = tm;
};

void DpchInvPlnrWgmodeFd2d::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrWgmodeFd2d");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "lossmat", "", lossmat)) add(LOSSMAT);
		if (extractStringUclc(docctx, basexpath, "prefix", "", prefix)) add(PREFIX);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalc", "", refPlnrMCalc)) add(REFPLNRMCALC);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalcitem", "", refPlnrMCalcitem)) add(REFPLNRMCALCITEM);
		if (extractUbigintUclc(docctx, basexpath, "refRastfile", "", refRastfile)) add(REFRASTFILE);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringvecUclc(docctx, basexpath, "srefsDomEval", "", srefsDomEval)) add(SREFSDOMEVAL);
		if (extractBoolUclc(docctx, basexpath, "te", "", te)) add(TE);
		if (extractBoolUclc(docctx, basexpath, "tm", "", tm)) add(TM);
	};
};

void DpchInvPlnrWgmodeFd2d::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrWgmodeFd2d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "lossmat", lossmat);
		writeString(wr, "prefix", prefix);
		writeUbigint(wr, "refPlnrMCalc", refPlnrMCalc);
		writeUbigint(wr, "refPlnrMCalcitem", refPlnrMCalcitem);
		writeUbigint(wr, "refRastfile", refRastfile);
		writeString(wr, "srefDom", srefDom);
		writeStringvec(wr, "srefsDomEval", srefsDomEval);
		writeBool(wr, "te", te);
		writeBool(wr, "tm", tm);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrWgmodeFd2d
 ******************************************************************************/

DpchRetPlnrWgmodeFd2d::DpchRetPlnrWgmodeFd2d(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const uint teN
			, const uint tmN
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRWGMODEFD2D, scrOref, scrJref) {
	this->success = success;
	this->teN = teN;
	this->tmN = tmN;
};

void DpchRetPlnrWgmodeFd2d::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrWgmodeFd2d");
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
		if (extractUintUclc(docctx, basexpath, "teN", "", teN)) add(TEN);
		if (extractUintUclc(docctx, basexpath, "tmN", "", tmN)) add(TMN);
	};
};

void DpchRetPlnrWgmodeFd2d::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrWgmodeFd2d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeUint(wr, "teN", teN);
		writeUint(wr, "tmN", tmN);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrWgmodeFem1d
 ******************************************************************************/

DpchInvPlnrWgmodeFem1d::DpchInvPlnrWgmodeFem1d(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRWGMODEFEM1D, oref, jref) {
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMCalcitem = refPlnrMCalcitem;
};

void DpchInvPlnrWgmodeFem1d::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrWgmodeFem1d");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalc", "", refPlnrMCalc)) add(REFPLNRMCALC);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalcitem", "", refPlnrMCalcitem)) add(REFPLNRMCALCITEM);
	};
};

void DpchInvPlnrWgmodeFem1d::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrWgmodeFem1d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMCalc", refPlnrMCalc);
		writeUbigint(wr, "refPlnrMCalcitem", refPlnrMCalcitem);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrWgmodeFem2d
 ******************************************************************************/

DpchInvPlnrWgmodeFem2d::DpchInvPlnrWgmodeFem2d(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRWGMODEFEM2D, oref, jref) {
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMCalcitem = refPlnrMCalcitem;
};

void DpchInvPlnrWgmodeFem2d::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrWgmodeFem2d");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalc", "", refPlnrMCalc)) add(REFPLNRMCALC);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalcitem", "", refPlnrMCalcitem)) add(REFPLNRMCALCITEM);
	};
};

void DpchInvPlnrWgmodeFem2d::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrWgmodeFem2d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMCalc", refPlnrMCalc);
		writeUbigint(wr, "refPlnrMCalcitem", refPlnrMCalcitem);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT


