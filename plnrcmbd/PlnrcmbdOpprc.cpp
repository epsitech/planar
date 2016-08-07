/**
  * \file PlnrcmbdOpprc.cpp
  * operation processor for Plnr combined daemon (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnrcmbd.h"

#include "PlnrcmbdOpprc.h"

/******************************************************************************
 namespace PlnrcmbdOpprc
 ******************************************************************************/

void* PlnrcmbdOpprc::run(
			void* arg
		) {
	XchgPlnrcmbd* xchg = (XchgPlnrcmbd*) arg;

	// open database connection
	DbsPlnr dbsplnr;
	int contry = 10;

	while (contry > 0) {
		try {
			dbsplnr.init(xchg->stgplnrdatabase.ixDbsVDbstype, "", xchg->stgplnrdatabase.dbsname, xchg->stgplnrdatabase.ip
						, xchg->stgplnrdatabase.port, xchg->stgplnrdatabase.username, xchg->stgplnrdatabase.password);
			break;
		} catch (DbsException e) {
			contry--;
			if (contry == 0) throw;
		};
	};

	DpchInvPlnr* inv = NULL;
	ReqPlnr* req = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	// main loop: wait for operation invocations
	while (true) {
		// an inv is already here
		inv = xchg->pullFirstInv();

		while (inv == NULL) {
			// no req is here ; wait for it
			Mutex::lock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "PlnrcmbdOpprc", "run");
			Cond::wait(&(xchg->cOpprcs), &(xchg->mcOpprcs), "xchg->cOpprcs", "PlnrcmbdOpprc", "run");

			// note that the result here might be NULL, if another (idle) op processor strikes first
			inv = xchg->pullFirstInv();

			Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "PlnrcmbdOpprc", "run");
		};

		if (inv) {
			// prepare request
			req = new ReqPlnr(ReqPlnr::VecVBasetype::RET);

			req->jref = inv->jref;
			req->dpchinv = inv;

			// perform op
			if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCOLLDEV) {
				req->dpchret = PlnrExpColldev::run(xchg, &dbsplnr, (DpchInvPlnrExpColldev*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCOLLDSN) {
				req->dpchret = PlnrExpColldsn::run(xchg, &dbsplnr, (DpchInvPlnrExpColldsn*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCOLLSTK) {
				req->dpchret = PlnrExpCollstk::run(xchg, &dbsplnr, (DpchInvPlnrExpCollstk*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCORNER) {
				req->dpchret = PlnrExpCorner::run(xchg, &dbsplnr, (DpchInvPlnrExpCorner*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPCROSS) {
				req->dpchret = PlnrExpCross::run(xchg, &dbsplnr, (DpchInvPlnrExpCross*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDIRCOUP) {
				req->dpchret = PlnrExpDircoup::run(xchg, &dbsplnr, (DpchInvPlnrExpDircoup*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDISCRES) {
				req->dpchret = PlnrExpDiscres::run(xchg, &dbsplnr, (DpchInvPlnrExpDiscres*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDOTTEXT) {
				req->dpchret = PlnrExpDottext::run(xchg, &dbsplnr, (DpchInvPlnrExpDottext*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPDSN) {
				req->dpchret = PlnrExpDsn::run(xchg, &dbsplnr, (DpchInvPlnrExpDsn*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPGRATCPL) {
				req->dpchret = PlnrExpGratcpl::run(xchg, &dbsplnr, (DpchInvPlnrExpGratcpl*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPGRAY) {
				req->dpchret = PlnrExpGray::run(xchg, &dbsplnr, (DpchInvPlnrExpGray*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPIMAGE) {
				req->dpchret = PlnrExpImage::run(xchg, &dbsplnr, (DpchInvPlnrExpImage*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPMARKER) {
				req->dpchret = PlnrExpMarker::run(xchg, &dbsplnr, (DpchInvPlnrExpMarker*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPAD) {
				req->dpchret = PlnrExpPad::run(xchg, &dbsplnr, (DpchInvPlnrExpPad*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCSQ) {
				req->dpchret = PlnrExpPhcsq::run(xchg, &dbsplnr, (DpchInvPlnrExpPhcsq*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCSQNEG) {
				req->dpchret = PlnrExpPhcsqneg::run(xchg, &dbsplnr, (DpchInvPlnrExpPhcsqneg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCTRIG) {
				req->dpchret = PlnrExpPhctrig::run(xchg, &dbsplnr, (DpchInvPlnrExpPhctrig*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHCTRIGNEG) {
				req->dpchret = PlnrExpPhctrigneg::run(xchg, &dbsplnr, (DpchInvPlnrExpPhctrigneg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPHOTDET) {
				req->dpchret = PlnrExpPhotdet::run(xchg, &dbsplnr, (DpchInvPlnrExpPhotdet*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPIE) {
				req->dpchret = PlnrExpPie::run(xchg, &dbsplnr, (DpchInvPlnrExpPie*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPPINOUT) {
				req->dpchret = PlnrExpPinout::run(xchg, &dbsplnr, (DpchInvPlnrExpPinout*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPROICADP) {
				req->dpchret = PlnrExpRoicadp::run(xchg, &dbsplnr, (DpchInvPlnrExpRoicadp*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPRTRESNEG) {
				req->dpchret = PlnrExpRtresneg::run(xchg, &dbsplnr, (DpchInvPlnrExpRtresneg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPSPRING) {
				req->dpchret = PlnrExpSpring::run(xchg, &dbsplnr, (DpchInvPlnrExpSpring*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPSTKPERTPL) {
				req->dpchret = PlnrExpStkpertpl::run(xchg, &dbsplnr, (DpchInvPlnrExpStkpertpl*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPSTKREGFILL) {
				req->dpchret = PlnrExpStkregfill::run(xchg, &dbsplnr, (DpchInvPlnrExpStkregfill*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPVANDERPAUW) {
				req->dpchret = PlnrExpVanderpauw::run(xchg, &dbsplnr, (DpchInvPlnrExpVanderpauw*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWG) {
				req->dpchret = PlnrExpWg::run(xchg, &dbsplnr, (DpchInvPlnrExpWg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGBEND) {
				req->dpchret = PlnrExpWgbend::run(xchg, &dbsplnr, (DpchInvPlnrExpWgbend*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGBENDNEG) {
				req->dpchret = PlnrExpWgbendneg::run(xchg, &dbsplnr, (DpchInvPlnrExpWgbendneg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGNEG) {
				req->dpchret = PlnrExpWgneg::run(xchg, &dbsplnr, (DpchInvPlnrExpWgneg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGSUSP) {
				req->dpchret = PlnrExpWgsusp::run(xchg, &dbsplnr, (DpchInvPlnrExpWgsusp*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGTAP) {
				req->dpchret = PlnrExpWgtap::run(xchg, &dbsplnr, (DpchInvPlnrExpWgtap*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNREXPWGTAPNEG) {
				req->dpchret = PlnrExpWgtapneg::run(xchg, &dbsplnr, (DpchInvPlnrExpWgtapneg*) req->dpchinv);
			};
			if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRMEEPTRF2D) {
				req->dpchret = PlnrMeepTrf2d::run(xchg, &dbsplnr, (DpchInvPlnrMeepTrf2d*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRMEEPTRF3D) {
				req->dpchret = PlnrMeepTrf3d::run(xchg, &dbsplnr, (DpchInvPlnrMeepTrf3d*) req->dpchinv);
			};
			if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNU) {
				req->dpchret = PlnrPlotDat1dgnu::run(xchg, &dbsplnr, (DpchInvPlnrPlotDat1dgnu*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDAT1DGNUMULT) {
				req->dpchret = PlnrPlotDat1dgnumult::run(xchg, &dbsplnr, (DpchInvPlnrPlotDat1dgnumult*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDEVSVG) {
				req->dpchret = PlnrPlotDevsvg::run(xchg, &dbsplnr, (DpchInvPlnrPlotDevsvg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT1DGNU) {
				req->dpchret = PlnrPlotDomdat1dgnu::run(xchg, &dbsplnr, (DpchInvPlnrPlotDomdat1dgnu*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DGNU) {
				req->dpchret = PlnrPlotDomdat2dgnu::run(xchg, &dbsplnr, (DpchInvPlnrPlotDomdat2dgnu*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DPNG) {
				req->dpchret = PlnrPlotDomdat2dpng::run(xchg, &dbsplnr, (DpchInvPlnrPlotDomdat2dpng*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMDAT2DVID) {
				req->dpchret = PlnrPlotDomdat2dvid::run(xchg, &dbsplnr, (DpchInvPlnrPlotDomdat2dvid*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDOMZCSSVG) {
				req->dpchret = PlnrPlotDomzcssvg::run(xchg, &dbsplnr, (DpchInvPlnrPlotDomzcssvg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDSNXYSVG) {
				req->dpchret = PlnrPlotDsnxysvg::run(xchg, &dbsplnr, (DpchInvPlnrPlotDsnxysvg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTDSNZSVG) {
				req->dpchret = PlnrPlotDsnzsvg::run(xchg, &dbsplnr, (DpchInvPlnrPlotDsnzsvg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTSTKSVG) {
				req->dpchret = PlnrPlotStksvg::run(xchg, &dbsplnr, (DpchInvPlnrPlotStksvg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTTPOSVG) {
				req->dpchret = PlnrPlotTposvg::run(xchg, &dbsplnr, (DpchInvPlnrPlotTposvg*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRPLOTTPOTXT) {
				req->dpchret = PlnrPlotTpotxt::run(xchg, &dbsplnr, (DpchInvPlnrPlotTpotxt*) req->dpchinv);
			};
			if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRRASTCUB) {
				req->dpchret = PlnrRastCub::run(xchg, &dbsplnr, (DpchInvPlnrRastCub*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRRASTXYBOX) {
				req->dpchret = PlnrRastXybox::run(xchg, &dbsplnr, (DpchInvPlnrRastXybox*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRRASTZLINE) {
				req->dpchret = PlnrRastZline::run(xchg, &dbsplnr, (DpchInvPlnrRastZline*) req->dpchinv);
			};
			if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFD1D) {
				req->dpchret = PlnrWgmodeFd1d::run(xchg, &dbsplnr, (DpchInvPlnrWgmodeFd1d*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFD2D) {
				req->dpchret = PlnrWgmodeFd2d::run(xchg, &dbsplnr, (DpchInvPlnrWgmodeFd2d*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFEM1D) {
				req->dpchret = PlnrWgmodeFem1d::run(xchg, &dbsplnr, (DpchInvPlnrWgmodeFem1d*) req->dpchinv);
			} else if (req->dpchinv->ixPlnrVDpch == VecPlnrVDpch::DPCHINVPLNRWGMODEFEM2D) {
				req->dpchret = PlnrWgmodeFem2d::run(xchg, &dbsplnr, (DpchInvPlnrWgmodeFem2d*) req->dpchinv);
			};

			if (req->dpchret) {
				req->dpchret->oref = req->dpchinv->oref;
				req->dpchret->jref = req->dpchinv->jref;

				xchg->addReq(req);

			} else {
				delete req;
			};
		};
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void PlnrcmbdOpprc::cleanup(
			void* arg
		) {
	XchgPlnrcmbd* xchg = (XchgPlnrcmbd*) arg;

	Mutex::unlock(&(xchg->mcOpprcs), "xchg->mcOpprcs", "PlnrcmbdOpprc", "cleanup");
};


