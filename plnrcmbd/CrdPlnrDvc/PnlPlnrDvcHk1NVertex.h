/**
  * \file PnlPlnrDvcHk1NVertex.h
  * job handler for job PnlPlnrDvcHk1NVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDVCHK1NVERTEX_H
#define PNLPLNRDVCHK1NVERTEX_H

// IP custInclude --- INSERT

#include "QryPlnrDvcHk1NVertex.h"

/**
  * PnlPlnrDvcHk1NVertex
  */
class PnlPlnrDvcHk1NVertex : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDvcHk1NVertexDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDELETECLICK = 1;
		static const uint BUTREFRESHCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDvcHk1NVertex)
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
		* StatApp (full: StatAppPlnrDvcHk1NVertex)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrPlnrDvcHk1NVertex)
		*/
	class StatShr : public Block {

	public:
		static const uint BUTDELETEACTIVE = 1;

	public:
		StatShr(const bool ButDeleteActive = true);

	public:
		bool ButDeleteActive;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacPlnrDvcHk1NVertex)
		*/
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
		* Tag (full: TagPlnrDvcHk1NVertex)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDvcHk1NVertexData)
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
		QryPlnrDvcHk1NVertex::StgIac stgiacqry;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDvcHk1NVertexDo)
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
		* DpchEngData (full: DpchEngPlnrDvcHk1NVertexData)
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
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, Feed* feedFCsiQst = NULL, StatShr* statshr = NULL, StgIac* stgiac = NULL, ListPlnrQDvcHk1NVertex* rst = NULL, QryPlnrDvcHk1NVertex::StatShr* statshrqry = NULL, QryPlnrDvcHk1NVertex::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatShr statshr;
		StgIac stgiac;
		ListPlnrQDvcHk1NVertex rst;
		QryPlnrDvcHk1NVertex::StatShr statshrqry;
		QryPlnrDvcHk1NVertex::StgIac stgiacqry;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalButDeleteActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrDvcHk1NVertex(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDvcHk1NVertex();

public:
	ContInf continf;
	StatShr statshr;
	StgIac stgiac;

	Feed feedFCsiQst;

	QryPlnrDvcHk1NVertex* qry;

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
	void handleDpchAppDataStgiacqry(DbsPlnr* dbsplnr, QryPlnrDvcHk1NVertex::StgIac* _stgiacqry, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButDeleteClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRefreshClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrStatChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
};

#endif


