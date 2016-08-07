/**
  * \file PnlPlnrArrDetail_evals.cpp
  * job handler for job PnlPlnrArrDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrArrDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacArrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARR, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrArrDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrArrDetail::evalButTpoViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpo()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrArrDetail::evalButDsnViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


