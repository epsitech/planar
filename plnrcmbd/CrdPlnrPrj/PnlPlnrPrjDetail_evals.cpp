/**
  * \file PnlPlnrPrjDetail_evals.cpp
  * job handler for job PnlPlnrPrjDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrPrjDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrPrjDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrPrjDetail::evalButJEditAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


