/**
  * \file PnlPlnrNavGlobal_evals.cpp
  * job handler for job PnlPlnrNavGlobal (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavGlobal::evalLstDtpAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavGlobal::evalButDtpViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstDtp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDtp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavGlobal::evalLstCtpAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacCtp()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCTP, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavGlobal::evalButCtpViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstCtp.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCtp != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavGlobal::evalLstMatAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacMat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavGlobal::evalButMatViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstMat.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstMat != 0);
	args.push_back(a);

	return(args.back());
};


