/**
  * \file PlnrRMLineguideMLineguide.cpp
  * database access for table TblPlnrRMLineguideMLineguide (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMLineguideMLineguide.h"

/******************************************************************************
 class PlnrRMLineguideMLineguide
 ******************************************************************************/

PlnrRMLineguideMLineguide::PlnrRMLineguideMLineguide(
			const ubigint ref
			, const ubigint devRefPlnrMLineguide
			, const ubigint dsnRefPlnrMLineguide
		) {

	this->ref = ref;
	this->devRefPlnrMLineguide = devRefPlnrMLineguide;
	this->dsnRefPlnrMLineguide = dsnRefPlnrMLineguide;
};

bool PlnrRMLineguideMLineguide::operator==(
			const PlnrRMLineguideMLineguide& comp
		) {
	return false;
};

bool PlnrRMLineguideMLineguide::operator!=(
			const PlnrRMLineguideMLineguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMLineguideMLineguide
 ******************************************************************************/

ListPlnrRMLineguideMLineguide::ListPlnrRMLineguideMLineguide() {
};

ListPlnrRMLineguideMLineguide::ListPlnrRMLineguideMLineguide(
			const ListPlnrRMLineguideMLineguide& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMLineguideMLineguide(*(src.nodes[i]));
};

ListPlnrRMLineguideMLineguide::~ListPlnrRMLineguideMLineguide() {
	clear();
};

void ListPlnrRMLineguideMLineguide::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMLineguideMLineguide::size() const {
	return(nodes.size());
};

void ListPlnrRMLineguideMLineguide::append(
			PlnrRMLineguideMLineguide* rec
		) {
	nodes.push_back(rec);
};

PlnrRMLineguideMLineguide* ListPlnrRMLineguideMLineguide::operator[](
			const uint ix
		) {
	PlnrRMLineguideMLineguide* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMLineguideMLineguide& ListPlnrRMLineguideMLineguide::operator=(
			const ListPlnrRMLineguideMLineguide& src
		) {
	PlnrRMLineguideMLineguide* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMLineguideMLineguide(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMLineguideMLineguide::operator==(
			const ListPlnrRMLineguideMLineguide& comp
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

bool ListPlnrRMLineguideMLineguide::operator!=(
			const ListPlnrRMLineguideMLineguide& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMLineguideMLineguide
 ******************************************************************************/

TblPlnrRMLineguideMLineguide::TblPlnrRMLineguideMLineguide() {
};

TblPlnrRMLineguideMLineguide::~TblPlnrRMLineguideMLineguide() {
};

bool TblPlnrRMLineguideMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLineguideMLineguide** rec
		) {
	return false;
};

ubigint TblPlnrRMLineguideMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLineguideMLineguide& rst
		) {
	return 0;
};

void TblPlnrRMLineguideMLineguide::insertRec(
			PlnrRMLineguideMLineguide* rec
		) {
};

ubigint TblPlnrRMLineguideMLineguide::insertNewRec(
			PlnrRMLineguideMLineguide** rec
			, const ubigint devRefPlnrMLineguide
			, const ubigint dsnRefPlnrMLineguide
		) {
	ubigint retval = 0;
	PlnrRMLineguideMLineguide* _rec = NULL;

	_rec = new PlnrRMLineguideMLineguide(0, devRefPlnrMLineguide, dsnRefPlnrMLineguide);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMLineguideMLineguide::appendNewRecToRst(
			ListPlnrRMLineguideMLineguide& rst
			, PlnrRMLineguideMLineguide** rec
			, const ubigint devRefPlnrMLineguide
			, const ubigint dsnRefPlnrMLineguide
		) {
	ubigint retval = 0;
	PlnrRMLineguideMLineguide* _rec = NULL;

	retval = insertNewRec(&_rec, devRefPlnrMLineguide, dsnRefPlnrMLineguide);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMLineguideMLineguide::insertRst(
			ListPlnrRMLineguideMLineguide& rst
			, bool transact
		) {
};

void TblPlnrRMLineguideMLineguide::updateRec(
			PlnrRMLineguideMLineguide* rec
		) {
};

void TblPlnrRMLineguideMLineguide::updateRst(
			ListPlnrRMLineguideMLineguide& rst
			, bool transact
		) {
};

void TblPlnrRMLineguideMLineguide::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMLineguideMLineguide::loadRecByRef(
			ubigint ref
			, PlnrRMLineguideMLineguide** rec
		) {
	return false;
};

ubigint TblPlnrRMLineguideMLineguide::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMLineguideMLineguide& rst
		) {
	ubigint numload = 0;
	PlnrRMLineguideMLineguide* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMLineguideMLineguide
 ******************************************************************************/

MyTblPlnrRMLineguideMLineguide::MyTblPlnrRMLineguideMLineguide() : TblPlnrRMLineguideMLineguide(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMLineguideMLineguide::~MyTblPlnrRMLineguideMLineguide() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMLineguideMLineguide::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMLineguideMLineguide (devRefPlnrMLineguide, dsnRefPlnrMLineguide) VALUES (?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMLineguideMLineguide SET devRefPlnrMLineguide = ?, dsnRefPlnrMLineguide = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMLineguideMLineguide WHERE ref = ?", false);
};

bool MyTblPlnrRMLineguideMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLineguideMLineguide** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMLineguideMLineguide* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMLineguideMLineguide / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMLineguideMLineguide();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->devRefPlnrMLineguide = atoll((char*) dbrow[1]); else _rec->devRefPlnrMLineguide = 0;
		if (dbrow[2]) _rec->dsnRefPlnrMLineguide = atoll((char*) dbrow[2]); else _rec->dsnRefPlnrMLineguide = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMLineguideMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLineguideMLineguide& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMLineguideMLineguide* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMLineguideMLineguide / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMLineguideMLineguide();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->devRefPlnrMLineguide = atoll((char*) dbrow[1]); else rec->devRefPlnrMLineguide = 0;
			if (dbrow[2]) rec->dsnRefPlnrMLineguide = atoll((char*) dbrow[2]); else rec->dsnRefPlnrMLineguide = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMLineguideMLineguide::insertRec(
			PlnrRMLineguideMLineguide* rec
		) {
	unsigned long l[2]; my_bool n[2]; my_bool e[2];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->devRefPlnrMLineguide,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->dsnRefPlnrMLineguide,&(l[1]),&(n[1]),&(e[1]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLineguideMLineguide / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLineguideMLineguide / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMLineguideMLineguide::insertRst(
			ListPlnrRMLineguideMLineguide& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMLineguideMLineguide::updateRec(
			PlnrRMLineguideMLineguide* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->devRefPlnrMLineguide,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->dsnRefPlnrMLineguide,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLineguideMLineguide / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLineguideMLineguide / stmtUpdateRec)\n");
};

void MyTblPlnrRMLineguideMLineguide::updateRst(
			ListPlnrRMLineguideMLineguide& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMLineguideMLineguide::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMLineguideMLineguide / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMLineguideMLineguide / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMLineguideMLineguide::loadRecByRef(
			ubigint ref
			, PlnrRMLineguideMLineguide** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMLineguideMLineguide WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMLineguideMLineguide
 ******************************************************************************/

PgTblPlnrRMLineguideMLineguide::PgTblPlnrRMLineguideMLineguide() : TblPlnrRMLineguideMLineguide(), PgTable() {
};

PgTblPlnrRMLineguideMLineguide::~PgTblPlnrRMLineguideMLineguide() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMLineguideMLineguide::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMLineguideMLineguide_insertRec", "INSERT INTO TblPlnrRMLineguideMLineguide (devRefPlnrMLineguide, dsnRefPlnrMLineguide) VALUES ($1,$2) RETURNING ref", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMLineguideMLineguide_updateRec", "UPDATE TblPlnrRMLineguideMLineguide SET devRefPlnrMLineguide = $1, dsnRefPlnrMLineguide = $2 WHERE ref = $3", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMLineguideMLineguide_removeRecByRef", "DELETE FROM TblPlnrRMLineguideMLineguide WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMLineguideMLineguide_loadRecByRef", "SELECT ref, devRefPlnrMLineguide, dsnRefPlnrMLineguide FROM TblPlnrRMLineguideMLineguide WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrRMLineguideMLineguide::loadRec(
			PGresult* res
			, PlnrRMLineguideMLineguide** rec
		) {
	char* ptr;

	PlnrRMLineguideMLineguide* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMLineguideMLineguide();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "devrefplnrmlineguide"),
			PQfnumber(res, "dsnrefplnrmlineguide")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->devRefPlnrMLineguide = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->dsnRefPlnrMLineguide = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMLineguideMLineguide::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMLineguideMLineguide& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMLineguideMLineguide* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "devrefplnrmlineguide"),
			PQfnumber(res, "dsnrefplnrmlineguide")
		};

		while (numread < numrow) {
			rec = new PlnrRMLineguideMLineguide();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->devRefPlnrMLineguide = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->dsnRefPlnrMLineguide = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMLineguideMLineguide::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMLineguideMLineguide** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLineguideMLineguide / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMLineguideMLineguide::loadRecBySQL(
			const string& sqlstr
			, PlnrRMLineguideMLineguide** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMLineguideMLineguide::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMLineguideMLineguide& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMLineguideMLineguide::insertRec(
			PlnrRMLineguideMLineguide* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _devRefPlnrMLineguide = htonl64(rec->devRefPlnrMLineguide);
	ubigint _dsnRefPlnrMLineguide = htonl64(rec->dsnRefPlnrMLineguide);

	const char* vals[] = {
		(char*) &_devRefPlnrMLineguide,
		(char*) &_dsnRefPlnrMLineguide
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMLineguideMLineguide_insertRec", 2, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLineguideMLineguide_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMLineguideMLineguide::insertRst(
			ListPlnrRMLineguideMLineguide& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMLineguideMLineguide::updateRec(
			PlnrRMLineguideMLineguide* rec
		) {
	PGresult* res;

	ubigint _devRefPlnrMLineguide = htonl64(rec->devRefPlnrMLineguide);
	ubigint _dsnRefPlnrMLineguide = htonl64(rec->dsnRefPlnrMLineguide);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_devRefPlnrMLineguide,
		(char*) &_dsnRefPlnrMLineguide,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMLineguideMLineguide_updateRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLineguideMLineguide_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMLineguideMLineguide::updateRst(
			ListPlnrRMLineguideMLineguide& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMLineguideMLineguide::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMLineguideMLineguide_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMLineguideMLineguide_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMLineguideMLineguide::loadRecByRef(
			ubigint ref
			, PlnrRMLineguideMLineguide** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMLineguideMLineguide_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

