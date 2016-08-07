/**
  * \file PlnrMDevice.h
  * database access for table TblPlnrMDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMDEVICE_H
#define PLNRMDEVICE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMDevice: record of TblPlnrMDevice
  */
class PlnrMDevice {

public:
	PlnrMDevice(const ubigint ref = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const ubigint supRefPlnrMDevice = 0, const uint supNum = 0, const ubigint tplRefPlnrMDevice = 0, const string sref = "", const uint ixVModtype = 0, const uint ixVAligntype = 0, const string av1SrefPlnrMVertex = "", const string pav1SrefPlnrMVertex = "", const string av2SrefPlnrMVertex = "", const string pav2SrefPlnrMVertex = "", const double x = 0.0, const double y = 0.0, const double phi = 0.0, const string Comment = "");

public:
	ubigint ref;
	ubigint dsnRefPlnrMDesign;
	uint dsnNum;
	ubigint supRefPlnrMDevice;
	uint supNum;
	ubigint tplRefPlnrMDevice;
	string sref;
	uint ixVModtype;
	uint ixVAligntype;
	string av1SrefPlnrMVertex;
	string pav1SrefPlnrMVertex;
	string av2SrefPlnrMVertex;
	string pav2SrefPlnrMVertex;
	double x;
	double y;
	double phi;
	string Comment;

public:
	bool operator==(const PlnrMDevice& comp);
	bool operator!=(const PlnrMDevice& comp);
};

/**
  * ListPlnrMDevice: recordset of TblPlnrMDevice
  */
class ListPlnrMDevice {

public:
	ListPlnrMDevice();
	ListPlnrMDevice(const ListPlnrMDevice& src);
	~ListPlnrMDevice();

	void clear();
	unsigned int size() const;
	void append(PlnrMDevice* rec);

	PlnrMDevice* operator[](const uint ix);
	ListPlnrMDevice& operator=(const ListPlnrMDevice& src);
	bool operator==(const ListPlnrMDevice& comp);
	bool operator!=(const ListPlnrMDevice& comp);

public:
	vector<PlnrMDevice*> nodes;
};

/**
  * TblPlnrMDevice: C++ wrapper for table TblPlnrMDevice
  */
class TblPlnrMDevice {

public:
	TblPlnrMDevice();
	virtual ~TblPlnrMDevice();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMDevice** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDevice& rst);

	virtual void insertRec(PlnrMDevice* rec);
	ubigint insertNewRec(PlnrMDevice** rec = NULL, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const ubigint supRefPlnrMDevice = 0, const uint supNum = 0, const ubigint tplRefPlnrMDevice = 0, const string sref = "", const uint ixVModtype = 0, const uint ixVAligntype = 0, const string av1SrefPlnrMVertex = "", const string pav1SrefPlnrMVertex = "", const string av2SrefPlnrMVertex = "", const string pav2SrefPlnrMVertex = "", const double x = 0.0, const double y = 0.0, const double phi = 0.0, const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMDevice& rst, PlnrMDevice** rec = NULL, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const ubigint supRefPlnrMDevice = 0, const uint supNum = 0, const ubigint tplRefPlnrMDevice = 0, const string sref = "", const uint ixVModtype = 0, const uint ixVAligntype = 0, const string av1SrefPlnrMVertex = "", const string pav1SrefPlnrMVertex = "", const string av2SrefPlnrMVertex = "", const string pav2SrefPlnrMVertex = "", const double x = 0.0, const double y = 0.0, const double phi = 0.0, const string Comment = "");
	virtual void insertRst(ListPlnrMDevice& rst, bool transact = false);
	virtual void updateRec(PlnrMDevice* rec);
	virtual void updateRst(ListPlnrMDevice& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMDevice** rec);
	virtual bool loadRefByTplSrf(ubigint tplRefPlnrMDevice, string sref, ubigint& val);
	virtual ubigint loadRefsBySup(ubigint supRefPlnrMDevice, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRefsBySupTpl(ubigint supRefPlnrMDevice, ubigint tplRefPlnrMDevice, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDevice& rst);
	virtual ubigint loadRstByDsnSup(ubigint dsnRefPlnrMDesign, ubigint supRefPlnrMDevice, const bool append, ListPlnrMDevice& rst);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMDevice& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMDevice: C++ wrapper for table TblPlnrMDevice (MySQL database)
  */
class MyTblPlnrMDevice : public TblPlnrMDevice, public MyTable {

public:
	MyTblPlnrMDevice();
	~MyTblPlnrMDevice();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDevice& rst);

	void insertRec(PlnrMDevice* rec);
	void insertRst(ListPlnrMDevice& rst, bool transact = false);
	void updateRec(PlnrMDevice* rec);
	void updateRst(ListPlnrMDevice& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDevice** rec);
	bool loadRefByTplSrf(ubigint tplRefPlnrMDevice, string sref, ubigint& val);
	ubigint loadRefsBySup(ubigint supRefPlnrMDevice, const bool append, vector<ubigint>& refs);
	ubigint loadRefsBySupTpl(ubigint supRefPlnrMDevice, ubigint tplRefPlnrMDevice, const bool append, vector<ubigint>& refs);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDevice& rst);
	ubigint loadRstByDsnSup(ubigint dsnRefPlnrMDesign, ubigint supRefPlnrMDevice, const bool append, ListPlnrMDevice& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMDevice: C++ wrapper for table TblPlnrMDevice (PgSQL database)
  */
class PgTblPlnrMDevice : public TblPlnrMDevice, public PgTable {

public:
	PgTblPlnrMDevice();
	~PgTblPlnrMDevice();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMDevice** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMDevice& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMDevice** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMDevice& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDevice& rst);

	void insertRec(PlnrMDevice* rec);
	void insertRst(ListPlnrMDevice& rst, bool transact = false);
	void updateRec(PlnrMDevice* rec);
	void updateRst(ListPlnrMDevice& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDevice** rec);
	bool loadRefByTplSrf(ubigint tplRefPlnrMDevice, string sref, ubigint& val);
	ubigint loadRefsBySup(ubigint supRefPlnrMDevice, const bool append, vector<ubigint>& refs);
	ubigint loadRefsBySupTpl(ubigint supRefPlnrMDevice, ubigint tplRefPlnrMDevice, const bool append, vector<ubigint>& refs);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDevice& rst);
	ubigint loadRstByDsnSup(ubigint dsnRefPlnrMDesign, ubigint supRefPlnrMDevice, const bool append, ListPlnrMDevice& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

