/**
  * \file PlnrMProject.cpp
  * database access for table TblPlnrMProject (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMProject.h"

/******************************************************************************
 class PlnrMProject
 ******************************************************************************/

PlnrMProject::PlnrMProject(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->Title = Title;
	this->refJState = refJState;
	this->ixVState = ixVState;
	this->Comment = Comment;
};

bool PlnrMProject::operator==(
			const PlnrMProject& comp
		) {
	return false;
};

bool PlnrMProject::operator!=(
			const PlnrMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMProject
 ******************************************************************************/

ListPlnrMProject::ListPlnrMProject() {
};

ListPlnrMProject::ListPlnrMProject(
			const ListPlnrMProject& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMProject(*(src.nodes[i]));
};

ListPlnrMProject::~ListPlnrMProject() {
	clear();
};

void ListPlnrMProject::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMProject::size() const {
	return(nodes.size());
};

void ListPlnrMProject::append(
			PlnrMProject* rec
		) {
	nodes.push_back(rec);
};

PlnrMProject* ListPlnrMProject::operator[](
			const uint ix
		) {
	PlnrMProject* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMProject& ListPlnrMProject::operator=(
			const ListPlnrMProject& src
		) {
	PlnrMProject* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMProject(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMProject::operator==(
			const ListPlnrMProject& comp
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

bool ListPlnrMProject::operator!=(
			const ListPlnrMProject& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMProject
 ******************************************************************************/

TblPlnrMProject::TblPlnrMProject() {
};

TblPlnrMProject::~TblPlnrMProject() {
};

bool TblPlnrMProject::loadRecBySQL(
			const string& sqlstr
			, PlnrMProject** rec
		) {
	return false;
};

ubigint TblPlnrMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMProject& rst
		) {
	return 0;
};

void TblPlnrMProject::insertRec(
			PlnrMProject* rec
		) {
};

ubigint TblPlnrMProject::insertNewRec(
			PlnrMProject** rec
			, const ubigint grp
			, const ubigint own
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMProject* _rec = NULL;

	_rec = new PlnrMProject(0, grp, own, Title, refJState, ixVState, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMProject::appendNewRecToRst(
			ListPlnrMProject& rst
			, PlnrMProject** rec
			, const ubigint grp
			, const ubigint own
			, const string Title
			, const ubigint refJState
			, const uint ixVState
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMProject* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, Title, refJState, ixVState, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMProject::insertRst(
			ListPlnrMProject& rst
			, bool transact
		) {
};

void TblPlnrMProject::updateRec(
			PlnrMProject* rec
		) {
};

void TblPlnrMProject::updateRst(
			ListPlnrMProject& rst
			, bool transact
		) {
};

void TblPlnrMProject::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMProject::loadRecByRef(
			ubigint ref
			, PlnrMProject** rec
		) {
	return false;
};

bool TblPlnrMProject::loadRefByTit(
			string Title
			, ubigint& val
		) {
	return false;
};

bool TblPlnrMProject::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMProject::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMProject& rst
		) {
	ubigint numload = 0;
	PlnrMProject* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMProject
 ******************************************************************************/

MyTblPlnrMProject::MyTblPlnrMProject() : TblPlnrMProject(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMProject::~MyTblPlnrMProject() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMProject::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMProject (grp, own, Title, refJState, ixVState, Comment) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMProject SET grp = ?, own = ?, Title = ?, refJState = ?, ixVState = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMProject WHERE ref = ?", false);
};

bool MyTblPlnrMProject::loadRecBySQL(
			const string& sqlstr
			, PlnrMProject** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMProject* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMProject / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMProject();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->refJState = atoll((char*) dbrow[4]); else _rec->refJState = 0;
		if (dbrow[5]) _rec->ixVState = atol((char*) dbrow[5]); else _rec->ixVState = 0;
		if (dbrow[6]) _rec->Comment.assign(dbrow[6], dblengths[6]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMProject& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMProject* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMProject / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMProject();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->refJState = atoll((char*) dbrow[4]); else rec->refJState = 0;
			if (dbrow[5]) rec->ixVState = atol((char*) dbrow[5]); else rec->ixVState = 0;
			if (dbrow[6]) rec->Comment.assign(dbrow[6], dblengths[6]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMProject::insertRec(
			PlnrMProject* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[2] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->refJState,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVState,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMProject / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMProject / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMProject::insertRst(
			ListPlnrMProject& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMProject::updateRec(
			PlnrMProject* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[2] = rec->Title.length();
	l[5] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->refJState,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVState,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->ref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMProject / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMProject / stmtUpdateRec)\n");
};

void MyTblPlnrMProject::updateRst(
			ListPlnrMProject& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMProject::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMProject / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMProject / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMProject::loadRecByRef(
			ubigint ref
			, PlnrMProject** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMProject WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMProject::loadRefByTit(
			string Title
			, ubigint& val
		) {
	return loadUbigintBySQL("SELECT ref FROM TblPlnrMProject WHERE Title = '" + Title + "'", val);
};

bool MyTblPlnrMProject::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrMProject WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMProject
 ******************************************************************************/

PgTblPlnrMProject::PgTblPlnrMProject() : TblPlnrMProject(), PgTable() {
};

PgTblPlnrMProject::~PgTblPlnrMProject() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMProject::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMProject_insertRec", "INSERT INTO TblPlnrMProject (grp, own, Title, refJState, ixVState, Comment) VALUES ($1,$2,$3,$4,$5,$6) RETURNING ref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMProject_updateRec", "UPDATE TblPlnrMProject SET grp = $1, own = $2, Title = $3, refJState = $4, ixVState = $5, Comment = $6 WHERE ref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMProject_removeRecByRef", "DELETE FROM TblPlnrMProject WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMProject_loadRecByRef", "SELECT ref, grp, own, Title, refJState, ixVState, Comment FROM TblPlnrMProject WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMProject_loadRefByTit", "SELECT ref FROM TblPlnrMProject WHERE Title = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMProject_loadTitByRef", "SELECT Title FROM TblPlnrMProject WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMProject::loadRec(
			PGresult* res
			, PlnrMProject** rec
		) {
	char* ptr;

	PlnrMProject* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMProject();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refJState = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVState = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMProject::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMProject& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMProject* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "title"),
			PQfnumber(res, "refjstate"),
			PQfnumber(res, "ixvstate"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMProject();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refJState = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVState = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMProject::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMProject** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMProject / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMProject::loadRecBySQL(
			const string& sqlstr
			, PlnrMProject** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMProject::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMProject& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMProject::insertRec(
			PlnrMProject* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMProject_insertRec", 6, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMProject_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMProject::insertRst(
			ListPlnrMProject& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMProject::updateRec(
			PlnrMProject* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refJState = htonl64(rec->refJState);
	uint _ixVState = htonl(rec->ixVState);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->Title.c_str(),
		(char*) &_refJState,
		(char*) &_ixVState,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMProject_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMProject_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMProject::updateRst(
			ListPlnrMProject& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMProject::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMProject_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMProject_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMProject::loadRecByRef(
			ubigint ref
			, PlnrMProject** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMProject_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMProject::loadRefByTit(
			string Title
			, ubigint& val
		) {

	const char* vals[] = {
		Title.c_str()
	};
	const int l[] = {
		0
	};
	const int f[] = {0};

	return loadUbigintByStmt("TblPlnrMProject_loadRefByTit", 1, vals, l, f, val);
};

bool PgTblPlnrMProject::loadTitByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblPlnrMProject_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

