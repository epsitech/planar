/**
  * \file PlnrExp_blks.h
  * invocation / return data blocks for operation pack PlnrExp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNREXP_BLKS_H
#define PLNREXP_BLKS_H

#include "Plnr.h"

/**
	* DpchInvPlnrExpColldev
	*/
class DpchInvPlnrExpColldev : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpColldev(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpColldsn
	*/
class DpchInvPlnrExpColldsn : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDESIGN = 3;

public:
	DpchInvPlnrExpColldsn(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDesign = 0);

public:
	ubigint refPlnrMDesign;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpCollstk
	*/
class DpchInvPlnrExpCollstk : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMSTACK = 3;

public:
	DpchInvPlnrExpCollstk(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMStack = 0);

public:
	ubigint refPlnrMStack;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpCorner
	*/
class DpchInvPlnrExpCorner : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpCorner(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpCross
	*/
class DpchInvPlnrExpCross : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpCross(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpDircoup
	*/
class DpchInvPlnrExpDircoup : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpDircoup(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpDiscres
	*/
class DpchInvPlnrExpDiscres : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpDiscres(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpDottext
	*/
class DpchInvPlnrExpDottext : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpDottext(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpDsn
	*/
class DpchInvPlnrExpDsn : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDESIGN = 3;

public:
	DpchInvPlnrExpDsn(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDesign = 0);

public:
	ubigint refPlnrMDesign;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpGratcpl
	*/
class DpchInvPlnrExpGratcpl : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpGratcpl(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpGray
	*/
class DpchInvPlnrExpGray : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpGray(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpImage
	*/
class DpchInvPlnrExpImage : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpImage(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpMarker
	*/
class DpchInvPlnrExpMarker : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpMarker(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPad
	*/
class DpchInvPlnrExpPad : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPad(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPhcsq
	*/
class DpchInvPlnrExpPhcsq : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPhcsq(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPhcsqneg
	*/
class DpchInvPlnrExpPhcsqneg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPhcsqneg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPhctrig
	*/
class DpchInvPlnrExpPhctrig : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPhctrig(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPhctrigneg
	*/
class DpchInvPlnrExpPhctrigneg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPhctrigneg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPhotdet
	*/
class DpchInvPlnrExpPhotdet : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPhotdet(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPie
	*/
class DpchInvPlnrExpPie : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPie(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpPinout
	*/
class DpchInvPlnrExpPinout : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpPinout(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpRoicadp
	*/
class DpchInvPlnrExpRoicadp : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpRoicadp(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpRtresneg
	*/
class DpchInvPlnrExpRtresneg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpRtresneg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpSpring
	*/
class DpchInvPlnrExpSpring : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpSpring(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpStkpertpl
	*/
class DpchInvPlnrExpStkpertpl : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMSTACK = 3;

public:
	DpchInvPlnrExpStkpertpl(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMStack = 0);

public:
	ubigint refPlnrMStack;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpStkregfill
	*/
class DpchInvPlnrExpStkregfill : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMSTACK = 3;

public:
	DpchInvPlnrExpStkregfill(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMStack = 0);

public:
	ubigint refPlnrMStack;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpVanderpauw
	*/
class DpchInvPlnrExpVanderpauw : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpVanderpauw(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWg
	*/
class DpchInvPlnrExpWg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWgbend
	*/
class DpchInvPlnrExpWgbend : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWgbend(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWgbendneg
	*/
class DpchInvPlnrExpWgbendneg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWgbendneg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWgneg
	*/
class DpchInvPlnrExpWgneg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWgneg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWgsusp
	*/
class DpchInvPlnrExpWgsusp : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWgsusp(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWgtap
	*/
class DpchInvPlnrExpWgtap : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWgtap(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

/**
	* DpchInvPlnrExpWgtapneg
	*/
class DpchInvPlnrExpWgtapneg : public DpchInvPlnr {

public:
	static const uint SCROREF = 1;
	static const uint OREF = 1;
	static const uint SCRJREF = 2;
	static const uint JREF = 2;
	static const uint REFPLNRMDEVICE = 3;

public:
	DpchInvPlnrExpWgtapneg(const ubigint oref = 0, const ubigint jref = 0, const ubigint refPlnrMDevice = 0);

public:
	ubigint refPlnrMDevice;

public:
	void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	void writeXML(pthread_mutex_t* mScr, map<ubigint,string>& scr, map<string,ubigint>& descr, xmlTextWriter* wr);
};

// IP cust --- IBEGIN
namespace PlnrExp_blks {
	void getInvs(DbsPlnr* dbsplnr, map<string, ubigint>& refsDtp, const ubigint refDsn, vector<DpchInvPlnr*>& dpchinvs);
};
// IP cust --- IEND

#endif


