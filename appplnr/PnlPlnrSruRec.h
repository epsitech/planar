/**
  * \file PnlPlnrSruRec.h
  * app access code for job PnlPlnrSruRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRSRUREC_H
#define PNLPLNRSRUREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrSruRec
  */
namespace PnlPlnrSruRec {
	/**
		* VecVDo (full: VecVPlnrSruRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrSruRec)
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
	  * StatApp (full: StatAppPlnrSruRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONE1NBLOCK = 2;
		static const uint INITDONESRU1NFACE = 3;
		static const uint INITDONEMNLAYER = 4;
		static const uint INITDONEMNSTACK = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdone1NBlock = false, const bool initdoneSru1NFace = false, const bool initdoneMNLayer = false, const bool initdoneMNStack = false);

	public:
		bool initdoneDetail;
		bool initdone1NBlock;
		bool initdoneSru1NFace;
		bool initdoneMNLayer;
		bool initdoneMNStack;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrSruRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREF1NBLOCK = 3;
		static const uint PNL1NBLOCKAVAIL = 4;
		static const uint SCRJREFSRU1NFACE = 5;
		static const uint SCRJREFMNLAYER = 6;
		static const uint PNLMNLAYERAVAIL = 7;
		static const uint SCRJREFMNSTACK = 8;
		static const uint PNLMNSTACKAVAIL = 9;
		static const uint BUTREGULARIZEACTIVE = 10;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJref1NBlock = "", const bool pnl1nblockAvail = false, const string& scrJrefSru1NFace = "", const string& scrJrefMNLayer = "", const bool pnlmnlayerAvail = false, const string& scrJrefMNStack = "", const bool pnlmnstackAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJref1NBlock;
		bool pnl1nblockAvail;
		string scrJrefSru1NFace;
		string scrJrefMNLayer;
		bool pnlmnlayerAvail;
		string scrJrefMNStack;
		bool pnlmnstackAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrSruRec)
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
		* DpchAppDo (full: DpchAppPlnrSruRecDo)
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
		* DpchEngData (full: DpchEngPlnrSruRecData)
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

