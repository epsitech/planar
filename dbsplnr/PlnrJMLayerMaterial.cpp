/**
  * \file PlnrJMLayerMaterial.cpp
  * database access for table TblPlnrJMLayerMaterial (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMLayerMaterial.h"

/******************************************************************************
 class PlnrJMLayerMaterial
 ******************************************************************************/

PlnrJMLayerMaterial::PlnrJMLayerMaterial(
			const ubigint ref
			, const ubigint refPlnrMLayer
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMMaterial
		) {

	this->ref = ref;
	this->refPlnrMLayer = refPlnrMLayer;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->refPlnrMMaterial = refPlnrMMaterial;
};

bool PlnrJMLayerMaterial::operator==(
			const PlnrJMLayerMaterial& comp
		) {
	return false;
};

bool PlnrJMLayerMaterial::operator!=(
			const PlnrJMLayerMaterial& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMLayerMaterial
 ******************************************************************************/

ListPlnrJMLayerMaterial::ListPlnrJMLayerMaterial() {
};

ListPlnrJMLayerMaterial::ListPlnrJMLayerMaterial(
			const ListPlnrJMLayerMaterial& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMLayerMaterial(*(src.nodes[i]));
};

ListPlnrJMLayerMaterial::~ListPlnrJMLayerMaterial() {
	clear();
};

void ListPlnrJMLayerMaterial::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMLayerMaterial::size() const {
	return(nodes.size());
};

void ListPlnrJMLayerMaterial::append(
			PlnrJMLayerMaterial* rec
		) {
	nodes.push_back(rec);
};

PlnrJMLayerMaterial* ListPlnrJMLayerMaterial::operator[](
			const uint ix
		) {
	PlnrJMLayerMaterial* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMLayerMaterial& ListPlnrJMLayerMaterial::operator=(
			const ListPlnrJMLayerMaterial& src
		) {
	PlnrJMLayerMaterial* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMLayerMaterial(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMLayerMaterial::operator==(
			const ListPlnrJMLayerMaterial& comp
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

bool ListPlnrJMLayerMaterial::operator!=(
			const ListPlnrJMLayerMaterial& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMLayerMaterial
 ******************************************************************************/

TblPlnrJMLayerMaterial::TblPlnrJMLayerMaterial() {
};

TblPlnrJMLayerMaterial::~TblPlnrJMLayerMaterial() {
};

bool TblPlnrJMLayerMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLayerMaterial** rec
		) {
	return false;
};

ubigint TblPlnrJMLayerMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	return 0;
};

void TblPlnrJMLayerMaterial::insertRec(
			PlnrJMLayerMaterial* rec
		) {
};

ubigint TblPlnrJMLayerMaterial::insertNewRec(
			PlnrJMLayerMaterial** rec
			, const ubigint refPlnrMLayer
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMMaterial
		) {
	ubigint retval = 0;
	PlnrJMLayerMaterial* _rec = NULL;

	_rec = new PlnrJMLayerMaterial(0, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMLayerMaterial::appendNewRecToRst(
			ListPlnrJMLayerMaterial& rst
			, PlnrJMLayerMaterial** rec
			, const ubigint refPlnrMLayer
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMMaterial
		) {
	ubigint retval = 0;
	PlnrJMLayerMaterial* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMLayerMaterial::insertRst(
			ListPlnrJMLayerMaterial& rst
			, bool transact
		) {
};

void TblPlnrJMLayerMaterial::updateRec(
			PlnrJMLayerMaterial* rec
		) {
};

void TblPlnrJMLayerMaterial::updateRst(
			ListPlnrJMLayerMaterial& rst
			, bool transact
		) {
};

void TblPlnrJMLayerMaterial::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMLayerMaterial::loadRecByRef(
			ubigint ref
			, PlnrJMLayerMaterial** rec
		) {
	return false;
};

bool TblPlnrJMLayerMaterial::loadRecByLyrDsn(
			ubigint refPlnrMLayer
			, ubigint x1RefPlnrMDesign
			, PlnrJMLayerMaterial** rec
		) {
	return false;
};

ubigint TblPlnrJMLayerMaterial::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	return 0;
};

ubigint TblPlnrJMLayerMaterial::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	ubigint numload = 0;
	PlnrJMLayerMaterial* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMLayerMaterial
 ******************************************************************************/

MyTblPlnrJMLayerMaterial::MyTblPlnrJMLayerMaterial() : TblPlnrJMLayerMaterial(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMLayerMaterial::~MyTblPlnrJMLayerMaterial() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMLayerMaterial::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMLayerMaterial (refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMLayerMaterial SET refPlnrMLayer = ?, x1RefPlnrMDesign = ?, refPlnrMMaterial = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMLayerMaterial WHERE ref = ?", false);
};

bool MyTblPlnrJMLayerMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLayerMaterial** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMLayerMaterial* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMLayerMaterial / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMLayerMaterial();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMLayer = atoll((char*) dbrow[1]); else _rec->refPlnrMLayer = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->refPlnrMMaterial = atoll((char*) dbrow[3]); else _rec->refPlnrMMaterial = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMLayerMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMLayerMaterial* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMLayerMaterial / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMLayerMaterial();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMLayer = atoll((char*) dbrow[1]); else rec->refPlnrMLayer = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->refPlnrMMaterial = atoll((char*) dbrow[3]); else rec->refPlnrMMaterial = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMLayerMaterial::insertRec(
			PlnrJMLayerMaterial* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLayer,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMMaterial,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLayerMaterial / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLayerMaterial / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMLayerMaterial::insertRst(
			ListPlnrJMLayerMaterial& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMLayerMaterial::updateRec(
			PlnrJMLayerMaterial* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLayer,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMMaterial,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLayerMaterial / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLayerMaterial / stmtUpdateRec)\n");
};

void MyTblPlnrJMLayerMaterial::updateRst(
			ListPlnrJMLayerMaterial& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMLayerMaterial::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLayerMaterial / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLayerMaterial / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMLayerMaterial::loadRecByRef(
			ubigint ref
			, PlnrJMLayerMaterial** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMLayerMaterial WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMLayerMaterial::loadRecByLyrDsn(
			ubigint refPlnrMLayer
			, ubigint x1RefPlnrMDesign
			, PlnrJMLayerMaterial** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE refPlnrMLayer = " + to_string(refPlnrMLayer) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMLayerMaterial::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE refPlnrMLayer = " + to_string(refPlnrMLayer) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMLayerMaterial
 ******************************************************************************/

PgTblPlnrJMLayerMaterial::PgTblPlnrJMLayerMaterial() : TblPlnrJMLayerMaterial(), PgTable() {
};

PgTblPlnrJMLayerMaterial::~PgTblPlnrJMLayerMaterial() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMLayerMaterial::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMLayerMaterial_insertRec", "INSERT INTO TblPlnrJMLayerMaterial (refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLayerMaterial_updateRec", "UPDATE TblPlnrJMLayerMaterial SET refPlnrMLayer = $1, x1RefPlnrMDesign = $2, refPlnrMMaterial = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLayerMaterial_removeRecByRef", "DELETE FROM TblPlnrJMLayerMaterial WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMLayerMaterial_loadRecByRef", "SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMLayerMaterial_loadRecByLyrDsn", "SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE refPlnrMLayer = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLayerMaterial_loadRstByLyr", "SELECT ref, refPlnrMLayer, x1RefPlnrMDesign, refPlnrMMaterial FROM TblPlnrJMLayerMaterial WHERE refPlnrMLayer = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMLayerMaterial::loadRec(
			PGresult* res
			, PlnrJMLayerMaterial** rec
		) {
	char* ptr;

	PlnrJMLayerMaterial* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMLayerMaterial();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "refplnrmmaterial")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMLayer = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMMaterial = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMLayerMaterial::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMLayerMaterial* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlayer"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "refplnrmmaterial")
		};

		while (numread < numrow) {
			rec = new PlnrJMLayerMaterial();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMLayer = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMMaterial = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMLayerMaterial::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMLayerMaterial** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayerMaterial / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMLayerMaterial::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayerMaterial / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMLayerMaterial::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLayerMaterial** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMLayerMaterial::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMLayerMaterial::insertRec(
			PlnrJMLayerMaterial* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_x1RefPlnrMDesign,
		(char*) &_refPlnrMMaterial
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMLayerMaterial_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayerMaterial_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMLayerMaterial::insertRst(
			ListPlnrJMLayerMaterial& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMLayerMaterial::updateRec(
			PlnrJMLayerMaterial* rec
		) {
	PGresult* res;

	ubigint _refPlnrMLayer = htonl64(rec->refPlnrMLayer);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMMaterial = htonl64(rec->refPlnrMMaterial);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_x1RefPlnrMDesign,
		(char*) &_refPlnrMMaterial,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMLayerMaterial_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayerMaterial_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMLayerMaterial::updateRst(
			ListPlnrJMLayerMaterial& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMLayerMaterial::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMLayerMaterial_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLayerMaterial_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMLayerMaterial::loadRecByRef(
			ubigint ref
			, PlnrJMLayerMaterial** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMLayerMaterial_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMLayerMaterial::loadRecByLyrDsn(
			ubigint refPlnrMLayer
			, ubigint x1RefPlnrMDesign
			, PlnrJMLayerMaterial** rec
		) {
	ubigint _refPlnrMLayer = htonl64(refPlnrMLayer);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMLayer,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMLayerMaterial_loadRecByLyrDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMLayerMaterial::loadRstByLyr(
			ubigint refPlnrMLayer
			, const bool append
			, ListPlnrJMLayerMaterial& rst
		) {
	ubigint _refPlnrMLayer = htonl64(refPlnrMLayer);

	const char* vals[] = {
		(char*) &_refPlnrMLayer
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMLayerMaterial_loadRstByLyr", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

