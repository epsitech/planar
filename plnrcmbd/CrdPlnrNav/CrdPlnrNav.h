/**
  * \file CrdPlnrNav.h
  * job handler for job CrdPlnrNav (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef CRDPLNRNAV_H
#define CRDPLNRNAV_H

// IP custInclude --- INSERT

#include "DlgPlnrNavLoaini.h"
#include "PnlPlnrNavHeadbar.h"
#include "PnlPlnrNavPre.h"
#include "PnlPlnrNavAdmin.h"
#include "PnlPlnrNavGlobal.h"
#include "PnlPlnrNavDesign.h"
#include "PnlPlnrNavCalc.h"
#include "PnlPlnrNavLayout.h"

/**
  * CrdPlnrNav
  */
class CrdPlnrNav : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrNavDo)
		*/
	class VecVDo {

	public:
		static const uint CLOSE = 1;
		static const uint MITAPPABTCLICK = 2;
		static const uint MITSESTRMCLICK = 3;
		static const uint MITCRDUSGCLICK = 4;
		static const uint MITCRDUSRCLICK = 5;
		static const uint MITCRDPRSCLICK = 6;
		static const uint MITCRDFILCLICK = 7;
		static const uint MITCRDDTPCLICK = 8;
		static const uint MITCRDCTPCLICK = 9;
		static const uint MITCRDMATCLICK = 10;
		static const uint MITCRDPRJCLICK = 11;
		static const uint MITCRDDSNCLICK = 12;
		static const uint MITCRDDOMCLICK = 13;
		static const uint MITCRDDGDCLICK = 14;
		static const uint MITCRDDVCCLICK = 15;
		static const uint MITCRDSRUCLICK = 16;
		static const uint MITCRDSTKCLICK = 17;
		static const uint MITCRDLYRCLICK = 18;
		static const uint MITCRDCLCCLICK = 19;
		static const uint MITCRDCLICLICK = 20;
		static const uint MITCRDTPOCLICK = 21;
		static const uint MITAPPLOICLICK = 22;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
		* VecVSge (full: VecVPlnrNavSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint ALRPLNRABT = 2;
		static const uint CLOSE = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
	  * ContInf (full: ContInfPlnrNav)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFSGE = 1;
		static const uint MRLAPPHLP = 2;
		static const uint MTXSESSES1 = 3;
		static const uint MTXSESSES2 = 4;
		static const uint MTXSESSES3 = 5;

	public:
		ContInf(const uint numFSge = 1, const string& MrlAppHlp = "", const string& MtxSesSes1 = "", const string& MtxSesSes2 = "", const string& MtxSesSes3 = "");

	public:
		uint numFSge;
		string MrlAppHlp;
		string MtxSesSes1;
		string MtxSesSes2;
		string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVReqitmode = VecPlnrVReqitmode::IDLE, const usmallint latency = 5, const string& shortMenu = "", const uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneGlobal = false, const bool initdoneDesign = false, const bool initdoneCalc = false, const bool initdoneLayout = false);
	};

	/**
		* StatShr (full: StatShrPlnrNav)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFDLGLOAINI = 1;
		static const uint JREFHEADBAR = 2;
		static const uint JREFPRE = 3;
		static const uint PNLPREAVAIL = 4;
		static const uint JREFADMIN = 5;
		static const uint PNLADMINAVAIL = 6;
		static const uint JREFGLOBAL = 7;
		static const uint PNLGLOBALAVAIL = 8;
		static const uint JREFDESIGN = 9;
		static const uint PNLDESIGNAVAIL = 10;
		static const uint JREFCALC = 11;
		static const uint PNLCALCAVAIL = 12;
		static const uint JREFLAYOUT = 13;
		static const uint PNLLAYOUTAVAIL = 14;
		static const uint MSPCRD1AVAIL = 15;
		static const uint MITCRDUSGAVAIL = 16;
		static const uint MITCRDUSRAVAIL = 17;
		static const uint MITCRDPRSAVAIL = 18;
		static const uint MITCRDFILAVAIL = 19;
		static const uint MSPCRD2AVAIL = 20;
		static const uint MITCRDDTPAVAIL = 21;
		static const uint MITCRDCTPAVAIL = 22;
		static const uint MITCRDMATAVAIL = 23;
		static const uint MSPCRD3AVAIL = 24;
		static const uint MITCRDPRJAVAIL = 25;
		static const uint MITCRDDSNAVAIL = 26;
		static const uint MITCRDDOMAVAIL = 27;
		static const uint MITCRDDOMACTIVE = 28;
		static const uint MITCRDDGDAVAIL = 29;
		static const uint MITCRDDGDACTIVE = 30;
		static const uint MITCRDDVCAVAIL = 31;
		static const uint MITCRDDVCACTIVE = 32;
		static const uint MITCRDSRUAVAIL = 33;
		static const uint MITCRDSRUACTIVE = 34;
		static const uint MITCRDSTKAVAIL = 35;
		static const uint MITCRDSTKACTIVE = 36;
		static const uint MITCRDLYRAVAIL = 37;
		static const uint MITCRDLYRACTIVE = 38;
		static const uint MSPCRD4AVAIL = 39;
		static const uint MITCRDCLCAVAIL = 40;
		static const uint MITCRDCLCACTIVE = 41;
		static const uint MITCRDCLIAVAIL = 42;
		static const uint MITCRDCLIACTIVE = 43;
		static const uint MSPCRD5AVAIL = 44;
		static const uint MITCRDTPOAVAIL = 45;
		static const uint MSPAPP2AVAIL = 46;
		static const uint MITAPPLOIAVAIL = 47;

	public:
		StatShr(const ubigint jrefDlgloaini = 0, const ubigint jrefHeadbar = 0, const ubigint jrefPre = 0, const bool pnlpreAvail = false, const ubigint jrefAdmin = 0, const bool pnladminAvail = false, const ubigint jrefGlobal = 0, const bool pnlglobalAvail = false, const ubigint jrefDesign = 0, const bool pnldesignAvail = false, const ubigint jrefCalc = 0, const bool pnlcalcAvail = false, const ubigint jrefLayout = 0, const bool pnllayoutAvail = false, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdFilAvail = true, const bool MspCrd2Avail = true, const bool MitCrdDtpAvail = true, const bool MitCrdCtpAvail = true, const bool MitCrdMatAvail = true, const bool MspCrd3Avail = true, const bool MitCrdPrjAvail = true, const bool MitCrdDsnAvail = true, const bool MitCrdDomAvail = true, const bool MitCrdDomActive = true, const bool MitCrdDgdAvail = true, const bool MitCrdDgdActive = true, const bool MitCrdDvcAvail = true, const bool MitCrdDvcActive = true, const bool MitCrdSruAvail = true, const bool MitCrdSruActive = true, const bool MitCrdStkAvail = true, const bool MitCrdStkActive = true, const bool MitCrdLyrAvail = true, const bool MitCrdLyrActive = true, const bool MspCrd4Avail = true, const bool MitCrdClcAvail = true, const bool MitCrdClcActive = true, const bool MitCrdCliAvail = true, const bool MitCrdCliActive = true, const bool MspCrd5Avail = true, const bool MitCrdTpoAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		ubigint jrefDlgloaini;
		ubigint jrefHeadbar;
		ubigint jrefPre;
		bool pnlpreAvail;
		ubigint jrefAdmin;
		bool pnladminAvail;
		ubigint jrefGlobal;
		bool pnlglobalAvail;
		ubigint jrefDesign;
		bool pnldesignAvail;
		ubigint jrefCalc;
		bool pnlcalcAvail;
		ubigint jrefLayout;
		bool pnllayoutAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdFilAvail;
		bool MspCrd2Avail;
		bool MitCrdDtpAvail;
		bool MitCrdCtpAvail;
		bool MitCrdMatAvail;
		bool MspCrd3Avail;
		bool MitCrdPrjAvail;
		bool MitCrdDsnAvail;
		bool MitCrdDomAvail;
		bool MitCrdDomActive;
		bool MitCrdDgdAvail;
		bool MitCrdDgdActive;
		bool MitCrdDvcAvail;
		bool MitCrdDvcActive;
		bool MitCrdSruAvail;
		bool MitCrdSruActive;
		bool MitCrdStkAvail;
		bool MitCrdStkActive;
		bool MitCrdLyrAvail;
		bool MitCrdLyrActive;
		bool MspCrd4Avail;
		bool MitCrdClcAvail;
		bool MitCrdClcActive;
		bool MitCrdCliAvail;
		bool MitCrdCliActive;
		bool MspCrd5Avail;
		bool MitCrdTpoAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrNav)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrNavDo)
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
		* DpchEngData (full: DpchEngPlnrNavData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFSGE = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint TAG = 6;
		static const uint ALL = 7;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFSge = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFSge;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPnlpreAvail(DbsPlnr* dbsplnr);
	bool evalPnladminAvail(DbsPlnr* dbsplnr);
	bool evalPnlglobalAvail(DbsPlnr* dbsplnr);
	bool evalPnldesignAvail(DbsPlnr* dbsplnr);
	bool evalPnlcalcAvail(DbsPlnr* dbsplnr);
	bool evalPnllayoutAvail(DbsPlnr* dbsplnr);
	bool evalMspCrd1Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdUsgAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdUsrAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdPrsAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdFilAvail(DbsPlnr* dbsplnr);
	bool evalMspCrd2Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdDtpAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdCtpAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdMatAvail(DbsPlnr* dbsplnr);
	bool evalMspCrd3Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdPrjAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdDsnAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdDomAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdDomActive(DbsPlnr* dbsplnr);
	bool evalMitCrdDgdAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdDgdActive(DbsPlnr* dbsplnr);
	bool evalMitCrdDvcAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdDvcActive(DbsPlnr* dbsplnr);
	bool evalMitCrdSruAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdSruActive(DbsPlnr* dbsplnr);
	bool evalMitCrdStkAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdStkActive(DbsPlnr* dbsplnr);
	bool evalMitCrdLyrAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdLyrActive(DbsPlnr* dbsplnr);
	bool evalMspCrd4Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdClcAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdClcActive(DbsPlnr* dbsplnr);
	bool evalMitCrdCliAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdCliActive(DbsPlnr* dbsplnr);
	bool evalMspCrd5Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdTpoAvail(DbsPlnr* dbsplnr);
	bool evalMspApp2Avail(DbsPlnr* dbsplnr);
	bool evalMitAppLoiAvail(DbsPlnr* dbsplnr);

public:
	CrdPlnrNav(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
	~CrdPlnrNav();

public:
	ContInf continf;
	StatShr statshr;

	Feed feedFMcbAlert;
	Feed feedFSge;

	DlgPlnrNavLoaini* dlgloaini;
	PnlPlnrNavHeadbar* pnlheadbar;
	PnlPlnrNavPre* pnlpre;
	PnlPlnrNavAdmin* pnladmin;
	PnlPlnrNavGlobal* pnlglobal;
	PnlPlnrNavDesign* pnldesign;
	PnlPlnrNavCalc* pnlcalc;
	PnlPlnrNavLayout* pnllayout;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);
	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);
	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:
// IP dpchchangeStage --- BEGIN
	void changeStage(DbsPlnr* dbsplnr, uint _ixVSge, DpchEngPlnr** dpcheng = NULL);
// IP dpchchangeStage --- END

	uint enterSgeIdle(DbsPlnr* dbsplnr);
	void leaveSgeIdle(DbsPlnr* dbsplnr);
	uint enterSgeAlrplnrabt(DbsPlnr* dbsplnr);
	void leaveSgeAlrplnrabt(DbsPlnr* dbsplnr);
	uint enterSgeClose(DbsPlnr* dbsplnr);
	void leaveSgeClose(DbsPlnr* dbsplnr);

// IP getSquawk --- BEGIN
	string getSquawk(DbsPlnr* dbsplnr);
// IP getSquawk --- END

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

	void handleDpchAppDoClose(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdDtpClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdCtpClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdMatClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdPrjClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdDsnClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdDomClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdDgdClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdDvcClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdSruClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdStkClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdLyrClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdClcClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdCliClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitCrdTpoClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppPlnrAlert(DbsPlnr* dbsplnr, DpchAppPlnrAlert* dpchappplnralert, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrDlgClose(DbsPlnr* dbsplnr, const ubigint jrefTrig);
};

#endif


