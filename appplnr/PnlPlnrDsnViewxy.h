/**
  * \file PnlPlnrDsnViewxy.h
  * app access code for job PnlPlnrDsnViewxy (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDSNVIEWXY_H
#define PNLPLNRDSNVIEWXY_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDsnViewxy
  */
namespace PnlPlnrDsnViewxy {
	/**
	  * Tag (full: TagPlnrDsnViewxy)
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
		* DpchEngData (full: DpchEngPlnrDsnViewxyData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint TAG = 2;

	public:
		DpchEngData();

	public:
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

