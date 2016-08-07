/**
  * \file VecPlnrVMaintable.cpp
  * vector VecPlnrVMaintable (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "VecPlnrVMaintable.h"

/******************************************************************************
 namespace VecPlnrVMaintable
 ******************************************************************************/

uint VecPlnrVMaintable::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "void") return VOID;
	else if (s == "tblplnrmarcguide") return TBLPLNRMARCGUIDE;
	else if (s == "tblplnrmarray") return TBLPLNRMARRAY;
	else if (s == "tblplnrmarrayitem") return TBLPLNRMARRAYITEM;
	else if (s == "tblplnrmblock") return TBLPLNRMBLOCK;
	else if (s == "tblplnrmcalc") return TBLPLNRMCALC;
	else if (s == "tblplnrmcalcitem") return TBLPLNRMCALCITEM;
	else if (s == "tblplnrmdesign") return TBLPLNRMDESIGN;
	else if (s == "tblplnrmdevice") return TBLPLNRMDEVICE;
	else if (s == "tblplnrmdomain") return TBLPLNRMDOMAIN;
	else if (s == "tblplnrmdomaingd") return TBLPLNRMDOMAINGD;
	else if (s == "tblplnrmface") return TBLPLNRMFACE;
	else if (s == "tblplnrmfile") return TBLPLNRMFILE;
	else if (s == "tblplnrmlayer") return TBLPLNRMLAYER;
	else if (s == "tblplnrmlevel") return TBLPLNRMLEVEL;
	else if (s == "tblplnrmlineguide") return TBLPLNRMLINEGUIDE;
	else if (s == "tblplnrmmaterial") return TBLPLNRMMATERIAL;
	else if (s == "tblplnrmperson") return TBLPLNRMPERSON;
	else if (s == "tblplnrmproject") return TBLPLNRMPROJECT;
	else if (s == "tblplnrmreticle") return TBLPLNRMRETICLE;
	else if (s == "tblplnrmsession") return TBLPLNRMSESSION;
	else if (s == "tblplnrmstack") return TBLPLNRMSTACK;
	else if (s == "tblplnrmstructure") return TBLPLNRMSTRUCTURE;
	else if (s == "tblplnrmtapeout") return TBLPLNRMTAPEOUT;
	else if (s == "tblplnrmuser") return TBLPLNRMUSER;
	else if (s == "tblplnrmusergroup") return TBLPLNRMUSERGROUP;
	else if (s == "tblplnrmvertex") return TBLPLNRMVERTEX;

	return(0);
};

string VecPlnrVMaintable::getSref(
			const uint ix
		) {
	if (ix == VOID) return("void");
	else if (ix == TBLPLNRMARCGUIDE) return("TblPlnrMArcguide");
	else if (ix == TBLPLNRMARRAY) return("TblPlnrMArray");
	else if (ix == TBLPLNRMARRAYITEM) return("TblPlnrMArrayitem");
	else if (ix == TBLPLNRMBLOCK) return("TblPlnrMBlock");
	else if (ix == TBLPLNRMCALC) return("TblPlnrMCalc");
	else if (ix == TBLPLNRMCALCITEM) return("TblPlnrMCalcitem");
	else if (ix == TBLPLNRMDESIGN) return("TblPlnrMDesign");
	else if (ix == TBLPLNRMDEVICE) return("TblPlnrMDevice");
	else if (ix == TBLPLNRMDOMAIN) return("TblPlnrMDomain");
	else if (ix == TBLPLNRMDOMAINGD) return("TblPlnrMDomaingd");
	else if (ix == TBLPLNRMFACE) return("TblPlnrMFace");
	else if (ix == TBLPLNRMFILE) return("TblPlnrMFile");
	else if (ix == TBLPLNRMLAYER) return("TblPlnrMLayer");
	else if (ix == TBLPLNRMLEVEL) return("TblPlnrMLevel");
	else if (ix == TBLPLNRMLINEGUIDE) return("TblPlnrMLineguide");
	else if (ix == TBLPLNRMMATERIAL) return("TblPlnrMMaterial");
	else if (ix == TBLPLNRMPERSON) return("TblPlnrMPerson");
	else if (ix == TBLPLNRMPROJECT) return("TblPlnrMProject");
	else if (ix == TBLPLNRMRETICLE) return("TblPlnrMReticle");
	else if (ix == TBLPLNRMSESSION) return("TblPlnrMSession");
	else if (ix == TBLPLNRMSTACK) return("TblPlnrMStack");
	else if (ix == TBLPLNRMSTRUCTURE) return("TblPlnrMStructure");
	else if (ix == TBLPLNRMTAPEOUT) return("TblPlnrMTapeout");
	else if (ix == TBLPLNRMUSER) return("TblPlnrMUser");
	else if (ix == TBLPLNRMUSERGROUP) return("TblPlnrMUsergroup");
	else if (ix == TBLPLNRMVERTEX) return("TblPlnrMVertex");

	return("");
};

string VecPlnrVMaintable::getTitle(
			const uint ix
			, const uint ixPlnrVLocale
		) {
	if (ixPlnrVLocale == 1) {
		if (ix == VOID) return("none");
		else if (ix == TBLPLNRMARCGUIDE) return("arc guide");
		else if (ix == TBLPLNRMARRAY) return("array");
		else if (ix == TBLPLNRMARRAYITEM) return("array item");
		else if (ix == TBLPLNRMBLOCK) return("block");
		else if (ix == TBLPLNRMCALC) return("calculation");
		else if (ix == TBLPLNRMCALCITEM) return("calculation item");
		else if (ix == TBLPLNRMDESIGN) return("design");
		else if (ix == TBLPLNRMDEVICE) return("device");
		else if (ix == TBLPLNRMDOMAIN) return("domain");
		else if (ix == TBLPLNRMDOMAINGD) return("domain guide");
		else if (ix == TBLPLNRMFACE) return("face");
		else if (ix == TBLPLNRMFILE) return("file");
		else if (ix == TBLPLNRMLAYER) return("layer");
		else if (ix == TBLPLNRMLEVEL) return("level");
		else if (ix == TBLPLNRMLINEGUIDE) return("line guide");
		else if (ix == TBLPLNRMMATERIAL) return("material");
		else if (ix == TBLPLNRMPERSON) return("person");
		else if (ix == TBLPLNRMPROJECT) return("project");
		else if (ix == TBLPLNRMRETICLE) return("reticle");
		else if (ix == TBLPLNRMSESSION) return("session");
		else if (ix == TBLPLNRMSTACK) return("stack");
		else if (ix == TBLPLNRMSTRUCTURE) return("structure");
		else if (ix == TBLPLNRMTAPEOUT) return("tape-out");
		else if (ix == TBLPLNRMUSER) return("user");
		else if (ix == TBLPLNRMUSERGROUP) return("user group");
		else if (ix == TBLPLNRMVERTEX) return("vertex");
	};

	return("");
};

void VecPlnrVMaintable::fillFeed(
			const uint ixPlnrVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i=1;i<=27;i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixPlnrVLocale));
};

