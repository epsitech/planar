/**
  * \file PnlPlnrStkRec.h
  * job handler for job PnlPlnrStkRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSTKREC_H
#define PNLPLNRSTKREC_H

// IP custInclude --- INSERT

#include "PnlPlnrStkPre.h"
#include "PnlPlnrStkDetail.h"
#include "PnlPlnrStkView.h"
#include "PnlPlnrStkHk1NLevel.h"
#include "PnlPlnrStkHk1NLayer.h"
#include "PnlPlnrStkMNStructure.h"

/**
  * PnlPlnrStkRec
  */
class PnlPlnrStkRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrStkRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrStkRec)
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
		* StatApp (full: StatAppPlnrStkRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneHk1NLevel = false, const bool initdoneHk1NLayer = false, const bool initdoneMNStructure = false);
	};

	/**
		* StatShr (full: StatShrPlnrStkRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFVIEW = 4;
		static const uint JREFHK1NLEVEL = 5;
		static const uint JREFHK1NLAYER = 6;
		static const uint JREFMNSTRUCTURE = 7;
		static const uint PNLMNSTRUCTUREAVAIL = 8;
		static const uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefView = 0, const ubigint jrefHk1NLevel = 0, const ubigint jrefHk1NLayer = 0, const ubigint jrefMNStructure = 0, const bool pnlmnstructureAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefView;
		ubigint jrefHk1NLevel;
		ubigint jrefHk1NLayer;
		ubigint jrefMNStructure;
		bool pnlmnstructureAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrStkRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrStkRecDo)
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
		* DpchEngData (full: DpchEngPlnrStkRecData)
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

	bool evalPnlmnstructureAvail(DbsPlnr* dbsplnr);
	bool evalButRegularizeActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrStkRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrStkRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrStkPre* pnlpre;
	PnlPlnrStkDetail* pnldetail;
	PnlPlnrStkView* pnlview;
	PnlPlnrStkHk1NLevel* pnlhk1nlevel;
	PnlPlnrStkHk1NLayer* pnlhk1nlayer;
	PnlPlnrStkMNStructure* pnlmnstructure;

	PlnrMStack recStk;

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

	bool handleCallPlnrStkUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


