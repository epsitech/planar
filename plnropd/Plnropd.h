/**
  * \file Plnropd.h
  * inter-thread exchange object for Plnr operation daemon plnropd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNROPD_H
#define PLNROPD_H

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

#ifdef _WIN32
	#include <pthread.h>
#endif

#include <microhttpd.h>

#include <curl/curl.h>

#include "Plnr.h"

class XchgPlnropd;
typedef XchgPlnropd XchgPlnr;

/**
  * DpchPlnrdReg (written by dOpengconsrv, read by opd_exe)
  */
class DpchPlnrdReg : public DpchPlnr {

public:
	static const uint SCRNREF = 1;

public:
	DpchPlnrdReg();

public:
	string scrNref;

public:
	static bool all(const set<uint>& items);

	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
};

/**
  * DpchPlnropdAck (written by opd_exe, identified by d_exe)
  */
namespace DpchPlnropdAck {
	void writeXML(xmlTextWriter* wr);
};

/**
  * DpchPlnropdReg (written by opd_exe, read by dOpengconsrv)
  */
namespace DpchPlnropdReg {
	void writeXML(xmlTextWriter* wr, const usmallint port = 0, const vector<string>& srefsOpk = {}, const usmallint opprcn = 0);
};

/**
  * DpchPlnropdUnreg (written by opd_exe, read by dOpengconsrv)
  */
namespace DpchPlnropdUnreg {
	void writeXML(xmlTextWriter* wr, const string& scrNref = "");
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
	* StgPlnropd
	*/
class StgPlnropd : public Block {

public:
	static const uint ENGCLIIP = 1;
	static const uint ENGCLIPORT = 2;
	static const uint ENGSRVPORT = 3;
	static const uint OPPRCN = 4;

public:
	StgPlnropd(const string& engcliip = "", const usmallint engcliport = 0, const usmallint engsrvport = 0, const usmallint opprcn = 1);

public:
	string engcliip;
	usmallint engcliport;
	usmallint engsrvport;
	usmallint opprcn;

public:
	bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
	set<uint> comm(const StgPlnropd* comp);
	set<uint> diff(const StgPlnropd* comp);
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
  * ReqopPlnr
  */
class ReqopPlnr {

public:
	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const uint RECEIVE = 0; // during data reception - engsrv internal
		static const uint WAITPRC = 1; // before caught by op processor that is idle - in reqs list
		static const uint PRC = 2; // while being processesd by op processor - still in reqs list ; engsrv thread waiting on cReply
		static const uint REPLY = 3; // while reply being transmitted by engsrv - engsrv internal
	};

public:
	ReqopPlnr(const uint ixVState = VecVState::RECEIVE);
	~ReqopPlnr();

public:
	uint ixVState;

	MHD_PostProcessor* pp;

	pthread_mutex_t mcReady;
	pthread_cond_t cReady;

	char* request;
	size_t requestlen;

	DpchInvPlnr* dpchinv;

	DpchRetPlnr* dpchret;

	char* reply;
	size_t replylen;
};

/**
  * XchgdataPlnrOpprc
  */
class XchgdataPlnrOpprc {

public:
	XchgdataPlnrOpprc();

public:
// IP dataopprc --- INSERT
};

/**
  * XchgPlnropd
  */
class XchgPlnropd {

public:
	XchgPlnropd();
	~XchgPlnropd();

public:
	StgPlnrDatabase stgplnrdatabase;
	StgPlnropd stgplnropd;
	StgPlnrPath stgplnrpath;

	XchgdataPlnrOpprc dataopprc;

public:
// IP cust --- INSERT

public:
	// archive/temporary folder paths and help URL
	string acvpath;
	string tmppath;
	string helpurl;

	// node reference as assigned by engine
	string scrNref;

	// mutex for log file
	pthread_mutex_t mLogfile;

	// condition for termination
	pthread_mutex_t mcTerm;
	pthread_cond_t cTerm;

	// condition for op processors
	pthread_mutex_t mcOpprcs;
	pthread_cond_t cOpprcs;

	// request list
	pthread_mutex_t mReqs;
	list<ReqopPlnr*> reqs;

public:
	// log file methods
	void appendToLogfile(const string& str);

	// request list methods
	void addReq(ReqopPlnr* req);
	ReqopPlnr* pullFirstReq();
};

#endif


