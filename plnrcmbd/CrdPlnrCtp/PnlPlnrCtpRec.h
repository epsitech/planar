/**
  * \file PnlPlnrCtpRec.h
  * job handler for job PnlPlnrCtpRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRCTPREC_H
#define PNLPLNRCTPREC_H

// IP custInclude --- INSERT

#include "PnlPlnrCtpDetail.h"
#include "PnlPlnrCtpKEnvKey.h"
#include "PnlPlnrCtpKParCat.h"
#include "PnlPlnrCtpKParProp.h"
#include "PnlPlnrCtpKCalcdomprp.h"
#include "PnlPlnrCtpKCalcvar.h"
#include "PnlPlnrCtpAEnv.h"
#include "PnlPlnrCtpAPar.h"
#include "PnlPlnrCtpSup1NCalc.h"
#include "PnlPlnrCtpRef1NFile.h"
#include "PnlPlnrCtpTpl1NCalc.h"

/**
  * PnlPlnrCtpRec
  */
class PnlPlnrCtpRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrCtpRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrCtpRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrCtpRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneKEnvKey = false, const bool initdoneKParCat = false, const bool initdoneKParProp = false, const bool initdoneKCalcdomprp = false, const bool initdoneKCalcvar = false, const bool initdoneAEnv = false, const bool initdoneAPar = false, const bool initdoneSup1NCalc = false, const bool initdoneRef1NFile = false, const bool initdoneTpl1NCalc = false);
	};

	/**
		* StatShr (full: StatShrPlnrCtpRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREFKENVKEY = 3;
		static const uint JREFKPARCAT = 4;
		static const uint JREFKPARPROP = 5;
		static const uint JREFKCALCDOMPRP = 6;
		static const uint JREFKCALCVAR = 7;
		static const uint JREFAENV = 8;
		static const uint JREFAPAR = 9;
		static const uint JREFSUP1NCALC = 10;
		static const uint JREFREF1NFILE = 11;
		static const uint JREFTPL1NCALC = 12;
		static const uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jrefKEnvKey = 0, const ubigint jrefKParCat = 0, const ubigint jrefKParProp = 0, const ubigint jrefKCalcdomprp = 0, const ubigint jrefKCalcvar = 0, const ubigint jrefAEnv = 0, const ubigint jrefAPar = 0, const ubigint jrefSup1NCalc = 0, const ubigint jrefRef1NFile = 0, const ubigint jrefTpl1NCalc = 0, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefDetail;
		ubigint jrefKEnvKey;
		ubigint jrefKParCat;
		ubigint jrefKParProp;
		ubigint jrefKCalcdomprp;
		ubigint jrefKCalcvar;
		ubigint jrefAEnv;
		ubigint jrefAPar;
		ubigint jrefSup1NCalc;
		ubigint jrefRef1NFile;
		ubigint jrefTpl1NCalc;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrCtpRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrCtpRecDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		uint ixVDo;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngPlnrCtpRecData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrCtpRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrCtpRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrCtpDetail* pnldetail;
	PnlPlnrCtpKEnvKey* pnlkenvkey;
	PnlPlnrCtpKParCat* pnlkparcat;
	PnlPlnrCtpKParProp* pnlkparprop;
	PnlPlnrCtpKCalcdomprp* pnlkcalcdomprp;
	PnlPlnrCtpKCalcvar* pnlkcalcvar;
	PnlPlnrCtpAEnv* pnlaenv;
	PnlPlnrCtpAPar* pnlapar;
	PnlPlnrCtpSup1NCalc* pnlsup1ncalc;
	PnlPlnrCtpRef1NFile* pnlref1nfile;
	PnlPlnrCtpTpl1NCalc* pnltpl1ncalc;

	PlnrMCalc recCal;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsPlnr* dbsplnr, const bool notif = false, DpchEngPlnr** dpcheng = NULL);
	void regularize(DbsPlnr* dbsplnr, const bool notif = false, DpchEngPlnr** dpcheng = NULL);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrCalUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


