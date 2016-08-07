/**
  * \file PnlPlnrFilDetail.h
  * job handler for job PnlPlnrFilDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRFILDETAIL_H
#define PNLPLNRFILDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrFilDetail
  */
class PnlPlnrFilDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrFilDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTCLUVIEWCLICK = 2;
		static const uint BUTCLUCLUSTERCLICK = 3;
		static const uint BUTCLUUNCLUSTERCLICK = 4;
		static const uint BUTREUVIEWCLICK = 5;
		static const uint BUTCNTEDITCLICK = 6;
		static const uint BUTMIMEDITCLICK = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrFilDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFFNM = 1;
		static const uint NUMFLSTCLU = 2;
		static const uint NUMFPUPRET = 3;
		static const uint NUMFPUPCNT = 4;
		static const uint TXFCNT = 5;
		static const uint TXFACV = 6;
		static const uint TXFANM = 7;
		static const uint NUMFPUPMIM = 8;
		static const uint TXFMIM = 9;
		static const uint TXFSIZ = 10;
		static const uint TXFCMT = 11;

	public:
		ContIac(const string& TxfFnm = "", const uint numFLstClu = 1, const uint numFPupRet = 1, const uint numFPupCnt = 1, const string& TxfCnt = "", const string& TxfAcv = "", const string& TxfAnm = "", const uint numFPupMim = 1, const string& TxfMim = "", const string& TxfSiz = "", const string& TxfCmt = "");

	public:
		string TxfFnm;
		uint numFLstClu;
		uint numFPupRet;
		uint numFPupCnt;
		string TxfCnt;
		string TxfAcv;
		string TxfAnm;
		uint numFPupMim;
		string TxfMim;
		string TxfSiz;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrFilDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTCLU = 1;
		static const uint TXTREU = 2;

	public:
		ContInf(const string& TxtClu = "", const string& TxtReu = "");

	public:
		string TxtClu;
		string TxtReu;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrFilDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrFilDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFCNTVALID = 1;
		static const uint TXFMIMVALID = 2;
		static const uint BUTSAVEAVAIL = 3;
		static const uint BUTSAVEACTIVE = 4;
		static const uint BUTCLUVIEWACTIVE = 5;
		static const uint BUTCLUCLUSTERAVAIL = 6;
		static const uint BUTCLUUNCLUSTERAVAIL = 7;
		static const uint BUTCNTEDITAVAIL = 8;
		static const uint BUTMIMEDITAVAIL = 9;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool ButCntEditAvail = true, const bool ButMimEditAvail = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool ButCntEditAvail;
		bool ButMimEditAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrFilDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrFilDetailData)
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
		* DpchAppDo (full: DpchAppPlnrFilDetailDo)
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
		* DpchEngData (full: DpchEngPlnrFilDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTCLU = 4;
		static const uint FEEDFPUPCNT = 5;
		static const uint FEEDFPUPMIM = 6;
		static const uint FEEDFPUPRET = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint TAG = 10;
		static const uint ALL = 11;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstClu = NULL, Feed* feedFPupCnt = NULL, Feed* feedFPupMim = NULL, Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstClu;
		Feed feedFPupCnt;
		Feed feedFPupMim;
		Feed feedFPupRet;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButCluViewActive(DbsPlnr* dbsplnr);
	bool evalButCluClusterAvail(DbsPlnr* dbsplnr);
	bool evalButCluUnclusterAvail(DbsPlnr* dbsplnr);
	bool evalButCntEditAvail(DbsPlnr* dbsplnr);
	bool evalButMimEditAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrFilDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrFilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstClu;
	Feed feedFPupCnt;
	Feed feedFPupMim;
	Feed feedFPupRet;

	PlnrMFile recFil;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshLstClu(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshClu(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshPupCnt(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxfCnt(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshCnt(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshPupMim(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxfMim(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshMim(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecFil(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCntEditClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButMimEditClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrFil_cluEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallPlnrFilUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrKlsAkeyMod_klsEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv);
	bool handleCallPlnrFilMod_cluEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


