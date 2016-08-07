/**
  * \file PnlPlnrNavLayout_evals.cpp
  * job handler for job PnlPlnrNavLayout (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavLayout::evalLstTpoAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpo()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalButTpoViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstTpo.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstTpo != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalLstArrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacArr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalButArrViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstArr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstArr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalLstAriAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacAri()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalButAriViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstAri.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstAri != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalLstRtcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacRtc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACRTC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavLayout::evalButRtcViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstRtc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstRtc != 0);
	args.push_back(a);

	return(args.back());
};


