/**
  * \file PnlPlnrNavHeadbar.h
  * app access code for job PnlPlnrNavHeadbar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRNAVHEADBAR_H
#define PNLPLNRNAVHEADBAR_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrNavHeadbar
  */
namespace PnlPlnrNavHeadbar {
	/**
	  * StatShr (full: StatShrPlnrNavHeadbar)
	  */
	class StatShr : public Block {

	public:
		static const uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * StgInf (full: StgInfPlnrNavHeadbar)
	  */
	class StgInf : public Block {

	public:
		static const uint MENAPPCPTWIDTH = 1;
		static const uint MENAPPWIDTH = 2;
		static const uint MENSESCPTWIDTH = 3;
		static const uint MENSESWIDTH = 4;
		static const uint MENCRDCPTWIDTH = 5;
		static const uint MENCRDWIDTH = 6;

	public:
		StgInf(const uint MenAppCptwidth = 100, const uint MenAppWidth = 100, const uint MenSesCptwidth = 100, const uint MenSesWidth = 100, const uint MenCrdCptwidth = 100, const uint MenCrdWidth = 100);

	public:
		uint MenAppCptwidth;
		uint MenAppWidth;
		uint MenSesCptwidth;
		uint MenSesWidth;
		uint MenCrdCptwidth;
		uint MenCrdWidth;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StgInf* comp);
		set<uint> diff(const StgInf* comp);
	};

	/**
	  * Tag (full: TagPlnrNavHeadbar)
	  */
	class Tag : public Block {

	public:
		static const uint MENAPP = 1;
		static const uint MENSES = 2;
		static const uint MENCRD = 3;

	public:
		Tag(const string& MenApp = "", const string& MenSes = "", const string& MenCrd = "");

	public:
		string MenApp;
		string MenSes;
		string MenCrd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngPlnrNavHeadbarData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint STATSHR = 2;
		static const uint STGINF = 3;
		static const uint TAG = 4;

	public:
		DpchEngData();

	public:
		StatShr statshr;
		StgInf stginf;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

