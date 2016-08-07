/**
  * \file PlnrQUsrAAccess.h
  * Dbs and XML wrapper for table TblPlnrQUsrAAccess (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSRAACCESS_H
#define PLNRQUSRAACCESS_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsrAAccess: record of TblPlnrQUsrAAccess
  */
class PlnrQUsrAAccess {

public:
	PlnrQUsrAAccess(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxPlnrVCard = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const uint ixPlnrWUiaccess = 0, const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");

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
  * ListPlnrQUsrAAccess: recordset of TblPlnrQUsrAAccess
  */
class ListPlnrQUsrAAccess {

public:
	ListPlnrQUsrAAccess();
	ListPlnrQUsrAAccess(const ListPlnrQUsrAAccess& src);
	~ListPlnrQUsrAAccess();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsrAAccess* rec);

	ListPlnrQUsrAAccess& operator=(const ListPlnrQUsrAAccess& src);

public:
	vector<PlnrQUsrAAccess*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsrAAccess: C++ wrapper for table TblPlnrQUsrAAccess
  */
class TblPlnrQUsrAAccess {

public:
	TblPlnrQUsrAAccess();
	virtual ~TblPlnrQUsrAAccess();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsrAAccess** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrAAccess& rst);

	virtual void insertRec(PlnrQUsrAAccess* rec);
	ubigint insertNewRec(PlnrQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxPlnrVCard = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const uint ixPlnrWUiaccess = 0, const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");
	ubigint appendNewRecToRst(ListPlnrQUsrAAccess& rst, PlnrQUsrAAccess** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const uint x1IxPlnrVCard = 0, const string srefX1IxPlnrVCard = "", const string titX1IxPlnrVCard = "", const uint ixPlnrWUiaccess = 0, const string srefsIxPlnrWUiaccess = "", const string titsIxPlnrWUiaccess = "");
	virtual void insertRst(ListPlnrQUsrAAccess& rst);
	virtual void updateRec(PlnrQUsrAAccess* rec);
	virtual void updateRst(ListPlnrQUsrAAccess& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsrAAccess** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrAAccess& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsrAAccess: C++ wrapper for table TblPlnrQUsrAAccess (MySQL database)
  */
class MyTblPlnrQUsrAAccess : public TblPlnrQUsrAAccess, public MyTable {

public:
	MyTblPlnrQUsrAAccess();
	~MyTblPlnrQUsrAAccess();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrAAccess& rst);

	void insertRec(PlnrQUsrAAccess* rec);
	void insertRst(ListPlnrQUsrAAccess& rst);
	void updateRec(PlnrQUsrAAccess* rec);
	void updateRst(ListPlnrQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrAAccess& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsrAAccess: C++ wrapper for table TblPlnrQUsrAAccess (PgSQL database)
  */
class PgTblPlnrQUsrAAccess : public TblPlnrQUsrAAccess, public PgTable {

public:
	PgTblPlnrQUsrAAccess();
	~PgTblPlnrQUsrAAccess();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsrAAccess** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsrAAccess& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsrAAccess** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsrAAccess& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsrAAccess** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrAAccess& rst);

	void insertRec(PlnrQUsrAAccess* rec);
	void insertRst(ListPlnrQUsrAAccess& rst);
	void updateRec(PlnrQUsrAAccess* rec);
	void updateRst(ListPlnrQUsrAAccess& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsrAAccess** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrAAccess& rst);
};
// IP pgTbl --- END

#endif

