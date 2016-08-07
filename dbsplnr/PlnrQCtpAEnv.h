/**
  * \file PlnrQCtpAEnv.h
  * Dbs and XML wrapper for table TblPlnrQCtpAEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPAENV_H
#define PLNRQCTPAENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpAEnv: record of TblPlnrQCtpAEnv
  */
class PlnrQCtpAEnv {

public:
	PlnrQCtpAEnv(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	ubigint x1RefPlnrMCalcitem;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCtpAEnv: recordset of TblPlnrQCtpAEnv
  */
class ListPlnrQCtpAEnv {

public:
	ListPlnrQCtpAEnv();
	ListPlnrQCtpAEnv(const ListPlnrQCtpAEnv& src);
	~ListPlnrQCtpAEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpAEnv* rec);

	ListPlnrQCtpAEnv& operator=(const ListPlnrQCtpAEnv& src);

public:
	vector<PlnrQCtpAEnv*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpAEnv: C++ wrapper for table TblPlnrQCtpAEnv
  */
class TblPlnrQCtpAEnv {

public:
	TblPlnrQCtpAEnv();
	virtual ~TblPlnrQCtpAEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpAEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpAEnv& rst);

	virtual void insertRec(PlnrQCtpAEnv* rec);
	ubigint insertNewRec(PlnrQCtpAEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQCtpAEnv& rst, PlnrQCtpAEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrQCtpAEnv& rst);
	virtual void updateRec(PlnrQCtpAEnv* rec);
	virtual void updateRst(ListPlnrQCtpAEnv& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpAEnv** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpAEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpAEnv: C++ wrapper for table TblPlnrQCtpAEnv (MySQL database)
  */
class MyTblPlnrQCtpAEnv : public TblPlnrQCtpAEnv, public MyTable {

public:
	MyTblPlnrQCtpAEnv();
	~MyTblPlnrQCtpAEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpAEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpAEnv& rst);

	void insertRec(PlnrQCtpAEnv* rec);
	void insertRst(ListPlnrQCtpAEnv& rst);
	void updateRec(PlnrQCtpAEnv* rec);
	void updateRst(ListPlnrQCtpAEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpAEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpAEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpAEnv: C++ wrapper for table TblPlnrQCtpAEnv (PgSQL database)
  */
class PgTblPlnrQCtpAEnv : public TblPlnrQCtpAEnv, public PgTable {

public:
	PgTblPlnrQCtpAEnv();
	~PgTblPlnrQCtpAEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpAEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpAEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpAEnv** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpAEnv& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpAEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpAEnv& rst);

	void insertRec(PlnrQCtpAEnv* rec);
	void insertRst(ListPlnrQCtpAEnv& rst);
	void updateRec(PlnrQCtpAEnv* rec);
	void updateRst(ListPlnrQCtpAEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpAEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpAEnv& rst);
};
// IP pgTbl --- END

#endif

