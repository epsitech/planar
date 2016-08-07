/**
  * \file QryPlnrAriList.h
  * job handler for job QryPlnrAriList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef QRYPLNRARILIST_H
#define QRYPLNRARILIST_H

// IP custInclude --- INSERT

/**
  * QryPlnrAriList
  */
class QryPlnrAriList : public JobPlnr {

public:
	/**
		* VecVOrd (full: VecVQryPlnrAriListOrd)
		*/
	class VecVOrd {

	public:
		static const uint I = 1;
		static const uint J = 2;
		static const uint K = 3;
		static const uint L = 4;
		static const uint M = 5;
		static const uint N = 6;
		static const uint ARR = 7;
		static const uint DSN = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryPlnrAriList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 10, const uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryPlnrAriList)
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
		* StgIac (full: StgIacQryPlnrAriList)
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
	QryPlnrAriList(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~QryPlnrAriList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListPlnrQAriList rst;

	uint ixPlnrVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsPlnr* dbsplnr, const bool call = false);
	void refresh_baseSQL(string& sqlstr);
	void refresh_filtSQL(string& sqlstr, const int preI, const int preJ, const int preK, const int preL, const int preM, const int preN, const ubigint preArr, const ubigint preDsn, const bool addwhere);
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
	bool handleCallPlnrAriMod(DbsPlnr* dbsplnr, const ubigint jrefTrig);
	bool handleCallPlnrAriUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


