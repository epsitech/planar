/**
  * \file PlnrQLyr1NBlock.h
  * Dbs and XML wrapper for table TblPlnrQLyr1NBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQLYR1NBLOCK_H
#define PLNRQLYR1NBLOCK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQLyr1NBlock: record of TblPlnrQLyr1NBlock
  */
class PlnrQLyr1NBlock {

public:
	PlnrQLyr1NBlock(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQLyr1NBlock: recordset of TblPlnrQLyr1NBlock
  */
class ListPlnrQLyr1NBlock {

public:
	ListPlnrQLyr1NBlock();
	ListPlnrQLyr1NBlock(const ListPlnrQLyr1NBlock& src);
	~ListPlnrQLyr1NBlock();

	void clear();
	unsigned int size() const;
	void append(PlnrQLyr1NBlock* rec);

	ListPlnrQLyr1NBlock& operator=(const ListPlnrQLyr1NBlock& src);

public:
	vector<PlnrQLyr1NBlock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQLyr1NBlock: C++ wrapper for table TblPlnrQLyr1NBlock
  */
class TblPlnrQLyr1NBlock {

public:
	TblPlnrQLyr1NBlock();
	virtual ~TblPlnrQLyr1NBlock();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQLyr1NBlock** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyr1NBlock& rst);

	virtual void insertRec(PlnrQLyr1NBlock* rec);
	ubigint insertNewRec(PlnrQLyr1NBlock** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQLyr1NBlock& rst, PlnrQLyr1NBlock** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQLyr1NBlock& rst);
	virtual void updateRec(PlnrQLyr1NBlock* rec);
	virtual void updateRst(ListPlnrQLyr1NBlock& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQLyr1NBlock** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyr1NBlock& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQLyr1NBlock: C++ wrapper for table TblPlnrQLyr1NBlock (MySQL database)
  */
class MyTblPlnrQLyr1NBlock : public TblPlnrQLyr1NBlock, public MyTable {

public:
	MyTblPlnrQLyr1NBlock();
	~MyTblPlnrQLyr1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyr1NBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyr1NBlock& rst);

	void insertRec(PlnrQLyr1NBlock* rec);
	void insertRst(ListPlnrQLyr1NBlock& rst);
	void updateRec(PlnrQLyr1NBlock* rec);
	void updateRst(ListPlnrQLyr1NBlock& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyr1NBlock** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyr1NBlock& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQLyr1NBlock: C++ wrapper for table TblPlnrQLyr1NBlock (PgSQL database)
  */
class PgTblPlnrQLyr1NBlock : public TblPlnrQLyr1NBlock, public PgTable {

public:
	PgTblPlnrQLyr1NBlock();
	~PgTblPlnrQLyr1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQLyr1NBlock** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQLyr1NBlock& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQLyr1NBlock** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQLyr1NBlock& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQLyr1NBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQLyr1NBlock& rst);

	void insertRec(PlnrQLyr1NBlock* rec);
	void insertRst(ListPlnrQLyr1NBlock& rst);
	void updateRec(PlnrQLyr1NBlock* rec);
	void updateRst(ListPlnrQLyr1NBlock& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQLyr1NBlock** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQLyr1NBlock& rst);
};
// IP pgTbl --- END

#endif

