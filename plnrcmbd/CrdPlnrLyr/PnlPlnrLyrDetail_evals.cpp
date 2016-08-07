/**
  * \file PnlPlnrLyrDetail_evals.cpp
  * job handler for job PnlPlnrLyrDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrLyrDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacLyrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrLyrDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrLyrDetail::evalButMatViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacMat()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref) != 0);
	args.push_back(a);

	return(args.back());
};


