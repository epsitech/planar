/**
  * \file PnlPlnrNavAdmin.h
  * app access code for job PnlPlnrNavAdmin (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVADMIN_H
#define PNLPLNRNAVADMIN_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavAdmin
  */
namespace PnlPlnrNavAdmin {
	/**
		* VecVDo (full: VecVPlnrNavAdminDo)
		*/
	class VecVDo {

	public:
		static const uint BUTUSGVIEWCLICK = 1;
		static const uint BUTUSGNEWCRDCLICK = 2;
		static const uint BUTUSRVIEWCLICK = 3;
		static const uint BUTUSRNEWCRDCLICK = 4;
		static const uint BUTPRSVIEWCLICK = 5;
		static const uint BUTPRSNEWCRDCLICK = 6;
		static const uint BUTFILVIEWCLICK = 7;
		static const uint BUTFILNEWCRDCLICK = 8;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrNavAdmin)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFLSTUSG = 1;
		static const uint NUMFLSTUSR = 2;
		static const uint NUMFLSTPRS = 3;
		static const uint NUMFLSTFIL = 4;

	public:
		ContIac(const uint numFLstUsg = 1, const uint numFLstUsr = 1, const uint numFLstPrs = 1, const uint numFLstFil = 1);

	public:
		uint numFLstUsg;
		uint numFLstUsr;
		uint numFLstPrs;
		uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrNavAdmin)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint LSTUSGALT = 2;
		static const uint LSTUSRALT = 3;
		static const uint LSTPRSALT = 4;
		static const uint LSTFILALT = 5;
		static const uint LSTUSGNUMFIRSTDISP = 6;
		static const uint LSTUSRNUMFIRSTDISP = 7;
		static const uint LSTPRSNUMFIRSTDISP = 8;
		static const uint LSTFILNUMFIRSTDISP = 9;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const bool LstFilAlt = true, const uint LstUsgNumFirstdisp = 1, const uint LstUsrNumFirstdisp = 1, const uint LstPrsNumFirstdisp = 1, const uint LstFilNumFirstdisp = 1);

	public:
		uint ixPlnrVExpstate;
		bool LstUsgAlt;
		bool LstUsrAlt;
		bool LstPrsAlt;
		bool LstFilAlt;
		uint LstUsgNumFirstdisp;
		uint LstUsrNumFirstdisp;
		uint LstPrsNumFirstdisp;
		uint LstFilNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNavAdmin)
	  */
	class StatShr : public Block {

	public:
		static const uint LSTUSGAVAIL = 1;
		static const uint BUTUSGVIEWACTIVE = 2;
		static const uint LSTUSRAVAIL = 3;
		static const uint BUTUSRVIEWACTIVE = 4;
		static const uint LSTPRSAVAIL = 5;
		static const uint BUTPRSVIEWACTIVE = 6;
		static const uint LSTFILAVAIL = 7;
		static const uint BUTFILVIEWACTIVE = 8;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNavAdmin)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTUSG = 2;
		static const uint CPTUSR = 3;
		static const uint CPTPRS = 4;
		static const uint CPTFIL = 5;

	public:
		Tag(const string& Cpt = "", const string& CptUsg = "", const string& CptUsr = "", const string& CptPrs = "", const string& CptFil = "");

	public:
		string Cpt;
		string CptUsg;
		string CptUsr;
		string CptPrs;
		string CptFil;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrNavAdminData)
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
		* DpchAppDo (full: DpchAppPlnrNavAdminDo)
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
		* DpchEngData (full: DpchEngPlnrNavAdminData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint FEEDFLSTFIL = 3;
		static const uint FEEDFLSTPRS = 4;
		static const uint FEEDFLSTUSG = 5;
		static const uint FEEDFLSTUSR = 6;
		static const uint STATAPP = 7;
		static const uint STATSHR = 8;
		static const uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Feed feedFLstFil;
		Feed feedFLstPrs;
		Feed feedFLstUsg;
		Feed feedFLstUsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

