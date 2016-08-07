/**
  * \file VecPlnrVMStackModtype.h
  * vector VecPlnrVMStackModtype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMSTACKMODTYPE_H
#define VECPLNRVMSTACKMODTYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMStackModtype
	*/
namespace VecPlnrVMStackModtype {
	const uint VOID = 1;
	const uint NOLN = 2;
	const uint LYR = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

