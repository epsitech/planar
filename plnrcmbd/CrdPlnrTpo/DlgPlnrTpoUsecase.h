/**
  * \file DlgPlnrTpoUsecase.h
  * job handler for job DlgPlnrTpoUsecase (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRTPOUSECASE_H
#define DLGPLNRTPOUSECASE_H

// IP custInclude --- INSERT

#include "JobPlnrTpoExamples.h"
#include "JobPlnrTpoIcabatch1.h"
#include "JobPlnrTpoIcabatch2.h"
#include "JobPlnrTpoIcabatch3.h"
#include "JobPlnrTpoUvslides.h"

/**
  * DlgPlnrTpoUsecase
  */
class DlgPlnrTpoUsecase : public JobPlnr {

public:
	/**
		* VecVDit (full: VecVDlgPlnrTpoUsecaseDit)
		*/
	class VecVDit {

	public:
		static const uint PRP = 1;
		static const uint GEN = 2;
		static const uint CFI = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixPlnrVLocale);

		static void fillFeed(const uint ixPlnrVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgPlnrTpoUsecaseDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoGen (full: VecVDlgPlnrTpoUsecaseDoGen)
		*/
	class VecVDoGen {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPrp (full: VecVDlgPlnrTpoUsecaseDoPrp)
		*/
	class VecVDoPrp {

	public:
		static const uint BUTCRECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgPlnrTpoUsecaseSge)
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
		* VecVUcs (full: VecVDlgPlnrTpoUsecaseUcs)
		*/
	class VecVUcs {

	public:
		static const uint EXAMPLES = 1;
		static const uint ICABATCH1 = 2;
		static const uint ICABATCH2 = 3;
		static const uint ICABATCH3 = 4;
		static const uint UVSLIDES = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgPlnrTpoUsecase)
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
	  * ContIacPrp (full: ContIacDlgPlnrTpoUsecasePrp)
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
	  * ContInf (full: ContInfDlgPlnrTpoUsecase)
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
	  * ContInfGen (full: ContInfDlgPlnrTpoUsecaseGen)
	  */
	class ContInfGen : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfGen(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfGen* comp);
		set<uint> diff(const ContInfGen* comp);
	};

	/**
		* StatApp (full: StatAppDlgPlnrTpoUsecase)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgPlnrTpoUsecase)
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
		* StatShrCfi (full: StatShrDlgPlnrTpoUsecaseCfi)
		*/
	class StatShrCfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrCfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrCfi* comp);
		set<uint> diff(const StatShrCfi* comp);
	};

	/**
		* StatShrGen (full: StatShrDlgPlnrTpoUsecaseGen)
		*/
	class StatShrGen : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrGen(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrGen* comp);
		set<uint> diff(const StatShrGen* comp);
	};

	/**
		* StatShrPrp (full: StatShrDlgPlnrTpoUsecasePrp)
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
		* Tag (full: TagDlgPlnrTpoUsecase)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagCfi (full: TagDlgPlnrTpoUsecaseCfi)
		*/
	class TagCfi {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagGen (full: TagDlgPlnrTpoUsecaseGen)
		*/
	class TagGen {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagPrp (full: TagDlgPlnrTpoUsecasePrp)
		*/
	class TagPrp {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgPlnrTpoUsecaseData)
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
		* DpchAppDo (full: DpchAppDlgPlnrTpoUsecaseDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOGEN = 3;
		static const uint IXVDOPRP = 4;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoGen;
		uint ixVDoPrp;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgPlnrTpoUsecaseData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTIACPRP = 3;
		static const uint CONTINF = 4;
		static const uint CONTINFGEN = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFPRPPUPUCS = 7;
		static const uint FEEDFSGE = 8;
		static const uint STATAPP = 9;
		static const uint STATSHR = 10;
		static const uint STATSHRCFI = 11;
		static const uint STATSHRGEN = 12;
		static const uint STATSHRPRP = 13;
		static const uint TAG = 14;
		static const uint TAGCFI = 15;
		static const uint TAGGEN = 16;
		static const uint TAGPRP = 17;
		static const uint ALL = 18;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContIacPrp* contiacprp = NULL, ContInf* continf = NULL, ContInfGen* continfgen = NULL, Feed* feedFDse = NULL, Feed* feedFPrpPupUcs = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrCfi* statshrcfi = NULL, StatShrGen* statshrgen = NULL, StatShrPrp* statshrprp = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContIacPrp contiacprp;
		ContInf continf;
		ContInfGen continfgen;
		Feed feedFDse;
		Feed feedFPrpPupUcs;
		Feed feedFSge;
		StatShr statshr;
		StatShrCfi statshrcfi;
		StatShrGen statshrgen;
		StatShrPrp statshrprp;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPrpButCreActive(DbsPlnr* dbsplnr);
	bool evalGenButRunActive(DbsPlnr* dbsplnr);
	bool evalGenButStoActive(DbsPlnr* dbsplnr);
	bool evalCfiDldActive(DbsPlnr* dbsplnr);
	bool evalButDneActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	DlgPlnrTpoUsecase(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~DlgPlnrTpoUsecase();

public:
	ContIac contiac;
	ContIacPrp contiacprp;
	ContInf continf;
	ContInfGen continfgen;
	StatShr statshr;
	StatShrCfi statshrcfi;
	StatShrGen statshrgen;
	StatShrPrp statshrprp;

	Feed feedFDse;
	Feed feedFPrpPupUcs;
	Feed feedFSge;

	JobPlnrTpoExamples* jobexamples;
	JobPlnrTpoIcabatch1* jobicabatch1;
	JobPlnrTpoIcabatch2* jobicabatch2;
	JobPlnrTpoIcabatch3* jobicabatch3;
	JobPlnrTpoUvslides* jobuvslides;

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
	void refreshGen(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshCfi(DbsPlnr* dbsplnr, set<uint>& moditems);

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

	void handleDpchAppDoGenButRunClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoGenButStoClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

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


