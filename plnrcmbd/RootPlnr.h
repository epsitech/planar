/**
  * \file RootPlnr.h
  * job handler for job RootPlnr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef ROOTPLNR_H
#define ROOTPLNR_H

// IP custInclude --- INSERT

#include "SessPlnr.h"

/**
  * RootPlnr
  */
class RootPlnr : public JobPlnr {

public:
	/**
		* DpchAppLogin (full: DpchAppRootPlnrLogin)
		*/
	class DpchAppLogin : public DpchAppPlnr {

	public:
		static const uint JREF = 1;
		static const uint PASSWORD = 2;
		static const uint USERNAME = 3;

	public:
		DpchAppLogin();

	public:
		string password;
		string username;

	public:
		void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

public:
	RootPlnr(XchgPlnr* xchg);
	~RootPlnr();

public:

	list<SessPlnr*> sesss;

// IP specVar --- INSERT

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	void clearAll(DbsPlnr* dbsplnr);
	void clearQtb(DbsPlnr* dbsplnr);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	bool handleClearAll(DbsPlnr* dbsplnr);
	bool handleCreateSess(DbsPlnr* dbsplnr);
	bool handleEraseSess(DbsPlnr* dbsplnr);

	void handleDpchAppLogin(DbsPlnr* dbsplnr, DpchAppLogin* dpchapplogin, const string ip, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrLogout(DbsPlnr* dbsplnr, const ubigint jrefTrig);
};

#endif


