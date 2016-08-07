/**
  * \file VecPlnrVStub.cpp
  * vector VecPlnrVStub (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVStub.h"

/******************************************************************************
 namespace VecPlnrVStub
 ******************************************************************************/

uint VecPlnrVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubplnragdstd") return STUBPLNRAGDSTD;
	else if (s == "stubplnrarrstd") return STUBPLNRARRSTD;
	else if (s == "stubplnraristd") return STUBPLNRARISTD;
	else if (s == "stubplnrblkstd") return STUBPLNRBLKSTD;
	else if (s == "stubplnrcalstd") return STUBPLNRCALSTD;
	else if (s == "stubplnrclcstd") return STUBPLNRCLCSTD;
	else if (s == "stubplnrctpstd") return STUBPLNRCTPSTD;
	else if (s == "stubplnrclistd") return STUBPLNRCLISTD;
	else if (s == "stubplnrdsnstd") return STUBPLNRDSNSTD;
	else if (s == "stubplnrdevshort") return STUBPLNRDEVSHORT;
	else if (s == "stubplnrdevstd") return STUBPLNRDEVSTD;
	else if (s == "stubplnrdtpstd") return STUBPLNRDTPSTD;
	else if (s == "stubplnrdvcstd") return STUBPLNRDVCSTD;
	else if (s == "stubplnrdgdstd") return STUBPLNRDGDSTD;
	else if (s == "stubplnrdomshort") return STUBPLNRDOMSHORT;
	else if (s == "stubplnrdomstd") return STUBPLNRDOMSTD;
	else if (s == "stubplnrfcestd") return STUBPLNRFCESTD;
	else if (s == "stubplnrfilshort") return STUBPLNRFILSHORT;
	else if (s == "stubplnrfilstd") return STUBPLNRFILSTD;
	else if (s == "stubplnrlyrstd") return STUBPLNRLYRSTD;
	else if (s == "stubplnrlvlstd") return STUBPLNRLVLSTD;
	else if (s == "stubplnrlgdstd") return STUBPLNRLGDSTD;
	else if (s == "stubplnrmatstd") return STUBPLNRMATSTD;
	else if (s == "stubplnrprsstd") return STUBPLNRPRSSTD;
	else if (s == "stubplnrprjstd") return STUBPLNRPRJSTD;
	else if (s == "stubplnrrtcstd") return STUBPLNRRTCSTD;
	else if (s == "stubplnrsesmenu") return STUBPLNRSESMENU;
	else if (s == "stubplnrsesstd") return STUBPLNRSESSTD;
	else if (s == "stubplnrstkshort") return STUBPLNRSTKSHORT;
	else if (s == "stubplnrstkstd") return STUBPLNRSTKSTD;
	else if (s == "stubplnrsrustd") return STUBPLNRSRUSTD;
	else if (s == "stubplnrtpostd") return STUBPLNRTPOSTD;
	else if (s == "stubplnrgrp") return STUBPLNRGRP;
	else if (s == "stubplnrusgstd") return STUBPLNRUSGSTD;
	else if (s == "stubplnrown") return STUBPLNROWN;
	else if (s == "stubplnrusrstd") return STUBPLNRUSRSTD;
	else if (s == "stubplnrvtxstd") return STUBPLNRVTXSTD;

	return(0);
};

string VecPlnrVStub::getSref(
			const uint ix
		) {
	if (ix == STUBPLNRAGDSTD) return("StubPlnrAgdStd");
	else if (ix == STUBPLNRARRSTD) return("StubPlnrArrStd");
	else if (ix == STUBPLNRARISTD) return("StubPlnrAriStd");
	else if (ix == STUBPLNRBLKSTD) return("StubPlnrBlkStd");
	else if (ix == STUBPLNRCALSTD) return("StubPlnrCalStd");
	else if (ix == STUBPLNRCLCSTD) return("StubPlnrClcStd");
	else if (ix == STUBPLNRCTPSTD) return("StubPlnrCtpStd");
	else if (ix == STUBPLNRCLISTD) return("StubPlnrCliStd");
	else if (ix == STUBPLNRDSNSTD) return("StubPlnrDsnStd");
	else if (ix == STUBPLNRDEVSHORT) return("StubPlnrDevShort");
	else if (ix == STUBPLNRDEVSTD) return("StubPlnrDevStd");
	else if (ix == STUBPLNRDTPSTD) return("StubPlnrDtpStd");
	else if (ix == STUBPLNRDVCSTD) return("StubPlnrDvcStd");
	else if (ix == STUBPLNRDGDSTD) return("StubPlnrDgdStd");
	else if (ix == STUBPLNRDOMSHORT) return("StubPlnrDomShort");
	else if (ix == STUBPLNRDOMSTD) return("StubPlnrDomStd");
	else if (ix == STUBPLNRFCESTD) return("StubPlnrFceStd");
	else if (ix == STUBPLNRFILSHORT) return("StubPlnrFilShort");
	else if (ix == STUBPLNRFILSTD) return("StubPlnrFilStd");
	else if (ix == STUBPLNRLYRSTD) return("StubPlnrLyrStd");
	else if (ix == STUBPLNRLVLSTD) return("StubPlnrLvlStd");
	else if (ix == STUBPLNRLGDSTD) return("StubPlnrLgdStd");
	else if (ix == STUBPLNRMATSTD) return("StubPlnrMatStd");
	else if (ix == STUBPLNRPRSSTD) return("StubPlnrPrsStd");
	else if (ix == STUBPLNRPRJSTD) return("StubPlnrPrjStd");
	else if (ix == STUBPLNRRTCSTD) return("StubPlnrRtcStd");
	else if (ix == STUBPLNRSESMENU) return("StubPlnrSesMenu");
	else if (ix == STUBPLNRSESSTD) return("StubPlnrSesStd");
	else if (ix == STUBPLNRSTKSHORT) return("StubPlnrStkShort");
	else if (ix == STUBPLNRSTKSTD) return("StubPlnrStkStd");
	else if (ix == STUBPLNRSRUSTD) return("StubPlnrSruStd");
	else if (ix == STUBPLNRTPOSTD) return("StubPlnrTpoStd");
	else if (ix == STUBPLNRGRP) return("StubPlnrGrp");
	else if (ix == STUBPLNRUSGSTD) return("StubPlnrUsgStd");
	else if (ix == STUBPLNROWN) return("StubPlnrOwn");
	else if (ix == STUBPLNRUSRSTD) return("StubPlnrUsrStd");
	else if (ix == STUBPLNRVTXSTD) return("StubPlnrVtxStd");

	return("");
};


