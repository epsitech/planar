/**
  * \file RootPlnr.h
  * app access code for job RootPlnr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef ROOTPLNR_H
#define ROOTPLNR_H

#include "AppPlnr_blks.h"

/**
  * RootPlnr
  */
namespace RootPlnr {
	/**
		* DpchAppLogin (full: DpchAppRootPlnrLogin)
		*/
	class DpchAppLogin : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint PASSWORD = 2;
		static const uint USERNAME = 3;
		static const uint ALL = 4;

	public:
		DpchAppLogin(const string& scrJref = "", const string& password = "", const string& username = "", const set<uint>& mask = {NONE});

	public:
		string password;
		string username;

	public:
		void writeXML(xmlTextWriter* wr);
	};

};

#endif

