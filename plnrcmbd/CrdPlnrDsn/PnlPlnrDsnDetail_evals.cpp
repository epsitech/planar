/**
  * \file PnlPlnrDsnDetail_evals.cpp
  * job handler for job PnlPlnrDsnDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDsnDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsnIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnDetail::evalButPrjViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnDetail::evalButModViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnDetail::evalButDrvViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


