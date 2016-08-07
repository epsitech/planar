/**
  * \file PnlPlnrCliRef1NFile_evals.cpp
  * job handler for job PnlPlnrCliRef1NFile (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrCliRef1NFile::evalButViewActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrCliRef1NFile::evalButDeleteActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


