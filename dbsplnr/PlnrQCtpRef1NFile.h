/**
  * \file PlnrQCtpRef1NFile.h
  * Dbs and XML wrapper for table TblPlnrQCtpRef1NFile (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQCTPREF1NFILE_H
#define PLNRQCTPREF1NFILE_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQCtpRef1NFile: record of TblPlnrQCtpRef1NFile
  */
class PlnrQCtpRef1NFile {

public:
	PlnrQCtpRef1NFile(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQCtpRef1NFile: recordset of TblPlnrQCtpRef1NFile
  */
class ListPlnrQCtpRef1NFile {

public:
	ListPlnrQCtpRef1NFile();
	ListPlnrQCtpRef1NFile(const ListPlnrQCtpRef1NFile& src);
	~ListPlnrQCtpRef1NFile();

	void clear();
	unsigned int size() const;
	void append(PlnrQCtpRef1NFile* rec);

	ListPlnrQCtpRef1NFile& operator=(const ListPlnrQCtpRef1NFile& src);

public:
	vector<PlnrQCtpRef1NFile*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQCtpRef1NFile: C++ wrapper for table TblPlnrQCtpRef1NFile
  */
class TblPlnrQCtpRef1NFile {

public:
	TblPlnrQCtpRef1NFile();
	virtual ~TblPlnrQCtpRef1NFile();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQCtpRef1NFile** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpRef1NFile& rst);

	virtual void insertRec(PlnrQCtpRef1NFile* rec);
	ubigint insertNewRec(PlnrQCtpRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQCtpRef1NFile& rst, PlnrQCtpRef1NFile** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQCtpRef1NFile& rst);
	virtual void updateRec(PlnrQCtpRef1NFile* rec);
	virtual void updateRst(ListPlnrQCtpRef1NFile& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQCtpRef1NFile** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpRef1NFile& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQCtpRef1NFile: C++ wrapper for table TblPlnrQCtpRef1NFile (MySQL database)
  */
class MyTblPlnrQCtpRef1NFile : public TblPlnrQCtpRef1NFile, public MyTable {

public:
	MyTblPlnrQCtpRef1NFile();
	~MyTblPlnrQCtpRef1NFile();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpRef1NFile& rst);

	void insertRec(PlnrQCtpRef1NFile* rec);
	void insertRst(ListPlnrQCtpRef1NFile& rst);
	void updateRec(PlnrQCtpRef1NFile* rec);
	void updateRst(ListPlnrQCtpRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpRef1NFile& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQCtpRef1NFile: C++ wrapper for table TblPlnrQCtpRef1NFile (PgSQL database)
  */
class PgTblPlnrQCtpRef1NFile : public TblPlnrQCtpRef1NFile, public PgTable {

public:
	PgTblPlnrQCtpRef1NFile();
	~PgTblPlnrQCtpRef1NFile();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQCtpRef1NFile** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQCtpRef1NFile& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQCtpRef1NFile** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQCtpRef1NFile& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQCtpRef1NFile** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQCtpRef1NFile& rst);

	void insertRec(PlnrQCtpRef1NFile* rec);
	void insertRst(ListPlnrQCtpRef1NFile& rst);
	void updateRec(PlnrQCtpRef1NFile* rec);
	void updateRst(ListPlnrQCtpRef1NFile& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQCtpRef1NFile** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQCtpRef1NFile& rst);
};
// IP pgTbl --- END

#endif

