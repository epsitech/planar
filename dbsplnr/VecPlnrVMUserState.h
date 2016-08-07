/**
  * \file VecPlnrVMUserState.h
  * vector VecPlnrVMUserState (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMUSERSTATE_H
#define VECPLNRVMUSERSTATE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMUserState
	*/
namespace VecPlnrVMUserState {
	const uint ACT = 1;
	const uint DSG = 2;
	const uint DUE = 3;
	const uint EXP = 4;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

