/**
  * \file PlnrQCtpKCalcdomprp.h
  * Dbs and XML wrapper for table TblPlnrQCtpKCalcdomprp (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKCALCDOMPRP_H
#define PLNRQCTPKCALCDOMPRP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKCalcdomprp: record of TblPlnrQCtpKCalcdomprp
  */
class PlnrQCtpKCalcdomprp {

public:
	PlnrQCtpKCalcdomprp(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint klsNum;
	bool Fixed;
	string yesnoFixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQCtpKCalcdomprp: recordset of TblPlnrQCtpKCalcdomprp
  */
class ListPlnrQCtpKCalcdomprp {

public:
	ListPlnrQCtpKCalcdomprp();
	ListPlnrQCtpKCalcdomprp(const ListPlnrQCtpKCalcdomprp& src);
	~ListPlnrQCtpKCalcdomprp();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpKCalcdomprp* rec);

	ListPlnrQCtpKCalcdomprp& operator=(const ListPlnrQCtpKCalcdomprp& src);

public:
	vector<PlnrQCtpKCalcdomprp*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpKCalcdomprp: C++ wrapper for table TblPlnrQCtpKCalcdomprp
  */
class TblPlnrQCtpKCalcdomprp {

public:
	TblPlnrQCtpKCalcdomprp();
	virtual ~TblPlnrQCtpKCalcdomprp();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpKCalcdomprp** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKCalcdomprp& rst);

	virtual void insertRec(PlnrQCtpKCalcdomprp* rec);
	ubigint insertNewRec(PlnrQCtpKCalcdomprp** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQCtpKCalcdomprp& rst, PlnrQCtpKCalcdomprp** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQCtpKCalcdomprp& rst);
	virtual void updateRec(PlnrQCtpKCalcdomprp* rec);
	virtual void updateRst(ListPlnrQCtpKCalcdomprp& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpKCalcdomprp** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKCalcdomprp& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpKCalcdomprp: C++ wrapper for table TblPlnrQCtpKCalcdomprp (MySQL database)
  */
class MyTblPlnrQCtpKCalcdomprp : public TblPlnrQCtpKCalcdomprp, public MyTable {

public:
	MyTblPlnrQCtpKCalcdomprp();
	~MyTblPlnrQCtpKCalcdomprp();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKCalcdomprp** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKCalcdomprp& rst);

	void insertRec(PlnrQCtpKCalcdomprp* rec);
	void insertRst(ListPlnrQCtpKCalcdomprp& rst);
	void updateRec(PlnrQCtpKCalcdomprp* rec);
	void updateRst(ListPlnrQCtpKCalcdomprp& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKCalcdomprp** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKCalcdomprp& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpKCalcdomprp: C++ wrapper for table TblPlnrQCtpKCalcdomprp (PgSQL database)
  */
class PgTblPlnrQCtpKCalcdomprp : public TblPlnrQCtpKCalcdomprp, public PgTable {

public:
	PgTblPlnrQCtpKCalcdomprp();
	~PgTblPlnrQCtpKCalcdomprp();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpKCalcdomprp** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpKCalcdomprp& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpKCalcdomprp** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpKCalcdomprp& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKCalcdomprp** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKCalcdomprp& rst);

	void insertRec(PlnrQCtpKCalcdomprp* rec);
	void insertRst(ListPlnrQCtpKCalcdomprp& rst);
	void updateRec(PlnrQCtpKCalcdomprp* rec);
	void updateRst(ListPlnrQCtpKCalcdomprp& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKCalcdomprp** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKCalcdomprp& rst);
};
// IP pgTbl --- END

#endif

