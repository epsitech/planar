/**
  * \file PnlPlnrUsrDetail.cpp
  * job handler for job PnlPlnrUsrDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "PnlPlnrUsrDetail.h"

// IP blksInclude --- BEGIN
#include "PnlPlnrUsrDetail_blks.cpp"
// IP blksInclude --- END
// IP evalsInclude --- BEGIN
#include "PnlPlnrUsrDetail_evals.cpp"
// IP evalsInclude --- END

/******************************************************************************
 class PnlPlnrUsrDetail
 ******************************************************************************/

// IP constructor.hdr --- BEGIN
PnlPlnrUsrDetail::PnlPlnrUsrDetail(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::PNLPLNRUSRDETAIL, jrefSup, ixPlnrVLocale) {
// IP constructor.hdr --- END

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	feedFPupJ.tag = "FeedFPupJ";
	feedFPupLcl.tag = "FeedFPupLcl";
	VecPlnrVLocale::fillFeed(ixPlnrVLocale, feedFPupLcl);
	feedFPupSte.tag = "FeedFPupSte";
	VecPlnrVMUserState::fillFeed(ixPlnrVLocale, feedFPupSte);
	feedFPupUlv.tag = "FeedFPupUlv";
	VecPlnrVUserlevel::fillFeed(ixPlnrVLocale, feedFPupUlv);

// IP constructor.cust1 --- INSERT

	dirty = false;

	muteRefresh = false;

// IP constructor.cust2 --- INSERT

// IP constructor.cust3 --- INSERT

	updatePreset(dbsplnr, VecPlnrVPreset::PREPLNRREFUSR, jref);
};

PnlPlnrUsrDetail::~PnlPlnrUsrDetail() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
DpchEngPlnr* PnlPlnrUsrDetail::getNewDpchEng(
			set<uint> items
		) {
	DpchEngPlnr* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngPlnrConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupJ, &feedFPupLcl, &feedFPupSte, &feedFPupUlv, &statshr, items);
	};

	return dpcheng;
};

void PnlPlnrUsrDetail::refreshJ(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ListPlnrJMUserState usrJstes;
	PlnrJMUserState* usrJste = NULL;

	string s;

	// feedFPupJ
	feedFPupJ.clear();

	dbsplnr->tblplnrjmuserstate->loadRstByUsr(recUsr.ref, false, usrJstes);

	for (unsigned int i=0;i<usrJstes.nodes.size();i++) {
		usrJste = usrJstes.nodes[i];

		s = "";
		if (usrJste->x1Startd != 0) {
			s = Ftm::date(usrJste->x1Startd) + " -";
			if ((i+2) < usrJstes.nodes.size()) if (usrJstes.nodes[i+1]->x1Startd != 0) s += " " + Ftm::date(usrJstes.nodes[i+1]->x1Startd);
		} else s = "(" + VecPlnrVTag::getTitle(VecPlnrVTag::ALWAYS, ixPlnrVLocale) + ")";
		feedFPupJ.appendRefTitles(usrJste->ref, s);
	};

	insert(moditems, DpchEngData::FEEDFPUPJ);

	refreshRecUsrJste(dbsplnr, moditems);

};

void PnlPlnrUsrDetail::refreshRecUsr(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrMUser* _recUsr = NULL;

	if (dbsplnr->tblplnrmuser->loadRecByRef(recUsr.ref, &_recUsr)) {
		recUsr = *_recUsr;
		delete _recUsr;
	} else recUsr = PlnrMUser();

	dirty = false;

	recUsrJste.ref = recUsr.refJState;
	xchg->removeClstns(VecPlnrVCall::CALLPLNRUSRJSTEMOD_USREQ, jref);
	if (recUsr.ref != 0) xchg->addRefClstn(VecPlnrVCall::CALLPLNRUSRJSTEMOD_USREQ, jref, Clstn::VecVJobmask::ALL, 0, recUsr.ref, Clstn::VecVJactype::LOCK);

	continf.TxtPrs = StubPlnr::getStubPrsStd(dbsplnr, recUsr.refPlnrMPerson, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	continf.TxtSrf = recUsr.sref;
	continf.TxtUsg = StubPlnr::getStubUsgStd(dbsplnr, recUsr.refPlnrMUsergroup, ixPlnrVLocale, Stub::VecVNonetype::FULL);
	contiac.numFPupLcl = feedFPupLcl.getNumByIx(recUsr.ixPlnrVLocale);
	contiac.numFPupUlv = feedFPupUlv.getNumByIx(recUsr.ixPlnrVUserlevel);
	contiac.TxfPwd = recUsr.Password;

	statshr.ButPrsViewAvail = evalButPrsViewAvail(dbsplnr);
	statshr.ButUsgViewAvail = evalButUsgViewAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	refreshJ(dbsplnr, moditems);

};

void PnlPlnrUsrDetail::refreshRecUsrJste(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);
	StatShr oldStatshr(statshr);

	PlnrJMUserState* _recUsrJste = NULL;

	if (dbsplnr->tblplnrjmuserstate->loadRecByRef(recUsrJste.ref, &_recUsrJste)) {
		recUsrJste = *_recUsrJste;
		delete _recUsrJste;
	} else recUsrJste = PlnrJMUserState();

	contiac.numFPupJ = feedFPupJ.getNumByRef(recUsrJste.ref);
	contiac.numFPupSte = feedFPupSte.getNumByIx(recUsrJste.ixVState);

	statshr.ButJEditAvail = evalButJEditAvail(dbsplnr);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

};

void PnlPlnrUsrDetail::refresh(
			DbsPlnr* dbsplnr
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);

// IP refresh --- BEGIN
	// statshr
	statshr.ButSaveAvail = evalButSaveAvail(dbsplnr);
	statshr.ButSaveActive = evalButSaveActive(dbsplnr);
// IP refresh --- END

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
};

void PnlPlnrUsrDetail::updatePreset(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint jrefTrig
			, const bool notif
		) {
// IP updatePreset --- BEGIN
	set<uint> moditems;

	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFUSR) {
		recUsr.ref = xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFUSR, jref);
		refreshRecUsr(dbsplnr, moditems);

		if (notif && !moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	};
// IP updatePreset --- END
};

void PnlPlnrUsrDetail::handleRequest(
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

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRDETAILDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbsplnr, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRUSRDETAILDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTSAVECLICK) {
					handleDpchAppDoButSaveClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPRSVIEWCLICK) {
					handleDpchAppDoButPrsViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTUSGVIEWCLICK) {
					handleDpchAppDoButUsgViewClick(dbsplnr, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTJEDITCLICK) {
					handleDpchAppDoButJEditClick(dbsplnr, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlPlnrUsrDetail::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlPlnrUsrDetail::handleDpchAppDataContiac(
			DbsPlnr* dbsplnr
			, ContIac* _contiac
			, DpchEngPlnr** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (hasAny(diffitems, {ContIac::NUMFPUPSTE, ContIac::NUMFPUPLCL, ContIac::NUMFPUPULV, ContIac::TXFPWD})) {
		if (has(diffitems, ContIac::NUMFPUPSTE)) contiac.numFPupSte = _contiac->numFPupSte;
		if (has(diffitems, ContIac::NUMFPUPLCL)) contiac.numFPupLcl = _contiac->numFPupLcl;
		if (has(diffitems, ContIac::NUMFPUPULV)) contiac.numFPupUlv = _contiac->numFPupUlv;
		if (has(diffitems, ContIac::TXFPWD)) contiac.TxfPwd = _contiac->TxfPwd;
	};

	if (has(diffitems, ContIac::NUMFPUPJ)) {
		recUsrJste.ref = feedFPupJ.getRefByNum(_contiac->numFPupJ);
		refreshRecUsrJste(dbsplnr, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlPlnrUsrDetail::handleDpchAppDoButSaveClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButSaveClick --- INSERT
};

void PnlPlnrUsrDetail::handleDpchAppDoButPrsViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButPrsViewClick --- INSERT
};

void PnlPlnrUsrDetail::handleDpchAppDoButUsgViewClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButUsgViewClick --- INSERT
};

void PnlPlnrUsrDetail::handleDpchAppDoButJEditClick(
			DbsPlnr* dbsplnr
			, DpchEngPlnr** dpcheng
		) {
// IP handleDpchAppDoButJEditClick --- INSERT
};

void PnlPlnrUsrDetail::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRUPD_REFEQ) {
		call->abort = handleCallPlnrUsrUpd_refEq(dbsplnr, call->jref, call->argInv.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRUSRJSTEMOD_USREQ) {
		call->abort = handleCallPlnrUsrJsteMod_usrEq(dbsplnr, call->jref, call->argInv.ref);
	};
};

bool PnlPlnrUsrDetail::handleCallPlnrUsrUpd_refEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
// IP handleCallPlnrUsrUpd_refEq --- INSERT
	return retval;
};

bool PnlPlnrUsrDetail::handleCallPlnrUsrJsteMod_usrEq(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const ubigint refInv
		) {
	bool retval = false;
	set<uint> moditems;

	refreshJ(dbsplnr, moditems);

	xchg->submitDpch(getNewDpchEng(moditems));
	return retval;
};


