/**
  * \file SqkPlnrExp.h
  * squawk generation for operation pack PlnrExp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef SQKPLNREXP_H
#define SQKPLNREXP_H

#include "PlnrExp_blks.h"

/**
  * SqkPlnrExp
  */
namespace SqkPlnrExp {
	string getSquawkColldev(DbsPlnr* dbsplnr, DpchInvPlnrExpColldev* dpchinv);
	string getSquawkColldsn(DbsPlnr* dbsplnr, DpchInvPlnrExpColldsn* dpchinv);
	string getSquawkCollstk(DbsPlnr* dbsplnr, DpchInvPlnrExpCollstk* dpchinv);
	string getSquawkCorner(DbsPlnr* dbsplnr, DpchInvPlnrExpCorner* dpchinv);
	string getSquawkCross(DbsPlnr* dbsplnr, DpchInvPlnrExpCross* dpchinv);
	string getSquawkDircoup(DbsPlnr* dbsplnr, DpchInvPlnrExpDircoup* dpchinv);
	string getSquawkDiscres(DbsPlnr* dbsplnr, DpchInvPlnrExpDiscres* dpchinv);
	string getSquawkDottext(DbsPlnr* dbsplnr, DpchInvPlnrExpDottext* dpchinv);
	string getSquawkDsn(DbsPlnr* dbsplnr, DpchInvPlnrExpDsn* dpchinv);
	string getSquawkGratcpl(DbsPlnr* dbsplnr, DpchInvPlnrExpGratcpl* dpchinv);
	string getSquawkGray(DbsPlnr* dbsplnr, DpchInvPlnrExpGray* dpchinv);
	string getSquawkImage(DbsPlnr* dbsplnr, DpchInvPlnrExpImage* dpchinv);
	string getSquawkMarker(DbsPlnr* dbsplnr, DpchInvPlnrExpMarker* dpchinv);
	string getSquawkPad(DbsPlnr* dbsplnr, DpchInvPlnrExpPad* dpchinv);
	string getSquawkPhcsq(DbsPlnr* dbsplnr, DpchInvPlnrExpPhcsq* dpchinv);
	string getSquawkPhcsqneg(DbsPlnr* dbsplnr, DpchInvPlnrExpPhcsqneg* dpchinv);
	string getSquawkPhctrig(DbsPlnr* dbsplnr, DpchInvPlnrExpPhctrig* dpchinv);
	string getSquawkPhctrigneg(DbsPlnr* dbsplnr, DpchInvPlnrExpPhctrigneg* dpchinv);
	string getSquawkPhotdet(DbsPlnr* dbsplnr, DpchInvPlnrExpPhotdet* dpchinv);
	string getSquawkPie(DbsPlnr* dbsplnr, DpchInvPlnrExpPie* dpchinv);
	string getSquawkPinout(DbsPlnr* dbsplnr, DpchInvPlnrExpPinout* dpchinv);
	string getSquawkRoicadp(DbsPlnr* dbsplnr, DpchInvPlnrExpRoicadp* dpchinv);
	string getSquawkRtresneg(DbsPlnr* dbsplnr, DpchInvPlnrExpRtresneg* dpchinv);
	string getSquawkSpring(DbsPlnr* dbsplnr, DpchInvPlnrExpSpring* dpchinv);
	string getSquawkStkpertpl(DbsPlnr* dbsplnr, DpchInvPlnrExpStkpertpl* dpchinv);
	string getSquawkStkregfill(DbsPlnr* dbsplnr, DpchInvPlnrExpStkregfill* dpchinv);
	string getSquawkVanderpauw(DbsPlnr* dbsplnr, DpchInvPlnrExpVanderpauw* dpchinv);
	string getSquawkWg(DbsPlnr* dbsplnr, DpchInvPlnrExpWg* dpchinv);
	string getSquawkWgbend(DbsPlnr* dbsplnr, DpchInvPlnrExpWgbend* dpchinv);
	string getSquawkWgbendneg(DbsPlnr* dbsplnr, DpchInvPlnrExpWgbendneg* dpchinv);
	string getSquawkWgneg(DbsPlnr* dbsplnr, DpchInvPlnrExpWgneg* dpchinv);
	string getSquawkWgsusp(DbsPlnr* dbsplnr, DpchInvPlnrExpWgsusp* dpchinv);
	string getSquawkWgtap(DbsPlnr* dbsplnr, DpchInvPlnrExpWgtap* dpchinv);
	string getSquawkWgtapneg(DbsPlnr* dbsplnr, DpchInvPlnrExpWgtapneg* dpchinv);
};

#endif


