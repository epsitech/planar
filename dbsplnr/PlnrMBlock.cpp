/**
  * \file PlnrMBlock.cpp
  * database access for table TblPlnrMBlock (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMBlock.h"

/******************************************************************************
 class PlnrMBlock
 ******************************************************************************/

PlnrMBlock::PlnrMBlock(
			const ubigint ref
			, const ubigint refPlnrMDesign
			, const ubigint refPlnrMStructure
			, const ubigint refPlnrMLayer
		) {

	this->ref = ref;
	this->refPlnrMDesign = refPlnrMDesign;
	this->refPlnrMStructure = refPlnrMStructure;
	this->refPlnrMLayer = refPlnrMLayer;
};

bool PlnrMBlock::operator==(
			const PlnrMBlock& comp
		) {
	return false;
};

bool PlnrMBlock::operator!=(
			const PlnrMBlock& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMBlock
 ******************************************************************************/

ListPlnrMBlock::ListPlnrMBlock() {
};

ListPlnrMBlock::ListPlnrMBlock(
			const ListPlnrMBlock& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMBlock(*(src.nodes[i]));
};

ListPlnrMBlock::~ListPlnrMBlock() {
	clear();
};

void ListPlnrMBlock::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMBlock::size() const {
	return(nodes.size());
};

void ListPlnrMBlock::append(
			PlnrMBlock* rec
		) {
	nodes.push_back(rec);
};

PlnrMBlock* ListPlnrMBlock::operator[](
			const uint ix
		) {
	PlnrMBlock* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMBlock& ListPlnrMBlock::operator=(
			const ListPlnrMBlock& src
		) {
	PlnrMBlock* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMBlock(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMBlock::operator==(
			const ListPlnrMBlock& comp
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

bool ListPlnrMBlock::operator!=(
			const ListPlnrMBlock& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMBlock
 ******************************************************************************/

TblPlnrMBlock::TblPlnrMBlock() {
};

TblPlnrMBlock::~TblPlnrMBlock() {
};

bool TblPlnrMBlock::loadRecBySQL(
			const string& sqlstr
			, PlnrMBlock** rec
		) {
	return false;
};

ubigint TblPlnrMBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMBlock& rst
		) {
	return 0;
};

void TblPlnrMBlock::insertRec(
			PlnrMBlock* rec
		) {
};

ubigint TblPlnrMBlock::insertNewRec(
			PlnrMBlock** rec
			, const ubigint refPlnrMDesign
			, const ubigint refPlnrMStructure
			, const ubigint refPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrMBlock* _rec = NULL;

	_rec = new PlnrMBlock(0, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMBlock::appendNewRecToRst(
			ListPlnrMBlock& rst
			, PlnrMBlock** rec
			, const ubigint refPlnrMDesign
			, const ubigint refPlnrMStructure
			, const ubigint refPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrMBlock* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMBlock::insertRst(
			ListPlnrMBlock& rst
			, bool transact
		) {
};

void TblPlnrMBlock::updateRec(
			PlnrMBlock* rec
		) {
};

void TblPlnrMBlock::updateRst(
			ListPlnrMBlock& rst
			, bool transact
		) {
};

void TblPlnrMBlock::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMBlock::loadRecByRef(
			ubigint ref
			, PlnrMBlock** rec
		) {
	return false;
};

ubigint TblPlnrMBlock::loadRstByDsn(
			ubigint refPlnrMDesign
			, const bool append
			, ListPlnrMBlock& rst
		) {
	return 0;
};

ubigint TblPlnrMBlock::loadRstByDsnLyr(
			ubigint refPlnrMDesign
			, ubigint refPlnrMLayer
			, const bool append
			, ListPlnrMBlock& rst
		) {
	return 0;
};

ubigint TblPlnrMBlock::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMBlock& rst
		) {
	ubigint numload = 0;
	PlnrMBlock* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMBlock
 ******************************************************************************/

MyTblPlnrMBlock::MyTblPlnrMBlock() : TblPlnrMBlock(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMBlock::~MyTblPlnrMBlock() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMBlock::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMBlock (refPlnrMDesign, refPlnrMStructure, refPlnrMLayer) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMBlock SET refPlnrMDesign = ?, refPlnrMStructure = ?, refPlnrMLayer = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMBlock WHERE ref = ?", false);
};

bool MyTblPlnrMBlock::loadRecBySQL(
			const string& sqlstr
			, PlnrMBlock** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMBlock* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMBlock / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMBlock();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMDesign = atoll((char*) dbrow[1]); else _rec->refPlnrMDesign = 0;
		if (dbrow[2]) _rec->refPlnrMStructure = atoll((char*) dbrow[2]); else _rec->refPlnrMStructure = 0;
		if (dbrow[3]) _rec->refPlnrMLayer = atoll((char*) dbrow[3]); else _rec->refPlnrMLayer = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMBlock& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMBlock* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMBlock / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMBlock();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMDesign = atoll((char*) dbrow[1]); else rec->refPlnrMDesign = 0;
			if (dbrow[2]) rec->refPlnrMStructure = atoll((char*) dbrow[2]); else rec->refPlnrMStructure = 0;
			if (dbrow[3]) rec->refPlnrMLayer = atoll((char*) dbrow[3]); else rec->refPlnrMLayer = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMBlock::insertRec(
			PlnrMBlock* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDesign,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMStructure,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMLayer,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMBlock / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMBlock / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMBlock::insertRst(
			ListPlnrMBlock& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMBlock::updateRec(
			PlnrMBlock* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMDesign,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMStructure,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMLayer,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMBlock / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMBlock / stmtUpdateRec)\n");
};

void MyTblPlnrMBlock::updateRst(
			ListPlnrMBlock& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMBlock::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMBlock / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMBlock / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMBlock::loadRecByRef(
			ubigint ref
			, PlnrMBlock** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMBlock WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMBlock::loadRstByDsn(
			ubigint refPlnrMDesign
			, const bool append
			, ListPlnrMBlock& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer FROM TblPlnrMBlock WHERE refPlnrMDesign = " + to_string(refPlnrMDesign) + "", append, rst);
};

ubigint MyTblPlnrMBlock::loadRstByDsnLyr(
			ubigint refPlnrMDesign
			, ubigint refPlnrMLayer
			, const bool append
			, ListPlnrMBlock& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer FROM TblPlnrMBlock WHERE refPlnrMDesign = " + to_string(refPlnrMDesign) + " AND refPlnrMLayer = " + to_string(refPlnrMLayer) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMBlock
 ******************************************************************************/

PgTblPlnrMBlock::PgTblPlnrMBlock() : TblPlnrMBlock(), PgTable() {
};

PgTblPlnrMBlock::~PgTblPlnrMBlock() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMBlock::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMBlock_insertRec", "INSERT INTO TblPlnrMBlock (refPlnrMDesign, refPlnrMStructure, refPlnrMLayer) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMBlock_updateRec", "UPDATE TblPlnrMBlock SET refPlnrMDesign = $1, refPlnrMStructure = $2, refPlnrMLayer = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMBlock_removeRecByRef", "DELETE FROM TblPlnrMBlock WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMBlock_loadRecByRef", "SELECT ref, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer FROM TblPlnrMBlock WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMBlock_loadRstByDsn", "SELECT ref, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer FROM TblPlnrMBlock WHERE refPlnrMDesign = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMBlock_loadRstByDsnLyr", "SELECT ref, refPlnrMDesign, refPlnrMStructure, refPlnrMLayer FROM TblPlnrMBlock WHERE refPlnrMDesign = $1 AND refPlnrMLayer = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMBlock::loadRec(
			PGresult* res
			, PlnrMBlock** rec
		) {
	char* ptr;

	PlnrMBlock* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMBlock();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "refplnrmstructure"),
			PQfnumber(res, "refplnrmlayer")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMStructure = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMLayer = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMBlock::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMBlock& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMBlock* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "refplnrmstructure"),
			PQfnumber(res, "refplnrmlayer")
		};

		while (numread < numrow) {
			rec = new PlnrMBlock();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMStructure = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMLayer = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMBlock::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMBlock** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMBlock / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMBlock::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMBlock& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMBlock / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMBlock::loadRecBySQL(
			const string& sqlstr
			, PlnrMBlock** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMBlock::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMBlock& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMBlock::insertRec(
			PlnrMBlock* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);
	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);

	const char* vals[] = {
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMStructure,
		(char*) &_refPlnrMLayer
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrMBlock_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMBlock_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMBlock::insertRst(
			ListPlnrMBlock& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMBlock::updateRec(
			PlnrMBlock* rec
		) {
	PGresult* res;

	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);
	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMStructure,
		(char*) &_refPlnrMLayer,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrMBlock_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMBlock_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMBlock::updateRst(
			ListPlnrMBlock& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMBlock::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMBlock_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMBlock_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMBlock::loadRecByRef(
			ubigint ref
			, PlnrMBlock** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMBlock_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMBlock::loadRstByDsn(
			ubigint refPlnrMDesign
			, const bool append
			, ListPlnrMBlock& rst
		) {
	ubigint _refPlnrMDesign = htonl64(refPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMBlock_loadRstByDsn", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrMBlock::loadRstByDsnLyr(
			ubigint refPlnrMDesign
			, ubigint refPlnrMLayer
			, const bool append
			, ListPlnrMBlock& rst
		) {
	ubigint _refPlnrMDesign = htonl64(refPlnrMDesign);
	ubigint _refPlnrMLayer = htonl64(refPlnrMLayer);

	const char* vals[] = {
		(char*) &_refPlnrMDesign,
		(char*) &_refPlnrMLayer
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrMBlock_loadRstByDsnLyr", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

