/**
  * \file PlnrQAriAMArrayEnv.h
  * Dbs and XML wrapper for table TblPlnrQAriAMArrayEnv (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQARIAMARRAYENV_H
#define PLNRQARIAMARRAYENV_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQAriAMArrayEnv: record of TblPlnrQAriAMArrayEnv
  */
class PlnrQAriAMArrayEnv {

public:
	PlnrQAriAMArrayEnv(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x2SrefKKey;
	string titX2SrefKKey;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQAriAMArrayEnv: recordset of TblPlnrQAriAMArrayEnv
  */
class ListPlnrQAriAMArrayEnv {

public:
	ListPlnrQAriAMArrayEnv();
	ListPlnrQAriAMArrayEnv(const ListPlnrQAriAMArrayEnv& src);
	~ListPlnrQAriAMArrayEnv();

	void clear();
	unsigned int size() const;
	void append(PlnrQAriAMArrayEnv* rec);

	ListPlnrQAriAMArrayEnv& operator=(const ListPlnrQAriAMArrayEnv& src);

public:
	vector<PlnrQAriAMArrayEnv*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQAriAMArrayEnv: C++ wrapper for table TblPlnrQAriAMArrayEnv
  */
class TblPlnrQAriAMArrayEnv {

public:
	TblPlnrQAriAMArrayEnv();
	virtual ~TblPlnrQAriAMArrayEnv();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQAriAMArrayEnv** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQAriAMArrayEnv& rst);

	virtual void insertRec(PlnrQAriAMArrayEnv* rec);
	ubigint insertNewRec(PlnrQAriAMArrayEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQAriAMArrayEnv& rst, PlnrQAriAMArrayEnv** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const string Val = "");
	virtual void insertRst(ListPlnrQAriAMArrayEnv& rst);
	virtual void updateRec(PlnrQAriAMArrayEnv* rec);
	virtual void updateRst(ListPlnrQAriAMArrayEnv& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQAriAMArrayEnv** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQAriAMArrayEnv& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQAriAMArrayEnv: C++ wrapper for table TblPlnrQAriAMArrayEnv (MySQL database)
  */
class MyTblPlnrQAriAMArrayEnv : public TblPlnrQAriAMArrayEnv, public MyTable {

public:
	MyTblPlnrQAriAMArrayEnv();
	~MyTblPlnrQAriAMArrayEnv();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQAriAMArrayEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQAriAMArrayEnv& rst);

	void insertRec(PlnrQAriAMArrayEnv* rec);
	void insertRst(ListPlnrQAriAMArrayEnv& rst);
	void updateRec(PlnrQAriAMArrayEnv* rec);
	void updateRst(ListPlnrQAriAMArrayEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQAriAMArrayEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQAriAMArrayEnv& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQAriAMArrayEnv: C++ wrapper for table TblPlnrQAriAMArrayEnv (PgSQL database)
  */
class PgTblPlnrQAriAMArrayEnv : public TblPlnrQAriAMArrayEnv, public PgTable {

public:
	PgTblPlnrQAriAMArrayEnv();
	~PgTblPlnrQAriAMArrayEnv();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQAriAMArrayEnv** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQAriAMArrayEnv& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQAriAMArrayEnv** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQAriAMArrayEnv& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQAriAMArrayEnv** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQAriAMArrayEnv& rst);

	void insertRec(PlnrQAriAMArrayEnv* rec);
	void insertRst(ListPlnrQAriAMArrayEnv& rst);
	void updateRec(PlnrQAriAMArrayEnv* rec);
	void updateRst(ListPlnrQAriAMArrayEnv& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQAriAMArrayEnv** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQAriAMArrayEnv& rst);
};
// IP pgTbl --- END

#endif

