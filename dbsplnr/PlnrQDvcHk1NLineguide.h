/**
  * \file PlnrQDvcHk1NLineguide.h
  * Dbs and XML wrapper for table TblPlnrQDvcHk1NLineguide (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NLINEGUIDE_H
#define PLNRQDVCHK1NLINEGUIDE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NLineguide: record of TblPlnrQDvcHk1NLineguide
  */
class PlnrQDvcHk1NLineguide {

public:
	PlnrQDvcHk1NLineguide(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDvcHk1NLineguide: recordset of TblPlnrQDvcHk1NLineguide
  */
class ListPlnrQDvcHk1NLineguide {

public:
	ListPlnrQDvcHk1NLineguide();
	ListPlnrQDvcHk1NLineguide(const ListPlnrQDvcHk1NLineguide& src);
	~ListPlnrQDvcHk1NLineguide();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcHk1NLineguide* rec);

	ListPlnrQDvcHk1NLineguide& operator=(const ListPlnrQDvcHk1NLineguide& src);

public:
	vector<PlnrQDvcHk1NLineguide*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcHk1NLineguide: C++ wrapper for table TblPlnrQDvcHk1NLineguide
  */
class TblPlnrQDvcHk1NLineguide {

public:
	TblPlnrQDvcHk1NLineguide();
	virtual ~TblPlnrQDvcHk1NLineguide();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NLineguide** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NLineguide& rst);

	virtual void insertRec(PlnrQDvcHk1NLineguide* rec);
	ubigint insertNewRec(PlnrQDvcHk1NLineguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDvcHk1NLineguide& rst, PlnrQDvcHk1NLineguide** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDvcHk1NLineguide& rst);
	virtual void updateRec(PlnrQDvcHk1NLineguide* rec);
	virtual void updateRst(ListPlnrQDvcHk1NLineguide& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcHk1NLineguide** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NLineguide& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcHk1NLineguide: C++ wrapper for table TblPlnrQDvcHk1NLineguide (MySQL database)
  */
class MyTblPlnrQDvcHk1NLineguide : public TblPlnrQDvcHk1NLineguide, public MyTable {

public:
	MyTblPlnrQDvcHk1NLineguide();
	~MyTblPlnrQDvcHk1NLineguide();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NLineguide& rst);

	void insertRec(PlnrQDvcHk1NLineguide* rec);
	void insertRst(ListPlnrQDvcHk1NLineguide& rst);
	void updateRec(PlnrQDvcHk1NLineguide* rec);
	void updateRst(ListPlnrQDvcHk1NLineguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NLineguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NLineguide& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcHk1NLineguide: C++ wrapper for table TblPlnrQDvcHk1NLineguide (PgSQL database)
  */
class PgTblPlnrQDvcHk1NLineguide : public TblPlnrQDvcHk1NLineguide, public PgTable {

public:
	PgTblPlnrQDvcHk1NLineguide();
	~PgTblPlnrQDvcHk1NLineguide();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcHk1NLineguide** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcHk1NLineguide& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcHk1NLineguide** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcHk1NLineguide& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NLineguide** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NLineguide& rst);

	void insertRec(PlnrQDvcHk1NLineguide* rec);
	void insertRst(ListPlnrQDvcHk1NLineguide& rst);
	void updateRec(PlnrQDvcHk1NLineguide* rec);
	void updateRst(ListPlnrQDvcHk1NLineguide& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NLineguide** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NLineguide& rst);
};
// IP pgTbl --- END

#endif

