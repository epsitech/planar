/**
  * \file VecPlnrVRMCalcMFileIo.h
  * vector VecPlnrVRMCalcMFileIo (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVRMCALCMFILEIO_H
#define VECPLNRVRMCALCMFILEIO_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVRMCalcMFileIo
	*/
namespace VecPlnrVRMCalcMFileIo {
	const uint IN = 1;
	const uint OUT = 2;
	const uint IMD = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

