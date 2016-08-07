/**
  * \file PnlPlnrNavCalc.h
  * app access code for job PnlPlnrNavCalc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVCALC_H
#define PNLPLNRNAVCALC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavCalc
  */
namespace PnlPlnrNavCalc {
	/**
		* VecVDo (full: VecVPlnrNavCalcDo)
		*/
	class VecVDo {

	public:
		static const uint BUTCLCVIEWCLICK = 1;
		static const uint BUTCLCNEWCRDCLICK = 2;
		static const uint BUTCLIVIEWCLICK = 3;
		static const uint BUTCLINEWCRDCLICK = 4;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavCalc)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTCLC = 1;
		static const uint NUMFLSTCLI = 2;

	public:
		ContIac(const uint numFLstClc = 1, const uint numFLstCli = 1);

	public:
		uint numFLstClc;
		uint numFLstCli;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrNavCalc)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTCLCALT = 2;
		static const uint LSTCLIALT = 3;
		static const uint LSTCLCNUMFIRSTDISP = 4;
		static const uint LSTCLINUMFIRSTDISP = 5;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstClcAlt = true, const bool LstCliAlt = true, const uint LstClcNumFirstdisp = 1, const uint LstCliNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstClcAlt;
		bool LstCliAlt;
		uint LstClcNumFirstdisp;
		uint LstCliNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNavCalc)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTCLCAVAIL = 1;
		static const uint BUTCLCVIEWACTIVE = 2;
		static const uint BUTCLCNEWCRDACTIVE = 3;
		static const uint LSTCLIAVAIL = 4;
		static const uint BUTCLIVIEWACTIVE = 5;
		static const uint BUTCLINEWCRDACTIVE = 6;

	public:
		StatShr(const bool LstClcAvail = true, const bool ButClcViewActive = true, const bool ButClcNewcrdActive = true, const bool LstCliAvail = true, const bool ButCliViewActive = true, const bool ButCliNewcrdActive = true);

	public:
		bool LstClcAvail;
		bool ButClcViewActive;
		bool ButClcNewcrdActive;
		bool LstCliAvail;
		bool ButCliViewActive;
		bool ButCliNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNavCalc)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTCLC = 2;
		static const uint CPTCLI = 3;

	public:
		Tag(const string& Cpt = "", const string& CptClc = "", const string& CptCli = "");

	public:
		string Cpt;
		string CptClc;
		string CptCli;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavCalcData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrNavCalcDo)
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
		* DpchEngData (full: DpchEngPlnrNavCalcData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTCLC = 3;
		static const uint FEEDFLSTCLI = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstClc;
		Feed feedFLstCli;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

