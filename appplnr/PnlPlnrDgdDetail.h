/**
  * \file PnlPlnrDgdDetail.h
  * app access code for job PnlPlnrDgdDetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PNLPLNRDGDDETAIL_H
#define PNLPLNRDGDDETAIL_H

#include "AppPlnr_blks.h"

/**
  * PnlPlnrDgdDetail
  */
namespace PnlPlnrDgdDetail {
	/**
		* VecVDo (full: VecVPlnrDgdDetailDo)
		*/
	class VecVDo {

	public:
		static const uint BUTSAVECLICK = 1;
		static const uint BUTDSNVIEWCLICK = 2;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

	/**
	  * ContIac (full: ContIacPlnrDgdDetail)
	  */
	class ContIac : public Block {

	public:
		static const uint NUMFPUPTYP = 1;
		static const uint TXFLVL = 2;
		static const uint TXFAV1 = 3;
		static const uint TXFAV2 = 4;
		static const uint TXFAL1 = 5;
		static const uint TXFAL2 = 6;
		static const uint TXFAGD = 7;
		static const uint TXFD = 8;
		static const uint TXFDPH = 9;

	public:
		ContIac(const uint numFPupTyp = 1, const string& TxfLvl = "", const string& TxfAv1 = "", const string& TxfAv2 = "", const string& TxfAl1 = "", const string& TxfAl2 = "", const string& TxfAgd = "", const string& TxfD = "", const string& TxfDph = "");

	public:
		uint numFPupTyp;
		string TxfLvl;
		string TxfAv1;
		string TxfAv2;
		string TxfAl1;
		string TxfAl2;
		string TxfAgd;
		string TxfD;
		string TxfDph;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, string difftag = "", bool shorttags = true);
		set<uint> comm(const ContIac* comp);
		set<uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfPlnrDgdDetail)
	  */
	class ContInf : public Block {

	public:
		static const uint TXTSRF = 1;
		static const uint TXTDSN = 2;
		static const uint TXTLVL = 3;
		static const uint TXTAV1 = 4;
		static const uint TXTAV2 = 5;
		static const uint TXTAL1 = 6;
		static const uint TXTAL2 = 7;
		static const uint TXTAGD = 8;

	public:
		ContInf(const string& TxtSrf = "", const string& TxtDsn = "", const string& TxtLvl = "", const string& TxtAv1 = "", const string& TxtAv2 = "", const string& TxtAl1 = "", const string& TxtAl2 = "", const string& TxtAgd = "");

	public:
		string TxtSrf;
		string TxtDsn;
		string TxtLvl;
		string TxtAv1;
		string TxtAv2;
		string TxtAl1;
		string TxtAl2;
		string TxtAgd;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const ContInf* comp);
		set<uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppPlnrDgdDetail)
	  */
	class StatApp : public Block {

	public:
		static const uint IXPLNRVEXPSTATE = 1;
		static const uint TXTLVLALT = 2;
		static const uint TXTAV1ALT = 3;
		static const uint TXTAV2ALT = 4;
		static const uint TXTAL1ALT = 5;
		static const uint TXTAL2ALT = 6;
		static const uint TXTAGDALT = 7;

	public:
		StatApp(const uint ixPlnrVExpstate = VecPlnrVExpstate::MIND, const bool TxtLvlAlt = false, const bool TxtAv1Alt = false, const bool TxtAv2Alt = false, const bool TxtAl1Alt = false, const bool TxtAl2Alt = false, const bool TxtAgdAlt = false);

	public:
		uint ixPlnrVExpstate;
		bool TxtLvlAlt;
		bool TxtAv1Alt;
		bool TxtAv2Alt;
		bool TxtAl1Alt;
		bool TxtAl2Alt;
		bool TxtAgdAlt;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatApp* comp);
		set<uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrPlnrDgdDetail)
	  */
	class StatShr : public Block {

	public:
		static const uint TXFLVLVALID = 1;
		static const uint TXFAV1VALID = 2;
		static const uint TXFAV2VALID = 3;
		static const uint TXFAL1VALID = 4;
		static const uint TXFAL2VALID = 5;
		static const uint TXFAGDVALID = 6;
		static const uint BUTSAVEAVAIL = 7;
		static const uint BUTSAVEACTIVE = 8;
		static const uint BUTDSNVIEWAVAIL = 9;

	public:
		StatShr(const bool TxfLvlValid = false, const bool TxfAv1Valid = false, const bool TxfAv2Valid = false, const bool TxfAl1Valid = false, const bool TxfAl2Valid = false, const bool TxfAgdValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool ButDsnViewAvail = true);

	public:
		bool TxfLvlValid;
		bool TxfAv1Valid;
		bool TxfAv2Valid;
		bool TxfAl1Valid;
		bool TxfAl2Valid;
		bool TxfAgdValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool ButDsnViewAvail;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
		set<uint> comm(const StatShr* comp);
		set<uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagPlnrDgdDetail)
	  */
	class Tag : public Block {

	public:
		static const uint CPT = 1;
		static const uint CPTSRF = 2;
		static const uint CPTTYP = 3;
		static const uint CPTDSN = 4;
		static const uint CPTLVL = 5;
		static const uint CPTAV1 = 6;
		static const uint CPTAV2 = 7;
		static const uint CPTAL1 = 8;
		static const uint CPTAL2 = 9;
		static const uint CPTAGD = 10;
		static const uint CPTD = 11;
		static const uint CPTDPH = 12;

	public:
		Tag(const string& Cpt = "", const string& CptSrf = "", const string& CptTyp = "", const string& CptDsn = "", const string& CptLvl = "", const string& CptAv1 = "", const string& CptAv2 = "", const string& CptAl1 = "", const string& CptAl2 = "", const string& CptAgd = "", const string& CptD = "", const string& CptDph = "");

	public:
		string Cpt;
		string CptSrf;
		string CptTyp;
		string CptDsn;
		string CptLvl;
		string CptAv1;
		string CptAv2;
		string CptAl1;
		string CptAl2;
		string CptAgd;
		string CptD;
		string CptDph;

	public:
		bool readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppPlnrDgdDetailData)
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
		* DpchAppDo (full: DpchAppPlnrDgdDetailDo)
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
		* DpchEngData (full: DpchEngPlnrDgdDetailData)
		*/
	class DpchEngData : public DpchEngPlnr {

	public:
		static const uint SCRJREF = 1;
		static const uint CONTIAC = 2;
		static const uint CONTINF = 3;
		static const uint FEEDFPUPTYP = 4;
		static const uint STATAPP = 5;
		static const uint STATSHR = 6;
		static const uint TAG = 7;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Feed feedFPupTyp;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		void readXML(xmlXPathContext* docctx, string basexpath = "", bool addbasetag = false);
	};

};

#endif

