/**
  * \file AppPlnr_blks.h
  * Plnr app access library global functionality (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef APPPLNR_BLKS_H
#define APPPLNR_BLKS_H

#include "VecPlnrVDpch.h"
#include "VecPlnrVExpstate.h"
#include "VecPlnrVQrystate.h"
#include "VecPlnrVReqitmode.h"

/**
	* ContInfPlnrAlert
	*/
class ContInfPlnrAlert : public Block {

public:
	static const uint TXTCPT = 1;
	static const uint TXTMSG1 = 2;
	static const uint TXTMSG2 = 3;
	static const uint TXTMSG3 = 4;
	static const uint TXTMSG4 = 5;
	static const uint TXTMSG5 = 6;
	static const uint TXTMSG6 = 7;
	static const uint TXTMSG7 = 8;
	static const uint TXTMSG8 = 9;
	static const uint TXTMSG9 = 10;
	static const uint TXTMSG10 = 11;

public:
	ContInfPlnrAlert(const string& TxtCpt = "", const string& TxtMsg1 = "", const string& TxtMsg2 = "", const string& TxtMsg3 = "", const string& TxtMsg4 = "", const string& TxtMsg5 = "", const string& TxtMsg6 = "", const string& TxtMsg7 = "", const string& TxtMsg8 = "", const string& TxtMsg9 = "", const string& TxtMsg10 = "");

public:
	string TxtCpt;
	string TxtMsg1;
	string TxtMsg2;
	string TxtMsg3;
	string TxtMsg4;
	string TxtMsg5;
	string TxtMsg6;
	string TxtMsg7;
	string TxtMsg8;
	string TxtMsg9;
	string TxtMsg10;

public:
	static bool all(const set<uint>& items);
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	set<uint> compare(const ContInfPlnrAlert* comp);
};

/**
	* DpchPlnr
	*/
class DpchPlnr : public Block {

public:
	DpchPlnr(const uint ixPlnrVDpch = 0);
	virtual ~DpchPlnr();

public:
	uint ixPlnrVDpch;
};

/**
	* DpchAppPlnr
	*/
class DpchAppPlnr : public DpchPlnr {

public:
	static const uint SCRJREF = 1;

public:
	DpchAppPlnr(const uint ixPlnrVDpch = 0, const string& scrJref = "");
	virtual ~DpchAppPlnr();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppPlnrAlert
	*/
class DpchAppPlnrAlert : public DpchAppPlnr {

public:
	static const uint SCRJREF = 1;
	static const uint NUMFMCB = 2;
	static const uint ALL = 3;

public:
	DpchAppPlnrAlert(const string& scrJref = "", const uint numFMcb = 0, const set<uint>& mask = {NONE});

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchAppPlnrInit
	*/
class DpchAppPlnrInit : public DpchAppPlnr {

public:
	DpchAppPlnrInit(const string& scrJref = "");
};

/**
	* DpchAppPlnrResume
	*/
class DpchAppPlnrResume : public DpchAppPlnr {

public:
	DpchAppPlnrResume(const string& scrJref = "");
};

/**
	* DpchEngPlnr
	*/
class DpchEngPlnr : public DpchPlnr {

public:
	static const uint SCRJREF = 1;

public:
	DpchEngPlnr(const uint ixPlnrVDpch = 0);
	virtual ~DpchEngPlnr();

public:
	string scrJref;

public:
	static bool all(const set<uint>& items);
	virtual void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngPlnrAck
	*/
class DpchEngPlnrAck : public DpchEngPlnr {

public:
	DpchEngPlnrAck();
};

/**
	* DpchEngPlnrAlert
	*/
class DpchEngPlnrAlert : public DpchEngPlnr {

public:
	static const uint SCRJREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;

public:
	DpchEngPlnrAlert();

public:
	ContInfPlnrAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngPlnrConfirm
	*/
class DpchEngPlnrConfirm : public DpchEngPlnr {

public:
	static const uint ACCEPTED = 1;
	static const uint SCRJREF = 2;
	static const uint SREF = 3;

public:
	DpchEngPlnrConfirm();

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchEngPlnrSuspend
	*/
class DpchEngPlnrSuspend : public DpchEngPlnr {

public:
	DpchEngPlnrSuspend();
};

#endif

