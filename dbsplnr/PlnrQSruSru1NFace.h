/**
  * \file PlnrQSruSru1NFace.h
  * Dbs and XML wrapper for table TblPlnrQSruSru1NFace (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRUSRU1NFACE_H
#define PLNRQSRUSRU1NFACE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruSru1NFace: record of TblPlnrQSruSru1NFace
  */
class PlnrQSruSru1NFace {

public:
	PlnrQSruSru1NFace(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQSruSru1NFace: recordset of TblPlnrQSruSru1NFace
  */
class ListPlnrQSruSru1NFace {

public:
	ListPlnrQSruSru1NFace();
	ListPlnrQSruSru1NFace(const ListPlnrQSruSru1NFace& src);
	~ListPlnrQSruSru1NFace();

	void clear();
	unsigned int size() const;
	void append(PlnrQSruSru1NFace* rec);

	ListPlnrQSruSru1NFace& operator=(const ListPlnrQSruSru1NFace& src);

public:
	vector<PlnrQSruSru1NFace*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQSruSru1NFace: C++ wrapper for table TblPlnrQSruSru1NFace
  */
class TblPlnrQSruSru1NFace {

public:
	TblPlnrQSruSru1NFace();
	virtual ~TblPlnrQSruSru1NFace();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQSruSru1NFace** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruSru1NFace& rst);

	virtual void insertRec(PlnrQSruSru1NFace* rec);
	ubigint insertNewRec(PlnrQSruSru1NFace** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQSruSru1NFace& rst, PlnrQSruSru1NFace** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQSruSru1NFace& rst);
	virtual void updateRec(PlnrQSruSru1NFace* rec);
	virtual void updateRst(ListPlnrQSruSru1NFace& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQSruSru1NFace** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruSru1NFace& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQSruSru1NFace: C++ wrapper for table TblPlnrQSruSru1NFace (MySQL database)
  */
class MyTblPlnrQSruSru1NFace : public TblPlnrQSruSru1NFace, public MyTable {

public:
	MyTblPlnrQSruSru1NFace();
	~MyTblPlnrQSruSru1NFace();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruSru1NFace** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruSru1NFace& rst);

	void insertRec(PlnrQSruSru1NFace* rec);
	void insertRst(ListPlnrQSruSru1NFace& rst);
	void updateRec(PlnrQSruSru1NFace* rec);
	void updateRst(ListPlnrQSruSru1NFace& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruSru1NFace** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruSru1NFace& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQSruSru1NFace: C++ wrapper for table TblPlnrQSruSru1NFace (PgSQL database)
  */
class PgTblPlnrQSruSru1NFace : public TblPlnrQSruSru1NFace, public PgTable {

public:
	PgTblPlnrQSruSru1NFace();
	~PgTblPlnrQSruSru1NFace();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQSruSru1NFace** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQSruSru1NFace& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQSruSru1NFace** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQSruSru1NFace& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruSru1NFace** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruSru1NFace& rst);

	void insertRec(PlnrQSruSru1NFace* rec);
	void insertRst(ListPlnrQSruSru1NFace& rst);
	void updateRec(PlnrQSruSru1NFace* rec);
	void updateRst(ListPlnrQSruSru1NFace& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruSru1NFace** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruSru1NFace& rst);
};
// IP pgTbl --- END

#endif

