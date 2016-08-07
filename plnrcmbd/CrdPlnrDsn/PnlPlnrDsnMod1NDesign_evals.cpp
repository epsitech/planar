/**
  * \file PnlPlnrDsnMod1NDesign_evals.cpp
  * job handler for job PnlPlnrDsnMod1NDesign (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDsnMod1NDesign::evalButViewActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnMod1NDesign::evalButDeleteActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


