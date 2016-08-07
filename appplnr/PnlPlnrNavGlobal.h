/**
  * \file PnlPlnrNavGlobal.h
  * app access code for job PnlPlnrNavGlobal (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVGLOBAL_H
#define PNLPLNRNAVGLOBAL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavGlobal
  */
namespace PnlPlnrNavGlobal {
	/**
		* VecVDo (full: VecVPlnrNavGlobalDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDTPVIEWCLICK = 1;
		static const uint BUTDTPNEWCRDCLICK = 2;
		static const uint BUTCTPVIEWCLICK = 3;
		static const uint BUTCTPNEWCRDCLICK = 4;
		static const uint BUTMATVIEWCLICK = 5;
		static const uint BUTMATNEWCRDCLICK = 6;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavGlobal)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTDTP = 1;
		static const uint NUMFLSTCTP = 2;
		static const uint NUMFLSTMAT = 3;

	public:
		ContIac(const uint numFLstDtp = 1, const uint numFLstCtp = 1, const uint numFLstMat = 1);

	public:
		uint numFLstDtp;
		uint numFLstCtp;
		uint numFLstMat;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrNavGlobal)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTDTPALT = 2;
		static const uint LSTCTPALT = 3;
		static const uint LSTMATALT = 4;
		static const uint LSTDTPNUMFIRSTDISP = 5;
		static const uint LSTCTPNUMFIRSTDISP = 6;
		static const uint LSTMATNUMFIRSTDISP = 7;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstDtpAlt = true, const bool LstCtpAlt = true, const bool LstMatAlt = true, const uint LstDtpNumFirstdisp = 1, const uint LstCtpNumFirstdisp = 1, const uint LstMatNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstDtpAlt;
		bool LstCtpAlt;
		bool LstMatAlt;
		uint LstDtpNumFirstdisp;
		uint LstCtpNumFirstdisp;
		uint LstMatNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNavGlobal)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTDTPAVAIL = 1;
		static const uint BUTDTPVIEWACTIVE = 2;
		static const uint LSTCTPAVAIL = 3;
		static const uint BUTCTPVIEWACTIVE = 4;
		static const uint LSTMATAVAIL = 5;
		static const uint BUTMATVIEWACTIVE = 6;

	public:
		StatShr(const bool LstDtpAvail = true, const bool ButDtpViewActive = true, const bool LstCtpAvail = true, const bool ButCtpViewActive = true, const bool LstMatAvail = true, const bool ButMatViewActive = true);

	public:
		bool LstDtpAvail;
		bool ButDtpViewActive;
		bool LstCtpAvail;
		bool ButCtpViewActive;
		bool LstMatAvail;
		bool ButMatViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNavGlobal)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTDTP = 2;
		static const uint CPTCTP = 3;
		static const uint CPTMAT = 4;

	public:
		Tag(const string& Cpt = "", const string& CptDtp = "", const string& CptCtp = "", const string& CptMat = "");

	public:
		string Cpt;
		string CptDtp;
		string CptCtp;
		string CptMat;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavGlobalData)
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
		* DpchAppDo (full: DpchAppPlnrNavGlobalDo)
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
		* DpchEngData (full: DpchEngPlnrNavGlobalData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTCTP = 3;
		static const uint FEEDFLSTDTP = 4;
		static const uint FEEDFLSTMAT = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstCtp;
		Feed feedFLstDtp;
		Feed feedFLstMat;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

