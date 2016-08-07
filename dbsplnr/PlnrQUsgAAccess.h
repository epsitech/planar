/**
  * \file PlnrQUsgAAccess.h
  * Dbs and XML wrapper for table TblPlnrQUsgAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSGAACCESS_H
#define PLNRQUSGAACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsgAAccess: record of TblPlnrQUsgAAccess
  */
class PlnrQUsgAAccess {

public:
	PlnrQUsgAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxPlnrVCard = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const uint ixPlnrWUiaccess = 0, const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	uint x1IxPlnrVCard;
	string srefX1IxPlnrVCard;
	string titX1IxPlnrVCard;
	uint ixPlnrWUiaccess;
	string srefsIxPlnrWUiaccess;
	string titsIxPlnrWUiaccess;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQUsgAAccess: recordset of TblPlnrQUsgAAccess
  */
class ListPlnrQUsgAAccess {

public:
	ListPlnrQUsgAAccess();
	ListPlnrQUsgAAccess(const ListPlnrQUsgAAccess& src);
	~ListPlnrQUsgAAccess();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsgAAccess* rec);

	ListPlnrQUsgAAccess& operator=(const ListPlnrQUsgAAccess& src);

public:
	vector<PlnrQUsgAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsgAAccess: C++ wrapper for table TblPlnrQUsgAAccess
  */
class TblPlnrQUsgAAccess {

public:
	TblPlnrQUsgAAccess();
	virtual ~TblPlnrQUsgAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsgAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgAAccess& rst);

	virtual void insertRec(PlnrQUsgAAccess* rec);
	ubigint insertNewRec(PlnrQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxPlnrVCard = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const uint ixPlnrWUiaccess = 0, const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");
	ubigint appendNewRecToRst(ListPlnrQUsgAAccess& rst, PlnrQUsgAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxPlnrVCard = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const uint ixPlnrWUiaccess = 0, const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");
	virtual void insertRst(ListPlnrQUsgAAccess& rst);
	virtual void updateRec(PlnrQUsgAAccess* rec);
	virtual void updateRst(ListPlnrQUsgAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsgAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgAAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsgAAccess: C++ wrapper for table TblPlnrQUsgAAccess (MySQL database)
  */
class MyTblPlnrQUsgAAccess : public TblPlnrQUsgAAccess, public MyTable {

public:
	MyTblPlnrQUsgAAccess();
	~MyTblPlnrQUsgAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgAAccess& rst);

	void insertRec(PlnrQUsgAAccess* rec);
	void insertRst(ListPlnrQUsgAAccess& rst);
	void updateRec(PlnrQUsgAAccess* rec);
	void updateRst(ListPlnrQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgAAccess& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsgAAccess: C++ wrapper for table TblPlnrQUsgAAccess (PgSQL database)
  */
class PgTblPlnrQUsgAAccess : public TblPlnrQUsgAAccess, public PgTable {

public:
	PgTblPlnrQUsgAAccess();
	~PgTblPlnrQUsgAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsgAAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsgAAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsgAAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsgAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsgAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgAAccess& rst);

	void insertRec(PlnrQUsgAAccess* rec);
	void insertRst(ListPlnrQUsgAAccess& rst);
	void updateRec(PlnrQUsgAAccess* rec);
	void updateRst(ListPlnrQUsgAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsgAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgAAccess& rst);
};
// IP pgTbl --- END

#endif

