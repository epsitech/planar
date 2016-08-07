/**
  * \file VecPlnrWMDesignModtype.h
  * vector VecPlnrWMDesignModtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRWMDESIGNMODTYPE_H
#define VECPLNRWMDESIGNMODTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrWMDesignModtype
	*/
namespace VecPlnrWMDesignModtype {
	const uint DNOTO = 1;
	const uint DTO = 2;
	const uint SNOLN = 4;
	const uint SLN = 8;
	const uint MLT = 16;
	const uint DOMXY = 32;
	const uint DOMZ = 64;
	const uint MVAR = 128;
	const uint MAT = 256;
	const uint GRID = 512;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

