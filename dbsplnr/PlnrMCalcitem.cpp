/**
  * \file PlnrMCalcitem.cpp
  * database access for table TblPlnrMCalcitem (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMCalcitem.h"

/******************************************************************************
 class PlnrMCalcitem
 ******************************************************************************/

PlnrMCalcitem::PlnrMCalcitem(
			const ubigint ref
			, const ubigint calRefPlnrMCalc
			, const uint calNum
			, const ubigint refPlnrMDesign
			, const string Title
		) {

	this->ref = ref;
	this->calRefPlnrMCalc = calRefPlnrMCalc;
	this->calNum = calNum;
	this->refPlnrMDesign = refPlnrMDesign;
	this->Title = Title;
};

bool PlnrMCalcitem::operator==(
			const PlnrMCalcitem& comp
		) {
	return false;
};

bool PlnrMCalcitem::operator!=(
			const PlnrMCalcitem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMCalcitem
 ******************************************************************************/

ListPlnrMCalcitem::ListPlnrMCalcitem() {
};

ListPlnrMCalcitem::ListPlnrMCalcitem(
			const ListPlnrMCalcitem& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMCalcitem(*(src.nodes[i]));
};

ListPlnrMCalcitem::~ListPlnrMCalcitem() {
	clear();
};

void ListPlnrMCalcitem::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMCalcitem::size() const {
	return(nodes.size());
};

void ListPlnrMCalcitem::append(
			PlnrMCalcitem* rec
		) {
	nodes.push_back(rec);
};

PlnrMCalcitem* ListPlnrMCalcitem::operator[](
			const uint ix
		) {
	PlnrMCalcitem* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMCalcitem& ListPlnrMCalcitem::operator=(
			const ListPlnrMCalcitem& src
		) {
	PlnrMCalcitem* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMCalcitem(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMCalcitem::operator==(
			const ListPlnrMCalcitem& comp
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

bool ListPlnrMCalcitem::operator!=(
			const ListPlnrMCalcitem& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMCalcitem
 ******************************************************************************/

TblPlnrMCalcitem::TblPlnrMCalcitem() {
};

TblPlnrMCalcitem::~TblPlnrMCalcitem() {
};

bool TblPlnrMCalcitem::loadRecBySQL(
			const string& sqlstr
			, PlnrMCalcitem** rec
		) {
	return false;
};

ubigint TblPlnrMCalcitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	return 0;
};

void TblPlnrMCalcitem::insertRec(
			PlnrMCalcitem* rec
		) {
};

ubigint TblPlnrMCalcitem::insertNewRec(
			PlnrMCalcitem** rec
			, const ubigint calRefPlnrMCalc
			, const uint calNum
			, const ubigint refPlnrMDesign
			, const string Title
		) {
	ubigint retval = 0;
	PlnrMCalcitem* _rec = NULL;

	_rec = new PlnrMCalcitem(0, calRefPlnrMCalc, calNum, refPlnrMDesign, Title);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMCalcitem::appendNewRecToRst(
			ListPlnrMCalcitem& rst
			, PlnrMCalcitem** rec
			, const ubigint calRefPlnrMCalc
			, const uint calNum
			, const ubigint refPlnrMDesign
			, const string Title
		) {
	ubigint retval = 0;
	PlnrMCalcitem* _rec = NULL;

	retval = insertNewRec(&_rec, calRefPlnrMCalc, calNum, refPlnrMDesign, Title);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMCalcitem::insertRst(
			ListPlnrMCalcitem& rst
			, bool transact
		) {
};

void TblPlnrMCalcitem::updateRec(
			PlnrMCalcitem* rec
		) {
};

void TblPlnrMCalcitem::updateRst(
			ListPlnrMCalcitem& rst
			, bool transact
		) {
};

void TblPlnrMCalcitem::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMCalcitem::loadRecByRef(
			ubigint ref
			, PlnrMCalcitem** rec
		) {
	return false;
};

ubigint TblPlnrMCalcitem::loadRstByCal(
			ubigint calRefPlnrMCalc
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	return 0;
};

bool TblPlnrMCalcitem::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMCalcitem::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	ubigint numload = 0;
	PlnrMCalcitem* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMCalcitem
 ******************************************************************************/

MyTblPlnrMCalcitem::MyTblPlnrMCalcitem() : TblPlnrMCalcitem(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMCalcitem::~MyTblPlnrMCalcitem() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMCalcitem::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMCalcitem (calRefPlnrMCalc, calNum, refPlnrMDesign, Title) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMCalcitem SET calRefPlnrMCalc = ?, calNum = ?, refPlnrMDesign = ?, Title = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMCalcitem WHERE ref = ?", false);
};

bool MyTblPlnrMCalcitem::loadRecBySQL(
			const string& sqlstr
			, PlnrMCalcitem** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMCalcitem* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMCalcitem / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMCalcitem();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->calRefPlnrMCalc = atoll((char*) dbrow[1]); else _rec->calRefPlnrMCalc = 0;
		if (dbrow[2]) _rec->calNum = atol((char*) dbrow[2]); else _rec->calNum = 0;
		if (dbrow[3]) _rec->refPlnrMDesign = atoll((char*) dbrow[3]); else _rec->refPlnrMDesign = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMCalcitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMCalcitem* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMCalcitem / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMCalcitem();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->calRefPlnrMCalc = atoll((char*) dbrow[1]); else rec->calRefPlnrMCalc = 0;
			if (dbrow[2]) rec->calNum = atol((char*) dbrow[2]); else rec->calNum = 0;
			if (dbrow[3]) rec->refPlnrMDesign = atoll((char*) dbrow[3]); else rec->refPlnrMDesign = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMCalcitem::insertRec(
			PlnrMCalcitem* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->calRefPlnrMCalc,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->calNum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrMDesign,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMCalcitem / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMCalcitem / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMCalcitem::insertRst(
			ListPlnrMCalcitem& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMCalcitem::updateRec(
			PlnrMCalcitem* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->calRefPlnrMCalc,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->calNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrMDesign,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMCalcitem / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMCalcitem / stmtUpdateRec)\n");
};

void MyTblPlnrMCalcitem::updateRst(
			ListPlnrMCalcitem& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMCalcitem::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMCalcitem / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMCalcitem / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMCalcitem::loadRecByRef(
			ubigint ref
			, PlnrMCalcitem** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMCalcitem WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrMCalcitem::loadRstByCal(
			ubigint calRefPlnrMCalc
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	return loadRstBySQL("SELECT ref, calRefPlnrMCalc, calNum, refPlnrMDesign, Title FROM TblPlnrMCalcitem WHERE calRefPlnrMCalc = " + to_string(calRefPlnrMCalc) + " ORDER BY calNum ASC", append, rst);
};

bool MyTblPlnrMCalcitem::loadTitByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Title FROM TblPlnrMCalcitem WHERE ref = " + to_string(ref) + "", val);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMCalcitem
 ******************************************************************************/

PgTblPlnrMCalcitem::PgTblPlnrMCalcitem() : TblPlnrMCalcitem(), PgTable() {
};

PgTblPlnrMCalcitem::~PgTblPlnrMCalcitem() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMCalcitem::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMCalcitem_insertRec", "INSERT INTO TblPlnrMCalcitem (calRefPlnrMCalc, calNum, refPlnrMDesign, Title) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalcitem_updateRec", "UPDATE TblPlnrMCalcitem SET calRefPlnrMCalc = $1, calNum = $2, refPlnrMDesign = $3, Title = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalcitem_removeRecByRef", "DELETE FROM TblPlnrMCalcitem WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMCalcitem_loadRecByRef", "SELECT ref, calRefPlnrMCalc, calNum, refPlnrMDesign, Title FROM TblPlnrMCalcitem WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMCalcitem_loadRstByCal", "SELECT ref, calRefPlnrMCalc, calNum, refPlnrMDesign, Title FROM TblPlnrMCalcitem WHERE calRefPlnrMCalc = $1 ORDER BY calNum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMCalcitem_loadTitByRef", "SELECT Title FROM TblPlnrMCalcitem WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMCalcitem::loadRec(
			PGresult* res
			, PlnrMCalcitem** rec
		) {
	char* ptr;

	PlnrMCalcitem* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMCalcitem();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "calrefplnrmcalc"),
			PQfnumber(res, "calnum"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "title")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->calRefPlnrMCalc = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->calNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMCalcitem::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMCalcitem* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "calrefplnrmcalc"),
			PQfnumber(res, "calnum"),
			PQfnumber(res, "refplnrmdesign"),
			PQfnumber(res, "title")
		};

		while (numread < numrow) {
			rec = new PlnrMCalcitem();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->calRefPlnrMCalc = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->calNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMCalcitem::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMCalcitem** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalcitem / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMCalcitem::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalcitem / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMCalcitem::loadRecBySQL(
			const string& sqlstr
			, PlnrMCalcitem** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMCalcitem::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMCalcitem::insertRec(
			PlnrMCalcitem* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _calRefPlnrMCalc = htonl64(rec->calRefPlnrMCalc);
	uint _calNum = htonl(rec->calNum);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);

	const char* vals[] = {
		(char*) &_calRefPlnrMCalc,
		(char*) &_calNum,
		(char*) &_refPlnrMDesign,
		rec->Title.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMCalcitem_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalcitem_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMCalcitem::insertRst(
			ListPlnrMCalcitem& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMCalcitem::updateRec(
			PlnrMCalcitem* rec
		) {
	PGresult* res;

	ubigint _calRefPlnrMCalc = htonl64(rec->calRefPlnrMCalc);
	uint _calNum = htonl(rec->calNum);
	ubigint _refPlnrMDesign = htonl64(rec->refPlnrMDesign);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_calRefPlnrMCalc,
		(char*) &_calNum,
		(char*) &_refPlnrMDesign,
		rec->Title.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMCalcitem_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalcitem_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMCalcitem::updateRst(
			ListPlnrMCalcitem& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMCalcitem::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrMCalcitem_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMCalcitem_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMCalcitem::loadRecByRef(
			ubigint ref
			, PlnrMCalcitem** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMCalcitem_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrMCalcitem::loadRstByCal(
			ubigint calRefPlnrMCalc
			, const bool append
			, ListPlnrMCalcitem& rst
		) {
	ubigint _calRefPlnrMCalc = htonl64(calRefPlnrMCalc);

	const char* vals[] = {
		(char*) &_calRefPlnrMCalc
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMCalcitem_loadRstByCal", 1, vals, l, f, append, rst);
};

bool PgTblPlnrMCalcitem::loadTitByRef(
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

	return loadStringByStmt("TblPlnrMCalcitem_loadTitByRef", 1, vals, l, f, val);
};

// IP pgTbl --- END

