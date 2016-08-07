/**
  * \file PlnrQCtpKParProp.h
  * Dbs and XML wrapper for table TblPlnrQCtpKParProp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKPARPROP_H
#define PLNRQCTPKPARPROP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKParProp: record of TblPlnrQCtpKParProp
  */
class PlnrQCtpKParProp {

public:
	PlnrQCtpKParProp(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const string Avail = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	string sref;
	string Avail;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCtpKParProp: recordset of TblPlnrQCtpKParProp
  */
class ListPlnrQCtpKParProp {

public:
	ListPlnrQCtpKParProp();
	ListPlnrQCtpKParProp(const ListPlnrQCtpKParProp& src);
	~ListPlnrQCtpKParProp();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpKParProp* rec);

	ListPlnrQCtpKParProp& operator=(const ListPlnrQCtpKParProp& src);

public:
	vector<PlnrQCtpKParProp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpKParProp: C++ wrapper for table TblPlnrQCtpKParProp
  */
class TblPlnrQCtpKParProp {

public:
	TblPlnrQCtpKParProp();
	virtual ~TblPlnrQCtpKParProp();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpKParProp** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKParProp& rst);

	virtual void insertRec(PlnrQCtpKParProp* rec);
	ubigint insertNewRec(PlnrQCtpKParProp** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const string Avail = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQCtpKParProp& rst, PlnrQCtpKParProp** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const string sref = "", const string Avail = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQCtpKParProp& rst);
	virtual void updateRec(PlnrQCtpKParProp* rec);
	virtual void updateRst(ListPlnrQCtpKParProp& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpKParProp** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKParProp& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpKParProp: C++ wrapper for table TblPlnrQCtpKParProp (MySQL database)
  */
class MyTblPlnrQCtpKParProp : public TblPlnrQCtpKParProp, public MyTable {

public:
	MyTblPlnrQCtpKParProp();
	~MyTblPlnrQCtpKParProp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKParProp** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKParProp& rst);

	void insertRec(PlnrQCtpKParProp* rec);
	void insertRst(ListPlnrQCtpKParProp& rst);
	void updateRec(PlnrQCtpKParProp* rec);
	void updateRst(ListPlnrQCtpKParProp& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKParProp** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKParProp& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpKParProp: C++ wrapper for table TblPlnrQCtpKParProp (PgSQL database)
  */
class PgTblPlnrQCtpKParProp : public TblPlnrQCtpKParProp, public PgTable {

public:
	PgTblPlnrQCtpKParProp();
	~PgTblPlnrQCtpKParProp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpKParProp** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpKParProp& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpKParProp** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpKParProp& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKParProp** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKParProp& rst);

	void insertRec(PlnrQCtpKParProp* rec);
	void insertRst(ListPlnrQCtpKParProp& rst);
	void updateRec(PlnrQCtpKParProp* rec);
	void updateRst(ListPlnrQCtpKParProp& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKParProp** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKParProp& rst);
};
// IP pgTbl --- END

#endif

