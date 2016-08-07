/**
  * \file PnlPlnrStkDetail.h
  * job handler for job PnlPlnrStkDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSTKDETAIL_H
#define PNLPLNRSTKDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrStkDetail
  */
class PnlPlnrStkDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrStkDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;
		static const uint BUTLYRVIEWCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrStkDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint NUMFPUPMTY = 2;
		static const uint NUMFPUPFAL = 3;
		static const uint TXFFLR = 4;
		static const uint TXFZFL = 5;
		static const uint NUMFPUPCAL = 6;
		static const uint TXFCIL = 7;
		static const uint TXFZCI = 8;
		static const uint NUMFLSTLYR = 9;
		static const uint TXFLYR = 10;
		static const uint TXFN = 11;

	public:
		ContIac(const uint numFPupTyp = 1, const uint numFPupMty = 1, const uint numFPupFal = 1, const string& TxfFlr = "", const string& TxfZfl = "", const uint numFPupCal = 1, const string& TxfCil = "", const string& TxfZci = "", const uint numFLstLyr = 1, const string& TxfLyr = "", const string& TxfN = "");

	public:
		uint numFPupTyp;
		uint numFPupMty;
		uint numFPupFal;
		string TxfFlr;
		string TxfZfl;
		uint numFPupCal;
		string TxfCil;
		string TxfZci;
		uint numFLstLyr;
		string TxfLyr;
		string TxfN;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrStkDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTFLR = 3;
		static const uint TXTCIL = 4;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtFlr = "", const string& TxtCil = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtFlr;
		string TxtCil;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrStkDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtFlrAlt = false, const bool TxtCilAlt = false, const bool LstLyrAlt = true, const uint LstLyrNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrStkDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFFLRVALID = 1;
		static const uint TXFCILVALID = 2;
		static const uint TXFLYRVALID = 3;
		static const uint BUTSAVEAVAIL = 4;
		static const uint BUTSAVEACTIVE = 5;
		static const uint BUTDSNVIEWAVAIL = 6;
		static const uint BUTLYRVIEWAVAIL = 7;
		static const uint BUTLYRVIEWACTIVE = 8;

	public:
		StatShr(const bool TxfFlrValid = false, const bool TxfCilValid = false, const bool TxfLyrValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true, const bool ButLyrViewAvail = true, const bool ButLyrViewActive = true);

	public:
		bool TxfFlrValid;
		bool TxfCilValid;
		bool TxfLyrValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;
		bool ButLyrViewAvail;
		bool ButLyrViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrStkDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrStkDetailData)
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
		* DpchAppDo (full: DpchAppPlnrStkDetailDo)
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
		* DpchEngData (full: DpchEngPlnrStkDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTLYR = 4;
		static const uint FEEDFPUPCAL = 5;
		static const uint FEEDFPUPFAL = 6;
		static const uint FEEDFPUPMTY = 7;
		static const uint FEEDFPUPTYP = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint TAG = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstLyr = NULL, Feed* feedFPupCal = NULL, Feed* feedFPupFal = NULL, Feed* feedFPupMty = NULL, Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstLyr;
		Feed feedFPupCal;
		Feed feedFPupFal;
		Feed feedFPupMty;
		Feed feedFPupTyp;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButDsnViewAvail(DbsPlnr* dbsplnr);
	bool evalButLyrViewAvail(DbsPlnr* dbsplnr);
	bool evalButLyrViewActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrStkDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrStkDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstLyr;
	Feed feedFPupCal;
	Feed feedFPupFal;
	Feed feedFPupMty;
	Feed feedFPupTyp;

	PlnrMStack recStk;
	PlnrJMStackN recStkJn;
	PlnrJMStackModtype recStkJmod;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshTxtFlr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtCil(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstLyr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLyr(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecStk(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecStkJn(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecStkJmod(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDsnViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButLyrViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrStkUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrStkJnMod_stkEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrStkJmodMod_stkEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


