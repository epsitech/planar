/**
  * \file IexPlnrIni.h
  * import/export handler for database DbsPlnr (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef IEXPLNRINI_H
#define IEXPLNRINI_H

/**
	* IexPlnrIni
	*/
class IexPlnrIni : public JobPlnr {

public:
	/**
		* VecVIme (full: VecVIexPlnrIniIme)
		*/
	class VecVIme {

	public:
		static const uint IMEIAVCONTROLPAR = 1;
		static const uint IMEIAVKEYLISTKEY1 = 2;
		static const uint IMEIAVVALUELISTVAL = 3;
		static const uint IMEIMCALC = 4;
		static const uint IMEIMDEVICE = 5;
		static const uint IMEIMFILE = 6;
		static const uint IMEIMMATERIAL = 7;
		static const uint IMEIMUSERGROUP = 8;
		static const uint IMEIAMDEVICEPAR = 9;
		static const uint IMEIAMMATERIALPAR = 10;
		static const uint IMEIAMUSERGROUPACCESS = 11;
		static const uint IMEIAVKEYLISTKEY2 = 12;
		static const uint IMEIAVKEYLISTKEY3 = 13;
		static const uint IMEIJAVKEYLISTKEY1 = 14;
		static const uint IMEIMSTRUCTURE = 15;
		static const uint IMEIMUSER = 16;
		static const uint IMEIJAVKEYLISTKEY2 = 17;
		static const uint IMEIJAVKEYLISTKEY3 = 18;
		static const uint IMEIJMUSERSTATE = 19;
		static const uint IMEIMPERSON = 20;
		static const uint IMEIJMPERSONLASTNAME = 21;

		static uint getIx(const string& sref);
		static string getSref(const uint ix);
	};

public:
	/**
		* ImeitemIAVControlPar (full: ImeitemIPlnrIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public PlnrAVControlPar {

	public:
		ImeitemIAVControlPar(const uint ixPlnrVControl = 0, const string& Par = "", const string& Val = "");
		ImeitemIAVControlPar(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIPlnrIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXPLNRVCONTROL = 1;
			static const uint PAR = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey1 (full: ImeitemIPlnrIniJAVKeylistKey1)
		*/
	class ImeitemIJAVKeylistKey1 : public PlnrJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey1(const uint x1IxPlnrVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey1(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey1 (full: ImeIPlnrIniJAVKeylistKey1)
		*/
	class ImeIJAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniJAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXPLNRVLOCALE = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJAVKeylistKey1();
		~ImeIJAVKeylistKey1();

	public:
		vector<ImeitemIJAVKeylistKey1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey1 (full: ImeitemIPlnrIniAVKeylistKey1)
		*/
	class ImeitemIAVKeylistKey1 : public PlnrAVKeylistKey {

	public:
		ImeitemIAVKeylistKey1(const uint klsIxPlnrVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey1(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey1 imeijavkeylistkey1;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey1 (full: ImeIPlnrIniAVKeylistKey1)
		*/
	class ImeIAVKeylistKey1 {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAVKeylistKey1Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFKLSIXPLNRVKEYLIST = 1;
			static const uint SREF = 2;
			static const uint AVAIL = 4;
			static const uint IMPLIED = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey1();
		~ImeIAVKeylistKey1();

	public:
		vector<ImeitemIAVKeylistKey1*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIPlnrIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public PlnrAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const uint vlsIxPlnrVValuelist = 0, const uint x1IxPlnrVLocale = 0, const string& Val = "");
		ImeitemIAVValuelistVal(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIPlnrIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const uint SREFVLSIXPLNRVVALUELIST = 1;
			static const uint SREFX1IXPLNRVLOCALE = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey3 (full: ImeitemIPlnrIniJAVKeylistKey3)
		*/
	class ImeitemIJAVKeylistKey3 : public PlnrJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey3(const uint x1IxPlnrVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey3(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey3 (full: ImeIPlnrIniJAVKeylistKey3)
		*/
	class ImeIJAVKeylistKey3 {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniJAVKeylistKey3Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXPLNRVLOCALE = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJAVKeylistKey3();
		~ImeIJAVKeylistKey3();

	public:
		vector<ImeitemIJAVKeylistKey3*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey3 (full: ImeitemIPlnrIniAVKeylistKey3)
		*/
	class ImeitemIAVKeylistKey3 : public PlnrAVKeylistKey {

	public:
		ImeitemIAVKeylistKey3(const uint klsIxPlnrVKeylist = 0, const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey3(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey3 imeijavkeylistkey3;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey3 (full: ImeIPlnrIniAVKeylistKey3)
		*/
	class ImeIAVKeylistKey3 {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAVKeylistKey3Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFKLSIXPLNRVKEYLIST = 1;
			static const uint SREF = 2;
			static const uint AVAIL = 4;
			static const uint IMPLIED = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey3();
		~ImeIAVKeylistKey3();

	public:
		vector<ImeitemIAVKeylistKey3*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMCalc (full: ImeitemIPlnrIniMCalc)
		*/
	class ImeitemIMCalc : public PlnrMCalc {

	public:
		ImeitemIMCalc(const uint ixVDim = 0, const string& Title = "", const string& Comment = "");
		ImeitemIMCalc(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAVKeylistKey3 imeiavkeylistkey3;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMCalc (full: ImeIPlnrIniMCalc)
		*/
	class ImeIMCalc {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMCalcIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVDIM = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMCalc();
		~ImeIMCalc();

	public:
		vector<ImeitemIMCalc*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMDevicePar (full: ImeitemIPlnrIniAMDevicePar)
		*/
	class ImeitemIAMDevicePar : public PlnrAMDevicePar {

	public:
		ImeitemIAMDevicePar(const string& x2SrefKKey = "", const ubigint irefRefPlnrMFile = 0, const string& Val = "");
		ImeitemIAMDevicePar(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint irefRefPlnrMFile;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMDevicePar (full: ImeIPlnrIniAMDevicePar)
		*/
	class ImeIAMDevicePar {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAMDeviceParIel)
			*/
		class VecWIel {

		public:
			static const uint X2SREFKKEY = 1;
			static const uint IREFREFPLNRMFILE = 2;
			static const uint VAL = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMDevicePar();
		~ImeIAMDevicePar();

	public:
		vector<ImeitemIAMDevicePar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey2 (full: ImeitemIPlnrIniJAVKeylistKey2)
		*/
	class ImeitemIJAVKeylistKey2 : public PlnrJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey2(const uint x1IxPlnrVLocale = 0, const string& Title = "", const string& Comment = "");
		ImeitemIJAVKeylistKey2(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey2 (full: ImeIPlnrIniJAVKeylistKey2)
		*/
	class ImeIJAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniJAVKeylistKey2Iel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXPLNRVLOCALE = 1;
			static const uint TITLE = 2;
			static const uint COMMENT = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJAVKeylistKey2();
		~ImeIJAVKeylistKey2();

	public:
		vector<ImeitemIJAVKeylistKey2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey2 (full: ImeitemIPlnrIniAVKeylistKey2)
		*/
	class ImeitemIAVKeylistKey2 : public PlnrAVKeylistKey {

	public:
		ImeitemIAVKeylistKey2(const string& sref = "", const string& Avail = "", const string& Implied = "");
		ImeitemIAVKeylistKey2(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJAVKeylistKey2 imeijavkeylistkey2;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey2 (full: ImeIPlnrIniAVKeylistKey2)
		*/
	class ImeIAVKeylistKey2 {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAVKeylistKey2Iel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint AVAIL = 2;
			static const uint IMPLIED = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAVKeylistKey2();
		~ImeIAVKeylistKey2();

	public:
		vector<ImeitemIAVKeylistKey2*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMStructure (full: ImeitemIPlnrIniMStructure)
		*/
	class ImeitemIMStructure : public PlnrMStructure {

	public:
		ImeitemIMStructure(const string& sref = "");
		ImeitemIMStructure(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMStructure (full: ImeIPlnrIniMStructure)
		*/
	class ImeIMStructure {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMStructureIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMStructure();
		~ImeIMStructure();

	public:
		vector<ImeitemIMStructure*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMDevice (full: ImeitemIPlnrIniMDevice)
		*/
	class ImeitemIMDevice : public PlnrMDevice {

	public:
		ImeitemIMDevice(const ubigint iref = 0, const ubigint irefSupRefPlnrMDevice = 0, const string& sref = "", const string& Comment = "");
		ImeitemIMDevice(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;
		ubigint irefSupRefPlnrMDevice;

		ImeIAMDevicePar imeiamdevicepar;
		ImeIAVKeylistKey2 imeiavkeylistkey2;
		ImeIMStructure imeimstructure;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMDevice (full: ImeIPlnrIniMDevice)
		*/
	class ImeIMDevice {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMDeviceIel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint IREFSUPREFPLNRMDEVICE = 2;
			static const uint SREF = 4;
			static const uint COMMENT = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMDevice();
		~ImeIMDevice();

	public:
		vector<ImeitemIMDevice*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile (full: ImeitemIPlnrIniMFile)
		*/
	class ImeitemIMFile : public PlnrMFile {

	public:
		ImeitemIMFile(const ubigint iref = 0, const string& osrefKContent = "", const string& Filename = "", const string& srefKMimetype = "", const string& Comment = "");
		ImeitemIMFile(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile (full: ImeIPlnrIniMFile)
		*/
	class ImeIMFile {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMFileIel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint OSREFKCONTENT = 2;
			static const uint FILENAME = 4;
			static const uint SREFKMIMETYPE = 8;
			static const uint COMMENT = 16;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMFile();
		~ImeIMFile();

	public:
		vector<ImeitemIMFile*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMMaterialPar (full: ImeitemIPlnrIniAMMaterialPar)
		*/
	class ImeitemIAMMaterialPar : public PlnrAMMaterialPar {

	public:
		ImeitemIAMMaterialPar(const string& x2SrefKCat = "", const string& x3SrefKProp = "", const ubigint irefRefPlnrMFile = 0, const string& Val = "", const string& Comment = "");
		ImeitemIAMMaterialPar(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint irefRefPlnrMFile;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMMaterialPar (full: ImeIPlnrIniAMMaterialPar)
		*/
	class ImeIAMMaterialPar {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAMMaterialParIel)
			*/
		class VecWIel {

		public:
			static const uint X2SREFKCAT = 1;
			static const uint X3SREFKPROP = 2;
			static const uint IREFREFPLNRMFILE = 4;
			static const uint VAL = 8;
			static const uint COMMENT = 16;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMMaterialPar();
		~ImeIAMMaterialPar();

	public:
		vector<ImeitemIAMMaterialPar*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMMaterial (full: ImeitemIPlnrIniMMaterial)
		*/
	class ImeitemIMMaterial : public PlnrMMaterial {

	public:
		ImeitemIMMaterial(const ubigint iref = 0, const uint ixVBasetype = 0, const ubigint irefModRefPlnrMMaterial = 0, const string& sref = "", const string& Title = "");
		ImeitemIMMaterial(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ubigint iref;
		ubigint irefModRefPlnrMMaterial;

		ImeIAMMaterialPar imeiammaterialpar;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMMaterial (full: ImeIPlnrIniMMaterial)
		*/
	class ImeIMMaterial {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMMaterialIel)
			*/
		class VecWIel {

		public:
			static const uint IREF = 1;
			static const uint SREFIXVBASETYPE = 2;
			static const uint IREFMODREFPLNRMMATERIAL = 4;
			static const uint SREF = 8;
			static const uint TITLE = 16;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMMaterial();
		~ImeIMMaterial();

	public:
		vector<ImeitemIMMaterial*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIPlnrIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public PlnrAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const uint x1IxPlnrVCard = 0, const uint ixPlnrWUiaccess = 0);
		ImeitemIAMUsergroupAccess(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIPlnrIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const uint SREFX1IXPLNRVCARD = 1;
			static const uint SREFSIXPLNRWUIACCESS = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIPlnrIniJMUserState)
		*/
	class ImeitemIJMUserState : public PlnrJMUserState {

	public:
		ImeitemIJMUserState(const uint ixVState = 0);
		ImeitemIJMUserState(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIPlnrIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSTATE = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIPlnrIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public PlnrJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const string& Lastname = "");
		ImeitemIJMPersonLastname(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIPlnrIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const uint LASTNAME = 1;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIPlnrIniMPerson)
		*/
	class ImeitemIMPerson : public PlnrMPerson {

	public:
		ImeitemIMPerson(const uint ixVSex = 0, const string& Title = "", const string& Firstname = "");
		ImeitemIMPerson(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIPlnrIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const uint SREFIXVSEX = 1;
			static const uint TITLE = 2;
			static const uint FIRSTNAME = 4;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIPlnrIniMUser)
		*/
	class ImeitemIMUser : public PlnrMUser {

	public:
		ImeitemIMUser(const string& sref = "", const uint ixPlnrVLocale = 0, const uint ixPlnrVUserlevel = 0, const string& Password = "");
		ImeitemIMUser(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIPlnrIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMUserIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint SREFIXPLNRVLOCALE = 2;
			static const uint SREFIXPLNRVUSERLEVEL = 4;
			static const uint PASSWORD = 8;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIPlnrIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public PlnrMUsergroup {

	public:
		ImeitemIMUsergroup(const string& sref = "", const string& Comment = "");
		ImeitemIMUsergroup(DbsPlnr* dbsplnr, const ubigint ref);

	public:
		uint lineno;
		uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const string& basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIPlnrIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIPlnrIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const uint SREF = 1;
			static const uint COMMENT = 2;

			static uint getIx(const string& srefs);
			static void getIcs(const uint ix, set<uint>& ics);
			static string getSrefs(const uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		bool readTxt(Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, string basexpath);

		void writeTxt(fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

public:
	IexPlnrIni(XchgPlnr* xchg, DbsPlnr* dbsplnr, const ubigint jrefSup, const uint ixPlnrVLocale);
	~IexPlnrIni();

public:
	uint lineno;
	uint impcnt;

	ImeIAVControlPar imeiavcontrolpar;
	ImeIAVKeylistKey1 imeiavkeylistkey1;
	ImeIAVValuelistVal imeiavvaluelistval;
	ImeIMCalc imeimcalc;
	ImeIMDevice imeimdevice;
	ImeIMFile imeimfile;
	ImeIMMaterial imeimmaterial;
	ImeIMUsergroup imeimusergroup;

public:
// IP cust --- INSERT

public:
	void reset();

	void import(DbsPlnr* dbsplnr);

	void collect(DbsPlnr* dbsplnr, const map<uint,uint>& icsDartVIop = icsPlnrVIopInsAll());

public:
	bool readTxt(Txtrd& txtrd);
	void readXML(xmlXPathContext* docctx, string basexpath);

	bool readTxtFile(const string& fullpath);
	bool readXMLFile(const string& fullpath);

	void writeTxt(fstream& outfile);
	void writeXML(xmlTextWriter* wr, const bool shorttags);

	void writeTxtFile(const string& fullpath);
	void writeXMLFile(const string& fullpath, const bool shorttags);

	static map<uint,uint> icsPlnrVIopInsAll();
	uint getIxPlnrVIop(const map<uint,uint>& icsPlnrVIop, const uint ixVIme, uint& ixPlnrVIop);

public:
	void handleRequest(DbsPlnr* dbsplnr, ReqPlnr* req);

	void handleCall(DbsPlnr* dbsplnr, Call* call);
};

#endif


