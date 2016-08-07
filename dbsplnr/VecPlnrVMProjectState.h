/**
  * \file VecPlnrVMProjectState.h
  * vector VecPlnrVMProjectState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMPROJECTSTATE_H
#define VECPLNRVMPROJECTSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMProjectState
	*/
namespace VecPlnrVMProjectState {
	const uint PLAN = 1;
	const uint ACT = 2;
	const uint CPL = 3;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

