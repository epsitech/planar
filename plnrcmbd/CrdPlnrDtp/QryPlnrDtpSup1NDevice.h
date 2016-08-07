/**
  * \file QryPlnrDtpSup1NDevice.h
  * job handler for job QryPlnrDtpSup1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef QRYPLNRDTPSUP1NDEVICE_H
#define QRYPLNRDTPSUP1NDEVICE_H

// IP custInclude --- INSERT

/**
  * QryPlnrDtpSup1NDevice
  */
class QryPlnrDtpSup1NDevice : public JobPlnr {

public:
	/**
		* StatApp (full: StatAppQryPlnrDtpSup1NDevice)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const uint firstcol = 1, const uint jnumFirstdisp = 1, const uint ncol = 1, const uint ndisp = 10);
	};

	/**
		* StatShr (full: StatShrQryPlnrDtpSup1NDevice)
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
		* StgIac (full: StgIacQryPlnrDtpSup1NDevice)
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
	QryPlnrDtpSup1NDevice(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~QryPlnrDtpSup1NDevice();

public:
	StatShr statshr;
	StgIac stgiac;

	ListPlnrQDtpSup1NDevice rst;

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
	bool handleCallPlnrDevMod_supEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


