/**
  * \file PlnrMFace.h
  * database access for table TblPlnrMFace (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMFACE_H
#define PLNRMFACE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMFace: record of TblPlnrMFace
  */
class PlnrMFace {

public:
	PlnrMFace(const ubigint ref = 0, const ubigint x1RefPlnrMDesign = 0, const ubigint devRefPlnrMFace = 0, const uint sruIxPlnrVLat = 0, const ubigint sruRefPlnrMStructure = 0, const string sref = "");

public:
	ubigint ref;
	ubigint x1RefPlnrMDesign;
	ubigint devRefPlnrMFace;
	uint sruIxPlnrVLat;
	ubigint sruRefPlnrMStructure;
	string sref;

public:
	bool operator==(const PlnrMFace& comp);
	bool operator!=(const PlnrMFace& comp);
};

/**
  * ListPlnrMFace: recordset of TblPlnrMFace
  */
class ListPlnrMFace {

public:
	ListPlnrMFace();
	ListPlnrMFace(const ListPlnrMFace& src);
	~ListPlnrMFace();

	void clear();
	unsigned int size() const;
	void append(PlnrMFace* rec);

	PlnrMFace* operator[](const uint ix);
	ListPlnrMFace& operator=(const ListPlnrMFace& src);
	bool operator==(const ListPlnrMFace& comp);
	bool operator!=(const ListPlnrMFace& comp);

public:
	vector<PlnrMFace*> nodes;
};

/**
  * TblPlnrMFace: C++ wrapper for table TblPlnrMFace
  */
class TblPlnrMFace {

public:
	TblPlnrMFace();
	virtual ~TblPlnrMFace();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMFace** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMFace& rst);

	virtual void insertRec(PlnrMFace* rec);
	ubigint insertNewRec(PlnrMFace** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const ubigint devRefPlnrMFace = 0, const uint sruIxPlnrVLat = 0, const ubigint sruRefPlnrMStructure = 0, const string sref = "");
	ubigint appendNewRecToRst(ListPlnrMFace& rst, PlnrMFace** rec = NULL, const ubigint x1RefPlnrMDesign = 0, const ubigint devRefPlnrMFace = 0, const uint sruIxPlnrVLat = 0, const ubigint sruRefPlnrMStructure = 0, const string sref = "");
	virtual void insertRst(ListPlnrMFace& rst, bool transact = false);
	virtual void updateRec(PlnrMFace* rec);
	virtual void updateRst(ListPlnrMFace& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMFace** rec);
	virtual ubigint countByDsnSru(ubigint x1RefPlnrMDesign, ubigint sruRefPlnrMStructure);
	virtual ubigint loadRstByDsnSru(ubigint x1RefPlnrMDesign, ubigint sruRefPlnrMStructure, const bool append, ListPlnrMFace& rst);
	virtual ubigint loadRstBySru(ubigint sruRefPlnrMStructure, const bool append, ListPlnrMFace& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMFace& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMFace: C++ wrapper for table TblPlnrMFace (MySQL database)
  */
class MyTblPlnrMFace : public TblPlnrMFace, public MyTable {

public:
	MyTblPlnrMFace();
	~MyTblPlnrMFace();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMFace** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMFace& rst);

	void insertRec(PlnrMFace* rec);
	void insertRst(ListPlnrMFace& rst, bool transact = false);
	void updateRec(PlnrMFace* rec);
	void updateRst(ListPlnrMFace& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMFace** rec);
	ubigint countByDsnSru(ubigint x1RefPlnrMDesign, ubigint sruRefPlnrMStructure);
	ubigint loadRstByDsnSru(ubigint x1RefPlnrMDesign, ubigint sruRefPlnrMStructure, const bool append, ListPlnrMFace& rst);
	ubigint loadRstBySru(ubigint sruRefPlnrMStructure, const bool append, ListPlnrMFace& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMFace: C++ wrapper for table TblPlnrMFace (PgSQL database)
  */
class PgTblPlnrMFace : public TblPlnrMFace, public PgTable {

public:
	PgTblPlnrMFace();
	~PgTblPlnrMFace();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMFace** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMFace& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMFace** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMFace& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMFace** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMFace& rst);

	void insertRec(PlnrMFace* rec);
	void insertRst(ListPlnrMFace& rst, bool transact = false);
	void updateRec(PlnrMFace* rec);
	void updateRst(ListPlnrMFace& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMFace** rec);
	ubigint countByDsnSru(ubigint x1RefPlnrMDesign, ubigint sruRefPlnrMStructure);
	ubigint loadRstByDsnSru(ubigint x1RefPlnrMDesign, ubigint sruRefPlnrMStructure, const bool append, ListPlnrMFace& rst);
	ubigint loadRstBySru(ubigint sruRefPlnrMStructure, const bool append, ListPlnrMFace& rst);
};
// IP pgTbl --- END

#endif

