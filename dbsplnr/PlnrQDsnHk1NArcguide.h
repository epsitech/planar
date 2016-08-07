/**
  * \file PlnrQDsnHk1NArcguide.h
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NArcguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NARCGUIDE_H
#define PLNRQDSNHK1NARCGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NArcguide: record of TblPlnrQDsnHk1NArcguide
  */
class PlnrQDsnHk1NArcguide {

public:
	PlnrQDsnHk1NArcguide(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsnHk1NArcguide: recordset of TblPlnrQDsnHk1NArcguide
  */
class ListPlnrQDsnHk1NArcguide {

public:
	ListPlnrQDsnHk1NArcguide();
	ListPlnrQDsnHk1NArcguide(const ListPlnrQDsnHk1NArcguide& src);
	~ListPlnrQDsnHk1NArcguide();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnHk1NArcguide* rec);

	ListPlnrQDsnHk1NArcguide& operator=(const ListPlnrQDsnHk1NArcguide& src);

public:
	vector<PlnrQDsnHk1NArcguide*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnHk1NArcguide: C++ wrapper for table TblPlnrQDsnHk1NArcguide
  */
class TblPlnrQDsnHk1NArcguide {

public:
	TblPlnrQDsnHk1NArcguide();
	virtual ~TblPlnrQDsnHk1NArcguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NArcguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NArcguide& rst);

	virtual void insertRec(PlnrQDsnHk1NArcguide* rec);
	ubigint insertNewRec(PlnrQDsnHk1NArcguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnHk1NArcguide& rst, PlnrQDsnHk1NArcguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnHk1NArcguide& rst);
	virtual void updateRec(PlnrQDsnHk1NArcguide* rec);
	virtual void updateRst(ListPlnrQDsnHk1NArcguide& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnHk1NArcguide** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NArcguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnHk1NArcguide: C++ wrapper for table TblPlnrQDsnHk1NArcguide (MySQL database)
  */
class MyTblPlnrQDsnHk1NArcguide : public TblPlnrQDsnHk1NArcguide, public MyTable {

public:
	MyTblPlnrQDsnHk1NArcguide();
	~MyTblPlnrQDsnHk1NArcguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NArcguide& rst);

	void insertRec(PlnrQDsnHk1NArcguide* rec);
	void insertRst(ListPlnrQDsnHk1NArcguide& rst);
	void updateRec(PlnrQDsnHk1NArcguide* rec);
	void updateRst(ListPlnrQDsnHk1NArcguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NArcguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NArcguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnHk1NArcguide: C++ wrapper for table TblPlnrQDsnHk1NArcguide (PgSQL database)
  */
class PgTblPlnrQDsnHk1NArcguide : public TblPlnrQDsnHk1NArcguide, public PgTable {

public:
	PgTblPlnrQDsnHk1NArcguide();
	~PgTblPlnrQDsnHk1NArcguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnHk1NArcguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnHk1NArcguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnHk1NArcguide** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnHk1NArcguide& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NArcguide& rst);

	void insertRec(PlnrQDsnHk1NArcguide* rec);
	void insertRst(ListPlnrQDsnHk1NArcguide& rst);
	void updateRec(PlnrQDsnHk1NArcguide* rec);
	void updateRst(ListPlnrQDsnHk1NArcguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NArcguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NArcguide& rst);
};
// IP pgTbl --- END

#endif

