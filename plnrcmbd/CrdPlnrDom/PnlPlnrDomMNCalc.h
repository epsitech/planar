/**
  * \file PnlPlnrDomMNCalc.h
  * job handler for job PnlPlnrDomMNCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDOMMNCALC_H
#define PNLPLNRDOMMNCALC_H

// IP custInclude --- INSERT

#include "QryPlnrDomMNCalc.h"

/**
  * PnlPlnrDomMNCalc
  */
class PnlPlnrDomMNCalc : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDomMNCalcDo)
		*/
	class VecVDo {

	public:
		static const uint BUTADDCLICK = 1;
		static const uint BUTSUBCLICK = 2;
		static const uint BUTREFRESHCLICK = 3;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDomMNCalc)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDomMNCalc)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrPlnrDomMNCalc)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTSUBACTIVE = 1;

	public:
		StatShr(const bool ButSubActive = true);

	public:
		bool ButSubActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacPlnrDomMNCalc)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOMREFWIDTH = 1;
		static const uint TCOPRPWIDTH = 2;

	public:
		StgIac(const uint TcoMrefWidth = 100, const uint TcoPrpWidth = 100);

	public:
		uint TcoMrefWidth;
		uint TcoPrpWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagPlnrDomMNCalc)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDomMNCalcData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;

	public:
		DpchAppData();

	public:
		StgIac stgiac;
		QryPlnrDomMNCalc::StgIac stgiacqry;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDomMNCalcDo)
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
		* DpchEngData (full: DpchEngPlnrDomMNCalcData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;
		static const uint ALL = 12;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListPlnrQDomMNCalc* rst = NULL, QryPlnrDomMNCalc::StatShr* statshrqry = NULL, QryPlnrDomMNCalc::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListPlnrQDomMNCalc rst;
		QryPlnrDomMNCalc::StatShr statshrqry;
		QryPlnrDomMNCalc::StgIac stgiacqry;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButSubActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrDomMNCalc(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDomMNCalc();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryPlnrDomMNCalc* qry;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataStgiac(DbsPlnr* dbsplnr, StgIac* _stgiac, DpchEngPlnr** dpcheng);
	void handleDpchAppDataStgiacqry(DbsPlnr* dbsplnr, QryPlnrDomMNCalc::StgIac* _stgiacqry, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButAddClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButSubClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrStatChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
};

#endif


