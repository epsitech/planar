/**
  * \file PlnrJMArcguideR.h
  * database access for table TblPlnrJMArcguideR (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRJMARCGUIDER_H
#define PLNRJMARCGUIDER_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrJMArcguideR: record of TblPlnrJMArcguideR
  */
class PlnrJMArcguideR {

public:
	PlnrJMArcguideR(const ubigint ref = 0, const ubigint refPlnrMArcguide = 0, const ubigint x1RefPlnrMDesign = 0, const double r = 0.0);

public:
	ubigint ref;
	ubigint refPlnrMArcguide;
	ubigint x1RefPlnrMDesign;
	double r;

public:
	bool operator==(const PlnrJMArcguideR& comp);
	bool operator!=(const PlnrJMArcguideR& comp);
};

/**
  * ListPlnrJMArcguideR: recordset of TblPlnrJMArcguideR
  */
class ListPlnrJMArcguideR {

public:
	ListPlnrJMArcguideR();
	ListPlnrJMArcguideR(const ListPlnrJMArcguideR& src);
	~ListPlnrJMArcguideR();

	void clear();
	unsigned int size() const;
	void append(PlnrJMArcguideR* rec);

	PlnrJMArcguideR* operator[](const uint ix);
	ListPlnrJMArcguideR& operator=(const ListPlnrJMArcguideR& src);
	bool operator==(const ListPlnrJMArcguideR& comp);
	bool operator!=(const ListPlnrJMArcguideR& comp);

public:
	vector<PlnrJMArcguideR*> nodes;
};

/**
  * TblPlnrJMArcguideR: C++ wrapper for table TblPlnrJMArcguideR
  */
class TblPlnrJMArcguideR {

public:
	TblPlnrJMArcguideR();
	virtual ~TblPlnrJMArcguideR();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrJMArcguideR** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMArcguideR& rst);

	virtual void insertRec(PlnrJMArcguideR* rec);
	ubigint insertNewRec(PlnrJMArcguideR** rec = NULL, const ubigint refPlnrMArcguide = 0, const ubigint x1RefPlnrMDesign = 0, const double r = 0.0);
	ubigint appendNewRecToRst(ListPlnrJMArcguideR& rst, PlnrJMArcguideR** rec = NULL, const ubigint refPlnrMArcguide = 0, const ubigint x1RefPlnrMDesign = 0, const double r = 0.0);
	virtual void insertRst(ListPlnrJMArcguideR& rst, bool transact = false);
	virtual void updateRec(PlnrJMArcguideR* rec);
	virtual void updateRst(ListPlnrJMArcguideR& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrJMArcguideR** rec);
	virtual bool loadRecByAgdDsn(ubigint refPlnrMArcguide, ubigint x1RefPlnrMDesign, PlnrJMArcguideR** rec);
	virtual ubigint loadRstByAgd(ubigint refPlnrMArcguide, const bool append, ListPlnrJMArcguideR& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrJMArcguideR& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrJMArcguideR: C++ wrapper for table TblPlnrJMArcguideR (MySQL database)
  */
class MyTblPlnrJMArcguideR : public TblPlnrJMArcguideR, public MyTable {

public:
	MyTblPlnrJMArcguideR();
	~MyTblPlnrJMArcguideR();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMArcguideR** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMArcguideR& rst);

	void insertRec(PlnrJMArcguideR* rec);
	void insertRst(ListPlnrJMArcguideR& rst, bool transact = false);
	void updateRec(PlnrJMArcguideR* rec);
	void updateRst(ListPlnrJMArcguideR& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMArcguideR** rec);
	bool loadRecByAgdDsn(ubigint refPlnrMArcguide, ubigint x1RefPlnrMDesign, PlnrJMArcguideR** rec);
	ubigint loadRstByAgd(ubigint refPlnrMArcguide, const bool append, ListPlnrJMArcguideR& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrJMArcguideR: C++ wrapper for table TblPlnrJMArcguideR (PgSQL database)
  */
class PgTblPlnrJMArcguideR : public TblPlnrJMArcguideR, public PgTable {

public:
	PgTblPlnrJMArcguideR();
	~PgTblPlnrJMArcguideR();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrJMArcguideR** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrJMArcguideR& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrJMArcguideR** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrJMArcguideR& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrJMArcguideR** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrJMArcguideR& rst);

	void insertRec(PlnrJMArcguideR* rec);
	void insertRst(ListPlnrJMArcguideR& rst, bool transact = false);
	void updateRec(PlnrJMArcguideR* rec);
	void updateRst(ListPlnrJMArcguideR& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrJMArcguideR** rec);
	bool loadRecByAgdDsn(ubigint refPlnrMArcguide, ubigint x1RefPlnrMDesign, PlnrJMArcguideR** rec);
	ubigint loadRstByAgd(ubigint refPlnrMArcguide, const bool append, ListPlnrJMArcguideR& rst);
};
// IP pgTbl --- END

#endif

