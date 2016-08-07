/**
  * \file PlnrJAVKeylistKey.cpp
  * database access for table TblPlnrJAVKeylistKey (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJAVKeylistKey.h"

/******************************************************************************
 class PlnrJAVKeylistKey
 ******************************************************************************/

PlnrJAVKeylistKey::PlnrJAVKeylistKey(
			const ubigint ref
			, const ubigint refPlnrAVKeylistKey
			, const uint x1IxPlnrVLocale
			, const string Title
			, const string Comment
		) {

	this->ref = ref;
	this->refPlnrAVKeylistKey = refPlnrAVKeylistKey;
	this->x1IxPlnrVLocale = x1IxPlnrVLocale;
	this->Title = Title;
	this->Comment = Comment;
};

bool PlnrJAVKeylistKey::operator==(
			const PlnrJAVKeylistKey& comp
		) {
	return false;
};

bool PlnrJAVKeylistKey::operator!=(
			const PlnrJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJAVKeylistKey
 ******************************************************************************/

ListPlnrJAVKeylistKey::ListPlnrJAVKeylistKey() {
};

ListPlnrJAVKeylistKey::ListPlnrJAVKeylistKey(
			const ListPlnrJAVKeylistKey& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJAVKeylistKey(*(src.nodes[i]));
};

ListPlnrJAVKeylistKey::~ListPlnrJAVKeylistKey() {
	clear();
};

void ListPlnrJAVKeylistKey::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJAVKeylistKey::size() const {
	return(nodes.size());
};

void ListPlnrJAVKeylistKey::append(
			PlnrJAVKeylistKey* rec
		) {
	nodes.push_back(rec);
};

PlnrJAVKeylistKey* ListPlnrJAVKeylistKey::operator[](
			const uint ix
		) {
	PlnrJAVKeylistKey* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJAVKeylistKey& ListPlnrJAVKeylistKey::operator=(
			const ListPlnrJAVKeylistKey& src
		) {
	PlnrJAVKeylistKey* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJAVKeylistKey(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJAVKeylistKey::operator==(
			const ListPlnrJAVKeylistKey& comp
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

bool ListPlnrJAVKeylistKey::operator!=(
			const ListPlnrJAVKeylistKey& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJAVKeylistKey
 ******************************************************************************/

TblPlnrJAVKeylistKey::TblPlnrJAVKeylistKey() {
};

TblPlnrJAVKeylistKey::~TblPlnrJAVKeylistKey() {
};

bool TblPlnrJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, PlnrJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblPlnrJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	return 0;
};

void TblPlnrJAVKeylistKey::insertRec(
			PlnrJAVKeylistKey* rec
		) {
};

ubigint TblPlnrJAVKeylistKey::insertNewRec(
			PlnrJAVKeylistKey** rec
			, const ubigint refPlnrAVKeylistKey
			, const uint x1IxPlnrVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrJAVKeylistKey* _rec = NULL;

	_rec = new PlnrJAVKeylistKey(0, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJAVKeylistKey::appendNewRecToRst(
			ListPlnrJAVKeylistKey& rst
			, PlnrJAVKeylistKey** rec
			, const ubigint refPlnrAVKeylistKey
			, const uint x1IxPlnrVLocale
			, const string Title
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrJAVKeylistKey* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJAVKeylistKey::insertRst(
			ListPlnrJAVKeylistKey& rst
			, bool transact
		) {
};

void TblPlnrJAVKeylistKey::updateRec(
			PlnrJAVKeylistKey* rec
		) {
};

void TblPlnrJAVKeylistKey::updateRst(
			ListPlnrJAVKeylistKey& rst
			, bool transact
		) {
};

void TblPlnrJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJAVKeylistKey::loadRecByRef(
			ubigint ref
			, PlnrJAVKeylistKey** rec
		) {
	return false;
};

bool TblPlnrJAVKeylistKey::loadRecByKlkLcl(
			ubigint refPlnrAVKeylistKey
			, uint x1IxPlnrVLocale
			, PlnrJAVKeylistKey** rec
		) {
	return false;
};

ubigint TblPlnrJAVKeylistKey::loadRefsByKlk(
			ubigint refPlnrAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrJAVKeylistKey::loadRstByKlk(
			ubigint refPlnrAVKeylistKey
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	return 0;
};

bool TblPlnrJAVKeylistKey::loadTitByKlkLcl(
			ubigint refPlnrAVKeylistKey
			, uint x1IxPlnrVLocale
			, string& val
		) {
	return false;
};

ubigint TblPlnrJAVKeylistKey::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	ubigint numload = 0;
	PlnrJAVKeylistKey* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJAVKeylistKey
 ******************************************************************************/

MyTblPlnrJAVKeylistKey::MyTblPlnrJAVKeylistKey() : TblPlnrJAVKeylistKey(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJAVKeylistKey::~MyTblPlnrJAVKeylistKey() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJAVKeylistKey::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJAVKeylistKey (refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJAVKeylistKey SET refPlnrAVKeylistKey = ?, x1IxPlnrVLocale = ?, Title = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJAVKeylistKey WHERE ref = ?", false);
};

bool MyTblPlnrJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, PlnrJAVKeylistKey** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJAVKeylistKey* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJAVKeylistKey / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJAVKeylistKey();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrAVKeylistKey = atoll((char*) dbrow[1]); else _rec->refPlnrAVKeylistKey = 0;
		if (dbrow[2]) _rec->x1IxPlnrVLocale = atol((char*) dbrow[2]); else _rec->x1IxPlnrVLocale = 0;
		if (dbrow[3]) _rec->Title.assign(dbrow[3], dblengths[3]); else _rec->Title = "";
		if (dbrow[4]) _rec->Comment.assign(dbrow[4], dblengths[4]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJAVKeylistKey* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJAVKeylistKey / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJAVKeylistKey();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrAVKeylistKey = atoll((char*) dbrow[1]); else rec->refPlnrAVKeylistKey = 0;
			if (dbrow[2]) rec->x1IxPlnrVLocale = atol((char*) dbrow[2]); else rec->x1IxPlnrVLocale = 0;
			if (dbrow[3]) rec->Title.assign(dbrow[3], dblengths[3]); else rec->Title = "";
			if (dbrow[4]) rec->Comment.assign(dbrow[4], dblengths[4]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJAVKeylistKey::insertRec(
			PlnrJAVKeylistKey* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrAVKeylistKey,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1IxPlnrVLocale,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJAVKeylistKey / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJAVKeylistKey / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJAVKeylistKey::insertRst(
			ListPlnrJAVKeylistKey& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJAVKeylistKey::updateRec(
			PlnrJAVKeylistKey* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[2] = rec->Title.length();
	l[3] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrAVKeylistKey,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1IxPlnrVLocale,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJAVKeylistKey / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJAVKeylistKey / stmtUpdateRec)\n");
};

void MyTblPlnrJAVKeylistKey::updateRst(
			ListPlnrJAVKeylistKey& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJAVKeylistKey::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJAVKeylistKey / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJAVKeylistKey / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJAVKeylistKey::loadRecByRef(
			ubigint ref
			, PlnrJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJAVKeylistKey WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJAVKeylistKey::loadRecByKlkLcl(
			ubigint refPlnrAVKeylistKey
			, uint x1IxPlnrVLocale
			, PlnrJAVKeylistKey** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = " + to_string(refPlnrAVKeylistKey) + " AND x1IxPlnrVLocale = " + to_string(x1IxPlnrVLocale) + "", rec);
};

ubigint MyTblPlnrJAVKeylistKey::loadRefsByKlk(
			ubigint refPlnrAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = " + to_string(refPlnrAVKeylistKey) + "", append, refs);
};

ubigint MyTblPlnrJAVKeylistKey::loadRstByKlk(
			ubigint refPlnrAVKeylistKey
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = " + to_string(refPlnrAVKeylistKey) + " ORDER BY x1IxPlnrVLocale ASC", append, rst);
};

bool MyTblPlnrJAVKeylistKey::loadTitByKlkLcl(
			ubigint refPlnrAVKeylistKey
			, uint x1IxPlnrVLocale
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = " + to_string(refPlnrAVKeylistKey) + " AND x1IxPlnrVLocale = " + to_string(x1IxPlnrVLocale) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJAVKeylistKey
 ******************************************************************************/

PgTblPlnrJAVKeylistKey::PgTblPlnrJAVKeylistKey() : TblPlnrJAVKeylistKey(), PgTable() {
};

PgTblPlnrJAVKeylistKey::~PgTblPlnrJAVKeylistKey() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJAVKeylistKey::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_insertRec", "INSERT INTO TblPlnrJAVKeylistKey (refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_updateRec", "UPDATE TblPlnrJAVKeylistKey SET refPlnrAVKeylistKey = $1, x1IxPlnrVLocale = $2, Title = $3, Comment = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_removeRecByRef", "DELETE FROM TblPlnrJAVKeylistKey WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_loadRecByRef", "SELECT ref, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment FROM TblPlnrJAVKeylistKey WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_loadRecByKlkLcl", "SELECT ref, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = $1 AND x1IxPlnrVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_loadRefsByKlk", "SELECT ref FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_loadRstByKlk", "SELECT ref, refPlnrAVKeylistKey, x1IxPlnrVLocale, Title, Comment FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = $1 ORDER BY x1IxPlnrVLocale ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJAVKeylistKey_loadTitByKlkLcl", "SELECT Title FROM TblPlnrJAVKeylistKey WHERE refPlnrAVKeylistKey = $1 AND x1IxPlnrVLocale = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJAVKeylistKey::loadRec(
			PGresult* res
			, PlnrJAVKeylistKey** rec
		) {
	char* ptr;

	PlnrJAVKeylistKey* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJAVKeylistKey();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnravkeylistkey"),
			PQfnumber(res, "x1ixplnrvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrAVKeylistKey = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1IxPlnrVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[3]));
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJAVKeylistKey::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJAVKeylistKey* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnravkeylistkey"),
			PQfnumber(res, "x1ixplnrvlocale"),
			PQfnumber(res, "title"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrJAVKeylistKey();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrAVKeylistKey = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1IxPlnrVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[3]));
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJAVKeylistKey::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJAVKeylistKey / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJAVKeylistKey::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJAVKeylistKey / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJAVKeylistKey::loadRecBySQL(
			const string& sqlstr
			, PlnrJAVKeylistKey** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJAVKeylistKey::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJAVKeylistKey::insertRec(
			PlnrJAVKeylistKey* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrAVKeylistKey = htonl64(rec->refPlnrAVKeylistKey);
	uint _x1IxPlnrVLocale = htonl(rec->x1IxPlnrVLocale);

	const char* vals[] = {
		(char*) &_refPlnrAVKeylistKey,
		(char*) &_x1IxPlnrVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrJAVKeylistKey_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJAVKeylistKey_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJAVKeylistKey::insertRst(
			ListPlnrJAVKeylistKey& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJAVKeylistKey::updateRec(
			PlnrJAVKeylistKey* rec
		) {
	PGresult* res;

	ubigint _refPlnrAVKeylistKey = htonl64(rec->refPlnrAVKeylistKey);
	uint _x1IxPlnrVLocale = htonl(rec->x1IxPlnrVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrAVKeylistKey,
		(char*) &_x1IxPlnrVLocale,
		rec->Title.c_str(),
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJAVKeylistKey_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJAVKeylistKey_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJAVKeylistKey::updateRst(
			ListPlnrJAVKeylistKey& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJAVKeylistKey::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJAVKeylistKey_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJAVKeylistKey_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJAVKeylistKey::loadRecByRef(
			ubigint ref
			, PlnrJAVKeylistKey** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJAVKeylistKey_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJAVKeylistKey::loadRecByKlkLcl(
			ubigint refPlnrAVKeylistKey
			, uint x1IxPlnrVLocale
			, PlnrJAVKeylistKey** rec
		) {
	ubigint _refPlnrAVKeylistKey = htonl64(refPlnrAVKeylistKey);
	uint _x1IxPlnrVLocale = htonl(x1IxPlnrVLocale);

	const char* vals[] = {
		(char*) &_refPlnrAVKeylistKey,
		(char*) &_x1IxPlnrVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJAVKeylistKey_loadRecByKlkLcl", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJAVKeylistKey::loadRefsByKlk(
			ubigint refPlnrAVKeylistKey
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrAVKeylistKey = htonl64(refPlnrAVKeylistKey);

	const char* vals[] = {
		(char*) &_refPlnrAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrJAVKeylistKey_loadRefsByKlk", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrJAVKeylistKey::loadRstByKlk(
			ubigint refPlnrAVKeylistKey
			, const bool append
			, ListPlnrJAVKeylistKey& rst
		) {
	ubigint _refPlnrAVKeylistKey = htonl64(refPlnrAVKeylistKey);

	const char* vals[] = {
		(char*) &_refPlnrAVKeylistKey
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJAVKeylistKey_loadRstByKlk", 1, vals, l, f, append, rst);
};

bool PgTblPlnrJAVKeylistKey::loadTitByKlkLcl(
			ubigint refPlnrAVKeylistKey
			, uint x1IxPlnrVLocale
			, string& val
		) {
	ubigint _refPlnrAVKeylistKey = htonl64(refPlnrAVKeylistKey);
	uint _x1IxPlnrVLocale = htonl(x1IxPlnrVLocale);

	const char* vals[] = {
		(char*) &_refPlnrAVKeylistKey,
		(char*) &_x1IxPlnrVLocale
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadStringByStmt("TblPlnrJAVKeylistKey_loadTitByKlkLcl", 2, vals, l, f, val);
};

// IP pgTbl --- END

