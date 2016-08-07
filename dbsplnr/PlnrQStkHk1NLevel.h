/**
  * \file PlnrQStkHk1NLevel.h
  * Dbs and XML wrapper for table TblPlnrQStkHk1NLevel (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSTKHK1NLEVEL_H
#define PLNRQSTKHK1NLEVEL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQStkHk1NLevel: record of TblPlnrQStkHk1NLevel
  */
class PlnrQStkHk1NLevel {

public:
	PlnrQStkHk1NLevel(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQStkHk1NLevel: recordset of TblPlnrQStkHk1NLevel
  */
class ListPlnrQStkHk1NLevel {

public:
	ListPlnrQStkHk1NLevel();
	ListPlnrQStkHk1NLevel(const ListPlnrQStkHk1NLevel& src);
	~ListPlnrQStkHk1NLevel();

	void clear();
	unsigned int size() const;
	void append(PlnrQStkHk1NLevel* rec);

	ListPlnrQStkHk1NLevel& operator=(const ListPlnrQStkHk1NLevel& src);

public:
	vector<PlnrQStkHk1NLevel*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQStkHk1NLevel: C++ wrapper for table TblPlnrQStkHk1NLevel
  */
class TblPlnrQStkHk1NLevel {

public:
	TblPlnrQStkHk1NLevel();
	virtual ~TblPlnrQStkHk1NLevel();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQStkHk1NLevel** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkHk1NLevel& rst);

	virtual void insertRec(PlnrQStkHk1NLevel* rec);
	ubigint insertNewRec(PlnrQStkHk1NLevel** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQStkHk1NLevel& rst, PlnrQStkHk1NLevel** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQStkHk1NLevel& rst);
	virtual void updateRec(PlnrQStkHk1NLevel* rec);
	virtual void updateRst(ListPlnrQStkHk1NLevel& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQStkHk1NLevel** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkHk1NLevel& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQStkHk1NLevel: C++ wrapper for table TblPlnrQStkHk1NLevel (MySQL database)
  */
class MyTblPlnrQStkHk1NLevel : public TblPlnrQStkHk1NLevel, public MyTable {

public:
	MyTblPlnrQStkHk1NLevel();
	~MyTblPlnrQStkHk1NLevel();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkHk1NLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkHk1NLevel& rst);

	void insertRec(PlnrQStkHk1NLevel* rec);
	void insertRst(ListPlnrQStkHk1NLevel& rst);
	void updateRec(PlnrQStkHk1NLevel* rec);
	void updateRst(ListPlnrQStkHk1NLevel& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkHk1NLevel** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkHk1NLevel& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQStkHk1NLevel: C++ wrapper for table TblPlnrQStkHk1NLevel (PgSQL database)
  */
class PgTblPlnrQStkHk1NLevel : public TblPlnrQStkHk1NLevel, public PgTable {

public:
	PgTblPlnrQStkHk1NLevel();
	~PgTblPlnrQStkHk1NLevel();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQStkHk1NLevel** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQStkHk1NLevel& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQStkHk1NLevel** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQStkHk1NLevel& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQStkHk1NLevel** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQStkHk1NLevel& rst);

	void insertRec(PlnrQStkHk1NLevel* rec);
	void insertRst(ListPlnrQStkHk1NLevel& rst);
	void updateRec(PlnrQStkHk1NLevel* rec);
	void updateRst(ListPlnrQStkHk1NLevel& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQStkHk1NLevel** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQStkHk1NLevel& rst);
};
// IP pgTbl --- END

#endif

