/**
  * \file DbsPlnr.h
  * C++ wrapper for database DbsPlnr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef DBSPLNR_H
#define DBSPLNR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include "VecPlnrVAccess.h"
#include "VecPlnrVCard.h"
#include "VecPlnrVControl.h"
#include "VecPlnrVKeylist.h"
#include "VecPlnrVLat.h"
#include "VecPlnrVLocale.h"
#include "VecPlnrVLop.h"
#include "VecPlnrVMaintable.h"
#include "VecPlnrVOolop.h"
#include "VecPlnrVPreset.h"
#include "VecPlnrVUserlevel.h"
#include "VecPlnrVValuelist.h"
#include "VecPlnrWUiaccess.h"
#include "VecPlnrVMArcguideHkTbl.h"
#include "VecPlnrVMCalcDim.h"
#include "VecPlnrVMDesignBasetype.h"
#include "VecPlnrVMDesignDim.h"
#include "VecPlnrVMDesignRefTbl.h"
#include "VecPlnrVMDeviceAligntype.h"
#include "VecPlnrVMDeviceModtype.h"
#include "VecPlnrVMDomainBasetype.h"
#include "VecPlnrVMDomaingdBasetype.h"
#include "VecPlnrVMFileRefTbl.h"
#include "VecPlnrVMLayerBasetype.h"
#include "VecPlnrVMLayerHkTbl.h"
#include "VecPlnrVMLayerTtype.h"
#include "VecPlnrVMLevelHkTbl.h"
#include "VecPlnrVMLineguideHkTbl.h"
#include "VecPlnrVMMaterialBasetype.h"
#include "VecPlnrVMPersonSex.h"
#include "VecPlnrVMProjectState.h"
#include "VecPlnrVMReticleHkTbl.h"
#include "VecPlnrVMStackBasetype.h"
#include "VecPlnrVMStackCeilAligntype.h"
#include "VecPlnrVMStackFlrAligntype.h"
#include "VecPlnrVMStackModtype.h"
#include "VecPlnrVMStructureHkTbl.h"
#include "VecPlnrVMTapeoutBasetype.h"
#include "VecPlnrVMTapeoutState.h"
#include "VecPlnrVMUserState.h"
#include "VecPlnrVMVertexHkTbl.h"
#include "VecPlnrVRMCalcMFileIo.h"
#include "VecPlnrVRMFaceMVertexDir.h"
#include "VecPlnrVRMFaceMVertexRteTbl.h"
#include "VecPlnrWMDesignModtype.h"
#include "VecPlnrWMPersonDerivate.h"

#include "PlnrAccRMUserUniversal.h"
#include "PlnrAMArrayEnv.h"
#include "PlnrAMCalcEnv.h"
#include "PlnrAMCalcPar.h"
#include "PlnrAMDevicePar.h"
#include "PlnrAMMaterialPar.h"
#include "PlnrAMPersonDetail.h"
#include "PlnrAMUserAccess.h"
#include "PlnrAMUsergroupAccess.h"
#include "PlnrAVControlPar.h"
#include "PlnrAVKeylistKey.h"
#include "PlnrAVValuelistVal.h"
#include "PlnrCFile.h"
#include "PlnrDevOMDeviceMArcguide.h"
#include "PlnrDevOMDeviceMLineguide.h"
#include "PlnrDevOMDeviceMVertex.h"
#include "PlnrDevORMArcguideMVertex.h"
#include "PlnrDevORMLineguideMVertex.h"
#include "PlnrHistRMUserUniversal.h"
#include "PlnrJAVKeylistKey.h"
#include "PlnrJMArcguideR.h"
#include "PlnrJMDeviceModtype.h"
#include "PlnrJMDomain.h"
#include "PlnrJMDomaingd.h"
#include "PlnrJMLayer.h"
#include "PlnrJMLayerMaterial.h"
#include "PlnrJMLevelZ.h"
#include "PlnrJMPersonLastname.h"
#include "PlnrJMProjectState.h"
#include "PlnrJMStackModtype.h"
#include "PlnrJMStackN.h"
#include "PlnrJMTapeoutState.h"
#include "PlnrJMUserState.h"
#include "PlnrJMVertex.h"
#include "PlnrLRMArcguideMVertex.h"
#include "PlnrLRMLineguideMVertex.h"
#include "PlnrMArcguide.h"
#include "PlnrMArray.h"
#include "PlnrMArrayitem.h"
#include "PlnrMBlock.h"
#include "PlnrMCalc.h"
#include "PlnrMCalcitem.h"
#include "PlnrMDesign.h"
#include "PlnrMDevice.h"
#include "PlnrMDomain.h"
#include "PlnrMDomaingd.h"
#include "PlnrMFace.h"
#include "PlnrMFile.h"
#include "PlnrMLayer.h"
#include "PlnrMLevel.h"
#include "PlnrMLineguide.h"
#include "PlnrMMaterial.h"
#include "PlnrMPerson.h"
#include "PlnrMProject.h"
#include "PlnrMReticle.h"
#include "PlnrMSession.h"
#include "PlnrMStack.h"
#include "PlnrMStructure.h"
#include "PlnrMTapeout.h"
#include "PlnrMUser.h"
#include "PlnrMUsergroup.h"
#include "PlnrMVertex.h"
#include "PlnrOMStructureMFace.h"
#include "PlnrRMCalcMDomain.h"
#include "PlnrRMCalcMFile.h"
#include "PlnrRMFaceMVertex.h"
#include "PlnrRMLayerMStructure.h"
#include "PlnrRMLevelMLevel.h"
#include "PlnrRMLineguideMLineguide.h"
#include "PlnrRMProjectMTapeout.h"
#include "PlnrRMStackMStructure.h"
#include "PlnrRMUsergroupUniversal.h"
#include "PlnrRMUserMUsergroup.h"
#include "PlnrRMVertexMVertex.h"

#include "PlnrQAriAMArrayEnv.h"
#include "PlnrQAriList.h"
#include "PlnrQArr1NArrayitem.h"
#include "PlnrQArrAEnv.h"
#include "PlnrQArrHk1NReticle.h"
#include "PlnrQArrKEnvKey.h"
#include "PlnrQArrList.h"
#include "PlnrQClc1NMaterial.h"
#include "PlnrQClcAEnv.h"
#include "PlnrQClcAPar.h"
#include "PlnrQClcCal1NCalcitem.h"
#include "PlnrQClcList.h"
#include "PlnrQClcMNDomain.h"
#include "PlnrQClcMNFile.h"
#include "PlnrQClcRef1NFile.h"
#include "PlnrQClcSup1NCalc.h"
#include "PlnrQCliAAMCalcEnv.h"
#include "PlnrQCliAAMCalcPar.h"
#include "PlnrQCliList.h"
#include "PlnrQCliRef1NFile.h"
#include "PlnrQCtpAEnv.h"
#include "PlnrQCtpAPar.h"
#include "PlnrQCtpKCalcdomprp.h"
#include "PlnrQCtpKCalcvar.h"
#include "PlnrQCtpKEnvKey.h"
#include "PlnrQCtpKParCat.h"
#include "PlnrQCtpKParProp.h"
#include "PlnrQCtpList.h"
#include "PlnrQCtpRef1NFile.h"
#include "PlnrQCtpSup1NCalc.h"
#include "PlnrQCtpTpl1NCalc.h"
#include "PlnrQDgdList.h"
#include "PlnrQDomList.h"
#include "PlnrQDomMNCalc.h"
#include "PlnrQDsn1NBlock.h"
#include "PlnrQDsn1NReticle.h"
#include "PlnrQDsnDrv1NDesign.h"
#include "PlnrQDsnDsn1NDevice.h"
#include "PlnrQDsnDsn1NDomain.h"
#include "PlnrQDsnDsn1NDomaingd.h"
#include "PlnrQDsnDsn1NStack.h"
#include "PlnrQDsnHk1NArcguide.h"
#include "PlnrQDsnHk1NLayer.h"
#include "PlnrQDsnHk1NLevel.h"
#include "PlnrQDsnHk1NLineguide.h"
#include "PlnrQDsnHk1NStructure.h"
#include "PlnrQDsnHk1NVertex.h"
#include "PlnrQDsnList.h"
#include "PlnrQDsnMod1NDesign.h"
#include "PlnrQDtpAPar.h"
#include "PlnrQDtpHk1NStructure.h"
#include "PlnrQDtpKParKey.h"
#include "PlnrQDtpList.h"
#include "PlnrQDtpSup1NDevice.h"
#include "PlnrQDtpTpl1NDevice.h"
#include "PlnrQDvcAPar.h"
#include "PlnrQDvcHk1NArcguide.h"
#include "PlnrQDvcHk1NLineguide.h"
#include "PlnrQDvcHk1NStructure.h"
#include "PlnrQDvcHk1NVertex.h"
#include "PlnrQDvcList.h"
#include "PlnrQDvcSup1NDevice.h"
#include "PlnrQFilList.h"
#include "PlnrQFilMNCalc.h"
#include "PlnrQLyr1NBlock.h"
#include "PlnrQLyr1NReticle.h"
#include "PlnrQLyrList.h"
#include "PlnrQLyrMNStructure.h"
#include "PlnrQMat1NLayer.h"
#include "PlnrQMatAPar.h"
#include "PlnrQMatList.h"
#include "PlnrQMatMod1NMaterial.h"
#include "PlnrQMatRef1NFile.h"
#include "PlnrQPreselect.h"
#include "PlnrQPrj1NCalc.h"
#include "PlnrQPrj1NDesign.h"
#include "PlnrQPrjList.h"
#include "PlnrQPrjMNTapeout.h"
#include "PlnrQPrsADetail.h"
#include "PlnrQPrsList.h"
#include "PlnrQRtcList.h"
#include "PlnrQSelect.h"
#include "PlnrQSru1NBlock.h"
#include "PlnrQSruList.h"
#include "PlnrQSruMNLayer.h"
#include "PlnrQSruMNStack.h"
#include "PlnrQSruSru1NFace.h"
#include "PlnrQStkHk1NLayer.h"
#include "PlnrQStkHk1NLevel.h"
#include "PlnrQStkList.h"
#include "PlnrQStkMNStructure.h"
#include "PlnrQTpo1NArray.h"
#include "PlnrQTpoHk1NReticle.h"
#include "PlnrQTpoList.h"
#include "PlnrQTpoMNProject.h"
#include "PlnrQUsgAAccess.h"
#include "PlnrQUsgList.h"
#include "PlnrQUsgMNUser.h"
#include "PlnrQUsr1NSession.h"
#include "PlnrQUsrAAccess.h"
#include "PlnrQUsrList.h"
#include "PlnrQUsrMNUsergroup.h"

/**
  * DbsPlnr
  */
class DbsPlnr {

public:
	DbsPlnr();
	~DbsPlnr();

	void init(const uint _ixDbsVDbstype, const string& _dbspath, const string& _dbsname, const string& _ip, const uint _port, const string& _username, const string& _password);
	void term();

// IP inittermMy --- BEGIN
	void initMy();
	void termMy();
// IP inittermMy --- END
// IP inittermPg --- BEGIN
	void initPg();
	void termPg();
// IP inittermPg --- END

public:
	uint ixDbsVDbstype;
	string dbspath;
	string dbsname;
	string username;
	string password;
	string ip;
	int port;

	bool initdone;

// IP dbsMy --- BEGIN
	MYSQL* dbsMy;
// IP dbsMy --- END
// IP dbsPg --- BEGIN
	PGconn* dbsPg;
// IP dbsPg --- END

public:
	void begin();																						//!< transaction functionality
	bool commit();
	void rollback();

// IP transactMy --- BEGIN
	void beginMy();
	bool commitMy();
	void rollbackMy();
// IP transactMy --- END
// IP transactPg --- BEGIN
	void beginPg();
	bool commitPg();
	void rollbackPg();
// IP transactPg --- END

																													//! execute a SQL query returning a single ubigint (arbitrary tables)
	bool loadUbigintBySQL(const string& sqlstr, ubigint& val);
	bool loadStringBySQL(const string& sqlstr, string& val);//!< execute a SQL query returning a single string (arbitrary tables)
																													//! load a list of references by a SQL query (arbitrary tables)
	ubigint loadRefsBySQL(const string& sqlstr, const bool append, vector<ubigint>& refs);

// IP loadfctsMy --- BEGIN
	bool loadUbigintBySQLMy(const string& sqlstr, ubigint& val);
	bool loadStringBySQLMy(const string& sqlstr, string& val);
	ubigint loadRefsBySQLMy(const string& sqlstr, const bool append, vector<ubigint>& refs);
// IP loadfctsMy --- END
// IP loadfctsPg --- BEGIN
	bool loadUbigintBySQLPg(const string& sqlstr, ubigint& val);
	bool loadStringBySQLPg(const string& sqlstr, string& val);
	ubigint loadRefsBySQLPg(const string& sqlstr, const bool append, vector<ubigint>& refs);
// IP loadfctsPg --- END

	void executeQuery(const string& sqlstr);								//!< run single SQL command
	void executeQueryDiv(const string& sqlstrmy, const string& sqlstrpg);
	void executeFile(const string& fullpath);								//!< SQL file batch execution

public:
	void fillFeedFromKlst(const uint klsIxPlnrVKeylist, const uint ixPlnrVLocale, Feed& feed);
	void fillFeedFromKlstByMtbUref(const uint klsIxPlnrVKeylist, const uint x1IxPlnrVMaintable, const ubigint x1Uref, const uint ixPlnrVLocale, Feed& feed);

	string getKlstTitleBySref(const uint klsIxPlnrVKeylist, const string& sref, const uint ixPlnrVLocale = 0);
	string getKlstTitleByMtbUrefSref(const uint klsIxPlnrVKeylist, const uint x1IxPlnrVMaintable, const ubigint x1Uref, const string& sref, const uint ixPlnrVLocale = 0);

	void fillFeedFromVlst(const uint vlsIxPlnrVValuelist, const uint x1IxPlnrVLocale, Feed& feed);

public:
	TblPlnrAccRMUserUniversal* tblplnraccrmuseruniversal;
	TblPlnrAMArrayEnv* tblplnramarrayenv;
	TblPlnrAMCalcEnv* tblplnramcalcenv;
	TblPlnrAMCalcPar* tblplnramcalcpar;
	TblPlnrAMDevicePar* tblplnramdevicepar;
	TblPlnrAMMaterialPar* tblplnrammaterialpar;
	TblPlnrAMPersonDetail* tblplnrampersondetail;
	TblPlnrAMUserAccess* tblplnramuseraccess;
	TblPlnrAMUsergroupAccess* tblplnramusergroupaccess;
	TblPlnrAVControlPar* tblplnravcontrolpar;
	TblPlnrAVKeylistKey* tblplnravkeylistkey;
	TblPlnrAVValuelistVal* tblplnravvaluelistval;
	TblPlnrCFile* tblplnrcfile;
	TblPlnrDevOMDeviceMArcguide* tblplnrdevomdevicemarcguide;
	TblPlnrDevOMDeviceMLineguide* tblplnrdevomdevicemlineguide;
	TblPlnrDevOMDeviceMVertex* tblplnrdevomdevicemvertex;
	TblPlnrDevORMArcguideMVertex* tblplnrdevormarcguidemvertex;
	TblPlnrDevORMLineguideMVertex* tblplnrdevormlineguidemvertex;
	TblPlnrHistRMUserUniversal* tblplnrhistrmuseruniversal;
	TblPlnrJAVKeylistKey* tblplnrjavkeylistkey;
	TblPlnrJMArcguideR* tblplnrjmarcguider;
	TblPlnrJMDeviceModtype* tblplnrjmdevicemodtype;
	TblPlnrJMDomain* tblplnrjmdomain;
	TblPlnrJMDomaingd* tblplnrjmdomaingd;
	TblPlnrJMLayer* tblplnrjmlayer;
	TblPlnrJMLayerMaterial* tblplnrjmlayermaterial;
	TblPlnrJMLevelZ* tblplnrjmlevelz;
	TblPlnrJMPersonLastname* tblplnrjmpersonlastname;
	TblPlnrJMProjectState* tblplnrjmprojectstate;
	TblPlnrJMStackModtype* tblplnrjmstackmodtype;
	TblPlnrJMStackN* tblplnrjmstackn;
	TblPlnrJMTapeoutState* tblplnrjmtapeoutstate;
	TblPlnrJMUserState* tblplnrjmuserstate;
	TblPlnrJMVertex* tblplnrjmvertex;
	TblPlnrLRMArcguideMVertex* tblplnrlrmarcguidemvertex;
	TblPlnrLRMLineguideMVertex* tblplnrlrmlineguidemvertex;
	TblPlnrMArcguide* tblplnrmarcguide;
	TblPlnrMArray* tblplnrmarray;
	TblPlnrMArrayitem* tblplnrmarrayitem;
	TblPlnrMBlock* tblplnrmblock;
	TblPlnrMCalc* tblplnrmcalc;
	TblPlnrMCalcitem* tblplnrmcalcitem;
	TblPlnrMDesign* tblplnrmdesign;
	TblPlnrMDevice* tblplnrmdevice;
	TblPlnrMDomain* tblplnrmdomain;
	TblPlnrMDomaingd* tblplnrmdomaingd;
	TblPlnrMFace* tblplnrmface;
	TblPlnrMFile* tblplnrmfile;
	TblPlnrMLayer* tblplnrmlayer;
	TblPlnrMLevel* tblplnrmlevel;
	TblPlnrMLineguide* tblplnrmlineguide;
	TblPlnrMMaterial* tblplnrmmaterial;
	TblPlnrMPerson* tblplnrmperson;
	TblPlnrMProject* tblplnrmproject;
	TblPlnrMReticle* tblplnrmreticle;
	TblPlnrMSession* tblplnrmsession;
	TblPlnrMStack* tblplnrmstack;
	TblPlnrMStructure* tblplnrmstructure;
	TblPlnrMTapeout* tblplnrmtapeout;
	TblPlnrMUser* tblplnrmuser;
	TblPlnrMUsergroup* tblplnrmusergroup;
	TblPlnrMVertex* tblplnrmvertex;
	TblPlnrOMStructureMFace* tblplnromstructuremface;
	TblPlnrRMCalcMDomain* tblplnrrmcalcmdomain;
	TblPlnrRMCalcMFile* tblplnrrmcalcmfile;
	TblPlnrRMFaceMVertex* tblplnrrmfacemvertex;
	TblPlnrRMLayerMStructure* tblplnrrmlayermstructure;
	TblPlnrRMLevelMLevel* tblplnrrmlevelmlevel;
	TblPlnrRMLineguideMLineguide* tblplnrrmlineguidemlineguide;
	TblPlnrRMProjectMTapeout* tblplnrrmprojectmtapeout;
	TblPlnrRMStackMStructure* tblplnrrmstackmstructure;
	TblPlnrRMUsergroupUniversal* tblplnrrmusergroupuniversal;
	TblPlnrRMUserMUsergroup* tblplnrrmusermusergroup;
	TblPlnrRMVertexMVertex* tblplnrrmvertexmvertex;

	TblPlnrQAriAMArrayEnv* tblplnrqariamarrayenv;
	TblPlnrQAriList* tblplnrqarilist;
	TblPlnrQArr1NArrayitem* tblplnrqarr1narrayitem;
	TblPlnrQArrAEnv* tblplnrqarraenv;
	TblPlnrQArrHk1NReticle* tblplnrqarrhk1nreticle;
	TblPlnrQArrKEnvKey* tblplnrqarrkenvkey;
	TblPlnrQArrList* tblplnrqarrlist;
	TblPlnrQClc1NMaterial* tblplnrqclc1nmaterial;
	TblPlnrQClcAEnv* tblplnrqclcaenv;
	TblPlnrQClcAPar* tblplnrqclcapar;
	TblPlnrQClcCal1NCalcitem* tblplnrqclccal1ncalcitem;
	TblPlnrQClcList* tblplnrqclclist;
	TblPlnrQClcMNDomain* tblplnrqclcmndomain;
	TblPlnrQClcMNFile* tblplnrqclcmnfile;
	TblPlnrQClcRef1NFile* tblplnrqclcref1nfile;
	TblPlnrQClcSup1NCalc* tblplnrqclcsup1ncalc;
	TblPlnrQCliAAMCalcEnv* tblplnrqcliaamcalcenv;
	TblPlnrQCliAAMCalcPar* tblplnrqcliaamcalcpar;
	TblPlnrQCliList* tblplnrqclilist;
	TblPlnrQCliRef1NFile* tblplnrqcliref1nfile;
	TblPlnrQCtpAEnv* tblplnrqctpaenv;
	TblPlnrQCtpAPar* tblplnrqctpapar;
	TblPlnrQCtpKCalcdomprp* tblplnrqctpkcalcdomprp;
	TblPlnrQCtpKCalcvar* tblplnrqctpkcalcvar;
	TblPlnrQCtpKEnvKey* tblplnrqctpkenvkey;
	TblPlnrQCtpKParCat* tblplnrqctpkparcat;
	TblPlnrQCtpKParProp* tblplnrqctpkparprop;
	TblPlnrQCtpList* tblplnrqctplist;
	TblPlnrQCtpRef1NFile* tblplnrqctpref1nfile;
	TblPlnrQCtpSup1NCalc* tblplnrqctpsup1ncalc;
	TblPlnrQCtpTpl1NCalc* tblplnrqctptpl1ncalc;
	TblPlnrQDgdList* tblplnrqdgdlist;
	TblPlnrQDomList* tblplnrqdomlist;
	TblPlnrQDomMNCalc* tblplnrqdommncalc;
	TblPlnrQDsn1NBlock* tblplnrqdsn1nblock;
	TblPlnrQDsn1NReticle* tblplnrqdsn1nreticle;
	TblPlnrQDsnDrv1NDesign* tblplnrqdsndrv1ndesign;
	TblPlnrQDsnDsn1NDevice* tblplnrqdsndsn1ndevice;
	TblPlnrQDsnDsn1NDomain* tblplnrqdsndsn1ndomain;
	TblPlnrQDsnDsn1NDomaingd* tblplnrqdsndsn1ndomaingd;
	TblPlnrQDsnDsn1NStack* tblplnrqdsndsn1nstack;
	TblPlnrQDsnHk1NArcguide* tblplnrqdsnhk1narcguide;
	TblPlnrQDsnHk1NLayer* tblplnrqdsnhk1nlayer;
	TblPlnrQDsnHk1NLevel* tblplnrqdsnhk1nlevel;
	TblPlnrQDsnHk1NLineguide* tblplnrqdsnhk1nlineguide;
	TblPlnrQDsnHk1NStructure* tblplnrqdsnhk1nstructure;
	TblPlnrQDsnHk1NVertex* tblplnrqdsnhk1nvertex;
	TblPlnrQDsnList* tblplnrqdsnlist;
	TblPlnrQDsnMod1NDesign* tblplnrqdsnmod1ndesign;
	TblPlnrQDtpAPar* tblplnrqdtpapar;
	TblPlnrQDtpHk1NStructure* tblplnrqdtphk1nstructure;
	TblPlnrQDtpKParKey* tblplnrqdtpkparkey;
	TblPlnrQDtpList* tblplnrqdtplist;
	TblPlnrQDtpSup1NDevice* tblplnrqdtpsup1ndevice;
	TblPlnrQDtpTpl1NDevice* tblplnrqdtptpl1ndevice;
	TblPlnrQDvcAPar* tblplnrqdvcapar;
	TblPlnrQDvcHk1NArcguide* tblplnrqdvchk1narcguide;
	TblPlnrQDvcHk1NLineguide* tblplnrqdvchk1nlineguide;
	TblPlnrQDvcHk1NStructure* tblplnrqdvchk1nstructure;
	TblPlnrQDvcHk1NVertex* tblplnrqdvchk1nvertex;
	TblPlnrQDvcList* tblplnrqdvclist;
	TblPlnrQDvcSup1NDevice* tblplnrqdvcsup1ndevice;
	TblPlnrQFilList* tblplnrqfillist;
	TblPlnrQFilMNCalc* tblplnrqfilmncalc;
	TblPlnrQLyr1NBlock* tblplnrqlyr1nblock;
	TblPlnrQLyr1NReticle* tblplnrqlyr1nreticle;
	TblPlnrQLyrList* tblplnrqlyrlist;
	TblPlnrQLyrMNStructure* tblplnrqlyrmnstructure;
	TblPlnrQMat1NLayer* tblplnrqmat1nlayer;
	TblPlnrQMatAPar* tblplnrqmatapar;
	TblPlnrQMatList* tblplnrqmatlist;
	TblPlnrQMatMod1NMaterial* tblplnrqmatmod1nmaterial;
	TblPlnrQMatRef1NFile* tblplnrqmatref1nfile;
	TblPlnrQPreselect* tblplnrqpreselect;
	TblPlnrQPrj1NCalc* tblplnrqprj1ncalc;
	TblPlnrQPrj1NDesign* tblplnrqprj1ndesign;
	TblPlnrQPrjList* tblplnrqprjlist;
	TblPlnrQPrjMNTapeout* tblplnrqprjmntapeout;
	TblPlnrQPrsADetail* tblplnrqprsadetail;
	TblPlnrQPrsList* tblplnrqprslist;
	TblPlnrQRtcList* tblplnrqrtclist;
	TblPlnrQSelect* tblplnrqselect;
	TblPlnrQSru1NBlock* tblplnrqsru1nblock;
	TblPlnrQSruList* tblplnrqsrulist;
	TblPlnrQSruMNLayer* tblplnrqsrumnlayer;
	TblPlnrQSruMNStack* tblplnrqsrumnstack;
	TblPlnrQSruSru1NFace* tblplnrqsrusru1nface;
	TblPlnrQStkHk1NLayer* tblplnrqstkhk1nlayer;
	TblPlnrQStkHk1NLevel* tblplnrqstkhk1nlevel;
	TblPlnrQStkList* tblplnrqstklist;
	TblPlnrQStkMNStructure* tblplnrqstkmnstructure;
	TblPlnrQTpo1NArray* tblplnrqtpo1narray;
	TblPlnrQTpoHk1NReticle* tblplnrqtpohk1nreticle;
	TblPlnrQTpoList* tblplnrqtpolist;
	TblPlnrQTpoMNProject* tblplnrqtpomnproject;
	TblPlnrQUsgAAccess* tblplnrqusgaaccess;
	TblPlnrQUsgList* tblplnrqusglist;
	TblPlnrQUsgMNUser* tblplnrqusgmnuser;
	TblPlnrQUsr1NSession* tblplnrqusr1nsession;
	TblPlnrQUsrAAccess* tblplnrqusraaccess;
	TblPlnrQUsrList* tblplnrqusrlist;
	TblPlnrQUsrMNUsergroup* tblplnrqusrmnusergroup;
};
#endif

