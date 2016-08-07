/**
  * \file PlnrMeep_blks.h
  * invocation / return data blocks for operation pack PlnrMeep (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMEEP_BLKS_H
#define PLNRMEEP_BLKS_H

#include "Plnr.h"

/**
	* DpchInvPlnrMeepTrf2d
	*/
class DpchInvPlnrMeepTrf2d : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint ANISOMAT = 3;
	static const uint DELTALAM = 4;
	static const uint DT = 5;
	static const uint LOSSMAT = 6;
	static const uint PREFIX = 7;
	static const uint REFPLNRMCALC = 8;
	static const uint REFPLNRMCALCITEM = 9;
	static const uint REFRASTFILE = 10;
	static const uint SREFDOM = 11;
	static const uint SREFDOMEXC = 12;
	static const uint SREFSDOMMON = 13;
	static const uint SREFSDOMSSHOT = 14;
	static const uint TM = 15;
	static const uint TSTOP = 16;

public:
	DpchInvPlnrMeepTrf2d(const ubigint oref = 0, const ubigint jref = 0, const bool anisomat = false, const double deltalam = 0.0, const double dt = 0.0, const bool lossmat = false, const string& prefix = "", const ubigint refPlnrMCalc = 0, const ubigint refPlnrMCalcitem = 0, const ubigint refRastfile = 0, const string& srefDom = "", const string& srefDomExc = "", const vector<string>& srefsDomMon = {}, const vector<string>& srefsDomSshot = {}, const bool tm = false, const double tstop = 0.0);

public:
	bool anisomat;
	double deltalam;
	double dt;
	bool lossmat;
	string prefix;
	ubigint refPlnrMCalc;
	ubigint refPlnrMCalcitem;
	ubigint refRastfile;
	string srefDom;
	string srefDomExc;
	vector<string> srefsDomMon;
	vector<string> srefsDomSshot;
	bool tm;
	double tstop;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrMeepTrf3d
	*/
class DpchInvPlnrMeepTrf3d : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMCALC = 3;
	static const uint REFPLNRMCALCITEM = 4;

public:
	DpchInvPlnrMeepTrf3d(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMCalcitem = 0);

public:
	ubigint refPlnrMCalc;
	ubigint refPlnrMCalcitem;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif


