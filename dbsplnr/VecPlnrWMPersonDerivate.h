/**
  * \file VecPlnrWMPersonDerivate.h
  * vector VecPlnrWMPersonDerivate (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRWMPERSONDERIVATE_H
#define VECPLNRWMPERSONDERIVATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrWMPersonDerivate
	*/
namespace VecPlnrWMPersonDerivate {
	const uint USR = 1;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

