/**
  * \file PnlPlnrNavDesign_evals.cpp
  * job handler for job PnlPlnrNavDesign (implementation of availability/activation evaluation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

bool PnlPlnrNavDesign::evalLstPrjAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacPrj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButPrjViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstPrj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstDsnAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDsnViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstDsn.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDsn != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstDomAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDom()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDOM, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDomViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstDom.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDom != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDomNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstDgdAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDgd()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDGD, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDgdViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstDgd.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDgd != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDgdNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstDvcAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacDvc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDVC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDvcViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstDvc.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstDvc != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButDvcNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstSruAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacSru()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButSruViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstSru.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSru != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButSruNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstStkAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacStk()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButStkViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstStk.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstStk != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButStkNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalLstLyrAvail(
			DbsPlnr* dbsplnr
		) {
	// pre.ixUacLyr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButLyrViewActive(
			DbsPlnr* dbsplnr
		) {
	// LstLyr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstLyr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlPlnrNavDesign::evalButLyrNewcrdActive(
			DbsPlnr* dbsplnr
		) {
	// pre.refDsn()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref) != 0);
	args.push_back(a);

	return(args.back());
};


