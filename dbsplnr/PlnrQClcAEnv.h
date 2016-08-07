/**
  * \file PlnrQClcAEnv.h
  * Dbs and XML wrapper for table TblPlnrQClcAEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCAENV_H
#define PLNRQCLCAENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcAEnv: record of TblPlnrQClcAEnv
  */
class PlnrQClcAEnv {

public:
	PlnrQClcAEnv(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

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
  * ListPlnrQClcAEnv: recordset of TblPlnrQClcAEnv
  */
class ListPlnrQClcAEnv {

public:
	ListPlnrQClcAEnv();
	ListPlnrQClcAEnv(const ListPlnrQClcAEnv& src);
	~ListPlnrQClcAEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcAEnv* rec);

	ListPlnrQClcAEnv& operator=(const ListPlnrQClcAEnv& src);

public:
	vector<PlnrQClcAEnv*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcAEnv: C++ wrapper for table TblPlnrQClcAEnv
  */
class TblPlnrQClcAEnv {

public:
	TblPlnrQClcAEnv();
	virtual ~TblPlnrQClcAEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcAEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcAEnv& rst);

	virtual void insertRec(PlnrQClcAEnv* rec);
	ubigint insertNewRec(PlnrQClcAEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQClcAEnv& rst, PlnrQClcAEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrQClcAEnv& rst);
	virtual void updateRec(PlnrQClcAEnv* rec);
	virtual void updateRst(ListPlnrQClcAEnv& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcAEnv** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcAEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcAEnv: C++ wrapper for table TblPlnrQClcAEnv (MySQL database)
  */
class MyTblPlnrQClcAEnv : public TblPlnrQClcAEnv, public MyTable {

public:
	MyTblPlnrQClcAEnv();
	~MyTblPlnrQClcAEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcAEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcAEnv& rst);

	void insertRec(PlnrQClcAEnv* rec);
	void insertRst(ListPlnrQClcAEnv& rst);
	void updateRec(PlnrQClcAEnv* rec);
	void updateRst(ListPlnrQClcAEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcAEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcAEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcAEnv: C++ wrapper for table TblPlnrQClcAEnv (PgSQL database)
  */
class PgTblPlnrQClcAEnv : public TblPlnrQClcAEnv, public PgTable {

public:
	PgTblPlnrQClcAEnv();
	~PgTblPlnrQClcAEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcAEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcAEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcAEnv** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcAEnv& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcAEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcAEnv& rst);

	void insertRec(PlnrQClcAEnv* rec);
	void insertRst(ListPlnrQClcAEnv& rst);
	void updateRec(PlnrQClcAEnv* rec);
	void updateRst(ListPlnrQClcAEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcAEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcAEnv& rst);
};
// IP pgTbl --- END

#endif

