/**
  * \file PlnrQDsnDsn1NDevice.h
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NDevice (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NDEVICE_H
#define PLNRQDSNDSN1NDEVICE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NDevice: record of TblPlnrQDsnDsn1NDevice
  */
class PlnrQDsnDsn1NDevice {

public:
	PlnrQDsnDsn1NDevice(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint dsnNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDsnDsn1NDevice: recordset of TblPlnrQDsnDsn1NDevice
  */
class ListPlnrQDsnDsn1NDevice {

public:
	ListPlnrQDsnDsn1NDevice();
	ListPlnrQDsnDsn1NDevice(const ListPlnrQDsnDsn1NDevice& src);
	~ListPlnrQDsnDsn1NDevice();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnDsn1NDevice* rec);

	ListPlnrQDsnDsn1NDevice& operator=(const ListPlnrQDsnDsn1NDevice& src);

public:
	vector<PlnrQDsnDsn1NDevice*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnDsn1NDevice: C++ wrapper for table TblPlnrQDsnDsn1NDevice
  */
class TblPlnrQDsnDsn1NDevice {

public:
	TblPlnrQDsnDsn1NDevice();
	virtual ~TblPlnrQDsnDsn1NDevice();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDevice** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDevice& rst);

	virtual void insertRec(PlnrQDsnDsn1NDevice* rec);
	ubigint insertNewRec(PlnrQDsnDsn1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDsnDsn1NDevice& rst, PlnrQDsnDsn1NDevice** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	virtual void insertRst(ListPlnrQDsnDsn1NDevice& rst);
	virtual void updateRec(PlnrQDsnDsn1NDevice* rec);
	virtual void updateRst(ListPlnrQDsnDsn1NDevice& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDevice** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDevice& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnDsn1NDevice: C++ wrapper for table TblPlnrQDsnDsn1NDevice (MySQL database)
  */
class MyTblPlnrQDsnDsn1NDevice : public TblPlnrQDsnDsn1NDevice, public MyTable {

public:
	MyTblPlnrQDsnDsn1NDevice();
	~MyTblPlnrQDsnDsn1NDevice();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDevice& rst);

	void insertRec(PlnrQDsnDsn1NDevice* rec);
	void insertRst(ListPlnrQDsnDsn1NDevice& rst);
	void updateRec(PlnrQDsnDsn1NDevice* rec);
	void updateRst(ListPlnrQDsnDsn1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDevice& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnDsn1NDevice: C++ wrapper for table TblPlnrQDsnDsn1NDevice (PgSQL database)
  */
class PgTblPlnrQDsnDsn1NDevice : public TblPlnrQDsnDsn1NDevice, public PgTable {

public:
	PgTblPlnrQDsnDsn1NDevice();
	~PgTblPlnrQDsnDsn1NDevice();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnDsn1NDevice** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnDsn1NDevice& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnDsn1NDevice** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnDsn1NDevice& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDevice** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDevice& rst);

	void insertRec(PlnrQDsnDsn1NDevice* rec);
	void insertRst(ListPlnrQDsnDsn1NDevice& rst);
	void updateRec(PlnrQDsnDsn1NDevice* rec);
	void updateRst(ListPlnrQDsnDsn1NDevice& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDevice** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDevice& rst);
};
// IP pgTbl --- END

#endif

