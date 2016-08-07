/**
  * \file PnlPlnrNavDesign.h
  * app access code for job PnlPlnrNavDesign (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVDESIGN_H
#define PNLPLNRNAVDESIGN_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavDesign
  */
namespace PnlPlnrNavDesign {
	/**
		* VecVDo (full: VecVPlnrNavDesignDo)
		*/
	class VecVDo {

	public:
		static const uint BUTPRJVIEWCLICK = 1;
		static const uint BUTPRJNEWCRDCLICK = 2;
		static const uint BUTDSNVIEWCLICK = 3;
		static const uint BUTDSNNEWCRDCLICK = 4;
		static const uint BUTDOMVIEWCLICK = 5;
		static const uint BUTDOMNEWCRDCLICK = 6;
		static const uint BUTDGDVIEWCLICK = 7;
		static const uint BUTDGDNEWCRDCLICK = 8;
		static const uint BUTDVCVIEWCLICK = 9;
		static const uint BUTDVCNEWCRDCLICK = 10;
		static const uint BUTSRUVIEWCLICK = 11;
		static const uint BUTSRUNEWCRDCLICK = 12;
		static const uint BUTSTKVIEWCLICK = 13;
		static const uint BUTSTKNEWCRDCLICK = 14;
		static const uint BUTLYRVIEWCLICK = 15;
		static const uint BUTLYRNEWCRDCLICK = 16;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavDesign)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTPRJ = 1;
		static const uint NUMFLSTDSN = 2;
		static const uint NUMFLSTDOM = 3;
		static const uint NUMFLSTDGD = 4;
		static const uint NUMFLSTDVC = 5;
		static const uint NUMFLSTSRU = 6;
		static const uint NUMFLSTSTK = 7;
		static const uint NUMFLSTLYR = 8;

	public:
		ContIac(const uint numFLstPrj = 1, const uint numFLstDsn = 1, const uint numFLstDom = 1, const uint numFLstDgd = 1, const uint numFLstDvc = 1, const uint numFLstSru = 1, const uint numFLstStk = 1, const uint numFLstLyr = 1);

	public:
		uint numFLstPrj;
		uint numFLstDsn;
		uint numFLstDom;
		uint numFLstDgd;
		uint numFLstDvc;
		uint numFLstSru;
		uint numFLstStk;
		uint numFLstLyr;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrNavDesign)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTPRJALT = 2;
		static const uint LSTDSNALT = 3;
		static const uint LSTDOMALT = 4;
		static const uint LSTDGDALT = 5;
		static const uint LSTDVCALT = 6;
		static const uint LSTSRUALT = 7;
		static const uint LSTSTKALT = 8;
		static const uint LSTLYRALT = 9;
		static const uint LSTPRJNUMFIRSTDISP = 10;
		static const uint LSTDSNNUMFIRSTDISP = 11;
		static const uint LSTDOMNUMFIRSTDISP = 12;
		static const uint LSTDGDNUMFIRSTDISP = 13;
		static const uint LSTDVCNUMFIRSTDISP = 14;
		static const uint LSTSRUNUMFIRSTDISP = 15;
		static const uint LSTSTKNUMFIRSTDISP = 16;
		static const uint LSTLYRNUMFIRSTDISP = 17;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstPrjAlt = true, const bool LstDsnAlt = true, const bool LstDomAlt = true, const bool LstDgdAlt = true, const bool LstDvcAlt = true, const bool LstSruAlt = true, const bool LstStkAlt = true, const bool LstLyrAlt = true, const uint LstPrjNumFirstdisp = 1, const uint LstDsnNumFirstdisp = 1, const uint LstDomNumFirstdisp = 1, const uint LstDgdNumFirstdisp = 1, const uint LstDvcNumFirstdisp = 1, const uint LstSruNumFirstdisp = 1, const uint LstStkNumFirstdisp = 1, const uint LstLyrNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstPrjAlt;
		bool LstDsnAlt;
		bool LstDomAlt;
		bool LstDgdAlt;
		bool LstDvcAlt;
		bool LstSruAlt;
		bool LstStkAlt;
		bool LstLyrAlt;
		uint LstPrjNumFirstdisp;
		uint LstDsnNumFirstdisp;
		uint LstDomNumFirstdisp;
		uint LstDgdNumFirstdisp;
		uint LstDvcNumFirstdisp;
		uint LstSruNumFirstdisp;
		uint LstStkNumFirstdisp;
		uint LstLyrNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNavDesign)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTPRJAVAIL = 1;
		static const uint BUTPRJVIEWACTIVE = 2;
		static const uint LSTDSNAVAIL = 3;
		static const uint BUTDSNVIEWACTIVE = 4;
		static const uint LSTDOMAVAIL = 5;
		static const uint BUTDOMVIEWACTIVE = 6;
		static const uint BUTDOMNEWCRDACTIVE = 7;
		static const uint LSTDGDAVAIL = 8;
		static const uint BUTDGDVIEWACTIVE = 9;
		static const uint BUTDGDNEWCRDACTIVE = 10;
		static const uint LSTDVCAVAIL = 11;
		static const uint BUTDVCVIEWACTIVE = 12;
		static const uint BUTDVCNEWCRDACTIVE = 13;
		static const uint LSTSRUAVAIL = 14;
		static const uint BUTSRUVIEWACTIVE = 15;
		static const uint BUTSRUNEWCRDACTIVE = 16;
		static const uint LSTSTKAVAIL = 17;
		static const uint BUTSTKVIEWACTIVE = 18;
		static const uint BUTSTKNEWCRDACTIVE = 19;
		static const uint LSTLYRAVAIL = 20;
		static const uint BUTLYRVIEWACTIVE = 21;
		static const uint BUTLYRNEWCRDACTIVE = 22;

	public:
		StatShr(const bool LstPrjAvail = true, const bool ButPrjViewActive = true, const bool LstDsnAvail = true, const bool ButDsnViewActive = true, const bool LstDomAvail = true, const bool ButDomViewActive = true, const bool ButDomNewcrdActive = true, const bool LstDgdAvail = true, const bool ButDgdViewActive = true, const bool ButDgdNewcrdActive = true, const bool LstDvcAvail = true, const bool ButDvcViewActive = true, const bool ButDvcNewcrdActive = true, const bool LstSruAvail = true, const bool ButSruViewActive = true, const bool ButSruNewcrdActive = true, const bool LstStkAvail = true, const bool ButStkViewActive = true, const bool ButStkNewcrdActive = true, const bool LstLyrAvail = true, const bool ButLyrViewActive = true, const bool ButLyrNewcrdActive = true);

	public:
		bool LstPrjAvail;
		bool ButPrjViewActive;
		bool LstDsnAvail;
		bool ButDsnViewActive;
		bool LstDomAvail;
		bool ButDomViewActive;
		bool ButDomNewcrdActive;
		bool LstDgdAvail;
		bool ButDgdViewActive;
		bool ButDgdNewcrdActive;
		bool LstDvcAvail;
		bool ButDvcViewActive;
		bool ButDvcNewcrdActive;
		bool LstSruAvail;
		bool ButSruViewActive;
		bool ButSruNewcrdActive;
		bool LstStkAvail;
		bool ButStkViewActive;
		bool ButStkNewcrdActive;
		bool LstLyrAvail;
		bool ButLyrViewActive;
		bool ButLyrNewcrdActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNavDesign)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTPRJ = 2;
		static const uint CPTDSN = 3;
		static const uint CPTDOM = 4;
		static const uint CPTDGD = 5;
		static const uint CPTDVC = 6;
		static const uint CPTSRU = 7;
		static const uint CPTSTK = 8;
		static const uint CPTLYR = 9;

	public:
		Tag(const string& Cpt = "", const string& CptPrj = "", const string& CptDsn = "", const string& CptDom = "", const string& CptDgd = "", const string& CptDvc = "", const string& CptSru = "", const string& CptStk = "", const string& CptLyr = "");

	public:
		string Cpt;
		string CptPrj;
		string CptDsn;
		string CptDom;
		string CptDgd;
		string CptDvc;
		string CptSru;
		string CptStk;
		string CptLyr;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavDesignData)
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
		* DpchAppDo (full: DpchAppPlnrNavDesignDo)
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
		* DpchEngData (full: DpchEngPlnrNavDesignData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTDGD = 3;
		static const uint FEEDFLSTDOM = 4;
		static const uint FEEDFLSTDSN = 5;
		static const uint FEEDFLSTDVC = 6;
		static const uint FEEDFLSTLYR = 7;
		static const uint FEEDFLSTPRJ = 8;
		static const uint FEEDFLSTSRU = 9;
		static const uint FEEDFLSTSTK = 10;
		static const uint STATAPP = 11;
		static const uint STATSHR = 12;
		static const uint TAG = 13;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstDgd;
		Feed feedFLstDom;
		Feed feedFLstDsn;
		Feed feedFLstDvc;
		Feed feedFLstLyr;
		Feed feedFLstPrj;
		Feed feedFLstSru;
		Feed feedFLstStk;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

