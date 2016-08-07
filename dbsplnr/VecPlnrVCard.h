/**
  * \file VecPlnrVCard.h
  * vector VecPlnrVCard (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVCARD_H
#define VECPLNRVCARD_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVCard
	*/
namespace VecPlnrVCard {
	const uint CRDPLNRNAV = 1;
	const uint CRDPLNRUSG = 2;
	const uint CRDPLNRUSR = 3;
	const uint CRDPLNRPRS = 4;
	const uint CRDPLNRFIL = 5;
	const uint CRDPLNRDTP = 6;
	const uint CRDPLNRCTP = 7;
	const uint CRDPLNRMAT = 8;
	const uint CRDPLNRPRJ = 9;
	const uint CRDPLNRDSN = 10;
	const uint CRDPLNRDOM = 11;
	const uint CRDPLNRDGD = 12;
	const uint CRDPLNRDVC = 13;
	const uint CRDPLNRSRU = 14;
	const uint CRDPLNRSTK = 15;
	const uint CRDPLNRLYR = 16;
	const uint CRDPLNRCLC = 17;
	const uint CRDPLNRCLI = 18;
	const uint CRDPLNRTPO = 19;
	const uint CRDPLNRARR = 20;
	const uint CRDPLNRARI = 21;
	const uint CRDPLNRRTC = 22;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);

	void fillFeed(const uint ixPlnrVLocale, Feed& feed);
};

#endif

