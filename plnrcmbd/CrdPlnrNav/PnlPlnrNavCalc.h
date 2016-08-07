/**
  * \file PnlPlnrNavCalc.h
  * job handler for job PnlPlnrNavCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVCALC_H
#define PNLPLNRNAVCALC_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavCalc
  */
class PnlPlnrNavCalc : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavCalcDo)
		*/
	class VecVDo {

	public:
		static const uint BUTCLCVIEWCLICK = 1;
		static const uint BUTCLCNEWCRDCLICK = 2;
		static const uint BUTCLIVIEWCLICK = 3;
		static const uint BUTCLINEWCRDCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavCalc)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTCLC = 1;
		static const uint NUMFLSTCLI = 2;

	public:
		ContIac(const uint numFLstClc = 1, const uint numFLstCli = 1);

	public:
		uint numFLstClc;
		uint numFLstCli;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppPlnrNavCalc)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstClcAlt = true, const bool LstCliAlt = true, const uint LstClcNumFirstdisp = 1, const uint LstCliNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrNavCalc)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTCLCAVAIL = 1;
		static const uint BUTCLCVIEWACTIVE = 2;
		static const uint BUTCLCNEWCRDACTIVE = 3;
		static const uint LSTCLIAVAIL = 4;
		static const uint BUTCLIVIEWACTIVE = 5;
		static const uint BUTCLINEWCRDACTIVE = 6;

	public:
		StatShr(const bool LstClcAvail = true, const bool ButClcViewActive = true, const bool ButClcNewcrdActive = true, const bool LstCliAvail = true, const bool ButCliViewActive = true, const bool ButCliNewcrdActive = true);

	public:
		bool LstClcAvail;
		bool ButClcViewActive;
		bool ButClcNewcrdActive;
		bool LstCliAvail;
		bool ButCliViewActive;
		bool ButCliNewcrdActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNavCalc)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavCalcData)
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
		* DpchAppDo (full: DpchAppPlnrNavCalcDo)
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
		* DpchEngData (full: DpchEngPlnrNavCalcData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTCLC = 3;
		static const uint FEEDFLSTCLI = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;
		static const uint ALL = 8;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstClc = NULL, Feed* feedFLstCli = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstClc;
		Feed feedFLstCli;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstClcAvail(DbsPlnr* dbsplnr);
	bool evalButClcViewActive(DbsPlnr* dbsplnr);
	bool evalButClcNewcrdActive(DbsPlnr* dbsplnr);
	bool evalLstCliAvail(DbsPlnr* dbsplnr);
	bool evalButCliViewActive(DbsPlnr* dbsplnr);
	bool evalButCliNewcrdActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavCalc(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavCalc();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstClc;
	Feed feedFLstCli;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshLstClc(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshClc(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstCli(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshCli(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButClcViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButClcNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCliViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButCliNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrHusrRunvMod_crdUsrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


