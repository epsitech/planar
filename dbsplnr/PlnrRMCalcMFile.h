/**
  * \file PlnrRMCalcMFile.h
  * database access for table TblPlnrRMCalcMFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRRMCALCMFILE_H
#define PLNRRMCALCMFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrRMCalcMFile: record of TblPlnrRMCalcMFile
  */
class PlnrRMCalcMFile {

public:
	PlnrRMCalcMFile(const ubigint ref = 0, const ubigint x1RefPlnrMCalcitem = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMFile = 0, const uint ixVIo = 0);

public:
	ubigint ref;
	ubigint x1RefPlnrMCalcitem;
	ubigint refPlnrMCalc;
	ubigint refPlnrMFile;
	uint ixVIo;

public:
	bool operator==(const PlnrRMCalcMFile& comp);
	bool operator!=(const PlnrRMCalcMFile& comp);
};

/**
  * ListPlnrRMCalcMFile: recordset of TblPlnrRMCalcMFile
  */
class ListPlnrRMCalcMFile {

public:
	ListPlnrRMCalcMFile();
	ListPlnrRMCalcMFile(const ListPlnrRMCalcMFile& src);
	~ListPlnrRMCalcMFile();

	void clear();
	unsigned int size() const;
	void append(PlnrRMCalcMFile* rec);

	PlnrRMCalcMFile* operator[](const uint ix);
	ListPlnrRMCalcMFile& operator=(const ListPlnrRMCalcMFile& src);
	bool operator==(const ListPlnrRMCalcMFile& comp);
	bool operator!=(const ListPlnrRMCalcMFile& comp);

public:
	vector<PlnrRMCalcMFile*> nodes;
};

/**
  * TblPlnrRMCalcMFile: C++ wrapper for table TblPlnrRMCalcMFile
  */
class TblPlnrRMCalcMFile {

public:
	TblPlnrRMCalcMFile();
	virtual ~TblPlnrRMCalcMFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrRMCalcMFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMCalcMFile& rst);

	virtual void insertRec(PlnrRMCalcMFile* rec);
	ubigint insertNewRec(PlnrRMCalcMFile** rec = NULL, const ubigint x1RefPlnrMCalcitem = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMFile = 0, const uint ixVIo = 0);
	ubigint appendNewRecToRst(ListPlnrRMCalcMFile& rst, PlnrRMCalcMFile** rec = NULL, const ubigint x1RefPlnrMCalcitem = 0, const ubigint refPlnrMCalc = 0, const ubigint refPlnrMFile = 0, const uint ixVIo = 0);
	virtual void insertRst(ListPlnrRMCalcMFile& rst, bool transact = false);
	virtual void updateRec(PlnrRMCalcMFile* rec);
	virtual void updateRst(ListPlnrRMCalcMFile& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrRMCalcMFile** rec);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrRMCalcMFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrRMCalcMFile: C++ wrapper for table TblPlnrRMCalcMFile (MySQL database)
  */
class MyTblPlnrRMCalcMFile : public TblPlnrRMCalcMFile, public MyTable {

public:
	MyTblPlnrRMCalcMFile();
	~MyTblPlnrRMCalcMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMCalcMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMCalcMFile& rst);

	void insertRec(PlnrRMCalcMFile* rec);
	void insertRst(ListPlnrRMCalcMFile& rst, bool transact = false);
	void updateRec(PlnrRMCalcMFile* rec);
	void updateRst(ListPlnrRMCalcMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMCalcMFile** rec);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrRMCalcMFile: C++ wrapper for table TblPlnrRMCalcMFile (PgSQL database)
  */
class PgTblPlnrRMCalcMFile : public TblPlnrRMCalcMFile, public PgTable {

public:
	PgTblPlnrRMCalcMFile();
	~PgTblPlnrRMCalcMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrRMCalcMFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrRMCalcMFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrRMCalcMFile** rec);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrRMCalcMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrRMCalcMFile& rst);

	void insertRec(PlnrRMCalcMFile* rec);
	void insertRst(ListPlnrRMCalcMFile& rst, bool transact = false);
	void updateRec(PlnrRMCalcMFile* rec);
	void updateRst(ListPlnrRMCalcMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrRMCalcMFile** rec);
};
// IP pgTbl --- END

#endif

