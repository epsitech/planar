/**
  * \file PlnrQArrAEnv.h
  * Dbs and XML wrapper for table TblPlnrQArrAEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARRAENV_H
#define PLNRQARRAENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQArrAEnv: record of TblPlnrQArrAEnv
  */
class PlnrQArrAEnv {

public:
	PlnrQArrAEnv(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMArrayitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefPlnrMArrayitem;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQArrAEnv: recordset of TblPlnrQArrAEnv
  */
class ListPlnrQArrAEnv {

public:
	ListPlnrQArrAEnv();
	ListPlnrQArrAEnv(const ListPlnrQArrAEnv& src);
	~ListPlnrQArrAEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrQArrAEnv* rec);

	ListPlnrQArrAEnv& operator=(const ListPlnrQArrAEnv& src);

public:
	vector<PlnrQArrAEnv*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQArrAEnv: C++ wrapper for table TblPlnrQArrAEnv
  */
class TblPlnrQArrAEnv {

public:
	TblPlnrQArrAEnv();
	virtual ~TblPlnrQArrAEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQArrAEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrAEnv& rst);

	virtual void insertRec(PlnrQArrAEnv* rec);
	ubigint insertNewRec(PlnrQArrAEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMArrayitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQArrAEnv& rst, PlnrQArrAEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMArrayitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrQArrAEnv& rst);
	virtual void updateRec(PlnrQArrAEnv* rec);
	virtual void updateRst(ListPlnrQArrAEnv& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQArrAEnv** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrAEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQArrAEnv: C++ wrapper for table TblPlnrQArrAEnv (MySQL database)
  */
class MyTblPlnrQArrAEnv : public TblPlnrQArrAEnv, public MyTable {

public:
	MyTblPlnrQArrAEnv();
	~MyTblPlnrQArrAEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrAEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrAEnv& rst);

	void insertRec(PlnrQArrAEnv* rec);
	void insertRst(ListPlnrQArrAEnv& rst);
	void updateRec(PlnrQArrAEnv* rec);
	void updateRst(ListPlnrQArrAEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrAEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrAEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQArrAEnv: C++ wrapper for table TblPlnrQArrAEnv (PgSQL database)
  */
class PgTblPlnrQArrAEnv : public TblPlnrQArrAEnv, public PgTable {

public:
	PgTblPlnrQArrAEnv();
	~PgTblPlnrQArrAEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQArrAEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQArrAEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQArrAEnv** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQArrAEnv& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQArrAEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQArrAEnv& rst);

	void insertRec(PlnrQArrAEnv* rec);
	void insertRst(ListPlnrQArrAEnv& rst);
	void updateRec(PlnrQArrAEnv* rec);
	void updateRst(ListPlnrQArrAEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQArrAEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQArrAEnv& rst);
};
// IP pgTbl --- END

#endif

