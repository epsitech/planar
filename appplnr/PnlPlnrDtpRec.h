/**
  * \file PnlPlnrDtpRec.h
  * app access code for job PnlPlnrDtpRec (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDTPREC_H
#define PNLPLNRDTPREC_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDtpRec
  */
namespace PnlPlnrDtpRec {
	/**
		* VecVDo (full: VecVPlnrDtpRecDo)
		*/
	class VecVDo {

	public:
		static const uint BUTMINIMIZECLICK = 1;
		static const uint BUTREGULARIZECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrDtpRec)
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
	  * StatApp (full: StatAppPlnrDtpRec)
	  */
	class StatApp : public Block {

	public:
		static const uint INITDONEPRE = 1;
		static const uint INITDONEDETAIL = 2;
		static const uint INITDONEVIEW = 3;
		static const uint INITDONEKPARKEY = 4;
		static const uint INITDONEAPAR = 5;
		static const uint INITDONESUP1NDEVICE = 6;
		static const uint INITDONEHK1NSTRUCTURE = 7;
		static const uint INITDONETPL1NDEVICE = 8;

	public:
		StatApp(const bool initdonePre = false, const bool initdoneDetail = false, const bool initdoneView = false, const bool initdoneKParKey = false, const bool initdoneAPar = false, const bool initdoneSup1NDevice = false, const bool initdoneHk1NStructure = false, const bool initdoneTpl1NDevice = false);

	public:
		bool initdonePre;
		bool initdoneDetail;
		bool initdoneView;
		bool initdoneKParKey;
		bool initdoneAPar;
		bool initdoneSup1NDevice;
		bool initdoneHk1NStructure;
		bool initdoneTpl1NDevice;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDtpRec)
	  */
	class StatShr : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint SCRJREFPRE = 2;
		static const uint SCRJREFDETAIL = 3;
		static const uint SCRJREFVIEW = 4;
		static const uint SCRJREFKPARKEY = 5;
		static const uint SCRJREFAPAR = 6;
		static const uint SCRJREFSUP1NDEVICE = 7;
		static const uint SCRJREFHK1NSTRUCTURE = 8;
		static const uint SCRJREFTPL1NDEVICE = 9;
		static const uint BUTREGULARIZEACTIVE = 10;

	public:
		StatShr(const uint ixPlnrVExpstate = VecPlnrVExpstate::REGD, const string& scrJrefPre = "", const string& scrJrefDetail = "", const string& scrJrefView = "", const string& scrJrefKParKey = "", const string& scrJrefAPar = "", const string& scrJrefSup1NDevice = "", const string& scrJrefHk1NStructure = "", const string& scrJrefTpl1NDevice = "", const bool ButRegularizeActive = true);

	public:
		uint ixPlnrVExpstate;
		string scrJrefPre;
		string scrJrefDetail;
		string scrJrefView;
		string scrJrefKParKey;
		string scrJrefAPar;
		string scrJrefSup1NDevice;
		string scrJrefHk1NStructure;
		string scrJrefTpl1NDevice;
		bool ButRegularizeActive;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDtpRec)
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
		* DpchAppDo (full: DpchAppPlnrDtpRecDo)
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
		* DpchEngData (full: DpchEngPlnrDtpRecData)
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

