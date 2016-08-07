/**
  * \file PlnrAMUserAccess.cpp
  * database access for table TblPlnrAMUserAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMUserAccess.h"

/******************************************************************************
 class PlnrAMUserAccess
 ******************************************************************************/

PlnrAMUserAccess::PlnrAMUserAccess(
			const ubigint ref
			, const ubigint refPlnrMUser
			, const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) {

	this->ref = ref;
	this->refPlnrMUser = refPlnrMUser;
	this->x1IxPlnrVCard = x1IxPlnrVCard;
	this->ixPlnrWUiaccess = ixPlnrWUiaccess;
};

bool PlnrAMUserAccess::operator==(
			const PlnrAMUserAccess& comp
		) {
	return false;
};

bool PlnrAMUserAccess::operator!=(
			const PlnrAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMUserAccess
 ******************************************************************************/

ListPlnrAMUserAccess::ListPlnrAMUserAccess() {
};

ListPlnrAMUserAccess::ListPlnrAMUserAccess(
			const ListPlnrAMUserAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMUserAccess(*(src.nodes[i]));
};

ListPlnrAMUserAccess::~ListPlnrAMUserAccess() {
	clear();
};

void ListPlnrAMUserAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMUserAccess::size() const {
	return(nodes.size());
};

void ListPlnrAMUserAccess::append(
			PlnrAMUserAccess* rec
		) {
	nodes.push_back(rec);
};

PlnrAMUserAccess* ListPlnrAMUserAccess::operator[](
			const uint ix
		) {
	PlnrAMUserAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMUserAccess& ListPlnrAMUserAccess::operator=(
			const ListPlnrAMUserAccess& src
		) {
	PlnrAMUserAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMUserAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMUserAccess::operator==(
			const ListPlnrAMUserAccess& comp
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

bool ListPlnrAMUserAccess::operator!=(
			const ListPlnrAMUserAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMUserAccess
 ******************************************************************************/

TblPlnrAMUserAccess::TblPlnrAMUserAccess() {
};

TblPlnrAMUserAccess::~TblPlnrAMUserAccess() {
};

bool TblPlnrAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrAMUserAccess** rec
		) {
	return false;
};

ubigint TblPlnrAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMUserAccess& rst
		) {
	return 0;
};

void TblPlnrAMUserAccess::insertRec(
			PlnrAMUserAccess* rec
		) {
};

ubigint TblPlnrAMUserAccess::insertNewRec(
			PlnrAMUserAccess** rec
			, const ubigint refPlnrMUser
			, const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) {
	ubigint retval = 0;
	PlnrAMUserAccess* _rec = NULL;

	_rec = new PlnrAMUserAccess(0, refPlnrMUser, x1IxPlnrVCard, ixPlnrWUiaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMUserAccess::appendNewRecToRst(
			ListPlnrAMUserAccess& rst
			, PlnrAMUserAccess** rec
			, const ubigint refPlnrMUser
			, const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) {
	ubigint retval = 0;
	PlnrAMUserAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUser, x1IxPlnrVCard, ixPlnrWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMUserAccess::insertRst(
			ListPlnrAMUserAccess& rst
			, bool transact
		) {
};

void TblPlnrAMUserAccess::updateRec(
			PlnrAMUserAccess* rec
		) {
};

void TblPlnrAMUserAccess::updateRst(
			ListPlnrAMUserAccess& rst
			, bool transact
		) {
};

void TblPlnrAMUserAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMUserAccess::loadRecByRef(
			ubigint ref
			, PlnrAMUserAccess** rec
		) {
	return false;
};

ubigint TblPlnrAMUserAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMUserAccess& rst
		) {
	ubigint numload = 0;
	PlnrAMUserAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMUserAccess
 ******************************************************************************/

MyTblPlnrAMUserAccess::MyTblPlnrAMUserAccess() : TblPlnrAMUserAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMUserAccess::~MyTblPlnrAMUserAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMUserAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMUserAccess (refPlnrMUser, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMUserAccess SET refPlnrMUser = ?, x1IxPlnrVCard = ?, ixPlnrWUiaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMUserAccess WHERE ref = ?", false);
};

bool MyTblPlnrAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrAMUserAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMUserAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMUserAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMUserAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUser = atoll((char*) dbrow[1]); else _rec->refPlnrMUser = 0;
		if (dbrow[2]) _rec->x1IxPlnrVCard = atol((char*) dbrow[2]); else _rec->x1IxPlnrVCard = 0;
		if (dbrow[3]) _rec->ixPlnrWUiaccess = atol((char*) dbrow[3]); else _rec->ixPlnrWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMUserAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMUserAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMUserAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMUserAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUser = atoll((char*) dbrow[1]); else rec->refPlnrMUser = 0;
			if (dbrow[2]) rec->x1IxPlnrVCard = atol((char*) dbrow[2]); else rec->x1IxPlnrVCard = 0;
			if (dbrow[3]) rec->ixPlnrWUiaccess = atol((char*) dbrow[3]); else rec->ixPlnrWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMUserAccess::insertRec(
			PlnrAMUserAccess* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxPlnrVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrWUiaccess,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMUserAccess / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMUserAccess / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMUserAccess::insertRst(
			ListPlnrAMUserAccess& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMUserAccess::updateRec(
			PlnrAMUserAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1IxPlnrVCard,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrWUiaccess,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMUserAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMUserAccess / stmtUpdateRec)\n");
};

void MyTblPlnrAMUserAccess::updateRst(
			ListPlnrAMUserAccess& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMUserAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMUserAccess / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMUserAccess / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMUserAccess::loadRecByRef(
			ubigint ref
			, PlnrAMUserAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMUserAccess WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMUserAccess
 ******************************************************************************/

PgTblPlnrAMUserAccess::PgTblPlnrAMUserAccess() : TblPlnrAMUserAccess(), PgTable() {
};

PgTblPlnrAMUserAccess::~PgTblPlnrAMUserAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMUserAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMUserAccess_insertRec", "INSERT INTO TblPlnrAMUserAccess (refPlnrMUser, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMUserAccess_updateRec", "UPDATE TblPlnrAMUserAccess SET refPlnrMUser = $1, x1IxPlnrVCard = $2, ixPlnrWUiaccess = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMUserAccess_removeRecByRef", "DELETE FROM TblPlnrAMUserAccess WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMUserAccess_loadRecByRef", "SELECT ref, refPlnrMUser, x1IxPlnrVCard, ixPlnrWUiaccess FROM TblPlnrAMUserAccess WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrAMUserAccess::loadRec(
			PGresult* res
			, PlnrAMUserAccess** rec
		) {
	char* ptr;

	PlnrAMUserAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMUserAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "x1ixplnrvcard"),
			PQfnumber(res, "ixplnrwuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxPlnrVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMUserAccess::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMUserAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMUserAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "x1ixplnrvcard"),
			PQfnumber(res, "ixplnrwuiaccess")
		};

		while (numread < numrow) {
			rec = new PlnrAMUserAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxPlnrVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixPlnrWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMUserAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUserAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAMUserAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrAMUserAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMUserAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMUserAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMUserAccess::insertRec(
			PlnrAMUserAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _x1IxPlnrVCard = htonl(rec->x1IxPlnrVCard);
	uint _ixPlnrWUiaccess = htonl(rec->ixPlnrWUiaccess);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_x1IxPlnrVCard,
		(char*) &_ixPlnrWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMUserAccess_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUserAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMUserAccess::insertRst(
			ListPlnrAMUserAccess& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMUserAccess::updateRec(
			PlnrAMUserAccess* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _x1IxPlnrVCard = htonl(rec->x1IxPlnrVCard);
	uint _ixPlnrWUiaccess = htonl(rec->ixPlnrWUiaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_x1IxPlnrVCard,
		(char*) &_ixPlnrWUiaccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMUserAccess_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUserAccess_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMUserAccess::updateRst(
			ListPlnrAMUserAccess& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMUserAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMUserAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUserAccess_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMUserAccess::loadRecByRef(
			ubigint ref
			, PlnrAMUserAccess** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMUserAccess_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

