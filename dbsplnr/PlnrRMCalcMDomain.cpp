/**
  * \file PlnrRMCalcMDomain.cpp
  * database access for table TblPlnrRMCalcMDomain (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMCalcMDomain.h"

/******************************************************************************
 class PlnrRMCalcMDomain
 ******************************************************************************/

PlnrRMCalcMDomain::PlnrRMCalcMDomain(
			const ubigint ref
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMDomain
			, const string srefPlnrKCalcdomprp
		) {

	this->ref = ref;
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMDomain = refPlnrMDomain;
	this->srefPlnrKCalcdomprp = srefPlnrKCalcdomprp;
};

bool PlnrRMCalcMDomain::operator==(
			const PlnrRMCalcMDomain& comp
		) {
	return false;
};

bool PlnrRMCalcMDomain::operator!=(
			const PlnrRMCalcMDomain& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMCalcMDomain
 ******************************************************************************/

ListPlnrRMCalcMDomain::ListPlnrRMCalcMDomain() {
};

ListPlnrRMCalcMDomain::ListPlnrRMCalcMDomain(
			const ListPlnrRMCalcMDomain& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMCalcMDomain(*(src.nodes[i]));
};

ListPlnrRMCalcMDomain::~ListPlnrRMCalcMDomain() {
	clear();
};

void ListPlnrRMCalcMDomain::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMCalcMDomain::size() const {
	return(nodes.size());
};

void ListPlnrRMCalcMDomain::append(
			PlnrRMCalcMDomain* rec
		) {
	nodes.push_back(rec);
};

PlnrRMCalcMDomain* ListPlnrRMCalcMDomain::operator[](
			const uint ix
		) {
	PlnrRMCalcMDomain* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMCalcMDomain& ListPlnrRMCalcMDomain::operator=(
			const ListPlnrRMCalcMDomain& src
		) {
	PlnrRMCalcMDomain* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMCalcMDomain(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMCalcMDomain::operator==(
			const ListPlnrRMCalcMDomain& comp
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

bool ListPlnrRMCalcMDomain::operator!=(
			const ListPlnrRMCalcMDomain& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMCalcMDomain
 ******************************************************************************/

TblPlnrRMCalcMDomain::TblPlnrRMCalcMDomain() {
};

TblPlnrRMCalcMDomain::~TblPlnrRMCalcMDomain() {
};

bool TblPlnrRMCalcMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrRMCalcMDomain** rec
		) {
	return false;
};

ubigint TblPlnrRMCalcMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMCalcMDomain& rst
		) {
	return 0;
};

void TblPlnrRMCalcMDomain::insertRec(
			PlnrRMCalcMDomain* rec
		) {
};

ubigint TblPlnrRMCalcMDomain::insertNewRec(
			PlnrRMCalcMDomain** rec
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMDomain
			, const string srefPlnrKCalcdomprp
		) {
	ubigint retval = 0;
	PlnrRMCalcMDomain* _rec = NULL;

	_rec = new PlnrRMCalcMDomain(0, refPlnrMCalc, refPlnrMDomain, srefPlnrKCalcdomprp);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMCalcMDomain::appendNewRecToRst(
			ListPlnrRMCalcMDomain& rst
			, PlnrRMCalcMDomain** rec
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMDomain
			, const string srefPlnrKCalcdomprp
		) {
	ubigint retval = 0;
	PlnrRMCalcMDomain* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMCalc, refPlnrMDomain, srefPlnrKCalcdomprp);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMCalcMDomain::insertRst(
			ListPlnrRMCalcMDomain& rst
			, bool transact
		) {
};

void TblPlnrRMCalcMDomain::updateRec(
			PlnrRMCalcMDomain* rec
		) {
};

void TblPlnrRMCalcMDomain::updateRst(
			ListPlnrRMCalcMDomain& rst
			, bool transact
		) {
};

void TblPlnrRMCalcMDomain::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMCalcMDomain::loadRecByRef(
			ubigint ref
			, PlnrRMCalcMDomain** rec
		) {
	return false;
};

ubigint TblPlnrRMCalcMDomain::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMCalcMDomain& rst
		) {
	ubigint numload = 0;
	PlnrRMCalcMDomain* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMCalcMDomain
 ******************************************************************************/

MyTblPlnrRMCalcMDomain::MyTblPlnrRMCalcMDomain() : TblPlnrRMCalcMDomain(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMCalcMDomain::~MyTblPlnrRMCalcMDomain() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMCalcMDomain::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMCalcMDomain (refPlnrMCalc, refPlnrMDomain, srefPlnrKCalcdomprp) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMCalcMDomain SET refPlnrMCalc = ?, refPlnrMDomain = ?, srefPlnrKCalcdomprp = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMCalcMDomain WHERE ref = ?", false);
};

bool MyTblPlnrRMCalcMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrRMCalcMDomain** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMCalcMDomain* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMCalcMDomain / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMCalcMDomain();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMCalc = atoll((char*) dbrow[1]); else _rec->refPlnrMCalc = 0;
		if (dbrow[2]) _rec->refPlnrMDomain = atoll((char*) dbrow[2]); else _rec->refPlnrMDomain = 0;
		if (dbrow[3]) _rec->srefPlnrKCalcdomprp.assign(dbrow[3], dblengths[3]); else _rec->srefPlnrKCalcdomprp = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMCalcMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMCalcMDomain& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMCalcMDomain* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMCalcMDomain / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMCalcMDomain();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMCalc = atoll((char*) dbrow[1]); else rec->refPlnrMCalc = 0;
			if (dbrow[2]) rec->refPlnrMDomain = atoll((char*) dbrow[2]); else rec->refPlnrMDomain = 0;
			if (dbrow[3]) rec->srefPlnrKCalcdomprp.assign(dbrow[3], dblengths[3]); else rec->srefPlnrKCalcdomprp = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMCalcMDomain::insertRec(
			PlnrRMCalcMDomain* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->srefPlnrKCalcdomprp.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMCalc,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMDomain,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->srefPlnrKCalcdomprp.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMCalcMDomain / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMCalcMDomain / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMCalcMDomain::insertRst(
			ListPlnrRMCalcMDomain& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMCalcMDomain::updateRec(
			PlnrRMCalcMDomain* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->srefPlnrKCalcdomprp.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMCalc,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMDomain,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->srefPlnrKCalcdomprp.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMCalcMDomain / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMCalcMDomain / stmtUpdateRec)\n");
};

void MyTblPlnrRMCalcMDomain::updateRst(
			ListPlnrRMCalcMDomain& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMCalcMDomain::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMCalcMDomain / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMCalcMDomain / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMCalcMDomain::loadRecByRef(
			ubigint ref
			, PlnrRMCalcMDomain** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMCalcMDomain WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMCalcMDomain
 ******************************************************************************/

PgTblPlnrRMCalcMDomain::PgTblPlnrRMCalcMDomain() : TblPlnrRMCalcMDomain(), PgTable() {
};

PgTblPlnrRMCalcMDomain::~PgTblPlnrRMCalcMDomain() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMCalcMDomain::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMCalcMDomain_insertRec", "INSERT INTO TblPlnrRMCalcMDomain (refPlnrMCalc, refPlnrMDomain, srefPlnrKCalcdomprp) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMCalcMDomain_updateRec", "UPDATE TblPlnrRMCalcMDomain SET refPlnrMCalc = $1, refPlnrMDomain = $2, srefPlnrKCalcdomprp = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMCalcMDomain_removeRecByRef", "DELETE FROM TblPlnrRMCalcMDomain WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMCalcMDomain_loadRecByRef", "SELECT ref, refPlnrMCalc, refPlnrMDomain, srefPlnrKCalcdomprp FROM TblPlnrRMCalcMDomain WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrRMCalcMDomain::loadRec(
			PGresult* res
			, PlnrRMCalcMDomain** rec
		) {
	char* ptr;

	PlnrRMCalcMDomain* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMCalcMDomain();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "refplnrmdomain"),
			PQfnumber(res, "srefplnrkcalcdomprp")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMDomain = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->srefPlnrKCalcdomprp.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMCalcMDomain::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMCalcMDomain& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMCalcMDomain* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "refplnrmdomain"),
			PQfnumber(res, "srefplnrkcalcdomprp")
		};

		while (numread < numrow) {
			rec = new PlnrRMCalcMDomain();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMDomain = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->srefPlnrKCalcdomprp.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMCalcMDomain::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMCalcMDomain** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMDomain / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMCalcMDomain::loadRecBySQL(
			const string& sqlstr
			, PlnrRMCalcMDomain** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMCalcMDomain::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMCalcMDomain& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMCalcMDomain::insertRec(
			PlnrRMCalcMDomain* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _refPlnrMDomain = htonl64(rec->refPlnrMDomain);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_refPlnrMDomain,
		rec->srefPlnrKCalcdomprp.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrRMCalcMDomain_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMDomain_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMCalcMDomain::insertRst(
			ListPlnrRMCalcMDomain& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMCalcMDomain::updateRec(
			PlnrRMCalcMDomain* rec
		) {
	PGresult* res;

	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _refPlnrMDomain = htonl64(rec->refPlnrMDomain);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMCalc,
		(char*) &_refPlnrMDomain,
		rec->srefPlnrKCalcdomprp.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMCalcMDomain_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMDomain_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMCalcMDomain::updateRst(
			ListPlnrRMCalcMDomain& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMCalcMDomain::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMCalcMDomain_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMDomain_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMCalcMDomain::loadRecByRef(
			ubigint ref
			, PlnrRMCalcMDomain** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMCalcMDomain_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

