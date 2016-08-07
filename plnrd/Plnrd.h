/**
  * \file Plnrd.h
  * inter-thread exchange object for Plnr daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRD_H
#define PLNRD_H

#include <unistd.h>
#ifndef _WIN32
	#include <sys/socket.h>
#endif

#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <unistd.h>

#include <microhttpd.h>

#include <curl/curl.h>

#include <dartcore/Engtypes.h>
#include <dartcore/Txtrd.h>

#include "Plnr.h"

#include "SqkPlnrExp.h"
#include "SqkPlnrMeep.h"
#include "SqkPlnrMesh.h"
#include "SqkPlnrPlot.h"
#include "SqkPlnrRast.h"
#include "SqkPlnrWgmode.h"

class XchgPlnrd;
typedef XchgPlnrd XchgPlnr;

/**
  * DpchPlnrdAck (written by dOpengconsrv, identified by opd_exe)
  */
namespace DpchPlnrdAck {
	void writeXML(xmlTextWriter* wr);
};

/**
  * DpchPlnrdQuit (written by d_exe, identified by opdEngsrv)
  */
namespace DpchPlnrdQuit {
	void writeXML(xmlTextWriter* wr);
};

/**
  * DpchPlnrdReg (written by dOpengconsrv, read by opd_exe)
  */
namespace DpchPlnrdReg {
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr, const ubigint nref = 0);
};

/**
  * DpchPlnropdReg (written by opd_exe, read by dOpengconsrv)
  */
class DpchPlnropdReg : public DpchPlnr {

public:
	static const uint PORT = 1;
	static const uint SREFSOPK = 2;
	static const uint OPPRCN = 3;

public:
	DpchPlnropdReg();

public:
	usmallint port;
	vector<string> srefsOpk;
	usmallint opprcn;

public:
	static bool all(const set<uint>& items);

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchPlnropdUnreg (written by opd_exe, read by dOpengconsrv)
  */
class DpchPlnropdUnreg : public DpchPlnr {

public:
	static const uint NREF = 1;

public:
	DpchPlnropdUnreg();

public:
	ubigint nref;

public:
	static bool all(const set<uint>& items);

	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppPlnr
	*/
class DpchAppPlnr : public DpchPlnr {

public:
	static const uint JREF = 1;

public:
	DpchAppPlnr(const uint ixPlnrVDpch = 0);
	virtual ~DpchAppPlnr();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);

	virtual void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppPlnrAlert
  */
class DpchAppPlnrAlert : public DpchAppPlnr {

public:
	static const uint JREF = 1;
	static const uint NUMFMCB = 2;

public:
	DpchAppPlnrAlert();

public:
	uint numFMcb;

public:
	static bool all(const set<uint>& items);

	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchAppPlnrInit
  */
class DpchAppPlnrInit : public DpchAppPlnr {

public:
	DpchAppPlnrInit();
};

/**
  * DpchAppPlnrResume
  */
class DpchAppPlnrResume : public DpchAppPlnr {

public:
	DpchAppPlnrResume();
};

/**
	* DpchEngPlnr
	*/
class DpchEngPlnr : public DpchPlnr {

public:
	static const uint JREF = 1;

public:
	DpchEngPlnr(const uint ixPlnrVDpch = 0, const ubigint jref = 0);
	virtual ~DpchEngPlnr();

public:
	ubigint jref;

public:
	static bool all(const set<uint>& items);
	virtual void merge(DpchEngPlnr* dpcheng);

	virtual void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngPlnrAck
  */
class DpchEngPlnrAck : public DpchEngPlnr {

public:
	DpchEngPlnrAck(const ubigint jref = 0);
};

/**
  * DpchEngPlnrAlert
  */
class DpchEngPlnrAlert : public DpchEngPlnr {

public:
	static const uint JREF = 1;
	static const uint CONTINF = 2;
	static const uint FEEDFMCB = 3;
	static const uint ALL = 4;

public:
	DpchEngPlnrAlert(const ubigint jref = 0, ContInfPlnrAlert* continf = NULL, Feed* feedFMcb = NULL, const set<uint>& mask = {NONE});

public:
	ContInfPlnrAlert continf;
	Feed feedFMcb;

public:
	static bool all(const set<uint>& items);
	void merge(DpchEngPlnr* dpcheng);

	void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngPlnrConfirm
  */
class DpchEngPlnrConfirm : public DpchEngPlnr {

public:
	static const uint ACCEPTED = 1;
	static const uint JREF = 2;
	static const uint SREF = 3;
	static const uint ALL = 4;

public:
	DpchEngPlnrConfirm(const bool accepted = false, const ubigint jref = 0, const string& sref = "", const set<uint>& mask = {ALL});

public:
	bool accepted;
	string sref;

public:
	static bool all(const set<uint>& items);
	void merge(DpchEngPlnr* dpcheng);

	void writeXML(const uint ixPlnrVLocale, pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
  * DpchEngPlnrSuspend
  */
class DpchEngPlnrSuspend : public DpchEngPlnr {

public:
	DpchEngPlnrSuspend(const ubigint jref = 0);
};

/**
	* StgPlnrd
	*/
class StgPlnrd : public Block {

public:
	static const uint JOBPRCN = 1;
	static const uint OPENGSRVPORT = 2;
	static const uint APPSRVPORT = 3;
	static const uint HISTLENGTH = 4;

public:
	StgPlnrd(const usmallint jobprcn = 1, const usmallint opengsrvport = 0, const usmallint appsrvport = 0, const usmallint histlength = 20);

public:
	usmallint jobprcn;
	usmallint opengsrvport;
	usmallint appsrvport;
	usmallint histlength;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgPlnrd* comp);
	set<uint> diff(const StgPlnrd* comp);
};

/**
	* StgPlnrDatabase
	*/
class StgPlnrDatabase : public Block {

public:
	static const uint IXDBSVDBSTYPE = 1;
	static const uint DBSPATH = 2;
	static const uint DBSNAME = 3;
	static const uint USERNAME = 4;
	static const uint PASSWORD = 5;
	static const uint IP = 6;
	static const uint PORT = 7;

public:
	StgPlnrDatabase(const uint ixDbsVDbstype = 0, const string& dbspath = "", const string& dbsname = "", const string& username = "epsi", const string& password = "f9w8feeh", const string& ip = "", const usmallint port = 0);

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgPlnrDatabase* comp);
	set<uint> diff(const StgPlnrDatabase* comp);
};

/**
	* StgPlnrPath
	*/
class StgPlnrPath : public Block {

public:
	static const uint ACVPATH = 1;
	static const uint TMPPATH = 2;
	static const uint WEBPATH = 3;
	static const uint HELPURL = 4;

public:
	StgPlnrPath(const string& acvpath = "", const string& tmppath = "", const string& webpath = "", const string& helpurl = "");

public:
	string acvpath;
	string tmppath;
	string webpath;
	string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgPlnrPath* comp);
	set<uint> diff(const StgPlnrPath* comp);
};

/**
  * AlrPlnr
  */
namespace AlrPlnr {
	DpchEngPlnrAlert* prepareAlrAbt(const ubigint jref, const uint ixPlnrVLocale, Feed& feedFMcbAlert);
	DpchEngPlnrAlert* prepareAlrPer(const ubigint jref, const uint ixPlnrVLocale, const string& lineno, Feed& feedFMcbAlert);
	DpchEngPlnrAlert* prepareAlrSav(const ubigint jref, const uint ixPlnrVLocale, Feed& feedFMcbAlert);
};

/**
  * ReqPlnr
  */
class ReqPlnr {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const uint NONE = 0; // invalid
		static const uint WEB = 1; // web-client triggered ui file request (GET)
		static const uint CMD = 2; // command-line request
		static const uint REGULAR = 3; // web-client triggered Dpch request (POST+Dpch)
		static const uint NOTIFY = 4; // web-client triggered notify-on-Dpch request (POST/empty)
		static const uint POLL = 5; // web-client triggered Dpch poll request (POST/empty)
		static const uint UPLOAD = 6; // web-client triggered file upload request (POST)
		static const uint DOWNLOAD = 7; // web-client triggered file download request (GET)
		static const uint RET = 8; // op-engine or opprc triggered op return (DpchRet)
		static const uint TIMER = 9; // timer triggered request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint NONE = 0; // invalid
		static const uint RECEIVE = 1; // during data reception - appsrv internal
		static const uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const uint PRC = 3; // while being processesd by job processor - still in reqs list ; appsrv thread waiting on cReply
		static const uint REPLY = 4; // while reply being transmitted by appsrv - appsrv internal
	};

public:
	ReqPlnr(const uint ixVBasetype = VecVBasetype::NONE, const uint ixVState = VecVState::RECEIVE, const string& ip = "");
	~ReqPlnr();

public:
	uint ixVBasetype;
	uint ixVState;

	// specific data for base type CMD
	string cmd;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD
	string ip;

	// specific data for base types REGULAR, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, REGULAR, NOTIFY, UPLOAD, DOWNLOAD
	bool retain;
	pthread_mutex_t mcReady; // also protects compare/set of ixVState to REPLY
	pthread_cond_t cReady;

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	string filename; // full path
	fstream* file;
	size_t filelen;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* request;
	size_t requestlen;

	// specific data for base types CMD, REGULAR, NOTIFY, POLL, UPLOAD, DOWNLOAD, RET, TIMER
	ubigint jref;

	// specific data for base type TIMER
	ubigint wref;
	string sref;

	// specific data for base types CMD, REGULAR, UPLOAD, DOWNLOAD, RET, TIMER
	bool weak;

	// specific data for base type REGULAR
	DpchAppPlnr* dpchapp;

	// specific data for base types REGULAR, NOTIFY, POLL
	DpchEngPlnr* dpcheng;
	uint ixPlnrVLocale;

	// specific data for base type RET
	DpchInvPlnr* dpchinv;
	DpchRetPlnr* dpchret;

	// specific data for base types REGULAR, NOTIFY, POLL, RET
	char* reply;
	size_t replylen;

public:
	void setStateReply();
};

/**
  * ReqopengconPlnr
  */
class ReqopengconPlnr {

public:
	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint RECEIVE = 0; // during data reception - opengconsrv internal
		static const uint REPLY = 1; // while reply being transmitted by opengconsrv - opengconsrv internal
	};

public:
	ReqopengconPlnr(const uint ixVState = VecVState::RECEIVE, const string& ip = "");
	~ReqopengconPlnr();

public:
	uint ixVState;
	string ip;

	MHD_PostProcessor* pp;

	char* request;
	size_t requestlen;

	DpchPlnr* dpchopd;

	char* reply;
	size_t replylen;
};

/**
	* DcolPlnr
	*/
class DcolPlnr {

public:
	DcolPlnr(const ubigint jref = 0, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS);
	~DcolPlnr();

public:
	ubigint jref;

	uint ixPlnrVLocale;

	pthread_mutex_t mAccess;

	bool hot;

	list<DpchEngPlnr*> dpchs;

	ReqPlnr* req;

public:
	int lockAccess(const string& srefObject = "", const string& srefMember = "");
	int unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * JobPlnr
  */
class JobPlnr {

public:
	JobPlnr(XchgPlnr* xchg, const uint ixPlnrVJob = 0, const ubigint jrefSup = 0, const uint ixPlnrVLocale = VecPlnrVLocale::ENUS, const bool prefmast = false);
	virtual ~JobPlnr();

public:
	XchgPlnr* xchg;

	ubigint jref;

	uint ixPlnrVJob;

	ubigint jrefSup;
	set<ubigint> jrefsSub;

	uint ixPlnrVLocale;

	ubigint jrefMast;
	list<ubigint> jrefsSlv;

	bool prefmast;

	pthread_mutex_t mAccess;

	uint ixVSge;
	uint nextIxVSge;

	uint opNdone;
	uint opN;

	vector<DpchInvPlnr*> invs;

	pthread_mutex_t mOps;
	list<Op*> ops;
	string opsqkLast;

	ubigint wrefLast;
	ubigint wrefMin;

	ReqPlnr* reqCmd;

public:
	virtual string getSquawk(DbsPlnr* dbsplnr);

	virtual void giveupMaster(DbsPlnr* dbsplnr);
	virtual void giveupSlave(DbsPlnr* dbsplnr);
	virtual void becomeMaster(DbsPlnr* dbsplnr);
	virtual void becomeSlave(DbsPlnr* dbsplnr);

	virtual bool handleClaimMaster(DbsPlnr* dbsplnr);
	virtual void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);
	virtual void handleCall(DbsPlnr* dbsplnr, Call* call);

	int lockAccess(const string& srefObject, const string& srefMember);
	int trylockAccess(const string& srefObject, const string& srefMember);
	int unlockAccess(const string& srefObject, const string& srefMember);
	int lockAccess(const string& srefMember);
	int unlockAccess(const string& srefMember);

	void clearInvs();
	void addInv(DpchInvPlnr* inv);
	void addInvs(vector<DpchInvPlnr*>& _invs);
	void submitInvs(DbsPlnr* dbsplnr, const uint emptyIxVSge, uint& _ixVSge);

	void clearOps();
	void addOp(DbsPlnr* dbsplnr, DpchInvPlnr* inv);
	void removeOp(const ubigint oref);
	string getOpsqkLast();

	void callback(const uint _nextIxVSge);
	void invalidateWakeups();
};

/**
  * StmgrPlnr
  */
class StmgrPlnr {

public:
	StmgrPlnr(XchgPlnr* xchg, const ubigint jref, const uint ixVNonetype);
	~StmgrPlnr();

public:
	XchgPlnr* xchg;

	ubigint jref;
	uint ixVNonetype;

	Stcch* stcch;

	pthread_mutex_t mAccess;

public:
	void handleCall(DbsPlnr* dbsplnr, Call* call);
	bool refresh(DbsPlnr* dbsplnr, Stcchitem* stit);

	void begin();
	void commit();

	int lockAccess(const string& srefObject = "", const string& srefMember = "");
	int unlockAccess(const string& srefObject = "", const string& srefMember = "");
};

/**
  * WakeupPlnr
  */
class WakeupPlnr {

public:
	WakeupPlnr(XchgPlnr* xchg, const ubigint wref, const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);

public:
	XchgPlnr* xchg;

	ubigint wref;

	ubigint jref;
	string sref;
	unsigned int deltat;
	bool weak;
};

/**
  * ConopengPlnr
  */
class ConopengPlnr {

public:
	ConopengPlnr(const string& ip = "", const uint port = 0);
	~ConopengPlnr();

public:
	CURL* curl;

	bool busy;
};

/**
  * NodePlnr
  */
class NodePlnr {

public:
	NodePlnr(const ubigint nref, const string& ip, const uint port, const uint opprcn, const vector<string>& srefsOpk);
	~NodePlnr();

public:
	ubigint nref;

	string ip;
	uint port;
	uint opprcn;
	set<uint> icsPlnrVDpch;

	uint opprcbusy;

	pthread_mutex_t mCons;
	vector<ConopengPlnr*> cons;

public:
	ConopengPlnr* getCon();
};

/**
  * XchgdataPlnrJobprc
  */
class XchgdataPlnrJobprc {

public:
	XchgdataPlnrJobprc();

public:
// IP datajobprc --- INSERT
};

/**
  * XchgPlnrd
  */
class XchgPlnrd {

public:
	XchgPlnrd();
	~XchgPlnrd();

public:
	StgPlnrd stgplnrd;
	StgPlnrDatabase stgplnrdatabase;
	StgPlnrPath stgplnrpath;

	XchgdataPlnrJobprc datajobprc;

public:
// IP cust --- INSERT

public:
	// archive/temporary folder paths and help URL
	string acvpath;
	string tmppath;
	string helpurl;

	// root job
	ubigint jrefRoot;

	// job receiving commands
	ubigint jrefCmd;

	// scrambled ref codes
	pthread_mutex_t mScr;
	map<ubigint,string> scr;
	map<string,ubigint> descr;

	// log file
	pthread_mutex_t mLogfile;

	// condition for op engine client
	pthread_mutex_t mcOpengcli;
	pthread_cond_t cOpengcli;

	// condition for job processors
	pthread_mutex_t mcJobprcs;
	pthread_cond_t cJobprcs;

	// request list
	pthread_mutex_t mReqs;
	list<ReqPlnr*> reqs;

	// operation invocation list
	Refseq* orefseq;
	pthread_mutex_t mInvs;
	list<DpchInvPlnr*> invs;

	// presetting list
	pthread_mutex_t mPresets;
	multimap<pref_t,Preset*> presets;

	// stub manager list
	pthread_mutex_t mStmgrs;
	map<ubigint,StmgrPlnr*> stmgrs;

	// sequence for call listener references
	pthread_mutex_t mCrefseq;
	ubigint crefseq;

	// call listener list
	pthread_mutex_t mClstns;
	multimap<cref_t,Clstn*> clstns;
	multimap<cref2_t,cref_t> cref2sClstns;

	// dispatch collector list
	pthread_mutex_t mDcols;
	map<ubigint,DcolPlnr*> dcols;

	// job list
	Refseq* jrefseq;
	pthread_mutex_t mJobs;
	map<ubigint,JobPlnr*> jobs;

	// sequence for wakeup references
	Refseq* wrefseq;

	// node list
	Refseq* nrefseq;
	pthread_mutex_t mNodes;
	map<ubigint,NodePlnr*> nodes;

public:
	// log file methods
	void appendToLogfile(const string& str);

	// request list methods
	void addReq(ReqPlnr* req);
	ReqPlnr* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsPlnr* dbsplnr, const ubigint jref, vector<DpchInvPlnr*>& dpchinvs);
	bool pullFirstInv(DpchInvPlnr** dpchinv, NodePlnr** node);
	void returnInv(DpchInvPlnr* dpchinv);

	// presetting methods
	Preset* addPreset(const uint ixPlnrVPreset, const ubigint jref, const Arg& arg);

	Preset* addIxPreset(const uint ixPlnrVPreset, const ubigint jref, const uint ix);
	Preset* addRefPreset(const uint ixPlnrVPreset, const ubigint jref, const ubigint ref);
	Preset* addRefsPreset(const uint ixPlnrVPreset, const ubigint jref, const vector<ubigint>& refs);
	Preset* addSrefPreset(const uint ixPlnrVPreset, const ubigint jref, const string& sref);
	Preset* addIntvalPreset(const uint ixPlnrVPreset, const ubigint jref, const int intval);
	Preset* addDblvalPreset(const uint ixPlnrVPreset, const ubigint jref, const double dblval);
	Preset* addBoolvalPreset(const uint ixPlnrVPreset, const ubigint jref, const bool boolval);
	Preset* addTxtvalPreset(const uint ixPlnrVPreset, const ubigint jref, const string& txtval);

	Preset* getPresetByPref(const pref_t& pref);

	Arg getPreset(const uint ixPlnrVPreset, const ubigint jref);

	uint getIxPreset(const uint ixPlnrVPreset, const ubigint jref);
	ubigint getRefPreset(const uint ixPlnrVPreset, const ubigint jref);
	vector<ubigint> getRefsPreset(const uint ixPlnrVPreset, const ubigint jref);
	string getSrefPreset(const uint ixPlnrVPreset, const ubigint jref);
	int getIntvalPreset(const uint ixPlnrVPreset, const ubigint jref);
	double getDblvalPreset(const uint ixPlnrVPreset, const ubigint jref);
	bool getBoolvalPreset(const uint ixPlnrVPreset, const ubigint jref);
	string getTxtvalPreset(const uint ixPlnrVPreset, const ubigint jref);

	void getPresetsByJref(const ubigint jref, vector<uint>& icsPlnrVPreset, vector<Arg>& args);

	void removePreset(const uint ixPlnrVPreset, const ubigint jref);
	void removePresetsByJref(const ubigint jref);

	// stub manager methods
	StmgrPlnr* addStmgr(const ubigint jref, const uint ixVNonetype);
	StmgrPlnr* getStmgrByJref(const ubigint jref);
	void removeStmgrByJref(const ubigint jref);

	// call listener list methods
	Clstn* addClstn(const uint ixPlnrVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const Arg& argMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addIxClstn(const uint ixPlnrVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addRefClstn(const uint ixPlnrVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefClstn(const uint ixPlnrVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);
	Clstn* addIxRefSrefClstn(const uint ixPlnrVCall, const ubigint jref, const uint ixVJobmask, const ubigint jrefTrig, const uint ixMask, const ubigint refMask, const string& srefMask, const uint ixVJactype = Clstn::VecVJactype::LOCK);

	Clstn* addClstnStmgr(const uint ixPlnrVCall, const ubigint jref);

	Clstn* getClstnByCref(const cref_t& cref);
	void getClstnsByJref(const ubigint jref, const bool stmgr, vector<uint>& icsPlnrVCall, vector<uint>& icsVJobmask);

	void removeClstns(const uint ixPlnrVCall, const ubigint jref, const bool stmgr = false);
	void removeClstnsByJref(const ubigint jref, const bool stmgr = false);

	// call methods
	void findJrefsByCall(Call* call, vector<ubigint>& jrefs, vector<bool>& stmgrs, vector<uint>& icsVJactype);

	void triggerCall(DbsPlnr* dbsplnr, Call* call);

	bool triggerArgToArgCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const Arg& argInv, Arg& argRet);
	bool triggerCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref);
	bool triggerIxCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv);
	bool triggerRefCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const ubigint refInv);
	bool triggerIntvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const ubigint refInv);
	bool triggerIxSrefCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const string& srefInv);
	bool triggerIxIntvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const double dblvalInv);
	bool triggerToBoolvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, bool& boolvalRet);
	bool triggerRefToBoolvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const ubigint refInv, uint& ixRet);
	bool triggerIxRefToRefCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const ubigint refInv, ubigint& refRet);
	bool triggerIxRefSrefCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const uint ixInv, const ubigint refInv, const string& srefInv, const int intvalInv, ubigint& refRet);
	bool triggerRefToIxCall(DbsPlnr* dbsplnr, const uint ixPlnrVCall, const ubigint jref, const ubigint refInv, uint& ixRet);

	// dispatch collector list methods
	DcolPlnr* addDcol(const ubigint jref);
	DcolPlnr* getDcolByJref(const ubigint jref, const bool tree = true);
	void removeDcolByJref(const ubigint jref);

	void submitDpch(DpchEngPlnr* dpcheng);
	DpchEngPlnr* pullFirstDpch(DcolPlnr* dcol);

	// job list methods
	ubigint addJob(JobPlnr* job);
	ubigint addJob(DbsPlnr* dbsplnr, JobPlnr* job);

	JobPlnr* getJobByJref(const ubigint jref);

	void removeJobByJref(const ubigint jref);

	void transferMaster(DbsPlnr* dbsplnr, JobPlnr* fromjob, JobPlnr* tojob);
	void offerMaster(DbsPlnr* dbsplnr, const ubigint jref);
	bool claimMaster(DbsPlnr* dbsplnr, const ubigint jref);

	// timer methods
	ubigint addWakeup(const ubigint jref, const string sref, const unsigned int deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// node methods
	NodePlnr* addNode(const string& ip, const uint port, const uint opprcn, const vector<string>& srefsOpk);
	NodePlnr* getNodeByNref(const ubigint nref);
	void removeNodeByNref(const ubigint nref);
};
#endif


