/**
  * \file PnlPlnrSruRec_evals.cpp
  * job handler for job PnlPlnrSruRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrSruRec::evalPnl1nblockAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrSruRec::evalPnlmnlayerAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrSruRec::evalPnlmnstackAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrSruRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refSru()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSRU, jref) != 0);
	args.push_back(a);

	return(args.back());
};


