/**
  * \file PnlPlnrTpoDetail_evals.cpp
  * job handler for job PnlPlnrTpoDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrTpoDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrTpoDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrTpoDetail::evalButJEditAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacTpoIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


