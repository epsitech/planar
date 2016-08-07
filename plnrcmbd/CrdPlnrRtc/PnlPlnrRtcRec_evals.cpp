/**
  * \file PnlPlnrRtcRec_evals.cpp
  * job handler for job PnlPlnrRtcRec (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrRtcRec::evalButRegularizeActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refRtc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFRTC, jref) != 0);
	args.push_back(a);

	return(args.back());
};


