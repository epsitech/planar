/**
  * \file PnlPlnrDsnRec.h
  * job handler for job PnlPlnrDsnRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNREC_H
#define PNLPLNRDSNREC_H

// IP custInclude --- INSERT

#include "PnlPlnrDsnPre.h"
#include "PnlPlnrDsnDetail.h"
#include "PnlPlnrDsnViewxy.h"
#include "PnlPlnrDsnViewz.h"
#include "PnlPlnrDsnMod1NDesign.h"
#include "PnlPlnrDsnDrv1NDesign.h"
#include "PnlPlnrDsnDsn1NDevice.h"
#include "PnlPlnrDsnDsn1NStack.h"
#include "PnlPlnrDsnDsn1NDomaingd.h"
#include "PnlPlnrDsnDsn1NDomain.h"
#include "PnlPlnrDsn1NBlock.h"
#include "PnlPlnrDsn1NReticle.h"
#include "PnlPlnrDsnHk1NLevel.h"
#include "PnlPlnrDsnHk1NVertex.h"
#include "PnlPlnrDsnHk1NLineguide.h"
#include "PnlPlnrDsnHk1NArcguide.h"
#include "PnlPlnrDsnHk1NLayer.h"
#include "PnlPlnrDsnHk1NStructure.h"

/**
  * PnlPlnrDsnRec
  */
class PnlPlnrDsnRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDsnRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDsnRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppPlnrDsnRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneViewxy = false, const bool initdoneViewz = false, const bool initdoneMod1NDesign = false, const bool initdoneDrv1NDesign = false, const bool initdoneDsn1NDevice = false, const bool initdoneDsn1NStack = false, const bool initdoneDsn1NDomaingd = false, const bool initdoneDsn1NDomain = false, const bool initdone1NBlock = false, const bool initdone1NReticle = false, const bool initdoneHk1NLevel = false, const bool initdoneHk1NVertex = false, const bool initdoneHk1NLineguide = false, const bool initdoneHk1NArcguide = false, const bool initdoneHk1NLayer = false, const bool initdoneHk1NStructure = false);
	};

	/**
		* StatShr (full: StatShrPlnrDsnRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFVIEWXY = 4;
		static const uint PNLVIEWXYAVAIL = 5;
		static const uint JREFVIEWZ = 6;
		static const uint PNLVIEWZAVAIL = 7;
		static const uint JREFMOD1NDESIGN = 8;
		static const uint PNLMOD1NDESIGNAVAIL = 9;
		static const uint JREFDRV1NDESIGN = 10;
		static const uint JREFDSN1NDEVICE = 11;
		static const uint PNLDSN1NDEVICEAVAIL = 12;
		static const uint JREFDSN1NSTACK = 13;
		static const uint PNLDSN1NSTACKAVAIL = 14;
		static const uint JREFDSN1NDOMAINGD = 15;
		static const uint JREFDSN1NDOMAIN = 16;
		static const uint JREF1NBLOCK = 17;
		static const uint PNL1NBLOCKAVAIL = 18;
		static const uint JREF1NRETICLE = 19;
		static const uint PNL1NRETICLEAVAIL = 20;
		static const uint JREFHK1NLEVEL = 21;
		static const uint PNLHK1NLEVELAVAIL = 22;
		static const uint JREFHK1NVERTEX = 23;
		static const uint PNLHK1NVERTEXAVAIL = 24;
		static const uint JREFHK1NLINEGUIDE = 25;
		static const uint PNLHK1NLINEGUIDEAVAIL = 26;
		static const uint JREFHK1NARCGUIDE = 27;
		static const uint PNLHK1NARCGUIDEAVAIL = 28;
		static const uint JREFHK1NLAYER = 29;
		static const uint PNLHK1NLAYERAVAIL = 30;
		static const uint JREFHK1NSTRUCTURE = 31;
		static const uint PNLHK1NSTRUCTUREAVAIL = 32;
		static const uint BUTREGULARIZEACTIVE = 33;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefViewxy = 0, const bool pnlviewxyAvail = false, const ubigint jrefViewz = 0, const bool pnlviewzAvail = false, const ubigint jrefMod1NDesign = 0, const bool pnlmod1ndesignAvail = false, const ubigint jrefDrv1NDesign = 0, const ubigint jrefDsn1NDevice = 0, const bool pnldsn1ndeviceAvail = false, const ubigint jrefDsn1NStack = 0, const bool pnldsn1nstackAvail = false, const ubigint jrefDsn1NDomaingd = 0, const ubigint jrefDsn1NDomain = 0, const ubigint jref1NBlock = 0, const bool pnl1nblockAvail = false, const ubigint jref1NReticle = 0, const bool pnl1nreticleAvail = false, const ubigint jrefHk1NLevel = 0, const bool pnlhk1nlevelAvail = false, const ubigint jrefHk1NVertex = 0, const bool pnlhk1nvertexAvail = false, const ubigint jrefHk1NLineguide = 0, const bool pnlhk1nlineguideAvail = false, const ubigint jrefHk1NArcguide = 0, const bool pnlhk1narcguideAvail = false, const ubigint jrefHk1NLayer = 0, const bool pnlhk1nlayerAvail = false, const ubigint jrefHk1NStructure = 0, const bool pnlhk1nstructureAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefViewxy;
		bool pnlviewxyAvail;
		ubigint jrefViewz;
		bool pnlviewzAvail;
		ubigint jrefMod1NDesign;
		bool pnlmod1ndesignAvail;
		ubigint jrefDrv1NDesign;
		ubigint jrefDsn1NDevice;
		bool pnldsn1ndeviceAvail;
		ubigint jrefDsn1NStack;
		bool pnldsn1nstackAvail;
		ubigint jrefDsn1NDomaingd;
		ubigint jrefDsn1NDomain;
		ubigint jref1NBlock;
		bool pnl1nblockAvail;
		ubigint jref1NReticle;
		bool pnl1nreticleAvail;
		ubigint jrefHk1NLevel;
		bool pnlhk1nlevelAvail;
		ubigint jrefHk1NVertex;
		bool pnlhk1nvertexAvail;
		ubigint jrefHk1NLineguide;
		bool pnlhk1nlineguideAvail;
		ubigint jrefHk1NArcguide;
		bool pnlhk1narcguideAvail;
		ubigint jrefHk1NLayer;
		bool pnlhk1nlayerAvail;
		ubigint jrefHk1NStructure;
		bool pnlhk1nstructureAvail;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDsnRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDsnRecDo)
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
		* DpchEngData (full: DpchEngPlnrDsnRecData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint JREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;
		static const uint ALL = 6;

	public:
		DpchEngData(const ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const set<uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		void merge(DpchEngPlnr* dpcheng);
		void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
	};

	bool evalPnlviewxyAvail(DbsPlnr* dbsplnr);
	bool evalPnlviewzAvail(DbsPlnr* dbsplnr);
	bool evalPnlmod1ndesignAvail(DbsPlnr* dbsplnr);
	bool evalPnldsn1ndeviceAvail(DbsPlnr* dbsplnr);
	bool evalPnldsn1nstackAvail(DbsPlnr* dbsplnr);
	bool evalPnl1nblockAvail(DbsPlnr* dbsplnr);
	bool evalPnl1nreticleAvail(DbsPlnr* dbsplnr);
	bool evalPnlhk1nlevelAvail(DbsPlnr* dbsplnr);
	bool evalPnlhk1nvertexAvail(DbsPlnr* dbsplnr);
	bool evalPnlhk1nlineguideAvail(DbsPlnr* dbsplnr);
	bool evalPnlhk1narcguideAvail(DbsPlnr* dbsplnr);
	bool evalPnlhk1nlayerAvail(DbsPlnr* dbsplnr);
	bool evalPnlhk1nstructureAvail(DbsPlnr* dbsplnr);
	bool evalButRegularizeActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrDsnRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDsnRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrDsnPre* pnlpre;
	PnlPlnrDsnDetail* pnldetail;
	PnlPlnrDsnViewxy* pnlviewxy;
	PnlPlnrDsnViewz* pnlviewz;
	PnlPlnrDsnMod1NDesign* pnlmod1ndesign;
	PnlPlnrDsnDrv1NDesign* pnldrv1ndesign;
	PnlPlnrDsnDsn1NDevice* pnldsn1ndevice;
	PnlPlnrDsnDsn1NStack* pnldsn1nstack;
	PnlPlnrDsnDsn1NDomaingd* pnldsn1ndomaingd;
	PnlPlnrDsnDsn1NDomain* pnldsn1ndomain;
	PnlPlnrDsn1NBlock* pnl1nblock;
	PnlPlnrDsn1NReticle* pnl1nreticle;
	PnlPlnrDsnHk1NLevel* pnlhk1nlevel;
	PnlPlnrDsnHk1NVertex* pnlhk1nvertex;
	PnlPlnrDsnHk1NLineguide* pnlhk1nlineguide;
	PnlPlnrDsnHk1NArcguide* pnlhk1narcguide;
	PnlPlnrDsnHk1NLayer* pnlhk1nlayer;
	PnlPlnrDsnHk1NStructure* pnlhk1nstructure;

	PlnrMDesign recDsn;

	bool muteRefresh;

// IP custVar --- INSERT

public:
// IP cust --- INSERT

public:
	DpchEngPlnr* getNewDpchEng(set<uint> items);

	void refresh(DbsPlnr* dbsplnr, set<uint>& moditems);

	void updatePreset(DbsPlnr* dbsplnr, const uint ixPlnrVPreset, const ubigint jrefTrig, const bool notif = false);
	void minimize(DbsPlnr* dbsplnr, const bool notif = false, DpchEngPlnr** dpcheng = NULL);
	void regularize(DbsPlnr* dbsplnr, const bool notif = false, DpchEngPlnr** dpcheng = NULL);

public:

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleDpchAppPlnrInit(DbsPlnr* dbsplnr, DpchAppPlnrInit* dpchappplnrinit, DpchEngPlnr** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsPlnr* dbsplnr, DpchEngPlnr** dpcheng);

// IP handleCall --- BEGIN
	void handleCall(DbsPlnr* dbsplnr, Call* call);
// IP handleCall --- END

	bool handleCallPlnrDsn_dimEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallPlnrDsn_modEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv, bool& boolvalRet);
	bool handleCallPlnrDsn_typEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const uint ixInv, bool& boolvalRet);
	bool handleCallPlnrDsnUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


