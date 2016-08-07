/**
  * \file PnlPlnrDtpAPar_evals.cpp
  * job handler for job PnlPlnrDtpAPar (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDtpAPar::evalButDuplicateActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDtpAPar::evalButDeleteActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


