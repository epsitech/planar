/**
  * \file PlnrRMStackMStructure.cpp
  * database access for table TblPlnrRMStackMStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMStackMStructure.h"

/******************************************************************************
 class PlnrRMStackMStructure
 ******************************************************************************/

PlnrRMStackMStructure::PlnrRMStackMStructure(
			const ubigint ref
			, const ubigint refPlnrMStack
			, const ubigint refPlnrMStructure
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {

	this->ref = ref;
	this->refPlnrMStack = refPlnrMStack;
	this->refPlnrMStructure = refPlnrMStructure;
	this->fromSrefPlnrMLayer = fromSrefPlnrMLayer;
	this->toSrefPlnrMLayer = toSrefPlnrMLayer;
};

bool PlnrRMStackMStructure::operator==(
			const PlnrRMStackMStructure& comp
		) {
	return false;
};

bool PlnrRMStackMStructure::operator!=(
			const PlnrRMStackMStructure& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMStackMStructure
 ******************************************************************************/

ListPlnrRMStackMStructure::ListPlnrRMStackMStructure() {
};

ListPlnrRMStackMStructure::ListPlnrRMStackMStructure(
			const ListPlnrRMStackMStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMStackMStructure(*(src.nodes[i]));
};

ListPlnrRMStackMStructure::~ListPlnrRMStackMStructure() {
	clear();
};

void ListPlnrRMStackMStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMStackMStructure::size() const {
	return(nodes.size());
};

void ListPlnrRMStackMStructure::append(
			PlnrRMStackMStructure* rec
		) {
	nodes.push_back(rec);
};

PlnrRMStackMStructure* ListPlnrRMStackMStructure::operator[](
			const uint ix
		) {
	PlnrRMStackMStructure* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMStackMStructure& ListPlnrRMStackMStructure::operator=(
			const ListPlnrRMStackMStructure& src
		) {
	PlnrRMStackMStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMStackMStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMStackMStructure::operator==(
			const ListPlnrRMStackMStructure& comp
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

bool ListPlnrRMStackMStructure::operator!=(
			const ListPlnrRMStackMStructure& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMStackMStructure
 ******************************************************************************/

TblPlnrRMStackMStructure::TblPlnrRMStackMStructure() {
};

TblPlnrRMStackMStructure::~TblPlnrRMStackMStructure() {
};

bool TblPlnrRMStackMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrRMStackMStructure** rec
		) {
	return false;
};

ubigint TblPlnrRMStackMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	return 0;
};

void TblPlnrRMStackMStructure::insertRec(
			PlnrRMStackMStructure* rec
		) {
};

ubigint TblPlnrRMStackMStructure::insertNewRec(
			PlnrRMStackMStructure** rec
			, const ubigint refPlnrMStack
			, const ubigint refPlnrMStructure
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrRMStackMStructure* _rec = NULL;

	_rec = new PlnrRMStackMStructure(0, refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMStackMStructure::appendNewRecToRst(
			ListPlnrRMStackMStructure& rst
			, PlnrRMStackMStructure** rec
			, const ubigint refPlnrMStack
			, const ubigint refPlnrMStructure
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrRMStackMStructure* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMStackMStructure::insertRst(
			ListPlnrRMStackMStructure& rst
			, bool transact
		) {
};

void TblPlnrRMStackMStructure::updateRec(
			PlnrRMStackMStructure* rec
		) {
};

void TblPlnrRMStackMStructure::updateRst(
			ListPlnrRMStackMStructure& rst
			, bool transact
		) {
};

void TblPlnrRMStackMStructure::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMStackMStructure::loadRecByRef(
			ubigint ref
			, PlnrRMStackMStructure** rec
		) {
	return false;
};

ubigint TblPlnrRMStackMStructure::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	return 0;
};

ubigint TblPlnrRMStackMStructure::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	ubigint numload = 0;
	PlnrRMStackMStructure* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMStackMStructure
 ******************************************************************************/

MyTblPlnrRMStackMStructure::MyTblPlnrRMStackMStructure() : TblPlnrRMStackMStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMStackMStructure::~MyTblPlnrRMStackMStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMStackMStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMStackMStructure (refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMStackMStructure SET refPlnrMStack = ?, refPlnrMStructure = ?, fromSrefPlnrMLayer = ?, toSrefPlnrMLayer = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMStackMStructure WHERE ref = ?", false);
};

bool MyTblPlnrRMStackMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrRMStackMStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMStackMStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMStackMStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMStackMStructure();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMStack = atoll((char*) dbrow[1]); else _rec->refPlnrMStack = 0;
		if (dbrow[2]) _rec->refPlnrMStructure = atoll((char*) dbrow[2]); else _rec->refPlnrMStructure = 0;
		if (dbrow[3]) _rec->fromSrefPlnrMLayer.assign(dbrow[3], dblengths[3]); else _rec->fromSrefPlnrMLayer = "";
		if (dbrow[4]) _rec->toSrefPlnrMLayer.assign(dbrow[4], dblengths[4]); else _rec->toSrefPlnrMLayer = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMStackMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMStackMStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMStackMStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMStackMStructure();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMStack = atoll((char*) dbrow[1]); else rec->refPlnrMStack = 0;
			if (dbrow[2]) rec->refPlnrMStructure = atoll((char*) dbrow[2]); else rec->refPlnrMStructure = 0;
			if (dbrow[3]) rec->fromSrefPlnrMLayer.assign(dbrow[3], dblengths[3]); else rec->fromSrefPlnrMLayer = "";
			if (dbrow[4]) rec->toSrefPlnrMLayer.assign(dbrow[4], dblengths[4]); else rec->toSrefPlnrMLayer = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMStackMStructure::insertRec(
			PlnrRMStackMStructure* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->fromSrefPlnrMLayer.length();
	l[3] = rec->toSrefPlnrMLayer.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStack,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMStructure,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->fromSrefPlnrMLayer.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->toSrefPlnrMLayer.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMStackMStructure / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMStackMStructure / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMStackMStructure::insertRst(
			ListPlnrRMStackMStructure& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMStackMStructure::updateRec(
			PlnrRMStackMStructure* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->fromSrefPlnrMLayer.length();
	l[3] = rec->toSrefPlnrMLayer.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMStack,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMStructure,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->fromSrefPlnrMLayer.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->toSrefPlnrMLayer.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMStackMStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMStackMStructure / stmtUpdateRec)\n");
};

void MyTblPlnrRMStackMStructure::updateRst(
			ListPlnrRMStackMStructure& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMStackMStructure::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMStackMStructure / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMStackMStructure / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMStackMStructure::loadRecByRef(
			ubigint ref
			, PlnrRMStackMStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMStackMStructure WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrRMStackMStructure::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrRMStackMStructure WHERE refPlnrMStack = " + to_string(refPlnrMStack) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMStackMStructure
 ******************************************************************************/

PgTblPlnrRMStackMStructure::PgTblPlnrRMStackMStructure() : TblPlnrRMStackMStructure(), PgTable() {
};

PgTblPlnrRMStackMStructure::~PgTblPlnrRMStackMStructure() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMStackMStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMStackMStructure_insertRec", "INSERT INTO TblPlnrRMStackMStructure (refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMStackMStructure_updateRec", "UPDATE TblPlnrRMStackMStructure SET refPlnrMStack = $1, refPlnrMStructure = $2, fromSrefPlnrMLayer = $3, toSrefPlnrMLayer = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMStackMStructure_removeRecByRef", "DELETE FROM TblPlnrRMStackMStructure WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMStackMStructure_loadRecByRef", "SELECT ref, refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrRMStackMStructure WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrRMStackMStructure_loadRstByStk", "SELECT ref, refPlnrMStack, refPlnrMStructure, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrRMStackMStructure WHERE refPlnrMStack = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrRMStackMStructure::loadRec(
			PGresult* res
			, PlnrRMStackMStructure** rec
		) {
	char* ptr;

	PlnrRMStackMStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMStackMStructure();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstack"),
			PQfnumber(res, "refplnrmstructure"),
			PQfnumber(res, "fromsrefplnrmlayer"),
			PQfnumber(res, "tosrefplnrmlayer")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMStack = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMStructure = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->fromSrefPlnrMLayer.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->toSrefPlnrMLayer.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMStackMStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMStackMStructure* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmstack"),
			PQfnumber(res, "refplnrmstructure"),
			PQfnumber(res, "fromsrefplnrmlayer"),
			PQfnumber(res, "tosrefplnrmlayer")
		};

		while (numread < numrow) {
			rec = new PlnrRMStackMStructure();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMStack = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMStructure = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->fromSrefPlnrMLayer.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->toSrefPlnrMLayer.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMStackMStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMStackMStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMStackMStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrRMStackMStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMStackMStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrRMStackMStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrRMStackMStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMStackMStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMStackMStructure::insertRec(
			PlnrRMStackMStructure* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMStack = htonl64(rec->refPlnrMStack);
	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_refPlnrMStructure,
		rec->fromSrefPlnrMLayer.c_str(),
		rec->toSrefPlnrMLayer.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrRMStackMStructure_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMStackMStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMStackMStructure::insertRst(
			ListPlnrRMStackMStructure& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMStackMStructure::updateRec(
			PlnrRMStackMStructure* rec
		) {
	PGresult* res;

	ubigint _refPlnrMStack = htonl64(rec->refPlnrMStack);
	ubigint _refPlnrMStructure = htonl64(rec->refPlnrMStructure);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMStack,
		(char*) &_refPlnrMStructure,
		rec->fromSrefPlnrMLayer.c_str(),
		rec->toSrefPlnrMLayer.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMStackMStructure_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMStackMStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMStackMStructure::updateRst(
			ListPlnrRMStackMStructure& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMStackMStructure::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMStackMStructure_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMStackMStructure_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMStackMStructure::loadRecByRef(
			ubigint ref
			, PlnrRMStackMStructure** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMStackMStructure_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrRMStackMStructure::loadRstByStk(
			ubigint refPlnrMStack
			, const bool append
			, ListPlnrRMStackMStructure& rst
		) {
	ubigint _refPlnrMStack = htonl64(refPlnrMStack);

	const char* vals[] = {
		(char*) &_refPlnrMStack
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrRMStackMStructure_loadRstByStk", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

