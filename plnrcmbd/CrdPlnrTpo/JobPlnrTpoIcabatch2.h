/**
  * \file JobPlnrTpoIcabatch2.h
  * job handler for job JobPlnrTpoIcabatch2 (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef JOBPLNRTPOICABATCH2_H
#define JOBPLNRTPOICABATCH2_H

// IP custInclude --- INSERT

/**
  * JobPlnrTpoIcabatch2
  */
class JobPlnrTpoIcabatch2 : public JobPlnr {

public:
	/**
		* VecVSge (full: VecVJobPlnrTpoIcabatch2Sge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint CREIDLE = 2;
		static const uint CREATE = 3;
		static const uint EXPAND1 = 4;
		static const uint EXPAND2 = 5;
		static const uint PLOT = 6;
		static const uint DONE = 7;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

public:
// IP constructor --- BEGIN
	JobPlnrTpoIcabatch2(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~JobPlnrTpoIcabatch2();

public:

// IP specVar --- INSERT

// IP custVar --- IBEGIN
	map<string,ubigint> refsDtp;
	vector<ubigint> refsDsn;

	ubigint refTpoGratNeg;
	ubigint refTpoMesaPos;
	ubigint refTpoBotmetNeg;
	ubigint refTpoInsNeg;
	ubigint refTpoTopmetPos;

	map<ubigint,string> plots;
	string plotfolder;
// IP custVar --- IEND

public:
// IP cust --- IBEGIN
	PlnrMTapeout* createTpo(DbsPlnr* dbsplnr, const ubigint refPlnrMProject, const string& Title, const bool Hflip);
	PlnrMDesign* createDsn(DbsPlnr* dbsplnr, const ubigint refPlnrMProject, const string& Title, const string& Comment, ubigint& refStk, ubigint& refLyrMesa, ubigint& refLyrGrat, ubigint& refLyrBotmet, ubigint& refLyrIns, ubigint& refLyrTopmet, ubigint& refLyrBump, ListPlnrMDesign& dsns);
	PlnrMDevice* createDetsng(DbsPlnr* dbsplnr, const double rast, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const string sref, const double x, const double y, const double size, const bool ext, const bool vgrat, const double gratprd, const double gratfill, const double extsize, const double extofsx, const double extofsy, const double bumpofsx, const double bumpofsy, ListPlnrMDevice& devs);
	PlnrMDevice* createDetarr(DbsPlnr* dbsplnr, const double rast, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const string sref, const double gratprd, const double gratfill, const bool sbot, const bool ebot, const bool nbot, const bool wbot, ListPlnrMDevice& devs);
	PlnrMDevice* createPad(DbsPlnr* dbsplnr, const double rast, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const string sref, const double x, const double y, const double bumpofsx, const double bumpofsy, ListPlnrMDevice& devs);
	void addAnnot(DbsPlnr* dbsplnr, const ubigint refPlnrMLayer1, const ubigint refPlnrMLayer2, const ubigint refPlnrMLayer3, const ubigint refPlnrMLayer4, const ubigint refPlnrMLayer5, const ubigint refPlnrMLayer6, const ubigint refPlnrMDevice, const string& srefPlnrMStructure);
	void addMarker(DbsPlnr* dbsplnr, const string& type, const bool sq, const ubigint dsnRefPlnrMDesign, const uint dsnNum, const string& sref, const double x, const double y, const ubigint refLyrMesa, const ubigint refLyrTopmet, const ubigint refLyrBotmet, const ubigint refLyrIns, const ubigint refLyrGrat);
	void createMask(DbsPlnr* dbsplnr, const ubigint refPlnrMTapeout, const ubigint refPlnrMDesign, const string& sref, const ubigint refPlnrMLayer, const double x0, const double y0, const usmallint I, const usmallint J, const double di, const double dj, const usmallint K = 0, const usmallint L = 0, const double dk = 0.0, const double dl = 0.0, const usmallint M = 0, const usmallint N = 0, const double dm = 0.0, const double dn = 0.0);
// IP cust --- IEND

public:
// IP spec --- INSERT

public:
// IP changeStage --- BEGIN
	void changeStage(DbsPlnr* dbsplnr, uint _ixVSge);
// IP changeStage --- END

	uint enterSgeIdle(DbsPlnr* dbsplnr);
	void leaveSgeIdle(DbsPlnr* dbsplnr);
	uint enterSgeCreidle(DbsPlnr* dbsplnr);
	void leaveSgeCreidle(DbsPlnr* dbsplnr);
	uint enterSgeCreate(DbsPlnr* dbsplnr);
	void leaveSgeCreate(DbsPlnr* dbsplnr);
	uint enterSgeExpand1(DbsPlnr* dbsplnr);
	void leaveSgeExpand1(DbsPlnr* dbsplnr);
	uint enterSgeExpand2(DbsPlnr* dbsplnr);
	void leaveSgeExpand2(DbsPlnr* dbsplnr);
	uint enterSgePlot(DbsPlnr* dbsplnr);
	void leaveSgePlot(DbsPlnr* dbsplnr);
	uint enterSgeDone(DbsPlnr* dbsplnr);
	void leaveSgeDone(DbsPlnr* dbsplnr);

// IP getSquawk --- BEGIN
	string getSquawk(DbsPlnr* dbsplnr);
// IP getSquawk --- END

	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	bool handleRun(DbsPlnr* dbsplnr);

// IP handleTimer --- BEGIN
	void handleTimer(DbsPlnr* dbsplnr, const string& sref);
// IP handleTimer --- END

};

#endif


