/**
  * \file PlnrQDvcHk1NStructure.h
  * Dbs and XML wrapper for table TblPlnrQDvcHk1NStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDVCHK1NSTRUCTURE_H
#define PLNRQDVCHK1NSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDvcHk1NStructure: record of TblPlnrQDvcHk1NStructure
  */
class PlnrQDvcHk1NStructure {

public:
	PlnrQDvcHk1NStructure(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDvcHk1NStructure: recordset of TblPlnrQDvcHk1NStructure
  */
class ListPlnrQDvcHk1NStructure {

public:
	ListPlnrQDvcHk1NStructure();
	ListPlnrQDvcHk1NStructure(const ListPlnrQDvcHk1NStructure& src);
	~ListPlnrQDvcHk1NStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrQDvcHk1NStructure* rec);

	ListPlnrQDvcHk1NStructure& operator=(const ListPlnrQDvcHk1NStructure& src);

public:
	vector<PlnrQDvcHk1NStructure*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDvcHk1NStructure: C++ wrapper for table TblPlnrQDvcHk1NStructure
  */
class TblPlnrQDvcHk1NStructure {

public:
	TblPlnrQDvcHk1NStructure();
	virtual ~TblPlnrQDvcHk1NStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NStructure& rst);

	virtual void insertRec(PlnrQDvcHk1NStructure* rec);
	ubigint insertNewRec(PlnrQDvcHk1NStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDvcHk1NStructure& rst, PlnrQDvcHk1NStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDvcHk1NStructure& rst);
	virtual void updateRec(PlnrQDvcHk1NStructure* rec);
	virtual void updateRst(ListPlnrQDvcHk1NStructure& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDvcHk1NStructure** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDvcHk1NStructure: C++ wrapper for table TblPlnrQDvcHk1NStructure (MySQL database)
  */
class MyTblPlnrQDvcHk1NStructure : public TblPlnrQDvcHk1NStructure, public MyTable {

public:
	MyTblPlnrQDvcHk1NStructure();
	~MyTblPlnrQDvcHk1NStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NStructure& rst);

	void insertRec(PlnrQDvcHk1NStructure* rec);
	void insertRst(ListPlnrQDvcHk1NStructure& rst);
	void updateRec(PlnrQDvcHk1NStructure* rec);
	void updateRst(ListPlnrQDvcHk1NStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDvcHk1NStructure: C++ wrapper for table TblPlnrQDvcHk1NStructure (PgSQL database)
  */
class PgTblPlnrQDvcHk1NStructure : public TblPlnrQDvcHk1NStructure, public PgTable {

public:
	PgTblPlnrQDvcHk1NStructure();
	~PgTblPlnrQDvcHk1NStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDvcHk1NStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDvcHk1NStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDvcHk1NStructure** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDvcHk1NStructure& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDvcHk1NStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDvcHk1NStructure& rst);

	void insertRec(PlnrQDvcHk1NStructure* rec);
	void insertRst(ListPlnrQDvcHk1NStructure& rst);
	void updateRec(PlnrQDvcHk1NStructure* rec);
	void updateRst(ListPlnrQDvcHk1NStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDvcHk1NStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDvcHk1NStructure& rst);
};
// IP pgTbl --- END

#endif

