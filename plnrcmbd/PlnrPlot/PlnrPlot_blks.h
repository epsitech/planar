/**
  * \file PlnrPlot_blks.h
  * invocation / return data blocks for operation pack PlnrPlot (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOT_BLKS_H
#define PLNRPLOT_BLKS_H

#include "Plnr.h"

/**
	* DpchInvPlnrPlotDat1dgnu
	*/
class DpchInvPlnrPlotDat1dgnu : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALTTITLE = 3;
	static const uint ALTXTITLE = 4;
	static const uint ALTYTITLE = 5;
	static const uint REFFILE = 6;
	static const uint XPATH = 7;
	static const uint XVAR = 8;
	static const uint YPATH = 9;
	static const uint YSLCDIMS = 10;
	static const uint YSLCICS = 11;
	static const uint YVAR = 12;

public:
	DpchInvPlnrPlotDat1dgnu(const ubigint oref = 0, const ubigint jref = 0, const string& alttitle = "", const string& altxtitle = "", const string& altytitle = "", const ubigint refFile = 0, const string& xpath = "", const string& xvar = "", const string& ypath = "", const vector<string>& yslcDims = {}, const vector<int>& yslcIcs = {}, const string& yvar = "");

public:
	string alttitle;
	string altxtitle;
	string altytitle;
	ubigint refFile;
	string xpath;
	string xvar;
	string ypath;
	vector<string> yslcDims;
	vector<int> yslcIcs;
	string yvar;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDat1dgnu
	*/
class DpchRetPlnrPlotDat1dgnu : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint TGZFILE = 4;

public:
	DpchRetPlnrPlotDat1dgnu(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& tgzfile = "");

public:
	bool success;
	string tgzfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDat1dgnumult
	*/
class DpchInvPlnrPlotDat1dgnumult : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFSFILE = 3;
	static const uint TITLE = 4;
	static const uint XPATHS = 5;
	static const uint XTITLE = 6;
	static const uint XVARS = 7;
	static const uint YPATHS = 8;
	static const uint YTITLE = 9;
	static const uint YVARS = 10;

public:
	DpchInvPlnrPlotDat1dgnumult(const ubigint oref = 0, const ubigint jref = 0, const vector<ubigint>& refsFile = {}, const string& title = "", const vector<string>& xpaths = {}, const string& xtitle = "", const vector<string>& xvars = {}, const vector<string>& ypaths = {}, const string& ytitle = "", const vector<string>& yvars = {});

public:
	vector<ubigint> refsFile;
	string title;
	vector<string> xpaths;
	string xtitle;
	vector<string> xvars;
	vector<string> ypaths;
	string ytitle;
	vector<string> yvars;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDat1dgnumult
	*/
class DpchRetPlnrPlotDat1dgnumult : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint TGZFILE = 4;

public:
	DpchRetPlnrPlotDat1dgnumult(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& tgzfile = "");

public:
	bool success;
	string tgzfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDevsvg
	*/
class DpchInvPlnrPlotDevsvg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint HEIGHT = 3;
	static const uint REFBASEDSN = 4;
	static const uint REFMODDSN = 5;
	static const uint REFPLNRMDEVICE = 6;
	static const uint REFSSRU = 7;
	static const uint REFSSUBDEV = 8;
	static const uint SHOWFCES = 9;
	static const uint SHOWGDS = 10;
	static const uint SHOWVTXS = 11;
	static const uint WIDTH = 12;

public:
	DpchInvPlnrPlotDevsvg(const ubigint oref = 0, const ubigint jref = 0, const uint height = 0, const ubigint refBasedsn = 0, const ubigint refModdsn = 0, const ubigint refPlnrMDevice = 0, const vector<ubigint>& refsSru = {}, const vector<ubigint>& refsSubdev = {}, const bool showfces = false, const bool showgds = false, const bool showvtxs = false, const uint width = 0);

public:
	uint height;
	ubigint refBasedsn;
	ubigint refModdsn;
	ubigint refPlnrMDevice;
	vector<ubigint> refsSru;
	vector<ubigint> refsSubdev;
	bool showfces;
	bool showgds;
	bool showvtxs;
	uint width;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDevsvg
	*/
class DpchRetPlnrPlotDevsvg : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint SVGFILE = 4;

public:
	DpchRetPlnrPlotDevsvg(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& svgfile = "");

public:
	bool success;
	string svgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDomdat1dgnu
	*/
class DpchInvPlnrPlotDomdat1dgnu : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALTTITLE = 3;
	static const uint ALTYTITLE = 4;
	static const uint REFFILE = 5;
	static const uint SREFDOM = 6;
	static const uint XDIM = 7;
	static const uint YSLCDIMS = 8;
	static const uint YSLCICS = 9;
	static const uint YVAR = 10;

public:
	DpchInvPlnrPlotDomdat1dgnu(const ubigint oref = 0, const ubigint jref = 0, const string& alttitle = "", const string& altytitle = "", const ubigint refFile = 0, const string& srefDom = "", const string& xdim = "", const vector<string>& yslcDims = {}, const vector<int>& yslcIcs = {}, const string& yvar = "");

public:
	string alttitle;
	string altytitle;
	ubigint refFile;
	string srefDom;
	string xdim;
	vector<string> yslcDims;
	vector<int> yslcIcs;
	string yvar;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDomdat1dgnu
	*/
class DpchRetPlnrPlotDomdat1dgnu : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint TGZFILE = 4;

public:
	DpchRetPlnrPlotDomdat1dgnu(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& tgzfile = "");

public:
	bool success;
	string tgzfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDomdat2dgnu
	*/
class DpchInvPlnrPlotDomdat2dgnu : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALTTITLE = 3;
	static const uint REFFILE = 4;
	static const uint SPCZLIM = 5;
	static const uint SREFDOM = 6;
	static const uint XDIM = 7;
	static const uint YDIM = 8;
	static const uint ZMAX = 9;
	static const uint ZMIN = 10;
	static const uint ZSLCDIMS = 11;
	static const uint ZSLCICS = 12;
	static const uint ZVAR = 13;

public:
	DpchInvPlnrPlotDomdat2dgnu(const ubigint oref = 0, const ubigint jref = 0, const string& alttitle = "", const ubigint refFile = 0, const bool spczlim = false, const string& srefDom = "", const string& xdim = "", const string& ydim = "", const double zmax = 0.0, const double zmin = 0.0, const vector<string>& zslcDims = {}, const vector<int>& zslcIcs = {}, const string& zvar = "");

public:
	string alttitle;
	ubigint refFile;
	bool spczlim;
	string srefDom;
	string xdim;
	string ydim;
	double zmax;
	double zmin;
	vector<string> zslcDims;
	vector<int> zslcIcs;
	string zvar;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDomdat2dgnu
	*/
class DpchRetPlnrPlotDomdat2dgnu : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint TGZFILE = 4;

public:
	DpchRetPlnrPlotDomdat2dgnu(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& tgzfile = "");

public:
	bool success;
	string tgzfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDomdat2dpng
	*/
class DpchInvPlnrPlotDomdat2dpng : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALTZMAX = 3;
	static const uint ALTZMIN = 4;
	static const uint ANNOTCOLOR = 5;
	static const uint ANNOTDIM = 6;
	static const uint ANNOTHEIGHT = 7;
	static const uint ANNOTPOS = 8;
	static const uint ANNOTTEXT = 9;
	static const uint CTRZERO = 10;
	static const uint LOGSCALE = 11;
	static const uint REFFILE = 12;
	static const uint SPCZLIM = 13;
	static const uint SREFDOM = 14;
	static const uint XDIM = 15;
	static const uint YDIM = 16;
	static const uint ZSLCDIMS = 17;
	static const uint ZSLCICS = 18;
	static const uint ZVAR = 19;

public:
	DpchInvPlnrPlotDomdat2dpng(const ubigint oref = 0, const ubigint jref = 0, const double altzmax = 0.0, const double altzmin = 0.0, const string& annotColor = "", const string& annotDim = "", const uint annotHeight = 0, const string& annotPos = "", const string& annotText = "", const bool ctrzero = false, const bool logscale = false, const ubigint refFile = 0, const bool spczlim = false, const string& srefDom = "", const string& xdim = "", const string& ydim = "", const vector<string>& zslcDims = {}, const vector<int>& zslcIcs = {}, const string& zvar = "");

public:
	double altzmax;
	double altzmin;
	string annotColor;
	string annotDim;
	uint annotHeight;
	string annotPos;
	string annotText;
	bool ctrzero;
	bool logscale;
	ubigint refFile;
	bool spczlim;
	string srefDom;
	string xdim;
	string ydim;
	vector<string> zslcDims;
	vector<int> zslcIcs;
	string zvar;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDomdat2dpng
	*/
class DpchRetPlnrPlotDomdat2dpng : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint PNGFILE = 4;

public:
	DpchRetPlnrPlotDomdat2dpng(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& pngfile = "");

public:
	bool success;
	string pngfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDomdat2dvid
	*/
class DpchInvPlnrPlotDomdat2dvid : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ALTZMAX = 3;
	static const uint ALTZMIN = 4;
	static const uint ANNOTCOLOR = 5;
	static const uint ANNOTHEIGHT = 6;
	static const uint CTRZERO = 7;
	static const uint FRMRATE = 8;
	static const uint LOGSCALE = 9;
	static const uint REFFILE = 10;
	static const uint SPCZLIM = 11;
	static const uint SREFDOM = 12;
	static const uint TDIM = 13;
	static const uint XDIM = 14;
	static const uint YDIM = 15;
	static const uint ZSLCDIMS = 16;
	static const uint ZSLCICS = 17;
	static const uint ZVAR = 18;

public:
	DpchInvPlnrPlotDomdat2dvid(const ubigint oref = 0, const ubigint jref = 0, const double altzmax = 0.0, const double altzmin = 0.0, const string& annotColor = "", const uint annotHeight = 0, const bool ctrzero = false, const uint frmrate = 0, const bool logscale = false, const ubigint refFile = 0, const bool spczlim = false, const string& srefDom = "", const string& tdim = "", const string& xdim = "", const string& ydim = "", const vector<string>& zslcDims = {}, const vector<int>& zslcIcs = {}, const string& zvar = "");

public:
	double altzmax;
	double altzmin;
	string annotColor;
	uint annotHeight;
	bool ctrzero;
	uint frmrate;
	bool logscale;
	ubigint refFile;
	bool spczlim;
	string srefDom;
	string tdim;
	string xdim;
	string ydim;
	vector<string> zslcDims;
	vector<int> zslcIcs;
	string zvar;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDomdat2dvid
	*/
class DpchRetPlnrPlotDomdat2dvid : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint MPGFILE = 4;

public:
	DpchRetPlnrPlotDomdat2dvid(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& mpgfile = "");

public:
	bool success;
	string mpgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDomzcssvg
	*/
class DpchInvPlnrPlotDomzcssvg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint DATPNGPATH = 3;
	static const uint DATTIT = 4;
	static const uint EQZ = 5;
	static const uint HEIGHT = 6;
	static const uint REFPLNRMDOMAIN = 7;
	static const uint SHOWFCES = 8;
	static const uint SHOWLVLS = 9;
	static const uint SHOWVTXS = 10;
	static const uint WIDTH = 11;

public:
	DpchInvPlnrPlotDomzcssvg(const ubigint oref = 0, const ubigint jref = 0, const string& datPngpath = "", const string& datTit = "", const bool eqz = false, const uint height = 0, const ubigint refPlnrMDomain = 0, const bool showfces = false, const bool showlvls = false, const bool showvtxs = false, const uint width = 0);

public:
	string datPngpath;
	string datTit;
	bool eqz;
	uint height;
	ubigint refPlnrMDomain;
	bool showfces;
	bool showlvls;
	bool showvtxs;
	uint width;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDomzcssvg
	*/
class DpchRetPlnrPlotDomzcssvg : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint SVGFILE = 4;

public:
	DpchRetPlnrPlotDomzcssvg(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& svgfile = "");

public:
	bool success;
	string svgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDsnxysvg
	*/
class DpchInvPlnrPlotDsnxysvg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint DATPNGPATH = 3;
	static const uint DATSREFDOM = 4;
	static const uint DATTIT = 5;
	static const uint HEIGHT = 6;
	static const uint REFPLNRMDESIGN = 7;
	static const uint REFSLYR = 8;
	static const uint SHOWDOMS = 9;
	static const uint SHOWFCES = 10;
	static const uint SHOWGDS = 11;
	static const uint SHOWVTXS = 12;
	static const uint SPCLYRS = 13;
	static const uint WIDTH = 14;

public:
	DpchInvPlnrPlotDsnxysvg(const ubigint oref = 0, const ubigint jref = 0, const string& datPngpath = "", const string& datSrefDom = "", const string& datTit = "", const uint height = 0, const ubigint refPlnrMDesign = 0, const vector<ubigint>& refsLyr = {}, const bool showdoms = false, const bool showfces = false, const bool showgds = false, const bool showvtxs = false, const bool spclyrs = false, const uint width = 0);

public:
	string datPngpath;
	string datSrefDom;
	string datTit;
	uint height;
	ubigint refPlnrMDesign;
	vector<ubigint> refsLyr;
	bool showdoms;
	bool showfces;
	bool showgds;
	bool showvtxs;
	bool spclyrs;
	uint width;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDsnxysvg
	*/
class DpchRetPlnrPlotDsnxysvg : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint SVGFILE = 4;

public:
	DpchRetPlnrPlotDsnxysvg(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& svgfile = "");

public:
	bool success;
	string svgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotDsnzsvg
	*/
class DpchInvPlnrPlotDsnzsvg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint EQZ = 3;
	static const uint HEIGHT = 4;
	static const uint REFPLNRMDESIGN = 5;
	static const uint SHOWDOMS = 6;
	static const uint WIDTH = 7;

public:
	DpchInvPlnrPlotDsnzsvg(const ubigint oref = 0, const ubigint jref = 0, const bool eqz = false, const uint height = 0, const ubigint refPlnrMDesign = 0, const bool showdoms = false, const uint width = 0);

public:
	bool eqz;
	uint height;
	ubigint refPlnrMDesign;
	bool showdoms;
	uint width;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotDsnzsvg
	*/
class DpchRetPlnrPlotDsnzsvg : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint SVGFILE = 4;

public:
	DpchRetPlnrPlotDsnzsvg(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& svgfile = "");

public:
	bool success;
	string svgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotStksvg
	*/
class DpchInvPlnrPlotStksvg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint EQZ = 3;
	static const uint HEIGHT = 4;
	static const uint REFBASEDSN = 5;
	static const uint REFMODDSN = 6;
	static const uint REFPLNRMSTACK = 7;
	static const uint WIDTH = 8;

public:
	DpchInvPlnrPlotStksvg(const ubigint oref = 0, const ubigint jref = 0, const bool eqz = false, const uint height = 0, const ubigint refBasedsn = 0, const ubigint refModdsn = 0, const ubigint refPlnrMStack = 0, const uint width = 0);

public:
	bool eqz;
	uint height;
	ubigint refBasedsn;
	ubigint refModdsn;
	ubigint refPlnrMStack;
	uint width;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotStksvg
	*/
class DpchRetPlnrPlotStksvg : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint SVGFILE = 4;

public:
	DpchRetPlnrPlotStksvg(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& svgfile = "");

public:
	bool success;
	string svgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotTposvg
	*/
class DpchInvPlnrPlotTposvg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint HEIGHT = 3;
	static const uint REFPLNRMTAPEOUT = 4;
	static const uint WIDTH = 5;

public:
	DpchInvPlnrPlotTposvg(const ubigint oref = 0, const ubigint jref = 0, const uint height = 0, const ubigint refPlnrMTapeout = 0, const uint width = 0);

public:
	uint height;
	ubigint refPlnrMTapeout;
	uint width;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotTposvg
	*/
class DpchRetPlnrPlotTposvg : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint SVGFILE = 4;

public:
	DpchRetPlnrPlotTposvg(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& svgfile = "");

public:
	bool success;
	string svgfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrPlotTpotxt
	*/
class DpchInvPlnrPlotTpotxt : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint FMTCIF = 3;
	static const uint FMTRAITH = 4;
	static const uint RAST = 5;
	static const uint REFPLNRMTAPEOUT = 6;

public:
	DpchInvPlnrPlotTpotxt(const ubigint oref = 0, const ubigint jref = 0, const bool fmtcif = false, const bool fmtraith = false, const double rast = 0.0, const ubigint refPlnrMTapeout = 0);

public:
	bool fmtcif;
	bool fmtraith;
	double rast;
	ubigint refPlnrMTapeout;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrPlotTpotxt
	*/
class DpchRetPlnrPlotTpotxt : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint ASCFILE = 4;
	static const uint CIFFILE = 5;
	static const uint TGZFILE = 6;

public:
	DpchRetPlnrPlotTpotxt(const string& scrOref = "", const string& scrJref = "", const bool success = false, const string& ascfile = "", const string& ciffile = "", const string& tgzfile = "");

public:
	bool success;
	string ascfile;
	string ciffile;
	string tgzfile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif


