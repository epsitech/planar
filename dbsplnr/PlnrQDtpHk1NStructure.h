/**
  * \file PlnrQDtpHk1NStructure.h
  * Dbs and XML wrapper for table TblPlnrQDtpHk1NStructure (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDTPHK1NSTRUCTURE_H
#define PLNRQDTPHK1NSTRUCTURE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDtpHk1NStructure: record of TblPlnrQDtpHk1NStructure
  */
class PlnrQDtpHk1NStructure {

public:
	PlnrQDtpHk1NStructure(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQDtpHk1NStructure: recordset of TblPlnrQDtpHk1NStructure
  */
class ListPlnrQDtpHk1NStructure {

public:
	ListPlnrQDtpHk1NStructure();
	ListPlnrQDtpHk1NStructure(const ListPlnrQDtpHk1NStructure& src);
	~ListPlnrQDtpHk1NStructure();

	void clear();
	unsigned int size() const;
	void append(PlnrQDtpHk1NStructure* rec);

	ListPlnrQDtpHk1NStructure& operator=(const ListPlnrQDtpHk1NStructure& src);

public:
	vector<PlnrQDtpHk1NStructure*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDtpHk1NStructure: C++ wrapper for table TblPlnrQDtpHk1NStructure
  */
class TblPlnrQDtpHk1NStructure {

public:
	TblPlnrQDtpHk1NStructure();
	virtual ~TblPlnrQDtpHk1NStructure();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDtpHk1NStructure** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpHk1NStructure& rst);

	virtual void insertRec(PlnrQDtpHk1NStructure* rec);
	ubigint insertNewRec(PlnrQDtpHk1NStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQDtpHk1NStructure& rst, PlnrQDtpHk1NStructure** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQDtpHk1NStructure& rst);
	virtual void updateRec(PlnrQDtpHk1NStructure* rec);
	virtual void updateRst(ListPlnrQDtpHk1NStructure& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDtpHk1NStructure** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpHk1NStructure& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDtpHk1NStructure: C++ wrapper for table TblPlnrQDtpHk1NStructure (MySQL database)
  */
class MyTblPlnrQDtpHk1NStructure : public TblPlnrQDtpHk1NStructure, public MyTable {

public:
	MyTblPlnrQDtpHk1NStructure();
	~MyTblPlnrQDtpHk1NStructure();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpHk1NStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpHk1NStructure& rst);

	void insertRec(PlnrQDtpHk1NStructure* rec);
	void insertRst(ListPlnrQDtpHk1NStructure& rst);
	void updateRec(PlnrQDtpHk1NStructure* rec);
	void updateRst(ListPlnrQDtpHk1NStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpHk1NStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpHk1NStructure& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDtpHk1NStructure: C++ wrapper for table TblPlnrQDtpHk1NStructure (PgSQL database)
  */
class PgTblPlnrQDtpHk1NStructure : public TblPlnrQDtpHk1NStructure, public PgTable {

public:
	PgTblPlnrQDtpHk1NStructure();
	~PgTblPlnrQDtpHk1NStructure();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDtpHk1NStructure** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDtpHk1NStructure& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDtpHk1NStructure** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDtpHk1NStructure& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDtpHk1NStructure** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDtpHk1NStructure& rst);

	void insertRec(PlnrQDtpHk1NStructure* rec);
	void insertRst(ListPlnrQDtpHk1NStructure& rst);
	void updateRec(PlnrQDtpHk1NStructure* rec);
	void updateRst(ListPlnrQDtpHk1NStructure& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDtpHk1NStructure** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDtpHk1NStructure& rst);
};
// IP pgTbl --- END

#endif

