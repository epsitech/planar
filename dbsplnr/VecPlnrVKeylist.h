/**
  * \file VecPlnrVKeylist.h
  * vector VecPlnrVKeylist (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVKEYLIST_H
#define VECPLNRVKEYLIST_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVKeylist
	*/
namespace VecPlnrVKeylist {
	const uint KLSTPLNRKCALCDOMPRP = 1;
	const uint KLSTPLNRKCALCVAR = 2;
	const uint KLSTPLNRKAMARRAYENVKEY = 3;
	const uint KLSTPLNRKAMCALCENVKEY = 4;
	const uint KLSTPLNRKAMCALCPARCAT = 5;
	const uint KLSTPLNRKAMCALCPARPROP = 6;
	const uint KLSTPLNRKAMDEVICEPARKEY = 7;
	const uint KLSTPLNRKAMMATERIALPARCAT = 8;
	const uint KLSTPLNRKAMMATERIALPARPROP = 9;
	const uint KLSTPLNRKAMPERSONDETAILTYPE = 10;
	const uint KLSTPLNRKMFILECONTENT = 11;
	const uint KLSTPLNRKMFILEMIMETYPE = 12;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);
};

#endif

