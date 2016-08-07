/**
  * \file PlnrQDvcSup1NDevice.h
  * Dbs and XML wrapper for table TblPlnrQDvcSup1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCSUP1NDEVICE_H
#define PLNRQDVCSUP1NDEVICE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcSup1NDevice: record of TblPlnrQDvcSup1NDevice
  */
class PlnrQDvcSup1NDevice {

public:
	PlnrQDvcSup1NDevice(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint supNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint supNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDvcSup1NDevice: recordset of TblPlnrQDvcSup1NDevice
  */
class ListPlnrQDvcSup1NDevice {

public:
	ListPlnrQDvcSup1NDevice();
	ListPlnrQDvcSup1NDevice(const ListPlnrQDvcSup1NDevice& src);
	~ListPlnrQDvcSup1NDevice();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcSup1NDevice* rec);

	ListPlnrQDvcSup1NDevice& operator=(const ListPlnrQDvcSup1NDevice& src);

public:
	vector<PlnrQDvcSup1NDevice*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcSup1NDevice: C++ wrapper for table TblPlnrQDvcSup1NDevice
  */
class TblPlnrQDvcSup1NDevice {

public:
	TblPlnrQDvcSup1NDevice();
	virtual ~TblPlnrQDvcSup1NDevice();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcSup1NDevice** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcSup1NDevice& rst);

	virtual void insertRec(PlnrQDvcSup1NDevice* rec);
	ubigint insertNewRec(PlnrQDvcSup1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint supNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDvcSup1NDevice& rst, PlnrQDvcSup1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint supNum = 0);
	virtual void insertRst(ListPlnrQDvcSup1NDevice& rst);
	virtual void updateRec(PlnrQDvcSup1NDevice* rec);
	virtual void updateRst(ListPlnrQDvcSup1NDevice& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcSup1NDevice** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcSup1NDevice& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcSup1NDevice: C++ wrapper for table TblPlnrQDvcSup1NDevice (MySQL database)
  */
class MyTblPlnrQDvcSup1NDevice : public TblPlnrQDvcSup1NDevice, public MyTable {

public:
	MyTblPlnrQDvcSup1NDevice();
	~MyTblPlnrQDvcSup1NDevice();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcSup1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcSup1NDevice& rst);

	void insertRec(PlnrQDvcSup1NDevice* rec);
	void insertRst(ListPlnrQDvcSup1NDevice& rst);
	void updateRec(PlnrQDvcSup1NDevice* rec);
	void updateRst(ListPlnrQDvcSup1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcSup1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcSup1NDevice& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcSup1NDevice: C++ wrapper for table TblPlnrQDvcSup1NDevice (PgSQL database)
  */
class PgTblPlnrQDvcSup1NDevice : public TblPlnrQDvcSup1NDevice, public PgTable {

public:
	PgTblPlnrQDvcSup1NDevice();
	~PgTblPlnrQDvcSup1NDevice();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcSup1NDevice** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcSup1NDevice& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcSup1NDevice** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcSup1NDevice& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcSup1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcSup1NDevice& rst);

	void insertRec(PlnrQDvcSup1NDevice* rec);
	void insertRst(ListPlnrQDvcSup1NDevice& rst);
	void updateRec(PlnrQDvcSup1NDevice* rec);
	void updateRst(ListPlnrQDvcSup1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcSup1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcSup1NDevice& rst);
};
// IP pgTbl --- END

#endif

