/**
  * \file PnlPlnrNavPre.h
  * app access code for job PnlPlnrNavPre (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVPRE_H
#define PNLPLNRNAVPRE_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavPre
  */
namespace PnlPlnrNavPre {
	/**
		* VecVDo (full: VecVPlnrNavPreDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDSNREMOVECLICK = 1;
		static const uint BUTPRJREMOVECLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContInf (full: ContInfPlnrNavPre)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTDSN = 1;
		static const uint TXTPRJ = 2;

	public:
		ContInf(const string& TxtDsn = "", const string& TxtPrj = "");

	public:
		string TxtDsn;
		string TxtPrj;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrNavPre)
	  */
	class StatShr : public Block {

	public:
		static const uint TXTDSNAVAIL = 1;
		static const uint TXTPRJAVAIL = 2;

	public:
		StatShr(const bool TxtDsnAvail = true, const bool TxtPrjAvail = true);

	public:
		bool TxtDsnAvail;
		bool TxtPrjAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrNavPre)
	  */
	class Tag : public Block {

	public:
		static const uint CPTDSN = 1;
		static const uint CPTPRJ = 2;

	public:
		Tag(const string& CptDsn = "", const string& CptPrj = "");

	public:
		string CptDsn;
		string CptPrj;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrNavPreDo)
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
		* DpchEngData (full: DpchEngPlnrNavPreData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTINF = 2;
		static const uint STATSHR = 3;
		static const uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

