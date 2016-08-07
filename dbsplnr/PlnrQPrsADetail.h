/**
  * \file PlnrQPrsADetail.h
  * Dbs and XML wrapper for table TblPlnrQPrsADetail (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRSADETAIL_H
#define PLNRQPRSADETAIL_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPrsADetail: record of TblPlnrQPrsADetail
  */
class PlnrQPrsADetail {

public:
	PlnrQPrsADetail(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string x1SrefKType;
	string titX1SrefKType;
	string Val;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQPrsADetail: recordset of TblPlnrQPrsADetail
  */
class ListPlnrQPrsADetail {

public:
	ListPlnrQPrsADetail();
	ListPlnrQPrsADetail(const ListPlnrQPrsADetail& src);
	~ListPlnrQPrsADetail();

	void clear();
	unsigned int size() const;
	void append(PlnrQPrsADetail* rec);

	ListPlnrQPrsADetail& operator=(const ListPlnrQPrsADetail& src);

public:
	vector<PlnrQPrsADetail*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPrsADetail: C++ wrapper for table TblPlnrQPrsADetail
  */
class TblPlnrQPrsADetail {

public:
	TblPlnrQPrsADetail();
	virtual ~TblPlnrQPrsADetail();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPrsADetail** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrsADetail& rst);

	virtual void insertRec(PlnrQPrsADetail* rec);
	ubigint insertNewRec(PlnrQPrsADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	ubigint appendNewRecToRst(ListPlnrQPrsADetail& rst, PlnrQPrsADetail** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string x1SrefKType = "", const string titX1SrefKType = "", const string Val = "");
	virtual void insertRst(ListPlnrQPrsADetail& rst);
	virtual void updateRec(PlnrQPrsADetail* rec);
	virtual void updateRst(ListPlnrQPrsADetail& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPrsADetail** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrsADetail& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPrsADetail: C++ wrapper for table TblPlnrQPrsADetail (MySQL database)
  */
class MyTblPlnrQPrsADetail : public TblPlnrQPrsADetail, public MyTable {

public:
	MyTblPlnrQPrsADetail();
	~MyTblPlnrQPrsADetail();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrsADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrsADetail& rst);

	void insertRec(PlnrQPrsADetail* rec);
	void insertRst(ListPlnrQPrsADetail& rst);
	void updateRec(PlnrQPrsADetail* rec);
	void updateRst(ListPlnrQPrsADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrsADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrsADetail& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPrsADetail: C++ wrapper for table TblPlnrQPrsADetail (PgSQL database)
  */
class PgTblPlnrQPrsADetail : public TblPlnrQPrsADetail, public PgTable {

public:
	PgTblPlnrQPrsADetail();
	~PgTblPlnrQPrsADetail();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPrsADetail** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPrsADetail& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPrsADetail** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPrsADetail& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPrsADetail** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPrsADetail& rst);

	void insertRec(PlnrQPrsADetail* rec);
	void insertRst(ListPlnrQPrsADetail& rst);
	void updateRec(PlnrQPrsADetail* rec);
	void updateRst(ListPlnrQPrsADetail& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPrsADetail** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPrsADetail& rst);
};
// IP pgTbl --- END

#endif

