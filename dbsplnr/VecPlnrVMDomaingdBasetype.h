/**
  * \file VecPlnrVMDomaingdBasetype.h
  * vector VecPlnrVMDomaingdBasetype (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMDOMAINGDBASETYPE_H
#define VECPLNRVMDOMAINGDBASETYPE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMDomaingdBasetype
	*/
namespace VecPlnrVMDomaingdBasetype {
	const uint LVL = 1;
	const uint VTXLG = 2;
	const uint VTXAG = 3;
	const uint VTXPRPLG = 4;
	const uint VTXLGX = 5;
	const uint LGPAR = 6;
	const uint LGPAR2 = 7;
	const uint LGPRPAG = 8;
	const uint LGPRPLG = 9;
	const uint LGVTX = 10;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

