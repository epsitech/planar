/**
  * \file PnlPlnrPrsDetail_evals.cpp
  * job handler for job PnlPlnrPrsDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrPrsDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrPrsDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrPrsDetail::evalButJEditAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};


