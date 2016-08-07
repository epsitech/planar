/**
  * \file PlnropdOpprc.h
  * operation processor for Plnr operation daemon plnropd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNROPDOPPRC_H
#define PLNROPDOPPRC_H

#include "PlnrExpColldev.h"
#include "PlnrExpColldsn.h"
#include "PlnrExpCollstk.h"
#include "PlnrExpCorner.h"
#include "PlnrExpCross.h"
#include "PlnrExpDircoup.h"
#include "PlnrExpDiscres.h"
#include "PlnrExpDottext.h"
#include "PlnrExpDsn.h"
#include "PlnrExpGratcpl.h"
#include "PlnrExpGray.h"
#include "PlnrExpImage.h"
#include "PlnrExpMarker.h"
#include "PlnrExpPad.h"
#include "PlnrExpPhcsq.h"
#include "PlnrExpPhcsqneg.h"
#include "PlnrExpPhctrig.h"
#include "PlnrExpPhctrigneg.h"
#include "PlnrExpPhotdet.h"
#include "PlnrExpPie.h"
#include "PlnrExpPinout.h"
#include "PlnrExpRoicadp.h"
#include "PlnrExpRtresneg.h"
#include "PlnrExpSpring.h"
#include "PlnrExpStkpertpl.h"
#include "PlnrExpStkregfill.h"
#include "PlnrExpVanderpauw.h"
#include "PlnrExpWg.h"
#include "PlnrExpWgbend.h"
#include "PlnrExpWgbendneg.h"
#include "PlnrExpWgneg.h"
#include "PlnrExpWgsusp.h"
#include "PlnrExpWgtap.h"
#include "PlnrExpWgtapneg.h"
#include "PlnrMeepTrf2d.h"
#include "PlnrMeepTrf3d.h"
#include "PlnrPlotDat1dgnu.h"
#include "PlnrPlotDat1dgnumult.h"
#include "PlnrPlotDevsvg.h"
#include "PlnrPlotDomdat1dgnu.h"
#include "PlnrPlotDomdat2dgnu.h"
#include "PlnrPlotDomdat2dpng.h"
#include "PlnrPlotDomdat2dvid.h"
#include "PlnrPlotDomzcssvg.h"
#include "PlnrPlotDsnxysvg.h"
#include "PlnrPlotDsnzsvg.h"
#include "PlnrPlotStksvg.h"
#include "PlnrPlotTposvg.h"
#include "PlnrPlotTpotxt.h"
#include "PlnrRastCub.h"
#include "PlnrRastXybox.h"
#include "PlnrRastZline.h"
#include "PlnrWgmodeFd1d.h"
#include "PlnrWgmodeFd2d.h"
#include "PlnrWgmodeFem1d.h"
#include "PlnrWgmodeFem2d.h"

/**
  * PlnropdOpprc
  */
namespace PlnropdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif


