/**
  * \file PnlPlnrLyrRec.h
  * job handler for job PnlPlnrLyrRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRLYRREC_H
#define PNLPLNRLYRREC_H

// IP custInclude --- INSERT

#include "PnlPlnrLyrDetail.h"
#include "PnlPlnrLyr1NBlock.h"
#include "PnlPlnrLyr1NReticle.h"
#include "PnlPlnrLyrMNStructure.h"

/**
  * PnlPlnrLyrRec
  */
class PnlPlnrLyrRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrLyrRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrLyrRec)
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
		* StatApp (full: StatAppPlnrLyrRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NBlock = false, const bool initdone1NReticle = false, const bool initdoneMNStructure = false);
	};

	/**
		* StatShr (full: StatShrPlnrLyrRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREF1NBLOCK = 3;
		static const uint PNL1NBLOCKAVAIL = 4;
		static const uint JREF1NRETICLE = 5;
		static const uint PNL1NRETICLEAVAIL = 6;
		static const uint JREFMNSTRUCTURE = 7;
		static const uint PNLMNSTRUCTUREAVAIL = 8;
		static const uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jref1NBlock = 0, const bool pnl1nblockAvail = false, const ubigint jref1NReticle = 0, const bool pnl1nreticleAvail = false, const ubigint jrefMNStructure = 0, const bool pnlmnstructureAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefDetail;
		ubigint jref1NBlock;
		bool pnl1nblockAvail;
		ubigint jref1NReticle;
		bool pnl1nreticleAvail;
		ubigint jrefMNStructure;
		bool pnlmnstructureAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrLyrRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrLyrRecDo)
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
		* DpchEngData (full: DpchEngPlnrLyrRecData)
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

	bool evalPnl1nblockAvail(DbsPlnr* dbsplnr);
	bool evalPnl1nreticleAvail(DbsPlnr* dbsplnr);
	bool evalPnlmnstructureAvail(DbsPlnr* dbsplnr);
	bool evalButRegularizeActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrLyrRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrLyrRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrLyrDetail* pnldetail;
	PnlPlnrLyr1NBlock* pnl1nblock;
	PnlPlnrLyr1NReticle* pnl1nreticle;
	PnlPlnrLyrMNStructure* pnlmnstructure;

	PlnrMLayer recLyr;

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

	bool handleCallPlnrLyrUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


