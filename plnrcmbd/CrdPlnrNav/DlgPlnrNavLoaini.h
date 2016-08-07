/**
  * \file DlgPlnrNavLoaini.h
  * job handler for job DlgPlnrNavLoaini (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRNAVLOAINI_H
#define DLGPLNRNAVLOAINI_H

// IP custInclude --- IBEGIN
#include <sys/types.h>
#include <dirent.h>
// IP custInclude --- IEND

#include "IexPlnrIni.h"

/**
  * DlgPlnrNavLoaini
  */
class DlgPlnrNavLoaini : public JobPlnr {

public:
	/**
		* VecVDit (full: VecVDlgPlnrNavLoainiDit)
		*/
	class VecVDit {

	public:
		static const uint IFI = 1;
		static const uint IMP = 2;
		static const uint ACV = 3;
		static const uint PPR = 4;
		static const uint LFI = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static string getTitle(const uint ix, const uint ixPlnrVLocale);

		static void fillFeed(const uint ixPlnrVLocale, Feed& feed);
	};

	/**
		* VecVDo (full: VecVDlgPlnrNavLoainiDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoImp (full: VecVDlgPlnrNavLoainiDoImp)
		*/
	class VecVDoImp {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVDoPpr (full: VecVDlgPlnrNavLoainiDoPpr)
		*/
	class VecVDoPpr {

	public:
		static const uint BUTRUNCLICK = 1;
		static const uint BUTSTOCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVDlgPlnrNavLoainiSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRSIDLE = 2;
		static const uint PARSE = 3;
		static const uint ALRPLNRPER = 4;
		static const uint PRSDONE = 5;
		static const uint IMPIDLE = 6;
		static const uint IMPORT = 7;
		static const uint IMPDONE = 8;
		static const uint UPKIDLE = 9;
		static const uint UNPACK = 10;
		static const uint UPKDONE = 11;
		static const uint POSTPRC = 12;
		static const uint DONE = 13;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgPlnrNavLoaini)
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
	  * ContInf (full: ContInfDlgPlnrNavLoaini)
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
	  * ContInfImp (full: ContInfDlgPlnrNavLoainiImp)
	  */
	class ContInfImp : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfImp(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfImp* comp);
		set<uint> diff(const ContInfImp* comp);
	};

	/**
	  * ContInfPpr (full: ContInfDlgPlnrNavLoainiPpr)
	  */
	class ContInfPpr : public Block {

	public:
		static const uint TXTPRG = 1;

	public:
		ContInfPpr(const string& TxtPrg = "");

	public:
		string TxtPrg;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInfPpr* comp);
		set<uint> diff(const ContInfPpr* comp);
	};

	/**
		* StatApp (full: StatAppDlgPlnrNavLoaini)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdone = false, const string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgPlnrNavLoaini)
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
		* StatShrAcv (full: StatShrDlgPlnrNavLoainiAcv)
		*/
	class StatShrAcv : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrAcv(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrAcv* comp);
		set<uint> diff(const StatShrAcv* comp);
	};

	/**
		* StatShrIfi (full: StatShrDlgPlnrNavLoainiIfi)
		*/
	class StatShrIfi : public Block {

	public:
		static const uint ULDACTIVE = 1;

	public:
		StatShrIfi(const bool UldActive = true);

	public:
		bool UldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrIfi* comp);
		set<uint> diff(const StatShrIfi* comp);
	};

	/**
		* StatShrImp (full: StatShrDlgPlnrNavLoainiImp)
		*/
	class StatShrImp : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrImp(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrImp* comp);
		set<uint> diff(const StatShrImp* comp);
	};

	/**
		* StatShrLfi (full: StatShrDlgPlnrNavLoainiLfi)
		*/
	class StatShrLfi : public Block {

	public:
		static const uint DLDACTIVE = 1;

	public:
		StatShrLfi(const bool DldActive = true);

	public:
		bool DldActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrLfi* comp);
		set<uint> diff(const StatShrLfi* comp);
	};

	/**
		* StatShrPpr (full: StatShrDlgPlnrNavLoainiPpr)
		*/
	class StatShrPpr : public Block {

	public:
		static const uint BUTRUNACTIVE = 1;
		static const uint BUTSTOACTIVE = 2;

	public:
		StatShrPpr(const bool ButRunActive = true, const bool ButStoActive = true);

	public:
		bool ButRunActive;
		bool ButStoActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShrPpr* comp);
		set<uint> diff(const StatShrPpr* comp);
	};

	/**
		* Tag (full: TagDlgPlnrNavLoaini)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagAcv (full: TagDlgPlnrNavLoainiAcv)
		*/
	class TagAcv {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagIfi (full: TagDlgPlnrNavLoainiIfi)
		*/
	class TagIfi {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagImp (full: TagDlgPlnrNavLoainiImp)
		*/
	class TagImp {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagLfi (full: TagDlgPlnrNavLoainiLfi)
		*/
	class TagLfi {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* TagPpr (full: TagDlgPlnrNavLoainiPpr)
		*/
	class TagPpr {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgPlnrNavLoainiData)
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
		* DpchAppDo (full: DpchAppDlgPlnrNavLoainiDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint IXVDO = 2;
		static const uint IXVDOIMP = 3;
		static const uint IXVDOPPR = 4;

	public:
		DpchAppDo();

	public:
		uint ixVDo;
		uint ixVDoImp;
		uint ixVDoPpr;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgPlnrNavLoainiData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint CONTINFIMP = 4;
		static const uint CONTINFPPR = 5;
		static const uint FEEDFDSE = 6;
		static const uint FEEDFSGE = 7;
		static const uint STATAPP = 8;
		static const uint STATSHR = 9;
		static const uint STATSHRACV = 10;
		static const uint STATSHRIFI = 11;
		static const uint STATSHRIMP = 12;
		static const uint STATSHRLFI = 13;
		static const uint STATSHRPPR = 14;
		static const uint TAG = 15;
		static const uint TAGACV = 16;
		static const uint TAGIFI = 17;
		static const uint TAGIMP = 18;
		static const uint TAGLFI = 19;
		static const uint TAGPPR = 20;
		static const uint ALL = 21;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, ContInfImp* continfimp = NULL, ContInfPpr* continfppr = NULL, Feed* feedFDse = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, StatShrAcv* statshracv = NULL, StatShrIfi* statshrifi = NULL, StatShrImp* statshrimp = NULL, StatShrLfi* statshrlfi = NULL, StatShrPpr* statshrppr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		ContInfImp continfimp;
		ContInfPpr continfppr;
		Feed feedFDse;
		Feed feedFSge;
		StatShr statshr;
		StatShrAcv statshracv;
		StatShrIfi statshrifi;
		StatShrImp statshrimp;
		StatShrLfi statshrlfi;
		StatShrPpr statshrppr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalIfiUldActive(DbsPlnr* dbsplnr);
	bool evalImpButRunActive(DbsPlnr* dbsplnr);
	bool evalImpButStoActive(DbsPlnr* dbsplnr);
	bool evalAcvUldActive(DbsPlnr* dbsplnr);
	bool evalPprButRunActive(DbsPlnr* dbsplnr);
	bool evalPprButStoActive(DbsPlnr* dbsplnr);
	bool evalLfiDldActive(DbsPlnr* dbsplnr);
	bool evalButDneActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	DlgPlnrNavLoaini(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~DlgPlnrNavLoaini();

public:
	ContIac contiac;
	ContInf continf;
	ContInfImp continfimp;
	ContInfPpr continfppr;
	StatShr statshr;
	StatShrAcv statshracv;
	StatShrIfi statshrifi;
	StatShrImp statshrimp;
	StatShrLfi statshrlfi;
	StatShrPpr statshrppr;

	Feed feedFMcbAlert;
	Feed feedFDse;
	Feed feedFSge;

	IexPlnrIni* iex;

	uint ixVDit;

	bool muteRefresh;

// IP custVar --- IBEGIN
	string infilename;
// IP custVar --- IEND

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshIfi(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshImp(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshAcv(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshPpr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLfi(DbsPlnr* dbsplnr, set<uint>& moditems);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsPlnr* dbsplnr, uint _ixVSge, DpchEngPlnr** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsPlnr* dbsplnr);
	void leaveSgeIdle(DbsPlnr* dbsplnr);
	uint enterSgePrsidle(DbsPlnr* dbsplnr);
	void leaveSgePrsidle(DbsPlnr* dbsplnr);
	uint enterSgeParse(DbsPlnr* dbsplnr);
	void leaveSgeParse(DbsPlnr* dbsplnr);
	uint enterSgeAlrplnrper(DbsPlnr* dbsplnr);
	void leaveSgeAlrplnrper(DbsPlnr* dbsplnr);
	uint enterSgePrsdone(DbsPlnr* dbsplnr);
	void leaveSgePrsdone(DbsPlnr* dbsplnr);
	uint enterSgeImpidle(DbsPlnr* dbsplnr);
	void leaveSgeImpidle(DbsPlnr* dbsplnr);
	uint enterSgeImport(DbsPlnr* dbsplnr);
	void leaveSgeImport(DbsPlnr* dbsplnr);
	uint enterSgeImpdone(DbsPlnr* dbsplnr);
	void leaveSgeImpdone(DbsPlnr* dbsplnr);
	uint enterSgeUpkidle(DbsPlnr* dbsplnr);
	void leaveSgeUpkidle(DbsPlnr* dbsplnr);
	uint enterSgeUnpack(DbsPlnr* dbsplnr);
	void leaveSgeUnpack(DbsPlnr* dbsplnr);
	uint enterSgeUpkdone(DbsPlnr* dbsplnr);
	void leaveSgeUpkdone(DbsPlnr* dbsplnr);
	uint enterSgePostprc(DbsPlnr* dbsplnr);
	void leaveSgePostprc(DbsPlnr* dbsplnr);
	uint enterSgeDone(DbsPlnr* dbsplnr);
	void leaveSgeDone(DbsPlnr* dbsplnr);

// IP getSquawk --- BEGIN
	string getSquawk(DbsPlnr* dbsplnr);
// IP getSquawk --- END

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButDneClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

	void handleDpchAppDoImpButRunClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoImpButStoClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

	void handleDpchAppDoPprButRunClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoPprButStoClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppPlnrAlert(DbsPlnr* dbsplnr, DpchAppPlnrAlert* dpchappplnralert, DpchEngPlnr** dpcheng);

// IP handleUpload --- BEGIN
	void handleUpload(DbsPlnr* dbsplnr, const string& filename);
// IP handleUpload --- END
// IP handleDownload --- BEGIN
	string handleDownload(DbsPlnr* dbsplnr);
// IP handleDownload --- END
// IP handleTimer --- BEGIN
	void handleTimer(DbsPlnr* dbsplnr, const string& sref);
// IP handleTimer --- END

};

#endif


