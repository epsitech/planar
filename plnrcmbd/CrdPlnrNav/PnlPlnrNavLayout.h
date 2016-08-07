/**
  * \file PnlPlnrNavLayout.h
  * job handler for job PnlPlnrNavLayout (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVLAYOUT_H
#define PNLPLNRNAVLAYOUT_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavLayout
  */
class PnlPlnrNavLayout : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavLayoutDo)
		*/
	class VecVDo {

	public:
		static const uint BUTTPOVIEWCLICK = 1;
		static const uint BUTTPONEWCRDCLICK = 2;
		static const uint BUTARRVIEWCLICK = 3;
		static const uint BUTARIVIEWCLICK = 4;
		static const uint BUTRTCVIEWCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavLayout)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTTPO = 1;
		static const uint NUMFLSTARR = 2;
		static const uint NUMFLSTARI = 3;
		static const uint NUMFLSTRTC = 4;

	public:
		ContIac(const uint numFLstTpo = 1, const uint numFLstArr = 1, const uint numFLstAri = 1, const uint numFLstRtc = 1);

	public:
		uint numFLstTpo;
		uint numFLstArr;
		uint numFLstAri;
		uint numFLstRtc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppPlnrNavLayout)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstTpoAlt = true, const bool LstArrAlt = true, const bool LstAriAlt = true, const bool LstRtcAlt = true, const uint LstTpoNumFirstdisp = 1, const uint LstArrNumFirstdisp = 1, const uint LstAriNumFirstdisp = 1, const uint LstRtcNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrPlnrNavLayout)
		*/
	class StatShr : public Block {

	public:
		static const uint LSTTPOAVAIL = 1;
		static const uint BUTTPOVIEWACTIVE = 2;
		static const uint LSTARRAVAIL = 3;
		static const uint BUTARRVIEWACTIVE = 4;
		static const uint LSTARIAVAIL = 5;
		static const uint BUTARIVIEWACTIVE = 6;
		static const uint LSTRTCAVAIL = 7;
		static const uint BUTRTCVIEWACTIVE = 8;

	public:
		StatShr(const bool LstTpoAvail = true, const bool ButTpoViewActive = true, const bool LstArrAvail = true, const bool ButArrViewActive = true, const bool LstAriAvail = true, const bool ButAriViewActive = true, const bool LstRtcAvail = true, const bool ButRtcViewActive = true);

	public:
		bool LstTpoAvail;
		bool ButTpoViewActive;
		bool LstArrAvail;
		bool ButArrViewActive;
		bool LstAriAvail;
		bool ButAriViewActive;
		bool LstRtcAvail;
		bool ButRtcViewActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNavLayout)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavLayoutData)
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
		* DpchAppDo (full: DpchAppPlnrNavLayoutDo)
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
		* DpchEngData (full: DpchEngPlnrNavLayoutData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTARI = 3;
		static const uint FEEDFLSTARR = 4;
		static const uint FEEDFLSTRTC = 5;
		static const uint FEEDFLSTTPO = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;
		static const uint ALL = 10;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, Feed* feedFLstAri = NULL, Feed* feedFLstArr = NULL, Feed* feedFLstRtc = NULL, Feed* feedFLstTpo = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		Feed feedFLstAri;
		Feed feedFLstArr;
		Feed feedFLstRtc;
		Feed feedFLstTpo;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalLstTpoAvail(DbsPlnr* dbsplnr);
	bool evalButTpoViewActive(DbsPlnr* dbsplnr);
	bool evalLstArrAvail(DbsPlnr* dbsplnr);
	bool evalButArrViewActive(DbsPlnr* dbsplnr);
	bool evalLstAriAvail(DbsPlnr* dbsplnr);
	bool evalButAriViewActive(DbsPlnr* dbsplnr);
	bool evalLstRtcAvail(DbsPlnr* dbsplnr);
	bool evalButRtcViewActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavLayout(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavLayout();

public:
	ContIac contiac;
	StatShr statshr;

	Feed feedFLstAri;
	Feed feedFLstArr;
	Feed feedFLstRtc;
	Feed feedFLstTpo;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refreshLstTpo(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshTpo(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstArr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshArr(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstAri(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshAri(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshLstRtc(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refreshRtc(DbsPlnr* dbsplnr, set<uint>& moditems);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButTpoViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButTpoNewcrdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButArrViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButAriViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRtcViewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrHusrRunvMod_crdUsrEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


