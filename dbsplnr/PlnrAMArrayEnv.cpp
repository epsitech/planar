/**
  * \file PlnrAMArrayEnv.cpp
  * database access for table TblPlnrAMArrayEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMArrayEnv.h"

/******************************************************************************
 class PlnrAMArrayEnv
 ******************************************************************************/

PlnrAMArrayEnv::PlnrAMArrayEnv(
			const ubigint ref
			, const ubigint refPlnrMArray
			, const ubigint x1RefPlnrMArrayitem
			, const string x2SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refPlnrMArray = refPlnrMArray;
	this->x1RefPlnrMArrayitem = x1RefPlnrMArrayitem;
	this->x2SrefKKey = x2SrefKKey;
	this->Val = Val;
};

bool PlnrAMArrayEnv::operator==(
			const PlnrAMArrayEnv& comp
		) {
	return false;
};

bool PlnrAMArrayEnv::operator!=(
			const PlnrAMArrayEnv& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMArrayEnv
 ******************************************************************************/

ListPlnrAMArrayEnv::ListPlnrAMArrayEnv() {
};

ListPlnrAMArrayEnv::ListPlnrAMArrayEnv(
			const ListPlnrAMArrayEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMArrayEnv(*(src.nodes[i]));
};

ListPlnrAMArrayEnv::~ListPlnrAMArrayEnv() {
	clear();
};

void ListPlnrAMArrayEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMArrayEnv::size() const {
	return(nodes.size());
};

void ListPlnrAMArrayEnv::append(
			PlnrAMArrayEnv* rec
		) {
	nodes.push_back(rec);
};

PlnrAMArrayEnv* ListPlnrAMArrayEnv::operator[](
			const uint ix
		) {
	PlnrAMArrayEnv* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMArrayEnv& ListPlnrAMArrayEnv::operator=(
			const ListPlnrAMArrayEnv& src
		) {
	PlnrAMArrayEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMArrayEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMArrayEnv::operator==(
			const ListPlnrAMArrayEnv& comp
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

bool ListPlnrAMArrayEnv::operator!=(
			const ListPlnrAMArrayEnv& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMArrayEnv
 ******************************************************************************/

TblPlnrAMArrayEnv::TblPlnrAMArrayEnv() {
};

TblPlnrAMArrayEnv::~TblPlnrAMArrayEnv() {
};

bool TblPlnrAMArrayEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrAMArrayEnv** rec
		) {
	return false;
};

ubigint TblPlnrAMArrayEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	return 0;
};

void TblPlnrAMArrayEnv::insertRec(
			PlnrAMArrayEnv* rec
		) {
};

ubigint TblPlnrAMArrayEnv::insertNewRec(
			PlnrAMArrayEnv** rec
			, const ubigint refPlnrMArray
			, const ubigint x1RefPlnrMArrayitem
			, const string x2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMArrayEnv* _rec = NULL;

	_rec = new PlnrAMArrayEnv(0, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMArrayEnv::appendNewRecToRst(
			ListPlnrAMArrayEnv& rst
			, PlnrAMArrayEnv** rec
			, const ubigint refPlnrMArray
			, const ubigint x1RefPlnrMArrayitem
			, const string x2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMArrayEnv* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMArrayEnv::insertRst(
			ListPlnrAMArrayEnv& rst
			, bool transact
		) {
};

void TblPlnrAMArrayEnv::updateRec(
			PlnrAMArrayEnv* rec
		) {
};

void TblPlnrAMArrayEnv::updateRst(
			ListPlnrAMArrayEnv& rst
			, bool transact
		) {
};

void TblPlnrAMArrayEnv::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMArrayEnv::loadRecByRef(
			ubigint ref
			, PlnrAMArrayEnv** rec
		) {
	return false;
};

ubigint TblPlnrAMArrayEnv::loadRstByArrAri(
			ubigint refPlnrMArray
			, ubigint x1RefPlnrMArrayitem
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	return 0;
};

ubigint TblPlnrAMArrayEnv::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	ubigint numload = 0;
	PlnrAMArrayEnv* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMArrayEnv
 ******************************************************************************/

MyTblPlnrAMArrayEnv::MyTblPlnrAMArrayEnv() : TblPlnrAMArrayEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMArrayEnv::~MyTblPlnrAMArrayEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMArrayEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMArrayEnv (refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMArrayEnv SET refPlnrMArray = ?, x1RefPlnrMArrayitem = ?, x2SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMArrayEnv WHERE ref = ?", false);
};

bool MyTblPlnrAMArrayEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrAMArrayEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMArrayEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMArrayEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMArrayEnv();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMArray = atoll((char*) dbrow[1]); else _rec->refPlnrMArray = 0;
		if (dbrow[2]) _rec->x1RefPlnrMArrayitem = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMArrayitem = 0;
		if (dbrow[3]) _rec->x2SrefKKey.assign(dbrow[3], dblengths[3]); else _rec->x2SrefKKey = "";
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMArrayEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMArrayEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMArrayEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMArrayEnv();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMArray = atoll((char*) dbrow[1]); else rec->refPlnrMArray = 0;
			if (dbrow[2]) rec->x1RefPlnrMArrayitem = atoll((char*) dbrow[2]); else rec->x1RefPlnrMArrayitem = 0;
			if (dbrow[3]) rec->x2SrefKKey.assign(dbrow[3], dblengths[3]); else rec->x2SrefKKey = "";
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMArrayEnv::insertRec(
			PlnrAMArrayEnv* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArray,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMArrayitem,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMArrayEnv / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMArrayEnv / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMArrayEnv::insertRst(
			ListPlnrAMArrayEnv& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMArrayEnv::updateRec(
			PlnrAMArrayEnv* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMArray,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMArrayitem,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMArrayEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMArrayEnv / stmtUpdateRec)\n");
};

void MyTblPlnrAMArrayEnv::updateRst(
			ListPlnrAMArrayEnv& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMArrayEnv::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMArrayEnv / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMArrayEnv / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMArrayEnv::loadRecByRef(
			ubigint ref
			, PlnrAMArrayEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMArrayEnv WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrAMArrayEnv::loadRstByArrAri(
			ubigint refPlnrMArray
			, ubigint x1RefPlnrMArrayitem
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val FROM TblPlnrAMArrayEnv WHERE refPlnrMArray = " + to_string(refPlnrMArray) + " AND x1RefPlnrMArrayitem = " + to_string(x1RefPlnrMArrayitem) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMArrayEnv
 ******************************************************************************/

PgTblPlnrAMArrayEnv::PgTblPlnrAMArrayEnv() : TblPlnrAMArrayEnv(), PgTable() {
};

PgTblPlnrAMArrayEnv::~PgTblPlnrAMArrayEnv() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMArrayEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMArrayEnv_insertRec", "INSERT INTO TblPlnrAMArrayEnv (refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMArrayEnv_updateRec", "UPDATE TblPlnrAMArrayEnv SET refPlnrMArray = $1, x1RefPlnrMArrayitem = $2, x2SrefKKey = $3, Val = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMArrayEnv_removeRecByRef", "DELETE FROM TblPlnrAMArrayEnv WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMArrayEnv_loadRecByRef", "SELECT ref, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val FROM TblPlnrAMArrayEnv WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAMArrayEnv_loadRstByArrAri", "SELECT ref, refPlnrMArray, x1RefPlnrMArrayitem, x2SrefKKey, Val FROM TblPlnrAMArrayEnv WHERE refPlnrMArray = $1 AND x1RefPlnrMArrayitem = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAMArrayEnv::loadRec(
			PGresult* res
			, PlnrAMArrayEnv** rec
		) {
	char* ptr;

	PlnrAMArrayEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMArrayEnv();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarray"),
			PQfnumber(res, "x1refplnrmarrayitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMArray = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMArrayitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMArrayEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMArrayEnv* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmarray"),
			PQfnumber(res, "x1refplnrmarrayitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAMArrayEnv();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMArray = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMArrayitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMArrayEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMArrayEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMArrayEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrAMArrayEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMArrayEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrAMArrayEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrAMArrayEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMArrayEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMArrayEnv::insertRec(
			PlnrAMArrayEnv* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMArray = htonl64(rec->refPlnrMArray);
	ubigint _x1RefPlnrMArrayitem = htonl64(rec->x1RefPlnrMArrayitem);

	const char* vals[] = {
		(char*) &_refPlnrMArray,
		(char*) &_x1RefPlnrMArrayitem,
		rec->x2SrefKKey.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrAMArrayEnv_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMArrayEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMArrayEnv::insertRst(
			ListPlnrAMArrayEnv& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMArrayEnv::updateRec(
			PlnrAMArrayEnv* rec
		) {
	PGresult* res;

	ubigint _refPlnrMArray = htonl64(rec->refPlnrMArray);
	ubigint _x1RefPlnrMArrayitem = htonl64(rec->x1RefPlnrMArrayitem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMArray,
		(char*) &_x1RefPlnrMArrayitem,
		rec->x2SrefKKey.c_str(),
		rec->Val.c_str(),
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

	res = PQexecPrepared(dbs, "TblPlnrAMArrayEnv_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMArrayEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMArrayEnv::updateRst(
			ListPlnrAMArrayEnv& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMArrayEnv::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMArrayEnv_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMArrayEnv_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMArrayEnv::loadRecByRef(
			ubigint ref
			, PlnrAMArrayEnv** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMArrayEnv_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrAMArrayEnv::loadRstByArrAri(
			ubigint refPlnrMArray
			, ubigint x1RefPlnrMArrayitem
			, const bool append
			, ListPlnrAMArrayEnv& rst
		) {
	ubigint _refPlnrMArray = htonl64(refPlnrMArray);
	ubigint _x1RefPlnrMArrayitem = htonl64(x1RefPlnrMArrayitem);

	const char* vals[] = {
		(char*) &_refPlnrMArray,
		(char*) &_x1RefPlnrMArrayitem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrAMArrayEnv_loadRstByArrAri", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

