/**
  * \file PlnrPlot_blks.cpp
  * invocation / return data blocks for operation pack PlnrPlot (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrPlot_blks.h"

/******************************************************************************
 class DpchInvPlnrPlotDat1dgnu
 ******************************************************************************/

DpchInvPlnrPlotDat1dgnu::DpchInvPlnrPlotDat1dgnu(
			const ubigint oref
			, const ubigint jref
			, const string& alttitle
			, const string& altxtitle
			, const string& altytitle
			, const ubigint refFile
			, const string& xpath
			, const string& xvar
			, const string& ypath
			, const vector<string>& yslcDims
			, const vector<int>& yslcIcs
			, const string& yvar
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNU, oref, jref) {
	this->alttitle = alttitle;
	this->altxtitle = altxtitle;
	this->altytitle = altytitle;
	this->refFile = refFile;
	this->xpath = xpath;
	this->xvar = xvar;
	this->ypath = ypath;
	this->yslcDims = yslcDims;
	this->yslcIcs = yslcIcs;
	this->yvar = yvar;
};

void DpchInvPlnrPlotDat1dgnu::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDat1dgnu");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "alttitle", "", alttitle)) add(ALTTITLE);
		if (extractStringUclc(docctx, basexpath, "altxtitle", "", altxtitle)) add(ALTXTITLE);
		if (extractStringUclc(docctx, basexpath, "altytitle", "", altytitle)) add(ALTYTITLE);
		if (extractUbigintUclc(docctx, basexpath, "refFile", "", refFile)) add(REFFILE);
		if (extractStringUclc(docctx, basexpath, "xpath", "", xpath)) add(XPATH);
		if (extractStringUclc(docctx, basexpath, "xvar", "", xvar)) add(XVAR);
		if (extractStringUclc(docctx, basexpath, "ypath", "", ypath)) add(YPATH);
		if (extractStringvecUclc(docctx, basexpath, "yslcDims", "", yslcDims)) add(YSLCDIMS);
		if (extractIntvecUclc(docctx, basexpath, "yslcIcs", "", yslcIcs)) add(YSLCICS);
		if (extractStringUclc(docctx, basexpath, "yvar", "", yvar)) add(YVAR);
	};
};

void DpchInvPlnrPlotDat1dgnu::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDat1dgnu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeString(wr, "alttitle", alttitle);
		writeString(wr, "altxtitle", altxtitle);
		writeString(wr, "altytitle", altytitle);
		writeUbigint(wr, "refFile", refFile);
		writeString(wr, "xpath", xpath);
		writeString(wr, "xvar", xvar);
		writeString(wr, "ypath", ypath);
		writeStringvec(wr, "yslcDims", yslcDims);
		writeIntvec(wr, "yslcIcs", yslcIcs);
		writeString(wr, "yvar", yvar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDat1dgnu
 ******************************************************************************/

DpchRetPlnrPlotDat1dgnu::DpchRetPlnrPlotDat1dgnu(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& tgzfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDAT1DGNU, scrOref, scrJref) {
	this->success = success;
	this->tgzfile = tgzfile;
};

void DpchRetPlnrPlotDat1dgnu::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDat1dgnu");
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
		if (extractStringUclc(docctx, basexpath, "tgzfile", "", tgzfile)) add(TGZFILE);
	};
};

void DpchRetPlnrPlotDat1dgnu::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDat1dgnu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "tgzfile", tgzfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDat1dgnumult
 ******************************************************************************/

DpchInvPlnrPlotDat1dgnumult::DpchInvPlnrPlotDat1dgnumult(
			const ubigint oref
			, const ubigint jref
			, const vector<ubigint>& refsFile
			, const string& title
			, const vector<string>& xpaths
			, const string& xtitle
			, const vector<string>& xvars
			, const vector<string>& ypaths
			, const string& ytitle
			, const vector<string>& yvars
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNUMULT, oref, jref) {
	this->refsFile = refsFile;
	this->title = title;
	this->xpaths = xpaths;
	this->xtitle = xtitle;
	this->xvars = xvars;
	this->ypaths = ypaths;
	this->ytitle = ytitle;
	this->yvars = yvars;
};

void DpchInvPlnrPlotDat1dgnumult::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDat1dgnumult");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUbigintvecUclc(docctx, basexpath, "refsFile", "", refsFile)) add(REFSFILE);
		if (extractStringUclc(docctx, basexpath, "title", "", title)) add(TITLE);
		if (extractStringvecUclc(docctx, basexpath, "xpaths", "", xpaths)) add(XPATHS);
		if (extractStringUclc(docctx, basexpath, "xtitle", "", xtitle)) add(XTITLE);
		if (extractStringvecUclc(docctx, basexpath, "xvars", "", xvars)) add(XVARS);
		if (extractStringvecUclc(docctx, basexpath, "ypaths", "", ypaths)) add(YPATHS);
		if (extractStringUclc(docctx, basexpath, "ytitle", "", ytitle)) add(YTITLE);
		if (extractStringvecUclc(docctx, basexpath, "yvars", "", yvars)) add(YVARS);
	};
};

void DpchInvPlnrPlotDat1dgnumult::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDat1dgnumult");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUbigintvec(wr, "refsFile", refsFile);
		writeString(wr, "title", title);
		writeStringvec(wr, "xpaths", xpaths);
		writeString(wr, "xtitle", xtitle);
		writeStringvec(wr, "xvars", xvars);
		writeStringvec(wr, "ypaths", ypaths);
		writeString(wr, "ytitle", ytitle);
		writeStringvec(wr, "yvars", yvars);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDat1dgnumult
 ******************************************************************************/

DpchRetPlnrPlotDat1dgnumult::DpchRetPlnrPlotDat1dgnumult(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& tgzfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDAT1DGNUMULT, scrOref, scrJref) {
	this->success = success;
	this->tgzfile = tgzfile;
};

void DpchRetPlnrPlotDat1dgnumult::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDat1dgnumult");
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
		if (extractStringUclc(docctx, basexpath, "tgzfile", "", tgzfile)) add(TGZFILE);
	};
};

void DpchRetPlnrPlotDat1dgnumult::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDat1dgnumult");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "tgzfile", tgzfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDevsvg
 ******************************************************************************/

DpchInvPlnrPlotDevsvg::DpchInvPlnrPlotDevsvg(
			const ubigint oref
			, const ubigint jref
			, const uint height
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMDevice
			, const vector<ubigint>& refsSru
			, const vector<ubigint>& refsSubdev
			, const bool showfces
			, const bool showgds
			, const bool showvtxs
			, const uint width
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDEVSVG, oref, jref) {
	this->height = height;
	this->refBasedsn = refBasedsn;
	this->refModdsn = refModdsn;
	this->refPlnrMDevice = refPlnrMDevice;
	this->refsSru = refsSru;
	this->refsSubdev = refsSubdev;
	this->showfces = showfces;
	this->showgds = showgds;
	this->showvtxs = showvtxs;
	this->width = width;
};

void DpchInvPlnrPlotDevsvg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDevsvg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractUbigintUclc(docctx, basexpath, "refBasedsn", "", refBasedsn)) add(REFBASEDSN);
		if (extractUbigintUclc(docctx, basexpath, "refModdsn", "", refModdsn)) add(REFMODDSN);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDevice", "", refPlnrMDevice)) add(REFPLNRMDEVICE);
		if (extractUbigintvecUclc(docctx, basexpath, "refsSru", "", refsSru)) add(REFSSRU);
		if (extractUbigintvecUclc(docctx, basexpath, "refsSubdev", "", refsSubdev)) add(REFSSUBDEV);
		if (extractBoolUclc(docctx, basexpath, "showfces", "", showfces)) add(SHOWFCES);
		if (extractBoolUclc(docctx, basexpath, "showgds", "", showgds)) add(SHOWGDS);
		if (extractBoolUclc(docctx, basexpath, "showvtxs", "", showvtxs)) add(SHOWVTXS);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
	};
};

void DpchInvPlnrPlotDevsvg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDevsvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUint(wr, "height", height);
		writeUbigint(wr, "refBasedsn", refBasedsn);
		writeUbigint(wr, "refModdsn", refModdsn);
		writeUbigint(wr, "refPlnrMDevice", refPlnrMDevice);
		writeUbigintvec(wr, "refsSru", refsSru);
		writeUbigintvec(wr, "refsSubdev", refsSubdev);
		writeBool(wr, "showfces", showfces);
		writeBool(wr, "showgds", showgds);
		writeBool(wr, "showvtxs", showvtxs);
		writeUint(wr, "width", width);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDevsvg
 ******************************************************************************/

DpchRetPlnrPlotDevsvg::DpchRetPlnrPlotDevsvg(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& svgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDEVSVG, scrOref, scrJref) {
	this->success = success;
	this->svgfile = svgfile;
};

void DpchRetPlnrPlotDevsvg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDevsvg");
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
		if (extractStringUclc(docctx, basexpath, "svgfile", "", svgfile)) add(SVGFILE);
	};
};

void DpchRetPlnrPlotDevsvg::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDevsvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "svgfile", svgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDomdat1dgnu
 ******************************************************************************/

DpchInvPlnrPlotDomdat1dgnu::DpchInvPlnrPlotDomdat1dgnu(
			const ubigint oref
			, const ubigint jref
			, const string& alttitle
			, const string& altytitle
			, const ubigint refFile
			, const string& srefDom
			, const string& xdim
			, const vector<string>& yslcDims
			, const vector<int>& yslcIcs
			, const string& yvar
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT1DGNU, oref, jref) {
	this->alttitle = alttitle;
	this->altytitle = altytitle;
	this->refFile = refFile;
	this->srefDom = srefDom;
	this->xdim = xdim;
	this->yslcDims = yslcDims;
	this->yslcIcs = yslcIcs;
	this->yvar = yvar;
};

void DpchInvPlnrPlotDomdat1dgnu::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDomdat1dgnu");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "alttitle", "", alttitle)) add(ALTTITLE);
		if (extractStringUclc(docctx, basexpath, "altytitle", "", altytitle)) add(ALTYTITLE);
		if (extractUbigintUclc(docctx, basexpath, "refFile", "", refFile)) add(REFFILE);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringUclc(docctx, basexpath, "xdim", "", xdim)) add(XDIM);
		if (extractStringvecUclc(docctx, basexpath, "yslcDims", "", yslcDims)) add(YSLCDIMS);
		if (extractIntvecUclc(docctx, basexpath, "yslcIcs", "", yslcIcs)) add(YSLCICS);
		if (extractStringUclc(docctx, basexpath, "yvar", "", yvar)) add(YVAR);
	};
};

void DpchInvPlnrPlotDomdat1dgnu::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDomdat1dgnu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeString(wr, "alttitle", alttitle);
		writeString(wr, "altytitle", altytitle);
		writeUbigint(wr, "refFile", refFile);
		writeString(wr, "srefDom", srefDom);
		writeString(wr, "xdim", xdim);
		writeStringvec(wr, "yslcDims", yslcDims);
		writeIntvec(wr, "yslcIcs", yslcIcs);
		writeString(wr, "yvar", yvar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDomdat1dgnu
 ******************************************************************************/

DpchRetPlnrPlotDomdat1dgnu::DpchRetPlnrPlotDomdat1dgnu(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& tgzfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT1DGNU, scrOref, scrJref) {
	this->success = success;
	this->tgzfile = tgzfile;
};

void DpchRetPlnrPlotDomdat1dgnu::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDomdat1dgnu");
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
		if (extractStringUclc(docctx, basexpath, "tgzfile", "", tgzfile)) add(TGZFILE);
	};
};

void DpchRetPlnrPlotDomdat1dgnu::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDomdat1dgnu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "tgzfile", tgzfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDomdat2dgnu
 ******************************************************************************/

DpchInvPlnrPlotDomdat2dgnu::DpchInvPlnrPlotDomdat2dgnu(
			const ubigint oref
			, const ubigint jref
			, const string& alttitle
			, const ubigint refFile
			, const bool spczlim
			, const string& srefDom
			, const string& xdim
			, const string& ydim
			, const double zmax
			, const double zmin
			, const vector<string>& zslcDims
			, const vector<int>& zslcIcs
			, const string& zvar
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DGNU, oref, jref) {
	this->alttitle = alttitle;
	this->refFile = refFile;
	this->spczlim = spczlim;
	this->srefDom = srefDom;
	this->xdim = xdim;
	this->ydim = ydim;
	this->zmax = zmax;
	this->zmin = zmin;
	this->zslcDims = zslcDims;
	this->zslcIcs = zslcIcs;
	this->zvar = zvar;
};

void DpchInvPlnrPlotDomdat2dgnu::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDomdat2dgnu");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "alttitle", "", alttitle)) add(ALTTITLE);
		if (extractUbigintUclc(docctx, basexpath, "refFile", "", refFile)) add(REFFILE);
		if (extractBoolUclc(docctx, basexpath, "spczlim", "", spczlim)) add(SPCZLIM);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringUclc(docctx, basexpath, "xdim", "", xdim)) add(XDIM);
		if (extractStringUclc(docctx, basexpath, "ydim", "", ydim)) add(YDIM);
		if (extractDoubleUclc(docctx, basexpath, "zmax", "", zmax)) add(ZMAX);
		if (extractDoubleUclc(docctx, basexpath, "zmin", "", zmin)) add(ZMIN);
		if (extractStringvecUclc(docctx, basexpath, "zslcDims", "", zslcDims)) add(ZSLCDIMS);
		if (extractIntvecUclc(docctx, basexpath, "zslcIcs", "", zslcIcs)) add(ZSLCICS);
		if (extractStringUclc(docctx, basexpath, "zvar", "", zvar)) add(ZVAR);
	};
};

void DpchInvPlnrPlotDomdat2dgnu::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDomdat2dgnu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeString(wr, "alttitle", alttitle);
		writeUbigint(wr, "refFile", refFile);
		writeBool(wr, "spczlim", spczlim);
		writeString(wr, "srefDom", srefDom);
		writeString(wr, "xdim", xdim);
		writeString(wr, "ydim", ydim);
		writeDouble(wr, "zmax", zmax);
		writeDouble(wr, "zmin", zmin);
		writeStringvec(wr, "zslcDims", zslcDims);
		writeIntvec(wr, "zslcIcs", zslcIcs);
		writeString(wr, "zvar", zvar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDomdat2dgnu
 ******************************************************************************/

DpchRetPlnrPlotDomdat2dgnu::DpchRetPlnrPlotDomdat2dgnu(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& tgzfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DGNU, scrOref, scrJref) {
	this->success = success;
	this->tgzfile = tgzfile;
};

void DpchRetPlnrPlotDomdat2dgnu::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDomdat2dgnu");
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
		if (extractStringUclc(docctx, basexpath, "tgzfile", "", tgzfile)) add(TGZFILE);
	};
};

void DpchRetPlnrPlotDomdat2dgnu::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDomdat2dgnu");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "tgzfile", tgzfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDomdat2dpng
 ******************************************************************************/

DpchInvPlnrPlotDomdat2dpng::DpchInvPlnrPlotDomdat2dpng(
			const ubigint oref
			, const ubigint jref
			, const double altzmax
			, const double altzmin
			, const string& annotColor
			, const string& annotDim
			, const uint annotHeight
			, const string& annotPos
			, const string& annotText
			, const bool ctrzero
			, const bool logscale
			, const ubigint refFile
			, const bool spczlim
			, const string& srefDom
			, const string& xdim
			, const string& ydim
			, const vector<string>& zslcDims
			, const vector<int>& zslcIcs
			, const string& zvar
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DPNG, oref, jref) {
	this->altzmax = altzmax;
	this->altzmin = altzmin;
	this->annotColor = annotColor;
	this->annotDim = annotDim;
	this->annotHeight = annotHeight;
	this->annotPos = annotPos;
	this->annotText = annotText;
	this->ctrzero = ctrzero;
	this->logscale = logscale;
	this->refFile = refFile;
	this->spczlim = spczlim;
	this->srefDom = srefDom;
	this->xdim = xdim;
	this->ydim = ydim;
	this->zslcDims = zslcDims;
	this->zslcIcs = zslcIcs;
	this->zvar = zvar;
};

void DpchInvPlnrPlotDomdat2dpng::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDomdat2dpng");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractDoubleUclc(docctx, basexpath, "altzmax", "", altzmax)) add(ALTZMAX);
		if (extractDoubleUclc(docctx, basexpath, "altzmin", "", altzmin)) add(ALTZMIN);
		if (extractStringUclc(docctx, basexpath, "annotColor", "", annotColor)) add(ANNOTCOLOR);
		if (extractStringUclc(docctx, basexpath, "annotDim", "", annotDim)) add(ANNOTDIM);
		if (extractUintUclc(docctx, basexpath, "annotHeight", "", annotHeight)) add(ANNOTHEIGHT);
		if (extractStringUclc(docctx, basexpath, "annotPos", "", annotPos)) add(ANNOTPOS);
		if (extractStringUclc(docctx, basexpath, "annotText", "", annotText)) add(ANNOTTEXT);
		if (extractBoolUclc(docctx, basexpath, "ctrzero", "", ctrzero)) add(CTRZERO);
		if (extractBoolUclc(docctx, basexpath, "logscale", "", logscale)) add(LOGSCALE);
		if (extractUbigintUclc(docctx, basexpath, "refFile", "", refFile)) add(REFFILE);
		if (extractBoolUclc(docctx, basexpath, "spczlim", "", spczlim)) add(SPCZLIM);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringUclc(docctx, basexpath, "xdim", "", xdim)) add(XDIM);
		if (extractStringUclc(docctx, basexpath, "ydim", "", ydim)) add(YDIM);
		if (extractStringvecUclc(docctx, basexpath, "zslcDims", "", zslcDims)) add(ZSLCDIMS);
		if (extractIntvecUclc(docctx, basexpath, "zslcIcs", "", zslcIcs)) add(ZSLCICS);
		if (extractStringUclc(docctx, basexpath, "zvar", "", zvar)) add(ZVAR);
	};
};

void DpchInvPlnrPlotDomdat2dpng::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDomdat2dpng");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeDouble(wr, "altzmax", altzmax);
		writeDouble(wr, "altzmin", altzmin);
		writeString(wr, "annotColor", annotColor);
		writeString(wr, "annotDim", annotDim);
		writeUint(wr, "annotHeight", annotHeight);
		writeString(wr, "annotPos", annotPos);
		writeString(wr, "annotText", annotText);
		writeBool(wr, "ctrzero", ctrzero);
		writeBool(wr, "logscale", logscale);
		writeUbigint(wr, "refFile", refFile);
		writeBool(wr, "spczlim", spczlim);
		writeString(wr, "srefDom", srefDom);
		writeString(wr, "xdim", xdim);
		writeString(wr, "ydim", ydim);
		writeStringvec(wr, "zslcDims", zslcDims);
		writeIntvec(wr, "zslcIcs", zslcIcs);
		writeString(wr, "zvar", zvar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDomdat2dpng
 ******************************************************************************/

DpchRetPlnrPlotDomdat2dpng::DpchRetPlnrPlotDomdat2dpng(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& pngfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DPNG, scrOref, scrJref) {
	this->success = success;
	this->pngfile = pngfile;
};

void DpchRetPlnrPlotDomdat2dpng::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDomdat2dpng");
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
		if (extractStringUclc(docctx, basexpath, "pngfile", "", pngfile)) add(PNGFILE);
	};
};

void DpchRetPlnrPlotDomdat2dpng::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDomdat2dpng");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "pngfile", pngfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDomdat2dvid
 ******************************************************************************/

DpchInvPlnrPlotDomdat2dvid::DpchInvPlnrPlotDomdat2dvid(
			const ubigint oref
			, const ubigint jref
			, const double altzmax
			, const double altzmin
			, const string& annotColor
			, const uint annotHeight
			, const bool ctrzero
			, const uint frmrate
			, const bool logscale
			, const ubigint refFile
			, const bool spczlim
			, const string& srefDom
			, const string& tdim
			, const string& xdim
			, const string& ydim
			, const vector<string>& zslcDims
			, const vector<int>& zslcIcs
			, const string& zvar
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DVID, oref, jref) {
	this->altzmax = altzmax;
	this->altzmin = altzmin;
	this->annotColor = annotColor;
	this->annotHeight = annotHeight;
	this->ctrzero = ctrzero;
	this->frmrate = frmrate;
	this->logscale = logscale;
	this->refFile = refFile;
	this->spczlim = spczlim;
	this->srefDom = srefDom;
	this->tdim = tdim;
	this->xdim = xdim;
	this->ydim = ydim;
	this->zslcDims = zslcDims;
	this->zslcIcs = zslcIcs;
	this->zvar = zvar;
};

void DpchInvPlnrPlotDomdat2dvid::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDomdat2dvid");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractDoubleUclc(docctx, basexpath, "altzmax", "", altzmax)) add(ALTZMAX);
		if (extractDoubleUclc(docctx, basexpath, "altzmin", "", altzmin)) add(ALTZMIN);
		if (extractStringUclc(docctx, basexpath, "annotColor", "", annotColor)) add(ANNOTCOLOR);
		if (extractUintUclc(docctx, basexpath, "annotHeight", "", annotHeight)) add(ANNOTHEIGHT);
		if (extractBoolUclc(docctx, basexpath, "ctrzero", "", ctrzero)) add(CTRZERO);
		if (extractUintUclc(docctx, basexpath, "frmrate", "", frmrate)) add(FRMRATE);
		if (extractBoolUclc(docctx, basexpath, "logscale", "", logscale)) add(LOGSCALE);
		if (extractUbigintUclc(docctx, basexpath, "refFile", "", refFile)) add(REFFILE);
		if (extractBoolUclc(docctx, basexpath, "spczlim", "", spczlim)) add(SPCZLIM);
		if (extractStringUclc(docctx, basexpath, "srefDom", "", srefDom)) add(SREFDOM);
		if (extractStringUclc(docctx, basexpath, "tdim", "", tdim)) add(TDIM);
		if (extractStringUclc(docctx, basexpath, "xdim", "", xdim)) add(XDIM);
		if (extractStringUclc(docctx, basexpath, "ydim", "", ydim)) add(YDIM);
		if (extractStringvecUclc(docctx, basexpath, "zslcDims", "", zslcDims)) add(ZSLCDIMS);
		if (extractIntvecUclc(docctx, basexpath, "zslcIcs", "", zslcIcs)) add(ZSLCICS);
		if (extractStringUclc(docctx, basexpath, "zvar", "", zvar)) add(ZVAR);
	};
};

void DpchInvPlnrPlotDomdat2dvid::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDomdat2dvid");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeDouble(wr, "altzmax", altzmax);
		writeDouble(wr, "altzmin", altzmin);
		writeString(wr, "annotColor", annotColor);
		writeUint(wr, "annotHeight", annotHeight);
		writeBool(wr, "ctrzero", ctrzero);
		writeUint(wr, "frmrate", frmrate);
		writeBool(wr, "logscale", logscale);
		writeUbigint(wr, "refFile", refFile);
		writeBool(wr, "spczlim", spczlim);
		writeString(wr, "srefDom", srefDom);
		writeString(wr, "tdim", tdim);
		writeString(wr, "xdim", xdim);
		writeString(wr, "ydim", ydim);
		writeStringvec(wr, "zslcDims", zslcDims);
		writeIntvec(wr, "zslcIcs", zslcIcs);
		writeString(wr, "zvar", zvar);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDomdat2dvid
 ******************************************************************************/

DpchRetPlnrPlotDomdat2dvid::DpchRetPlnrPlotDomdat2dvid(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& mpgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDOMDAT2DVID, scrOref, scrJref) {
	this->success = success;
	this->mpgfile = mpgfile;
};

void DpchRetPlnrPlotDomdat2dvid::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDomdat2dvid");
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
		if (extractStringUclc(docctx, basexpath, "mpgfile", "", mpgfile)) add(MPGFILE);
	};
};

void DpchRetPlnrPlotDomdat2dvid::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDomdat2dvid");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "mpgfile", mpgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDomzcssvg
 ******************************************************************************/

DpchInvPlnrPlotDomzcssvg::DpchInvPlnrPlotDomzcssvg(
			const ubigint oref
			, const ubigint jref
			, const string& datPngpath
			, const string& datTit
			, const bool eqz
			, const uint height
			, const ubigint refPlnrMDomain
			, const bool showfces
			, const bool showlvls
			, const bool showvtxs
			, const uint width
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDOMZCSSVG, oref, jref) {
	this->datPngpath = datPngpath;
	this->datTit = datTit;
	this->eqz = eqz;
	this->height = height;
	this->refPlnrMDomain = refPlnrMDomain;
	this->showfces = showfces;
	this->showlvls = showlvls;
	this->showvtxs = showvtxs;
	this->width = width;
};

void DpchInvPlnrPlotDomzcssvg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDomzcssvg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "datPngpath", "", datPngpath)) add(DATPNGPATH);
		if (extractStringUclc(docctx, basexpath, "datTit", "", datTit)) add(DATTIT);
		if (extractBoolUclc(docctx, basexpath, "eqz", "", eqz)) add(EQZ);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDomain", "", refPlnrMDomain)) add(REFPLNRMDOMAIN);
		if (extractBoolUclc(docctx, basexpath, "showfces", "", showfces)) add(SHOWFCES);
		if (extractBoolUclc(docctx, basexpath, "showlvls", "", showlvls)) add(SHOWLVLS);
		if (extractBoolUclc(docctx, basexpath, "showvtxs", "", showvtxs)) add(SHOWVTXS);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
	};
};

void DpchInvPlnrPlotDomzcssvg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDomzcssvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeString(wr, "datPngpath", datPngpath);
		writeString(wr, "datTit", datTit);
		writeBool(wr, "eqz", eqz);
		writeUint(wr, "height", height);
		writeUbigint(wr, "refPlnrMDomain", refPlnrMDomain);
		writeBool(wr, "showfces", showfces);
		writeBool(wr, "showlvls", showlvls);
		writeBool(wr, "showvtxs", showvtxs);
		writeUint(wr, "width", width);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDomzcssvg
 ******************************************************************************/

DpchRetPlnrPlotDomzcssvg::DpchRetPlnrPlotDomzcssvg(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& svgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDOMZCSSVG, scrOref, scrJref) {
	this->success = success;
	this->svgfile = svgfile;
};

void DpchRetPlnrPlotDomzcssvg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDomzcssvg");
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
		if (extractStringUclc(docctx, basexpath, "svgfile", "", svgfile)) add(SVGFILE);
	};
};

void DpchRetPlnrPlotDomzcssvg::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDomzcssvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "svgfile", svgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDsnxysvg
 ******************************************************************************/

DpchInvPlnrPlotDsnxysvg::DpchInvPlnrPlotDsnxysvg(
			const ubigint oref
			, const ubigint jref
			, const string& datPngpath
			, const string& datSrefDom
			, const string& datTit
			, const uint height
			, const ubigint refPlnrMDesign
			, const vector<ubigint>& refsLyr
			, const bool showdoms
			, const bool showfces
			, const bool showgds
			, const bool showvtxs
			, const bool spclyrs
			, const uint width
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDSNXYSVG, oref, jref) {
	this->datPngpath = datPngpath;
	this->datSrefDom = datSrefDom;
	this->datTit = datTit;
	this->height = height;
	this->refPlnrMDesign = refPlnrMDesign;
	this->refsLyr = refsLyr;
	this->showdoms = showdoms;
	this->showfces = showfces;
	this->showgds = showgds;
	this->showvtxs = showvtxs;
	this->spclyrs = spclyrs;
	this->width = width;
};

void DpchInvPlnrPlotDsnxysvg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDsnxysvg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractStringUclc(docctx, basexpath, "datPngpath", "", datPngpath)) add(DATPNGPATH);
		if (extractStringUclc(docctx, basexpath, "datSrefDom", "", datSrefDom)) add(DATSREFDOM);
		if (extractStringUclc(docctx, basexpath, "datTit", "", datTit)) add(DATTIT);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
		if (extractUbigintvecUclc(docctx, basexpath, "refsLyr", "", refsLyr)) add(REFSLYR);
		if (extractBoolUclc(docctx, basexpath, "showdoms", "", showdoms)) add(SHOWDOMS);
		if (extractBoolUclc(docctx, basexpath, "showfces", "", showfces)) add(SHOWFCES);
		if (extractBoolUclc(docctx, basexpath, "showgds", "", showgds)) add(SHOWGDS);
		if (extractBoolUclc(docctx, basexpath, "showvtxs", "", showvtxs)) add(SHOWVTXS);
		if (extractBoolUclc(docctx, basexpath, "spclyrs", "", spclyrs)) add(SPCLYRS);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
	};
};

void DpchInvPlnrPlotDsnxysvg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDsnxysvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeString(wr, "datPngpath", datPngpath);
		writeString(wr, "datSrefDom", datSrefDom);
		writeString(wr, "datTit", datTit);
		writeUint(wr, "height", height);
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
		writeUbigintvec(wr, "refsLyr", refsLyr);
		writeBool(wr, "showdoms", showdoms);
		writeBool(wr, "showfces", showfces);
		writeBool(wr, "showgds", showgds);
		writeBool(wr, "showvtxs", showvtxs);
		writeBool(wr, "spclyrs", spclyrs);
		writeUint(wr, "width", width);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDsnxysvg
 ******************************************************************************/

DpchRetPlnrPlotDsnxysvg::DpchRetPlnrPlotDsnxysvg(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& svgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDSNXYSVG, scrOref, scrJref) {
	this->success = success;
	this->svgfile = svgfile;
};

void DpchRetPlnrPlotDsnxysvg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDsnxysvg");
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
		if (extractStringUclc(docctx, basexpath, "svgfile", "", svgfile)) add(SVGFILE);
	};
};

void DpchRetPlnrPlotDsnxysvg::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDsnxysvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "svgfile", svgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotDsnzsvg
 ******************************************************************************/

DpchInvPlnrPlotDsnzsvg::DpchInvPlnrPlotDsnzsvg(
			const ubigint oref
			, const ubigint jref
			, const bool eqz
			, const uint height
			, const ubigint refPlnrMDesign
			, const bool showdoms
			, const uint width
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTDSNZSVG, oref, jref) {
	this->eqz = eqz;
	this->height = height;
	this->refPlnrMDesign = refPlnrMDesign;
	this->showdoms = showdoms;
	this->width = width;
};

void DpchInvPlnrPlotDsnzsvg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotDsnzsvg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "eqz", "", eqz)) add(EQZ);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMDesign", "", refPlnrMDesign)) add(REFPLNRMDESIGN);
		if (extractBoolUclc(docctx, basexpath, "showdoms", "", showdoms)) add(SHOWDOMS);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
	};
};

void DpchInvPlnrPlotDsnzsvg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotDsnzsvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "eqz", eqz);
		writeUint(wr, "height", height);
		writeUbigint(wr, "refPlnrMDesign", refPlnrMDesign);
		writeBool(wr, "showdoms", showdoms);
		writeUint(wr, "width", width);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotDsnzsvg
 ******************************************************************************/

DpchRetPlnrPlotDsnzsvg::DpchRetPlnrPlotDsnzsvg(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& svgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTDSNZSVG, scrOref, scrJref) {
	this->success = success;
	this->svgfile = svgfile;
};

void DpchRetPlnrPlotDsnzsvg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotDsnzsvg");
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
		if (extractStringUclc(docctx, basexpath, "svgfile", "", svgfile)) add(SVGFILE);
	};
};

void DpchRetPlnrPlotDsnzsvg::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotDsnzsvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "svgfile", svgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotStksvg
 ******************************************************************************/

DpchInvPlnrPlotStksvg::DpchInvPlnrPlotStksvg(
			const ubigint oref
			, const ubigint jref
			, const bool eqz
			, const uint height
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMStack
			, const uint width
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTSTKSVG, oref, jref) {
	this->eqz = eqz;
	this->height = height;
	this->refBasedsn = refBasedsn;
	this->refModdsn = refModdsn;
	this->refPlnrMStack = refPlnrMStack;
	this->width = width;
};

void DpchInvPlnrPlotStksvg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotStksvg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "eqz", "", eqz)) add(EQZ);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractUbigintUclc(docctx, basexpath, "refBasedsn", "", refBasedsn)) add(REFBASEDSN);
		if (extractUbigintUclc(docctx, basexpath, "refModdsn", "", refModdsn)) add(REFMODDSN);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMStack", "", refPlnrMStack)) add(REFPLNRMSTACK);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
	};
};

void DpchInvPlnrPlotStksvg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotStksvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "eqz", eqz);
		writeUint(wr, "height", height);
		writeUbigint(wr, "refBasedsn", refBasedsn);
		writeUbigint(wr, "refModdsn", refModdsn);
		writeUbigint(wr, "refPlnrMStack", refPlnrMStack);
		writeUint(wr, "width", width);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotStksvg
 ******************************************************************************/

DpchRetPlnrPlotStksvg::DpchRetPlnrPlotStksvg(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& svgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTSTKSVG, scrOref, scrJref) {
	this->success = success;
	this->svgfile = svgfile;
};

void DpchRetPlnrPlotStksvg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotStksvg");
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
		if (extractStringUclc(docctx, basexpath, "svgfile", "", svgfile)) add(SVGFILE);
	};
};

void DpchRetPlnrPlotStksvg::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotStksvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "svgfile", svgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotTposvg
 ******************************************************************************/

DpchInvPlnrPlotTposvg::DpchInvPlnrPlotTposvg(
			const ubigint oref
			, const ubigint jref
			, const uint height
			, const ubigint refPlnrMTapeout
			, const uint width
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTTPOSVG, oref, jref) {
	this->height = height;
	this->refPlnrMTapeout = refPlnrMTapeout;
	this->width = width;
};

void DpchInvPlnrPlotTposvg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotTposvg");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractUintUclc(docctx, basexpath, "height", "", height)) add(HEIGHT);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMTapeout", "", refPlnrMTapeout)) add(REFPLNRMTAPEOUT);
		if (extractUintUclc(docctx, basexpath, "width", "", width)) add(WIDTH);
	};
};

void DpchInvPlnrPlotTposvg::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotTposvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeUint(wr, "height", height);
		writeUbigint(wr, "refPlnrMTapeout", refPlnrMTapeout);
		writeUint(wr, "width", width);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotTposvg
 ******************************************************************************/

DpchRetPlnrPlotTposvg::DpchRetPlnrPlotTposvg(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& svgfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTTPOSVG, scrOref, scrJref) {
	this->success = success;
	this->svgfile = svgfile;
};

void DpchRetPlnrPlotTposvg::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotTposvg");
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
		if (extractStringUclc(docctx, basexpath, "svgfile", "", svgfile)) add(SVGFILE);
	};
};

void DpchRetPlnrPlotTposvg::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotTposvg");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "svgfile", svgfile);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchInvPlnrPlotTpotxt
 ******************************************************************************/

DpchInvPlnrPlotTpotxt::DpchInvPlnrPlotTpotxt(
			const ubigint oref
			, const ubigint jref
			, const bool fmtcif
			, const bool fmtraith
			, const double rast
			, const ubigint refPlnrMTapeout
		) : DpchInvPlnr(VecPlnrVDpch::DPCHINVPLNRPLOTTPOTXT, oref, jref) {
	this->fmtcif = fmtcif;
	this->fmtraith = fmtraith;
	this->rast = rast;
	this->refPlnrMTapeout = refPlnrMTapeout;
};

void DpchInvPlnrPlotTpotxt::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnrPlotTpotxt");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (extractBoolUclc(docctx, basexpath, "fmtcif", "", fmtcif)) add(FMTCIF);
		if (extractBoolUclc(docctx, basexpath, "fmtraith", "", fmtraith)) add(FMTRAITH);
		if (extractDoubleUclc(docctx, basexpath, "rast", "", rast)) add(RAST);
		if (extractUbigintUclc(docctx, basexpath, "refPlnrMTapeout", "", refPlnrMTapeout)) add(REFPLNRMTAPEOUT);
	};
};

void DpchInvPlnrPlotTpotxt::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchInvPlnrPlotTpotxt");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
		writeBool(wr, "fmtcif", fmtcif);
		writeBool(wr, "fmtraith", fmtraith);
		writeDouble(wr, "rast", rast);
		writeUbigint(wr, "refPlnrMTapeout", refPlnrMTapeout);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnrPlotTpotxt
 ******************************************************************************/

DpchRetPlnrPlotTpotxt::DpchRetPlnrPlotTpotxt(
			const string& scrOref
			, const string& scrJref
			, const bool success
			, const string& ascfile
			, const string& ciffile
			, const string& tgzfile
		) : DpchRetPlnr(VecPlnrVDpch::DPCHRETPLNRPLOTTPOTXT, scrOref, scrJref) {
	this->success = success;
	this->ascfile = ascfile;
	this->ciffile = ciffile;
	this->tgzfile = tgzfile;
};

void DpchRetPlnrPlotTpotxt::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnrPlotTpotxt");
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
		if (extractStringUclc(docctx, basexpath, "ascfile", "", ascfile)) add(ASCFILE);
		if (extractStringUclc(docctx, basexpath, "ciffile", "", ciffile)) add(CIFFILE);
		if (extractStringUclc(docctx, basexpath, "tgzfile", "", tgzfile)) add(TGZFILE);
	};
};

void DpchRetPlnrPlotTpotxt::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnrPlotTpotxt");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeBool(wr, "success", success);
		writeString(wr, "ascfile", ascfile);
		writeString(wr, "ciffile", ciffile);
		writeString(wr, "tgzfile", tgzfile);
	xmlTextWriterEndElement(wr);
};

// IP cust --- INSERT


