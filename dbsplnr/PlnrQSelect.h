/**
  * \file PlnrQSelect.h
  * Dbs and XML wrapper for table TblPlnrQSelect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSELECT_H
#define PLNRQSELECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSelect: record of TblPlnrQSelect
  */
class PlnrQSelect {

public:
	PlnrQSelect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	uint ix;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQSelect: recordset of TblPlnrQSelect
  */
class ListPlnrQSelect {

public:
	ListPlnrQSelect();
	ListPlnrQSelect(const ListPlnrQSelect& src);
	~ListPlnrQSelect();

	void clear();
	unsigned int size() const;
	void append(PlnrQSelect* rec);

	ListPlnrQSelect& operator=(const ListPlnrQSelect& src);

public:
	vector<PlnrQSelect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQSelect: C++ wrapper for table TblPlnrQSelect
  */
class TblPlnrQSelect {

public:
	TblPlnrQSelect();
	virtual ~TblPlnrQSelect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQSelect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSelect& rst);

	virtual void insertRec(PlnrQSelect* rec);
	ubigint insertNewRec(PlnrQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListPlnrQSelect& rst, PlnrQSelect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const uint ix = 0, const ubigint ref = 0);
	virtual void insertRst(ListPlnrQSelect& rst);
	virtual void updateRec(PlnrQSelect* rec);
	virtual void updateRst(ListPlnrQSelect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQSelect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSelect& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQSelect: C++ wrapper for table TblPlnrQSelect (MySQL database)
  */
class MyTblPlnrQSelect : public TblPlnrQSelect, public MyTable {

public:
	MyTblPlnrQSelect();
	~MyTblPlnrQSelect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSelect& rst);

	void insertRec(PlnrQSelect* rec);
	void insertRst(ListPlnrQSelect& rst);
	void updateRec(PlnrQSelect* rec);
	void updateRst(ListPlnrQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSelect& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQSelect: C++ wrapper for table TblPlnrQSelect (PgSQL database)
  */
class PgTblPlnrQSelect : public TblPlnrQSelect, public PgTable {

public:
	PgTblPlnrQSelect();
	~PgTblPlnrQSelect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQSelect** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQSelect& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQSelect** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQSelect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSelect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSelect& rst);

	void insertRec(PlnrQSelect* rec);
	void insertRst(ListPlnrQSelect& rst);
	void updateRec(PlnrQSelect* rec);
	void updateRst(ListPlnrQSelect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSelect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSelect& rst);
};
// IP pgTbl --- END

#endif

