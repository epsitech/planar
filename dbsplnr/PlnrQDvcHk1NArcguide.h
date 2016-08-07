/**
  * \file PlnrQDvcHk1NArcguide.h
  * Dbs and XML wrapper for table TblPlnrQDvcHk1NArcguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NARCGUIDE_H
#define PLNRQDVCHK1NARCGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NArcguide: record of TblPlnrQDvcHk1NArcguide
  */
class PlnrQDvcHk1NArcguide {

public:
	PlnrQDvcHk1NArcguide(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDvcHk1NArcguide: recordset of TblPlnrQDvcHk1NArcguide
  */
class ListPlnrQDvcHk1NArcguide {

public:
	ListPlnrQDvcHk1NArcguide();
	ListPlnrQDvcHk1NArcguide(const ListPlnrQDvcHk1NArcguide& src);
	~ListPlnrQDvcHk1NArcguide();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcHk1NArcguide* rec);

	ListPlnrQDvcHk1NArcguide& operator=(const ListPlnrQDvcHk1NArcguide& src);

public:
	vector<PlnrQDvcHk1NArcguide*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcHk1NArcguide: C++ wrapper for table TblPlnrQDvcHk1NArcguide
  */
class TblPlnrQDvcHk1NArcguide {

public:
	TblPlnrQDvcHk1NArcguide();
	virtual ~TblPlnrQDvcHk1NArcguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NArcguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NArcguide& rst);

	virtual void insertRec(PlnrQDvcHk1NArcguide* rec);
	ubigint insertNewRec(PlnrQDvcHk1NArcguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDvcHk1NArcguide& rst, PlnrQDvcHk1NArcguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDvcHk1NArcguide& rst);
	virtual void updateRec(PlnrQDvcHk1NArcguide* rec);
	virtual void updateRst(ListPlnrQDvcHk1NArcguide& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcHk1NArcguide** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NArcguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcHk1NArcguide: C++ wrapper for table TblPlnrQDvcHk1NArcguide (MySQL database)
  */
class MyTblPlnrQDvcHk1NArcguide : public TblPlnrQDvcHk1NArcguide, public MyTable {

public:
	MyTblPlnrQDvcHk1NArcguide();
	~MyTblPlnrQDvcHk1NArcguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NArcguide& rst);

	void insertRec(PlnrQDvcHk1NArcguide* rec);
	void insertRst(ListPlnrQDvcHk1NArcguide& rst);
	void updateRec(PlnrQDvcHk1NArcguide* rec);
	void updateRst(ListPlnrQDvcHk1NArcguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NArcguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NArcguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcHk1NArcguide: C++ wrapper for table TblPlnrQDvcHk1NArcguide (PgSQL database)
  */
class PgTblPlnrQDvcHk1NArcguide : public TblPlnrQDvcHk1NArcguide, public PgTable {

public:
	PgTblPlnrQDvcHk1NArcguide();
	~PgTblPlnrQDvcHk1NArcguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcHk1NArcguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcHk1NArcguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcHk1NArcguide** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcHk1NArcguide& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NArcguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NArcguide& rst);

	void insertRec(PlnrQDvcHk1NArcguide* rec);
	void insertRst(ListPlnrQDvcHk1NArcguide& rst);
	void updateRec(PlnrQDvcHk1NArcguide* rec);
	void updateRst(ListPlnrQDvcHk1NArcguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NArcguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NArcguide& rst);
};
// IP pgTbl --- END

#endif

