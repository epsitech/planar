/**
  * \file PlnrJMUserState.cpp
  * database access for table TblPlnrJMUserState (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMUserState.h"

/******************************************************************************
 class PlnrJMUserState
 ******************************************************************************/

PlnrJMUserState::PlnrJMUserState(
			const ubigint ref
			, const ubigint refPlnrMUser
			, const uint x1Startd
			, const uint ixVState
		) {

	this->ref = ref;
	this->refPlnrMUser = refPlnrMUser;
	this->x1Startd = x1Startd;
	this->ixVState = ixVState;
};

bool PlnrJMUserState::operator==(
			const PlnrJMUserState& comp
		) {
	return false;
};

bool PlnrJMUserState::operator!=(
			const PlnrJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMUserState
 ******************************************************************************/

ListPlnrJMUserState::ListPlnrJMUserState() {
};

ListPlnrJMUserState::ListPlnrJMUserState(
			const ListPlnrJMUserState& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMUserState(*(src.nodes[i]));
};

ListPlnrJMUserState::~ListPlnrJMUserState() {
	clear();
};

void ListPlnrJMUserState::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMUserState::size() const {
	return(nodes.size());
};

void ListPlnrJMUserState::append(
			PlnrJMUserState* rec
		) {
	nodes.push_back(rec);
};

PlnrJMUserState* ListPlnrJMUserState::operator[](
			const uint ix
		) {
	PlnrJMUserState* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMUserState& ListPlnrJMUserState::operator=(
			const ListPlnrJMUserState& src
		) {
	PlnrJMUserState* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMUserState(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMUserState::operator==(
			const ListPlnrJMUserState& comp
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

bool ListPlnrJMUserState::operator!=(
			const ListPlnrJMUserState& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMUserState
 ******************************************************************************/

TblPlnrJMUserState::TblPlnrJMUserState() {
};

TblPlnrJMUserState::~TblPlnrJMUserState() {
};

bool TblPlnrJMUserState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMUserState** rec
		) {
	return false;
};

ubigint TblPlnrJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	return 0;
};

void TblPlnrJMUserState::insertRec(
			PlnrJMUserState* rec
		) {
};

ubigint TblPlnrJMUserState::insertNewRec(
			PlnrJMUserState** rec
			, const ubigint refPlnrMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	PlnrJMUserState* _rec = NULL;

	_rec = new PlnrJMUserState(0, refPlnrMUser, x1Startd, ixVState);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMUserState::appendNewRecToRst(
			ListPlnrJMUserState& rst
			, PlnrJMUserState** rec
			, const ubigint refPlnrMUser
			, const uint x1Startd
			, const uint ixVState
		) {
	ubigint retval = 0;
	PlnrJMUserState* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUser, x1Startd, ixVState);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMUserState::insertRst(
			ListPlnrJMUserState& rst
			, bool transact
		) {
};

void TblPlnrJMUserState::updateRec(
			PlnrJMUserState* rec
		) {
};

void TblPlnrJMUserState::updateRst(
			ListPlnrJMUserState& rst
			, bool transact
		) {
};

void TblPlnrJMUserState::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMUserState::loadRecByRef(
			ubigint ref
			, PlnrJMUserState** rec
		) {
	return false;
};

bool TblPlnrJMUserState::loadRecByUsrSta(
			ubigint refPlnrMUser
			, uint x1Startd
			, PlnrJMUserState** rec
		) {
	return false;
};

ubigint TblPlnrJMUserState::loadRefsByUsr(
			ubigint refPlnrMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrJMUserState::loadRstByUsr(
			ubigint refPlnrMUser
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	return 0;
};

ubigint TblPlnrJMUserState::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	ubigint numload = 0;
	PlnrJMUserState* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMUserState
 ******************************************************************************/

MyTblPlnrJMUserState::MyTblPlnrJMUserState() : TblPlnrJMUserState(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMUserState::~MyTblPlnrJMUserState() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMUserState::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMUserState (refPlnrMUser, x1Startd, ixVState) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMUserState SET refPlnrMUser = ?, x1Startd = ?, ixVState = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMUserState WHERE ref = ?", false);
};

bool MyTblPlnrJMUserState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMUserState** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMUserState* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMUserState / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMUserState();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUser = atoll((char*) dbrow[1]); else _rec->refPlnrMUser = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->ixVState = atol((char*) dbrow[3]); else _rec->ixVState = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMUserState* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMUserState / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMUserState();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUser = atoll((char*) dbrow[1]); else rec->refPlnrMUser = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->ixVState = atol((char*) dbrow[3]); else rec->ixVState = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMUserState::insertRec(
			PlnrJMUserState* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMUserState / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMUserState / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMUserState::insertRst(
			ListPlnrJMUserState& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMUserState::updateRec(
			PlnrJMUserState* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVState,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMUserState / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMUserState / stmtUpdateRec)\n");
};

void MyTblPlnrJMUserState::updateRst(
			ListPlnrJMUserState& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMUserState::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMUserState / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMUserState / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMUserState::loadRecByRef(
			ubigint ref
			, PlnrJMUserState** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMUserState WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMUserState::loadRecByUsrSta(
			ubigint refPlnrMUser
			, uint x1Startd
			, PlnrJMUserState** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMUser, x1Startd, ixVState FROM TblPlnrJMUserState WHERE refPlnrMUser = " + to_string(refPlnrMUser) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblPlnrJMUserState::loadRefsByUsr(
			ubigint refPlnrMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrJMUserState WHERE refPlnrMUser = " + to_string(refPlnrMUser) + "", append, refs);
};

ubigint MyTblPlnrJMUserState::loadRstByUsr(
			ubigint refPlnrMUser
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMUser, x1Startd, ixVState FROM TblPlnrJMUserState WHERE refPlnrMUser = " + to_string(refPlnrMUser) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMUserState
 ******************************************************************************/

PgTblPlnrJMUserState::PgTblPlnrJMUserState() : TblPlnrJMUserState(), PgTable() {
};

PgTblPlnrJMUserState::~PgTblPlnrJMUserState() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMUserState::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMUserState_insertRec", "INSERT INTO TblPlnrJMUserState (refPlnrMUser, x1Startd, ixVState) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMUserState_updateRec", "UPDATE TblPlnrJMUserState SET refPlnrMUser = $1, x1Startd = $2, ixVState = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMUserState_removeRecByRef", "DELETE FROM TblPlnrJMUserState WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMUserState_loadRecByRef", "SELECT ref, refPlnrMUser, x1Startd, ixVState FROM TblPlnrJMUserState WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMUserState_loadRecByUsrSta", "SELECT ref, refPlnrMUser, x1Startd, ixVState FROM TblPlnrJMUserState WHERE refPlnrMUser = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMUserState_loadRefsByUsr", "SELECT ref FROM TblPlnrJMUserState WHERE refPlnrMUser = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMUserState_loadRstByUsr", "SELECT ref, refPlnrMUser, x1Startd, ixVState FROM TblPlnrJMUserState WHERE refPlnrMUser = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMUserState::loadRec(
			PGresult* res
			, PlnrJMUserState** rec
		) {
	char* ptr;

	PlnrJMUserState* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMUserState();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVState = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMUserState::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMUserState* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "ixvstate")
		};

		while (numread < numrow) {
			rec = new PlnrJMUserState();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVState = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMUserState::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMUserState** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMUserState / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMUserState::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMUserState / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMUserState::loadRecBySQL(
			const string& sqlstr
			, PlnrJMUserState** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMUserState::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMUserState::insertRec(
			PlnrJMUserState* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_x1Startd,
		(char*) &_ixVState
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMUserState_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMUserState_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMUserState::insertRst(
			ListPlnrJMUserState& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMUserState::updateRec(
			PlnrJMUserState* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _x1Startd = htonl(rec->x1Startd);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_x1Startd,
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

	res = PQexecPrepared(dbs, "TblPlnrJMUserState_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMUserState_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMUserState::updateRst(
			ListPlnrJMUserState& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMUserState::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMUserState_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMUserState_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMUserState::loadRecByRef(
			ubigint ref
			, PlnrJMUserState** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMUserState_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMUserState::loadRecByUsrSta(
			ubigint refPlnrMUser
			, uint x1Startd
			, PlnrJMUserState** rec
		) {
	ubigint _refPlnrMUser = htonl64(refPlnrMUser);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMUserState_loadRecByUsrSta", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMUserState::loadRefsByUsr(
			ubigint refPlnrMUser
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrMUser = htonl64(refPlnrMUser);

	const char* vals[] = {
		(char*) &_refPlnrMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrJMUserState_loadRefsByUsr", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrJMUserState::loadRstByUsr(
			ubigint refPlnrMUser
			, const bool append
			, ListPlnrJMUserState& rst
		) {
	ubigint _refPlnrMUser = htonl64(refPlnrMUser);

	const char* vals[] = {
		(char*) &_refPlnrMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMUserState_loadRstByUsr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

