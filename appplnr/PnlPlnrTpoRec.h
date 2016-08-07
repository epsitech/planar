/**
  * \file PnlPlnrTpoRec.h
  * app access code for job PnlPlnrTpoRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRTPOREC_H
#define PNLPLNRTPOREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrTpoRec
  */
namespace PnlPlnrTpoRec {
	/**
		* VecVDo (full: VecVPlnrTpoRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrTpoRec)
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
	  * StatApp (full: StatAppPlnrTpoRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEFLOORPLAN = 2;
		static const uint INITDONE1NARRAY = 3;
		static const uint INITDONEHK1NRETICLE = 4;
		static const uint INITDONEMNPROJECT = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneFloorplan = false, const bool initdone1NArray = false, const bool initdoneHk1NReticle = false, const bool initdoneMNProject = false);

	public:
		bool initdoneDetail;
		bool initdoneFloorplan;
		bool initdone1NArray;
		bool initdoneHk1NReticle;
		bool initdoneMNProject;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrTpoRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFFLOORPLAN = 3;
		static const uint SCRJREF1NARRAY = 4;
		static const uint SCRJREFHK1NRETICLE = 5;
		static const uint SCRJREFMNPROJECT = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefFloorplan = "", const string& scrJref1NArray = "", const string& scrJrefHk1NReticle = "", const string& scrJrefMNProject = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJrefFloorplan;
		string scrJref1NArray;
		string scrJrefHk1NReticle;
		string scrJrefMNProject;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrTpoRec)
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
		* DpchAppDo (full: DpchAppPlnrTpoRecDo)
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
		* DpchEngData (full: DpchEngPlnrTpoRecData)
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

