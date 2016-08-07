/**
  * \file PnlPlnrTpoDetail.h
  * job handler for job PnlPlnrTpoDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRTPODETAIL_H
#define PNLPLNRTPODETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrTpoDetail
  */
class PnlPlnrTpoDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrTpoDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrTpoDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPTYP = 2;
		static const uint TXFMAJ = 3;
		static const uint TXFSUB = 4;
		static const uint NUMFPUPJ = 5;
		static const uint NUMFPUPSTE = 6;
		static const uint CHKFLI = 7;
		static const uint TXFCMT = 8;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupTyp = 1, const string& TxfMaj = "", const string& TxfSub = "", const uint numFPupJ = 1, const uint numFPupSte = 1, const bool ChkFli = false, const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupTyp;
		string TxfMaj;
		string TxfSub;
		uint numFPupJ;
		uint numFPupSte;
		bool ChkFli;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppPlnrTpoDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrPlnrTpoDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTJEDITAVAIL = 3;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButJEditAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButJEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrTpoDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrTpoDetailData)
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
		* DpchAppDo (full: DpchAppPlnrTpoDetailDo)
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
		* DpchEngData (full: DpchEngPlnrTpoDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFPUPJ = 3;
		static const uint FEEDFPUPSTE = 4;
		static const uint FEEDFPUPTYP = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFPupJ = NULL, Feed* feedFPupSte = NULL, Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFPupJ;
		Feed feedFPupSte;
		Feed feedFPupTyp;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButJEditAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrTpoDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrTpoDetail();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFPupJ;
	Feed feedFPupSte;
	Feed feedFPupTyp;

	PlnrMTapeout recTpo;
	PlnrJMTapeoutState recTpoJste;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshJ(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecTpo(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecTpoJste(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButJEditClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrTpoUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrTpoJsteMod_tpoEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


