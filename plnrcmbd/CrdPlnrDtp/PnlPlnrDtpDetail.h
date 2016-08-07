/**
  * \file PnlPlnrDtpDetail.h
  * job handler for job PnlPlnrDtpDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDTPDETAIL_H
#define PNLPLNRDTPDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrDtpDetail
  */
class PnlPlnrDtpDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDtpDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDtpDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPMTY = 1;
		static const uint NUMFPUPATY = 2;
		static const uint TXFAV1 = 3;
		static const uint TXFPV1 = 4;
		static const uint TXFAV2 = 5;
		static const uint TXFPV2 = 6;
		static const uint TXFX = 7;
		static const uint TXFY = 8;
		static const uint TXFPHI = 9;
		static const uint TXFCMT = 10;

	public:
		ContIac(const uint numFPupMty = 1, const uint numFPupAty = 1, const string& TxfAv1 = "", const string& TxfPv1 = "", const string& TxfAv2 = "", const string& TxfPv2 = "", const string& TxfX = "", const string& TxfY = "", const string& TxfPhi = "", const string& TxfCmt = "");

	public:
		uint numFPupMty;
		uint numFPupAty;
		string TxfAv1;
		string TxfPv1;
		string TxfAv2;
		string TxfPv2;
		string TxfX;
		string TxfY;
		string TxfPhi;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDtpDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTSUP = 3;
		static const uint TXTTPL = 4;
		static const uint TXTAV1 = 5;
		static const uint TXTPV1 = 6;
		static const uint TXTAV2 = 7;
		static const uint TXTPV2 = 8;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtSup = "", const string& TxtTpl = "", const string& TxtAv1 = "", const string& TxtPv1 = "", const string& TxtAv2 = "", const string& TxtPv2 = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtSup;
		string TxtTpl;
		string TxtAv1;
		string TxtPv1;
		string TxtAv2;
		string TxtPv2;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDtpDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtAv1Alt = false, const bool TxtPv1Alt = false, const bool TxtAv2Alt = false, const bool TxtPv2Alt = false);
	};

	/**
		* StatShr (full: StatShrPlnrDtpDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFAV1VALID = 1;
		static const uint TXFPV1VALID = 2;
		static const uint TXFAV2VALID = 3;
		static const uint TXFPV2VALID = 4;
		static const uint BUTSAVEAVAIL = 5;
		static const uint BUTSAVEACTIVE = 6;
		static const uint BUTDSNVIEWAVAIL = 7;

	public:
		StatShr(const bool TxfAv1Valid = false, const bool TxfPv1Valid = false, const bool TxfAv2Valid = false, const bool TxfPv2Valid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true);

	public:
		bool TxfAv1Valid;
		bool TxfPv1Valid;
		bool TxfAv2Valid;
		bool TxfPv2Valid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDtpDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDtpDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDtpDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDtpDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPATY = 4;
		static const uint FEEDFPUPMTY = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;
		static const uint ALL = 9;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFPupAty = NULL, Feed* feedFPupMty = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAty;
		Feed feedFPupMty;
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
	PnlPlnrDtpDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDtpDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupAty;
	Feed feedFPupMty;

	PlnrMDevice recDev;
	PlnrJMDeviceModtype recDevJmod;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshTxtAv1(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtPv1(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtAv2(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtPv2(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecDev(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecDevJmod(DbsPlnr* dbsplnr, set<uint>& moditems);

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

	bool handleCallPlnrDevUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrDevJmodMod_devEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


