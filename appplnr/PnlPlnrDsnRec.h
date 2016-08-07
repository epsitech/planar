/**
  * \file PnlPlnrDsnRec.h
  * app access code for job PnlPlnrDsnRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNREC_H
#define PNLPLNRDSNREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDsnRec
  */
namespace PnlPlnrDsnRec {
	/**
		* VecVDo (full: VecVPlnrDsnRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDsnRec)
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
	  * StatApp (full: StatAppPlnrDsnRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEVIEWXY = 3;
		static const uint INITDONEVIEWZ = 4;
		static const uint INITDONEMOD1NDESIGN = 5;
		static const uint INITDONEDRV1NDESIGN = 6;
		static const uint INITDONEDSN1NDEVICE = 7;
		static const uint INITDONEDSN1NSTACK = 8;
		static const uint INITDONEDSN1NDOMAINGD = 9;
		static const uint INITDONEDSN1NDOMAIN = 10;
		static const uint INITDONE1NBLOCK = 11;
		static const uint INITDONE1NRETICLE = 12;
		static const uint INITDONEHK1NLEVEL = 13;
		static const uint INITDONEHK1NVERTEX = 14;
		static const uint INITDONEHK1NLINEGUIDE = 15;
		static const uint INITDONEHK1NARCGUIDE = 16;
		static const uint INITDONEHK1NLAYER = 17;
		static const uint INITDONEHK1NSTRUCTURE = 18;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneViewxy = false, const bool initdoneViewz = false, const bool initdoneMod1NDesign = false, const bool initdoneDrv1NDesign = false, const bool initdoneDsn1NDevice = false, const bool initdoneDsn1NStack = false, const bool initdoneDsn1NDomaingd = false, const bool initdoneDsn1NDomain = false, const bool initdone1NBlock = false, const bool initdone1NReticle = false, const bool initdoneHk1NLevel = false, const bool initdoneHk1NVertex = false, const bool initdoneHk1NLineguide = false, const bool initdoneHk1NArcguide = false, const bool initdoneHk1NLayer = false, const bool initdoneHk1NStructure = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneViewxy;
		bool initdoneViewz;
		bool initdoneMod1NDesign;
		bool initdoneDrv1NDesign;
		bool initdoneDsn1NDevice;
		bool initdoneDsn1NStack;
		bool initdoneDsn1NDomaingd;
		bool initdoneDsn1NDomain;
		bool initdone1NBlock;
		bool initdone1NReticle;
		bool initdoneHk1NLevel;
		bool initdoneHk1NVertex;
		bool initdoneHk1NLineguide;
		bool initdoneHk1NArcguide;
		bool initdoneHk1NLayer;
		bool initdoneHk1NStructure;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDsnRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFVIEWXY = 4;
		static const uint PNLVIEWXYAVAIL = 5;
		static const uint SCRJREFVIEWZ = 6;
		static const uint PNLVIEWZAVAIL = 7;
		static const uint SCRJREFMOD1NDESIGN = 8;
		static const uint PNLMOD1NDESIGNAVAIL = 9;
		static const uint SCRJREFDRV1NDESIGN = 10;
		static const uint SCRJREFDSN1NDEVICE = 11;
		static const uint PNLDSN1NDEVICEAVAIL = 12;
		static const uint SCRJREFDSN1NSTACK = 13;
		static const uint PNLDSN1NSTACKAVAIL = 14;
		static const uint SCRJREFDSN1NDOMAINGD = 15;
		static const uint SCRJREFDSN1NDOMAIN = 16;
		static const uint SCRJREF1NBLOCK = 17;
		static const uint PNL1NBLOCKAVAIL = 18;
		static const uint SCRJREF1NRETICLE = 19;
		static const uint PNL1NRETICLEAVAIL = 20;
		static const uint SCRJREFHK1NLEVEL = 21;
		static const uint PNLHK1NLEVELAVAIL = 22;
		static const uint SCRJREFHK1NVERTEX = 23;
		static const uint PNLHK1NVERTEXAVAIL = 24;
		static const uint SCRJREFHK1NLINEGUIDE = 25;
		static const uint PNLHK1NLINEGUIDEAVAIL = 26;
		static const uint SCRJREFHK1NARCGUIDE = 27;
		static const uint PNLHK1NARCGUIDEAVAIL = 28;
		static const uint SCRJREFHK1NLAYER = 29;
		static const uint PNLHK1NLAYERAVAIL = 30;
		static const uint SCRJREFHK1NSTRUCTURE = 31;
		static const uint PNLHK1NSTRUCTUREAVAIL = 32;
		static const uint BUTREGULARIZEACTIVE = 33;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefViewxy = "", const bool pnlviewxyAvail = false, const string& scrJrefViewz = "", const bool pnlviewzAvail = false, const string& scrJrefMod1NDesign = "", const bool pnlmod1ndesignAvail = false, const string& scrJrefDrv1NDesign = "", const string& scrJrefDsn1NDevice = "", const bool pnldsn1ndeviceAvail = false, const string& scrJrefDsn1NStack = "", const bool pnldsn1nstackAvail = false, const string& scrJrefDsn1NDomaingd = "", const string& scrJrefDsn1NDomain = "", const string& scrJref1NBlock = "", const bool pnl1nblockAvail = false, const string& scrJref1NReticle = "", const bool pnl1nreticleAvail = false, const string& scrJrefHk1NLevel = "", const bool pnlhk1nlevelAvail = false, const string& scrJrefHk1NVertex = "", const bool pnlhk1nvertexAvail = false, const string& scrJrefHk1NLineguide = "", const bool pnlhk1nlineguideAvail = false, const string& scrJrefHk1NArcguide = "", const bool pnlhk1narcguideAvail = false, const string& scrJrefHk1NLayer = "", const bool pnlhk1nlayerAvail = false, const string& scrJrefHk1NStructure = "", const bool pnlhk1nstructureAvail = false, const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefViewxy;
		bool pnlviewxyAvail;
		string scrJrefViewz;
		bool pnlviewzAvail;
		string scrJrefMod1NDesign;
		bool pnlmod1ndesignAvail;
		string scrJrefDrv1NDesign;
		string scrJrefDsn1NDevice;
		bool pnldsn1ndeviceAvail;
		string scrJrefDsn1NStack;
		bool pnldsn1nstackAvail;
		string scrJrefDsn1NDomaingd;
		string scrJrefDsn1NDomain;
		string scrJref1NBlock;
		bool pnl1nblockAvail;
		string scrJref1NReticle;
		bool pnl1nreticleAvail;
		string scrJrefHk1NLevel;
		bool pnlhk1nlevelAvail;
		string scrJrefHk1NVertex;
		bool pnlhk1nvertexAvail;
		string scrJrefHk1NLineguide;
		bool pnlhk1nlineguideAvail;
		string scrJrefHk1NArcguide;
		bool pnlhk1narcguideAvail;
		string scrJrefHk1NLayer;
		bool pnlhk1nlayerAvail;
		string scrJrefHk1NStructure;
		bool pnlhk1nstructureAvail;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDsnRec)
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
		* DpchAppDo (full: DpchAppPlnrDsnRecDo)
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
		* DpchEngData (full: DpchEngPlnrDsnRecData)
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

