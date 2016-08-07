/**
  * \file PnlPlnrNavLayout.h
  * app access code for job PnlPlnrNavLayout (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVLAYOUT_H
#define PNLPLNRNAVLAYOUT_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavLayout
  */
namespace PnlPlnrNavLayout {
	/**
		* VecVDo (full: VecVPlnrNavLayoutDo)
		*/
	class VecVDo {

	public:
		static const uint BUTTPOVIEWCLICK = 1;
		static const uint BUTTPONEWCRDCLICK = 2;
		static const uint BUTARRVIEWCLICK = 3;
		static const uint BUTARIVIEWCLICK = 4;
		static const uint BUTRTCVIEWCLICK = 5;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavLayout)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTTPO = 1;
		static const uint NUMFLSTARR = 2;
		static const uint NUMFLSTARI = 3;
		static const uint NUMFLSTRTC = 4;

	public:
		ContIac(const uint numFLstTpo = 1, const uint numFLstArr = 1, const uint numFLstAri = 1, const uint numFLstRtc = 1);

	public:
		uint numFLstTpo;
		uint numFLstArr;
		uint numFLstAri;
		uint numFLstRtc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrNavLayout)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTTPOALT = 2;
		static const uint LSTARRALT = 3;
		static const uint LSTARIALT = 4;
		static const uint LSTRTCALT = 5;
		static const uint LSTTPONUMFIRSTDISP = 6;
		static const uint LSTARRNUMFIRSTDISP = 7;
		static const uint LSTARINUMFIRSTDISP = 8;
		static const uint LSTRTCNUMFIRSTDISP = 9;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstTpoAlt = true, const bool LstArrAlt = true, const bool LstAriAlt = true, const bool LstRtcAlt = true, const uint LstTpoNumFirstdisp = 1, const uint LstArrNumFirstdisp = 1, const uint LstAriNumFirstdisp = 1, const uint LstRtcNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstTpoAlt;
		bool LstArrAlt;
		bool LstAriAlt;
		bool LstRtcAlt;
		uint LstTpoNumFirstdisp;
		uint LstArrNumFirstdisp;
		uint LstAriNumFirstdisp;
		uint LstRtcNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNavLayout)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTTPOAVAIL = 1;
		static const uint BUTTPOVIEWACTIVE = 2;
		static const uint LSTARRAVAIL = 3;
		static const uint BUTARRVIEWACTIVE = 4;
		static const uint LSTARIAVAIL = 5;
		static const uint BUTARIVIEWACTIVE = 6;
		static const uint LSTRTCAVAIL = 7;
		static const uint BUTRTCVIEWACTIVE = 8;

	public:
		StatShr(const bool LstTpoAvail = true, const bool ButTpoViewActive = true, const bool LstArrAvail = true, const bool ButArrViewActive = true, const bool LstAriAvail = true, const bool ButAriViewActive = true, const bool LstRtcAvail = true, const bool ButRtcViewActive = true);

	public:
		bool LstTpoAvail;
		bool ButTpoViewActive;
		bool LstArrAvail;
		bool ButArrViewActive;
		bool LstAriAvail;
		bool ButAriViewActive;
		bool LstRtcAvail;
		bool ButRtcViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNavLayout)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTTPO = 2;
		static const uint CPTARR = 3;
		static const uint CPTARI = 4;
		static const uint CPTRTC = 5;

	public:
		Tag(const string& Cpt = "", const string& CptTpo = "", const string& CptArr = "", const string& CptAri = "", const string& CptRtc = "");

	public:
		string Cpt;
		string CptTpo;
		string CptArr;
		string CptAri;
		string CptRtc;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavLayoutData)
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
		* DpchAppDo (full: DpchAppPlnrNavLayoutDo)
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
		* DpchEngData (full: DpchEngPlnrNavLayoutData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTARI = 3;
		static const uint FEEDFLSTARR = 4;
		static const uint FEEDFLSTRTC = 5;
		static const uint FEEDFLSTTPO = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstAri;
		Feed feedFLstArr;
		Feed feedFLstRtc;
		Feed feedFLstTpo;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

