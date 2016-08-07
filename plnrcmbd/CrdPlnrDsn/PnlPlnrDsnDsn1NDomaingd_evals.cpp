/**
  * \file PnlPlnrDsnDsn1NDomaingd_evals.cpp
  * job handler for job PnlPlnrDsnDsn1NDomaingd (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrDsnDsn1NDomaingd::evalButUpActive(
			DbsPlnr* dbsplnr
		) {
	// sel() & !sel.first()

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = false; a = (qry->stgiac.jnum == 1);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlPlnrDsnDsn1NDomaingd::evalButDownActive(
			DbsPlnr* dbsplnr
		) {
	// sel() & !sel.last()

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = false; a = (qry->stgiac.jnum == qry->statshr.ntot);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

bool PnlPlnrDsnDsn1NDomaingd::evalButViewActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrDsnDsn1NDomaingd::evalButDeleteActive(
			DbsPlnr* dbsplnr
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};


