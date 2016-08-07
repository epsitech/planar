/**
  * \file PnlPlnrUsrRec.h
  * app access code for job PnlPlnrUsrRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRUSRREC_H
#define PNLPLNRUSRREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrUsrRec
  */
namespace PnlPlnrUsrRec {
	/**
		* VecVDo (full: VecVPlnrUsrRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrUsrRec)
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
	  * StatApp (full: StatAppPlnrUsrRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEDETAIL = 1;
		static const uint INITDONEAACCESS = 2;
		static const uint INITDONE1NSESSION = 3;
		static const uint INITDONEMNUSERGROUP = 4;

	public:
		StatApp(const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdone1NSession = false, const bool initdoneMNUsergroup = false);

	public:
		bool initdoneDetail;
		bool initdoneAAccess;
		bool initdone1NSession;
		bool initdoneMNUsergroup;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrUsrRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFDETAIL = 2;
		static const uint SCRJREFAACCESS = 3;
		static const uint SCRJREF1NSESSION = 4;
		static const uint SCRJREFMNUSERGROUP = 5;
		static const uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefDetail = "", const string& scrJrefAAccess = "", const string& scrJref1NSession = "", const string& scrJrefMNUsergroup = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefDetail;
		string scrJrefAAccess;
		string scrJref1NSession;
		string scrJrefMNUsergroup;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrUsrRec)
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
		* DpchAppDo (full: DpchAppPlnrUsrRecDo)
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
		* DpchEngData (full: DpchEngPlnrUsrRecData)
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

