/**
  * \file VecPlnrWUiaccess.h
  * vector VecPlnrWUiaccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRWUIACCESS_H
#define VECPLNRWUIACCESS_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrWUiaccess
	*/
namespace VecPlnrWUiaccess {
	const uint EDIT = 1;
	const uint EXEC = 2;
	const uint VIEW = 4;

	uint getIx(const string& srefs);
	void getIcs(const uint ix, set<uint>& ics);
	string getSrefs(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

