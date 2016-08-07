/**
  * \file PlnrRMCalcMFile.cpp
  * database access for table TblPlnrRMCalcMFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrRMCalcMFile.h"

/******************************************************************************
 class PlnrRMCalcMFile
 ******************************************************************************/

PlnrRMCalcMFile::PlnrRMCalcMFile(
			const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMFile
			, const uint ixVIo
		) {

	this->ref = ref;
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->refPlnrMCalc = refPlnrMCalc;
	this->refPlnrMFile = refPlnrMFile;
	this->ixVIo = ixVIo;
};

bool PlnrRMCalcMFile::operator==(
			const PlnrRMCalcMFile& comp
		) {
	return false;
};

bool PlnrRMCalcMFile::operator!=(
			const PlnrRMCalcMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrRMCalcMFile
 ******************************************************************************/

ListPlnrRMCalcMFile::ListPlnrRMCalcMFile() {
};

ListPlnrRMCalcMFile::ListPlnrRMCalcMFile(
			const ListPlnrRMCalcMFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrRMCalcMFile(*(src.nodes[i]));
};

ListPlnrRMCalcMFile::~ListPlnrRMCalcMFile() {
	clear();
};

void ListPlnrRMCalcMFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrRMCalcMFile::size() const {
	return(nodes.size());
};

void ListPlnrRMCalcMFile::append(
			PlnrRMCalcMFile* rec
		) {
	nodes.push_back(rec);
};

PlnrRMCalcMFile* ListPlnrRMCalcMFile::operator[](
			const uint ix
		) {
	PlnrRMCalcMFile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrRMCalcMFile& ListPlnrRMCalcMFile::operator=(
			const ListPlnrRMCalcMFile& src
		) {
	PlnrRMCalcMFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrRMCalcMFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrRMCalcMFile::operator==(
			const ListPlnrRMCalcMFile& comp
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

bool ListPlnrRMCalcMFile::operator!=(
			const ListPlnrRMCalcMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrRMCalcMFile
 ******************************************************************************/

TblPlnrRMCalcMFile::TblPlnrRMCalcMFile() {
};

TblPlnrRMCalcMFile::~TblPlnrRMCalcMFile() {
};

bool TblPlnrRMCalcMFile::loadRecBySQL(
			const string& sqlstr
			, PlnrRMCalcMFile** rec
		) {
	return false;
};

ubigint TblPlnrRMCalcMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMCalcMFile& rst
		) {
	return 0;
};

void TblPlnrRMCalcMFile::insertRec(
			PlnrRMCalcMFile* rec
		) {
};

ubigint TblPlnrRMCalcMFile::insertNewRec(
			PlnrRMCalcMFile** rec
			, const ubigint x1RefPlnrMCalcitem
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMFile
			, const uint ixVIo
		) {
	ubigint retval = 0;
	PlnrRMCalcMFile* _rec = NULL;

	_rec = new PlnrRMCalcMFile(0, x1RefPlnrMCalcitem, refPlnrMCalc, refPlnrMFile, ixVIo);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrRMCalcMFile::appendNewRecToRst(
			ListPlnrRMCalcMFile& rst
			, PlnrRMCalcMFile** rec
			, const ubigint x1RefPlnrMCalcitem
			, const ubigint refPlnrMCalc
			, const ubigint refPlnrMFile
			, const uint ixVIo
		) {
	ubigint retval = 0;
	PlnrRMCalcMFile* _rec = NULL;

	retval = insertNewRec(&_rec, x1RefPlnrMCalcitem, refPlnrMCalc, refPlnrMFile, ixVIo);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrRMCalcMFile::insertRst(
			ListPlnrRMCalcMFile& rst
			, bool transact
		) {
};

void TblPlnrRMCalcMFile::updateRec(
			PlnrRMCalcMFile* rec
		) {
};

void TblPlnrRMCalcMFile::updateRst(
			ListPlnrRMCalcMFile& rst
			, bool transact
		) {
};

void TblPlnrRMCalcMFile::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrRMCalcMFile::loadRecByRef(
			ubigint ref
			, PlnrRMCalcMFile** rec
		) {
	return false;
};

ubigint TblPlnrRMCalcMFile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrRMCalcMFile& rst
		) {
	ubigint numload = 0;
	PlnrRMCalcMFile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrRMCalcMFile
 ******************************************************************************/

MyTblPlnrRMCalcMFile::MyTblPlnrRMCalcMFile() : TblPlnrRMCalcMFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrRMCalcMFile::~MyTblPlnrRMCalcMFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrRMCalcMFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrRMCalcMFile (x1RefPlnrMCalcitem, refPlnrMCalc, refPlnrMFile, ixVIo) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrRMCalcMFile SET x1RefPlnrMCalcitem = ?, refPlnrMCalc = ?, refPlnrMFile = ?, ixVIo = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrRMCalcMFile WHERE ref = ?", false);
};

bool MyTblPlnrRMCalcMFile::loadRecBySQL(
			const string& sqlstr
			, PlnrRMCalcMFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrRMCalcMFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMCalcMFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrRMCalcMFile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[1]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[2]) _rec->refPlnrMCalc = atoll((char*) dbrow[2]); else _rec->refPlnrMCalc = 0;
		if (dbrow[3]) _rec->refPlnrMFile = atoll((char*) dbrow[3]); else _rec->refPlnrMFile = 0;
		if (dbrow[4]) _rec->ixVIo = atol((char*) dbrow[4]); else _rec->ixVIo = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrRMCalcMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMCalcMFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrRMCalcMFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrRMCalcMFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrRMCalcMFile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[1]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[2]) rec->refPlnrMCalc = atoll((char*) dbrow[2]); else rec->refPlnrMCalc = 0;
			if (dbrow[3]) rec->refPlnrMFile = atoll((char*) dbrow[3]); else rec->refPlnrMFile = 0;
			if (dbrow[4]) rec->ixVIo = atol((char*) dbrow[4]); else rec->ixVIo = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrRMCalcMFile::insertRec(
			PlnrRMCalcMFile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->refPlnrMCalc,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->ixVIo,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMCalcMFile / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMCalcMFile / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrRMCalcMFile::insertRst(
			ListPlnrRMCalcMFile& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrRMCalcMFile::updateRec(
			PlnrRMCalcMFile* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->refPlnrMCalc,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMFile,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->ixVIo,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMCalcMFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMCalcMFile / stmtUpdateRec)\n");
};

void MyTblPlnrRMCalcMFile::updateRst(
			ListPlnrRMCalcMFile& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrRMCalcMFile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrRMCalcMFile / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrRMCalcMFile / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrRMCalcMFile::loadRecByRef(
			ubigint ref
			, PlnrRMCalcMFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrRMCalcMFile WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrRMCalcMFile
 ******************************************************************************/

PgTblPlnrRMCalcMFile::PgTblPlnrRMCalcMFile() : TblPlnrRMCalcMFile(), PgTable() {
};

PgTblPlnrRMCalcMFile::~PgTblPlnrRMCalcMFile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrRMCalcMFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrRMCalcMFile_insertRec", "INSERT INTO TblPlnrRMCalcMFile (x1RefPlnrMCalcitem, refPlnrMCalc, refPlnrMFile, ixVIo) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMCalcMFile_updateRec", "UPDATE TblPlnrRMCalcMFile SET x1RefPlnrMCalcitem = $1, refPlnrMCalc = $2, refPlnrMFile = $3, ixVIo = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrRMCalcMFile_removeRecByRef", "DELETE FROM TblPlnrRMCalcMFile WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrRMCalcMFile_loadRecByRef", "SELECT ref, x1RefPlnrMCalcitem, refPlnrMCalc, refPlnrMFile, ixVIo FROM TblPlnrRMCalcMFile WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrRMCalcMFile::loadRec(
			PGresult* res
			, PlnrRMCalcMFile** rec
		) {
	char* ptr;

	PlnrRMCalcMFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrRMCalcMFile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "ixvio")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->refPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ixVIo = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrRMCalcMFile::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrRMCalcMFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrRMCalcMFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "refplnrmcalc"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "ixvio")
		};

		while (numread < numrow) {
			rec = new PlnrRMCalcMFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->refPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ixVIo = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrRMCalcMFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrRMCalcMFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrRMCalcMFile::loadRecBySQL(
			const string& sqlstr
			, PlnrRMCalcMFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrRMCalcMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrRMCalcMFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrRMCalcMFile::insertRec(
			PlnrRMCalcMFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	uint _ixVIo = htonl(rec->ixVIo);

	const char* vals[] = {
		(char*) &_x1RefPlnrMCalcitem,
		(char*) &_refPlnrMCalc,
		(char*) &_refPlnrMFile,
		(char*) &_ixVIo
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMCalcMFile_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrRMCalcMFile::insertRst(
			ListPlnrRMCalcMFile& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrRMCalcMFile::updateRec(
			PlnrRMCalcMFile* rec
		) {
	PGresult* res;

	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	ubigint _refPlnrMCalc = htonl64(rec->refPlnrMCalc);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	uint _ixVIo = htonl(rec->ixVIo);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_x1RefPlnrMCalcitem,
		(char*) &_refPlnrMCalc,
		(char*) &_refPlnrMFile,
		(char*) &_ixVIo,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrRMCalcMFile_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMFile_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrRMCalcMFile::updateRst(
			ListPlnrRMCalcMFile& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrRMCalcMFile::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrRMCalcMFile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrRMCalcMFile_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrRMCalcMFile::loadRecByRef(
			ubigint ref
			, PlnrRMCalcMFile** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrRMCalcMFile_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

