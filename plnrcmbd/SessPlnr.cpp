/**
  * \file SessPlnr.cpp
  * job handler for job SessPlnr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "SessPlnr.h"

// IP blksInclude --- BEGIN
#include "SessPlnr_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class SessPlnr
 ******************************************************************************/

SessPlnr::SessPlnr(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const ubigint refPlnrMUser
			, const string& ip
		) : JobPlnr(xchg, VecPlnrVJob::SESSPLNR, jrefSup) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

	crdnav = NULL;

// IP constructor.cust1 --- INSERT

	vector<ubigint> refs;

	ubigint refSes;

	PlnrMUser* usr = NULL;

	bool adm;

	ListPlnrRMUserMUsergroup urus;
	PlnrRMUserMUsergroup* uru = NULL;

	// create new session with start time
	time_t rawtime;
	time(&rawtime);

	refSes = dbsplnr->tblplnrmsession->insertNewRec(NULL, refPlnrMUser, (uint) rawtime, 0, ip);

	xchg->addRefPreset(VecPlnrVPreset::PREPLNRSESS, jref, refSes);
	xchg->addTxtvalPreset(VecPlnrVPreset::PREPLNRIP, jref, ip);

	// set locale and presetings corresponding to user
	dbsplnr->tblplnrmuser->loadRecByRef(refPlnrMUser, &usr);

	ixPlnrVLocale = usr->ixPlnrVLocale;
	adm = (usr->ixPlnrVUserlevel == VecPlnrVUserlevel::ADM);

	xchg->addBoolvalPreset(VecPlnrVPreset::PREPLNRADM, jref, adm);

	xchg->addRefPreset(VecPlnrVPreset::PREPLNRGRP, jref, usr->refPlnrMUsergroup);
	xchg->addRefPreset(VecPlnrVPreset::PREPLNROWN, jref, refPlnrMUser);

	delete usr;

	// set jrefSess locale (for access to PlnrQSelect from rst-type panel queries)
	xchg->addRefPreset(VecPlnrVPreset::PREPLNRJREFSESS, jref, jref);

	// fill query in PlnrQSelect with all applicable user groups
	dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, 1, 0, 0);

	if (usr->ixPlnrVUserlevel == VecPlnrVUserlevel::ADM) {
		dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMUsergroup ORDER BY ref ASC", false, refs);

		for (unsigned int i=0;i<refs.size();i++) dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, i+2, 0, refs[i]);

	} else {
		dbsplnr->tblplnrrmusermusergroup->loadRstByUsr(refPlnrMUser, false, urus);

		for (unsigned int i=0;i<urus.nodes.size();i++) {
			uru = urus.nodes[i];

			usgaccs[uru->refPlnrMUsergroup] = uru->ixPlnrVUserlevel;
			dbsplnr->tblplnrqselect->insertNewRec(NULL, jref, i+2, 0, uru->refPlnrMUsergroup);
		};
	};

	// determine UI access rights for each card
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRUSG, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRUSR, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRPRS, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRFIL, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACDTP, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRDTP, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACCTP, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRCTP, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRMAT, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRPRJ, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRDSN, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACDOM, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRDOM, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACDGD, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRDGD, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACDVC, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRDVC, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRSRU, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRSTK, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRLYR, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRCLC, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACCLI, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRCLI, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRTPO, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACARR, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRARR, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACARI, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRARI, adm, urus, refPlnrMUser));
	xchg->addIxPreset(VecPlnrVPreset::PREPLNRIXUACRTC, jref, getIxUac(dbsplnr, VecPlnrVCard::CRDPLNRRTC, adm, urus, refPlnrMUser));

	crdnav = new CrdPlnrNav(xchg, dbsplnr, jref, ixPlnrVLocale);

// IP constructor.cust2 --- INSERT

	statshr.jrefCrdnav = crdnav->jref;

	xchg->addClstn(VecPlnrVCall::CALLPLNRACCESS, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRCRDACTIVE, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRCRDCLOSE, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRCRDOPEN, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRLOG, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecPlnrVCall::CALLPLNRREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

SessPlnr::~SessPlnr() {
// IP destructor.spec --- INSERT

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
uint SessPlnr::checkCrdActive(
			const uint ixPlnrVCard
		) {
	if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDSN) return evalCrddsnActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDOM) return evalCrddomActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDGD) return evalCrddgdActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDVC) return evalCrddvcActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSRU) return evalCrdsruActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSTK) return evalCrdstkActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRLYR) return evalCrdlyrActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLC) return evalCrdclcActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLI) return evalCrdcliActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARR) return evalCrdarrActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARI) return evalCrdariActive();
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRRTC) return evalCrdrtcActive();

return 0;
};

uint SessPlnr::evalCrddsnActive() {
	// pre.refPrj() > pre.void()

	vector<uint> args;
	bool a, b;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref)) ? VecPlnrVPreset::PREPLNRREFPRJ : 0);
	args.push_back(VecPlnrVPreset::VOID);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessPlnr::evalCrddomActive() {
	// pre.refDsn()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref)) ? VecPlnrVPreset::PREPLNRREFDSN : 0);

	return(args.back());
};

uint SessPlnr::evalCrddgdActive() {
	// pre.refDsn()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref)) ? VecPlnrVPreset::PREPLNRREFDSN : 0);

	return(args.back());
};

uint SessPlnr::evalCrddvcActive() {
	// pre.refDsn()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref)) ? VecPlnrVPreset::PREPLNRREFDSN : 0);

	return(args.back());
};

uint SessPlnr::evalCrdsruActive() {
	// pre.refDtp() > pre.refDvc() > pre.refDsn()

	vector<uint> args;
	bool a, b;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDTP, jref)) ? VecPlnrVPreset::PREPLNRREFDTP : 0);
	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDVC, jref)) ? VecPlnrVPreset::PREPLNRREFDVC : 0);
	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref)) ? VecPlnrVPreset::PREPLNRREFDSN : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessPlnr::evalCrdstkActive() {
	// pre.refDsn()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref)) ? VecPlnrVPreset::PREPLNRREFDSN : 0);

	return(args.back());
};

uint SessPlnr::evalCrdlyrActive() {
	// pre.refStk() > pre.refDsn()

	vector<uint> args;
	bool a, b;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFSTK, jref)) ? VecPlnrVPreset::PREPLNRREFSTK : 0);
	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFDSN, jref)) ? VecPlnrVPreset::PREPLNRREFDSN : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessPlnr::evalCrdclcActive() {
	// pre.refPrj()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref)) ? VecPlnrVPreset::PREPLNRREFPRJ : 0);

	return(args.back());
};

uint SessPlnr::evalCrdcliActive() {
	// pre.refClc() > pre.refPrj()

	vector<uint> args;
	bool a, b;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFCLC, jref)) ? VecPlnrVPreset::PREPLNRREFCLC : 0);
	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFPRJ, jref)) ? VecPlnrVPreset::PREPLNRREFPRJ : 0);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	if (a != 0) args.push_back(a);
	else args.push_back(b);

	return(args.back());
};

uint SessPlnr::evalCrdarrActive() {
	// pre.refTpo()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref)) ? VecPlnrVPreset::PREPLNRREFTPO : 0);

	return(args.back());
};

uint SessPlnr::evalCrdariActive() {
	// pre.refTpo()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref)) ? VecPlnrVPreset::PREPLNRREFTPO : 0);

	return(args.back());
};

uint SessPlnr::evalCrdrtcActive() {
	// pre.refTpo()

	vector<uint> args;
	bool a;

	args.push_back((xchg->getRefPreset(VecPlnrVPreset::PREPLNRREFTPO, jref)) ? VecPlnrVPreset::PREPLNRREFTPO : 0);

	return(args.back());
};

uint SessPlnr::checkUiaccess(
			const uint ixPlnrVCard
		) {
	if (ixPlnrVCard == VecPlnrVCard::CRDPLNRUSG) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSG, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRUSR) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACUSR, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRPRS) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRS, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRFIL) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACFIL, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDTP) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDTP, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCTP) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCTP, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRMAT) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACMAT, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRPRJ) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACPRJ, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDSN) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDSN, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDOM) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDOM, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDGD) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDGD, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDVC) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACDVC, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSRU) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSRU, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSTK) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACSTK, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRLYR) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACLYR, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLC) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLC, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLI) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACCLI, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRTPO) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACTPO, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARR) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARR, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARI) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACARI, jref);
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRRTC) return xchg->getIxPreset(VecPlnrVPreset::PREPLNRIXUACRTC, jref);

	return 0;
};

uint SessPlnr::getIxUac(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCard
			, const bool adm
			, ListPlnrRMUserMUsergroup& urus
			, const ubigint refPlnrMUser
		) {
	uint retval = 0;

	PlnrRMUserMUsergroup* uru = NULL;
	PlnrAMUsergroupAccess* usgAacc = NULL;
	PlnrAMUserAccess* usrAacc = NULL;

	if (adm) {
		retval = VecPlnrWUiaccess::EDIT + VecPlnrWUiaccess::EXEC + VecPlnrWUiaccess::VIEW;

	} else {
		for (unsigned int i=0;i<urus.nodes.size();i++) {
			uru = urus.nodes[i];

			if (dbsplnr->tblplnramusergroupaccess->loadRecBySQL("SELECT * FROM TblPlnrAMUsergroupAccess WHERE refPlnrMUsergroup = " + to_string(uru->refPlnrMUsergroup) + " AND x1IxPlnrVCard = " + to_string(ixPlnrVCard), &usgAacc)) {
				retval |= usgAacc->ixPlnrWUiaccess;
				delete usgAacc;
			};
		};

		if (dbsplnr->tblplnramuseraccess->loadRecBySQL("SELECT * FROM TblPlnrAMUserAccess WHERE refPlnrMUser = " + to_string(refPlnrMUser) + " AND x1IxPlnrVCard = " + to_string(ixPlnrVCard), &usrAacc)) {
			retval = usrAacc->ixPlnrWUiaccess;
			delete usrAacc;
		};
	};

	return retval;
};

uint SessPlnr::checkAccess(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVCard
			, const ubigint ref
		) {
	uint retval = VecPlnrVAccess::NONE;

	ubigint grp;
	ubigint own;

	map<ubigint,uint>::iterator it;

	ubigint refPlnrMUser;
	uint ixPlnrVMaintable;

	PlnrAccRMUserUniversal* ausrRunv = NULL;
	PlnrRMUsergroupUniversal* usgRunv = NULL;

	ixPlnrVMaintable = crdToMtb(ixPlnrVCard);

	if (ixPlnrVMaintable == VecPlnrVMaintable::VOID) {
		retval = VecPlnrVAccess::FULL;

	} else if (hasGrpown(ixPlnrVMaintable)) {
		// find record's group and owner
		dbsplnr->loadUbigintBySQL("SELECT grp FROM " + VecPlnrVMaintable::getSref(ixPlnrVMaintable) + " WHERE ref = " + to_string(ref), grp);
		dbsplnr->loadUbigintBySQL("SELECT own FROM " + VecPlnrVMaintable::getSref(ixPlnrVMaintable) + " WHERE ref = " + to_string(ref), own);

		// administrators can edit any record
		if (xchg->getBoolvalPreset(VecPlnrVPreset::PREPLNRADM, jref)) retval = VecPlnrVAccess::FULL;

		// all non-administrators can view user group non-specific records but not edit them
		if (retval == VecPlnrVAccess::NONE) {
			if (grp == 0) retval = VecPlnrVAccess::VIEW;
		};

		if (retval == VecPlnrVAccess::NONE) {
			refPlnrMUser = xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref);

			// a record's owner has full rights on his records
			if (refPlnrMUser == own) retval = VecPlnrVAccess::FULL;

			if (retval == VecPlnrVAccess::NONE) {
				it = usgaccs.find(grp);
				if (it != usgaccs.end()) {
					if (it->second == VecPlnrVUserlevel::GADM) {
						// group admins have full access to all of the group's records
						retval = VecPlnrVAccess::FULL;
					} else {
						// other group members have view access only
						retval = VecPlnrVAccess::VIEW;
					};
				};
			};

			if (retval != VecPlnrVAccess::FULL) {
				// individual record access right
				if (dbsplnr->tblplnraccrmuseruniversal->loadRecByUsrMtbUnv(refPlnrMUser, ixPlnrVMaintable, ref, &ausrRunv)) {
					retval = ausrRunv->ixPlnrVAccess;
					delete ausrRunv;
				};
			};

			if (retval != VecPlnrVAccess::FULL) {
				// individual record access right due to group membership
				for (it = usgaccs.begin() ; it != usgaccs.end() ; it++) {

					if (dbsplnr->tblplnrrmusergroupuniversal->loadRecByUsgMtbUnv(it->second, ixPlnrVMaintable, ref, &usgRunv)) {
						if (retval == VecPlnrVAccess::VIEW) {
							if (usgRunv->ixPlnrVAccess == VecPlnrVAccess::FULL) retval = VecPlnrVAccess::FULL;
						} else {
							retval = usgRunv->ixPlnrVAccess;
						};

						delete usgRunv;
					};

					if (retval == VecPlnrVAccess::FULL) break;
				};
			};
		};

	} else {
		if (xchg->getBoolvalPreset(VecPlnrVPreset::PREPLNRADM, jref)) retval = VecPlnrVAccess::FULL;
		else retval = VecPlnrVAccess::VIEW;
	};

	return retval;
};

void SessPlnr::logAccess(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVPreset
			, const ubigint preUref
			, const uint ixPlnrVCard
			, const ubigint unvUref
		) {
	ubigint refPlnrMUser;
	uint unvIxPlnrVMaintable;
	uint preIxPlnrVMaintable;

	PlnrHistRMUserUniversal* husrRunv = NULL;

	refPlnrMUser = xchg->getRefPreset(VecPlnrVPreset::PREPLNROWN, jref);
	unvIxPlnrVMaintable = crdToMtb(ixPlnrVCard);
	preIxPlnrVMaintable = preToMtb(ixPlnrVPreset);

	if (!dbsplnr->tblplnrhistrmuseruniversal->loadRecBySQL("SELECT * FROM TblPlnrHistRMUserUniversal WHERE refPlnrMUser = " + to_string(refPlnrMUser)
				+ " AND unvIxPlnrVMaintable = " + to_string(unvIxPlnrVMaintable) + " AND unvUref = " + to_string(unvUref) + " AND ixPlnrVCard = " + to_string(ixPlnrVCard), &husrRunv)) {
		husrRunv = new PlnrHistRMUserUniversal(0, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVCard, ixPlnrVPreset, preIxPlnrVMaintable, preUref, 0);
	};

	husrRunv->start = time(NULL);

	if (husrRunv->ref == 0) dbsplnr->tblplnrhistrmuseruniversal->insertRec(husrRunv);
	else dbsplnr->tblplnrhistrmuseruniversal->updateRec(husrRunv);

	xchg->triggerIxRefCall(dbsplnr, VecPlnrVCall::CALLPLNRHUSRRUNVMOD_CRDUSREQ, jref, ixPlnrVCard, refPlnrMUser);

	delete husrRunv;
};

uint SessPlnr::crdToMtb(
			const uint ixPlnrVCard
		) {
	if (ixPlnrVCard == VecPlnrVCard::CRDPLNRUSG) return VecPlnrVMaintable::TBLPLNRMUSERGROUP;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRUSR) return VecPlnrVMaintable::TBLPLNRMUSER;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRPRS) return VecPlnrVMaintable::TBLPLNRMPERSON;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRFIL) return VecPlnrVMaintable::TBLPLNRMFILE;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDTP) return VecPlnrVMaintable::TBLPLNRMDEVICE;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCTP) return VecPlnrVMaintable::TBLPLNRMCALC;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRMAT) return VecPlnrVMaintable::TBLPLNRMMATERIAL;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRPRJ) return VecPlnrVMaintable::TBLPLNRMPROJECT;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDSN) return VecPlnrVMaintable::TBLPLNRMDESIGN;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDOM) return VecPlnrVMaintable::TBLPLNRMDOMAIN;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDGD) return VecPlnrVMaintable::TBLPLNRMDOMAINGD;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDVC) return VecPlnrVMaintable::TBLPLNRMDEVICE;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSRU) return VecPlnrVMaintable::TBLPLNRMSTRUCTURE;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSTK) return VecPlnrVMaintable::TBLPLNRMSTACK;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRLYR) return VecPlnrVMaintable::TBLPLNRMLAYER;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLC) return VecPlnrVMaintable::TBLPLNRMCALC;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLI) return VecPlnrVMaintable::TBLPLNRMCALCITEM;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRTPO) return VecPlnrVMaintable::TBLPLNRMTAPEOUT;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARR) return VecPlnrVMaintable::TBLPLNRMARRAY;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARI) return VecPlnrVMaintable::TBLPLNRMARRAYITEM;
	else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRRTC) return VecPlnrVMaintable::TBLPLNRMRETICLE;

	return VecPlnrVMaintable::VOID;
};

uint SessPlnr::preToMtb(
			const uint ixPlnrVPreset
		) {
	if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFAGD) return VecPlnrVMaintable::TBLPLNRMARCGUIDE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFARI) return VecPlnrVMaintable::TBLPLNRMARRAYITEM;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFARR) return VecPlnrVMaintable::TBLPLNRMARRAY;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFBLK) return VecPlnrVMaintable::TBLPLNRMBLOCK;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCAL) return VecPlnrVMaintable::TBLPLNRMCALC;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCLC) return VecPlnrVMaintable::TBLPLNRMCALC;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCLI) return VecPlnrVMaintable::TBLPLNRMCALCITEM;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFCTP) return VecPlnrVMaintable::TBLPLNRMCALC;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDEV) return VecPlnrVMaintable::TBLPLNRMDEVICE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDGD) return VecPlnrVMaintable::TBLPLNRMDOMAINGD;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDOM) return VecPlnrVMaintable::TBLPLNRMDOMAIN;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDSN) return VecPlnrVMaintable::TBLPLNRMDESIGN;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDTP) return VecPlnrVMaintable::TBLPLNRMDEVICE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFDVC) return VecPlnrVMaintable::TBLPLNRMDEVICE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFFCE) return VecPlnrVMaintable::TBLPLNRMFACE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFFIL) return VecPlnrVMaintable::TBLPLNRMFILE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFLGD) return VecPlnrVMaintable::TBLPLNRMLINEGUIDE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFLVL) return VecPlnrVMaintable::TBLPLNRMLEVEL;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFLYR) return VecPlnrVMaintable::TBLPLNRMLAYER;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFMAT) return VecPlnrVMaintable::TBLPLNRMMATERIAL;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFPRJ) return VecPlnrVMaintable::TBLPLNRMPROJECT;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFPRS) return VecPlnrVMaintable::TBLPLNRMPERSON;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFRTC) return VecPlnrVMaintable::TBLPLNRMRETICLE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFSES) return VecPlnrVMaintable::TBLPLNRMSESSION;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFSRU) return VecPlnrVMaintable::TBLPLNRMSTRUCTURE;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFSTK) return VecPlnrVMaintable::TBLPLNRMSTACK;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFTPO) return VecPlnrVMaintable::TBLPLNRMTAPEOUT;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFUSG) return VecPlnrVMaintable::TBLPLNRMUSERGROUP;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFUSR) return VecPlnrVMaintable::TBLPLNRMUSER;
	else if (ixPlnrVPreset == VecPlnrVPreset::PREPLNRREFVTX) return VecPlnrVMaintable::TBLPLNRMVERTEX;

	return VecPlnrVMaintable::VOID;
};

bool SessPlnr::hasActive(
			const uint ixPlnrVCard
		) {
	return((ixPlnrVCard == VecPlnrVCard::CRDPLNRDSN) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRDOM) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRDGD) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRDVC) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRSRU) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRSTK) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRLYR) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLC) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLI) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRARR) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRARI) || (ixPlnrVCard == VecPlnrVCard::CRDPLNRRTC));
};

bool SessPlnr::hasGrpown(
			const uint ixPlnrVMaintable
		) {
	return((ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMCALC) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMDESIGN) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMFILE) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMMATERIAL) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMPERSON) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMPROJECT) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMTAPEOUT) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMUSER) || (ixPlnrVMaintable == VecPlnrVMaintable::TBLPLNRMUSERGROUP));
};

void SessPlnr::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\tcreateCrdari" << endl;
			cout << "\tcreateCrdarr" << endl;
			cout << "\tcreateCrdclc" << endl;
			cout << "\tcreateCrdcli" << endl;
			cout << "\tcreateCrdctp" << endl;
			cout << "\tcreateCrddgd" << endl;
			cout << "\tcreateCrddom" << endl;
			cout << "\tcreateCrddsn" << endl;
			cout << "\tcreateCrddtp" << endl;
			cout << "\tcreateCrddvc" << endl;
			cout << "\tcreateCrdfil" << endl;
			cout << "\tcreateCrdlyr" << endl;
			cout << "\tcreateCrdmat" << endl;
			cout << "\tcreateCrdprj" << endl;
			cout << "\tcreateCrdprs" << endl;
			cout << "\tcreateCrdrtc" << endl;
			cout << "\tcreateCrdsru" << endl;
			cout << "\tcreateCrdstk" << endl;
			cout << "\tcreateCrdtpo" << endl;
			cout << "\tcreateCrdusg" << endl;
			cout << "\tcreateCrdusr" << endl;
			cout << "\teraseCrdari" << endl;
			cout << "\teraseCrdarr" << endl;
			cout << "\teraseCrdclc" << endl;
			cout << "\teraseCrdcli" << endl;
			cout << "\teraseCrdctp" << endl;
			cout << "\teraseCrddgd" << endl;
			cout << "\teraseCrddom" << endl;
			cout << "\teraseCrddsn" << endl;
			cout << "\teraseCrddtp" << endl;
			cout << "\teraseCrddvc" << endl;
			cout << "\teraseCrdfil" << endl;
			cout << "\teraseCrdlyr" << endl;
			cout << "\teraseCrdmat" << endl;
			cout << "\teraseCrdprj" << endl;
			cout << "\teraseCrdprs" << endl;
			cout << "\teraseCrdrtc" << endl;
			cout << "\teraseCrdsru" << endl;
			cout << "\teraseCrdstk" << endl;
			cout << "\teraseCrdtpo" << endl;
			cout << "\teraseCrdusg" << endl;
			cout << "\teraseCrdusr" << endl;
		} else if (req->cmd.compare("createCrdari") == 0) {
			req->retain = handleCreateCrdari(dbsplnr);

		} else if (req->cmd.compare("createCrdarr") == 0) {
			req->retain = handleCreateCrdarr(dbsplnr);

		} else if (req->cmd.compare("createCrdclc") == 0) {
			req->retain = handleCreateCrdclc(dbsplnr);

		} else if (req->cmd.compare("createCrdcli") == 0) {
			req->retain = handleCreateCrdcli(dbsplnr);

		} else if (req->cmd.compare("createCrdctp") == 0) {
			req->retain = handleCreateCrdctp(dbsplnr);

		} else if (req->cmd.compare("createCrddgd") == 0) {
			req->retain = handleCreateCrddgd(dbsplnr);

		} else if (req->cmd.compare("createCrddom") == 0) {
			req->retain = handleCreateCrddom(dbsplnr);

		} else if (req->cmd.compare("createCrddsn") == 0) {
			req->retain = handleCreateCrddsn(dbsplnr);

		} else if (req->cmd.compare("createCrddtp") == 0) {
			req->retain = handleCreateCrddtp(dbsplnr);

		} else if (req->cmd.compare("createCrddvc") == 0) {
			req->retain = handleCreateCrddvc(dbsplnr);

		} else if (req->cmd.compare("createCrdfil") == 0) {
			req->retain = handleCreateCrdfil(dbsplnr);

		} else if (req->cmd.compare("createCrdlyr") == 0) {
			req->retain = handleCreateCrdlyr(dbsplnr);

		} else if (req->cmd.compare("createCrdmat") == 0) {
			req->retain = handleCreateCrdmat(dbsplnr);

		} else if (req->cmd.compare("createCrdprj") == 0) {
			req->retain = handleCreateCrdprj(dbsplnr);

		} else if (req->cmd.compare("createCrdprs") == 0) {
			req->retain = handleCreateCrdprs(dbsplnr);

		} else if (req->cmd.compare("createCrdrtc") == 0) {
			req->retain = handleCreateCrdrtc(dbsplnr);

		} else if (req->cmd.compare("createCrdsru") == 0) {
			req->retain = handleCreateCrdsru(dbsplnr);

		} else if (req->cmd.compare("createCrdstk") == 0) {
			req->retain = handleCreateCrdstk(dbsplnr);

		} else if (req->cmd.compare("createCrdtpo") == 0) {
			req->retain = handleCreateCrdtpo(dbsplnr);

		} else if (req->cmd.compare("createCrdusg") == 0) {
			req->retain = handleCreateCrdusg(dbsplnr);

		} else if (req->cmd.compare("createCrdusr") == 0) {
			req->retain = handleCreateCrdusr(dbsplnr);

		} else if (req->cmd.compare("eraseCrdari") == 0) {
			req->retain = handleEraseCrdari(dbsplnr);

		} else if (req->cmd.compare("eraseCrdarr") == 0) {
			req->retain = handleEraseCrdarr(dbsplnr);

		} else if (req->cmd.compare("eraseCrdclc") == 0) {
			req->retain = handleEraseCrdclc(dbsplnr);

		} else if (req->cmd.compare("eraseCrdcli") == 0) {
			req->retain = handleEraseCrdcli(dbsplnr);

		} else if (req->cmd.compare("eraseCrdctp") == 0) {
			req->retain = handleEraseCrdctp(dbsplnr);

		} else if (req->cmd.compare("eraseCrddgd") == 0) {
			req->retain = handleEraseCrddgd(dbsplnr);

		} else if (req->cmd.compare("eraseCrddom") == 0) {
			req->retain = handleEraseCrddom(dbsplnr);

		} else if (req->cmd.compare("eraseCrddsn") == 0) {
			req->retain = handleEraseCrddsn(dbsplnr);

		} else if (req->cmd.compare("eraseCrddtp") == 0) {
			req->retain = handleEraseCrddtp(dbsplnr);

		} else if (req->cmd.compare("eraseCrddvc") == 0) {
			req->retain = handleEraseCrddvc(dbsplnr);

		} else if (req->cmd.compare("eraseCrdfil") == 0) {
			req->retain = handleEraseCrdfil(dbsplnr);

		} else if (req->cmd.compare("eraseCrdlyr") == 0) {
			req->retain = handleEraseCrdlyr(dbsplnr);

		} else if (req->cmd.compare("eraseCrdmat") == 0) {
			req->retain = handleEraseCrdmat(dbsplnr);

		} else if (req->cmd.compare("eraseCrdprj") == 0) {
			req->retain = handleEraseCrdprj(dbsplnr);

		} else if (req->cmd.compare("eraseCrdprs") == 0) {
			req->retain = handleEraseCrdprs(dbsplnr);

		} else if (req->cmd.compare("eraseCrdrtc") == 0) {
			req->retain = handleEraseCrdrtc(dbsplnr);

		} else if (req->cmd.compare("eraseCrdsru") == 0) {
			req->retain = handleEraseCrdsru(dbsplnr);

		} else if (req->cmd.compare("eraseCrdstk") == 0) {
			req->retain = handleEraseCrdstk(dbsplnr);

		} else if (req->cmd.compare("eraseCrdtpo") == 0) {
			req->retain = handleEraseCrdtpo(dbsplnr);

		} else if (req->cmd.compare("eraseCrdusg") == 0) {
			req->retain = handleEraseCrdusg(dbsplnr);

		} else if (req->cmd.compare("eraseCrdusr") == 0) {
			req->retain = handleEraseCrdusr(dbsplnr);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPPLNRINIT) {
			handleDpchAppPlnrInit(dbsplnr, (DpchAppPlnrInit*) (req->dpchapp), &(req->dpcheng));

		};
	};
};

bool SessPlnr::handleCreateCrdari(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrAri* crdari = NULL;

	uint ixPlnrVPreset = evalCrdariActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdari = new CrdPlnrAri(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdaris.push_back(crdari);
		cout << "\tjob reference: " << crdari->jref << endl;
		xchg->jrefCmd = crdari->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdarr(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrArr* crdarr = NULL;

	uint ixPlnrVPreset = evalCrdarrActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdarr = new CrdPlnrArr(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdarrs.push_back(crdarr);
		cout << "\tjob reference: " << crdarr->jref << endl;
		xchg->jrefCmd = crdarr->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdclc(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrClc* crdclc = NULL;

	uint ixPlnrVPreset = evalCrdclcActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdclc = new CrdPlnrClc(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdclcs.push_back(crdclc);
		cout << "\tjob reference: " << crdclc->jref << endl;
		xchg->jrefCmd = crdclc->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdcli(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrCli* crdcli = NULL;

	uint ixPlnrVPreset = evalCrdcliActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdcli = new CrdPlnrCli(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdclis.push_back(crdcli);
		cout << "\tjob reference: " << crdcli->jref << endl;
		xchg->jrefCmd = crdcli->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdctp(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrCtp* crdctp = NULL;

	crdctp = new CrdPlnrCtp(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdctps.push_back(crdctp);
	cout << "\tjob reference: " << crdctp->jref << endl;
	xchg->jrefCmd = crdctp->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrddgd(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrDgd* crddgd = NULL;

	uint ixPlnrVPreset = evalCrddgdActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crddgd = new CrdPlnrDgd(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crddgds.push_back(crddgd);
		cout << "\tjob reference: " << crddgd->jref << endl;
		xchg->jrefCmd = crddgd->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrddom(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrDom* crddom = NULL;

	uint ixPlnrVPreset = evalCrddomActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crddom = new CrdPlnrDom(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crddoms.push_back(crddom);
		cout << "\tjob reference: " << crddom->jref << endl;
		xchg->jrefCmd = crddom->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrddsn(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrDsn* crddsn = NULL;

	uint ixPlnrVPreset = evalCrddsnActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crddsn = new CrdPlnrDsn(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crddsns.push_back(crddsn);
		cout << "\tjob reference: " << crddsn->jref << endl;
		xchg->jrefCmd = crddsn->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrddtp(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrDtp* crddtp = NULL;

	crddtp = new CrdPlnrDtp(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crddtps.push_back(crddtp);
	cout << "\tjob reference: " << crddtp->jref << endl;
	xchg->jrefCmd = crddtp->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrddvc(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrDvc* crddvc = NULL;

	uint ixPlnrVPreset = evalCrddvcActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crddvc = new CrdPlnrDvc(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crddvcs.push_back(crddvc);
		cout << "\tjob reference: " << crddvc->jref << endl;
		xchg->jrefCmd = crddvc->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdfil(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrFil* crdfil = NULL;

	crdfil = new CrdPlnrFil(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdfils.push_back(crdfil);
	cout << "\tjob reference: " << crdfil->jref << endl;
	xchg->jrefCmd = crdfil->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdlyr(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrLyr* crdlyr = NULL;

	uint ixPlnrVPreset = evalCrdlyrActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdlyr = new CrdPlnrLyr(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdlyrs.push_back(crdlyr);
		cout << "\tjob reference: " << crdlyr->jref << endl;
		xchg->jrefCmd = crdlyr->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdmat(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrMat* crdmat = NULL;

	crdmat = new CrdPlnrMat(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdmats.push_back(crdmat);
	cout << "\tjob reference: " << crdmat->jref << endl;
	xchg->jrefCmd = crdmat->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdprj(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrPrj* crdprj = NULL;

	crdprj = new CrdPlnrPrj(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdprjs.push_back(crdprj);
	cout << "\tjob reference: " << crdprj->jref << endl;
	xchg->jrefCmd = crdprj->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdprs(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrPrs* crdprs = NULL;

	crdprs = new CrdPlnrPrs(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdprss.push_back(crdprs);
	cout << "\tjob reference: " << crdprs->jref << endl;
	xchg->jrefCmd = crdprs->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdrtc(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrRtc* crdrtc = NULL;

	uint ixPlnrVPreset = evalCrdrtcActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdrtc = new CrdPlnrRtc(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdrtcs.push_back(crdrtc);
		cout << "\tjob reference: " << crdrtc->jref << endl;
		xchg->jrefCmd = crdrtc->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdsru(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrSru* crdsru = NULL;

	uint ixPlnrVPreset = evalCrdsruActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdsru = new CrdPlnrSru(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdsrus.push_back(crdsru);
		cout << "\tjob reference: " << crdsru->jref << endl;
		xchg->jrefCmd = crdsru->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdstk(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrStk* crdstk = NULL;

	uint ixPlnrVPreset = evalCrdstkActive();

	if (ixPlnrVPreset == 0) {
		cout << "\tcard is not activated!" << endl;
	} else {
		crdstk = new CrdPlnrStk(xchg, dbsplnr, jref, ixPlnrVLocale, 0, ixPlnrVPreset, xchg->getRefPreset(ixPlnrVPreset, jref));
		crdstks.push_back(crdstk);
		cout << "\tjob reference: " << crdstk->jref << endl;
		xchg->jrefCmd = crdstk->jref;
	};

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdtpo(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrTpo* crdtpo = NULL;

	crdtpo = new CrdPlnrTpo(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdtpos.push_back(crdtpo);
	cout << "\tjob reference: " << crdtpo->jref << endl;
	xchg->jrefCmd = crdtpo->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdusg(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrUsg* crdusg = NULL;

	crdusg = new CrdPlnrUsg(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdusgs.push_back(crdusg);
	cout << "\tjob reference: " << crdusg->jref << endl;
	xchg->jrefCmd = crdusg->jref;

	return false;
	return retval;
};

bool SessPlnr::handleCreateCrdusr(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	CrdPlnrUsr* crdusr = NULL;

	crdusr = new CrdPlnrUsr(xchg, dbsplnr, jref, ixPlnrVLocale, 0);
	crdusrs.push_back(crdusr);
	cout << "\tjob reference: " << crdusr->jref << endl;
	xchg->jrefCmd = crdusr->jref;

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdari(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrAri* crdari = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdaris.begin();it!=crdaris.end();) {
		crdari = *it;
		if (crdari->jref == iinput) {
			it = crdaris.erase(it);
			delete crdari;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdarr(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrArr* crdarr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdarrs.begin();it!=crdarrs.end();) {
		crdarr = *it;
		if (crdarr->jref == iinput) {
			it = crdarrs.erase(it);
			delete crdarr;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdclc(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrClc* crdclc = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdclcs.begin();it!=crdclcs.end();) {
		crdclc = *it;
		if (crdclc->jref == iinput) {
			it = crdclcs.erase(it);
			delete crdclc;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdcli(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrCli* crdcli = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdclis.begin();it!=crdclis.end();) {
		crdcli = *it;
		if (crdcli->jref == iinput) {
			it = crdclis.erase(it);
			delete crdcli;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdctp(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrCtp* crdctp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdctps.begin();it!=crdctps.end();) {
		crdctp = *it;
		if (crdctp->jref == iinput) {
			it = crdctps.erase(it);
			delete crdctp;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrddgd(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrDgd* crddgd = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crddgds.begin();it!=crddgds.end();) {
		crddgd = *it;
		if (crddgd->jref == iinput) {
			it = crddgds.erase(it);
			delete crddgd;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrddom(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrDom* crddom = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crddoms.begin();it!=crddoms.end();) {
		crddom = *it;
		if (crddom->jref == iinput) {
			it = crddoms.erase(it);
			delete crddom;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrddsn(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrDsn* crddsn = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crddsns.begin();it!=crddsns.end();) {
		crddsn = *it;
		if (crddsn->jref == iinput) {
			it = crddsns.erase(it);
			delete crddsn;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrddtp(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrDtp* crddtp = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crddtps.begin();it!=crddtps.end();) {
		crddtp = *it;
		if (crddtp->jref == iinput) {
			it = crddtps.erase(it);
			delete crddtp;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrddvc(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrDvc* crddvc = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crddvcs.begin();it!=crddvcs.end();) {
		crddvc = *it;
		if (crddvc->jref == iinput) {
			it = crddvcs.erase(it);
			delete crddvc;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdfil(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrFil* crdfil = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdfils.begin();it!=crdfils.end();) {
		crdfil = *it;
		if (crdfil->jref == iinput) {
			it = crdfils.erase(it);
			delete crdfil;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdlyr(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrLyr* crdlyr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdlyrs.begin();it!=crdlyrs.end();) {
		crdlyr = *it;
		if (crdlyr->jref == iinput) {
			it = crdlyrs.erase(it);
			delete crdlyr;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdmat(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrMat* crdmat = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdmats.begin();it!=crdmats.end();) {
		crdmat = *it;
		if (crdmat->jref == iinput) {
			it = crdmats.erase(it);
			delete crdmat;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdprj(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrPrj* crdprj = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdprjs.begin();it!=crdprjs.end();) {
		crdprj = *it;
		if (crdprj->jref == iinput) {
			it = crdprjs.erase(it);
			delete crdprj;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdprs(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrPrs* crdprs = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdprss.begin();it!=crdprss.end();) {
		crdprs = *it;
		if (crdprs->jref == iinput) {
			it = crdprss.erase(it);
			delete crdprs;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdrtc(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrRtc* crdrtc = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdrtcs.begin();it!=crdrtcs.end();) {
		crdrtc = *it;
		if (crdrtc->jref == iinput) {
			it = crdrtcs.erase(it);
			delete crdrtc;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdsru(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrSru* crdsru = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdsrus.begin();it!=crdsrus.end();) {
		crdsru = *it;
		if (crdsru->jref == iinput) {
			it = crdsrus.erase(it);
			delete crdsru;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdstk(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrStk* crdstk = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdstks.begin();it!=crdstks.end();) {
		crdstk = *it;
		if (crdstk->jref == iinput) {
			it = crdstks.erase(it);
			delete crdstk;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdtpo(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrTpo* crdtpo = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdtpos.begin();it!=crdtpos.end();) {
		crdtpo = *it;
		if (crdtpo->jref == iinput) {
			it = crdtpos.erase(it);
			delete crdtpo;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdusg(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrUsg* crdusg = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdusgs.begin();it!=crdusgs.end();) {
		crdusg = *it;
		if (crdusg->jref == iinput) {
			it = crdusgs.erase(it);
			delete crdusg;
			break;
		} else it++;
	};

	return false;
	return retval;
};

bool SessPlnr::handleEraseCrdusr(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	CrdPlnrUsr* crdusr = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=crdusrs.begin();it!=crdusrs.end();) {
		crdusr = *it;
		if (crdusr->jref == iinput) {
			it = crdusrs.erase(it);
			delete crdusr;
			break;
		} else it++;
	};

	return false;
	return retval;
};

void SessPlnr::handleDpchAppPlnrInit(
			DbsPlnr* dbsplnr
			, DpchAppPlnrInit* dpchappplnrinit
			, DpchEngPlnr** dpcheng
		) {
	*dpcheng = new DpchEngData(jref, &statshr, {DpchEngData::ALL});
};

void SessPlnr::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRACCESS) {
		call->abort = handleCallPlnrAccess(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref, call->argRet.ix);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCRDACTIVE) {
		call->abort = handleCallPlnrCrdActive(dbsplnr, call->jref, call->argInv.ix, call->argRet.ix);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCRDCLOSE) {
		call->abort = handleCallPlnrCrdClose(dbsplnr, call->jref, call->argInv.ix);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRCRDOPEN) {
		call->abort = handleCallPlnrCrdOpen(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval, call->argRet.ref);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRLOG) {
		call->abort = handleCallPlnrLog(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref, call->argInv.sref, call->argInv.intval);
	} else if (call->ixVCall == VecPlnrVCall::CALLPLNRREFPRESET) {
		call->abort = handleCallPlnrRefPreSet(dbsplnr, call->jref, call->argInv.ix, call->argInv.ref);
	};
};

bool SessPlnr::handleCallPlnrAccess(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkAccess(dbsplnr, ixInv, refInv);
	return retval;
};

bool SessPlnr::handleCallPlnrCrdActive(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, uint& ixRet
		) {
	bool retval = false;
	ixRet = checkCrdActive(ixInv);
	return retval;
};

bool SessPlnr::handleCallPlnrCrdClose(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
		) {
	bool retval = false;
	ubigint jrefNotif = xchg->getRefPreset(VecPlnrVPreset::PREPLNRJREFNOTIFY, jref);
	if (jrefNotif == jrefTrig) xchg->removePreset(VecPlnrVPreset::PREPLNRJREFNOTIFY, jref);

	if (ixInv == VecPlnrVCard::CRDPLNRNAV) {
		PlnrMSession* ses = NULL;

		time_t rawtime;

		if (crdnav) {
			delete crdnav;
			crdnav = NULL;
		};

		// update session with stop time
		time(&rawtime);

		dbsplnr->tblplnrmsession->loadRecByRef(xchg->getRefPreset(VecPlnrVPreset::PREPLNRSESS, jref), &ses);
		ses->stop = rawtime;
		dbsplnr->tblplnrmsession->updateRec(ses);

		delete ses;

		// notify root
		xchg->triggerCall(dbsplnr, VecPlnrVCall::CALLPLNRLOGOUT, jref);
	} else if (ixInv == VecPlnrVCard::CRDPLNRUSG) {
		CrdPlnrUsg* crdusg = NULL;

		for (auto it=crdusgs.begin();it!=crdusgs.end();) {
			crdusg = *it;
			if (crdusg->jref == jrefTrig) {
				it = crdusgs.erase(it);
				delete crdusg;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRUSR) {
		CrdPlnrUsr* crdusr = NULL;

		for (auto it=crdusrs.begin();it!=crdusrs.end();) {
			crdusr = *it;
			if (crdusr->jref == jrefTrig) {
				it = crdusrs.erase(it);
				delete crdusr;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRPRS) {
		CrdPlnrPrs* crdprs = NULL;

		for (auto it=crdprss.begin();it!=crdprss.end();) {
			crdprs = *it;
			if (crdprs->jref == jrefTrig) {
				it = crdprss.erase(it);
				delete crdprs;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRFIL) {
		CrdPlnrFil* crdfil = NULL;

		for (auto it=crdfils.begin();it!=crdfils.end();) {
			crdfil = *it;
			if (crdfil->jref == jrefTrig) {
				it = crdfils.erase(it);
				delete crdfil;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRDTP) {
		CrdPlnrDtp* crddtp = NULL;

		for (auto it=crddtps.begin();it!=crddtps.end();) {
			crddtp = *it;
			if (crddtp->jref == jrefTrig) {
				it = crddtps.erase(it);
				delete crddtp;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRCTP) {
		CrdPlnrCtp* crdctp = NULL;

		for (auto it=crdctps.begin();it!=crdctps.end();) {
			crdctp = *it;
			if (crdctp->jref == jrefTrig) {
				it = crdctps.erase(it);
				delete crdctp;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRMAT) {
		CrdPlnrMat* crdmat = NULL;

		for (auto it=crdmats.begin();it!=crdmats.end();) {
			crdmat = *it;
			if (crdmat->jref == jrefTrig) {
				it = crdmats.erase(it);
				delete crdmat;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRPRJ) {
		CrdPlnrPrj* crdprj = NULL;

		for (auto it=crdprjs.begin();it!=crdprjs.end();) {
			crdprj = *it;
			if (crdprj->jref == jrefTrig) {
				it = crdprjs.erase(it);
				delete crdprj;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRDSN) {
		CrdPlnrDsn* crddsn = NULL;

		for (auto it=crddsns.begin();it!=crddsns.end();) {
			crddsn = *it;
			if (crddsn->jref == jrefTrig) {
				it = crddsns.erase(it);
				delete crddsn;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRDOM) {
		CrdPlnrDom* crddom = NULL;

		for (auto it=crddoms.begin();it!=crddoms.end();) {
			crddom = *it;
			if (crddom->jref == jrefTrig) {
				it = crddoms.erase(it);
				delete crddom;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRDGD) {
		CrdPlnrDgd* crddgd = NULL;

		for (auto it=crddgds.begin();it!=crddgds.end();) {
			crddgd = *it;
			if (crddgd->jref == jrefTrig) {
				it = crddgds.erase(it);
				delete crddgd;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRDVC) {
		CrdPlnrDvc* crddvc = NULL;

		for (auto it=crddvcs.begin();it!=crddvcs.end();) {
			crddvc = *it;
			if (crddvc->jref == jrefTrig) {
				it = crddvcs.erase(it);
				delete crddvc;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRSRU) {
		CrdPlnrSru* crdsru = NULL;

		for (auto it=crdsrus.begin();it!=crdsrus.end();) {
			crdsru = *it;
			if (crdsru->jref == jrefTrig) {
				it = crdsrus.erase(it);
				delete crdsru;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRSTK) {
		CrdPlnrStk* crdstk = NULL;

		for (auto it=crdstks.begin();it!=crdstks.end();) {
			crdstk = *it;
			if (crdstk->jref == jrefTrig) {
				it = crdstks.erase(it);
				delete crdstk;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRLYR) {
		CrdPlnrLyr* crdlyr = NULL;

		for (auto it=crdlyrs.begin();it!=crdlyrs.end();) {
			crdlyr = *it;
			if (crdlyr->jref == jrefTrig) {
				it = crdlyrs.erase(it);
				delete crdlyr;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRCLC) {
		CrdPlnrClc* crdclc = NULL;

		for (auto it=crdclcs.begin();it!=crdclcs.end();) {
			crdclc = *it;
			if (crdclc->jref == jrefTrig) {
				it = crdclcs.erase(it);
				delete crdclc;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRCLI) {
		CrdPlnrCli* crdcli = NULL;

		for (auto it=crdclis.begin();it!=crdclis.end();) {
			crdcli = *it;
			if (crdcli->jref == jrefTrig) {
				it = crdclis.erase(it);
				delete crdcli;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRTPO) {
		CrdPlnrTpo* crdtpo = NULL;

		for (auto it=crdtpos.begin();it!=crdtpos.end();) {
			crdtpo = *it;
			if (crdtpo->jref == jrefTrig) {
				it = crdtpos.erase(it);
				delete crdtpo;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRARR) {
		CrdPlnrArr* crdarr = NULL;

		for (auto it=crdarrs.begin();it!=crdarrs.end();) {
			crdarr = *it;
			if (crdarr->jref == jrefTrig) {
				it = crdarrs.erase(it);
				delete crdarr;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRARI) {
		CrdPlnrAri* crdari = NULL;

		for (auto it=crdaris.begin();it!=crdaris.end();) {
			crdari = *it;
			if (crdari->jref == jrefTrig) {
				it = crdaris.erase(it);
				delete crdari;
				break;
			} else it++;
		};
	} else if (ixInv == VecPlnrVCard::CRDPLNRRTC) {
		CrdPlnrRtc* crdrtc = NULL;

		for (auto it=crdrtcs.begin();it!=crdrtcs.end();) {
			crdrtc = *it;
			if (crdrtc->jref == jrefTrig) {
				it = crdrtcs.erase(it);
				delete crdrtc;
				break;
			} else it++;
		};
	};
	return retval;
};

bool SessPlnr::handleCallPlnrCrdOpen(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
			, ubigint& refRet
		) {
	bool retval = false;
	bool denied = false;

	uint ixPlnrVCard = VecPlnrVCard::getIx(srefInv);

	ubigint ref = (ubigint) intvalInv;
	if (intvalInv == -1) {
		ref = 0;
		ref--;
	};

	uint ixPlnrVPreset;
	ubigint preUref;

	uint ixPlnrWUiaccess;
	uint ixPlnrVAccess;

	if (hasActive(ixPlnrVCard)) {
		if (ixInv == 0) {
			ixPlnrVPreset = checkCrdActive(ixPlnrVCard);
			if (ixPlnrVPreset == 0) {
				denied = true;
			} else {
				preUref = xchg->getRefPreset(ixPlnrVPreset, jref);
			};

		} else {
			ixPlnrVPreset = ixInv;
			preUref = refInv;
		};
	};

	if (!denied) {
		ixPlnrWUiaccess = checkUiaccess(ixPlnrVCard);
		denied = (ixPlnrWUiaccess == 0);
	};

	if (!denied) {
		if (intvalInv == -1) {
			denied = (((ixPlnrWUiaccess & VecPlnrWUiaccess::EDIT) == 0) || ((ixPlnrWUiaccess & VecPlnrWUiaccess::EXEC) == 0));
		} else if (intvalInv > 0) {
			ixPlnrVAccess = checkAccess(dbsplnr, ixPlnrVCard, intvalInv);
			denied = (ixPlnrVAccess == VecPlnrVAccess::NONE);
		};
	};

	if (denied) {
		refRet = 0;

	} else {
		if (ixPlnrVCard == VecPlnrVCard::CRDPLNRNAV) {
		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRUSG) {
			CrdPlnrUsg* crdusg = NULL;

			crdusg = new CrdPlnrUsg(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdusgs.push_back(crdusg);

			refRet = crdusg->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRUSR) {
			CrdPlnrUsr* crdusr = NULL;

			crdusr = new CrdPlnrUsr(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdusrs.push_back(crdusr);

			refRet = crdusr->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRPRS) {
			CrdPlnrPrs* crdprs = NULL;

			crdprs = new CrdPlnrPrs(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdprss.push_back(crdprs);

			refRet = crdprs->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRFIL) {
			CrdPlnrFil* crdfil = NULL;

			crdfil = new CrdPlnrFil(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdfils.push_back(crdfil);

			refRet = crdfil->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDTP) {
			CrdPlnrDtp* crddtp = NULL;

			crddtp = new CrdPlnrDtp(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crddtps.push_back(crddtp);

			refRet = crddtp->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCTP) {
			CrdPlnrCtp* crdctp = NULL;

			crdctp = new CrdPlnrCtp(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdctps.push_back(crdctp);

			refRet = crdctp->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRMAT) {
			CrdPlnrMat* crdmat = NULL;

			crdmat = new CrdPlnrMat(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdmats.push_back(crdmat);

			refRet = crdmat->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRPRJ) {
			CrdPlnrPrj* crdprj = NULL;

			crdprj = new CrdPlnrPrj(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdprjs.push_back(crdprj);

			refRet = crdprj->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDSN) {
			CrdPlnrDsn* crddsn = NULL;

			crddsn = new CrdPlnrDsn(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crddsns.push_back(crddsn);

			refRet = crddsn->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDOM) {
			CrdPlnrDom* crddom = NULL;

			crddom = new CrdPlnrDom(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crddoms.push_back(crddom);

			refRet = crddom->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDGD) {
			CrdPlnrDgd* crddgd = NULL;

			crddgd = new CrdPlnrDgd(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crddgds.push_back(crddgd);

			refRet = crddgd->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRDVC) {
			CrdPlnrDvc* crddvc = NULL;

			crddvc = new CrdPlnrDvc(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crddvcs.push_back(crddvc);

			refRet = crddvc->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSRU) {
			CrdPlnrSru* crdsru = NULL;

			crdsru = new CrdPlnrSru(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdsrus.push_back(crdsru);

			refRet = crdsru->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRSTK) {
			CrdPlnrStk* crdstk = NULL;

			crdstk = new CrdPlnrStk(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdstks.push_back(crdstk);

			refRet = crdstk->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRLYR) {
			CrdPlnrLyr* crdlyr = NULL;

			crdlyr = new CrdPlnrLyr(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdlyrs.push_back(crdlyr);

			refRet = crdlyr->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLC) {
			CrdPlnrClc* crdclc = NULL;

			crdclc = new CrdPlnrClc(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdclcs.push_back(crdclc);

			refRet = crdclc->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRCLI) {
			CrdPlnrCli* crdcli = NULL;

			crdcli = new CrdPlnrCli(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdclis.push_back(crdcli);

			refRet = crdcli->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRTPO) {
			CrdPlnrTpo* crdtpo = NULL;

			crdtpo = new CrdPlnrTpo(xchg, dbsplnr, jref, ixPlnrVLocale, ref);
			crdtpos.push_back(crdtpo);

			refRet = crdtpo->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARR) {
			CrdPlnrArr* crdarr = NULL;

			crdarr = new CrdPlnrArr(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdarrs.push_back(crdarr);

			refRet = crdarr->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRARI) {
			CrdPlnrAri* crdari = NULL;

			crdari = new CrdPlnrAri(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdaris.push_back(crdari);

			refRet = crdari->jref;

		} else if (ixPlnrVCard == VecPlnrVCard::CRDPLNRRTC) {
			CrdPlnrRtc* crdrtc = NULL;

			crdrtc = new CrdPlnrRtc(xchg, dbsplnr, jref, ixPlnrVLocale, ref, ixPlnrVPreset, preUref);
			crdrtcs.push_back(crdrtc);

			refRet = crdrtc->jref;

		};
	};

	return retval;
};

bool SessPlnr::handleCallPlnrLog(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
			, const string& srefInv
			, const int intvalInv
		) {
	bool retval = false;
	logAccess(dbsplnr, ixInv, refInv, VecPlnrVCard::getIx(srefInv), intvalInv);
	return retval;
};

bool SessPlnr::handleCallPlnrRefPreSet(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;
	if (ixInv == VecPlnrVPreset::PREPLNRJREFNOTIFY) {
		ubigint jrefNotify_old = xchg->getRefPreset(VecPlnrVPreset::PREPLNRJREFNOTIFY, jref);

		if (refInv != jrefNotify_old) {
			if (jrefNotify_old != 0) xchg->submitDpch(new DpchEngPlnrSuspend(jrefNotify_old));

			if (refInv == 0) xchg->removePreset(ixInv, jref);
			else xchg->addRefPreset(ixInv, jref, refInv);
		};

	} else if ((ixInv == VecPlnrVPreset::PREPLNRREFDSN) || (ixInv == VecPlnrVPreset::PREPLNRREFPRJ)) {
		if (refInv == 0) xchg->removePreset(ixInv, jref);
		else xchg->addRefPreset(ixInv, jref, refInv);

		if (crdnav) crdnav->updatePreset(dbsplnr, ixInv, jrefTrig, true);
	};
	return retval;
};


