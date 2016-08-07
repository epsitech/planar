/**
  * \file PlnrQClcCal1NCalcitem.h
  * Dbs and XML wrapper for table TblPlnrQClcCal1NCalcitem (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCCAL1NCALCITEM_H
#define PLNRQCLCCAL1NCALCITEM_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcCal1NCalcitem: record of TblPlnrQClcCal1NCalcitem
  */
class PlnrQClcCal1NCalcitem {

public:
	PlnrQClcCal1NCalcitem(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint calNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint calNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQClcCal1NCalcitem: recordset of TblPlnrQClcCal1NCalcitem
  */
class ListPlnrQClcCal1NCalcitem {

public:
	ListPlnrQClcCal1NCalcitem();
	ListPlnrQClcCal1NCalcitem(const ListPlnrQClcCal1NCalcitem& src);
	~ListPlnrQClcCal1NCalcitem();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcCal1NCalcitem* rec);

	ListPlnrQClcCal1NCalcitem& operator=(const ListPlnrQClcCal1NCalcitem& src);

public:
	vector<PlnrQClcCal1NCalcitem*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcCal1NCalcitem: C++ wrapper for table TblPlnrQClcCal1NCalcitem
  */
class TblPlnrQClcCal1NCalcitem {

public:
	TblPlnrQClcCal1NCalcitem();
	virtual ~TblPlnrQClcCal1NCalcitem();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcCal1NCalcitem** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcCal1NCalcitem& rst);

	virtual void insertRec(PlnrQClcCal1NCalcitem* rec);
	ubigint insertNewRec(PlnrQClcCal1NCalcitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint calNum = 0);
	ubigint appendNewRecToRst(ListPlnrQClcCal1NCalcitem& rst, PlnrQClcCal1NCalcitem** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint calNum = 0);
	virtual void insertRst(ListPlnrQClcCal1NCalcitem& rst);
	virtual void updateRec(PlnrQClcCal1NCalcitem* rec);
	virtual void updateRst(ListPlnrQClcCal1NCalcitem& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcCal1NCalcitem** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcCal1NCalcitem& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcCal1NCalcitem: C++ wrapper for table TblPlnrQClcCal1NCalcitem (MySQL database)
  */
class MyTblPlnrQClcCal1NCalcitem : public TblPlnrQClcCal1NCalcitem, public MyTable {

public:
	MyTblPlnrQClcCal1NCalcitem();
	~MyTblPlnrQClcCal1NCalcitem();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcCal1NCalcitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcCal1NCalcitem& rst);

	void insertRec(PlnrQClcCal1NCalcitem* rec);
	void insertRst(ListPlnrQClcCal1NCalcitem& rst);
	void updateRec(PlnrQClcCal1NCalcitem* rec);
	void updateRst(ListPlnrQClcCal1NCalcitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcCal1NCalcitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcCal1NCalcitem& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcCal1NCalcitem: C++ wrapper for table TblPlnrQClcCal1NCalcitem (PgSQL database)
  */
class PgTblPlnrQClcCal1NCalcitem : public TblPlnrQClcCal1NCalcitem, public PgTable {

public:
	PgTblPlnrQClcCal1NCalcitem();
	~PgTblPlnrQClcCal1NCalcitem();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcCal1NCalcitem** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcCal1NCalcitem& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcCal1NCalcitem** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcCal1NCalcitem& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcCal1NCalcitem** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcCal1NCalcitem& rst);

	void insertRec(PlnrQClcCal1NCalcitem* rec);
	void insertRst(ListPlnrQClcCal1NCalcitem& rst);
	void updateRec(PlnrQClcCal1NCalcitem* rec);
	void updateRst(ListPlnrQClcCal1NCalcitem& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcCal1NCalcitem** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcCal1NCalcitem& rst);
};
// IP pgTbl --- END

#endif

