/**
  * \file Plnropd_exe.h
  * Plnr operation daemon plnropd main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNROPD_EXE_H
#define PLNROPD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "PlnropdEngsrv.h"
#include "PlnropdOpprc.h"

/**
  * PrefPlnropd
  */
class PrefPlnropd : public Block {

public:
	static const uint STGPLNRDATABASE = 1;
	static const uint STGPLNROPD = 2;
	static const uint STGPLNRPATH = 3;
	static const uint ALL = 4;

public:
	PrefPlnropd(StgPlnrDatabase* stgplnrdatabase = NULL, StgPlnropd* stgplnropd = NULL, StgPlnrPath* stgplnrpath = NULL, const set<uint>& mask = {ALL});

public:
	StgPlnrDatabase stgplnrdatabase;
	StgPlnropd stgplnropd;
	StgPlnrPath stgplnrpath;

public:
	static bool all(const set<uint>& items);

	void readXMLFromFile(const string& fullpath);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXMLToFile(const string& fullpath);
	void writeXML(xmlTextWriter* wr);
};

/**
  * Plnropd
  */
class Plnropd {

public:
	Plnropd(const string& exedir);
	~Plnropd();

	void init();
	bool initdone;
	void term();

public:
	string exedir;

	XchgPlnropd* xchg;

	MHD_Daemon* engsrv;

	vector<pthread_t> opprcs;

public:
	char* curlrecv;
	size_t curlrecvlen;

	static uint CurlPostrecv(void* data, uint size, uint blocksize, void* _inst);
	bool CurlPostDpch(const string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, string& rplydpch);

public:
	void loadPref();
	void storePref();

	void initXchgdataOpprc();
	void termXchgdataOpprc();
};

Plnropd* plnropd;

#endif


