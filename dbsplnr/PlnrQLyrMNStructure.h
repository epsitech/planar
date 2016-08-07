/**
  * \file PlnrQLyrMNStructure.h
  * Dbs and XML wrapper for table TblPlnrQLyrMNStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYRMNSTRUCTURE_H
#define PLNRQLYRMNSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyrMNStructure: record of TblPlnrQLyrMNStructure
  */
class PlnrQLyrMNStructure {

public:
	PlnrQLyrMNStructure(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQLyrMNStructure: recordset of TblPlnrQLyrMNStructure
  */
class ListPlnrQLyrMNStructure {

public:
	ListPlnrQLyrMNStructure();
	ListPlnrQLyrMNStructure(const ListPlnrQLyrMNStructure& src);
	~ListPlnrQLyrMNStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrQLyrMNStructure* rec);

	ListPlnrQLyrMNStructure& operator=(const ListPlnrQLyrMNStructure& src);

public:
	vector<PlnrQLyrMNStructure*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQLyrMNStructure: C++ wrapper for table TblPlnrQLyrMNStructure
  */
class TblPlnrQLyrMNStructure {

public:
	TblPlnrQLyrMNStructure();
	virtual ~TblPlnrQLyrMNStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQLyrMNStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyrMNStructure& rst);

	virtual void insertRec(PlnrQLyrMNStructure* rec);
	ubigint insertNewRec(PlnrQLyrMNStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	ubigint appendNewRecToRst(ListPlnrQLyrMNStructure& rst, PlnrQLyrMNStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0);
	virtual void insertRst(ListPlnrQLyrMNStructure& rst);
	virtual void updateRec(PlnrQLyrMNStructure* rec);
	virtual void updateRst(ListPlnrQLyrMNStructure& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQLyrMNStructure** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyrMNStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQLyrMNStructure: C++ wrapper for table TblPlnrQLyrMNStructure (MySQL database)
  */
class MyTblPlnrQLyrMNStructure : public TblPlnrQLyrMNStructure, public MyTable {

public:
	MyTblPlnrQLyrMNStructure();
	~MyTblPlnrQLyrMNStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyrMNStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyrMNStructure& rst);

	void insertRec(PlnrQLyrMNStructure* rec);
	void insertRst(ListPlnrQLyrMNStructure& rst);
	void updateRec(PlnrQLyrMNStructure* rec);
	void updateRst(ListPlnrQLyrMNStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyrMNStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyrMNStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQLyrMNStructure: C++ wrapper for table TblPlnrQLyrMNStructure (PgSQL database)
  */
class PgTblPlnrQLyrMNStructure : public TblPlnrQLyrMNStructure, public PgTable {

public:
	PgTblPlnrQLyrMNStructure();
	~PgTblPlnrQLyrMNStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQLyrMNStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQLyrMNStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQLyrMNStructure** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQLyrMNStructure& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyrMNStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyrMNStructure& rst);

	void insertRec(PlnrQLyrMNStructure* rec);
	void insertRst(ListPlnrQLyrMNStructure& rst);
	void updateRec(PlnrQLyrMNStructure* rec);
	void updateRst(ListPlnrQLyrMNStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyrMNStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyrMNStructure& rst);
};
// IP pgTbl --- END

#endif

