/**
  * \file PlnrQArr1NArrayitem.h
  * Dbs and XML wrapper for table TblPlnrQArr1NArrayitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARR1NARRAYITEM_H
#define PLNRQARR1NARRAYITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArr1NArrayitem: record of TblPlnrQArr1NArrayitem
  */
class PlnrQArr1NArrayitem {

public:
	PlnrQArr1NArrayitem(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQArr1NArrayitem: recordset of TblPlnrQArr1NArrayitem
  */
class ListPlnrQArr1NArrayitem {

public:
	ListPlnrQArr1NArrayitem();
	ListPlnrQArr1NArrayitem(const ListPlnrQArr1NArrayitem& src);
	~ListPlnrQArr1NArrayitem();

	void clear();
	unsigned int size() const;
	void append(PlnrQArr1NArrayitem* rec);

	ListPlnrQArr1NArrayitem& operator=(const ListPlnrQArr1NArrayitem& src);

public:
	vector<PlnrQArr1NArrayitem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQArr1NArrayitem: C++ wrapper for table TblPlnrQArr1NArrayitem
  */
class TblPlnrQArr1NArrayitem {

public:
	TblPlnrQArr1NArrayitem();
	virtual ~TblPlnrQArr1NArrayitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQArr1NArrayitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArr1NArrayitem& rst);

	virtual void insertRec(PlnrQArr1NArrayitem* rec);
	ubigint insertNewRec(PlnrQArr1NArrayitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQArr1NArrayitem& rst, PlnrQArr1NArrayitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQArr1NArrayitem& rst);
	virtual void updateRec(PlnrQArr1NArrayitem* rec);
	virtual void updateRst(ListPlnrQArr1NArrayitem& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQArr1NArrayitem** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArr1NArrayitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQArr1NArrayitem: C++ wrapper for table TblPlnrQArr1NArrayitem (MySQL database)
  */
class MyTblPlnrQArr1NArrayitem : public TblPlnrQArr1NArrayitem, public MyTable {

public:
	MyTblPlnrQArr1NArrayitem();
	~MyTblPlnrQArr1NArrayitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArr1NArrayitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArr1NArrayitem& rst);

	void insertRec(PlnrQArr1NArrayitem* rec);
	void insertRst(ListPlnrQArr1NArrayitem& rst);
	void updateRec(PlnrQArr1NArrayitem* rec);
	void updateRst(ListPlnrQArr1NArrayitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArr1NArrayitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArr1NArrayitem& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQArr1NArrayitem: C++ wrapper for table TblPlnrQArr1NArrayitem (PgSQL database)
  */
class PgTblPlnrQArr1NArrayitem : public TblPlnrQArr1NArrayitem, public PgTable {

public:
	PgTblPlnrQArr1NArrayitem();
	~PgTblPlnrQArr1NArrayitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQArr1NArrayitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQArr1NArrayitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQArr1NArrayitem** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQArr1NArrayitem& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArr1NArrayitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArr1NArrayitem& rst);

	void insertRec(PlnrQArr1NArrayitem* rec);
	void insertRst(ListPlnrQArr1NArrayitem& rst);
	void updateRec(PlnrQArr1NArrayitem* rec);
	void updateRst(ListPlnrQArr1NArrayitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArr1NArrayitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArr1NArrayitem& rst);
};
// IP pgTbl --- END

#endif

