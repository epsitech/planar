/**
  * \file PlnrAVValuelistVal.cpp
  * database access for table TblPlnrAVValuelistVal (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAVValuelistVal.h"

/******************************************************************************
 class PlnrAVValuelistVal
 ******************************************************************************/

PlnrAVValuelistVal::PlnrAVValuelistVal(
			const ubigint ref
			, const uint vlsIxPlnrVValuelist
			, const uint vlsNum
			, const uint x1IxPlnrVLocale
			, const string Val
		) {

	this->ref = ref;
	this->vlsIxPlnrVValuelist = vlsIxPlnrVValuelist;
	this->vlsNum = vlsNum;
	this->x1IxPlnrVLocale = x1IxPlnrVLocale;
	this->Val = Val;
};

bool PlnrAVValuelistVal::operator==(
			const PlnrAVValuelistVal& comp
		) {
	return false;
};

bool PlnrAVValuelistVal::operator!=(
			const PlnrAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAVValuelistVal
 ******************************************************************************/

ListPlnrAVValuelistVal::ListPlnrAVValuelistVal() {
};

ListPlnrAVValuelistVal::ListPlnrAVValuelistVal(
			const ListPlnrAVValuelistVal& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAVValuelistVal(*(src.nodes[i]));
};

ListPlnrAVValuelistVal::~ListPlnrAVValuelistVal() {
	clear();
};

void ListPlnrAVValuelistVal::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAVValuelistVal::size() const {
	return(nodes.size());
};

void ListPlnrAVValuelistVal::append(
			PlnrAVValuelistVal* rec
		) {
	nodes.push_back(rec);
};

PlnrAVValuelistVal* ListPlnrAVValuelistVal::operator[](
			const uint ix
		) {
	PlnrAVValuelistVal* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAVValuelistVal& ListPlnrAVValuelistVal::operator=(
			const ListPlnrAVValuelistVal& src
		) {
	PlnrAVValuelistVal* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAVValuelistVal(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAVValuelistVal::operator==(
			const ListPlnrAVValuelistVal& comp
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

bool ListPlnrAVValuelistVal::operator!=(
			const ListPlnrAVValuelistVal& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAVValuelistVal
 ******************************************************************************/

TblPlnrAVValuelistVal::TblPlnrAVValuelistVal() {
};

TblPlnrAVValuelistVal::~TblPlnrAVValuelistVal() {
};

bool TblPlnrAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, PlnrAVValuelistVal** rec
		) {
	return false;
};

ubigint TblPlnrAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	return 0;
};

void TblPlnrAVValuelistVal::insertRec(
			PlnrAVValuelistVal* rec
		) {
};

ubigint TblPlnrAVValuelistVal::insertNewRec(
			PlnrAVValuelistVal** rec
			, const uint vlsIxPlnrVValuelist
			, const uint vlsNum
			, const uint x1IxPlnrVLocale
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAVValuelistVal* _rec = NULL;

	_rec = new PlnrAVValuelistVal(0, vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAVValuelistVal::appendNewRecToRst(
			ListPlnrAVValuelistVal& rst
			, PlnrAVValuelistVal** rec
			, const uint vlsIxPlnrVValuelist
			, const uint vlsNum
			, const uint x1IxPlnrVLocale
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAVValuelistVal* _rec = NULL;

	retval = insertNewRec(&_rec, vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAVValuelistVal::insertRst(
			ListPlnrAVValuelistVal& rst
			, bool transact
		) {
};

void TblPlnrAVValuelistVal::updateRec(
			PlnrAVValuelistVal* rec
		) {
};

void TblPlnrAVValuelistVal::updateRst(
			ListPlnrAVValuelistVal& rst
			, bool transact
		) {
};

void TblPlnrAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAVValuelistVal::loadRecByRef(
			ubigint ref
			, PlnrAVValuelistVal** rec
		) {
	return false;
};

ubigint TblPlnrAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxPlnrVValuelist
			, uint x1IxPlnrVLocale
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	return 0;
};

ubigint TblPlnrAVValuelistVal::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	ubigint numload = 0;
	PlnrAVValuelistVal* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAVValuelistVal
 ******************************************************************************/

MyTblPlnrAVValuelistVal::MyTblPlnrAVValuelistVal() : TblPlnrAVValuelistVal(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAVValuelistVal::~MyTblPlnrAVValuelistVal() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAVValuelistVal::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAVValuelistVal (vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val) VALUES (?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAVValuelistVal SET vlsIxPlnrVValuelist = ?, vlsNum = ?, x1IxPlnrVLocale = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAVValuelistVal WHERE ref = ?", false);
};

bool MyTblPlnrAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, PlnrAVValuelistVal** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAVValuelistVal* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAVValuelistVal / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAVValuelistVal();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->vlsIxPlnrVValuelist = atol((char*) dbrow[1]); else _rec->vlsIxPlnrVValuelist = 0;
		if (dbrow[2]) _rec->vlsNum = atol((char*) dbrow[2]); else _rec->vlsNum = 0;
		if (dbrow[3]) _rec->x1IxPlnrVLocale = atol((char*) dbrow[3]); else _rec->x1IxPlnrVLocale = 0;
		if (dbrow[4]) _rec->Val.assign(dbrow[4], dblengths[4]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAVValuelistVal* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAVValuelistVal / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAVValuelistVal();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->vlsIxPlnrVValuelist = atol((char*) dbrow[1]); else rec->vlsIxPlnrVValuelist = 0;
			if (dbrow[2]) rec->vlsNum = atol((char*) dbrow[2]); else rec->vlsNum = 0;
			if (dbrow[3]) rec->x1IxPlnrVLocale = atol((char*) dbrow[3]); else rec->x1IxPlnrVLocale = 0;
			if (dbrow[4]) rec->Val.assign(dbrow[4], dblengths[4]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAVValuelistVal::insertRec(
			PlnrAVValuelistVal* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxPlnrVValuelist,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x1IxPlnrVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVValuelistVal / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVValuelistVal / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAVValuelistVal::insertRst(
			ListPlnrAVValuelistVal& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAVValuelistVal::updateRec(
			PlnrAVValuelistVal* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->vlsIxPlnrVValuelist,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->vlsNum,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x1IxPlnrVLocale,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->ref,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVValuelistVal / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVValuelistVal / stmtUpdateRec)\n");
};

void MyTblPlnrAVValuelistVal::updateRst(
			ListPlnrAVValuelistVal& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAVValuelistVal::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVValuelistVal / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVValuelistVal / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAVValuelistVal::loadRecByRef(
			ubigint ref
			, PlnrAVValuelistVal** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAVValuelistVal WHERE ref = " + to_string(ref), rec);
};

ubigint MyTblPlnrAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxPlnrVValuelist
			, uint x1IxPlnrVLocale
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	return loadRstBySQL("SELECT ref, vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val FROM TblPlnrAVValuelistVal WHERE vlsIxPlnrVValuelist = " + to_string(vlsIxPlnrVValuelist) + " AND x1IxPlnrVLocale = " + to_string(x1IxPlnrVLocale) + " ORDER BY vlsNum ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAVValuelistVal
 ******************************************************************************/

PgTblPlnrAVValuelistVal::PgTblPlnrAVValuelistVal() : TblPlnrAVValuelistVal(), PgTable() {
};

PgTblPlnrAVValuelistVal::~PgTblPlnrAVValuelistVal() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAVValuelistVal::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAVValuelistVal_insertRec", "INSERT INTO TblPlnrAVValuelistVal (vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val) VALUES ($1,$2,$3,$4) RETURNING ref", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVValuelistVal_updateRec", "UPDATE TblPlnrAVValuelistVal SET vlsIxPlnrVValuelist = $1, vlsNum = $2, x1IxPlnrVLocale = $3, Val = $4 WHERE ref = $5", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVValuelistVal_removeRecByRef", "DELETE FROM TblPlnrAVValuelistVal WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAVValuelistVal_loadRecByRef", "SELECT ref, vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val FROM TblPlnrAVValuelistVal WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrAVValuelistVal_loadRstByVlsLcl", "SELECT ref, vlsIxPlnrVValuelist, vlsNum, x1IxPlnrVLocale, Val FROM TblPlnrAVValuelistVal WHERE vlsIxPlnrVValuelist = $1 AND x1IxPlnrVLocale = $2 ORDER BY vlsNum ASC", 2, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrAVValuelistVal::loadRec(
			PGresult* res
			, PlnrAVValuelistVal** rec
		) {
	char* ptr;

	PlnrAVValuelistVal* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAVValuelistVal();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixplnrvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixplnrvlocale"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->vlsIxPlnrVValuelist = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->vlsNum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x1IxPlnrVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[4]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAVValuelistVal::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAVValuelistVal* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "vlsixplnrvvaluelist"),
			PQfnumber(res, "vlsnum"),
			PQfnumber(res, "x1ixplnrvlocale"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAVValuelistVal();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->vlsIxPlnrVValuelist = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->vlsNum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x1IxPlnrVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[4]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAVValuelistVal::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVValuelistVal / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrAVValuelistVal::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVValuelistVal / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrAVValuelistVal::loadRecBySQL(
			const string& sqlstr
			, PlnrAVValuelistVal** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAVValuelistVal::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAVValuelistVal::insertRec(
			PlnrAVValuelistVal* rec
		) {
	PGresult* res;
	char* ptr;

	uint _vlsIxPlnrVValuelist = htonl(rec->vlsIxPlnrVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxPlnrVLocale = htonl(rec->x1IxPlnrVLocale);

	const char* vals[] = {
		(char*) &_vlsIxPlnrVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxPlnrVLocale,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrAVValuelistVal_insertRec", 4, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVValuelistVal_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAVValuelistVal::insertRst(
			ListPlnrAVValuelistVal& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAVValuelistVal::updateRec(
			PlnrAVValuelistVal* rec
		) {
	PGresult* res;

	uint _vlsIxPlnrVValuelist = htonl(rec->vlsIxPlnrVValuelist);
	uint _vlsNum = htonl(rec->vlsNum);
	uint _x1IxPlnrVLocale = htonl(rec->x1IxPlnrVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_vlsIxPlnrVValuelist,
		(char*) &_vlsNum,
		(char*) &_x1IxPlnrVLocale,
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint),
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAVValuelistVal_updateRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVValuelistVal_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAVValuelistVal::updateRst(
			ListPlnrAVValuelistVal& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAVValuelistVal::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAVValuelistVal_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVValuelistVal_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAVValuelistVal::loadRecByRef(
			ubigint ref
			, PlnrAVValuelistVal** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAVValuelistVal_loadRecByRef", 1, vals, l, f, rec);
};

ubigint PgTblPlnrAVValuelistVal::loadRstByVlsLcl(
			uint vlsIxPlnrVValuelist
			, uint x1IxPlnrVLocale
			, const bool append
			, ListPlnrAVValuelistVal& rst
		) {
	uint _vlsIxPlnrVValuelist = htonl(vlsIxPlnrVValuelist);
	uint _x1IxPlnrVLocale = htonl(x1IxPlnrVLocale);

	const char* vals[] = {
		(char*) &_vlsIxPlnrVValuelist,
		(char*) &_x1IxPlnrVLocale
	};
	const int l[] = {
		sizeof(uint),
		sizeof(uint)
	};
	const int f[] = {1,1};

	return loadRstByStmt("TblPlnrAVValuelistVal_loadRstByVlsLcl", 2, vals, l, f, append, rst);
};

// IP pgTbl --- END

