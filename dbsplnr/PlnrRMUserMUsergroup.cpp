/**
  * \file PlnrRMUserMUsergroup.cpp
  * database access for table TblPlnrRMUserMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMUserMUsergroup.h"

/******************************************************************************
 class PlnrRMUserMUsergroup
 ******************************************************************************/

PlnrRMUserMUsergroup::PlnrRMUserMUsergroup(
			const ubigint ref
			, const ubigint refPlnrMUser
			, const ubigint refPlnrMUsergroup
			, const uint ixPlnrVUserlevel
		) {

	this->ref = ref;
	this->refPlnrMUser = refPlnrMUser;
	this->refPlnrMUsergroup = refPlnrMUsergroup;
	this->ixPlnrVUserlevel = ixPlnrVUserlevel;
};

bool PlnrRMUserMUsergroup::operator==(
			const PlnrRMUserMUsergroup& comp
		) {
	return false;
};

bool PlnrRMUserMUsergroup::operator!=(
			const PlnrRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMUserMUsergroup
 ******************************************************************************/

ListPlnrRMUserMUsergroup::ListPlnrRMUserMUsergroup() {
};

ListPlnrRMUserMUsergroup::ListPlnrRMUserMUsergroup(
			const ListPlnrRMUserMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMUserMUsergroup(*(src.nodes[i]));
};

ListPlnrRMUserMUsergroup::~ListPlnrRMUserMUsergroup() {
	clear();
};

void ListPlnrRMUserMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMUserMUsergroup::size() const {
	return(nodes.size());
};

void ListPlnrRMUserMUsergroup::append(
			PlnrRMUserMUsergroup* rec
		) {
	nodes.push_back(rec);
};

PlnrRMUserMUsergroup* ListPlnrRMUserMUsergroup::operator[](
			const uint ix
		) {
	PlnrRMUserMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMUserMUsergroup& ListPlnrRMUserMUsergroup::operator=(
			const ListPlnrRMUserMUsergroup& src
		) {
	PlnrRMUserMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMUserMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMUserMUsergroup::operator==(
			const ListPlnrRMUserMUsergroup& comp
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

bool ListPlnrRMUserMUsergroup::operator!=(
			const ListPlnrRMUserMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMUserMUsergroup
 ******************************************************************************/

TblPlnrRMUserMUsergroup::TblPlnrRMUserMUsergroup() {
};

TblPlnrRMUserMUsergroup::~TblPlnrRMUserMUsergroup() {
};

bool TblPlnrRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblPlnrRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	return 0;
};

void TblPlnrRMUserMUsergroup::insertRec(
			PlnrRMUserMUsergroup* rec
		) {
};

ubigint TblPlnrRMUserMUsergroup::insertNewRec(
			PlnrRMUserMUsergroup** rec
			, const ubigint refPlnrMUser
			, const ubigint refPlnrMUsergroup
			, const uint ixPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrRMUserMUsergroup* _rec = NULL;

	_rec = new PlnrRMUserMUsergroup(0, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMUserMUsergroup::appendNewRecToRst(
			ListPlnrRMUserMUsergroup& rst
			, PlnrRMUserMUsergroup** rec
			, const ubigint refPlnrMUser
			, const ubigint refPlnrMUsergroup
			, const uint ixPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrRMUserMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMUserMUsergroup::insertRst(
			ListPlnrRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblPlnrRMUserMUsergroup::updateRec(
			PlnrRMUserMUsergroup* rec
		) {
};

void TblPlnrRMUserMUsergroup::updateRst(
			ListPlnrRMUserMUsergroup& rst
			, bool transact
		) {
};

void TblPlnrRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, PlnrRMUserMUsergroup** rec
		) {
	return false;
};

ubigint TblPlnrRMUserMUsergroup::loadRstByUsg(
			ubigint refPlnrMUsergroup
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblPlnrRMUserMUsergroup::loadRstByUsr(
			ubigint refPlnrMUser
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	return 0;
};

ubigint TblPlnrRMUserMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	ubigint numload = 0;
	PlnrRMUserMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMUserMUsergroup
 ******************************************************************************/

MyTblPlnrRMUserMUsergroup::MyTblPlnrRMUserMUsergroup() : TblPlnrRMUserMUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMUserMUsergroup::~MyTblPlnrRMUserMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMUserMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMUserMUsergroup (refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMUserMUsergroup SET refPlnrMUser = ?, refPlnrMUsergroup = ?, ixPlnrVUserlevel = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMUserMUsergroup WHERE ref = ?", false);
};

bool MyTblPlnrRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrRMUserMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMUserMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMUserMUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMUserMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMUser = atoll((char*) dbrow[1]); else _rec->refPlnrMUser = 0;
		if (dbrow[2]) _rec->refPlnrMUsergroup = atoll((char*) dbrow[2]); else _rec->refPlnrMUsergroup = 0;
		if (dbrow[3]) _rec->ixPlnrVUserlevel = atol((char*) dbrow[3]); else _rec->ixPlnrVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMUserMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMUserMUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMUserMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMUser = atoll((char*) dbrow[1]); else rec->refPlnrMUser = 0;
			if (dbrow[2]) rec->refPlnrMUsergroup = atoll((char*) dbrow[2]); else rec->refPlnrMUsergroup = 0;
			if (dbrow[3]) rec->ixPlnrVUserlevel = atol((char*) dbrow[3]); else rec->ixPlnrVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMUserMUsergroup::insertRec(
			PlnrRMUserMUsergroup* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMUsergroup,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->ixPlnrVUserlevel,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMUserMUsergroup / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMUserMUsergroup / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMUserMUsergroup::insertRst(
			ListPlnrRMUserMUsergroup& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMUserMUsergroup::updateRec(
			PlnrRMUserMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMUser,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMUsergroup,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->ixPlnrVUserlevel,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMUserMUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMUserMUsergroup / stmtUpdateRec)\n");
};

void MyTblPlnrRMUserMUsergroup::updateRst(
			ListPlnrRMUserMUsergroup& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMUserMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMUserMUsergroup / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMUserMUsergroup / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, PlnrRMUserMUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMUserMUsergroup WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrRMUserMUsergroup::loadRstByUsg(
			ubigint refPlnrMUsergroup
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel FROM TblPlnrRMUserMUsergroup WHERE refPlnrMUsergroup = " + to_string(refPlnrMUsergroup) + "", append, rst);
};

ubigint MyTblPlnrRMUserMUsergroup::loadRstByUsr(
			ubigint refPlnrMUser
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel FROM TblPlnrRMUserMUsergroup WHERE refPlnrMUser = " + to_string(refPlnrMUser) + "", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMUserMUsergroup
 ******************************************************************************/

PgTblPlnrRMUserMUsergroup::PgTblPlnrRMUserMUsergroup() : TblPlnrRMUserMUsergroup(), PgTable() {
};

PgTblPlnrRMUserMUsergroup::~PgTblPlnrRMUserMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMUserMUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMUserMUsergroup_insertRec", "INSERT INTO TblPlnrRMUserMUsergroup (refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMUserMUsergroup_updateRec", "UPDATE TblPlnrRMUserMUsergroup SET refPlnrMUser = $1, refPlnrMUsergroup = $2, ixPlnrVUserlevel = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMUserMUsergroup_removeRecByRef", "DELETE FROM TblPlnrRMUserMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMUserMUsergroup_loadRecByRef", "SELECT ref, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel FROM TblPlnrRMUserMUsergroup WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrRMUserMUsergroup_loadRstByUsg", "SELECT ref, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel FROM TblPlnrRMUserMUsergroup WHERE refPlnrMUsergroup = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMUserMUsergroup_loadRstByUsr", "SELECT ref, refPlnrMUser, refPlnrMUsergroup, ixPlnrVUserlevel FROM TblPlnrRMUserMUsergroup WHERE refPlnrMUser = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrRMUserMUsergroup::loadRec(
			PGresult* res
			, PlnrRMUserMUsergroup** rec
		) {
	char* ptr;

	PlnrRMUserMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMUserMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "ixplnrvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMUsergroup = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ixPlnrVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMUserMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMUserMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmuser"),
			PQfnumber(res, "refplnrmusergroup"),
			PQfnumber(res, "ixplnrvuserlevel")
		};

		while (numread < numrow) {
			rec = new PlnrRMUserMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMUsergroup = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ixPlnrVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMUserMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUserMUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrRMUserMUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUserMUsergroup / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrRMUserMUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrRMUserMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMUserMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMUserMUsergroup::insertRec(
			PlnrRMUserMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_refPlnrMUsergroup,
		(char*) &_ixPlnrVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMUserMUsergroup_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUserMUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMUserMUsergroup::insertRst(
			ListPlnrRMUserMUsergroup& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMUserMUsergroup::updateRec(
			PlnrRMUserMUsergroup* rec
		) {
	PGresult* res;

	ubigint _refPlnrMUser = htonl64(rec->refPlnrMUser);
	ubigint _refPlnrMUsergroup = htonl64(rec->refPlnrMUsergroup);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMUser,
		(char*) &_refPlnrMUsergroup,
		(char*) &_ixPlnrVUserlevel,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMUserMUsergroup_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUserMUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMUserMUsergroup::updateRst(
			ListPlnrRMUserMUsergroup& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMUserMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMUserMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMUserMUsergroup_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMUserMUsergroup::loadRecByRef(
			ubigint ref
			, PlnrRMUserMUsergroup** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMUserMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrRMUserMUsergroup::loadRstByUsg(
			ubigint refPlnrMUsergroup
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	ubigint _refPlnrMUsergroup = htonl64(refPlnrMUsergroup);

	const char* vals[] = {
		(char*) &_refPlnrMUsergroup
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrRMUserMUsergroup_loadRstByUsg", 1, vals, l, f, append, rst);
};

ubigint PgTblPlnrRMUserMUsergroup::loadRstByUsr(
			ubigint refPlnrMUser
			, const bool append
			, ListPlnrRMUserMUsergroup& rst
		) {
	ubigint _refPlnrMUser = htonl64(refPlnrMUser);

	const char* vals[] = {
		(char*) &_refPlnrMUser
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrRMUserMUsergroup_loadRstByUsr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

