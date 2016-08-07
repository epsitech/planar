/**
  * \file PnlPlnrUsrDetail_evals.cpp
  * job handler for job PnlPlnrUsrDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrUsrDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrUsrDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrUsrDetail::evalButPrsViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrUsrDetail::evalButUsgViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrUsrDetail::evalButJEditAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacUsrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


