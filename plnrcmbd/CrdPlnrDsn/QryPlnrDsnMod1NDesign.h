/**
  * \file QryPlnrDsnMod1NDesign.h
  * job handler for job QryPlnrDsnMod1NDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef QRYPLNRDSNMOD1NDESIGN_H
#define QRYPLNRDSNMOD1NDESIGN_H

// IP custInclude --- INSERT

/**
  * QryPlnrDsnMod1NDesign
  */
class QryPlnrDsnMod1NDesign : public JobPlnr {

public:
	/**
		* StatApp (full: StatAppQryPlnrDsnMod1NDesign)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 1, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryPlnrDsnMod1NDesign)
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
		* StgIac (full: StgIacQryPlnrDsnMod1NDesign)
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
	QryPlnrDsnMod1NDesign(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~QryPlnrDsnMod1NDesign();

public:
	StatShr statshr;
	StgIac stgiac;

	ListPlnrQDsnMod1NDesign rst;

	uint ixPlnrVQrystate;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void refreshJnum();
	void refresh(DbsPlnr* dbsplnr, const bool call = false);
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
	bool handleCallPlnrDsnMod_modEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


