/**
  * \file PlnrRMLayerMStructure.cpp
  * database access for table TblPlnrRMLayerMStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMLayerMStructure.h"

/******************************************************************************
 class PlnrRMLayerMStructure
 ******************************************************************************/

PlnrRMLayerMStructure::PlnrRMLayerMStructure(
			const ubigint ref
			, const ubigint refPlnrMLayer
			, const ubigint refPlnrMStructure
		) {

	this->ref = ref;
	this->refPlnrMLayer = refPlnrMLayer;
	this->refPlnrMStructure = refPlnrMStructure;
};

bool PlnrRMLayerMStructure::operator==(
			const PlnrRMLayerMStructure& comp
		) {
	return false;
};

bool PlnrRMLayerMStructure::operator!=(
			const PlnrRMLayerMStructure& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMLayerMStructure
 ******************************************************************************/

ListPlnrRMLayerMStructure::ListPlnrRMLayerMStructure() {
};

ListPlnrRMLayerMStructure::ListPlnrRMLayerMStructure(
			const ListPlnrRMLayerMStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMLayerMStructure(*(src.nodes[i]));
};

ListPlnrRMLayerMStructure::~ListPlnrRMLayerMStructure() {
	clear();
};

void ListPlnrRMLayerMStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMLayerMStructure::size() const {
	return(nodes.size());
};

void ListPlnrRMLayerMStructure::append(
			PlnrRMLayerMStructure* rec
		) {
	nodes.push_back(rec);
};

PlnrRMLayerMStructure* ListPlnrRMLayerMStructure::operator[](
			const uint ix
		) {
	PlnrRMLayerMStructure* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMLayerMStructure& ListPlnrRMLayerMStructure::operator=(
			const ListPlnrRMLayerMStructure& src
		) {
	PlnrRMLayerMStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMLayerMStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMLayerMStructure::operator==(
			const ListPlnrRMLayerMStructure& comp
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

bool ListPlnrRMLayerMStructure::operator!=(
			const ListPlnrRMLayerMStructure& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMLayerMStructure
 ******************************************************************************/

TblPlnrRMLayerMStructure::TblPlnrRMLayerMStructure() {
};

TblPlnrRMLayerMStructure::~TblPlnrRMLayerMStructure() {
};

bool TblPlnrRMLayerMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLayerMStructure** rec
		) {
	return false;
};

ubigint TblPlnrRMLayerMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	return 0;
};

void TblPlnrRMLayerMStructure::insertRec(
			PlnrRMLayerMStructure* rec
		) {
};

ubigint TblPlnrRMLayerMStructure::insertNewRec(
			PlnrRMLayerMStructure** rec
			, const ubigint refPlnrMLayer
			, const ubigint refPlnrMStructure
		) {
	ubigint retval = 0;
	PlnrRMLayerMStructure* _rec = NULL;

	_rec = new PlnrRMLayerMStructure(0, refPlnrMLayer, refPlnrMStructure);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMLayerMStructure::appendNewRecToRst(
			ListPlnrRMLayerMStructure& rst
			, PlnrRMLayerMStructure** rec
			, const ubigint refPlnrMLayer
			, const ubigint refPlnrMStructure
		) {
	ubigint retval = 0;
	PlnrRMLayerMStructure* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMLayer, refPlnrMStructure);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMLayerMStructure::insertRst(
			ListPlnrRMLayerMStructure& rst
			, bool transact
		) {
};

void TblPlnrRMLayerMStructure::updateRec(
			PlnrRMLayerMStructure* rec
		) {
};

void TblPlnrRMLayerMStructure::updateRst(
			ListPlnrRMLayerMStructure& rst
			, bool transact
		) {
};

void TblPlnrRMLayerMStructure::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMLayerMStructure::loadRecByRef(
			ubigint ref
			, PlnrRMLayerMStructure** rec
		) {
	return false;
};

ubigint TblPlnrRMLayerMStructure::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	return 0;
};

ubigint TblPlnrRMLayerMStructure::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	ubigint numload = 0;
	PlnrRMLayerMStructure* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMLayerMStructure
 ******************************************************************************/

MyTblPlnrRMLayerMStructure::MyTblPlnrRMLayerMStructure() : TblPlnrRMLayerMStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMLayerMStructure::~MyTblPlnrRMLayerMStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMLayerMStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMLayerMStructure (refPlnrMLayer, refPlnrMStructure) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMLayerMStructure SET refPlnrMLayer = ?, refPlnrMStructure = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMLayerMStructure WHERE ref = ?", false);
};

bool MyTblPlnrRMLayerMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLayerMStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMLayerMStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMLayerMStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMLayerMStructure();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMLayer = atoll((char*) dbrow[1]); else _rec->refPlnrMLayer = 0;
		if (dbrow[2]) _rec->refPlnrMStructure = atoll((char*) dbrow[2]); else _rec->refPlnrMStructure = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMLayerMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMLayerMStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMLayerMStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMLayerMStructure();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMLayer = atoll((char*) dbrow[1]); else rec->refPlnrMLayer = 0;
			if (dbrow[2]) rec->refPlnrMStructure = atoll((char*) dbrow[2]); else rec->refPlnrMStructure = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMLayerMStructure::insertRec(
			PlnrRMLayerMStructure* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLayer,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMStructure,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLayerMStructure / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLayerMStructure / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMLayerMStructure::insertRst(
			ListPlnrRMLayerMStructure& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMLayerMStructure::updateRec(
			PlnrRMLayerMStructure* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLayer,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMStructure,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLayerMStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLayerMStructure / stmtUpdateRec)\n");
};

void MyTblPlnrRMLayerMStructure::updateRst(
			ListPlnrRMLayerMStructure& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMLayerMStructure::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLayerMStructure / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLayerMStructure / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMLayerMStructure::loadRecByRef(
			ubigint ref
			, PlnrRMLayerMStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMLayerMStructure WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrRMLayerMStructure::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMLayer, refPlnrMStructure FROM TblPlnrRMLayerMStructure WHERE refPlnrMLayer = " + to_string(refPlnrMLayer) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMLayerMStructure
 ******************************************************************************/

PgTblPlnrRMLayerMStructure::PgTblPlnrRMLayerMStructure() : TblPlnrRMLayerMStructure(), PgTable() {
};

PgTblPlnrRMLayerMStructure::~PgTblPlnrRMLayerMStructure() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMLayerMStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMLayerMStructure_insertRec", "INSERT INTO TblPlnrRMLayerMStructure (refPlnrMLayer, refPlnrMStructure) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMLayerMStructure_updateRec", "UPDATE TblPlnrRMLayerMStructure SET refPlnrMLayer = $1, refPlnrMStructure = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMLayerMStructure_removeRecByRef", "DELETE FROM TblPlnrRMLayerMStructure WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMLayerMStructure_loadRecByRef", "SELECT ref, refPlnrMLayer, refPlnrMStructure FROM TblPlnrRMLayerMStructure WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrRMLayerMStructure_loadRstByLyr", "SELECT ref, refPlnrMLayer, refPlnrMStructure FROM TblPlnrRMLayerMStructure WHERE refPlnrMLayer = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrRMLayerMStructure::loadRec(
			PGresult* res
			, PlnrRMLayerMStructure** rec
		) {
	char* ptr;

	PlnrRMLayerMStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMLayerMStructure();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "refplnrmstructure")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMLayer = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMStructure = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMLayerMStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMLayerMStructure* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "refplnrmstructure")
		};

		while (numread < numrow) {
			rec = new PlnrRMLayerMStructure();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMLayer = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMStructure = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMLayerMStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMLayerMStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLayerMStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrRMLayerMStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLayerMStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrRMLayerMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLayerMStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMLayerMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMLayerMStructure::insertRec(
			PlnrRMLayerMStructure* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_refPlnrMStructure
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMLayerMStructure_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLayerMStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMLayerMStructure::insertRst(
			ListPlnrRMLayerMStructure& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMLayerMStructure::updateRec(
			PlnrRMLayerMStructure* rec
		) {
	PGresult* res;

	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_refPlnrMStructure,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMLayerMStructure_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLayerMStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMLayerMStructure::updateRst(
			ListPlnrRMLayerMStructure& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMLayerMStructure::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMLayerMStructure_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLayerMStructure_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMLayerMStructure::loadRecByRef(
			ubigint ref
			, PlnrRMLayerMStructure** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMLayerMStructure_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrRMLayerMStructure::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrRMLayerMStructure& rst
		) {
	ubigint _refPlnrMLayer = htonl64(refPlnrMLayer);

	const char* vals[] = {
		(char*) &_refPlnrMLayer
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrRMLayerMStructure_loadRstByLyr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

