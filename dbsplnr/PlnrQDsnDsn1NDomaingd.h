/**
  * \file PlnrQDsnDsn1NDomaingd.h
  * Dbs and XML wrapper for table TblPlnrQDsnDsn1NDomaingd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQDSNDSN1NDOMAINGD_H
#define PLNRQDSNDSN1NDOMAINGD_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQDsnDsn1NDomaingd: record of TblPlnrQDsnDsn1NDomaingd
  */
class PlnrQDsnDsn1NDomaingd {

public:
	PlnrQDsnDsn1NDomaingd(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;
	uint dsnNum;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQDsnDsn1NDomaingd: recordset of TblPlnrQDsnDsn1NDomaingd
  */
class ListPlnrQDsnDsn1NDomaingd {

public:
	ListPlnrQDsnDsn1NDomaingd();
	ListPlnrQDsnDsn1NDomaingd(const ListPlnrQDsnDsn1NDomaingd& src);
	~ListPlnrQDsnDsn1NDomaingd();

	void clear();
	unsigned int size() const;
	void append(PlnrQDsnDsn1NDomaingd* rec);

	ListPlnrQDsnDsn1NDomaingd& operator=(const ListPlnrQDsnDsn1NDomaingd& src);

public:
	vector<PlnrQDsnDsn1NDomaingd*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQDsnDsn1NDomaingd: C++ wrapper for table TblPlnrQDsnDsn1NDomaingd
  */
class TblPlnrQDsnDsn1NDomaingd {

public:
	TblPlnrQDsnDsn1NDomaingd();
	virtual ~TblPlnrQDsnDsn1NDomaingd();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDomaingd** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);

	virtual void insertRec(PlnrQDsnDsn1NDomaingd* rec);
	ubigint insertNewRec(PlnrQDsnDsn1NDomaingd** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	ubigint appendNewRecToRst(ListPlnrQDsnDsn1NDomaingd& rst, PlnrQDsnDsn1NDomaingd** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "", const uint dsnNum = 0);
	virtual void insertRst(ListPlnrQDsnDsn1NDomaingd& rst);
	virtual void updateRec(PlnrQDsnDsn1NDomaingd* rec);
	virtual void updateRst(ListPlnrQDsnDsn1NDomaingd& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDomaingd** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQDsnDsn1NDomaingd: C++ wrapper for table TblPlnrQDsnDsn1NDomaingd (MySQL database)
  */
class MyTblPlnrQDsnDsn1NDomaingd : public TblPlnrQDsnDsn1NDomaingd, public MyTable {

public:
	MyTblPlnrQDsnDsn1NDomaingd();
	~MyTblPlnrQDsnDsn1NDomaingd();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDomaingd** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);

	void insertRec(PlnrQDsnDsn1NDomaingd* rec);
	void insertRst(ListPlnrQDsnDsn1NDomaingd& rst);
	void updateRec(PlnrQDsnDsn1NDomaingd* rec);
	void updateRst(ListPlnrQDsnDsn1NDomaingd& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDomaingd** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQDsnDsn1NDomaingd: C++ wrapper for table TblPlnrQDsnDsn1NDomaingd (PgSQL database)
  */
class PgTblPlnrQDsnDsn1NDomaingd : public TblPlnrQDsnDsn1NDomaingd, public PgTable {

public:
	PgTblPlnrQDsnDsn1NDomaingd();
	~PgTblPlnrQDsnDsn1NDomaingd();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQDsnDsn1NDomaingd** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQDsnDsn1NDomaingd** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQDsnDsn1NDomaingd** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);

	void insertRec(PlnrQDsnDsn1NDomaingd* rec);
	void insertRst(ListPlnrQDsnDsn1NDomaingd& rst);
	void updateRec(PlnrQDsnDsn1NDomaingd* rec);
	void updateRst(ListPlnrQDsnDsn1NDomaingd& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQDsnDsn1NDomaingd** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQDsnDsn1NDomaingd& rst);
};
// IP pgTbl --- END

#endif

