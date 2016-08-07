/**
  * \file PnlPlnrDomDetail.h
  * job handler for job PnlPlnrDomDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDOMDETAIL_H
#define PNLPLNRDOMDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrDomDetail
  */
class PnlPlnrDomDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDomDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDomDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint TXFFLR = 2;
		static const uint TXFCEI = 3;
		static const uint TXFVX1 = 4;
		static const uint TXFLG1 = 5;
		static const uint TXFVX2 = 6;
		static const uint TXFLG2 = 7;
		static const uint TXFVX3 = 8;
		static const uint TXFLG3 = 9;
		static const uint TXFVX4 = 10;
		static const uint TXFLG4 = 11;
		static const uint TXFDX = 12;
		static const uint TXFDY = 13;
		static const uint TXFDXY = 14;
		static const uint TXFDZ = 15;

	public:
		ContIac(const uint numFPupTyp = 1, const string& TxfFlr = "", const string& TxfCei = "", const string& TxfVx1 = "", const string& TxfLg1 = "", const string& TxfVx2 = "", const string& TxfLg2 = "", const string& TxfVx3 = "", const string& TxfLg3 = "", const string& TxfVx4 = "", const string& TxfLg4 = "", const string& TxfDx = "", const string& TxfDy = "", const string& TxfDxy = "", const string& TxfDz = "");

	public:
		uint numFPupTyp;
		string TxfFlr;
		string TxfCei;
		string TxfVx1;
		string TxfLg1;
		string TxfVx2;
		string TxfLg2;
		string TxfVx3;
		string TxfLg3;
		string TxfVx4;
		string TxfLg4;
		string TxfDx;
		string TxfDy;
		string TxfDxy;
		string TxfDz;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDomDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTFLR = 3;
		static const uint TXTCEI = 4;
		static const uint TXTVX1 = 5;
		static const uint TXTLG1 = 6;
		static const uint TXTVX2 = 7;
		static const uint TXTLG2 = 8;
		static const uint TXTVX3 = 9;
		static const uint TXTLG3 = 10;
		static const uint TXTVX4 = 11;
		static const uint TXTLG4 = 12;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtFlr = "", const string& TxtCei = "", const string& TxtVx1 = "", const string& TxtLg1 = "", const string& TxtVx2 = "", const string& TxtLg2 = "", const string& TxtVx3 = "", const string& TxtLg3 = "", const string& TxtVx4 = "", const string& TxtLg4 = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtFlr;
		string TxtCei;
		string TxtVx1;
		string TxtLg1;
		string TxtVx2;
		string TxtLg2;
		string TxtVx3;
		string TxtLg3;
		string TxtVx4;
		string TxtLg4;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDomDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtFlrAlt = false, const bool TxtCeiAlt = false, const bool TxtVx1Alt = false, const bool TxtLg1Alt = false, const bool TxtVx2Alt = false, const bool TxtLg2Alt = false, const bool TxtVx3Alt = false, const bool TxtLg3Alt = false, const bool TxtVx4Alt = false, const bool TxtLg4Alt = false);
	};

	/**
		* StatShr (full: StatShrPlnrDomDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFFLRVALID = 1;
		static const uint TXFCEIVALID = 2;
		static const uint TXFVX1VALID = 3;
		static const uint TXFLG1VALID = 4;
		static const uint TXFVX2VALID = 5;
		static const uint TXFLG2VALID = 6;
		static const uint TXFVX3VALID = 7;
		static const uint TXFLG3VALID = 8;
		static const uint TXFVX4VALID = 9;
		static const uint TXFLG4VALID = 10;
		static const uint BUTSAVEAVAIL = 11;
		static const uint BUTSAVEACTIVE = 12;
		static const uint BUTDSNVIEWAVAIL = 13;

	public:
		StatShr(const bool TxfFlrValid = false, const bool TxfCeiValid = false, const bool TxfVx1Valid = false, const bool TxfLg1Valid = false, const bool TxfVx2Valid = false, const bool TxfLg2Valid = false, const bool TxfVx3Valid = false, const bool TxfLg3Valid = false, const bool TxfVx4Valid = false, const bool TxfLg4Valid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true);

	public:
		bool TxfFlrValid;
		bool TxfCeiValid;
		bool TxfVx1Valid;
		bool TxfLg1Valid;
		bool TxfVx2Valid;
		bool TxfLg2Valid;
		bool TxfVx3Valid;
		bool TxfLg3Valid;
		bool TxfVx4Valid;
		bool TxfLg4Valid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDomDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDomDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDomDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDomDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPTYP = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupTyp = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupTyp;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsPlnr* dbsplnr);
	bool evalButSaveActive(DbsPlnr* dbsplnr);
	bool evalButDsnViewAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrDomDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDomDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupTyp;

	PlnrMDomain recDom;
	PlnrJMDomain recDomJ;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshTxtFlr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtCei(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtVx1(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtLg1(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtVx2(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtLg2(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtVx3(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtLg3(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtVx4(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtLg4(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecDom(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecDomJ(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButSaveClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDsnViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrDomUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrDomJMod_domEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


