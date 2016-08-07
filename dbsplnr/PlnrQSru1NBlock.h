/**
  * \file PlnrQSru1NBlock.h
  * Dbs and XML wrapper for table TblPlnrQSru1NBlock (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRQSRU1NBLOCK_H
#define PLNRQSRU1NBLOCK_H

// IP myInclude --- BEGIN
#include <dartcore/MyDbs.h>
// IP myInclude --- END
// IP pgInclude --- BEGIN
#include <dartcore/PgDbs.h>
// IP pgInclude --- END

#include <dartcore/Xmlio.h>

using namespace Xmlio;

/**
  * PlnrQSru1NBlock: record of TblPlnrQSru1NBlock
  */
class PlnrQSru1NBlock {

public:
	PlnrQSru1NBlock(const ubigint qref = 0, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");

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
  * ListPlnrQSru1NBlock: recordset of TblPlnrQSru1NBlock
  */
class ListPlnrQSru1NBlock {

public:
	ListPlnrQSru1NBlock();
	ListPlnrQSru1NBlock(const ListPlnrQSru1NBlock& src);
	~ListPlnrQSru1NBlock();

	void clear();
	unsigned int size() const;
	void append(PlnrQSru1NBlock* rec);

	ListPlnrQSru1NBlock& operator=(const ListPlnrQSru1NBlock& src);

public:
	vector<PlnrQSru1NBlock*> nodes;

public:
	void writeXML(xmlTextWriter* wr, string difftag = "");
};

/**
  * TblPlnrQSru1NBlock: C++ wrapper for table TblPlnrQSru1NBlock
  */
class TblPlnrQSru1NBlock {

public:
	TblPlnrQSru1NBlock();
	virtual ~TblPlnrQSru1NBlock();

public:
	virtual bool loadRecBySQL(const string& sqlstr, PlnrQSru1NBlock** rec);
	virtual ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSru1NBlock& rst);

	virtual void insertRec(PlnrQSru1NBlock* rec);
	ubigint insertNewRec(PlnrQSru1NBlock** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	ubigint appendNewRecToRst(ListPlnrQSru1NBlock& rst, PlnrQSru1NBlock** rec = NULL, const ubigint jref = 0, const uint jnum = 0, const ubigint ref = 0, const string stubRef = "");
	virtual void insertRst(ListPlnrQSru1NBlock& rst);
	virtual void updateRec(PlnrQSru1NBlock* rec);
	virtual void updateRst(ListPlnrQSru1NBlock& rst);
	virtual void removeRecByQref(ubigint qref);
	virtual void removeRstByJref(ubigint jref);

	virtual bool loadRecByQref(ubigint qref, PlnrQSru1NBlock** rec);
	virtual ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSru1NBlock& rst);
};

// IP myTbl --- BEGIN
/**
  * MyPlnrQSru1NBlock: C++ wrapper for table TblPlnrQSru1NBlock (MySQL database)
  */
class MyTblPlnrQSru1NBlock : public TblPlnrQSru1NBlock, public MyTable {

public:
	MyTblPlnrQSru1NBlock();
	~MyTblPlnrQSru1NBlock();

public:
	void initStatements();

public:
	MYSQL_STMT* stmtInsertRec;
	MYSQL_STMT* stmtUpdateRec;
	MYSQL_STMT* stmtRemoveRecByQref;
	MYSQL_STMT* stmtRemoveRstByJref;

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSru1NBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSru1NBlock& rst);

	void insertRec(PlnrQSru1NBlock* rec);
	void insertRst(ListPlnrQSru1NBlock& rst);
	void updateRec(PlnrQSru1NBlock* rec);
	void updateRst(ListPlnrQSru1NBlock& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSru1NBlock** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSru1NBlock& rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/**
  * PgPlnrQSru1NBlock: C++ wrapper for table TblPlnrQSru1NBlock (PgSQL database)
  */
class PgTblPlnrQSru1NBlock : public TblPlnrQSru1NBlock, public PgTable {

public:
	PgTblPlnrQSru1NBlock();
	~PgTblPlnrQSru1NBlock();

public:
	void initStatements();

private:
	bool loadRec(PGresult* res, PlnrQSru1NBlock** rec);
	ubigint loadRst(PGresult* res, const bool append, ListPlnrQSru1NBlock& rst);
	bool loadRecByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, PlnrQSru1NBlock** rec);
	ubigint loadRstByStmt(const string& srefStmt, const unsigned int N, const char** vals, const int* l, const int* f, const bool append, ListPlnrQSru1NBlock& rst);

public:
	bool loadRecBySQL(const string& sqlstr, PlnrQSru1NBlock** rec);
	ubigint loadRstBySQL(const string& sqlstr, const bool append, ListPlnrQSru1NBlock& rst);

	void insertRec(PlnrQSru1NBlock* rec);
	void insertRst(ListPlnrQSru1NBlock& rst);
	void updateRec(PlnrQSru1NBlock* rec);
	void updateRst(ListPlnrQSru1NBlock& rst);
	void removeRecByQref(ubigint qref);
	void removeRstByJref(ubigint jref);

	bool loadRecByQref(ubigint qref, PlnrQSru1NBlock** rec);
	ubigint loadRstByJref(ubigint jref, const bool append, ListPlnrQSru1NBlock& rst);
};
// IP pgTbl --- END

#endif

