/**
  * \file PlnrJMTapeoutState.cpp
  * database access for table TblPlnrJMTapeoutState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMTapeoutState.h"

/******************************************************************************
 class PlnrJMTapeoutState
 ******************************************************************************/

PlnrJMTapeoutState::PlnrJMTapeoutState(
			const ubigint ref
			, const ubigint refPlnrMTapeout
			, const uint x1Start
			, const uint ixVState
		) {

	this->ref = ref;
	this->refPlnrMTapeout = refPlnrMTapeout;
	this->x1Start = x1Start;
	this->ixVState = ixVState;
};

bool PlnrJMTapeoutState::operator==(
			const PlnrJMTapeoutState& comp
		) {
	return false;
};

bool PlnrJMTapeoutState::operator!=(
			const PlnrJMTapeoutState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMTapeoutState
 ******************************************************************************/

ListPlnrJMTapeoutState::ListPlnrJMTapeoutState() {
};

ListPlnrJMTapeoutState::ListPlnrJMTapeoutState(
			const ListPlnrJMTapeoutState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMTapeoutState(*(src.nodes[i]));
};

ListPlnrJMTapeoutState::~ListPlnrJMTapeoutState() {
	clear();
};

void ListPlnrJMTapeoutState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMTapeoutState::size() const {
	return(nodes.size());
};

void ListPlnrJMTapeoutState::append(
			PlnrJMTapeoutState* rec
		) {
	nodes.push_back(rec);
};

PlnrJMTapeoutState* ListPlnrJMTapeoutState::operator[](
			const uint ix
		) {
	PlnrJMTapeoutState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMTapeoutState& ListPlnrJMTapeoutState::operator=(
			const ListPlnrJMTapeoutState& src
		) {
	PlnrJMTapeoutState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMTapeoutState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMTapeoutState::operator==(
			const ListPlnrJMTapeoutState& comp
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

bool ListPlnrJMTapeoutState::operator!=(
			const ListPlnrJMTapeoutState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMTapeoutState
 ******************************************************************************/

TblPlnrJMTapeoutState::TblPlnrJMTapeoutState() {
};

TblPlnrJMTapeoutState::~TblPlnrJMTapeoutState() {
};

bool TblPlnrJMTapeoutState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMTapeoutState** rec
		) {
	return false;
};

ubigint TblPlnrJMTapeoutState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	return 0;
};

void TblPlnrJMTapeoutState::insertRec(
			PlnrJMTapeoutState* rec
		) {
};

ubigint TblPlnrJMTapeoutState::insertNewRec(
			PlnrJMTapeoutState** rec
			, const ubigint refPlnrMTapeout
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	PlnrJMTapeoutState* _rec = NULL;

	_rec = new PlnrJMTapeoutState(0, refPlnrMTapeout, x1Start, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMTapeoutState::appendNewRecToRst(
			ListPlnrJMTapeoutState& rst
			, PlnrJMTapeoutState** rec
			, const ubigint refPlnrMTapeout
			, const uint x1Start
			, const uint ixVState
		) {
	ubigint retval = 0;
	PlnrJMTapeoutState* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMTapeout, x1Start, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMTapeoutState::insertRst(
			ListPlnrJMTapeoutState& rst
			, bool transact
		) {
};

void TblPlnrJMTapeoutState::updateRec(
			PlnrJMTapeoutState* rec
		) {
};

void TblPlnrJMTapeoutState::updateRst(
			ListPlnrJMTapeoutState& rst
			, bool transact
		) {
};

void TblPlnrJMTapeoutState::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMTapeoutState::loadRecByRef(
			ubigint ref
			, PlnrJMTapeoutState** rec
		) {
	return false;
};

bool TblPlnrJMTapeoutState::loadRecByTpoSta(
			ubigint refPlnrMTapeout
			, uint x1Start
			, PlnrJMTapeoutState** rec
		) {
	return false;
};

ubigint TblPlnrJMTapeoutState::loadRstByTpo(
			ubigint refPlnrMTapeout
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	return 0;
};

ubigint TblPlnrJMTapeoutState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	ubigint numload = 0;
	PlnrJMTapeoutState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMTapeoutState
 ******************************************************************************/

MyTblPlnrJMTapeoutState::MyTblPlnrJMTapeoutState() : TblPlnrJMTapeoutState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMTapeoutState::~MyTblPlnrJMTapeoutState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMTapeoutState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMTapeoutState (refPlnrMTapeout, x1Start, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMTapeoutState SET refPlnrMTapeout = ?, x1Start = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMTapeoutState WHERE ref = ?", false);
};

bool MyTblPlnrJMTapeoutState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMTapeoutState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMTapeoutState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMTapeoutState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMTapeoutState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMTapeout = atoll((char*) dbrow[1]); else _rec->refPlnrMTapeout = 0;
		if (dbrow[2]) _rec->x1Start = atol((char*) dbrow[2]); else _rec->x1Start = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMTapeoutState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMTapeoutState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMTapeoutState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMTapeoutState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMTapeout = atoll((char*) dbrow[1]); else rec->refPlnrMTapeout = 0;
			if (dbrow[2]) rec->x1Start = atol((char*) dbrow[2]); else rec->x1Start = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMTapeoutState::insertRec(
			PlnrJMTapeoutState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMTapeout,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMTapeoutState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMTapeoutState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMTapeoutState::insertRst(
			ListPlnrJMTapeoutState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMTapeoutState::updateRec(
			PlnrJMTapeoutState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMTapeout,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMTapeoutState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMTapeoutState / stmtUpdateRec)\n");
};

void MyTblPlnrJMTapeoutState::updateRst(
			ListPlnrJMTapeoutState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMTapeoutState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMTapeoutState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMTapeoutState / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMTapeoutState::loadRecByRef(
			ubigint ref
			, PlnrJMTapeoutState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMTapeoutState WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMTapeoutState::loadRecByTpoSta(
			ubigint refPlnrMTapeout
			, uint x1Start
			, PlnrJMTapeoutState** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMTapeout, x1Start, ixVState FROM TblPlnrJMTapeoutState WHERE refPlnrMTapeout = " + to_string(refPlnrMTapeout) + " AND x1Start <= " + to_string(x1Start) + " ORDER BY x1Start DESC LIMIT 0,1", rec);
};

ubigint MyTblPlnrJMTapeoutState::loadRstByTpo(
			ubigint refPlnrMTapeout
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMTapeout, x1Start, ixVState FROM TblPlnrJMTapeoutState WHERE refPlnrMTapeout = " + to_string(refPlnrMTapeout) + " ORDER BY x1Start ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMTapeoutState
 ******************************************************************************/

PgTblPlnrJMTapeoutState::PgTblPlnrJMTapeoutState() : TblPlnrJMTapeoutState(), PgTable() {
};

PgTblPlnrJMTapeoutState::~PgTblPlnrJMTapeoutState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMTapeoutState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMTapeoutState_insertRec", "INSERT INTO TblPlnrJMTapeoutState (refPlnrMTapeout, x1Start, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMTapeoutState_updateRec", "UPDATE TblPlnrJMTapeoutState SET refPlnrMTapeout = $1, x1Start = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMTapeoutState_removeRecByRef", "DELETE FROM TblPlnrJMTapeoutState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMTapeoutState_loadRecByRef", "SELECT ref, refPlnrMTapeout, x1Start, ixVState FROM TblPlnrJMTapeoutState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMTapeoutState_loadRecByTpoSta", "SELECT ref, refPlnrMTapeout, x1Start, ixVState FROM TblPlnrJMTapeoutState WHERE refPlnrMTapeout = $1 AND x1Start <= $2 ORDER BY x1Start DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMTapeoutState_loadRstByTpo", "SELECT ref, refPlnrMTapeout, x1Start, ixVState FROM TblPlnrJMTapeoutState WHERE refPlnrMTapeout = $1 ORDER BY x1Start ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMTapeoutState::loadRec(
			PGresult* res
			, PlnrJMTapeoutState** rec
		) {
	char* ptr;

	PlnrJMTapeoutState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMTapeoutState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmtapeout"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMTapeout = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMTapeoutState::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMTapeoutState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmtapeout"),
			PQfnumber(res, "x1start"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new PlnrJMTapeoutState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMTapeout = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMTapeoutState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMTapeoutState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMTapeoutState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMTapeoutState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMTapeoutState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMTapeoutState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMTapeoutState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMTapeoutState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMTapeoutState::insertRec(
			PlnrJMTapeoutState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refPlnrMTapeout,
		(char*) &_x1Start,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMTapeoutState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMTapeoutState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMTapeoutState::insertRst(
			ListPlnrJMTapeoutState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMTapeoutState::updateRec(
			PlnrJMTapeoutState* rec
		) {
	PGresult* res;

	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	uint _x1Start = htonl(rec->x1Start);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMTapeout,
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

	res = PQexecPrepared(dbs, "TblPlnrJMTapeoutState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMTapeoutState_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMTapeoutState::updateRst(
			ListPlnrJMTapeoutState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMTapeoutState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMTapeoutState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMTapeoutState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMTapeoutState::loadRecByRef(
			ubigint ref
			, PlnrJMTapeoutState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMTapeoutState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMTapeoutState::loadRecByTpoSta(
			ubigint refPlnrMTapeout
			, uint x1Start
			, PlnrJMTapeoutState** rec
		) {
	ubigint _refPlnrMTapeout = htonl64(refPlnrMTapeout);
	uint _x1Start = htonl(x1Start);

	const char* vals[] = {
		(char*) &_refPlnrMTapeout,
		(char*) &_x1Start
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMTapeoutState_loadRecByTpoSta", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMTapeoutState::loadRstByTpo(
			ubigint refPlnrMTapeout
			, const bool append
			, ListPlnrJMTapeoutState& rst
		) {
	ubigint _refPlnrMTapeout = htonl64(refPlnrMTapeout);

	const char* vals[] = {
		(char*) &_refPlnrMTapeout
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMTapeoutState_loadRstByTpo", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

