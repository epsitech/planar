/**
  * \file PnlPlnrNavDesign.h
  * job handler for job PnlPlnrNavDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVDESIGN_H
#define PNLPLNRNAVDESIGN_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavDesign
  */
class PnlPlnrNavDesign : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavDesignDo)
		*/
	class VecVDo {

	public:
		static const uint BUTPRJVIEWCLICK = 1;
		static const uint BUTPRJNEWCRDCLICK = 2;
		static const uint BUTDSNVIEWCLICK = 3;
		static const uint BUTDSNNEWCRDCLICK = 4;
		static const uint BUTDOMVIEWCLICK = 5;
		static const uint BUTDOMNEWCRDCLICK = 6;
		static const uint BUTDGDVIEWCLICK = 7;
		static const uint BUTDGDNEWCRDCLICK = 8;
		static const uint BUTDVCVIEWCLICK = 9;
		static const uint BUTDVCNEWCRDCLICK = 10;
		static const uint BUTSRUVIEWCLICK = 11;
		static const uint BUTSRUNEWCRDCLICK = 12;
		static const uint BUTSTKVIEWCLICK = 13;
		static const uint BUTSTKNEWCRDCLICK = 14;
		static const uint BUTLYRVIEWCLICK = 15;
		static const uint BUTLYRNEWCRDCLICK = 16;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavDesign)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTPRJ = 1;
		static const uint NUMFLSTDSN = 2;
		static const uint NUMFLSTDOM = 3;
		static const uint NUMFLSTDGD = 4;
		static const uint NUMFLSTDVC = 5;
		static const uint NUMFLSTSRU = 6;
		static const uint NUMFLSTSTK = 7;
		static const uint NUMFLSTLYR = 8;

	public:
		ContIac(const uint numFLstPrj = 1, const uint numFLstDsn = 1, const uint numFLstDom = 1, const uint numFLstDgd = 1, const uint numFLstDvc = 1, const uint numFLstSru = 1, const uint numFLstStk = 1, const uint numFLstLyr = 1);

	public:
		uint numFLstPrj;
		uint numFLstDsn;
		uint numFLstDom;
		uint numFLstDgd;
		uint numFLstDvc;
		uint numFLstSru;
		uint numFLstStk;
		uint numFLstLyr;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppPlnrNavDesign)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstPrjAlt = true, const bool LstDsnAlt = true, const bool LstDomAlt = true, const bool LstDgdAlt = true, const bool LstDvcAlt = true, const bool LstSruAlt = true, const bool LstStkAlt = true, const bool LstLyrAlt = true, const uint LstPrjNumFirstdisp = 1, const uint LstDsnNumFirstdisp = 1, const uint LstDomNumFirstdisp = 1, const uint LstDgdNumFirstdisp = 1, const uint LstDvcNumFirstdisp = 1, const uint LstSruNumFirstdisp = 1, const uint LstStkNumFirstdisp = 1, const uint LstLyrNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrNavDesign)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTPRJAVAIL = 1;
		static const uint BUTPRJVIEWACTIVE = 2;
		static const uint LSTDSNAVAIL = 3;
		static const uint BUTDSNVIEWACTIVE = 4;
		static const uint LSTDOMAVAIL = 5;
		static const uint BUTDOMVIEWACTIVE = 6;
		static const uint BUTDOMNEWCRDACTIVE = 7;
		static const uint LSTDGDAVAIL = 8;
		static const uint BUTDGDVIEWACTIVE = 9;
		static const uint BUTDGDNEWCRDACTIVE = 10;
		static const uint LSTDVCAVAIL = 11;
		static const uint BUTDVCVIEWACTIVE = 12;
		static const uint BUTDVCNEWCRDACTIVE = 13;
		static const uint LSTSRUAVAIL = 14;
		static const uint BUTSRUVIEWACTIVE = 15;
		static const uint BUTSRUNEWCRDACTIVE = 16;
		static const uint LSTSTKAVAIL = 17;
		static const uint BUTSTKVIEWACTIVE = 18;
		static const uint BUTSTKNEWCRDACTIVE = 19;
		static const uint LSTLYRAVAIL = 20;
		static const uint BUTLYRVIEWACTIVE = 21;
		static const uint BUTLYRNEWCRDACTIVE = 22;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstDsnAvail = true, const bool ButDsnViewActive = true, const bool LstDomAvail = true, const bool ButDomViewActive = true, const bool ButDomNewcrdActive = true, const bool LstDgdAvail = true, const bool ButDgdViewActive = true, const bool ButDgdNewcrdActive = true, const bool LstDvcAvail = true, const bool ButDvcViewActive = true, const bool ButDvcNewcrdActive = true, const bool LstSruAvail = true, const bool ButSruViewActive = true, const bool ButSruNewcrdActive = true, const bool LstStkAvail = true, const bool ButStkViewActive = true, const bool ButStkNewcrdActive = true, const bool LstLyrAvail = true, const bool ButLyrViewActive = true, const bool ButLyrNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstDsnAvail;
		bool ButDsnViewActive;
		bool LstDomAvail;
		bool ButDomViewActive;
		bool ButDomNewcrdActive;
		bool LstDgdAvail;
		bool ButDgdViewActive;
		bool ButDgdNewcrdActive;
		bool LstDvcAvail;
		bool ButDvcViewActive;
		bool ButDvcNewcrdActive;
		bool LstSruAvail;
		bool ButSruViewActive;
		bool ButSruNewcrdActive;
		bool LstStkAvail;
		bool ButStkViewActive;
		bool ButStkNewcrdActive;
		bool LstLyrAvail;
		bool ButLyrViewActive;
		bool ButLyrNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNavDesign)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavDesignData)
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
		* DpchAppDo (full: DpchAppPlnrNavDesignDo)
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
		* DpchEngData (full: DpchEngPlnrNavDesignData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTDGD = 3;
		static const uint FEEDFLSTDOM = 4;
		static const uint FEEDFLSTDSN = 5;
		static const uint FEEDFLSTDVC = 6;
		static const uint FEEDFLSTLYR = 7;
		static const uint FEEDFLSTPRJ = 8;
		static const uint FEEDFLSTSRU = 9;
		static const uint FEEDFLSTSTK = 10;
		static const uint STATAPP = 11;
		static const uint STATSHR = 12;
		static const uint TAG = 13;
		static const uint ALL = 14;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstDgd = NULL, Feed* feedFLstDom = NULL, Feed* feedFLstDsn = NULL, Feed* feedFLstDvc = NULL, Feed* feedFLstLyr = NULL, Feed* feedFLstPrj = NULL, Feed* feedFLstSru = NULL, Feed* feedFLstStk = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstDgd;
		Feed feedFLstDom;
		Feed feedFLstDsn;
		Feed feedFLstDvc;
		Feed feedFLstLyr;
		Feed feedFLstPrj;
		Feed feedFLstSru;
		Feed feedFLstStk;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstPrjAvail(DbsPlnr* dbsplnr);
	bool evalButPrjViewActive(DbsPlnr* dbsplnr);
	bool evalLstDsnAvail(DbsPlnr* dbsplnr);
	bool evalButDsnViewActive(DbsPlnr* dbsplnr);
	bool evalLstDomAvail(DbsPlnr* dbsplnr);
	bool evalButDomViewActive(DbsPlnr* dbsplnr);
	bool evalButDomNewcrdActive(DbsPlnr* dbsplnr);
	bool evalLstDgdAvail(DbsPlnr* dbsplnr);
	bool evalButDgdViewActive(DbsPlnr* dbsplnr);
	bool evalButDgdNewcrdActive(DbsPlnr* dbsplnr);
	bool evalLstDvcAvail(DbsPlnr* dbsplnr);
	bool evalButDvcViewActive(DbsPlnr* dbsplnr);
	bool evalButDvcNewcrdActive(DbsPlnr* dbsplnr);
	bool evalLstSruAvail(DbsPlnr* dbsplnr);
	bool evalButSruViewActive(DbsPlnr* dbsplnr);
	bool evalButSruNewcrdActive(DbsPlnr* dbsplnr);
	bool evalLstStkAvail(DbsPlnr* dbsplnr);
	bool evalButStkViewActive(DbsPlnr* dbsplnr);
	bool evalButStkNewcrdActive(DbsPlnr* dbsplnr);
	bool evalLstLyrAvail(DbsPlnr* dbsplnr);
	bool evalButLyrViewActive(DbsPlnr* dbsplnr);
	bool evalButLyrNewcrdActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavDesign(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavDesign();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstDgd;
	Feed feedFLstDom;
	Feed feedFLstDsn;
	Feed feedFLstDvc;
	Feed feedFLstLyr;
	Feed feedFLstPrj;
	Feed feedFLstSru;
	Feed feedFLstStk;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshLstPrj(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshPrj(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstDsn(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshDsn(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstDom(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshDom(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstDgd(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshDgd(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstDvc(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshDvc(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstSru(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshSru(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstStk(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshStk(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstLyr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLyr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButPrjViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButPrjNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDsnViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDsnNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDomViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDomNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDgdViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDgdNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDvcViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDvcNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButSruViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButSruNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButStkViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButStkNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButLyrViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButLyrNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrHusrRunvMod_crdUsrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


