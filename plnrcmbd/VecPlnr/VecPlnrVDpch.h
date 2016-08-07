/**
  * \file VecPlnrVDpch.h
  * vector VecPlnrVDpch (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef VECPLNRVDPCH_H
#define VECPLNRVDPCH_H

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
	* VecPlnrVDpch
	*/
namespace VecPlnrVDpch {
	const uint DPCHAPPDLGPLNRCLCEXPRTXDO = 1;
	const uint DPCHAPPDLGPLNRCLCGENRPVDO = 2;
	const uint DPCHAPPDLGPLNRCLCUSECASEDATA = 3;
	const uint DPCHAPPDLGPLNRCLCUSECASEDO = 4;
	const uint DPCHAPPDLGPLNRDSNGENPLTDO = 5;
	const uint DPCHAPPDLGPLNRFILDLDCPYDO = 6;
	const uint DPCHAPPDLGPLNRNAVLOAINIDATA = 7;
	const uint DPCHAPPDLGPLNRNAVLOAINIDO = 8;
	const uint DPCHAPPDLGPLNRTPOUSECASEDATA = 9;
	const uint DPCHAPPDLGPLNRTPOUSECASEDO = 10;
	const uint DPCHAPPPLNRALERT = 11;
	const uint DPCHAPPPLNRARIAMARRAYENVDATA = 12;
	const uint DPCHAPPPLNRARIAMARRAYENVDO = 13;
	const uint DPCHAPPPLNRARIDETAILDATA = 14;
	const uint DPCHAPPPLNRARIDETAILDO = 15;
	const uint DPCHAPPPLNRARIDO = 16;
	const uint DPCHAPPPLNRARILISTDATA = 17;
	const uint DPCHAPPPLNRARILISTDO = 18;
	const uint DPCHAPPPLNRARIRECDO = 19;
	const uint DPCHAPPPLNRARR1NARRAYITEMDATA = 20;
	const uint DPCHAPPPLNRARR1NARRAYITEMDO = 21;
	const uint DPCHAPPPLNRARRAENVDATA = 22;
	const uint DPCHAPPPLNRARRAENVDO = 23;
	const uint DPCHAPPPLNRARRDETAILDATA = 24;
	const uint DPCHAPPPLNRARRDETAILDO = 25;
	const uint DPCHAPPPLNRARRDO = 26;
	const uint DPCHAPPPLNRARRHK1NRETICLEDATA = 27;
	const uint DPCHAPPPLNRARRHK1NRETICLEDO = 28;
	const uint DPCHAPPPLNRARRKENVKEYDATA = 29;
	const uint DPCHAPPPLNRARRKENVKEYDO = 30;
	const uint DPCHAPPPLNRARRLISTDATA = 31;
	const uint DPCHAPPPLNRARRLISTDO = 32;
	const uint DPCHAPPPLNRARRRECDO = 33;
	const uint DPCHAPPPLNRCLC1NMATERIALDATA = 34;
	const uint DPCHAPPPLNRCLC1NMATERIALDO = 35;
	const uint DPCHAPPPLNRCLCAENVDATA = 36;
	const uint DPCHAPPPLNRCLCAENVDO = 37;
	const uint DPCHAPPPLNRCLCAPARDATA = 38;
	const uint DPCHAPPPLNRCLCAPARDO = 39;
	const uint DPCHAPPPLNRCLCCAL1NCALCITEMDATA = 40;
	const uint DPCHAPPPLNRCLCCAL1NCALCITEMDO = 41;
	const uint DPCHAPPPLNRCLCDETAILDATA = 42;
	const uint DPCHAPPPLNRCLCDETAILDO = 43;
	const uint DPCHAPPPLNRCLCDO = 44;
	const uint DPCHAPPPLNRCLCLISTDATA = 45;
	const uint DPCHAPPPLNRCLCLISTDO = 46;
	const uint DPCHAPPPLNRCLCMNDOMAINDATA = 47;
	const uint DPCHAPPPLNRCLCMNDOMAINDO = 48;
	const uint DPCHAPPPLNRCLCMNFILEDATA = 49;
	const uint DPCHAPPPLNRCLCMNFILEDO = 50;
	const uint DPCHAPPPLNRCLCRECDO = 51;
	const uint DPCHAPPPLNRCLCREF1NFILEDATA = 52;
	const uint DPCHAPPPLNRCLCREF1NFILEDO = 53;
	const uint DPCHAPPPLNRCLCSUP1NCALCDATA = 54;
	const uint DPCHAPPPLNRCLCSUP1NCALCDO = 55;
	const uint DPCHAPPPLNRCLIAAMCALCENVDATA = 56;
	const uint DPCHAPPPLNRCLIAAMCALCENVDO = 57;
	const uint DPCHAPPPLNRCLIAAMCALCPARDATA = 58;
	const uint DPCHAPPPLNRCLIAAMCALCPARDO = 59;
	const uint DPCHAPPPLNRCLIDETAILDATA = 60;
	const uint DPCHAPPPLNRCLIDETAILDO = 61;
	const uint DPCHAPPPLNRCLIDO = 62;
	const uint DPCHAPPPLNRCLILISTDATA = 63;
	const uint DPCHAPPPLNRCLILISTDO = 64;
	const uint DPCHAPPPLNRCLIRECDO = 65;
	const uint DPCHAPPPLNRCLIREF1NFILEDATA = 66;
	const uint DPCHAPPPLNRCLIREF1NFILEDO = 67;
	const uint DPCHAPPPLNRCTPAENVDATA = 68;
	const uint DPCHAPPPLNRCTPAENVDO = 69;
	const uint DPCHAPPPLNRCTPAPARDATA = 70;
	const uint DPCHAPPPLNRCTPAPARDO = 71;
	const uint DPCHAPPPLNRCTPDETAILDATA = 72;
	const uint DPCHAPPPLNRCTPDETAILDO = 73;
	const uint DPCHAPPPLNRCTPDO = 74;
	const uint DPCHAPPPLNRCTPKCALCDOMPRPDATA = 75;
	const uint DPCHAPPPLNRCTPKCALCDOMPRPDO = 76;
	const uint DPCHAPPPLNRCTPKCALCVARDATA = 77;
	const uint DPCHAPPPLNRCTPKCALCVARDO = 78;
	const uint DPCHAPPPLNRCTPKENVKEYDATA = 79;
	const uint DPCHAPPPLNRCTPKENVKEYDO = 80;
	const uint DPCHAPPPLNRCTPKPARCATDATA = 81;
	const uint DPCHAPPPLNRCTPKPARCATDO = 82;
	const uint DPCHAPPPLNRCTPKPARPROPDATA = 83;
	const uint DPCHAPPPLNRCTPKPARPROPDO = 84;
	const uint DPCHAPPPLNRCTPLISTDATA = 85;
	const uint DPCHAPPPLNRCTPLISTDO = 86;
	const uint DPCHAPPPLNRCTPRECDO = 87;
	const uint DPCHAPPPLNRCTPREF1NFILEDATA = 88;
	const uint DPCHAPPPLNRCTPREF1NFILEDO = 89;
	const uint DPCHAPPPLNRCTPSUP1NCALCDATA = 90;
	const uint DPCHAPPPLNRCTPSUP1NCALCDO = 91;
	const uint DPCHAPPPLNRCTPTPL1NCALCDATA = 92;
	const uint DPCHAPPPLNRCTPTPL1NCALCDO = 93;
	const uint DPCHAPPPLNRDGDDETAILDATA = 94;
	const uint DPCHAPPPLNRDGDDETAILDO = 95;
	const uint DPCHAPPPLNRDGDDO = 96;
	const uint DPCHAPPPLNRDGDLISTDATA = 97;
	const uint DPCHAPPPLNRDGDLISTDO = 98;
	const uint DPCHAPPPLNRDGDRECDO = 99;
	const uint DPCHAPPPLNRDOMDETAILDATA = 100;
	const uint DPCHAPPPLNRDOMDETAILDO = 101;
	const uint DPCHAPPPLNRDOMDO = 102;
	const uint DPCHAPPPLNRDOMLISTDATA = 103;
	const uint DPCHAPPPLNRDOMLISTDO = 104;
	const uint DPCHAPPPLNRDOMMNCALCDATA = 105;
	const uint DPCHAPPPLNRDOMMNCALCDO = 106;
	const uint DPCHAPPPLNRDOMRECDO = 107;
	const uint DPCHAPPPLNRDSN1NBLOCKDATA = 108;
	const uint DPCHAPPPLNRDSN1NBLOCKDO = 109;
	const uint DPCHAPPPLNRDSN1NRETICLEDATA = 110;
	const uint DPCHAPPPLNRDSN1NRETICLEDO = 111;
	const uint DPCHAPPPLNRDSNDETAILDATA = 112;
	const uint DPCHAPPPLNRDSNDETAILDO = 113;
	const uint DPCHAPPPLNRDSNDO = 114;
	const uint DPCHAPPPLNRDSNDRV1NDESIGNDATA = 115;
	const uint DPCHAPPPLNRDSNDRV1NDESIGNDO = 116;
	const uint DPCHAPPPLNRDSNDSN1NDEVICEDATA = 117;
	const uint DPCHAPPPLNRDSNDSN1NDEVICEDO = 118;
	const uint DPCHAPPPLNRDSNDSN1NDOMAINDATA = 119;
	const uint DPCHAPPPLNRDSNDSN1NDOMAINDO = 120;
	const uint DPCHAPPPLNRDSNDSN1NDOMAINGDDATA = 121;
	const uint DPCHAPPPLNRDSNDSN1NDOMAINGDDO = 122;
	const uint DPCHAPPPLNRDSNDSN1NSTACKDATA = 123;
	const uint DPCHAPPPLNRDSNDSN1NSTACKDO = 124;
	const uint DPCHAPPPLNRDSNHK1NARCGUIDEDATA = 125;
	const uint DPCHAPPPLNRDSNHK1NARCGUIDEDO = 126;
	const uint DPCHAPPPLNRDSNHK1NLAYERDATA = 127;
	const uint DPCHAPPPLNRDSNHK1NLAYERDO = 128;
	const uint DPCHAPPPLNRDSNHK1NLEVELDATA = 129;
	const uint DPCHAPPPLNRDSNHK1NLEVELDO = 130;
	const uint DPCHAPPPLNRDSNHK1NLINEGUIDEDATA = 131;
	const uint DPCHAPPPLNRDSNHK1NLINEGUIDEDO = 132;
	const uint DPCHAPPPLNRDSNHK1NSTRUCTUREDATA = 133;
	const uint DPCHAPPPLNRDSNHK1NSTRUCTUREDO = 134;
	const uint DPCHAPPPLNRDSNHK1NVERTEXDATA = 135;
	const uint DPCHAPPPLNRDSNHK1NVERTEXDO = 136;
	const uint DPCHAPPPLNRDSNLISTDATA = 137;
	const uint DPCHAPPPLNRDSNLISTDO = 138;
	const uint DPCHAPPPLNRDSNMOD1NDESIGNDATA = 139;
	const uint DPCHAPPPLNRDSNMOD1NDESIGNDO = 140;
	const uint DPCHAPPPLNRDSNRECDO = 141;
	const uint DPCHAPPPLNRDTPAPARDATA = 142;
	const uint DPCHAPPPLNRDTPAPARDO = 143;
	const uint DPCHAPPPLNRDTPDETAILDATA = 144;
	const uint DPCHAPPPLNRDTPDETAILDO = 145;
	const uint DPCHAPPPLNRDTPDO = 146;
	const uint DPCHAPPPLNRDTPHK1NSTRUCTUREDATA = 147;
	const uint DPCHAPPPLNRDTPHK1NSTRUCTUREDO = 148;
	const uint DPCHAPPPLNRDTPKPARKEYDATA = 149;
	const uint DPCHAPPPLNRDTPKPARKEYDO = 150;
	const uint DPCHAPPPLNRDTPLISTDATA = 151;
	const uint DPCHAPPPLNRDTPLISTDO = 152;
	const uint DPCHAPPPLNRDTPRECDO = 153;
	const uint DPCHAPPPLNRDTPSUP1NDEVICEDATA = 154;
	const uint DPCHAPPPLNRDTPSUP1NDEVICEDO = 155;
	const uint DPCHAPPPLNRDTPTPL1NDEVICEDATA = 156;
	const uint DPCHAPPPLNRDTPTPL1NDEVICEDO = 157;
	const uint DPCHAPPPLNRDVCAPARDATA = 158;
	const uint DPCHAPPPLNRDVCAPARDO = 159;
	const uint DPCHAPPPLNRDVCDETAILDATA = 160;
	const uint DPCHAPPPLNRDVCDETAILDO = 161;
	const uint DPCHAPPPLNRDVCDO = 162;
	const uint DPCHAPPPLNRDVCHK1NARCGUIDEDATA = 163;
	const uint DPCHAPPPLNRDVCHK1NARCGUIDEDO = 164;
	const uint DPCHAPPPLNRDVCHK1NLINEGUIDEDATA = 165;
	const uint DPCHAPPPLNRDVCHK1NLINEGUIDEDO = 166;
	const uint DPCHAPPPLNRDVCHK1NSTRUCTUREDATA = 167;
	const uint DPCHAPPPLNRDVCHK1NSTRUCTUREDO = 168;
	const uint DPCHAPPPLNRDVCHK1NVERTEXDATA = 169;
	const uint DPCHAPPPLNRDVCHK1NVERTEXDO = 170;
	const uint DPCHAPPPLNRDVCLISTDATA = 171;
	const uint DPCHAPPPLNRDVCLISTDO = 172;
	const uint DPCHAPPPLNRDVCRECDO = 173;
	const uint DPCHAPPPLNRDVCSUP1NDEVICEDATA = 174;
	const uint DPCHAPPPLNRDVCSUP1NDEVICEDO = 175;
	const uint DPCHAPPPLNRFILDETAILDATA = 176;
	const uint DPCHAPPPLNRFILDETAILDO = 177;
	const uint DPCHAPPPLNRFILDO = 178;
	const uint DPCHAPPPLNRFILLISTDATA = 179;
	const uint DPCHAPPPLNRFILLISTDO = 180;
	const uint DPCHAPPPLNRFILMNCALCDATA = 181;
	const uint DPCHAPPPLNRFILMNCALCDO = 182;
	const uint DPCHAPPPLNRFILRECDO = 183;
	const uint DPCHAPPPLNRINIT = 184;
	const uint DPCHAPPPLNRLYR1NBLOCKDATA = 185;
	const uint DPCHAPPPLNRLYR1NBLOCKDO = 186;
	const uint DPCHAPPPLNRLYR1NRETICLEDATA = 187;
	const uint DPCHAPPPLNRLYR1NRETICLEDO = 188;
	const uint DPCHAPPPLNRLYRDETAILDATA = 189;
	const uint DPCHAPPPLNRLYRDETAILDO = 190;
	const uint DPCHAPPPLNRLYRDO = 191;
	const uint DPCHAPPPLNRLYRLISTDATA = 192;
	const uint DPCHAPPPLNRLYRLISTDO = 193;
	const uint DPCHAPPPLNRLYRMNSTRUCTUREDATA = 194;
	const uint DPCHAPPPLNRLYRMNSTRUCTUREDO = 195;
	const uint DPCHAPPPLNRLYRRECDO = 196;
	const uint DPCHAPPPLNRMAT1NLAYERDATA = 197;
	const uint DPCHAPPPLNRMAT1NLAYERDO = 198;
	const uint DPCHAPPPLNRMATAPARDATA = 199;
	const uint DPCHAPPPLNRMATAPARDO = 200;
	const uint DPCHAPPPLNRMATDETAILDATA = 201;
	const uint DPCHAPPPLNRMATDETAILDO = 202;
	const uint DPCHAPPPLNRMATDO = 203;
	const uint DPCHAPPPLNRMATLISTDATA = 204;
	const uint DPCHAPPPLNRMATLISTDO = 205;
	const uint DPCHAPPPLNRMATMOD1NMATERIALDATA = 206;
	const uint DPCHAPPPLNRMATMOD1NMATERIALDO = 207;
	const uint DPCHAPPPLNRMATRECDO = 208;
	const uint DPCHAPPPLNRMATREF1NFILEDATA = 209;
	const uint DPCHAPPPLNRMATREF1NFILEDO = 210;
	const uint DPCHAPPPLNRNAVADMINDATA = 211;
	const uint DPCHAPPPLNRNAVADMINDO = 212;
	const uint DPCHAPPPLNRNAVCALCDATA = 213;
	const uint DPCHAPPPLNRNAVCALCDO = 214;
	const uint DPCHAPPPLNRNAVDESIGNDATA = 215;
	const uint DPCHAPPPLNRNAVDESIGNDO = 216;
	const uint DPCHAPPPLNRNAVDO = 217;
	const uint DPCHAPPPLNRNAVGLOBALDATA = 218;
	const uint DPCHAPPPLNRNAVGLOBALDO = 219;
	const uint DPCHAPPPLNRNAVLAYOUTDATA = 220;
	const uint DPCHAPPPLNRNAVLAYOUTDO = 221;
	const uint DPCHAPPPLNRNAVPREDO = 222;
	const uint DPCHAPPPLNRPRJ1NCALCDATA = 223;
	const uint DPCHAPPPLNRPRJ1NCALCDO = 224;
	const uint DPCHAPPPLNRPRJ1NDESIGNDATA = 225;
	const uint DPCHAPPPLNRPRJ1NDESIGNDO = 226;
	const uint DPCHAPPPLNRPRJDETAILDATA = 227;
	const uint DPCHAPPPLNRPRJDETAILDO = 228;
	const uint DPCHAPPPLNRPRJDO = 229;
	const uint DPCHAPPPLNRPRJLISTDATA = 230;
	const uint DPCHAPPPLNRPRJLISTDO = 231;
	const uint DPCHAPPPLNRPRJMNTAPEOUTDATA = 232;
	const uint DPCHAPPPLNRPRJMNTAPEOUTDO = 233;
	const uint DPCHAPPPLNRPRJRECDO = 234;
	const uint DPCHAPPPLNRPRSADETAILDATA = 235;
	const uint DPCHAPPPLNRPRSADETAILDO = 236;
	const uint DPCHAPPPLNRPRSDETAILDATA = 237;
	const uint DPCHAPPPLNRPRSDETAILDO = 238;
	const uint DPCHAPPPLNRPRSDO = 239;
	const uint DPCHAPPPLNRPRSLISTDATA = 240;
	const uint DPCHAPPPLNRPRSLISTDO = 241;
	const uint DPCHAPPPLNRPRSRECDO = 242;
	const uint DPCHAPPPLNRRESUME = 243;
	const uint DPCHAPPPLNRRTCDETAILDATA = 244;
	const uint DPCHAPPPLNRRTCDETAILDO = 245;
	const uint DPCHAPPPLNRRTCDO = 246;
	const uint DPCHAPPPLNRRTCLISTDATA = 247;
	const uint DPCHAPPPLNRRTCLISTDO = 248;
	const uint DPCHAPPPLNRRTCRECDO = 249;
	const uint DPCHAPPPLNRSRU1NBLOCKDATA = 250;
	const uint DPCHAPPPLNRSRU1NBLOCKDO = 251;
	const uint DPCHAPPPLNRSRUDETAILDATA = 252;
	const uint DPCHAPPPLNRSRUDETAILDO = 253;
	const uint DPCHAPPPLNRSRUDO = 254;
	const uint DPCHAPPPLNRSRULISTDATA = 255;
	const uint DPCHAPPPLNRSRULISTDO = 256;
	const uint DPCHAPPPLNRSRUMNLAYERDATA = 257;
	const uint DPCHAPPPLNRSRUMNLAYERDO = 258;
	const uint DPCHAPPPLNRSRUMNSTACKDATA = 259;
	const uint DPCHAPPPLNRSRUMNSTACKDO = 260;
	const uint DPCHAPPPLNRSRURECDO = 261;
	const uint DPCHAPPPLNRSRUSRU1NFACEDATA = 262;
	const uint DPCHAPPPLNRSRUSRU1NFACEDO = 263;
	const uint DPCHAPPPLNRSTKDETAILDATA = 264;
	const uint DPCHAPPPLNRSTKDETAILDO = 265;
	const uint DPCHAPPPLNRSTKDO = 266;
	const uint DPCHAPPPLNRSTKHK1NLAYERDATA = 267;
	const uint DPCHAPPPLNRSTKHK1NLAYERDO = 268;
	const uint DPCHAPPPLNRSTKHK1NLEVELDATA = 269;
	const uint DPCHAPPPLNRSTKHK1NLEVELDO = 270;
	const uint DPCHAPPPLNRSTKLISTDATA = 271;
	const uint DPCHAPPPLNRSTKLISTDO = 272;
	const uint DPCHAPPPLNRSTKMNSTRUCTUREDATA = 273;
	const uint DPCHAPPPLNRSTKMNSTRUCTUREDO = 274;
	const uint DPCHAPPPLNRSTKRECDO = 275;
	const uint DPCHAPPPLNRTPO1NARRAYDATA = 276;
	const uint DPCHAPPPLNRTPO1NARRAYDO = 277;
	const uint DPCHAPPPLNRTPODETAILDATA = 278;
	const uint DPCHAPPPLNRTPODETAILDO = 279;
	const uint DPCHAPPPLNRTPODO = 280;
	const uint DPCHAPPPLNRTPOHK1NRETICLEDATA = 281;
	const uint DPCHAPPPLNRTPOHK1NRETICLEDO = 282;
	const uint DPCHAPPPLNRTPOLISTDATA = 283;
	const uint DPCHAPPPLNRTPOLISTDO = 284;
	const uint DPCHAPPPLNRTPOMNPROJECTDATA = 285;
	const uint DPCHAPPPLNRTPOMNPROJECTDO = 286;
	const uint DPCHAPPPLNRTPORECDO = 287;
	const uint DPCHAPPPLNRUSGAACCESSDATA = 288;
	const uint DPCHAPPPLNRUSGAACCESSDO = 289;
	const uint DPCHAPPPLNRUSGDETAILDATA = 290;
	const uint DPCHAPPPLNRUSGDETAILDO = 291;
	const uint DPCHAPPPLNRUSGDO = 292;
	const uint DPCHAPPPLNRUSGLISTDATA = 293;
	const uint DPCHAPPPLNRUSGLISTDO = 294;
	const uint DPCHAPPPLNRUSGMNUSERDATA = 295;
	const uint DPCHAPPPLNRUSGMNUSERDO = 296;
	const uint DPCHAPPPLNRUSGRECDO = 297;
	const uint DPCHAPPPLNRUSR1NSESSIONDATA = 298;
	const uint DPCHAPPPLNRUSR1NSESSIONDO = 299;
	const uint DPCHAPPPLNRUSRAACCESSDATA = 300;
	const uint DPCHAPPPLNRUSRAACCESSDO = 301;
	const uint DPCHAPPPLNRUSRDETAILDATA = 302;
	const uint DPCHAPPPLNRUSRDETAILDO = 303;
	const uint DPCHAPPPLNRUSRDO = 304;
	const uint DPCHAPPPLNRUSRLISTDATA = 305;
	const uint DPCHAPPPLNRUSRLISTDO = 306;
	const uint DPCHAPPPLNRUSRMNUSERGROUPDATA = 307;
	const uint DPCHAPPPLNRUSRMNUSERGROUPDO = 308;
	const uint DPCHAPPPLNRUSRRECDO = 309;
	const uint DPCHAPPROOTPLNRLOGIN = 310;
	const uint DPCHENGDLGPLNRCLCEXPRTXDATA = 311;
	const uint DPCHENGDLGPLNRCLCGENRPVDATA = 312;
	const uint DPCHENGDLGPLNRCLCUSECASEDATA = 313;
	const uint DPCHENGDLGPLNRDSNGENPLTDATA = 314;
	const uint DPCHENGDLGPLNRFILDLDCPYDATA = 315;
	const uint DPCHENGDLGPLNRNAVLOAINIDATA = 316;
	const uint DPCHENGDLGPLNRTPOUSECASEDATA = 317;
	const uint DPCHENGPLNRACK = 318;
	const uint DPCHENGPLNRALERT = 319;
	const uint DPCHENGPLNRARIAMARRAYENVDATA = 320;
	const uint DPCHENGPLNRARIDATA = 321;
	const uint DPCHENGPLNRARIDETAILDATA = 322;
	const uint DPCHENGPLNRARIHEADBARDATA = 323;
	const uint DPCHENGPLNRARILISTDATA = 324;
	const uint DPCHENGPLNRARIRECDATA = 325;
	const uint DPCHENGPLNRARR1NARRAYITEMDATA = 326;
	const uint DPCHENGPLNRARRAENVDATA = 327;
	const uint DPCHENGPLNRARRDATA = 328;
	const uint DPCHENGPLNRARRDETAILDATA = 329;
	const uint DPCHENGPLNRARRHEADBARDATA = 330;
	const uint DPCHENGPLNRARRHK1NRETICLEDATA = 331;
	const uint DPCHENGPLNRARRKENVKEYDATA = 332;
	const uint DPCHENGPLNRARRLISTDATA = 333;
	const uint DPCHENGPLNRARRRECDATA = 334;
	const uint DPCHENGPLNRCLC1NMATERIALDATA = 335;
	const uint DPCHENGPLNRCLCAENVDATA = 336;
	const uint DPCHENGPLNRCLCAPARDATA = 337;
	const uint DPCHENGPLNRCLCCAL1NCALCITEMDATA = 338;
	const uint DPCHENGPLNRCLCDATA = 339;
	const uint DPCHENGPLNRCLCDETAILDATA = 340;
	const uint DPCHENGPLNRCLCHEADBARDATA = 341;
	const uint DPCHENGPLNRCLCLISTDATA = 342;
	const uint DPCHENGPLNRCLCMNDOMAINDATA = 343;
	const uint DPCHENGPLNRCLCMNFILEDATA = 344;
	const uint DPCHENGPLNRCLCPREDATA = 345;
	const uint DPCHENGPLNRCLCRECDATA = 346;
	const uint DPCHENGPLNRCLCREF1NFILEDATA = 347;
	const uint DPCHENGPLNRCLCSUP1NCALCDATA = 348;
	const uint DPCHENGPLNRCLCVIEWDATA = 349;
	const uint DPCHENGPLNRCLIAAMCALCENVDATA = 350;
	const uint DPCHENGPLNRCLIAAMCALCPARDATA = 351;
	const uint DPCHENGPLNRCLIDATA = 352;
	const uint DPCHENGPLNRCLIDETAILDATA = 353;
	const uint DPCHENGPLNRCLIHEADBARDATA = 354;
	const uint DPCHENGPLNRCLILISTDATA = 355;
	const uint DPCHENGPLNRCLIRECDATA = 356;
	const uint DPCHENGPLNRCLIREF1NFILEDATA = 357;
	const uint DPCHENGPLNRCONFIRM = 358;
	const uint DPCHENGPLNRCTPAENVDATA = 359;
	const uint DPCHENGPLNRCTPAPARDATA = 360;
	const uint DPCHENGPLNRCTPDATA = 361;
	const uint DPCHENGPLNRCTPDETAILDATA = 362;
	const uint DPCHENGPLNRCTPHEADBARDATA = 363;
	const uint DPCHENGPLNRCTPKCALCDOMPRPDATA = 364;
	const uint DPCHENGPLNRCTPKCALCVARDATA = 365;
	const uint DPCHENGPLNRCTPKENVKEYDATA = 366;
	const uint DPCHENGPLNRCTPKPARCATDATA = 367;
	const uint DPCHENGPLNRCTPKPARPROPDATA = 368;
	const uint DPCHENGPLNRCTPLISTDATA = 369;
	const uint DPCHENGPLNRCTPRECDATA = 370;
	const uint DPCHENGPLNRCTPREF1NFILEDATA = 371;
	const uint DPCHENGPLNRCTPSUP1NCALCDATA = 372;
	const uint DPCHENGPLNRCTPTPL1NCALCDATA = 373;
	const uint DPCHENGPLNRDGDDATA = 374;
	const uint DPCHENGPLNRDGDDETAILDATA = 375;
	const uint DPCHENGPLNRDGDHEADBARDATA = 376;
	const uint DPCHENGPLNRDGDLISTDATA = 377;
	const uint DPCHENGPLNRDGDRECDATA = 378;
	const uint DPCHENGPLNRDOMDATA = 379;
	const uint DPCHENGPLNRDOMDETAILDATA = 380;
	const uint DPCHENGPLNRDOMHEADBARDATA = 381;
	const uint DPCHENGPLNRDOMLISTDATA = 382;
	const uint DPCHENGPLNRDOMMNCALCDATA = 383;
	const uint DPCHENGPLNRDOMRECDATA = 384;
	const uint DPCHENGPLNRDSN1NBLOCKDATA = 385;
	const uint DPCHENGPLNRDSN1NRETICLEDATA = 386;
	const uint DPCHENGPLNRDSNDATA = 387;
	const uint DPCHENGPLNRDSNDETAILDATA = 388;
	const uint DPCHENGPLNRDSNDRV1NDESIGNDATA = 389;
	const uint DPCHENGPLNRDSNDSN1NDEVICEDATA = 390;
	const uint DPCHENGPLNRDSNDSN1NDOMAINDATA = 391;
	const uint DPCHENGPLNRDSNDSN1NDOMAINGDDATA = 392;
	const uint DPCHENGPLNRDSNDSN1NSTACKDATA = 393;
	const uint DPCHENGPLNRDSNHEADBARDATA = 394;
	const uint DPCHENGPLNRDSNHK1NARCGUIDEDATA = 395;
	const uint DPCHENGPLNRDSNHK1NLAYERDATA = 396;
	const uint DPCHENGPLNRDSNHK1NLEVELDATA = 397;
	const uint DPCHENGPLNRDSNHK1NLINEGUIDEDATA = 398;
	const uint DPCHENGPLNRDSNHK1NSTRUCTUREDATA = 399;
	const uint DPCHENGPLNRDSNHK1NVERTEXDATA = 400;
	const uint DPCHENGPLNRDSNLISTDATA = 401;
	const uint DPCHENGPLNRDSNMOD1NDESIGNDATA = 402;
	const uint DPCHENGPLNRDSNPREDATA = 403;
	const uint DPCHENGPLNRDSNRECDATA = 404;
	const uint DPCHENGPLNRDSNVIEWXYDATA = 405;
	const uint DPCHENGPLNRDSNVIEWZDATA = 406;
	const uint DPCHENGPLNRDTPAPARDATA = 407;
	const uint DPCHENGPLNRDTPDATA = 408;
	const uint DPCHENGPLNRDTPDETAILDATA = 409;
	const uint DPCHENGPLNRDTPHEADBARDATA = 410;
	const uint DPCHENGPLNRDTPHK1NSTRUCTUREDATA = 411;
	const uint DPCHENGPLNRDTPKPARKEYDATA = 412;
	const uint DPCHENGPLNRDTPLISTDATA = 413;
	const uint DPCHENGPLNRDTPPREDATA = 414;
	const uint DPCHENGPLNRDTPRECDATA = 415;
	const uint DPCHENGPLNRDTPSUP1NDEVICEDATA = 416;
	const uint DPCHENGPLNRDTPTPL1NDEVICEDATA = 417;
	const uint DPCHENGPLNRDTPVIEWDATA = 418;
	const uint DPCHENGPLNRDVCAPARDATA = 419;
	const uint DPCHENGPLNRDVCDATA = 420;
	const uint DPCHENGPLNRDVCDETAILDATA = 421;
	const uint DPCHENGPLNRDVCHEADBARDATA = 422;
	const uint DPCHENGPLNRDVCHK1NARCGUIDEDATA = 423;
	const uint DPCHENGPLNRDVCHK1NLINEGUIDEDATA = 424;
	const uint DPCHENGPLNRDVCHK1NSTRUCTUREDATA = 425;
	const uint DPCHENGPLNRDVCHK1NVERTEXDATA = 426;
	const uint DPCHENGPLNRDVCLISTDATA = 427;
	const uint DPCHENGPLNRDVCPREDATA = 428;
	const uint DPCHENGPLNRDVCRECDATA = 429;
	const uint DPCHENGPLNRDVCSUP1NDEVICEDATA = 430;
	const uint DPCHENGPLNRDVCVIEWDATA = 431;
	const uint DPCHENGPLNRFILDATA = 432;
	const uint DPCHENGPLNRFILDETAILDATA = 433;
	const uint DPCHENGPLNRFILHEADBARDATA = 434;
	const uint DPCHENGPLNRFILLISTDATA = 435;
	const uint DPCHENGPLNRFILMNCALCDATA = 436;
	const uint DPCHENGPLNRFILRECDATA = 437;
	const uint DPCHENGPLNRLYR1NBLOCKDATA = 438;
	const uint DPCHENGPLNRLYR1NRETICLEDATA = 439;
	const uint DPCHENGPLNRLYRDATA = 440;
	const uint DPCHENGPLNRLYRDETAILDATA = 441;
	const uint DPCHENGPLNRLYRHEADBARDATA = 442;
	const uint DPCHENGPLNRLYRLISTDATA = 443;
	const uint DPCHENGPLNRLYRMNSTRUCTUREDATA = 444;
	const uint DPCHENGPLNRLYRRECDATA = 445;
	const uint DPCHENGPLNRMAT1NLAYERDATA = 446;
	const uint DPCHENGPLNRMATAPARDATA = 447;
	const uint DPCHENGPLNRMATDATA = 448;
	const uint DPCHENGPLNRMATDETAILDATA = 449;
	const uint DPCHENGPLNRMATHEADBARDATA = 450;
	const uint DPCHENGPLNRMATLISTDATA = 451;
	const uint DPCHENGPLNRMATMOD1NMATERIALDATA = 452;
	const uint DPCHENGPLNRMATRECDATA = 453;
	const uint DPCHENGPLNRMATREF1NFILEDATA = 454;
	const uint DPCHENGPLNRNAVADMINDATA = 455;
	const uint DPCHENGPLNRNAVCALCDATA = 456;
	const uint DPCHENGPLNRNAVDATA = 457;
	const uint DPCHENGPLNRNAVDESIGNDATA = 458;
	const uint DPCHENGPLNRNAVGLOBALDATA = 459;
	const uint DPCHENGPLNRNAVHEADBARDATA = 460;
	const uint DPCHENGPLNRNAVLAYOUTDATA = 461;
	const uint DPCHENGPLNRNAVPREDATA = 462;
	const uint DPCHENGPLNRPRJ1NCALCDATA = 463;
	const uint DPCHENGPLNRPRJ1NDESIGNDATA = 464;
	const uint DPCHENGPLNRPRJDATA = 465;
	const uint DPCHENGPLNRPRJDETAILDATA = 466;
	const uint DPCHENGPLNRPRJHEADBARDATA = 467;
	const uint DPCHENGPLNRPRJLISTDATA = 468;
	const uint DPCHENGPLNRPRJMNTAPEOUTDATA = 469;
	const uint DPCHENGPLNRPRJRECDATA = 470;
	const uint DPCHENGPLNRPRSADETAILDATA = 471;
	const uint DPCHENGPLNRPRSDATA = 472;
	const uint DPCHENGPLNRPRSDETAILDATA = 473;
	const uint DPCHENGPLNRPRSHEADBARDATA = 474;
	const uint DPCHENGPLNRPRSLISTDATA = 475;
	const uint DPCHENGPLNRPRSRECDATA = 476;
	const uint DPCHENGPLNRRTCDATA = 477;
	const uint DPCHENGPLNRRTCDETAILDATA = 478;
	const uint DPCHENGPLNRRTCHEADBARDATA = 479;
	const uint DPCHENGPLNRRTCLISTDATA = 480;
	const uint DPCHENGPLNRRTCRECDATA = 481;
	const uint DPCHENGPLNRSRU1NBLOCKDATA = 482;
	const uint DPCHENGPLNRSRUDATA = 483;
	const uint DPCHENGPLNRSRUDETAILDATA = 484;
	const uint DPCHENGPLNRSRUHEADBARDATA = 485;
	const uint DPCHENGPLNRSRULISTDATA = 486;
	const uint DPCHENGPLNRSRUMNLAYERDATA = 487;
	const uint DPCHENGPLNRSRUMNSTACKDATA = 488;
	const uint DPCHENGPLNRSRURECDATA = 489;
	const uint DPCHENGPLNRSRUSRU1NFACEDATA = 490;
	const uint DPCHENGPLNRSTKDATA = 491;
	const uint DPCHENGPLNRSTKDETAILDATA = 492;
	const uint DPCHENGPLNRSTKHEADBARDATA = 493;
	const uint DPCHENGPLNRSTKHK1NLAYERDATA = 494;
	const uint DPCHENGPLNRSTKHK1NLEVELDATA = 495;
	const uint DPCHENGPLNRSTKLISTDATA = 496;
	const uint DPCHENGPLNRSTKMNSTRUCTUREDATA = 497;
	const uint DPCHENGPLNRSTKPREDATA = 498;
	const uint DPCHENGPLNRSTKRECDATA = 499;
	const uint DPCHENGPLNRSTKVIEWDATA = 500;
	const uint DPCHENGPLNRSUSPEND = 501;
	const uint DPCHENGPLNRTPO1NARRAYDATA = 502;
	const uint DPCHENGPLNRTPODATA = 503;
	const uint DPCHENGPLNRTPODETAILDATA = 504;
	const uint DPCHENGPLNRTPOFLOORPLANDATA = 505;
	const uint DPCHENGPLNRTPOHEADBARDATA = 506;
	const uint DPCHENGPLNRTPOHK1NRETICLEDATA = 507;
	const uint DPCHENGPLNRTPOLISTDATA = 508;
	const uint DPCHENGPLNRTPOMNPROJECTDATA = 509;
	const uint DPCHENGPLNRTPORECDATA = 510;
	const uint DPCHENGPLNRUSGAACCESSDATA = 511;
	const uint DPCHENGPLNRUSGDATA = 512;
	const uint DPCHENGPLNRUSGDETAILDATA = 513;
	const uint DPCHENGPLNRUSGHEADBARDATA = 514;
	const uint DPCHENGPLNRUSGLISTDATA = 515;
	const uint DPCHENGPLNRUSGMNUSERDATA = 516;
	const uint DPCHENGPLNRUSGRECDATA = 517;
	const uint DPCHENGPLNRUSR1NSESSIONDATA = 518;
	const uint DPCHENGPLNRUSRAACCESSDATA = 519;
	const uint DPCHENGPLNRUSRDATA = 520;
	const uint DPCHENGPLNRUSRDETAILDATA = 521;
	const uint DPCHENGPLNRUSRHEADBARDATA = 522;
	const uint DPCHENGPLNRUSRLISTDATA = 523;
	const uint DPCHENGPLNRUSRMNUSERGROUPDATA = 524;
	const uint DPCHENGPLNRUSRRECDATA = 525;
	const uint DPCHENGSESSPLNRDATA = 526;
	const uint DPCHINVPLNR = 527;
	const uint DPCHINVPLNREXPCOLLDEV = 528;
	const uint DPCHINVPLNREXPCOLLDSN = 529;
	const uint DPCHINVPLNREXPCOLLSTK = 530;
	const uint DPCHINVPLNREXPCORNER = 531;
	const uint DPCHINVPLNREXPCROSS = 532;
	const uint DPCHINVPLNREXPDIRCOUP = 533;
	const uint DPCHINVPLNREXPDISCRES = 534;
	const uint DPCHINVPLNREXPDOTTEXT = 535;
	const uint DPCHINVPLNREXPDSN = 536;
	const uint DPCHINVPLNREXPGRATCPL = 537;
	const uint DPCHINVPLNREXPGRAY = 538;
	const uint DPCHINVPLNREXPIMAGE = 539;
	const uint DPCHINVPLNREXPMARKER = 540;
	const uint DPCHINVPLNREXPPAD = 541;
	const uint DPCHINVPLNREXPPHCSQ = 542;
	const uint DPCHINVPLNREXPPHCSQNEG = 543;
	const uint DPCHINVPLNREXPPHCTRIG = 544;
	const uint DPCHINVPLNREXPPHCTRIGNEG = 545;
	const uint DPCHINVPLNREXPPHOTDET = 546;
	const uint DPCHINVPLNREXPPIE = 547;
	const uint DPCHINVPLNREXPPINOUT = 548;
	const uint DPCHINVPLNREXPROICADP = 549;
	const uint DPCHINVPLNREXPRTRESNEG = 550;
	const uint DPCHINVPLNREXPSPRING = 551;
	const uint DPCHINVPLNREXPSTKPERTPL = 552;
	const uint DPCHINVPLNREXPSTKREGFILL = 553;
	const uint DPCHINVPLNREXPVANDERPAUW = 554;
	const uint DPCHINVPLNREXPWG = 555;
	const uint DPCHINVPLNREXPWGBEND = 556;
	const uint DPCHINVPLNREXPWGBENDNEG = 557;
	const uint DPCHINVPLNREXPWGNEG = 558;
	const uint DPCHINVPLNREXPWGSUSP = 559;
	const uint DPCHINVPLNREXPWGTAP = 560;
	const uint DPCHINVPLNREXPWGTAPNEG = 561;
	const uint DPCHINVPLNRMEEPTRF2D = 562;
	const uint DPCHINVPLNRMEEPTRF3D = 563;
	const uint DPCHINVPLNRPLOTDAT1DGNU = 564;
	const uint DPCHINVPLNRPLOTDAT1DGNUMULT = 565;
	const uint DPCHINVPLNRPLOTDEVSVG = 566;
	const uint DPCHINVPLNRPLOTDOMDAT1DGNU = 567;
	const uint DPCHINVPLNRPLOTDOMDAT2DGNU = 568;
	const uint DPCHINVPLNRPLOTDOMDAT2DPNG = 569;
	const uint DPCHINVPLNRPLOTDOMDAT2DVID = 570;
	const uint DPCHINVPLNRPLOTDOMZCSSVG = 571;
	const uint DPCHINVPLNRPLOTDSNXYSVG = 572;
	const uint DPCHINVPLNRPLOTDSNZSVG = 573;
	const uint DPCHINVPLNRPLOTSTKSVG = 574;
	const uint DPCHINVPLNRPLOTTPOSVG = 575;
	const uint DPCHINVPLNRPLOTTPOTXT = 576;
	const uint DPCHINVPLNRRASTCUB = 577;
	const uint DPCHINVPLNRRASTXYBOX = 578;
	const uint DPCHINVPLNRRASTZLINE = 579;
	const uint DPCHINVPLNRWGMODEFD1D = 580;
	const uint DPCHINVPLNRWGMODEFD2D = 581;
	const uint DPCHINVPLNRWGMODEFEM1D = 582;
	const uint DPCHINVPLNRWGMODEFEM2D = 583;
	const uint DPCHPLNRDACK = 584;
	const uint DPCHPLNRDQUIT = 585;
	const uint DPCHPLNRDREG = 586;
	const uint DPCHPLNROPDREG = 587;
	const uint DPCHPLNROPDUNREG = 588;
	const uint DPCHRETPLNR = 589;
	const uint DPCHRETPLNRPLOTDAT1DGNU = 590;
	const uint DPCHRETPLNRPLOTDAT1DGNUMULT = 591;
	const uint DPCHRETPLNRPLOTDEVSVG = 592;
	const uint DPCHRETPLNRPLOTDOMDAT1DGNU = 593;
	const uint DPCHRETPLNRPLOTDOMDAT2DGNU = 594;
	const uint DPCHRETPLNRPLOTDOMDAT2DPNG = 595;
	const uint DPCHRETPLNRPLOTDOMDAT2DVID = 596;
	const uint DPCHRETPLNRPLOTDOMZCSSVG = 597;
	const uint DPCHRETPLNRPLOTDSNXYSVG = 598;
	const uint DPCHRETPLNRPLOTDSNZSVG = 599;
	const uint DPCHRETPLNRPLOTSTKSVG = 600;
	const uint DPCHRETPLNRPLOTTPOSVG = 601;
	const uint DPCHRETPLNRPLOTTPOTXT = 602;
	const uint DPCHRETPLNRRASTCUB = 603;
	const uint DPCHRETPLNRRASTXYBOX = 604;
	const uint DPCHRETPLNRRASTZLINE = 605;
	const uint DPCHRETPLNRWGMODEFD1D = 606;
	const uint DPCHRETPLNRWGMODEFD2D = 607;

	uint getIx(const string& sref);
	string getSref(const uint ix);
};

#endif

