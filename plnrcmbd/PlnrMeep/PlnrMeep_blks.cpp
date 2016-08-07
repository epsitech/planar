/**
  * \file PlnrMeep_blks.cpp
  * invocation / return data blocks for operation pack PlnrMeep (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMeep_blks.h"

/******************************************************************************
 class DpchInvPlnrMeepTrf2d
 ******************************************************************************/

DpchInvPlnrMeepTrf2d::DpchInvPlnrMeepTrf2d(
			const ubigint oref
			, const ubigint jref
			, const bool anisomat
			, const double deltalam
			, const double dt
			, const bool lossmat
			, const string& prefix
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
			, const ubigint refRastfile
			, const string& srefDom
			, const string& srefDomExc
			, const vector<string>& srefsDomMon
			, const vector<string>& srefsDomSshot
			, const bool tm
			, const double tstop
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRMEEPTRF2D, oref, jref) {
	this->anisomat = anisomat;
	this->deltalam = deltalam;
	this->dt = dt;
	this->lossmat = lossmat;
	this->prefix = prefix;
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMCalcitem = refPlnrMCalcitem;
	this->refRastfile = refRastfile;
	this->srefDom = srefDom;
	this->srefDomExc = srefDomExc;
	this->srefsDomMon = srefsDomMon;
	this->srefsDomSshot = srefsDomSshot;
	this->tm = tm;
	this->tstop = tstop;
};

void DpchInvPlnrMeepTrf2d::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrMeepTrf2d");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "anisomat", "", anisomat)) add(ANISOMAT);
		if (extractDoubleUclc(docctx, basexpath, "deltalam", "", deltalam)) add(DELTALAM);
		if (extractDoubleUclc(docctx, basexpath, "dt", "", dt)) add(DT);
		if (extractBoolUclc(docctx, basexpath, "lossmat", "", lossmat)) add(LOSSMAT);
		if (extractStringUclc(docctx, basexpath, "prefix", "", prefix)) add(PREFIX);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalc", "", refPlnrMCalc)) add(REFPLNRMCALC);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalcitem", "", refPlnrMCalcitem)) add(REFPLNRMCALCITEM);
		if (extractUbigintUclc(docctx, basexpath, "refRastfile", "", refRastfile)) add(REFRASTFILE);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringUclc(docctx, basexpath, "srefDomExc", "", srefDomExc)) add(SREFDOMEXC);
		if (extractStringvecUclc(docctx, basexpath, "srefsDomMon", "", srefsDomMon)) add(SREFSDOMMON);
		if (extractStringvecUclc(docctx, basexpath, "srefsDomSshot", "", srefsDomSshot)) add(SREFSDOMSSHOT);
		if (extractBoolUclc(docctx, basexpath, "tm", "", tm)) add(TM);
		if (extractDoubleUclc(docctx, basexpath, "tstop", "", tstop)) add(TSTOP);
	};
};

void DpchInvPlnrMeepTrf2d::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrMeepTrf2d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "anisomat", anisomat);
		writeDouble(wr, "deltalam", deltalam);
		writeDouble(wr, "dt", dt);
		writeBool(wr, "lossmat", lossmat);
		writeString(wr, "prefix", prefix);
		writeUbigint(wr, "refPlnrMCalc", refPlnrMCalc);
		writeUbigint(wr, "refPlnrMCalcitem", refPlnrMCalcitem);
		writeUbigint(wr, "refRastfile", refRastfile);
		writeString(wr, "srefDom", srefDom);
		writeString(wr, "srefDomExc", srefDomExc);
		writeStringvec(wr, "srefsDomMon", srefsDomMon);
		writeStringvec(wr, "srefsDomSshot", srefsDomSshot);
		writeBool(wr, "tm", tm);
		writeDouble(wr, "tstop", tstop);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrMeepTrf3d
 ******************************************************************************/

DpchInvPlnrMeepTrf3d::DpchInvPlnrMeepTrf3d(
			const ubigint oref
			, const ubigint jref
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRMEEPTRF3D, oref, jref) {
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMCalcitem = refPlnrMCalcitem;
};

void DpchInvPlnrMeepTrf3d::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrMeepTrf3d");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalc", "", refPlnrMCalc)) add(REFPLNRMCALC);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMCalcitem", "", refPlnrMCalcitem)) add(REFPLNRMCALCITEM);
	};
};

void DpchInvPlnrMeepTrf3d::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrMeepTrf3d");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigint(wr, "refPlnrMCalc", refPlnrMCalc);
		writeUbigint(wr, "refPlnrMCalcitem", refPlnrMCalcitem);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT


