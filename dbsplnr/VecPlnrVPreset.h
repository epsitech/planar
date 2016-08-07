/**
  * \file VecPlnrVPreset.h
  * vector VecPlnrVPreset (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVPRESET_H
#define VECPLNRVPRESET_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVPreset
	*/
namespace VecPlnrVPreset {
	const uint VOID = 1;
	const uint PREPLNRADM = 2;
	const uint PREPLNRARIAMARRAYENV_X2 = 3;
	const uint PREPLNRARILIST_ARR = 4;
	const uint PREPLNRARILIST_DSN = 5;
	const uint PREPLNRARILIST_I = 6;
	const uint PREPLNRARILIST_J = 7;
	const uint PREPLNRARILIST_K = 8;
	const uint PREPLNRARILIST_L = 9;
	const uint PREPLNRARILIST_M = 10;
	const uint PREPLNRARILIST_N = 11;
	const uint PREPLNRARRAENV_X1 = 12;
	const uint PREPLNRARRAENV_X2 = 13;
	const uint PREPLNRARRLIST_DSN = 14;
	const uint PREPLNRARRLIST_SRF = 15;
	const uint PREPLNRARRLIST_TPO = 16;
	const uint PREPLNRCLCAENV_X1 = 17;
	const uint PREPLNRCLCAENV_X2 = 18;
	const uint PREPLNRCLCAPAR_X1 = 19;
	const uint PREPLNRCLCAPAR_X2 = 20;
	const uint PREPLNRCLCAPAR_X3 = 21;
	const uint PREPLNRCLCLIST_DIM = 22;
	const uint PREPLNRCLCLIST_DSN = 23;
	const uint PREPLNRCLCLIST_PRJ = 24;
	const uint PREPLNRCLCLIST_SUP = 25;
	const uint PREPLNRCLCLIST_TIT = 26;
	const uint PREPLNRCLCLIST_TPL = 27;
	const uint PREPLNRCLCMNFILE_X1 = 28;
	const uint PREPLNRCLIAAMCALCENV_X2 = 29;
	const uint PREPLNRCLIAAMCALCPAR_X2 = 30;
	const uint PREPLNRCLIAAMCALCPAR_X3 = 31;
	const uint PREPLNRCLILIST_CAL = 32;
	const uint PREPLNRCLILIST_DSN = 33;
	const uint PREPLNRCLILIST_TIT = 34;
	const uint PREPLNRCTPAENV_X1 = 35;
	const uint PREPLNRCTPAENV_X2 = 36;
	const uint PREPLNRCTPAPAR_X1 = 37;
	const uint PREPLNRCTPAPAR_X2 = 38;
	const uint PREPLNRCTPAPAR_X3 = 39;
	const uint PREPLNRCTPLIST_DIM = 40;
	const uint PREPLNRCTPLIST_DSN = 41;
	const uint PREPLNRCTPLIST_PRJ = 42;
	const uint PREPLNRCTPLIST_SUP = 43;
	const uint PREPLNRCTPLIST_TIT = 44;
	const uint PREPLNRCTPLIST_TPL = 45;
	const uint PREPLNRCTPMNFILE_X1 = 46;
	const uint PREPLNRDGDLIST_DSN = 47;
	const uint PREPLNRDGDLIST_SRF = 48;
	const uint PREPLNRDGDLIST_TYP = 49;
	const uint PREPLNRDOMLIST_DSN = 50;
	const uint PREPLNRDOMLIST_SRF = 51;
	const uint PREPLNRDOMLIST_TYP = 52;
	const uint PREPLNRDSNHK1NARCGUIDE_X1 = 53;
	const uint PREPLNRDSNHK1NLAYER_X1 = 54;
	const uint PREPLNRDSNHK1NLEVEL_X1 = 55;
	const uint PREPLNRDSNHK1NLINEGUIDE_X1 = 56;
	const uint PREPLNRDSNHK1NVERTEX_X1 = 57;
	const uint PREPLNRDSNLIST_DIM = 58;
	const uint PREPLNRDSNLIST_DRV = 59;
	const uint PREPLNRDSNLIST_MOD = 60;
	const uint PREPLNRDSNLIST_MTY = 61;
	const uint PREPLNRDSNLIST_PRJ = 62;
	const uint PREPLNRDSNLIST_RET = 63;
	const uint PREPLNRDSNLIST_REU = 64;
	const uint PREPLNRDSNLIST_TYP = 65;
	const uint PREPLNRDTPAPAR_X1 = 66;
	const uint PREPLNRDTPAPAR_X2 = 67;
	const uint PREPLNRDTPHK1NARCGUIDE_OPR_X1 = 68;
	const uint PREPLNRDTPHK1NARCGUIDE_X1 = 69;
	const uint PREPLNRDTPHK1NLINEGUIDE_OPR_X1 = 70;
	const uint PREPLNRDTPHK1NLINEGUIDE_X1 = 71;
	const uint PREPLNRDTPHK1NVERTEX_OPR_X1 = 72;
	const uint PREPLNRDTPHK1NVERTEX_X1 = 73;
	const uint PREPLNRDTPLIST_DSN = 74;
	const uint PREPLNRDTPLIST_SRF = 75;
	const uint PREPLNRDTPLIST_SUP = 76;
	const uint PREPLNRDTPLIST_TPL = 77;
	const uint PREPLNRDVCAPAR_X1 = 78;
	const uint PREPLNRDVCAPAR_X2 = 79;
	const uint PREPLNRDVCHK1NARCGUIDE_OPR_X1 = 80;
	const uint PREPLNRDVCHK1NARCGUIDE_X1 = 81;
	const uint PREPLNRDVCHK1NLINEGUIDE_OPR_X1 = 82;
	const uint PREPLNRDVCHK1NLINEGUIDE_X1 = 83;
	const uint PREPLNRDVCHK1NVERTEX_OPR_X1 = 84;
	const uint PREPLNRDVCHK1NVERTEX_X1 = 85;
	const uint PREPLNRDVCLIST_DSN = 86;
	const uint PREPLNRDVCLIST_SRF = 87;
	const uint PREPLNRDVCLIST_SUP = 88;
	const uint PREPLNRDVCLIST_TPL = 89;
	const uint PREPLNRFILLIST_FNM = 90;
	const uint PREPLNRFILLIST_RET = 91;
	const uint PREPLNRFILLIST_REU = 92;
	const uint PREPLNRFILMNCALC_X1 = 93;
	const uint PREPLNRGRP = 94;
	const uint PREPLNRIP = 95;
	const uint PREPLNRIXACC = 96;
	const uint PREPLNRIXLCL = 97;
	const uint PREPLNRIXORD = 98;
	const uint PREPLNRIXPRE = 99;
	const uint PREPLNRIXUACARI = 100;
	const uint PREPLNRIXUACARR = 101;
	const uint PREPLNRIXUACCLC = 102;
	const uint PREPLNRIXUACCLI = 103;
	const uint PREPLNRIXUACCTP = 104;
	const uint PREPLNRIXUACDGD = 105;
	const uint PREPLNRIXUACDOM = 106;
	const uint PREPLNRIXUACDSN = 107;
	const uint PREPLNRIXUACDTP = 108;
	const uint PREPLNRIXUACDVC = 109;
	const uint PREPLNRIXUACFIL = 110;
	const uint PREPLNRIXUACLYR = 111;
	const uint PREPLNRIXUACMAT = 112;
	const uint PREPLNRIXUACPRJ = 113;
	const uint PREPLNRIXUACPRS = 114;
	const uint PREPLNRIXUACRTC = 115;
	const uint PREPLNRIXUACSRU = 116;
	const uint PREPLNRIXUACSTK = 117;
	const uint PREPLNRIXUACTPO = 118;
	const uint PREPLNRIXUACUSG = 119;
	const uint PREPLNRIXUACUSR = 120;
	const uint PREPLNRJREFNOTIFY = 121;
	const uint PREPLNRJREFSESS = 122;
	const uint PREPLNRLYRLIST_HKT = 123;
	const uint PREPLNRLYRLIST_HKU = 124;
	const uint PREPLNRLYRLIST_MAT = 125;
	const uint PREPLNRLYRLIST_SRF = 126;
	const uint PREPLNRLYRLIST_TTY = 127;
	const uint PREPLNRLYRLIST_TYP = 128;
	const uint PREPLNRMAT1NLAYER_X1 = 129;
	const uint PREPLNRMATAPAR_X1 = 130;
	const uint PREPLNRMATAPAR_X2 = 131;
	const uint PREPLNRMATAPAR_X3 = 132;
	const uint PREPLNRMATLIST_CAL = 133;
	const uint PREPLNRMATLIST_SRF = 134;
	const uint PREPLNRMATLIST_SUP = 135;
	const uint PREPLNRMATLIST_TIT = 136;
	const uint PREPLNRMATLIST_TYP = 137;
	const uint PREPLNROWN = 138;
	const uint PREPLNRPRJLIST_TIT = 139;
	const uint PREPLNRPRSADETAIL_X1 = 140;
	const uint PREPLNRPRSLIST_GRP = 141;
	const uint PREPLNRPRSLIST_LNM = 142;
	const uint PREPLNRPRSLIST_OWN = 143;
	const uint PREPLNRREFAGD = 144;
	const uint PREPLNRREFARI = 145;
	const uint PREPLNRREFARR = 146;
	const uint PREPLNRREFBLK = 147;
	const uint PREPLNRREFCAL = 148;
	const uint PREPLNRREFCLC = 149;
	const uint PREPLNRREFCLI = 150;
	const uint PREPLNRREFCTP = 151;
	const uint PREPLNRREFDEV = 152;
	const uint PREPLNRREFDGD = 153;
	const uint PREPLNRREFDOM = 154;
	const uint PREPLNRREFDSN = 155;
	const uint PREPLNRREFDTP = 156;
	const uint PREPLNRREFDVC = 157;
	const uint PREPLNRREFFCE = 158;
	const uint PREPLNRREFFIL = 159;
	const uint PREPLNRREFLGD = 160;
	const uint PREPLNRREFLVL = 161;
	const uint PREPLNRREFLYR = 162;
	const uint PREPLNRREFMAT = 163;
	const uint PREPLNRREFMODDSN = 164;
	const uint PREPLNRREFPRJ = 165;
	const uint PREPLNRREFPRS = 166;
	const uint PREPLNRREFRTC = 167;
	const uint PREPLNRREFSEL = 168;
	const uint PREPLNRREFSES = 169;
	const uint PREPLNRREFSRU = 170;
	const uint PREPLNRREFSSUBDEV = 171;
	const uint PREPLNRREFSTK = 172;
	const uint PREPLNRREFTPO = 173;
	const uint PREPLNRREFUSG = 174;
	const uint PREPLNRREFUSR = 175;
	const uint PREPLNRREFVTX = 176;
	const uint PREPLNRRTCLIST_DSN = 177;
	const uint PREPLNRRTCLIST_HKT = 178;
	const uint PREPLNRRTCLIST_HKU = 179;
	const uint PREPLNRRTCLIST_LYR = 180;
	const uint PREPLNRRTCLIST_SRF = 181;
	const uint PREPLNRSESS = 182;
	const uint PREPLNRSRULIST_HKT = 183;
	const uint PREPLNRSRULIST_HKU = 184;
	const uint PREPLNRSRULIST_SRF = 185;
	const uint PREPLNRSRUSRU1NFACE_OPR_X1 = 186;
	const uint PREPLNRSRUSRU1NFACE_X1 = 187;
	const uint PREPLNRSTKHK1NLAYER_X1 = 188;
	const uint PREPLNRSTKHK1NLEVEL_X1 = 189;
	const uint PREPLNRSTKLIST_DSN = 190;
	const uint PREPLNRSTKLIST_SRF = 191;
	const uint PREPLNRSTKLIST_TYP = 192;
	const uint PREPLNRSYSDATE = 193;
	const uint PREPLNRSYSSTAMP = 194;
	const uint PREPLNRSYSTIME = 195;
	const uint PREPLNRTPOLIST_TIT = 196;
	const uint PREPLNRTPOLIST_TYP = 197;
	const uint PREPLNRUSGAACCESS_X1 = 198;
	const uint PREPLNRUSGLIST_SRF = 199;
	const uint PREPLNRUSRAACCESS_X1 = 200;
	const uint PREPLNRUSRLIST_PRS = 201;
	const uint PREPLNRUSRLIST_SRF = 202;
	const uint PREPLNRUSRLIST_USG = 203;

	uint getIx(const string& sref);
	string getSref(const uint ix);

	string getTitle(const uint ix, const uint ixPlnrVLocale);
};

#endif

