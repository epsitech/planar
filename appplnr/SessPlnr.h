/**
  * \file SessPlnr.h
  * app access code for job SessPlnr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SESSPLNR_H
#define SESSPLNR_H

#include "AppPlnr_blks.h"

/**
  * SessPlnr
  */
namespace SessPlnr {
	/**
	  * StatShr (full: StatShrSessPlnr)
	  */
	class StatShr : public Block {

	public:
		static const uint SCRJREFCRDNAV = 1;

	public:
		StatShr(const string& scrJrefCrdnav = "");

	public:
		string scrJrefCrdnav;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessPlnrData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint STATSHR = 2;

	public:
		DpchEngData();

	public:
		StatShr statshr;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

