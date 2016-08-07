/**
  * \file PlnrRMProjectMTapeout.cpp
  * database access for table TblPlnrRMProjectMTapeout (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMProjectMTapeout.h"

/******************************************************************************
 class PlnrRMProjectMTapeout
 ******************************************************************************/

PlnrRMProjectMTapeout::PlnrRMProjectMTapeout(
			const ubigint ref
			, const ubigint refPlnrMProject
			, const ubigint refPlnrMTapeout
		) {

	this->ref = ref;
	this->refPlnrMProject = refPlnrMProject;
	this->refPlnrMTapeout = refPlnrMTapeout;
};

bool PlnrRMProjectMTapeout::operator==(
			const PlnrRMProjectMTapeout& comp
		) {
	return false;
};

bool PlnrRMProjectMTapeout::operator!=(
			const PlnrRMProjectMTapeout& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMProjectMTapeout
 ******************************************************************************/

ListPlnrRMProjectMTapeout::ListPlnrRMProjectMTapeout() {
};

ListPlnrRMProjectMTapeout::ListPlnrRMProjectMTapeout(
			const ListPlnrRMProjectMTapeout& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMProjectMTapeout(*(src.nodes[i]));
};

ListPlnrRMProjectMTapeout::~ListPlnrRMProjectMTapeout() {
	clear();
};

void ListPlnrRMProjectMTapeout::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMProjectMTapeout::size() const {
	return(nodes.size());
};

void ListPlnrRMProjectMTapeout::append(
			PlnrRMProjectMTapeout* rec
		) {
	nodes.push_back(rec);
};

PlnrRMProjectMTapeout* ListPlnrRMProjectMTapeout::operator[](
			const uint ix
		) {
	PlnrRMProjectMTapeout* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMProjectMTapeout& ListPlnrRMProjectMTapeout::operator=(
			const ListPlnrRMProjectMTapeout& src
		) {
	PlnrRMProjectMTapeout* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMProjectMTapeout(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMProjectMTapeout::operator==(
			const ListPlnrRMProjectMTapeout& comp
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

bool ListPlnrRMProjectMTapeout::operator!=(
			const ListPlnrRMProjectMTapeout& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMProjectMTapeout
 ******************************************************************************/

TblPlnrRMProjectMTapeout::TblPlnrRMProjectMTapeout() {
};

TblPlnrRMProjectMTapeout::~TblPlnrRMProjectMTapeout() {
};

bool TblPlnrRMProjectMTapeout::loadRecBySQL(
			const string& sqlstr
			, PlnrRMProjectMTapeout** rec
		) {
	return false;
};

ubigint TblPlnrRMProjectMTapeout::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMProjectMTapeout& rst
		) {
	return 0;
};

void TblPlnrRMProjectMTapeout::insertRec(
			PlnrRMProjectMTapeout* rec
		) {
};

ubigint TblPlnrRMProjectMTapeout::insertNewRec(
			PlnrRMProjectMTapeout** rec
			, const ubigint refPlnrMProject
			, const ubigint refPlnrMTapeout
		) {
	ubigint retval = 0;
	PlnrRMProjectMTapeout* _rec = NULL;

	_rec = new PlnrRMProjectMTapeout(0, refPlnrMProject, refPlnrMTapeout);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMProjectMTapeout::appendNewRecToRst(
			ListPlnrRMProjectMTapeout& rst
			, PlnrRMProjectMTapeout** rec
			, const ubigint refPlnrMProject
			, const ubigint refPlnrMTapeout
		) {
	ubigint retval = 0;
	PlnrRMProjectMTapeout* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMProject, refPlnrMTapeout);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMProjectMTapeout::insertRst(
			ListPlnrRMProjectMTapeout& rst
			, bool transact
		) {
};

void TblPlnrRMProjectMTapeout::updateRec(
			PlnrRMProjectMTapeout* rec
		) {
};

void TblPlnrRMProjectMTapeout::updateRst(
			ListPlnrRMProjectMTapeout& rst
			, bool transact
		) {
};

void TblPlnrRMProjectMTapeout::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMProjectMTapeout::loadRecByRef(
			ubigint ref
			, PlnrRMProjectMTapeout** rec
		) {
	return false;
};

ubigint TblPlnrRMProjectMTapeout::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMProjectMTapeout& rst
		) {
	ubigint numload = 0;
	PlnrRMProjectMTapeout* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMProjectMTapeout
 ******************************************************************************/

MyTblPlnrRMProjectMTapeout::MyTblPlnrRMProjectMTapeout() : TblPlnrRMProjectMTapeout(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMProjectMTapeout::~MyTblPlnrRMProjectMTapeout() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMProjectMTapeout::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMProjectMTapeout (refPlnrMProject, refPlnrMTapeout) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMProjectMTapeout SET refPlnrMProject = ?, refPlnrMTapeout = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMProjectMTapeout WHERE ref = ?", false);
};

bool MyTblPlnrRMProjectMTapeout::loadRecBySQL(
			const string& sqlstr
			, PlnrRMProjectMTapeout** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMProjectMTapeout* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMProjectMTapeout / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMProjectMTapeout();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMProject = atoll((char*) dbrow[1]); else _rec->refPlnrMProject = 0;
		if (dbrow[2]) _rec->refPlnrMTapeout = atoll((char*) dbrow[2]); else _rec->refPlnrMTapeout = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMProjectMTapeout::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMProjectMTapeout& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMProjectMTapeout* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMProjectMTapeout / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMProjectMTapeout();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMProject = atoll((char*) dbrow[1]); else rec->refPlnrMProject = 0;
			if (dbrow[2]) rec->refPlnrMTapeout = atoll((char*) dbrow[2]); else rec->refPlnrMTapeout = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMProjectMTapeout::insertRec(
			PlnrRMProjectMTapeout* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMProject,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMTapeout,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMProjectMTapeout / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMProjectMTapeout / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMProjectMTapeout::insertRst(
			ListPlnrRMProjectMTapeout& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMProjectMTapeout::updateRec(
			PlnrRMProjectMTapeout* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMProject,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMTapeout,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMProjectMTapeout / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMProjectMTapeout / stmtUpdateRec)\n");
};

void MyTblPlnrRMProjectMTapeout::updateRst(
			ListPlnrRMProjectMTapeout& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMProjectMTapeout::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMProjectMTapeout / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMProjectMTapeout / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMProjectMTapeout::loadRecByRef(
			ubigint ref
			, PlnrRMProjectMTapeout** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMProjectMTapeout WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMProjectMTapeout
 ******************************************************************************/

PgTblPlnrRMProjectMTapeout::PgTblPlnrRMProjectMTapeout() : TblPlnrRMProjectMTapeout(), PgTable() {
};

PgTblPlnrRMProjectMTapeout::~PgTblPlnrRMProjectMTapeout() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMProjectMTapeout::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMProjectMTapeout_insertRec", "INSERT INTO TblPlnrRMProjectMTapeout (refPlnrMProject, refPlnrMTapeout) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMProjectMTapeout_updateRec", "UPDATE TblPlnrRMProjectMTapeout SET refPlnrMProject = $1, refPlnrMTapeout = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMProjectMTapeout_removeRecByRef", "DELETE FROM TblPlnrRMProjectMTapeout WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMProjectMTapeout_loadRecByRef", "SELECT ref, refPlnrMProject, refPlnrMTapeout FROM TblPlnrRMProjectMTapeout WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrRMProjectMTapeout::loadRec(
			PGresult* res
			, PlnrRMProjectMTapeout** rec
		) {
	char* ptr;

	PlnrRMProjectMTapeout* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMProjectMTapeout();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "refplnrmtapeout")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMProject = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMTapeout = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMProjectMTapeout::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMProjectMTapeout& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMProjectMTapeout* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmproject"),
			PQfnumber(res, "refplnrmtapeout")
		};

		while (numread < numrow) {
			rec = new PlnrRMProjectMTapeout();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMProject = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMTapeout = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMProjectMTapeout::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMProjectMTapeout** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMProjectMTapeout / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMProjectMTapeout::loadRecBySQL(
			const string& sqlstr
			, PlnrRMProjectMTapeout** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMProjectMTapeout::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMProjectMTapeout& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMProjectMTapeout::insertRec(
			PlnrRMProjectMTapeout* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);

	const char* vals[] = {
		(char*) &_refPlnrMProject,
		(char*) &_refPlnrMTapeout
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMProjectMTapeout_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMProjectMTapeout_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMProjectMTapeout::insertRst(
			ListPlnrRMProjectMTapeout& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMProjectMTapeout::updateRec(
			PlnrRMProjectMTapeout* rec
		) {
	PGresult* res;

	ubigint _refPlnrMProject = htonl64(rec->refPlnrMProject);
	ubigint _refPlnrMTapeout = htonl64(rec->refPlnrMTapeout);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMProject,
		(char*) &_refPlnrMTapeout,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMProjectMTapeout_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMProjectMTapeout_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMProjectMTapeout::updateRst(
			ListPlnrRMProjectMTapeout& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMProjectMTapeout::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMProjectMTapeout_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMProjectMTapeout_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMProjectMTapeout::loadRecByRef(
			ubigint ref
			, PlnrRMProjectMTapeout** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMProjectMTapeout_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

