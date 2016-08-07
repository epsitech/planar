/**
  * \file PnlPlnrLyrDetail.h
  * job handler for job PnlPlnrLyrDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRLYRDETAIL_H
#define PNLPLNRLYRDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrLyrDetail
  */
class PnlPlnrLyrDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrLyrDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTHKUVIEWCLICK = 2;
		static const uint BUTMATVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrLyrDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint NUMFPUPHKT = 2;
		static const uint NUMFPUPTTY = 3;
		static const uint TXFT = 4;
		static const uint TXFML = 5;

	public:
		ContIac(const uint numFPupTyp = 1, const uint numFPupHkt = 1, const uint numFPupTty = 1, const string& TxfT = "", const string& TxfMl = "");

	public:
		uint numFPupTyp;
		uint numFPupHkt;
		uint numFPupTty;
		string TxfT;
		string TxfMl;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrLyrDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTHKU = 2;
		static const uint TXTMAT = 3;
		static const uint TXTFLR = 4;
		static const uint TXTCTR = 5;
		static const uint TXTCEI = 6;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtHku = "", const string& TxtMat = "", const string& TxtFlr = "", const string& TxtCtr = "", const string& TxtCei = "");

	public:
		string TxtSrf;
		string TxtHku;
		string TxtMat;
		string TxtFlr;
		string TxtCtr;
		string TxtCei;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrLyrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrPlnrLyrDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTMATVIEWAVAIL = 3;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButMatViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButMatViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrLyrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrLyrDetailData)
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
		* DpchAppDo (full: DpchAppPlnrLyrDetailDo)
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
		* DpchEngData (full: DpchEngPlnrLyrDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPHKT = 4;
		static const uint FEEDFPUPTTY = 5;
		static const uint FEEDFPUPTYP = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupHkt = NULL, Feed* feedFPupTty = NULL, Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupHkt;
		Feed feedFPupTty;
		Feed feedFPupTyp;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButMatViewAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrLyrDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrLyrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupHkt;
	Feed feedFPupTty;
	Feed feedFPupTyp;

	PlnrMLayer recLyr;
	PlnrJMLayer recLyrJ;
	PlnrJMLayerMaterial recLyrJmat;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshRecLyr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecLyrJ(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecLyrJmat(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButHkuViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButMatViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrLyrUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrLyrJMod_lyrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrLyrJmatMod_lyrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


