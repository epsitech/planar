/**
  * \file PlnrAMPersonDetail.cpp
  * database access for table TblPlnrAMPersonDetail (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAMPersonDetail.h"

/******************************************************************************
 class PlnrAMPersonDetail
 ******************************************************************************/

PlnrAMPersonDetail::PlnrAMPersonDetail(
			const ubigint ref
			, const ubigint refPlnrMPerson
			, const string x1SrefKType
			, const string Val
		) {

	this->ref = ref;
	this->refPlnrMPerson = refPlnrMPerson;
	this->x1SrefKType = x1SrefKType;
	this->Val = Val;
};

bool PlnrAMPersonDetail::operator==(
			const PlnrAMPersonDetail& comp
		) {
	return false;
};

bool PlnrAMPersonDetail::operator!=(
			const PlnrAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAMPersonDetail
 ******************************************************************************/

ListPlnrAMPersonDetail::ListPlnrAMPersonDetail() {
};

ListPlnrAMPersonDetail::ListPlnrAMPersonDetail(
			const ListPlnrAMPersonDetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAMPersonDetail(*(src.nodes[i]));
};

ListPlnrAMPersonDetail::~ListPlnrAMPersonDetail() {
	clear();
};

void ListPlnrAMPersonDetail::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAMPersonDetail::size() const {
	return(nodes.size());
};

void ListPlnrAMPersonDetail::append(
			PlnrAMPersonDetail* rec
		) {
	nodes.push_back(rec);
};

PlnrAMPersonDetail* ListPlnrAMPersonDetail::operator[](
			const uint ix
		) {
	PlnrAMPersonDetail* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAMPersonDetail& ListPlnrAMPersonDetail::operator=(
			const ListPlnrAMPersonDetail& src
		) {
	PlnrAMPersonDetail* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAMPersonDetail(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAMPersonDetail::operator==(
			const ListPlnrAMPersonDetail& comp
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

bool ListPlnrAMPersonDetail::operator!=(
			const ListPlnrAMPersonDetail& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAMPersonDetail
 ******************************************************************************/

TblPlnrAMPersonDetail::TblPlnrAMPersonDetail() {
};

TblPlnrAMPersonDetail::~TblPlnrAMPersonDetail() {
};

bool TblPlnrAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, PlnrAMPersonDetail** rec
		) {
	return false;
};

ubigint TblPlnrAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMPersonDetail& rst
		) {
	return 0;
};

void TblPlnrAMPersonDetail::insertRec(
			PlnrAMPersonDetail* rec
		) {
};

ubigint TblPlnrAMPersonDetail::insertNewRec(
			PlnrAMPersonDetail** rec
			, const ubigint refPlnrMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMPersonDetail* _rec = NULL;

	_rec = new PlnrAMPersonDetail(0, refPlnrMPerson, x1SrefKType, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAMPersonDetail::appendNewRecToRst(
			ListPlnrAMPersonDetail& rst
			, PlnrAMPersonDetail** rec
			, const ubigint refPlnrMPerson
			, const string x1SrefKType
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAMPersonDetail* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMPerson, x1SrefKType, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAMPersonDetail::insertRst(
			ListPlnrAMPersonDetail& rst
			, bool transact
		) {
};

void TblPlnrAMPersonDetail::updateRec(
			PlnrAMPersonDetail* rec
		) {
};

void TblPlnrAMPersonDetail::updateRst(
			ListPlnrAMPersonDetail& rst
			, bool transact
		) {
};

void TblPlnrAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAMPersonDetail::loadRecByRef(
			ubigint ref
			, PlnrAMPersonDetail** rec
		) {
	return false;
};

ubigint TblPlnrAMPersonDetail::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAMPersonDetail& rst
		) {
	ubigint numload = 0;
	PlnrAMPersonDetail* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAMPersonDetail
 ******************************************************************************/

MyTblPlnrAMPersonDetail::MyTblPlnrAMPersonDetail() : TblPlnrAMPersonDetail(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAMPersonDetail::~MyTblPlnrAMPersonDetail() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAMPersonDetail::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAMPersonDetail (refPlnrMPerson, x1SrefKType, Val) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAMPersonDetail SET refPlnrMPerson = ?, x1SrefKType = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAMPersonDetail WHERE ref = ?", false);
};

bool MyTblPlnrAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, PlnrAMPersonDetail** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAMPersonDetail* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMPersonDetail / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAMPersonDetail();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMPerson = atoll((char*) dbrow[1]); else _rec->refPlnrMPerson = 0;
		if (dbrow[2]) _rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else _rec->x1SrefKType = "";
		if (dbrow[3]) _rec->Val.assign(dbrow[3], dblengths[3]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMPersonDetail& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAMPersonDetail* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAMPersonDetail / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAMPersonDetail();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMPerson = atoll((char*) dbrow[1]); else rec->refPlnrMPerson = 0;
			if (dbrow[2]) rec->x1SrefKType.assign(dbrow[2], dblengths[2]); else rec->x1SrefKType = "";
			if (dbrow[3]) rec->Val.assign(dbrow[3], dblengths[3]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAMPersonDetail::insertRec(
			PlnrAMPersonDetail* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMPersonDetail / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMPersonDetail / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAMPersonDetail::insertRst(
			ListPlnrAMPersonDetail& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAMPersonDetail::updateRec(
			PlnrAMPersonDetail* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[1] = rec->x1SrefKType.length();
	l[2] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindCstring((char*) (rec->x1SrefKType.c_str()),&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMPersonDetail / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMPersonDetail / stmtUpdateRec)\n");
};

void MyTblPlnrAMPersonDetail::updateRst(
			ListPlnrAMPersonDetail& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAMPersonDetail::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAMPersonDetail / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAMPersonDetail / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAMPersonDetail::loadRecByRef(
			ubigint ref
			, PlnrAMPersonDetail** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAMPersonDetail WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAMPersonDetail
 ******************************************************************************/

PgTblPlnrAMPersonDetail::PgTblPlnrAMPersonDetail() : TblPlnrAMPersonDetail(), PgTable() {
};

PgTblPlnrAMPersonDetail::~PgTblPlnrAMPersonDetail() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAMPersonDetail::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAMPersonDetail_insertRec", "INSERT INTO TblPlnrAMPersonDetail (refPlnrMPerson, x1SrefKType, Val) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMPersonDetail_updateRec", "UPDATE TblPlnrAMPersonDetail SET refPlnrMPerson = $1, x1SrefKType = $2, Val = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAMPersonDetail_removeRecByRef", "DELETE FROM TblPlnrAMPersonDetail WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAMPersonDetail_loadRecByRef", "SELECT ref, refPlnrMPerson, x1SrefKType, Val FROM TblPlnrAMPersonDetail WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrAMPersonDetail::loadRec(
			PGresult* res
			, PlnrAMPersonDetail** rec
		) {
	char* ptr;

	PlnrAMPersonDetail* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAMPersonDetail();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1SrefKType.assign(ptr, PQgetlength(res, 0, fnum[2]));
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAMPersonDetail::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAMPersonDetail& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAMPersonDetail* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "x1srefktype"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAMPersonDetail();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1SrefKType.assign(ptr, PQgetlength(res, numread, fnum[2]));
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAMPersonDetail::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMPersonDetail / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAMPersonDetail::loadRecBySQL(
			const string& sqlstr
			, PlnrAMPersonDetail** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAMPersonDetail::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAMPersonDetail& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAMPersonDetail::insertRec(
			PlnrAMPersonDetail* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);

	const char* vals[] = {
		(char*) &_refPlnrMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrAMPersonDetail_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMPersonDetail_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAMPersonDetail::insertRst(
			ListPlnrAMPersonDetail& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAMPersonDetail::updateRec(
			PlnrAMPersonDetail* rec
		) {
	PGresult* res;

	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMPerson,
		rec->x1SrefKType.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAMPersonDetail_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMPersonDetail_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAMPersonDetail::updateRst(
			ListPlnrAMPersonDetail& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAMPersonDetail::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAMPersonDetail_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAMPersonDetail_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAMPersonDetail::loadRecByRef(
			ubigint ref
			, PlnrAMPersonDetail** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAMPersonDetail_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

