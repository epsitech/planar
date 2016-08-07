/**
  * \file PlnrQUsrMNUsergroup.h
  * Dbs and XML wrapper for table TblPlnrQUsrMNUsergroup (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQUSRMNUSERGROUP_H
#define PLNRQUSRMNUSERGROUP_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQUsrMNUsergroup: record of TblPlnrQUsrMNUsergroup
  */
class PlnrQUsrMNUsergroup {

public:
	PlnrQUsrMNUsergroup(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");

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
  * ListPlnrQUsrMNUsergroup: recordset of TblPlnrQUsrMNUsergroup
  */
class ListPlnrQUsrMNUsergroup {

public:
	ListPlnrQUsrMNUsergroup();
	ListPlnrQUsrMNUsergroup(const ListPlnrQUsrMNUsergroup& src);
	~ListPlnrQUsrMNUsergroup();

	void clear();
	unsigned int size() const;
	void append(PlnrQUsrMNUsergroup* rec);

	ListPlnrQUsrMNUsergroup& operator=(const ListPlnrQUsrMNUsergroup& src);

public:
	vector<PlnrQUsrMNUsergroup*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQUsrMNUsergroup: C++ wrapper for table TblPlnrQUsrMNUsergroup
  */
class TblPlnrQUsrMNUsergroup {

public:
	TblPlnrQUsrMNUsergroup();
	virtual ~TblPlnrQUsrMNUsergroup();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQUsrMNUsergroup** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrMNUsergroup& rst);

	virtual void insertRec(PlnrQUsrMNUsergroup* rec);
	ubigint insertNewRec(PlnrQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");
	ubigint appendNewRecToRst(ListPlnrQUsrMNUsergroup& rst, PlnrQUsrMNUsergroup** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const uint ixPlnrVUserlevel = 0, const string srefIxPlnrVUserlevel = "", const string titIxPlnrVUserlevel = "");
	virtual void insertRst(ListPlnrQUsrMNUsergroup& rst);
	virtual void updateRec(PlnrQUsrMNUsergroup* rec);
	virtual void updateRst(ListPlnrQUsrMNUsergroup& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQUsrMNUsergroup** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrMNUsergroup& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQUsrMNUsergroup: C++ wrapper for table TblPlnrQUsrMNUsergroup (MySQL database)
  */
class MyTblPlnrQUsrMNUsergroup : public TblPlnrQUsrMNUsergroup, public MyTable {

public:
	MyTblPlnrQUsrMNUsergroup();
	~MyTblPlnrQUsrMNUsergroup();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrMNUsergroup& rst);

	void insertRec(PlnrQUsrMNUsergroup* rec);
	void insertRst(ListPlnrQUsrMNUsergroup& rst);
	void updateRec(PlnrQUsrMNUsergroup* rec);
	void updateRst(ListPlnrQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrMNUsergroup& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQUsrMNUsergroup: C++ wrapper for table TblPlnrQUsrMNUsergroup (PgSQL database)
  */
class PgTblPlnrQUsrMNUsergroup : public TblPlnrQUsrMNUsergroup, public PgTable {

public:
	PgTblPlnrQUsrMNUsergroup();
	~PgTblPlnrQUsrMNUsergroup();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQUsrMNUsergroup** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQUsrMNUsergroup& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQUsrMNUsergroup** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQUsrMNUsergroup& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQUsrMNUsergroup** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQUsrMNUsergroup& rst);

	void insertRec(PlnrQUsrMNUsergroup* rec);
	void insertRst(ListPlnrQUsrMNUsergroup& rst);
	void updateRec(PlnrQUsrMNUsergroup* rec);
	void updateRst(ListPlnrQUsrMNUsergroup& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQUsrMNUsergroup** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQUsrMNUsergroup& rst);
};
// IP pgTbl --- END

#endif

