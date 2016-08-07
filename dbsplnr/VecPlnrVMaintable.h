/**
  * \file VecPlnrVMaintable.h
  * vector VecPlnrVMaintable (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVMAINTABLE_H
#define VECPLNRVMAINTABLE_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVMaintable
	*/
namespace VecPlnrVMaintable {
	const uint VOID = 1;
	const uint TBLPLNRMARCGUIDE = 2;
	const uint TBLPLNRMARRAY = 3;
	const uint TBLPLNRMARRAYITEM = 4;
	const uint TBLPLNRMBLOCK = 5;
	const uint TBLPLNRMCALC = 6;
	const uint TBLPLNRMCALCITEM = 7;
	const uint TBLPLNRMDESIGN = 8;
	const uint TBLPLNRMDEVICE = 9;
	const uint TBLPLNRMDOMAIN = 10;
	const uint TBLPLNRMDOMAINGD = 11;
	const uint TBLPLNRMFACE = 12;
	const uint TBLPLNRMFILE = 13;
	const uint TBLPLNRMLAYER = 14;
	const uint TBLPLNRMLEVEL = 15;
	const uint TBLPLNRMLINEGUIDE = 16;
	const uint TBLPLNRMMATERIAL = 17;
	const uint TBLPLNRMPERSON = 18;
	const uint TBLPLNRMPROJECT = 19;
	const uint TBLPLNRMRETICLE = 20;
	const uint TBLPLNRMSESSION = 21;
	const uint TBLPLNRMSTACK = 22;
	const uint TBLPLNRMSTRUCTURE = 23;
	const uint TBLPLNRMTAPEOUT = 24;
	const uint TBLPLNRMUSER = 25;
	const uint TBLPLNRMUSERGROUP = 26;
	const uint TBLPLNRMVERTEX = 27;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

