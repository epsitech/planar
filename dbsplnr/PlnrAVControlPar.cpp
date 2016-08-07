/**
  * \file PlnrAVControlPar.cpp
  * database access for table TblPlnrAVControlPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrAVControlPar.h"

/******************************************************************************
 class PlnrAVControlPar
 ******************************************************************************/

PlnrAVControlPar::PlnrAVControlPar(
			const ubigint ref
			, const uint ixPlnrVControl
			, const ubigint x1RefPlnrMUser
			, const uint x2IxPlnrVLocale
			, const string Par
			, const string Val
		) {

	this->ref = ref;
	this->ixPlnrVControl = ixPlnrVControl;
	this->x1RefPlnrMUser = x1RefPlnrMUser;
	this->x2IxPlnrVLocale = x2IxPlnrVLocale;
	this->Par = Par;
	this->Val = Val;
};

bool PlnrAVControlPar::operator==(
			const PlnrAVControlPar& comp
		) {
	return false;
};

bool PlnrAVControlPar::operator!=(
			const PlnrAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrAVControlPar
 ******************************************************************************/

ListPlnrAVControlPar::ListPlnrAVControlPar() {
};

ListPlnrAVControlPar::ListPlnrAVControlPar(
			const ListPlnrAVControlPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrAVControlPar(*(src.nodes[i]));
};

ListPlnrAVControlPar::~ListPlnrAVControlPar() {
	clear();
};

void ListPlnrAVControlPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrAVControlPar::size() const {
	return(nodes.size());
};

void ListPlnrAVControlPar::append(
			PlnrAVControlPar* rec
		) {
	nodes.push_back(rec);
};

PlnrAVControlPar* ListPlnrAVControlPar::operator[](
			const uint ix
		) {
	PlnrAVControlPar* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrAVControlPar& ListPlnrAVControlPar::operator=(
			const ListPlnrAVControlPar& src
		) {
	PlnrAVControlPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrAVControlPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrAVControlPar::operator==(
			const ListPlnrAVControlPar& comp
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

bool ListPlnrAVControlPar::operator!=(
			const ListPlnrAVControlPar& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrAVControlPar
 ******************************************************************************/

TblPlnrAVControlPar::TblPlnrAVControlPar() {
};

TblPlnrAVControlPar::~TblPlnrAVControlPar() {
};

bool TblPlnrAVControlPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAVControlPar** rec
		) {
	return false;
};

ubigint TblPlnrAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVControlPar& rst
		) {
	return 0;
};

void TblPlnrAVControlPar::insertRec(
			PlnrAVControlPar* rec
		) {
};

ubigint TblPlnrAVControlPar::insertNewRec(
			PlnrAVControlPar** rec
			, const uint ixPlnrVControl
			, const ubigint x1RefPlnrMUser
			, const uint x2IxPlnrVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAVControlPar* _rec = NULL;

	_rec = new PlnrAVControlPar(0, ixPlnrVControl, x1RefPlnrMUser, x2IxPlnrVLocale, Par, Val);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrAVControlPar::appendNewRecToRst(
			ListPlnrAVControlPar& rst
			, PlnrAVControlPar** rec
			, const uint ixPlnrVControl
			, const ubigint x1RefPlnrMUser
			, const uint x2IxPlnrVLocale
			, const string Par
			, const string Val
		) {
	ubigint retval = 0;
	PlnrAVControlPar* _rec = NULL;

	retval = insertNewRec(&_rec, ixPlnrVControl, x1RefPlnrMUser, x2IxPlnrVLocale, Par, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrAVControlPar::insertRst(
			ListPlnrAVControlPar& rst
			, bool transact
		) {
};

void TblPlnrAVControlPar::updateRec(
			PlnrAVControlPar* rec
		) {
};

void TblPlnrAVControlPar::updateRst(
			ListPlnrAVControlPar& rst
			, bool transact
		) {
};

void TblPlnrAVControlPar::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrAVControlPar::loadRecByRef(
			ubigint ref
			, PlnrAVControlPar** rec
		) {
	return false;
};

ubigint TblPlnrAVControlPar::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrAVControlPar& rst
		) {
	ubigint numload = 0;
	PlnrAVControlPar* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrAVControlPar
 ******************************************************************************/

MyTblPlnrAVControlPar::MyTblPlnrAVControlPar() : TblPlnrAVControlPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrAVControlPar::~MyTblPlnrAVControlPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrAVControlPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrAVControlPar (ixPlnrVControl, x1RefPlnrMUser, x2IxPlnrVLocale, Par, Val) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrAVControlPar SET ixPlnrVControl = ?, x1RefPlnrMUser = ?, x2IxPlnrVLocale = ?, Par = ?, Val = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrAVControlPar WHERE ref = ?", false);
};

bool MyTblPlnrAVControlPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAVControlPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrAVControlPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAVControlPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrAVControlPar();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->ixPlnrVControl = atol((char*) dbrow[1]); else _rec->ixPlnrVControl = 0;
		if (dbrow[2]) _rec->x1RefPlnrMUser = atoll((char*) dbrow[2]); else _rec->x1RefPlnrMUser = 0;
		if (dbrow[3]) _rec->x2IxPlnrVLocale = atol((char*) dbrow[3]); else _rec->x2IxPlnrVLocale = 0;
		if (dbrow[4]) _rec->Par.assign(dbrow[4], dblengths[4]); else _rec->Par = "";
		if (dbrow[5]) _rec->Val.assign(dbrow[5], dblengths[5]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVControlPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrAVControlPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrAVControlPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrAVControlPar();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->ixPlnrVControl = atol((char*) dbrow[1]); else rec->ixPlnrVControl = 0;
			if (dbrow[2]) rec->x1RefPlnrMUser = atoll((char*) dbrow[2]); else rec->x1RefPlnrMUser = 0;
			if (dbrow[3]) rec->x2IxPlnrVLocale = atol((char*) dbrow[3]); else rec->x2IxPlnrVLocale = 0;
			if (dbrow[4]) rec->Par.assign(dbrow[4], dblengths[4]); else rec->Par = "";
			if (dbrow[5]) rec->Val.assign(dbrow[5], dblengths[5]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrAVControlPar::insertRec(
			PlnrAVControlPar* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixPlnrVControl,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->x1RefPlnrMUser,&(l[1]),&(n[1]),&(e[1])),
		bindUint(&rec->x2IxPlnrVLocale,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVControlPar / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVControlPar / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrAVControlPar::insertRst(
			ListPlnrAVControlPar& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrAVControlPar::updateRec(
			PlnrAVControlPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Par.length();
	l[4] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUint(&rec->ixPlnrVControl,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->x1RefPlnrMUser,&(l[1]),&(n[1]),&(e[1])), 
		bindUint(&rec->x2IxPlnrVLocale,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Par.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->ref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVControlPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVControlPar / stmtUpdateRec)\n");
};

void MyTblPlnrAVControlPar::updateRst(
			ListPlnrAVControlPar& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrAVControlPar::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrAVControlPar / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrAVControlPar / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrAVControlPar::loadRecByRef(
			ubigint ref
			, PlnrAVControlPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrAVControlPar WHERE ref = " + to_string(ref), rec);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrAVControlPar
 ******************************************************************************/

PgTblPlnrAVControlPar::PgTblPlnrAVControlPar() : TblPlnrAVControlPar(), PgTable() {
};

PgTblPlnrAVControlPar::~PgTblPlnrAVControlPar() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrAVControlPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrAVControlPar_insertRec", "INSERT INTO TblPlnrAVControlPar (ixPlnrVControl, x1RefPlnrMUser, x2IxPlnrVLocale, Par, Val) VALUES ($1,$2,$3,$4,$5) RETURNING ref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVControlPar_updateRec", "UPDATE TblPlnrAVControlPar SET ixPlnrVControl = $1, x1RefPlnrMUser = $2, x2IxPlnrVLocale = $3, Par = $4, Val = $5 WHERE ref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrAVControlPar_removeRecByRef", "DELETE FROM TblPlnrAVControlPar WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrAVControlPar_loadRecByRef", "SELECT ref, ixPlnrVControl, x1RefPlnrMUser, x2IxPlnrVLocale, Par, Val FROM TblPlnrAVControlPar WHERE ref = $1", 1, NULL);
};

bool PgTblPlnrAVControlPar::loadRec(
			PGresult* res
			, PlnrAVControlPar** rec
		) {
	char* ptr;

	PlnrAVControlPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrAVControlPar();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixplnrvcontrol"),
			PQfnumber(res, "x1refplnrmuser"),
			PQfnumber(res, "x2ixplnrvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->ixPlnrVControl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->x1RefPlnrMUser = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->x2IxPlnrVLocale = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Par.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[5]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrAVControlPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrAVControlPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrAVControlPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixplnrvcontrol"),
			PQfnumber(res, "x1refplnrmuser"),
			PQfnumber(res, "x2ixplnrvlocale"),
			PQfnumber(res, "par"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrAVControlPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->ixPlnrVControl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->x1RefPlnrMUser = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->x2IxPlnrVLocale = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Par.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[5]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrAVControlPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrAVControlPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVControlPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

bool PgTblPlnrAVControlPar::loadRecBySQL(
			const string& sqlstr
			, PlnrAVControlPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrAVControlPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrAVControlPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrAVControlPar::insertRec(
			PlnrAVControlPar* rec
		) {
	PGresult* res;
	char* ptr;

	uint _ixPlnrVControl = htonl(rec->ixPlnrVControl);
	ubigint _x1RefPlnrMUser = htonl64(rec->x1RefPlnrMUser);
	uint _x2IxPlnrVLocale = htonl(rec->x2IxPlnrVLocale);

	const char* vals[] = {
		(char*) &_ixPlnrVControl,
		(char*) &_x1RefPlnrMUser,
		(char*) &_x2IxPlnrVLocale,
		rec->Par.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrAVControlPar_insertRec", 5, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVControlPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrAVControlPar::insertRst(
			ListPlnrAVControlPar& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrAVControlPar::updateRec(
			PlnrAVControlPar* rec
		) {
	PGresult* res;

	uint _ixPlnrVControl = htonl(rec->ixPlnrVControl);
	ubigint _x1RefPlnrMUser = htonl64(rec->x1RefPlnrMUser);
	uint _x2IxPlnrVLocale = htonl(rec->x2IxPlnrVLocale);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_ixPlnrVControl,
		(char*) &_x1RefPlnrMUser,
		(char*) &_x2IxPlnrVLocale,
		rec->Par.c_str(),
		rec->Val.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(uint),
		sizeof(ubigint),
		sizeof(uint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrAVControlPar_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVControlPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrAVControlPar::updateRst(
			ListPlnrAVControlPar& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrAVControlPar::removeRecByRef(
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

	res = PQexecPrepared(dbs, "TblPlnrAVControlPar_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrAVControlPar_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrAVControlPar::loadRecByRef(
			ubigint ref
			, PlnrAVControlPar** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrAVControlPar_loadRecByRef", 1, vals, l, f, rec);
};

// IP pgTbl --- END

