/**
  * \file PlnrQDvcHk1NVertex.h
  * Dbs and XML wrapper for table TblPlnrQDvcHk1NVertex (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NVERTEX_H
#define PLNRQDVCHK1NVERTEX_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NVertex: record of TblPlnrQDvcHk1NVertex
  */
class PlnrQDvcHk1NVertex {

public:
	PlnrQDvcHk1NVertex(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDvcHk1NVertex: recordset of TblPlnrQDvcHk1NVertex
  */
class ListPlnrQDvcHk1NVertex {

public:
	ListPlnrQDvcHk1NVertex();
	ListPlnrQDvcHk1NVertex(const ListPlnrQDvcHk1NVertex& src);
	~ListPlnrQDvcHk1NVertex();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcHk1NVertex* rec);

	ListPlnrQDvcHk1NVertex& operator=(const ListPlnrQDvcHk1NVertex& src);

public:
	vector<PlnrQDvcHk1NVertex*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcHk1NVertex: C++ wrapper for table TblPlnrQDvcHk1NVertex
  */
class TblPlnrQDvcHk1NVertex {

public:
	TblPlnrQDvcHk1NVertex();
	virtual ~TblPlnrQDvcHk1NVertex();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NVertex** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NVertex& rst);

	virtual void insertRec(PlnrQDvcHk1NVertex* rec);
	ubigint insertNewRec(PlnrQDvcHk1NVertex** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDvcHk1NVertex& rst, PlnrQDvcHk1NVertex** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDvcHk1NVertex& rst);
	virtual void updateRec(PlnrQDvcHk1NVertex* rec);
	virtual void updateRst(ListPlnrQDvcHk1NVertex& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcHk1NVertex** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NVertex& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcHk1NVertex: C++ wrapper for table TblPlnrQDvcHk1NVertex (MySQL database)
  */
class MyTblPlnrQDvcHk1NVertex : public TblPlnrQDvcHk1NVertex, public MyTable {

public:
	MyTblPlnrQDvcHk1NVertex();
	~MyTblPlnrQDvcHk1NVertex();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NVertex& rst);

	void insertRec(PlnrQDvcHk1NVertex* rec);
	void insertRst(ListPlnrQDvcHk1NVertex& rst);
	void updateRec(PlnrQDvcHk1NVertex* rec);
	void updateRst(ListPlnrQDvcHk1NVertex& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NVertex** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NVertex& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcHk1NVertex: C++ wrapper for table TblPlnrQDvcHk1NVertex (PgSQL database)
  */
class PgTblPlnrQDvcHk1NVertex : public TblPlnrQDvcHk1NVertex, public PgTable {

public:
	PgTblPlnrQDvcHk1NVertex();
	~PgTblPlnrQDvcHk1NVertex();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcHk1NVertex** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcHk1NVertex& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcHk1NVertex** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcHk1NVertex& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NVertex** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NVertex& rst);

	void insertRec(PlnrQDvcHk1NVertex* rec);
	void insertRst(ListPlnrQDvcHk1NVertex& rst);
	void updateRec(PlnrQDvcHk1NVertex* rec);
	void updateRst(ListPlnrQDvcHk1NVertex& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NVertex** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NVertex& rst);
};
// IP pgTbl --- END

#endif

