/**
  * \file PnlPlnrClcRec.h
  * app access code for job PnlPlnrClcRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRCLCREC_H
#define PNLPLNRCLCREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrClcRec
  */
namespace PnlPlnrClcRec {
	/**
		* VecVDo (full: VecVPlnrClcRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrClcRec)
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
	  * StatApp (full: StatAppPlnrClcRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEVIEW = 3;
		static const uint INITDONEAENV = 4;
		static const uint INITDONEAPAR = 5;
		static const uint INITDONECAL1NCALCITEM = 6;
		static const uint INITDONE1NMATERIAL = 7;
		static const uint INITDONESUP1NCALC = 8;
		static const uint INITDONEREF1NFILE = 9;
		static const uint INITDONEMNFILE = 10;
		static const uint INITDONEMNDOMAIN = 11;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneAEnv = false, const bool initdoneAPar = false, const bool initdoneCal1NCalcitem = false, const bool initdone1NMaterial = false, const bool initdoneSup1NCalc = false, const bool initdoneRef1NFile = false, const bool initdoneMNFile = false, const bool initdoneMNDomain = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneView;
		bool initdoneAEnv;
		bool initdoneAPar;
		bool initdoneCal1NCalcitem;
		bool initdone1NMaterial;
		bool initdoneSup1NCalc;
		bool initdoneRef1NFile;
		bool initdoneMNFile;
		bool initdoneMNDomain;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrClcRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFVIEW = 4;
		static const uint SCRJREFAENV = 5;
		static const uint SCRJREFAPAR = 6;
		static const uint SCRJREFCAL1NCALCITEM = 7;
		static const uint SCRJREF1NMATERIAL = 8;
		static const uint SCRJREFSUP1NCALC = 9;
		static const uint SCRJREFREF1NFILE = 10;
		static const uint SCRJREFMNFILE = 11;
		static const uint SCRJREFMNDOMAIN = 12;
		static const uint BUTREGULARIZEACTIVE = 13;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefView = "", const string& scrJrefAEnv = "", const string& scrJrefAPar = "", const string& scrJrefCal1NCalcitem = "", const string& scrJref1NMaterial = "", const string& scrJrefSup1NCalc = "", const string& scrJrefRef1NFile = "", const string& scrJrefMNFile = "", const string& scrJrefMNDomain = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefView;
		string scrJrefAEnv;
		string scrJrefAPar;
		string scrJrefCal1NCalcitem;
		string scrJref1NMaterial;
		string scrJrefSup1NCalc;
		string scrJrefRef1NFile;
		string scrJrefMNFile;
		string scrJrefMNDomain;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrClcRec)
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
		* DpchAppDo (full: DpchAppPlnrClcRecDo)
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
		* DpchEngData (full: DpchEngPlnrClcRecData)
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

