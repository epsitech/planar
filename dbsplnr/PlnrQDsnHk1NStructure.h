/**
  * \file PlnrQDsnHk1NStructure.h
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NSTRUCTURE_H
#define PLNRQDSNHK1NSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NStructure: record of TblPlnrQDsnHk1NStructure
  */
class PlnrQDsnHk1NStructure {

public:
	PlnrQDsnHk1NStructure(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsnHk1NStructure: recordset of TblPlnrQDsnHk1NStructure
  */
class ListPlnrQDsnHk1NStructure {

public:
	ListPlnrQDsnHk1NStructure();
	ListPlnrQDsnHk1NStructure(const ListPlnrQDsnHk1NStructure& src);
	~ListPlnrQDsnHk1NStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnHk1NStructure* rec);

	ListPlnrQDsnHk1NStructure& operator=(const ListPlnrQDsnHk1NStructure& src);

public:
	vector<PlnrQDsnHk1NStructure*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnHk1NStructure: C++ wrapper for table TblPlnrQDsnHk1NStructure
  */
class TblPlnrQDsnHk1NStructure {

public:
	TblPlnrQDsnHk1NStructure();
	virtual ~TblPlnrQDsnHk1NStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NStructure& rst);

	virtual void insertRec(PlnrQDsnHk1NStructure* rec);
	ubigint insertNewRec(PlnrQDsnHk1NStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnHk1NStructure& rst, PlnrQDsnHk1NStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnHk1NStructure& rst);
	virtual void updateRec(PlnrQDsnHk1NStructure* rec);
	virtual void updateRst(ListPlnrQDsnHk1NStructure& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnHk1NStructure** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnHk1NStructure: C++ wrapper for table TblPlnrQDsnHk1NStructure (MySQL database)
  */
class MyTblPlnrQDsnHk1NStructure : public TblPlnrQDsnHk1NStructure, public MyTable {

public:
	MyTblPlnrQDsnHk1NStructure();
	~MyTblPlnrQDsnHk1NStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NStructure& rst);

	void insertRec(PlnrQDsnHk1NStructure* rec);
	void insertRst(ListPlnrQDsnHk1NStructure& rst);
	void updateRec(PlnrQDsnHk1NStructure* rec);
	void updateRst(ListPlnrQDsnHk1NStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnHk1NStructure: C++ wrapper for table TblPlnrQDsnHk1NStructure (PgSQL database)
  */
class PgTblPlnrQDsnHk1NStructure : public TblPlnrQDsnHk1NStructure, public PgTable {

public:
	PgTblPlnrQDsnHk1NStructure();
	~PgTblPlnrQDsnHk1NStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnHk1NStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnHk1NStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnHk1NStructure** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnHk1NStructure& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NStructure& rst);

	void insertRec(PlnrQDsnHk1NStructure* rec);
	void insertRst(ListPlnrQDsnHk1NStructure& rst);
	void updateRec(PlnrQDsnHk1NStructure* rec);
	void updateRst(ListPlnrQDsnHk1NStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NStructure& rst);
};
// IP pgTbl --- END

#endif

