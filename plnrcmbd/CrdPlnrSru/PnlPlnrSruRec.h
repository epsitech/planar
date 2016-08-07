/**
  * \file PnlPlnrSruRec.h
  * job handler for job PnlPlnrSruRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSRUREC_H
#define PNLPLNRSRUREC_H

// IP custInclude --- INSERT

#include "PnlPlnrSruDetail.h"
#include "PnlPlnrSru1NBlock.h"
#include "PnlPlnrSruSru1NFace.h"
#include "PnlPlnrSruMNLayer.h"
#include "PnlPlnrSruMNStack.h"

/**
  * PnlPlnrSruRec
  */
class PnlPlnrSruRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrSruRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrSruRec)
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
		* StatApp (full: StatAppPlnrSruRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdone1NBlock = false, const bool initdoneSru1NFace = false, const bool initdoneMNLayer = false, const bool initdoneMNStack = false);
	};

	/**
		* StatShr (full: StatShrPlnrSruRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFDETAIL = 2;
		static const uint JREF1NBLOCK = 3;
		static const uint PNL1NBLOCKAVAIL = 4;
		static const uint JREFSRU1NFACE = 5;
		static const uint JREFMNLAYER = 6;
		static const uint PNLMNLAYERAVAIL = 7;
		static const uint JREFMNSTACK = 8;
		static const uint PNLMNSTACKAVAIL = 9;
		static const uint BUTREGULARIZEACTIVE = 10;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefDetail = 0, const ubigint jref1NBlock = 0, const bool pnl1nblockAvail = false, const ubigint jrefSru1NFace = 0, const ubigint jrefMNLayer = 0, const bool pnlmnlayerAvail = false, const ubigint jrefMNStack = 0, const bool pnlmnstackAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefDetail;
		ubigint jref1NBlock;
		bool pnl1nblockAvail;
		ubigint jrefSru1NFace;
		ubigint jrefMNLayer;
		bool pnlmnlayerAvail;
		ubigint jrefMNStack;
		bool pnlmnstackAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrSruRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrSruRecDo)
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
		* DpchEngData (full: DpchEngPlnrSruRecData)
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
	bool evalPnlmnlayerAvail(DbsPlnr* dbsplnr);
	bool evalPnlmnstackAvail(DbsPlnr* dbsplnr);
	bool evalButRegularizeActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrSruRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrSruRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrSruDetail* pnldetail;
	PnlPlnrSru1NBlock* pnl1nblock;
	PnlPlnrSruSru1NFace* pnlsru1nface;
	PnlPlnrSruMNLayer* pnlmnlayer;
	PnlPlnrSruMNStack* pnlmnstack;

	PlnrMStructure recSru;

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

	bool handleCallPlnrSruUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


