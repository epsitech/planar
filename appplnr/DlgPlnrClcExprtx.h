/**
  * \file DlgPlnrClcExprtx.h
  * app access code for job DlgPlnrClcExprtx (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DLGPLNRCLCEXPRTX_H
#define DLGPLNRCLCEXPRTX_H

#include "AppPlnr_blks.h"

/**
  * DlgPlnrClcExprtx
  */
namespace DlgPlnrClcExprtx {
	/**
		* VecVDo (full: VecVDlgPlnrClcExprtxDo)
		*/
	class VecVDo {

	public:
		static const uint BUTDNECLICK = 1;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * StatApp (full: StatAppDlgPlnrClcExprtx)
	  */
	class StatApp : public Block {

	public:
		static const uint SHORTMENU = 1;

	public:
		StatApp(const string& shortMenu = "");

	public:
		string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * Tag (full: TagDlgPlnrClcExprtx)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint BUTDNE = 2;

	public:
		Tag(const string& Cpt = "", const string& ButDne = "");

	public:
		string Cpt;
		string ButDne;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppDlgPlnrClcExprtxDo)
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
		* DpchEngData (full: DpchEngDlgPlnrClcExprtxData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint STATAPP = 2;
		static const uint TAG = 3;

	public:
		DpchEngData();

	public:
		StatApp statapp;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

