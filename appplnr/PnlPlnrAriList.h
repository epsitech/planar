/**
  * \file PnlPlnrAriList.h
  * app access code for job PnlPlnrAriList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRARILIST_H
#define PNLPLNRARILIST_H

#include "AppPlnr_blks.h"

#include "PlnrQAriList.h"

#include "QryPlnrAriList.h"

/**
  * PnlPlnrAriList
  */
namespace PnlPlnrAriList {
	/**
		* VecVDo (full: VecVPlnrAriListDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;
		static const uint BUTNEWCLICK = 3;
		static const uint BUTDELETECLICK = 4;
		static const uint BUTFILTERCLICK = 5;
		static const uint BUTREFRESHCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrAriList)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFTOS = 1;

	public:
		ContIac(const uint numFTos = 1);

	public:
		uint numFTos;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrAriList)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTFOR = 1;
		static const uint TXTPRE = 2;
		static const uint BUTFILTERON = 3;
		static const uint NUMFCSIQST = 4;

	public:
		ContInf(const string& TxtFor = "", const string& TxtPre = "", const bool ButFilterOn = false, const uint numFCsiQst = 1);

	public:
		string TxtFor;
		string TxtPre;
		bool ButFilterOn;
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrAriList)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint BUTDELETEACTIVE = 2;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool ButDeleteActive = true);

	public:
		uint ixPlnrVExpstate;
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacPlnrAriList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOIWIDTH = 1;
		static const uint TCOJWIDTH = 2;
		static const uint TCOKWIDTH = 3;
		static const uint TCOLWIDTH = 4;
		static const uint TCOMWIDTH = 5;
		static const uint TCONWIDTH = 6;
		static const uint TCOARRWIDTH = 7;
		static const uint TCODSNWIDTH = 8;
		static const uint TCODXWIDTH = 9;
		static const uint TCODYWIDTH = 10;

	public:
		StgIac(const uint TcoIWidth = 100, const uint TcoJWidth = 100, const uint TcoKWidth = 100, const uint TcoLWidth = 100, const uint TcoMWidth = 100, const uint TcoNWidth = 100, const uint TcoArrWidth = 100, const uint TcoDsnWidth = 100, const uint TcoDxWidth = 100, const uint TcoDyWidth = 100);

	public:
		uint TcoIWidth;
		uint TcoJWidth;
		uint TcoKWidth;
		uint TcoLWidth;
		uint TcoMWidth;
		uint TcoNWidth;
		uint TcoArrWidth;
		uint TcoDsnWidth;
		uint TcoDxWidth;
		uint TcoDyWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagPlnrAriList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TXTFOR = 2;
		static const uint TRS = 3;
		static const uint TXTSHOWING1 = 4;
		static const uint TXTSHOWING2 = 5;
		static const uint TCOI = 6;
		static const uint TCOJ = 7;
		static const uint TCOK = 8;
		static const uint TCOL = 9;
		static const uint TCOM = 10;
		static const uint TCON = 11;
		static const uint TCOARR = 12;
		static const uint TCODSN = 13;
		static const uint TCODX = 14;
		static const uint TCODY = 15;

	public:
		Tag(const string& Cpt = "", const string& TxtFor = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoI = "", const string& TcoJ = "", const string& TcoK = "", const string& TcoL = "", const string& TcoM = "", const string& TcoN = "", const string& TcoArr = "", const string& TcoDsn = "", const string& TcoDx = "", const string& TcoDy = "");

	public:
		string Cpt;
		string TxtFor;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoI;
		string TcoJ;
		string TcoK;
		string TcoL;
		string TcoM;
		string TcoN;
		string TcoArr;
		string TcoDsn;
		string TcoDx;
		string TcoDy;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrAriListData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryPlnrAriList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryPlnrAriList::StgIac stgiacqry;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrAriListDo)
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
		* DpchEngData (full: DpchEngPlnrAriListData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFCSIQST = 4;
		static const uint FEEDFTOS = 5;
		static const uint STATSHR = 6;
		static const uint STGIAC = 7;
		static const uint TAG = 8;
		static const uint RST = 9;
		static const uint STATAPPQRY = 10;
		static const uint STATSHRQRY = 11;
		static const uint STGIACQRY = 12;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFCsiQst;
		Feed feedFTos;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListPlnrQAriList rst;
		QryPlnrAriList::StatApp statappqry;
		QryPlnrAriList::StatShr statshrqry;
		QryPlnrAriList::StgIac stgiacqry;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

