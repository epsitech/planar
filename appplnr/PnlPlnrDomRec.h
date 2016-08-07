/**
  * \file PnlPlnrDomRec.h
  * app access code for job PnlPlnrDomRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDOMREC_H
#define PNLPLNRDOMREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDomRec
  */
namespace PnlPlnrDomRec {
	/**
		* VecVDo (full: VecVPlnrDomRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDomRec)
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
	  * StatApp (full: StatAppPlnrDomRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEMNCALC = 2;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneMNCalc = false);

	public:
		bool initdoneDetail;
		bool initdoneMNCalc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDomRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFMNCALC = 3;
		static const uint BUTREGULARIZEACTIVE = 4;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefMNCalc = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJrefMNCalc;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDomRec)
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
		* DpchAppDo (full: DpchAppPlnrDomRecDo)
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
		* DpchEngData (full: DpchEngPlnrDomRecData)
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

