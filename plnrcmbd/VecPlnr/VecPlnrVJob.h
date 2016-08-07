/**
  * \file VecPlnrVJob.h
  * vector VecPlnrVJob (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVJOB_H
#define VECPLNRVJOB_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVJob
	*/
namespace VecPlnrVJob {
	const uint CRDPLNRARI = 1;
	const uint CRDPLNRARR = 2;
	const uint CRDPLNRCLC = 3;
	const uint CRDPLNRCLI = 4;
	const uint CRDPLNRCTP = 5;
	const uint CRDPLNRDGD = 6;
	const uint CRDPLNRDOM = 7;
	const uint CRDPLNRDSN = 8;
	const uint CRDPLNRDTP = 9;
	const uint CRDPLNRDVC = 10;
	const uint CRDPLNRFIL = 11;
	const uint CRDPLNRLYR = 12;
	const uint CRDPLNRMAT = 13;
	const uint CRDPLNRNAV = 14;
	const uint CRDPLNRPRJ = 15;
	const uint CRDPLNRPRS = 16;
	const uint CRDPLNRRTC = 17;
	const uint CRDPLNRSRU = 18;
	const uint CRDPLNRSTK = 19;
	const uint CRDPLNRTPO = 20;
	const uint CRDPLNRUSG = 21;
	const uint CRDPLNRUSR = 22;
	const uint DLGPLNRCLCEXPRTX = 23;
	const uint DLGPLNRCLCGENRPV = 24;
	const uint DLGPLNRCLCUSECASE = 25;
	const uint DLGPLNRDSNGENPLT = 26;
	const uint DLGPLNRFILDLDCPY = 27;
	const uint DLGPLNRNAVLOAINI = 28;
	const uint DLGPLNRTPOUSECASE = 29;
	const uint IEXPLNRINI = 30;
	const uint JOBPLNRCLCDISPTEST = 31;
	const uint JOBPLNRCLCQCDSLAB = 32;
	const uint JOBPLNRTPOEXAMPLES = 33;
	const uint JOBPLNRTPOICABATCH1 = 34;
	const uint JOBPLNRTPOICABATCH2 = 35;
	const uint JOBPLNRTPOICABATCH3 = 36;
	const uint JOBPLNRTPOUVSLIDES = 37;
	const uint PNLPLNRARIAMARRAYENV = 38;
	const uint PNLPLNRARIDETAIL = 39;
	const uint PNLPLNRARIHEADBAR = 40;
	const uint PNLPLNRARILIST = 41;
	const uint PNLPLNRARIREC = 42;
	const uint PNLPLNRARR1NARRAYITEM = 43;
	const uint PNLPLNRARRAENV = 44;
	const uint PNLPLNRARRDETAIL = 45;
	const uint PNLPLNRARRHEADBAR = 46;
	const uint PNLPLNRARRHK1NRETICLE = 47;
	const uint PNLPLNRARRKENVKEY = 48;
	const uint PNLPLNRARRLIST = 49;
	const uint PNLPLNRARRREC = 50;
	const uint PNLPLNRCLC1NMATERIAL = 51;
	const uint PNLPLNRCLCAENV = 52;
	const uint PNLPLNRCLCAPAR = 53;
	const uint PNLPLNRCLCCAL1NCALCITEM = 54;
	const uint PNLPLNRCLCDETAIL = 55;
	const uint PNLPLNRCLCHEADBAR = 56;
	const uint PNLPLNRCLCLIST = 57;
	const uint PNLPLNRCLCMNDOMAIN = 58;
	const uint PNLPLNRCLCMNFILE = 59;
	const uint PNLPLNRCLCPRE = 60;
	const uint PNLPLNRCLCREC = 61;
	const uint PNLPLNRCLCREF1NFILE = 62;
	const uint PNLPLNRCLCSUP1NCALC = 63;
	const uint PNLPLNRCLCVIEW = 64;
	const uint PNLPLNRCLIAAMCALCENV = 65;
	const uint PNLPLNRCLIAAMCALCPAR = 66;
	const uint PNLPLNRCLIDETAIL = 67;
	const uint PNLPLNRCLIHEADBAR = 68;
	const uint PNLPLNRCLILIST = 69;
	const uint PNLPLNRCLIREC = 70;
	const uint PNLPLNRCLIREF1NFILE = 71;
	const uint PNLPLNRCTPAENV = 72;
	const uint PNLPLNRCTPAPAR = 73;
	const uint PNLPLNRCTPDETAIL = 74;
	const uint PNLPLNRCTPHEADBAR = 75;
	const uint PNLPLNRCTPKCALCDOMPRP = 76;
	const uint PNLPLNRCTPKCALCVAR = 77;
	const uint PNLPLNRCTPKENVKEY = 78;
	const uint PNLPLNRCTPKPARCAT = 79;
	const uint PNLPLNRCTPKPARPROP = 80;
	const uint PNLPLNRCTPLIST = 81;
	const uint PNLPLNRCTPREC = 82;
	const uint PNLPLNRCTPREF1NFILE = 83;
	const uint PNLPLNRCTPSUP1NCALC = 84;
	const uint PNLPLNRCTPTPL1NCALC = 85;
	const uint PNLPLNRDGDDETAIL = 86;
	const uint PNLPLNRDGDHEADBAR = 87;
	const uint PNLPLNRDGDLIST = 88;
	const uint PNLPLNRDGDREC = 89;
	const uint PNLPLNRDOMDETAIL = 90;
	const uint PNLPLNRDOMHEADBAR = 91;
	const uint PNLPLNRDOMLIST = 92;
	const uint PNLPLNRDOMMNCALC = 93;
	const uint PNLPLNRDOMREC = 94;
	const uint PNLPLNRDSN1NBLOCK = 95;
	const uint PNLPLNRDSN1NRETICLE = 96;
	const uint PNLPLNRDSNDETAIL = 97;
	const uint PNLPLNRDSNDRV1NDESIGN = 98;
	const uint PNLPLNRDSNDSN1NDEVICE = 99;
	const uint PNLPLNRDSNDSN1NDOMAIN = 100;
	const uint PNLPLNRDSNDSN1NDOMAINGD = 101;
	const uint PNLPLNRDSNDSN1NSTACK = 102;
	const uint PNLPLNRDSNHEADBAR = 103;
	const uint PNLPLNRDSNHK1NARCGUIDE = 104;
	const uint PNLPLNRDSNHK1NLAYER = 105;
	const uint PNLPLNRDSNHK1NLEVEL = 106;
	const uint PNLPLNRDSNHK1NLINEGUIDE = 107;
	const uint PNLPLNRDSNHK1NSTRUCTURE = 108;
	const uint PNLPLNRDSNHK1NVERTEX = 109;
	const uint PNLPLNRDSNLIST = 110;
	const uint PNLPLNRDSNMOD1NDESIGN = 111;
	const uint PNLPLNRDSNPRE = 112;
	const uint PNLPLNRDSNREC = 113;
	const uint PNLPLNRDSNVIEWXY = 114;
	const uint PNLPLNRDSNVIEWZ = 115;
	const uint PNLPLNRDTPAPAR = 116;
	const uint PNLPLNRDTPDETAIL = 117;
	const uint PNLPLNRDTPHEADBAR = 118;
	const uint PNLPLNRDTPHK1NSTRUCTURE = 119;
	const uint PNLPLNRDTPKPARKEY = 120;
	const uint PNLPLNRDTPLIST = 121;
	const uint PNLPLNRDTPPRE = 122;
	const uint PNLPLNRDTPREC = 123;
	const uint PNLPLNRDTPSUP1NDEVICE = 124;
	const uint PNLPLNRDTPTPL1NDEVICE = 125;
	const uint PNLPLNRDTPVIEW = 126;
	const uint PNLPLNRDVCAPAR = 127;
	const uint PNLPLNRDVCDETAIL = 128;
	const uint PNLPLNRDVCHEADBAR = 129;
	const uint PNLPLNRDVCHK1NARCGUIDE = 130;
	const uint PNLPLNRDVCHK1NLINEGUIDE = 131;
	const uint PNLPLNRDVCHK1NSTRUCTURE = 132;
	const uint PNLPLNRDVCHK1NVERTEX = 133;
	const uint PNLPLNRDVCLIST = 134;
	const uint PNLPLNRDVCPRE = 135;
	const uint PNLPLNRDVCREC = 136;
	const uint PNLPLNRDVCSUP1NDEVICE = 137;
	const uint PNLPLNRDVCVIEW = 138;
	const uint PNLPLNRFILDETAIL = 139;
	const uint PNLPLNRFILHEADBAR = 140;
	const uint PNLPLNRFILLIST = 141;
	const uint PNLPLNRFILMNCALC = 142;
	const uint PNLPLNRFILREC = 143;
	const uint PNLPLNRLYR1NBLOCK = 144;
	const uint PNLPLNRLYR1NRETICLE = 145;
	const uint PNLPLNRLYRDETAIL = 146;
	const uint PNLPLNRLYRHEADBAR = 147;
	const uint PNLPLNRLYRLIST = 148;
	const uint PNLPLNRLYRMNSTRUCTURE = 149;
	const uint PNLPLNRLYRREC = 150;
	const uint PNLPLNRMAT1NLAYER = 151;
	const uint PNLPLNRMATAPAR = 152;
	const uint PNLPLNRMATDETAIL = 153;
	const uint PNLPLNRMATHEADBAR = 154;
	const uint PNLPLNRMATLIST = 155;
	const uint PNLPLNRMATMOD1NMATERIAL = 156;
	const uint PNLPLNRMATREC = 157;
	const uint PNLPLNRMATREF1NFILE = 158;
	const uint PNLPLNRNAVADMIN = 159;
	const uint PNLPLNRNAVCALC = 160;
	const uint PNLPLNRNAVDESIGN = 161;
	const uint PNLPLNRNAVGLOBAL = 162;
	const uint PNLPLNRNAVHEADBAR = 163;
	const uint PNLPLNRNAVLAYOUT = 164;
	const uint PNLPLNRNAVPRE = 165;
	const uint PNLPLNRPRJ1NCALC = 166;
	const uint PNLPLNRPRJ1NDESIGN = 167;
	const uint PNLPLNRPRJDETAIL = 168;
	const uint PNLPLNRPRJHEADBAR = 169;
	const uint PNLPLNRPRJLIST = 170;
	const uint PNLPLNRPRJMNTAPEOUT = 171;
	const uint PNLPLNRPRJREC = 172;
	const uint PNLPLNRPRSADETAIL = 173;
	const uint PNLPLNRPRSDETAIL = 174;
	const uint PNLPLNRPRSHEADBAR = 175;
	const uint PNLPLNRPRSLIST = 176;
	const uint PNLPLNRPRSREC = 177;
	const uint PNLPLNRRTCDETAIL = 178;
	const uint PNLPLNRRTCHEADBAR = 179;
	const uint PNLPLNRRTCLIST = 180;
	const uint PNLPLNRRTCREC = 181;
	const uint PNLPLNRSRU1NBLOCK = 182;
	const uint PNLPLNRSRUDETAIL = 183;
	const uint PNLPLNRSRUHEADBAR = 184;
	const uint PNLPLNRSRULIST = 185;
	const uint PNLPLNRSRUMNLAYER = 186;
	const uint PNLPLNRSRUMNSTACK = 187;
	const uint PNLPLNRSRUREC = 188;
	const uint PNLPLNRSRUSRU1NFACE = 189;
	const uint PNLPLNRSTKDETAIL = 190;
	const uint PNLPLNRSTKHEADBAR = 191;
	const uint PNLPLNRSTKHK1NLAYER = 192;
	const uint PNLPLNRSTKHK1NLEVEL = 193;
	const uint PNLPLNRSTKLIST = 194;
	const uint PNLPLNRSTKMNSTRUCTURE = 195;
	const uint PNLPLNRSTKPRE = 196;
	const uint PNLPLNRSTKREC = 197;
	const uint PNLPLNRSTKVIEW = 198;
	const uint PNLPLNRTPO1NARRAY = 199;
	const uint PNLPLNRTPODETAIL = 200;
	const uint PNLPLNRTPOFLOORPLAN = 201;
	const uint PNLPLNRTPOHEADBAR = 202;
	const uint PNLPLNRTPOHK1NRETICLE = 203;
	const uint PNLPLNRTPOLIST = 204;
	const uint PNLPLNRTPOMNPROJECT = 205;
	const uint PNLPLNRTPOREC = 206;
	const uint PNLPLNRUSGAACCESS = 207;
	const uint PNLPLNRUSGDETAIL = 208;
	const uint PNLPLNRUSGHEADBAR = 209;
	const uint PNLPLNRUSGLIST = 210;
	const uint PNLPLNRUSGMNUSER = 211;
	const uint PNLPLNRUSGREC = 212;
	const uint PNLPLNRUSR1NSESSION = 213;
	const uint PNLPLNRUSRAACCESS = 214;
	const uint PNLPLNRUSRDETAIL = 215;
	const uint PNLPLNRUSRHEADBAR = 216;
	const uint PNLPLNRUSRLIST = 217;
	const uint PNLPLNRUSRMNUSERGROUP = 218;
	const uint PNLPLNRUSRREC = 219;
	const uint QRYPLNRARIAMARRAYENV = 220;
	const uint QRYPLNRARILIST = 221;
	const uint QRYPLNRARR1NARRAYITEM = 222;
	const uint QRYPLNRARRAENV = 223;
	const uint QRYPLNRARRHK1NRETICLE = 224;
	const uint QRYPLNRARRKENVKEY = 225;
	const uint QRYPLNRARRLIST = 226;
	const uint QRYPLNRCLC1NMATERIAL = 227;
	const uint QRYPLNRCLCAENV = 228;
	const uint QRYPLNRCLCAPAR = 229;
	const uint QRYPLNRCLCCAL1NCALCITEM = 230;
	const uint QRYPLNRCLCLIST = 231;
	const uint QRYPLNRCLCMNDOMAIN = 232;
	const uint QRYPLNRCLCMNFILE = 233;
	const uint QRYPLNRCLCREF1NFILE = 234;
	const uint QRYPLNRCLCSUP1NCALC = 235;
	const uint QRYPLNRCLIAAMCALCENV = 236;
	const uint QRYPLNRCLIAAMCALCPAR = 237;
	const uint QRYPLNRCLILIST = 238;
	const uint QRYPLNRCLIREF1NFILE = 239;
	const uint QRYPLNRCTPAENV = 240;
	const uint QRYPLNRCTPAPAR = 241;
	const uint QRYPLNRCTPKCALCDOMPRP = 242;
	const uint QRYPLNRCTPKCALCVAR = 243;
	const uint QRYPLNRCTPKENVKEY = 244;
	const uint QRYPLNRCTPKPARCAT = 245;
	const uint QRYPLNRCTPKPARPROP = 246;
	const uint QRYPLNRCTPLIST = 247;
	const uint QRYPLNRCTPREF1NFILE = 248;
	const uint QRYPLNRCTPSUP1NCALC = 249;
	const uint QRYPLNRCTPTPL1NCALC = 250;
	const uint QRYPLNRDGDLIST = 251;
	const uint QRYPLNRDOMLIST = 252;
	const uint QRYPLNRDOMMNCALC = 253;
	const uint QRYPLNRDSN1NBLOCK = 254;
	const uint QRYPLNRDSN1NRETICLE = 255;
	const uint QRYPLNRDSNDRV1NDESIGN = 256;
	const uint QRYPLNRDSNDSN1NDEVICE = 257;
	const uint QRYPLNRDSNDSN1NDOMAIN = 258;
	const uint QRYPLNRDSNDSN1NDOMAINGD = 259;
	const uint QRYPLNRDSNDSN1NSTACK = 260;
	const uint QRYPLNRDSNHK1NARCGUIDE = 261;
	const uint QRYPLNRDSNHK1NLAYER = 262;
	const uint QRYPLNRDSNHK1NLEVEL = 263;
	const uint QRYPLNRDSNHK1NLINEGUIDE = 264;
	const uint QRYPLNRDSNHK1NSTRUCTURE = 265;
	const uint QRYPLNRDSNHK1NVERTEX = 266;
	const uint QRYPLNRDSNLIST = 267;
	const uint QRYPLNRDSNMOD1NDESIGN = 268;
	const uint QRYPLNRDTPAPAR = 269;
	const uint QRYPLNRDTPHK1NSTRUCTURE = 270;
	const uint QRYPLNRDTPKPARKEY = 271;
	const uint QRYPLNRDTPLIST = 272;
	const uint QRYPLNRDTPSUP1NDEVICE = 273;
	const uint QRYPLNRDTPTPL1NDEVICE = 274;
	const uint QRYPLNRDVCAPAR = 275;
	const uint QRYPLNRDVCHK1NARCGUIDE = 276;
	const uint QRYPLNRDVCHK1NLINEGUIDE = 277;
	const uint QRYPLNRDVCHK1NSTRUCTURE = 278;
	const uint QRYPLNRDVCHK1NVERTEX = 279;
	const uint QRYPLNRDVCLIST = 280;
	const uint QRYPLNRDVCSUP1NDEVICE = 281;
	const uint QRYPLNRFILLIST = 282;
	const uint QRYPLNRFILMNCALC = 283;
	const uint QRYPLNRLYR1NBLOCK = 284;
	const uint QRYPLNRLYR1NRETICLE = 285;
	const uint QRYPLNRLYRLIST = 286;
	const uint QRYPLNRLYRMNSTRUCTURE = 287;
	const uint QRYPLNRMAT1NLAYER = 288;
	const uint QRYPLNRMATAPAR = 289;
	const uint QRYPLNRMATLIST = 290;
	const uint QRYPLNRMATMOD1NMATERIAL = 291;
	const uint QRYPLNRMATREF1NFILE = 292;
	const uint QRYPLNRPRJ1NCALC = 293;
	const uint QRYPLNRPRJ1NDESIGN = 294;
	const uint QRYPLNRPRJLIST = 295;
	const uint QRYPLNRPRJMNTAPEOUT = 296;
	const uint QRYPLNRPRSADETAIL = 297;
	const uint QRYPLNRPRSLIST = 298;
	const uint QRYPLNRRTCLIST = 299;
	const uint QRYPLNRSRU1NBLOCK = 300;
	const uint QRYPLNRSRULIST = 301;
	const uint QRYPLNRSRUMNLAYER = 302;
	const uint QRYPLNRSRUMNSTACK = 303;
	const uint QRYPLNRSRUSRU1NFACE = 304;
	const uint QRYPLNRSTKHK1NLAYER = 305;
	const uint QRYPLNRSTKHK1NLEVEL = 306;
	const uint QRYPLNRSTKLIST = 307;
	const uint QRYPLNRSTKMNSTRUCTURE = 308;
	const uint QRYPLNRTPO1NARRAY = 309;
	const uint QRYPLNRTPOHK1NRETICLE = 310;
	const uint QRYPLNRTPOLIST = 311;
	const uint QRYPLNRTPOMNPROJECT = 312;
	const uint QRYPLNRUSGAACCESS = 313;
	const uint QRYPLNRUSGLIST = 314;
	const uint QRYPLNRUSGMNUSER = 315;
	const uint QRYPLNRUSR1NSESSION = 316;
	const uint QRYPLNRUSRAACCESS = 317;
	const uint QRYPLNRUSRLIST = 318;
	const uint QRYPLNRUSRMNUSERGROUP = 319;
	const uint ROOTPLNR = 320;
	const uint SESSPLNR = 321;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif


