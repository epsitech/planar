/**
  * \file QryPlnrMatList.h
  * job handler for job QryPlnrMatList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef QRYPLNRMATLIST_H
#define QRYPLNRMATLIST_H

// IP custInclude --- INSERT

/**
  * QryPlnrMatList
  */
class QryPlnrMatList : public JobPlnr {

public:
	/**
		* VecVOrd (full: VecVQryPlnrMatListOrd)
		*/
	class VecVOrd {

	public:
		static const uint SRF = 1;
		static const uint TIT = 2;
		static const uint TYP = 3;
		static const uint CAL = 4;
		static const uint SUP = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryPlnrMatList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 6, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryPlnrMatList)
		*/
	class StatShr : public Block {

	public:
		static const uint NTOT = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StatShr(const uint ntot = 0, const uint jnumFirstload = 0, const uint nload = 0);

	public:
		uint ntot;
		uint jnumFirstload;
		uint nload;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryPlnrMatList)
		*/
	class StgIac : public Block {

	public:
		static const uint JNUM = 1;
		static const uint JNUMFIRSTLOAD = 2;
		static const uint NLOAD = 3;

	public:
		StgIac(const uint jnum = 0, const uint jnumFirstload = 1, const uint nload = 100);

	public:
		uint jnum;
		uint jnumFirstload;
		uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

public:
// IP constructor --- BEGIN
	QryPlnrMatList(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~QryPlnrMatList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListPlnrQMatList rst;

	uint ixPlnrVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsPlnr* dbsplnr, const bool call = false);
	void refresh_filtSQL(string& sqlstr, const string& preSrf, const string& preTit, const uint preTyp, const ubigint preCal, const ubigint preSup, const bool addwhere);
	void refresh_filtSQL_append(string& sqlstr, bool& first);
	void refresh_orderSQL(string& sqlstr, const uint preIxOrd);
	void fetch(DbsPlnr* dbsplnr);
	uint getJnumByRef(const ubigint ref);
	ubigint getRefByJnum(const uint jnum);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	bool handleRefresh(DbsPlnr* dbsplnr);
	bool handleShow(DbsPlnr* dbsplnr);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrStubChg(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrMatMod(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrMatUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


