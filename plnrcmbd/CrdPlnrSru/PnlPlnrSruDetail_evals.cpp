/**
  * \file PnlPlnrSruDetail_evals.cpp
  * job handler for job PnlPlnrSruDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrSruDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacSruIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrSruDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};


