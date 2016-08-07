/**
  * \file PnlPlnrCtpRec.h
  * app access code for job PnlPlnrCtpRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRCTPREC_H
#define PNLPLNRCTPREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrCtpRec
  */
namespace PnlPlnrCtpRec {
	/**
		* VecVDo (full: VecVPlnrCtpRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrCtpRec)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTREF = 1;

	public:
		ContInf(const string& TxtRef = "");

	public:
		string TxtRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrCtpRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEKENVKEY = 2;
		static const uint INITDONEKPARCAT = 3;
		static const uint INITDONEKPARPROP = 4;
		static const uint INITDONEKCALCDOMPRP = 5;
		static const uint INITDONEKCALCVAR = 6;
		static const uint INITDONEAENV = 7;
		static const uint INITDONEAPAR = 8;
		static const uint INITDONESUP1NCALC = 9;
		static const uint INITDONEREF1NFILE = 10;
		static const uint INITDONETPL1NCALC = 11;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKEnvKey = false, const bool initdoneKParCat = false, const bool initdoneKParProp = false, const bool initdoneKCalcdomprp = false, const bool initdoneKCalcvar = false, const bool initdoneAEnv = false, const bool initdoneAPar = false, const bool initdoneSup1NCalc = false, const bool initdoneRef1NFile = false, const bool initdoneTpl1NCalc = false);

	public:
		bool initdoneDetail;
		bool initdoneKEnvKey;
		bool initdoneKParCat;
		bool initdoneKParProp;
		bool initdoneKCalcdomprp;
		bool initdoneKCalcvar;
		bool initdoneAEnv;
		bool initdoneAPar;
		bool initdoneSup1NCalc;
		bool initdoneRef1NFile;
		bool initdoneTpl1NCalc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrCtpRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFKENVKEY = 3;
		static const uint SCRJREFKPARCAT = 4;
		static const uint SCRJREFKPARPROP = 5;
		static const uint SCRJREFKCALCDOMPRP = 6;
		static const uint SCRJREFKCALCVAR = 7;
		static const uint SCRJREFAENV = 8;
		static const uint SCRJREFAPAR = 9;
		static const uint SCRJREFSUP1NCALC = 10;
		static const uint SCRJREFREF1NFILE = 11;
		static const uint SCRJREFTPL1NCALC = 12;
		static const uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefKEnvKey = "", const string& scrJrefKParCat = "", const string& scrJrefKParProp = "", const string& scrJrefKCalcdomprp = "", const string& scrJrefKCalcvar = "", const string& scrJrefAEnv = "", const string& scrJrefAPar = "", const string& scrJrefSup1NCalc = "", const string& scrJrefRef1NFile = "", const string& scrJrefTpl1NCalc = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJrefKEnvKey;
		string scrJrefKParCat;
		string scrJrefKParProp;
		string scrJrefKCalcdomprp;
		string scrJrefKCalcvar;
		string scrJrefAEnv;
		string scrJrefAPar;
		string scrJrefSup1NCalc;
		string scrJrefRef1NFile;
		string scrJrefTpl1NCalc;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrCtpRec)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;

	public:
		Tag(const string& Cpt = "");

	public:
		string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrCtpRecDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngPlnrCtpRecData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATAPP = 3;
		static const uint STATSHR = 4;
		static const uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

