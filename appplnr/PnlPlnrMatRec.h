/**
  * \file PnlPlnrMatRec.h
  * app access code for job PnlPlnrMatRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRMATREC_H
#define PNLPLNRMATREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrMatRec
  */
namespace PnlPlnrMatRec {
	/**
		* VecVDo (full: VecVPlnrMatRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrMatRec)
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
	  * StatApp (full: StatAppPlnrMatRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEAPAR = 2;
		static const uint INITDONE1NLAYER = 3;
		static const uint INITDONEMOD1NMATERIAL = 4;
		static const uint INITDONEREF1NFILE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdone1NLayer = false, const bool initdoneMod1NMaterial = false, const bool initdoneRef1NFile = false);

	public:
		bool initdoneDetail;
		bool initdoneAPar;
		bool initdone1NLayer;
		bool initdoneMod1NMaterial;
		bool initdoneRef1NFile;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrMatRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFAPAR = 3;
		static const uint SCRJREF1NLAYER = 4;
		static const uint SCRJREFMOD1NMATERIAL = 5;
		static const uint SCRJREFREF1NFILE = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefAPar = "", const string& scrJref1NLayer = "", const string& scrJrefMod1NMaterial = "", const string& scrJrefRef1NFile = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJrefAPar;
		string scrJref1NLayer;
		string scrJrefMod1NMaterial;
		string scrJrefRef1NFile;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrMatRec)
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
		* DpchAppDo (full: DpchAppPlnrMatRecDo)
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
		* DpchEngData (full: DpchEngPlnrMatRecData)
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

