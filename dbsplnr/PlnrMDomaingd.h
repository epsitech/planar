/**
  * \file PlnrMDomaingd.h
  * database access for table TblPlnrMDomaingd (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMDOMAINGD_H
#define PLNRMDOMAINGD_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMDomaingd: record of TblPlnrMDomaingd
  */
class PlnrMDomaingd {

public:
	PlnrMDomaingd(const ubigint ref = 0, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const string srefPlnrMLevel = "", const string av1SrefPlnrMVertex = "", const string av2SrefPlnrMVertex = "", const string al1SrefPlnrMLineguide = "", const string al2SrefPlnrMLineguide = "", const string srefPlnrMArcguide = "", const string d = "", const string dphi = "");

public:
	ubigint ref;
	uint ixVBasetype;
	ubigint dsnRefPlnrMDesign;
	uint dsnNum;
	string sref;
	string srefPlnrMLevel;
	string av1SrefPlnrMVertex;
	string av2SrefPlnrMVertex;
	string al1SrefPlnrMLineguide;
	string al2SrefPlnrMLineguide;
	string srefPlnrMArcguide;
	string d;
	string dphi;

public:
	bool operator==(const PlnrMDomaingd& comp);
	bool operator!=(const PlnrMDomaingd& comp);
};

/**
  * ListPlnrMDomaingd: recordset of TblPlnrMDomaingd
  */
class ListPlnrMDomaingd {

public:
	ListPlnrMDomaingd();
	ListPlnrMDomaingd(const ListPlnrMDomaingd& src);
	~ListPlnrMDomaingd();

	void clear();
	unsigned int size() const;
	void append(PlnrMDomaingd* rec);

	PlnrMDomaingd* operator[](const uint ix);
	ListPlnrMDomaingd& operator=(const ListPlnrMDomaingd& src);
	bool operator==(const ListPlnrMDomaingd& comp);
	bool operator!=(const ListPlnrMDomaingd& comp);

public:
	vector<PlnrMDomaingd*> nodes;
};

/**
  * TblPlnrMDomaingd: C++ wrapper for table TblPlnrMDomaingd
  */
class TblPlnrMDomaingd {

public:
	TblPlnrMDomaingd();
	virtual ~TblPlnrMDomaingd();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMDomaingd** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDomaingd& rst);

	virtual void insertRec(PlnrMDomaingd* rec);
	ubigint insertNewRec(PlnrMDomaingd** rec = NULL, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const string srefPlnrMLevel = "", const string av1SrefPlnrMVertex = "", const string av2SrefPlnrMVertex = "", const string al1SrefPlnrMLineguide = "", const string al2SrefPlnrMLineguide = "", const string srefPlnrMArcguide = "", const string d = "", const string dphi = "");
	ubigint appendNewRecToRst(ListPlnrMDomaingd& rst, PlnrMDomaingd** rec = NULL, const uint ixVBasetype = 0, const ubigint dsnRefPlnrMDesign = 0, const uint dsnNum = 0, const string sref = "", const string srefPlnrMLevel = "", const string av1SrefPlnrMVertex = "", const string av2SrefPlnrMVertex = "", const string al1SrefPlnrMLineguide = "", const string al2SrefPlnrMLineguide = "", const string srefPlnrMArcguide = "", const string d = "", const string dphi = "");
	virtual void insertRst(ListPlnrMDomaingd& rst, bool transact = false);
	virtual void updateRec(PlnrMDomaingd* rec);
	virtual void updateRst(ListPlnrMDomaingd& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMDomaingd** rec);
	virtual ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomaingd& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMDomaingd& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMDomaingd: C++ wrapper for table TblPlnrMDomaingd (MySQL database)
  */
class MyTblPlnrMDomaingd : public TblPlnrMDomaingd, public MyTable {

public:
	MyTblPlnrMDomaingd();
	~MyTblPlnrMDomaingd();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDomaingd** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDomaingd& rst);

	void insertRec(PlnrMDomaingd* rec);
	void insertRst(ListPlnrMDomaingd& rst, bool transact = false);
	void updateRec(PlnrMDomaingd* rec);
	void updateRst(ListPlnrMDomaingd& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDomaingd** rec);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomaingd& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMDomaingd: C++ wrapper for table TblPlnrMDomaingd (PgSQL database)
  */
class PgTblPlnrMDomaingd : public TblPlnrMDomaingd, public PgTable {

public:
	PgTblPlnrMDomaingd();
	~PgTblPlnrMDomaingd();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMDomaingd** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMDomaingd& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMDomaingd** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMDomaingd& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMDomaingd** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMDomaingd& rst);

	void insertRec(PlnrMDomaingd* rec);
	void insertRst(ListPlnrMDomaingd& rst, bool transact = false);
	void updateRec(PlnrMDomaingd* rec);
	void updateRst(ListPlnrMDomaingd& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMDomaingd** rec);
	ubigint loadRstByDsn(ubigint dsnRefPlnrMDesign, const bool append, ListPlnrMDomaingd& rst);
};
// IP pgTbl --- END

#endif

