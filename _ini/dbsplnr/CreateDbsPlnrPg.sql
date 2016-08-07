-- CREATE ROLE epsi LOGIN
-- 	ENCRYPTED PASSWORD 'md5f0bc6f83ba77933c9206cfbf7a4a8e2c'
-- 	NOSUPERUSER INHERIT NOCREATEDB NOCREATEROLE;
-- COMMENT ON ROLE epsi IS 'Epsi Software Universal Account';

CREATE DATABASE "DbsPlnr"
	WITH ENCODING='UTF8'
	OWNER = epsi
	CONNECTION LIMIT = -1;

DROP TABLE IF EXISTS TblPlnrAccRMUserUniversal;
DROP TABLE IF EXISTS TblPlnrAMArrayEnv;
DROP TABLE IF EXISTS TblPlnrAMCalcEnv;
DROP TABLE IF EXISTS TblPlnrAMCalcPar;
DROP TABLE IF EXISTS TblPlnrAMDevicePar;
DROP TABLE IF EXISTS TblPlnrAMMaterialPar;
DROP TABLE IF EXISTS TblPlnrAMPersonDetail;
DROP TABLE IF EXISTS TblPlnrAMUserAccess;
DROP TABLE IF EXISTS TblPlnrAMUsergroupAccess;
DROP TABLE IF EXISTS TblPlnrAVControlPar;
DROP TABLE IF EXISTS TblPlnrAVKeylistKey;
DROP TABLE IF EXISTS TblPlnrAVValuelistVal;
DROP SEQUENCE IF EXISTS TblPlnrCFile;
DROP TABLE IF EXISTS TblPlnrDevOMDeviceMArcguide;
DROP TABLE IF EXISTS TblPlnrDevOMDeviceMLineguide;
DROP TABLE IF EXISTS TblPlnrDevOMDeviceMVertex;
DROP TABLE IF EXISTS TblPlnrDevORMArcguideMVertex;
DROP TABLE IF EXISTS TblPlnrDevORMLineguideMVertex;
DROP TABLE IF EXISTS TblPlnrHistRMUserUniversal;
DROP TABLE IF EXISTS TblPlnrJAVKeylistKey;
DROP TABLE IF EXISTS TblPlnrJMArcguideR;
DROP TABLE IF EXISTS TblPlnrJMDeviceModtype;
DROP TABLE IF EXISTS TblPlnrJMDomain;
DROP TABLE IF EXISTS TblPlnrJMDomaingd;
DROP TABLE IF EXISTS TblPlnrJMLayer;
DROP TABLE IF EXISTS TblPlnrJMLayerMaterial;
DROP TABLE IF EXISTS TblPlnrJMLevelZ;
DROP TABLE IF EXISTS TblPlnrJMPersonLastname;
DROP TABLE IF EXISTS TblPlnrJMProjectState;
DROP TABLE IF EXISTS TblPlnrJMStackModtype;
DROP TABLE IF EXISTS TblPlnrJMStackN;
DROP TABLE IF EXISTS TblPlnrJMTapeoutState;
DROP TABLE IF EXISTS TblPlnrJMUserState;
DROP TABLE IF EXISTS TblPlnrJMVertex;
DROP TABLE IF EXISTS TblPlnrLRMArcguideMVertex;
DROP TABLE IF EXISTS TblPlnrLRMLineguideMVertex;
DROP TABLE IF EXISTS TblPlnrMArcguide;
DROP TABLE IF EXISTS TblPlnrMArray;
DROP TABLE IF EXISTS TblPlnrMArrayitem;
DROP TABLE IF EXISTS TblPlnrMBlock;
DROP TABLE IF EXISTS TblPlnrMCalc;
DROP TABLE IF EXISTS TblPlnrMCalcitem;
DROP TABLE IF EXISTS TblPlnrMDesign;
DROP TABLE IF EXISTS TblPlnrMDevice;
DROP TABLE IF EXISTS TblPlnrMDomain;
DROP TABLE IF EXISTS TblPlnrMDomaingd;
DROP TABLE IF EXISTS TblPlnrMFace;
DROP TABLE IF EXISTS TblPlnrMFile;
DROP TABLE IF EXISTS TblPlnrMLayer;
DROP TABLE IF EXISTS TblPlnrMLevel;
DROP TABLE IF EXISTS TblPlnrMLineguide;
DROP TABLE IF EXISTS TblPlnrMMaterial;
DROP TABLE IF EXISTS TblPlnrMPerson;
DROP TABLE IF EXISTS TblPlnrMProject;
DROP TABLE IF EXISTS TblPlnrMReticle;
DROP TABLE IF EXISTS TblPlnrMSession;
DROP TABLE IF EXISTS TblPlnrMStack;
DROP TABLE IF EXISTS TblPlnrMStructure;
DROP TABLE IF EXISTS TblPlnrMTapeout;
DROP TABLE IF EXISTS TblPlnrMUser;
DROP TABLE IF EXISTS TblPlnrMUsergroup;
DROP TABLE IF EXISTS TblPlnrMVertex;
DROP TABLE IF EXISTS TblPlnrOMStructureMFace;
DROP TABLE IF EXISTS TblPlnrRMCalcMDomain;
DROP TABLE IF EXISTS TblPlnrRMCalcMFile;
DROP TABLE IF EXISTS TblPlnrRMFaceMVertex;
DROP TABLE IF EXISTS TblPlnrRMLayerMStructure;
DROP TABLE IF EXISTS TblPlnrRMLevelMLevel;
DROP TABLE IF EXISTS TblPlnrRMLineguideMLineguide;
DROP TABLE IF EXISTS TblPlnrRMProjectMTapeout;
DROP TABLE IF EXISTS TblPlnrRMStackMStructure;
DROP TABLE IF EXISTS TblPlnrRMUsergroupUniversal;
DROP TABLE IF EXISTS TblPlnrRMUserMUsergroup;
DROP TABLE IF EXISTS TblPlnrRMVertexMVertex;

DROP TABLE IF EXISTS TblPlnrQAriAMArrayEnv;
DROP TABLE IF EXISTS TblPlnrQAriList;
DROP TABLE IF EXISTS TblPlnrQArr1NArrayitem;
DROP TABLE IF EXISTS TblPlnrQArrAEnv;
DROP TABLE IF EXISTS TblPlnrQArrHk1NReticle;
DROP TABLE IF EXISTS TblPlnrQArrKEnvKey;
DROP TABLE IF EXISTS TblPlnrQArrList;
DROP TABLE IF EXISTS TblPlnrQClc1NMaterial;
DROP TABLE IF EXISTS TblPlnrQClcAEnv;
DROP TABLE IF EXISTS TblPlnrQClcAPar;
DROP TABLE IF EXISTS TblPlnrQClcCal1NCalcitem;
DROP TABLE IF EXISTS TblPlnrQClcList;
DROP TABLE IF EXISTS TblPlnrQClcMNDomain;
DROP TABLE IF EXISTS TblPlnrQClcMNFile;
DROP TABLE IF EXISTS TblPlnrQClcRef1NFile;
DROP TABLE IF EXISTS TblPlnrQClcSup1NCalc;
DROP TABLE IF EXISTS TblPlnrQCliAAMCalcEnv;
DROP TABLE IF EXISTS TblPlnrQCliAAMCalcPar;
DROP TABLE IF EXISTS TblPlnrQCliList;
DROP TABLE IF EXISTS TblPlnrQCliRef1NFile;
DROP TABLE IF EXISTS TblPlnrQCtpAEnv;
DROP TABLE IF EXISTS TblPlnrQCtpAPar;
DROP TABLE IF EXISTS TblPlnrQCtpKCalcdomprp;
DROP TABLE IF EXISTS TblPlnrQCtpKCalcvar;
DROP TABLE IF EXISTS TblPlnrQCtpKEnvKey;
DROP TABLE IF EXISTS TblPlnrQCtpKParCat;
DROP TABLE IF EXISTS TblPlnrQCtpKParProp;
DROP TABLE IF EXISTS TblPlnrQCtpList;
DROP TABLE IF EXISTS TblPlnrQCtpRef1NFile;
DROP TABLE IF EXISTS TblPlnrQCtpSup1NCalc;
DROP TABLE IF EXISTS TblPlnrQCtpTpl1NCalc;
DROP TABLE IF EXISTS TblPlnrQDgdList;
DROP TABLE IF EXISTS TblPlnrQDomList;
DROP TABLE IF EXISTS TblPlnrQDomMNCalc;
DROP TABLE IF EXISTS TblPlnrQDsn1NBlock;
DROP TABLE IF EXISTS TblPlnrQDsn1NReticle;
DROP TABLE IF EXISTS TblPlnrQDsnDrv1NDesign;
DROP TABLE IF EXISTS TblPlnrQDsnDsn1NDevice;
DROP TABLE IF EXISTS TblPlnrQDsnDsn1NDomain;
DROP TABLE IF EXISTS TblPlnrQDsnDsn1NDomaingd;
DROP TABLE IF EXISTS TblPlnrQDsnDsn1NStack;
DROP TABLE IF EXISTS TblPlnrQDsnHk1NArcguide;
DROP TABLE IF EXISTS TblPlnrQDsnHk1NLayer;
DROP TABLE IF EXISTS TblPlnrQDsnHk1NLevel;
DROP TABLE IF EXISTS TblPlnrQDsnHk1NLineguide;
DROP TABLE IF EXISTS TblPlnrQDsnHk1NStructure;
DROP TABLE IF EXISTS TblPlnrQDsnHk1NVertex;
DROP TABLE IF EXISTS TblPlnrQDsnList;
DROP TABLE IF EXISTS TblPlnrQDsnMod1NDesign;
DROP TABLE IF EXISTS TblPlnrQDtpAPar;
DROP TABLE IF EXISTS TblPlnrQDtpHk1NStructure;
DROP TABLE IF EXISTS TblPlnrQDtpKParKey;
DROP TABLE IF EXISTS TblPlnrQDtpList;
DROP TABLE IF EXISTS TblPlnrQDtpSup1NDevice;
DROP TABLE IF EXISTS TblPlnrQDtpTpl1NDevice;
DROP TABLE IF EXISTS TblPlnrQDvcAPar;
DROP TABLE IF EXISTS TblPlnrQDvcHk1NArcguide;
DROP TABLE IF EXISTS TblPlnrQDvcHk1NLineguide;
DROP TABLE IF EXISTS TblPlnrQDvcHk1NStructure;
DROP TABLE IF EXISTS TblPlnrQDvcHk1NVertex;
DROP TABLE IF EXISTS TblPlnrQDvcList;
DROP TABLE IF EXISTS TblPlnrQDvcSup1NDevice;
DROP TABLE IF EXISTS TblPlnrQFilList;
DROP TABLE IF EXISTS TblPlnrQFilMNCalc;
DROP TABLE IF EXISTS TblPlnrQLyr1NBlock;
DROP TABLE IF EXISTS TblPlnrQLyr1NReticle;
DROP TABLE IF EXISTS TblPlnrQLyrList;
DROP TABLE IF EXISTS TblPlnrQLyrMNStructure;
DROP TABLE IF EXISTS TblPlnrQMat1NLayer;
DROP TABLE IF EXISTS TblPlnrQMatAPar;
DROP TABLE IF EXISTS TblPlnrQMatList;
DROP TABLE IF EXISTS TblPlnrQMatMod1NMaterial;
DROP TABLE IF EXISTS TblPlnrQMatRef1NFile;
DROP TABLE IF EXISTS TblPlnrQPreselect;
DROP TABLE IF EXISTS TblPlnrQPrj1NCalc;
DROP TABLE IF EXISTS TblPlnrQPrj1NDesign;
DROP TABLE IF EXISTS TblPlnrQPrjList;
DROP TABLE IF EXISTS TblPlnrQPrjMNTapeout;
DROP TABLE IF EXISTS TblPlnrQPrsADetail;
DROP TABLE IF EXISTS TblPlnrQPrsList;
DROP TABLE IF EXISTS TblPlnrQRtcList;
DROP TABLE IF EXISTS TblPlnrQSelect;
DROP TABLE IF EXISTS TblPlnrQSru1NBlock;
DROP TABLE IF EXISTS TblPlnrQSruList;
DROP TABLE IF EXISTS TblPlnrQSruMNLayer;
DROP TABLE IF EXISTS TblPlnrQSruMNStack;
DROP TABLE IF EXISTS TblPlnrQSruSru1NFace;
DROP TABLE IF EXISTS TblPlnrQStkHk1NLayer;
DROP TABLE IF EXISTS TblPlnrQStkHk1NLevel;
DROP TABLE IF EXISTS TblPlnrQStkList;
DROP TABLE IF EXISTS TblPlnrQStkMNStructure;
DROP TABLE IF EXISTS TblPlnrQTpo1NArray;
DROP TABLE IF EXISTS TblPlnrQTpoHk1NReticle;
DROP TABLE IF EXISTS TblPlnrQTpoList;
DROP TABLE IF EXISTS TblPlnrQTpoMNProject;
DROP TABLE IF EXISTS TblPlnrQUsgAAccess;
DROP TABLE IF EXISTS TblPlnrQUsgList;
DROP TABLE IF EXISTS TblPlnrQUsgMNUser;
DROP TABLE IF EXISTS TblPlnrQUsr1NSession;
DROP TABLE IF EXISTS TblPlnrQUsrAAccess;
DROP TABLE IF EXISTS TblPlnrQUsrList;
DROP TABLE IF EXISTS TblPlnrQUsrMNUsergroup;

CREATE TABLE TblPlnrAccRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUser BIGINT,
	unvIxPlnrVMaintable INT,
	unvUref BIGINT,
	ixPlnrVAccess INT
);
ALTER TABLE TblPlnrAccRMUserUniversal OWNER TO epsi;
CREATE INDEX TblPlnrAccRMUserUniversal_refPlnrMUser ON TblPlnrAccRMUserUniversal (refPlnrMUser);
CREATE INDEX TblPlnrAccRMUserUniversal_unvIxPlnrVMaintable ON TblPlnrAccRMUserUniversal (unvIxPlnrVMaintable);
CREATE INDEX TblPlnrAccRMUserUniversal_unvUref ON TblPlnrAccRMUserUniversal (unvUref);

CREATE TABLE TblPlnrAMArrayEnv(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMArray BIGINT,
	x1RefPlnrMArrayitem BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAMArrayEnv OWNER TO epsi;
CREATE INDEX TblPlnrAMArrayEnv_refPlnrMArray ON TblPlnrAMArrayEnv (refPlnrMArray);
CREATE INDEX TblPlnrAMArrayEnv_x1RefPlnrMArrayitem ON TblPlnrAMArrayEnv (x1RefPlnrMArrayitem);
CREATE INDEX TblPlnrAMArrayEnv_x2SrefKKey ON TblPlnrAMArrayEnv (x2SrefKKey);

CREATE TABLE TblPlnrAMCalcEnv(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMCalc BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAMCalcEnv OWNER TO epsi;
CREATE INDEX TblPlnrAMCalcEnv_refPlnrMCalc ON TblPlnrAMCalcEnv (refPlnrMCalc);
CREATE INDEX TblPlnrAMCalcEnv_x1RefPlnrMCalcitem ON TblPlnrAMCalcEnv (x1RefPlnrMCalcitem);
CREATE INDEX TblPlnrAMCalcEnv_x2SrefKKey ON TblPlnrAMCalcEnv (x2SrefKKey);

CREATE TABLE TblPlnrAMCalcPar(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMCalc BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	x2SrefKCat VARCHAR(50),
	x3SrefKProp VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAMCalcPar OWNER TO epsi;
CREATE INDEX TblPlnrAMCalcPar_refPlnrMCalc ON TblPlnrAMCalcPar (refPlnrMCalc);
CREATE INDEX TblPlnrAMCalcPar_x1RefPlnrMCalcitem ON TblPlnrAMCalcPar (x1RefPlnrMCalcitem);
CREATE INDEX TblPlnrAMCalcPar_x2SrefKCat ON TblPlnrAMCalcPar (x2SrefKCat);
CREATE INDEX TblPlnrAMCalcPar_x3SrefKProp ON TblPlnrAMCalcPar (x3SrefKProp);

CREATE TABLE TblPlnrAMDevicePar(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDevice BIGINT,
	x1RefPlnrMDesign BIGINT,
	x2SrefKKey VARCHAR(50),
	refPlnrMFile BIGINT,
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAMDevicePar OWNER TO epsi;
CREATE INDEX TblPlnrAMDevicePar_refPlnrMDevice ON TblPlnrAMDevicePar (refPlnrMDevice);
CREATE INDEX TblPlnrAMDevicePar_x1RefPlnrMDesign ON TblPlnrAMDevicePar (x1RefPlnrMDesign);
CREATE INDEX TblPlnrAMDevicePar_x2SrefKKey ON TblPlnrAMDevicePar (x2SrefKKey);

CREATE TABLE TblPlnrAMMaterialPar(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMMaterial BIGINT,
	x1RefPlnrMDesign BIGINT,
	x2SrefKCat VARCHAR(50),
	x3SrefKProp VARCHAR(50),
	refPlnrMFile BIGINT,
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrAMMaterialPar OWNER TO epsi;
CREATE INDEX TblPlnrAMMaterialPar_refPlnrMMaterial ON TblPlnrAMMaterialPar (refPlnrMMaterial);
CREATE INDEX TblPlnrAMMaterialPar_x1RefPlnrMDesign ON TblPlnrAMMaterialPar (x1RefPlnrMDesign);
CREATE INDEX TblPlnrAMMaterialPar_x2SrefKCat ON TblPlnrAMMaterialPar (x2SrefKCat);
CREATE INDEX TblPlnrAMMaterialPar_x3SrefKProp ON TblPlnrAMMaterialPar (x3SrefKProp);

CREATE TABLE TblPlnrAMPersonDetail(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMPerson BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAMPersonDetail OWNER TO epsi;
CREATE INDEX TblPlnrAMPersonDetail_refPlnrMPerson ON TblPlnrAMPersonDetail (refPlnrMPerson);
CREATE INDEX TblPlnrAMPersonDetail_x1SrefKType ON TblPlnrAMPersonDetail (x1SrefKType);

CREATE TABLE TblPlnrAMUserAccess(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUser BIGINT,
	x1IxPlnrVCard INT,
	ixPlnrWUiaccess INT
);
ALTER TABLE TblPlnrAMUserAccess OWNER TO epsi;
CREATE INDEX TblPlnrAMUserAccess_refPlnrMUser ON TblPlnrAMUserAccess (refPlnrMUser);
CREATE INDEX TblPlnrAMUserAccess_x1IxPlnrVCard ON TblPlnrAMUserAccess (x1IxPlnrVCard);

CREATE TABLE TblPlnrAMUsergroupAccess(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUsergroup BIGINT,
	x1IxPlnrVCard INT,
	ixPlnrWUiaccess INT
);
ALTER TABLE TblPlnrAMUsergroupAccess OWNER TO epsi;
CREATE INDEX TblPlnrAMUsergroupAccess_refPlnrMUsergroup ON TblPlnrAMUsergroupAccess (refPlnrMUsergroup);
CREATE INDEX TblPlnrAMUsergroupAccess_x1IxPlnrVCard ON TblPlnrAMUsergroupAccess (x1IxPlnrVCard);

CREATE TABLE TblPlnrAVControlPar(
	ref BIGSERIAL PRIMARY KEY,
	ixPlnrVControl INT,
	x1RefPlnrMUser BIGINT,
	x2IxPlnrVLocale INT,
	Par VARCHAR(255),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAVControlPar OWNER TO epsi;
CREATE INDEX TblPlnrAVControlPar_ixPlnrVControl ON TblPlnrAVControlPar (ixPlnrVControl);
CREATE INDEX TblPlnrAVControlPar_x1RefPlnrMUser ON TblPlnrAVControlPar (x1RefPlnrMUser);
CREATE INDEX TblPlnrAVControlPar_x2IxPlnrVLocale ON TblPlnrAVControlPar (x2IxPlnrVLocale);

CREATE TABLE TblPlnrAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	klsIxPlnrVKeylist INT,
	klsNum INT,
	x1IxPlnrVMaintable INT,
	x1Uref BIGINT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrAVKeylistKey OWNER TO epsi;
CREATE INDEX TblPlnrAVKeylistKey_klsNum ON TblPlnrAVKeylistKey (klsNum);
CREATE INDEX TblPlnrAVKeylistKey_x1IxPlnrVMaintable ON TblPlnrAVKeylistKey (x1IxPlnrVMaintable);
CREATE INDEX TblPlnrAVKeylistKey_x1Uref ON TblPlnrAVKeylistKey (x1Uref);
CREATE INDEX TblPlnrAVKeylistKey_sref ON TblPlnrAVKeylistKey (sref);

CREATE TABLE TblPlnrAVValuelistVal(
	ref BIGSERIAL PRIMARY KEY,
	vlsIxPlnrVValuelist INT,
	vlsNum INT,
	x1IxPlnrVLocale INT,
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrAVValuelistVal OWNER TO epsi;
CREATE INDEX TblPlnrAVValuelistVal_vlsIxPlnrVValuelist ON TblPlnrAVValuelistVal (vlsIxPlnrVValuelist);
CREATE INDEX TblPlnrAVValuelistVal_vlsNum ON TblPlnrAVValuelistVal (vlsNum);
CREATE INDEX TblPlnrAVValuelistVal_x1IxPlnrVLocale ON TblPlnrAVValuelistVal (x1IxPlnrVLocale);

CREATE SEQUENCE TblPlnrCFile INCREMENT 1 MINVALUE 1 START 1 CACHE 1;
ALTER TABLE TblPlnrCFile OWNER TO epsi;

CREATE TABLE TblPlnrDevOMDeviceMArcguide(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDevice BIGINT,
	x1RefPlnrMDevice BIGINT,
	ixPlnrVLop INT,
	pr1RefM BIGINT
);
ALTER TABLE TblPlnrDevOMDeviceMArcguide OWNER TO epsi;
CREATE INDEX TblPlnrDevOMDeviceMArcguide_refPlnrMDevice ON TblPlnrDevOMDeviceMArcguide (refPlnrMDevice);
CREATE INDEX TblPlnrDevOMDeviceMArcguide_x1RefPlnrMDevice ON TblPlnrDevOMDeviceMArcguide (x1RefPlnrMDevice);
CREATE INDEX TblPlnrDevOMDeviceMArcguide_ixPlnrVLop ON TblPlnrDevOMDeviceMArcguide (ixPlnrVLop);
CREATE INDEX TblPlnrDevOMDeviceMArcguide_pr1RefM ON TblPlnrDevOMDeviceMArcguide (pr1RefM);

CREATE TABLE TblPlnrDevOMDeviceMLineguide(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDevice BIGINT,
	x1RefPlnrMDevice BIGINT,
	ixPlnrVLop INT,
	pr1RefM BIGINT
);
ALTER TABLE TblPlnrDevOMDeviceMLineguide OWNER TO epsi;
CREATE INDEX TblPlnrDevOMDeviceMLineguide_refPlnrMDevice ON TblPlnrDevOMDeviceMLineguide (refPlnrMDevice);
CREATE INDEX TblPlnrDevOMDeviceMLineguide_x1RefPlnrMDevice ON TblPlnrDevOMDeviceMLineguide (x1RefPlnrMDevice);
CREATE INDEX TblPlnrDevOMDeviceMLineguide_ixPlnrVLop ON TblPlnrDevOMDeviceMLineguide (ixPlnrVLop);
CREATE INDEX TblPlnrDevOMDeviceMLineguide_pr1RefM ON TblPlnrDevOMDeviceMLineguide (pr1RefM);

CREATE TABLE TblPlnrDevOMDeviceMVertex(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDevice BIGINT,
	x1RefPlnrMDevice BIGINT,
	ixPlnrVLop INT,
	pr1RefM BIGINT
);
ALTER TABLE TblPlnrDevOMDeviceMVertex OWNER TO epsi;
CREATE INDEX TblPlnrDevOMDeviceMVertex_refPlnrMDevice ON TblPlnrDevOMDeviceMVertex (refPlnrMDevice);
CREATE INDEX TblPlnrDevOMDeviceMVertex_x1RefPlnrMDevice ON TblPlnrDevOMDeviceMVertex (x1RefPlnrMDevice);
CREATE INDEX TblPlnrDevOMDeviceMVertex_ixPlnrVLop ON TblPlnrDevOMDeviceMVertex (ixPlnrVLop);
CREATE INDEX TblPlnrDevOMDeviceMVertex_pr1RefM ON TblPlnrDevOMDeviceMVertex (pr1RefM);

CREATE TABLE TblPlnrDevORMArcguideMVertex(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMArcguide BIGINT,
	x1RefPlnrMDevice BIGINT,
	ixPlnrVLop INT,
	pr1RefLR BIGINT
);
ALTER TABLE TblPlnrDevORMArcguideMVertex OWNER TO epsi;
CREATE INDEX TblPlnrDevORMArcguideMVertex_refPlnrMArcguide ON TblPlnrDevORMArcguideMVertex (refPlnrMArcguide);
CREATE INDEX TblPlnrDevORMArcguideMVertex_x1RefPlnrMDevice ON TblPlnrDevORMArcguideMVertex (x1RefPlnrMDevice);
CREATE INDEX TblPlnrDevORMArcguideMVertex_ixPlnrVLop ON TblPlnrDevORMArcguideMVertex (ixPlnrVLop);
CREATE INDEX TblPlnrDevORMArcguideMVertex_pr1RefLR ON TblPlnrDevORMArcguideMVertex (pr1RefLR);

CREATE TABLE TblPlnrDevORMLineguideMVertex(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMLineguide BIGINT,
	x1RefPlnrMDevice BIGINT,
	ixPlnrVLop INT,
	pr1RefLR BIGINT
);
ALTER TABLE TblPlnrDevORMLineguideMVertex OWNER TO epsi;
CREATE INDEX TblPlnrDevORMLineguideMVertex_refPlnrMLineguide ON TblPlnrDevORMLineguideMVertex (refPlnrMLineguide);
CREATE INDEX TblPlnrDevORMLineguideMVertex_x1RefPlnrMDevice ON TblPlnrDevORMLineguideMVertex (x1RefPlnrMDevice);
CREATE INDEX TblPlnrDevORMLineguideMVertex_ixPlnrVLop ON TblPlnrDevORMLineguideMVertex (ixPlnrVLop);
CREATE INDEX TblPlnrDevORMLineguideMVertex_pr1RefLR ON TblPlnrDevORMLineguideMVertex (pr1RefLR);

CREATE TABLE TblPlnrHistRMUserUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUser BIGINT,
	unvIxPlnrVMaintable INT,
	unvUref BIGINT,
	ixPlnrVCard INT,
	ixPlnrVPreset INT,
	preIxPlnrVMaintable INT,
	preUref BIGINT,
	start INT
);
ALTER TABLE TblPlnrHistRMUserUniversal OWNER TO epsi;
CREATE INDEX TblPlnrHistRMUserUniversal_refPlnrMUser ON TblPlnrHistRMUserUniversal (refPlnrMUser);
CREATE INDEX TblPlnrHistRMUserUniversal_unvIxPlnrVMaintable ON TblPlnrHistRMUserUniversal (unvIxPlnrVMaintable);
CREATE INDEX TblPlnrHistRMUserUniversal_unvUref ON TblPlnrHistRMUserUniversal (unvUref);
CREATE INDEX TblPlnrHistRMUserUniversal_ixPlnrVCard ON TblPlnrHistRMUserUniversal (ixPlnrVCard);
CREATE INDEX TblPlnrHistRMUserUniversal_ixPlnrVPreset ON TblPlnrHistRMUserUniversal (ixPlnrVPreset);
CREATE INDEX TblPlnrHistRMUserUniversal_preIxPlnrVMaintable ON TblPlnrHistRMUserUniversal (preIxPlnrVMaintable);
CREATE INDEX TblPlnrHistRMUserUniversal_preUref ON TblPlnrHistRMUserUniversal (preUref);
CREATE INDEX TblPlnrHistRMUserUniversal_start ON TblPlnrHistRMUserUniversal (start);

CREATE TABLE TblPlnrJAVKeylistKey(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrAVKeylistKey BIGINT,
	x1IxPlnrVLocale INT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrJAVKeylistKey OWNER TO epsi;
CREATE INDEX TblPlnrJAVKeylistKey_refPlnrAVKeylistKey ON TblPlnrJAVKeylistKey (refPlnrAVKeylistKey);
CREATE INDEX TblPlnrJAVKeylistKey_x1IxPlnrVLocale ON TblPlnrJAVKeylistKey (x1IxPlnrVLocale);

CREATE TABLE TblPlnrJMArcguideR(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMArcguide BIGINT,
	x1RefPlnrMDesign BIGINT,
	r DOUBLE PRECISION
);
ALTER TABLE TblPlnrJMArcguideR OWNER TO epsi;
CREATE INDEX TblPlnrJMArcguideR_refPlnrMArcguide ON TblPlnrJMArcguideR (refPlnrMArcguide);
CREATE INDEX TblPlnrJMArcguideR_x1RefPlnrMDesign ON TblPlnrJMArcguideR (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMDeviceModtype(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDevice BIGINT,
	x1RefPlnrMDesign BIGINT,
	ixVModtype INT
);
ALTER TABLE TblPlnrJMDeviceModtype OWNER TO epsi;
CREATE INDEX TblPlnrJMDeviceModtype_refPlnrMDevice ON TblPlnrJMDeviceModtype (refPlnrMDevice);
CREATE INDEX TblPlnrJMDeviceModtype_x1RefPlnrMDesign ON TblPlnrJMDeviceModtype (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMDomain(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDomain BIGINT,
	x1RefPlnrMDesign BIGINT,
	dx VARCHAR(30),
	dy VARCHAR(30),
	dxy VARCHAR(30),
	dz VARCHAR(30)
);
ALTER TABLE TblPlnrJMDomain OWNER TO epsi;
CREATE INDEX TblPlnrJMDomain_refPlnrMDomain ON TblPlnrJMDomain (refPlnrMDomain);
CREATE INDEX TblPlnrJMDomain_x1RefPlnrMDesign ON TblPlnrJMDomain (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMDomaingd(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDomaingd BIGINT,
	x1RefPlnrMDesign BIGINT,
	d VARCHAR(30),
	dphi VARCHAR(30)
);
ALTER TABLE TblPlnrJMDomaingd OWNER TO epsi;
CREATE INDEX TblPlnrJMDomaingd_refPlnrMDomaingd ON TblPlnrJMDomaingd (refPlnrMDomaingd);
CREATE INDEX TblPlnrJMDomaingd_x1RefPlnrMDesign ON TblPlnrJMDomaingd (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMLayer(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMLayer BIGINT,
	x1RefPlnrMDesign BIGINT,
	t VARCHAR(30),
	ML VARCHAR(30)
);
ALTER TABLE TblPlnrJMLayer OWNER TO epsi;
CREATE INDEX TblPlnrJMLayer_refPlnrMLayer ON TblPlnrJMLayer (refPlnrMLayer);
CREATE INDEX TblPlnrJMLayer_x1RefPlnrMDesign ON TblPlnrJMLayer (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMLayerMaterial(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMLayer BIGINT,
	x1RefPlnrMDesign BIGINT,
	refPlnrMMaterial BIGINT
);
ALTER TABLE TblPlnrJMLayerMaterial OWNER TO epsi;
CREATE INDEX TblPlnrJMLayerMaterial_refPlnrMLayer ON TblPlnrJMLayerMaterial (refPlnrMLayer);
CREATE INDEX TblPlnrJMLayerMaterial_x1RefPlnrMDesign ON TblPlnrJMLayerMaterial (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMLevelZ(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMLevel BIGINT,
	x1RefPlnrMDesign BIGINT,
	z DOUBLE PRECISION
);
ALTER TABLE TblPlnrJMLevelZ OWNER TO epsi;
CREATE INDEX TblPlnrJMLevelZ_refPlnrMLevel ON TblPlnrJMLevelZ (refPlnrMLevel);
CREATE INDEX TblPlnrJMLevelZ_x1RefPlnrMDesign ON TblPlnrJMLevelZ (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMPersonLastname(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMPerson BIGINT,
	x1Startd INT,
	Lastname VARCHAR(50)
);
ALTER TABLE TblPlnrJMPersonLastname OWNER TO epsi;
CREATE INDEX TblPlnrJMPersonLastname_refPlnrMPerson ON TblPlnrJMPersonLastname (refPlnrMPerson);
CREATE INDEX TblPlnrJMPersonLastname_x1Startd ON TblPlnrJMPersonLastname (x1Startd);
CREATE INDEX TblPlnrJMPersonLastname_Lastname ON TblPlnrJMPersonLastname (Lastname);

CREATE TABLE TblPlnrJMProjectState(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMProject BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblPlnrJMProjectState OWNER TO epsi;
CREATE INDEX TblPlnrJMProjectState_refPlnrMProject ON TblPlnrJMProjectState (refPlnrMProject);
CREATE INDEX TblPlnrJMProjectState_x1Start ON TblPlnrJMProjectState (x1Start);

CREATE TABLE TblPlnrJMStackModtype(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMStack BIGINT,
	x1RefPlnrMDesign BIGINT,
	ixVModtype INT
);
ALTER TABLE TblPlnrJMStackModtype OWNER TO epsi;
CREATE INDEX TblPlnrJMStackModtype_refPlnrMStack ON TblPlnrJMStackModtype (refPlnrMStack);
CREATE INDEX TblPlnrJMStackModtype_x1RefPlnrMDesign ON TblPlnrJMStackModtype (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMStackN(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMStack BIGINT,
	x1RefPlnrMDesign BIGINT,
	N VARCHAR(30)
);
ALTER TABLE TblPlnrJMStackN OWNER TO epsi;
CREATE INDEX TblPlnrJMStackN_refPlnrMStack ON TblPlnrJMStackN (refPlnrMStack);
CREATE INDEX TblPlnrJMStackN_x1RefPlnrMDesign ON TblPlnrJMStackN (x1RefPlnrMDesign);

CREATE TABLE TblPlnrJMTapeoutState(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMTapeout BIGINT,
	x1Start INT,
	ixVState INT
);
ALTER TABLE TblPlnrJMTapeoutState OWNER TO epsi;
CREATE INDEX TblPlnrJMTapeoutState_refPlnrMTapeout ON TblPlnrJMTapeoutState (refPlnrMTapeout);
CREATE INDEX TblPlnrJMTapeoutState_x1Start ON TblPlnrJMTapeoutState (x1Start);

CREATE TABLE TblPlnrJMUserState(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUser BIGINT,
	x1Startd INT,
	ixVState INT
);
ALTER TABLE TblPlnrJMUserState OWNER TO epsi;
CREATE INDEX TblPlnrJMUserState_refPlnrMUser ON TblPlnrJMUserState (refPlnrMUser);
CREATE INDEX TblPlnrJMUserState_x1Startd ON TblPlnrJMUserState (x1Startd);

CREATE TABLE TblPlnrJMVertex(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMVertex BIGINT,
	x1RefPlnrMDesign BIGINT,
	x DOUBLE PRECISION,
	y DOUBLE PRECISION
);
ALTER TABLE TblPlnrJMVertex OWNER TO epsi;
CREATE INDEX TblPlnrJMVertex_refPlnrMVertex ON TblPlnrJMVertex (refPlnrMVertex);
CREATE INDEX TblPlnrJMVertex_x1RefPlnrMDesign ON TblPlnrJMVertex (x1RefPlnrMDesign);

CREATE TABLE TblPlnrLRMArcguideMVertex(
	ref BIGSERIAL PRIMARY KEY,
	agdIxPlnrVLat INT,
	agdRefPlnrMArcguide BIGINT,
	agdNum INT,
	refPlnrMVertex BIGINT
);
ALTER TABLE TblPlnrLRMArcguideMVertex OWNER TO epsi;
CREATE INDEX TblPlnrLRMArcguideMVertex_agdIxPlnrVLat ON TblPlnrLRMArcguideMVertex (agdIxPlnrVLat);
CREATE INDEX TblPlnrLRMArcguideMVertex_agdRefPlnrMArcguide ON TblPlnrLRMArcguideMVertex (agdRefPlnrMArcguide);
CREATE INDEX TblPlnrLRMArcguideMVertex_agdNum ON TblPlnrLRMArcguideMVertex (agdNum);
CREATE INDEX TblPlnrLRMArcguideMVertex_refPlnrMVertex ON TblPlnrLRMArcguideMVertex (refPlnrMVertex);

CREATE TABLE TblPlnrLRMLineguideMVertex(
	ref BIGSERIAL PRIMARY KEY,
	lgdIxPlnrVLat INT,
	lgdRefPlnrMLineguide BIGINT,
	lgdNum INT,
	refPlnrMVertex BIGINT
);
ALTER TABLE TblPlnrLRMLineguideMVertex OWNER TO epsi;
CREATE INDEX TblPlnrLRMLineguideMVertex_lgdIxPlnrVLat ON TblPlnrLRMLineguideMVertex (lgdIxPlnrVLat);
CREATE INDEX TblPlnrLRMLineguideMVertex_lgdRefPlnrMLineguide ON TblPlnrLRMLineguideMVertex (lgdRefPlnrMLineguide);
CREATE INDEX TblPlnrLRMLineguideMVertex_lgdNum ON TblPlnrLRMLineguideMVertex (lgdNum);
CREATE INDEX TblPlnrLRMLineguideMVertex_refPlnrMVertex ON TblPlnrLRMLineguideMVertex (refPlnrMVertex);

CREATE TABLE TblPlnrMArcguide(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMDesign BIGINT,
	devRefPlnrMArcguide BIGINT,
	hkIxPlnrVLat INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	sref VARCHAR(50),
	ctrRefPlnrMVertex BIGINT,
	r DOUBLE PRECISION
);
ALTER TABLE TblPlnrMArcguide OWNER TO epsi;
CREATE INDEX TblPlnrMArcguide_x1RefPlnrMDesign ON TblPlnrMArcguide (x1RefPlnrMDesign);
CREATE INDEX TblPlnrMArcguide_devRefPlnrMArcguide ON TblPlnrMArcguide (devRefPlnrMArcguide);
CREATE INDEX TblPlnrMArcguide_hkIxPlnrVLat ON TblPlnrMArcguide (hkIxPlnrVLat);
CREATE INDEX TblPlnrMArcguide_hkIxVTbl ON TblPlnrMArcguide (hkIxVTbl);
CREATE INDEX TblPlnrMArcguide_hkUref ON TblPlnrMArcguide (hkUref);
CREATE INDEX TblPlnrMArcguide_sref ON TblPlnrMArcguide (sref);
CREATE INDEX TblPlnrMArcguide_ctrRefPlnrMVertex ON TblPlnrMArcguide (ctrRefPlnrMVertex);

CREATE TABLE TblPlnrMArray(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMTapeout BIGINT,
	refPlnrMDesign BIGINT,
	sref VARCHAR(50),
	I SMALLINT,
	J SMALLINT,
	di DOUBLE PRECISION,
	dj DOUBLE PRECISION,
	K SMALLINT,
	L SMALLINT,
	dk DOUBLE PRECISION,
	dl DOUBLE PRECISION,
	M SMALLINT,
	N SMALLINT,
	dm DOUBLE PRECISION,
	dn DOUBLE PRECISION
);
ALTER TABLE TblPlnrMArray OWNER TO epsi;
CREATE INDEX TblPlnrMArray_refPlnrMTapeout ON TblPlnrMArray (refPlnrMTapeout);
CREATE INDEX TblPlnrMArray_refPlnrMDesign ON TblPlnrMArray (refPlnrMDesign);
CREATE INDEX TblPlnrMArray_sref ON TblPlnrMArray (sref);

CREATE TABLE TblPlnrMArrayitem(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMArray BIGINT,
	refPlnrMDesign BIGINT,
	i SMALLINT,
	j SMALLINT,
	k SMALLINT,
	l SMALLINT,
	m SMALLINT,
	n SMALLINT,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION
);
ALTER TABLE TblPlnrMArrayitem OWNER TO epsi;
CREATE INDEX TblPlnrMArrayitem_refPlnrMArray ON TblPlnrMArrayitem (refPlnrMArray);
CREATE INDEX TblPlnrMArrayitem_refPlnrMDesign ON TblPlnrMArrayitem (refPlnrMDesign);
CREATE INDEX TblPlnrMArrayitem_i ON TblPlnrMArrayitem (i);
CREATE INDEX TblPlnrMArrayitem_j ON TblPlnrMArrayitem (j);
CREATE INDEX TblPlnrMArrayitem_k ON TblPlnrMArrayitem (k);
CREATE INDEX TblPlnrMArrayitem_l ON TblPlnrMArrayitem (l);
CREATE INDEX TblPlnrMArrayitem_m ON TblPlnrMArrayitem (m);
CREATE INDEX TblPlnrMArrayitem_n ON TblPlnrMArrayitem (n);

CREATE TABLE TblPlnrMBlock(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMDesign BIGINT,
	refPlnrMStructure BIGINT,
	refPlnrMLayer BIGINT
);
ALTER TABLE TblPlnrMBlock OWNER TO epsi;
CREATE INDEX TblPlnrMBlock_refPlnrMDesign ON TblPlnrMBlock (refPlnrMDesign);
CREATE INDEX TblPlnrMBlock_refPlnrMStructure ON TblPlnrMBlock (refPlnrMStructure);
CREATE INDEX TblPlnrMBlock_refPlnrMLayer ON TblPlnrMBlock (refPlnrMLayer);

CREATE TABLE TblPlnrMCalc(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refPlnrMProject BIGINT,
	ixVDim INT,
	tplRefPlnrMCalc BIGINT,
	supRefPlnrMCalc BIGINT,
	refPlnrMDesign BIGINT,
	Title VARCHAR(50),
	start INT,
	Comment TEXT
);
ALTER TABLE TblPlnrMCalc OWNER TO epsi;
CREATE INDEX TblPlnrMCalc_grp ON TblPlnrMCalc (grp);
CREATE INDEX TblPlnrMCalc_own ON TblPlnrMCalc (own);
CREATE INDEX TblPlnrMCalc_refPlnrMProject ON TblPlnrMCalc (refPlnrMProject);
CREATE INDEX TblPlnrMCalc_ixVDim ON TblPlnrMCalc (ixVDim);
CREATE INDEX TblPlnrMCalc_tplRefPlnrMCalc ON TblPlnrMCalc (tplRefPlnrMCalc);
CREATE INDEX TblPlnrMCalc_supRefPlnrMCalc ON TblPlnrMCalc (supRefPlnrMCalc);
CREATE INDEX TblPlnrMCalc_refPlnrMDesign ON TblPlnrMCalc (refPlnrMDesign);
CREATE INDEX TblPlnrMCalc_Title ON TblPlnrMCalc (Title);
CREATE INDEX TblPlnrMCalc_start ON TblPlnrMCalc (start);

CREATE TABLE TblPlnrMCalcitem(
	ref BIGSERIAL PRIMARY KEY,
	calRefPlnrMCalc BIGINT,
	calNum INT,
	refPlnrMDesign BIGINT,
	Title VARCHAR(50)
);
ALTER TABLE TblPlnrMCalcitem OWNER TO epsi;
CREATE INDEX TblPlnrMCalcitem_calRefPlnrMCalc ON TblPlnrMCalcitem (calRefPlnrMCalc);
CREATE INDEX TblPlnrMCalcitem_calNum ON TblPlnrMCalcitem (calNum);
CREATE INDEX TblPlnrMCalcitem_refPlnrMDesign ON TblPlnrMCalcitem (refPlnrMDesign);
CREATE INDEX TblPlnrMCalcitem_Title ON TblPlnrMCalcitem (Title);

CREATE TABLE TblPlnrMDesign(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixVBasetype INT,
	ixVDim INT,
	refIxVTbl INT,
	refUref BIGINT,
	refPlnrMProject BIGINT,
	ixWModtype INT,
	modRefPlnrMDesign BIGINT,
	drvRefPlnrMDesign BIGINT,
	Title VARCHAR(50),
	Major SMALLINT,
	Sub SMALLINT,
	Comment TEXT
);
ALTER TABLE TblPlnrMDesign OWNER TO epsi;
CREATE INDEX TblPlnrMDesign_grp ON TblPlnrMDesign (grp);
CREATE INDEX TblPlnrMDesign_own ON TblPlnrMDesign (own);
CREATE INDEX TblPlnrMDesign_ixVBasetype ON TblPlnrMDesign (ixVBasetype);
CREATE INDEX TblPlnrMDesign_ixVDim ON TblPlnrMDesign (ixVDim);
CREATE INDEX TblPlnrMDesign_refIxVTbl ON TblPlnrMDesign (refIxVTbl);
CREATE INDEX TblPlnrMDesign_refUref ON TblPlnrMDesign (refUref);
CREATE INDEX TblPlnrMDesign_refPlnrMProject ON TblPlnrMDesign (refPlnrMProject);
CREATE INDEX TblPlnrMDesign_ixWModtype ON TblPlnrMDesign (ixWModtype);
CREATE INDEX TblPlnrMDesign_modRefPlnrMDesign ON TblPlnrMDesign (modRefPlnrMDesign);
CREATE INDEX TblPlnrMDesign_drvRefPlnrMDesign ON TblPlnrMDesign (drvRefPlnrMDesign);

CREATE TABLE TblPlnrMDevice(
	ref BIGSERIAL PRIMARY KEY,
	dsnRefPlnrMDesign BIGINT,
	dsnNum INT,
	supRefPlnrMDevice BIGINT,
	supNum INT,
	tplRefPlnrMDevice BIGINT,
	sref VARCHAR(50),
	ixVModtype INT,
	ixVAligntype INT,
	av1SrefPlnrMVertex VARCHAR(50),
	pav1SrefPlnrMVertex VARCHAR(50),
	av2SrefPlnrMVertex VARCHAR(50),
	pav2SrefPlnrMVertex VARCHAR(50),
	x DOUBLE PRECISION,
	y DOUBLE PRECISION,
	phi DOUBLE PRECISION,
	Comment TEXT
);
ALTER TABLE TblPlnrMDevice OWNER TO epsi;
CREATE INDEX TblPlnrMDevice_dsnRefPlnrMDesign ON TblPlnrMDevice (dsnRefPlnrMDesign);
CREATE INDEX TblPlnrMDevice_dsnNum ON TblPlnrMDevice (dsnNum);
CREATE INDEX TblPlnrMDevice_supRefPlnrMDevice ON TblPlnrMDevice (supRefPlnrMDevice);
CREATE INDEX TblPlnrMDevice_supNum ON TblPlnrMDevice (supNum);
CREATE INDEX TblPlnrMDevice_tplRefPlnrMDevice ON TblPlnrMDevice (tplRefPlnrMDevice);
CREATE INDEX TblPlnrMDevice_sref ON TblPlnrMDevice (sref);

CREATE TABLE TblPlnrMDomain(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	dsnRefPlnrMDesign BIGINT,
	dsnNum INT,
	sref VARCHAR(50),
	flrSrefPlnrMLevel VARCHAR(50),
	ceilSrefPlnrMLevel VARCHAR(50),
	vtx1SrefPlnrMVertex VARCHAR(50),
	lgd1SrefPlnrMLineguide VARCHAR(50),
	vtx2SrefPlnrMVertex VARCHAR(50),
	lgd2SrefPlnrMLineguide VARCHAR(50),
	vtx3SrefPlnrMVertex VARCHAR(50),
	lgd3SrefPlnrMLineguide VARCHAR(50),
	vtx4SrefPlnrMVertex VARCHAR(50),
	lgd4SrefPlnrMLineguide VARCHAR(50),
	dx VARCHAR(30),
	dy VARCHAR(30),
	dxy VARCHAR(30),
	dz VARCHAR(30)
);
ALTER TABLE TblPlnrMDomain OWNER TO epsi;
CREATE INDEX TblPlnrMDomain_ixVBasetype ON TblPlnrMDomain (ixVBasetype);
CREATE INDEX TblPlnrMDomain_dsnRefPlnrMDesign ON TblPlnrMDomain (dsnRefPlnrMDesign);
CREATE INDEX TblPlnrMDomain_dsnNum ON TblPlnrMDomain (dsnNum);
CREATE INDEX TblPlnrMDomain_sref ON TblPlnrMDomain (sref);

CREATE TABLE TblPlnrMDomaingd(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	dsnRefPlnrMDesign BIGINT,
	dsnNum INT,
	sref VARCHAR(50),
	srefPlnrMLevel VARCHAR(50),
	av1SrefPlnrMVertex VARCHAR(50),
	av2SrefPlnrMVertex VARCHAR(50),
	al1SrefPlnrMLineguide VARCHAR(50),
	al2SrefPlnrMLineguide VARCHAR(50),
	srefPlnrMArcguide VARCHAR(50),
	d VARCHAR(30),
	dphi VARCHAR(30)
);
ALTER TABLE TblPlnrMDomaingd OWNER TO epsi;
CREATE INDEX TblPlnrMDomaingd_ixVBasetype ON TblPlnrMDomaingd (ixVBasetype);
CREATE INDEX TblPlnrMDomaingd_dsnRefPlnrMDesign ON TblPlnrMDomaingd (dsnRefPlnrMDesign);
CREATE INDEX TblPlnrMDomaingd_dsnNum ON TblPlnrMDomaingd (dsnNum);
CREATE INDEX TblPlnrMDomaingd_sref ON TblPlnrMDomaingd (sref);

CREATE TABLE TblPlnrMFace(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMDesign BIGINT,
	devRefPlnrMFace BIGINT,
	sruIxPlnrVLat INT,
	sruRefPlnrMStructure BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblPlnrMFace OWNER TO epsi;
CREATE INDEX TblPlnrMFace_x1RefPlnrMDesign ON TblPlnrMFace (x1RefPlnrMDesign);
CREATE INDEX TblPlnrMFace_devRefPlnrMFace ON TblPlnrMFace (devRefPlnrMFace);
CREATE INDEX TblPlnrMFace_sruIxPlnrVLat ON TblPlnrMFace (sruIxPlnrVLat);
CREATE INDEX TblPlnrMFace_sruRefPlnrMStructure ON TblPlnrMFace (sruRefPlnrMStructure);
CREATE INDEX TblPlnrMFace_sref ON TblPlnrMFace (sref);

CREATE TABLE TblPlnrMFile(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refPlnrCFile BIGINT,
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	Archived INT,
	Filename VARCHAR(50),
	Archivename VARCHAR(30),
	srefKMimetype VARCHAR(50),
	Size INT,
	Comment TEXT
);
ALTER TABLE TblPlnrMFile OWNER TO epsi;
CREATE INDEX TblPlnrMFile_grp ON TblPlnrMFile (grp);
CREATE INDEX TblPlnrMFile_own ON TblPlnrMFile (own);
CREATE INDEX TblPlnrMFile_refPlnrCFile ON TblPlnrMFile (refPlnrCFile);
CREATE INDEX TblPlnrMFile_refIxVTbl ON TblPlnrMFile (refIxVTbl);
CREATE INDEX TblPlnrMFile_refUref ON TblPlnrMFile (refUref);
CREATE INDEX TblPlnrMFile_Filename ON TblPlnrMFile (Filename);

CREATE TABLE TblPlnrMLayer(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMDesign BIGINT,
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	hkNum INT,
	refPlnrMMaterial BIGINT,
	ixVTtype INT,
	sref VARCHAR(50),
	flrRefPlnrMLevel BIGINT,
	ctrRefPlnrMLevel BIGINT,
	ceilRefPlnrMLevel BIGINT,
	t VARCHAR(30),
	ML VARCHAR(30)
);
ALTER TABLE TblPlnrMLayer OWNER TO epsi;
CREATE INDEX TblPlnrMLayer_x1RefPlnrMDesign ON TblPlnrMLayer (x1RefPlnrMDesign);
CREATE INDEX TblPlnrMLayer_ixVBasetype ON TblPlnrMLayer (ixVBasetype);
CREATE INDEX TblPlnrMLayer_hkIxVTbl ON TblPlnrMLayer (hkIxVTbl);
CREATE INDEX TblPlnrMLayer_hkUref ON TblPlnrMLayer (hkUref);
CREATE INDEX TblPlnrMLayer_hkNum ON TblPlnrMLayer (hkNum);
CREATE INDEX TblPlnrMLayer_refPlnrMMaterial ON TblPlnrMLayer (refPlnrMMaterial);
CREATE INDEX TblPlnrMLayer_ixVTtype ON TblPlnrMLayer (ixVTtype);
CREATE INDEX TblPlnrMLayer_sref ON TblPlnrMLayer (sref);
CREATE INDEX TblPlnrMLayer_flrRefPlnrMLevel ON TblPlnrMLayer (flrRefPlnrMLevel);
CREATE INDEX TblPlnrMLayer_ctrRefPlnrMLevel ON TblPlnrMLayer (ctrRefPlnrMLevel);
CREATE INDEX TblPlnrMLayer_ceilRefPlnrMLevel ON TblPlnrMLayer (ceilRefPlnrMLevel);

CREATE TABLE TblPlnrMLevel(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMDesign BIGINT,
	hkIxVTbl INT,
	hkUref BIGINT,
	sref VARCHAR(50),
	z DOUBLE PRECISION
);
ALTER TABLE TblPlnrMLevel OWNER TO epsi;
CREATE INDEX TblPlnrMLevel_x1RefPlnrMDesign ON TblPlnrMLevel (x1RefPlnrMDesign);
CREATE INDEX TblPlnrMLevel_hkIxVTbl ON TblPlnrMLevel (hkIxVTbl);
CREATE INDEX TblPlnrMLevel_hkUref ON TblPlnrMLevel (hkUref);
CREATE INDEX TblPlnrMLevel_sref ON TblPlnrMLevel (sref);
CREATE INDEX TblPlnrMLevel_z ON TblPlnrMLevel (z);

CREATE TABLE TblPlnrMLineguide(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMDesign BIGINT,
	hkIxPlnrVLat INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblPlnrMLineguide OWNER TO epsi;
CREATE INDEX TblPlnrMLineguide_x1RefPlnrMDesign ON TblPlnrMLineguide (x1RefPlnrMDesign);
CREATE INDEX TblPlnrMLineguide_hkIxPlnrVLat ON TblPlnrMLineguide (hkIxPlnrVLat);
CREATE INDEX TblPlnrMLineguide_hkIxVTbl ON TblPlnrMLineguide (hkIxVTbl);
CREATE INDEX TblPlnrMLineguide_hkUref ON TblPlnrMLineguide (hkUref);
CREATE INDEX TblPlnrMLineguide_sref ON TblPlnrMLineguide (sref);

CREATE TABLE TblPlnrMMaterial(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixVBasetype INT,
	refPlnrMCalc BIGINT,
	modRefPlnrMMaterial BIGINT,
	modLvl SMALLINT,
	sref VARCHAR(50),
	Title VARCHAR(50)
);
ALTER TABLE TblPlnrMMaterial OWNER TO epsi;
CREATE INDEX TblPlnrMMaterial_grp ON TblPlnrMMaterial (grp);
CREATE INDEX TblPlnrMMaterial_own ON TblPlnrMMaterial (own);
CREATE INDEX TblPlnrMMaterial_ixVBasetype ON TblPlnrMMaterial (ixVBasetype);
CREATE INDEX TblPlnrMMaterial_refPlnrMCalc ON TblPlnrMMaterial (refPlnrMCalc);
CREATE INDEX TblPlnrMMaterial_modRefPlnrMMaterial ON TblPlnrMMaterial (modRefPlnrMMaterial);
CREATE INDEX TblPlnrMMaterial_modLvl ON TblPlnrMMaterial (modLvl);
CREATE INDEX TblPlnrMMaterial_sref ON TblPlnrMMaterial (sref);
CREATE INDEX TblPlnrMMaterial_Title ON TblPlnrMMaterial (Title);

CREATE TABLE TblPlnrMPerson(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixWDerivate INT,
	ixVSex INT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	refJLastname BIGINT,
	Lastname VARCHAR(50),
	telRefADetail BIGINT,
	Tel VARCHAR(255),
	emlRefADetail BIGINT,
	Eml VARCHAR(255),
	Salutation VARCHAR(100)
);
ALTER TABLE TblPlnrMPerson OWNER TO epsi;
CREATE INDEX TblPlnrMPerson_grp ON TblPlnrMPerson (grp);
CREATE INDEX TblPlnrMPerson_own ON TblPlnrMPerson (own);
CREATE INDEX TblPlnrMPerson_ixWDerivate ON TblPlnrMPerson (ixWDerivate);
CREATE INDEX TblPlnrMPerson_Lastname ON TblPlnrMPerson (Lastname);

CREATE TABLE TblPlnrMProject(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	Title VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	Comment TEXT
);
ALTER TABLE TblPlnrMProject OWNER TO epsi;
CREATE INDEX TblPlnrMProject_grp ON TblPlnrMProject (grp);
CREATE INDEX TblPlnrMProject_own ON TblPlnrMProject (own);
CREATE INDEX TblPlnrMProject_Title ON TblPlnrMProject (Title);

CREATE TABLE TblPlnrMReticle(
	ref BIGSERIAL PRIMARY KEY,
	hkIxVTbl INT,
	hkUref BIGINT,
	refPlnrMDesign BIGINT,
	refPlnrMLayer BIGINT,
	sref VARCHAR(50),
	x0 DOUBLE PRECISION,
	y0 DOUBLE PRECISION,
	phi DOUBLE PRECISION
);
ALTER TABLE TblPlnrMReticle OWNER TO epsi;
CREATE INDEX TblPlnrMReticle_hkIxVTbl ON TblPlnrMReticle (hkIxVTbl);
CREATE INDEX TblPlnrMReticle_hkUref ON TblPlnrMReticle (hkUref);
CREATE INDEX TblPlnrMReticle_refPlnrMDesign ON TblPlnrMReticle (refPlnrMDesign);
CREATE INDEX TblPlnrMReticle_refPlnrMLayer ON TblPlnrMReticle (refPlnrMLayer);
CREATE INDEX TblPlnrMReticle_sref ON TblPlnrMReticle (sref);

CREATE TABLE TblPlnrMSession(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUser BIGINT,
	start INT,
	stop INT,
	Ip VARCHAR(30)
);
ALTER TABLE TblPlnrMSession OWNER TO epsi;
CREATE INDEX TblPlnrMSession_refPlnrMUser ON TblPlnrMSession (refPlnrMUser);
CREATE INDEX TblPlnrMSession_start ON TblPlnrMSession (start);

CREATE TABLE TblPlnrMStack(
	ref BIGSERIAL PRIMARY KEY,
	ixVBasetype INT,
	dsnRefPlnrMDesign BIGINT,
	dsnNum INT,
	sref VARCHAR(50),
	ixVModtype INT,
	ixVFlrAligntype INT,
	flrSrefPlnrMLevel VARCHAR(50),
	zFlr DOUBLE PRECISION,
	ixVCeilAligntype INT,
	ceilSrefPlnrMLevel VARCHAR(50),
	zCeil DOUBLE PRECISION,
	srefsPlnrMLayer VARCHAR(255),
	N VARCHAR(30)
);
ALTER TABLE TblPlnrMStack OWNER TO epsi;
CREATE INDEX TblPlnrMStack_ixVBasetype ON TblPlnrMStack (ixVBasetype);
CREATE INDEX TblPlnrMStack_dsnRefPlnrMDesign ON TblPlnrMStack (dsnRefPlnrMDesign);
CREATE INDEX TblPlnrMStack_dsnNum ON TblPlnrMStack (dsnNum);
CREATE INDEX TblPlnrMStack_sref ON TblPlnrMStack (sref);

CREATE TABLE TblPlnrMStructure(
	ref BIGSERIAL PRIMARY KEY,
	hkIxVTbl INT,
	hkUref BIGINT,
	sref VARCHAR(50),
	x0 DOUBLE PRECISION,
	x1 DOUBLE PRECISION,
	y0 DOUBLE PRECISION,
	y1 DOUBLE PRECISION
);
ALTER TABLE TblPlnrMStructure OWNER TO epsi;
CREATE INDEX TblPlnrMStructure_hkIxVTbl ON TblPlnrMStructure (hkIxVTbl);
CREATE INDEX TblPlnrMStructure_hkUref ON TblPlnrMStructure (hkUref);
CREATE INDEX TblPlnrMStructure_sref ON TblPlnrMStructure (sref);

CREATE TABLE TblPlnrMTapeout(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	ixVBasetype INT,
	Title VARCHAR(50),
	Major SMALLINT,
	Sub SMALLINT,
	refJState BIGINT,
	ixVState INT,
	Hflip SMALLINT,
	Comment TEXT
);
ALTER TABLE TblPlnrMTapeout OWNER TO epsi;
CREATE INDEX TblPlnrMTapeout_grp ON TblPlnrMTapeout (grp);
CREATE INDEX TblPlnrMTapeout_own ON TblPlnrMTapeout (own);
CREATE INDEX TblPlnrMTapeout_ixVBasetype ON TblPlnrMTapeout (ixVBasetype);
CREATE INDEX TblPlnrMTapeout_Title ON TblPlnrMTapeout (Title);

CREATE TABLE TblPlnrMUser(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	refRUsergroup BIGINT,
	refPlnrMUsergroup BIGINT,
	refPlnrMPerson BIGINT,
	sref VARCHAR(50),
	refJState BIGINT,
	ixVState INT,
	ixPlnrVLocale INT,
	ixPlnrVUserlevel INT,
	Password VARCHAR(30)
);
ALTER TABLE TblPlnrMUser OWNER TO epsi;
CREATE INDEX TblPlnrMUser_grp ON TblPlnrMUser (grp);
CREATE INDEX TblPlnrMUser_own ON TblPlnrMUser (own);
CREATE INDEX TblPlnrMUser_refPlnrMUsergroup ON TblPlnrMUser (refPlnrMUsergroup);
CREATE INDEX TblPlnrMUser_refPlnrMPerson ON TblPlnrMUser (refPlnrMPerson);
CREATE INDEX TblPlnrMUser_sref ON TblPlnrMUser (sref);

CREATE TABLE TblPlnrMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	grp BIGINT,
	own BIGINT,
	sref VARCHAR(50),
	Comment TEXT
);
ALTER TABLE TblPlnrMUsergroup OWNER TO epsi;
CREATE INDEX TblPlnrMUsergroup_grp ON TblPlnrMUsergroup (grp);
CREATE INDEX TblPlnrMUsergroup_own ON TblPlnrMUsergroup (own);
CREATE INDEX TblPlnrMUsergroup_sref ON TblPlnrMUsergroup (sref);

CREATE TABLE TblPlnrMVertex(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMDesign BIGINT,
	hkIxPlnrVLat INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	sref VARCHAR(50),
	x DOUBLE PRECISION,
	y DOUBLE PRECISION
);
ALTER TABLE TblPlnrMVertex OWNER TO epsi;
CREATE INDEX TblPlnrMVertex_x1RefPlnrMDesign ON TblPlnrMVertex (x1RefPlnrMDesign);
CREATE INDEX TblPlnrMVertex_hkIxPlnrVLat ON TblPlnrMVertex (hkIxPlnrVLat);
CREATE INDEX TblPlnrMVertex_hkIxVTbl ON TblPlnrMVertex (hkIxVTbl);
CREATE INDEX TblPlnrMVertex_hkUref ON TblPlnrMVertex (hkUref);
CREATE INDEX TblPlnrMVertex_sref ON TblPlnrMVertex (sref);

CREATE TABLE TblPlnrOMStructureMFace(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMStructure BIGINT,
	x1RefPlnrMDevice BIGINT,
	ixPlnrVLop INT,
	pr1RefM BIGINT
);
ALTER TABLE TblPlnrOMStructureMFace OWNER TO epsi;
CREATE INDEX TblPlnrOMStructureMFace_refPlnrMStructure ON TblPlnrOMStructureMFace (refPlnrMStructure);
CREATE INDEX TblPlnrOMStructureMFace_x1RefPlnrMDevice ON TblPlnrOMStructureMFace (x1RefPlnrMDevice);
CREATE INDEX TblPlnrOMStructureMFace_ixPlnrVLop ON TblPlnrOMStructureMFace (ixPlnrVLop);
CREATE INDEX TblPlnrOMStructureMFace_pr1RefM ON TblPlnrOMStructureMFace (pr1RefM);

CREATE TABLE TblPlnrRMCalcMDomain(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMCalc BIGINT,
	refPlnrMDomain BIGINT,
	srefPlnrKCalcdomprp VARCHAR(50)
);
ALTER TABLE TblPlnrRMCalcMDomain OWNER TO epsi;
CREATE INDEX TblPlnrRMCalcMDomain_refPlnrMCalc ON TblPlnrRMCalcMDomain (refPlnrMCalc);
CREATE INDEX TblPlnrRMCalcMDomain_refPlnrMDomain ON TblPlnrRMCalcMDomain (refPlnrMDomain);

CREATE TABLE TblPlnrRMCalcMFile(
	ref BIGSERIAL PRIMARY KEY,
	x1RefPlnrMCalcitem BIGINT,
	refPlnrMCalc BIGINT,
	refPlnrMFile BIGINT,
	ixVIo INT
);
ALTER TABLE TblPlnrRMCalcMFile OWNER TO epsi;
CREATE INDEX TblPlnrRMCalcMFile_x1RefPlnrMCalcitem ON TblPlnrRMCalcMFile (x1RefPlnrMCalcitem);
CREATE INDEX TblPlnrRMCalcMFile_refPlnrMCalc ON TblPlnrRMCalcMFile (refPlnrMCalc);
CREATE INDEX TblPlnrRMCalcMFile_refPlnrMFile ON TblPlnrRMCalcMFile (refPlnrMFile);

CREATE TABLE TblPlnrRMFaceMVertex(
	ref BIGSERIAL PRIMARY KEY,
	fceRefPlnrMFace BIGINT,
	fceNum INT,
	refPlnrMVertex BIGINT,
	rteIxVTbl INT,
	rteUref BIGINT,
	ixVDir INT
);
ALTER TABLE TblPlnrRMFaceMVertex OWNER TO epsi;
CREATE INDEX TblPlnrRMFaceMVertex_fceRefPlnrMFace ON TblPlnrRMFaceMVertex (fceRefPlnrMFace);
CREATE INDEX TblPlnrRMFaceMVertex_fceNum ON TblPlnrRMFaceMVertex (fceNum);
CREATE INDEX TblPlnrRMFaceMVertex_refPlnrMVertex ON TblPlnrRMFaceMVertex (refPlnrMVertex);
CREATE INDEX TblPlnrRMFaceMVertex_rteIxVTbl ON TblPlnrRMFaceMVertex (rteIxVTbl);
CREATE INDEX TblPlnrRMFaceMVertex_rteUref ON TblPlnrRMFaceMVertex (rteUref);

CREATE TABLE TblPlnrRMLayerMStructure(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMLayer BIGINT,
	refPlnrMStructure BIGINT
);
ALTER TABLE TblPlnrRMLayerMStructure OWNER TO epsi;
CREATE INDEX TblPlnrRMLayerMStructure_refPlnrMLayer ON TblPlnrRMLayerMStructure (refPlnrMLayer);
CREATE INDEX TblPlnrRMLayerMStructure_refPlnrMStructure ON TblPlnrRMLayerMStructure (refPlnrMStructure);

CREATE TABLE TblPlnrRMLevelMLevel(
	ref BIGSERIAL PRIMARY KEY,
	stkRefPlnrMLevel BIGINT,
	dsnRefPlnrMLevel BIGINT
);
ALTER TABLE TblPlnrRMLevelMLevel OWNER TO epsi;
CREATE INDEX TblPlnrRMLevelMLevel_stkRefPlnrMLevel ON TblPlnrRMLevelMLevel (stkRefPlnrMLevel);
CREATE INDEX TblPlnrRMLevelMLevel_dsnRefPlnrMLevel ON TblPlnrRMLevelMLevel (dsnRefPlnrMLevel);

CREATE TABLE TblPlnrRMLineguideMLineguide(
	ref BIGSERIAL PRIMARY KEY,
	devRefPlnrMLineguide BIGINT,
	dsnRefPlnrMLineguide BIGINT
);
ALTER TABLE TblPlnrRMLineguideMLineguide OWNER TO epsi;
CREATE INDEX TblPlnrRMLineguideMLineguide_devRefPlnrMLineguide ON TblPlnrRMLineguideMLineguide (devRefPlnrMLineguide);
CREATE INDEX TblPlnrRMLineguideMLineguide_dsnRefPlnrMLineguide ON TblPlnrRMLineguideMLineguide (dsnRefPlnrMLineguide);

CREATE TABLE TblPlnrRMProjectMTapeout(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMProject BIGINT,
	refPlnrMTapeout BIGINT
);
ALTER TABLE TblPlnrRMProjectMTapeout OWNER TO epsi;
CREATE INDEX TblPlnrRMProjectMTapeout_refPlnrMProject ON TblPlnrRMProjectMTapeout (refPlnrMProject);
CREATE INDEX TblPlnrRMProjectMTapeout_refPlnrMTapeout ON TblPlnrRMProjectMTapeout (refPlnrMTapeout);

CREATE TABLE TblPlnrRMStackMStructure(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMStack BIGINT,
	refPlnrMStructure BIGINT,
	fromSrefPlnrMLayer VARCHAR(50),
	toSrefPlnrMLayer VARCHAR(50)
);
ALTER TABLE TblPlnrRMStackMStructure OWNER TO epsi;
CREATE INDEX TblPlnrRMStackMStructure_refPlnrMStack ON TblPlnrRMStackMStructure (refPlnrMStack);
CREATE INDEX TblPlnrRMStackMStructure_refPlnrMStructure ON TblPlnrRMStackMStructure (refPlnrMStructure);

CREATE TABLE TblPlnrRMUsergroupUniversal(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUsergroup BIGINT,
	unvIxPlnrVMaintable INT,
	unvUref BIGINT,
	ixPlnrVAccess INT
);
ALTER TABLE TblPlnrRMUsergroupUniversal OWNER TO epsi;
CREATE INDEX TblPlnrRMUsergroupUniversal_refPlnrMUsergroup ON TblPlnrRMUsergroupUniversal (refPlnrMUsergroup);
CREATE INDEX TblPlnrRMUsergroupUniversal_unvIxPlnrVMaintable ON TblPlnrRMUsergroupUniversal (unvIxPlnrVMaintable);
CREATE INDEX TblPlnrRMUsergroupUniversal_unvUref ON TblPlnrRMUsergroupUniversal (unvUref);

CREATE TABLE TblPlnrRMUserMUsergroup(
	ref BIGSERIAL PRIMARY KEY,
	refPlnrMUser BIGINT,
	refPlnrMUsergroup BIGINT,
	ixPlnrVUserlevel INT
);
ALTER TABLE TblPlnrRMUserMUsergroup OWNER TO epsi;
CREATE INDEX TblPlnrRMUserMUsergroup_refPlnrMUser ON TblPlnrRMUserMUsergroup (refPlnrMUser);
CREATE INDEX TblPlnrRMUserMUsergroup_refPlnrMUsergroup ON TblPlnrRMUserMUsergroup (refPlnrMUsergroup);

CREATE TABLE TblPlnrRMVertexMVertex(
	ref BIGSERIAL PRIMARY KEY,
	devRefPlnrMVertex BIGINT,
	dsnRefPlnrMVertex BIGINT
);
ALTER TABLE TblPlnrRMVertexMVertex OWNER TO epsi;
CREATE INDEX TblPlnrRMVertexMVertex_devRefPlnrMVertex ON TblPlnrRMVertexMVertex (devRefPlnrMVertex);
CREATE INDEX TblPlnrRMVertexMVertex_dsnRefPlnrMVertex ON TblPlnrRMVertexMVertex (dsnRefPlnrMVertex);

CREATE TABLE TblPlnrQAriAMArrayEnv(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQAriAMArrayEnv OWNER TO epsi;
CREATE INDEX TblPlnrQAriAMArrayEnv_jref ON TblPlnrQAriAMArrayEnv (jref);
CREATE INDEX TblPlnrQAriAMArrayEnv_jnum ON TblPlnrQAriAMArrayEnv (jnum);

CREATE TABLE TblPlnrQAriList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	i SMALLINT,
	j SMALLINT,
	k SMALLINT,
	l SMALLINT,
	m SMALLINT,
	n SMALLINT,
	refPlnrMArray BIGINT,
	refPlnrMDesign BIGINT,
	dx DOUBLE PRECISION,
	dy DOUBLE PRECISION
);
ALTER TABLE TblPlnrQAriList OWNER TO epsi;
CREATE INDEX TblPlnrQAriList_jref ON TblPlnrQAriList (jref);
CREATE INDEX TblPlnrQAriList_jnum ON TblPlnrQAriList (jnum);

CREATE TABLE TblPlnrQArr1NArrayitem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQArr1NArrayitem OWNER TO epsi;
CREATE INDEX TblPlnrQArr1NArrayitem_jref ON TblPlnrQArr1NArrayitem (jref);
CREATE INDEX TblPlnrQArr1NArrayitem_jnum ON TblPlnrQArr1NArrayitem (jnum);

CREATE TABLE TblPlnrQArrAEnv(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMArrayitem BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQArrAEnv OWNER TO epsi;
CREATE INDEX TblPlnrQArrAEnv_jref ON TblPlnrQArrAEnv (jref);
CREATE INDEX TblPlnrQArrAEnv_jnum ON TblPlnrQArrAEnv (jnum);

CREATE TABLE TblPlnrQArrHk1NReticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQArrHk1NReticle OWNER TO epsi;
CREATE INDEX TblPlnrQArrHk1NReticle_jref ON TblPlnrQArrHk1NReticle (jref);
CREATE INDEX TblPlnrQArrHk1NReticle_jnum ON TblPlnrQArrHk1NReticle (jnum);

CREATE TABLE TblPlnrQArrKEnvKey(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQArrKEnvKey OWNER TO epsi;
CREATE INDEX TblPlnrQArrKEnvKey_jref ON TblPlnrQArrKEnvKey (jref);
CREATE INDEX TblPlnrQArrKEnvKey_jnum ON TblPlnrQArrKEnvKey (jnum);

CREATE TABLE TblPlnrQArrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	refPlnrMTapeout BIGINT,
	refPlnrMDesign BIGINT,
	I SMALLINT,
	J SMALLINT,
	K SMALLINT,
	L SMALLINT,
	M SMALLINT,
	N SMALLINT
);
ALTER TABLE TblPlnrQArrList OWNER TO epsi;
CREATE INDEX TblPlnrQArrList_jref ON TblPlnrQArrList (jref);
CREATE INDEX TblPlnrQArrList_jnum ON TblPlnrQArrList (jnum);

CREATE TABLE TblPlnrQClc1NMaterial(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQClc1NMaterial OWNER TO epsi;
CREATE INDEX TblPlnrQClc1NMaterial_jref ON TblPlnrQClc1NMaterial (jref);
CREATE INDEX TblPlnrQClc1NMaterial_jnum ON TblPlnrQClc1NMaterial (jnum);

CREATE TABLE TblPlnrQClcAEnv(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQClcAEnv OWNER TO epsi;
CREATE INDEX TblPlnrQClcAEnv_jref ON TblPlnrQClcAEnv (jref);
CREATE INDEX TblPlnrQClcAEnv_jnum ON TblPlnrQClcAEnv (jnum);

CREATE TABLE TblPlnrQClcAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	x2SrefKCat VARCHAR(50),
	x3SrefKProp VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQClcAPar OWNER TO epsi;
CREATE INDEX TblPlnrQClcAPar_jref ON TblPlnrQClcAPar (jref);
CREATE INDEX TblPlnrQClcAPar_jnum ON TblPlnrQClcAPar (jnum);

CREATE TABLE TblPlnrQClcCal1NCalcitem(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	calNum INT
);
ALTER TABLE TblPlnrQClcCal1NCalcitem OWNER TO epsi;
CREATE INDEX TblPlnrQClcCal1NCalcitem_jref ON TblPlnrQClcCal1NCalcitem (jref);
CREATE INDEX TblPlnrQClcCal1NCalcitem_jnum ON TblPlnrQClcCal1NCalcitem (jnum);

CREATE TABLE TblPlnrQClcList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	refPlnrMProject BIGINT,
	ixVDim INT,
	tplRefPlnrMCalc BIGINT,
	supRefPlnrMCalc BIGINT,
	refPlnrMDesign BIGINT
);
ALTER TABLE TblPlnrQClcList OWNER TO epsi;
CREATE INDEX TblPlnrQClcList_jref ON TblPlnrQClcList (jref);
CREATE INDEX TblPlnrQClcList_jnum ON TblPlnrQClcList (jnum);

CREATE TABLE TblPlnrQClcMNDomain(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	srefPlnrKCalcdomprp VARCHAR(50)
);
ALTER TABLE TblPlnrQClcMNDomain OWNER TO epsi;
CREATE INDEX TblPlnrQClcMNDomain_jref ON TblPlnrQClcMNDomain (jref);
CREATE INDEX TblPlnrQClcMNDomain_jnum ON TblPlnrQClcMNDomain (jnum);

CREATE TABLE TblPlnrQClcMNFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	ixVIo INT
);
ALTER TABLE TblPlnrQClcMNFile OWNER TO epsi;
CREATE INDEX TblPlnrQClcMNFile_jref ON TblPlnrQClcMNFile (jref);
CREATE INDEX TblPlnrQClcMNFile_jnum ON TblPlnrQClcMNFile (jnum);

CREATE TABLE TblPlnrQClcRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQClcRef1NFile OWNER TO epsi;
CREATE INDEX TblPlnrQClcRef1NFile_jref ON TblPlnrQClcRef1NFile (jref);
CREATE INDEX TblPlnrQClcRef1NFile_jnum ON TblPlnrQClcRef1NFile (jnum);

CREATE TABLE TblPlnrQClcSup1NCalc(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQClcSup1NCalc OWNER TO epsi;
CREATE INDEX TblPlnrQClcSup1NCalc_jref ON TblPlnrQClcSup1NCalc (jref);
CREATE INDEX TblPlnrQClcSup1NCalc_jnum ON TblPlnrQClcSup1NCalc (jnum);

CREATE TABLE TblPlnrQCliAAMCalcEnv(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQCliAAMCalcEnv OWNER TO epsi;
CREATE INDEX TblPlnrQCliAAMCalcEnv_jref ON TblPlnrQCliAAMCalcEnv (jref);
CREATE INDEX TblPlnrQCliAAMCalcEnv_jnum ON TblPlnrQCliAAMCalcEnv (jnum);

CREATE TABLE TblPlnrQCliAAMCalcPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x2SrefKCat VARCHAR(50),
	x3SrefKProp VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQCliAAMCalcPar OWNER TO epsi;
CREATE INDEX TblPlnrQCliAAMCalcPar_jref ON TblPlnrQCliAAMCalcPar (jref);
CREATE INDEX TblPlnrQCliAAMCalcPar_jnum ON TblPlnrQCliAAMCalcPar (jnum);

CREATE TABLE TblPlnrQCliList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	calRefPlnrMCalc BIGINT,
	refPlnrMDesign BIGINT
);
ALTER TABLE TblPlnrQCliList OWNER TO epsi;
CREATE INDEX TblPlnrQCliList_jref ON TblPlnrQCliList (jref);
CREATE INDEX TblPlnrQCliList_jnum ON TblPlnrQCliList (jnum);

CREATE TABLE TblPlnrQCliRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQCliRef1NFile OWNER TO epsi;
CREATE INDEX TblPlnrQCliRef1NFile_jref ON TblPlnrQCliRef1NFile (jref);
CREATE INDEX TblPlnrQCliRef1NFile_jnum ON TblPlnrQCliRef1NFile (jnum);

CREATE TABLE TblPlnrQCtpAEnv(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	x2SrefKKey VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQCtpAEnv OWNER TO epsi;
CREATE INDEX TblPlnrQCtpAEnv_jref ON TblPlnrQCtpAEnv (jref);
CREATE INDEX TblPlnrQCtpAEnv_jnum ON TblPlnrQCtpAEnv (jnum);

CREATE TABLE TblPlnrQCtpAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	x2SrefKCat VARCHAR(50),
	x3SrefKProp VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQCtpAPar OWNER TO epsi;
CREATE INDEX TblPlnrQCtpAPar_jref ON TblPlnrQCtpAPar (jref);
CREATE INDEX TblPlnrQCtpAPar_jnum ON TblPlnrQCtpAPar (jnum);

CREATE TABLE TblPlnrQCtpKCalcdomprp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQCtpKCalcdomprp OWNER TO epsi;
CREATE INDEX TblPlnrQCtpKCalcdomprp_jref ON TblPlnrQCtpKCalcdomprp (jref);
CREATE INDEX TblPlnrQCtpKCalcdomprp_jnum ON TblPlnrQCtpKCalcdomprp (jnum);

CREATE TABLE TblPlnrQCtpKCalcvar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	Fixed SMALLINT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	Implied VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQCtpKCalcvar OWNER TO epsi;
CREATE INDEX TblPlnrQCtpKCalcvar_jref ON TblPlnrQCtpKCalcvar (jref);
CREATE INDEX TblPlnrQCtpKCalcvar_jnum ON TblPlnrQCtpKCalcvar (jnum);

CREATE TABLE TblPlnrQCtpKEnvKey(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	sref VARCHAR(50),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQCtpKEnvKey OWNER TO epsi;
CREATE INDEX TblPlnrQCtpKEnvKey_jref ON TblPlnrQCtpKEnvKey (jref);
CREATE INDEX TblPlnrQCtpKEnvKey_jnum ON TblPlnrQCtpKEnvKey (jnum);

CREATE TABLE TblPlnrQCtpKParCat(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	sref VARCHAR(50),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQCtpKParCat OWNER TO epsi;
CREATE INDEX TblPlnrQCtpKParCat_jref ON TblPlnrQCtpKParCat (jref);
CREATE INDEX TblPlnrQCtpKParCat_jnum ON TblPlnrQCtpKParCat (jnum);

CREATE TABLE TblPlnrQCtpKParProp(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	sref VARCHAR(50),
	Avail VARCHAR(255),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQCtpKParProp OWNER TO epsi;
CREATE INDEX TblPlnrQCtpKParProp_jref ON TblPlnrQCtpKParProp (jref);
CREATE INDEX TblPlnrQCtpKParProp_jnum ON TblPlnrQCtpKParProp (jnum);

CREATE TABLE TblPlnrQCtpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	ixVDim INT,
	supRefPlnrMCalc BIGINT
);
ALTER TABLE TblPlnrQCtpList OWNER TO epsi;
CREATE INDEX TblPlnrQCtpList_jref ON TblPlnrQCtpList (jref);
CREATE INDEX TblPlnrQCtpList_jnum ON TblPlnrQCtpList (jnum);

CREATE TABLE TblPlnrQCtpRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQCtpRef1NFile OWNER TO epsi;
CREATE INDEX TblPlnrQCtpRef1NFile_jref ON TblPlnrQCtpRef1NFile (jref);
CREATE INDEX TblPlnrQCtpRef1NFile_jnum ON TblPlnrQCtpRef1NFile (jnum);

CREATE TABLE TblPlnrQCtpSup1NCalc(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQCtpSup1NCalc OWNER TO epsi;
CREATE INDEX TblPlnrQCtpSup1NCalc_jref ON TblPlnrQCtpSup1NCalc (jref);
CREATE INDEX TblPlnrQCtpSup1NCalc_jnum ON TblPlnrQCtpSup1NCalc (jnum);

CREATE TABLE TblPlnrQCtpTpl1NCalc(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQCtpTpl1NCalc OWNER TO epsi;
CREATE INDEX TblPlnrQCtpTpl1NCalc_jref ON TblPlnrQCtpTpl1NCalc (jref);
CREATE INDEX TblPlnrQCtpTpl1NCalc_jnum ON TblPlnrQCtpTpl1NCalc (jnum);

CREATE TABLE TblPlnrQDgdList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	dsnRefPlnrMDesign BIGINT
);
ALTER TABLE TblPlnrQDgdList OWNER TO epsi;
CREATE INDEX TblPlnrQDgdList_jref ON TblPlnrQDgdList (jref);
CREATE INDEX TblPlnrQDgdList_jnum ON TblPlnrQDgdList (jnum);

CREATE TABLE TblPlnrQDomList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	dsnRefPlnrMDesign BIGINT
);
ALTER TABLE TblPlnrQDomList OWNER TO epsi;
CREATE INDEX TblPlnrQDomList_jref ON TblPlnrQDomList (jref);
CREATE INDEX TblPlnrQDomList_jnum ON TblPlnrQDomList (jnum);

CREATE TABLE TblPlnrQDomMNCalc(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	srefPlnrKCalcdomprp VARCHAR(50)
);
ALTER TABLE TblPlnrQDomMNCalc OWNER TO epsi;
CREATE INDEX TblPlnrQDomMNCalc_jref ON TblPlnrQDomMNCalc (jref);
CREATE INDEX TblPlnrQDomMNCalc_jnum ON TblPlnrQDomMNCalc (jnum);

CREATE TABLE TblPlnrQDsn1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsn1NBlock OWNER TO epsi;
CREATE INDEX TblPlnrQDsn1NBlock_jref ON TblPlnrQDsn1NBlock (jref);
CREATE INDEX TblPlnrQDsn1NBlock_jnum ON TblPlnrQDsn1NBlock (jnum);

CREATE TABLE TblPlnrQDsn1NReticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsn1NReticle OWNER TO epsi;
CREATE INDEX TblPlnrQDsn1NReticle_jref ON TblPlnrQDsn1NReticle (jref);
CREATE INDEX TblPlnrQDsn1NReticle_jnum ON TblPlnrQDsn1NReticle (jnum);

CREATE TABLE TblPlnrQDsnDrv1NDesign(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnDrv1NDesign OWNER TO epsi;
CREATE INDEX TblPlnrQDsnDrv1NDesign_jref ON TblPlnrQDsnDrv1NDesign (jref);
CREATE INDEX TblPlnrQDsnDrv1NDesign_jnum ON TblPlnrQDsnDrv1NDesign (jnum);

CREATE TABLE TblPlnrQDsnDsn1NDevice(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	dsnNum INT
);
ALTER TABLE TblPlnrQDsnDsn1NDevice OWNER TO epsi;
CREATE INDEX TblPlnrQDsnDsn1NDevice_jref ON TblPlnrQDsnDsn1NDevice (jref);
CREATE INDEX TblPlnrQDsnDsn1NDevice_jnum ON TblPlnrQDsnDsn1NDevice (jnum);

CREATE TABLE TblPlnrQDsnDsn1NDomain(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	dsnNum INT
);
ALTER TABLE TblPlnrQDsnDsn1NDomain OWNER TO epsi;
CREATE INDEX TblPlnrQDsnDsn1NDomain_jref ON TblPlnrQDsnDsn1NDomain (jref);
CREATE INDEX TblPlnrQDsnDsn1NDomain_jnum ON TblPlnrQDsnDsn1NDomain (jnum);

CREATE TABLE TblPlnrQDsnDsn1NDomaingd(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	dsnNum INT
);
ALTER TABLE TblPlnrQDsnDsn1NDomaingd OWNER TO epsi;
CREATE INDEX TblPlnrQDsnDsn1NDomaingd_jref ON TblPlnrQDsnDsn1NDomaingd (jref);
CREATE INDEX TblPlnrQDsnDsn1NDomaingd_jnum ON TblPlnrQDsnDsn1NDomaingd (jnum);

CREATE TABLE TblPlnrQDsnDsn1NStack(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	dsnNum INT
);
ALTER TABLE TblPlnrQDsnDsn1NStack OWNER TO epsi;
CREATE INDEX TblPlnrQDsnDsn1NStack_jref ON TblPlnrQDsnDsn1NStack (jref);
CREATE INDEX TblPlnrQDsnDsn1NStack_jnum ON TblPlnrQDsnDsn1NStack (jnum);

CREATE TABLE TblPlnrQDsnHk1NArcguide(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnHk1NArcguide OWNER TO epsi;
CREATE INDEX TblPlnrQDsnHk1NArcguide_jref ON TblPlnrQDsnHk1NArcguide (jref);
CREATE INDEX TblPlnrQDsnHk1NArcguide_jnum ON TblPlnrQDsnHk1NArcguide (jnum);

CREATE TABLE TblPlnrQDsnHk1NLayer(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblPlnrQDsnHk1NLayer OWNER TO epsi;
CREATE INDEX TblPlnrQDsnHk1NLayer_jref ON TblPlnrQDsnHk1NLayer (jref);
CREATE INDEX TblPlnrQDsnHk1NLayer_jnum ON TblPlnrQDsnHk1NLayer (jnum);

CREATE TABLE TblPlnrQDsnHk1NLevel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnHk1NLevel OWNER TO epsi;
CREATE INDEX TblPlnrQDsnHk1NLevel_jref ON TblPlnrQDsnHk1NLevel (jref);
CREATE INDEX TblPlnrQDsnHk1NLevel_jnum ON TblPlnrQDsnHk1NLevel (jnum);

CREATE TABLE TblPlnrQDsnHk1NLineguide(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnHk1NLineguide OWNER TO epsi;
CREATE INDEX TblPlnrQDsnHk1NLineguide_jref ON TblPlnrQDsnHk1NLineguide (jref);
CREATE INDEX TblPlnrQDsnHk1NLineguide_jnum ON TblPlnrQDsnHk1NLineguide (jnum);

CREATE TABLE TblPlnrQDsnHk1NStructure(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnHk1NStructure OWNER TO epsi;
CREATE INDEX TblPlnrQDsnHk1NStructure_jref ON TblPlnrQDsnHk1NStructure (jref);
CREATE INDEX TblPlnrQDsnHk1NStructure_jnum ON TblPlnrQDsnHk1NStructure (jnum);

CREATE TABLE TblPlnrQDsnHk1NVertex(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnHk1NVertex OWNER TO epsi;
CREATE INDEX TblPlnrQDsnHk1NVertex_jref ON TblPlnrQDsnHk1NVertex (jref);
CREATE INDEX TblPlnrQDsnHk1NVertex_jnum ON TblPlnrQDsnHk1NVertex (jnum);

CREATE TABLE TblPlnrQDsnList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	ixVBasetype INT,
	ixVDim INT,
	refIxVTbl INT,
	refUref BIGINT,
	refPlnrMProject BIGINT,
	ixWModtype INT,
	modRefPlnrMDesign BIGINT,
	drvRefPlnrMDesign BIGINT,
	Major SMALLINT,
	Sub SMALLINT
);
ALTER TABLE TblPlnrQDsnList OWNER TO epsi;
CREATE INDEX TblPlnrQDsnList_jref ON TblPlnrQDsnList (jref);
CREATE INDEX TblPlnrQDsnList_jnum ON TblPlnrQDsnList (jnum);

CREATE TABLE TblPlnrQDsnMod1NDesign(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDsnMod1NDesign OWNER TO epsi;
CREATE INDEX TblPlnrQDsnMod1NDesign_jref ON TblPlnrQDsnMod1NDesign (jref);
CREATE INDEX TblPlnrQDsnMod1NDesign_jnum ON TblPlnrQDsnMod1NDesign (jnum);

CREATE TABLE TblPlnrQDtpAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x2SrefKKey VARCHAR(50),
	refPlnrMFile BIGINT,
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQDtpAPar OWNER TO epsi;
CREATE INDEX TblPlnrQDtpAPar_jref ON TblPlnrQDtpAPar (jref);
CREATE INDEX TblPlnrQDtpAPar_jnum ON TblPlnrQDtpAPar (jnum);

CREATE TABLE TblPlnrQDtpHk1NStructure(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDtpHk1NStructure OWNER TO epsi;
CREATE INDEX TblPlnrQDtpHk1NStructure_jref ON TblPlnrQDtpHk1NStructure (jref);
CREATE INDEX TblPlnrQDtpHk1NStructure_jnum ON TblPlnrQDtpHk1NStructure (jnum);

CREATE TABLE TblPlnrQDtpKParKey(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	klsNum INT,
	sref VARCHAR(50),
	refJ BIGINT,
	Title VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQDtpKParKey OWNER TO epsi;
CREATE INDEX TblPlnrQDtpKParKey_jref ON TblPlnrQDtpKParKey (jref);
CREATE INDEX TblPlnrQDtpKParKey_jnum ON TblPlnrQDtpKParKey (jnum);

CREATE TABLE TblPlnrQDtpList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	supRefPlnrMDevice BIGINT,
	ixVAligntype INT
);
ALTER TABLE TblPlnrQDtpList OWNER TO epsi;
CREATE INDEX TblPlnrQDtpList_jref ON TblPlnrQDtpList (jref);
CREATE INDEX TblPlnrQDtpList_jnum ON TblPlnrQDtpList (jnum);

CREATE TABLE TblPlnrQDtpSup1NDevice(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	supNum INT
);
ALTER TABLE TblPlnrQDtpSup1NDevice OWNER TO epsi;
CREATE INDEX TblPlnrQDtpSup1NDevice_jref ON TblPlnrQDtpSup1NDevice (jref);
CREATE INDEX TblPlnrQDtpSup1NDevice_jnum ON TblPlnrQDtpSup1NDevice (jnum);

CREATE TABLE TblPlnrQDtpTpl1NDevice(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDtpTpl1NDevice OWNER TO epsi;
CREATE INDEX TblPlnrQDtpTpl1NDevice_jref ON TblPlnrQDtpTpl1NDevice (jref);
CREATE INDEX TblPlnrQDtpTpl1NDevice_jnum ON TblPlnrQDtpTpl1NDevice (jnum);

CREATE TABLE TblPlnrQDvcAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMDesign BIGINT,
	x2SrefKKey VARCHAR(50),
	refPlnrMFile BIGINT,
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQDvcAPar OWNER TO epsi;
CREATE INDEX TblPlnrQDvcAPar_jref ON TblPlnrQDvcAPar (jref);
CREATE INDEX TblPlnrQDvcAPar_jnum ON TblPlnrQDvcAPar (jnum);

CREATE TABLE TblPlnrQDvcHk1NArcguide(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDvcHk1NArcguide OWNER TO epsi;
CREATE INDEX TblPlnrQDvcHk1NArcguide_jref ON TblPlnrQDvcHk1NArcguide (jref);
CREATE INDEX TblPlnrQDvcHk1NArcguide_jnum ON TblPlnrQDvcHk1NArcguide (jnum);

CREATE TABLE TblPlnrQDvcHk1NLineguide(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDvcHk1NLineguide OWNER TO epsi;
CREATE INDEX TblPlnrQDvcHk1NLineguide_jref ON TblPlnrQDvcHk1NLineguide (jref);
CREATE INDEX TblPlnrQDvcHk1NLineguide_jnum ON TblPlnrQDvcHk1NLineguide (jnum);

CREATE TABLE TblPlnrQDvcHk1NStructure(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDvcHk1NStructure OWNER TO epsi;
CREATE INDEX TblPlnrQDvcHk1NStructure_jref ON TblPlnrQDvcHk1NStructure (jref);
CREATE INDEX TblPlnrQDvcHk1NStructure_jnum ON TblPlnrQDvcHk1NStructure (jnum);

CREATE TABLE TblPlnrQDvcHk1NVertex(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQDvcHk1NVertex OWNER TO epsi;
CREATE INDEX TblPlnrQDvcHk1NVertex_jref ON TblPlnrQDvcHk1NVertex (jref);
CREATE INDEX TblPlnrQDvcHk1NVertex_jnum ON TblPlnrQDvcHk1NVertex (jnum);

CREATE TABLE TblPlnrQDvcList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	dsnRefPlnrMDesign BIGINT,
	supRefPlnrMDevice BIGINT,
	tplRefPlnrMDevice BIGINT,
	ixVModtype INT,
	ixVAligntype INT
);
ALTER TABLE TblPlnrQDvcList OWNER TO epsi;
CREATE INDEX TblPlnrQDvcList_jref ON TblPlnrQDvcList (jref);
CREATE INDEX TblPlnrQDvcList_jnum ON TblPlnrQDvcList (jnum);

CREATE TABLE TblPlnrQDvcSup1NDevice(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	supNum INT
);
ALTER TABLE TblPlnrQDvcSup1NDevice OWNER TO epsi;
CREATE INDEX TblPlnrQDvcSup1NDevice_jref ON TblPlnrQDvcSup1NDevice (jref);
CREATE INDEX TblPlnrQDvcSup1NDevice_jnum ON TblPlnrQDvcSup1NDevice (jnum);

CREATE TABLE TblPlnrQFilList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Filename VARCHAR(50),
	refIxVTbl INT,
	refUref BIGINT,
	osrefKContent VARCHAR(50),
	srefKMimetype VARCHAR(50),
	Size INT
);
ALTER TABLE TblPlnrQFilList OWNER TO epsi;
CREATE INDEX TblPlnrQFilList_jref ON TblPlnrQFilList (jref);
CREATE INDEX TblPlnrQFilList_jnum ON TblPlnrQFilList (jnum);

CREATE TABLE TblPlnrQFilMNCalc(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	x1RefPlnrMCalcitem BIGINT,
	ixVIo INT
);
ALTER TABLE TblPlnrQFilMNCalc OWNER TO epsi;
CREATE INDEX TblPlnrQFilMNCalc_jref ON TblPlnrQFilMNCalc (jref);
CREATE INDEX TblPlnrQFilMNCalc_jnum ON TblPlnrQFilMNCalc (jnum);

CREATE TABLE TblPlnrQLyr1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQLyr1NBlock OWNER TO epsi;
CREATE INDEX TblPlnrQLyr1NBlock_jref ON TblPlnrQLyr1NBlock (jref);
CREATE INDEX TblPlnrQLyr1NBlock_jnum ON TblPlnrQLyr1NBlock (jnum);

CREATE TABLE TblPlnrQLyr1NReticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQLyr1NReticle OWNER TO epsi;
CREATE INDEX TblPlnrQLyr1NReticle_jref ON TblPlnrQLyr1NReticle (jref);
CREATE INDEX TblPlnrQLyr1NReticle_jnum ON TblPlnrQLyr1NReticle (jnum);

CREATE TABLE TblPlnrQLyrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	x1RefPlnrMDesign BIGINT,
	ixVBasetype INT,
	hkIxVTbl INT,
	hkUref BIGINT,
	refPlnrMMaterial BIGINT,
	ixVTtype INT
);
ALTER TABLE TblPlnrQLyrList OWNER TO epsi;
CREATE INDEX TblPlnrQLyrList_jref ON TblPlnrQLyrList (jref);
CREATE INDEX TblPlnrQLyrList_jnum ON TblPlnrQLyrList (jnum);

CREATE TABLE TblPlnrQLyrMNStructure(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblPlnrQLyrMNStructure OWNER TO epsi;
CREATE INDEX TblPlnrQLyrMNStructure_jref ON TblPlnrQLyrMNStructure (jref);
CREATE INDEX TblPlnrQLyrMNStructure_jnum ON TblPlnrQLyrMNStructure (jnum);

CREATE TABLE TblPlnrQMat1NLayer(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQMat1NLayer OWNER TO epsi;
CREATE INDEX TblPlnrQMat1NLayer_jref ON TblPlnrQMat1NLayer (jref);
CREATE INDEX TblPlnrQMat1NLayer_jnum ON TblPlnrQMat1NLayer (jnum);

CREATE TABLE TblPlnrQMatAPar(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1RefPlnrMDesign BIGINT,
	x2SrefKCat VARCHAR(50),
	x3SrefKProp VARCHAR(50),
	refPlnrMFile BIGINT,
	Val VARCHAR(255),
	Comment TEXT
);
ALTER TABLE TblPlnrQMatAPar OWNER TO epsi;
CREATE INDEX TblPlnrQMatAPar_jref ON TblPlnrQMatAPar (jref);
CREATE INDEX TblPlnrQMatAPar_jnum ON TblPlnrQMatAPar (jnum);

CREATE TABLE TblPlnrQMatList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	Title VARCHAR(50),
	ixVBasetype INT,
	refPlnrMCalc BIGINT,
	modRefPlnrMMaterial BIGINT
);
ALTER TABLE TblPlnrQMatList OWNER TO epsi;
CREATE INDEX TblPlnrQMatList_jref ON TblPlnrQMatList (jref);
CREATE INDEX TblPlnrQMatList_jnum ON TblPlnrQMatList (jnum);

CREATE TABLE TblPlnrQMatMod1NMaterial(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQMatMod1NMaterial OWNER TO epsi;
CREATE INDEX TblPlnrQMatMod1NMaterial_jref ON TblPlnrQMatMod1NMaterial (jref);
CREATE INDEX TblPlnrQMatMod1NMaterial_jnum ON TblPlnrQMatMod1NMaterial (jnum);

CREATE TABLE TblPlnrQMatRef1NFile(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQMatRef1NFile OWNER TO epsi;
CREATE INDEX TblPlnrQMatRef1NFile_jref ON TblPlnrQMatRef1NFile (jref);
CREATE INDEX TblPlnrQMatRef1NFile_jnum ON TblPlnrQMatRef1NFile (jnum);

CREATE TABLE TblPlnrQPreselect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQPreselect OWNER TO epsi;
CREATE INDEX TblPlnrQPreselect_jref ON TblPlnrQPreselect (jref);

CREATE TABLE TblPlnrQPrj1NCalc(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQPrj1NCalc OWNER TO epsi;
CREATE INDEX TblPlnrQPrj1NCalc_jref ON TblPlnrQPrj1NCalc (jref);
CREATE INDEX TblPlnrQPrj1NCalc_jnum ON TblPlnrQPrj1NCalc (jnum);

CREATE TABLE TblPlnrQPrj1NDesign(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQPrj1NDesign OWNER TO epsi;
CREATE INDEX TblPlnrQPrj1NDesign_jref ON TblPlnrQPrj1NDesign (jref);
CREATE INDEX TblPlnrQPrj1NDesign_jnum ON TblPlnrQPrj1NDesign (jnum);

CREATE TABLE TblPlnrQPrjList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	ixVState INT
);
ALTER TABLE TblPlnrQPrjList OWNER TO epsi;
CREATE INDEX TblPlnrQPrjList_jref ON TblPlnrQPrjList (jref);
CREATE INDEX TblPlnrQPrjList_jnum ON TblPlnrQPrjList (jnum);

CREATE TABLE TblPlnrQPrjMNTapeout(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblPlnrQPrjMNTapeout OWNER TO epsi;
CREATE INDEX TblPlnrQPrjMNTapeout_jref ON TblPlnrQPrjMNTapeout (jref);
CREATE INDEX TblPlnrQPrjMNTapeout_jnum ON TblPlnrQPrjMNTapeout (jnum);

CREATE TABLE TblPlnrQPrsADetail(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1SrefKType VARCHAR(50),
	Val VARCHAR(255)
);
ALTER TABLE TblPlnrQPrsADetail OWNER TO epsi;
CREATE INDEX TblPlnrQPrsADetail_jref ON TblPlnrQPrsADetail (jref);
CREATE INDEX TblPlnrQPrsADetail_jnum ON TblPlnrQPrsADetail (jnum);

CREATE TABLE TblPlnrQPrsList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(30),
	Firstname VARCHAR(30),
	Lastname VARCHAR(50),
	grp BIGINT,
	own BIGINT,
	ixVSex INT,
	Tel VARCHAR(255),
	Eml VARCHAR(255)
);
ALTER TABLE TblPlnrQPrsList OWNER TO epsi;
CREATE INDEX TblPlnrQPrsList_jref ON TblPlnrQPrsList (jref);
CREATE INDEX TblPlnrQPrsList_jnum ON TblPlnrQPrsList (jnum);

CREATE TABLE TblPlnrQRtcList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	hkIxVTbl INT,
	hkUref BIGINT,
	refPlnrMDesign BIGINT,
	refPlnrMLayer BIGINT
);
ALTER TABLE TblPlnrQRtcList OWNER TO epsi;
CREATE INDEX TblPlnrQRtcList_jref ON TblPlnrQRtcList (jref);
CREATE INDEX TblPlnrQRtcList_jnum ON TblPlnrQRtcList (jnum);

CREATE TABLE TblPlnrQSelect(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ix INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQSelect OWNER TO epsi;
CREATE INDEX TblPlnrQSelect_jref ON TblPlnrQSelect (jref);
CREATE INDEX TblPlnrQSelect_ix ON TblPlnrQSelect (ix);

CREATE TABLE TblPlnrQSru1NBlock(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQSru1NBlock OWNER TO epsi;
CREATE INDEX TblPlnrQSru1NBlock_jref ON TblPlnrQSru1NBlock (jref);
CREATE INDEX TblPlnrQSru1NBlock_jnum ON TblPlnrQSru1NBlock (jnum);

CREATE TABLE TblPlnrQSruList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	hkIxVTbl INT,
	hkUref BIGINT
);
ALTER TABLE TblPlnrQSruList OWNER TO epsi;
CREATE INDEX TblPlnrQSruList_jref ON TblPlnrQSruList (jref);
CREATE INDEX TblPlnrQSruList_jnum ON TblPlnrQSruList (jnum);

CREATE TABLE TblPlnrQSruMNLayer(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblPlnrQSruMNLayer OWNER TO epsi;
CREATE INDEX TblPlnrQSruMNLayer_jref ON TblPlnrQSruMNLayer (jref);
CREATE INDEX TblPlnrQSruMNLayer_jnum ON TblPlnrQSruMNLayer (jnum);

CREATE TABLE TblPlnrQSruMNStack(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	fromSrefPlnrMLayer VARCHAR(50),
	toSrefPlnrMLayer VARCHAR(50)
);
ALTER TABLE TblPlnrQSruMNStack OWNER TO epsi;
CREATE INDEX TblPlnrQSruMNStack_jref ON TblPlnrQSruMNStack (jref);
CREATE INDEX TblPlnrQSruMNStack_jnum ON TblPlnrQSruMNStack (jnum);

CREATE TABLE TblPlnrQSruSru1NFace(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQSruSru1NFace OWNER TO epsi;
CREATE INDEX TblPlnrQSruSru1NFace_jref ON TblPlnrQSruSru1NFace (jref);
CREATE INDEX TblPlnrQSruSru1NFace_jnum ON TblPlnrQSruSru1NFace (jnum);

CREATE TABLE TblPlnrQStkHk1NLayer(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	hkNum INT
);
ALTER TABLE TblPlnrQStkHk1NLayer OWNER TO epsi;
CREATE INDEX TblPlnrQStkHk1NLayer_jref ON TblPlnrQStkHk1NLayer (jref);
CREATE INDEX TblPlnrQStkHk1NLayer_jnum ON TblPlnrQStkHk1NLayer (jnum);

CREATE TABLE TblPlnrQStkHk1NLevel(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQStkHk1NLevel OWNER TO epsi;
CREATE INDEX TblPlnrQStkHk1NLevel_jref ON TblPlnrQStkHk1NLevel (jref);
CREATE INDEX TblPlnrQStkHk1NLevel_jnum ON TblPlnrQStkHk1NLevel (jnum);

CREATE TABLE TblPlnrQStkList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50),
	ixVBasetype INT,
	dsnRefPlnrMDesign BIGINT,
	ixVModtype INT,
	ixVFlrAligntype INT,
	ixVCeilAligntype INT
);
ALTER TABLE TblPlnrQStkList OWNER TO epsi;
CREATE INDEX TblPlnrQStkList_jref ON TblPlnrQStkList (jref);
CREATE INDEX TblPlnrQStkList_jnum ON TblPlnrQStkList (jnum);

CREATE TABLE TblPlnrQStkMNStructure(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	fromSrefPlnrMLayer VARCHAR(50),
	toSrefPlnrMLayer VARCHAR(50)
);
ALTER TABLE TblPlnrQStkMNStructure OWNER TO epsi;
CREATE INDEX TblPlnrQStkMNStructure_jref ON TblPlnrQStkMNStructure (jref);
CREATE INDEX TblPlnrQStkMNStructure_jnum ON TblPlnrQStkMNStructure (jnum);

CREATE TABLE TblPlnrQTpo1NArray(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQTpo1NArray OWNER TO epsi;
CREATE INDEX TblPlnrQTpo1NArray_jref ON TblPlnrQTpo1NArray (jref);
CREATE INDEX TblPlnrQTpo1NArray_jnum ON TblPlnrQTpo1NArray (jnum);

CREATE TABLE TblPlnrQTpoHk1NReticle(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQTpoHk1NReticle OWNER TO epsi;
CREATE INDEX TblPlnrQTpoHk1NReticle_jref ON TblPlnrQTpoHk1NReticle (jref);
CREATE INDEX TblPlnrQTpoHk1NReticle_jnum ON TblPlnrQTpoHk1NReticle (jnum);

CREATE TABLE TblPlnrQTpoList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	Title VARCHAR(50),
	ixVBasetype INT,
	Major SMALLINT,
	Sub SMALLINT,
	ixVState INT,
	Hflip SMALLINT
);
ALTER TABLE TblPlnrQTpoList OWNER TO epsi;
CREATE INDEX TblPlnrQTpoList_jref ON TblPlnrQTpoList (jref);
CREATE INDEX TblPlnrQTpoList_jnum ON TblPlnrQTpoList (jnum);

CREATE TABLE TblPlnrQTpoMNProject(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT
);
ALTER TABLE TblPlnrQTpoMNProject OWNER TO epsi;
CREATE INDEX TblPlnrQTpoMNProject_jref ON TblPlnrQTpoMNProject (jref);
CREATE INDEX TblPlnrQTpoMNProject_jnum ON TblPlnrQTpoMNProject (jnum);

CREATE TABLE TblPlnrQUsgAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxPlnrVCard INT,
	ixPlnrWUiaccess INT
);
ALTER TABLE TblPlnrQUsgAAccess OWNER TO epsi;
CREATE INDEX TblPlnrQUsgAAccess_jref ON TblPlnrQUsgAAccess (jref);
CREATE INDEX TblPlnrQUsgAAccess_jnum ON TblPlnrQUsgAAccess (jnum);

CREATE TABLE TblPlnrQUsgList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	sref VARCHAR(50)
);
ALTER TABLE TblPlnrQUsgList OWNER TO epsi;
CREATE INDEX TblPlnrQUsgList_jref ON TblPlnrQUsgList (jref);
CREATE INDEX TblPlnrQUsgList_jnum ON TblPlnrQUsgList (jnum);

CREATE TABLE TblPlnrQUsgMNUser(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixPlnrVUserlevel INT
);
ALTER TABLE TblPlnrQUsgMNUser OWNER TO epsi;
CREATE INDEX TblPlnrQUsgMNUser_jref ON TblPlnrQUsgMNUser (jref);
CREATE INDEX TblPlnrQUsgMNUser_jnum ON TblPlnrQUsgMNUser (jnum);

CREATE TABLE TblPlnrQUsr1NSession(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT
);
ALTER TABLE TblPlnrQUsr1NSession OWNER TO epsi;
CREATE INDEX TblPlnrQUsr1NSession_jref ON TblPlnrQUsr1NSession (jref);
CREATE INDEX TblPlnrQUsr1NSession_jnum ON TblPlnrQUsr1NSession (jnum);

CREATE TABLE TblPlnrQUsrAAccess(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	x1IxPlnrVCard INT,
	ixPlnrWUiaccess INT
);
ALTER TABLE TblPlnrQUsrAAccess OWNER TO epsi;
CREATE INDEX TblPlnrQUsrAAccess_jref ON TblPlnrQUsrAAccess (jref);
CREATE INDEX TblPlnrQUsrAAccess_jnum ON TblPlnrQUsrAAccess (jnum);

CREATE TABLE TblPlnrQUsrList(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	ref BIGINT,
	refPlnrMPerson BIGINT,
	sref VARCHAR(50),
	refPlnrMUsergroup BIGINT,
	ixVState INT,
	ixPlnrVLocale INT,
	ixPlnrVUserlevel INT
);
ALTER TABLE TblPlnrQUsrList OWNER TO epsi;
CREATE INDEX TblPlnrQUsrList_jref ON TblPlnrQUsrList (jref);
CREATE INDEX TblPlnrQUsrList_jnum ON TblPlnrQUsrList (jnum);

CREATE TABLE TblPlnrQUsrMNUsergroup(
	qref BIGSERIAL PRIMARY KEY,
	jref BIGINT,
	jnum INT,
	mref BIGINT,
	ref BIGINT,
	ixPlnrVUserlevel INT
);
ALTER TABLE TblPlnrQUsrMNUsergroup OWNER TO epsi;
CREATE INDEX TblPlnrQUsrMNUsergroup_jref ON TblPlnrQUsrMNUsergroup (jref);
CREATE INDEX TblPlnrQUsrMNUsergroup_jnum ON TblPlnrQUsrMNUsergroup (jnum);

