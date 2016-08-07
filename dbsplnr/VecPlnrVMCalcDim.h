/**
  * \file VecPlnrVMCalcDim.h
  * vector VecPlnrVMCalcDim (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMCALCDIM_H
#define VECPLNRVMCALCDIM_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMCalcDim
	*/
namespace VecPlnrVMCalcDim {
	const uint MSHBOX = 1;
	const uint MSHLINE = 2;
	const uint RSTCUB = 3;
	const uint RSTBOX = 4;
	const uint RSTLINE = 5;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

