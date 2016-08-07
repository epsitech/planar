/**
  * \file Plnr.cpp
  * Plnr global functionality (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "Plnr.h"

// IP acv --- BEGIN
/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const string& path
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	PlnrMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	fil = new PlnrMFile(0, 0, 0, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	dbsplnr->tblplnrmfile->insertRec(fil);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbsplnr->tblplnrmfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	// copy file
	s = "cp " + path + " " + str.str() + "/" + fil->Archivename;
	system(s.c_str());

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	PlnrMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbsplnr->tblplnrmfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbsplnr->tblplnrmfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

		// copy file
		s = "cp " + path + " " + str.str() + "/" + fil->Archivename;
		system(s.c_str());

		delete fil;
	};
};

string Acv::getfile(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMFile
		) {
	PlnrMFile* fil = NULL;

	ostringstream str;

	dbsplnr->tblplnrmfile->loadRecByRef(refPlnrMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};
// IP acv --- END

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixPlnrVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixPlnrVLop == VecPlnrVLop::INS) insert(refsList, refsPool, ref);
	else if (ixPlnrVLop == VecPlnrVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsPool.size();i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixPlnrVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixPlnrVOolop == VecPlnrVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixPlnrVOolop == VecPlnrVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixPlnrVOolop == VecPlnrVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixPlnrVOolop == VecPlnrVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixPlnrVOolop == VecPlnrVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixPlnrVOolop == VecPlnrVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool=refsPool.begin();itPool!=refsPool.end();itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k=i+1;k<j;k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i=0;i<refsList.size();i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j=i+1;j<refsList.size();j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k=i+1;k<j;k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList=refsList.begin();itList!=refsList.end();itList++) {
		if (*itList == ref1) {
			for (auto itList2=refsList.begin();itList2!=refsList.end();itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename + "." + ext;

		// check if present, create otherwise
		if (access(filename.c_str(), R_OK | W_OK) == -1) {
			tmpfile.open(filename.c_str(), ios::out);
			tmpfile.close();

			valid = true;
		};
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// check if present, create otherwise
		if (access(foldername.c_str(), R_OK | W_OK) == -1) {
#ifdef _WIN32
			mkdir(foldername.c_str());
#else
			mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

			valid = true;
		};
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i=0;i<8;i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- IBEGIN
/******************************************************************************
 namespace Cdf
 ******************************************************************************/

void Cdf::putBoolVec(
			const int ncid
			, const int varid
			, const vector<bool>& vec
		) {
	unsigned char* boolbuf = NULL;

	boolbuf = new unsigned char[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) boolbuf[i] = ((vec[i]) ? 1 : 0);

	nc_put_var_uchar(ncid, varid, boolbuf);

	delete[] boolbuf;
};

void Cdf::putUintVec(
			const int ncid
			, const int varid
			, const vector<uint>& vec
		) {
	uint* uintbuf = NULL;

	uintbuf = new uint[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) uintbuf[i] = vec[i];

	nc_put_var_uint(ncid, varid, uintbuf);

	delete[] uintbuf;
};

void Cdf::putUbigintVec(
			const int ncid
			, const int varid
			, const vector<ubigint>& vec
		) {
	ubigint* ubigintbuf = NULL;

	ubigintbuf = new ubigint[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) ubigintbuf[i] = vec[i];

	nc_put_var_ulonglong(ncid, varid, ubigintbuf);

	delete[] ubigintbuf;
};

void Cdf::putDoubleVec(
			const int ncid
			, const int varid
			, const vector<double>& vec
		) {
	double* dblbuf = NULL;

	dblbuf = new double[vec.size()];
	for (unsigned int i=0;i<vec.size();i++) dblbuf[i] = vec[i];

	nc_put_var_double(ncid, varid, dblbuf);

	delete[] dblbuf;
};

bool Cdf::getGroup(
			const int ncid
			, const string& path
			, int& pathid
		) {
	bool retval = true;

	vector<string> pathvec;
	pathid = ncid;

	// find group
	StrMod::stringToVector(path, pathvec);
	for (unsigned int i=0;i<pathvec.size();i++) {
		if (nc_inq_ncid(pathid, pathvec[i].c_str(), &pathid) != NC_NOERR) {
			retval = false;
			break;
		};
	};

	return retval;
};

bool Cdf::getBoolVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<bool>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	unsigned char* boolbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			boolbuf = new unsigned char[N];

			// fetch variable
			nc_get_var_uchar(pathid, varid, boolbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = (boolbuf[i] == 1);

			// clean up
			delete[] boolbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getUintVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<uint>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	uint* uintbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			uintbuf = new uint[N];

			// fetch variable
			nc_get_var_uint(pathid, varid, uintbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = uintbuf[i];

			// clean up
			delete[] uintbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getUbigintVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<ubigint>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	ubigint* ubigintbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			ubigintbuf = new ubigint[N];

			// fetch variable
			nc_get_var_ulonglong(pathid, varid, ubigintbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = ubigintbuf[i];

			// clean up
			delete[] ubigintbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getDoubleVec(
			const int ncid
			, const string& path
			, const string& varsref
			, vector<double>& vec
		) {
	int pathid;
	int varid;

	int dimid;
	size_t N;

	double* dblbuf = NULL;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find and adjust vector dimension
			nc_inq_vardimid(pathid, varid, &dimid);
			nc_inq_dimlen(pathid, dimid, &N);
			dblbuf = new double[N];

			// fetch variable
			nc_get_var_double(pathid, varid, dblbuf);
			
			vec.resize(0); vec.resize(N);
			for (unsigned int i=0;i<N;i++) vec[i] = dblbuf[i];

			// clean up
			delete[] dblbuf;

			return true;
		};
	};

	return false;
};

bool Cdf::getDoubleVecSlc(
			const int ncid
			, const string& path
			, const string& varsref
			, const vector<string>& slcDims
			, const vector<int>& slcIcs
			, const unsigned int Ntarget
			, vector<double>& vec
		) {
	int pathid, varid;
	char* dimname = NULL;

	int ndims;
	int* dimids = NULL;
	size_t* start = NULL;
	size_t* count = NULL;

	size_t N;
	double* dblbuf = NULL;

	if (Cdf::getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {

			// retrieve variable dimension information
			nc_inq_varndims(pathid, varid, &ndims);
			dimids = new int[ndims];
			nc_inq_vardimid(pathid, varid, dimids);

			// prepare array read start/counts
			start = new size_t[ndims];
			count = new size_t[ndims];

			dimname = new char[NC_MAX_NAME+1];

			for (int i=0;i<ndims;i++) {
				// initialize with full dimension lengths
				start[i] = 0;
				nc_inq_dimlen(pathid, dimids[i], &(count[i]));

				// override with yslc information where needed
				nc_inq_dimname(pathid, dimids[i], dimname);

				for (unsigned int j=0;j<slcDims.size();j++) {
cout << "slcDim = '" << slcDims[j] << "' vs. dimname = '" << dimname << "'" << endl;
					if (slcDims[j].compare(dimname) == 0) {
						// count[i] holds the dimension length

						if (slcIcs[j] < 0) {
							// negative index: substract from count[i] unless out of range => center
							if ( ((size_t) -slcIcs[j]) <= count[i] ) {
								start[i] = count[i] + slcIcs[j];
							} else {
								start[i] = count[i]/2;
							};

						} else {
							// positive index: actual index unless out of range => center
							if ( ((size_t) slcIcs[j]) < count[i] ) {
								start[i] = slcIcs[j];
							} else {
								start[i] = count[i]/2;
							};
						};

						count[i] = 1;
						
						break;
					};
				};
			};

			// calculate total array size, needs to equal targetted size
			N = 1;
			for (int i=0;i<ndims;i++) N *= count[i];

cout << "N = " << N << ", Ntarget = " << Ntarget << endl;

			// load y data
			if (N == Ntarget) {
				dblbuf = new double[N];

				// fetch variable
				nc_get_vara_double(pathid, varid, start, count, dblbuf);

				vec.resize(0); vec.resize(N);
				for (unsigned int i=0;i<N;i++) vec[i] = dblbuf[i];
				
				// clean up
				delete[] dblbuf;
			};

			delete[] dimids;
			delete[] start;
			delete[] count;
			delete[] dimname;
			
			return true;
		};
	};

	return false;
};

bool Cdf::getUint(
			const int ncid
			, const string& path
			, const string& varsref
			, uint& val
		) {
	int pathid;
	int varid;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// fetch variable
			nc_get_var_uint(pathid, varid, &val);
			return true;
		};
	};

	return false;
};

bool Cdf::getDouble(
			const int ncid
			, const string& path
			, const string& varsref
			, double& val
		) {
	int pathid;
	int varid;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// fetch variable
			nc_get_var_double(pathid, varid, &val);
			return true;
		};
	};

	return false;
};

bool Cdf::getDim(
			const int ncid
			, const string& path
			, const string& dimsref
			, int& dimid
			, unsigned int& dimlen
		) {
	int pathid;

	size_t N;

	if (getGroup(ncid, path, pathid)) {
		// find dimension
		if (nc_inq_dimid(pathid, dimsref.c_str(), &dimid) == NC_NOERR) {
			nc_inq_dimlen(pathid, dimid, &N);
			dimlen = N;

			return true;
		};
	};

	return false;
};

bool Cdf::getAttr(
			const int ncid
			, const string& path
			, const string& varsref
			, const string& attrsref
			, string& attr
		) {
	int pathid;
	int varid;

	char* attrbuf = NULL;
	size_t attrlen;

	if (getGroup(ncid, path, pathid)) {
		// find variable
		if (nc_inq_varid(pathid, varsref.c_str(), &varid) == NC_NOERR) {
			// find attribute
			if (nc_inq_attlen(pathid, varid, attrsref.c_str(), &attrlen) == NC_NOERR) {
				attrbuf = new char[attrlen];

				nc_get_att_text(pathid, varid, attrsref.c_str(), attrbuf);
				attr = attrbuf;

				delete[] attrbuf;

				return true;
			};
		};
	};

	return false;
};

/******************************************************************************
 namespace Dotmatrix
 ******************************************************************************/

bool Dotmatrix::dmNull(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmA(
			const unsigned int ix
		) {
	dm ch = {
			false, false, true, false, false,
			false, true, false, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, true,
			true, false, false, false, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmB(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmC(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, true,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			false, true, true, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmD(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmE(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			true, false, false, false, false,
			true, false, false, false, false,
			true, true, true, true, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, true, true, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmF(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			true, false, false, false, false,
			true, false, false, false, false,
			true, true, true, true, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmG(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, true,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, true, true, true,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmH(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmI(
			const unsigned int ix
		) {
	dm ch = {
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmJ(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			false, false, false, false, true,
			false, false, false, false, true,
			false, false, false, false, true,
			false, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmK(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, true, false,
			true, false, true, false, false,
			true, true, false, false, false,
			true, false, true, false, false,
			true, false, false, true, false,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmL(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, true, true, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmM(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, true, false, true, true,
			true, false, true, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmN(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, true, false, false, true,
			true, false, true, false, true,
			true, false, false, true, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmO(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmP(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, false,
			true, false, false, false, false,
			true, false, false, false, false,
			true, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmQ(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false,
			false, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmR(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmS(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, true,
			true, false, false, false, false,
			true, false, false, false, false,
			false, true, true, true, false,
			false, false, false, false, true,
			false, false, false, false, true,
			true, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmT(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmU(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmV(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, false, true, false,
			false, false, true, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmW(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, false, false, true,
			true, false, true, false, true,
			true, true, false, true, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmX(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, false, true, false,
			false, false, true, false, false,
			false, true, false, true, false,
			true, false, false, false, true,
			true, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmY(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, false, true, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmZ(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			false, false, false, false, true,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			true, false, false, false, false,
			true, true, true, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dm0(
			const unsigned int ix
		) {
	dm ch  = {
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, true, true,
			true, false, true, false, true,
			true, true, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm1(
			const unsigned int ix
		) {
	dm ch  = {
			false, false, false, true, false,
			false, false, true, true, false,
			false, true, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm2(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			true, false, false, false, false,
			true, true, true, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dm3(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			false, false, false, false, true,
			false, true, true, true, false,
			false, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm4(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, true, false,
			false, false, true, true, false,
			false, true, false, true, false,
			true, false, false, true, false,
			true, true, true, true, true,
			false, false, false, true, false,
			false, false, false, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm5(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			true, false, false, false, false,
			true, false, false, false, false,
			true, true, true, true, false,
			false, false, false, false, true,
			false, false, false, false, true,
			true, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm6(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, false,
			true, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm7(
			const unsigned int ix
		) {
	dm ch = {
			true, true, true, true, true,
			false, false, false, false, true,
			false, false, false, true, false,
			true, true, true, true, true,
			false, false, true, false, false,
			false, true, false, false, false,
			true, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm8(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dm9(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			true, false, false, false, true,
			true, false, false, false, true,
			false, true, true, true, true,
			false, false, false, false, true,
			false, false, false, false, true,
			true, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmDot(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, true, true, false, false,
			false, true, true, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmLbrace(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			false, true, false, false, false,
			false, true, false, false, false,
			false, false, true, false, false,
			false, false, false, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmRbrace(
			const unsigned int ix
		) {
	dm ch = {
			false, true, false, false, false,
			false, false, true, false, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmLsqbra(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			false, true, false, false, false,
			false, true, false, false, false,
			false, true, false, false, false,
			false, true, false, false, false,
			false, true, false, false, false,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmRsqbra(
			const unsigned int ix
		) {
	dm ch = {
			false, true, true, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, false, false, true, false,
			false, true, true, true, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmSmaller(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, true,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			false, false, true, false, false,
			false, false, false, true, false,
			false, false, false, false, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmGreater(
			const unsigned int ix
		) {
	dm ch = {
			true, false, false, false, false,
			false, true, false, false, false,
			false, false, true, false, false,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			true, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmPlus(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			true, true, true, true, true,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmMinus(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			true, true, true, true, true,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmStar(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, false,
			false, true, false, true, false,
			false, false, true, false, false,
			false, true, false, true, false,
			false, false, false, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmSlash(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, true,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			true, false, false, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmPercent(
			const unsigned int ix
		) {
	dm ch = {
			true, true, false, false, false,
			true, true, false, false, true,
			false, false, false, true, false,
			false, false, true, false, false,
			false, true, false, false, false,
			true, false, false, true, true,
			false, false, false, true, true
		};
	return(ch[ix]);
};

bool Dotmatrix::dmComma(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, true, true, false, false,
			false, true, true, false, false,
			false, false, true, false, false,
			false, true, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmEqual(
			const unsigned int ix
		) {
	dm ch = {
			false, false, false, false, false,
			false, false, false, false, false,
			true, true, true, true, true,
			false, false, false, false, false,
			true, true, true, true, true,
			false, false, false, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmVline(
			const unsigned int ix
		) {
	dm ch = {
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false,
			false, false, true, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::dmHat(
			const unsigned int ix
		) {
	dm ch = {
			false, false, true, false, false,
			false, true, false, true, false,
			true, false, false, false, true,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false,
			false, false, false, false, false
		};
	return(ch[ix]);
};

bool Dotmatrix::getDot(
			const char c
			, const unsigned int ix
		) {
	switch (c) {
		case 'A':
			return dmA(ix);
		case 'B':
			return dmB(ix);
		case 'C':
			return dmC(ix);
		case 'D':
			return dmD(ix);
		case 'E':
			return dmE(ix);
		case 'F':
			return dmF(ix);
		case 'G':
			return dmG(ix);
		case 'H':
			return dmH(ix);
		case 'I':
			return dmI(ix);
		case 'J':
			return dmJ(ix);
		case 'K':
			return dmK(ix);
		case 'L':
			return dmL(ix);
		case 'M':
			return dmM(ix);
		case 'N':
			return dmN(ix);
		case 'O':
			return dmO(ix);
		case 'P':
			return dmP(ix);
		case 'Q':
			return dmQ(ix);
		case 'R':
			return dmR(ix);
		case 'S':
			return dmS(ix);
		case 'T':
			return dmT(ix);
		case 'U':
			return dmU(ix);
		case 'V':
			return dmV(ix);
		case 'W':
			return dmW(ix);
		case 'X':
			return dmX(ix);
		case 'Y':
			return dmY(ix);
		case 'Z':
			return dmZ(ix);
		case 'a':
			return dmA(ix);
		case 'b':
			return dmB(ix);
		case 'c':
			return dmC(ix);
		case 'd':
			return dmD(ix);
		case 'e':
			return dmE(ix);
		case 'f':
			return dmF(ix);
		case 'g':
			return dmG(ix);
		case 'h':
			return dmH(ix);
		case 'i':
			return dmI(ix);
		case 'j':
			return dmJ(ix);
		case 'k':
			return dmK(ix);
		case 'l':
			return dmL(ix);
		case 'm':
			return dmM(ix);
		case 'n':
			return dmN(ix);
		case 'o':
			return dmO(ix);
		case 'p':
			return dmP(ix);
		case 'q':
			return dmQ(ix);
		case 'r':
			return dmR(ix);
		case 's':
			return dmS(ix);
		case 't':
			return dmT(ix);
		case 'u':
			return dmU(ix);
		case 'v':
			return dmV(ix);
		case 'w':
			return dmW(ix);
		case 'x':
			return dmX(ix);
		case 'y':
			return dmY(ix);
		case 'z':
			return dmZ(ix);
		case '0':
			return dm0(ix);
		case '1':
			return dm1(ix);
		case '2':
			return dm2(ix);
		case '3':
			return dm3(ix);
		case '4':
			return dm4(ix);
		case '5':
			return dm5(ix);
		case '6':
			return dm6(ix);
		case '7':
			return dm7(ix);
		case '8':
			return dm8(ix);
		case '9':
			return dm9(ix);
		case '.':
			return dmDot(ix);
		case '(':
			return dmLbrace(ix);
		case ')':
			return dmRbrace(ix);
		case '[':
			return dmLsqbra(ix);
		case ']':
			return dmRsqbra(ix);
		case '<':
			return dmSmaller(ix);
		case '>':
			return dmGreater(ix);
		case '+':
			return dmPlus(ix);
		case '-':
			return dmMinus(ix);
		case '*':
			return dmStar(ix);
		case '/':
			return dmSlash(ix);
		case '%':
			return dmPercent(ix);
		case ',':
			return dmComma(ix);
		case '=':
			return dmEqual(ix);
		case '|':
			return dmVline(ix);
		case '^':
			return dmHat(ix);
		default:
			return dmNull(ix);
	};
};

/******************************************************************************
 class Cubrast
 ******************************************************************************/

Cubrast::Cubrast(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const map<string, string>& env
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMFile
			, const string& srefsMatparCat
			, const string& srefsMatparProp
		) {
	string s;

	Mpa mpacache;

	PlnrMFile* fil = NULL;

	int cdfRoot;

	int cdfGrpdoms, cdfDim;

	int* cdfDoms = NULL;
	int cdfDom;

	int numdoms;

	char* domname;

	vector<string> vecMpaCat;
	vector<string> vecMpaProp;
	PlnrAMMaterialPar* mpa = NULL;

	vector<ubigint> refs;
	vector<bool> avl;

	ListPlnrAVKeylistKey klks;
	PlnrAVKeylistKey* klk = NULL;

	// load rasterizer data from cdf file in archive
	dbsplnr->tblplnrmfile->loadRecByRef(refPlnrMFile, &fil);
	s = acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
	delete fil;

	nc_open(s.c_str(), 0, &cdfRoot);

	// load face, edge, layer and material information
	Cdf::getDoubleVec(cdfRoot, "faces", "x0", x0);
	Cdf::getDoubleVec(cdfRoot, "faces", "x1", x1);
	Cdf::getDoubleVec(cdfRoot, "faces", "y0", y0);
	Cdf::getDoubleVec(cdfRoot, "faces", "y1", y1);
	Cdf::getDoubleVec(cdfRoot, "faces", "pdx", pdx);
	Cdf::getDoubleVec(cdfRoot, "faces", "pdy", pdy);
	Cdf::getDoubleVec(cdfRoot, "faces", "z0", z0);
	Cdf::getDoubleVec(cdfRoot, "faces", "z1", z1);
	Cdf::getUintVec(cdfRoot, "faces", "ixEdges0", ixEdges0);
	Cdf::getUintVec(cdfRoot, "faces", "ixEdges1", ixEdges1);
	Cdf::getUintVec(cdfRoot, "faces", "ixLayers0", ixLayers0);
	Cdf::getUintVec(cdfRoot, "faces", "ixLayers1", ixLayers1);
	// cout << "face count: " << x0.size() << endl;

	Cdf::getBoolVec(cdfRoot, "edges", "ag", ag);
	Cdf::getDoubleVec(cdfRoot, "edges", "lx0", lx0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ly0", ly0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ldx", ldx);
	Cdf::getDoubleVec(cdfRoot, "edges", "ldy", ldy);
	Cdf::getBoolVec(cdfRoot, "edges", "accw", accw);
	Cdf::getDoubleVec(cdfRoot, "edges", "ax0", ax0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ay0", ay0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ar", ar);
	Cdf::getDoubleVec(cdfRoot, "edges", "aphi0", aphi0);
	Cdf::getDoubleVec(cdfRoot, "edges", "aphi1", aphi1);
	// cout << "edge count: " << ag.size() << endl;

	Cdf::getDoubleVec(cdfRoot, "layers", "z0", lyrz0);
	Cdf::getDoubleVec(cdfRoot, "layers", "z1", lyrz1);
	Cdf::getUintVec(cdfRoot, "layers", "ixMats", ixMats);
	// cout << "layer count: " << lyrz0.size() << endl;

	Cdf::getUbigintVec(cdfRoot, "", "mats", mats);
	// cout << "material count: " << mats.size() << endl;

	// load domain information
	domname = new char[NC_MAX_NAME+1];

	if (Cdf::getGroup(cdfRoot, "doms", cdfGrpdoms)) {
		nc_inq_grps(cdfGrpdoms, &numdoms, NULL);
		// cout << "domain count: " << numdoms << endl;

		if (numdoms > 0) {
			domics.clear();

			domSref.resize(numdoms);
			domIxVBasetype.resize(numdoms); domDimX.resize(numdoms); domDimY.resize(numdoms); domDimXY.resize(numdoms); domDimZ.resize(numdoms);
			domX0.resize(numdoms); domX1.resize(numdoms); domDx.resize(numdoms);
			domY0.resize(numdoms); domY1.resize(numdoms); domDy.resize(numdoms);
			domXy0.resize(numdoms); domXy1.resize(numdoms); domDxy.resize(numdoms);
			domZ0.resize(numdoms); domZ1.resize(numdoms); domDz.resize(numdoms);
			domA11.resize(numdoms); domA21.resize(numdoms); domB1.resize(numdoms); domB2.resize(numdoms); domB3.resize(numdoms);

			cdfDoms = new int[numdoms];
			nc_inq_grps(cdfGrpdoms, NULL, cdfDoms);

			for (int i=0;i<numdoms;i++) {
				cdfDom = cdfDoms[i];

				nc_inq_grpname(cdfDom, domname);
				domSref[i] = domname;

				Cdf::getDim(cdfDom, "", "dimX", cdfDim, domDimX[i]);
				Cdf::getDim(cdfDom, "", "dimY", cdfDim, domDimY[i]);
				Cdf::getDim(cdfDom, "", "dimXY", cdfDim, domDimXY[i]);
				Cdf::getDim(cdfDom, "", "dimZ", cdfDim, domDimZ[i]);

				Cdf::getUint(cdfDom, "", "ixVBasetype", domIxVBasetype[i]);

				Cdf::getDouble(cdfDom, "", "x0", domX0[i]);
				Cdf::getDouble(cdfDom, "", "x1", domX1[i]);
				Cdf::getDouble(cdfDom, "", "dx", domDx[i]);

				Cdf::getDouble(cdfDom, "", "y0", domY0[i]);
				Cdf::getDouble(cdfDom, "", "y1", domY1[i]);
				Cdf::getDouble(cdfDom, "", "dy", domDy[i]);

				Cdf::getDouble(cdfDom, "", "xy0", domXy0[i]);
				Cdf::getDouble(cdfDom, "", "xy1", domXy1[i]);
				Cdf::getDouble(cdfDom, "", "dxy", domDxy[i]);

				Cdf::getDouble(cdfDom, "", "z0", domZ0[i]);
				Cdf::getDouble(cdfDom, "", "z1", domZ1[i]);
				Cdf::getDouble(cdfDom, "", "dz", domDz[i]);

				Cdf::getDouble(cdfDom, "", "a11", domA11[i]);
				Cdf::getDouble(cdfDom, "", "a21", domA21[i]);
				Cdf::getDouble(cdfDom, "", "b1", domB1[i]);
				Cdf::getDouble(cdfDom, "", "b2", domB2[i]);
				Cdf::getDouble(cdfDom, "", "b3", domB3[i]);

				domics[domSref[i]] = i;
			};

			delete[] cdfDoms;
		};
	};

	delete[] domname;

	nc_close(cdfRoot);

	// for each material, load material parameters
	StrMod::stringToVector(srefsMatparCat, vecMpaCat);
	StrMod::stringToVector(srefsMatparProp, vecMpaProp);

	matparN = vecMpaCat.size();
	matpars.resize(0); matpars.resize(mats.size()*matparN, 0.0);

	srefMatparCats.resize(0); srefMatparCats.resize(matparN);
	srefMatparProps.resize(0); srefMatparProps.resize(matparN);
	titMatparProps.resize(0); titMatparProps.resize(matparN);

	for (unsigned int i=0;i<matparN;i++) {
		srefMatparCats[i] = vecMpaCat[i];
		srefMatparProps[i] = vecMpaProp[i];

		// find enus title for material property
		dbsplnr->tblplnravkeylistkey->loadRstBySQL("SELECT * FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKAMMATERIALPARPROP)
					+ " AND sref = '" + srefMatparProps[i] + "'", false, klks);

		Fct::klkavlMatAparPrp(klks, avl, srefMatparCats[i]);
		for (unsigned int j=0;j<klks.nodes.size();j++) {
			if (avl[j]) {
				klk = klks.nodes[j];
				dbsplnr->tblplnrjavkeylistkey->loadTitByKlkLcl(klk->ref, VecPlnrVLocale::ENUS, titMatparProps[i]);

				break;
			};
		};
		
	};

	// outer loop: materials, inner loop: material parameters
	for (unsigned int i=0;i<mats.size();i++) {
cout << "starting on material #" << mats[i] << endl;
		for (unsigned int j=0;j<vecMpaCat.size();j++) {
cout << "checking for parameter " << vecMpaProp[j] << " ..." << endl;
			if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, vecMpaCat[j], vecMpaProp[j], &mpa)) {
				s = Fct::evalMatAparVal(dbsplnr, env, mpacache, acvpath, mpa, refBasedsn, refModdsn, true);
				if (s.length() > 0) matpars[i*matparN + j] = atof(s.c_str());
cout << "\t... set to " << matpars[i*matparN + j] << ", (original: '" << s << "')" << endl;
				delete mpa;
			};
		};
	};

/// DEBUG
	cout << "material parameters:" << endl;
	for (unsigned int i=0;i<mats.size();i++) {
		for (unsigned int j=0;j<vecMpaCat.size();j++) {
			cout << matpars[i*matparN + j] << " ";
		};
	};
	cout << endl;
///

	ixLastface = 0;
};

Cubrast::~Cubrast() {
};

inline bool Cubrast::isinFace(
			const unsigned int ixFace
			, const double x
			, const double y
			, const double z
			, unsigned int& ixMat
		) {
	bool isin;

	unsigned int xcnt;
	double _pdx, _pdy;
	double _aphi0, _aphi1;
	bool _accw;
	double a, b, c;
	double det, lam, mu, phi;

	// cout << "(" << x << "," << y << "," << z << ") ";

	// z isin raw
	isin = false;
	if ((z >= z0[ixFace]) && (z < z1[ixFace])) isin = true;

	// z isin by layer
	if (isin) {
		isin = false;
		for (unsigned int i=ixLayers0[ixFace];i<ixLayers1[ixFace];i++) {
			if ((z >= lyrz0[i]) && (z < lyrz1[i])) {
				isin = true;
				ixMat = ixMats[i];

				break;
			};
		};
	};

	// xy isin raw
	if (isin) {
		isin = false;
		if ((x >= x0[ixFace]) && (x <= x1[ixFace]) && (y >= y0[ixFace]) && (y <= y1[ixFace])) isin = true;
	};

	// xy isin in detail
	if (isin) {
		xcnt = 0;
		_pdx = pdx[ixFace];
		_pdy = pdy[ixFace];

		if (ixEdges0[ixFace] != ixEdges1[ixFace]) {
			for (unsigned int i=ixEdges0[ixFace];i<ixEdges1[ixFace];i++) {
				if (ag[i]) {
					// check for xsec with arc
					_aphi0 = aphi0[i];
					_aphi1 = aphi1[i];
					_accw = accw[i];
					if (_accw && (_aphi1 < _aphi0)) _aphi1 += 2.0*pi; // ensures _aphi1 > _aphi0
					if (!_accw && (_aphi0 < _aphi1)) _aphi0 += 2.0*pi; // ensures _aphi0 > _aphi1

					a = _pdx + _pdy;
					b = 2.0 * (_pdx*(x-ax0[i]) + _pdy*(y-ay0[i]));
					c = x+y -ax0[i]-ay0[i] -pow(ar[i], 2);

					det = pow(b, 2) - 4.0*a*c;
					if (det > 0) {
						// two intersections with entire circle, check angular position
						lam = (-b + sqrt(det)) / (2.0*a);
						phi = atan2(y+lam*_pdy, x+lam*_pdx);
						if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) {
							xcnt++;
						} else {
							phi += 2.0*pi;
							if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) xcnt++;
						};

						lam = (-b - sqrt(det)) / (2.0*a);
						phi = atan2(y+lam*_pdy, x+lam*_pdx);
						if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) {
							xcnt++;
						} else {
							phi += 2.0*pi;
							if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) xcnt++;
						};
					};

				} else {
					// check for xsec with line
					det = -ldx[i]*_pdy + _pdx*ldy[i];
					if (det != 0.0) {
						lam = (1.0/det) * (-_pdy*(x-lx0[i]) + _pdx*(y-ly0[i]));
						mu = (1.0/det) * (-ldy[i]*(x-lx0[i]) + ldx[i]*(y-ly0[i]));
						if ((lam >= 0.0) && (lam <= 1.0) && (mu >= 0.0)) xcnt++;
					};
				};
			};

			isin = ((xcnt%2) != 0);

		} else {
			// fill face has no edges
			isin = true;
		};
	};

	return isin;
};

unsigned int Cubrast::getIxMat(
			const double x
			, const double y
			, const double z
		) {
	unsigned int ixMat;

	ixMat = 0;
	ixMat--;

	if (!isinFace(ixLastface, x, y, z, ixMat)) {
		for (unsigned int i=0;i<x0.size();i++) {
			if (isinFace(i, x, y, z, ixMat)) {
				if (i != (x0.size()-1)) ixLastface = i;
				break;
			};
		};
	};

	return ixMat;
};

double Cubrast::getMatpar(
			const double x
			, const double y
			, const double z
			, const unsigned int ixMatpar
		) {
	double retval = 0.0;
	unsigned int ixMat;

	if (isinFace(ixLastface, x, y, z, ixMat)) {
		retval = matpars[ixMat*matparN + ixMatpar];

	} else {
		for (unsigned int i=0;i<x0.size();i++) {
			if (isinFace(i, x, y, z, ixMat)) {
				retval = matpars[ixMat*matparN + ixMatpar];
				if (i != (x0.size()-1)) ixLastface = i;

				break;
			};
		};
	};

	return retval;
};

bool Cubrast::getMatparIx(
			const string& srefMatparCat
			, const string& srefMatparProp
			, unsigned int& ixMatpar
		) {
	bool found = false;

	for (unsigned int i=0;i<srefMatparCats.size();i++) {
		if (srefMatparCats[i].compare(srefMatparCat) == 0) {
			if (srefMatparProps[i].compare(srefMatparProp) == 0) {
				ixMatpar = i;
				found = true;

				break;
			};
		};
	};

	return found;
};

bool Cubrast::getDomIx(
			const string& srefDom
			, unsigned int& ixDom
		) {
	bool found = false;

	for (unsigned int i=0;i<domSref.size();i++) {
		if (domSref[i].compare(srefDom) == 0) {
			ixDom = i;
			found = true;

			break;
		};
	};

	return found;
};

string Cubrast::matparCdf(
			const string& tmppath
			, const string& srefsDomain
			, const string& srefMatparCat
			, const string& srefMatparProp
		) {
	string s;

	string outfile;

	vector<string> vecDom;

	unsigned int ixDom;
	unsigned int ixMatpar;

	int cdfRoot, cdfDoms, cdfDom;
	int cdfDimX, cdfDimY, cdfDimXY, cdfDimZ;
	int cdfVar;

	int* dims = NULL;

	double* var = NULL;

	double x, y, z;

	StrMod::stringToVector(srefsDomain, vecDom);
	getMatparIx(srefMatparCat, srefMatparProp, ixMatpar);

	// create and open cdf file
	outfile = Tmp::newfile(tmppath, "cdf");
	s = tmppath + "/" + outfile;

	nc_create(s.c_str(), NC_NETCDF4, &cdfRoot);
	nc_def_grp(cdfRoot, "doms", &cdfDoms);

	// set up cdf file
	nc_enddef(cdfRoot);

	// traverse specified domains
	for (unsigned int i=0;i<vecDom.size();i++) {
		if (getDomIx(vecDom[i], ixDom)) {
			// copy parameters first
			cdfDom = domCdf(ixDom, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimZ);

			// define and assemble variable
			nc_redef(cdfRoot);

			if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::CUB_XYZ) {
				dims = new int[3]; dims[0] = cdfDimX; dims[1] = cdfDimY; dims[2] = cdfDimZ;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 3, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimX[ixDom]*domDimY[ixDom]*domDimZ[ixDom]];

				for (unsigned int k=0;k<domDimX[ixDom];k++) {
					for (unsigned int l=0;l<domDimY[ixDom];l++) {
						for (unsigned int m=0;m<domDimZ[ixDom];m++) {
							x = domA11[ixDom]*(domX0[ixDom]+k*domDx[ixDom])-domA21[ixDom]*(domY0[ixDom]+l*domDy[ixDom])+domB1[ixDom];
							y = domA21[ixDom]*(domX0[ixDom]+k*domDx[ixDom])+domA11[ixDom]*(domY0[ixDom]+l*domDy[ixDom])+domB2[ixDom];
							z = domZ0[ixDom]+m*domDz[ixDom]+domB3[ixDom];
							var[k*domDimY[ixDom]*domDimZ[ixDom]+l*domDimZ[ixDom]+m] = getMatpar(x, y, z, ixMatpar);
						};
					};
				};

				s = srefMatparProp + "(x,y,z)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
				dims = new int[2]; dims[0] = cdfDimXY; dims[1] = cdfDimZ;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 2, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimXY[ixDom]*domDimZ[ixDom]];

				for (unsigned int k=0;k<domDimXY[ixDom];k++) {
					for (unsigned int l=0;l<domDimZ[ixDom];l++) {
						x = domA11[ixDom]*(domXy0[ixDom]+k*domDxy[ixDom])+domB1[ixDom];
						y = domA21[ixDom]*(domXy0[ixDom]+k*domDxy[ixDom])+domB2[ixDom];
						z = domZ0[ixDom]+l*domDz[ixDom]+domB3[ixDom];
						var[k*domDimZ[ixDom]+l] = getMatpar(x, y, z, ixMatpar);
					};
				};

				s = srefMatparProp + "(xy,z)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYBOX_XYZ) {
				dims = new int[2]; dims[0] = cdfDimX; dims[1] = cdfDimY;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 2, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimX[ixDom]*domDimY[ixDom]];

				z = domB3[ixDom];
				for (unsigned int k=0;k<domDimX[ixDom];k++) {
					for (unsigned int l=0;l<domDimY[ixDom];l++) {
						x = domA11[ixDom]*(domX0[ixDom]+k*domDx[ixDom])-domA21[ixDom]*(domY0[ixDom]+l*domDy[ixDom])+domB1[ixDom];
						y = domA21[ixDom]*(domX0[ixDom]+k*domDx[ixDom])+domA11[ixDom]*(domY0[ixDom]+l*domDy[ixDom])+domB2[ixDom];
						var[k*domDimY[ixDom]+l] = getMatpar(x, y, z, ixMatpar);
					};
				};

				s = srefMatparProp + "(x,y)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
				dims = new int[1]; dims[0] = cdfDimXY;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimXY[ixDom]];

				z = domB3[ixDom];
				for (unsigned int k=0;k<domDimXY[ixDom];k++) {
					x = domA11[ixDom]*(domXy0[ixDom]+k*domDxy[ixDom])+domB1[ixDom];
					y = domA21[ixDom]*(domXy0[ixDom]+k*domDxy[ixDom])+domB2[ixDom];
					var[k] = getMatpar(x, y, z, ixMatpar);
				};

				s = srefMatparProp + "(xy)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
				dims = new int[1]; dims[0] = cdfDimZ;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimZ[ixDom]];

				x = domB1[ixDom];
				y = domB2[ixDom];
				for (unsigned int k=0;k<domDimZ[ixDom];k++) {
					z = domZ0[ixDom]+k*domDz[ixDom]+domB3[ixDom];
					var[k] = getMatpar(x, y, z, ixMatpar);
				};

				s = srefMatparProp + "(z)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::POINT_XYZ) {
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 0, NULL, &cdfVar);

				var = new double[1];

				var[0] = getMatpar(domB1[ixDom], domB2[ixDom], domB3[ixDom], ixMatpar);

				s = srefMatparProp;
			};

			if (var) {
				nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());
				nc_put_att_text(cdfDom, cdfVar, "title", titMatparProps[ixMatpar].length(), titMatparProps[ixMatpar].c_str());
			};

			nc_enddef(cdfRoot);

			// write variable
			if (var) {
				nc_put_var_double(cdfDom, cdfVar, var);

				delete[] var;
				var = NULL;
			};
		};
	};

	nc_close(cdfRoot);

	return outfile;
};

int Cubrast::domCdf(
			const unsigned int ixDom
			, const int cdfRoot
			, int& cdfDimX
			, int& cdfDimY
			, int& cdfDimXY
			, int& cdfDimZ
		) {
	bool hasx, hasxy, hasz;

	int cdfDom;
	int cdf_ixVBasetype;
	int cdf_x0;
	int cdf_x1;
	int cdf_dx;
	int cdf_y0;
	int cdf_y1;
	int cdf_dy;
	int cdf_xy0;
	int cdf_xy1;
	int cdf_dxy;
	int cdf_z0;
	int cdf_z1;
	int cdf_dz;
	int cdf_a11;
	int cdf_a21;
	int cdf_b1;
	int cdf_b2;
	int cdf_b3;

	hasx = ((domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::CUB_XYZ) || (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYBOX_XYZ));
	hasxy = ((domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) || (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYLINE_XYZ));
	hasz = ((domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::CUB_XYZ) || (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) || (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZLINE_XYZ));

	nc_redef(cdfRoot);
		nc_def_grp(cdfRoot, domSref[ixDom].c_str(), &cdfDom);
			if (hasx) {
				nc_def_dim(cdfDom, "dimX", domDimX[ixDom], &cdfDimX);
				nc_def_dim(cdfDom, "dimY", domDimY[ixDom], &cdfDimY);
			};
			if (hasxy) nc_def_dim(cdfDom, "dimXY", domDimXY[ixDom], &cdfDimXY);
			if (hasz) nc_def_dim(cdfDom, "dimZ", domDimZ[ixDom], &cdfDimZ);
			nc_def_var(cdfDom, "ixVBasetype", NC_UINT, 0, NULL, &cdf_ixVBasetype);
			if (hasx) {
				nc_def_var(cdfDom, "x0", NC_DOUBLE, 0, NULL, &cdf_x0);
				nc_def_var(cdfDom, "x1", NC_DOUBLE, 0, NULL, &cdf_x1);
				nc_def_var(cdfDom, "dx", NC_DOUBLE, 0, NULL, &cdf_dx);
				nc_def_var(cdfDom, "y0", NC_DOUBLE, 0, NULL, &cdf_y0);
				nc_def_var(cdfDom, "y1", NC_DOUBLE, 0, NULL, &cdf_y1);
				nc_def_var(cdfDom, "dy", NC_DOUBLE, 0, NULL, &cdf_dy);
			};
			if (hasxy) {
				nc_def_var(cdfDom, "xy0", NC_DOUBLE, 0, NULL, &cdf_xy0);
				nc_def_var(cdfDom, "xy1", NC_DOUBLE, 0, NULL, &cdf_xy1);
				nc_def_var(cdfDom, "dxy", NC_DOUBLE, 0, NULL, &cdf_dxy);
			};
			if (hasz) {
				nc_def_var(cdfDom, "z0", NC_DOUBLE, 0, NULL, &cdf_z0);
				nc_def_var(cdfDom, "z1", NC_DOUBLE, 0, NULL, &cdf_z1);
				nc_def_var(cdfDom, "dz", NC_DOUBLE, 0, NULL, &cdf_dz);
			};
			if (hasx || hasxy) {
				nc_def_var(cdfDom, "a11", NC_DOUBLE, 0, NULL, &cdf_a11);
				nc_def_var(cdfDom, "a21", NC_DOUBLE, 0, NULL, &cdf_a21);
			};
			nc_def_var(cdfDom, "b1", NC_DOUBLE, 0, NULL, &cdf_b1);
			nc_def_var(cdfDom, "b2", NC_DOUBLE, 0, NULL, &cdf_b2);
			nc_def_var(cdfDom, "b3", NC_DOUBLE, 0, NULL, &cdf_b3);
	nc_enddef(cdfRoot);
	if (hasx) {
		nc_put_var_double(cdfDom, cdf_x0, &(domX0[ixDom]));
		nc_put_var_double(cdfDom, cdf_x1, &(domX1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dx, &(domDx[ixDom]));
		nc_put_var_double(cdfDom, cdf_y0, &(domY0[ixDom]));
		nc_put_var_double(cdfDom, cdf_y1, &(domY1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dy, &(domDy[ixDom]));
	};
	if (hasxy) {
		nc_put_var_double(cdfDom, cdf_xy0, &(domXy0[ixDom]));
		nc_put_var_double(cdfDom, cdf_xy1, &(domXy1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dxy, &(domDxy[ixDom]));
	};
	if (hasz) {
		nc_put_var_double(cdfDom, cdf_z0, &(domZ0[ixDom]));
		nc_put_var_double(cdfDom, cdf_z1, &(domZ1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dz, &(domDz[ixDom]));
	};
	nc_put_var_double(cdfDom, cdf_a11, &(domA11[ixDom]));
	nc_put_var_double(cdfDom, cdf_a21, &(domA21[ixDom]));
	nc_put_var_double(cdfDom, cdf_b1, &(domB1[ixDom]));
	nc_put_var_double(cdfDom, cdf_b2, &(domB2[ixDom]));
	nc_put_var_double(cdfDom, cdf_b3, &(domB3[ixDom]));
	nc_put_var_uint(cdfDom, cdf_ixVBasetype, &(domIxVBasetype[ixDom])); // doesn't work if put in first place for POINT_XYZ

	return cdfDom;
};

/******************************************************************************
 class Xyboxrast
 ******************************************************************************/

Xyboxrast::Xyboxrast(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const map<string, string>& env
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMFile
			, const string& srefsMatparCat
			, const string& srefsMatparProp
		) {
	string s;

	Mpa mpacache;

	PlnrMFile* fil = NULL;

	int cdfRoot;

	int cdfGrpdoms, cdfDim;

	int* cdfDoms = NULL;
	int cdfDom;

	int numdoms;

	char* domname;

	vector<string> vecMpaCat;
	vector<string> vecMpaProp;
	PlnrAMMaterialPar* mpa = NULL;

	vector<ubigint> refs;
	vector<bool> avl;

	ListPlnrAVKeylistKey klks;
	PlnrAVKeylistKey* klk = NULL;

	// load rasterizer data from cdf file in archive
	dbsplnr->tblplnrmfile->loadRecByRef(refPlnrMFile, &fil);
	s = acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
	delete fil;

	nc_open(s.c_str(), 0, &cdfRoot);

	// load face, edge and material information
	Cdf::getDoubleVec(cdfRoot, "faces", "x0", x0);
	Cdf::getDoubleVec(cdfRoot, "faces", "x1", x1);
	Cdf::getDoubleVec(cdfRoot, "faces", "y0", y0);
	Cdf::getDoubleVec(cdfRoot, "faces", "y1", y1);
	Cdf::getDoubleVec(cdfRoot, "faces", "pdx", pdx);
	Cdf::getDoubleVec(cdfRoot, "faces", "pdy", pdy);
	Cdf::getUintVec(cdfRoot, "faces", "ixEdges0", ixEdges0);
	Cdf::getUintVec(cdfRoot, "faces", "ixEdges1", ixEdges1);
	Cdf::getUintVec(cdfRoot, "faces", "ixMats", ixMats);
	//cout << "face count: " << x0.size() << endl;

	Cdf::getBoolVec(cdfRoot, "edges", "ag", ag);
	Cdf::getDoubleVec(cdfRoot, "edges", "lx0", lx0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ly0", ly0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ldx", ldx);
	Cdf::getDoubleVec(cdfRoot, "edges", "ldy", ldy);
	Cdf::getBoolVec(cdfRoot, "edges", "accw", accw);
	Cdf::getDoubleVec(cdfRoot, "edges", "ax0", ax0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ay0", ay0);
	Cdf::getDoubleVec(cdfRoot, "edges", "ar", ar);
	Cdf::getDoubleVec(cdfRoot, "edges", "aphi0", aphi0);
	Cdf::getDoubleVec(cdfRoot, "edges", "aphi1", aphi1);
	//cout << "edge count: " << ag.size() << endl;

	Cdf::getUbigintVec(cdfRoot, "", "mats", mats);
	//cout << "material count: " << mats.size() << endl;

	// load domain information
	domname = new char[NC_MAX_NAME+1];

	if (Cdf::getGroup(cdfRoot, "doms", cdfGrpdoms)) {
		nc_inq_grps(cdfGrpdoms, &numdoms, NULL);
		// cout << "domain count: " << numdoms << endl;

		if (numdoms > 0) {
			domics.clear();

			domSref.resize(numdoms);
			domIxVBasetype.resize(numdoms); domDimX.resize(numdoms); domDimY.resize(numdoms); domDimXY.resize(numdoms);
			domX0.resize(numdoms); domX1.resize(numdoms); domDx.resize(numdoms);
			domY0.resize(numdoms); domY1.resize(numdoms); domDy.resize(numdoms);
			domXy0.resize(numdoms); domXy1.resize(numdoms); domDxy.resize(numdoms);
			domA11.resize(numdoms); domA21.resize(numdoms); domB1.resize(numdoms); domB2.resize(numdoms);

			cdfDoms = new int[numdoms];
			nc_inq_grps(cdfGrpdoms, NULL, cdfDoms);

			for (int i=0;i<numdoms;i++) {
				cdfDom = cdfDoms[i];

				nc_inq_grpname(cdfDom, domname);
				domSref[i] = domname;

				Cdf::getDim(cdfDom, "", "dimX", cdfDim, domDimX[i]);
				Cdf::getDim(cdfDom, "", "dimY", cdfDim, domDimY[i]);
				Cdf::getDim(cdfDom, "", "dimXY", cdfDim, domDimXY[i]);

				Cdf::getUint(cdfDom, "", "ixVBasetype", domIxVBasetype[i]);

				Cdf::getDouble(cdfDom, "", "x0", domX0[i]);
				Cdf::getDouble(cdfDom, "", "x1", domX1[i]);
				Cdf::getDouble(cdfDom, "", "dx", domDx[i]);

				Cdf::getDouble(cdfDom, "", "y0", domY0[i]);
				Cdf::getDouble(cdfDom, "", "y1", domY1[i]);
				Cdf::getDouble(cdfDom, "", "dy", domDy[i]);

				Cdf::getDouble(cdfDom, "", "xy0", domXy0[i]);
				Cdf::getDouble(cdfDom, "", "xy1", domXy1[i]);
				Cdf::getDouble(cdfDom, "", "dxy", domDxy[i]);

				Cdf::getDouble(cdfDom, "", "a11", domA11[i]);
				Cdf::getDouble(cdfDom, "", "a21", domA21[i]);
				Cdf::getDouble(cdfDom, "", "b1", domB1[i]);
				Cdf::getDouble(cdfDom, "", "b2", domB2[i]);

				domics[domSref[i]] = i;
			};

			delete[] cdfDoms;
		};
	};

	delete[] domname;

	nc_close(cdfRoot);

	// for each material, load material parameters
	StrMod::stringToVector(srefsMatparCat, vecMpaCat);
	StrMod::stringToVector(srefsMatparProp, vecMpaProp);

	matparN = vecMpaCat.size();
	matpars.resize(0); matpars.resize(mats.size()*matparN, 0.0);

	srefMatparCats.resize(0); srefMatparCats.resize(matparN);
	srefMatparProps.resize(0); srefMatparProps.resize(matparN);
	titMatparProps.resize(0); titMatparProps.resize(matparN);

	for (unsigned int i=0;i<matparN;i++) {
		srefMatparCats[i] = vecMpaCat[i];
		srefMatparProps[i] = vecMpaProp[i];

		// find enus title for material property
		dbsplnr->tblplnravkeylistkey->loadRstBySQL("SELECT * FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKAMMATERIALPARPROP)
					+ " AND sref = '" + srefMatparProps[i] + "'", false, klks);

		Fct::klkavlMatAparPrp(klks, avl, srefMatparCats[i]);
		for (unsigned int j=0;j<klks.nodes.size();j++) {
			if (avl[j]) {
				klk = klks.nodes[j];
				dbsplnr->tblplnrjavkeylistkey->loadTitByKlkLcl(klk->ref, VecPlnrVLocale::ENUS, titMatparProps[i]);

				break;
			};
		};
		
	};

	// outer loop: materials, inner loop: material parameters
	for (unsigned int i=0;i<mats.size();i++) {
		for (unsigned int j=0;j<vecMpaCat.size();j++) {
			if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, vecMpaCat[j], vecMpaProp[j], &mpa)) {
				s = Fct::evalMatAparVal(dbsplnr, env, mpacache, acvpath, mpa, refBasedsn, refModdsn, true);
				if (s.length() > 0) matpars[i*matparN + j] = atof(s.c_str());

				delete mpa;
			};
		};
	};

	ixLastface = 0;
};

Xyboxrast::~Xyboxrast() {
};

inline bool Xyboxrast::isinFace(
			const unsigned int ixFace
			, const double x
			, const double y
			, unsigned int& ixMat
		) {
	bool isin;

	unsigned int xcnt;
	double _pdx, _pdy;
	double _aphi0, _aphi1;
	bool _accw;
	double a, b, c;
	double det, lam, mu, phi;

	// cout << "(" << x << "," << y << ") ";

	// xy isin raw
	isin = false;
	if ((x >= x0[ixFace]) && (x <= x1[ixFace]) && (y >= y0[ixFace]) && (y <= y1[ixFace])) isin = true;

	// xy isin in detail
	if (isin) {
		xcnt = 0;
		_pdx = pdx[ixFace];
		_pdy = pdy[ixFace];

		if (ixEdges0[ixFace] != ixEdges1[ixFace]) {
			for (unsigned int i=ixEdges0[ixFace];i<ixEdges1[ixFace];i++) {
				if (ag[i]) {
					// check for xsec with arc
					_aphi0 = aphi0[i];
					_aphi1 = aphi1[i];
					_accw = accw[i];
					if (_accw && (_aphi1 < _aphi0)) _aphi1 += 2.0*pi; // ensures _aphi1 > _aphi0
					if (!_accw && (_aphi0 < _aphi1)) _aphi0 += 2.0*pi; // ensures _aphi0 > _aphi1

					a = _pdx + _pdy;
					b = 2.0 * (_pdx*(x-ax0[i]) + _pdy*(y-ay0[i]));
					c = x+y -ax0[i]-ay0[i] -pow(ar[i], 2);

					det = pow(b, 2) - 4.0*a*c;
					if (det > 0) {
						// two intersections with entire circle, check angular position
						lam = (-b + sqrt(det)) / (2.0*a);
						phi = atan2(y+lam*_pdy, x+lam*_pdx);
						if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) {
							xcnt++;
						} else {
							phi += 2.0*pi;
							if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) xcnt++;
						};

						lam = (-b - sqrt(det)) / (2.0*a);
						phi = atan2(y+lam*_pdy, x+lam*_pdx);
						if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) {
							xcnt++;
						} else {
							phi += 2.0*pi;
							if ( ((_aphi1 > _aphi0) && (phi > _aphi0) && (phi < _aphi1)) || ((_aphi1 < _aphi0) && (phi < _aphi0) && (phi > _aphi1)) ) xcnt++;
						};
					};

				} else {
					// check for xsec with line
					det = -ldx[i]*_pdy + _pdx*ldy[i];
					if (det != 0.0) {
						lam = (1.0/det) * (-_pdy*(x-lx0[i]) + _pdx*(y-ly0[i]));
						mu = (1.0/det) * (-ldy[i]*(x-lx0[i]) + ldx[i]*(y-ly0[i]));
						if ((lam >= 0.0) && (lam <= 1.0) && (mu >= 0.0)) xcnt++;
					};
				};
			};

			isin = ((xcnt%2) != 0);

		} else {
			// fill face has no edges
			isin = true;
		};
	};

	if (isin) ixMat = ixMats[ixFace];

	return isin;
};

unsigned int Xyboxrast::getIxMat(
			const double x
			, const double y
		) {
	unsigned int ixMat;

	ixMat = 0;
	ixMat--;

	if (!isinFace(ixLastface, x, y, ixMat)) {
		for (unsigned int i=0;i<x0.size();i++) {
			if (isinFace(i, x, y, ixMat)) {
				if (i != (x0.size()-1)) ixLastface = i;
				break;
			};
		};
	};

	return ixMat;
};

double Xyboxrast::getMatpar(
			const double x
			, const double y
			, const unsigned int ixMatpar
		) {
	double retval = 0.0;
	unsigned int ixMat;

	if (isinFace(ixLastface, x, y, ixMat)) {
		retval = matpars[ixMat*matparN + ixMatpar];

	} else {
		for (unsigned int i=0;i<x0.size();i++) {
			if (isinFace(i, x, y, ixMat)) {
				retval = matpars[ixMat*matparN + ixMatpar];
				if (i != (x0.size()-1)) ixLastface = i;

				break;
			};
		};
	};

	return retval;
};

bool Xyboxrast::getMatparIx(
			const string& srefMatparCat
			, const string& srefMatparProp
			, unsigned int& ixMatpar
		) {
	bool found = false;

	for (unsigned int i=0;i<srefMatparCats.size();i++) {
		if (srefMatparCats[i].compare(srefMatparCat) == 0) {
			if (srefMatparProps[i].compare(srefMatparProp) == 0) {
				ixMatpar = i;
				found = true;

				break;
			};
		};
	};

	return found;
};

bool Xyboxrast::getDomIx(
			const string& srefDom
			, unsigned int& ixDom
		) {
	bool found = false;

	for (unsigned int i=0;i<domSref.size();i++) {
		if (domSref[i].compare(srefDom) == 0) {
			ixDom = i;
			found = true;

			break;
		};
	};

	return found;
};

string Xyboxrast::matparCdf(
			const string& tmppath
			, const string& srefsDomain
			, const string& srefMatparCat
			, const string& srefMatparProp
		) {
	string s;

	string outfile;

	vector<string> vecDom;
	unsigned int ixDom;

	unsigned int ixMatpar;

	int cdfRoot, cdfDoms, cdfDom;
	int cdfDimX, cdfDimY, cdfDimXY;
	int cdfVar;

	int* dims = NULL;

	double* var = NULL;

	double x, y;

	StrMod::stringToVector(srefsDomain, vecDom);
	getMatparIx(srefMatparCat, srefMatparProp, ixMatpar);

	// create and open cdf file
	outfile = Tmp::newfile(tmppath, "cdf");
	s = tmppath + "/" + outfile;

	nc_create(s.c_str(), NC_NETCDF4, &cdfRoot);
	nc_def_grp(cdfRoot, "doms", &cdfDoms);

	// set up cdf file
	nc_enddef(cdfRoot);

	// traverse specified domains
	for (unsigned int i=0;i<vecDom.size();i++) {
		if (getDomIx(vecDom[i], ixDom)) {
			// copy parameters first
			cdfDom = domCdf(ixDom, cdfDoms, cdfDimX, cdfDimY, cdfDimXY);

			// define and assemble variable
			nc_redef(cdfRoot);

			if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYBOX_XY) {
				dims = new int[2]; dims[0] = cdfDimX; dims[1] = cdfDimY;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 2, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimX[ixDom]*domDimY[ixDom]];

				for (unsigned int k=0;k<domDimX[ixDom];k++) {
					for (unsigned int l=0;l<domDimY[ixDom];l++) {
						x = domA11[ixDom]*(domX0[ixDom]+k*domDx[ixDom])-domA21[ixDom]*(domY0[ixDom]+l*domDy[ixDom])+domB1[ixDom];
						y = domA21[ixDom]*(domX0[ixDom]+k*domDx[ixDom])+domA11[ixDom]*(domY0[ixDom]+l*domDy[ixDom])+domB2[ixDom];
						var[k*domDimY[ixDom]+l] = getMatpar(x, y, ixMatpar);
					};
				};

				s = srefMatparProp + "(x,y)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYLINE_XY) {
				dims = new int[1]; dims[0] = cdfDimXY;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimXY[ixDom]];

				for (unsigned int k=0;k<domDimXY[ixDom];k++) {
					x = domA11[ixDom]*(domXy0[ixDom]+k*domDxy[ixDom])+domB1[ixDom];
					y = domA21[ixDom]*(domXy0[ixDom]+k*domDxy[ixDom])+domB2[ixDom];
					var[k] = getMatpar(x, y, ixMatpar);
				};

				s = srefMatparProp + "(xy)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::POINT_XY) {
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 0, NULL, &cdfVar);

				var = new double[1];

				var[0] = getMatpar(domB1[ixDom], domB2[ixDom], ixMatpar);

				s = srefMatparProp;
			};

			if (var) {
				nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());
				nc_put_att_text(cdfDom, cdfVar, "title", titMatparProps[ixMatpar].length(), titMatparProps[ixMatpar].c_str());
			};

			nc_enddef(cdfRoot);

			// write variable
			if (var) {
				nc_put_var_double(cdfDom, cdfVar, var);

				delete[] var;
				var = NULL;
			};
		};
	};

	nc_close(cdfRoot);

	return outfile;
};

int Xyboxrast::domCdf(
			const unsigned int ixDom
			, const int cdfRoot
			, int& cdfDimX
			, int& cdfDimY
			, int& cdfDimXY
		) {
	bool hasx, hasxy;

	int cdfDom;
	int cdf_ixVBasetype;
	int cdf_x0;
	int cdf_x1;
	int cdf_dx;
	int cdf_y0;
	int cdf_y1;
	int cdf_dy;
	int cdf_xy0;
	int cdf_xy1;
	int cdf_dxy;
	int cdf_a11;
	int cdf_a21;
	int cdf_b1;
	int cdf_b2;

	hasx = (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYBOX_XY);
	hasxy = (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::XYLINE_XY);

	nc_redef(cdfRoot);
		nc_def_grp(cdfRoot, domSref[ixDom].c_str(), &cdfDom);
			if (hasx) {
				nc_def_dim(cdfDom, "dimX", domDimX[ixDom], &cdfDimX);
				nc_def_dim(cdfDom, "dimY", domDimY[ixDom], &cdfDimY);
			};
			if (hasxy) nc_def_dim(cdfDom, "dimXY", domDimXY[ixDom], &cdfDimXY);
			nc_def_var(cdfDom, "ixVBasetype", NC_UINT, 0, NULL, &cdf_ixVBasetype);
			if (hasx) {
				nc_def_var(cdfDom, "x0", NC_DOUBLE, 0, NULL, &cdf_x0);
				nc_def_var(cdfDom, "x1", NC_DOUBLE, 0, NULL, &cdf_x1);
				nc_def_var(cdfDom, "dx", NC_DOUBLE, 0, NULL, &cdf_dx);
				nc_def_var(cdfDom, "y0", NC_DOUBLE, 0, NULL, &cdf_y0);
				nc_def_var(cdfDom, "y1", NC_DOUBLE, 0, NULL, &cdf_y1);
				nc_def_var(cdfDom, "dy", NC_DOUBLE, 0, NULL, &cdf_dy);
			};
			if (hasxy) {
				nc_def_var(cdfDom, "xy0", NC_DOUBLE, 0, NULL, &cdf_xy0);
				nc_def_var(cdfDom, "xy1", NC_DOUBLE, 0, NULL, &cdf_xy1);
				nc_def_var(cdfDom, "dxy", NC_DOUBLE, 0, NULL, &cdf_dxy);
			};
			if (hasx || hasxy) {
				nc_def_var(cdfDom, "a11", NC_DOUBLE, 0, NULL, &cdf_a11);
				nc_def_var(cdfDom, "a21", NC_DOUBLE, 0, NULL, &cdf_a21);
			};
			nc_def_var(cdfDom, "b1", NC_DOUBLE, 0, NULL, &cdf_b1);
			nc_def_var(cdfDom, "b2", NC_DOUBLE, 0, NULL, &cdf_b2);
	nc_enddef(cdfRoot);
	if (hasx) {
		nc_put_var_double(cdfDom, cdf_x0, &(domX0[ixDom]));
		nc_put_var_double(cdfDom, cdf_x1, &(domX1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dx, &(domDx[ixDom]));
		nc_put_var_double(cdfDom, cdf_y0, &(domY0[ixDom]));
		nc_put_var_double(cdfDom, cdf_y1, &(domY1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dy, &(domDy[ixDom]));
	};
	if (hasxy) {
		nc_put_var_double(cdfDom, cdf_xy0, &(domXy0[ixDom]));
		nc_put_var_double(cdfDom, cdf_xy1, &(domXy1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dxy, &(domDxy[ixDom]));
	};
	nc_put_var_double(cdfDom, cdf_a11, &(domA11[ixDom]));
	nc_put_var_double(cdfDom, cdf_a21, &(domA21[ixDom]));
	nc_put_var_double(cdfDom, cdf_b1, &(domB1[ixDom]));
	nc_put_var_double(cdfDom, cdf_b2, &(domB2[ixDom]));
	nc_put_var_uint(cdfDom, cdf_ixVBasetype, &(domIxVBasetype[ixDom]));

	return cdfDom;
};

/******************************************************************************
 class Zlinerast
 ******************************************************************************/

Zlinerast::Zlinerast(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const map<string, string>& env
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const ubigint refPlnrMFile
			, const string& srefsMatparCat
			, const string& srefsMatparProp
		) {
	string s;

	Mpa mpacache;

	PlnrMFile* fil = NULL;

	int cdfRoot;

	int cdfGrpdoms, cdfDim;

	int* cdfDoms = NULL;
	int cdfDom;

	int numdoms;

	char* domname;

	vector<string> vecMpaCat;
	vector<string> vecMpaProp;
	PlnrAMMaterialPar* mpa = NULL;

	vector<ubigint> refs;
	vector<bool> avl;

	ListPlnrAVKeylistKey klks;
	PlnrAVKeylistKey* klk = NULL;

	// load rasterizer data from cdf file in archive
	dbsplnr->tblplnrmfile->loadRecByRef(refPlnrMFile, &fil);
	s = acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
	delete fil;

	nc_open(s.c_str(), 0, &cdfRoot);

	// load layer and material information
	Cdf::getDoubleVec(cdfRoot, "layers", "z0", lyrz0);
	Cdf::getDoubleVec(cdfRoot, "layers", "z1", lyrz1);
	Cdf::getUintVec(cdfRoot, "layers", "ixMats", ixMats);
	// cout << "layer count: " << lyrz0.size() << endl;

	Cdf::getUbigintVec(cdfRoot, "", "mats", mats);
	// cout << "material count: " << mats.size() << endl;

	// load domain information
	domname = new char[NC_MAX_NAME+1];

	if (Cdf::getGroup(cdfRoot, "doms", cdfGrpdoms)) {
		nc_inq_grps(cdfGrpdoms, &numdoms, NULL);

		if (numdoms > 0) {
			domics.clear();

			domSref.resize(numdoms);
			domIxVBasetype.resize(numdoms); domDimZ.resize(numdoms);
			domZ0.resize(numdoms); domZ1.resize(numdoms); domDz.resize(numdoms);
			domB3.resize(numdoms);

			cdfDoms = new int[numdoms];
			nc_inq_grps(cdfGrpdoms, NULL, cdfDoms);

			for (int i=0;i<numdoms;i++) {
				cdfDom = cdfDoms[i];

				nc_inq_grpname(cdfDom, domname);
				domSref[i] = domname;

				Cdf::getDim(cdfDom, "", "dimZ", cdfDim, domDimZ[i]);

				Cdf::getUint(cdfDom, "", "ixVBasetype", domIxVBasetype[i]);

				Cdf::getDouble(cdfDom, "", "z0", domZ0[i]);
				Cdf::getDouble(cdfDom, "", "z1", domZ1[i]);
				Cdf::getDouble(cdfDom, "", "dz", domDz[i]);
				Cdf::getDouble(cdfDom, "", "b3", domB3[i]);

				domics[domSref[i]] = i;
			};

			delete[] cdfDoms;
		};
	};

	delete[] domname;

	nc_close(cdfRoot);

	// for each material, load material parameters
	StrMod::stringToVector(srefsMatparCat, vecMpaCat);
	StrMod::stringToVector(srefsMatparProp, vecMpaProp);

	matparN = vecMpaCat.size();
	matpars.resize(0); matpars.resize(mats.size()*matparN, 0.0);

	srefMatparCats.resize(0); srefMatparCats.resize(matparN);
	srefMatparProps.resize(0); srefMatparProps.resize(matparN);
	titMatparProps.resize(0); titMatparProps.resize(matparN);

	for (unsigned int i=0;i<matparN;i++) {
		srefMatparCats[i] = vecMpaCat[i];
		srefMatparProps[i] = vecMpaProp[i];

		// find enus title for material property
		dbsplnr->tblplnravkeylistkey->loadRstBySQL("SELECT * FROM TblPlnrAVKeylistKey WHERE klsIxPlnrVKeylist = " + to_string(VecPlnrVKeylist::KLSTPLNRKAMMATERIALPARPROP)
					+ " AND sref = '" + srefMatparProps[i] + "'", false, klks);

		Fct::klkavlMatAparPrp(klks, avl, srefMatparCats[i]);
		for (unsigned int j=0;j<klks.nodes.size();j++) {
			if (avl[j]) {
				klk = klks.nodes[j];
				dbsplnr->tblplnrjavkeylistkey->loadTitByKlkLcl(klk->ref, VecPlnrVLocale::ENUS, titMatparProps[i]);

				break;
			};
		};
		
	};

	// outer loop: materials, inner loop: material parameters
	for (unsigned int i=0;i<mats.size();i++) {
		for (unsigned int j=0;j<vecMpaCat.size();j++) {
			if (Plnr::findMpa(dbsplnr, mats[i], refBasedsn, refModdsn, vecMpaCat[j], vecMpaProp[j], &mpa)) {
				s = Fct::evalMatAparVal(dbsplnr, env, mpacache, acvpath, mpa, refBasedsn, refModdsn, true);
				if (s.length() > 0) matpars[i*matparN + j] = atof(s.c_str());

				delete mpa;
			};
		};
	};

	ixLastlayer = 0;
};

Zlinerast::~Zlinerast() {
};

inline bool Zlinerast::isinLayer(
			const unsigned int ixLayer
			, const double z
			, unsigned int& ixMat
		) {
	bool isin;

	// cout << z << " ";

	// z isin by layer
	isin = false;
	if ((z >= lyrz0[ixLayer]) && (z < lyrz1[ixLayer])) {
		isin = true;
		ixMat = ixMats[ixLayer];
	};

	return isin;
};

unsigned int Zlinerast::getIxMat(
			const double z
		) {
	unsigned int ixMat;

	ixMat = 0;
	ixMat--;

	if (!isinLayer(ixLastlayer, z, ixMat)) {
		for (unsigned int i=0;i<lyrz0.size();i++) {
			if (isinLayer(i, z, ixMat)) {
				if (i != (lyrz0.size()-1)) ixLastlayer = i;
				break;
			};
		};
	};

	return ixMat;
};

double Zlinerast::getMatpar(
			const double z
			, const unsigned int ixMatpar
		) {
	double retval = 0.0;
	unsigned int ixMat;

	if (isinLayer(ixLastlayer, z, ixMat)) {
		retval = matpars[ixMat*matparN + ixMatpar];

	} else {
		for (unsigned int i=0;i<lyrz0.size();i++) {
			if (isinLayer(i, z, ixMat)) {
				retval = matpars[ixMat*matparN + ixMatpar];
				ixLastlayer = i;

				break;
			};
		};
	};

	return retval;
};

bool Zlinerast::getMatparIx(
			const string& srefMatparCat
			, const string& srefMatparProp
			, unsigned int& ixMatpar
		) {
	bool found = false;

	for (unsigned int i=0;i<srefMatparCats.size();i++) {
		if (srefMatparCats[i].compare(srefMatparCat) == 0) {
			if (srefMatparProps[i].compare(srefMatparProp) == 0) {
				ixMatpar = i;
				found = true;

				break;
			};
		};
	};

	return found;
};

bool Zlinerast::getDomIx(
			const string& srefDom
			, unsigned int& ixDom
		) {
	bool found = false;

	for (unsigned int i=0;i<domSref.size();i++) {
		if (domSref[i].compare(srefDom) == 0) {
			ixDom = i;
			found = true;

			break;
		};
	};

	return found;
};

string Zlinerast::matparCdf(
			const string& tmppath
			, const string& srefsDomain
			, const string& srefMatparCat
			, const string& srefMatparProp
		) {
	string s;

	string outfile;

	vector<string> vecDom;
	unsigned int ixDom;

	unsigned int ixMatpar;

	int cdfRoot, cdfDoms, cdfDom;
	int cdfDimZ;
	int cdfVar;

	int* dims = NULL;

	double* var = NULL;

	double z;

	StrMod::stringToVector(srefsDomain, vecDom);
	getMatparIx(srefMatparCat, srefMatparProp, ixMatpar);

	// create and open cdf file
	outfile = Tmp::newfile(tmppath, "cdf");
	s = tmppath + "/" + outfile;

	nc_create(s.c_str(), NC_NETCDF4, &cdfRoot);
	nc_def_grp(cdfRoot, "doms", &cdfDoms);

	// set up cdf file
	nc_enddef(cdfRoot);

	// traverse specified domains
	for (unsigned int i=0;i<vecDom.size();i++) {
		if (getDomIx(vecDom[i], ixDom)) {
			// copy parameters first
			cdfDom = domCdf(ixDom, cdfDoms, cdfDimZ);

			// define and assemble variable
			nc_redef(cdfRoot);

			if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZLINE_Z) {
				dims = new int[1]; dims[0] = cdfDimZ;
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 1, dims, &cdfVar);
				delete[] dims;

				var = new double[domDimZ[ixDom]];

				for (unsigned int k=0;k<domDimZ[ixDom];k++) {
					z = domZ0[ixDom]+k*domDz[ixDom]+domB3[ixDom];
					var[k] = getMatpar(z, ixMatpar);
				};

				s = srefMatparProp + "(z)";

			} else if (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::POINT_Z) {
				nc_def_var(cdfDom, srefMatparProp.c_str(), NC_DOUBLE, 0, NULL, &cdfVar);

				var = new double[1];

				var[0] = getMatpar(domB3[ixDom], ixMatpar);

				s = srefMatparProp;
			};

			if (var) {
				nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());
				nc_put_att_text(cdfDom, cdfVar, "title", titMatparProps[ixMatpar].length(), titMatparProps[ixMatpar].c_str());
			};

			nc_enddef(cdfRoot);

			// write variable
			if (var) {
				nc_put_var_double(cdfDom, cdfVar, var);

				delete[] var;
				var = NULL;
			};
		};
	};

	nc_close(cdfRoot);

	return outfile;
};

int Zlinerast::domCdf(
			const unsigned int ixDom
			, const int cdfRoot
			, int& cdfDimZ
		) {
	bool hasz;

	int cdfDom;
	int cdf_ixVBasetype;
	int cdf_z0;
	int cdf_z1;
	int cdf_dz;
	int cdf_b3;

	hasz = (domIxVBasetype[ixDom] == VecPlnrVMDomainBasetype::ZLINE_Z);

	nc_redef(cdfRoot);
		nc_def_grp(cdfRoot, domSref[ixDom].c_str(), &cdfDom);
			if (hasz) nc_def_dim(cdfDom, "dimZ", domDimZ[ixDom], &cdfDimZ);
			nc_def_var(cdfDom, "ixVBasetype", NC_UINT, 0, NULL, &cdf_ixVBasetype);
			if (hasz) {
				nc_def_var(cdfDom, "z0", NC_DOUBLE, 0, NULL, &cdf_z0);
				nc_def_var(cdfDom, "z1", NC_DOUBLE, 0, NULL, &cdf_z1);
				nc_def_var(cdfDom, "dz", NC_DOUBLE, 0, NULL, &cdf_dz);
			};
			nc_def_var(cdfDom, "b3", NC_DOUBLE, 0, NULL, &cdf_b3);
	nc_enddef(cdfRoot);
	if (hasz) {
		nc_put_var_double(cdfDom, cdf_z0, &(domZ0[ixDom]));
		nc_put_var_double(cdfDom, cdf_z1, &(domZ1[ixDom]));
		nc_put_var_double(cdfDom, cdf_dz, &(domDz[ixDom]));
	};
	nc_put_var_double(cdfDom, cdf_b3, &(domB3[ixDom]));
	nc_put_var_uint(cdfDom, cdf_ixVBasetype, &(domIxVBasetype[ixDom]));

	return cdfDom;
};

/******************************************************************************
 namespace Env
 ******************************************************************************/

string Env::extractKey(
			const string& s
		) {
	string retval;

	size_t ptr1;

	ptr1 = s.find("env.");
	if (ptr1 != string::npos) retval = s.substr(ptr1+4);

	return retval;
};

bool Env::getBoolVal(
			const map<string, string>& env
			, const string& key
		) {
	string strval = getStringVal(env, key);

	return (strval.compare("true") == 0);
};

int Env::getIntVal(
			const map<string, string>& env
			, const string& key
		) {
	string strval = getStringVal(env, key);

	return atoi(strval.c_str());
};

double Env::getDoubleVal(
			const map<string, string>& env
			, const string& key
		) {
	string strval = getStringVal(env, key);

	return atof(strval.c_str());
};

string Env::getStringVal(
			const map<string, string>& env
			, const string& key
		) {
	map<string, string>::const_iterator ptr = env.find(key);

	if (ptr == env.end()) return "";
	else return ptr->second;
};

void Env::setBoolVal(
			map<string, string>& env
			, const string& key
			, const bool val
		) {
	if (val) env[key] = "true";
	else env[key] = "false";
};

void Env::setIntVal(
			map<string, string>& env
			, const string& key
			, const int val
		) {
	env[key] = to_string(val);
};

void Env::setDoubleVal(
			map<string, string>& env
			, const string& key
			, const double val
		) {
	ostringstream str;
	str.setf(ios::scientific);

	str << val;
	env[key] = str.str();
};

void Env::setStringVal(
			map<string, string>& env
			, const string& key
			, const string& val
		) {
	env[key] = val;
};

void Env::setForCli(
			DbsPlnr* dbsplnr
			, map<string, string>& env
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMCalcitem
		) {
	ListPlnrAMCalcEnv cens;
	PlnrAMCalcEnv* cen = NULL;

	// pre-fill with calc values
	dbsplnr->tblplnramcalcenv->loadRstByCalCli(refPlnrMCalc, 0, false, cens);
	// override with / add calcitem specific values
	dbsplnr->tblplnramcalcenv->loadRstByCalCli(refPlnrMCalc, refPlnrMCalcitem, true, cens);

	for (unsigned int j=0;j<cens.nodes.size();j++) {
		cen = cens.nodes[j];
		setStringVal(env, cen->x2SrefKKey, cen->Val);
	};
};

void Env::setForAri(
			DbsPlnr* dbsplnr
			, map<string, string>& env
			, const ubigint refPlnrMArray
			, const ubigint refPlnrMArrayitem
		) {
	ListPlnrAMArrayEnv aens;
	PlnrAMArrayEnv* aen = NULL;

	// pre-fill with array values
	dbsplnr->tblplnramarrayenv->loadRstByArrAri(refPlnrMArray, 0, false, aens);
	// override with / add arrayitem specific values
	dbsplnr->tblplnramarrayenv->loadRstByArrAri(refPlnrMArray, refPlnrMArrayitem, true, aens);

	for (unsigned int j=0;j<aens.nodes.size();j++) {
		aen = aens.nodes[j];
		setStringVal(env, aen->x2SrefKKey, aen->Val);
	};
};

/******************************************************************************
 class Mpa
 ******************************************************************************/

Mpa::Mpa() {
};

Mpa::~Mpa() {
	for (unsigned int i=0;i<vars.size();i++) delete vars[i];
};

bool Mpa::findVar(
			const ubigint refPlnrMFile
			, const string& srefVar
			, unsigned int& ixVar
		) {
	bool found = false;

	for (unsigned int i=0;i<refsPlnrMFile.size();i++) {
		if (refsPlnrMFile[i] == refPlnrMFile) {
			if (srefsVar[i].compare(srefVar) == 0) {
				ixVar = i;
				found = true;
				break;
			};
		};
	};

	return found;
};

bool Mpa::getVar(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const ubigint refPlnrMFile
			, const string& srefVar
			, vector<double>*& var
		) {
	unsigned int ixVar;

	vector<string> srefs;

	if (findVar(refPlnrMFile, srefVar, ixVar)) {
		var = vars[ixVar];
		return true;

	} else {
		// load variable into cache
		srefs.push_back(srefVar);
		loadVars(dbsplnr, acvpath, refPlnrMFile, srefs);

		if (findVar(refPlnrMFile, srefVar, ixVar)) {
			var = vars[ixVar];
			return true;
		};
	};

	return false;
};

void Mpa::loadVars(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const ubigint refPlnrMFile
			, const vector<string>& srefs
		) {
	unsigned int ixVar;

	double load, found;

	string s;

	PlnrMFile* fil = NULL;

	int cdfRoot;

	vector<double> vec;
	vector<double>* vecptr = NULL;

	// verify that at least one variable is not yet cached
	load = false;
	for (unsigned int i=0;i<srefs.size();i++) {
		if (!findVar(refPlnrMFile, srefs[i], ixVar)) {
			load = true;
			break;
		};
	};

	if (load) {
		// cdf file via archive
		dbsplnr->tblplnrmfile->loadRecByRef(refPlnrMFile, &fil);
		s = acvpath + "/" + fil->Archivename.substr(0, 5) + "/" + fil->Archivename;
		delete fil;
cout << "opening netCDF file '" << s << "'" << endl;

		nc_open(s.c_str(), 0, &cdfRoot);

		for (unsigned int i=0;i<srefs.size();i++) {
			if (!findVar(refPlnrMFile, srefs[i], ixVar)) {
				// non-cached variables only
				found = Cdf::getDoubleVec(cdfRoot, "", srefs[i], vec);

				if (found) {
					vecptr = new vector<double>;
					*vecptr = vec;

					refsPlnrMFile.push_back(refPlnrMFile);
					srefsVar.push_back(srefs[i]);
					vars.push_back(vecptr);
				};
			};
		};

		nc_close(cdfRoot);
	};
};

/******************************************************************************
 namespace Fct
 ******************************************************************************/

bool Fct::parse(
			const string& expr
			, const string& fct
			, vector<string>& args
		) {
	string s;
	size_t pos, pos1, pos2;
	bool valid, skip, text;

	s = expr;

	pos1 = s.find(fct);
	valid = (pos1 != string::npos);

	// check for "fct("
	if (valid) {
		valid = false;

		pos1 = pos1+fct.length();

		if (pos1 < s.length()) if (s[pos1] == '(') valid = true;
	};

	// check for well-formed content within "()"
	if (valid) {
		valid = false;
		skip = false;

		pos1 += 1;

		for (pos=pos1;pos<s.length();pos++) {
			if (s[pos] == '\"') {
				skip = !skip;
			} else if (s[pos] == '\'') {
				skip = !skip;
			} else if (s[pos] == '(') {
				skip = true;
			} else if (s[pos] == ')') {
				if (skip) {
					skip = false;
				} else {
					pos2 = pos;
					valid = true;
					break;
				};
			};
		};
	};

	// extract arguments
	if (valid) {
		args.resize(0);

		s = s.substr(pos1, pos2-pos1);
		s = StrMod::spcex(s);
		
		// strip {, } if present
		if (s.length() >= 2) {
			if (s[0] == '{') s = s.substr(1);
			if (s[s.length()-1] == '}') s = s.substr(0, s.length()-1);
		};

		pos1 = s.length();
		skip = true;
		text = false;

		// fetch function arguments, skipping quotes and spaces outside quotes
		for (pos=0;pos<s.length();pos++) {
			if (skip) {
				if ((s[pos] == '\"') || (s[pos] == '\'')) {
					pos1 = pos+1;
					skip = false;
					text = true;

				} else if (s[pos] == ',') {
				} else if (s[pos] == ' ') {

				} else {
					pos1 = pos;
					skip = false;
				};

			} else {
				if (text) {
					if ((s[pos] == '\"') || (s[pos] == '\'')) {
						pos2 = pos;
						if (pos2 > pos1) args.push_back(s.substr(pos1, pos2-pos1));
						skip = true;
						text = false;
					};

				} else {
					if ((s[pos] == ',') || (s[pos] == ' ')) {
						pos2 = pos;
						if (pos2 > pos1) args.push_back(s.substr(pos1, pos2-pos1));
						skip = true;
					};
				};
			};
		};

		if (text) {
			valid = false;
		} else {
			if (!skip && (pos > pos1)) args.push_back(s.substr(pos1));
		};
	};

	return valid;
};

bool Fct::venavlDgdTyp(
			const uint ixVBasetype
			, const uint dsnDim
		) {
	// dsnDimEq(TblPlnrMDesign.ixVDim)

	if (ixVBasetype == VecPlnrVMDomaingdBasetype::LVL) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::Z)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::VTXLG) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::VTXAG) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::VTXPRPLG) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::VTXLGX) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::LGPAR) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::LGPAR2) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::LGPRPAG) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::LGPRPLG) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	} else if (ixVBasetype == VecPlnrVMDomaingdBasetype::LGVTX) {
		if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) return true;
	};

	return false;
};

void Fct::venavlDgdTyp(
			vector<uint>& icsVBasetype
			, const uint dsnDim
		) {
	// dsnDimEq(TblPlnrMDesign.ixVDim)

	icsVBasetype.resize(0);

	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::Z)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::LVL);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::VTXLG);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::VTXAG);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::VTXPRPLG);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::VTXLGX);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::LGPAR);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::LGPAR2);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::LGPRPAG);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::LGPRPLG);
	if ((dsnDim == VecPlnrVMDesignDim::XYZ) || (dsnDim == VecPlnrVMDesignDim::XY)) icsVBasetype.push_back(VecPlnrVMDomaingdBasetype::LGVTX);
};

bool Fct::venavlDomTyp(
			const uint ixVBasetype
			, const uint dsnDim
		) {
	// dsnDimEq(TblPlnrMDesign.ixVDim)

	if (ixVBasetype == VecPlnrVMDomainBasetype::CUB_XYZ) {
		if (dsnDim == VecPlnrVMDesignDim::XYZ) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XYZ) {
		if (dsnDim == VecPlnrVMDesignDim::XYZ) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::XYBOX_XY) {
		if (dsnDim == VecPlnrVMDesignDim::XY) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
		if (dsnDim == VecPlnrVMDesignDim::XYZ) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XYZ) {
		if (dsnDim == VecPlnrVMDesignDim::XYZ) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::XYLINE_XY) {
		if (dsnDim == VecPlnrVMDesignDim::XY) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_XYZ) {
		if (dsnDim == VecPlnrVMDesignDim::XYZ) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::ZLINE_Z) {
		if (dsnDim == VecPlnrVMDesignDim::Z) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::POINT_XYZ) {
		if (dsnDim == VecPlnrVMDesignDim::XYZ) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::POINT_XY) {
		if (dsnDim == VecPlnrVMDesignDim::XY) return true;
	} else if (ixVBasetype == VecPlnrVMDomainBasetype::POINT_Z) {
		if (dsnDim == VecPlnrVMDesignDim::Z) return true;
	};

	return false;
};

void Fct::venavlDomTyp(
			vector<uint>& icsVBasetype
			, const uint dsnDim
		) {
	// dsnDimEq(TblPlnrMDesign.ixVDim)

	icsVBasetype.resize(0);

	if (dsnDim == VecPlnrVMDesignDim::XYZ) icsVBasetype.push_back(VecPlnrVMDomainBasetype::CUB_XYZ);
	if (dsnDim == VecPlnrVMDesignDim::XYZ) icsVBasetype.push_back(VecPlnrVMDomainBasetype::XYBOX_XYZ);
	if (dsnDim == VecPlnrVMDesignDim::XY) icsVBasetype.push_back(VecPlnrVMDomainBasetype::XYBOX_XY);
	if (dsnDim == VecPlnrVMDesignDim::XYZ) icsVBasetype.push_back(VecPlnrVMDomainBasetype::ZCSBOX_XYZ);
	if (dsnDim == VecPlnrVMDesignDim::XYZ) icsVBasetype.push_back(VecPlnrVMDomainBasetype::XYLINE_XYZ);
	if (dsnDim == VecPlnrVMDesignDim::XY) icsVBasetype.push_back(VecPlnrVMDomainBasetype::XYLINE_XY);
	if (dsnDim == VecPlnrVMDesignDim::XYZ) icsVBasetype.push_back(VecPlnrVMDomainBasetype::ZLINE_XYZ);
	if (dsnDim == VecPlnrVMDesignDim::Z) icsVBasetype.push_back(VecPlnrVMDomainBasetype::ZLINE_Z);
	if (dsnDim == VecPlnrVMDesignDim::XYZ) icsVBasetype.push_back(VecPlnrVMDomainBasetype::POINT_XYZ);
	if (dsnDim == VecPlnrVMDesignDim::XY) icsVBasetype.push_back(VecPlnrVMDomainBasetype::POINT_XY);
	if (dsnDim == VecPlnrVMDesignDim::Z) icsVBasetype.push_back(VecPlnrVMDomainBasetype::POINT_Z);
};

bool Fct::klkavlMatAparPrp(
			const PlnrAVKeylistKey* klk
			, const string& matAparCat
		) {
	// catEq({TblPlnrAMMaterialPar.x2SrefKCat})

	bool retval = true;

	vector<string> args;
	string arg;

	if (parse(klk->Avail, "catEq", args)) {
		retval = false;

		for (unsigned int i=0;i<args.size();i++) {
			arg = args[i];

			if (arg.compare(matAparCat) == 0) {
				retval = true;
				break;
			};
		};
	};

	return retval;
};

void Fct::klkavlMatAparPrp(
			const ListPlnrAVKeylistKey& klks
			, vector<bool>& avl
			, const string& matAparCat
		) {
	PlnrAVKeylistKey* klk = NULL;

	avl.resize(0); avl.resize(klks.nodes.size());

	for (unsigned int i=0;i<klks.nodes.size();i++) {
		klk = klks.nodes[i];

		avl[i] = klkavlMatAparPrp(klk, matAparCat);
	};
};

string Fct::evalMatAparVal(
			DbsPlnr* dbsplnr
			, const map<string, string>& env
			, Mpa& mpacache
			, const string& acvpath
			, const PlnrAMMaterialPar* mpa
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// lintbl(env.<srefx>, <colx>, <coly>)
	// uses Env
	// uses referencing mpa->Val -> TblPlnrAMMaterialPar.x3SrefKProp (hierarchical refPlnrMMaterial)

cout << "\tevalMatAparVal() with mpa->Val = '" << mpa->Val << "'" << endl;

	ostringstream str;
	str.setf(ios::scientific);

	string retval;

	vector<string> args;
	string s;
	double par;

	vector<double>* colx = NULL;
	vector<double>* coly = NULL;
	unsigned int N, ix;

	PlnrAMMaterialPar* mpa2 = NULL;

	if (parse(mpa->Val, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else if (parse(mpa->Val, "lintbl", args)) {
		if (args.size() == 3) {
			// first argument env vs. double value
			s = Env::getStringVal(env, Env::extractKey(args[0]));

			if (s.length() == 0) {
				par = atof(args[0].c_str());
			} else {
				par = atof(s.c_str());
			};
cout << "par is " << par << endl;
			// retrieve material parameter by linearizing from tabular data stored in cdf file
			if (mpa->refPlnrMFile != 0) {
cout << "looking for columns '" << args[1] << "' and '" << args[2] << "'" << endl;
				if (mpacache.getVar(dbsplnr, acvpath, mpa->refPlnrMFile, args[1], colx)) {
					if (mpacache.getVar(dbsplnr, acvpath, mpa->refPlnrMFile, args[2], coly)) {
						// linear interpolation
						N = colx->size();
cout << "found both columns of size " << N << endl;

						if ((*colx)[N-1] > (*colx)[0]) {
							// x ascending
							if (((*colx)[0] <= par) && ((*colx)[N-1] >= par)) {
								for (ix=0;ix<N;ix++) {
									if ((*colx)[ix] >= par) {
										if (ix == 0) {
											str << ((*coly)[0]);
										} else {
											str << ((*coly)[ix-1] + ((par-(*colx)[ix-1])/((*colx)[ix]-(*colx)[ix-1])) * ((*coly)[ix]-(*coly)[ix-1]));
										};
										retval = str.str();
										break;
									};
								};
							};

						} else {
							// x descending
							if (((*colx)[N-1] <= par) && ((*colx)[0] >= par)) {
								for (ix=0;ix<N;ix++) {
									if ((*colx)[ix] <= par) {
										if (ix == 0) {
											str << ((*coly)[0]);
										} else {
											str << ((*coly)[ix-1] + ((par-(*colx)[ix-1])/((*colx)[ix]-(*colx)[ix-1])) * ((*coly)[ix]-(*coly)[ix-1]));
										};
										retval = str.str();
										break;
									};
								};
							};
						};
					};
				};
			};
		};

	} else {
		// improvised (and unprecise) test for numerical value vs. reference to other material parameter
		if (mpa->Val.length() > 0) {
			if ((mpa->Val[0] == '+') || (mpa->Val[0] == '-') || ((mpa->Val[0] >= '0') && (mpa->Val[0] <= '9'))) {
				retval = mpa->Val;

			} else {
				// reference to other material parameter (recursive evaluation)
				if (Plnr::findMpa(dbsplnr, mpa->refPlnrMMaterial, refBasedsn, refModdsn, mpa->x2SrefKCat, mpa->Val, &mpa2)) {
					retval = evalMatAparVal(dbsplnr, env, mpacache, acvpath, mpa2, refBasedsn, refModdsn, forcedft);

					delete mpa2;
				};
			};
		};
	};

	return retval;
};

string Fct::evalDevAparVal(
			const map<string, string>& env
			, const PlnrAMDevicePar* dpa
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dpa->Val, "envdft", args)) {

		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dpa->Val;
	};

	return retval;
};

string Fct::evalLyrT(
			const map<string, string>& env
			, const PlnrMLayer* lyr
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(lyr->t, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = lyr->t;
	};

	return retval;
};

string Fct::evalLyrMl(
			const map<string, string>& env
			, const PlnrMLayer* lyr
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(lyr->ML, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = lyr->ML;
	};

	return retval;
};

string Fct::evalStkN(
			const map<string, string>& env
			, const PlnrMStack* stk
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(stk->N, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = stk->N;
	};

	// enforce integer value
	retval = to_string(roundf(atof(retval.c_str())));

	return retval;
};

string Fct::evalDgdD(
			const map<string, string>& env
			, const PlnrMDomaingd* dgd
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dgd->d, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dgd->d;
	};

	return retval;
};

string Fct::evalDgdDph(
			const map<string, string>& env
			, const PlnrMDomaingd* dgd
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dgd->dphi, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dgd->dphi;
	};

	return retval;
};

string Fct::evalDomDx(
			const map<string, string>& env
			, const PlnrMDomain* dom
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dom->dx, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dom->dx;
	};

	return retval;
};

string Fct::evalDomDy(
			const map<string, string>& env
			, const PlnrMDomain* dom
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dom->dy, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dom->dy;
	};

	return retval;
};

string Fct::evalDomDxy(
			const map<string, string>& env
			, const PlnrMDomain* dom
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dom->dxy, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dom->dxy;
	};

	return retval;
};

string Fct::evalDomDz(
			const map<string, string>& env
			, const PlnrMDomain* dom
			, const bool forcedft
		) {
	// envdft(env.<sref>, <dft>)
	// uses Env

	string retval;

	vector<string> args;

	if (parse(dom->dz, "envdft", args)) {
		if (args.size() == 2) {
			retval = Env::getStringVal(env, Env::extractKey(args[0]));
			if ((retval.length() == 0) || forcedft) retval = args[1];
		};

	} else {
		retval = dom->dz;
	};

	return retval;
};
// IP cust --- IEND

/******************************************************************************
 namespace Plnr
 ******************************************************************************/

// IP gbl --- IBEGIN
double Plnr::degToRad(
			const double deg
		) {
	return(pi*deg/180.0);
};

void Plnr::removeDesign(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDesign
		) {
};

void Plnr::removeCalc(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
		) {
};

void Plnr::removeTapeout(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMTapeout
		) {
};

void Plnr::getRefsDtp(
			DbsPlnr* dbsplnr
			, map<string, ubigint>& refsDtp
		) {
	ListPlnrMDevice dtps;
	PlnrMDevice* dtp = NULL;

	dbsplnr->tblplnrmdevice->loadRstBySQL("SELECT * FROM TblPlnrMDevice WHERE tplRefPlnrMDevice = 0", false, dtps);

	for (unsigned int i=0;i<dtps.nodes.size();i++) {
		dtp = dtps.nodes[i];

		refsDtp[dtp->sref] = dtp->ref;
	};
};

PlnrMDevice* Plnr::addDeviceFromTpl(
			DbsPlnr* dbsplnr
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const ubigint supRefPlnrMDevice
			, const uint supNum
			, const string& sref
			, const uint ixVAligntype
			, const string& av1SrefPlnrMVertex
			, const string& pav1SrefPlnrMVertex
			, const string& av2SrefPlnrMVertex
			, const string& pav2SrefPlnrMVertex
			, const double x
			, const double y
			, const double phi
			, const string& Comment
			, map<string, ubigint>& refsDtp
			, const string& srefDtp
			, ListPlnrMDevice& devs
		) {
	PlnrMDevice* dev = NULL;

	PlnrAMDevicePar* dpa = NULL;
	ListPlnrAMDevicePar dpas;

	PlnrMStructure* sru = NULL;
	ListPlnrMStructure srus;

	// find reference of template device
	ubigint refTpl = 0;
	map<string, ubigint>::iterator ix;

	ix = refsDtp.find(srefDtp);
	if (ix != refsDtp.end()) refTpl = ix->second;

	if (refTpl != 0) {
		// create device
		dev = new PlnrMDevice(0, dsnRefPlnrMDesign, dsnNum, supRefPlnrMDevice, supNum, refTpl, sref,
					VecPlnrVMDeviceModtype::VOID, ixVAligntype, av1SrefPlnrMVertex, pav1SrefPlnrMVertex, av2SrefPlnrMVertex, pav2SrefPlnrMVertex, x, y, phi, Comment);
		dbsplnr->tblplnrmdevice->insertRec(dev); devs.nodes.push_back(dev);

		// copy parameters from template device
		dbsplnr->tblplnramdevicepar->loadRstByDev(refTpl, false, dpas);
		for (unsigned int i=0;i<dpas.nodes.size();i++) {
			dpa = dpas.nodes[i];

			dpa->ref = 0; // in principle obsolete
			dpa->refPlnrMDevice = dev->ref;
		};
		dbsplnr->tblplnramdevicepar->insertRst(dpas);

		// copy structures from template device
		dbsplnr->tblplnrmstructure->loadRstByHktHku(VecPlnrVMStructureHkTbl::DEV, refTpl, false, srus);
		for (unsigned int i=0;i<srus.nodes.size();i++) {
			sru = srus.nodes[i];

			sru->ref = 0; // in principle obsolete
			sru->hkUref = dev->ref;
		};
		dbsplnr->tblplnrmstructure->insertRst(srus);
	};

	return dev;
};

void Plnr::changeBoolDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const bool Val
		) {
	if (Val) changeDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, "true");
	else changeDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, "false");
};

void Plnr::changeIntDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const int Val
		) {
	changeDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, to_string(Val));
};

void Plnr::changeDoubleDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const double Val
		) {
	changeDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, to_string(Val));
};

void Plnr::changeDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const string& Val
		) {
	dbsplnr->executeQuery("UPDATE TblPlnrAMDevicePar SET Val = '" + Val + "' WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign = "
				+ to_string(x1RefPlnrMDesign) + " AND x2SrefKKey = '" + x2SrefKKey + "'");
};

void Plnr::changeDpaReffile(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const ubigint Val
		) {
	dbsplnr->executeQuery("UPDATE TblPlnrAMDevicePar SET refPlnrMFile = " + to_string(Val) + " WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign = "
				+ to_string(x1RefPlnrMDesign) + " AND x2SrefKKey = '" + x2SrefKKey + "'");
};

void Plnr::addBoolDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const bool Val
		) {
	if (Val) addDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, "true");
	else addDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, "false");
};

void Plnr::addIntDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const int Val
		) {
	addDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, to_string(Val));
};

void Plnr::addDoubleDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const double Val
		) {
	addDpa(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, to_string(Val));
};

void Plnr::addDpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const string& Val
		) {
	PlnrAMDevicePar* dpa = new PlnrAMDevicePar(0, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, 0, Val);

	dbsplnr->tblplnramdevicepar->insertRec(dpa);

	delete dpa;
};

void Plnr::addDpaReffile(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKKey
			, const ubigint Val
		) {
	PlnrAMDevicePar* dpa = new PlnrAMDevicePar(0, refPlnrMDevice, x1RefPlnrMDesign, x2SrefKKey, Val, "");

	dbsplnr->tblplnramdevicepar->insertRec(dpa);

	delete dpa;
};

PlnrMLayer* Plnr::addLayer(
			DbsPlnr* dbsplnr
			, const uint ixVBasetype
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint refPlnrMMaterial
			, const uint ixVTtype
			, const string& sref
			, const double t
			, const string& ML
			, ListPlnrMLayer& lyrs
		) {
	return addLayer(dbsplnr, ixVBasetype, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, to_string(t), ML, lyrs);
};

PlnrMLayer* Plnr::addLayer(
			DbsPlnr* dbsplnr
			, const uint ixVBasetype
			, const ubigint hkUref
			, const uint hkNum
			, const ubigint refPlnrMMaterial
			, const uint ixVTtype
			, const string& sref
			, const string& t
			, const string& ML
			, ListPlnrMLayer& lyrs
		) {
	PlnrMLayer* lyr = NULL;

	lyr = new PlnrMLayer(0, 0, ixVBasetype, VecPlnrVMLayerHkTbl::STK, hkUref, hkNum, refPlnrMMaterial, ixVTtype, sref, 0, 0, 0, t, ML);
	dbsplnr->tblplnrmlayer->insertRec(lyr); lyrs.nodes.push_back(lyr);

	return lyr;
};

void Plnr::addLyrsru(
			DbsPlnr* dbsplnr
			, const ubigint refLyr
			, const ubigint refDev
			, const string& srefSru
		) {
	PlnrRMLayerMStructure* lrs = NULL;

	// find structure
	ubigint refSru = 0;
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refDev, srefSru, refSru);

	// create link
	lrs = new PlnrRMLayerMStructure(0, refLyr, refSru);
	dbsplnr->tblplnrrmlayermstructure->insertRec(lrs);

	delete lrs;
};

void Plnr::addLyrsru(
			DbsPlnr* dbsplnr
			, const ubigint refLyr
			, const string& srefDev
			, const string& srefSru
			, const ListPlnrMDevice& devs
		) {
	PlnrRMLayerMStructure* lrs = NULL;

	// find device
	ubigint refDev = 0;
	for (unsigned int i=0;i<devs.nodes.size();i++) {
		if (devs.nodes[i]->sref.compare(srefDev) == 0) {
			refDev = devs.nodes[i]->ref;
			break;
		};
	};

	// find structure
	ubigint refSru = 0;
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refDev, srefSru, refSru);

	// create link
	lrs = new PlnrRMLayerMStructure(0, refLyr, refSru);
	dbsplnr->tblplnrrmlayermstructure->insertRec(lrs);

	delete lrs;
};

void Plnr::addLyrsru(
			DbsPlnr* dbsplnr
			, const string& srefLyr
			, const string& srefDev
			, const string& srefSru
			, const ListPlnrMLayer& lyrs
			, const ListPlnrMDevice& devs
		) {
	PlnrRMLayerMStructure* lrs = NULL;

	// find layer
	ubigint refLyr = 0;
	for (unsigned int i=0;i<lyrs.nodes.size();i++) {
		if (lyrs.nodes[i]->sref.compare(srefLyr) == 0) {
			refLyr = lyrs.nodes[i]->ref;
			break;
		};
	};

	// find device
	ubigint refDev = 0;
	for (unsigned int i=0;i<devs.nodes.size();i++) {
		if (devs.nodes[i]->sref.compare(srefDev) == 0) {
			refDev = devs.nodes[i]->ref;
			break;
		};
	};

	// find structure
	ubigint refSru = 0;
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refDev, srefSru, refSru);

	// create link
	lrs = new PlnrRMLayerMStructure(0, refLyr, refSru);
	dbsplnr->tblplnrrmlayermstructure->insertRec(lrs);

	delete lrs;
};

void Plnr::addStksru(
			DbsPlnr* dbsplnr
			, const string& srefStk
			, const string& srefDev
			, const string& srefSru
			, const string& fromSrefPlnrMLayer
			, const string& toSrefPlnrMLayer
			, const ListPlnrMStack& stks
			, const ListPlnrMDevice& devs
		) {
	PlnrRMStackMStructure* srs = NULL;

	// find stack
	ubigint refStk = 0;
	for (unsigned int i=0;i<stks.nodes.size();i++) {
		if (stks.nodes[i]->sref.compare(srefStk) == 0) {
			refStk = stks.nodes[i]->ref;
			break;
		};
	};

	// find device
	ubigint refDev = 0;
	for (unsigned int i=0;i<devs.nodes.size();i++) {
		if (devs.nodes[i]->sref.compare(srefDev) == 0) {
			refDev = devs.nodes[i]->ref;
			break;
		};
	};

	// find structure
	ubigint refSru = 0;
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refDev, srefSru, refSru);

	// create link
	srs = new PlnrRMStackMStructure(0, refStk, refSru, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	dbsplnr->tblplnrrmstackmstructure->insertRec(srs);

	// clean up
	delete srs;
};

PlnrMDomaingd* Plnr::addDomaingd(
			DbsPlnr* dbsplnr
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string& sref
			, const string& srefPlnrMLevel
			, const string& av1SrefPlnrMVertex
			, const string& av2SrefPlnrMVertex
			, const string& al1SrefPlnrMLineguide
			, const string& al2SrefPlnrMLineguide
			, const string& srefPlnrMArcguide
			, const string& d
			, const string& dphi
			, ListPlnrMDomaingd& dgds
		) {
	PlnrMDomaingd* dgd = NULL;

	dgd = new PlnrMDomaingd(0, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, srefPlnrMLevel, av1SrefPlnrMVertex, av2SrefPlnrMVertex, al1SrefPlnrMLineguide, al2SrefPlnrMLineguide, srefPlnrMArcguide, d, dphi);
	dbsplnr->tblplnrmdomaingd->insertRec(dgd); dgds.nodes.push_back(dgd);

	return dgd;
};

PlnrMDomain* Plnr::addDomain(
			DbsPlnr* dbsplnr
			, const uint ixVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const uint dsnNum
			, const string& sref
			, const string& flrSrefPlnrMLevel
			, const string& ceilSrefPlnrMLevel
			, const string& vtx1SrefPlnrMVertex
			, const string& lgd1SrefPlnrMLineguide
			, const string& vtx2SrefPlnrMVertex
			, const string& lgd2SrefPlnrMLineguide
			, const string& vtx3SrefPlnrMVertex
			, const string& lgd3SrefPlnrMLineguide
			, const string& vtx4SrefPlnrMVertex
			, const string& lgd4SrefPlnrMLineguide
			, ListPlnrMDomain& doms
		) {
	PlnrMDomain* dom = NULL;

	dom = new PlnrMDomain(0, ixVBasetype, dsnRefPlnrMDesign, dsnNum, sref, flrSrefPlnrMLevel, ceilSrefPlnrMLevel, vtx1SrefPlnrMVertex, lgd1SrefPlnrMLineguide, vtx2SrefPlnrMVertex, lgd2SrefPlnrMLineguide, vtx3SrefPlnrMVertex, lgd3SrefPlnrMLineguide, vtx4SrefPlnrMVertex, lgd4SrefPlnrMLineguide);
	dbsplnr->tblplnrmdomain->insertRec(dom); doms.nodes.push_back(dom);

	return dom;
};

void Plnr::getDomrast(
			DbsPlnr* dbsplnr
			, PlnrMDomain* dom
			, const ubigint refModdsn
			, double& dx
			, double& dy
			, double& dxy
			, double& dz
		) {
	map<string, string> env;

	PlnrJMDomain* doj = NULL;

	dom->dx = Fct::evalDomDx(env, dom, true);
	dom->dy = Fct::evalDomDy(env, dom, true);
	dom->dxy = Fct::evalDomDxy(env, dom, true);
	dom->dz = Fct::evalDomDz(env, dom, true);

	if (dbsplnr->tblplnrjmdomain->loadRecByDomDsn(dom->ref, refModdsn, &doj)) {
		dom->dx = doj->dx;
		dom->dy = doj->dy;
		dom->dxy = doj->dxy;
		dom->dz = doj->dz;

		delete doj;
	};

	dx = atof(dom->dx.c_str());
	if (dx == 0.0) dx = 0.1;

	dy = atof(dom->dy.c_str());
	if (dy == 0.0) dy = 0.1;

	dxy = atof(dom->dxy.c_str());
	if (dxy == 0.0) dxy = 0.1;

	dz = atof(dom->dz.c_str());
	if (dz == 0.0) dz = 0.1;
};

PlnrMCalc* Plnr::calcFromTpl(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMProject
			, const ubigint refPlnrMDesign
			, const string& Title
			, const string& titTpl
			, const string& Comment
		) {
	PlnrMCalc* cal = NULL;

	// find template calculation
	dbsplnr->tblplnrmcalc->loadRecByTplTit(0, titTpl, &cal);

	// change into actual calculation
	cal->refPlnrMProject = refPlnrMProject;
	cal->tplRefPlnrMCalc = cal->ref;
	cal->refPlnrMDesign = refPlnrMDesign;
	cal->Title = Title;
	cal->Comment = Comment;
	cal->ref = 0;

	dbsplnr->tblplnrmcalc->insertRec(cal);

	return cal;
};

void Plnr::addBoolCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, const bool Val
		) {
	PlnrAMCalcPar* cpa = NULL;

	if (Val) cpa = new PlnrAMCalcPar(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, "true");
	else cpa = new PlnrAMCalcPar(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, "false");
	dbsplnr->tblplnramcalcpar->insertRec(cpa);

	delete cpa;
};

void Plnr::addIntCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, const int Val
		) {
	PlnrAMCalcPar* cpa = NULL;

	cpa = new PlnrAMCalcPar(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, to_string(Val));
	dbsplnr->tblplnramcalcpar->insertRec(cpa);

	delete cpa;
};

void Plnr::addDoubleCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, const double Val
		) {
	ostringstream str;
	str.setf(ios::scientific);

	PlnrAMCalcPar* cpa = NULL;

	str << Val;
	cpa = new PlnrAMCalcPar(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, str.str());
	dbsplnr->tblplnramcalcpar->insertRec(cpa);

	delete cpa;
};

void Plnr::addDoubleCen(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKKey
			, const double Val
		) {
	ostringstream str;
	str.setf(ios::scientific);

	PlnrAMCalcEnv* cen = NULL;

	str << Val;
	cen = new PlnrAMCalcEnv(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, str.str());
	dbsplnr->tblplnramcalcenv->insertRec(cen);

	delete cen;
};

bool Plnr::loadBoolCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, bool& val
		) {
	PlnrAMCalcPar* cpa = NULL;

	if (dbsplnr->tblplnramcalcpar->loadRecByCalCliCatPrp(refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, &cpa)) {
		val = (cpa->Val.compare("true") == 0);

		delete cpa;
		return true;
	};

	return false;
};

bool Plnr::loadIntCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, int& val
		) {
	PlnrAMCalcPar* cpa = NULL;

	if (dbsplnr->tblplnramcalcpar->loadRecByCalCliCatPrp(refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, &cpa)) {
		val = atoi(cpa->Val.c_str());
	
		delete cpa;
		return true;
	};

	return false;
};

bool Plnr::loadDoubleCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, double& val
		) {
	PlnrAMCalcPar* cpa = NULL;

	if (dbsplnr->tblplnramcalcpar->loadRecByCalCliCatPrp(refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, &cpa)) {
		val = atof(cpa->Val.c_str());

		delete cpa;
		return true;
	};

	return false;
};

bool Plnr::loadStringCpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, string& val
		) {
	PlnrAMCalcPar* cpa = NULL;

	if (dbsplnr->tblplnramcalcpar->loadRecByCalCliCatPrp(refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, &cpa)) {
		val = cpa->Val;

		delete cpa;
		return true;
	};

	return false;
};

ubigint Plnr::findMat(
			DbsPlnr* dbsplnr
			, const string& hsref
		) {
	vector<string> srefs;
	ubigint ref = 0;

	StrMod::stringToVector(hsref, srefs);
	for (unsigned int i=0;i<srefs.size();i++) dbsplnr->tblplnrmmaterial->loadRefBySupSrf(ref, srefs[i], ref);

	return ref;
};

void Plnr::setMpa(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMMaterial
			, const ubigint x1RefPlnrMDesign
			, const string& x2SrefKCat
			, const string& x3SrefKProp
			, const string& Val
		) {
	PlnrAMMaterialPar* mpa = NULL;

	mpa = new PlnrAMMaterialPar(0, refPlnrMMaterial, x1RefPlnrMDesign, x2SrefKCat, x3SrefKProp, 0, Val, "");
	dbsplnr->tblplnrammaterialpar->insertRec(mpa);

	delete mpa;
};

bool Plnr::findMpa(
			DbsPlnr* dbsplnr
			, const ubigint refMat
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const string& srefCat
			, const string& srefProp
			, PlnrAMMaterialPar** mpa
		) {
	bool retval = false;

	ubigint ref;

	// first try: material, modified design specific
	if (refModdsn != 0) {
		retval = dbsplnr->tblplnrammaterialpar->loadRecBySQL("SELECT * FROM TblPlnrAMMaterialPar WHERE refPlnrMMaterial = " + to_string(refMat) + " AND x1RefPlnrMDesign = "
					+ to_string(refModdsn) + " AND x2SrefKCat = '" + srefCat + "' AND x3SrefKProp = '" + srefProp + "'", mpa);
	};

	// second try: material, base design specific
	if (!retval) {
		retval = dbsplnr->tblplnrammaterialpar->loadRecBySQL("SELECT * FROM TblPlnrAMMaterialPar WHERE refPlnrMMaterial = " + to_string(refMat) + " AND x1RefPlnrMDesign = "
					+ to_string(refBasedsn) + " AND x2SrefKCat = '" + srefCat + "' AND x3SrefKProp = '" + srefProp + "'", mpa);
	};

	if (!retval) {
		// third try: material, general
		retval = dbsplnr->tblplnrammaterialpar->loadRecBySQL("SELECT * FROM TblPlnrAMMaterialPar WHERE refPlnrMMaterial = " + to_string(refMat) + " AND x1RefPlnrMDesign = 0 AND x2SrefKCat = '"
					+ srefCat + "' AND x3SrefKProp = '" + srefProp + "'", mpa);
	};

	if (!retval) {
		// forth try: sup material, recursive
		retval = dbsplnr->tblplnrmmaterial->loadSupByRef(refMat, ref);
		if (retval) retval = findMpa(dbsplnr, ref, refBasedsn, refModdsn, srefCat, srefProp, mpa);
	};

	return retval;
};

void Plnr::getDeviceExp(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMDevice
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const vector<ubigint>& refsSubdev
			, const bool init
			, ListPlnrMVertex& vtxs
			, vector<bool>& vtxacts
			, ListPlnrMLineguide& lgs
			, vector<bool>& lgacts
			, ListPlnrMArcguide& ags
			, vector<bool>& agacts
			, ListPlnrMStructure& srus
			, vector<unsigned int>& srufceics0
			, vector<unsigned int>& srufceics1
			, ListPlnrMFace& fces
			, vector<bool>& fceacts
		) {
	vector<ubigint> refs;

	PlnrJMDeviceModtype* djm = NULL;
	uint ixVModtype = VecPlnrVMDeviceModtype::VOID;

	ubigint refSubdev;

	PlnrMVertex* vtx = NULL;

	ListPlnrJMVertex vtxjs;
	PlnrJMVertex* vtxj = NULL;

	ListPlnrDevOMDeviceMVertex vtxos;
	PlnrDevOMDeviceMVertex* vtxo = NULL;

	PlnrMLineguide* lg = NULL;

	ListPlnrDevOMDeviceMLineguide lgos;
	PlnrDevOMDeviceMLineguide* lgo = NULL;

	PlnrMArcguide* ag = NULL;

	ListPlnrJMArcguideR agjs;
	PlnrJMArcguideR* agj = NULL;

	ListPlnrDevOMDeviceMArcguide agos;
	PlnrDevOMDeviceMArcguide* ago = NULL;

	PlnrMStructure* sru = NULL;

	PlnrMFace* fce = NULL;

	ListPlnrOMStructureMFace strfceos;
	PlnrOMStructureMFace* strfceo = NULL;

	// -- determine modification type
	if (init && (refModdsn != 0)) {
		if (dbsplnr->tblplnrjmdevicemodtype->loadRecBySQL("SELECT * FROM TblPlnrJMDeviceModtype WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign = " + to_string(refModdsn), &djm)) {
			ixVModtype = djm->ixVModtype;
			delete djm;
		};
	};

	// -- reset lists and vectors
	if (init) {
		vtxs.clear();
		vtxacts.resize(0);

		lgs.clear();
		lgacts.resize(0);

		ags.clear();
		agacts.resize(0);

		srus.clear();
		srufceics0.resize(0);
		srufceics1.resize(0);

		fces.clear();
		fceacts.resize(0);
	};

	// -- vertices
	if (init) {
		// - load and apply design modifications
		if (refModdsn == 0) {
			dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, false, vtxs);

		} else {
			if (ixVModtype == VecPlnrVMDeviceModtype::VTXGDFCE) {
				// different set of vertices for modified design
				dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(refModdsn, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, false, vtxs);

			} else {
				// baseline set of vertices, potentially with modified coordinates: NOTO or FCE possible
				dbsplnr->tblplnrmvertex->loadRstByDsnHktHku(0, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, false, vtxs);

				dbsplnr->loadRefsBySQL("SELECT TblPlnrJMVertex.ref FROM TblPlnrJMVertex, TblPlnrMVertex WHERE TblPlnrJMVertex.refPlnrMVertex = TblPlnrMVertex.ref AND TblPlnrJMVertex.x1RefPlnrMDesign = "
							+ to_string(refModdsn) + " AND TblPlnrMVertex.hkIxVTbl = " + to_string(VecPlnrVMVertexHkTbl::DEV) + " AND TblPlnrMVertex.hkUref = "
							+ to_string(refPlnrMDevice), false, refs);
				dbsplnr->tblplnrjmvertex->loadRstByRefs(refs, false, vtxjs);

				for (unsigned int j=0;j<vtxjs.nodes.size();j++) {
					vtxj = vtxjs.nodes[j];

					for (unsigned int k=0;k<vtxs.nodes.size();k++) {
						vtx = vtxs.nodes[k];

						if (vtx->ref == vtxj->refPlnrMVertex) {
							vtx->x = vtxj->x;
							vtx->y = vtxj->y;

							break;
						};
					};
				};
			};
		};

		vtxacts.resize(vtxs.nodes.size());
	};

	// - initial operator functionality
	for (unsigned int j=0;j<vtxs.nodes.size();j++) vtxacts[j] = (vtxs.nodes[j]->hkIxPlnrVLat == VecPlnrVLat::INI);

	// - apply sub-device modifications
	for (unsigned int j=0;j<refsSubdev.size();j++) {
		refSubdev = refsSubdev[j];

		dbsplnr->tblplnrdevomdevicemvertex->loadRstByDevDv2(refPlnrMDevice, refSubdev, false, vtxos);
		for (unsigned int k=0;k<vtxos.nodes.size();k++) {
			vtxo = vtxos.nodes[k];

			for (unsigned int l=0;l<vtxs.nodes.size();l++) {
				vtx = vtxs.nodes[l];

				if (vtx->ref == vtxo->pr1RefM) {
					if (vtxo->ixPlnrVLop == VecPlnrVLop::INS) vtxacts[l] = true;
					else if (vtxo->ixPlnrVLop == VecPlnrVLop::RMV) vtxacts[l] = false;

					break;
				};
			};
		};
	};

	// -- lineguides

	if (init) {
		// - load and apply design modifications
		if (refModdsn == 0) {
			dbsplnr->tblplnrmlineguide->loadRstByDsnHktHku(0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, false, lgs);

		} else {
			if (ixVModtype == VecPlnrVMDeviceModtype::VTXGDFCE) {
				// different set of lineguides for modified design
				dbsplnr->tblplnrmlineguide->loadRstByDsnHktHku(refModdsn, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, false, lgs);

			} else {
				// baseline set of lineguides
				dbsplnr->tblplnrmlineguide->loadRstByDsnHktHku(0, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, false, lgs);
			};
		};

		lgacts.resize(lgs.nodes.size());
	};

	// initial operator functionality
	for (unsigned int j=0;j<lgs.nodes.size();j++) lgacts[j] = (lgs.nodes[j]->hkIxPlnrVLat == VecPlnrVLat::INI);

	// - apply sub-device modifications
	for (unsigned int j=0;j<refsSubdev.size();j++) {
		refSubdev = refsSubdev[j];

		dbsplnr->tblplnrdevomdevicemlineguide->loadRstByDevDv2(refPlnrMDevice, refSubdev, false, lgos);
		for (unsigned int k=0;k<lgos.nodes.size();k++) {
			lgo = lgos.nodes[k];

			for (unsigned int l=0;l<lgs.nodes.size();l++) {
				lg = lgs.nodes[l];

				if (lg->ref == lgo->pr1RefM) {
					if (lgo->ixPlnrVLop == VecPlnrVLop::INS) lgacts[l] = true;
					else if (lgo->ixPlnrVLop == VecPlnrVLop::RMV) lgacts[l] = false;

					break;
				};
			};
		};
	};

	// -- arcguides

	if (init) {
		// - load and apply design modifications
		if (refModdsn == 0) {
			dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, false, ags);

		} else {
			if (ixVModtype == VecPlnrVMDeviceModtype::VTXGDFCE) {
				// different set of arcguides for modified design
				dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(refModdsn, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, false, ags);

			} else {
				// baseline set of arcguides, potentially with modified radii: NOTO or FCE possible
				dbsplnr->tblplnrmarcguide->loadRstByDsnHktHku(0, VecPlnrVMArcguideHkTbl::DEV, refPlnrMDevice, false, ags);

				dbsplnr->loadRefsBySQL("SELECT TblPlnrJMArcguideR.ref FROM TblPlnrJMArcguideR, TblPlnrMArcguide WHERE TblPlnrJMArcguideR.refPlnrMArcguide = TblPlnrMArcguide.ref AND TblPlnrJMArcguideR.x1RefPlnrMDesign = "
							+ to_string(refModdsn) + " AND TblPlnrMArcguide.hkIxVTbl = " + to_string(VecPlnrVMArcguideHkTbl::DEV) + " AND TblPlnrMArcguide.hkUref = "
							+ to_string(refPlnrMDevice), false, refs);
				dbsplnr->tblplnrjmarcguider->loadRstByRefs(refs, false, agjs);

				for (unsigned int j=0;j<agjs.nodes.size();j++) {
					agj = agjs.nodes[j];

					for (unsigned int k=0;k<ags.nodes.size();k++) {
						ag = ags.nodes[k];

						if (ag->ref == agj->refPlnrMArcguide) {
							ag->r = agj->r;

							break;
						};
					};
				};
			};
		};

		agacts.resize(ags.nodes.size());
	};

	// initial operator functionality
	for (unsigned int j=0;j<ags.nodes.size();j++) agacts[j] = (ags.nodes[j]->hkIxPlnrVLat == VecPlnrVLat::INI);

	// - apply sub-device modifications
	for (unsigned int j=0;j<refsSubdev.size();j++) {
		refSubdev = refsSubdev[j];

		dbsplnr->tblplnrdevomdevicemarcguide->loadRstByDevDv2(refPlnrMDevice, refSubdev, false, agos);
		for (unsigned int k=0;k<agos.nodes.size();k++) {
			ago = agos.nodes[k];

			for (unsigned int l=0;l<ags.nodes.size();l++) {
				ag = ags.nodes[l];

				if (ag->ref == ago->pr1RefM) {
					if (ago->ixPlnrVLop == VecPlnrVLop::INS) agacts[l] = true;
					else if (ago->ixPlnrVLop == VecPlnrVLop::RMV) agacts[l] = false;

					break;
				};
			};
		};
	};

	// -- structures and faces
	if (init) {
		dbsplnr->tblplnrmstructure->loadRstByHktHku(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, false, srus);
		
		srufceics0.resize(srus.nodes.size());
		srufceics1.resize(srus.nodes.size());
	};

	if (init) {
		for (unsigned int j=0;j<srus.nodes.size();j++) {
			sru = srus.nodes[j];

			// - load faces and apply design modifications
			srufceics0[j] = fces.nodes.size();

			if (refModdsn == 0) {
				dbsplnr->tblplnrmface->loadRstByDsnSru(0, sru->ref, true, fces);

			} else {
				if ((ixVModtype == VecPlnrVMDeviceModtype::VTXGDFCE) || (ixVModtype == VecPlnrVMDeviceModtype::FCE)) {
					// different set of faces for modified design
					dbsplnr->tblplnrmface->loadRstByDsnSru(refModdsn, sru->ref, true, fces);

				} else {
					// baseline set of faces
					dbsplnr->tblplnrmface->loadRstByDsnSru(0, sru->ref, true, fces);
				};
			};

			srufceics1[j] = fces.nodes.size();
		};

		fceacts.resize(fces.nodes.size());
	};

	// initial operator functionality
	for (unsigned int k=0;k<fces.nodes.size();k++) fceacts[k] = (fces.nodes[k]->sruIxPlnrVLat == VecPlnrVLat::INI);

	// - apply sub-device modifications
	for (unsigned int k=0;k<refsSubdev.size();k++) {
		refSubdev = refsSubdev[k];

		for (unsigned int j=0;j<srus.nodes.size();j++) {
			sru = srus.nodes[j];

			dbsplnr->tblplnromstructuremface->loadRstBySruDev(sru->ref, refSubdev, false, strfceos);
			for (unsigned int l=0;l<strfceos.nodes.size();l++) {
				strfceo = strfceos.nodes[l];

				for (unsigned int m=0;m<fces.nodes.size();m++) {
					fce = fces.nodes[m];

					if (fce->ref == strfceo->pr1RefM) {
						if (strfceo->ixPlnrVLop == VecPlnrVLop::INS) fceacts[m] = true;
						else if (strfceo->ixPlnrVLop == VecPlnrVLop::RMV) fceacts[m] = false;

						break;
					};
				};
			};
		};
	};
};

void Plnr::getLrvExp(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMLineguide
			, const vector<ubigint>& refsSubdev
			, const bool init
			, ListPlnrLRMLineguideMVertex& lrvs
			, vector<bool>& lrvacts
		) {
	ubigint refSubdev;

	PlnrLRMLineguideMVertex* lrv = NULL;

	ListPlnrDevORMLineguideMVertex lrvos;
	PlnrDevORMLineguideMVertex* lrvo = NULL;

	if (init) {
		dbsplnr->tblplnrlrmlineguidemvertex->loadRstByLgd(refPlnrMLineguide, false, lrvs);

		lrvacts.resize(lrvs.nodes.size());
	};

	// initial operator functionality
	for (unsigned int k=0;k<lrvs.nodes.size();k++) lrvacts[k] = (lrvs.nodes[k]->lgdIxPlnrVLat == VecPlnrVLat::INI);

	// apply sub-device modifications
	for (unsigned int k=0;k<refsSubdev.size();k++) {
		refSubdev = refsSubdev[k];

		dbsplnr->tblplnrdevormlineguidemvertex->loadRstByLgdDev(refPlnrMLineguide, refSubdev, false, lrvos);
		for (unsigned int l=0;l<lrvos.nodes.size();l++) {
			lrvo = lrvos.nodes[l];

			for (unsigned int m=0;m<lrvs.nodes.size();m++) {
				lrv = lrvs.nodes[m];

				if (lrv->ref == lrvo->pr1RefLR) {
					if (lrvo->ixPlnrVLop == VecPlnrVLop::INS) lrvacts[m] = true;
					else if (lrvo->ixPlnrVLop == VecPlnrVLop::RMV) lrvacts[m] = false;
					break;
				};
			};
		};
	};
};

void Plnr::getArvExp(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMArcguide
			, const vector<ubigint>& refsSubdev
			, const bool init
			, ListPlnrLRMArcguideMVertex& arvs
			, vector<bool>& arvacts
		) {
	ubigint refSubdev;

	PlnrLRMArcguideMVertex* arv = NULL;

	ListPlnrDevORMArcguideMVertex arvos;
	PlnrDevORMArcguideMVertex* arvo = NULL;

	if (init) {
		dbsplnr->tblplnrlrmarcguidemvertex->loadRstByAgd(refPlnrMArcguide, false, arvs);

		arvacts.resize(arvs.nodes.size());
	};

	// initial operator functionality
	for (unsigned int k=0;k<arvs.nodes.size();k++) arvacts[k] = (arvs.nodes[k]->agdIxPlnrVLat == VecPlnrVLat::INI);

	// apply sub-device modifications
	for (unsigned int k=0;k<refsSubdev.size();k++) {
		refSubdev = refsSubdev[k];

		dbsplnr->tblplnrdevormarcguidemvertex->loadRstByAgdDev(refPlnrMArcguide, refSubdev, false, arvos);
		for (unsigned int l=0;l<arvos.nodes.size();l++) {
			arvo = arvos.nodes[l];

			for (unsigned int m=0;m<arvs.nodes.size();m++) {
				arv = arvs.nodes[m];

				if (arv->ref == arvo->pr1RefLR) {
					if (arvo->ixPlnrVLop == VecPlnrVLop::INS) arvacts[m] = true;
					else if (arvo->ixPlnrVLop == VecPlnrVLop::RMV) arvacts[m] = false;
					break;
				};
			};
		};
	};
};

void Plnr::getStackExp(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMStack
			, const ubigint refBasedsn
			, const ubigint refModdsn
			, const bool init
			, ListPlnrMLevel& lvls
			, ListPlnrMLayer& lyrs
		) {
	vector<ubigint> refs;

	PlnrJMStackModtype* sjm = NULL;
	uint ixVModtype = VecPlnrVMStackModtype::VOID;

	PlnrMLevel* lvl = NULL;

	ListPlnrJMLevelZ lvljs;
	PlnrJMLevelZ* lvlj = NULL;

	// -- determine modification type
	if (refModdsn != 0) {
		if (dbsplnr->tblplnrjmstackmodtype->loadRecBySQL("SELECT * FROM TblPlnrJMStackModtype WHERE refPlnrMStack = " + to_string(refPlnrMStack) + " AND x1RefPlnrMDesign = "
					+ to_string(refModdsn), &sjm)) {
			ixVModtype = sjm->ixVModtype;
			delete sjm;
		};
	};

	// -- load stack layers (reg only)
	if (refModdsn == 0) {
		dbsplnr->tblplnrmlayer->loadRstByDsnTypHktHku(0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refPlnrMStack, false, lyrs);

	} else {
		if (ixVModtype == VecPlnrVMStackModtype::LYR) {
			// different set of layers
			dbsplnr->tblplnrmlayer->loadRstByDsnTypHktHku(refModdsn, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refPlnrMStack, false, lyrs);

		} else {
			// baseline set of layers
			dbsplnr->tblplnrmlayer->loadRstByDsnTypHktHku(0, VecPlnrVMLayerBasetype::REG, VecPlnrVMLayerHkTbl::STK, refPlnrMStack, false, lyrs);
		};
	};

	// -- load stack levels
	if (refModdsn == 0) {
		dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, false, lvls);

	} else {
		if (ixVModtype == VecPlnrVMStackModtype::LYR) {
			// different set of levels for modified design
			dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(refModdsn, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, false, lvls);

		} else {
			// baseline set of levels, potentially with modified z: only for NOLN
			dbsplnr->tblplnrmlevel->loadRstByDsnHktHku(0, VecPlnrVMLevelHkTbl::STK, refPlnrMStack, false, lvls);

			if (ixVModtype == VecPlnrVMStackModtype::NOLN) {
				dbsplnr->loadRefsBySQL("SELECT TblPlnrJMLevelZ.ref FROM TblPlnrJMLevelZ, TblPlnrMLevel WHERE TblPlnrJMLevelZ.refPlnrMLevel = TblPlnrMLevel.ref AND TblPlnrJMLevelZ.x1RefPlnrMDesign = "
							+ to_string(refModdsn) + " AND TblPlnrMLevel.hkIxVTbl = " + to_string(VecPlnrVMLevelHkTbl::STK) + " AND TblPlnrMLevel.hkUref = " + to_string(refPlnrMStack), false, refs);
				dbsplnr->tblplnrjmlevelz->loadRstByRefs(refs, false, lvljs);

				for (unsigned int j=0;j<lvljs.nodes.size();j++) {
					lvlj = lvljs.nodes[j];
				
					for (unsigned int k=0;k<lvls.nodes.size();k++) {
						lvl = lvls.nodes[k];

						if (lvl->ref == lvlj->refPlnrMLevel) {
							lvl->z = lvlj->z;

							break;
						};
					};
				};
			};
		};
	};
};

void Plnr::createAris(
			DbsPlnr* dbsplnr
			, PlnrMArray* arr
			, ListPlnrMArrayitem& aris
		) {
	double dx, dy;

	aris.clear();

	PlnrMArrayitem* ari = NULL;

	if ((arr->K == 0) || (arr->L == 0)) {
		for (usmallint i=0;i<arr->I;i++) {
			for (usmallint j=0;j<arr->J;j++) {
				dx = j*arr->dj;
				dy = i*arr->di;

				ari = new PlnrMArrayitem(0, arr->ref, arr->refPlnrMDesign, i, j, 0, 0, 0, 0, dx, dy);
				dbsplnr->tblplnrmarrayitem->insertRec(ari); aris.nodes.push_back(ari);
			};
		};

	} else if ((arr->M == 0) || (arr->N == 0)) {
		for (usmallint i=0;i<arr->I;i++) {
			for (usmallint j=0;j<arr->J;j++) {
				for (usmallint k=0;k<arr->K;k++) {
					for (usmallint l=0;l<arr->L;l++) {
						dx = j*arr->dj + l*arr->dl;
						dy = i*arr->di + k*arr->dk;

						ari = new PlnrMArrayitem(0, arr->ref, arr->refPlnrMDesign, i, j, k, l, 0, 0, dx, dy);
						dbsplnr->tblplnrmarrayitem->insertRec(ari); aris.nodes.push_back(ari);
					};
				};
			};
		};

	} else {
		for (usmallint i=0;i<arr->I;i++) {
			for (usmallint j=0;j<arr->J;j++) {
				for (usmallint k=0;k<arr->K;k++) {
					for (usmallint l=0;l<arr->L;l++) {
						for (usmallint m=0;m<arr->M;m++) {
							for (usmallint n=0;n<arr->N;n++) {
								dx = j*arr->dj + l*arr->dl + n*arr->dn;
								dy = i*arr->di + k*arr->dk + m*arr->dm;

								ari = new PlnrMArrayitem(0, arr->ref, arr->refPlnrMDesign, i, j, k, l, m, n, dx, dy);
								dbsplnr->tblplnrmarrayitem->insertRec(ari); aris.nodes.push_back(ari);
							};
						};
					};
				};
			};
		};
	};
};

void Plnr::addArrenv(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMArray
			, const ubigint x1RefPlnrMArrayitem
			, const string& x2SrefKKey
			, const double Val
		) {
	addArrenv(dbsplnr, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, to_string(Val));
};

void Plnr::addArrenv(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMArray
			, const ubigint x1RefPlnrMArrayitem
			, const string& x2SrefKKey
			, const string& Val
		) {
	PlnrAMArrayEnv* aen = NULL;

	aen = new PlnrAMArrayEnv(0, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val);
	dbsplnr->tblplnramarrayenv->insertRec(aen);

	delete aen;
};

void Plnr::createArrrtcs(
			DbsPlnr* dbsplnr
			, const ubigint refPlnrMArray
		) {
	string s;

	PlnrMArray* arr = NULL;

	ListPlnrMArrayitem aris;
	PlnrMArrayitem* ari = NULL;

	ListPlnrMReticle tplrtcs;
	PlnrMReticle* tplrtc = NULL;

	ListPlnrMReticle rtcs;
	PlnrMReticle* rtc = NULL;

	double x0, y0;

	dbsplnr->tblplnrmarray->loadRecByRef(refPlnrMArray, &arr);

	// load template reticles and array items
	dbsplnr->tblplnrmreticle->loadRstByHktHku(VecPlnrVMReticleHkTbl::ARR, refPlnrMArray, false, tplrtcs);
	dbsplnr->tblplnrmarrayitem->loadRstByArr(arr->ref, false, aris);

	// one reticle for each template reticle and array item
	for (unsigned int i=0;i<tplrtcs.nodes.size();i++) {
		tplrtc = tplrtcs.nodes[i];

		for (unsigned int j=0;j<aris.nodes.size();j++) {
			ari = aris.nodes[j];

			s = arr->sref + "." + getAriSref(arr, ari) + "." + tplrtc->sref;

			// apply rotation to offset
			x0 = tplrtc->x0 + cos(degToRad(tplrtc->phi))*ari->dx - sin(degToRad(tplrtc->phi))*ari->dy;
			y0 = tplrtc->y0 + sin(degToRad(tplrtc->phi))*ari->dx + cos(degToRad(tplrtc->phi))*ari->dy;

			rtc = new PlnrMReticle(0, VecPlnrVMReticleHkTbl::TPO, arr->refPlnrMTapeout, ari->refPlnrMDesign, tplrtc->refPlnrMLayer, s, x0, y0, tplrtc->phi);
			dbsplnr->tblplnrmreticle->insertRec(rtc); rtcs.nodes.push_back(rtc);
		};
	};

	delete arr;
};

string Plnr::getAriSref(
			PlnrMArray* arr
			, PlnrMArrayitem* ari
		) {
	string retval;

	if ((arr->K == 0) || (arr->L == 0)) {
		retval = "i" + to_string(ari->i) + "j" + to_string(ari->j);
	} else if ((arr->M == 0) || (arr->N == 0)) {
		retval = "i" + to_string(ari->i) + "j" + to_string(ari->j) + "k" + to_string(ari->k) + "l" + to_string(ari->l);
	} else {
		retval = "i" + to_string(ari->i) + "j" + to_string(ari->j) + "k" + to_string(ari->k) + "l" + to_string(ari->l) + "m" + to_string(ari->m) + "n" + to_string(ari->n);
	};

	return retval;
};

void Plnr::createModdsns(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMArray
			, vector<ubigint>& refsModdsn
		) {
	vector<ubigint> refs;

	map<string, string> env;
	Mpa mpacache;

	PlnrMDesign* basedsn = NULL;

	PlnrMDesign* moddsn = NULL;

	ListPlnrMCalcitem clis;
	PlnrMCalcitem* cli = NULL;

	ListPlnrMArrayitem aris;
	PlnrMArrayitem* ari = NULL;

	ListPlnrAMDevicePar dpas;
	PlnrAMDevicePar* dpa = NULL;

	ListPlnrMLayer lyrs;
	PlnrMLayer* lyr = NULL;

	ListPlnrMStack stks;
	PlnrMStack* stk = NULL;

	ListPlnrMDomaingd dgds;
	PlnrMDomaingd* dgd = NULL;

	ListPlnrAMMaterialPar mpas;
	PlnrAMMaterialPar* mpa = NULL;
	ListPlnrAMMaterialPar mpas2;
	PlnrAMMaterialPar* mpa2 = NULL;

	ListPlnrMDomain doms;
	PlnrMDomain* dom = NULL;

	unsigned int N;
	string s, s2, s3, s4;
	bool found;

	refsModdsn.resize(0);

	// load base design and items
	if (refPlnrMCalc != 0) {
		dbsplnr->tblplnrmdesign->loadRecByRetReu(VecPlnrVMDesignRefTbl::CAL, refPlnrMCalc, &basedsn);

		dbsplnr->tblplnrmcalcitem->loadRstByCal(refPlnrMCalc, false, clis);
		N = clis.nodes.size();

	} else {
		dbsplnr->tblplnrmdesign->loadRecByRetReu(VecPlnrVMDesignRefTbl::ARR, refPlnrMArray, &basedsn);

		dbsplnr->tblplnrmarrayitem->loadRstByArr(refPlnrMArray, false, aris);
		N = aris.nodes.size();
	};

	// --- find env dependencies of base design
	if (basedsn->ixWModtype != 0) {

		if (basedsn->ixWModtype & (VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO)) {
			// -- check for env dependencies in TblPlnrAMDevicePar, devices and sub-devices of base design
			dbsplnr->loadRefsBySQL("SELECT TblPlnrAMDevicePar.ref FROM TblPlnrAMDevicePar, TblPlnrMDevice WHERE TblPlnrAMDevicePar.refPlnrMDevice = TblPlnrMDevice.ref AND TblPlnrMDevice.dsnRefPlnrMDesign = "
						+ to_string(basedsn->ref) + " AND TblPlnrAMDevicePar.Val LIKE '%env.%'", false, refs);
			dbsplnr->tblplnramdevicepar->loadRstByRefs(refs, false, dpas);
		};

		if (basedsn->ixWModtype & VecPlnrWMDesignModtype::SNOLN) {
			// -- check for env dependencies in TblPlnrMLayer(TblPlnrJMLayer), stacks/layers of base design
			// skip ML for now
			dbsplnr->loadRefsBySQL("SELECT TblPlnrMLayer.ref FROM TblPlnrMLayer, TblPlnrMStack WHERE TblPlnrMLayer.hkIxVTbl = " + to_string(VecPlnrVMLayerHkTbl::STK)
						+ " AND TblPlnrMLayer.hkUref = TblPlnrMStack.ref AND dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND TblPlnrMLayer.t LIKE '%env.%'", false, refs);
			dbsplnr->tblplnrmlayer->loadRstByRefs(refs, false, lyrs);
		};

		if (basedsn->ixWModtype & VecPlnrWMDesignModtype::SLN) {
			// -- check for env dependencies in TblPlnrMStack(TblPlnrJMStackN), stacks of base design
			dbsplnr->tblplnrmstack->loadRstBySQL("SELECT * FROM TblPlnrMStack WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND N LIKE '%env.%'", false, stks);
		};

		if (basedsn->ixWModtype & VecPlnrWMDesignModtype::MLT) {
			// -- check for env dependencies in TblPlnrAMMaterialPar(TblPlnrAMMaterialPar), materials used for layers of base design with ML thickness statement
			// skip for now
		};

		if (basedsn->ixWModtype & (VecPlnrWMDesignModtype::DOMXY + VecPlnrWMDesignModtype::DOMZ)) {
			// -- check for env dependencies in TblPlnrMDomaingd(TblPlnrJMDomaingd), domain guides of base design
			// profit from the fact that for none of the dgd types both d and dphi are needed
			dbsplnr->tblplnrmdomaingd->loadRstBySQL("SELECT * FROM TblPlnrMDomaingd WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND d LIKE '%env.%'", false, dgds);
			dbsplnr->tblplnrmdomaingd->loadRstBySQL("SELECT * FROM TblPlnrMDomaingd WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND dphi LIKE '%env.%'", true, dgds);
		};

		if (basedsn->ixWModtype & VecPlnrWMDesignModtype::MVAR) {
			// -- check for env dependencies in TblPlnrAMMaterialPar, material parameters that have specific entries for the base design
			// mpa using env can be hidden in the material hierarchy and e.g. lintbl(env.%, ...) can occur
			dbsplnr->tblplnrammaterialpar->loadRstBySQL("SELECT * FROM TblPlnrAMMaterialPar WHERE x1RefPlnrMDesign = " + to_string(basedsn->ref), false, mpas2);

			for (unsigned int i=0;i<mpas2.nodes.size();i++) {
				mpa2 = mpas2.nodes[i];

				if (Plnr::findMpa(dbsplnr, mpa2->refPlnrMMaterial, basedsn->ref, 0, mpa2->x2SrefKCat, mpa2->x3SrefKProp, &mpa)) {
					// possibly finds itself
					if (mpa->Val.find("env.") != string::npos) {
						found = false;
						for (unsigned int j=0;j<mpas.nodes.size();j++) {
							if (mpas.nodes[j]->ref == mpa->ref) {
								found = true;
								break;
							};
						};

						if (found) {
							delete mpa;
						} else {
							mpas.nodes.push_back(mpa);
						};

					} else {
						delete mpa;
					};
				};
			};
		};

		if (basedsn->ixWModtype & VecPlnrWMDesignModtype::GRID) {
			// -- check for env dependencies in TblPlnrMDomain(TblPlnrJMDomain), domain grid
			dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDomain WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND dx LIKE '%env.%'", false, refs);
			dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDomain WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND dy LIKE '%env.%'", true, refs);
			dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDomain WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND dxy LIKE '%env.%'", true, refs);
			dbsplnr->loadRefsBySQL("SELECT ref FROM TblPlnrMDomain WHERE dsnRefPlnrMDesign = " + to_string(basedsn->ref) + " AND dz LIKE '%env.%'", true, refs);

			for (unsigned int i=0;i<refs.size();i++) {
				for (unsigned int j=i+1;j<refs.size();j++) {
					if (refs[j] == refs[i]) refs[j] = 0;
				};
			};

			for (unsigned int i=0;i<refs.size();i++) {
				if (refs[i] == 0) {
					for (unsigned int j=i+1;j<refs.size();j++) {
						if (refs[j] != 0) {
							refs[i] = refs[j];
							refs[j] = 0;
							break;
						};
					};
				};
			};

			for (unsigned int i=1;i<refs.size();i++) {
				if (refs[i] == 0) {
					refs.resize(i);
					break;
				};
			};

			dbsplnr->tblplnrmdomain->loadRstByRefs(refs, false, doms);
		};
	};

	// --- match with item-specific env's
	if (basedsn->ixWModtype != 0) {
		for (unsigned int i=0;i<N;i++) {
			// -- generate modified design and cross-link
			moddsn = new PlnrMDesign(*basedsn);
			moddsn->ref = 0;

			moddsn->modRefPlnrMDesign = basedsn->ref;
			moddsn->drvRefPlnrMDesign = 0;

			if (refPlnrMCalc != 0) {
				cli = clis.nodes[i];

				moddsn->refIxVTbl = VecPlnrVMDesignRefTbl::CLI;
				moddsn->refUref = cli->ref;

				dbsplnr->tblplnrmdesign->insertRec(moddsn);
				refsModdsn.push_back(moddsn->ref);

				cli->refPlnrMDesign = moddsn->ref;
				dbsplnr->tblplnrmcalcitem->updateRec(cli);

			} else {
				ari = aris.nodes[i];

				moddsn->refIxVTbl = VecPlnrVMDesignRefTbl::ARI;
				moddsn->refUref = ari->ref;

				dbsplnr->tblplnrmdesign->insertRec(moddsn);
				refsModdsn.push_back(moddsn->ref);

				ari->refPlnrMDesign = moddsn->ref;
				dbsplnr->tblplnrmarrayitem->updateRec(ari);
			};

			// -- fill env
			if (refPlnrMCalc != 0) {
				Env::setForCli(dbsplnr, env, refPlnrMCalc, cli->ref);
			} else if (refPlnrMArray != 0) {
				Env::setForAri(dbsplnr, env, refPlnrMArray, ari->ref);
			};

			// -- match with base design env dependencies and create corresponding database entries

			if (basedsn->ixWModtype & (VecPlnrWMDesignModtype::DNOTO + VecPlnrWMDesignModtype::DTO)) {
				// - check for match in TblPlnrAMDevicePar(TblPlnrAMDevicePar)
				for (unsigned int j=0;j<dpas.nodes.size();j++) {
					dpa = dpas.nodes[j];

					s = Fct::evalDevAparVal(env, dpa);

					dbsplnr->tblplnramdevicepar->insertNewRec(NULL, dpa->refPlnrMDevice, moddsn->ref, dpa->x2SrefKKey, dpa->refPlnrMFile, s);
				};
			};

			if (basedsn->ixWModtype & VecPlnrWMDesignModtype::SNOLN) {
				// - check for match in TblPlnrMLayer(TblPlnrJMLayer)
				for (unsigned int j=0;j<lyrs.nodes.size();j++) {
					lyr = lyrs.nodes[j];

					s = Fct::evalLyrT(env, lyr);

					dbsplnr->tblplnrjmlayer->insertNewRec(NULL, lyr->ref, moddsn->ref, s, lyr->ML);
				};
			};

			if (basedsn->ixWModtype & VecPlnrWMDesignModtype::SLN) {
				// - check for match in TblPlnrMStack(TblPlnrJMStackN)
				for (unsigned int j=0;j<stks.nodes.size();j++) {
					stk = stks.nodes[j];

					s = Fct::evalStkN(env, stk);

					dbsplnr->tblplnrjmstackn->insertNewRec(NULL, stk->ref, moddsn->ref, s);
				};
			};

			if (basedsn->ixWModtype & VecPlnrWMDesignModtype::MLT) {
				// - check for match in TblPlnrAMMaterialPar(TblPlnrAMMaterialPar)
				// skip for now
			};

			if (basedsn->ixWModtype & (VecPlnrWMDesignModtype::DOMXY + VecPlnrWMDesignModtype::DOMZ)) {
				// - check for match in TblPlnrMDomaingd(TblPlnrJMDomaingd)
				for (unsigned int j=0;j<dgds.nodes.size();j++) {
					dgd = dgds.nodes[j];

					s = Fct::evalDgdD(env, dgd);
					s2 = Fct::evalDgdDph(env, dgd);

					dbsplnr->tblplnrjmdomaingd->insertNewRec(NULL, dgd->ref, moddsn->ref, s, s2);
				};
			};

			if (basedsn->ixWModtype & VecPlnrWMDesignModtype::MVAR) {
				// - check for match in TblPlnrAMMaterialPar
				for (unsigned int j=0;j<mpas.nodes.size();j++) {
					mpa = mpas.nodes[j];

					s = Fct::evalMatAparVal(dbsplnr, env, mpacache, acvpath, mpa, basedsn->ref, 0);

					dbsplnr->tblplnrammaterialpar->insertNewRec(NULL, mpa->refPlnrMMaterial, moddsn->ref, mpa->x2SrefKCat, mpa->x3SrefKProp, mpa->refPlnrMFile, s, mpa->Comment);
				};
			};

			if (basedsn->ixWModtype & VecPlnrWMDesignModtype::GRID) {
				// - check for match in TblPlnrMDomain(TblPlnrJMDomain)
				for (unsigned int j=0;j<doms.nodes.size();j++) {
					dom = doms.nodes[j];

					s = Fct::evalDomDx(env, dom);
					s2 = Fct::evalDomDy(env, dom);
					s3 = Fct::evalDomDxy(env, dom);
					s4 = Fct::evalDomDz(env, dom);

					dbsplnr->tblplnrjmdomain->insertNewRec(NULL, dom->ref, moddsn->ref, s, s2, s3, s4);
				};
			};

			delete moddsn;
		};
	};

	// clean up
	delete basedsn;
};

void Plnr::cellstopToXyofs(
			const double rast
			, const string& cellstop
			, double& xofs
			, double& yofs
		) {
	int m, n;

	crefToMn(cellstop, m, n);

	xofs = -0.5* ((double) n) * rast;
	yofs = -0.5* ((double) m) * rast;
};

void Plnr::crefToMn(
			const string& cref
			, int& m
			, int& n
		) {
	m = 0; // m = n = 0 corresponds to 'A1'
	n = 0;

	if (cref.size() == 2) {
		// assume 'A1'
		m = ((int) cref[1]) - 0x30 - 1;
		n = ((int) cref[0]) - 0x41;

	} else if (cref.size() == 3) {
		if ( ((int) cref[1]) >= 0x41 ) {
			// assume 'AB1'
			m = ((int) cref[2]) - 0x30 - 1;
			n = 26*(((int) cref[0]) - 0x41 + 1)  + (((int) cref[1]) - 0x41);

		} else {
			// assume 'A12'
			m = 10*(((int) cref[1]) - 0x30)  + (((int) cref[2]) - 0x30) - 1;
			n = ((int) cref[0]) - 0x41;
		};

	} else if (cref.size() == 4) {
		// assume 'AB12'
		m = 10*(((int) cref[2]) - 0x30)  + (((int) cref[3]) - 0x30) - 1;
		n = 26*(((int) cref[0]) - 0x41 + 1)  + (((int) cref[1]) - 0x41);
	};
};

void Plnr::crefToXy(
			const double rast
			, const double xofs
			, const double yofs
			, const string& cref
			, double& x
			, double& y
		) {
	int m, n;

	crefToMn(cref, m, n);

	x = xofs + ((double) n) * rast;
	y = yofs + ((double) m) * rast;
};

void Plnr::crefsToXyspan(
			const double rast
			, const double xofs
			, const double yofs
			, const string& crefSw
			, const string& crefNe
			, double& x
			, double& y
			, double& xsize
			, double& ysize
		) {
	int mSw, nSw, mNe, nNe;

	crefToMn(crefSw, mSw, nSw);
	crefToMn(crefNe, mNe, nNe);

	x = xofs + 0.5* ((double) (nSw+nNe)) * rast;
	y = yofs + 0.5* ((double) (mSw+mNe)) * rast;

	xsize = ((double) (abs(nSw-nNe) + 1)) * rast;
	ysize = ((double) (abs(mSw-mNe) + 1)) * rast;
};
// IP gbl --- IEND

/******************************************************************************
 namespace StubPlnr
 ******************************************************************************/

string StubPlnr::getStub(
			DbsPlnr* dbsplnr
			, const uint ixPlnrVStub
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	if (ixPlnrVStub == VecPlnrVStub::STUBPLNRAGDSTD) return getStubAgdStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRARISTD) return getStubAriStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRARRSTD) return getStubArrStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRBLKSTD) return getStubBlkStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRCALSTD) return getStubCalStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRCLCSTD) return getStubClcStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRCLISTD) return getStubCliStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRCTPSTD) return getStubCtpStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDEVSHORT) return getStubDevShort(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDEVSTD) return getStubDevStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDGDSTD) return getStubDgdStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDOMSHORT) return getStubDomShort(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDOMSTD) return getStubDomStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDSNSTD) return getStubDsnStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDTPSTD) return getStubDtpStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRDVCSTD) return getStubDvcStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRFCESTD) return getStubFceStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRFILSHORT) return getStubFilShort(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRFILSTD) return getStubFilStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRGRP) return getStubGrp(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRLGDSTD) return getStubLgdStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRLVLSTD) return getStubLvlStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRLYRSTD) return getStubLyrStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRMATSTD) return getStubMatStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNROWN) return getStubOwn(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRPRJSTD) return getStubPrjStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRPRSSTD) return getStubPrsStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRRTCSTD) return getStubRtcStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRSESMENU) return getStubSesMenu(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRSESSTD) return getStubSesStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRSRUSTD) return getStubSruStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRSTKSHORT) return getStubStkShort(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRSTKSTD) return getStubStkStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRTPOSTD) return getStubTpoStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRUSGSTD) return getStubUsgStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRUSRSTD) return getStubUsrStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixPlnrVStub == VecPlnrVStub::STUBPLNRVTXSTD) return getStubVtxStd(dbsplnr, ref, ixPlnrVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubPlnr::getStubAgdStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1.ag1'
	string stub;

	PlnrMArcguide* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRAGDSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no arc guide)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmarcguide->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubAgdStd --- IBEGIN
			if (rec->hkIxVTbl == VecPlnrVMArcguideHkTbl::DSN) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecPlnrVMArcguideHkTbl::DEV) {
				stub = getStubDevShort(dbsplnr, rec->hkUref, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
// IP getStubAgdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubAriStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'mosfets.i3j4'
	string stub;

	PlnrMArrayitem* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRARISTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no array item)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmarrayitem->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubAriStd --- IBEGIN
			stub = getStubArrStd(dbsplnr, rec->refPlnrMArray, ixPlnrVLocale, ixVNonetype, stcch, &stref) + ".i" + to_string(rec->i) + "j" + to_string(rec->j) + "k" + to_string(rec->k) + "l" + to_string(rec->l) + "m" + to_string(rec->m) +  "n" + to_string(rec->n);
// IP getStubAriStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubArrStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'mosfets'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRARRSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no array)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmarray->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubBlkStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1.main on litho.lyr1'
	string stub;

	PlnrMBlock* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRBLKSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no block)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmblock->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubBlkStd --- IBEGIN
			stub = getStubSruStd(dbsplnr, rec->refPlnrMStructure, ixPlnrVLocale, ixVNonetype, stcch, &stref) + " on " + getStubLyrStd(dbsplnr, rec->refPlnrMLayer, ixPlnrVLocale, ixVNonetype, stcch, &stref);
// IP getStubBlkStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubCalStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'MQW # scan - test 1'
	string stub;

	PlnrMCalc* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRCALSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no calculation)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmcalc->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubCalStd --- IBEGIN
			stub = rec->Title + ", t0=" + StrMod::timetToString(rec->start);
// IP getStubCalStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubClcStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'MQW # scan - test 1'
	string stub;

	PlnrMCalc* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRCLCSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no calculation)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmcalc->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubClcStd --- IBEGIN
			stub = rec->Title + ", t0=" + StrMod::timetToString(rec->start);
// IP getStubClcStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubCliStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'MQW # scan - test 1 (5/23)'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRCLISTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no calculation item)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmcalcitem->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubCtpStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'MQW # scan'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRCTPSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no calculation template)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmcalc->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubDevShort(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRDEVSHORT, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no device)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdevice->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubDevStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1 (wgtap)'
	string stub;

	PlnrMDevice* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRDEVSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no device)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdevice->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubDevStd --- IBEGIN
			stub = rec->sref;
			if (rec->tplRefPlnrMDevice != 0) stub += " (" + getStubDtpStd(dbsplnr, rec->tplRefPlnrMDevice, ixPlnrVLocale) + ")";
// IP getStubDevStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubDgdStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'dg1 (lgvtx)'
	string stub;

	PlnrMDomaingd* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRDGDSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no domain guide)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdomaingd->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubDgdStd --- IBEGIN
			stub = rec->sref + " (" + VecPlnrVMDomaingdBasetype::getSref(rec->ixVBasetype) + ")";
// IP getStubDgdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubDomShort(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'dom'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRDOMSHORT, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no domain)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdomain->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubDomStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'dom (cub_xyz)'
	string stub;

	PlnrMDomain* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRDOMSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no domain)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdomain->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubDomStd --- IBEGIN
			stub = rec->sref + " (" + VecPlnrVMDomainBasetype::getSref(rec->ixVBasetype) + ")";
// IP getStubDomStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubDsnStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'AlN buffer layers with embedded GaN quantum wells'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRDSNSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no design)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdesign->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubDtpStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'wgtap'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRDTPSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no device template)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdevice->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubDvcStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1 (wgtap)'
	string stub;

	PlnrMDevice* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRDVCSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no device)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmdevice->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubDvcStd --- IBEGIN
			stub = rec->sref + " (" + getStubDtpStd(dbsplnr, rec->tplRefPlnrMDevice, ixPlnrVLocale) + ")";
// IP getStubDvcStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubFceStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1.f1'
	string stub;

	PlnrMFace* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRFCESTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no face)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmface->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFceStd --- IBEGIN
			stub = getStubSruStd(dbsplnr, rec->sruRefPlnrMStructure, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
// IP getStubFceStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubFilShort(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Ex_prof.hdf5'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRFILSHORT, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no file)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmfile->loadFnmByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubFilStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Ex_prof.hdf5 (data on grid)'
	string stub;

	PlnrMFile* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRFILSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no file)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmfile->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubFilStd --- IBEGIN
			stub = rec->Filename;
			if (rec->osrefKContent.length() > 0) stub += " (" + rec->osrefKContent + ")";
// IP getStubFilStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubGrp(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'agroup'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRGRP, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubLgdStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1.lg1'
	string stub;

	PlnrMLineguide* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRLGDSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no line guide)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmlineguide->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubLgdStd --- IBEGIN
			if (rec->hkIxVTbl == VecPlnrVMLineguideHkTbl::DSN) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecPlnrVMLineguideHkTbl::DEV) {
				stub = getStubDevShort(dbsplnr, rec->hkUref, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
// IP getStubLgdStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubLvlStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'litho.lyr1.flr'
	string stub;

	PlnrMLevel* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRLVLSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no level)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmlevel->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubLvlStd --- IBEGIN
			if (rec->hkIxVTbl == VecPlnrVMLevelHkTbl::DSN) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecPlnrVMLevelHkTbl::STK) {
				stub = getStubStkShort(dbsplnr, rec->hkUref, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
// IP getStubLvlStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubLyrStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'litho.lyr1'
	string stub;

	PlnrMLayer* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRLYRSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no layer)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmlayer->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubLyrStd --- IBEGIN
			if (rec->hkIxVTbl == VecPlnrVMLayerHkTbl::DSN) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecPlnrVMLayerHkTbl::STK) {
				stub = getStubStkShort(dbsplnr, rec->hkUref, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
// IP getStubLyrStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubMatStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'AlGaN;AlGaN0.5;AlGaN0.5mod'
	string stub;

	PlnrMMaterial* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRMATSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no material)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmmaterial->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->modRefPlnrMMaterial != 0) stub = getStubMatStd(dbsplnr, rec->modRefPlnrMMaterial, ixPlnrVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubOwn(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'auser'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNROWN, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubPrjStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'MQW test'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRPRJSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no project)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmproject->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubPrsStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Franz Kuntz'
	string stub;

	PlnrMPerson* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRPRSSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no person)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubPlnrPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
// IP getStubPlnrPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubRtcStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'wgs.r3.0_cD.wg'
	string stub;

	PlnrMReticle* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRRTCSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no reticle)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmreticle->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubRtcStd --- IBEGIN
			if (rec->hkIxVTbl == VecPlnrVMReticleHkTbl::TPO) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecPlnrVMReticleHkTbl::ARR) {
				stub = getStubArrStd(dbsplnr, rec->hkUref, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
// IP getStubRtcStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubSesMenu(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'user Franz Kuntz (fkuntz) logged in from 127.0.0.1 since 01-01-2010 10:34'
	string stub;

	PlnrMSession* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRSESMENU, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubPlnrSesMenu --- BEGIN
			if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "user " + getStubUsrStd(dbsplnr, rec->refPlnrMUser, ixPlnrVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
// IP getStubPlnrSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubSesStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: '01-01-2010 10:34 from 127.0.0.1'
	string stub;

	PlnrMSession* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRSESSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubPlnrSesStd --- BEGIN
			if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
// IP getStubPlnrSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubSruStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'taper1.main'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRSRUSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no structure)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmstructure->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubStkShort(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'all'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRSTKSHORT, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no stack)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmstack->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubStkStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'all (litho)'
	string stub;

	PlnrMStack* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRSTKSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no stack)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmstack->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubStkStd --- IBEGIN
			stub = rec->sref + " (" + VecPlnrVMStackBasetype::getTitle(rec->ixVBasetype, ixPlnrVLocale) + ")";
// IP getStubStkStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubTpoStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'CEA III-Nitride Pyramid Pre-Pattern'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRTPOSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no tape-out)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmtapeout->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubUsgStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'super'
	string stub;

	stref_t stref(VecPlnrVStub::STUBPLNRUSGSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubPlnr::getStubUsrStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'Franz Kuntz (fkuntz)'
	string stub;

	PlnrMUser* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRUSRSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubPlnrUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbsplnr, rec->refPlnrMPerson, ixPlnrVLocale, ixVNonetype, stcch, &stref);
// IP getStubPlnrUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubPlnr::getStubVtxStd(
			DbsPlnr* dbsplnr
			, const ubigint ref
			, const uint ixPlnrVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stref_t* strefSub
			, const bool refresh
		) {
	// example: 'v5563'
	string stub;

	PlnrMVertex* rec = NULL;

	stref_t stref(VecPlnrVStub::STUBPLNRVTXSTD, ref, ixPlnrVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixPlnrVLocale == VecPlnrVLocale::ENUS) stub = "(no vertex)";
	};

	if (ref != 0) {
		if (dbsplnr->tblplnrmvertex->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
// IP getStubVtxStd --- IBEGIN
			if (rec->hkIxVTbl == VecPlnrVMVertexHkTbl::DSN) {
				stub = rec->sref;
			} else if (rec->hkIxVTbl == VecPlnrVMVertexHkTbl::DEV) {
				stub = getStubDevShort(dbsplnr, rec->hkUref, ixPlnrVLocale, ixVNonetype, stcch, &stref) + "." + rec->sref;
			};
// IP getStubVtxStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class ContInfPlnrAlert
 ******************************************************************************/

ContInfPlnrAlert::ContInfPlnrAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
		) : Block() {
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10};
};

bool ContInfPlnrAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;

	return true;
};

void ContInfPlnrAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfPlnrAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfPlnrAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfPlnrAlert::compare(
			const ContInfPlnrAlert* comp
		) {
	set<uint> items;

	if (TxtCpt.compare(comp->TxtCpt) == 0) insert(items, TXTCPT);
	if (TxtMsg1.compare(comp->TxtMsg1) == 0) insert(items, TXTMSG1);
	if (TxtMsg2.compare(comp->TxtMsg2) == 0) insert(items, TXTMSG2);
	if (TxtMsg3.compare(comp->TxtMsg3) == 0) insert(items, TXTMSG3);
	if (TxtMsg4.compare(comp->TxtMsg4) == 0) insert(items, TXTMSG4);
	if (TxtMsg5.compare(comp->TxtMsg5) == 0) insert(items, TXTMSG5);
	if (TxtMsg6.compare(comp->TxtMsg6) == 0) insert(items, TXTMSG6);
	if (TxtMsg7.compare(comp->TxtMsg7) == 0) insert(items, TXTMSG7);
	if (TxtMsg8.compare(comp->TxtMsg8) == 0) insert(items, TXTMSG8);
	if (TxtMsg9.compare(comp->TxtMsg9) == 0) insert(items, TXTMSG9);
	if (TxtMsg10.compare(comp->TxtMsg10) == 0) insert(items, TXTMSG10);

	return(items);
};

/******************************************************************************
 class DpchPlnr
 ******************************************************************************/

DpchPlnr::DpchPlnr(
			const uint ixPlnrVDpch
		) {
	this->ixPlnrVDpch = ixPlnrVDpch;
};

DpchPlnr::~DpchPlnr() {
};

/******************************************************************************
 class DpchInvPlnr
 ******************************************************************************/

DpchInvPlnr::DpchInvPlnr(
			const uint ixPlnrVDpch
			, const ubigint oref
			, const ubigint jref
			, const set<uint>& mask
		) : DpchPlnr(ixPlnrVDpch) {
	this->oref = oref;
	this->jref = jref;

	if (find(mask, ALL)) this->mask = {OREF, JREF};
	else this->mask = mask;
};

DpchInvPlnr::~DpchInvPlnr() {
};

bool DpchInvPlnr::all(
			const set<uint>& items
		) {
	if (!find(items, OREF)) return false;
	if (!find(items, JREF)) return false;

	return true;
};

void DpchInvPlnr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvPlnr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvPlnr::writeXML(
			pthread_mutex_t* mScr
			, map<ubigint,string>& scr
			, map<string,ubigint>& descr
			, xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(OREF)) writeString(wr, "scrOref", Scr::scramble(mScr, scr, descr, oref));
		if (has(JREF)) writeString(wr, "scrJref", Scr::scramble(mScr, scr, descr, jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetPlnr
 ******************************************************************************/

DpchRetPlnr::DpchRetPlnr(
			const uint ixPlnrVDpch
			, const string& scrOref
			, const string& scrJref
			, const bool success
			, const set<uint>& mask
		) : DpchPlnr(ixPlnrVDpch) {
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->success = success;

	if (find(mask, ALL)) this->mask = {SCROREF, SCRJREF, SUCCESS};
	else this->mask = mask;
};

DpchRetPlnr::~DpchRetPlnr() {
};

bool DpchRetPlnr::all(
			const set<uint>& items
		) {
	if (!find(items, OREF)) return false;
	if (!find(items, JREF)) return false;
	if (!find(items, SUCCESS)) return false;

	return true;
};

void DpchRetPlnr::readXML(
			pthread_mutex_t* mScr
			, map<string,ubigint>& descr
			, xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetPlnr");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(mScr, descr, scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(mScr, descr, scrJref);
			add(JREF);
		};
		if (extractBoolUclc(docctx, basexpath, "success", "", success)) add(SUCCESS);
	};
};

void DpchRetPlnr::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetPlnr");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.epsitechnologies.com/plnr");
		if (has(SCROREF)) writeString(wr, "scrOref", scrOref);
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(SUCCESS)) writeBool(wr, "success", success);
	xmlTextWriterEndElement(wr);
};


