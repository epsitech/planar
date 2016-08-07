/**
  * \file PlnrQCtpKParCat.h
  * Dbs and XML wrapper for table TblPlnrQCtpKParCat (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKPARCAT_H
#define PLNRQCTPKPARCAT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKParCat: record of TblPlnrQCtpKParCat
  */
class PlnrQCtpKParCat {

public:
	PlnrQCtpKParCat(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	string sref;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCtpKParCat: recordset of TblPlnrQCtpKParCat
  */
class ListPlnrQCtpKParCat {

public:
	ListPlnrQCtpKParCat();
	ListPlnrQCtpKParCat(const ListPlnrQCtpKParCat& src);
	~ListPlnrQCtpKParCat();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpKParCat* rec);

	ListPlnrQCtpKParCat& operator=(const ListPlnrQCtpKParCat& src);

public:
	vector<PlnrQCtpKParCat*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpKParCat: C++ wrapper for table TblPlnrQCtpKParCat
  */
class TblPlnrQCtpKParCat {

public:
	TblPlnrQCtpKParCat();
	virtual ~TblPlnrQCtpKParCat();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpKParCat** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKParCat& rst);

	virtual void insertRec(PlnrQCtpKParCat* rec);
	ubigint insertNewRec(PlnrQCtpKParCat** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQCtpKParCat& rst, PlnrQCtpKParCat** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQCtpKParCat& rst);
	virtual void updateRec(PlnrQCtpKParCat* rec);
	virtual void updateRst(ListPlnrQCtpKParCat& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpKParCat** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKParCat& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpKParCat: C++ wrapper for table TblPlnrQCtpKParCat (MySQL database)
  */
class MyTblPlnrQCtpKParCat : public TblPlnrQCtpKParCat, public MyTable {

public:
	MyTblPlnrQCtpKParCat();
	~MyTblPlnrQCtpKParCat();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKParCat** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKParCat& rst);

	void insertRec(PlnrQCtpKParCat* rec);
	void insertRst(ListPlnrQCtpKParCat& rst);
	void updateRec(PlnrQCtpKParCat* rec);
	void updateRst(ListPlnrQCtpKParCat& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKParCat** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKParCat& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpKParCat: C++ wrapper for table TblPlnrQCtpKParCat (PgSQL database)
  */
class PgTblPlnrQCtpKParCat : public TblPlnrQCtpKParCat, public PgTable {

public:
	PgTblPlnrQCtpKParCat();
	~PgTblPlnrQCtpKParCat();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpKParCat** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpKParCat& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpKParCat** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpKParCat& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKParCat** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKParCat& rst);

	void insertRec(PlnrQCtpKParCat* rec);
	void insertRst(ListPlnrQCtpKParCat& rst);
	void updateRec(PlnrQCtpKParCat* rec);
	void updateRst(ListPlnrQCtpKParCat& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKParCat** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKParCat& rst);
};
// IP pgTbl --- END

#endif

