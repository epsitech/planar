/**
  * \file PlnrJMStackModtype.cpp
  * database access for table TblPlnrJMStackModtype (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMStackModtype.h"

/******************************************************************************
 class PlnrJMStackModtype
 ******************************************************************************/

PlnrJMStackModtype::PlnrJMStackModtype(
			const ubigint ref
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {

	this->ref = ref;
	this->refPlnrMStack = refPlnrMStack;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->ixVModtype = ixVModtype;
};

bool PlnrJMStackModtype::operator==(
			const PlnrJMStackModtype& comp
		) {
	return false;
};

bool PlnrJMStackModtype::operator!=(
			const PlnrJMStackModtype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMStackModtype
 ******************************************************************************/

ListPlnrJMStackModtype::ListPlnrJMStackModtype() {
};

ListPlnrJMStackModtype::ListPlnrJMStackModtype(
			const ListPlnrJMStackModtype& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMStackModtype(*(src.nodes[i]));
};

ListPlnrJMStackModtype::~ListPlnrJMStackModtype() {
	clear();
};

void ListPlnrJMStackModtype::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMStackModtype::size() const {
	return(nodes.size());
};

void ListPlnrJMStackModtype::append(
			PlnrJMStackModtype* rec
		) {
	nodes.push_back(rec);
};

PlnrJMStackModtype* ListPlnrJMStackModtype::operator[](
			const uint ix
		) {
	PlnrJMStackModtype* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMStackModtype& ListPlnrJMStackModtype::operator=(
			const ListPlnrJMStackModtype& src
		) {
	PlnrJMStackModtype* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMStackModtype(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMStackModtype::operator==(
			const ListPlnrJMStackModtype& comp
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

bool ListPlnrJMStackModtype::operator!=(
			const ListPlnrJMStackModtype& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMStackModtype
 ******************************************************************************/

TblPlnrJMStackModtype::TblPlnrJMStackModtype() {
};

TblPlnrJMStackModtype::~TblPlnrJMStackModtype() {
};

bool TblPlnrJMStackModtype::loadRecBySQL(
			const string& sqlstr
			, PlnrJMStackModtype** rec
		) {
	return false;
};

ubigint TblPlnrJMStackModtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	return 0;
};

void TblPlnrJMStackModtype::insertRec(
			PlnrJMStackModtype* rec
		) {
};

ubigint TblPlnrJMStackModtype::insertNewRec(
			PlnrJMStackModtype** rec
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {
	ubigint retval = 0;
	PlnrJMStackModtype* _rec = NULL;

	_rec = new PlnrJMStackModtype(0, refPlnrMStack, x1RefPlnrMDesign, ixVModtype);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMStackModtype::appendNewRecToRst(
			ListPlnrJMStackModtype& rst
			, PlnrJMStackModtype** rec
			, const ubigint refPlnrMStack
			, const ubigint x1RefPlnrMDesign
			, const uint ixVModtype
		) {
	ubigint retval = 0;
	PlnrJMStackModtype* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMStack, x1RefPlnrMDesign, ixVModtype);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMStackModtype::insertRst(
			ListPlnrJMStackModtype& rst
			, bool transact
		) {
};

void TblPlnrJMStackModtype::updateRec(
			PlnrJMStackModtype* rec
		) {
};

void TblPlnrJMStackModtype::updateRst(
			ListPlnrJMStackModtype& rst
			, bool transact
		) {
};

void TblPlnrJMStackModtype::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMStackModtype::loadRecByRef(
			ubigint ref
			, PlnrJMStackModtype** rec
		) {
	return false;
};

bool TblPlnrJMStackModtype::loadRecByStkDsn(
			ubigint refPlnrMStack
			, ubigint x1RefPlnrMDesign
			, PlnrJMStackModtype** rec
		) {
	return false;
};

ubigint TblPlnrJMStackModtype::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	return 0;
};

ubigint TblPlnrJMStackModtype::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	ubigint numload = 0;
	PlnrJMStackModtype* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMStackModtype
 ******************************************************************************/

MyTblPlnrJMStackModtype::MyTblPlnrJMStackModtype() : TblPlnrJMStackModtype(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMStackModtype::~MyTblPlnrJMStackModtype() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMStackModtype::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMStackModtype (refPlnrMStack, x1RefPlnrMDesign, ixVModtype) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMStackModtype SET refPlnrMStack = ?, x1RefPlnrMDesign = ?, ixVModtype = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMStackModtype WHERE ref = ?", false);
};

bool MyTblPlnrJMStackModtype::loadRecBySQL(
			const string& sqlstr
			, PlnrJMStackModtype** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMStackModtype* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMStackModtype / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMStackModtype();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMStack = atoll((char*) dbrow[1]); else _rec->refPlnrMStack = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->ixVModtype = atol((char*) dbrow[3]); else _rec->ixVModtype = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMStackModtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMStackModtype* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMStackModtype / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMStackModtype();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMStack = atoll((char*) dbrow[1]); else rec->refPlnrMStack = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->ixVModtype = atol((char*) dbrow[3]); else rec->ixVModtype = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMStackModtype::insertRec(
			PlnrJMStackModtype* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStack,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixVModtype,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMStackModtype / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMStackModtype / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMStackModtype::insertRst(
			ListPlnrJMStackModtype& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMStackModtype::updateRec(
			PlnrJMStackModtype* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStack,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixVModtype,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMStackModtype / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMStackModtype / stmtUpdateRec)\n");
};

void MyTblPlnrJMStackModtype::updateRst(
			ListPlnrJMStackModtype& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMStackModtype::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMStackModtype / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMStackModtype / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMStackModtype::loadRecByRef(
			ubigint ref
			, PlnrJMStackModtype** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMStackModtype WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMStackModtype::loadRecByStkDsn(
			ubigint refPlnrMStack
			, ubigint x1RefPlnrMDesign
			, PlnrJMStackModtype** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMStack, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMStackModtype WHERE refPlnrMStack = " + to_string(refPlnrMStack) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMStackModtype::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMStack, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMStackModtype WHERE refPlnrMStack = " + to_string(refPlnrMStack) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMStackModtype
 ******************************************************************************/

PgTblPlnrJMStackModtype::PgTblPlnrJMStackModtype() : TblPlnrJMStackModtype(), PgTable() {
};

PgTblPlnrJMStackModtype::~PgTblPlnrJMStackModtype() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMStackModtype::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMStackModtype_insertRec", "INSERT INTO TblPlnrJMStackModtype (refPlnrMStack, x1RefPlnrMDesign, ixVModtype) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMStackModtype_updateRec", "UPDATE TblPlnrJMStackModtype SET refPlnrMStack = $1, x1RefPlnrMDesign = $2, ixVModtype = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMStackModtype_removeRecByRef", "DELETE FROM TblPlnrJMStackModtype WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMStackModtype_loadRecByRef", "SELECT ref, refPlnrMStack, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMStackModtype WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMStackModtype_loadRecByStkDsn", "SELECT ref, refPlnrMStack, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMStackModtype WHERE refPlnrMStack = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMStackModtype_loadRstByStk", "SELECT ref, refPlnrMStack, x1RefPlnrMDesign, ixVModtype FROM TblPlnrJMStackModtype WHERE refPlnrMStack = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMStackModtype::loadRec(
			PGresult* res
			, PlnrJMStackModtype** rec
		) {
	char* ptr;

	PlnrJMStackModtype* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMStackModtype();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstack"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvmodtype")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMStack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixVModtype = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMStackModtype::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMStackModtype* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstack"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "ixvmodtype")
		};

		while (numread < numrow) {
			rec = new PlnrJMStackModtype();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMStack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixVModtype = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMStackModtype::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMStackModtype** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackModtype / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMStackModtype::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackModtype / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMStackModtype::loadRecBySQL(
			const string& sqlstr
			, PlnrJMStackModtype** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMStackModtype::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMStackModtype::insertRec(
			PlnrJMStackModtype* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMStack = htonl64(rec->refPlnrMStack);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVModtype = htonl(rec->ixVModtype);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVModtype
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMStackModtype_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackModtype_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMStackModtype::insertRst(
			ListPlnrJMStackModtype& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMStackModtype::updateRec(
			PlnrJMStackModtype* rec
		) {
	PGresult* res;

	ubigint _refPlnrMStack = htonl64(rec->refPlnrMStack);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	uint _ixVModtype = htonl(rec->ixVModtype);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_x1RefPlnrMDesign,
		(char*) &_ixVModtype,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMStackModtype_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackModtype_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMStackModtype::updateRst(
			ListPlnrJMStackModtype& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMStackModtype::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMStackModtype_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMStackModtype_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMStackModtype::loadRecByRef(
			ubigint ref
			, PlnrJMStackModtype** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMStackModtype_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMStackModtype::loadRecByStkDsn(
			ubigint refPlnrMStack
			, ubigint x1RefPlnrMDesign
			, PlnrJMStackModtype** rec
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

	return loadRecByStmt("TblPlnrJMStackModtype_loadRecByStkDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMStackModtype::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrJMStackModtype& rst
		) {
	ubigint _refPlnrMStack = htonl64(refPlnrMStack);

	const char* vals[] = {
		(char*) &_refPlnrMStack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMStackModtype_loadRstByStk", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

