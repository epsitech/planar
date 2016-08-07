/**
  * \file PlnrQPreselect.h
  * Dbs and XML wrapper for table TblPlnrQPreselect (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQPRESELECT_H
#define PLNRQPRESELECT_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQPreselect: record of TblPlnrQPreselect
  */
class PlnrQPreselect {

public:
	PlnrQPreselect(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQPreselect: recordset of TblPlnrQPreselect
  */
class ListPlnrQPreselect {

public:
	ListPlnrQPreselect();
	ListPlnrQPreselect(const ListPlnrQPreselect& src);
	~ListPlnrQPreselect();

	void clear();
	unsigned int size() const;
	void append(PlnrQPreselect* rec);

	ListPlnrQPreselect& operator=(const ListPlnrQPreselect& src);

public:
	vector<PlnrQPreselect*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQPreselect: C++ wrapper for table TblPlnrQPreselect
  */
class TblPlnrQPreselect {

public:
	TblPlnrQPreselect();
	virtual ~TblPlnrQPreselect();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQPreselect** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPreselect& rst);

	virtual void insertRec(PlnrQPreselect* rec);
	ubigint insertNewRec(PlnrQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	ubigint appendNewRecToRst(ListPlnrQPreselect& rst, PlnrQPreselect** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0);
	virtual void insertRst(ListPlnrQPreselect& rst);
	virtual void updateRec(PlnrQPreselect* rec);
	virtual void updateRst(ListPlnrQPreselect& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQPreselect** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPreselect& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQPreselect: C++ wrapper for table TblPlnrQPreselect (MySQL database)
  */
class MyTblPlnrQPreselect : public TblPlnrQPreselect, public MyTable {

public:
	MyTblPlnrQPreselect();
	~MyTblPlnrQPreselect();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPreselect& rst);

	void insertRec(PlnrQPreselect* rec);
	void insertRst(ListPlnrQPreselect& rst);
	void updateRec(PlnrQPreselect* rec);
	void updateRst(ListPlnrQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPreselect& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQPreselect: C++ wrapper for table TblPlnrQPreselect (PgSQL database)
  */
class PgTblPlnrQPreselect : public TblPlnrQPreselect, public PgTable {

public:
	PgTblPlnrQPreselect();
	~PgTblPlnrQPreselect();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQPreselect** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQPreselect& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQPreselect** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQPreselect& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQPreselect** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQPreselect& rst);

	void insertRec(PlnrQPreselect* rec);
	void insertRst(ListPlnrQPreselect& rst);
	void updateRec(PlnrQPreselect* rec);
	void updateRst(ListPlnrQPreselect& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQPreselect** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQPreselect& rst);
};
// IP pgTbl --- END

#endif

