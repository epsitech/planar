/**
  * \file PnlPlnrDvcRec.h
  * job handler for job PnlPlnrDvcRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDVCREC_H
#define PNLPLNRDVCREC_H

// IP custInclude --- INSERT

#include "PnlPlnrDvcPre.h"
#include "PnlPlnrDvcDetail.h"
#include "PnlPlnrDvcView.h"
#include "PnlPlnrDvcAPar.h"
#include "PnlPlnrDvcSup1NDevice.h"
#include "PnlPlnrDvcHk1NStructure.h"
#include "PnlPlnrDvcHk1NVertex.h"
#include "PnlPlnrDvcHk1NLineguide.h"
#include "PnlPlnrDvcHk1NArcguide.h"

/**
  * PnlPlnrDvcRec
  */
class PnlPlnrDvcRec : public JobPlnr {

public:
	/**
		* VecVDo (full: VecVPlnrDvcRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDvcRec)
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
		* StatApp (full: StatAppPlnrDvcRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true, const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneAPar = false, const bool initdoneSup1NDevice = false, const bool initdoneHk1NStructure = false, const bool initdoneHk1NVertex = false, const bool initdoneHk1NLineguide = false, const bool initdoneHk1NArcguide = false);
	};

	/**
		* StatShr (full: StatShrPlnrDvcRec)
		*/
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint JREFPRE = 2;
		static const uint JREFDETAIL = 3;
		static const uint JREFVIEW = 4;
		static const uint JREFAPAR = 5;
		static const uint JREFSUP1NDEVICE = 6;
		static const uint JREFHK1NSTRUCTURE = 7;
		static const uint JREFHK1NVERTEX = 8;
		static const uint JREFHK1NLINEGUIDE = 9;
		static const uint JREFHK1NARCGUIDE = 10;
		static const uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const ubigint jrefPre = 0, const ubigint jrefDetail = 0, const ubigint jrefView = 0, const ubigint jrefAPar = 0, const ubigint jrefSup1NDevice = 0, const ubigint jrefHk1NStructure = 0, const ubigint jrefHk1NVertex = 0, const ubigint jrefHk1NLineguide = 0, const ubigint jrefHk1NArcguide = 0, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		ubigint jrefPre;
		ubigint jrefDetail;
		ubigint jrefView;
		ubigint jrefAPar;
		ubigint jrefSup1NDevice;
		ubigint jrefHk1NStructure;
		ubigint jrefHk1NVertex;
		ubigint jrefHk1NLineguide;
		ubigint jrefHk1NArcguide;
		bool ButRegularizeActive;

	public:
		void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagPlnrDvcRec)
		*/
	class Tag {

	public:
		static void writeXML(const uint ixPlnrVLocale, xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDvcRecDo)
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
		* DpchEngData (full: DpchEngPlnrDvcRecData)
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

	bool evalButRegularizeActive(DbsPlnr* dbsplnr);

public:
// IP constructor --- BEGIN
	PnlPlnrDvcRec(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~PnlPlnrDvcRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlPlnrDvcPre* pnlpre;
	PnlPlnrDvcDetail* pnldetail;
	PnlPlnrDvcView* pnlview;
	PnlPlnrDvcAPar* pnlapar;
	PnlPlnrDvcSup1NDevice* pnlsup1ndevice;
	PnlPlnrDvcHk1NStructure* pnlhk1nstructure;
	PnlPlnrDvcHk1NVertex* pnlhk1nvertex;
	PnlPlnrDvcHk1NLineguide* pnlhk1nlineguide;
	PnlPlnrDvcHk1NArcguide* pnlhk1narcguide;

	PlnrMDevice recDev;

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

	bool handleCallPlnrDevUpd_refEq(DbsPlnr* dbsplnr, const ubigint jrefTrig, const ubigint refInv);
};

#endif


