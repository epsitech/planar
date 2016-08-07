/**
  * \file PlnrQSruMNStack.h
  * Dbs and XML wrapper for table TblPlnrQSruMNStack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRUMNSTACK_H
#define PLNRQSRUMNSTACK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSruMNStack: record of TblPlnrQSruMNStack
  */
class PlnrQSruMNStack {

public:
	PlnrQSruMNStack(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint mref;
	string stubMref;
	ubigint ref;
	string fromSrefPlnrMLayer;
	string toSrefPlnrMLayer;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQSruMNStack: recordset of TblPlnrQSruMNStack
  */
class ListPlnrQSruMNStack {

public:
	ListPlnrQSruMNStack();
	ListPlnrQSruMNStack(const ListPlnrQSruMNStack& src);
	~ListPlnrQSruMNStack();

	void clear();
	unsigned int size() const;
	void append(PlnrQSruMNStack* rec);

	ListPlnrQSruMNStack& operator=(const ListPlnrQSruMNStack& src);

public:
	vector<PlnrQSruMNStack*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQSruMNStack: C++ wrapper for table TblPlnrQSruMNStack
  */
class TblPlnrQSruMNStack {

public:
	TblPlnrQSruMNStack();
	virtual ~TblPlnrQSruMNStack();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQSruMNStack** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruMNStack& rst);

	virtual void insertRec(PlnrQSruMNStack* rec);
	ubigint insertNewRec(PlnrQSruMNStack** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");
	ubigint appendNewRecToRst(ListPlnrQSruMNStack& rst, PlnrQSruMNStack** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint mref = 0, const string stubMref = "", const ubigint ref = 0, const string fromSrefPlnrMLayer = "", const string toSrefPlnrMLayer = "");
	virtual void insertRst(ListPlnrQSruMNStack& rst);
	virtual void updateRec(PlnrQSruMNStack* rec);
	virtual void updateRst(ListPlnrQSruMNStack& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQSruMNStack** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruMNStack& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQSruMNStack: C++ wrapper for table TblPlnrQSruMNStack (MySQL database)
  */
class MyTblPlnrQSruMNStack : public TblPlnrQSruMNStack, public MyTable {

public:
	MyTblPlnrQSruMNStack();
	~MyTblPlnrQSruMNStack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruMNStack** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruMNStack& rst);

	void insertRec(PlnrQSruMNStack* rec);
	void insertRst(ListPlnrQSruMNStack& rst);
	void updateRec(PlnrQSruMNStack* rec);
	void updateRst(ListPlnrQSruMNStack& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruMNStack** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruMNStack& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQSruMNStack: C++ wrapper for table TblPlnrQSruMNStack (PgSQL database)
  */
class PgTblPlnrQSruMNStack : public TblPlnrQSruMNStack, public PgTable {

public:
	PgTblPlnrQSruMNStack();
	~PgTblPlnrQSruMNStack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQSruMNStack** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQSruMNStack& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQSruMNStack** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQSruMNStack& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSruMNStack** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSruMNStack& rst);

	void insertRec(PlnrQSruMNStack* rec);
	void insertRst(ListPlnrQSruMNStack& rst);
	void updateRec(PlnrQSruMNStack* rec);
	void updateRst(ListPlnrQSruMNStack& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSruMNStack** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSruMNStack& rst);
};
// IP pgTbl --- END

#endif

