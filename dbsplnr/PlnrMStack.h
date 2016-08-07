/**
  * \file PlnrMStack.h
  * database access for table TblPlnrMStack (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMSTACK_H
#define PLNRMSTACK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMStack: record of TblPlnrMStack
  */
class PlnrMStack {

public:
	PlnrMStack(const ubigint ref = 0, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const uint ixVModtype = 0, const uint ixVFlrAligntype = 0, const string flrSrefPlnrMLevel = "", const double zFlr = 0.0, const uint ixVCeilAligntype = 0, const string ceilSrefPlnrMLevel = "", const double zCeil = 0.0, const string srefsPlnrMLayer = "", const string N = "");

public:
	ubigint ref;
	uint ixVBasetype;
	ubigint dsnRefPlnrMDesign;
	uint dsnNum;
	string sref;
	uint ixVModtype;
	uint ixVFlrAligntype;
	string flrSrefPlnrMLevel;
	double zFlr;
	uint ixVCeilAligntype;
	string ceilSrefPlnrMLevel;
	double zCeil;
	string srefsPlnrMLayer;
	string N;

public:
	bool operator==(const PlnrMStack& comp);
	bool operator!=(const PlnrMStack& comp);
};

/**
  * ListPlnrMStack: recordset of TblPlnrMStack
  */
class ListPlnrMStack {

public:
	ListPlnrMStack();
	ListPlnrMStack(const ListPlnrMStack& src);
	~ListPlnrMStack();

	void clear();
	unsigned int size() const;
	void append(PlnrMStack* rec);

	PlnrMStack* operator[](const uint ix);
	ListPlnrMStack& operator=(const ListPlnrMStack& src);
	bool operator==(const ListPlnrMStack& comp);
	bool operator!=(const ListPlnrMStack& comp);

public:
	vector<PlnrMStack*> nodes;
};

/**
  * TblPlnrMStack: C++ wrapper for table TblPlnrMStack
  */
class TblPlnrMStack {

public:
	TblPlnrMStack();
	virtual ~TblPlnrMStack();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMStack** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMStack& rst);

	virtual void insertRec(PlnrMStack* rec);
	ubigint insertNewRec(PlnrMStack** rec = NULL, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const uint ixVModtype = 0, const uint ixVFlrAligntype = 0, const string flrSrefPlnrMLevel = "", const double zFlr = 0.0, const uint ixVCeilAligntype = 0, const string ceilSrefPlnrMLevel = "", const double zCeil = 0.0, const string srefsPlnrMLayer = "", const string N = "");
	ubigint appendNewRecToRst(ListPlnrMStack& rst, PlnrMStack** rec = NULL, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const uint ixVModtype = 0, const uint ixVFlrAligntype = 0, const string flrSrefPlnrMLevel = "", const double zFlr = 0.0, const uint ixVCeilAligntype = 0, const string ceilSrefPlnrMLevel = "", const double zCeil = 0.0, const string srefsPlnrMLayer = "", const string N = "");
	virtual void insertRst(ListPlnrMStack& rst, bool transact = false);
	virtual void updateRec(PlnrMStack* rec);
	virtual void updateRst(ListPlnrMStack& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMStack** rec);
	virtual ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMStack& rst);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMStack& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMStack: C++ wrapper for table TblPlnrMStack (MySQL database)
  */
class MyTblPlnrMStack : public TblPlnrMStack, public MyTable {

public:
	MyTblPlnrMStack();
	~MyTblPlnrMStack();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMStack** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMStack& rst);

	void insertRec(PlnrMStack* rec);
	void insertRst(ListPlnrMStack& rst, bool transact = false);
	void updateRec(PlnrMStack* rec);
	void updateRst(ListPlnrMStack& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMStack** rec);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMStack& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMStack: C++ wrapper for table TblPlnrMStack (PgSQL database)
  */
class PgTblPlnrMStack : public TblPlnrMStack, public PgTable {

public:
	PgTblPlnrMStack();
	~PgTblPlnrMStack();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMStack** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMStack& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMStack** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMStack& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMStack** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMStack& rst);

	void insertRec(PlnrMStack* rec);
	void insertRst(ListPlnrMStack& rst, bool transact = false);
	void updateRec(PlnrMStack* rec);
	void updateRst(ListPlnrMStack& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMStack** rec);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMStack& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

