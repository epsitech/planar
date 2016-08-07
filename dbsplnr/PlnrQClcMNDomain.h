/**
  * \file PlnrQClcMNDomain.h
  * Dbs and XML wrapper for table TblPlnrQClcMNDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCMNDOMAIN_H
#define PLNRQCLCMNDOMAIN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcMNDomain: record of TblPlnrQClcMNDomain
  */
class PlnrQClcMNDomain {

public:
	PlnrQClcMNDomain(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	string srefPlnrKCalcdomprp;
	string titSrefPlnrKCalcdomprp;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQClcMNDomain: recordset of TblPlnrQClcMNDomain
  */
class ListPlnrQClcMNDomain {

public:
	ListPlnrQClcMNDomain();
	ListPlnrQClcMNDomain(const ListPlnrQClcMNDomain& src);
	~ListPlnrQClcMNDomain();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcMNDomain* rec);

	ListPlnrQClcMNDomain& operator=(const ListPlnrQClcMNDomain& src);

public:
	vector<PlnrQClcMNDomain*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcMNDomain: C++ wrapper for table TblPlnrQClcMNDomain
  */
class TblPlnrQClcMNDomain {

public:
	TblPlnrQClcMNDomain();
	virtual ~TblPlnrQClcMNDomain();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcMNDomain** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcMNDomain& rst);

	virtual void insertRec(PlnrQClcMNDomain* rec);
	ubigint insertNewRec(PlnrQClcMNDomain** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");
	ubigint appendNewRecToRst(ListPlnrQClcMNDomain& rst, PlnrQClcMNDomain** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string srefPlnrKCalcdomprp = "", const string titSrefPlnrKCalcdomprp = "");
	virtual void insertRst(ListPlnrQClcMNDomain& rst);
	virtual void updateRec(PlnrQClcMNDomain* rec);
	virtual void updateRst(ListPlnrQClcMNDomain& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcMNDomain** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcMNDomain& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcMNDomain: C++ wrapper for table TblPlnrQClcMNDomain (MySQL database)
  */
class MyTblPlnrQClcMNDomain : public TblPlnrQClcMNDomain, public MyTable {

public:
	MyTblPlnrQClcMNDomain();
	~MyTblPlnrQClcMNDomain();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcMNDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcMNDomain& rst);

	void insertRec(PlnrQClcMNDomain* rec);
	void insertRst(ListPlnrQClcMNDomain& rst);
	void updateRec(PlnrQClcMNDomain* rec);
	void updateRst(ListPlnrQClcMNDomain& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcMNDomain** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcMNDomain& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcMNDomain: C++ wrapper for table TblPlnrQClcMNDomain (PgSQL database)
  */
class PgTblPlnrQClcMNDomain : public TblPlnrQClcMNDomain, public PgTable {

public:
	PgTblPlnrQClcMNDomain();
	~PgTblPlnrQClcMNDomain();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcMNDomain** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcMNDomain& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcMNDomain** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcMNDomain& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcMNDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcMNDomain& rst);

	void insertRec(PlnrQClcMNDomain* rec);
	void insertRst(ListPlnrQClcMNDomain& rst);
	void updateRec(PlnrQClcMNDomain* rec);
	void updateRst(ListPlnrQClcMNDomain& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcMNDomain** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcMNDomain& rst);
};
// IP pgTbl --- END

#endif

