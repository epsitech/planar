/**
  * \file CrdPlnrDtp.h
  * job handler for job CrdPlnrDtp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef CRDPLNRDTP_H
#define CRDPLNRDTP_H

// IP custInclude --- INSERT

#include "PnlPlnrDtpRec.h"
#include "PnlPlnrDtpHeadbar.h"
#include "PnlPlnrDtpList.h"

/**
  * CrdPlnrDtp
  */
class CrdPlnrDtp : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDtpDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVPlnrDtpSge)
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
	  * ContInf (full: ContInfPlnrDtp)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXCRDDTP = 3;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxCrdDtp = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxCrdDtp;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDtp)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVReqitmode = VecPlnrVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneList = false, const bool initdoneRec = false);
	};

	/**
		* StatShr (full: StatShrPlnrDtp)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFHEADBAR = 1;
		static const uint JREFLIST = 2;
		static const uint JREFREC = 3;

	public:
		StatShr(const ubigint jrefHeadbar = 0, const ubigint jrefList = 0, const ubigint jrefRec = 0);

	public:
		ubigint jrefHeadbar;
		ubigint jrefList;
		ubigint jrefRec;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDtp)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDtpDo)
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
		* DpchEngData (full: DpchEngPlnrDtpData)
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

public:
	CrdPlnrDtp(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale, const ubigint ref = 0);
	~CrdPlnrDtp();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	PnlPlnrDtpRec* pnlrec;
	PnlPlnrDtpHeadbar* pnlheadbar;
	PnlPlnrDtpList* pnllist;

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
	void handleDpchAppPlnrAlert(DbsPlnr* dbsplnr, DpchAppPlnrAlert* dpchappplnralert, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrDlgClose(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrStatChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrRefPreSet(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


