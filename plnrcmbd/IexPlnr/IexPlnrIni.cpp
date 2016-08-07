/**
  * \file IexPlnrIni.cpp
  * import/export handler for database DbsPlnr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnrd.h>
#endif

#include "IexPlnrIni.h"

#include "IexPlnrIni_blks.cpp"

/******************************************************************************
 class IexPlnrIni
 ******************************************************************************/

IexPlnrIni::IexPlnrIni(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, const ubigint jrefSup
			, const uint ixPlnrVLocale
		) : JobPlnr(xchg, VecPlnrVJob::IEXPLNRINI, jrefSup, ixPlnrVLocale) {

	jref = xchg->addJob(this);
};

IexPlnrIni::~IexPlnrIni() {
	// remove job reference from job list
	if (jref != 0) xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void IexPlnrIni::reset() {
	imeiavcontrolpar.clear();
	imeiavkeylistkey1.clear();
	imeiavvaluelistval.clear();
	imeimcalc.clear();
	imeimdevice.clear();
	imeimfile.clear();
	imeimmaterial.clear();
	imeimusergroup.clear();

	lineno = 0;
	impcnt = 0;
};

void IexPlnrIni::import(
			DbsPlnr* dbsplnr
		) {
	ImeitemIAVControlPar* cntApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCalc* cal = NULL;
	ImeitemIMDevice* dev = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMMaterial* mat = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMDevicePar* devApar = NULL;
	ImeitemIAMMaterialPar* matApar = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemIJAVKeylistKey1* klkJkey1 = NULL;
	ImeitemIMStructure* sru = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIJAVKeylistKey2* klkJkey2 = NULL;
	ImeitemIJAVKeylistKey3* klkJkey3 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

// IP import --- IBEGIN
	PlnrRMUserMUsergroup uru;
	ImeitemIMMaterial* mat2 = NULL;
	ImeitemIMDevice* dev2 = NULL;
// IP import --- IEND

// IP import.traverse --- RBEGIN
	// -- ImeIAVKeylistKey1
	for (unsigned int ix0=0;ix0<imeiavkeylistkey1.nodes.size();ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];

		//klsAkey1->klsIxPlnrVKeylist: IXSREF
		klsAkey1->klsNum = (ix0 + 1);// TBD
		klsAkey1->x1IxPlnrVMaintable = VecPlnrVMaintable::VOID;
		klsAkey1->Fixed = true;
		//klsAkey1->sref: TBL
		//klsAkey1->Avail: TBL
		//klsAkey1->Implied: TBL
		//klsAkey1->refJ: SUB

		dbsplnr->tblplnravkeylistkey->insertRec(klsAkey1);
		impcnt++;

		for (unsigned int ix1=0;ix1<klsAkey1->imeijavkeylistkey1.nodes.size();ix1++) {
			klkJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

			klkJkey1->refPlnrAVKeylistKey = klsAkey1->ref;
			//klkJkey1->x1IxPlnrVLocale: IXSREF
			//klkJkey1->Title: TBL
			//klkJkey1->Comment: TBL

			dbsplnr->tblplnrjavkeylistkey->insertRec(klkJkey1);
			impcnt++;
		};

		if (klsAkey1->imeijavkeylistkey1.nodes.size() > 0) {
			klkJkey1 = klsAkey1->imeijavkeylistkey1.nodes[0];

			klsAkey1->refJ = klkJkey1->ref;
			klsAkey1->Title = klkJkey1->Title;
			klsAkey1->Comment = klkJkey1->Comment;
			
			dbsplnr->tblplnravkeylistkey->updateRec(klsAkey1);
		};
	};
	
	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		//vlsAval->vlsIxPlnrVValuelist: IXSREF
		vlsAval->vlsNum = (ix0 + 1);// TBD
		//vlsAval->x1IxPlnrVLocale: IXSREF
		//vlsAval->Val: TBL
		
		dbsplnr->tblplnravvaluelistval->insertRec(vlsAval);
		impcnt++;
	};

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		cntApar = imeiavcontrolpar.nodes[ix0];

		//cntApar->ixPlnrVControl: IXSREF
		//cntApar->Par: TBL
		//cntApar->Val: TBL

		dbsplnr->tblplnravcontrolpar->insertRec(cntApar);
		impcnt++;
	};

	// -- ImeIMFile
	for (unsigned int ix0=0;ix0<imeimfile.nodes.size();ix0++) {
		fil = imeimfile.nodes[ix0];

		//fil->ref: IDIREF
		fil->refIxVTbl = VecPlnrVMFileRefTbl::VOID;
		//fil->osrefKContent: TBL
		//fil->Archived = PP;
		//fil->Filename: TBL
		//fil->Archivename = PP;
		//fil->srefKMimetype: TBL
		//fil->Size = PP;
		//fil->Comment: TBL

		dbsplnr->tblplnrmfile->insertRec(fil);
		impcnt++;
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		//usg->grp = TBD;
		//usg->own = TBD;
		//usg->sref: TBL
		//usg->Comment: TBL

		dbsplnr->tblplnrmusergroup->insertRec(usg);
		impcnt++;

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			usgAacc->refPlnrMUsergroup = usg->ref;
			//usgAacc->x1IxPlnrVCard: IXSREF
			//usgAacc->ixPlnrWUiaccess: IXSREF

			dbsplnr->tblplnramusergroupaccess->insertRec(usgAacc);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			//usr->grp = TBD;
			//usr->own = TBD;
			//usr->refRUsergroup: IMPPP
			usr->refPlnrMUsergroup = usg->ref;
			//usr->refPlnrMPerson: IMPPP
			//usr->sref: TBL
			//usr->refJState: SUB
			//usr->ixPlnrVLocale: IXSREF
			//usr->ixPlnrVUserlevel: IXSREF
			//usr->Password: TBL

			dbsplnr->tblplnrmuser->insertRec(usr);
			impcnt++;

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				usrJste->refPlnrMUser = usr->ref;
				//usrJste->ixVState: IXSREF

				dbsplnr->tblplnrjmuserstate->insertRec(usrJste);
				impcnt++;
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				//prs->grp = TBD;
				//prs->own = TBD;
				prs->ixWDerivate = VecPlnrWMPersonDerivate::USR;
				//prs->ixVSex: IXSREF
				//prs->Title: TBL
				//prs->Firstname: TBL
				//prs->refJLastname: SUB

				dbsplnr->tblplnrmperson->insertRec(prs);
				impcnt++;

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					prsJlnm->refPlnrMPerson = prs->ref;
					//prsJlnm->Lastname: TBL

					dbsplnr->tblplnrjmpersonlastname->insertRec(prsJlnm);
					impcnt++;
				};

				if (prs->imeijmpersonlastname.nodes.size() > 0) {
					prsJlnm = prs->imeijmpersonlastname.nodes[0];

					prs->refJLastname = prsJlnm->ref;
					prs->Lastname = prsJlnm->Lastname;
					
					dbsplnr->tblplnrmperson->updateRec(prs);
				};
			};

			uru.refPlnrMUser = usr->ref;
			uru.refPlnrMUsergroup = usg->ref;
			uru.ixPlnrVUserlevel = usr->ixPlnrVUserlevel;

			dbsplnr->tblplnrrmusermusergroup->insertRec(&uru);
			impcnt++;

			usr->refRUsergroup = uru.ref;
			dbsplnr->tblplnrmuser->updateRec(usr);

			if (usr->imeijmuserstate.nodes.size() > 0) {
				usrJste = usr->imeijmuserstate.nodes[0];

				usr->refJState = usrJste->ref;
				usr->ixVState = usrJste->ixVState;
			
				dbsplnr->tblplnrmuser->updateRec(usr);
			};

			if (usr->imeimperson.nodes.size() > 0) {
				prs = usr->imeimperson.nodes[0];

				usr->refPlnrMPerson = prs->ref;

				dbsplnr->tblplnrmuser->updateRec(usr);
			};
		};
	};

	// -- ImeIMMaterial
	for (unsigned int ix0=0;ix0<imeimmaterial.nodes.size();ix0++) {
		mat = imeimmaterial.nodes[ix0];

		//mat->ref: IDIREF
		//mat->grp = TBD;
		//mat->own = TBD;
		//mat->ixVBasetype: IXSREF
		//mat->modRefPlnrMMaterial: IMPPP
		//mat->sref: TBL
		//mat->Title: TBL
		
		dbsplnr->tblplnrmmaterial->insertRec(mat);
		impcnt++;


		for (unsigned int ix1=0;ix1<mat->imeiammaterialpar.nodes.size();ix1++) {
			matApar = mat->imeiammaterialpar.nodes[ix1];

			matApar->refPlnrMMaterial = mat->ref;
			//matApar->x2SrefKCat: TBL
			//matApar->x3SrefKProp: TBL
			//matApar->refPlnrMFile: PREVIMP
			//matApar->Val: TBL
			//matApar->Comment: TBL

			if (matApar->irefRefPlnrMFile != 0) {
				for (unsigned int ix=0;ix<imeimfile.nodes.size();ix++) {
					fil = imeimfile.nodes[ix];
					if (fil->iref == matApar->irefRefPlnrMFile) {
						matApar->refPlnrMFile = fil->ref;
						break;
					};
				};
			};

			dbsplnr->tblplnrammaterialpar->insertRec(matApar);
			impcnt++;
		};
	};

	// -- ImeIMDevice
	for (unsigned int ix0=0;ix0<imeimdevice.nodes.size();ix0++) {
		dev = imeimdevice.nodes[ix0];

		//dev->ref: IDIREF
		//dev->supRefPlnrMDevice: IMPPP
		//dev->sref: TBL
		dev->ixVAligntype = VecPlnrVMDeviceAligntype::ABS;
		//dev->Comment: TBL

		dbsplnr->tblplnrmdevice->insertRec(dev);
		impcnt++;

		for (unsigned int ix1=0;ix1<dev->imeiavkeylistkey2.nodes.size();ix1++) {
			klsAkey2 = dev->imeiavkeylistkey2.nodes[ix1];

			klsAkey2->klsIxPlnrVKeylist = VecPlnrVKeylist::KLSTPLNRKAMDEVICEPARKEY;
			klsAkey2->klsNum = (ix1+1);
			klsAkey2->x1IxPlnrVMaintable = VecPlnrVMaintable::TBLPLNRMDEVICE;
			klsAkey2->x1Uref = dev->ref;
			klsAkey2->Fixed = true;
			//klsAkey2->sref: TBL
			//klsAkey2->Avail: TBL
			//klsAkey2->Implied: TBL
			//klsAkey2->refJ: SUB

			dbsplnr->tblplnravkeylistkey->insertRec(klsAkey2);
			impcnt++;

			for (unsigned int ix2=0;ix2<klsAkey2->imeijavkeylistkey2.nodes.size();ix2++) {
				klkJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];

				klkJkey2->refPlnrAVKeylistKey = klsAkey2->ref;
				//klkJkey2->x1IxPlnrVLocale: IXSREF
				//klkJkey2->Title: TBL
				//klkJkey2->Comment: TBL

				dbsplnr->tblplnrjavkeylistkey->insertRec(klkJkey2);
				impcnt++;
			};

			if (klsAkey2->imeijavkeylistkey2.nodes.size() > 0) {
				klkJkey2 = klsAkey2->imeijavkeylistkey2.nodes[0];

				klsAkey2->refJ = klkJkey2->ref;
				klsAkey2->Title = klkJkey2->Title;
				klsAkey2->Comment = klkJkey2->Comment;
			
				dbsplnr->tblplnravkeylistkey->updateRec(klsAkey2);
			};
		};

		for (unsigned int ix1=0;ix1<dev->imeiamdevicepar.nodes.size();ix1++) {
			devApar = dev->imeiamdevicepar.nodes[ix1];

			devApar->refPlnrMDevice = dev->ref;
			//devApar->x2SrefKKey: TBL
			//devApar->refPlnrMFile: PREVIMP
			//devApar->Val: TBL

			if (devApar->irefRefPlnrMFile != 0) {
				for (unsigned int ix=0;ix<imeimfile.nodes.size();ix++) {
					fil = imeimfile.nodes[ix];
					if (fil->iref == devApar->irefRefPlnrMFile) {
						devApar->refPlnrMFile = fil->ref;
						break;
					};
				};
			};

			dbsplnr->tblplnramdevicepar->insertRec(devApar);
			impcnt++;
		};

		for (unsigned int ix1=0;ix1<dev->imeimstructure.nodes.size();ix1++) {
			sru = dev->imeimstructure.nodes[ix1];

			sru->hkIxVTbl = VecPlnrVMStructureHkTbl::DEV;
			sru->hkUref = dev->ref;
			//sru->sref: TBL

			dbsplnr->tblplnrmstructure->insertRec(sru);
			impcnt++;
		};
	};

	// -- ImeIMCalc
	for (unsigned int ix0=0;ix0<imeimcalc.nodes.size();ix0++) {
		cal = imeimcalc.nodes[ix0];

		//cal->grp = TBD;
		//cal->own = TBD;
		//cal->ixVDim: IXSREF
		//cal->Title: TBL
		//cal->Comment: TBL

		dbsplnr->tblplnrmcalc->insertRec(cal);
		impcnt++;

		for (unsigned int ix1=0;ix1<cal->imeiavkeylistkey3.nodes.size();ix1++) {
			klsAkey3 = cal->imeiavkeylistkey3.nodes[ix1];

			//klsAkey3->klsIxPlnrVKeylist: IXSREF
			klsAkey3->klsNum = (ix1+1);
			klsAkey3->x1IxPlnrVMaintable = VecPlnrVMaintable::TBLPLNRMCALC;
			klsAkey3->x1Uref = cal->ref;
			klsAkey3->Fixed = true;
			//klsAkey3->sref: TBL
			//klsAkey3->Avail: TBL
			//klsAkey3->Implied: TBL
			//klsAkey3->refJ: SUB

			dbsplnr->tblplnravkeylistkey->insertRec(klsAkey3);
			impcnt++;

			for (unsigned int ix2=0;ix2<klsAkey3->imeijavkeylistkey3.nodes.size();ix2++) {
				klkJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix2];

				klkJkey3->refPlnrAVKeylistKey = klsAkey3->ref;
				//klkJkey3->x1IxPlnrVLocale: IXSREF
				//klkJkey3->Title: TBL
				//klkJkey3->Comment: TBL

				dbsplnr->tblplnrjavkeylistkey->insertRec(klkJkey3);
				impcnt++;
			};

			if (klsAkey3->imeijavkeylistkey3.nodes.size() > 0) {
				klkJkey3 = klsAkey3->imeijavkeylistkey3.nodes[0];

				klsAkey3->refJ = klkJkey3->ref;
				klsAkey3->Title = klkJkey3->Title;
				klsAkey3->Comment = klkJkey3->Comment;
			
				dbsplnr->tblplnravkeylistkey->updateRec(klsAkey3);
			};
		};
	};
// IP import.traverse --- REND

// IP import.ppr --- IBEGIN
	// -- MFile
	// ... have user upload files

	// -- MMaterial
	for (unsigned int ix0=0;ix0<imeimmaterial.nodes.size();ix0++) {
		mat = imeimmaterial.nodes[ix0];

		if (mat->irefModRefPlnrMMaterial != 0) {
			for (unsigned int ix=0;ix<imeimmaterial.nodes.size();ix++) {
				mat2 = imeimmaterial.nodes[ix];

				if (mat2->iref == mat->irefModRefPlnrMMaterial) {
					mat->modRefPlnrMMaterial = mat2->ref;
					mat->modLvl = mat2->modLvl + 1;

					break;
				};
			};

			dbsplnr->tblplnrmmaterial->updateRec(mat);
		};
	};

	// -- MDevice
	for (unsigned int ix0=0;ix0<imeimdevice.nodes.size();ix0++) {
		dev = imeimdevice.nodes[ix0];

		if (dev->irefSupRefPlnrMDevice != 0) {
			for (unsigned int ix=0;ix<imeimdevice.nodes.size();ix++) {
				dev2 = imeimdevice.nodes[ix];

				if (dev2->iref == dev->irefSupRefPlnrMDevice) {
					dev->supRefPlnrMDevice = dev2->ref;
					dev->supNum = (ix0 + 1);// TBD

					break;
				};
			};

			dbsplnr->tblplnrmdevice->updateRec(dev);
		};
	};
// IP import.ppr --- IEND
};

void IexPlnrIni::collect(
			DbsPlnr* dbsplnr
			, const map<uint,uint>& icsPlnrVIop
		) {
	ImeitemIAVControlPar* cntApar = NULL;
	ImeitemIAVKeylistKey1* klsAkey1 = NULL;
	ImeitemIAVValuelistVal* vlsAval = NULL;
	ImeitemIMCalc* cal = NULL;
	ImeitemIMDevice* dev = NULL;
	ImeitemIMFile* fil = NULL;
	ImeitemIMMaterial* mat = NULL;
	ImeitemIMUsergroup* usg = NULL;
	ImeitemIAMDevicePar* devApar = NULL;
	ImeitemIAMMaterialPar* matApar = NULL;
	ImeitemIAMUsergroupAccess* usgAacc = NULL;
	ImeitemIAVKeylistKey2* klsAkey2 = NULL;
	ImeitemIAVKeylistKey3* klsAkey3 = NULL;
	ImeitemIJAVKeylistKey1* klkJkey1 = NULL;
	ImeitemIMStructure* sru = NULL;
	ImeitemIMUser* usr = NULL;
	ImeitemIJAVKeylistKey2* klkJkey2 = NULL;
	ImeitemIJAVKeylistKey3* klkJkey3 = NULL;
	ImeitemIJMUserState* usrJste = NULL;
	ImeitemIMPerson* prs = NULL;
	ImeitemIJMPersonLastname* prsJlnm = NULL;

	uint ixPlnrVIop;

	vector<ubigint> refs;

	Stcch* stcch = new Stcch(false);

// IP collect.traverse --- BEGIN

	// -- ImeIAVControlPar
	for (unsigned int ix0=0;ix0<imeiavcontrolpar.nodes.size();ix0++) {
		cntApar = imeiavcontrolpar.nodes[ix0];

		if (cntApar->ref != 0) {
		};
	};

	// -- ImeIAVKeylistKey1
	for (unsigned int ix0=0;ix0<imeiavkeylistkey1.nodes.size();ix0++) {
		klsAkey1 = imeiavkeylistkey1.nodes[ix0];

		if (klsAkey1->ref != 0) {
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIJAVKEYLISTKEY1, ixPlnrVIop)) {
			dbsplnr->tblplnrjavkeylistkey->loadRefsByKlk(klsAkey1->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey1->refJ) {refs[i] = refs[0]; refs[0] = klsAkey1->refJ; break;};
			for (unsigned int i=0;i<refs.size();i++) klsAkey1->imeijavkeylistkey1.nodes.push_back(new ImeitemIJAVKeylistKey1(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<klsAkey1->imeijavkeylistkey1.nodes.size();ix1++) {
			klkJkey1 = klsAkey1->imeijavkeylistkey1.nodes[ix1];

			if (klkJkey1->ref != 0) {
			};
		};
	};

	// -- ImeIAVValuelistVal
	for (unsigned int ix0=0;ix0<imeiavvaluelistval.nodes.size();ix0++) {
		vlsAval = imeiavvaluelistval.nodes[ix0];

		if (vlsAval->ref != 0) {
		};
	};

	// -- ImeIMCalc
	for (unsigned int ix0=0;ix0<imeimcalc.nodes.size();ix0++) {
		cal = imeimcalc.nodes[ix0];

		if (cal->ref != 0) {
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIAVKEYLISTKEY3, ixPlnrVIop)) {
			dbsplnr->tblplnravkeylistkey->loadRefsByMtbUrf(VecPlnrVMaintable::TBLPLNRMCALC, cal->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) cal->imeiavkeylistkey3.nodes.push_back(new ImeitemIAVKeylistKey3(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<cal->imeiavkeylistkey3.nodes.size();ix1++) {
			klsAkey3 = cal->imeiavkeylistkey3.nodes[ix1];

			if (klsAkey3->ref != 0) {
			};

			if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIJAVKEYLISTKEY3, ixPlnrVIop)) {
				dbsplnr->tblplnrjavkeylistkey->loadRefsByKlk(klsAkey3->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey3->refJ) {refs[i] = refs[0]; refs[0] = klsAkey3->refJ; break;};
				for (unsigned int i=0;i<refs.size();i++) klsAkey3->imeijavkeylistkey3.nodes.push_back(new ImeitemIJAVKeylistKey3(dbsplnr, refs[i]));
			};

			for (unsigned int ix2=0;ix2<klsAkey3->imeijavkeylistkey3.nodes.size();ix2++) {
				klkJkey3 = klsAkey3->imeijavkeylistkey3.nodes[ix2];

				if (klkJkey3->ref != 0) {
				};
			};
		};
	};

	// -- ImeIMDevice
	for (unsigned int ix0=0;ix0<imeimdevice.nodes.size();ix0++) {
		dev = imeimdevice.nodes[ix0];

		if (dev->ref != 0) {
			dev->iref = ix0+1;
			//dev->irefSupRefPlnrMDevice: IREF
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIAMDEVICEPAR, ixPlnrVIop)) {
			dbsplnr->tblplnramdevicepar->loadRefsByDev(dev->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) dev->imeiamdevicepar.nodes.push_back(new ImeitemIAMDevicePar(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<dev->imeiamdevicepar.nodes.size();ix1++) {
			devApar = dev->imeiamdevicepar.nodes[ix1];

			if (devApar->ref != 0) {
				//devApar->irefRefPlnrMFile: IREF
			};
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIAVKEYLISTKEY2, ixPlnrVIop)) {
			dbsplnr->tblplnravkeylistkey->loadRefsByMtbUrf(VecPlnrVMaintable::TBLPLNRMDEVICE, dev->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) dev->imeiavkeylistkey2.nodes.push_back(new ImeitemIAVKeylistKey2(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<dev->imeiavkeylistkey2.nodes.size();ix1++) {
			klsAkey2 = dev->imeiavkeylistkey2.nodes[ix1];

			if (klsAkey2->ref != 0) {
			};

			if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIJAVKEYLISTKEY2, ixPlnrVIop)) {
				dbsplnr->tblplnrjavkeylistkey->loadRefsByKlk(klsAkey2->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == klsAkey2->refJ) {refs[i] = refs[0]; refs[0] = klsAkey2->refJ; break;};
				for (unsigned int i=0;i<refs.size();i++) klsAkey2->imeijavkeylistkey2.nodes.push_back(new ImeitemIJAVKeylistKey2(dbsplnr, refs[i]));
			};

			for (unsigned int ix2=0;ix2<klsAkey2->imeijavkeylistkey2.nodes.size();ix2++) {
				klkJkey2 = klsAkey2->imeijavkeylistkey2.nodes[ix2];

				if (klkJkey2->ref != 0) {
				};
			};
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIMSTRUCTURE, ixPlnrVIop)) {
			dbsplnr->tblplnrmstructure->loadRefsByHktHku(VecPlnrVMStructureHkTbl::DEV, dev->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) dev->imeimstructure.nodes.push_back(new ImeitemIMStructure(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<dev->imeimstructure.nodes.size();ix1++) {
			sru = dev->imeimstructure.nodes[ix1];

			if (sru->ref != 0) {
			};
		};
	};

	// -- ImeIMFile
	for (unsigned int ix0=0;ix0<imeimfile.nodes.size();ix0++) {
		fil = imeimfile.nodes[ix0];

		if (fil->ref != 0) {
			fil->iref = ix0+1;
		};
	};

	// -- ImeIMMaterial
	for (unsigned int ix0=0;ix0<imeimmaterial.nodes.size();ix0++) {
		mat = imeimmaterial.nodes[ix0];

		if (mat->ref != 0) {
			mat->iref = ix0+1;
			//mat->irefModRefPlnrMMaterial: IREF
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIAMMATERIALPAR, ixPlnrVIop)) {
			dbsplnr->tblplnrammaterialpar->loadRefsByMat(mat->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) mat->imeiammaterialpar.nodes.push_back(new ImeitemIAMMaterialPar(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<mat->imeiammaterialpar.nodes.size();ix1++) {
			matApar = mat->imeiammaterialpar.nodes[ix1];

			if (matApar->ref != 0) {
				//matApar->irefRefPlnrMFile: IREF
			};
		};
	};

	// -- ImeIMUsergroup
	for (unsigned int ix0=0;ix0<imeimusergroup.nodes.size();ix0++) {
		usg = imeimusergroup.nodes[ix0];

		if (usg->ref != 0) {
		};

		if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIAMUSERGROUPACCESS, ixPlnrVIop)) {
			dbsplnr->tblplnramusergroupaccess->loadRefsByUsg(usg->ref, false, refs);
			for (unsigned int i=0;i<refs.size();i++) usg->imeiamusergroupaccess.nodes.push_back(new ImeitemIAMUsergroupAccess(dbsplnr, refs[i]));
		};

		for (unsigned int ix1=0;ix1<usg->imeiamusergroupaccess.nodes.size();ix1++) {
			usgAacc = usg->imeiamusergroupaccess.nodes[ix1];

			if (usgAacc->ref != 0) {
			};
		};

		for (unsigned int ix1=0;ix1<usg->imeimuser.nodes.size();ix1++) {
			usr = usg->imeimuser.nodes[ix1];

			if (usr->ref != 0) {
			};

			if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIJMUSERSTATE, ixPlnrVIop)) {
				dbsplnr->tblplnrjmuserstate->loadRefsByUsr(usr->ref, false, refs);
				for (unsigned int i=0;i<refs.size();i++) if (refs[i] == usr->refJState) {refs[i] = refs[0]; refs[0] = usr->refJState; break;};
				for (unsigned int i=0;i<refs.size();i++) usr->imeijmuserstate.nodes.push_back(new ImeitemIJMUserState(dbsplnr, refs[i]));
			};

			for (unsigned int ix2=0;ix2<usr->imeijmuserstate.nodes.size();ix2++) {
				usrJste = usr->imeijmuserstate.nodes[ix2];

				if (usrJste->ref != 0) {
				};
			};

			for (unsigned int ix2=0;ix2<usr->imeimperson.nodes.size();ix2++) {
				prs = usr->imeimperson.nodes[ix2];

				if (prs->ref != 0) {
				};

				if (getIxPlnrVIop(icsPlnrVIop, VecVIme::IMEIJMPERSONLASTNAME, ixPlnrVIop)) {
					dbsplnr->tblplnrjmpersonlastname->loadRefsByPrs(prs->ref, false, refs);
					for (unsigned int i=0;i<refs.size();i++) if (refs[i] == prs->refJLastname) {refs[i] = refs[0]; refs[0] = prs->refJLastname; break;};
					for (unsigned int i=0;i<refs.size();i++) prs->imeijmpersonlastname.nodes.push_back(new ImeitemIJMPersonLastname(dbsplnr, refs[i]));
				};

				for (unsigned int ix3=0;ix3<prs->imeijmpersonlastname.nodes.size();ix3++) {
					prsJlnm = prs->imeijmpersonlastname.nodes[ix3];

					if (prsJlnm->ref != 0) {
					};
				};
			};
		};
	};
// IP collect.traverse --- END

// IP collect.ppr --- INSERT

	delete stcch;
};

bool IexPlnrIni::readTxt(
			Txtrd& txtrd
		) {
	bool parseok = true;

	while (txtrd.readLine()) {
		if (txtrd.comment) {
		} else if (txtrd.header && (txtrd.il == 0)) {
			if (txtrd.ixVToken == VecVIme::IMEIAVCONTROLPAR) {
				parseok = imeiavcontrolpar.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVKEYLISTKEY1) {
				parseok = imeiavkeylistkey1.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIAVVALUELISTVAL) {
				parseok = imeiavvaluelistval.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMCALC) {
				parseok = imeimcalc.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMDEVICE) {
				parseok = imeimdevice.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMFILE) {
				parseok = imeimfile.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMMATERIAL) {
				parseok = imeimmaterial.readTxt(txtrd); if (!parseok) break;
			} else if (txtrd.ixVToken == VecVIme::IMEIMUSERGROUP) {
				parseok = imeimusergroup.readTxt(txtrd); if (!parseok) break;
			} else {
				parseok = false; break;
			};
		} else {
			parseok = false; break;
		};
	};

	lineno = txtrd.linecnt;

	return parseok;
};

void IexPlnrIni::readXML(
			xmlXPathContext* docctx
			, string basexpath
		) {
	bool basefound;

	basefound = checkUclcXPaths(docctx, basexpath, basexpath, "IexPlnrIni");

	if (basefound) {
		// look for XML sub-blocks
		imeiavcontrolpar.readXML(docctx, basexpath);
		imeiavkeylistkey1.readXML(docctx, basexpath);
		imeiavvaluelistval.readXML(docctx, basexpath);
		imeimcalc.readXML(docctx, basexpath);
		imeimdevice.readXML(docctx, basexpath);
		imeimfile.readXML(docctx, basexpath);
		imeimmaterial.readXML(docctx, basexpath);
		imeimusergroup.readXML(docctx, basexpath);
	} else {
		imeiavcontrolpar = ImeIAVControlPar();
		imeiavkeylistkey1 = ImeIAVKeylistKey1();
		imeiavvaluelistval = ImeIAVValuelistVal();
		imeimcalc = ImeIMCalc();
		imeimdevice = ImeIMDevice();
		imeimfile = ImeIMFile();
		imeimmaterial = ImeIMMaterial();
		imeimusergroup = ImeIMUsergroup();
	};
};

bool IexPlnrIni::readTxtFile(
			const string& fullpath
		) {
	bool retval;

	Txtrd rd(VecVIme::getIx);

	rd.openFile(fullpath);

	retval = readTxt(rd);

	rd.closeFile();

	return retval;
};

bool IexPlnrIni::readXMLFile(
			const string& fullpath
		) {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	parseFile(fullpath, &doc, &docctx);
	readXML(docctx, "/");

	closeParsed(doc, docctx);

	return true;
};

void IexPlnrIni::writeTxt(
			fstream& outfile
		) {
	imeiavcontrolpar.writeTxt(outfile);
	imeiavkeylistkey1.writeTxt(outfile);
	imeiavvaluelistval.writeTxt(outfile);
	imeimcalc.writeTxt(outfile);
	imeimdevice.writeTxt(outfile);
	imeimfile.writeTxt(outfile);
	imeimmaterial.writeTxt(outfile);
	imeimusergroup.writeTxt(outfile);
};

void IexPlnrIni::writeXML(
			xmlTextWriter* wr
			, const bool shorttags
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "IexPlnrIni");
		imeiavcontrolpar.writeXML(wr, shorttags);
		imeiavkeylistkey1.writeXML(wr, shorttags);
		imeiavvaluelistval.writeXML(wr, shorttags);
		imeimcalc.writeXML(wr, shorttags);
		imeimdevice.writeXML(wr, shorttags);
		imeimfile.writeXML(wr, shorttags);
		imeimmaterial.writeXML(wr, shorttags);
		imeimusergroup.writeXML(wr, shorttags);
	xmlTextWriterEndElement(wr);
};

void IexPlnrIni::writeTxtFile(
			const string& fullpath
		) {
	fstream txtfile;

	txtfile.open(fullpath.c_str(), ios::out);

	writeTxt(txtfile);
	
	txtfile.close();
};

void IexPlnrIni::writeXMLFile(
			const string& fullpath
			, const bool shorttags
		) {
	xmlTextWriter* wr = NULL;

	startwriteFile(fullpath, &wr);
		writeXML(wr, shorttags);
	closewriteFile(wr);
};

map<uint,uint> IexPlnrIni::icsPlnrVIopInsAll() {
	return {{(uint)VecVIme::IMEIAVCONTROLPAR,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY1,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAVVALUELISTVAL,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMCALC,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMDEVICE,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMFILE,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMMATERIAL,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMUSERGROUP,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAMDEVICEPAR,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAMMATERIALPAR,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAMUSERGROUPACCESS,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY2,VecPlnrVIop::INS},{(uint)VecVIme::IMEIAVKEYLISTKEY3,VecPlnrVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY1,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMSTRUCTURE,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMUSER,VecPlnrVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY2,VecPlnrVIop::INS},{(uint)VecVIme::IMEIJAVKEYLISTKEY3,VecPlnrVIop::INS},{(uint)VecVIme::IMEIJMUSERSTATE,VecPlnrVIop::INS},{(uint)VecVIme::IMEIMPERSON,VecPlnrVIop::INS},{(uint)VecVIme::IMEIJMPERSONLASTNAME,VecPlnrVIop::INS}};
};

uint IexPlnrIni::getIxPlnrVIop(
			const map<uint,uint>& icsPlnrVIop
			, const uint ixVIme
			, uint& ixPlnrVIop
		) {
	ixPlnrVIop = 0;

	auto it = icsPlnrVIop.find(ixVIme);
	if (it != icsPlnrVIop.end()) ixPlnrVIop = it->second;

	return ixPlnrVIop;
};

void IexPlnrIni::handleRequest(
			DbsPlnr* dbsplnr
			, ReqPlnr* req
		) {
	if (req->ixVBasetype == ReqPlnr::VecVBasetype::CMD) {
		if (req->cmd.compare("cmdset") == 0) {

		} else {
			cout << "\tinvalid command!" << endl;
		};
	};
};

void IexPlnrIni::handleCall(
			DbsPlnr* dbsplnr
			, Call* call
		) {
};


