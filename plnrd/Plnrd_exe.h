/**
  * \file Plnrd_exe.h
  * Plnr daemon main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRD_EXE_H
#define PLNRD_EXE_H

#include <curl/curl.h>

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "PlnrdAppsrv.h"
#include "PlnrdJobprc.h"
#include "PlnrdOpengcli.h"
#include "PlnrdOpengconsrv.h"

/**
  * PrefPlnrd
  */
class PrefPlnrd : public Block {

public:
	static const uint STGPLNRD = 1;
	static const uint STGPLNRDATABASE = 2;
	static const uint STGPLNRPATH = 3;
	static const uint ALL = 4;

public:
	PrefPlnrd(StgPlnrd* stgplnrd = NULL, StgPlnrDatabase* stgplnrdatabase = NULL, StgPlnrPath* stgplnrpath = NULL, const set<uint>& mask = {ALL});

public:
	StgPlnrd stgplnrd;
	StgPlnrDatabase stgplnrdatabase;
	StgPlnrPath stgplnrpath;

public:
	static bool all(const set<uint>& items);

	void readXMLFromFile(const string& fullpath);
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXMLToFile(const string& fullpath);
	void writeXML(xmlTextWriter* wr);
};

/**
  * Plnrd
  */
class Plnrd {

public:
	Plnrd(const string& exedir);
	~Plnrd();

	void init();
	bool initdone;
	void term();

public:
	string exedir;

	unsigned int jrefCmd;

	DbsPlnr dbsplnr;

	XchgPlnrd* xchg;
	
	RootPlnr* root;

	MHD_Daemon* opengconsrv;
	MHD_Daemon* appsrv;

	pthread_t opengcli;

	vector<pthread_t> jobprcs;

public:
	char* curlrecv;
	size_t curlrecvlen;

	static uint CurlPostrecv(void* data, uint size, uint blocksize, void* _inst);
	bool CurlPostDpch(const string& url, xmlBuffer* xbuf, xmlDoc** rplydoc, xmlXPathContext** rplydocctx, string& rplydpch);

public:
	void loadPref();
	void storePref();

	void initXchgdataJobprc();
	void termXchgdataJobprc();
};

Plnrd* plnrd;

#endif


