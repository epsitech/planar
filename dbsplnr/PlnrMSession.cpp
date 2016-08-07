/**
  * \file PlnrMSession.cpp
  * database access for table TblPlnrMSession (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMSession.h"

/******************************************************************************
 class PlnrMSession
 ******************************************************************************/

PlnrMSession::PlnrMSession(
			const ubigint ref
			, const ubigint refPlnrMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {

	this->ref = ref;
	this->refPlnrMUser = refPlnrMUser;
	this->start = start;
	this->stop = stop;
	this->Ip = Ip;
};

bool PlnrMSession::operator==(
			const PlnrMSession& comp
		) {
	return false;
};

bool PlnrMSession::operator!=(
			const PlnrMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMSession
 ******************************************************************************/

ListPlnrMSession::ListPlnrMSession() {
};

ListPlnrMSession::ListPlnrMSession(
			const ListPlnrMSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMSession(*(src.nodes[i]));
};

ListPlnrMSession::~ListPlnrMSession() {
	clear();
};

void ListPlnrMSession::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMSession::size() const {
	return(nodes.size());
};

void ListPlnrMSession::append(
			PlnrMSession* rec
		) {
	nodes.push_back(rec);
};

PlnrMSession* ListPlnrMSession::operator[](
			const uint ix
		) {
	PlnrMSession* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMSession& ListPlnrMSession::operator=(
			const ListPlnrMSession& src
		) {
	PlnrMSession* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMSession(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMSession::operator==(
			const ListPlnrMSession& comp
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

bool ListPlnrMSession::operator!=(
			const ListPlnrMSession& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMSession
 ******************************************************************************/

TblPlnrMSession::TblPlnrMSession() {
};

TblPlnrMSession::~TblPlnrMSession() {
};

bool TblPlnrMSession::loadRecBySQL(
			const string& sqlstr
			, PlnrMSession** rec
		) {
	return false;
};

ubigint TblPlnrMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMSession& rst
		) {
	return 0;
};

void TblPlnrMSession::insertRec(
			PlnrMSession* rec
		) {
};

ubigint TblPlnrMSession::insertNewRec(
			PlnrMSession** rec
			, const ubigint refPlnrMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	PlnrMSession* _rec = NULL;

	_rec = new PlnrMSession(0, refPlnrMUser, start, stop, Ip);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMSession::appendNewRecToRst(
			ListPlnrMSession& rst
			, PlnrMSession** rec
			, const ubigint refPlnrMUser
			, const uint start
			, const uint stop
			, const string Ip
		) {
	ubigint retval = 0;
	PlnrMSession* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUser, start, stop, Ip);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMSession::insertRst(
			ListPlnrMSession& rst
			, bool transact
		) {
};

void TblPlnrMSession::updateRec(
			PlnrMSession* rec
		) {
};

void TblPlnrMSession::updateRst(
			ListPlnrMSession& rst
			, bool transact
		) {
};

void TblPlnrMSession::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMSession::loadRecByRef(
			ubigint ref
			, PlnrMSession** rec
		) {
	return false;
};

ubigint TblPlnrMSession::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMSession& rst
		) {
	ubigint numload = 0;
	PlnrMSession* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMSession
 ******************************************************************************/

MyTblPlnrMSession::MyTblPlnrMSession() : TblPlnrMSession(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMSession::~MyTblPlnrMSession() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMSession::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMSession (refPlnrMUser, start, stop, Ip) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMSession SET refPlnrMUser = ?, start = ?, stop = ?, Ip = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMSession WHERE ref = ?", false);
};

bool MyTblPlnrMSession::loadRecBySQL(
			const string& sqlstr
			, PlnrMSession** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMSession* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMSession / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMSession();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUser = atoll((char*) dbrow[1]); else _rec->refPlnrMUser = 0;
		if (dbrow[2]) _rec->start = atol((char*) dbrow[2]); else _rec->start = 0;
		if (dbrow[3]) _rec->stop = atol((char*) dbrow[3]); else _rec->stop = 0;
		if (dbrow[4]) _rec->Ip.assign(dbrow[4], dblengths[4]); else _rec->Ip = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMSession& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMSession* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMSession / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMSession();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUser = atoll((char*) dbrow[1]); else rec->refPlnrMUser = 0;
			if (dbrow[2]) rec->start = atol((char*) dbrow[2]); else rec->start = 0;
			if (dbrow[3]) rec->stop = atol((char*) dbrow[3]); else rec->stop = 0;
			if (dbrow[4]) rec->Ip.assign(dbrow[4], dblengths[4]); else rec->Ip = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMSession::insertRec(
			PlnrMSession* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMSession / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMSession / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMSession::insertRst(
			ListPlnrMSession& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMSession::updateRec(
			PlnrMSession* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Ip.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->start,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->stop,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Ip.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMSession / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMSession / stmtUpdateRec)\n");
};

void MyTblPlnrMSession::updateRst(
			ListPlnrMSession& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMSession::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMSession / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMSession / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMSession::loadRecByRef(
			ubigint ref
			, PlnrMSession** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMSession WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMSession
 ******************************************************************************/

PgTblPlnrMSession::PgTblPlnrMSession() : TblPlnrMSession(), PgTable() {
};

PgTblPlnrMSession::~PgTblPlnrMSession() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMSession::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMSession_insertRec", "INSERT INTO TblPlnrMSession (refPlnrMUser, start, stop, Ip) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMSession_updateRec", "UPDATE TblPlnrMSession SET refPlnrMUser = $1, start = $2, stop = $3, Ip = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMSession_removeRecByRef", "DELETE FROM TblPlnrMSession WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMSession_loadRecByRef", "SELECT ref, refPlnrMUser, start, stop, Ip FROM TblPlnrMSession WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrMSession::loadRec(
			PGresult* res
			, PlnrMSession** rec
		) {
	char* ptr;

	PlnrMSession* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMSession();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->start = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->stop = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Ip.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMSession::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMSession& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMSession* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "start"),
			PQfnumber(res, "stop"),
			PQfnumber(res, "ip")
		};

		while (numread < numrow) {
			rec = new PlnrMSession();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->start = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->stop = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Ip.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMSession::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMSession** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMSession / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMSession::loadRecBySQL(
			const string& sqlstr
			, PlnrMSession** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMSession::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMSession& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMSession::insertRec(
			PlnrMSession* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMSession_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMSession_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMSession::insertRst(
			ListPlnrMSession& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMSession::updateRec(
			PlnrMSession* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _start = htonl(rec->start);
	uint _stop = htonl(rec->stop);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_start,
		(char*) &_stop,
		rec->Ip.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMSession_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMSession_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMSession::updateRst(
			ListPlnrMSession& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMSession::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMSession_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMSession_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMSession::loadRecByRef(
			ubigint ref
			, PlnrMSession** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMSession_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

