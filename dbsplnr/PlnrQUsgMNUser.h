/**
  * \file PlnrQUsgMNUser.h
  * Dbs and XML wrapper for table TblPlnrQUsgMNUser (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSGMNUSER_H
#define PLNRQUSGMNUSER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsgMNUser: record of TblPlnrQUsgMNUser
  */
class PlnrQUsgMNUser {

public:
	PlnrQUsgMNUser(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	uint ixPlnrVUserlevel;
	string srefIxPlnrVUserlevel;
	string titIxPlnrVUserlevel;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQUsgMNUser: recordset of TblPlnrQUsgMNUser
  */
class ListPlnrQUsgMNUser {

public:
	ListPlnrQUsgMNUser();
	ListPlnrQUsgMNUser(const ListPlnrQUsgMNUser& src);
	~ListPlnrQUsgMNUser();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsgMNUser* rec);

	ListPlnrQUsgMNUser& operator=(const ListPlnrQUsgMNUser& src);

public:
	vector<PlnrQUsgMNUser*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsgMNUser: C++ wrapper for table TblPlnrQUsgMNUser
  */
class TblPlnrQUsgMNUser {

public:
	TblPlnrQUsgMNUser();
	virtual ~TblPlnrQUsgMNUser();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsgMNUser** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgMNUser& rst);

	virtual void insertRec(PlnrQUsgMNUser* rec);
	ubigint insertNewRec(PlnrQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");
	ubigint appendNewRecToRst(ListPlnrQUsgMNUser& rst, PlnrQUsgMNUser** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");
	virtual void insertRst(ListPlnrQUsgMNUser& rst);
	virtual void updateRec(PlnrQUsgMNUser* rec);
	virtual void updateRst(ListPlnrQUsgMNUser& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsgMNUser** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgMNUser& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsgMNUser: C++ wrapper for table TblPlnrQUsgMNUser (MySQL database)
  */
class MyTblPlnrQUsgMNUser : public TblPlnrQUsgMNUser, public MyTable {

public:
	MyTblPlnrQUsgMNUser();
	~MyTblPlnrQUsgMNUser();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgMNUser& rst);

	void insertRec(PlnrQUsgMNUser* rec);
	void insertRst(ListPlnrQUsgMNUser& rst);
	void updateRec(PlnrQUsgMNUser* rec);
	void updateRst(ListPlnrQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgMNUser& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsgMNUser: C++ wrapper for table TblPlnrQUsgMNUser (PgSQL database)
  */
class PgTblPlnrQUsgMNUser : public TblPlnrQUsgMNUser, public PgTable {

public:
	PgTblPlnrQUsgMNUser();
	~PgTblPlnrQUsgMNUser();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsgMNUser** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsgMNUser& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsgMNUser** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsgMNUser& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsgMNUser** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsgMNUser& rst);

	void insertRec(PlnrQUsgMNUser* rec);
	void insertRst(ListPlnrQUsgMNUser& rst);
	void updateRec(PlnrQUsgMNUser* rec);
	void updateRst(ListPlnrQUsgMNUser& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsgMNUser** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsgMNUser& rst);
};
// IP pgTbl --- END

#endif

