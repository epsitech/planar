/**
  * \file JobPlnrTpoExamples.h
  * job handler for job JobPlnrTpoExamples (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef JOBPLNRTPOEXAMPLES_H
#define JOBPLNRTPOEXAMPLES_H

// IP custInclude --- INSERT

/**
  * JobPlnrTpoExamples
  */
class JobPlnrTpoExamples : public JobPlnr {

public:
	/**
		* VecVSge (full: VecVJobPlnrTpoExamplesSge)
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
	JobPlnrTpoExamples(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
// IP constructor --- END
	~JobPlnrTpoExamples();

public:

// IP specVar --- INSERT

// IP custVar --- IBEGIN
	map<string,ubigint> refsDtp;

	ubigint refDsnPhotpos;
	ubigint refDsnPhotneg;
	ubigint refDsnPhc;
	ubigint refDsnVar;

	ubigint refTpoPhotpos;
	ubigint refTpoPhotneg;
	ubigint refTpoPhc;
	ubigint refTpoVar;

	map<ubigint,string> plots;
	string plotfolder;
// IP custVar --- IEND

public:
// IP cust --- INSERT

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


