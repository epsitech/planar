/**
  * \file QryPlnrClcMNFile.h
  * job handler for job QryPlnrClcMNFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef QRYPLNRCLCMNFILE_H
#define QRYPLNRCLCMNFILE_H

// IP custInclude --- INSERT

/**
  * QryPlnrClcMNFile
  */
class QryPlnrClcMNFile : public JobPlnr {

public:
	/**
		* StatApp (full: StatAppQryPlnrClcMNFile)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 4, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryPlnrClcMNFile)
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
		* StgIac (full: StgIacQryPlnrClcMNFile)
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
	QryPlnrClcMNFile(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~QryPlnrClcMNFile();

public:
	StatShr statshr;
	StgIac stgiac;

	ListPlnrQClcMNFile rst;

	uint ixPlnrVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsPlnr* dbsplnr, const bool call = false);
	void refresh_baseSQL(string& sqlstr);
	bool evalQmd1Avail();

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
	bool handleCallPlnrCalRfilMod_calEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


