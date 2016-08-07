/**
  * \file PlnrRMUsergroupUniversal.cpp
  * database access for table TblPlnrRMUsergroupUniversal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMUsergroupUniversal.h"

/******************************************************************************
 class PlnrRMUsergroupUniversal
 ******************************************************************************/

PlnrRMUsergroupUniversal::PlnrRMUsergroupUniversal(
			const ubigint ref
			, const ubigint refPlnrMUsergroup
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVAccess
		) {

	this->ref = ref;
	this->refPlnrMUsergroup = refPlnrMUsergroup;
	this->unvIxPlnrVMaintable = unvIxPlnrVMaintable;
	this->unvUref = unvUref;
	this->ixPlnrVAccess = ixPlnrVAccess;
};

bool PlnrRMUsergroupUniversal::operator==(
			const PlnrRMUsergroupUniversal& comp
		) {
	return false;
};

bool PlnrRMUsergroupUniversal::operator!=(
			const PlnrRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMUsergroupUniversal
 ******************************************************************************/

ListPlnrRMUsergroupUniversal::ListPlnrRMUsergroupUniversal() {
};

ListPlnrRMUsergroupUniversal::ListPlnrRMUsergroupUniversal(
			const ListPlnrRMUsergroupUniversal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMUsergroupUniversal(*(src.nodes[i]));
};

ListPlnrRMUsergroupUniversal::~ListPlnrRMUsergroupUniversal() {
	clear();
};

void ListPlnrRMUsergroupUniversal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMUsergroupUniversal::size() const {
	return(nodes.size());
};

void ListPlnrRMUsergroupUniversal::append(
			PlnrRMUsergroupUniversal* rec
		) {
	nodes.push_back(rec);
};

PlnrRMUsergroupUniversal* ListPlnrRMUsergroupUniversal::operator[](
			const uint ix
		) {
	PlnrRMUsergroupUniversal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMUsergroupUniversal& ListPlnrRMUsergroupUniversal::operator=(
			const ListPlnrRMUsergroupUniversal& src
		) {
	PlnrRMUsergroupUniversal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMUsergroupUniversal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMUsergroupUniversal::operator==(
			const ListPlnrRMUsergroupUniversal& comp
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

bool ListPlnrRMUsergroupUniversal::operator!=(
			const ListPlnrRMUsergroupUniversal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMUsergroupUniversal
 ******************************************************************************/

TblPlnrRMUsergroupUniversal::TblPlnrRMUsergroupUniversal() {
};

TblPlnrRMUsergroupUniversal::~TblPlnrRMUsergroupUniversal() {
};

bool TblPlnrRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblPlnrRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMUsergroupUniversal& rst
		) {
	return 0;
};

void TblPlnrRMUsergroupUniversal::insertRec(
			PlnrRMUsergroupUniversal* rec
		) {
};

ubigint TblPlnrRMUsergroupUniversal::insertNewRec(
			PlnrRMUsergroupUniversal** rec
			, const ubigint refPlnrMUsergroup
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVAccess
		) {
	ubigint retval = 0;
	PlnrRMUsergroupUniversal* _rec = NULL;

	_rec = new PlnrRMUsergroupUniversal(0, refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMUsergroupUniversal::appendNewRecToRst(
			ListPlnrRMUsergroupUniversal& rst
			, PlnrRMUsergroupUniversal** rec
			, const ubigint refPlnrMUsergroup
			, const uint unvIxPlnrVMaintable
			, const ubigint unvUref
			, const uint ixPlnrVAccess
		) {
	ubigint retval = 0;
	PlnrRMUsergroupUniversal* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMUsergroupUniversal::insertRst(
			ListPlnrRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblPlnrRMUsergroupUniversal::updateRec(
			PlnrRMUsergroupUniversal* rec
		) {
};

void TblPlnrRMUsergroupUniversal::updateRst(
			ListPlnrRMUsergroupUniversal& rst
			, bool transact
		) {
};

void TblPlnrRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, PlnrRMUsergroupUniversal** rec
		) {
	return false;
};

bool TblPlnrRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refPlnrMUsergroup
			, uint unvIxPlnrVMaintable
			, ubigint unvUref
			, PlnrRMUsergroupUniversal** rec
		) {
	return false;
};

ubigint TblPlnrRMUsergroupUniversal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMUsergroupUniversal& rst
		) {
	ubigint numload = 0;
	PlnrRMUsergroupUniversal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMUsergroupUniversal
 ******************************************************************************/

MyTblPlnrRMUsergroupUniversal::MyTblPlnrRMUsergroupUniversal() : TblPlnrRMUsergroupUniversal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMUsergroupUniversal::~MyTblPlnrRMUsergroupUniversal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMUsergroupUniversal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMUsergroupUniversal (refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMUsergroupUniversal SET refPlnrMUsergroup = ?, unvIxPlnrVMaintable = ?, unvUref = ?, ixPlnrVAccess = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMUsergroupUniversal WHERE ref = ?", false);
};

bool MyTblPlnrRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrRMUsergroupUniversal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMUsergroupUniversal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMUsergroupUniversal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMUsergroupUniversal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUsergroup = atoll((char*) dbrow[1]); else _rec->refPlnrMUsergroup = 0;
		if (dbrow[2]) _rec->unvIxPlnrVMaintable = atol((char*) dbrow[2]); else _rec->unvIxPlnrVMaintable = 0;
		if (dbrow[3]) _rec->unvUref = atoll((char*) dbrow[3]); else _rec->unvUref = 0;
		if (dbrow[4]) _rec->ixPlnrVAccess = atol((char*) dbrow[4]); else _rec->ixPlnrVAccess = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMUsergroupUniversal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMUsergroupUniversal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMUsergroupUniversal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUsergroup = atoll((char*) dbrow[1]); else rec->refPlnrMUsergroup = 0;
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

void MyTblPlnrRMUsergroupUniversal::insertRec(
			PlnrRMUsergroupUniversal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUsergroup,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->unvIxPlnrVMaintable,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixPlnrVAccess,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMUsergroupUniversal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMUsergroupUniversal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMUsergroupUniversal::insertRst(
			ListPlnrRMUsergroupUniversal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMUsergroupUniversal::updateRec(
			PlnrRMUsergroupUniversal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUsergroup,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->unvIxPlnrVMaintable,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->unvUref,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixPlnrVAccess,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMUsergroupUniversal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMUsergroupUniversal / stmtUpdateRec)\n");
};

void MyTblPlnrRMUsergroupUniversal::updateRst(
			ListPlnrRMUsergroupUniversal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMUsergroupUniversal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMUsergroupUniversal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMUsergroupUniversal / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, PlnrRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMUsergroupUniversal WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refPlnrMUsergroup
			, uint unvIxPlnrVMaintable
			, ubigint unvUref
			, PlnrRMUsergroupUniversal** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess FROM TblPlnrRMUsergroupUniversal WHERE refPlnrMUsergroup = " + to_string(refPlnrMUsergroup) + " AND unvIxPlnrVMaintable = " + to_string(unvIxPlnrVMaintable) + " AND unvUref = " + to_string(unvUref) + "", rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMUsergroupUniversal
 ******************************************************************************/

PgTblPlnrRMUsergroupUniversal::PgTblPlnrRMUsergroupUniversal() : TblPlnrRMUsergroupUniversal(), PgTable() {
};

PgTblPlnrRMUsergroupUniversal::~PgTblPlnrRMUsergroupUniversal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMUsergroupUniversal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMUsergroupUniversal_insertRec", "INSERT INTO TblPlnrRMUsergroupUniversal (refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMUsergroupUniversal_updateRec", "UPDATE TblPlnrRMUsergroupUniversal SET refPlnrMUsergroup = $1, unvIxPlnrVMaintable = $2, unvUref = $3, ixPlnrVAccess = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMUsergroupUniversal_removeRecByRef", "DELETE FROM TblPlnrRMUsergroupUniversal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMUsergroupUniversal_loadRecByRef", "SELECT ref, refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess FROM TblPlnrRMUsergroupUniversal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrRMUsergroupUniversal_loadRecByUsgMtbUnv", "SELECT ref, refPlnrMUsergroup, unvIxPlnrVMaintable, unvUref, ixPlnrVAccess FROM TblPlnrRMUsergroupUniversal WHERE refPlnrMUsergroup = $1 AND unvIxPlnrVMaintable = $2 AND unvUref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrRMUsergroupUniversal::loadRec(
			PGresult* res
			, PlnrRMUsergroupUniversal** rec
		) {
	char* ptr;

	PlnrRMUsergroupUniversal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMUsergroupUniversal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "unvixplnrvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixplnrvaccess")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->unvIxPlnrVMaintable = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->unvUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixPlnrVAccess = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMUsergroupUniversal::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMUsergroupUniversal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMUsergroupUniversal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "unvixplnrvmaintable"),
			PQfnumber(res, "unvuref"),
			PQfnumber(res, "ixplnrvaccess")
		};

		while (numread < numrow) {
			rec = new PlnrRMUsergroupUniversal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUsergroup = atoll(ptr);
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

bool PgTblPlnrRMUsergroupUniversal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUsergroupUniversal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMUsergroupUniversal::loadRecBySQL(
			const string& sqlstr
			, PlnrRMUsergroupUniversal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMUsergroupUniversal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMUsergroupUniversal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMUsergroupUniversal::insertRec(
			PlnrRMUsergroupUniversal* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _unvIxPlnrVMaintable = htonl(rec->unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixPlnrVAccess = htonl(rec->ixPlnrVAccess);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup,
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

	res = PQexecPrepared(dbs, "TblPlnrRMUsergroupUniversal_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUsergroupUniversal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMUsergroupUniversal::insertRst(
			ListPlnrRMUsergroupUniversal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMUsergroupUniversal::updateRec(
			PlnrRMUsergroupUniversal* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _unvIxPlnrVMaintable = htonl(rec->unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(rec->unvUref);
	uint _ixPlnrVAccess = htonl(rec->ixPlnrVAccess);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup,
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

	res = PQexecPrepared(dbs, "TblPlnrRMUsergroupUniversal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUsergroupUniversal_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMUsergroupUniversal::updateRst(
			ListPlnrRMUsergroupUniversal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMUsergroupUniversal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMUsergroupUniversal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUsergroupUniversal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMUsergroupUniversal::loadRecByRef(
			ubigint ref
			, PlnrRMUsergroupUniversal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMUsergroupUniversal_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrRMUsergroupUniversal::loadRecByUsgMtbUnv(
			ubigint refPlnrMUsergroup
			, uint unvIxPlnrVMaintable
			, ubigint unvUref
			, PlnrRMUsergroupUniversal** rec
		) {
	ubigint _refPlnrMUsergroup = htonl64(refPlnrMUsergroup);
	uint _unvIxPlnrVMaintable = htonl(unvIxPlnrVMaintable);
	ubigint _unvUref = htonl64(unvUref);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup,
		(char*) &_unvIxPlnrVMaintable,
		(char*) &_unvUref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1,1,1};

	return loadRecByStmt("TblPlnrRMUsergroupUniversal_loadRecByUsgMtbUnv", 3, vals, l, f, rec);
};

// IP pgTbl --- END

