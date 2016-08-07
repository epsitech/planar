/**
  * \file VecPlnrVMDesignRefTbl.h
  * vector VecPlnrVMDesignRefTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDESIGNREFTBL_H
#define VECPLNRVMDESIGNREFTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDesignRefTbl
	*/
namespace VecPlnrVMDesignRefTbl {
	const uint VOID = 1;
	const uint CAL = 2;
	const uint CLI = 3;
	const uint ARR = 4;
	const uint ARI = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

