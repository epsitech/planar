/**
  * \file PlnrMFile.h
  * database access for table TblPlnrMFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRMFILE_H
#define PLNRMFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

/**
  * PlnrMFile: record of TblPlnrMFile
  */
class PlnrMFile {

public:
	PlnrMFile(const ubigint ref = 0, const ubigint grp = 0, const ubigint own = 0, const ubigint refPlnrCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const uint Size = 0, const string Comment = "");

public:
	ubigint ref;
	ubigint grp;
	ubigint own;
	ubigint refPlnrCFile;
	uint refIxVTbl;
	ubigint refUref;
	string osrefKContent;
	uint Archived;
	string Filename;
	string Archivename;
	string srefKMimetype;
	uint Size;
	string Comment;

public:
	bool operator==(const PlnrMFile& comp);
	bool operator!=(const PlnrMFile& comp);
};

/**
  * ListPlnrMFile: recordset of TblPlnrMFile
  */
class ListPlnrMFile {

public:
	ListPlnrMFile();
	ListPlnrMFile(const ListPlnrMFile& src);
	~ListPlnrMFile();

	void clear();
	unsigned int size() const;
	void append(PlnrMFile* rec);

	PlnrMFile* operator[](const uint ix);
	ListPlnrMFile& operator=(const ListPlnrMFile& src);
	bool operator==(const ListPlnrMFile& comp);
	bool operator!=(const ListPlnrMFile& comp);

public:
	vector<PlnrMFile*> nodes;
};

/**
  * TblPlnrMFile: C++ wrapper for table TblPlnrMFile
  */
class TblPlnrMFile {

public:
	TblPlnrMFile();
	virtual ~TblPlnrMFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrMFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMFile& rst);

	virtual void insertRec(PlnrMFile* rec);
	ubigint insertNewRec(PlnrMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refPlnrCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const uint Size = 0, const string Comment = "");
	ubigint appendNewRecToRst(ListPlnrMFile& rst, PlnrMFile** rec = NULL, const ubigint grp = 0, const ubigint own = 0, const ubigint refPlnrCFile = 0, const uint refIxVTbl = 0, const ubigint refUref = 0, const string osrefKContent = "", const uint Archived = 0, const string Filename = "", const string Archivename = "", const string srefKMimetype = "", const uint Size = 0, const string Comment = "");
	virtual void insertRst(ListPlnrMFile& rst, bool transact = false);
	virtual void updateRec(PlnrMFile* rec);
	virtual void updateRst(ListPlnrMFile& rst, bool transact = false);
	virtual void removeRecByRef(ubigint ref);

	virtual bool loadRecByRef(ubigint ref, PlnrMFile** rec);
	virtual bool loadFnmByRef(ubigint ref, string& val);
	virtual ubigint loadRefsByClu(ubigint refPlnrCFile, const bool append, vector<ubigint>& refs);
	virtual ubigint loadRstByClu(ubigint refPlnrCFile, const bool append, ListPlnrMFile& rst);
	ubigint loadRstByRefs(vector<ubigint>& refs, const bool append, ListPlnrMFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrMFile: C++ wrapper for table TblPlnrMFile (MySQL database)
  */
class MyTblPlnrMFile : public TblPlnrMFile, public MyTable {

public:
	MyTblPlnrMFile();
	~MyTblPlnrMFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByRef;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMFile& rst);

	void insertRec(PlnrMFile* rec);
	void insertRst(ListPlnrMFile& rst, bool transact = false);
	void updateRec(PlnrMFile* rec);
	void updateRst(ListPlnrMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMFile** rec);
	bool loadFnmByRef(ubigint ref, string& val);
	ubigint loadRefsByClu(ubigint refPlnrCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refPlnrCFile, const bool append, ListPlnrMFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrMFile: C++ wrapper for table TblPlnrMFile (PgSQL database)
  */
class PgTblPlnrMFile : public TblPlnrMFile, public PgTable {

public:
	PgTblPlnrMFile();
	~PgTblPlnrMFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrMFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrMFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrMFile** rec);
// IP pgLoadRstByStmt --- BEGIN
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrMFile& rst);
// IP pgLoadRstByStmt --- END

public:
	bool loadRecBySQL(const string& sqlstr, PlnrMFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrMFile& rst);

	void insertRec(PlnrMFile* rec);
	void insertRst(ListPlnrMFile& rst, bool transact = false);
	void updateRec(PlnrMFile* rec);
	void updateRst(ListPlnrMFile& rst, bool transact = false);
	void removeRecByRef(ubigint ref);

	bool loadRecByRef(ubigint ref, PlnrMFile** rec);
	bool loadFnmByRef(ubigint ref, string& val);
	ubigint loadRefsByClu(ubigint refPlnrCFile, const bool append, vector<ubigint>& refs);
	ubigint loadRstByClu(ubigint refPlnrCFile, const bool append, ListPlnrMFile& rst);
};
// IP pgTbl --- END

#endif

