/**
  * \file SqkPlnrExp.cpp
  * squawk generation for operation pack PlnrExp (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "SqkPlnrExp.h"

/******************************************************************************
 namespace SqkPlnrExp
 ******************************************************************************/

string SqkPlnrExp::getSquawkColldev(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpColldev* dpchinv
		) {
	string retval;
// IP getSquawkColldev --- IBEGIN
	retval = "collapse device '" + StubPlnr::getStubDevStd(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkColldev --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkColldsn(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpColldsn* dpchinv
		) {
	string retval;
// IP getSquawkColldsn --- IBEGIN
	retval = "collapse design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "'";
// IP getSquawkColldsn --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkCollstk(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpCollstk* dpchinv
		) {
	string retval;
// IP getSquawkCollstk --- IBEGIN
	retval = "collapse stack '" + StubPlnr::getStubStkStd(dbsplnr, dpchinv->refPlnrMStack) + "'";
// IP getSquawkCollstk --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkCorner(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpCorner* dpchinv
		) {
	string retval;
// IP getSquawkCorner --- IBEGIN
	retval = "expand 'corner' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkCorner --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkCross(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpCross* dpchinv
		) {
	string retval;
// IP getSquawkCross --- IBEGIN
	retval = "expand 'cross' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkCross --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkDircoup(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpDircoup* dpchinv
		) {
	string retval;
// IP getSquawkDircoup --- IBEGIN
	retval = "expand 'dircoup' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkDircoup --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkDiscres(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpDiscres* dpchinv
		) {
	string retval;
// IP getSquawkDiscres --- IBEGIN
	retval = "expand 'discres' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkDiscres --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkDottext(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpDottext* dpchinv
		) {
	string retval;
// IP getSquawkDottext --- IBEGIN
	retval = "expand 'dottext' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkDottext --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkDsn(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpDsn* dpchinv
		) {
	string retval;
// IP getSquawkDsn --- IBEGIN
	retval = "expand design '" + StubPlnr::getStubDsnStd(dbsplnr, dpchinv->refPlnrMDesign) + "'";
// IP getSquawkDsn --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkGratcpl(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpGratcpl* dpchinv
		) {
	string retval;
// IP getSquawkGratcpl --- IBEGIN
	retval = "expand 'gratcpl' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkGratcpl --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkGray(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpGray* dpchinv
		) {
	string retval;
// IP getSquawkGray --- IBEGIN
	retval = "expand 'gray' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkGray --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkImage(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpImage* dpchinv
		) {
	string retval;
// IP getSquawkImage --- IBEGIN
	retval = "expand 'image' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkImage --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkMarker(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpMarker* dpchinv
		) {
	string retval;
// IP getSquawkMarker --- IBEGIN
	retval = "expand 'marker' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkMarker --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPad(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPad* dpchinv
		) {
	string retval;
// IP getSquawkPad --- IBEGIN
	retval = "expand 'pad' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPad --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPhcsq(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhcsq* dpchinv
		) {
	string retval;
// IP getSquawkPhcsq --- IBEGIN
	retval = "expand 'phcsq' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPhcsq --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPhcsqneg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhcsqneg* dpchinv
		) {
	string retval;
// IP getSquawkPhcsqneg --- IBEGIN
	retval = "expand 'phcsqneg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPhcsqneg --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPhctrig(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhctrig* dpchinv
		) {
	string retval;
// IP getSquawkPhctrig --- IBEGIN
	retval = "expand 'phctrig' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPhctrig --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPhctrigneg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhctrigneg* dpchinv
		) {
	string retval;
// IP getSquawkPhctrigneg --- IBEGIN
	retval = "expand 'phctrigneg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPhctrigneg --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPhotdet(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPhotdet* dpchinv
		) {
	string retval;
// IP getSquawkPhotdet --- IBEGIN
	retval = "expand 'photdet' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPhotdet --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPie(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPie* dpchinv
		) {
	string retval;
// IP getSquawkPie --- IBEGIN
	retval = "expand 'pie' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPie --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkPinout(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpPinout* dpchinv
		) {
	string retval;
// IP getSquawkPinout --- IBEGIN
	retval = "expand 'pinout' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkPinout --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkRoicadp(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpRoicadp* dpchinv
		) {
	string retval;
// IP getSquawkRoicadp --- IBEGIN
	retval = "expand 'roicadp' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkRoicadp --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkRtresneg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpRtresneg* dpchinv
		) {
	string retval;
// IP getSquawkRtresneg --- IBEGIN
	retval = "expand 'rtresneg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkRtresneg --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkSpring(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpSpring* dpchinv
		) {
	string retval;
// IP getSquawkSpring --- IBEGIN
	retval = "expand 'spring' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkSpring --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkStkpertpl(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpStkpertpl* dpchinv
		) {
	string retval;
// IP getSquawkStkpertpl --- IBEGIN
	retval = "expand periodic stack '" + StubPlnr::getStubStkShort(dbsplnr, dpchinv->refPlnrMStack) + "'";
// IP getSquawkStkpertpl --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkStkregfill(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpStkregfill* dpchinv
		) {
	string retval;
// IP getSquawkStkregfill --- IBEGIN
	retval = "expand regular or fill stack '" + StubPlnr::getStubStkShort(dbsplnr, dpchinv->refPlnrMStack) + "'";
// IP getSquawkStkregfill --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkVanderpauw(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpVanderpauw* dpchinv
		) {
	string retval;
// IP getSquawkVanderpauw --- IBEGIN
	retval = "expand 'vanderpauw' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkVanderpauw --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWg* dpchinv
		) {
	string retval;
// IP getSquawkWg --- IBEGIN
	retval = "expand 'wg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWg --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWgbend(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgbend* dpchinv
		) {
	string retval;
// IP getSquawkWgbend --- IBEGIN
	retval = "expand 'wgbend' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWgbend --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWgbendneg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgbendneg* dpchinv
		) {
	string retval;
// IP getSquawkWgbendneg --- IBEGIN
	retval = "expand 'wgbendneg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWgbendneg --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWgneg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgneg* dpchinv
		) {
	string retval;
// IP getSquawkWgneg --- IBEGIN
	retval = "expand 'wgneg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWgneg --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWgsusp(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgsusp* dpchinv
		) {
	string retval;
// IP getSquawkWgsusp --- IBEGIN
	retval = "expand 'wgsusp' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWgsusp --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWgtap(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgtap* dpchinv
		) {
	string retval;
// IP getSquawkWgtap --- IBEGIN
	retval = "expand 'wgtap' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWgtap --- IEND
	return(retval);
};

string SqkPlnrExp::getSquawkWgtapneg(
			DbsPlnr* dbsplnr
			, DpchInvPlnrExpWgtapneg* dpchinv
		) {
	string retval;
// IP getSquawkWgtapneg --- IBEGIN
	retval = "expand 'wgtapneg' device '" + StubPlnr::getStubDevShort(dbsplnr, dpchinv->refPlnrMDevice) + "'";
// IP getSquawkWgtapneg --- IEND
	return(retval);
};


