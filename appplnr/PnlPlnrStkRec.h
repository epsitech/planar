/**
  * \file PnlPlnrStkRec.h
  * app access code for job PnlPlnrStkRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSTKREC_H
#define PNLPLNRSTKREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrStkRec
  */
namespace PnlPlnrStkRec {
	/**
		* VecVDo (full: VecVPlnrStkRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrStkRec)
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
	  * StatApp (full: StatAppPlnrStkRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEVIEW = 3;
		static const uint INITDONEHK1NLEVEL = 4;
		static const uint INITDONEHK1NLAYER = 5;
		static const uint INITDONEMNSTRUCTURE = 6;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneHk1NLevel = false, const bool initdoneHk1NLayer = false, const bool initdoneMNStructure = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneView;
		bool initdoneHk1NLevel;
		bool initdoneHk1NLayer;
		bool initdoneMNStructure;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrStkRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFVIEW = 4;
		static const uint SCRJREFHK1NLEVEL = 5;
		static const uint SCRJREFHK1NLAYER = 6;
		static const uint SCRJREFMNSTRUCTURE = 7;
		static const uint PNLMNSTRUCTUREAVAIL = 8;
		static const uint BUTREGULARIZEACTIVE = 9;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefView = "", const string& scrJrefHk1NLevel = "", const string& scrJrefHk1NLayer = "", const string& scrJrefMNStructure = "", const bool pnlmnstructureAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefView;
		string scrJrefHk1NLevel;
		string scrJrefHk1NLayer;
		string scrJrefMNStructure;
		bool pnlmnstructureAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrStkRec)
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
		* DpchAppDo (full: DpchAppPlnrStkRecDo)
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
		* DpchEngData (full: DpchEngPlnrStkRecData)
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

