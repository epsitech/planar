/**
  * \file PlnrMUsergroup.cpp
  * database access for table TblPlnrMUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMUsergroup.h"

/******************************************************************************
 class PlnrMUsergroup
 ******************************************************************************/

PlnrMUsergroup::PlnrMUsergroup(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->sref = sref;
	this->Comment = Comment;
};

bool PlnrMUsergroup::operator==(
			const PlnrMUsergroup& comp
		) {
	return false;
};

bool PlnrMUsergroup::operator!=(
			const PlnrMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMUsergroup
 ******************************************************************************/

ListPlnrMUsergroup::ListPlnrMUsergroup() {
};

ListPlnrMUsergroup::ListPlnrMUsergroup(
			const ListPlnrMUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMUsergroup(*(src.nodes[i]));
};

ListPlnrMUsergroup::~ListPlnrMUsergroup() {
	clear();
};

void ListPlnrMUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMUsergroup::size() const {
	return(nodes.size());
};

void ListPlnrMUsergroup::append(
			PlnrMUsergroup* rec
		) {
	nodes.push_back(rec);
};

PlnrMUsergroup* ListPlnrMUsergroup::operator[](
			const uint ix
		) {
	PlnrMUsergroup* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMUsergroup& ListPlnrMUsergroup::operator=(
			const ListPlnrMUsergroup& src
		) {
	PlnrMUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMUsergroup::operator==(
			const ListPlnrMUsergroup& comp
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

bool ListPlnrMUsergroup::operator!=(
			const ListPlnrMUsergroup& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMUsergroup
 ******************************************************************************/

TblPlnrMUsergroup::TblPlnrMUsergroup() {
};

TblPlnrMUsergroup::~TblPlnrMUsergroup() {
};

bool TblPlnrMUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrMUsergroup** rec
		) {
	return false;
};

ubigint TblPlnrMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMUsergroup& rst
		) {
	return 0;
};

void TblPlnrMUsergroup::insertRec(
			PlnrMUsergroup* rec
		) {
};

ubigint TblPlnrMUsergroup::insertNewRec(
			PlnrMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMUsergroup* _rec = NULL;

	_rec = new PlnrMUsergroup(0, grp, own, sref, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMUsergroup::appendNewRecToRst(
			ListPlnrMUsergroup& rst
			, PlnrMUsergroup** rec
			, const ubigint grp
			, const ubigint own
			, const string sref
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, sref, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMUsergroup::insertRst(
			ListPlnrMUsergroup& rst
			, bool transact
		) {
};

void TblPlnrMUsergroup::updateRec(
			PlnrMUsergroup* rec
		) {
};

void TblPlnrMUsergroup::updateRst(
			ListPlnrMUsergroup& rst
			, bool transact
		) {
};

void TblPlnrMUsergroup::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMUsergroup::loadRecByRef(
			ubigint ref
			, PlnrMUsergroup** rec
		) {
	return false;
};

bool TblPlnrMUsergroup::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMUsergroup::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMUsergroup& rst
		) {
	ubigint numload = 0;
	PlnrMUsergroup* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMUsergroup
 ******************************************************************************/

MyTblPlnrMUsergroup::MyTblPlnrMUsergroup() : TblPlnrMUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMUsergroup::~MyTblPlnrMUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMUsergroup (grp, own, sref, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMUsergroup SET grp = ?, own = ?, sref = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMUsergroup WHERE ref = ?", false);
};

bool MyTblPlnrMUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrMUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMUsergroup();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->sref.assign(dbrow[3], dblengths[3]); else _rec->sref = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMUsergroup();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->sref.assign(dbrow[3], dblengths[3]); else rec->sref = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMUsergroup::insertRec(
			PlnrMUsergroup* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMUsergroup / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMUsergroup / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMUsergroup::insertRst(
			ListPlnrMUsergroup& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMUsergroup::updateRec(
			PlnrMUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->sref.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMUsergroup / stmtUpdateRec)\n");
};

void MyTblPlnrMUsergroup::updateRst(
			ListPlnrMUsergroup& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMUsergroup::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMUsergroup / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMUsergroup / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMUsergroup::loadRecByRef(
			ubigint ref
			, PlnrMUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMUsergroup WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMUsergroup::loadSrfByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT sref FROM TblPlnrMUsergroup WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMUsergroup
 ******************************************************************************/

PgTblPlnrMUsergroup::PgTblPlnrMUsergroup() : TblPlnrMUsergroup(), PgTable() {
};

PgTblPlnrMUsergroup::~PgTblPlnrMUsergroup() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMUsergroup_insertRec", "INSERT INTO TblPlnrMUsergroup (grp, own, sref, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMUsergroup_updateRec", "UPDATE TblPlnrMUsergroup SET grp = $1, own = $2, sref = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMUsergroup_removeRecByRef", "DELETE FROM TblPlnrMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMUsergroup_loadRecByRef", "SELECT ref, grp, own, sref, Comment FROM TblPlnrMUsergroup WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMUsergroup_loadSrfByRef", "SELECT sref FROM TblPlnrMUsergroup WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMUsergroup::loadRec(
			PGresult* res
			, PlnrMUsergroup** rec
		) {
	char* ptr;

	PlnrMUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMUsergroup();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMUsergroup* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrMUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrMUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMUsergroup::insertRec(
			PlnrMUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrMUsergroup_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMUsergroup::insertRst(
			ListPlnrMUsergroup& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMUsergroup::updateRec(
			PlnrMUsergroup* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		rec->sref.c_str(),
		rec->Comment.c_str(),
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

	res = PQexecPrepared(dbs, "TblPlnrMUsergroup_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMUsergroup::updateRst(
			ListPlnrMUsergroup& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMUsergroup::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMUsergroup_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMUsergroup_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMUsergroup::loadRecByRef(
			ubigint ref
			, PlnrMUsergroup** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMUsergroup_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMUsergroup::loadSrfByRef(
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

	return loadStringByStmt("TblPlnrMUsergroup_loadSrfByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

