/**
  * \file PnlPlnrRtcDetail_evals.cpp
  * job handler for job PnlPlnrRtcDetail (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrRtcDetail::evalButSaveAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacRtcIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACRTC, jref) & VecPlnrWUiaccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrRtcDetail::evalButSaveActive(
			DbsPlnr* dbsplnr
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrRtcDetail::evalButDsnViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrRtcDetail::evalButLyrViewAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacLyr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) != 0);
	args.push_back(a);

	return(args.back());
};


