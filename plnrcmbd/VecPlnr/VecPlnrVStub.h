/**
  * \file VecPlnrVStub.h
  * vector VecPlnrVStub (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVSTUB_H
#define VECPLNRVSTUB_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVStub
	*/
namespace VecPlnrVStub {
	const uint STUBPLNRAGDSTD = 1;
	const uint STUBPLNRARRSTD = 2;
	const uint STUBPLNRARISTD = 3;
	const uint STUBPLNRBLKSTD = 4;
	const uint STUBPLNRCALSTD = 5;
	const uint STUBPLNRCLCSTD = 6;
	const uint STUBPLNRCTPSTD = 7;
	const uint STUBPLNRCLISTD = 8;
	const uint STUBPLNRDSNSTD = 9;
	const uint STUBPLNRDEVSHORT = 10;
	const uint STUBPLNRDEVSTD = 11;
	const uint STUBPLNRDTPSTD = 12;
	const uint STUBPLNRDVCSTD = 13;
	const uint STUBPLNRDGDSTD = 14;
	const uint STUBPLNRDOMSHORT = 15;
	const uint STUBPLNRDOMSTD = 16;
	const uint STUBPLNRFCESTD = 17;
	const uint STUBPLNRFILSHORT = 18;
	const uint STUBPLNRFILSTD = 19;
	const uint STUBPLNRLYRSTD = 20;
	const uint STUBPLNRLVLSTD = 21;
	const uint STUBPLNRLGDSTD = 22;
	const uint STUBPLNRMATSTD = 23;
	const uint STUBPLNRPRSSTD = 24;
	const uint STUBPLNRPRJSTD = 25;
	const uint STUBPLNRRTCSTD = 26;
	const uint STUBPLNRSESMENU = 27;
	const uint STUBPLNRSESSTD = 28;
	const uint STUBPLNRSTKSHORT = 29;
	const uint STUBPLNRSTKSTD = 30;
	const uint STUBPLNRSRUSTD = 31;
	const uint STUBPLNRTPOSTD = 32;
	const uint STUBPLNRGRP = 33;
	const uint STUBPLNRUSGSTD = 34;
	const uint STUBPLNROWN = 35;
	const uint STUBPLNRUSRSTD = 36;
	const uint STUBPLNRVTXSTD = 37;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


