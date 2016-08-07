/**
  * \file CrdPlnrClc.h
  * job handler for job CrdPlnrClc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef CRDPLNRCLC_H
#define CRDPLNRCLC_H

// IP custInclude --- INSERT

#include "DlgPlnrClcExprtx.h"
#include "DlgPlnrClcGenrpv.h"
#include "DlgPlnrClcUsecase.h"
#include "PnlPlnrClcRec.h"
#include "PnlPlnrClcHeadbar.h"
#include "PnlPlnrClcList.h"

/**
  * CrdPlnrClc
  */
class CrdPlnrClc : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrClcDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITCRDUCSCLICK = 3;
		static const uint MITCRDGPVCLICK = 4;
		static const uint MITCRDETXCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVPlnrClcSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRPLNRABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfPlnrClc)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDCLC = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdClc = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdClc;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrClc)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVReqitmode = VecPlnrVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrPlnrClc)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGEXPRTX = 1;
		static const uint JREFDLGGENRPV = 2;
		static const uint JREFDLGUSECASE = 3;
		static const uint JREFHEADBAR = 4;
		static const uint JREFLIST = 5;
		static const uint JREFREC = 6;
		static const uint MSPCRD1AVAIL = 7;
		static const uint MITCRDUCSAVAIL = 8;
		static const uint MITCRDGPVAVAIL = 9;
		static const uint MITCRDGPVACTIVE = 10;
		static const uint MITCRDETXAVAIL = 11;
		static const uint MITCRDETXACTIVE = 12;

	public:
		StatShr(const ubigint jrefDlgexprtx = 0, const ubigint jrefDlggenrpv = 0, const ubigint jrefDlgusecase = 0, const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0, const bool MspCrd1Avail = true, const bool MitCrdUcsAvail = true, const bool MitCrdGpvAvail = true, const bool MitCrdGpvActive = true, const bool MitCrdEtxAvail = true, const bool MitCrdEtxActive = true);

	public:
		ubigint jrefDlgexprtx;
		ubigint jrefDlggenrpv;
		ubigint jrefDlgusecase;
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;
		bool MspCrd1Avail;
		bool MitCrdUcsAvail;
		bool MitCrdGpvAvail;
		bool MitCrdGpvActive;
		bool MitCrdEtxAvail;
		bool MitCrdEtxActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrClc)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrClcDo)
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
		* DpchEngData (full: DpchEngPlnrClcData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalMspCrd1Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdUcsAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdGpvAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdGpvActive(DbsPlnr* dbsplnr);
	bool evalMitCrdEtxAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdEtxActive(DbsPlnr* dbsplnr);

public:
	CrdPlnrClc(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale, const ubigint ref = 0, const uint ixPlnrVPreset = VecPlnrVPreset::VOID, const ubigint preUref = 0);
	~CrdPlnrClc();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgPlnrClcExprtx* dlgexprtx;
	DlgPlnrClcGenrpv* dlggenrpv;
	DlgPlnrClcUsecase* dlgusecase;
	PnlPlnrClcRec* pnlrec;
	PnlPlnrClcHeadbar* pnlheadbar;
	PnlPlnrClcList* pnllist;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);
	void changeRef(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint ref, const bool notif = false);
	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsPlnr* dbsplnr, uint _ixVSge, DpchEngPlnr** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsPlnr* dbsplnr);
	void leaveSgeIdle(DbsPlnr* dbsplnr);
	uint enterSgeAlrplnrabt(DbsPlnr* dbsplnr);
	void leaveSgeAlrplnrabt(DbsPlnr* dbsplnr);
	uint enterSgeClose(DbsPlnr* dbsplnr);
	void leaveSgeClose(DbsPlnr* dbsplnr);

// IP getSquawk --- BEGIN
	string getSquawk(DbsPlnr* dbsplnr);
// IP getSquawk --- END

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

	void handleDpchAppDoClose(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdUcsClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdGpvClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdEtxClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppPlnrAlert(DbsPlnr* dbsplnr, DpchAppPlnrAlert* dpchappplnralert, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrDlgClose(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrStatChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrRefPreSet(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


