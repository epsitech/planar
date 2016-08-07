/**
  * \file PnlPlnrDgdDetail.h
  * job handler for job PnlPlnrDgdDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDGDDETAIL_H
#define PNLPLNRDGDDETAIL_H

// IP custInclude --- INSERT

/**
  * PnlPlnrDgdDetail
  */
class PnlPlnrDgdDetail : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDgdDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDgdDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint TXFLVL = 2;
		static const uint TXFAV1 = 3;
		static const uint TXFAV2 = 4;
		static const uint TXFAL1 = 5;
		static const uint TXFAL2 = 6;
		static const uint TXFAGD = 7;
		static const uint TXFD = 8;
		static const uint TXFDPH = 9;

	public:
		ContIac(const uint numFPupTyp = 1, const string& TxfLvl = "", const string& TxfAv1 = "", const string& TxfAv2 = "", const string& TxfAl1 = "", const string& TxfAl2 = "", const string& TxfAgd = "", const string& TxfD = "", const string& TxfDph = "");

	public:
		uint numFPupTyp;
		string TxfLvl;
		string TxfAv1;
		string TxfAv2;
		string TxfAl1;
		string TxfAl2;
		string TxfAgd;
		string TxfD;
		string TxfDph;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDgdDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTLVL = 3;
		static const uint TXTAV1 = 4;
		static const uint TXTAV2 = 5;
		static const uint TXTAL1 = 6;
		static const uint TXTAL2 = 7;
		static const uint TXTAGD = 8;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtLvl = "", const string& TxtAv1 = "", const string& TxtAv2 = "", const string& TxtAl1 = "", const string& TxtAl2 = "", const string& TxtAgd = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtLvl;
		string TxtAv1;
		string TxtAv2;
		string TxtAl1;
		string TxtAl2;
		string TxtAgd;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDgdDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtLvlAlt = false, const bool TxtAv1Alt = false, const bool TxtAv2Alt = false, const bool TxtAl1Alt = false, const bool TxtAl2Alt = false, const bool TxtAgdAlt = false);
	};

	/**
		* StatShr (full: StatShrPlnrDgdDetail)
		*/
	class StatShr : public Block {

	public:
		static const uint TXFLVLVALID = 1;
		static const uint TXFAV1VALID = 2;
		static const uint TXFAV2VALID = 3;
		static const uint TXFAL1VALID = 4;
		static const uint TXFAL2VALID = 5;
		static const uint TXFAGDVALID = 6;
		static const uint BUTSAVEAVAIL = 7;
		static const uint BUTSAVEACTIVE = 8;
		static const uint BUTDSNVIEWAVAIL = 9;

	public:
		StatShr(const bool TxfLvlValid = false, const bool TxfAv1Valid = false, const bool TxfAv2Valid = false, const bool TxfAl1Valid = false, const bool TxfAl2Valid = false, const bool TxfAgdValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true);

	public:
		bool TxfLvlValid;
		bool TxfAv1Valid;
		bool TxfAv2Valid;
		bool TxfAl1Valid;
		bool TxfAl2Valid;
		bool TxfAgdValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDgdDetail)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDgdDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDgdDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDgdDetailData)
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
	PnlPlnrDgdDetail(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDgdDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Feed feedFPupTyp;

	PlnrMDomaingd recDgd;
	PlnrJMDomaingd recDgdJ;
	bool dirty;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshTxtLvl(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtAv1(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtAv2(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtAl1(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtAl2(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTxtAgd(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refreshRecDgd(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRecDgdJ(DbsPlnr* dbsplnr, set<uint>& moditems);

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

	bool handleCallPlnrDgdUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
	bool handleCallPlnrDgdJMod_dgdEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


