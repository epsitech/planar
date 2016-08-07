# file Makefile
# make file for Plnr database access library, release dbsplnr_genio
# author Alexander Wirthmueller
# date created: 4 Dec 2015
# modified: 4 Dec 2015

SRCROOT = /home/epsi/src
LIBROOT = /home/epsi/lib

CC = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

INCS = -I/usr/include/libxml2 -I/usr/include/mysql -I/usr/include/postgresql
INCS += -I$(SRCROOT)
PCHS = DbsPlnr.h.gch
OBJECTS = DbsPlnr.o
OBJECTS += PlnrQAriAMArrayEnv.o PlnrQAriList.o PlnrQArr1NArrayitem.o PlnrQArrAEnv.o PlnrQArrHk1NReticle.o PlnrQArrKEnvKey.o PlnrQArrList.o PlnrQClc1NMaterial.o PlnrQClcAEnv.o PlnrQClcAPar.o PlnrQClcCal1NCalcitem.o PlnrQClcList.o PlnrQClcMNDomain.o PlnrQClcMNFile.o PlnrQClcRef1NFile.o PlnrQClcSup1NCalc.o PlnrQCliAAMCalcEnv.o PlnrQCliAAMCalcPar.o PlnrQCliList.o PlnrQCliRef1NFile.o PlnrQCtpAEnv.o PlnrQCtpAPar.o PlnrQCtpKCalcdomprp.o PlnrQCtpKCalcvar.o PlnrQCtpKEnvKey.o PlnrQCtpKParCat.o PlnrQCtpKParProp.o PlnrQCtpList.o PlnrQCtpRef1NFile.o PlnrQCtpSup1NCalc.o PlnrQCtpTpl1NCalc.o PlnrQDgdList.o PlnrQDomList.o PlnrQDomMNCalc.o PlnrQDsn1NBlock.o PlnrQDsn1NReticle.o PlnrQDsnDrv1NDesign.o PlnrQDsnDsn1NDevice.o PlnrQDsnDsn1NDomain.o PlnrQDsnDsn1NDomaingd.o PlnrQDsnDsn1NStack.o PlnrQDsnHk1NArcguide.o PlnrQDsnHk1NLayer.o PlnrQDsnHk1NLevel.o PlnrQDsnHk1NLineguide.o PlnrQDsnHk1NStructure.o PlnrQDsnHk1NVertex.o PlnrQDsnList.o PlnrQDsnMod1NDesign.o PlnrQDtpAPar.o PlnrQDtpHk1NStructure.o PlnrQDtpKParKey.o PlnrQDtpList.o PlnrQDtpSup1NDevice.o PlnrQDtpTpl1NDevice.o PlnrQDvcAPar.o PlnrQDvcHk1NArcguide.o PlnrQDvcHk1NLineguide.o PlnrQDvcHk1NStructure.o PlnrQDvcHk1NVertex.o PlnrQDvcList.o PlnrQDvcSup1NDevice.o PlnrQFilList.o PlnrQFilMNCalc.o PlnrQLyr1NBlock.o PlnrQLyr1NReticle.o PlnrQLyrList.o PlnrQLyrMNStructure.o PlnrQMat1NLayer.o PlnrQMatAPar.o PlnrQMatList.o PlnrQMatMod1NMaterial.o PlnrQMatRef1NFile.o PlnrQPreselect.o PlnrQPrj1NCalc.o PlnrQPrj1NDesign.o PlnrQPrjList.o PlnrQPrjMNTapeout.o PlnrQPrsADetail.o PlnrQPrsList.o PlnrQRtcList.o PlnrQSelect.o PlnrQSru1NBlock.o PlnrQSruList.o PlnrQSruMNLayer.o PlnrQSruMNStack.o PlnrQSruSru1NFace.o PlnrQStkHk1NLayer.o PlnrQStkHk1NLevel.o PlnrQStkList.o PlnrQStkMNStructure.o PlnrQTpo1NArray.o PlnrQTpoHk1NReticle.o PlnrQTpoList.o PlnrQTpoMNProject.o PlnrQUsgAAccess.o PlnrQUsgList.o PlnrQUsgMNUser.o PlnrQUsr1NSession.o PlnrQUsrAAccess.o PlnrQUsrList.o PlnrQUsrMNUsergroup.o
OBJECTS += PlnrAccRMUserUniversal.o PlnrAMArrayEnv.o PlnrAMCalcEnv.o PlnrAMCalcPar.o PlnrAMDevicePar.o PlnrAMMaterialPar.o PlnrAMPersonDetail.o PlnrAMUserAccess.o PlnrAMUsergroupAccess.o PlnrAVControlPar.o PlnrAVKeylistKey.o PlnrAVValuelistVal.o PlnrCFile.o PlnrDevOMDeviceMArcguide.o PlnrDevOMDeviceMLineguide.o PlnrDevOMDeviceMVertex.o PlnrDevORMArcguideMVertex.o PlnrDevORMLineguideMVertex.o PlnrHistRMUserUniversal.o PlnrJAVKeylistKey.o PlnrJMArcguideR.o PlnrJMDeviceModtype.o PlnrJMDomain.o PlnrJMDomaingd.o PlnrJMLayer.o PlnrJMLayerMaterial.o PlnrJMLevelZ.o PlnrJMPersonLastname.o PlnrJMProjectState.o PlnrJMStackModtype.o PlnrJMStackN.o PlnrJMTapeoutState.o PlnrJMUserState.o PlnrJMVertex.o PlnrLRMArcguideMVertex.o PlnrLRMLineguideMVertex.o PlnrMArcguide.o PlnrMArray.o PlnrMArrayitem.o PlnrMBlock.o PlnrMCalc.o PlnrMCalcitem.o PlnrMDesign.o PlnrMDevice.o PlnrMDomain.o PlnrMDomaingd.o PlnrMFace.o PlnrMFile.o PlnrMLayer.o PlnrMLevel.o PlnrMLineguide.o PlnrMMaterial.o PlnrMPerson.o PlnrMProject.o PlnrMReticle.o PlnrMSession.o PlnrMStack.o PlnrMStructure.o PlnrMTapeout.o PlnrMUser.o PlnrMUsergroup.o PlnrMVertex.o PlnrOMStructureMFace.o PlnrRMCalcMDomain.o PlnrRMCalcMFile.o PlnrRMFaceMVertex.o PlnrRMLayerMStructure.o PlnrRMLevelMLevel.o PlnrRMLineguideMLineguide.o PlnrRMProjectMTapeout.o PlnrRMStackMStructure.o PlnrRMUsergroupUniversal.o PlnrRMUserMUsergroup.o PlnrRMVertexMVertex.o
OBJECTS += VecPlnrVAccess.o VecPlnrVCard.o VecPlnrVControl.o VecPlnrVKeylist.o VecPlnrVLat.o VecPlnrVLocale.o VecPlnrVLop.o VecPlnrVMaintable.o VecPlnrVOolop.o VecPlnrVPreset.o VecPlnrVUserlevel.o VecPlnrVValuelist.o VecPlnrVMArcguideHkTbl.o VecPlnrVMCalcDim.o VecPlnrVMDesignBasetype.o VecPlnrVMDesignDim.o VecPlnrVMDesignRefTbl.o VecPlnrVMDeviceAligntype.o VecPlnrVMDeviceModtype.o VecPlnrVMDomainBasetype.o VecPlnrVMDomaingdBasetype.o VecPlnrVMFileRefTbl.o VecPlnrVMLayerBasetype.o VecPlnrVMLayerHkTbl.o VecPlnrVMLayerTtype.o VecPlnrVMLevelHkTbl.o VecPlnrVMLineguideHkTbl.o VecPlnrVMMaterialBasetype.o VecPlnrVMPersonSex.o VecPlnrVMProjectState.o VecPlnrVMReticleHkTbl.o VecPlnrVMStackBasetype.o VecPlnrVMStackCeilAligntype.o VecPlnrVMStackFlrAligntype.o VecPlnrVMStackModtype.o VecPlnrVMStructureHkTbl.o VecPlnrVMTapeoutBasetype.o VecPlnrVMTapeoutState.o VecPlnrVMUserState.o VecPlnrVMVertexHkTbl.o VecPlnrVRMCalcMFileIo.o VecPlnrVRMFaceMVertexDir.o VecPlnrVRMFaceMVertexRteTbl.o VecPlnrWUiaccess.o VecPlnrWMDesignModtype.o VecPlnrWMPersonDerivate.o

LIBRARY = libdbsplnr

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

.cpp.o :
	$(CC) $(CPPFLAGS) $(INCS) -o $@ -c $<

all:	$(LIBRARY)

$(LIBRARY):	$(PCHS) $(OBJECTS)
	ar rcs $(LIBRARY).a $(OBJECTS)

install:
	cp $(LIBRARY).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o

