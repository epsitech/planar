/**
  * \file VecPlnrVUserlevel.h
  * vector VecPlnrVUserlevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVUSERLEVEL_H
#define VECPLNRVUSERLEVEL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVUserlevel
	*/
namespace VecPlnrVUserlevel {
	const uint ADM = 1;
	const uint GADM = 2;
	const uint REG = 3;
	const uint VTOR = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

