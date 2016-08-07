/**
  * \file PnlPlnrDvcRec.h
  * app access code for job PnlPlnrDvcRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDVCREC_H
#define PNLPLNRDVCREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDvcRec
  */
namespace PnlPlnrDvcRec {
	/**
		* VecVDo (full: VecVPlnrDvcRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDvcRec)
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
	  * StatApp (full: StatAppPlnrDvcRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEVIEW = 3;
		static const uint INITDONEAPAR = 4;
		static const uint INITDONESUP1NDEVICE = 5;
		static const uint INITDONEHK1NSTRUCTURE = 6;
		static const uint INITDONEHK1NVERTEX = 7;
		static const uint INITDONEHK1NLINEGUIDE = 8;
		static const uint INITDONEHK1NARCGUIDE = 9;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneAPar = false, const bool initdoneSup1NDevice = false, const bool initdoneHk1NStructure = false, const bool initdoneHk1NVertex = false, const bool initdoneHk1NLineguide = false, const bool initdoneHk1NArcguide = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneView;
		bool initdoneAPar;
		bool initdoneSup1NDevice;
		bool initdoneHk1NStructure;
		bool initdoneHk1NVertex;
		bool initdoneHk1NLineguide;
		bool initdoneHk1NArcguide;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDvcRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFVIEW = 4;
		static const uint SCRJREFAPAR = 5;
		static const uint SCRJREFSUP1NDEVICE = 6;
		static const uint SCRJREFHK1NSTRUCTURE = 7;
		static const uint SCRJREFHK1NVERTEX = 8;
		static const uint SCRJREFHK1NLINEGUIDE = 9;
		static const uint SCRJREFHK1NARCGUIDE = 10;
		static const uint BUTREGULARIZEACTIVE = 11;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefView = "", const string& scrJrefAPar = "", const string& scrJrefSup1NDevice = "", const string& scrJrefHk1NStructure = "", const string& scrJrefHk1NVertex = "", const string& scrJrefHk1NLineguide = "", const string& scrJrefHk1NArcguide = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefView;
		string scrJrefAPar;
		string scrJrefSup1NDevice;
		string scrJrefHk1NStructure;
		string scrJrefHk1NVertex;
		string scrJrefHk1NLineguide;
		string scrJrefHk1NArcguide;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDvcRec)
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
		* DpchAppDo (full: DpchAppPlnrDvcRecDo)
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
		* DpchEngData (full: DpchEngPlnrDvcRecData)
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

