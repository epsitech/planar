/**
  * \file PlnrAMCalcEnv.cpp
  * database access for table TblPlnrAMCalcEnv (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMCalcEnv.h"

/******************************************************************************
 class PlnrAMCalcEnv
 ******************************************************************************/

PlnrAMCalcEnv::PlnrAMCalcEnv(
			const ubigint ref
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string Val
		) {

	this->ref = ref;
	this->refPlnrMCalc = refPlnrMCalc;
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->x2SrefKKey = x2SrefKKey;
	this->Val = Val;
};

bool PlnrAMCalcEnv::operator==(
			const PlnrAMCalcEnv& comp
		) {
	return false;
};

bool PlnrAMCalcEnv::operator!=(
			const PlnrAMCalcEnv& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMCalcEnv
 ******************************************************************************/

ListPlnrAMCalcEnv::ListPlnrAMCalcEnv() {
};

ListPlnrAMCalcEnv::ListPlnrAMCalcEnv(
			const ListPlnrAMCalcEnv& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMCalcEnv(*(src.nodes[i]));
};

ListPlnrAMCalcEnv::~ListPlnrAMCalcEnv() {
	clear();
};

void ListPlnrAMCalcEnv::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMCalcEnv::size() const {
	return(nodes.size());
};

void ListPlnrAMCalcEnv::append(
			PlnrAMCalcEnv* rec
		) {
	nodes.push_back(rec);
};

PlnrAMCalcEnv* ListPlnrAMCalcEnv::operator[](
			const uint ix
		) {
	PlnrAMCalcEnv* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMCalcEnv& ListPlnrAMCalcEnv::operator=(
			const ListPlnrAMCalcEnv& src
		) {
	PlnrAMCalcEnv* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMCalcEnv(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMCalcEnv::operator==(
			const ListPlnrAMCalcEnv& comp
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

bool ListPlnrAMCalcEnv::operator!=(
			const ListPlnrAMCalcEnv& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMCalcEnv
 ******************************************************************************/

TblPlnrAMCalcEnv::TblPlnrAMCalcEnv() {
};

TblPlnrAMCalcEnv::~TblPlnrAMCalcEnv() {
};

bool TblPlnrAMCalcEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrAMCalcEnv** rec
		) {
	return false;
};

ubigint TblPlnrAMCalcEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	return 0;
};

void TblPlnrAMCalcEnv::insertRec(
			PlnrAMCalcEnv* rec
		) {
};

ubigint TblPlnrAMCalcEnv::insertNewRec(
			PlnrAMCalcEnv** rec
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMCalcEnv* _rec = NULL;

	_rec = new PlnrAMCalcEnv(0, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMCalcEnv::appendNewRecToRst(
			ListPlnrAMCalcEnv& rst
			, PlnrAMCalcEnv** rec
			, const ubigint refPlnrMCalc
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKKey
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMCalcEnv* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMCalcEnv::insertRst(
			ListPlnrAMCalcEnv& rst
			, bool transact
		) {
};

void TblPlnrAMCalcEnv::updateRec(
			PlnrAMCalcEnv* rec
		) {
};

void TblPlnrAMCalcEnv::updateRst(
			ListPlnrAMCalcEnv& rst
			, bool transact
		) {
};

void TblPlnrAMCalcEnv::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMCalcEnv::loadRecByRef(
			ubigint ref
			, PlnrAMCalcEnv** rec
		) {
	return false;
};

ubigint TblPlnrAMCalcEnv::loadRstByCalCli(
			ubigint refPlnrMCalc
			, ubigint x1RefPlnrMCalcitem
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	return 0;
};

ubigint TblPlnrAMCalcEnv::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	ubigint numload = 0;
	PlnrAMCalcEnv* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMCalcEnv
 ******************************************************************************/

MyTblPlnrAMCalcEnv::MyTblPlnrAMCalcEnv() : TblPlnrAMCalcEnv(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMCalcEnv::~MyTblPlnrAMCalcEnv() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMCalcEnv::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMCalcEnv (refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMCalcEnv SET refPlnrMCalc = ?, x1RefPlnrMCalcitem = ?, x2SrefKKey = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMCalcEnv WHERE ref = ?", false);
};

bool MyTblPlnrAMCalcEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrAMCalcEnv** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMCalcEnv* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMCalcEnv / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMCalcEnv();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMCalc = atoll((char*) dbrow[1]); else _rec->refPlnrMCalc = 0;
		if (dbrow[2]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[3]) _rec->x2SrefKKey.assign(dbrow[3], dblengths[3]); else _rec->x2SrefKKey = "";
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMCalcEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMCalcEnv* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMCalcEnv / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMCalcEnv();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMCalc = atoll((char*) dbrow[1]); else rec->refPlnrMCalc = 0;
			if (dbrow[2]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[2]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[3]) rec->x2SrefKKey.assign(dbrow[3], dblengths[3]); else rec->x2SrefKKey = "";
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMCalcEnv::insertRec(
			PlnrAMCalcEnv* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->x2SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMCalc,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMCalcEnv / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMCalcEnv / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMCalcEnv::insertRst(
			ListPlnrAMCalcEnv& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMCalcEnv::updateRec(
			PlnrAMCalcEnv* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->x2SrefKKey.length();
	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMCalc,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMCalcEnv / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMCalcEnv / stmtUpdateRec)\n");
};

void MyTblPlnrAMCalcEnv::updateRst(
			ListPlnrAMCalcEnv& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMCalcEnv::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMCalcEnv / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMCalcEnv / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMCalcEnv::loadRecByRef(
			ubigint ref
			, PlnrAMCalcEnv** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMCalcEnv WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrAMCalcEnv::loadRstByCalCli(
			ubigint refPlnrMCalc
			, ubigint x1RefPlnrMCalcitem
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrAMCalcEnv WHERE refPlnrMCalc = " + to_string(refPlnrMCalc) + " AND x1RefPlnrMCalcitem = " + to_string(x1RefPlnrMCalcitem) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMCalcEnv
 ******************************************************************************/

PgTblPlnrAMCalcEnv::PgTblPlnrAMCalcEnv() : TblPlnrAMCalcEnv(), PgTable() {
};

PgTblPlnrAMCalcEnv::~PgTblPlnrAMCalcEnv() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMCalcEnv::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMCalcEnv_insertRec", "INSERT INTO TblPlnrAMCalcEnv (refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMCalcEnv_updateRec", "UPDATE TblPlnrAMCalcEnv SET refPlnrMCalc = $1, x1RefPlnrMCalcitem = $2, x2SrefKKey = $3, Val = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMCalcEnv_removeRecByRef", "DELETE FROM TblPlnrAMCalcEnv WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMCalcEnv_loadRecByRef", "SELECT ref, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrAMCalcEnv WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAMCalcEnv_loadRstByCalCli", "SELECT ref, refPlnrMCalc, x1RefPlnrMCalcitem, x2SrefKKey, Val FROM TblPlnrAMCalcEnv WHERE refPlnrMCalc = $1 AND x1RefPlnrMCalcitem = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAMCalcEnv::loadRec(
			PGresult* res
			, PlnrAMCalcEnv** rec
		) {
	char* ptr;

	PlnrAMCalcEnv* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMCalcEnv();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMCalcEnv::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMCalcEnv* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAMCalcEnv();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMCalcEnv::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMCalcEnv** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcEnv / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrAMCalcEnv::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcEnv / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrAMCalcEnv::loadRecBySQL(
			const string& sqlstr
			, PlnrAMCalcEnv** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMCalcEnv::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMCalcEnv::insertRec(
			PlnrAMCalcEnv* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_x1RefPlnrMCalcitem,
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

	res = PQexecPrepared(dbs, "TblPlnrAMCalcEnv_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcEnv_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMCalcEnv::insertRst(
			ListPlnrAMCalcEnv& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMCalcEnv::updateRec(
			PlnrAMCalcEnv* rec
		) {
	PGresult* res;

	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_x1RefPlnrMCalcitem,
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

	res = PQexecPrepared(dbs, "TblPlnrAMCalcEnv_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcEnv_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMCalcEnv::updateRst(
			ListPlnrAMCalcEnv& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMCalcEnv::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMCalcEnv_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMCalcEnv_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMCalcEnv::loadRecByRef(
			ubigint ref
			, PlnrAMCalcEnv** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMCalcEnv_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrAMCalcEnv::loadRstByCalCli(
			ubigint refPlnrMCalc
			, ubigint x1RefPlnrMCalcitem
			, const bool append
			, ListPlnrAMCalcEnv& rst
		) {
	ubigint _refPlnrMCalc = htonl64(refPlnrMCalc);
	ubigint _x1RefPlnrMCalcitem = htonl64(x1RefPlnrMCalcitem);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_x1RefPlnrMCalcitem
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrAMCalcEnv_loadRstByCalCli", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

