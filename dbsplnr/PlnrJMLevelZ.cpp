/**
  * \file PlnrJMLevelZ.cpp
  * database access for table TblPlnrJMLevelZ (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrJMLevelZ.h"

/******************************************************************************
 class PlnrJMLevelZ
 ******************************************************************************/

PlnrJMLevelZ::PlnrJMLevelZ(
			const ubigint ref
			, const ubigint refPlnrMLevel
			, const ubigint x1RefPlnrMDesign
			, const double z
		) {

	this->ref = ref;
	this->refPlnrMLevel = refPlnrMLevel;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->z = z;
};

bool PlnrJMLevelZ::operator==(
			const PlnrJMLevelZ& comp
		) {
	return false;
};

bool PlnrJMLevelZ::operator!=(
			const PlnrJMLevelZ& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrJMLevelZ
 ******************************************************************************/

ListPlnrJMLevelZ::ListPlnrJMLevelZ() {
};

ListPlnrJMLevelZ::ListPlnrJMLevelZ(
			const ListPlnrJMLevelZ& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrJMLevelZ(*(src.nodes[i]));
};

ListPlnrJMLevelZ::~ListPlnrJMLevelZ() {
	clear();
};

void ListPlnrJMLevelZ::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrJMLevelZ::size() const {
	return(nodes.size());
};

void ListPlnrJMLevelZ::append(
			PlnrJMLevelZ* rec
		) {
	nodes.push_back(rec);
};

PlnrJMLevelZ* ListPlnrJMLevelZ::operator[](
			const uint ix
		) {
	PlnrJMLevelZ* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrJMLevelZ& ListPlnrJMLevelZ::operator=(
			const ListPlnrJMLevelZ& src
		) {
	PlnrJMLevelZ* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrJMLevelZ(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrJMLevelZ::operator==(
			const ListPlnrJMLevelZ& comp
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

bool ListPlnrJMLevelZ::operator!=(
			const ListPlnrJMLevelZ& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrJMLevelZ
 ******************************************************************************/

TblPlnrJMLevelZ::TblPlnrJMLevelZ() {
};

TblPlnrJMLevelZ::~TblPlnrJMLevelZ() {
};

bool TblPlnrJMLevelZ::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLevelZ** rec
		) {
	return false;
};

ubigint TblPlnrJMLevelZ::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	return 0;
};

void TblPlnrJMLevelZ::insertRec(
			PlnrJMLevelZ* rec
		) {
};

ubigint TblPlnrJMLevelZ::insertNewRec(
			PlnrJMLevelZ** rec
			, const ubigint refPlnrMLevel
			, const ubigint x1RefPlnrMDesign
			, const double z
		) {
	ubigint retval = 0;
	PlnrJMLevelZ* _rec = NULL;

	_rec = new PlnrJMLevelZ(0, refPlnrMLevel, x1RefPlnrMDesign, z);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrJMLevelZ::appendNewRecToRst(
			ListPlnrJMLevelZ& rst
			, PlnrJMLevelZ** rec
			, const ubigint refPlnrMLevel
			, const ubigint x1RefPlnrMDesign
			, const double z
		) {
	ubigint retval = 0;
	PlnrJMLevelZ* _rec = NULL;

	retval = insertNewRec(&_rec, refPlnrMLevel, x1RefPlnrMDesign, z);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrJMLevelZ::insertRst(
			ListPlnrJMLevelZ& rst
			, bool transact
		) {
};

void TblPlnrJMLevelZ::updateRec(
			PlnrJMLevelZ* rec
		) {
};

void TblPlnrJMLevelZ::updateRst(
			ListPlnrJMLevelZ& rst
			, bool transact
		) {
};

void TblPlnrJMLevelZ::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrJMLevelZ::loadRecByRef(
			ubigint ref
			, PlnrJMLevelZ** rec
		) {
	return false;
};

bool TblPlnrJMLevelZ::loadRecByLvlDsn(
			ubigint refPlnrMLevel
			, ubigint x1RefPlnrMDesign
			, PlnrJMLevelZ** rec
		) {
	return false;
};

ubigint TblPlnrJMLevelZ::loadRstByLvl(
			ubigint refPlnrMLevel
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	return 0;
};

ubigint TblPlnrJMLevelZ::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	ubigint numload = 0;
	PlnrJMLevelZ* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrJMLevelZ
 ******************************************************************************/

MyTblPlnrJMLevelZ::MyTblPlnrJMLevelZ() : TblPlnrJMLevelZ(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrJMLevelZ::~MyTblPlnrJMLevelZ() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrJMLevelZ::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrJMLevelZ (refPlnrMLevel, x1RefPlnrMDesign, z) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrJMLevelZ SET refPlnrMLevel = ?, x1RefPlnrMDesign = ?, z = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrJMLevelZ WHERE ref = ?", false);
};

bool MyTblPlnrJMLevelZ::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLevelZ** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrJMLevelZ* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMLevelZ / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrJMLevelZ();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->refPlnrMLevel = atoll((char*) dbrow[1]); else _rec->refPlnrMLevel = 0;
		if (dbrow[2]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[3]) _rec->z = atof((char*) dbrow[3]); else _rec->z = 0.0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrJMLevelZ::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrJMLevelZ* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrJMLevelZ / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrJMLevelZ();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->refPlnrMLevel = atoll((char*) dbrow[1]); else rec->refPlnrMLevel = 0;
			if (dbrow[2]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[2]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[3]) rec->z = atof((char*) dbrow[3]); else rec->z = 0.0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrJMLevelZ::insertRec(
			PlnrJMLevelZ* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLevel,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])),
		bindDouble(&rec->z,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLevelZ / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLevelZ / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrJMLevelZ::insertRst(
			ListPlnrJMLevelZ& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrJMLevelZ::updateRec(
			PlnrJMLevelZ* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->refPlnrMLevel,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[1]),&(n[1]),&(e[1])), 
		bindDouble(&rec->z,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLevelZ / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLevelZ / stmtUpdateRec)\n");
};

void MyTblPlnrJMLevelZ::updateRst(
			ListPlnrJMLevelZ& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrJMLevelZ::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrJMLevelZ / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrJMLevelZ / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrJMLevelZ::loadRecByRef(
			ubigint ref
			, PlnrJMLevelZ** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrJMLevelZ WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrJMLevelZ::loadRecByLvlDsn(
			ubigint refPlnrMLevel
			, ubigint x1RefPlnrMDesign
			, PlnrJMLevelZ** rec
		) {
	return loadRecBySQL("SELECT ref, refPlnrMLevel, x1RefPlnrMDesign, z FROM TblPlnrJMLevelZ WHERE refPlnrMLevel = " + to_string(refPlnrMLevel) + " AND x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + "", rec);
};

ubigint MyTblPlnrJMLevelZ::loadRstByLvl(
			ubigint refPlnrMLevel
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	return loadRstBySQL("SELECT ref, refPlnrMLevel, x1RefPlnrMDesign, z FROM TblPlnrJMLevelZ WHERE refPlnrMLevel = " + to_string(refPlnrMLevel) + " ORDER BY x1RefPlnrMDesign ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrJMLevelZ
 ******************************************************************************/

PgTblPlnrJMLevelZ::PgTblPlnrJMLevelZ() : TblPlnrJMLevelZ(), PgTable() {
};

PgTblPlnrJMLevelZ::~PgTblPlnrJMLevelZ() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrJMLevelZ::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrJMLevelZ_insertRec", "INSERT INTO TblPlnrJMLevelZ (refPlnrMLevel, x1RefPlnrMDesign, z) VALUES ($1,$2,$3) RETURNING ref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLevelZ_updateRec", "UPDATE TblPlnrJMLevelZ SET refPlnrMLevel = $1, x1RefPlnrMDesign = $2, z = $3 WHERE ref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLevelZ_removeRecByRef", "DELETE FROM TblPlnrJMLevelZ WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrJMLevelZ_loadRecByRef", "SELECT ref, refPlnrMLevel, x1RefPlnrMDesign, z FROM TblPlnrJMLevelZ WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrJMLevelZ_loadRecByLvlDsn", "SELECT ref, refPlnrMLevel, x1RefPlnrMDesign, z FROM TblPlnrJMLevelZ WHERE refPlnrMLevel = $1 AND x1RefPlnrMDesign = $2", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrJMLevelZ_loadRstByLvl", "SELECT ref, refPlnrMLevel, x1RefPlnrMDesign, z FROM TblPlnrJMLevelZ WHERE refPlnrMLevel = $1 ORDER BY x1RefPlnrMDesign ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrJMLevelZ::loadRec(
			PGresult* res
			, PlnrJMLevelZ** rec
		) {
	char* ptr;

	PlnrJMLevelZ* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrJMLevelZ();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlevel"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "z")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->refPlnrMLevel = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->z = atof(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrJMLevelZ::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrJMLevelZ* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "refplnrmlevel"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "z")
		};

		while (numread < numrow) {
			rec = new PlnrJMLevelZ();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->refPlnrMLevel = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->z = atof(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrJMLevelZ::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrJMLevelZ** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLevelZ / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrJMLevelZ::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLevelZ / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrJMLevelZ::loadRecBySQL(
			const string& sqlstr
			, PlnrJMLevelZ** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrJMLevelZ::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrJMLevelZ::insertRec(
			PlnrJMLevelZ* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _refPlnrMLevel = htonl64(rec->refPlnrMLevel);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	string _z = to_string(rec->z);

	const char* vals[] = {
		(char*) &_refPlnrMLevel,
		(char*) &_x1RefPlnrMDesign,
		_z.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrJMLevelZ_insertRec", 3, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLevelZ_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrJMLevelZ::insertRst(
			ListPlnrJMLevelZ& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrJMLevelZ::updateRec(
			PlnrJMLevelZ* rec
		) {
	PGresult* res;

	ubigint _refPlnrMLevel = htonl64(rec->refPlnrMLevel);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	string _z = to_string(rec->z);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_refPlnrMLevel,
		(char*) &_x1RefPlnrMDesign,
		_z.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrJMLevelZ_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLevelZ_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrJMLevelZ::updateRst(
			ListPlnrJMLevelZ& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrJMLevelZ::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrJMLevelZ_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrJMLevelZ_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrJMLevelZ::loadRecByRef(
			ubigint ref
			, PlnrJMLevelZ** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrJMLevelZ_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrJMLevelZ::loadRecByLvlDsn(
			ubigint refPlnrMLevel
			, ubigint x1RefPlnrMDesign
			, PlnrJMLevelZ** rec
		) {
	ubigint _refPlnrMLevel = htonl64(refPlnrMLevel);
	ubigint _x1RefPlnrMDesign = htonl64(x1RefPlnrMDesign);

	const char* vals[] = {
		(char*) &_refPlnrMLevel,
		(char*) &_x1RefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1,1};

	return loadRecByStmt("TblPlnrJMLevelZ_loadRecByLvlDsn", 2, vals, l, f, rec);
};

ubigint PgTblPlnrJMLevelZ::loadRstByLvl(
			ubigint refPlnrMLevel
			, const bool append
			, ListPlnrJMLevelZ& rst
		) {
	ubigint _refPlnrMLevel = htonl64(refPlnrMLevel);

	const char* vals[] = {
		(char*) &_refPlnrMLevel
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrJMLevelZ_loadRstByLvl", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

