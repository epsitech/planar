/**
  * \file PnlPlnrStkList.h
  * job handler for job PnlPlnrStkList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSTKLIST_H
#define PNLPLNRSTKLIST_H

// IP custInclude --- INSERT

#include "QryPlnrStkList.h"

/**
  * PnlPlnrStkList
  */
class PnlPlnrStkList : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrStkListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrStkList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrStkList)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFOR = 1;
		static const uint TXTPRE = 2;
		static const uint BUTFILTERON = 3;
		static const uint NUMFCSIQST = 4;

	public:
		ContInf(const string& TxtFor = "", const string& TxtPre = "", const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		string TxtFor;
		string TxtPre;
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrPlnrStkList)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixPlnrVExpstate;
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacPlnrStkList)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOSRFWIDTH = 1;
		static const uint TCOTYPWIDTH = 2;
		static const uint TCODSNWIDTH = 3;
		static const uint TCOMTYWIDTH = 4;
		static const uint TCOFALWIDTH = 5;
		static const uint TCOCALWIDTH = 6;

	public:
		StgIac(const uint TcoSrfWidth = 100, const uint TcoTypWidth = 100, const uint TcoDsnWidth = 100, const uint TcoMtyWidth = 100, const uint TcoFalWidth = 100, const uint TcoCalWidth = 100);

	public:
		uint TcoSrfWidth;
		uint TcoTypWidth;
		uint TcoDsnWidth;
		uint TcoMtyWidth;
		uint TcoFalWidth;
		uint TcoCalWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagPlnrStkList)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrStkListData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;

	public:
		DpchAppData();

	public:
		ContIac contiac;
		StgIac stgiac;
		QryPlnrStkList::StgIac stgiacqry;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrStkListDo)
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
		* DpchEngData (full: DpchEngPlnrStkListData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;
		static const uint ALL = 13;

	public:
		DpchEngData(const ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, Feed* feedFTos = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListPlnrQStkList* rst = NULL, QryPlnrStkList::StatShr* statshrqry = NULL, QryPlnrStkList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		ListPlnrQStkList rst;
		QryPlnrStkList::StatShr statshrqry;
		QryPlnrStkList::StgIac stgiacqry;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrStkList(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrStkList();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;
	Feed feedFTos;

	QryPlnrStkList* qry;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsPlnr* dbsplnr, const bool notif = false, DpchEngPlnr** dpcheng = NULL);
	void regularize(DbsPlnr* dbsplnr, const bool notif = false, DpchEngPlnr** dpcheng = NULL);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);
	void handleDpchAppDataContiac(DbsPlnr* dbsplnr, ContIac* _contiac, DpchEngPlnr** dpcheng);
	void handleDpchAppDataStgiac(DbsPlnr* dbsplnr, StgIac* _stgiac, DpchEngPlnr** dpcheng);
	void handleDpchAppDataStgiacqry(DbsPlnr* dbsplnr, QryPlnrStkList::StgIac* _stgiacqry, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButNewClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButDeleteClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButFilterClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrStatChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
};

#endif


