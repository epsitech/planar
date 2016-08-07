/**
  * \file PlnrQClcRef1NFile.h
  * Dbs and XML wrapper for table TblPlnrQClcRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCLCREF1NFILE_H
#define PLNRQCLCREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQClcRef1NFile: record of TblPlnrQClcRef1NFile
  */
class PlnrQClcRef1NFile {

public:
	PlnrQClcRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

public:
	ubigint qref;
	ubigint jref;
	uint jnum;
	ubigint ref;
	string stubRef;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "", bool jnumattr = false, bool shorttags = false);
};

/**
  * ListPlnrQClcRef1NFile: recordset of TblPlnrQClcRef1NFile
  */
class ListPlnrQClcRef1NFile {

public:
	ListPlnrQClcRef1NFile();
	ListPlnrQClcRef1NFile(const ListPlnrQClcRef1NFile& src);
	~ListPlnrQClcRef1NFile();

	void clear();
	unsigned int size() const;
	void append(PlnrQClcRef1NFile* rec);

	ListPlnrQClcRef1NFile& operator=(const ListPlnrQClcRef1NFile& src);

public:
	vector<PlnrQClcRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQClcRef1NFile: C++ wrapper for table TblPlnrQClcRef1NFile
  */
class TblPlnrQClcRef1NFile {

public:
	TblPlnrQClcRef1NFile();
	virtual ~TblPlnrQClcRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQClcRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcRef1NFile& rst);

	virtual void insertRec(PlnrQClcRef1NFile* rec);
	ubigint insertNewRec(PlnrQClcRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQClcRef1NFile& rst, PlnrQClcRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQClcRef1NFile& rst);
	virtual void updateRec(PlnrQClcRef1NFile* rec);
	virtual void updateRst(ListPlnrQClcRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQClcRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQClcRef1NFile: C++ wrapper for table TblPlnrQClcRef1NFile (MySQL database)
  */
class MyTblPlnrQClcRef1NFile : public TblPlnrQClcRef1NFile, public MyTable {

public:
	MyTblPlnrQClcRef1NFile();
	~MyTblPlnrQClcRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcRef1NFile& rst);

	void insertRec(PlnrQClcRef1NFile* rec);
	void insertRst(ListPlnrQClcRef1NFile& rst);
	void updateRec(PlnrQClcRef1NFile* rec);
	void updateRst(ListPlnrQClcRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQClcRef1NFile: C++ wrapper for table TblPlnrQClcRef1NFile (PgSQL database)
  */
class PgTblPlnrQClcRef1NFile : public TblPlnrQClcRef1NFile, public PgTable {

public:
	PgTblPlnrQClcRef1NFile();
	~PgTblPlnrQClcRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQClcRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQClcRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQClcRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQClcRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQClcRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQClcRef1NFile& rst);

	void insertRec(PlnrQClcRef1NFile* rec);
	void insertRst(ListPlnrQClcRef1NFile& rst);
	void updateRec(PlnrQClcRef1NFile* rec);
	void updateRst(ListPlnrQClcRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQClcRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQClcRef1NFile& rst);
};
// IP pgTbl --- END

#endif

