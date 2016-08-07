/**
  * \file PlnrQDsnHk1NLineguide.h
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NLINEGUIDE_H
#define PLNRQDSNHK1NLINEGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NLineguide: record of TblPlnrQDsnHk1NLineguide
  */
class PlnrQDsnHk1NLineguide {

public:
	PlnrQDsnHk1NLineguide(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsnHk1NLineguide: recordset of TblPlnrQDsnHk1NLineguide
  */
class ListPlnrQDsnHk1NLineguide {

public:
	ListPlnrQDsnHk1NLineguide();
	ListPlnrQDsnHk1NLineguide(const ListPlnrQDsnHk1NLineguide& src);
	~ListPlnrQDsnHk1NLineguide();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnHk1NLineguide* rec);

	ListPlnrQDsnHk1NLineguide& operator=(const ListPlnrQDsnHk1NLineguide& src);

public:
	vector<PlnrQDsnHk1NLineguide*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnHk1NLineguide: C++ wrapper for table TblPlnrQDsnHk1NLineguide
  */
class TblPlnrQDsnHk1NLineguide {

public:
	TblPlnrQDsnHk1NLineguide();
	virtual ~TblPlnrQDsnHk1NLineguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLineguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLineguide& rst);

	virtual void insertRec(PlnrQDsnHk1NLineguide* rec);
	ubigint insertNewRec(PlnrQDsnHk1NLineguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnHk1NLineguide& rst, PlnrQDsnHk1NLineguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnHk1NLineguide& rst);
	virtual void updateRec(PlnrQDsnHk1NLineguide* rec);
	virtual void updateRst(ListPlnrQDsnHk1NLineguide& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLineguide** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLineguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnHk1NLineguide: C++ wrapper for table TblPlnrQDsnHk1NLineguide (MySQL database)
  */
class MyTblPlnrQDsnHk1NLineguide : public TblPlnrQDsnHk1NLineguide, public MyTable {

public:
	MyTblPlnrQDsnHk1NLineguide();
	~MyTblPlnrQDsnHk1NLineguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLineguide& rst);

	void insertRec(PlnrQDsnHk1NLineguide* rec);
	void insertRst(ListPlnrQDsnHk1NLineguide& rst);
	void updateRec(PlnrQDsnHk1NLineguide* rec);
	void updateRst(ListPlnrQDsnHk1NLineguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLineguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLineguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnHk1NLineguide: C++ wrapper for table TblPlnrQDsnHk1NLineguide (PgSQL database)
  */
class PgTblPlnrQDsnHk1NLineguide : public TblPlnrQDsnHk1NLineguide, public PgTable {

public:
	PgTblPlnrQDsnHk1NLineguide();
	~PgTblPlnrQDsnHk1NLineguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnHk1NLineguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnHk1NLineguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnHk1NLineguide** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnHk1NLineguide& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NLineguide& rst);

	void insertRec(PlnrQDsnHk1NLineguide* rec);
	void insertRst(ListPlnrQDsnHk1NLineguide& rst);
	void updateRec(PlnrQDsnHk1NLineguide* rec);
	void updateRst(ListPlnrQDsnHk1NLineguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NLineguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NLineguide& rst);
};
// IP pgTbl --- END

#endif

