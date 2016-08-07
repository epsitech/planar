/**
  * \file PlnrAVKeylistKey.h
  * database access for table TblPlnrAVKeylistKey (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRAVKEYLISTKEY_H
#define PLNRAVKEYLISTKEY_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrAVKeylistKey: record of TblPlnrAVKeylistKey
  */
class PlnrAVKeylistKey {

public:
	PlnrAVKeylistKey(const ubigint ref = 0, const uint klsIxPlnrVKeylist = 0, const uint klsNum = 0, const uint x1IxPlnrVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");

public:
	ubigint ref;
	uint klsIxPlnrVKeylist;
	uint klsNum;
	uint x1IxPlnrVMaintable;
	ubigint x1Uref;
	bool Fixed;
	string sref;
	string Avail;
	string Implied;
	ubigint refJ;
	string Title;
	string Comment;

public:
	bool operator==(const PlnrAVKeylistKey& comp);
	bool operator!=(const PlnrAVKeylistKey& comp);
};

/**
  * ListPlnrAVKeylistKey: recordset of TblPlnrAVKeylistKey
  */
class ListPlnrAVKeylistKey {

public:
	ListPlnrAVKeylistKey();
	ListPlnrAVKeylistKey(const ListPlnrAVKeylistKey& src);
	~ListPlnrAVKeylistKey();

	void clear();
	unsigned int size() const;
	void append(PlnrAVKeylistKey* rec);

	PlnrAVKeylistKey* operator[](const uint ix);
	ListPlnrAVKeylistKey& operator=(const ListPlnrAVKeylistKey& src);
	bool operator==(const ListPlnrAVKeylistKey& comp);
	bool operator!=(const ListPlnrAVKeylistKey& comp);

public:
	vector<PlnrAVKeylistKey*> nodes;
};

/**
  * TblPlnrAVKeylistKey: C++ wrapper for table TblPlnrAVKeylistKey
  */
class TblPlnrAVKeylistKey {

public:
	TblPlnrAVKeylistKey();
	virtual ~TblPlnrAVKeylistKey();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrAVKeylistKey** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVKeylistKey& rst);

	virtual void insertRec(PlnrAVKeylistKey* rec);
	ubigint insertNewRec(PlnrAVKeylistKey** rec = NULL, const uint klsIxPlnrVKeylist = 0, const uint klsNum = 0, const uint x1IxPlnrVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrAVKeylistKey& rst, PlnrAVKeylistKey** rec = NULL, const uint klsIxPlnrVKeylist = 0, const uint klsNum = 0, const uint x1IxPlnrVMaintable = 0, const ubigint x1Uref = 0, const bool Fixed = false, const string sref = "", const string Avail = "", const string Implied = "", const ubigint refJ = 0, const string Title = "", const string Comment = "");
	virtual void insertRst(ListPlnrAVKeylistKey& rst, bool transact = false);
	virtual void updateRec(PlnrAVKeylistKey* rec);
	virtual void updateRst(ListPlnrAVKeylistKey& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrAVKeylistKey** rec);
	virtual bool loadRefByKlsMtbUrfSrf(uint klsIxPlnrVKeylist, uint x1IxPlnrVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	virtual bool loadRefByKlsSrf(uint klsIxPlnrVKeylist, string sref, ubigint& ref);
	virtual ubigint loadRefsByMtbUrf(uint x1IxPlnrVMaintable, ubigint x1Uref, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByKls(uint klsIxPlnrVKeylist, const bool append, ListPlnrAVKeylistKey& rst);
	virtual ubigint loadRstByKlsMtbUrf(uint klsIxPlnrVKeylist, uint x1IxPlnrVMaintable, ubigint x1Uref, const bool append, ListPlnrAVKeylistKey& rst);
	virtual bool loadTitByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrAVKeylistKey& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrAVKeylistKey: C++ wrapper for table TblPlnrAVKeylistKey (MySQL database)
  */
class MyTblPlnrAVKeylistKey : public TblPlnrAVKeylistKey, public MyTable {

public:
	MyTblPlnrAVKeylistKey();
	~MyTblPlnrAVKeylistKey();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVKeylistKey& rst);

	void insertRec(PlnrAVKeylistKey* rec);
	void insertRst(ListPlnrAVKeylistKey& rst, bool transact = false);
	void updateRec(PlnrAVKeylistKey* rec);
	void updateRst(ListPlnrAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxPlnrVKeylist, uint x1IxPlnrVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxPlnrVKeylist, string sref, ubigint& ref);
	ubigint loadRefsByMtbUrf(uint x1IxPlnrVMaintable, ubigint x1Uref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKls(uint klsIxPlnrVKeylist, const bool append, ListPlnrAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxPlnrVKeylist, uint x1IxPlnrVMaintable, ubigint x1Uref, const bool append, ListPlnrAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrAVKeylistKey: C++ wrapper for table TblPlnrAVKeylistKey (PgSQL database)
  */
class PgTblPlnrAVKeylistKey : public TblPlnrAVKeylistKey, public PgTable {

public:
	PgTblPlnrAVKeylistKey();
	~PgTblPlnrAVKeylistKey();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrAVKeylistKey** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrAVKeylistKey& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrAVKeylistKey** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrAVKeylistKey& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrAVKeylistKey** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrAVKeylistKey& rst);

	void insertRec(PlnrAVKeylistKey* rec);
	void insertRst(ListPlnrAVKeylistKey& rst, bool transact = false);
	void updateRec(PlnrAVKeylistKey* rec);
	void updateRst(ListPlnrAVKeylistKey& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrAVKeylistKey** rec);
	bool loadRefByKlsMtbUrfSrf(uint klsIxPlnrVKeylist, uint x1IxPlnrVMaintable, ubigint x1Uref, string sref, ubigint& ref);
	bool loadRefByKlsSrf(uint klsIxPlnrVKeylist, string sref, ubigint& ref);
	ubigint loadRefsByMtbUrf(uint x1IxPlnrVMaintable, ubigint x1Uref, const bool append, vector<ubigint>& refs);
	ubigint loadRstByKls(uint klsIxPlnrVKeylist, const bool append, ListPlnrAVKeylistKey& rst);
	ubigint loadRstByKlsMtbUrf(uint klsIxPlnrVKeylist, uint x1IxPlnrVMaintable, ubigint x1Uref, const bool append, ListPlnrAVKeylistKey& rst);
	bool loadTitByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

