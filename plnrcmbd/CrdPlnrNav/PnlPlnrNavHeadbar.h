/**
  * \file PnlPlnrNavHeadbar.h
  * job handler for job PnlPlnrNavHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVHEADBAR_H
#define PNLPLNRNAVHEADBAR_H

// IP custInclude --- INSERT

/**
  * PnlPlnrNavHeadbar
  */
class PnlPlnrNavHeadbar : public JobPlnr {

public:
	/**
		* StatShr (full: StatShrPlnrNavHeadbar)
		*/
	class StatShr : public Block {

	public:
		static const uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfPlnrNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagPlnrNavHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngPlnrNavHeadbarData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint STGINF = 3;
		static const uint TAG = 4;
		static const uint ALL = 5;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalMenCrdAvail(DbsPlnr* dbsplnr);
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
	bool evalMitCrdDgdAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdDvcAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdSruAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdStkAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdLyrAvail(DbsPlnr* dbsplnr);
	bool evalMspCrd4Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdClcAvail(DbsPlnr* dbsplnr);
	bool evalMitCrdCliAvail(DbsPlnr* dbsplnr);
	bool evalMspCrd5Avail(DbsPlnr* dbsplnr);
	bool evalMitCrdTpoAvail(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrNavHeadbar(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrNavHeadbar();

public:
	StatShr statshr;

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


