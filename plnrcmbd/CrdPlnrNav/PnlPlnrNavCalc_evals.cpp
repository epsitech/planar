/**
  * \file PnlPlnrNavCalc_evals.cpp
  * job handler for job PnlPlnrNavCalc (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavCalc::evalLstClcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavCalc::evalButClcViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstClc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstClc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavCalc::evalButClcNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavCalc::evalLstCliAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacCli()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLI, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavCalc::evalButCliViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstCli.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstCli != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavCalc::evalButCliNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};


