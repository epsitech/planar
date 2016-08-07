/**
  * \file PnlPlnrDsnDetail.h
  * job handler for job PnlPlnrDsnDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNDETAIL_H
#define PNLPLNRDSNDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrDsnDetail
  */
class PnlPlnrDsnDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDsnDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTREUVIEWCLICK = 2;
		static const uint BUTPRJVIEWCLICK = 3;
		static const uint BUTMODVIEWCLICK = 4;
		static const uint BUTDRVVIEWCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDsnDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint NUMFPUPTYP = 2;
		static const uint NUMFPUPDIM = 3;
		static const uint NUMFPUPRET = 4;
		static const uint NUMSFLSTMTY = 5;
		static const uint TXFMAJ = 6;
		static const uint TXFSUB = 7;
		static const uint TXFCMT = 8;

	public:
		ContIac(const string& TxfTit = "", const uint numFPupTyp = 1, const uint numFPupDim = 1, const uint numFPupRet = 1, const vector<uint>& numsFLstMty = {}, const string& TxfMaj = "", const string& TxfSub = "", const string& TxfCmt = "");

	public:
		string TxfTit;
		uint numFPupTyp;
		uint numFPupDim;
		uint numFPupRet;
		vector<uint> numsFLstMty;
		string TxfMaj;
		string TxfSub;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDsnDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREU = 1;
		static const uint TXTPRJ = 2;
		static const uint TXTMTY = 3;
		static const uint TXTMOD = 4;
		static const uint TXTDRV = 5;

	public:
		ContInf(const string& TxtReu = "", const string& TxtPrj = "", const string& TxtMty = "", const string& TxtMod = "", const string& TxtDrv = "");

	public:
		string TxtReu;
		string TxtPrj;
		string TxtMty;
		string TxtMod;
		string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDsnDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstMtyAlt = true, const uint LstMtyNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrDsnDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSAVEAVAIL = 1;
		static const uint BUTSAVEACTIVE = 2;
		static const uint BUTPRJVIEWAVAIL = 3;
		static const uint BUTMODVIEWAVAIL = 4;
		static const uint BUTDRVVIEWAVAIL = 5;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButPrjViewAvail = true, const bool ButModViewAvail = true, const bool ButDrvViewAvail = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButPrjViewAvail;
		bool ButModViewAvail;
		bool ButDrvViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDsnDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDsnDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDsnDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDsnDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTMTY = 4;
		static const uint FEEDFPUPDIM = 5;
		static const uint FEEDFPUPRET = 6;
		static const uint FEEDFPUPTYP = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;
		static const uint ALL = 11;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstMty = NULL, Feed* feedFPupDim = NULL, Feed* feedFPupRet = NULL, Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstMty;
		Feed feedFPupDim;
		Feed feedFPupRet;
		Feed feedFPupTyp;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButPrjViewAvail(DbsPlnr* dbsplnr);
	bool evalButModViewAvail(DbsPlnr* dbsplnr);
	bool evalButDrvViewAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrDsnDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDsnDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstMty;
	Feed feedFPupDim;
	Feed feedFPupRet;
	Feed feedFPupTyp;

	PlnrMDesign recDsn;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshTxtMty(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecDsn(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButPrjViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButModViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDrvViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrDsn_dimEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallPlnrDsn_modEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallPlnrDsn_typEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallPlnrDsnUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


