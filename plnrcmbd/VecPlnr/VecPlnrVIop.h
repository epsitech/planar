/**
  * \file VecPlnrVIop.h
  * vector VecPlnrVIop (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVIOP_H
#define VECPLNRVIOP_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVIop
	*/
namespace VecPlnrVIop {
	const uint INS = 1;
	const uint RETR = 2;
	const uint RETRINS = 3;
	const uint RETRUPD = 4;
	const uint RMV = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif


