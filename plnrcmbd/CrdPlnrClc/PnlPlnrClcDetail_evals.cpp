/**
  * \file PnlPlnrClcDetail_evals.cpp
  * job handler for job PnlPlnrClcDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrClcDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacClcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrClcDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrClcDetail::evalButPrjViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrClcDetail::evalButDsnViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


