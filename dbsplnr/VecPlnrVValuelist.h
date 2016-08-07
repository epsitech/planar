/**
  * \file VecPlnrVValuelist.h
  * vector VecPlnrVValuelist (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVVALUELIST_H
#define VECPLNRVVALUELIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVValuelist
	*/
namespace VecPlnrVValuelist {
	const uint VLSTPLNRUMPERSONTITLE = 1;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);
};

#endif

