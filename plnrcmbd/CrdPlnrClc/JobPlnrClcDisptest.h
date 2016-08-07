/**
  * \file JobPlnrClcDisptest.h
  * job handler for job JobPlnrClcDisptest (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef JOBPLNRCLCDISPTEST_H
#define JOBPLNRCLCDISPTEST_H

// IP custInclude --- INSERT

/**
  * JobPlnrClcDisptest
  */
class JobPlnrClcDisptest : public JobPlnr {

public:
	/**
		* VecVSge (full: VecVJobPlnrClcDisptestSge)
		*/
	class VecVSge {

	public:
		static const uint IDLE = 1;
		static const uint PRPIDLE = 2;
		static const uint PREPARE = 3;
		static const uint EXPAND1 = 4;
		static const uint EXPAND2 = 5;
		static const uint EXPAND3 = 6;
		static const uint DISCR = 7;
		static const uint CALC = 8;
		static const uint PLOT = 9;
		static const uint DONE = 10;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);

		static void fillFeed(Feed& feed);
	};

public:
// IP constructor --- BEGIN
	JobPlnrClcDisptest(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~JobPlnrClcDisptest();

public:

// IP specVar --- INSERT

// IP custVar --- IBEGIN
	map<string,ubigint> refsDtp;

	bool modlam, modgeo, modmpa, modmat;

	ubigint refDsn;
	vector<ubigint> refsModdsn;

	ubigint refClc;
	vector<ubigint> refsCli;

	vector<uint> orefsCli;
	vector<uint> teNs;
	vector<uint> tmNs;

	map<ubigint,string> plots;
	string plotfolder;

	// - device geometry parameters
	double mesa;
	bool topmet;
	bool buf;
	double tBuf;
	double tBotcont;
	int NPrd;
	double tPrd;
	double tTopcont;
	string grattype;
	double gratprd;
	double tGrat;

	// - material parameters
	string matsys;
	double kBotcont;
	double nDBotcont;
	double kTopcont;
	double nDTopcont;
	double xAR;
	double nDAR;
	double kAR;
	double keAR;
	string cladmat;
	double tClad;

	// - calculation parameters
	string calctype;
	string scantype;
	double scanstart;
	double scanstep;
	double scanmult;
	double scanstop;
	double grid;
	double lam;
	bool anisomat;
	bool lossmat;

	// - waveguide mode calculation parameters
	bool te;
	bool tm;

	// - FDTD parameters
	string illpos;
	double deltalam;
	double tstop;
	bool corn;
	bool mon;
	bool sshot;
	bool armon;
	bool arsshot;
	bool peeksshot;
	bool aspmon;
// IP custVar --- IEND

public:
// IP cust --- IBEGIN
	void resetPars();
// IP cust --- IEND

public:
// IP spec --- INSERT

public:
// IP changeStage --- BEGIN
	void changeStage(DbsPlnr* dbsplnr, uint _ixVSge);
// IP changeStage --- END

	uint enterSgeIdle(DbsPlnr* dbsplnr);
	void leaveSgeIdle(DbsPlnr* dbsplnr);
	uint enterSgePrpidle(DbsPlnr* dbsplnr);
	void leaveSgePrpidle(DbsPlnr* dbsplnr);
	uint enterSgePrepare(DbsPlnr* dbsplnr);
	void leaveSgePrepare(DbsPlnr* dbsplnr);
	uint enterSgeExpand1(DbsPlnr* dbsplnr);
	void leaveSgeExpand1(DbsPlnr* dbsplnr);
	uint enterSgeExpand2(DbsPlnr* dbsplnr);
	void leaveSgeExpand2(DbsPlnr* dbsplnr);
	uint enterSgeExpand3(DbsPlnr* dbsplnr);
	void leaveSgeExpand3(DbsPlnr* dbsplnr);
	uint enterSgeDiscr(DbsPlnr* dbsplnr);
	void leaveSgeDiscr(DbsPlnr* dbsplnr);
	uint enterSgeCalc(DbsPlnr* dbsplnr);
	void leaveSgeCalc(DbsPlnr* dbsplnr);
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


