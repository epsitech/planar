/**
  * \file PlnrAccRMUserUniversal.cpp
  * database access for table TblPlnrAccRMUserUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAccRMUserUniversal.h"

/******************************************************************************
 class PlnrAccRMUserUniversal
 ******************************************************************************/

PlnrAccRMUserUniversal::PlnrAccRMUserUniversal(
			const ubigint ref
			, const ubigint refPlnrMUser
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVAccess
		) {

	this->ref = ref;
	this->refPlnrMUser = refPlnrMUser;
	this->unvIxPlnrVMaintable = unvIxPlnrVMaintable;
	this->unvUref = unvUref;
	this->ixPlnrVAccess = ixPlnrVAccess;
};

bool PlnrAccRMUserUniversal::operator==(
			const PlnrAccRMUserUniversal& comp
		) {
	return false;
};

bool PlnrAccRMUserUniversal::operator!=(
			const PlnrAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAccRMUserUniversal
 ******************************************************************************/

ListPlnrAccRMUserUniversal::ListPlnrAccRMUserUniversal() {
};

ListPlnrAccRMUserUniversal::ListPlnrAccRMUserUniversal(
			const ListPlnrAccRMUserUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAccRMUserUniversal(*(src.nodes[i]));
};

ListPlnrAccRMUserUniversal::~ListPlnrAccRMUserUniversal() {
	clear();
};

void ListPlnrAccRMUserUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAccRMUserUniversal::size() const {
	return(nodes.size());
};

void ListPlnrAccRMUserUniversal::append(
			PlnrAccRMUserUniversal* rec
		) {
	nodes.push_back(rec);
};

PlnrAccRMUserUniversal* ListPlnrAccRMUserUniversal::operator[](
			const uint ix
		) {
	PlnrAccRMUserUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAccRMUserUniversal& ListPlnrAccRMUserUniversal::operator=(
			const ListPlnrAccRMUserUniversal& src
		) {
	PlnrAccRMUserUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAccRMUserUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAccRMUserUniversal::operator==(
			const ListPlnrAccRMUserUniversal& comp
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

bool ListPlnrAccRMUserUniversal::operator!=(
			const ListPlnrAccRMUserUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAccRMUserUniversal
 ******************************************************************************/

TblPlnrAccRMUserUniversal::TblPlnrAccRMUserUniversal() {
};

TblPlnrAccRMUserUniversal::~TblPlnrAccRMUserUniversal() {
};

bool TblPlnrAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblPlnrAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAccRMUserUniversal& rst
		) {
	return 0;
};

void TblPlnrAccRMUserUniversal::insertRec(
			PlnrAccRMUserUniversal* rec
		) {
};

ubigint TblPlnrAccRMUserUniversal::insertNewRec(
			PlnrAccRMUserUniversal** rec
			, const ubigint refPlnrMUser
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVAccess
		) {
	ubigint retval = 0;
	PlnrAccRMUserUniversal* _rec = NULL;

	_rec = new PlnrAccRMUserUniversal(0, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAccRMUserUniversal::appendNewRecToRst(
			ListPlnrAccRMUserUniversal& rst
			, PlnrAccRMUserUniversal** rec
			, const ubigint refPlnrMUser
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVAccess
		) {
	ubigint retval = 0;
	PlnrAccRMUserUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAccRMUserUniversal::insertRst(
			ListPlnrAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblPlnrAccRMUserUniversal::updateRec(
			PlnrAccRMUserUniversal* rec
		) {
};

void TblPlnrAccRMUserUniversal::updateRst(
			ListPlnrAccRMUserUniversal& rst
			, bool transact
		) {
};

void TblPlnrAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, PlnrAccRMUserUniversal** rec
		) {
	return false;
};

bool TblPlnrAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refPlnrMUser
			, uint unvIxPlnrVMaintable
			, ubigint unvUref
			, PlnrAccRMUserUniversal** rec
		) {
	return false;
};

ubigint TblPlnrAccRMUserUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAccRMUserUniversal& rst
		) {
	ubigint numload = 0;
	PlnrAccRMUserUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAccRMUserUniversal
 ******************************************************************************/

MyTblPlnrAccRMUserUniversal::MyTblPlnrAccRMUserUniversal() : TblPlnrAccRMUserUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAccRMUserUniversal::~MyTblPlnrAccRMUserUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAccRMUserUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAccRMUserUniversal (refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAccRMUserUniversal SET refPlnrMUser = ?, unvIxPlnrVMaintable = ?, unvUref = ?, ixPlnrVAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAccRMUserUniversal WHERE ref = ?", false);
};

bool MyTblPlnrAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrAccRMUserUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAccRMUserUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAccRMUserUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAccRMUserUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUser = atoll((char*) dbrow[1]); else _rec->refPlnrMUser = 0;
		if (dbrow[2]) _rec->unvIxPlnrVMaintable = atol((char*) dbrow[2]); else _rec->unvIxPlnrVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixPlnrVAccess = atol((char*) dbrow[4]); else _rec->ixPlnrVAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAccRMUserUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAccRMUserUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAccRMUserUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAccRMUserUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUser = atoll((char*) dbrow[1]); else rec->refPlnrMUser = 0;
			if (dbrow[2]) rec->unvIxPlnrVMaintable = atol((char*) dbrow[2]); else rec->unvIxPlnrVMaintable = 0;
			if (dbrow[3]) rec->unvUref = atoll((char*) dbrow[3]); else rec->unvUref = 0;
			if (dbrow[4]) rec->ixPlnrVAccess = atol((char*) dbrow[4]); else rec->ixPlnrVAccess = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAccRMUserUniversal::insertRec(
			PlnrAccRMUserUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxPlnrVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixPlnrVAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAccRMUserUniversal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAccRMUserUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAccRMUserUniversal::insertRst(
			ListPlnrAccRMUserUniversal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAccRMUserUniversal::updateRec(
			PlnrAccRMUserUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->unvIxPlnrVMaintable,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixPlnrVAccess,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAccRMUserUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAccRMUserUniversal / stmtUpdateRec)\n");
};

void MyTblPlnrAccRMUserUniversal::updateRst(
			ListPlnrAccRMUserUniversal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAccRMUserUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAccRMUserUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAccRMUserUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, PlnrAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAccRMUserUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refPlnrMUser
			, uint unvIxPlnrVMaintable
			, ubigint unvUref
			, PlnrAccRMUserUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess FROM TblPlnrAccRMUserUniversal WHERE refPlnrMUser = " + to_string(refPlnrMUser) + " AND unvIxPlnrVMaintable = " + to_string(unvIxPlnrVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAccRMUserUniversal
 ******************************************************************************/

PgTblPlnrAccRMUserUniversal::PgTblPlnrAccRMUserUniversal() : TblPlnrAccRMUserUniversal(), PgTable() {
};

PgTblPlnrAccRMUserUniversal::~PgTblPlnrAccRMUserUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAccRMUserUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAccRMUserUniversal_insertRec", "INSERT INTO TblPlnrAccRMUserUniversal (refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAccRMUserUniversal_updateRec", "UPDATE TblPlnrAccRMUserUniversal SET refPlnrMUser = $1, unvIxPlnrVMaintable = $2, unvUref = $3, ixPlnrVAccess = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAccRMUserUniversal_removeRecByRef", "DELETE FROM TblPlnrAccRMUserUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAccRMUserUniversal_loadRecByRef", "SELECT ref, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess FROM TblPlnrAccRMUserUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAccRMUserUniversal_loadRecByUsrMtbUnv", "SELECT ref, refPlnrMUser, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess FROM TblPlnrAccRMUserUniversal WHERE refPlnrMUser = $1 AND unvIxPlnrVMaintable = $2 AND unvUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAccRMUserUniversal::loadRec(
			PGresult* res
			, PlnrAccRMUserUniversal** rec
		) {
	char* ptr;

	PlnrAccRMUserUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAccRMUserUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "unvixplnrvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixplnrvaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxPlnrVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixPlnrVAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAccRMUserUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAccRMUserUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAccRMUserUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "unvixplnrvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixplnrvaccess")
		};

		while (numread < numrow) {
			rec = new PlnrAccRMUserUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->unvIxPlnrVMaintable = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->unvUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixPlnrVAccess = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAccRMUserUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAccRMUserUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAccRMUserUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrAccRMUserUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAccRMUserUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAccRMUserUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAccRMUserUniversal::insertRec(
			PlnrAccRMUserUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _unvIxPlnrVMaintable = htonl(rec->unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixPlnrVAccess = htonl(rec->ixPlnrVAccess);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_unvIxPlnrVMaintable,
		(char*) &_unvUref,
		(char*) &_ixPlnrVAccess
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrAccRMUserUniversal_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAccRMUserUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAccRMUserUniversal::insertRst(
			ListPlnrAccRMUserUniversal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAccRMUserUniversal::updateRec(
			PlnrAccRMUserUniversal* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	uint _unvIxPlnrVMaintable = htonl(rec->unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixPlnrVAccess = htonl(rec->ixPlnrVAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_unvIxPlnrVMaintable,
		(char*) &_unvUref,
		(char*) &_ixPlnrVAccess,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrAccRMUserUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAccRMUserUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAccRMUserUniversal::updateRst(
			ListPlnrAccRMUserUniversal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAccRMUserUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAccRMUserUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAccRMUserUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAccRMUserUniversal::loadRecByRef(
			ubigint ref
			, PlnrAccRMUserUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAccRMUserUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrAccRMUserUniversal::loadRecByUsrMtbUnv(
			ubigint refPlnrMUser
			, uint unvIxPlnrVMaintable
			, ubigint unvUref
			, PlnrAccRMUserUniversal** rec
		) {
	ubigint _refPlnrMUser = htonl64(refPlnrMUser);
	uint _unvIxPlnrVMaintable = htonl(unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_unvIxPlnrVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblPlnrAccRMUserUniversal_loadRecByUsrMtbUnv", 3, vals, l, f, rec);
};

// IP pgTbl --- END

