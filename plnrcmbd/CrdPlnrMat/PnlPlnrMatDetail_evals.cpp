/**
  * \file PnlPlnrMatDetail_evals.cpp
  * job handler for job PnlPlnrMatDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrMatDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacMatIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrMatDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrMatDetail::evalButSupViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacMat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};


