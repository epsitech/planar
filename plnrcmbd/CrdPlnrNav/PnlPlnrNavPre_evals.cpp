/**
  * \file PnlPlnrNavPre_evals.cpp
  * job handler for job PnlPlnrNavPre (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavPre::evalTxtDsnAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavPre::evalTxtPrjAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.refPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};


