/**
  * \file SessPlnr.h
  * job handler for job SessPlnr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SESSPLNR_H
#define SESSPLNR_H

// IP custInclude --- INSERT

#include "CrdPlnrNav.h"
#include "CrdPlnrUsg.h"
#include "CrdPlnrUsr.h"
#include "CrdPlnrPrs.h"
#include "CrdPlnrFil.h"
#include "CrdPlnrDtp.h"
#include "CrdPlnrCtp.h"
#include "CrdPlnrMat.h"
#include "CrdPlnrPrj.h"
#include "CrdPlnrDsn.h"
#include "CrdPlnrDom.h"
#include "CrdPlnrDgd.h"
#include "CrdPlnrDvc.h"
#include "CrdPlnrSru.h"
#include "CrdPlnrStk.h"
#include "CrdPlnrLyr.h"
#include "CrdPlnrClc.h"
#include "CrdPlnrCli.h"
#include "CrdPlnrTpo.h"
#include "CrdPlnrArr.h"
#include "CrdPlnrAri.h"
#include "CrdPlnrRtc.h"

/**
  * SessPlnr
  */
class SessPlnr : public JobPlnr {

public:
	/**
		* StatShr (full: StatShrSessPlnr)
		*/
	class StatShr : public Block {

	public:
		static const uint JREFCRDNAV = 1;

	public:
		StatShr(const ubigint jrefCrdnav = 0);

	public:
		ubigint jrefCrdnav;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessPlnrData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint STATSHR = 2;
		static const uint ALL = 3;

	public:
		DpchEngData(const ubigint jref = 0, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

public:
	SessPlnr(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const ubigint refPlnrMUser, const string& ip);
	~SessPlnr();

public:
	StatShr statshr;

	CrdPlnrNav* crdnav;
	list<CrdPlnrUsg*> crdusgs;
	list<CrdPlnrUsr*> crdusrs;
	list<CrdPlnrPrs*> crdprss;
	list<CrdPlnrFil*> crdfils;
	list<CrdPlnrDtp*> crddtps;
	list<CrdPlnrCtp*> crdctps;
	list<CrdPlnrMat*> crdmats;
	list<CrdPlnrPrj*> crdprjs;
	list<CrdPlnrDsn*> crddsns;
	list<CrdPlnrDom*> crddoms;
	list<CrdPlnrDgd*> crddgds;
	list<CrdPlnrDvc*> crddvcs;
	list<CrdPlnrSru*> crdsrus;
	list<CrdPlnrStk*> crdstks;
	list<CrdPlnrLyr*> crdlyrs;
	list<CrdPlnrClc*> crdclcs;
	list<CrdPlnrCli*> crdclis;
	list<CrdPlnrTpo*> crdtpos;
	list<CrdPlnrArr*> crdarrs;
	list<CrdPlnrAri*> crdaris;
	list<CrdPlnrRtc*> crdrtcs;

	map<ubigint, uint> usgaccs;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	uint checkCrdActive(const uint ixPlnrVCard);
	uint evalCrddsnActive();
	uint evalCrddomActive();
	uint evalCrddgdActive();
	uint evalCrddvcActive();
	uint evalCrdsruActive();
	uint evalCrdstkActive();
	uint evalCrdlyrActive();
	uint evalCrdclcActive();
	uint evalCrdcliActive();
	uint evalCrdarrActive();
	uint evalCrdariActive();
	uint evalCrdrtcActive();

	uint checkUiaccess(const uint ixPlnrVCard);
	uint getIxUac(DbsPlnr* dbsplnr, const uint ixPlnrVCard, const bool adm, ListPlnrRMUserMUsergroup& urus, const ubigint refPlnrMUser);

	uint checkAccess(DbsPlnr* dbsplnr, const uint ixPlnrVCard, const ubigint ref);
	void logAccess(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint preUref, const uint ixPlnrVCard, const ubigint unvUref);

	uint crdToMtb(const uint ixPlnrVCard);
	uint preToMtb(const uint ixPlnrVPreset);
	bool hasActive(const uint ixPlnrVCard);
	bool hasGrpown(const uint ixPlnrVMaintable);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	bool handleCreateCrdari(DbsPlnr* dbsplnr);
	bool handleCreateCrdarr(DbsPlnr* dbsplnr);
	bool handleCreateCrdclc(DbsPlnr* dbsplnr);
	bool handleCreateCrdcli(DbsPlnr* dbsplnr);
	bool handleCreateCrdctp(DbsPlnr* dbsplnr);
	bool handleCreateCrddgd(DbsPlnr* dbsplnr);
	bool handleCreateCrddom(DbsPlnr* dbsplnr);
	bool handleCreateCrddsn(DbsPlnr* dbsplnr);
	bool handleCreateCrddtp(DbsPlnr* dbsplnr);
	bool handleCreateCrddvc(DbsPlnr* dbsplnr);
	bool handleCreateCrdfil(DbsPlnr* dbsplnr);
	bool handleCreateCrdlyr(DbsPlnr* dbsplnr);
	bool handleCreateCrdmat(DbsPlnr* dbsplnr);
	bool handleCreateCrdprj(DbsPlnr* dbsplnr);
	bool handleCreateCrdprs(DbsPlnr* dbsplnr);
	bool handleCreateCrdrtc(DbsPlnr* dbsplnr);
	bool handleCreateCrdsru(DbsPlnr* dbsplnr);
	bool handleCreateCrdstk(DbsPlnr* dbsplnr);
	bool handleCreateCrdtpo(DbsPlnr* dbsplnr);
	bool handleCreateCrdusg(DbsPlnr* dbsplnr);
	bool handleCreateCrdusr(DbsPlnr* dbsplnr);
	bool handleEraseCrdari(DbsPlnr* dbsplnr);
	bool handleEraseCrdarr(DbsPlnr* dbsplnr);
	bool handleEraseCrdclc(DbsPlnr* dbsplnr);
	bool handleEraseCrdcli(DbsPlnr* dbsplnr);
	bool handleEraseCrdctp(DbsPlnr* dbsplnr);
	bool handleEraseCrddgd(DbsPlnr* dbsplnr);
	bool handleEraseCrddom(DbsPlnr* dbsplnr);
	bool handleEraseCrddsn(DbsPlnr* dbsplnr);
	bool handleEraseCrddtp(DbsPlnr* dbsplnr);
	bool handleEraseCrddvc(DbsPlnr* dbsplnr);
	bool handleEraseCrdfil(DbsPlnr* dbsplnr);
	bool handleEraseCrdlyr(DbsPlnr* dbsplnr);
	bool handleEraseCrdmat(DbsPlnr* dbsplnr);
	bool handleEraseCrdprj(DbsPlnr* dbsplnr);
	bool handleEraseCrdprs(DbsPlnr* dbsplnr);
	bool handleEraseCrdrtc(DbsPlnr* dbsplnr);
	bool handleEraseCrdsru(DbsPlnr* dbsplnr);
	bool handleEraseCrdstk(DbsPlnr* dbsplnr);
	bool handleEraseCrdtpo(DbsPlnr* dbsplnr);
	bool handleEraseCrdusg(DbsPlnr* dbsplnr);
	bool handleEraseCrdusr(DbsPlnr* dbsplnr);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrAccess(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool handleCallPlnrCrdActive(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, uint& ixRet);
	bool handleCallPlnrCrdClose(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv);
	bool handleCallPlnrCrdOpen(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool handleCallPlnrLog(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool handleCallPlnrRefPreSet(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, const ubigint refInv);
};

#endif


