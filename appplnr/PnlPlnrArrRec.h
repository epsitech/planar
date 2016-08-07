/**
  * \file PnlPlnrArrRec.h
  * app access code for job PnlPlnrArrRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRARRREC_H
#define PNLPLNRARRREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrArrRec
  */
namespace PnlPlnrArrRec {
	/**
		* VecVDo (full: VecVPlnrArrRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrArrRec)
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
	  * StatApp (full: StatAppPlnrArrRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEKENVKEY = 2;
		static const uint INITDONEAENV = 3;
		static const uint INITDONE1NARRAYITEM = 4;
		static const uint INITDONEHK1NRETICLE = 5;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneKEnvKey = false, const bool initdoneAEnv = false, const bool initdone1NArrayitem = false, const bool initdoneHk1NReticle = false);

	public:
		bool initdoneDetail;
		bool initdoneKEnvKey;
		bool initdoneAEnv;
		bool initdone1NArrayitem;
		bool initdoneHk1NReticle;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrArrRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFKENVKEY = 3;
		static const uint SCRJREFAENV = 4;
		static const uint SCRJREF1NARRAYITEM = 5;
		static const uint SCRJREFHK1NRETICLE = 6;
		static const uint BUTREGULARIZEACTIVE = 7;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefKEnvKey = "", const string& scrJrefAEnv = "", const string& scrJref1NArrayitem = "", const string& scrJrefHk1NReticle = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJrefKEnvKey;
		string scrJrefAEnv;
		string scrJref1NArrayitem;
		string scrJrefHk1NReticle;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrArrRec)
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
		* DpchAppDo (full: DpchAppPlnrArrRecDo)
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
		* DpchEngData (full: DpchEngPlnrArrRecData)
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

