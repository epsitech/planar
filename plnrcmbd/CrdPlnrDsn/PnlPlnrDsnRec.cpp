/**
  * \file PnlPlnrDsnRec.cpp
  * job handler for job PnlPlnrDsnRec (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrDsnRec.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrDsnRec_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrDsnRec_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrDsnRec
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrDsnRec::PnlPlnrDsnRec(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRDSNREC, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	pnlpre = NULL;
	pnldetail = NULL;
	pnlviewxy = NULL;
	pnlviewz = NULL;
	pnlmod1ndesign = NULL;
	pnldrv1ndesign = NULL;
	pnldsn1ndevice = NULL;
	pnldsn1nstack = NULL;
	pnldsn1ndomaingd = NULL;
	pnldsn1ndomain = NULL;
	pnl1nblock = NULL;
	pnl1nreticle = NULL;
	pnlhk1nlevel = NULL;
	pnlhk1nvertex = NULL;
	pnlhk1nlineguide = NULL;
	pnlhk1narcguide = NULL;
	pnlhk1nlayer = NULL;
	pnlhk1nstructure = NULL;

// IP constructor.cust1 --- INSERT

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

	xchg->addClstn(VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRDSN_MODEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRDSN_TYPEQ, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFDSN, jref);
};

PnlPlnrDsnRec::~PnlPlnrDsnRec() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrDsnRec::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrDsnRec::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// continf
	continf.TxtRef = StubPlnr::getStubDsnStd(dbsplnr, recDsn.ref, ixPlnrVLocale, Stub::VecVNonetype::FULL);

	// statshr
	if (recDsn.ref == 0) statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;

	statshr.pnlviewxyAvail = evalPnlviewxyAvail(dbsplnr);
	statshr.pnlviewzAvail = evalPnlviewzAvail(dbsplnr);
	statshr.pnlmod1ndesignAvail = evalPnlmod1ndesignAvail(dbsplnr);
	statshr.pnldsn1ndeviceAvail = evalPnldsn1ndeviceAvail(dbsplnr);
	statshr.pnldsn1nstackAvail = evalPnldsn1nstackAvail(dbsplnr);
	statshr.pnl1nblockAvail = evalPnl1nblockAvail(dbsplnr);
	statshr.pnl1nreticleAvail = evalPnl1nreticleAvail(dbsplnr);
	statshr.pnlhk1nlevelAvail = evalPnlhk1nlevelAvail(dbsplnr);
	statshr.pnlhk1nvertexAvail = evalPnlhk1nvertexAvail(dbsplnr);
	statshr.pnlhk1nlineguideAvail = evalPnlhk1nlineguideAvail(dbsplnr);
	statshr.pnlhk1narcguideAvail = evalPnlhk1narcguideAvail(dbsplnr);
	statshr.pnlhk1nlayerAvail = evalPnlhk1nlayerAvail(dbsplnr);
	statshr.pnlhk1nstructureAvail = evalPnlhk1nstructureAvail(dbsplnr);
	statshr.ButRegularizeActive = evalButRegularizeActive(dbsplnr);

	if (statshr.ixPlnrVExpstate == VecPlnrVExpstate::MIND) {
		if (pnlpre) {delete pnlpre; pnlpre = NULL;};
		if (pnldetail) {delete pnldetail; pnldetail = NULL;};
		if (pnlviewxy) {delete pnlviewxy; pnlviewxy = NULL;};
		if (pnlviewz) {delete pnlviewz; pnlviewz = NULL;};
		if (pnlmod1ndesign) {delete pnlmod1ndesign; pnlmod1ndesign = NULL;};
		if (pnldrv1ndesign) {delete pnldrv1ndesign; pnldrv1ndesign = NULL;};
		if (pnldsn1ndevice) {delete pnldsn1ndevice; pnldsn1ndevice = NULL;};
		if (pnldsn1nstack) {delete pnldsn1nstack; pnldsn1nstack = NULL;};
		if (pnldsn1ndomaingd) {delete pnldsn1ndomaingd; pnldsn1ndomaingd = NULL;};
		if (pnldsn1ndomain) {delete pnldsn1ndomain; pnldsn1ndomain = NULL;};
		if (pnl1nblock) {delete pnl1nblock; pnl1nblock = NULL;};
		if (pnl1nreticle) {delete pnl1nreticle; pnl1nreticle = NULL;};
		if (pnlhk1nlevel) {delete pnlhk1nlevel; pnlhk1nlevel = NULL;};
		if (pnlhk1nvertex) {delete pnlhk1nvertex; pnlhk1nvertex = NULL;};
		if (pnlhk1nlineguide) {delete pnlhk1nlineguide; pnlhk1nlineguide = NULL;};
		if (pnlhk1narcguide) {delete pnlhk1narcguide; pnlhk1narcguide = NULL;};
		if (pnlhk1nlayer) {delete pnlhk1nlayer; pnlhk1nlayer = NULL;};
		if (pnlhk1nstructure) {delete pnlhk1nstructure; pnlhk1nstructure = NULL;};
	} else {
		if (!pnlpre) pnlpre = new PnlPlnrDsnPre(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldetail) pnldetail = new PnlPlnrDsnDetail(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlviewxy) pnlviewxy = new PnlPlnrDsnViewxy(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlviewz) pnlviewz = new PnlPlnrDsnViewz(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlmod1ndesign) pnlmod1ndesign = new PnlPlnrDsnMod1NDesign(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldrv1ndesign) pnldrv1ndesign = new PnlPlnrDsnDrv1NDesign(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldsn1ndevice) pnldsn1ndevice = new PnlPlnrDsnDsn1NDevice(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldsn1nstack) pnldsn1nstack = new PnlPlnrDsnDsn1NStack(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldsn1ndomaingd) pnldsn1ndomaingd = new PnlPlnrDsnDsn1NDomaingd(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnldsn1ndomain) pnldsn1ndomain = new PnlPlnrDsnDsn1NDomain(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1nblock) pnl1nblock = new PnlPlnrDsn1NBlock(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnl1nreticle) pnl1nreticle = new PnlPlnrDsn1NReticle(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nlevel) pnlhk1nlevel = new PnlPlnrDsnHk1NLevel(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nvertex) pnlhk1nvertex = new PnlPlnrDsnHk1NVertex(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nlineguide) pnlhk1nlineguide = new PnlPlnrDsnHk1NLineguide(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1narcguide) pnlhk1narcguide = new PnlPlnrDsnHk1NArcguide(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nlayer) pnlhk1nlayer = new PnlPlnrDsnHk1NLayer(xchg, dbsplnr, jref, ixPlnrVLocale);
		if (!pnlhk1nstructure) pnlhk1nstructure = new PnlPlnrDsnHk1NStructure(xchg, dbsplnr, jref, ixPlnrVLocale);
	};

	statshr.jrefPre = ((pnlpre) ? pnlpre->jref : 0);
	statshr.jrefDetail = ((pnldetail) ? pnldetail->jref : 0);
	statshr.jrefViewxy = ((pnlviewxy) ? pnlviewxy->jref : 0);
	statshr.jrefViewz = ((pnlviewz) ? pnlviewz->jref : 0);
	statshr.jrefMod1NDesign = ((pnlmod1ndesign) ? pnlmod1ndesign->jref : 0);
	statshr.jrefDrv1NDesign = ((pnldrv1ndesign) ? pnldrv1ndesign->jref : 0);
	statshr.jrefDsn1NDevice = ((pnldsn1ndevice) ? pnldsn1ndevice->jref : 0);
	statshr.jrefDsn1NStack = ((pnldsn1nstack) ? pnldsn1nstack->jref : 0);
	statshr.jrefDsn1NDomaingd = ((pnldsn1ndomaingd) ? pnldsn1ndomaingd->jref : 0);
	statshr.jrefDsn1NDomain = ((pnldsn1ndomain) ? pnldsn1ndomain->jref : 0);
	statshr.jref1NBlock = ((pnl1nblock) ? pnl1nblock->jref : 0);
	statshr.jref1NReticle = ((pnl1nreticle) ? pnl1nreticle->jref : 0);
	statshr.jrefHk1NLevel = ((pnlhk1nlevel) ? pnlhk1nlevel->jref : 0);
	statshr.jrefHk1NVertex = ((pnlhk1nvertex) ? pnlhk1nvertex->jref : 0);
	statshr.jrefHk1NLineguide = ((pnlhk1nlineguide) ? pnlhk1nlineguide->jref : 0);
	statshr.jrefHk1NArcguide = ((pnlhk1narcguide) ? pnlhk1narcguide->jref : 0);
	statshr.jrefHk1NLayer = ((pnlhk1nlayer) ? pnlhk1nlayer->jref : 0);
	statshr.jrefHk1NStructure = ((pnlhk1nstructure) ? pnlhk1nstructure->jref : 0);

// IP refresh --- END
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrDsnRec::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDSN) {
		PlnrMDesign* _recDsn = NULL;

		recDsn.ref = 0;

		if (dbsplnr->tblplnrmdesign->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref), &_recDsn)) {
			recDsn = *_recDsn;

			delete _recDsn;
		};

		if (recDsn.ref != 0) {
			if (pnlpre) pnlpre->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldetail) pnldetail->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlviewxy) pnlviewxy->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlviewz) pnlviewz->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlmod1ndesign) pnlmod1ndesign->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldrv1ndesign) pnldrv1ndesign->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldsn1ndevice) pnldsn1ndevice->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldsn1nstack) pnldsn1nstack->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldsn1ndomaingd) pnldsn1ndomaingd->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnldsn1ndomain) pnldsn1ndomain->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1nblock) pnl1nblock->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnl1nreticle) pnl1nreticle->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nlevel) pnlhk1nlevel->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nvertex) pnlhk1nvertex->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nlineguide) pnlhk1nlineguide->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1narcguide) pnlhk1narcguide->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nlayer) pnlhk1nlayer->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
			if (pnlhk1nstructure) pnlhk1nstructure->updatePreset(dbsplnr, ixPlnrVPreset, jrefTrig, notif);
		};

		refresh(dbsplnr, moditems);
		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrDsnRec::minimize(
			DbsPlnr* dbsplnr
			, const bool notif
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixPlnrVExpstate != VecPlnrVExpstate::MIND) {
		statshr.ixPlnrVExpstate = VecPlnrVExpstate::MIND;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsplnr, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlPlnrDsnRec::regularize(
			DbsPlnr* dbsplnr
			, const bool notif
			, DpchEngPlnr** dpcheng
		) {
	set<uint> moditems;

	if (statshr.ixPlnrVExpstate != VecPlnrVExpstate::REGD) {
		statshr.ixPlnrVExpstate = VecPlnrVExpstate::REGD;
		insert(moditems, DpchEngData::STATSHR);

		refresh(dbsplnr, moditems);
	};

	if (notif) {
		if (dpcheng) *dpcheng = getNewDpchEng(moditems);
		else if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
};

void PnlPlnrDsnRec::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRINIT) {
			handleDpchAppPlnrInit(dbsplnr, (DpchAppPlnrInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRDSNRECDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrDsnRec::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrDsnRec::handleDpchAppDoButMinimizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	minimize(dbsplnr, true, dpcheng);
};

void PnlPlnrDsnRec::handleDpchAppDoButRegularizeClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
	regularize(dbsplnr, true, dpcheng);
};

void PnlPlnrDsnRec::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRDSN_DIMEQ) {
		call->abort = handleCallPlnrDsn_dimEq(dbsplnr, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSN_MODEQ) {
		call->abort = handleCallPlnrDsn_modEq(dbsplnr, call->jref, call->argInv.ref, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSN_TYPEQ) {
		call->abort = handleCallPlnrDsn_typEq(dbsplnr, call->jref, call->argInv.ix, call->argRet.boolval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRDSNUPD_REFEQ) {
		call->abort = handleCallPlnrDsnUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrDsnRec::handleCallPlnrDsn_dimEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrDsn_dimEq --- BEGIN
		if (recDsn.ref != 0) boolvalRet = (recDsn.ixVDim == ixInv);
// IP handleCallPlnrDsn_dimEq --- END
	return retval;
};

bool PnlPlnrDsnRec::handleCallPlnrDsn_modEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrDsn_modEq --- BEGIN
		if (recDsn.ref != 0) boolvalRet = (recDsn.modRefPlnrMDesign == refInv);
// IP handleCallPlnrDsn_modEq --- END
	return retval;
};

bool PnlPlnrDsnRec::handleCallPlnrDsn_typEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, bool& boolvalRet
		) {
	bool retval = false;
// IP handleCallPlnrDsn_typEq --- BEGIN
		if (recDsn.ref != 0) boolvalRet = (recDsn.ixVBasetype == ixInv);
// IP handleCallPlnrDsn_typEq --- END
	return retval;
};

bool PnlPlnrDsnRec::handleCallPlnrDsnUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrDsnUpd_refEq --- INSERT
	return retval;
};


