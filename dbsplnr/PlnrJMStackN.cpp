/**
  * \file PlnrJMStackN.cpp
  * database access for table TblPlnrJMStackN (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMStackN.h"

/******************************************************************************
 class PlnrJMStackN
 ******************************************************************************/

PlnrJMStackN::PlnrJMStackN(
			const ubigint ref
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const string N
		) {

	this->ref = ref;
	this->refPlnrMStack = refPlnrMStack;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->N = N;
};

bool PlnrJMStackN::operator==(
			const PlnrJMStackN& comp
		) {
	return false;
};

bool PlnrJMStackN::operator!=(
			const PlnrJMStackN& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMStackN
 ******************************************************************************/

ListPlnrJMStackN::ListPlnrJMStackN() {
};

ListPlnrJMStackN::ListPlnrJMStackN(
			const ListPlnrJMStackN& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMStackN(*(src.nodes[i]));
};

ListPlnrJMStackN::~ListPlnrJMStackN() {
	clear();
};

void ListPlnrJMStackN::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMStackN::size() const {
	return(nodes.size());
};

void ListPlnrJMStackN::append(
			PlnrJMStackN* rec
		) {
	nodes.push_back(rec);
};

PlnrJMStackN* ListPlnrJMStackN::operator[](
			const uint ix
		) {
	PlnrJMStackN* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMStackN& ListPlnrJMStackN::operator=(
			const ListPlnrJMStackN& src
		) {
	PlnrJMStackN* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMStackN(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMStackN::operator==(
			const ListPlnrJMStackN& comp
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

bool ListPlnrJMStackN::operator!=(
			const ListPlnrJMStackN& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMStackN
 ******************************************************************************/

TblPlnrJMStackN::TblPlnrJMStackN() {
};

TblPlnrJMStackN::~TblPlnrJMStackN() {
};

bool TblPlnrJMStackN::loadRecBySQL(
			const string& sqlstr
			, PlnrJMStackN** rec
		) {
	return false;
};

ubigint TblPlnrJMStackN::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	return 0;
};

void TblPlnrJMStackN::insertRec(
			PlnrJMStackN* rec
		) {
};

ubigint TblPlnrJMStackN::insertNewRec(
			PlnrJMStackN** rec
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const string N
		) {
	ubigint retval = 0;
	PlnrJMStackN* _rec = NULL;

	_rec = new PlnrJMStackN(0, refPlnrMStack, x1RefPlnrMDesign, N);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMStackN::appendNewRecToRst(
			ListPlnrJMStackN& rst
			, PlnrJMStackN** rec
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const string N
		) {
	ubigint retval = 0;
	PlnrJMStackN* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMStack, x1RefPlnrMDesign, N);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMStackN::insertRst(
			ListPlnrJMStackN& rst
			, bool transact
		) {
};

void TblPlnrJMStackN::updateRec(
			PlnrJMStackN* rec
		) {
};

void TblPlnrJMStackN::updateRst(
			ListPlnrJMStackN& rst
			, bool transact
		) {
};

void TblPlnrJMStackN::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMStackN::loadRecByRef(
			ubigint ref
			, PlnrJMStackN** rec
		) {
	return false;
};

bool TblPlnrJMStackN::loadRecByStkDsn(
			ubigint refPlnrMStack
			, ubigint x1RefPlnrMDesign
			, PlnrJMStackN** rec
		) {
	return false;
};

ubigint TblPlnrJMStackN::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	return 0;
};

ubigint TblPlnrJMStackN::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	ubigint numload = 0;
	PlnrJMStackN* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMStackN
 ******************************************************************************/

MyTblPlnrJMStackN::MyTblPlnrJMStackN() : TblPlnrJMStackN(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMStackN::~MyTblPlnrJMStackN() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMStackN::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMStackN (refPlnrMStack, x1RefPlnrMDesign, N) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMStackN SET refPlnrMStack = ?, x1RefPlnrMDesign = ?, N = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMStackN WHERE ref = ?", false);
};

bool MyTblPlnrJMStackN::loadRecBySQL(
			const string& sqlstr
			, PlnrJMStackN** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMStackN* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMStackN / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMStackN();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMStack = atoll((char*) dbrow[1]); else _rec->refPlnrMStack = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->N.assign(dbrow[3], dblengths[3]); else _rec->N = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMStackN::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMStackN* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMStackN / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMStackN();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMStack = atoll((char*) dbrow[1]); else rec->refPlnrMStack = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->N.assign(dbrow[3], dblengths[3]); else rec->N = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMStackN::insertRec(
			PlnrJMStackN* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->N.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStack,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->N.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMStackN / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMStackN / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMStackN::insertRst(
			ListPlnrJMStackN& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMStackN::updateRec(
			PlnrJMStackN* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->N.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStack,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->N.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMStackN / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMStackN / stmtUpdateRec)\n");
};

void MyTblPlnrJMStackN::updateRst(
			ListPlnrJMStackN& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMStackN::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMStackN / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMStackN / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMStackN::loadRecByRef(
			ubigint ref
			, PlnrJMStackN** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMStackN WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMStackN::loadRecByStkDsn(
			ubigint refPlnrMStack
			, ubigint x1RefPlnrMDesign
			, PlnrJMStackN** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMStack, x1RefPlnrMDesign, N FROM TblPlnrJMStackN WHERE refPlnrMStack = " + to_string(refPlnrMStack) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMStackN::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMStack, x1RefPlnrMDesign, N FROM TblPlnrJMStackN WHERE refPlnrMStack = " + to_string(refPlnrMStack) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMStackN
 ******************************************************************************/

PgTblPlnrJMStackN::PgTblPlnrJMStackN() : TblPlnrJMStackN(), PgTable() {
};

PgTblPlnrJMStackN::~PgTblPlnrJMStackN() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMStackN::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMStackN_insertRec", "INSERT INTO TblPlnrJMStackN (refPlnrMStack, x1RefPlnrMDesign, N) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMStackN_updateRec", "UPDATE TblPlnrJMStackN SET refPlnrMStack = $1, x1RefPlnrMDesign = $2, N = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMStackN_removeRecByRef", "DELETE FROM TblPlnrJMStackN WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMStackN_loadRecByRef", "SELECT ref, refPlnrMStack, x1RefPlnrMDesign, N FROM TblPlnrJMStackN WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMStackN_loadRecByStkDsn", "SELECT ref, refPlnrMStack, x1RefPlnrMDesign, N FROM TblPlnrJMStackN WHERE refPlnrMStack = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMStackN_loadRstByStk", "SELECT ref, refPlnrMStack, x1RefPlnrMDesign, N FROM TblPlnrJMStackN WHERE refPlnrMStack = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMStackN::loadRec(
			PGresult* res
			, PlnrJMStackN** rec
		) {
	char* ptr;

	PlnrJMStackN* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMStackN();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstack"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "n")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMStack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->N.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMStackN::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMStackN* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstack"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "n")
		};

		while (numread < numrow) {
			rec = new PlnrJMStackN();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMStack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->N.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMStackN::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMStackN** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackN / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMStackN::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackN / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMStackN::loadRecBySQL(
			const string& sqlstr
			, PlnrJMStackN** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMStackN::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMStackN::insertRec(
			PlnrJMStackN* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMStack = htonl64(rec->refPlnrMStack);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_x1RefPlnrMDesign,
		rec->N.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMStackN_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackN_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMStackN::insertRst(
			ListPlnrJMStackN& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMStackN::updateRec(
			PlnrJMStackN* rec
		) {
	PGresult* res;

	ubigint _refPlnrMStack = htonl64(rec->refPlnrMStack);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_x1RefPlnrMDesign,
		rec->N.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMStackN_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackN_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMStackN::updateRst(
			ListPlnrJMStackN& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMStackN::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMStackN_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackN_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMStackN::loadRecByRef(
			ubigint ref
			, PlnrJMStackN** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMStackN_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMStackN::loadRecByStkDsn(
			ubigint refPlnrMStack
			, ubigint x1RefPlnrMDesign
			, PlnrJMStackN** rec
		) {
	ubigint _refPlnrMStack = htonl64(refPlnrMStack);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMStackN_loadRecByStkDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMStackN::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrJMStackN& rst
		) {
	ubigint _refPlnrMStack = htonl64(refPlnrMStack);

	const char* vals[] = {
		(char*) &_refPlnrMStack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMStackN_loadRstByStk", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

