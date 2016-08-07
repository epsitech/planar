/**
  * \file PlnrJMPersonLastname.cpp
  * database access for table TblPlnrJMPersonLastname (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMPersonLastname.h"

/******************************************************************************
 class PlnrJMPersonLastname
 ******************************************************************************/

PlnrJMPersonLastname::PlnrJMPersonLastname(
			const ubigint ref
			, const ubigint refPlnrMPerson
			, const uint x1Startd
			, const string Lastname
		) {

	this->ref = ref;
	this->refPlnrMPerson = refPlnrMPerson;
	this->x1Startd = x1Startd;
	this->Lastname = Lastname;
};

bool PlnrJMPersonLastname::operator==(
			const PlnrJMPersonLastname& comp
		) {
	return false;
};

bool PlnrJMPersonLastname::operator!=(
			const PlnrJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMPersonLastname
 ******************************************************************************/

ListPlnrJMPersonLastname::ListPlnrJMPersonLastname() {
};

ListPlnrJMPersonLastname::ListPlnrJMPersonLastname(
			const ListPlnrJMPersonLastname& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMPersonLastname(*(src.nodes[i]));
};

ListPlnrJMPersonLastname::~ListPlnrJMPersonLastname() {
	clear();
};

void ListPlnrJMPersonLastname::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMPersonLastname::size() const {
	return(nodes.size());
};

void ListPlnrJMPersonLastname::append(
			PlnrJMPersonLastname* rec
		) {
	nodes.push_back(rec);
};

PlnrJMPersonLastname* ListPlnrJMPersonLastname::operator[](
			const uint ix
		) {
	PlnrJMPersonLastname* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMPersonLastname& ListPlnrJMPersonLastname::operator=(
			const ListPlnrJMPersonLastname& src
		) {
	PlnrJMPersonLastname* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMPersonLastname(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMPersonLastname::operator==(
			const ListPlnrJMPersonLastname& comp
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

bool ListPlnrJMPersonLastname::operator!=(
			const ListPlnrJMPersonLastname& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMPersonLastname
 ******************************************************************************/

TblPlnrJMPersonLastname::TblPlnrJMPersonLastname() {
};

TblPlnrJMPersonLastname::~TblPlnrJMPersonLastname() {
};

bool TblPlnrJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, PlnrJMPersonLastname** rec
		) {
	return false;
};

ubigint TblPlnrJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	return 0;
};

void TblPlnrJMPersonLastname::insertRec(
			PlnrJMPersonLastname* rec
		) {
};

ubigint TblPlnrJMPersonLastname::insertNewRec(
			PlnrJMPersonLastname** rec
			, const ubigint refPlnrMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	PlnrJMPersonLastname* _rec = NULL;

	_rec = new PlnrJMPersonLastname(0, refPlnrMPerson, x1Startd, Lastname);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMPersonLastname::appendNewRecToRst(
			ListPlnrJMPersonLastname& rst
			, PlnrJMPersonLastname** rec
			, const ubigint refPlnrMPerson
			, const uint x1Startd
			, const string Lastname
		) {
	ubigint retval = 0;
	PlnrJMPersonLastname* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMPerson, x1Startd, Lastname);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMPersonLastname::insertRst(
			ListPlnrJMPersonLastname& rst
			, bool transact
		) {
};

void TblPlnrJMPersonLastname::updateRec(
			PlnrJMPersonLastname* rec
		) {
};

void TblPlnrJMPersonLastname::updateRst(
			ListPlnrJMPersonLastname& rst
			, bool transact
		) {
};

void TblPlnrJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMPersonLastname::loadRecByRef(
			ubigint ref
			, PlnrJMPersonLastname** rec
		) {
	return false;
};

bool TblPlnrJMPersonLastname::loadRecByPrsSta(
			ubigint refPlnrMPerson
			, uint x1Startd
			, PlnrJMPersonLastname** rec
		) {
	return false;
};

ubigint TblPlnrJMPersonLastname::loadRefsByPrs(
			ubigint refPlnrMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrJMPersonLastname::loadRstByPrs(
			ubigint refPlnrMPerson
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	return 0;
};

ubigint TblPlnrJMPersonLastname::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	ubigint numload = 0;
	PlnrJMPersonLastname* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMPersonLastname
 ******************************************************************************/

MyTblPlnrJMPersonLastname::MyTblPlnrJMPersonLastname() : TblPlnrJMPersonLastname(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMPersonLastname::~MyTblPlnrJMPersonLastname() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMPersonLastname::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMPersonLastname (refPlnrMPerson, x1Startd, Lastname) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMPersonLastname SET refPlnrMPerson = ?, x1Startd = ?, Lastname = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMPersonLastname WHERE ref = ?", false);
};

bool MyTblPlnrJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, PlnrJMPersonLastname** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMPersonLastname* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMPersonLastname / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMPersonLastname();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMPerson = atoll((char*) dbrow[1]); else _rec->refPlnrMPerson = 0;
		if (dbrow[2]) _rec->x1Startd = atol((char*) dbrow[2]); else _rec->x1Startd = 0;
		if (dbrow[3]) _rec->Lastname.assign(dbrow[3], dblengths[3]); else _rec->Lastname = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMPersonLastname* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMPersonLastname / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMPersonLastname();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMPerson = atoll((char*) dbrow[1]); else rec->refPlnrMPerson = 0;
			if (dbrow[2]) rec->x1Startd = atol((char*) dbrow[2]); else rec->x1Startd = 0;
			if (dbrow[3]) rec->Lastname.assign(dbrow[3], dblengths[3]); else rec->Lastname = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMPersonLastname::insertRec(
			PlnrJMPersonLastname* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMPerson,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])),
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMPersonLastname / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMPersonLastname / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMPersonLastname::insertRst(
			ListPlnrJMPersonLastname& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMPersonLastname::updateRec(
			PlnrJMPersonLastname* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[2] = rec->Lastname.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMPerson,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->x1Startd,&(l[1]),&(n[1]),&(e[1])), 
		bindCstring((char*) (rec->Lastname.c_str()),&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMPersonLastname / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMPersonLastname / stmtUpdateRec)\n");
};

void MyTblPlnrJMPersonLastname::updateRst(
			ListPlnrJMPersonLastname& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMPersonLastname::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMPersonLastname / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMPersonLastname / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMPersonLastname::loadRecByRef(
			ubigint ref
			, PlnrJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMPersonLastname WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMPersonLastname::loadRecByPrsSta(
			ubigint refPlnrMPerson
			, uint x1Startd
			, PlnrJMPersonLastname** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMPerson, x1Startd, Lastname FROM TblPlnrJMPersonLastname WHERE refPlnrMPerson = " + to_string(refPlnrMPerson) + " AND x1Startd <= " + to_string(x1Startd) + " ORDER BY x1Startd DESC LIMIT 0,1", rec);
};

ubigint MyTblPlnrJMPersonLastname::loadRefsByPrs(
			ubigint refPlnrMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrJMPersonLastname WHERE refPlnrMPerson = " + to_string(refPlnrMPerson) + "", append, refs);
};

ubigint MyTblPlnrJMPersonLastname::loadRstByPrs(
			ubigint refPlnrMPerson
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMPerson, x1Startd, Lastname FROM TblPlnrJMPersonLastname WHERE refPlnrMPerson = " + to_string(refPlnrMPerson) + " ORDER BY x1Startd ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMPersonLastname
 ******************************************************************************/

PgTblPlnrJMPersonLastname::PgTblPlnrJMPersonLastname() : TblPlnrJMPersonLastname(), PgTable() {
};

PgTblPlnrJMPersonLastname::~PgTblPlnrJMPersonLastname() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMPersonLastname::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMPersonLastname_insertRec", "INSERT INTO TblPlnrJMPersonLastname (refPlnrMPerson, x1Startd, Lastname) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMPersonLastname_updateRec", "UPDATE TblPlnrJMPersonLastname SET refPlnrMPerson = $1, x1Startd = $2, Lastname = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMPersonLastname_removeRecByRef", "DELETE FROM TblPlnrJMPersonLastname WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMPersonLastname_loadRecByRef", "SELECT ref, refPlnrMPerson, x1Startd, Lastname FROM TblPlnrJMPersonLastname WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMPersonLastname_loadRecByPrsSta", "SELECT ref, refPlnrMPerson, x1Startd, Lastname FROM TblPlnrJMPersonLastname WHERE refPlnrMPerson = $1 AND x1Startd <= $2 ORDER BY x1Startd DESC OFFSET 0 LIMIT 1", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMPersonLastname_loadRefsByPrs", "SELECT ref FROM TblPlnrJMPersonLastname WHERE refPlnrMPerson = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMPersonLastname_loadRstByPrs", "SELECT ref, refPlnrMPerson, x1Startd, Lastname FROM TblPlnrJMPersonLastname WHERE refPlnrMPerson = $1 ORDER BY x1Startd ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMPersonLastname::loadRec(
			PGresult* res
			, PlnrJMPersonLastname** rec
		) {
	char* ptr;

	PlnrJMPersonLastname* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMPersonLastname();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMPerson = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1Startd = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->Lastname.assign(ptr, PQgetlength(res, 0, fnum[3]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMPersonLastname::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMPersonLastname* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmperson"),
			PQfnumber(res, "x1startd"),
			PQfnumber(res, "lastname")
		};

		while (numread < numrow) {
			rec = new PlnrJMPersonLastname();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMPerson = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1Startd = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->Lastname.assign(ptr, PQgetlength(res, numread, fnum[3]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMPersonLastname::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMPersonLastname / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMPersonLastname::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMPersonLastname / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMPersonLastname::loadRecBySQL(
			const string& sqlstr
			, PlnrJMPersonLastname** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMPersonLastname::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMPersonLastname::insertRec(
			PlnrJMPersonLastname* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	uint _x1Startd = htonl(rec->x1Startd);

	const char* vals[] = {
		(char*) &_refPlnrMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMPersonLastname_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMPersonLastname_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMPersonLastname::insertRst(
			ListPlnrJMPersonLastname& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMPersonLastname::updateRec(
			PlnrJMPersonLastname* rec
		) {
	PGresult* res;

	ubigint _refPlnrMPerson = htonl64(rec->refPlnrMPerson);
	uint _x1Startd = htonl(rec->x1Startd);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMPerson,
		(char*) &_x1Startd,
		rec->Lastname.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMPersonLastname_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMPersonLastname_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMPersonLastname::updateRst(
			ListPlnrJMPersonLastname& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMPersonLastname::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMPersonLastname_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMPersonLastname_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMPersonLastname::loadRecByRef(
			ubigint ref
			, PlnrJMPersonLastname** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMPersonLastname_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMPersonLastname::loadRecByPrsSta(
			ubigint refPlnrMPerson
			, uint x1Startd
			, PlnrJMPersonLastname** rec
		) {
	ubigint _refPlnrMPerson = htonl64(refPlnrMPerson);
	uint _x1Startd = htonl(x1Startd);

	const char* vals[] = {
		(char*) &_refPlnrMPerson,
		(char*) &_x1Startd
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMPersonLastname_loadRecByPrsSta", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMPersonLastname::loadRefsByPrs(
			ubigint refPlnrMPerson
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrMPerson = htonl64(refPlnrMPerson);

	const char* vals[] = {
		(char*) &_refPlnrMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrJMPersonLastname_loadRefsByPrs", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrJMPersonLastname::loadRstByPrs(
			ubigint refPlnrMPerson
			, const bool append
			, ListPlnrJMPersonLastname& rst
		) {
	ubigint _refPlnrMPerson = htonl64(refPlnrMPerson);

	const char* vals[] = {
		(char*) &_refPlnrMPerson
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMPersonLastname_loadRstByPrs", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

