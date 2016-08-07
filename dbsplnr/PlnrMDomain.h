/**
  * \file PlnrMDomain.h
  * database access for table TblPlnrMDomain (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMDOMAIN_H
#define PLNRMDOMAIN_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMDomain: record of TblPlnrMDomain
  */
class PlnrMDomain {

public:
	PlnrMDomain(const ubigint ref = 0, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const string flrSrefPlnrMLevel = "", const string ceilSrefPlnrMLevel = "", const string vtx1SrefPlnrMVertex = "", const string lgd1SrefPlnrMLineguide = "", const string vtx2SrefPlnrMVertex = "", const string lgd2SrefPlnrMLineguide = "", const string vtx3SrefPlnrMVertex = "", const string lgd3SrefPlnrMLineguide = "", const string vtx4SrefPlnrMVertex = "", const string lgd4SrefPlnrMLineguide = "", const string dx = "", const string dy = "", const string dxy = "", const string dz = "");

public:
	ubigint ref;
	uint ixVBasetype;
	ubigint dsnRefPlnrMDesign;
	uint dsnNum;
	string sref;
	string flrSrefPlnrMLevel;
	string ceilSrefPlnrMLevel;
	string vtx1SrefPlnrMVertex;
	string lgd1SrefPlnrMLineguide;
	string vtx2SrefPlnrMVertex;
	string lgd2SrefPlnrMLineguide;
	string vtx3SrefPlnrMVertex;
	string lgd3SrefPlnrMLineguide;
	string vtx4SrefPlnrMVertex;
	string lgd4SrefPlnrMLineguide;
	string dx;
	string dy;
	string dxy;
	string dz;

public:
	bool operator==(const PlnrMDomain& comp);
	bool operator!=(const PlnrMDomain& comp);
};

/**
  * ListPlnrMDomain: recordset of TblPlnrMDomain
  */
class ListPlnrMDomain {

public:
	ListPlnrMDomain();
	ListPlnrMDomain(const ListPlnrMDomain& src);
	~ListPlnrMDomain();

	void clear();
	unsigned int size() const;
	void append(PlnrMDomain* rec);

	PlnrMDomain* operator[](const uint ix);
	ListPlnrMDomain& operator=(const ListPlnrMDomain& src);
	bool operator==(const ListPlnrMDomain& comp);
	bool operator!=(const ListPlnrMDomain& comp);

public:
	vector<PlnrMDomain*> nodes;
};

/**
  * TblPlnrMDomain: C++ wrapper for table TblPlnrMDomain
  */
class TblPlnrMDomain {

public:
	TblPlnrMDomain();
	virtual ~TblPlnrMDomain();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMDomain** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDomain& rst);

	virtual void insertRec(PlnrMDomain* rec);
	ubigint insertNewRec(PlnrMDomain** rec = NULL, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const string flrSrefPlnrMLevel = "", const string ceilSrefPlnrMLevel = "", const string vtx1SrefPlnrMVertex = "", const string lgd1SrefPlnrMLineguide = "", const string vtx2SrefPlnrMVertex = "", const string lgd2SrefPlnrMLineguide = "", const string vtx3SrefPlnrMVertex = "", const string lgd3SrefPlnrMLineguide = "", const string vtx4SrefPlnrMVertex = "", const string lgd4SrefPlnrMLineguide = "", const string dx = "", const string dy = "", const string dxy = "", const string dz = "");
	ubigint appendNewRecToRst(ListPlnrMDomain& rst, PlnrMDomain** rec = NULL, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const string flrSrefPlnrMLevel = "", const string ceilSrefPlnrMLevel = "", const string vtx1SrefPlnrMVertex = "", const string lgd1SrefPlnrMLineguide = "", const string vtx2SrefPlnrMVertex = "", const string lgd2SrefPlnrMLineguide = "", const string vtx3SrefPlnrMVertex = "", const string lgd3SrefPlnrMLineguide = "", const string vtx4SrefPlnrMVertex = "", const string lgd4SrefPlnrMLineguide = "", const string dx = "", const string dy = "", const string dxy = "", const string dz = "");
	virtual void insertRst(ListPlnrMDomain& rst, bool transact = false);
	virtual void updateRec(PlnrMDomain* rec);
	virtual void updateRst(ListPlnrMDomain& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMDomain** rec);
	virtual bool loadRefByTypDsn(uint ixVBasetype, ubigint dsnRefPlnrMDesign, ubigint& val);
	virtual ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomain& rst);
	virtual ubigint loadRstByTypDsn(uint ixVBasetype, ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomain& rst);
	virtual bool loadSrfByRef(ubigint ref, string& val);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMDomain& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMDomain: C++ wrapper for table TblPlnrMDomain (MySQL database)
  */
class MyTblPlnrMDomain : public TblPlnrMDomain, public MyTable {

public:
	MyTblPlnrMDomain();
	~MyTblPlnrMDomain();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDomain& rst);

	void insertRec(PlnrMDomain* rec);
	void insertRst(ListPlnrMDomain& rst, bool transact = false);
	void updateRec(PlnrMDomain* rec);
	void updateRst(ListPlnrMDomain& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDomain** rec);
	bool loadRefByTypDsn(uint ixVBasetype, ubigint dsnRefPlnrMDesign, ubigint& val);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomain& rst);
	ubigint loadRstByTypDsn(uint ixVBasetype, ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomain& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMDomain: C++ wrapper for table TblPlnrMDomain (PgSQL database)
  */
class PgTblPlnrMDomain : public TblPlnrMDomain, public PgTable {

public:
	PgTblPlnrMDomain();
	~PgTblPlnrMDomain();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMDomain** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMDomain& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMDomain** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMDomain& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDomain** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDomain& rst);

	void insertRec(PlnrMDomain* rec);
	void insertRst(ListPlnrMDomain& rst, bool transact = false);
	void updateRec(PlnrMDomain* rec);
	void updateRst(ListPlnrMDomain& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDomain** rec);
	bool loadRefByTypDsn(uint ixVBasetype, ubigint dsnRefPlnrMDesign, ubigint& val);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomain& rst);
	ubigint loadRstByTypDsn(uint ixVBasetype, ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomain& rst);
	bool loadSrfByRef(ubigint ref, string& val);
};
// IP pgTbl --- END

#endif

