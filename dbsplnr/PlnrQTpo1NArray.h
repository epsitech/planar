/**
  * \file PlnrQTpo1NArray.h
  * Dbs and XML wrapper for table TblPlnrQTpo1NArray (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQTPO1NARRAY_H
#define PLNRQTPO1NARRAY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQTpo1NArray: record of TblPlnrQTpo1NArray
  */
class PlnrQTpo1NArray {

public:
	PlnrQTpo1NArray(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQTpo1NArray: recordset of TblPlnrQTpo1NArray
  */
class ListPlnrQTpo1NArray {

public:
	ListPlnrQTpo1NArray();
	ListPlnrQTpo1NArray(const ListPlnrQTpo1NArray& src);
	~ListPlnrQTpo1NArray();

	void clear();
	unsigned int size() const;
	void append(PlnrQTpo1NArray* rec);

	ListPlnrQTpo1NArray& operator=(const ListPlnrQTpo1NArray& src);

public:
	vector<PlnrQTpo1NArray*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQTpo1NArray: C++ wrapper for table TblPlnrQTpo1NArray
  */
class TblPlnrQTpo1NArray {

public:
	TblPlnrQTpo1NArray();
	virtual ~TblPlnrQTpo1NArray();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQTpo1NArray** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpo1NArray& rst);

	virtual void insertRec(PlnrQTpo1NArray* rec);
	ubigint insertNewRec(PlnrQTpo1NArray** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQTpo1NArray& rst, PlnrQTpo1NArray** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQTpo1NArray& rst);
	virtual void updateRec(PlnrQTpo1NArray* rec);
	virtual void updateRst(ListPlnrQTpo1NArray& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQTpo1NArray** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpo1NArray& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQTpo1NArray: C++ wrapper for table TblPlnrQTpo1NArray (MySQL database)
  */
class MyTblPlnrQTpo1NArray : public TblPlnrQTpo1NArray, public MyTable {

public:
	MyTblPlnrQTpo1NArray();
	~MyTblPlnrQTpo1NArray();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpo1NArray** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpo1NArray& rst);

	void insertRec(PlnrQTpo1NArray* rec);
	void insertRst(ListPlnrQTpo1NArray& rst);
	void updateRec(PlnrQTpo1NArray* rec);
	void updateRst(ListPlnrQTpo1NArray& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpo1NArray** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpo1NArray& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQTpo1NArray: C++ wrapper for table TblPlnrQTpo1NArray (PgSQL database)
  */
class PgTblPlnrQTpo1NArray : public TblPlnrQTpo1NArray, public PgTable {

public:
	PgTblPlnrQTpo1NArray();
	~PgTblPlnrQTpo1NArray();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQTpo1NArray** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQTpo1NArray& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQTpo1NArray** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQTpo1NArray& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQTpo1NArray** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQTpo1NArray& rst);

	void insertRec(PlnrQTpo1NArray* rec);
	void insertRst(ListPlnrQTpo1NArray& rst);
	void updateRec(PlnrQTpo1NArray* rec);
	void updateRst(ListPlnrQTpo1NArray& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQTpo1NArray** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQTpo1NArray& rst);
};
// IP pgTbl --- END

#endif

