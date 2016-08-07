/**
  * \file PlnrJMProjectState.cpp
  * database access for table TblPlnrJMProjectState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMProjectState.h"

/******************************************************************************
 class PlnrJMProjectState
 ******************************************************************************/

PlnrJMProjectState::PlnrJMProjectState(
			const ubigint ref
			, const ubigint refPlnrMProject
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refPlnrMProject = refPlnrMProject;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool PlnrJMProjectState::operator==(
			const PlnrJMProjectState& comp
		) {
	return false;
};

bool PlnrJMProjectState::operator!=(
			const PlnrJMProjectState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMProjectState
 ******************************************************************************/

ListPlnrJMProjectState::ListPlnrJMProjectState() {
};

ListPlnrJMProjectState::ListPlnrJMProjectState(
			const ListPlnrJMProjectState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMProjectState(*(src.nodes[i]));
};

ListPlnrJMProjectState::~ListPlnrJMProjectState() {
	clear();
};

void ListPlnrJMProjectState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMProjectState::size() const {
	return(nodes.size());
};

void ListPlnrJMProjectState::append(
			PlnrJMProjectState* rec
		) {
	nodes.push_back(rec);
};

PlnrJMProjectState* ListPlnrJMProjectState::operator[](
			const uint ix
		) {
	PlnrJMProjectState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMProjectState& ListPlnrJMProjectState::operator=(
			const ListPlnrJMProjectState& src
		) {
	PlnrJMProjectState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMProjectState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMProjectState::operator==(
			const ListPlnrJMProjectState& comp
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

bool ListPlnrJMProjectState::operator!=(
			const ListPlnrJMProjectState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMProjectState
 ******************************************************************************/

TblPlnrJMProjectState::TblPlnrJMProjectState() {
};

TblPlnrJMProjectState::~TblPlnrJMProjectState() {
};

bool TblPlnrJMProjectState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMProjectState** rec
		) {
	return false;
};

ubigint TblPlnrJMProjectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	return 0;
};

void TblPlnrJMProjectState::insertRec(
			PlnrJMProjectState* rec
		) {
};

ubigint TblPlnrJMProjectState::insertNewRec(
			PlnrJMProjectState** rec
			, const ubigint refPlnrMProject
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	PlnrJMProjectState* _rec = NULL;

	_rec = new PlnrJMProjectState(0, refPlnrMProject, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMProjectState::appendNewRecToRst(
			ListPlnrJMProjectState& rst
			, PlnrJMProjectState** rec
			, const ubigint refPlnrMProject
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	PlnrJMProjectState* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMProject, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMProjectState::insertRst(
			ListPlnrJMProjectState& rst
			, bool transact
		) {
};

void TblPlnrJMProjectState::updateRec(
			PlnrJMProjectState* rec
		) {
};

void TblPlnrJMProjectState::updateRst(
			ListPlnrJMProjectState& rst
			, bool transact
		) {
};

void TblPlnrJMProjectState::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMProjectState::loadRecByRef(
			ubigint ref
			, PlnrJMProjectState** rec
		) {
	return false;
};

bool TblPlnrJMProjectState::loadRecByPrjSta(
			ubigint refPlnrMProject
			, uint x1Start
			, PlnrJMProjectState** rec
		) {
	return false;
};

ubigint TblPlnrJMProjectState::loadRstByPrj(
			ubigint refPlnrMProject
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	return 0;
};

ubigint TblPlnrJMProjectState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	ubigint numload = 0;
	PlnrJMProjectState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMProjectState
 ******************************************************************************/

MyTblPlnrJMProjectState::MyTblPlnrJMProjectState() : TblPlnrJMProjectState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMProjectState::~MyTblPlnrJMProjectState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMProjectState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMProjectState (refPlnrMProject, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMProjectState SET refPlnrMProject = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMProjectState WHERE ref = ?", false);
};

bool MyTblPlnrJMProjectState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMProjectState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMProjectState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMProjectState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMProjectState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMProject = atoll((char*) dbrow[1]); else _rec->refPlnrMProject = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMProjectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMProjectState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMProjectState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMProjectState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMProject = atoll((char*) dbrow[1]); else rec->refPlnrMProject = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMProjectState::insertRec(
			PlnrJMProjectState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMProject,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMProjectState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMProjectState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMProjectState::insertRst(
			ListPlnrJMProjectState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMProjectState::updateRec(
			PlnrJMProjectState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMProject,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMProjectState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMProjectState / stmtUpdateRec)\n");
};

void MyTblPlnrJMProjectState::updateRst(
			ListPlnrJMProjectState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMProjectState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMProjectState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMProjectState / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMProjectState::loadRecByRef(
			ubigint ref
			, PlnrJMProjectState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMProjectState WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMProjectState::loadRecByPrjSta(
			ubigint refPlnrMProject
			, uint x1Start
			, PlnrJMProjectState** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMProject, x1Start, ixVState FROM TblPlnrJMProjectState WHERE refPlnrMProject = " + to_string(refPlnrMProject) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblPlnrJMProjectState::loadRstByPrj(
			ubigint refPlnrMProject
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMProject, x1Start, ixVState FROM TblPlnrJMProjectState WHERE refPlnrMProject = " + to_string(refPlnrMProject) + " ORDER BY x1Start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMProjectState
 ******************************************************************************/

PgTblPlnrJMProjectState::PgTblPlnrJMProjectState() : TblPlnrJMProjectState(), PgTable() {
};

PgTblPlnrJMProjectState::~PgTblPlnrJMProjectState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMProjectState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMProjectState_insertRec", "INSERT INTO TblPlnrJMProjectState (refPlnrMProject, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMProjectState_updateRec", "UPDATE TblPlnrJMProjectState SET refPlnrMProject = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMProjectState_removeRecByRef", "DELETE FROM TblPlnrJMProjectState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMProjectState_loadRecByRef", "SELECT ref, refPlnrMProject, x1Start, ixVState FROM TblPlnrJMProjectState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMProjectState_loadRecByPrjSta", "SELECT ref, refPlnrMProject, x1Start, ixVState FROM TblPlnrJMProjectState WHERE refPlnrMProject = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMProjectState_loadRstByPrj", "SELECT ref, refPlnrMProject, x1Start, ixVState FROM TblPlnrJMProjectState WHERE refPlnrMProject = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMProjectState::loadRec(
			PGresult* res
			, PlnrJMProjectState** rec
		) {
	char* ptr;

	PlnrJMProjectState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMProjectState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMProjectState::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMProjectState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new PlnrJMProjectState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMProjectState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMProjectState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMProjectState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMProjectState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMProjectState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMProjectState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMProjectState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMProjectState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMProjectState::insertRec(
			PlnrJMProjectState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refPlnrMProject,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMProjectState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMProjectState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMProjectState::insertRst(
			ListPlnrJMProjectState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMProjectState::updateRec(
			PlnrJMProjectState* rec
		) {
	PGresult* res;

	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMProject,
		(char*) &_x1Start,
		(char*) &_ixVState,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMProjectState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMProjectState_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMProjectState::updateRst(
			ListPlnrJMProjectState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMProjectState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMProjectState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMProjectState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMProjectState::loadRecByRef(
			ubigint ref
			, PlnrJMProjectState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMProjectState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMProjectState::loadRecByPrjSta(
			ubigint refPlnrMProject
			, uint x1Start
			, PlnrJMProjectState** rec
		) {
	ubigint _refPlnrMProject = htonl64(refPlnrMProject);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refPlnrMProject,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMProjectState_loadRecByPrjSta", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMProjectState::loadRstByPrj(
			ubigint refPlnrMProject
			, const bool append
			, ListPlnrJMProjectState& rst
		) {
	ubigint _refPlnrMProject = htonl64(refPlnrMProject);

	const char* vals[] = {
		(char*) &_refPlnrMProject
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMProjectState_loadRstByPrj", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

