/**
  * \file PlnrWgmode_blks.h
  * invocation / return data blocks for operation pack PlnrWgmode (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRWGMODE_BLKS_H
#define PLNRWGMODE_BLKS_H

#include "Plnr.h"

/**
	* DpchInvPlnrWgmodeFd1d
	*/
class DpchInvPlnrWgmodeFd1d : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint LOSSMAT = 3;
	static const uint PREFIX = 4;
	static const uint REFPLNRMCALC = 5;
	static const uint REFPLNRMCALCITEM = 6;
	static const uint REFRASTFILE = 7;
	static const uint SREFDOM = 8;
	static const uint SREFSDOMEVAL = 9;
	static const uint TE = 10;
	static const uint TM = 11;

public:
	DpchInvPlnrWgmodeFd1d(const ubigint oref = 0, const ubigint jref = 0, const bool lossmat = false, const string& prefix = "", const ubigint refPlnrMCalc = 0, const ubigint refPlnrMCalcitem = 0, const ubigint refRastfile = 0, const string& srefDom = "", const vector<string>& srefsDomEval = {}, const bool te = false, const bool tm = false);

public:
	bool lossmat;
	string prefix;
	ubigint refPlnrMCalc;
	ubigint refPlnrMCalcitem;
	ubigint refRastfile;
	string srefDom;
	vector<string> srefsDomEval;
	bool te;
	bool tm;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrWgmodeFd1d
	*/
class DpchRetPlnrWgmodeFd1d : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint TEN = 4;
	static const uint TMN = 5;

public:
	DpchRetPlnrWgmodeFd1d(const string& scrOref = "", const string& scrJref = "", const bool success = false, const uint teN = 0, const uint tmN = 0);

public:
	bool success;
	uint teN;
	uint tmN;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrWgmodeFd2d
	*/
class DpchInvPlnrWgmodeFd2d : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint LOSSMAT = 3;
	static const uint PREFIX = 4;
	static const uint REFPLNRMCALC = 5;
	static const uint REFPLNRMCALCITEM = 6;
	static const uint REFRASTFILE = 7;
	static const uint SREFDOM = 8;
	static const uint SREFSDOMEVAL = 9;
	static const uint TE = 10;
	static const uint TM = 11;

public:
	DpchInvPlnrWgmodeFd2d(const ubigint oref = 0, const ubigint jref = 0, const bool lossmat = false, const string& prefix = "", const ubigint refPlnrMCalc = 0, const ubigint refPlnrMCalcitem = 0, const ubigint refRastfile = 0, const string& srefDom = "", const vector<string>& srefsDomEval = {}, const bool te = false, const bool tm = false);

public:
	bool lossmat;
	string prefix;
	ubigint refPlnrMCalc;
	ubigint refPlnrMCalcitem;
	ubigint refRastfile;
	string srefDom;
	vector<string> srefsDomEval;
	bool te;
	bool tm;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrWgmodeFd2d
	*/
class DpchRetPlnrWgmodeFd2d : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint TEN = 4;
	static const uint TMN = 5;

public:
	DpchRetPlnrWgmodeFd2d(const string& scrOref = "", const string& scrJref = "", const bool success = false, const uint teN = 0, const uint tmN = 0);

public:
	bool success;
	uint teN;
	uint tmN;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrWgmodeFem1d
	*/
class DpchInvPlnrWgmodeFem1d : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMCALC = 3;
	static const uint REFPLNRMCALCITEM = 4;

public:
	DpchInvPlnrWgmodeFem1d(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMCalcitem = 0);

public:
	ubigint refPlnrMCalc;
	ubigint refPlnrMCalcitem;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrWgmodeFem2d
	*/
class DpchInvPlnrWgmodeFem2d : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMCALC = 3;
	static const uint REFPLNRMCALCITEM = 4;

public:
	DpchInvPlnrWgmodeFem2d(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMCalcitem = 0);

public:
	ubigint refPlnrMCalc;
	ubigint refPlnrMCalcitem;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif


