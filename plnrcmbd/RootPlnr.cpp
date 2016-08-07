/**
  * \file RootPlnr.cpp
  * job handler for job RootPlnr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "RootPlnr.h"

// IP blksInclude --- BEGIN
#include "RootPlnr_blks.cpp"
// IP blksInclude --- END

/******************************************************************************
 class RootPlnr
 ******************************************************************************/

RootPlnr::RootPlnr(
			XchgPlnr* xchg
		) : JobPlnr(xchg, VecPlnrVJob::ROOTPLNR, 0, ixPlnrVLocale) {

// IP constructor.addJob --- BEGIN
	jref = xchg->addJob(this);
// IP constructor.addJob --- END

// IP constructor.cust1 --- INSERT

	// root job receives commands
	xchg->jrefCmd = jref;

	// log
	xchg->appendToLogfile("root job created");

// IP constructor.cust2 --- INSERT

// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecPlnrVCall::CALLPLNRLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, Arg(), Clstn::VecVJactype::LOCK);

// IP constructor.cust3 --- INSERT

// IP constructor.spec3 --- INSERT
};

RootPlnr::~RootPlnr() {
	// log
	xchg->appendToLogfile("root job deleted");

// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT
void RootPlnr::clearAll(
			DbsPlnr* dbsplnr
		) {
	PlnrMUsergroup* usg = NULL;
	PlnrRMUserMUsergroup* uru = NULL;
	PlnrMUser* usr = NULL;
	ubigint refUjs = 0;
	PlnrMPerson* prs = NULL;
	ubigint refPjl = 0;

	time_t timeval;
	uint dateval;

	string s;

	// empty out tables
	dbsplnr->executeQuery("DELETE FROM TblPlnrAccRMUserUniversal");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMArrayEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMCalcEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMCalcPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMDevicePar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMMaterialPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMPersonDetail");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMUserAccess");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAMUsergroupAccess");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAVControlPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAVKeylistKey");
	dbsplnr->executeQuery("DELETE FROM TblPlnrAVValuelistVal");
	if (dbsplnr->ixDbsVDbstype == VecDbsVDbstype::MY) dbsplnr->executeQuery("DELETE FROM TblPlnrCFile");
	else if (dbsplnr->ixDbsVDbstype == VecDbsVDbstype::PG) dbsplnr->executeQuery("ALTER SEQUENCE TblPlnrCFile RESTART WITH 1");
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevOMDeviceMArcguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevOMDeviceMLineguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevOMDeviceMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevORMArcguideMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrDevORMLineguideMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrHistRMUserUniversal");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJAVKeylistKey");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMArcguideR");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMDeviceModtype");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMDomain");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMDomaingd");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMLayer");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMLayerMaterial");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMLevelZ");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMPersonLastname");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMProjectState");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMStackModtype");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMStackN");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMTapeoutState");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMUserState");
	dbsplnr->executeQuery("DELETE FROM TblPlnrJMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrLRMArcguideMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrLRMLineguideMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMArcguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMArray");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMArrayitem");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMBlock");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMCalcitem");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMDesign");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMDevice");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMDomain");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMDomaingd");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMFace");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMLayer");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMLevel");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMLineguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMMaterial");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMPerson");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMProject");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMReticle");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMSession");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMStack");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMTapeout");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMUser");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMUsergroup");
	dbsplnr->executeQuery("DELETE FROM TblPlnrMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrOMStructureMFace");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMCalcMDomain");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMCalcMFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMFaceMVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMLayerMStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMLevelMLevel");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMLineguideMLineguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMProjectMTapeout");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMStackMStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMUsergroupUniversal");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMUserMUsergroup");
	dbsplnr->executeQuery("DELETE FROM TblPlnrRMVertexMVertex");

	clearQtb(dbsplnr);

	// generate a temporary user such that a session can be generated
	dbsplnr->tblplnrmusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbsplnr->tblplnramusergroupaccess->insertNewRec(NULL, usg->ref, VecPlnrVCard::CRDPLNRNAV, VecPlnrWUiaccess::EDIT + VecPlnrWUiaccess::EXEC + VecPlnrWUiaccess::VIEW);
	dbsplnr->tblplnrrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecPlnrVUserlevel::GADM);
	dbsplnr->tblplnrmuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecPlnrVMUserState::DUE, VecPlnrVLocale::ENUS, VecPlnrVUserlevel::GADM, "asdf1234");
	refUjs = dbsplnr->tblplnrjmuserstate->insertNewRec(NULL, usr->ref, 0, VecPlnrVMUserState::DUE);

	time(&timeval);
	dateval = 1 + (timeval - (timeval % (3600*24))) / (3600*24);

	dbsplnr->tblplnrjmuserstate->insertNewRec(NULL, usr->ref, dateval, VecPlnrVMUserState::EXP);
	dbsplnr->tblplnrmperson->insertNewRec(&prs, usg->ref, usr->ref, VecPlnrWMPersonDerivate::USR, VecPlnrVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	refPjl = dbsplnr->tblplnrjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbsplnr->tblplnrmusergroup->updateRec(usg);

	uru->refPlnrMUser = usr->ref;
	dbsplnr->tblplnrrmusermusergroup->updateRec(uru);

	usr->refPlnrMPerson = prs->ref;
	usr->refJState = refUjs;
	dbsplnr->tblplnrmuser->updateRec(usr);

	prs->refJLastname = refPjl;
	dbsplnr->tblplnrmperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::date(dateval) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootPlnr::clearQtb(
			DbsPlnr* dbsplnr
		) {
	dbsplnr->executeQuery("DELETE FROM TblPlnrQAriAMArrayEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQAriList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQArr1NArrayitem");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQArrAEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQArrHk1NReticle");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQArrKEnvKey");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQArrList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClc1NMaterial");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcAEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcAPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcCal1NCalcitem");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcMNDomain");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcMNFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcRef1NFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQClcSup1NCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCliAAMCalcEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCliAAMCalcPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCliList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCliRef1NFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpAEnv");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpAPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpKCalcdomprp");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpKCalcvar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpKEnvKey");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpKParCat");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpKParProp");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpRef1NFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpSup1NCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQCtpTpl1NCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDgdList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDomList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDomMNCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsn1NBlock");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsn1NReticle");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnDrv1NDesign");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnDsn1NDevice");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnDsn1NDomain");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnDsn1NDomaingd");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnDsn1NStack");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnHk1NArcguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnHk1NLayer");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnHk1NLevel");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnHk1NLineguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnHk1NStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnHk1NVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDsnMod1NDesign");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDtpAPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDtpHk1NStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDtpKParKey");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDtpList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDtpSup1NDevice");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDtpTpl1NDevice");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcAPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcHk1NArcguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcHk1NLineguide");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcHk1NStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcHk1NVertex");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQDvcSup1NDevice");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQFilList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQFilMNCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQLyr1NBlock");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQLyr1NReticle");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQLyrList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQLyrMNStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQMat1NLayer");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQMatAPar");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQMatList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQMatMod1NMaterial");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQMatRef1NFile");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPreselect");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPrj1NCalc");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPrj1NDesign");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPrjList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPrjMNTapeout");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPrsADetail");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQPrsList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQRtcList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQSelect");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQSru1NBlock");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQSruList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQSruMNLayer");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQSruMNStack");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQSruSru1NFace");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQStkHk1NLayer");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQStkHk1NLevel");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQStkList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQStkMNStructure");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQTpo1NArray");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQTpoHk1NReticle");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQTpoList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQTpoMNProject");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsgAAccess");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsgList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsgMNUser");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsr1NSession");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsrAAccess");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsrList");
	dbsplnr->executeQuery("DELETE FROM TblPlnrQUsrMNUsergroup");
};

void RootPlnr::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd.compare("cmdset") == 0) {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
		} else if (req->cmd.compare("clearAll") == 0) {
			req->retain = handleClearAll(dbsplnr);

		} else if (req->cmd.compare("createSess") == 0) {
			req->retain = handleCreateSess(dbsplnr);

		} else if (req->cmd.compare("eraseSess") == 0) {
			req->retain = handleEraseSess(dbsplnr);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqPlnr::VecVBasetype::REGULAR) {
		if (req->dpchapp->ixPlnrVDpch == VecPlnrVDpch::DPCHAPPROOTPLNRLOGIN) {
			handleDpchAppLogin(dbsplnr, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};
	};
};

bool RootPlnr::handleClearAll(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	clearAll(dbsplnr);
	return retval;
};

bool RootPlnr::handleCreateSess(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	SessPlnr* sess = NULL;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (dbsplnr->tblplnrmuser->loadRefBySrfPwd(input, input2, refUsr)) {
		sess = new SessPlnr(xchg, dbsplnr, jref, refUsr, "127.0.0.1");
		sesss.push_back(sess);

		cout << "\tjob reference: " << sess->jref << endl;
		xchg->jrefCmd = sess->jref;

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return false;
	return retval;
};

bool RootPlnr::handleEraseSess(
			DbsPlnr* dbsplnr
		) {
	bool retval = false;
	string input;
	uint iinput;

	SessPlnr* sess = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it=sesss.begin();it!=sesss.end();) {
		sess = *it;
		if (sess->jref == iinput) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};

	return false;
	return retval;
};

void RootPlnr::handleDpchAppLogin(
			DbsPlnr* dbsplnr
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngPlnr** dpcheng
		) {
	ubigint refUsr;

	SessPlnr* sess = NULL;

	// verify password and create a session
	if (dbsplnr->tblplnrmuser->loadRefBySrfPwd(dpchapplogin->username, dpchapplogin->password, refUsr)) {
		sess = new SessPlnr(xchg, dbsplnr, jref, refUsr, ip);
		sesss.push_back(sess);

		xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngPlnrConfirm(true, sess->jref, "");

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngPlnrConfirm(false, 0, "");
	};
};

void RootPlnr::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
	if (call->ixVCall == VecPlnrVCall::CALLPLNRLOGOUT) {
		call->abort = handleCallPlnrLogout(dbsplnr, call->jref);
	};
};

bool RootPlnr::handleCallPlnrLogout(
			DbsPlnr* dbsplnr
			, const ubigint jrefTrig
		) {
	bool retval = false;
	SessPlnr* sess = NULL;

	for (auto it=sesss.begin();it!=sesss.end();) {
		sess = *it;
		if (sess->jref == jrefTrig) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};
	return retval;
};


