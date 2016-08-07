/**
  * \file PlnrCFile.cpp
  * Dbs and XML wrapper for table TblPlnrCFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrCFile.h"

/******************************************************************************
 class TblPlnrCFile
 ******************************************************************************/

TblPlnrCFile::TblPlnrCFile() {
};

TblPlnrCFile::~TblPlnrCFile() {
};

ubigint TblPlnrCFile::getNewRef() {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrCFile
 ******************************************************************************/

MyTblPlnrCFile::MyTblPlnrCFile() : TblPlnrCFile(), MyTable() {
	stmtGetNewRef = NULL;
};

MyTblPlnrCFile::~MyTblPlnrCFile() {
	if (stmtGetNewRef) delete(stmtGetNewRef);
};

void MyTblPlnrCFile::initStatements() {
	stmtGetNewRef = createStatement("INSERT INTO TblPlnrCFile () VALUES ()", false);
};

ubigint MyTblPlnrCFile::getNewRef() {
	MYSQL_BIND bind[] = {};

	if (mysql_stmt_bind_param(stmtGetNewRef, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrCFile / stmtGetNewRef)\n");
	if (mysql_stmt_execute(stmtGetNewRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrCFile / stmtGetNewRef)\n");
	return mysql_stmt_insert_id(stmtGetNewRef);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrCFile
 ******************************************************************************/

PgTblPlnrCFile::PgTblPlnrCFile() : TblPlnrCFile(), PgTable() {
};

PgTblPlnrCFile::~PgTblPlnrCFile() {
};

void PgTblPlnrCFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrCFile_getNewRef", "SELECT nextval('TblPlnrCFile')", 0, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

ubigint PgTblPlnrCFile::getNewRef() {
	ubigint ref = 0;

	PGresult* res;
	char* ptr;

	const char* vals[] = {};
	const int l[] = {};
	const int f[] = {};

	res = PQexecPrepared(dbs, "TblPlnrCFile_getNewRef", 0, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrCFile_getNewRef)\n");

	ptr = PQgetvalue(res, 0, 0); ref = atoll(ptr);

	PQclear(res);

	return ref;
};
// IP pgTbl --- END

