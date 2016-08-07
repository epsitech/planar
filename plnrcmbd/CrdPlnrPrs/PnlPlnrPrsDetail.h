/**
  * \file PnlPlnrPrsDetail.h
  * job handler for job PnlPlnrPrsDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRPRSDETAIL_H
#define PNLPLNRPRSDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrPrsDetail
  */
class PnlPlnrPrsDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTJEDITCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrPrsDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint TXFTIT = 1;
		static const uint TXFFNM = 2;
		static const uint NUMFPUPJ = 3;
		static const uint NUMSFLSTDRV = 4;
		static const uint NUMFPUPSEX = 5;
		static const uint TXFTEL = 6;
		static const uint TXFEML = 7;
		static const uint TXFSAL = 8;

	public:
		ContIac(const string& TxfTit = "", const string& TxfFnm = "", const uint numFPupJ = 1, const vector<uint>& numsFLstDrv = {}, const uint numFPupSex = 1, const string& TxfTel = "", const string& TxfEml = "", const string& TxfSal = "");

	public:
		string TxfTit;
		string TxfFnm;
		uint numFPupJ;
		vector<uint> numsFLstDrv;
		uint numFPupSex;
		string TxfTel;
		string TxfEml;
		string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrPrsDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTLNM = 1;
		static const uint TXTDRV = 2;

	public:
		ContInf(const string& TxtLnm = "", const string& TxtDrv = "");

	public:
		string TxtLnm;
		string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrPrsDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstDrvAlt = true, const uint LstDrvNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrPrsDetail)
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
		* Tag (full: TagPlnrPrsDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrPrsDetailData)
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
		* DpchAppDo (full: DpchAppPlnrPrsDetailDo)
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
		* DpchEngData (full: DpchEngPlnrPrsDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFLSTDRV = 4;
		static const uint FEEDFPUPJ = 5;
		static const uint FEEDFPUPSEX = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFLstDrv = NULL, Feed* feedFPupJ = NULL, Feed* feedFPupSex = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFLstDrv;
		Feed feedFPupJ;
		Feed feedFPupSex;
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
	PnlPlnrPrsDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrPrsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFLstDrv;
	Feed feedFPupJ;
	Feed feedFPupSex;

	PlnrMPerson recPrs;
	PlnrJMPersonLastname recPrsJlnm;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshJ(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtDrv(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecPrs(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecPrsJlnm(DbsPlnr* dbsplnr, set<uint>& moditems);

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

	bool handleCallPlnrPrsUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrPrsJlnmMod_prsEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


