/**
  * \file PnlPlnrDsnRec_evals.cpp
  * job handler for job PnlPlnrDsnRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDsnRec::evalPnlviewxyAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|xy)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlviewzAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|z)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::Z, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlmod1ndesignAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.modEq(0)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerRefToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_MODEQ, jref, 0, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnldsn1ndeviceAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|xy)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnldsn1nstackAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|z)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::Z, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnl1nblockAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnl1nreticleAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.typEq(vrtlyr)

	vector<bool> args;
	bool a;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_TYPEQ, jref, VecPlnrVMDesignBasetype::VRTLYR, a);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlhk1nlevelAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|z)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::Z, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlhk1nvertexAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|xy)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlhk1nlineguideAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|xy)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlhk1narcguideAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|xy)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlhk1nlayerAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|z)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::Z, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalPnlhk1nstructureAvail(
			DbsPlnr* dbsplnr
		) {
	// dsn.dimEq(xyz|xy)

	vector<bool> args;
	bool a, b;

	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XYZ, a);
	args.push_back(a);
	a = false; xchg->triggerIxToBoolvalCall(dbsplnr, VecPlnrVCall::CALLPLNRDSN_DIMEQ, jref, VecPlnrVMDesignDim::XY, a);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlPlnrDsnRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


