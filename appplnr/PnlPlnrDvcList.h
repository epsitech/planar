/**
  * \file PnlPlnrDvcList.h
  * app access code for job PnlPlnrDvcList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDVCLIST_H
#define PNLPLNRDVCLIST_H

#include "AppPlnr_blks.h"

#include "PlnrQDvcList.h"

#include "QryPlnrDvcList.h"

/**
  * PnlPlnrDvcList
  */
namespace PnlPlnrDvcList {
	/**
		* VecVDo (full: VecVPlnrDvcListDo)
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
	  * ContIac (full: ContIacPlnrDvcList)
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
	  * ContInf (full: ContInfPlnrDvcList)
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
	  * StatShr (full: StatShrPlnrDvcList)
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
	  * StgIac (full: StgIacPlnrDvcList)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOSRFWIDTH = 1;
		static const uint TCODSNWIDTH = 2;
		static const uint TCOSUPWIDTH = 3;
		static const uint TCOTPLWIDTH = 4;
		static const uint TCOMTYWIDTH = 5;
		static const uint TCOATYWIDTH = 6;

	public:
		StgIac(const uint TcoSrfWidth = 100, const uint TcoDsnWidth = 100, const uint TcoSupWidth = 100, const uint TcoTplWidth = 100, const uint TcoMtyWidth = 100, const uint TcoAtyWidth = 100);

	public:
		uint TcoSrfWidth;
		uint TcoDsnWidth;
		uint TcoSupWidth;
		uint TcoTplWidth;
		uint TcoMtyWidth;
		uint TcoAtyWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagPlnrDvcList)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TXTFOR = 2;
		static const uint TRS = 3;
		static const uint TXTSHOWING1 = 4;
		static const uint TXTSHOWING2 = 5;
		static const uint TCOSRF = 6;
		static const uint TCODSN = 7;
		static const uint TCOSUP = 8;
		static const uint TCOTPL = 9;
		static const uint TCOMTY = 10;
		static const uint TCOATY = 11;

	public:
		Tag(const string& Cpt = "", const string& TxtFor = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoSrf = "", const string& TcoDsn = "", const string& TcoSup = "", const string& TcoTpl = "", const string& TcoMty = "", const string& TcoAty = "");

	public:
		string Cpt;
		string TxtFor;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoSrf;
		string TcoDsn;
		string TcoSup;
		string TcoTpl;
		string TcoMty;
		string TcoAty;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDvcListData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint STGIAC = 3;
		static const uint STGIACQRY = 4;
		static const uint ALL = 5;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, StgIac* stgiac = NULL, QryPlnrDvcList::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;
		StgIac stgiac;
		QryPlnrDvcList::StgIac stgiacqry;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDvcListDo)
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
		* DpchEngData (full: DpchEngPlnrDvcListData)
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
		ListPlnrQDvcList rst;
		QryPlnrDvcList::StatApp statappqry;
		QryPlnrDvcList::StatShr statshrqry;
		QryPlnrDvcList::StgIac stgiacqry;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

