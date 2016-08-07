/**
  * \file Plnrcmbd_exe.h
  * Plnr combined daemon main (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRCMBD_EXE_H
#define PLNRCMBD_EXE_H

#include <string>
#include <vector>

using namespace std;

#include <signal.h>

#include "PlnrcmbdAppsrv.h"
#include "PlnrcmbdJobprc.h"
#include "PlnrcmbdOpprc.h"

/**
  * PrefPlnrcmbd
  */
class PrefPlnrcmbd : public Block {

public:
	static const uint STGPLNRCMBD = 1;
	static const uint STGPLNRDATABASE = 2;
	static const uint STGPLNRPATH = 3;
	static const uint ALL = 4;

public:
	PrefPlnrcmbd(StgPlnrcmbd* stgplnrcmbd = NULL, StgPlnrDatabase* stgplnrdatabase = NULL, StgPlnrPath* stgplnrpath = NULL, const set<uint>& mask = {ALL});

public:
	StgPlnrcmbd stgplnrcmbd;
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
  * Plnrcmbd
  */
class Plnrcmbd {

public:
	Plnrcmbd(const string& exedir);
	~Plnrcmbd();

	void init();
	bool initdone;
	void term();

public:
	string exedir;

	unsigned int jrefCmd;

	DbsPlnr dbsplnr;

	XchgPlnrcmbd* xchg;
	
	RootPlnr* root;

	MHD_Daemon* appsrv;

	vector<pthread_t> jobprcs;

	vector<pthread_t> opprcs;

public:
	void loadPref();
	void storePref();

	void initXchgdataJobprc();
	void termXchgdataJobprc();

	void initXchgdataOpprc();
	void termXchgdataOpprc();
};

Plnrcmbd* plnrcmbd;

#endif


