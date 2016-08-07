/**
  * \file PnlPlnrDsnHk1NVertex.h
  * app access code for job PnlPlnrDsnHk1NVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNHK1NVERTEX_H
#define PNLPLNRDSNHK1NVERTEX_H

#include "AppPlnr_blks.h"

#include "PlnrQDsnHk1NVertex.h"

#include "QryPlnrDsnHk1NVertex.h"

/**
  * PnlPlnrDsnHk1NVertex
  */
namespace PnlPlnrDsnHk1NVertex {
	/**
		* VecVDo (full: VecVPlnrDsnHk1NVertexDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDELETECLICK = 1;
		static const uint BUTREFRESHCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDsnHk1NVertex)
	  */
	class ContInf : public Block {

	public:
		static const uint NUMFCSIQST = 1;

	public:
		ContInf(const uint numFCsiQst = 1);

	public:
		uint numFCsiQst;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrDsnHk1NVertex)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND);

	public:
		uint ixPlnrVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDsnHk1NVertex)
	  */
	class StatShr : public Block {

	public:
		static const uint BUTDELETEACTIVE = 1;

	public:
		StatShr(const bool ButDeleteActive = true);

	public:
		bool ButDeleteActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgIac (full: StgIacPlnrDsnHk1NVertex)
	  */
	class StgIac : public Block {

	public:
		static const uint TCOREFWIDTH = 1;

	public:
		StgIac(const uint TcoRefWidth = 100);

	public:
		uint TcoRefWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const StgIac* comp);
		set<uint> diff(const StgIac* comp);
	};

	/**
	  * Tag (full: TagPlnrDsnHk1NVertex)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint TRS = 2;
		static const uint TXTSHOWING1 = 3;
		static const uint TXTSHOWING2 = 4;
		static const uint TCOREF = 5;

	public:
		Tag(const string& Cpt = "", const string& Trs = "", const string& TxtShowing1 = "", const string& TxtShowing2 = "", const string& TcoRef = "");

	public:
		string Cpt;
		string Trs;
		string TxtShowing1;
		string TxtShowing2;
		string TcoRef;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDsnHk1NVertexData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint STGIAC = 2;
		static const uint STGIACQRY = 3;
		static const uint ALL = 4;

	public:
		DpchAppData(const string& scrJref = "", StgIac* stgiac = NULL, QryPlnrDsnHk1NVertex::StgIac* stgiacqry = NULL, const set<uint>& mask = {NONE});

	public:
		StgIac stgiac;
		QryPlnrDsnHk1NVertex::StgIac stgiacqry;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDsnHk1NVertexDo)
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
		* DpchEngData (full: DpchEngPlnrDsnHk1NVertexData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint FEEDFCSIQST = 3;
		static const uint STATAPP = 4;
		static const uint STATSHR = 5;
		static const uint STGIAC = 6;
		static const uint TAG = 7;
		static const uint RST = 8;
		static const uint STATAPPQRY = 9;
		static const uint STATSHRQRY = 10;
		static const uint STGIACQRY = 11;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Feed feedFCsiQst;
		StatApp statapp;
		StatShr statshr;
		StgIac stgiac;
		Tag tag;
		ListPlnrQDsnHk1NVertex rst;
		QryPlnrDsnHk1NVertex::StatApp statappqry;
		QryPlnrDsnHk1NVertex::StatShr statshrqry;
		QryPlnrDsnHk1NVertex::StgIac stgiacqry;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

