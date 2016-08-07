/**
  * \file PlnrRMLevelMLevel.cpp
  * database access for table TblPlnrRMLevelMLevel (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMLevelMLevel.h"

/******************************************************************************
 class PlnrRMLevelMLevel
 ******************************************************************************/

PlnrRMLevelMLevel::PlnrRMLevelMLevel(
			const ubigint ref
			, const ubigint stkRefPlnrMLevel
			, const ubigint dsnRefPlnrMLevel
		) {

	this->ref = ref;
	this->stkRefPlnrMLevel = stkRefPlnrMLevel;
	this->dsnRefPlnrMLevel = dsnRefPlnrMLevel;
};

bool PlnrRMLevelMLevel::operator==(
			const PlnrRMLevelMLevel& comp
		) {
	return false;
};

bool PlnrRMLevelMLevel::operator!=(
			const PlnrRMLevelMLevel& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMLevelMLevel
 ******************************************************************************/

ListPlnrRMLevelMLevel::ListPlnrRMLevelMLevel() {
};

ListPlnrRMLevelMLevel::ListPlnrRMLevelMLevel(
			const ListPlnrRMLevelMLevel& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMLevelMLevel(*(src.nodes[i]));
};

ListPlnrRMLevelMLevel::~ListPlnrRMLevelMLevel() {
	clear();
};

void ListPlnrRMLevelMLevel::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMLevelMLevel::size() const {
	return(nodes.size());
};

void ListPlnrRMLevelMLevel::append(
			PlnrRMLevelMLevel* rec
		) {
	nodes.push_back(rec);
};

PlnrRMLevelMLevel* ListPlnrRMLevelMLevel::operator[](
			const uint ix
		) {
	PlnrRMLevelMLevel* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMLevelMLevel& ListPlnrRMLevelMLevel::operator=(
			const ListPlnrRMLevelMLevel& src
		) {
	PlnrRMLevelMLevel* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMLevelMLevel(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMLevelMLevel::operator==(
			const ListPlnrRMLevelMLevel& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListPlnrRMLevelMLevel::operator!=(
			const ListPlnrRMLevelMLevel& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMLevelMLevel
 ******************************************************************************/

TblPlnrRMLevelMLevel::TblPlnrRMLevelMLevel() {
};

TblPlnrRMLevelMLevel::~TblPlnrRMLevelMLevel() {
};

bool TblPlnrRMLevelMLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLevelMLevel** rec
		) {
	return false;
};

ubigint TblPlnrRMLevelMLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLevelMLevel& rst
		) {
	return 0;
};

void TblPlnrRMLevelMLevel::insertRec(
			PlnrRMLevelMLevel* rec
		) {
};

ubigint TblPlnrRMLevelMLevel::insertNewRec(
			PlnrRMLevelMLevel** rec
			, const ubigint stkRefPlnrMLevel
			, const ubigint dsnRefPlnrMLevel
		) {
	ubigint retval = 0;
	PlnrRMLevelMLevel* _rec = NULL;

	_rec = new PlnrRMLevelMLevel(0, stkRefPlnrMLevel, dsnRefPlnrMLevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMLevelMLevel::appendNewRecToRst(
			ListPlnrRMLevelMLevel& rst
			, PlnrRMLevelMLevel** rec
			, const ubigint stkRefPlnrMLevel
			, const ubigint dsnRefPlnrMLevel
		) {
	ubigint retval = 0;
	PlnrRMLevelMLevel* _rec = NULL;

	retval = insertNewRec(&_rec, stkRefPlnrMLevel, dsnRefPlnrMLevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMLevelMLevel::insertRst(
			ListPlnrRMLevelMLevel& rst
			, bool transact
		) {
};

void TblPlnrRMLevelMLevel::updateRec(
			PlnrRMLevelMLevel* rec
		) {
};

void TblPlnrRMLevelMLevel::updateRst(
			ListPlnrRMLevelMLevel& rst
			, bool transact
		) {
};

void TblPlnrRMLevelMLevel::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMLevelMLevel::loadRecByRef(
			ubigint ref
			, PlnrRMLevelMLevel** rec
		) {
	return false;
};

ubigint TblPlnrRMLevelMLevel::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMLevelMLevel& rst
		) {
	ubigint numload = 0;
	PlnrRMLevelMLevel* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMLevelMLevel
 ******************************************************************************/

MyTblPlnrRMLevelMLevel::MyTblPlnrRMLevelMLevel() : TblPlnrRMLevelMLevel(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMLevelMLevel::~MyTblPlnrRMLevelMLevel() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMLevelMLevel::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMLevelMLevel (stkRefPlnrMLevel, dsnRefPlnrMLevel) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMLevelMLevel SET stkRefPlnrMLevel = ?, dsnRefPlnrMLevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMLevelMLevel WHERE ref = ?", false);
};

bool MyTblPlnrRMLevelMLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLevelMLevel** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMLevelMLevel* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMLevelMLevel / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMLevelMLevel();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->stkRefPlnrMLevel = atoll((char*) dbrow[1]); else _rec->stkRefPlnrMLevel = 0;
		if (dbrow[2]) _rec->dsnRefPlnrMLevel = atoll((char*) dbrow[2]); else _rec->dsnRefPlnrMLevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMLevelMLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLevelMLevel& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMLevelMLevel* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMLevelMLevel / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMLevelMLevel();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->stkRefPlnrMLevel = atoll((char*) dbrow[1]); else rec->stkRefPlnrMLevel = 0;
			if (dbrow[2]) rec->dsnRefPlnrMLevel = atoll((char*) dbrow[2]); else rec->dsnRefPlnrMLevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMLevelMLevel::insertRec(
			PlnrRMLevelMLevel* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->stkRefPlnrMLevel,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->dsnRefPlnrMLevel,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLevelMLevel / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLevelMLevel / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMLevelMLevel::insertRst(
			ListPlnrRMLevelMLevel& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMLevelMLevel::updateRec(
			PlnrRMLevelMLevel* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->stkRefPlnrMLevel,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->dsnRefPlnrMLevel,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLevelMLevel / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLevelMLevel / stmtUpdateRec)\n");
};

void MyTblPlnrRMLevelMLevel::updateRst(
			ListPlnrRMLevelMLevel& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMLevelMLevel::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLevelMLevel / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLevelMLevel / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMLevelMLevel::loadRecByRef(
			ubigint ref
			, PlnrRMLevelMLevel** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMLevelMLevel WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMLevelMLevel
 ******************************************************************************/

PgTblPlnrRMLevelMLevel::PgTblPlnrRMLevelMLevel() : TblPlnrRMLevelMLevel(), PgTable() {
};

PgTblPlnrRMLevelMLevel::~PgTblPlnrRMLevelMLevel() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMLevelMLevel::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMLevelMLevel_insertRec", "INSERT INTO TblPlnrRMLevelMLevel (stkRefPlnrMLevel, dsnRefPlnrMLevel) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMLevelMLevel_updateRec", "UPDATE TblPlnrRMLevelMLevel SET stkRefPlnrMLevel = $1, dsnRefPlnrMLevel = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMLevelMLevel_removeRecByRef", "DELETE FROM TblPlnrRMLevelMLevel WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMLevelMLevel_loadRecByRef", "SELECT ref, stkRefPlnrMLevel, dsnRefPlnrMLevel FROM TblPlnrRMLevelMLevel WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrRMLevelMLevel::loadRec(
			PGresult* res
			, PlnrRMLevelMLevel** rec
		) {
	char* ptr;

	PlnrRMLevelMLevel* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMLevelMLevel();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "stkrefplnrmlevel"),
			PQfnumber(res, "dsnrefplnrmlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->stkRefPlnrMLevel = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnRefPlnrMLevel = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMLevelMLevel::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMLevelMLevel& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMLevelMLevel* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "stkrefplnrmlevel"),
			PQfnumber(res, "dsnrefplnrmlevel")
		};

		while (numread < numrow) {
			rec = new PlnrRMLevelMLevel();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->stkRefPlnrMLevel = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnRefPlnrMLevel = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMLevelMLevel::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMLevelMLevel** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLevelMLevel / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMLevelMLevel::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLevelMLevel** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMLevelMLevel::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLevelMLevel& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMLevelMLevel::insertRec(
			PlnrRMLevelMLevel* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _stkRefPlnrMLevel = htonl64(rec->stkRefPlnrMLevel);
	ubigint _dsnRefPlnrMLevel = htonl64(rec->dsnRefPlnrMLevel);

	const char* vals[] = {
		(char*) &_stkRefPlnrMLevel,
		(char*) &_dsnRefPlnrMLevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMLevelMLevel_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLevelMLevel_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMLevelMLevel::insertRst(
			ListPlnrRMLevelMLevel& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMLevelMLevel::updateRec(
			PlnrRMLevelMLevel* rec
		) {
	PGresult* res;

	ubigint _stkRefPlnrMLevel = htonl64(rec->stkRefPlnrMLevel);
	ubigint _dsnRefPlnrMLevel = htonl64(rec->dsnRefPlnrMLevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_stkRefPlnrMLevel,
		(char*) &_dsnRefPlnrMLevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMLevelMLevel_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLevelMLevel_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMLevelMLevel::updateRst(
			ListPlnrRMLevelMLevel& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMLevelMLevel::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrRMLevelMLevel_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLevelMLevel_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMLevelMLevel::loadRecByRef(
			ubigint ref
			, PlnrRMLevelMLevel** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMLevelMLevel_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

