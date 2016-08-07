/**
  * \file PnlPlnrAriDetail.h
  * job handler for job PnlPlnrAriDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRARIDETAIL_H
#define PNLPLNRARIDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrAriDetail
  */
class PnlPlnrAriDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrAriDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTARRVIEWCLICK = 2;
		static const uint BUTDSNVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrAriDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFI = 1;
		static const uint TXFJ = 2;
		static const uint TXFK = 3;
		static const uint TXFL = 4;
		static const uint TXFM = 5;
		static const uint TXFN = 6;
		static const uint TXFDX = 7;
		static const uint TXFDY = 8;

	public:
		ContIac(const string& TxfI = "", const string& TxfJ = "", const string& TxfK = "", const string& TxfL = "", const string& TxfM = "", const string& TxfN = "", const string& TxfDx = "", const string& TxfDy = "");

	public:
		string TxfI;
		string TxfJ;
		string TxfK;
		string TxfL;
		string TxfM;
		string TxfN;
		string TxfDx;
		string TxfDy;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrAriDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTARR = 1;
		static const uint TXTDSN = 2;

	public:
		ContInf(const string& TxtArr = "", const string& TxtDsn = "");

	public:
		string TxtArr;
		string TxtDsn;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrAriDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrPlnrAriDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTARRVIEWAVAIL = 3;
		static const uint BUTDSNVIEWAVAIL = 4;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButArrViewAvail = true, const bool ButDsnViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButArrViewAvail;
		bool ButDsnViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrAriDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrAriDetailData)
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
		* DpchAppDo (full: DpchAppPlnrAriDetailDo)
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
		* DpchEngData (full: DpchEngPlnrAriDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButArrViewAvail(DbsPlnr* dbsplnr);
	bool evalButDsnViewAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrAriDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrAriDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	PlnrMArrayitem recAri;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshRecAri(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButArrViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDsnViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrAriUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


