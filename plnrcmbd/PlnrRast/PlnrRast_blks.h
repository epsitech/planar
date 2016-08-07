/**
  * \file PlnrRast_blks.h
  * invocation / return data blocks for operation pack PlnrRast (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRAST_BLKS_H
#define PLNRRAST_BLKS_H

#include "Plnr.h"

/**
	* DpchInvPlnrRastCub
	*/
class DpchInvPlnrRastCub : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDESIGN = 3;

public:
	DpchInvPlnrRastCub(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDesign = 0);

public:
	ubigint refPlnrMDesign;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrRastCub
	*/
class DpchRetPlnrRastCub : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint REFPLNRMFILE = 4;

public:
	DpchRetPlnrRastCub(const string& scrOref = "", const string& scrJref = "", const bool success = false, const ubigint refPlnrMFile = 0);

public:
	bool success;
	ubigint refPlnrMFile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrRastXybox
	*/
class DpchInvPlnrRastXybox : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDESIGN = 3;

public:
	DpchInvPlnrRastXybox(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDesign = 0);

public:
	ubigint refPlnrMDesign;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrRastXybox
	*/
class DpchRetPlnrRastXybox : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint REFPLNRMFILE = 4;

public:
	DpchRetPlnrRastXybox(const string& scrOref = "", const string& scrJref = "", const bool success = false, const ubigint refPlnrMFile = 0);

public:
	bool success;
	ubigint refPlnrMFile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

/**
	* DpchInvPlnrRastZline
	*/
class DpchInvPlnrRastZline : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDESIGN = 3;

public:
	DpchInvPlnrRastZline(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDesign = 0);

public:
	ubigint refPlnrMDesign;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchRetPlnrRastZline
	*/
class DpchRetPlnrRastZline : public DpchRetPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint SUCCESS = 3;
	static const uint REFPLNRMFILE = 4;

public:
	DpchRetPlnrRastZline(const string& scrOref = "", const string& scrJref = "", const bool success = false, const ubigint refPlnrMFile = 0);

public:
	bool success;
	ubigint refPlnrMFile;

public:
	void readXML(pthread_mutex_t* mScr, map<string,ubigint>& descr, xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr);
};

// IP cust --- INSERT

#endif


