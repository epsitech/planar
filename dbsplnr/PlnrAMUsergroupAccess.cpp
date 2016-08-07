/**
  * \file PlnrAMUsergroupAccess.cpp
  * database access for table TblPlnrAMUsergroupAccess (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMUsergroupAccess.h"

/******************************************************************************
 class PlnrAMUsergroupAccess
 ******************************************************************************/

PlnrAMUsergroupAccess::PlnrAMUsergroupAccess(
			const ubigint ref
			, const ubigint refPlnrMUsergroup
			, const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) {

	this->ref = ref;
	this->refPlnrMUsergroup = refPlnrMUsergroup;
	this->x1IxPlnrVCard = x1IxPlnrVCard;
	this->ixPlnrWUiaccess = ixPlnrWUiaccess;
};

bool PlnrAMUsergroupAccess::operator==(
			const PlnrAMUsergroupAccess& comp
		) {
	return false;
};

bool PlnrAMUsergroupAccess::operator!=(
			const PlnrAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMUsergroupAccess
 ******************************************************************************/

ListPlnrAMUsergroupAccess::ListPlnrAMUsergroupAccess() {
};

ListPlnrAMUsergroupAccess::ListPlnrAMUsergroupAccess(
			const ListPlnrAMUsergroupAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMUsergroupAccess(*(src.nodes[i]));
};

ListPlnrAMUsergroupAccess::~ListPlnrAMUsergroupAccess() {
	clear();
};

void ListPlnrAMUsergroupAccess::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMUsergroupAccess::size() const {
	return(nodes.size());
};

void ListPlnrAMUsergroupAccess::append(
			PlnrAMUsergroupAccess* rec
		) {
	nodes.push_back(rec);
};

PlnrAMUsergroupAccess* ListPlnrAMUsergroupAccess::operator[](
			const uint ix
		) {
	PlnrAMUsergroupAccess* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMUsergroupAccess& ListPlnrAMUsergroupAccess::operator=(
			const ListPlnrAMUsergroupAccess& src
		) {
	PlnrAMUsergroupAccess* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMUsergroupAccess(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMUsergroupAccess::operator==(
			const ListPlnrAMUsergroupAccess& comp
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

bool ListPlnrAMUsergroupAccess::operator!=(
			const ListPlnrAMUsergroupAccess& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMUsergroupAccess
 ******************************************************************************/

TblPlnrAMUsergroupAccess::TblPlnrAMUsergroupAccess() {
};

TblPlnrAMUsergroupAccess::~TblPlnrAMUsergroupAccess() {
};

bool TblPlnrAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblPlnrAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMUsergroupAccess& rst
		) {
	return 0;
};

void TblPlnrAMUsergroupAccess::insertRec(
			PlnrAMUsergroupAccess* rec
		) {
};

ubigint TblPlnrAMUsergroupAccess::insertNewRec(
			PlnrAMUsergroupAccess** rec
			, const ubigint refPlnrMUsergroup
			, const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) {
	ubigint retval = 0;
	PlnrAMUsergroupAccess* _rec = NULL;

	_rec = new PlnrAMUsergroupAccess(0, refPlnrMUsergroup, x1IxPlnrVCard, ixPlnrWUiaccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMUsergroupAccess::appendNewRecToRst(
			ListPlnrAMUsergroupAccess& rst
			, PlnrAMUsergroupAccess** rec
			, const ubigint refPlnrMUsergroup
			, const uint x1IxPlnrVCard
			, const uint ixPlnrWUiaccess
		) {
	ubigint retval = 0;
	PlnrAMUsergroupAccess* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUsergroup, x1IxPlnrVCard, ixPlnrWUiaccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMUsergroupAccess::insertRst(
			ListPlnrAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblPlnrAMUsergroupAccess::updateRec(
			PlnrAMUsergroupAccess* rec
		) {
};

void TblPlnrAMUsergroupAccess::updateRst(
			ListPlnrAMUsergroupAccess& rst
			, bool transact
		) {
};

void TblPlnrAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, PlnrAMUsergroupAccess** rec
		) {
	return false;
};

ubigint TblPlnrAMUsergroupAccess::loadRefsByUsg(
			ubigint refPlnrMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrAMUsergroupAccess::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMUsergroupAccess& rst
		) {
	ubigint numload = 0;
	PlnrAMUsergroupAccess* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMUsergroupAccess
 ******************************************************************************/

MyTblPlnrAMUsergroupAccess::MyTblPlnrAMUsergroupAccess() : TblPlnrAMUsergroupAccess(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMUsergroupAccess::~MyTblPlnrAMUsergroupAccess() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMUsergroupAccess::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMUsergroupAccess (refPlnrMUsergroup, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMUsergroupAccess SET refPlnrMUsergroup = ?, x1IxPlnrVCard = ?, ixPlnrWUiaccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMUsergroupAccess WHERE ref = ?", false);
};

bool MyTblPlnrAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrAMUsergroupAccess** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMUsergroupAccess* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMUsergroupAccess / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMUsergroupAccess();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUsergroup = atoll((char*) dbrow[1]); else _rec->refPlnrMUsergroup = 0;
		if (dbrow[2]) _rec->x1IxPlnrVCard = atol((char*) dbrow[2]); else _rec->x1IxPlnrVCard = 0;
		if (dbrow[3]) _rec->ixPlnrWUiaccess = atol((char*) dbrow[3]); else _rec->ixPlnrWUiaccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMUsergroupAccess& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMUsergroupAccess* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMUsergroupAccess / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMUsergroupAccess();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUsergroup = atoll((char*) dbrow[1]); else rec->refPlnrMUsergroup = 0;
			if (dbrow[2]) rec->x1IxPlnrVCard = atol((char*) dbrow[2]); else rec->x1IxPlnrVCard = 0;
			if (dbrow[3]) rec->ixPlnrWUiaccess = atol((char*) dbrow[3]); else rec->ixPlnrWUiaccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMUsergroupAccess::insertRec(
			PlnrAMUsergroupAccess* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxPlnrVCard,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrWUiaccess,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMUsergroupAccess / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMUsergroupAccess / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMUsergroupAccess::insertRst(
			ListPlnrAMUsergroupAccess& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMUsergroupAccess::updateRec(
			PlnrAMUsergroupAccess* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUsergroup,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1IxPlnrVCard,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrWUiaccess,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMUsergroupAccess / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMUsergroupAccess / stmtUpdateRec)\n");
};

void MyTblPlnrAMUsergroupAccess::updateRst(
			ListPlnrAMUsergroupAccess& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMUsergroupAccess::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMUsergroupAccess / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMUsergroupAccess / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, PlnrAMUsergroupAccess** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMUsergroupAccess WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrAMUsergroupAccess::loadRefsByUsg(
			ubigint refPlnrMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrAMUsergroupAccess WHERE refPlnrMUsergroup = " + to_string(refPlnrMUsergroup) + "", append, refs);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMUsergroupAccess
 ******************************************************************************/

PgTblPlnrAMUsergroupAccess::PgTblPlnrAMUsergroupAccess() : TblPlnrAMUsergroupAccess(), PgTable() {
};

PgTblPlnrAMUsergroupAccess::~PgTblPlnrAMUsergroupAccess() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMUsergroupAccess::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMUsergroupAccess_insertRec", "INSERT INTO TblPlnrAMUsergroupAccess (refPlnrMUsergroup, x1IxPlnrVCard, ixPlnrWUiaccess) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMUsergroupAccess_updateRec", "UPDATE TblPlnrAMUsergroupAccess SET refPlnrMUsergroup = $1, x1IxPlnrVCard = $2, ixPlnrWUiaccess = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMUsergroupAccess_removeRecByRef", "DELETE FROM TblPlnrAMUsergroupAccess WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMUsergroupAccess_loadRecByRef", "SELECT ref, refPlnrMUsergroup, x1IxPlnrVCard, ixPlnrWUiaccess FROM TblPlnrAMUsergroupAccess WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAMUsergroupAccess_loadRefsByUsg", "SELECT ref FROM TblPlnrAMUsergroupAccess WHERE refPlnrMUsergroup = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAMUsergroupAccess::loadRec(
			PGresult* res
			, PlnrAMUsergroupAccess** rec
		) {
	char* ptr;

	PlnrAMUsergroupAccess* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMUsergroupAccess();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "x1ixplnrvcard"),
			PQfnumber(res, "ixplnrwuiaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxPlnrVCard = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrWUiaccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMUsergroupAccess::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMUsergroupAccess& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMUsergroupAccess* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "x1ixplnrvcard"),
			PQfnumber(res, "ixplnrwuiaccess")
		};

		while (numread < numrow) {
			rec = new PlnrAMUsergroupAccess();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxPlnrVCard = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixPlnrWUiaccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMUsergroupAccess::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUsergroupAccess / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAMUsergroupAccess::loadRecBySQL(
			const string& sqlstr
			, PlnrAMUsergroupAccess** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMUsergroupAccess::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMUsergroupAccess& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMUsergroupAccess::insertRec(
			PlnrAMUsergroupAccess* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _x1IxPlnrVCard = htonl(rec->x1IxPlnrVCard);
	uint _ixPlnrWUiaccess = htonl(rec->ixPlnrWUiaccess);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup,
		(char*) &_x1IxPlnrVCard,
		(char*) &_ixPlnrWUiaccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMUsergroupAccess_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUsergroupAccess_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMUsergroupAccess::insertRst(
			ListPlnrAMUsergroupAccess& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMUsergroupAccess::updateRec(
			PlnrAMUsergroupAccess* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _x1IxPlnrVCard = htonl(rec->x1IxPlnrVCard);
	uint _ixPlnrWUiaccess = htonl(rec->ixPlnrWUiaccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup,
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

	res = PQexecPrepared(dbs, "TblPlnrAMUsergroupAccess_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUsergroupAccess_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMUsergroupAccess::updateRst(
			ListPlnrAMUsergroupAccess& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMUsergroupAccess::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMUsergroupAccess_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMUsergroupAccess_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMUsergroupAccess::loadRecByRef(
			ubigint ref
			, PlnrAMUsergroupAccess** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMUsergroupAccess_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrAMUsergroupAccess::loadRefsByUsg(
			ubigint refPlnrMUsergroup
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrMUsergroup = htonl64(refPlnrMUsergroup);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrAMUsergroupAccess_loadRefsByUsg", 1, vals, l, f, append, refs);
};

// IP pgTbl --- END

