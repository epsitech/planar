/**
  * \file PnlPlnrClcRec.h
  * job handler for job PnlPlnrClcRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRCLCREC_H
#define PNLPLNRCLCREC_H

// IP custInclude --- INSERT

#include "PnlPlnrClcPre.h"
#include "PnlPlnrClcDetail.h"
#include "PnlPlnrClcView.h"
#include "PnlPlnrClcAEnv.h"
#include "PnlPlnrClcAPar.h"
#include "PnlPlnrClcCal1NCalcitem.h"
#include "PnlPlnrClc1NMaterial.h"
#include "PnlPlnrClcSup1NCalc.h"
#include "PnlPlnrClcRef1NFile.h"
#include "PnlPlnrClcMNFile.h"
#include "PnlPlnrClcMNDomain.h"

/**
  * PnlPlnrClcRec
  */
class PnlPlnrClcRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrClcRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrClcRec)
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
		* StatApp (full: StatAppPlnrClcRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneAEnv = false, const bool initdoneAPar = false, const bool initdoneCal1NCalcitem = false, const bool initdone1NMaterial = false, const bool initdoneSup1NCalc = false, const bool initdoneRef1NFile = false, const bool initdoneMNFile = false, const bool initdoneMNDomain = false);
	};

	/**
		* StatShr (full: StatShrPlnrClcRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFVIEW = 4;
		static const uint JREFAENV = 5;
		static const uint JREFAPAR = 6;
		static const uint JREFCAL1NCALCITEM = 7;
		static const uint JREF1NMATERIAL = 8;
		static const uint JREFSUP1NCALC = 9;
		static const uint JREFREF1NFILE = 10;
		static const uint JREFMNFILE = 11;
		static const uint JREFMNDOMAIN = 12;
		static const uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefView = 0, const ubigint jrefAEnv = 0, const ubigint jrefAPar = 0, const ubigint jrefCal1NCalcitem = 0, const ubigint jref1NMaterial = 0, const ubigint jrefSup1NCalc = 0, const ubigint jrefRef1NFile = 0, const ubigint jrefMNFile = 0, const ubigint jrefMNDomain = 0, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefView;
		ubigint jrefAEnv;
		ubigint jrefAPar;
		ubigint jrefCal1NCalcitem;
		ubigint jref1NMaterial;
		ubigint jrefSup1NCalc;
		ubigint jrefRef1NFile;
		ubigint jrefMNFile;
		ubigint jrefMNDomain;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrClcRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrClcRecDo)
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
		* DpchEngData (full: DpchEngPlnrClcRecData)
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
	PnlPlnrClcRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrClcRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrClcPre* pnlpre;
	PnlPlnrClcDetail* pnldetail;
	PnlPlnrClcView* pnlview;
	PnlPlnrClcAEnv* pnlaenv;
	PnlPlnrClcAPar* pnlapar;
	PnlPlnrClcCal1NCalcitem* pnlcal1ncalcitem;
	PnlPlnrClc1NMaterial* pnl1nmaterial;
	PnlPlnrClcSup1NCalc* pnlsup1ncalc;
	PnlPlnrClcRef1NFile* pnlref1nfile;
	PnlPlnrClcMNFile* pnlmnfile;
	PnlPlnrClcMNDomain* pnlmndomain;

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


