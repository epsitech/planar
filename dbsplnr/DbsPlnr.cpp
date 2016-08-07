/**
  * \file DbsPlnr.cpp
  * C++ wrapper for database DbsPlnr (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "DbsPlnr.h"

/******************************************************************************
 class DbsPlnr
 ******************************************************************************/

DbsPlnr::DbsPlnr() {
	initdone = false;

	dbsMy = NULL;
	dbsPg = NULL;
};

DbsPlnr::~DbsPlnr() {
	term();
};

void DbsPlnr::init(
			const uint _ixDbsVDbstype
			, const string& _dbspath
			, const string& _dbsname
			, const string& _ip
			, const uint _port
			, const string& _username
			, const string& _password
		) {
	ixDbsVDbstype = _ixDbsVDbstype;
	dbspath = _dbspath;
	dbsname = _dbsname;
	username = _username;
	password = _password;
	ip = _ip;
	port = _port;

	if (ixDbsVDbstype == VecDbsVDbstype::MY) initMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) initPg();

	initdone = true;
};

void DbsPlnr::term() {
	if (initdone) {
		if (ixDbsVDbstype == VecDbsVDbstype::MY) termMy();
		else if (ixDbsVDbstype == VecDbsVDbstype::PG) termPg();
	};
};

// IP inittermMy --- BEGIN
void DbsPlnr::initMy() {
	// connect to MySQL database
	dbsMy = mysql_init(NULL);

	mysql_options(dbsMy, MYSQL_READ_DEFAULT_GROUP, "MyccDatabase");
	if (!mysql_real_connect(dbsMy, ip.c_str(), username.c_str(), password.c_str(), dbsname.c_str(), 0, NULL, 0)) throw DbsException("DbsException / MySQL: connection failure");

	executeQuery("SET SESSION wait_timeout = 31536000");

	tblplnraccrmuseruniversal = new MyTblPlnrAccRMUserUniversal();
	((MyTblPlnrAccRMUserUniversal*) tblplnraccrmuseruniversal)->init(dbsMy);
	tblplnramarrayenv = new MyTblPlnrAMArrayEnv();
	((MyTblPlnrAMArrayEnv*) tblplnramarrayenv)->init(dbsMy);
	tblplnramcalcenv = new MyTblPlnrAMCalcEnv();
	((MyTblPlnrAMCalcEnv*) tblplnramcalcenv)->init(dbsMy);
	tblplnramcalcpar = new MyTblPlnrAMCalcPar();
	((MyTblPlnrAMCalcPar*) tblplnramcalcpar)->init(dbsMy);
	tblplnramdevicepar = new MyTblPlnrAMDevicePar();
	((MyTblPlnrAMDevicePar*) tblplnramdevicepar)->init(dbsMy);
	tblplnrammaterialpar = new MyTblPlnrAMMaterialPar();
	((MyTblPlnrAMMaterialPar*) tblplnrammaterialpar)->init(dbsMy);
	tblplnrampersondetail = new MyTblPlnrAMPersonDetail();
	((MyTblPlnrAMPersonDetail*) tblplnrampersondetail)->init(dbsMy);
	tblplnramuseraccess = new MyTblPlnrAMUserAccess();
	((MyTblPlnrAMUserAccess*) tblplnramuseraccess)->init(dbsMy);
	tblplnramusergroupaccess = new MyTblPlnrAMUsergroupAccess();
	((MyTblPlnrAMUsergroupAccess*) tblplnramusergroupaccess)->init(dbsMy);
	tblplnravcontrolpar = new MyTblPlnrAVControlPar();
	((MyTblPlnrAVControlPar*) tblplnravcontrolpar)->init(dbsMy);
	tblplnravkeylistkey = new MyTblPlnrAVKeylistKey();
	((MyTblPlnrAVKeylistKey*) tblplnravkeylistkey)->init(dbsMy);
	tblplnravvaluelistval = new MyTblPlnrAVValuelistVal();
	((MyTblPlnrAVValuelistVal*) tblplnravvaluelistval)->init(dbsMy);
	tblplnrcfile = new MyTblPlnrCFile();
	((MyTblPlnrCFile*) tblplnrcfile)->init(dbsMy);
	tblplnrdevomdevicemarcguide = new MyTblPlnrDevOMDeviceMArcguide();
	((MyTblPlnrDevOMDeviceMArcguide*) tblplnrdevomdevicemarcguide)->init(dbsMy);
	tblplnrdevomdevicemlineguide = new MyTblPlnrDevOMDeviceMLineguide();
	((MyTblPlnrDevOMDeviceMLineguide*) tblplnrdevomdevicemlineguide)->init(dbsMy);
	tblplnrdevomdevicemvertex = new MyTblPlnrDevOMDeviceMVertex();
	((MyTblPlnrDevOMDeviceMVertex*) tblplnrdevomdevicemvertex)->init(dbsMy);
	tblplnrdevormarcguidemvertex = new MyTblPlnrDevORMArcguideMVertex();
	((MyTblPlnrDevORMArcguideMVertex*) tblplnrdevormarcguidemvertex)->init(dbsMy);
	tblplnrdevormlineguidemvertex = new MyTblPlnrDevORMLineguideMVertex();
	((MyTblPlnrDevORMLineguideMVertex*) tblplnrdevormlineguidemvertex)->init(dbsMy);
	tblplnrhistrmuseruniversal = new MyTblPlnrHistRMUserUniversal();
	((MyTblPlnrHistRMUserUniversal*) tblplnrhistrmuseruniversal)->init(dbsMy);
	tblplnrjavkeylistkey = new MyTblPlnrJAVKeylistKey();
	((MyTblPlnrJAVKeylistKey*) tblplnrjavkeylistkey)->init(dbsMy);
	tblplnrjmarcguider = new MyTblPlnrJMArcguideR();
	((MyTblPlnrJMArcguideR*) tblplnrjmarcguider)->init(dbsMy);
	tblplnrjmdevicemodtype = new MyTblPlnrJMDeviceModtype();
	((MyTblPlnrJMDeviceModtype*) tblplnrjmdevicemodtype)->init(dbsMy);
	tblplnrjmdomain = new MyTblPlnrJMDomain();
	((MyTblPlnrJMDomain*) tblplnrjmdomain)->init(dbsMy);
	tblplnrjmdomaingd = new MyTblPlnrJMDomaingd();
	((MyTblPlnrJMDomaingd*) tblplnrjmdomaingd)->init(dbsMy);
	tblplnrjmlayer = new MyTblPlnrJMLayer();
	((MyTblPlnrJMLayer*) tblplnrjmlayer)->init(dbsMy);
	tblplnrjmlayermaterial = new MyTblPlnrJMLayerMaterial();
	((MyTblPlnrJMLayerMaterial*) tblplnrjmlayermaterial)->init(dbsMy);
	tblplnrjmlevelz = new MyTblPlnrJMLevelZ();
	((MyTblPlnrJMLevelZ*) tblplnrjmlevelz)->init(dbsMy);
	tblplnrjmpersonlastname = new MyTblPlnrJMPersonLastname();
	((MyTblPlnrJMPersonLastname*) tblplnrjmpersonlastname)->init(dbsMy);
	tblplnrjmprojectstate = new MyTblPlnrJMProjectState();
	((MyTblPlnrJMProjectState*) tblplnrjmprojectstate)->init(dbsMy);
	tblplnrjmstackmodtype = new MyTblPlnrJMStackModtype();
	((MyTblPlnrJMStackModtype*) tblplnrjmstackmodtype)->init(dbsMy);
	tblplnrjmstackn = new MyTblPlnrJMStackN();
	((MyTblPlnrJMStackN*) tblplnrjmstackn)->init(dbsMy);
	tblplnrjmtapeoutstate = new MyTblPlnrJMTapeoutState();
	((MyTblPlnrJMTapeoutState*) tblplnrjmtapeoutstate)->init(dbsMy);
	tblplnrjmuserstate = new MyTblPlnrJMUserState();
	((MyTblPlnrJMUserState*) tblplnrjmuserstate)->init(dbsMy);
	tblplnrjmvertex = new MyTblPlnrJMVertex();
	((MyTblPlnrJMVertex*) tblplnrjmvertex)->init(dbsMy);
	tblplnrlrmarcguidemvertex = new MyTblPlnrLRMArcguideMVertex();
	((MyTblPlnrLRMArcguideMVertex*) tblplnrlrmarcguidemvertex)->init(dbsMy);
	tblplnrlrmlineguidemvertex = new MyTblPlnrLRMLineguideMVertex();
	((MyTblPlnrLRMLineguideMVertex*) tblplnrlrmlineguidemvertex)->init(dbsMy);
	tblplnrmarcguide = new MyTblPlnrMArcguide();
	((MyTblPlnrMArcguide*) tblplnrmarcguide)->init(dbsMy);
	tblplnrmarray = new MyTblPlnrMArray();
	((MyTblPlnrMArray*) tblplnrmarray)->init(dbsMy);
	tblplnrmarrayitem = new MyTblPlnrMArrayitem();
	((MyTblPlnrMArrayitem*) tblplnrmarrayitem)->init(dbsMy);
	tblplnrmblock = new MyTblPlnrMBlock();
	((MyTblPlnrMBlock*) tblplnrmblock)->init(dbsMy);
	tblplnrmcalc = new MyTblPlnrMCalc();
	((MyTblPlnrMCalc*) tblplnrmcalc)->init(dbsMy);
	tblplnrmcalcitem = new MyTblPlnrMCalcitem();
	((MyTblPlnrMCalcitem*) tblplnrmcalcitem)->init(dbsMy);
	tblplnrmdesign = new MyTblPlnrMDesign();
	((MyTblPlnrMDesign*) tblplnrmdesign)->init(dbsMy);
	tblplnrmdevice = new MyTblPlnrMDevice();
	((MyTblPlnrMDevice*) tblplnrmdevice)->init(dbsMy);
	tblplnrmdomain = new MyTblPlnrMDomain();
	((MyTblPlnrMDomain*) tblplnrmdomain)->init(dbsMy);
	tblplnrmdomaingd = new MyTblPlnrMDomaingd();
	((MyTblPlnrMDomaingd*) tblplnrmdomaingd)->init(dbsMy);
	tblplnrmface = new MyTblPlnrMFace();
	((MyTblPlnrMFace*) tblplnrmface)->init(dbsMy);
	tblplnrmfile = new MyTblPlnrMFile();
	((MyTblPlnrMFile*) tblplnrmfile)->init(dbsMy);
	tblplnrmlayer = new MyTblPlnrMLayer();
	((MyTblPlnrMLayer*) tblplnrmlayer)->init(dbsMy);
	tblplnrmlevel = new MyTblPlnrMLevel();
	((MyTblPlnrMLevel*) tblplnrmlevel)->init(dbsMy);
	tblplnrmlineguide = new MyTblPlnrMLineguide();
	((MyTblPlnrMLineguide*) tblplnrmlineguide)->init(dbsMy);
	tblplnrmmaterial = new MyTblPlnrMMaterial();
	((MyTblPlnrMMaterial*) tblplnrmmaterial)->init(dbsMy);
	tblplnrmperson = new MyTblPlnrMPerson();
	((MyTblPlnrMPerson*) tblplnrmperson)->init(dbsMy);
	tblplnrmproject = new MyTblPlnrMProject();
	((MyTblPlnrMProject*) tblplnrmproject)->init(dbsMy);
	tblplnrmreticle = new MyTblPlnrMReticle();
	((MyTblPlnrMReticle*) tblplnrmreticle)->init(dbsMy);
	tblplnrmsession = new MyTblPlnrMSession();
	((MyTblPlnrMSession*) tblplnrmsession)->init(dbsMy);
	tblplnrmstack = new MyTblPlnrMStack();
	((MyTblPlnrMStack*) tblplnrmstack)->init(dbsMy);
	tblplnrmstructure = new MyTblPlnrMStructure();
	((MyTblPlnrMStructure*) tblplnrmstructure)->init(dbsMy);
	tblplnrmtapeout = new MyTblPlnrMTapeout();
	((MyTblPlnrMTapeout*) tblplnrmtapeout)->init(dbsMy);
	tblplnrmuser = new MyTblPlnrMUser();
	((MyTblPlnrMUser*) tblplnrmuser)->init(dbsMy);
	tblplnrmusergroup = new MyTblPlnrMUsergroup();
	((MyTblPlnrMUsergroup*) tblplnrmusergroup)->init(dbsMy);
	tblplnrmvertex = new MyTblPlnrMVertex();
	((MyTblPlnrMVertex*) tblplnrmvertex)->init(dbsMy);
	tblplnromstructuremface = new MyTblPlnrOMStructureMFace();
	((MyTblPlnrOMStructureMFace*) tblplnromstructuremface)->init(dbsMy);
	tblplnrrmcalcmdomain = new MyTblPlnrRMCalcMDomain();
	((MyTblPlnrRMCalcMDomain*) tblplnrrmcalcmdomain)->init(dbsMy);
	tblplnrrmcalcmfile = new MyTblPlnrRMCalcMFile();
	((MyTblPlnrRMCalcMFile*) tblplnrrmcalcmfile)->init(dbsMy);
	tblplnrrmfacemvertex = new MyTblPlnrRMFaceMVertex();
	((MyTblPlnrRMFaceMVertex*) tblplnrrmfacemvertex)->init(dbsMy);
	tblplnrrmlayermstructure = new MyTblPlnrRMLayerMStructure();
	((MyTblPlnrRMLayerMStructure*) tblplnrrmlayermstructure)->init(dbsMy);
	tblplnrrmlevelmlevel = new MyTblPlnrRMLevelMLevel();
	((MyTblPlnrRMLevelMLevel*) tblplnrrmlevelmlevel)->init(dbsMy);
	tblplnrrmlineguidemlineguide = new MyTblPlnrRMLineguideMLineguide();
	((MyTblPlnrRMLineguideMLineguide*) tblplnrrmlineguidemlineguide)->init(dbsMy);
	tblplnrrmprojectmtapeout = new MyTblPlnrRMProjectMTapeout();
	((MyTblPlnrRMProjectMTapeout*) tblplnrrmprojectmtapeout)->init(dbsMy);
	tblplnrrmstackmstructure = new MyTblPlnrRMStackMStructure();
	((MyTblPlnrRMStackMStructure*) tblplnrrmstackmstructure)->init(dbsMy);
	tblplnrrmusergroupuniversal = new MyTblPlnrRMUsergroupUniversal();
	((MyTblPlnrRMUsergroupUniversal*) tblplnrrmusergroupuniversal)->init(dbsMy);
	tblplnrrmusermusergroup = new MyTblPlnrRMUserMUsergroup();
	((MyTblPlnrRMUserMUsergroup*) tblplnrrmusermusergroup)->init(dbsMy);
	tblplnrrmvertexmvertex = new MyTblPlnrRMVertexMVertex();
	((MyTblPlnrRMVertexMVertex*) tblplnrrmvertexmvertex)->init(dbsMy);

	tblplnrqariamarrayenv = new MyTblPlnrQAriAMArrayEnv();
	((MyTblPlnrQAriAMArrayEnv*) tblplnrqariamarrayenv)->init(dbsMy);
	tblplnrqarilist = new MyTblPlnrQAriList();
	((MyTblPlnrQAriList*) tblplnrqarilist)->init(dbsMy);
	tblplnrqarr1narrayitem = new MyTblPlnrQArr1NArrayitem();
	((MyTblPlnrQArr1NArrayitem*) tblplnrqarr1narrayitem)->init(dbsMy);
	tblplnrqarraenv = new MyTblPlnrQArrAEnv();
	((MyTblPlnrQArrAEnv*) tblplnrqarraenv)->init(dbsMy);
	tblplnrqarrhk1nreticle = new MyTblPlnrQArrHk1NReticle();
	((MyTblPlnrQArrHk1NReticle*) tblplnrqarrhk1nreticle)->init(dbsMy);
	tblplnrqarrkenvkey = new MyTblPlnrQArrKEnvKey();
	((MyTblPlnrQArrKEnvKey*) tblplnrqarrkenvkey)->init(dbsMy);
	tblplnrqarrlist = new MyTblPlnrQArrList();
	((MyTblPlnrQArrList*) tblplnrqarrlist)->init(dbsMy);
	tblplnrqclc1nmaterial = new MyTblPlnrQClc1NMaterial();
	((MyTblPlnrQClc1NMaterial*) tblplnrqclc1nmaterial)->init(dbsMy);
	tblplnrqclcaenv = new MyTblPlnrQClcAEnv();
	((MyTblPlnrQClcAEnv*) tblplnrqclcaenv)->init(dbsMy);
	tblplnrqclcapar = new MyTblPlnrQClcAPar();
	((MyTblPlnrQClcAPar*) tblplnrqclcapar)->init(dbsMy);
	tblplnrqclccal1ncalcitem = new MyTblPlnrQClcCal1NCalcitem();
	((MyTblPlnrQClcCal1NCalcitem*) tblplnrqclccal1ncalcitem)->init(dbsMy);
	tblplnrqclclist = new MyTblPlnrQClcList();
	((MyTblPlnrQClcList*) tblplnrqclclist)->init(dbsMy);
	tblplnrqclcmndomain = new MyTblPlnrQClcMNDomain();
	((MyTblPlnrQClcMNDomain*) tblplnrqclcmndomain)->init(dbsMy);
	tblplnrqclcmnfile = new MyTblPlnrQClcMNFile();
	((MyTblPlnrQClcMNFile*) tblplnrqclcmnfile)->init(dbsMy);
	tblplnrqclcref1nfile = new MyTblPlnrQClcRef1NFile();
	((MyTblPlnrQClcRef1NFile*) tblplnrqclcref1nfile)->init(dbsMy);
	tblplnrqclcsup1ncalc = new MyTblPlnrQClcSup1NCalc();
	((MyTblPlnrQClcSup1NCalc*) tblplnrqclcsup1ncalc)->init(dbsMy);
	tblplnrqcliaamcalcenv = new MyTblPlnrQCliAAMCalcEnv();
	((MyTblPlnrQCliAAMCalcEnv*) tblplnrqcliaamcalcenv)->init(dbsMy);
	tblplnrqcliaamcalcpar = new MyTblPlnrQCliAAMCalcPar();
	((MyTblPlnrQCliAAMCalcPar*) tblplnrqcliaamcalcpar)->init(dbsMy);
	tblplnrqclilist = new MyTblPlnrQCliList();
	((MyTblPlnrQCliList*) tblplnrqclilist)->init(dbsMy);
	tblplnrqcliref1nfile = new MyTblPlnrQCliRef1NFile();
	((MyTblPlnrQCliRef1NFile*) tblplnrqcliref1nfile)->init(dbsMy);
	tblplnrqctpaenv = new MyTblPlnrQCtpAEnv();
	((MyTblPlnrQCtpAEnv*) tblplnrqctpaenv)->init(dbsMy);
	tblplnrqctpapar = new MyTblPlnrQCtpAPar();
	((MyTblPlnrQCtpAPar*) tblplnrqctpapar)->init(dbsMy);
	tblplnrqctpkcalcdomprp = new MyTblPlnrQCtpKCalcdomprp();
	((MyTblPlnrQCtpKCalcdomprp*) tblplnrqctpkcalcdomprp)->init(dbsMy);
	tblplnrqctpkcalcvar = new MyTblPlnrQCtpKCalcvar();
	((MyTblPlnrQCtpKCalcvar*) tblplnrqctpkcalcvar)->init(dbsMy);
	tblplnrqctpkenvkey = new MyTblPlnrQCtpKEnvKey();
	((MyTblPlnrQCtpKEnvKey*) tblplnrqctpkenvkey)->init(dbsMy);
	tblplnrqctpkparcat = new MyTblPlnrQCtpKParCat();
	((MyTblPlnrQCtpKParCat*) tblplnrqctpkparcat)->init(dbsMy);
	tblplnrqctpkparprop = new MyTblPlnrQCtpKParProp();
	((MyTblPlnrQCtpKParProp*) tblplnrqctpkparprop)->init(dbsMy);
	tblplnrqctplist = new MyTblPlnrQCtpList();
	((MyTblPlnrQCtpList*) tblplnrqctplist)->init(dbsMy);
	tblplnrqctpref1nfile = new MyTblPlnrQCtpRef1NFile();
	((MyTblPlnrQCtpRef1NFile*) tblplnrqctpref1nfile)->init(dbsMy);
	tblplnrqctpsup1ncalc = new MyTblPlnrQCtpSup1NCalc();
	((MyTblPlnrQCtpSup1NCalc*) tblplnrqctpsup1ncalc)->init(dbsMy);
	tblplnrqctptpl1ncalc = new MyTblPlnrQCtpTpl1NCalc();
	((MyTblPlnrQCtpTpl1NCalc*) tblplnrqctptpl1ncalc)->init(dbsMy);
	tblplnrqdgdlist = new MyTblPlnrQDgdList();
	((MyTblPlnrQDgdList*) tblplnrqdgdlist)->init(dbsMy);
	tblplnrqdomlist = new MyTblPlnrQDomList();
	((MyTblPlnrQDomList*) tblplnrqdomlist)->init(dbsMy);
	tblplnrqdommncalc = new MyTblPlnrQDomMNCalc();
	((MyTblPlnrQDomMNCalc*) tblplnrqdommncalc)->init(dbsMy);
	tblplnrqdsn1nblock = new MyTblPlnrQDsn1NBlock();
	((MyTblPlnrQDsn1NBlock*) tblplnrqdsn1nblock)->init(dbsMy);
	tblplnrqdsn1nreticle = new MyTblPlnrQDsn1NReticle();
	((MyTblPlnrQDsn1NReticle*) tblplnrqdsn1nreticle)->init(dbsMy);
	tblplnrqdsndrv1ndesign = new MyTblPlnrQDsnDrv1NDesign();
	((MyTblPlnrQDsnDrv1NDesign*) tblplnrqdsndrv1ndesign)->init(dbsMy);
	tblplnrqdsndsn1ndevice = new MyTblPlnrQDsnDsn1NDevice();
	((MyTblPlnrQDsnDsn1NDevice*) tblplnrqdsndsn1ndevice)->init(dbsMy);
	tblplnrqdsndsn1ndomain = new MyTblPlnrQDsnDsn1NDomain();
	((MyTblPlnrQDsnDsn1NDomain*) tblplnrqdsndsn1ndomain)->init(dbsMy);
	tblplnrqdsndsn1ndomaingd = new MyTblPlnrQDsnDsn1NDomaingd();
	((MyTblPlnrQDsnDsn1NDomaingd*) tblplnrqdsndsn1ndomaingd)->init(dbsMy);
	tblplnrqdsndsn1nstack = new MyTblPlnrQDsnDsn1NStack();
	((MyTblPlnrQDsnDsn1NStack*) tblplnrqdsndsn1nstack)->init(dbsMy);
	tblplnrqdsnhk1narcguide = new MyTblPlnrQDsnHk1NArcguide();
	((MyTblPlnrQDsnHk1NArcguide*) tblplnrqdsnhk1narcguide)->init(dbsMy);
	tblplnrqdsnhk1nlayer = new MyTblPlnrQDsnHk1NLayer();
	((MyTblPlnrQDsnHk1NLayer*) tblplnrqdsnhk1nlayer)->init(dbsMy);
	tblplnrqdsnhk1nlevel = new MyTblPlnrQDsnHk1NLevel();
	((MyTblPlnrQDsnHk1NLevel*) tblplnrqdsnhk1nlevel)->init(dbsMy);
	tblplnrqdsnhk1nlineguide = new MyTblPlnrQDsnHk1NLineguide();
	((MyTblPlnrQDsnHk1NLineguide*) tblplnrqdsnhk1nlineguide)->init(dbsMy);
	tblplnrqdsnhk1nstructure = new MyTblPlnrQDsnHk1NStructure();
	((MyTblPlnrQDsnHk1NStructure*) tblplnrqdsnhk1nstructure)->init(dbsMy);
	tblplnrqdsnhk1nvertex = new MyTblPlnrQDsnHk1NVertex();
	((MyTblPlnrQDsnHk1NVertex*) tblplnrqdsnhk1nvertex)->init(dbsMy);
	tblplnrqdsnlist = new MyTblPlnrQDsnList();
	((MyTblPlnrQDsnList*) tblplnrqdsnlist)->init(dbsMy);
	tblplnrqdsnmod1ndesign = new MyTblPlnrQDsnMod1NDesign();
	((MyTblPlnrQDsnMod1NDesign*) tblplnrqdsnmod1ndesign)->init(dbsMy);
	tblplnrqdtpapar = new MyTblPlnrQDtpAPar();
	((MyTblPlnrQDtpAPar*) tblplnrqdtpapar)->init(dbsMy);
	tblplnrqdtphk1nstructure = new MyTblPlnrQDtpHk1NStructure();
	((MyTblPlnrQDtpHk1NStructure*) tblplnrqdtphk1nstructure)->init(dbsMy);
	tblplnrqdtpkparkey = new MyTblPlnrQDtpKParKey();
	((MyTblPlnrQDtpKParKey*) tblplnrqdtpkparkey)->init(dbsMy);
	tblplnrqdtplist = new MyTblPlnrQDtpList();
	((MyTblPlnrQDtpList*) tblplnrqdtplist)->init(dbsMy);
	tblplnrqdtpsup1ndevice = new MyTblPlnrQDtpSup1NDevice();
	((MyTblPlnrQDtpSup1NDevice*) tblplnrqdtpsup1ndevice)->init(dbsMy);
	tblplnrqdtptpl1ndevice = new MyTblPlnrQDtpTpl1NDevice();
	((MyTblPlnrQDtpTpl1NDevice*) tblplnrqdtptpl1ndevice)->init(dbsMy);
	tblplnrqdvcapar = new MyTblPlnrQDvcAPar();
	((MyTblPlnrQDvcAPar*) tblplnrqdvcapar)->init(dbsMy);
	tblplnrqdvchk1narcguide = new MyTblPlnrQDvcHk1NArcguide();
	((MyTblPlnrQDvcHk1NArcguide*) tblplnrqdvchk1narcguide)->init(dbsMy);
	tblplnrqdvchk1nlineguide = new MyTblPlnrQDvcHk1NLineguide();
	((MyTblPlnrQDvcHk1NLineguide*) tblplnrqdvchk1nlineguide)->init(dbsMy);
	tblplnrqdvchk1nstructure = new MyTblPlnrQDvcHk1NStructure();
	((MyTblPlnrQDvcHk1NStructure*) tblplnrqdvchk1nstructure)->init(dbsMy);
	tblplnrqdvchk1nvertex = new MyTblPlnrQDvcHk1NVertex();
	((MyTblPlnrQDvcHk1NVertex*) tblplnrqdvchk1nvertex)->init(dbsMy);
	tblplnrqdvclist = new MyTblPlnrQDvcList();
	((MyTblPlnrQDvcList*) tblplnrqdvclist)->init(dbsMy);
	tblplnrqdvcsup1ndevice = new MyTblPlnrQDvcSup1NDevice();
	((MyTblPlnrQDvcSup1NDevice*) tblplnrqdvcsup1ndevice)->init(dbsMy);
	tblplnrqfillist = new MyTblPlnrQFilList();
	((MyTblPlnrQFilList*) tblplnrqfillist)->init(dbsMy);
	tblplnrqfilmncalc = new MyTblPlnrQFilMNCalc();
	((MyTblPlnrQFilMNCalc*) tblplnrqfilmncalc)->init(dbsMy);
	tblplnrqlyr1nblock = new MyTblPlnrQLyr1NBlock();
	((MyTblPlnrQLyr1NBlock*) tblplnrqlyr1nblock)->init(dbsMy);
	tblplnrqlyr1nreticle = new MyTblPlnrQLyr1NReticle();
	((MyTblPlnrQLyr1NReticle*) tblplnrqlyr1nreticle)->init(dbsMy);
	tblplnrqlyrlist = new MyTblPlnrQLyrList();
	((MyTblPlnrQLyrList*) tblplnrqlyrlist)->init(dbsMy);
	tblplnrqlyrmnstructure = new MyTblPlnrQLyrMNStructure();
	((MyTblPlnrQLyrMNStructure*) tblplnrqlyrmnstructure)->init(dbsMy);
	tblplnrqmat1nlayer = new MyTblPlnrQMat1NLayer();
	((MyTblPlnrQMat1NLayer*) tblplnrqmat1nlayer)->init(dbsMy);
	tblplnrqmatapar = new MyTblPlnrQMatAPar();
	((MyTblPlnrQMatAPar*) tblplnrqmatapar)->init(dbsMy);
	tblplnrqmatlist = new MyTblPlnrQMatList();
	((MyTblPlnrQMatList*) tblplnrqmatlist)->init(dbsMy);
	tblplnrqmatmod1nmaterial = new MyTblPlnrQMatMod1NMaterial();
	((MyTblPlnrQMatMod1NMaterial*) tblplnrqmatmod1nmaterial)->init(dbsMy);
	tblplnrqmatref1nfile = new MyTblPlnrQMatRef1NFile();
	((MyTblPlnrQMatRef1NFile*) tblplnrqmatref1nfile)->init(dbsMy);
	tblplnrqpreselect = new MyTblPlnrQPreselect();
	((MyTblPlnrQPreselect*) tblplnrqpreselect)->init(dbsMy);
	tblplnrqprj1ncalc = new MyTblPlnrQPrj1NCalc();
	((MyTblPlnrQPrj1NCalc*) tblplnrqprj1ncalc)->init(dbsMy);
	tblplnrqprj1ndesign = new MyTblPlnrQPrj1NDesign();
	((MyTblPlnrQPrj1NDesign*) tblplnrqprj1ndesign)->init(dbsMy);
	tblplnrqprjlist = new MyTblPlnrQPrjList();
	((MyTblPlnrQPrjList*) tblplnrqprjlist)->init(dbsMy);
	tblplnrqprjmntapeout = new MyTblPlnrQPrjMNTapeout();
	((MyTblPlnrQPrjMNTapeout*) tblplnrqprjmntapeout)->init(dbsMy);
	tblplnrqprsadetail = new MyTblPlnrQPrsADetail();
	((MyTblPlnrQPrsADetail*) tblplnrqprsadetail)->init(dbsMy);
	tblplnrqprslist = new MyTblPlnrQPrsList();
	((MyTblPlnrQPrsList*) tblplnrqprslist)->init(dbsMy);
	tblplnrqrtclist = new MyTblPlnrQRtcList();
	((MyTblPlnrQRtcList*) tblplnrqrtclist)->init(dbsMy);
	tblplnrqselect = new MyTblPlnrQSelect();
	((MyTblPlnrQSelect*) tblplnrqselect)->init(dbsMy);
	tblplnrqsru1nblock = new MyTblPlnrQSru1NBlock();
	((MyTblPlnrQSru1NBlock*) tblplnrqsru1nblock)->init(dbsMy);
	tblplnrqsrulist = new MyTblPlnrQSruList();
	((MyTblPlnrQSruList*) tblplnrqsrulist)->init(dbsMy);
	tblplnrqsrumnlayer = new MyTblPlnrQSruMNLayer();
	((MyTblPlnrQSruMNLayer*) tblplnrqsrumnlayer)->init(dbsMy);
	tblplnrqsrumnstack = new MyTblPlnrQSruMNStack();
	((MyTblPlnrQSruMNStack*) tblplnrqsrumnstack)->init(dbsMy);
	tblplnrqsrusru1nface = new MyTblPlnrQSruSru1NFace();
	((MyTblPlnrQSruSru1NFace*) tblplnrqsrusru1nface)->init(dbsMy);
	tblplnrqstkhk1nlayer = new MyTblPlnrQStkHk1NLayer();
	((MyTblPlnrQStkHk1NLayer*) tblplnrqstkhk1nlayer)->init(dbsMy);
	tblplnrqstkhk1nlevel = new MyTblPlnrQStkHk1NLevel();
	((MyTblPlnrQStkHk1NLevel*) tblplnrqstkhk1nlevel)->init(dbsMy);
	tblplnrqstklist = new MyTblPlnrQStkList();
	((MyTblPlnrQStkList*) tblplnrqstklist)->init(dbsMy);
	tblplnrqstkmnstructure = new MyTblPlnrQStkMNStructure();
	((MyTblPlnrQStkMNStructure*) tblplnrqstkmnstructure)->init(dbsMy);
	tblplnrqtpo1narray = new MyTblPlnrQTpo1NArray();
	((MyTblPlnrQTpo1NArray*) tblplnrqtpo1narray)->init(dbsMy);
	tblplnrqtpohk1nreticle = new MyTblPlnrQTpoHk1NReticle();
	((MyTblPlnrQTpoHk1NReticle*) tblplnrqtpohk1nreticle)->init(dbsMy);
	tblplnrqtpolist = new MyTblPlnrQTpoList();
	((MyTblPlnrQTpoList*) tblplnrqtpolist)->init(dbsMy);
	tblplnrqtpomnproject = new MyTblPlnrQTpoMNProject();
	((MyTblPlnrQTpoMNProject*) tblplnrqtpomnproject)->init(dbsMy);
	tblplnrqusgaaccess = new MyTblPlnrQUsgAAccess();
	((MyTblPlnrQUsgAAccess*) tblplnrqusgaaccess)->init(dbsMy);
	tblplnrqusglist = new MyTblPlnrQUsgList();
	((MyTblPlnrQUsgList*) tblplnrqusglist)->init(dbsMy);
	tblplnrqusgmnuser = new MyTblPlnrQUsgMNUser();
	((MyTblPlnrQUsgMNUser*) tblplnrqusgmnuser)->init(dbsMy);
	tblplnrqusr1nsession = new MyTblPlnrQUsr1NSession();
	((MyTblPlnrQUsr1NSession*) tblplnrqusr1nsession)->init(dbsMy);
	tblplnrqusraaccess = new MyTblPlnrQUsrAAccess();
	((MyTblPlnrQUsrAAccess*) tblplnrqusraaccess)->init(dbsMy);
	tblplnrqusrlist = new MyTblPlnrQUsrList();
	((MyTblPlnrQUsrList*) tblplnrqusrlist)->init(dbsMy);
	tblplnrqusrmnusergroup = new MyTblPlnrQUsrMNUsergroup();
	((MyTblPlnrQUsrMNUsergroup*) tblplnrqusrmnusergroup)->init(dbsMy);
};

void DbsPlnr::termMy() {
	mysql_close(dbsMy);
	mysql_thread_end();
};
// IP inittermMy --- END

// IP inittermPg --- BEGIN
void DbsPlnr::initPg() {
	// connect to PostgreSQL database
	dbsPg = PQsetdbLogin(ip.c_str(), to_string(port).c_str(), NULL, NULL, dbsname.c_str(), username.c_str(), password.c_str());

	if (PQstatus(dbsPg) == CONNECTION_BAD) throw DbsException("DbsException / PgSQL: connection failure");

	tblplnraccrmuseruniversal = new PgTblPlnrAccRMUserUniversal();
	((PgTblPlnrAccRMUserUniversal*) tblplnraccrmuseruniversal)->init(dbsPg);
	tblplnramarrayenv = new PgTblPlnrAMArrayEnv();
	((PgTblPlnrAMArrayEnv*) tblplnramarrayenv)->init(dbsPg);
	tblplnramcalcenv = new PgTblPlnrAMCalcEnv();
	((PgTblPlnrAMCalcEnv*) tblplnramcalcenv)->init(dbsPg);
	tblplnramcalcpar = new PgTblPlnrAMCalcPar();
	((PgTblPlnrAMCalcPar*) tblplnramcalcpar)->init(dbsPg);
	tblplnramdevicepar = new PgTblPlnrAMDevicePar();
	((PgTblPlnrAMDevicePar*) tblplnramdevicepar)->init(dbsPg);
	tblplnrammaterialpar = new PgTblPlnrAMMaterialPar();
	((PgTblPlnrAMMaterialPar*) tblplnrammaterialpar)->init(dbsPg);
	tblplnrampersondetail = new PgTblPlnrAMPersonDetail();
	((PgTblPlnrAMPersonDetail*) tblplnrampersondetail)->init(dbsPg);
	tblplnramuseraccess = new PgTblPlnrAMUserAccess();
	((PgTblPlnrAMUserAccess*) tblplnramuseraccess)->init(dbsPg);
	tblplnramusergroupaccess = new PgTblPlnrAMUsergroupAccess();
	((PgTblPlnrAMUsergroupAccess*) tblplnramusergroupaccess)->init(dbsPg);
	tblplnravcontrolpar = new PgTblPlnrAVControlPar();
	((PgTblPlnrAVControlPar*) tblplnravcontrolpar)->init(dbsPg);
	tblplnravkeylistkey = new PgTblPlnrAVKeylistKey();
	((PgTblPlnrAVKeylistKey*) tblplnravkeylistkey)->init(dbsPg);
	tblplnravvaluelistval = new PgTblPlnrAVValuelistVal();
	((PgTblPlnrAVValuelistVal*) tblplnravvaluelistval)->init(dbsPg);
	tblplnrcfile = new PgTblPlnrCFile();
	((PgTblPlnrCFile*) tblplnrcfile)->init(dbsPg);
	tblplnrdevomdevicemarcguide = new PgTblPlnrDevOMDeviceMArcguide();
	((PgTblPlnrDevOMDeviceMArcguide*) tblplnrdevomdevicemarcguide)->init(dbsPg);
	tblplnrdevomdevicemlineguide = new PgTblPlnrDevOMDeviceMLineguide();
	((PgTblPlnrDevOMDeviceMLineguide*) tblplnrdevomdevicemlineguide)->init(dbsPg);
	tblplnrdevomdevicemvertex = new PgTblPlnrDevOMDeviceMVertex();
	((PgTblPlnrDevOMDeviceMVertex*) tblplnrdevomdevicemvertex)->init(dbsPg);
	tblplnrdevormarcguidemvertex = new PgTblPlnrDevORMArcguideMVertex();
	((PgTblPlnrDevORMArcguideMVertex*) tblplnrdevormarcguidemvertex)->init(dbsPg);
	tblplnrdevormlineguidemvertex = new PgTblPlnrDevORMLineguideMVertex();
	((PgTblPlnrDevORMLineguideMVertex*) tblplnrdevormlineguidemvertex)->init(dbsPg);
	tblplnrhistrmuseruniversal = new PgTblPlnrHistRMUserUniversal();
	((PgTblPlnrHistRMUserUniversal*) tblplnrhistrmuseruniversal)->init(dbsPg);
	tblplnrjavkeylistkey = new PgTblPlnrJAVKeylistKey();
	((PgTblPlnrJAVKeylistKey*) tblplnrjavkeylistkey)->init(dbsPg);
	tblplnrjmarcguider = new PgTblPlnrJMArcguideR();
	((PgTblPlnrJMArcguideR*) tblplnrjmarcguider)->init(dbsPg);
	tblplnrjmdevicemodtype = new PgTblPlnrJMDeviceModtype();
	((PgTblPlnrJMDeviceModtype*) tblplnrjmdevicemodtype)->init(dbsPg);
	tblplnrjmdomain = new PgTblPlnrJMDomain();
	((PgTblPlnrJMDomain*) tblplnrjmdomain)->init(dbsPg);
	tblplnrjmdomaingd = new PgTblPlnrJMDomaingd();
	((PgTblPlnrJMDomaingd*) tblplnrjmdomaingd)->init(dbsPg);
	tblplnrjmlayer = new PgTblPlnrJMLayer();
	((PgTblPlnrJMLayer*) tblplnrjmlayer)->init(dbsPg);
	tblplnrjmlayermaterial = new PgTblPlnrJMLayerMaterial();
	((PgTblPlnrJMLayerMaterial*) tblplnrjmlayermaterial)->init(dbsPg);
	tblplnrjmlevelz = new PgTblPlnrJMLevelZ();
	((PgTblPlnrJMLevelZ*) tblplnrjmlevelz)->init(dbsPg);
	tblplnrjmpersonlastname = new PgTblPlnrJMPersonLastname();
	((PgTblPlnrJMPersonLastname*) tblplnrjmpersonlastname)->init(dbsPg);
	tblplnrjmprojectstate = new PgTblPlnrJMProjectState();
	((PgTblPlnrJMProjectState*) tblplnrjmprojectstate)->init(dbsPg);
	tblplnrjmstackmodtype = new PgTblPlnrJMStackModtype();
	((PgTblPlnrJMStackModtype*) tblplnrjmstackmodtype)->init(dbsPg);
	tblplnrjmstackn = new PgTblPlnrJMStackN();
	((PgTblPlnrJMStackN*) tblplnrjmstackn)->init(dbsPg);
	tblplnrjmtapeoutstate = new PgTblPlnrJMTapeoutState();
	((PgTblPlnrJMTapeoutState*) tblplnrjmtapeoutstate)->init(dbsPg);
	tblplnrjmuserstate = new PgTblPlnrJMUserState();
	((PgTblPlnrJMUserState*) tblplnrjmuserstate)->init(dbsPg);
	tblplnrjmvertex = new PgTblPlnrJMVertex();
	((PgTblPlnrJMVertex*) tblplnrjmvertex)->init(dbsPg);
	tblplnrlrmarcguidemvertex = new PgTblPlnrLRMArcguideMVertex();
	((PgTblPlnrLRMArcguideMVertex*) tblplnrlrmarcguidemvertex)->init(dbsPg);
	tblplnrlrmlineguidemvertex = new PgTblPlnrLRMLineguideMVertex();
	((PgTblPlnrLRMLineguideMVertex*) tblplnrlrmlineguidemvertex)->init(dbsPg);
	tblplnrmarcguide = new PgTblPlnrMArcguide();
	((PgTblPlnrMArcguide*) tblplnrmarcguide)->init(dbsPg);
	tblplnrmarray = new PgTblPlnrMArray();
	((PgTblPlnrMArray*) tblplnrmarray)->init(dbsPg);
	tblplnrmarrayitem = new PgTblPlnrMArrayitem();
	((PgTblPlnrMArrayitem*) tblplnrmarrayitem)->init(dbsPg);
	tblplnrmblock = new PgTblPlnrMBlock();
	((PgTblPlnrMBlock*) tblplnrmblock)->init(dbsPg);
	tblplnrmcalc = new PgTblPlnrMCalc();
	((PgTblPlnrMCalc*) tblplnrmcalc)->init(dbsPg);
	tblplnrmcalcitem = new PgTblPlnrMCalcitem();
	((PgTblPlnrMCalcitem*) tblplnrmcalcitem)->init(dbsPg);
	tblplnrmdesign = new PgTblPlnrMDesign();
	((PgTblPlnrMDesign*) tblplnrmdesign)->init(dbsPg);
	tblplnrmdevice = new PgTblPlnrMDevice();
	((PgTblPlnrMDevice*) tblplnrmdevice)->init(dbsPg);
	tblplnrmdomain = new PgTblPlnrMDomain();
	((PgTblPlnrMDomain*) tblplnrmdomain)->init(dbsPg);
	tblplnrmdomaingd = new PgTblPlnrMDomaingd();
	((PgTblPlnrMDomaingd*) tblplnrmdomaingd)->init(dbsPg);
	tblplnrmface = new PgTblPlnrMFace();
	((PgTblPlnrMFace*) tblplnrmface)->init(dbsPg);
	tblplnrmfile = new PgTblPlnrMFile();
	((PgTblPlnrMFile*) tblplnrmfile)->init(dbsPg);
	tblplnrmlayer = new PgTblPlnrMLayer();
	((PgTblPlnrMLayer*) tblplnrmlayer)->init(dbsPg);
	tblplnrmlevel = new PgTblPlnrMLevel();
	((PgTblPlnrMLevel*) tblplnrmlevel)->init(dbsPg);
	tblplnrmlineguide = new PgTblPlnrMLineguide();
	((PgTblPlnrMLineguide*) tblplnrmlineguide)->init(dbsPg);
	tblplnrmmaterial = new PgTblPlnrMMaterial();
	((PgTblPlnrMMaterial*) tblplnrmmaterial)->init(dbsPg);
	tblplnrmperson = new PgTblPlnrMPerson();
	((PgTblPlnrMPerson*) tblplnrmperson)->init(dbsPg);
	tblplnrmproject = new PgTblPlnrMProject();
	((PgTblPlnrMProject*) tblplnrmproject)->init(dbsPg);
	tblplnrmreticle = new PgTblPlnrMReticle();
	((PgTblPlnrMReticle*) tblplnrmreticle)->init(dbsPg);
	tblplnrmsession = new PgTblPlnrMSession();
	((PgTblPlnrMSession*) tblplnrmsession)->init(dbsPg);
	tblplnrmstack = new PgTblPlnrMStack();
	((PgTblPlnrMStack*) tblplnrmstack)->init(dbsPg);
	tblplnrmstructure = new PgTblPlnrMStructure();
	((PgTblPlnrMStructure*) tblplnrmstructure)->init(dbsPg);
	tblplnrmtapeout = new PgTblPlnrMTapeout();
	((PgTblPlnrMTapeout*) tblplnrmtapeout)->init(dbsPg);
	tblplnrmuser = new PgTblPlnrMUser();
	((PgTblPlnrMUser*) tblplnrmuser)->init(dbsPg);
	tblplnrmusergroup = new PgTblPlnrMUsergroup();
	((PgTblPlnrMUsergroup*) tblplnrmusergroup)->init(dbsPg);
	tblplnrmvertex = new PgTblPlnrMVertex();
	((PgTblPlnrMVertex*) tblplnrmvertex)->init(dbsPg);
	tblplnromstructuremface = new PgTblPlnrOMStructureMFace();
	((PgTblPlnrOMStructureMFace*) tblplnromstructuremface)->init(dbsPg);
	tblplnrrmcalcmdomain = new PgTblPlnrRMCalcMDomain();
	((PgTblPlnrRMCalcMDomain*) tblplnrrmcalcmdomain)->init(dbsPg);
	tblplnrrmcalcmfile = new PgTblPlnrRMCalcMFile();
	((PgTblPlnrRMCalcMFile*) tblplnrrmcalcmfile)->init(dbsPg);
	tblplnrrmfacemvertex = new PgTblPlnrRMFaceMVertex();
	((PgTblPlnrRMFaceMVertex*) tblplnrrmfacemvertex)->init(dbsPg);
	tblplnrrmlayermstructure = new PgTblPlnrRMLayerMStructure();
	((PgTblPlnrRMLayerMStructure*) tblplnrrmlayermstructure)->init(dbsPg);
	tblplnrrmlevelmlevel = new PgTblPlnrRMLevelMLevel();
	((PgTblPlnrRMLevelMLevel*) tblplnrrmlevelmlevel)->init(dbsPg);
	tblplnrrmlineguidemlineguide = new PgTblPlnrRMLineguideMLineguide();
	((PgTblPlnrRMLineguideMLineguide*) tblplnrrmlineguidemlineguide)->init(dbsPg);
	tblplnrrmprojectmtapeout = new PgTblPlnrRMProjectMTapeout();
	((PgTblPlnrRMProjectMTapeout*) tblplnrrmprojectmtapeout)->init(dbsPg);
	tblplnrrmstackmstructure = new PgTblPlnrRMStackMStructure();
	((PgTblPlnrRMStackMStructure*) tblplnrrmstackmstructure)->init(dbsPg);
	tblplnrrmusergroupuniversal = new PgTblPlnrRMUsergroupUniversal();
	((PgTblPlnrRMUsergroupUniversal*) tblplnrrmusergroupuniversal)->init(dbsPg);
	tblplnrrmusermusergroup = new PgTblPlnrRMUserMUsergroup();
	((PgTblPlnrRMUserMUsergroup*) tblplnrrmusermusergroup)->init(dbsPg);
	tblplnrrmvertexmvertex = new PgTblPlnrRMVertexMVertex();
	((PgTblPlnrRMVertexMVertex*) tblplnrrmvertexmvertex)->init(dbsPg);

	tblplnrqariamarrayenv = new PgTblPlnrQAriAMArrayEnv();
	((PgTblPlnrQAriAMArrayEnv*) tblplnrqariamarrayenv)->init(dbsPg);
	tblplnrqarilist = new PgTblPlnrQAriList();
	((PgTblPlnrQAriList*) tblplnrqarilist)->init(dbsPg);
	tblplnrqarr1narrayitem = new PgTblPlnrQArr1NArrayitem();
	((PgTblPlnrQArr1NArrayitem*) tblplnrqarr1narrayitem)->init(dbsPg);
	tblplnrqarraenv = new PgTblPlnrQArrAEnv();
	((PgTblPlnrQArrAEnv*) tblplnrqarraenv)->init(dbsPg);
	tblplnrqarrhk1nreticle = new PgTblPlnrQArrHk1NReticle();
	((PgTblPlnrQArrHk1NReticle*) tblplnrqarrhk1nreticle)->init(dbsPg);
	tblplnrqarrkenvkey = new PgTblPlnrQArrKEnvKey();
	((PgTblPlnrQArrKEnvKey*) tblplnrqarrkenvkey)->init(dbsPg);
	tblplnrqarrlist = new PgTblPlnrQArrList();
	((PgTblPlnrQArrList*) tblplnrqarrlist)->init(dbsPg);
	tblplnrqclc1nmaterial = new PgTblPlnrQClc1NMaterial();
	((PgTblPlnrQClc1NMaterial*) tblplnrqclc1nmaterial)->init(dbsPg);
	tblplnrqclcaenv = new PgTblPlnrQClcAEnv();
	((PgTblPlnrQClcAEnv*) tblplnrqclcaenv)->init(dbsPg);
	tblplnrqclcapar = new PgTblPlnrQClcAPar();
	((PgTblPlnrQClcAPar*) tblplnrqclcapar)->init(dbsPg);
	tblplnrqclccal1ncalcitem = new PgTblPlnrQClcCal1NCalcitem();
	((PgTblPlnrQClcCal1NCalcitem*) tblplnrqclccal1ncalcitem)->init(dbsPg);
	tblplnrqclclist = new PgTblPlnrQClcList();
	((PgTblPlnrQClcList*) tblplnrqclclist)->init(dbsPg);
	tblplnrqclcmndomain = new PgTblPlnrQClcMNDomain();
	((PgTblPlnrQClcMNDomain*) tblplnrqclcmndomain)->init(dbsPg);
	tblplnrqclcmnfile = new PgTblPlnrQClcMNFile();
	((PgTblPlnrQClcMNFile*) tblplnrqclcmnfile)->init(dbsPg);
	tblplnrqclcref1nfile = new PgTblPlnrQClcRef1NFile();
	((PgTblPlnrQClcRef1NFile*) tblplnrqclcref1nfile)->init(dbsPg);
	tblplnrqclcsup1ncalc = new PgTblPlnrQClcSup1NCalc();
	((PgTblPlnrQClcSup1NCalc*) tblplnrqclcsup1ncalc)->init(dbsPg);
	tblplnrqcliaamcalcenv = new PgTblPlnrQCliAAMCalcEnv();
	((PgTblPlnrQCliAAMCalcEnv*) tblplnrqcliaamcalcenv)->init(dbsPg);
	tblplnrqcliaamcalcpar = new PgTblPlnrQCliAAMCalcPar();
	((PgTblPlnrQCliAAMCalcPar*) tblplnrqcliaamcalcpar)->init(dbsPg);
	tblplnrqclilist = new PgTblPlnrQCliList();
	((PgTblPlnrQCliList*) tblplnrqclilist)->init(dbsPg);
	tblplnrqcliref1nfile = new PgTblPlnrQCliRef1NFile();
	((PgTblPlnrQCliRef1NFile*) tblplnrqcliref1nfile)->init(dbsPg);
	tblplnrqctpaenv = new PgTblPlnrQCtpAEnv();
	((PgTblPlnrQCtpAEnv*) tblplnrqctpaenv)->init(dbsPg);
	tblplnrqctpapar = new PgTblPlnrQCtpAPar();
	((PgTblPlnrQCtpAPar*) tblplnrqctpapar)->init(dbsPg);
	tblplnrqctpkcalcdomprp = new PgTblPlnrQCtpKCalcdomprp();
	((PgTblPlnrQCtpKCalcdomprp*) tblplnrqctpkcalcdomprp)->init(dbsPg);
	tblplnrqctpkcalcvar = new PgTblPlnrQCtpKCalcvar();
	((PgTblPlnrQCtpKCalcvar*) tblplnrqctpkcalcvar)->init(dbsPg);
	tblplnrqctpkenvkey = new PgTblPlnrQCtpKEnvKey();
	((PgTblPlnrQCtpKEnvKey*) tblplnrqctpkenvkey)->init(dbsPg);
	tblplnrqctpkparcat = new PgTblPlnrQCtpKParCat();
	((PgTblPlnrQCtpKParCat*) tblplnrqctpkparcat)->init(dbsPg);
	tblplnrqctpkparprop = new PgTblPlnrQCtpKParProp();
	((PgTblPlnrQCtpKParProp*) tblplnrqctpkparprop)->init(dbsPg);
	tblplnrqctplist = new PgTblPlnrQCtpList();
	((PgTblPlnrQCtpList*) tblplnrqctplist)->init(dbsPg);
	tblplnrqctpref1nfile = new PgTblPlnrQCtpRef1NFile();
	((PgTblPlnrQCtpRef1NFile*) tblplnrqctpref1nfile)->init(dbsPg);
	tblplnrqctpsup1ncalc = new PgTblPlnrQCtpSup1NCalc();
	((PgTblPlnrQCtpSup1NCalc*) tblplnrqctpsup1ncalc)->init(dbsPg);
	tblplnrqctptpl1ncalc = new PgTblPlnrQCtpTpl1NCalc();
	((PgTblPlnrQCtpTpl1NCalc*) tblplnrqctptpl1ncalc)->init(dbsPg);
	tblplnrqdgdlist = new PgTblPlnrQDgdList();
	((PgTblPlnrQDgdList*) tblplnrqdgdlist)->init(dbsPg);
	tblplnrqdomlist = new PgTblPlnrQDomList();
	((PgTblPlnrQDomList*) tblplnrqdomlist)->init(dbsPg);
	tblplnrqdommncalc = new PgTblPlnrQDomMNCalc();
	((PgTblPlnrQDomMNCalc*) tblplnrqdommncalc)->init(dbsPg);
	tblplnrqdsn1nblock = new PgTblPlnrQDsn1NBlock();
	((PgTblPlnrQDsn1NBlock*) tblplnrqdsn1nblock)->init(dbsPg);
	tblplnrqdsn1nreticle = new PgTblPlnrQDsn1NReticle();
	((PgTblPlnrQDsn1NReticle*) tblplnrqdsn1nreticle)->init(dbsPg);
	tblplnrqdsndrv1ndesign = new PgTblPlnrQDsnDrv1NDesign();
	((PgTblPlnrQDsnDrv1NDesign*) tblplnrqdsndrv1ndesign)->init(dbsPg);
	tblplnrqdsndsn1ndevice = new PgTblPlnrQDsnDsn1NDevice();
	((PgTblPlnrQDsnDsn1NDevice*) tblplnrqdsndsn1ndevice)->init(dbsPg);
	tblplnrqdsndsn1ndomain = new PgTblPlnrQDsnDsn1NDomain();
	((PgTblPlnrQDsnDsn1NDomain*) tblplnrqdsndsn1ndomain)->init(dbsPg);
	tblplnrqdsndsn1ndomaingd = new PgTblPlnrQDsnDsn1NDomaingd();
	((PgTblPlnrQDsnDsn1NDomaingd*) tblplnrqdsndsn1ndomaingd)->init(dbsPg);
	tblplnrqdsndsn1nstack = new PgTblPlnrQDsnDsn1NStack();
	((PgTblPlnrQDsnDsn1NStack*) tblplnrqdsndsn1nstack)->init(dbsPg);
	tblplnrqdsnhk1narcguide = new PgTblPlnrQDsnHk1NArcguide();
	((PgTblPlnrQDsnHk1NArcguide*) tblplnrqdsnhk1narcguide)->init(dbsPg);
	tblplnrqdsnhk1nlayer = new PgTblPlnrQDsnHk1NLayer();
	((PgTblPlnrQDsnHk1NLayer*) tblplnrqdsnhk1nlayer)->init(dbsPg);
	tblplnrqdsnhk1nlevel = new PgTblPlnrQDsnHk1NLevel();
	((PgTblPlnrQDsnHk1NLevel*) tblplnrqdsnhk1nlevel)->init(dbsPg);
	tblplnrqdsnhk1nlineguide = new PgTblPlnrQDsnHk1NLineguide();
	((PgTblPlnrQDsnHk1NLineguide*) tblplnrqdsnhk1nlineguide)->init(dbsPg);
	tblplnrqdsnhk1nstructure = new PgTblPlnrQDsnHk1NStructure();
	((PgTblPlnrQDsnHk1NStructure*) tblplnrqdsnhk1nstructure)->init(dbsPg);
	tblplnrqdsnhk1nvertex = new PgTblPlnrQDsnHk1NVertex();
	((PgTblPlnrQDsnHk1NVertex*) tblplnrqdsnhk1nvertex)->init(dbsPg);
	tblplnrqdsnlist = new PgTblPlnrQDsnList();
	((PgTblPlnrQDsnList*) tblplnrqdsnlist)->init(dbsPg);
	tblplnrqdsnmod1ndesign = new PgTblPlnrQDsnMod1NDesign();
	((PgTblPlnrQDsnMod1NDesign*) tblplnrqdsnmod1ndesign)->init(dbsPg);
	tblplnrqdtpapar = new PgTblPlnrQDtpAPar();
	((PgTblPlnrQDtpAPar*) tblplnrqdtpapar)->init(dbsPg);
	tblplnrqdtphk1nstructure = new PgTblPlnrQDtpHk1NStructure();
	((PgTblPlnrQDtpHk1NStructure*) tblplnrqdtphk1nstructure)->init(dbsPg);
	tblplnrqdtpkparkey = new PgTblPlnrQDtpKParKey();
	((PgTblPlnrQDtpKParKey*) tblplnrqdtpkparkey)->init(dbsPg);
	tblplnrqdtplist = new PgTblPlnrQDtpList();
	((PgTblPlnrQDtpList*) tblplnrqdtplist)->init(dbsPg);
	tblplnrqdtpsup1ndevice = new PgTblPlnrQDtpSup1NDevice();
	((PgTblPlnrQDtpSup1NDevice*) tblplnrqdtpsup1ndevice)->init(dbsPg);
	tblplnrqdtptpl1ndevice = new PgTblPlnrQDtpTpl1NDevice();
	((PgTblPlnrQDtpTpl1NDevice*) tblplnrqdtptpl1ndevice)->init(dbsPg);
	tblplnrqdvcapar = new PgTblPlnrQDvcAPar();
	((PgTblPlnrQDvcAPar*) tblplnrqdvcapar)->init(dbsPg);
	tblplnrqdvchk1narcguide = new PgTblPlnrQDvcHk1NArcguide();
	((PgTblPlnrQDvcHk1NArcguide*) tblplnrqdvchk1narcguide)->init(dbsPg);
	tblplnrqdvchk1nlineguide = new PgTblPlnrQDvcHk1NLineguide();
	((PgTblPlnrQDvcHk1NLineguide*) tblplnrqdvchk1nlineguide)->init(dbsPg);
	tblplnrqdvchk1nstructure = new PgTblPlnrQDvcHk1NStructure();
	((PgTblPlnrQDvcHk1NStructure*) tblplnrqdvchk1nstructure)->init(dbsPg);
	tblplnrqdvchk1nvertex = new PgTblPlnrQDvcHk1NVertex();
	((PgTblPlnrQDvcHk1NVertex*) tblplnrqdvchk1nvertex)->init(dbsPg);
	tblplnrqdvclist = new PgTblPlnrQDvcList();
	((PgTblPlnrQDvcList*) tblplnrqdvclist)->init(dbsPg);
	tblplnrqdvcsup1ndevice = new PgTblPlnrQDvcSup1NDevice();
	((PgTblPlnrQDvcSup1NDevice*) tblplnrqdvcsup1ndevice)->init(dbsPg);
	tblplnrqfillist = new PgTblPlnrQFilList();
	((PgTblPlnrQFilList*) tblplnrqfillist)->init(dbsPg);
	tblplnrqfilmncalc = new PgTblPlnrQFilMNCalc();
	((PgTblPlnrQFilMNCalc*) tblplnrqfilmncalc)->init(dbsPg);
	tblplnrqlyr1nblock = new PgTblPlnrQLyr1NBlock();
	((PgTblPlnrQLyr1NBlock*) tblplnrqlyr1nblock)->init(dbsPg);
	tblplnrqlyr1nreticle = new PgTblPlnrQLyr1NReticle();
	((PgTblPlnrQLyr1NReticle*) tblplnrqlyr1nreticle)->init(dbsPg);
	tblplnrqlyrlist = new PgTblPlnrQLyrList();
	((PgTblPlnrQLyrList*) tblplnrqlyrlist)->init(dbsPg);
	tblplnrqlyrmnstructure = new PgTblPlnrQLyrMNStructure();
	((PgTblPlnrQLyrMNStructure*) tblplnrqlyrmnstructure)->init(dbsPg);
	tblplnrqmat1nlayer = new PgTblPlnrQMat1NLayer();
	((PgTblPlnrQMat1NLayer*) tblplnrqmat1nlayer)->init(dbsPg);
	tblplnrqmatapar = new PgTblPlnrQMatAPar();
	((PgTblPlnrQMatAPar*) tblplnrqmatapar)->init(dbsPg);
	tblplnrqmatlist = new PgTblPlnrQMatList();
	((PgTblPlnrQMatList*) tblplnrqmatlist)->init(dbsPg);
	tblplnrqmatmod1nmaterial = new PgTblPlnrQMatMod1NMaterial();
	((PgTblPlnrQMatMod1NMaterial*) tblplnrqmatmod1nmaterial)->init(dbsPg);
	tblplnrqmatref1nfile = new PgTblPlnrQMatRef1NFile();
	((PgTblPlnrQMatRef1NFile*) tblplnrqmatref1nfile)->init(dbsPg);
	tblplnrqpreselect = new PgTblPlnrQPreselect();
	((PgTblPlnrQPreselect*) tblplnrqpreselect)->init(dbsPg);
	tblplnrqprj1ncalc = new PgTblPlnrQPrj1NCalc();
	((PgTblPlnrQPrj1NCalc*) tblplnrqprj1ncalc)->init(dbsPg);
	tblplnrqprj1ndesign = new PgTblPlnrQPrj1NDesign();
	((PgTblPlnrQPrj1NDesign*) tblplnrqprj1ndesign)->init(dbsPg);
	tblplnrqprjlist = new PgTblPlnrQPrjList();
	((PgTblPlnrQPrjList*) tblplnrqprjlist)->init(dbsPg);
	tblplnrqprjmntapeout = new PgTblPlnrQPrjMNTapeout();
	((PgTblPlnrQPrjMNTapeout*) tblplnrqprjmntapeout)->init(dbsPg);
	tblplnrqprsadetail = new PgTblPlnrQPrsADetail();
	((PgTblPlnrQPrsADetail*) tblplnrqprsadetail)->init(dbsPg);
	tblplnrqprslist = new PgTblPlnrQPrsList();
	((PgTblPlnrQPrsList*) tblplnrqprslist)->init(dbsPg);
	tblplnrqrtclist = new PgTblPlnrQRtcList();
	((PgTblPlnrQRtcList*) tblplnrqrtclist)->init(dbsPg);
	tblplnrqselect = new PgTblPlnrQSelect();
	((PgTblPlnrQSelect*) tblplnrqselect)->init(dbsPg);
	tblplnrqsru1nblock = new PgTblPlnrQSru1NBlock();
	((PgTblPlnrQSru1NBlock*) tblplnrqsru1nblock)->init(dbsPg);
	tblplnrqsrulist = new PgTblPlnrQSruList();
	((PgTblPlnrQSruList*) tblplnrqsrulist)->init(dbsPg);
	tblplnrqsrumnlayer = new PgTblPlnrQSruMNLayer();
	((PgTblPlnrQSruMNLayer*) tblplnrqsrumnlayer)->init(dbsPg);
	tblplnrqsrumnstack = new PgTblPlnrQSruMNStack();
	((PgTblPlnrQSruMNStack*) tblplnrqsrumnstack)->init(dbsPg);
	tblplnrqsrusru1nface = new PgTblPlnrQSruSru1NFace();
	((PgTblPlnrQSruSru1NFace*) tblplnrqsrusru1nface)->init(dbsPg);
	tblplnrqstkhk1nlayer = new PgTblPlnrQStkHk1NLayer();
	((PgTblPlnrQStkHk1NLayer*) tblplnrqstkhk1nlayer)->init(dbsPg);
	tblplnrqstkhk1nlevel = new PgTblPlnrQStkHk1NLevel();
	((PgTblPlnrQStkHk1NLevel*) tblplnrqstkhk1nlevel)->init(dbsPg);
	tblplnrqstklist = new PgTblPlnrQStkList();
	((PgTblPlnrQStkList*) tblplnrqstklist)->init(dbsPg);
	tblplnrqstkmnstructure = new PgTblPlnrQStkMNStructure();
	((PgTblPlnrQStkMNStructure*) tblplnrqstkmnstructure)->init(dbsPg);
	tblplnrqtpo1narray = new PgTblPlnrQTpo1NArray();
	((PgTblPlnrQTpo1NArray*) tblplnrqtpo1narray)->init(dbsPg);
	tblplnrqtpohk1nreticle = new PgTblPlnrQTpoHk1NReticle();
	((PgTblPlnrQTpoHk1NReticle*) tblplnrqtpohk1nreticle)->init(dbsPg);
	tblplnrqtpolist = new PgTblPlnrQTpoList();
	((PgTblPlnrQTpoList*) tblplnrqtpolist)->init(dbsPg);
	tblplnrqtpomnproject = new PgTblPlnrQTpoMNProject();
	((PgTblPlnrQTpoMNProject*) tblplnrqtpomnproject)->init(dbsPg);
	tblplnrqusgaaccess = new PgTblPlnrQUsgAAccess();
	((PgTblPlnrQUsgAAccess*) tblplnrqusgaaccess)->init(dbsPg);
	tblplnrqusglist = new PgTblPlnrQUsgList();
	((PgTblPlnrQUsgList*) tblplnrqusglist)->init(dbsPg);
	tblplnrqusgmnuser = new PgTblPlnrQUsgMNUser();
	((PgTblPlnrQUsgMNUser*) tblplnrqusgmnuser)->init(dbsPg);
	tblplnrqusr1nsession = new PgTblPlnrQUsr1NSession();
	((PgTblPlnrQUsr1NSession*) tblplnrqusr1nsession)->init(dbsPg);
	tblplnrqusraaccess = new PgTblPlnrQUsrAAccess();
	((PgTblPlnrQUsrAAccess*) tblplnrqusraaccess)->init(dbsPg);
	tblplnrqusrlist = new PgTblPlnrQUsrList();
	((PgTblPlnrQUsrList*) tblplnrqusrlist)->init(dbsPg);
	tblplnrqusrmnusergroup = new PgTblPlnrQUsrMNUsergroup();
	((PgTblPlnrQUsrMNUsergroup*) tblplnrqusrmnusergroup)->init(dbsPg);
};

void DbsPlnr::termPg() {
	PQfinish(dbsPg);
};
// IP inittermPg --- END

void DbsPlnr::begin() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) beginMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) beginPg();
};

bool DbsPlnr::commit() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return commitMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return commitPg();

	return false;
};

void DbsPlnr::rollback() {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) rollbackMy();
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) rollbackPg();
};

// IP transactMy --- BEGIN
void DbsPlnr::beginMy() {
	if (mysql_query(dbsMy, "BEGIN")) throw DbsException("DbsException / MySQL: failed to begin transaction\n");
};

bool DbsPlnr::commitMy() {
	if (mysql_query(dbsMy, "COMMIT")) {
		rollbackMy();
		return false;
	};

	return true;
};

void DbsPlnr::rollbackMy() {
	if (mysql_query(dbsMy, "ROLLBACK")) throw DbsException("DbsException / MySQL: failed to roll back transaction\n");
};
// IP transactMy --- END

// IP transactPg --- BEGIN
void DbsPlnr::beginPg() {
	PGresult* res;

	res = PQexec(dbsPg, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: failed to begin transaction\n");

	PQclear(res);
};

bool DbsPlnr::commitPg() {
	PGresult* res;

	res = PQexec(dbsPg, "COMMIT");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		rollbackPg();

		PQclear(res);
		return false;
	};

	PQclear(res);
	return true;
};

void DbsPlnr::rollbackPg() {
	PGresult* res;

	res = PQexec(dbsPg, "ROLLBACK");
	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: failed to roll back transaction\n");

	PQclear(res);
};
// IP transactPg --- END

bool DbsPlnr::loadUbigintBySQL(
			const string& sqlstr
			, ubigint& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadUbigintBySQLMy(sqlstr, val);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadUbigintBySQLPg(sqlstr, val);

	return false;
};

bool DbsPlnr::loadStringBySQL(
			const string& sqlstr
			, string& val
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadStringBySQLMy(sqlstr, val);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadStringBySQLPg(sqlstr, val);

	return false;
};

ubigint DbsPlnr::loadRefsBySQL(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) return loadRefsBySQLMy(sqlstr, append, refs);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) return loadRefsBySQLPg(sqlstr, append, refs);

	return 0;
};

// IP loadfctsMy --- BEGIN
bool DbsPlnr::loadUbigintBySQLMy(
			const string& sqlstr
			, ubigint& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadUbigintBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		val = atoll((char*) dbrow[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

bool DbsPlnr::loadStringBySQLMy(
			const string& sqlstr
			, string& val
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;

	bool retval = false;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadStringBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);
		val.assign(dbrow[0], dblengths[0]);

		retval = true;
	};
	
	mysql_free_result(dbresult);

	return retval;
};

ubigint DbsPlnr::loadRefsBySQLMy(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; ubigint numrow; ubigint numread = 0;

	if (mysql_real_query(dbsMy, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbsMy);
	if (!dbresult) throw DbsException("DbsException / MySQL: failed to store result! (loadRefsBySQL)\n");

	numrow = mysql_num_rows(dbresult);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		dbrow = mysql_fetch_row(dbresult);
		refs.push_back(atoll((char*) dbrow[0]));
		numread++;
	};

	mysql_free_result(dbresult);
	
	return(numread);
};
// IP loadfctsMy --- END

// IP loadfctsPg --- BEGIN
bool DbsPlnr::loadUbigintBySQLPg(
			const string& sqlstr
			, ubigint& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	return retval;
};

bool DbsPlnr::loadStringBySQLPg(
			const string& sqlstr
			, string& val
		) {
	PGresult* res; char* ptr;

	bool retval = false;

	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	if (PQntuples(res) == 1) {
		ptr = PQgetvalue(res, 0, 0);
		val.assign(ptr, PQgetlength(res, 0, 0));

		retval = true;
	};

	PQclear(res);

	return retval;
};

ubigint DbsPlnr::loadRefsBySQLPg(
			const string& sqlstr
			, const bool append
			, vector<ubigint>& refs
		) {
	PGresult* res; ubigint numrow; ubigint numread = 0; char* ptr;
	
	res = PQexec(dbsPg, sqlstr.c_str());
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	numrow = PQntuples(res);
	if (!append) refs.resize(0);

	refs.reserve(refs.size() + numrow);

	while (numread < numrow) {
		ptr = PQgetvalue(res, numread, 0); refs.push_back(atoll(ptr));
		numread++;
	};

	PQclear(res);

	return(numread);
};
// IP loadfctsPg --- END

void DbsPlnr::executeQuery(
			const string& sqlstr
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) {
		if (mysql_real_query(dbsMy, sqlstr.c_str(), strlen(sqlstr.c_str())))
			throw DbsException("DbsException / MySQL: failed to execute query '" + sqlstr + "'\n");

	} else if (ixDbsVDbstype == VecDbsVDbstype::PG) {
		PGresult* res;

		res = PQexec(dbsPg, sqlstr.c_str());
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
			throw DbsException("DbsException / PgSQL: failed to execute query '" + sqlstr + "'\n");

	};
};

void DbsPlnr::executeQueryDiv(
			const string& sqlstrmy
			, const string& sqlstrpg
		) {
	if (ixDbsVDbstype == VecDbsVDbstype::MY) executeQuery(sqlstrmy);
	else if (ixDbsVDbstype == VecDbsVDbstype::PG) executeQuery(sqlstrpg);
};

void DbsPlnr::executeFile(
			const string& fullpath
		) {
	string sqlstr = "";
	char c;
	
	ifstream sqlfile(fullpath.c_str());

	while (sqlfile.get(c)) {
		switch (c) {
			case '\n':
				break;
			case '\t':
				break;
			case ';':
				executeQuery(sqlstr);
				sqlstr = "";
				break;
			default:
				sqlstr = sqlstr + c;
				break;
		};
	};
	sqlfile.close();
};

void DbsPlnr::fillFeedFromKlst(
			const uint klsIxPlnrVKeylist
			, const uint ixPlnrVLocale
			, Feed& feed
		) {
	ListPlnrAVKeylistKey klsAkeys;
	PlnrAVKeylistKey* klsAkey = NULL;

	tblplnravkeylistkey->loadRstByKls(klsIxPlnrVKeylist, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblplnrjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixPlnrVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

void DbsPlnr::fillFeedFromKlstByMtbUref(
			const uint klsIxPlnrVKeylist
			, const uint x1IxPlnrVMaintable
			, const ubigint x1Uref
			, const uint ixPlnrVLocale
			, Feed& feed
		) {
	ListPlnrAVKeylistKey klsAkeys;
	PlnrAVKeylistKey* klsAkey = NULL;

	tblplnravkeylistkey->loadRstByKlsMtbUrf(klsIxPlnrVKeylist, x1IxPlnrVMaintable, x1Uref, false, klsAkeys);

	feed.clear();
	for (unsigned int i=0;i<klsAkeys.nodes.size();i++) {
		klsAkey = klsAkeys.nodes[i];

		tblplnrjavkeylistkey->loadTitByKlkLcl(klsAkey->ref, ixPlnrVLocale, klsAkey->Title);
		feed.appendIxSrefTitles(i+1, klsAkey->sref, klsAkey->Title);
	};
};

string DbsPlnr::getKlstTitleBySref(
			const uint klsIxPlnrVKeylist
			, const string& sref
			, const uint ixPlnrVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblplnravkeylistkey->loadRefByKlsSrf(klsIxPlnrVKeylist, sref, refKlk))
		if (!tblplnrjavkeylistkey->loadTitByKlkLcl(refKlk, ixPlnrVLocale, retval))
			tblplnravkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

string DbsPlnr::getKlstTitleByMtbUrefSref(
			const uint klsIxPlnrVKeylist
			, const uint x1IxPlnrVMaintable
			, const ubigint x1Uref
			, const string& sref
			, const uint ixPlnrVLocale
		) {
	string retval;

	ubigint refKlk;

	if (tblplnravkeylistkey->loadRefByKlsMtbUrfSrf(klsIxPlnrVKeylist, x1IxPlnrVMaintable, x1Uref, sref, refKlk))
		if (!tblplnrjavkeylistkey->loadTitByKlkLcl(refKlk, ixPlnrVLocale, retval))
			tblplnravkeylistkey->loadTitByRef(refKlk, retval);

	return retval;
};

void DbsPlnr::fillFeedFromVlst(
			const uint vlsIxPlnrVValuelist
			, const uint x1IxPlnrVLocale
			, Feed& feed
		) {
	ListPlnrAVValuelistVal vlsAvals;
	PlnrAVValuelistVal* vlsAval = NULL;

	tblplnravvaluelistval->loadRstByVlsLcl(vlsIxPlnrVValuelist, x1IxPlnrVLocale, false, vlsAvals);

	feed.clear();
	for (unsigned int i=0;i<vlsAvals.nodes.size();i++) {
		vlsAval = vlsAvals.nodes[i];

		feed.appendTitles(vlsAval->Val);
	};
};

