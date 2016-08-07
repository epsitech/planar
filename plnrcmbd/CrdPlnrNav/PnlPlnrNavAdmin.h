/**
  * \file PnlPlnrNavAdmin.h
  * job handler for job PnlPlnrNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVADMIN_H
#define PNLPLNRNAVADMIN_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavAdmin
  */
class PnlPlnrNavAdmin : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTPRSVIEWCLICK = 5;
		static const uint BUTPRSNEWCRDCLICK = 6;
		static const uint BUTFILVIEWCLICK = 7;
		static const uint BUTFILNEWCRDCLICK = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTPRS = 3;
		static const uint NUMFLSTFIL = 4;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstPrs = 1, const uint numFLstFil = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstPrs;
		uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppPlnrNavAdmin)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrNavAdmin)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTPRSAVAIL = 5;
		static const uint BUTPRSVIEWACTIVE = 6;
		static const uint LSTFILAVAIL = 7;
		static const uint BUTFILVIEWACTIVE = 8;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNavAdmin)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavAdminData)
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
		* DpchAppDo (full: DpchAppPlnrNavAdminDo)
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
		* DpchEngData (full: DpchEngPlnrNavAdminData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTFIL = 3;
		static const uint FEEDFLSTPRS = 4;
		static const uint FEEDFLSTUSG = 5;
		static const uint FEEDFLSTUSR = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstFil = NULL, Feed* feedFLstPrs = NULL, Feed* feedFLstUsg = NULL, Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstFil;
		Feed feedFLstPrs;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsPlnr* dbsplnr);
	bool evalButUsgViewActive(DbsPlnr* dbsplnr);
	bool evalLstUsrAvail(DbsPlnr* dbsplnr);
	bool evalButUsrViewActive(DbsPlnr* dbsplnr);
	bool evalLstPrsAvail(DbsPlnr* dbsplnr);
	bool evalButPrsViewActive(DbsPlnr* dbsplnr);
	bool evalLstFilAvail(DbsPlnr* dbsplnr);
	bool evalButFilViewActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavAdmin(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstFil;
	Feed feedFLstPrs;
	Feed feedFLstUsg;
	Feed feedFLstUsr;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshLstUsg(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshUsg(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstUsr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshUsr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstPrs(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshPrs(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstFil(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshFil(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrHusrRunvMod_crdUsrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


