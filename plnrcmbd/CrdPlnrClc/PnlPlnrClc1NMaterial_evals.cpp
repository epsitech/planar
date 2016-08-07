/**
  * \file PnlPlnrClc1NMaterial_evals.cpp
  * job handler for job PnlPlnrClc1NMaterial (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrClc1NMaterial::evalButViewActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrClc1NMaterial::evalButDeleteActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


