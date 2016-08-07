/**
  * \file PlnrQDtpAPar.h
  * Dbs and XML wrapper for table TblPlnrQDtpAPar (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPAPAR_H
#define PLNRQDTPAPAR_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpAPar: record of TblPlnrQDtpAPar
  */
class PlnrQDtpAPar {

public:
	PlnrQDtpAPar(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x2SrefKKey;
	string titX2SrefKKey;
	ubigint refPlnrMFile;
	string stubRefPlnrMFile;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDtpAPar: recordset of TblPlnrQDtpAPar
  */
class ListPlnrQDtpAPar {

public:
	ListPlnrQDtpAPar();
	ListPlnrQDtpAPar(const ListPlnrQDtpAPar& src);
	~ListPlnrQDtpAPar();

	void clear();
	unsigned int size() const;
	void append(PlnrQDtpAPar* rec);

	ListPlnrQDtpAPar& operator=(const ListPlnrQDtpAPar& src);

public:
	vector<PlnrQDtpAPar*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDtpAPar: C++ wrapper for table TblPlnrQDtpAPar
  */
class TblPlnrQDtpAPar {

public:
	TblPlnrQDtpAPar();
	virtual ~TblPlnrQDtpAPar();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDtpAPar** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpAPar& rst);

	virtual void insertRec(PlnrQDtpAPar* rec);
	ubigint insertNewRec(PlnrQDtpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQDtpAPar& rst, PlnrQDtpAPar** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x2SrefKKey = "", const string titX2SrefKKey = "", const ubigint refPlnrMFile = 0, const string stubRefPlnrMFile = "", const string Val = "");
	virtual void insertRst(ListPlnrQDtpAPar& rst);
	virtual void updateRec(PlnrQDtpAPar* rec);
	virtual void updateRst(ListPlnrQDtpAPar& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDtpAPar** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpAPar& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDtpAPar: C++ wrapper for table TblPlnrQDtpAPar (MySQL database)
  */
class MyTblPlnrQDtpAPar : public TblPlnrQDtpAPar, public MyTable {

public:
	MyTblPlnrQDtpAPar();
	~MyTblPlnrQDtpAPar();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpAPar& rst);

	void insertRec(PlnrQDtpAPar* rec);
	void insertRst(ListPlnrQDtpAPar& rst);
	void updateRec(PlnrQDtpAPar* rec);
	void updateRst(ListPlnrQDtpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpAPar& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDtpAPar: C++ wrapper for table TblPlnrQDtpAPar (PgSQL database)
  */
class PgTblPlnrQDtpAPar : public TblPlnrQDtpAPar, public PgTable {

public:
	PgTblPlnrQDtpAPar();
	~PgTblPlnrQDtpAPar();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDtpAPar** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDtpAPar& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDtpAPar** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDtpAPar& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpAPar** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpAPar& rst);

	void insertRec(PlnrQDtpAPar* rec);
	void insertRst(ListPlnrQDtpAPar& rst);
	void updateRec(PlnrQDtpAPar* rec);
	void updateRst(ListPlnrQDtpAPar& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpAPar** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpAPar& rst);
};
// IP pgTbl --- END

#endif

