/**
  * \file DlgPlnrClcUsecase.h
  * job handler for job DlgPlnrClcUsecase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRCLCUSECASE_H
#define DLGPLNRCLCUSECASE_H

// IP custInclude --- INSERT

#include "JobPlnrClcDisptest.h"
#include "JobPlnrClcQcdslab.h"

/**
  * DlgPlnrClcUsecase
  */
class DlgPlnrClcUsecase : public JobPlnr {

public:
	/**
		* VecVDit (full: VecVDlgPlnrClcUsecaseDit)
		*/
	class VecVDit {

	public:
		static const uint PRP = 1;
		static const uint CAL = 2;
		static const uint RFI = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixPlnrVLocale);

		static void fillFeed(const uint ixPlnrVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgPlnrClcUsecaseDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoCal (full: VecVDlgPlnrClcUsecaseDoCal)
		*/
	class VecVDoCal {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPrp (full: VecVDlgPlnrClcUsecaseDoPrp)
		*/
	class VecVDoPrp {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgPlnrClcUsecaseSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREATE = 2;
		static const uint CREDONE = 3;
		static const uint RUN = 4;
		static const uint DONE = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* VecVUcs (full: VecVDlgPlnrClcUsecaseUcs)
		*/
	class VecVUcs {

	public:
		static const uint DISPTEST = 1;
		static const uint QCDSLAB = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgPlnrClcUsecase)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFDSE = 1;

	public:
		ContIac(const uint numFDse = 1);

	public:
		uint numFDse;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacPrp (full: ContIacDlgPlnrClcUsecasePrp)
	  */
	class ContIacPrp : public Block {

	public:
		static const uint TXFPTI = 1;
		static const uint NUMFPUPUCS = 2;

	public:
		ContIacPrp(const string& TxfPti = "", const uint numFPupUcs = 1);

	public:
		string TxfPti;
		uint numFPupUcs;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIacPrp* comp);
		set<uint> diff(const ContIacPrp* comp);
	};

	/**
	  * ContInf (full: ContInfDlgPlnrClcUsecase)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;

	public:
		ContInf(const uint numFSge = 1);

	public:
		uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * ContInfCal (full: ContInfDlgPlnrClcUsecaseCal)
	  */
	class ContInfCal : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfCal(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfCal* comp);
		set<uint> diff(const ContInfCal* comp);
	};

	/**
		* StatApp (full: StatAppDlgPlnrClcUsecase)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgPlnrClcUsecase)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTDNEACTIVE = 1;

	public:
		StatShr(const bool ButDneActive = true);

	public:
		bool ButDneActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StatShrCal (full: StatShrDlgPlnrClcUsecaseCal)
		*/
	class StatShrCal : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrCal(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrCal* comp);
		set<uint> diff(const StatShrCal* comp);
	};

	/**
		* StatShrPrp (full: StatShrDlgPlnrClcUsecasePrp)
		*/
	class StatShrPrp : public Block {

	public:
		static const uint BUTCREACTIVE = 1;

	public:
		StatShrPrp(const bool ButCreActive = true);

	public:
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrPrp* comp);
		set<uint> diff(const StatShrPrp* comp);
	};

	/**
		* StatShrRfi (full: StatShrDlgPlnrClcUsecaseRfi)
		*/
	class StatShrRfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrRfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrRfi* comp);
		set<uint> diff(const StatShrRfi* comp);
	};

	/**
		* Tag (full: TagDlgPlnrClcUsecase)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagCal (full: TagDlgPlnrClcUsecaseCal)
		*/
	class TagCal {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagPrp (full: TagDlgPlnrClcUsecasePrp)
		*/
	class TagPrp {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagRfi (full: TagDlgPlnrClcUsecaseRfi)
		*/
	class TagRfi {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgPlnrClcUsecaseData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACPRP = 3;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		ContIacPrp contiacprp;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgPlnrClcUsecaseDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOCAL = 3;
		static const uint IXVDOPRP = 4;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoCal;
		uint ixVDoPrp;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgPlnrClcUsecaseData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACPRP = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFCAL = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFPRPPUPUCS = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRCAL = 11;
		static const uint STATSHRPRP = 12;
		static const uint STATSHRRFI = 13;
		static const uint TAG = 14;
		static const uint TAGCAL = 15;
		static const uint TAGPRP = 16;
		static const uint TAGRFI = 17;
		static const uint ALL = 18;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContIacPrp* contiacprp = NULL, ContInf* continf = NULL, ContInfCal* continfcal = NULL, Feed* feedFDse = NULL, Feed* feedFPrpPupUcs = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCal* statshrcal = NULL, StatShrPrp* statshrprp = NULL, StatShrRfi* statshrrfi = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacPrp contiacprp;
		ContInf continf;
		ContInfCal continfcal;
		Feed feedFDse;
		Feed feedFPrpPupUcs;
		Feed feedFSge;
		StatShr statshr;
		StatShrCal statshrcal;
		StatShrPrp statshrprp;
		StatShrRfi statshrrfi;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPrpButCreActive(DbsPlnr* dbsplnr);
	bool evalCalButRunActive(DbsPlnr* dbsplnr);
	bool evalCalButStoActive(DbsPlnr* dbsplnr);
	bool evalRfiDldActive(DbsPlnr* dbsplnr);
	bool evalButDneActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	DlgPlnrClcUsecase(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~DlgPlnrClcUsecase();

public:
	ContIac contiac;
	ContIacPrp contiacprp;
	ContInf continf;
	ContInfCal continfcal;
	StatShr statshr;
	StatShrCal statshrcal;
	StatShrPrp statshrprp;
	StatShrRfi statshrrfi;

	Feed feedFDse;
	Feed feedFPrpPupUcs;
	Feed feedFSge;

	JobPlnrClcDisptest* jobdisptest;
	JobPlnrClcQcdslab* jobqcdslab;

	uint ixVDit;

	bool muteRefresh;

// IP custVar --- IBEGIN
	uint ixVUcs;

	bool valid;
// IP custVar --- IEND

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshPrp(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshCal(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRfi(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsPlnr* dbsplnr, uint _ixVSge, DpchEngPlnr** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsPlnr* dbsplnr);
	void leaveSgeIdle(DbsPlnr* dbsplnr);
	uint enterSgeCreate(DbsPlnr* dbsplnr);
	void leaveSgeCreate(DbsPlnr* dbsplnr);
	uint enterSgeCredone(DbsPlnr* dbsplnr);
	void leaveSgeCredone(DbsPlnr* dbsplnr);
	uint enterSgeRun(DbsPlnr* dbsplnr);
	void leaveSgeRun(DbsPlnr* dbsplnr);
	uint enterSgeDone(DbsPlnr* dbsplnr);
	void leaveSgeDone(DbsPlnr* dbsplnr);

// IP getSquawk --- BEGIN
	string getSquawk(DbsPlnr* dbsplnr);
// IP getSquawk --- END

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiacprp(DbsPlnr* dbsplnr, ContIacPrp* _contiacprp, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButDneClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

	void handleDpchAppDoCalButRunClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoCalButStoClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

	void handleDpchAppDoPrpButCreClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleDownload --- BEGIN
	string handleDownload(DbsPlnr* dbsplnr);
// IP handleDownload --- END
// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrStatChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
};

#endif


