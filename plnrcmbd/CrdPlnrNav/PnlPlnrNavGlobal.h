/**
  * \file PnlPlnrNavGlobal.h
  * job handler for job PnlPlnrNavGlobal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVGLOBAL_H
#define PNLPLNRNAVGLOBAL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavGlobal
  */
class PnlPlnrNavGlobal : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavGlobalDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDTPVIEWCLICK = 1;
		static const uint BUTDTPNEWCRDCLICK = 2;
		static const uint BUTCTPVIEWCLICK = 3;
		static const uint BUTCTPNEWCRDCLICK = 4;
		static const uint BUTMATVIEWCLICK = 5;
		static const uint BUTMATNEWCRDCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavGlobal)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTDTP = 1;
		static const uint NUMFLSTCTP = 2;
		static const uint NUMFLSTMAT = 3;

	public:
		ContIac(const uint numFLstDtp = 1, const uint numFLstCtp = 1, const uint numFLstMat = 1);

	public:
		uint numFLstDtp;
		uint numFLstCtp;
		uint numFLstMat;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppPlnrNavGlobal)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstDtpAlt = true, const bool LstCtpAlt = true, const bool LstMatAlt = true, const uint LstDtpNumFirstdisp = 1, const uint LstCtpNumFirstdisp = 1, const uint LstMatNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrNavGlobal)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTDTPAVAIL = 1;
		static const uint BUTDTPVIEWACTIVE = 2;
		static const uint LSTCTPAVAIL = 3;
		static const uint BUTCTPVIEWACTIVE = 4;
		static const uint LSTMATAVAIL = 5;
		static const uint BUTMATVIEWACTIVE = 6;

	public:
		StatShr(const bool LstDtpAvail = true, const bool ButDtpViewActive = true, const bool LstCtpAvail = true, const bool ButCtpViewActive = true, const bool LstMatAvail = true, const bool ButMatViewActive = true);

	public:
		bool LstDtpAvail;
		bool ButDtpViewActive;
		bool LstCtpAvail;
		bool ButCtpViewActive;
		bool LstMatAvail;
		bool ButMatViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNavGlobal)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavGlobalData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrNavGlobalDo)
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
		* DpchEngData (full: DpchEngPlnrNavGlobalData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTCTP = 3;
		static const uint FEEDFLSTDTP = 4;
		static const uint FEEDFLSTMAT = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstCtp = NULL, Feed* feedFLstDtp = NULL, Feed* feedFLstMat = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstCtp;
		Feed feedFLstDtp;
		Feed feedFLstMat;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstDtpAvail(DbsPlnr* dbsplnr);
	bool evalButDtpViewActive(DbsPlnr* dbsplnr);
	bool evalLstCtpAvail(DbsPlnr* dbsplnr);
	bool evalButCtpViewActive(DbsPlnr* dbsplnr);
	bool evalLstMatAvail(DbsPlnr* dbsplnr);
	bool evalButMatViewActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavGlobal(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavGlobal();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstCtp;
	Feed feedFLstDtp;
	Feed feedFLstMat;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshLstDtp(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshDtp(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstCtp(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshCtp(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstMat(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshMat(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButDtpViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDtpNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCtpViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCtpNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButMatViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButMatNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrHusrRunvMod_crdUsrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


