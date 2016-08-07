/**
  * \file PlnrQCtpKCalcvar.h
  * Dbs and XML wrapper for table TblPlnrQCtpKCalcvar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPKCALCVAR_H
#define PLNRQCTPKCALCVAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpKCalcvar: record of TblPlnrQCtpKCalcvar
  */
class PlnrQCtpKCalcvar {

public:
	PlnrQCtpKCalcvar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

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
  * ListPlnrQCtpKCalcvar: recordset of TblPlnrQCtpKCalcvar
  */
class ListPlnrQCtpKCalcvar {

public:
	ListPlnrQCtpKCalcvar();
	ListPlnrQCtpKCalcvar(const ListPlnrQCtpKCalcvar& src);
	~ListPlnrQCtpKCalcvar();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpKCalcvar* rec);

	ListPlnrQCtpKCalcvar& operator=(const ListPlnrQCtpKCalcvar& src);

public:
	vector<PlnrQCtpKCalcvar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpKCalcvar: C++ wrapper for table TblPlnrQCtpKCalcvar
  */
class TblPlnrQCtpKCalcvar {

public:
	TblPlnrQCtpKCalcvar();
	virtual ~TblPlnrQCtpKCalcvar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpKCalcvar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKCalcvar& rst);

	virtual void insertRec(PlnrQCtpKCalcvar* rec);
	ubigint insertNewRec(PlnrQCtpKCalcvar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrQCtpKCalcvar& rst, PlnrQCtpKCalcvar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint klsNum = 0, const bool Fixed = false, const string yesnoFixed = "", const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrQCtpKCalcvar& rst);
	virtual void updateRec(PlnrQCtpKCalcvar* rec);
	virtual void updateRst(ListPlnrQCtpKCalcvar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpKCalcvar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKCalcvar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpKCalcvar: C++ wrapper for table TblPlnrQCtpKCalcvar (MySQL database)
  */
class MyTblPlnrQCtpKCalcvar : public TblPlnrQCtpKCalcvar, public MyTable {

public:
	MyTblPlnrQCtpKCalcvar();
	~MyTblPlnrQCtpKCalcvar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKCalcvar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKCalcvar& rst);

	void insertRec(PlnrQCtpKCalcvar* rec);
	void insertRst(ListPlnrQCtpKCalcvar& rst);
	void updateRec(PlnrQCtpKCalcvar* rec);
	void updateRst(ListPlnrQCtpKCalcvar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKCalcvar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKCalcvar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpKCalcvar: C++ wrapper for table TblPlnrQCtpKCalcvar (PgSQL database)
  */
class PgTblPlnrQCtpKCalcvar : public TblPlnrQCtpKCalcvar, public PgTable {

public:
	PgTblPlnrQCtpKCalcvar();
	~PgTblPlnrQCtpKCalcvar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpKCalcvar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpKCalcvar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpKCalcvar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpKCalcvar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpKCalcvar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpKCalcvar& rst);

	void insertRec(PlnrQCtpKCalcvar* rec);
	void insertRst(ListPlnrQCtpKCalcvar& rst);
	void updateRec(PlnrQCtpKCalcvar* rec);
	void updateRst(ListPlnrQCtpKCalcvar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpKCalcvar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpKCalcvar& rst);
};
// IP pgTbl --- END

#endif

