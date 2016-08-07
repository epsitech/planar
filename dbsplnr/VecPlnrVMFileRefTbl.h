/**
  * \file VecPlnrVMFileRefTbl.h
  * vector VecPlnrVMFileRefTbl (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMFILEREFTBL_H
#define VECPLNRVMFILEREFTBL_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMFileRefTbl
	*/
namespace VecPlnrVMFileRefTbl {
	const uint VOID = 1;
	const uint CAL = 2;
	const uint CLI = 3;
	const uint MAT = 4;
	const uint DEV = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

