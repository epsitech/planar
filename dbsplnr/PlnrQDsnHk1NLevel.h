/**
  * \file PlnrQDsnHk1NLevel.h
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NLevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NLEVEL_H
#define PLNRQDSNHK1NLEVEL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NLevel: record of TblPlnrQDsnHk1NLevel
  */
class PlnrQDsnHk1NLevel {

public:
	PlnrQDsnHk1NLevel(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsnHk1NLevel: recordset of TblPlnrQDsnHk1NLevel
  */
class ListPlnrQDsnHk1NLevel {

public:
	ListPlnrQDsnHk1NLevel();
	ListPlnrQDsnHk1NLevel(const ListPlnrQDsnHk1NLevel& src);
	~ListPlnrQDsnHk1NLevel();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnHk1NLevel* rec);

	ListPlnrQDsnHk1NLevel& operator=(const ListPlnrQDsnHk1NLevel& src);

public:
	vector<PlnrQDsnHk1NLevel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnHk1NLevel: C++ wrapper for table TblPlnrQDsnHk1NLevel
  */
class TblPlnrQDsnHk1NLevel {

public:
	TblPlnrQDsnHk1NLevel();
	virtual ~TblPlnrQDsnHk1NLevel();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLevel** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLevel& rst);

	virtual void insertRec(PlnrQDsnHk1NLevel* rec);
	ubigint insertNewRec(PlnrQDsnHk1NLevel** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnHk1NLevel& rst, PlnrQDsnHk1NLevel** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnHk1NLevel& rst);
	virtual void updateRec(PlnrQDsnHk1NLevel* rec);
	virtual void updateRst(ListPlnrQDsnHk1NLevel& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLevel** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLevel& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnHk1NLevel: C++ wrapper for table TblPlnrQDsnHk1NLevel (MySQL database)
  */
class MyTblPlnrQDsnHk1NLevel : public TblPlnrQDsnHk1NLevel, public MyTable {

public:
	MyTblPlnrQDsnHk1NLevel();
	~MyTblPlnrQDsnHk1NLevel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLevel& rst);

	void insertRec(PlnrQDsnHk1NLevel* rec);
	void insertRst(ListPlnrQDsnHk1NLevel& rst);
	void updateRec(PlnrQDsnHk1NLevel* rec);
	void updateRst(ListPlnrQDsnHk1NLevel& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLevel** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLevel& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnHk1NLevel: C++ wrapper for table TblPlnrQDsnHk1NLevel (PgSQL database)
  */
class PgTblPlnrQDsnHk1NLevel : public TblPlnrQDsnHk1NLevel, public PgTable {

public:
	PgTblPlnrQDsnHk1NLevel();
	~PgTblPlnrQDsnHk1NLevel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnHk1NLevel** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnHk1NLevel& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnHk1NLevel** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnHk1NLevel& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLevel& rst);

	void insertRec(PlnrQDsnHk1NLevel* rec);
	void insertRst(ListPlnrQDsnHk1NLevel& rst);
	void updateRec(PlnrQDsnHk1NLevel* rec);
	void updateRst(ListPlnrQDsnHk1NLevel& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLevel** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLevel& rst);
};
// IP pgTbl --- END

#endif

