/**
  * \file PnlPlnrStkDetail_evals.cpp
  * job handler for job PnlPlnrStkDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrStkDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacStkIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrStkDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrStkDetail::evalButDsnViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrStkDetail::evalButLyrViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacLyr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrStkDetail::evalButLyrViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstLyr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLyr != 0);
	args.push_back(a);

	return(args.back());
};


