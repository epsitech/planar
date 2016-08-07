/**
  * \file PnlPlnrStkHeadbar.h
  * job handler for job PnlPlnrStkHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSTKHEADBAR_H
#define PNLPLNRSTKHEADBAR_H

// IP custInclude --- INSERT

/**
  * PnlPlnrStkHeadbar
  */
class PnlPlnrStkHeadbar : public JobPlnr {

public:
	/**
		* StgInf (full: StgInfPlnrStkHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagPlnrStkHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngPlnrStkHeadbarData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint STGINF = 2;
		static const uint TAG = 3;
		static const uint ALL = 4;

	public:
		DpchEngData(const ubigint jref = 0, const set<uint>& mask = {NONE});

	public:

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
// IP constructor --- BEGIN
	PnlPlnrStkHeadbar(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrStkHeadbar();

public:

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

};

#endif


