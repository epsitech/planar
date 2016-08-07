/**
  * \file PnlPlnrDvcDetail.h
  * app access code for job PnlPlnrDvcDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDVCDETAIL_H
#define PNLPLNRDVCDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDvcDetail
  */
namespace PnlPlnrDvcDetail {
	/**
		* VecVDo (full: VecVPlnrDvcDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDvcDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPMTY = 1;
		static const uint NUMFPUPATY = 2;
		static const uint TXFAV1 = 3;
		static const uint TXFPV1 = 4;
		static const uint TXFAV2 = 5;
		static const uint TXFPV2 = 6;
		static const uint TXFX = 7;
		static const uint TXFY = 8;
		static const uint TXFPHI = 9;
		static const uint TXFCMT = 10;

	public:
		ContIac(const uint numFPupMty = 1, const uint numFPupAty = 1, const string& TxfAv1 = "", const string& TxfPv1 = "", const string& TxfAv2 = "", const string& TxfPv2 = "", const string& TxfX = "", const string& TxfY = "", const string& TxfPhi = "", const string& TxfCmt = "");

	public:
		uint numFPupMty;
		uint numFPupAty;
		string TxfAv1;
		string TxfPv1;
		string TxfAv2;
		string TxfPv2;
		string TxfX;
		string TxfY;
		string TxfPhi;
		string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDvcDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTSUP = 3;
		static const uint TXTTPL = 4;
		static const uint TXTAV1 = 5;
		static const uint TXTPV1 = 6;
		static const uint TXTAV2 = 7;
		static const uint TXTPV2 = 8;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtSup = "", const string& TxtTpl = "", const string& TxtAv1 = "", const string& TxtPv1 = "", const string& TxtAv2 = "", const string& TxtPv2 = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtSup;
		string TxtTpl;
		string TxtAv1;
		string TxtPv1;
		string TxtAv2;
		string TxtPv2;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrDvcDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint TXTAV1ALT = 2;
		static const uint TXTPV1ALT = 3;
		static const uint TXTAV2ALT = 4;
		static const uint TXTPV2ALT = 5;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtAv1Alt = false, const bool TxtPv1Alt = false, const bool TxtAv2Alt = false, const bool TxtPv2Alt = false);

	public:
		uint ixPlnrVExpstate;
		bool TxtAv1Alt;
		bool TxtPv1Alt;
		bool TxtAv2Alt;
		bool TxtPv2Alt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDvcDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFAV1VALID = 1;
		static const uint TXFPV1VALID = 2;
		static const uint TXFAV2VALID = 3;
		static const uint TXFPV2VALID = 4;
		static const uint BUTSAVEAVAIL = 5;
		static const uint BUTSAVEACTIVE = 6;
		static const uint BUTDSNVIEWAVAIL = 7;

	public:
		StatShr(const bool TxfAv1Valid = false, const bool TxfPv1Valid = false, const bool TxfAv2Valid = false, const bool TxfPv2Valid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true);

	public:
		bool TxfAv1Valid;
		bool TxfPv1Valid;
		bool TxfAv2Valid;
		bool TxfPv2Valid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDvcDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTDSN = 3;
		static const uint CPTSUP = 4;
		static const uint CPTTPL = 5;
		static const uint CPTMTY = 6;
		static const uint CPTATY = 7;
		static const uint CPTAV1 = 8;
		static const uint CPTPV1 = 9;
		static const uint CPTAV2 = 10;
		static const uint CPTPV2 = 11;
		static const uint CPTX = 12;
		static const uint CPTY = 13;
		static const uint CPTPHI = 14;
		static const uint CPTCMT = 15;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptDsn = "", const string& CptSup = "", const string& CptTpl = "", const string& CptMty = "", const string& CptAty = "", const string& CptAv1 = "", const string& CptPv1 = "", const string& CptAv2 = "", const string& CptPv2 = "", const string& CptX = "", const string& CptY = "", const string& CptPhi = "", const string& CptCmt = "");

	public:
		string Cpt;
		string CptSrf;
		string CptDsn;
		string CptSup;
		string CptTpl;
		string CptMty;
		string CptAty;
		string CptAv1;
		string CptPv1;
		string CptAv2;
		string CptPv2;
		string CptX;
		string CptY;
		string CptPhi;
		string CptCmt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDvcDetailData)
		*/
	class DpchAppData : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint ALL = 3;

	public:
		DpchAppData(const string& scrJref = "", ContIac* contiac = NULL, const set<uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppPlnrDvcDetailDo)
		*/
	class DpchAppDo : public DpchAppPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint IXVDO = 2;
		static const uint ALL = 3;

	public:
		DpchAppDo(const string& scrJref = "", const uint ixVDo = 0, const set<uint>& mask = {NONE});

	public:
		uint ixVDo;

	public:
		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngPlnrDvcDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPATY = 4;
		static const uint FEEDFPUPMTY = 5;
		static const uint STATAPP = 6;
		static const uint STATSHR = 7;
		static const uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupAty;
		Feed feedFPupMty;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

