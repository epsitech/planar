/**
  * \file PlnrJMVertex.cpp
  * database access for table TblPlnrJMVertex (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMVertex.h"

/******************************************************************************
 class PlnrJMVertex
 ******************************************************************************/

PlnrJMVertex::PlnrJMVertex(
			const ubigint ref
			, const ubigint refPlnrMVertex
			, const ubigint x1RefPlnrMDesign
			, const double x
			, const double y
		) {

	this->ref = ref;
	this->refPlnrMVertex = refPlnrMVertex;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->x = x;
	this->y = y;
};

bool PlnrJMVertex::operator==(
			const PlnrJMVertex& comp
		) {
	return false;
};

bool PlnrJMVertex::operator!=(
			const PlnrJMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMVertex
 ******************************************************************************/

ListPlnrJMVertex::ListPlnrJMVertex() {
};

ListPlnrJMVertex::ListPlnrJMVertex(
			const ListPlnrJMVertex& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMVertex(*(src.nodes[i]));
};

ListPlnrJMVertex::~ListPlnrJMVertex() {
	clear();
};

void ListPlnrJMVertex::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMVertex::size() const {
	return(nodes.size());
};

void ListPlnrJMVertex::append(
			PlnrJMVertex* rec
		) {
	nodes.push_back(rec);
};

PlnrJMVertex* ListPlnrJMVertex::operator[](
			const uint ix
		) {
	PlnrJMVertex* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMVertex& ListPlnrJMVertex::operator=(
			const ListPlnrJMVertex& src
		) {
	PlnrJMVertex* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMVertex(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMVertex::operator==(
			const ListPlnrJMVertex& comp
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

bool ListPlnrJMVertex::operator!=(
			const ListPlnrJMVertex& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMVertex
 ******************************************************************************/

TblPlnrJMVertex::TblPlnrJMVertex() {
};

TblPlnrJMVertex::~TblPlnrJMVertex() {
};

bool TblPlnrJMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrJMVertex** rec
		) {
	return false;
};

ubigint TblPlnrJMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	return 0;
};

void TblPlnrJMVertex::insertRec(
			PlnrJMVertex* rec
		) {
};

ubigint TblPlnrJMVertex::insertNewRec(
			PlnrJMVertex** rec
			, const ubigint refPlnrMVertex
			, const ubigint x1RefPlnrMDesign
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	PlnrJMVertex* _rec = NULL;

	_rec = new PlnrJMVertex(0, refPlnrMVertex, x1RefPlnrMDesign, x, y);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMVertex::appendNewRecToRst(
			ListPlnrJMVertex& rst
			, PlnrJMVertex** rec
			, const ubigint refPlnrMVertex
			, const ubigint x1RefPlnrMDesign
			, const double x
			, const double y
		) {
	ubigint retval = 0;
	PlnrJMVertex* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMVertex, x1RefPlnrMDesign, x, y);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMVertex::insertRst(
			ListPlnrJMVertex& rst
			, bool transact
		) {
};

void TblPlnrJMVertex::updateRec(
			PlnrJMVertex* rec
		) {
};

void TblPlnrJMVertex::updateRst(
			ListPlnrJMVertex& rst
			, bool transact
		) {
};

void TblPlnrJMVertex::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMVertex::loadRecByRef(
			ubigint ref
			, PlnrJMVertex** rec
		) {
	return false;
};

bool TblPlnrJMVertex::loadRecByVtxDsn(
			ubigint refPlnrMVertex
			, ubigint x1RefPlnrMDesign
			, PlnrJMVertex** rec
		) {
	return false;
};

ubigint TblPlnrJMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	return 0;
};

ubigint TblPlnrJMVertex::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	ubigint numload = 0;
	PlnrJMVertex* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMVertex
 ******************************************************************************/

MyTblPlnrJMVertex::MyTblPlnrJMVertex() : TblPlnrJMVertex(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMVertex::~MyTblPlnrJMVertex() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMVertex::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMVertex (refPlnrMVertex, x1RefPlnrMDesign, x, y) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMVertex SET refPlnrMVertex = ?, x1RefPlnrMDesign = ?, x = ?, y = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMVertex WHERE ref = ?", false);
};

bool MyTblPlnrJMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrJMVertex** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMVertex* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMVertex / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMVertex();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMVertex = atoll((char*) dbrow[1]); else _rec->refPlnrMVertex = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->x = atof((char*) dbrow[3]); else _rec->x = 0.0;
		if (dbrow[4]) _rec->y = atof((char*) dbrow[4]); else _rec->y = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMVertex* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMVertex / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMVertex();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMVertex = atoll((char*) dbrow[1]); else rec->refPlnrMVertex = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->x = atof((char*) dbrow[3]); else rec->x = 0.0;
			if (dbrow[4]) rec->y = atof((char*) dbrow[4]); else rec->y = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMVertex::insertRec(
			PlnrJMVertex* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMVertex,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->x,&(l[2]),&(n[2]),&(e[2])),
		bindDouble(&rec->y,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMVertex / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMVertex / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMVertex::insertRst(
			ListPlnrJMVertex& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMVertex::updateRec(
			PlnrJMVertex* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMVertex,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindDouble(&rec->x,&(l[2]),&(n[2]),&(e[2])), 
		bindDouble(&rec->y,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMVertex / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMVertex / stmtUpdateRec)\n");
};

void MyTblPlnrJMVertex::updateRst(
			ListPlnrJMVertex& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMVertex::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMVertex / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMVertex / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMVertex::loadRecByRef(
			ubigint ref
			, PlnrJMVertex** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMVertex WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMVertex::loadRecByVtxDsn(
			ubigint refPlnrMVertex
			, ubigint x1RefPlnrMDesign
			, PlnrJMVertex** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMVertex, x1RefPlnrMDesign, x, y FROM TblPlnrJMVertex WHERE refPlnrMVertex = " + to_string(refPlnrMVertex) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMVertex, x1RefPlnrMDesign, x, y FROM TblPlnrJMVertex WHERE refPlnrMVertex = " + to_string(refPlnrMVertex) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMVertex
 ******************************************************************************/

PgTblPlnrJMVertex::PgTblPlnrJMVertex() : TblPlnrJMVertex(), PgTable() {
};

PgTblPlnrJMVertex::~PgTblPlnrJMVertex() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMVertex::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMVertex_insertRec", "INSERT INTO TblPlnrJMVertex (refPlnrMVertex, x1RefPlnrMDesign, x, y) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMVertex_updateRec", "UPDATE TblPlnrJMVertex SET refPlnrMVertex = $1, x1RefPlnrMDesign = $2, x = $3, y = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMVertex_removeRecByRef", "DELETE FROM TblPlnrJMVertex WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMVertex_loadRecByRef", "SELECT ref, refPlnrMVertex, x1RefPlnrMDesign, x, y FROM TblPlnrJMVertex WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMVertex_loadRecByVtxDsn", "SELECT ref, refPlnrMVertex, x1RefPlnrMDesign, x, y FROM TblPlnrJMVertex WHERE refPlnrMVertex = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMVertex_loadRstByVtx", "SELECT ref, refPlnrMVertex, x1RefPlnrMDesign, x, y FROM TblPlnrJMVertex WHERE refPlnrMVertex = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMVertex::loadRec(
			PGresult* res
			, PlnrJMVertex** rec
		) {
	char* ptr;

	PlnrJMVertex* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMVertex();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmvertex"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMVertex = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x = atof(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->y = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMVertex::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMVertex* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmvertex"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x"),
			PQfnumber(res, "y")
		};

		while (numread < numrow) {
			rec = new PlnrJMVertex();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMVertex = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x = atof(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->y = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMVertex::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMVertex** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMVertex / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMVertex::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMVertex / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMVertex::loadRecBySQL(
			const string& sqlstr
			, PlnrJMVertex** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMVertex::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMVertex::insertRec(
			PlnrJMVertex* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);

	const char* vals[] = {
		(char*) &_refPlnrMVertex,
		(char*) &_x1RefPlnrMDesign,
		_x.c_str(),
		_y.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMVertex_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMVertex_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMVertex::insertRst(
			ListPlnrJMVertex& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMVertex::updateRec(
			PlnrJMVertex* rec
		) {
	PGresult* res;

	ubigint _refPlnrMVertex = htonl64(rec->refPlnrMVertex);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	string _x = to_string(rec->x);
	string _y = to_string(rec->y);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMVertex,
		(char*) &_x1RefPlnrMDesign,
		_x.c_str(),
		_y.c_str(),
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

	res = PQexecPrepared(dbs, "TblPlnrJMVertex_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMVertex_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMVertex::updateRst(
			ListPlnrJMVertex& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMVertex::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMVertex_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMVertex_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMVertex::loadRecByRef(
			ubigint ref
			, PlnrJMVertex** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMVertex_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMVertex::loadRecByVtxDsn(
			ubigint refPlnrMVertex
			, ubigint x1RefPlnrMDesign
			, PlnrJMVertex** rec
		) {
	ubigint _refPlnrMVertex = htonl64(refPlnrMVertex);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMVertex,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMVertex_loadRecByVtxDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMVertex::loadRstByVtx(
			ubigint refPlnrMVertex
			, const bool append
			, ListPlnrJMVertex& rst
		) {
	ubigint _refPlnrMVertex = htonl64(refPlnrMVertex);

	const char* vals[] = {
		(char*) &_refPlnrMVertex
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMVertex_loadRstByVtx", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

