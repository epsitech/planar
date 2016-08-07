/**
  * \file PlnrQSruList.h
  * Dbs and XML wrapper for table TblPlnrQSruList (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRULIST_H
#define PLNRQSRULIST_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruList: record of TblPlnrQSruList
  */
class PlnrQSruList {

public:
	PlnrQSruList(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string sref;
	uint hkIxVTbl;
	string srefHkIxVTbl;
	string titHkIxVTbl;
	ubigint hkUref;
	string stubHkUref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQSruList: recordset of TblPlnrQSruList
  */
class ListPlnrQSruList {

public:
	ListPlnrQSruList();
	ListPlnrQSruList(const ListPlnrQSruList& src);
	~ListPlnrQSruList();

	void clear();
	unsigned int size() const;
	void append(PlnrQSruList* rec);

	ListPlnrQSruList& operator=(const ListPlnrQSruList& src);

public:
	vector<PlnrQSruList*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQSruList: C++ wrapper for table TblPlnrQSruList
  */
class TblPlnrQSruList {

public:
	TblPlnrQSruList();
	virtual ~TblPlnrQSruList();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQSruList** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruList& rst);

	virtual void insertRec(PlnrQSruList* rec);
	ubigint insertNewRec(PlnrQSruList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "");
	ubigint appendNewRecToRst(ListPlnrQSruList& rst, PlnrQSruList** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string sref = "", const uint hkIxVTbl = 0, const string srefHkIxVTbl = "", const string titHkIxVTbl = "", const ubigint hkUref = 0, const string stubHkUref = "");
	virtual void insertRst(ListPlnrQSruList& rst);
	virtual void updateRec(PlnrQSruList* rec);
	virtual void updateRst(ListPlnrQSruList& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQSruList** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruList& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQSruList: C++ wrapper for table TblPlnrQSruList (MySQL database)
  */
class MyTblPlnrQSruList : public TblPlnrQSruList, public MyTable {

public:
	MyTblPlnrQSruList();
	~MyTblPlnrQSruList();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruList& rst);

	void insertRec(PlnrQSruList* rec);
	void insertRst(ListPlnrQSruList& rst);
	void updateRec(PlnrQSruList* rec);
	void updateRst(ListPlnrQSruList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruList& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQSruList: C++ wrapper for table TblPlnrQSruList (PgSQL database)
  */
class PgTblPlnrQSruList : public TblPlnrQSruList, public PgTable {

public:
	PgTblPlnrQSruList();
	~PgTblPlnrQSruList();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQSruList** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQSruList& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQSruList** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQSruList& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruList** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruList& rst);

	void insertRec(PlnrQSruList* rec);
	void insertRst(ListPlnrQSruList& rst);
	void updateRec(PlnrQSruList* rec);
	void updateRst(ListPlnrQSruList& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruList** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruList& rst);
};
// IP pgTbl --- END

#endif

