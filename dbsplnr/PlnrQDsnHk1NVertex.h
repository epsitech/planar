/**
  * \file PlnrQDsnHk1NVertex.h
  * Dbs and XML wrapper for table TblPlnrQDsnHk1NVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNHK1NVERTEX_H
#define PLNRQDSNHK1NVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnHk1NVertex: record of TblPlnrQDsnHk1NVertex
  */
class PlnrQDsnHk1NVertex {

public:
	PlnrQDsnHk1NVertex(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDsnHk1NVertex: recordset of TblPlnrQDsnHk1NVertex
  */
class ListPlnrQDsnHk1NVertex {

public:
	ListPlnrQDsnHk1NVertex();
	ListPlnrQDsnHk1NVertex(const ListPlnrQDsnHk1NVertex& src);
	~ListPlnrQDsnHk1NVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnHk1NVertex* rec);

	ListPlnrQDsnHk1NVertex& operator=(const ListPlnrQDsnHk1NVertex& src);

public:
	vector<PlnrQDsnHk1NVertex*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnHk1NVertex: C++ wrapper for table TblPlnrQDsnHk1NVertex
  */
class TblPlnrQDsnHk1NVertex {

public:
	TblPlnrQDsnHk1NVertex();
	virtual ~TblPlnrQDsnHk1NVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NVertex& rst);

	virtual void insertRec(PlnrQDsnHk1NVertex* rec);
	ubigint insertNewRec(PlnrQDsnHk1NVertex** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDsnHk1NVertex& rst, PlnrQDsnHk1NVertex** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDsnHk1NVertex& rst);
	virtual void updateRec(PlnrQDsnHk1NVertex* rec);
	virtual void updateRst(ListPlnrQDsnHk1NVertex& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnHk1NVertex** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnHk1NVertex: C++ wrapper for table TblPlnrQDsnHk1NVertex (MySQL database)
  */
class MyTblPlnrQDsnHk1NVertex : public TblPlnrQDsnHk1NVertex, public MyTable {

public:
	MyTblPlnrQDsnHk1NVertex();
	~MyTblPlnrQDsnHk1NVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NVertex& rst);

	void insertRec(PlnrQDsnHk1NVertex* rec);
	void insertRst(ListPlnrQDsnHk1NVertex& rst);
	void updateRec(PlnrQDsnHk1NVertex* rec);
	void updateRst(ListPlnrQDsnHk1NVertex& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NVertex** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnHk1NVertex: C++ wrapper for table TblPlnrQDsnHk1NVertex (PgSQL database)
  */
class PgTblPlnrQDsnHk1NVertex : public TblPlnrQDsnHk1NVertex, public PgTable {

public:
	PgTblPlnrQDsnHk1NVertex();
	~PgTblPlnrQDsnHk1NVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnHk1NVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnHk1NVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnHk1NVertex** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnHk1NVertex& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnHk1NVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnHk1NVertex& rst);

	void insertRec(PlnrQDsnHk1NVertex* rec);
	void insertRst(ListPlnrQDsnHk1NVertex& rst);
	void updateRec(PlnrQDsnHk1NVertex* rec);
	void updateRst(ListPlnrQDsnHk1NVertex& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnHk1NVertex** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnHk1NVertex& rst);
};
// IP pgTbl --- END

#endif

