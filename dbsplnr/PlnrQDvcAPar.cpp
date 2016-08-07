/**
  * \file PlnrQDvcAPar.cpp
  * Dbs and XML wrapper for table TblPlnrQDvcAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDvcAPar.h"

/******************************************************************************
 class PlnrQDvcAPar
 ******************************************************************************/

PlnrQDvcAPar::PlnrQDvcAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x1RefPlnrMDesign = x1RefPlnrMDesign;
	this->stubX1RefPlnrMDesign = stubX1RefPlnrMDesign;
	this->x2SrefKKey = x2SrefKKey;
	this->titX2SrefKKey = titX2SrefKKey;
	this->refPlnrMFile = refPlnrMFile;
	this->stubRefPlnrMFile = stubRefPlnrMFile;
	this->Val = Val;
};

void PlnrQDvcAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDvcAPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "dsn", stubX1RefPlnrMDesign);
		writeString(wr, "key", x2SrefKKey);
		writeString(wr, "key2", titX2SrefKKey);
		writeString(wr, "fil", stubRefPlnrMFile);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "stubX1RefPlnrMDesign", stubX1RefPlnrMDesign);
		writeString(wr, "x2SrefKKey", x2SrefKKey);
		writeString(wr, "titX2SrefKKey", titX2SrefKKey);
		writeString(wr, "stubRefPlnrMFile", stubRefPlnrMFile);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDvcAPar
 ******************************************************************************/

ListPlnrQDvcAPar::ListPlnrQDvcAPar() {
};

ListPlnrQDvcAPar::ListPlnrQDvcAPar(
			const ListPlnrQDvcAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDvcAPar(*(src.nodes[i]));
};

ListPlnrQDvcAPar::~ListPlnrQDvcAPar() {
	clear();
};

void ListPlnrQDvcAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDvcAPar::size() const {
	return(nodes.size());
};

void ListPlnrQDvcAPar::append(
			PlnrQDvcAPar* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDvcAPar& ListPlnrQDvcAPar::operator=(
			const ListPlnrQDvcAPar& src
		) {
	PlnrQDvcAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDvcAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDvcAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDvcAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDvcAPar
 ******************************************************************************/

TblPlnrQDvcAPar::TblPlnrQDvcAPar() {
};

TblPlnrQDvcAPar::~TblPlnrQDvcAPar() {
};

bool TblPlnrQDvcAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcAPar** rec
		) {
	return false;
};

ubigint TblPlnrQDvcAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	return 0;
};

void TblPlnrQDvcAPar::insertRec(
			PlnrQDvcAPar* rec
		) {
};

ubigint TblPlnrQDvcAPar::insertNewRec(
			PlnrQDvcAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQDvcAPar* _rec = NULL;

	_rec = new PlnrQDvcAPar(0, jref, jnum, ref, x1RefPlnrMDesign, stubX1RefPlnrMDesign, x2SrefKKey, titX2SrefKKey, refPlnrMFile, stubRefPlnrMFile, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDvcAPar::appendNewRecToRst(
			ListPlnrQDvcAPar& rst
			, PlnrQDvcAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMDesign
			, const string stubX1RefPlnrMDesign
			, const string x2SrefKKey
			, const string titX2SrefKKey
			, const ubigint refPlnrMFile
			, const string stubRefPlnrMFile
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQDvcAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefPlnrMDesign, stubX1RefPlnrMDesign, x2SrefKKey, titX2SrefKKey, refPlnrMFile, stubRefPlnrMFile, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDvcAPar::insertRst(
			ListPlnrQDvcAPar& rst
		) {
};

void TblPlnrQDvcAPar::updateRec(
			PlnrQDvcAPar* rec
		) {
};

void TblPlnrQDvcAPar::updateRst(
			ListPlnrQDvcAPar& rst
		) {
};

void TblPlnrQDvcAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDvcAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDvcAPar::loadRecByQref(
			ubigint qref
			, PlnrQDvcAPar** rec
		) {
	return false;
};

ubigint TblPlnrQDvcAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDvcAPar
 ******************************************************************************/

MyTblPlnrQDvcAPar::MyTblPlnrQDvcAPar() : TblPlnrQDvcAPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDvcAPar::~MyTblPlnrQDvcAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDvcAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDvcAPar (jref, jnum, ref, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDvcAPar SET jref = ?, jnum = ?, ref = ?, x1RefPlnrMDesign = ?, x2SrefKKey = ?, refPlnrMFile = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDvcAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDvcAPar WHERE jref = ?", false);
};

bool MyTblPlnrQDvcAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDvcAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcAPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDvcAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefPlnrMDesign = atoll((char*) dbrow[4]); else _rec->x1RefPlnrMDesign = 0;
		if (dbrow[5]) _rec->x2SrefKKey.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKKey = "";
		if (dbrow[6]) _rec->refPlnrMFile = atoll((char*) dbrow[6]); else _rec->refPlnrMFile = 0;
		if (dbrow[7]) _rec->Val.assign(dbrow[7], dblengths[7]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDvcAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDvcAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDvcAPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDvcAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefPlnrMDesign = atoll((char*) dbrow[4]); else rec->x1RefPlnrMDesign = 0;
			if (dbrow[5]) rec->x2SrefKKey.assign(dbrow[5], dblengths[5]); else rec->x2SrefKKey = "";
			if (dbrow[6]) rec->refPlnrMFile = atoll((char*) dbrow[6]); else rec->refPlnrMFile = 0;
			if (dbrow[7]) rec->Val.assign(dbrow[7], dblengths[7]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDvcAPar::insertRec(
			PlnrQDvcAPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2SrefKKey.length();
	l[6] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->refPlnrMFile,&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Val.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcAPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcAPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDvcAPar::insertRst(
			ListPlnrQDvcAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDvcAPar::updateRec(
			PlnrQDvcAPar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->x2SrefKKey.length();
	l[6] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefPlnrMDesign,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->x2SrefKKey.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->refPlnrMFile,&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcAPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcAPar / stmtUpdateRec)\n");
};

void MyTblPlnrQDvcAPar::updateRst(
			ListPlnrQDvcAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDvcAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcAPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcAPar / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDvcAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDvcAPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDvcAPar / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDvcAPar::loadRecByQref(
			ubigint qref
			, PlnrQDvcAPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDvcAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDvcAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDvcAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDvcAPar
 ******************************************************************************/

PgTblPlnrQDvcAPar::PgTblPlnrQDvcAPar() : TblPlnrQDvcAPar(), PgTable() {
};

PgTblPlnrQDvcAPar::~PgTblPlnrQDvcAPar() {
};

void PgTblPlnrQDvcAPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDvcAPar_insertRec", "INSERT INTO TblPlnrQDvcAPar (jref, jnum, ref, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcAPar_updateRec", "UPDATE TblPlnrQDvcAPar SET jref = $1, jnum = $2, ref = $3, x1RefPlnrMDesign = $4, x2SrefKKey = $5, refPlnrMFile = $6, Val = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcAPar_removeRecByQref", "DELETE FROM TblPlnrQDvcAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcAPar_removeRstByJref", "DELETE FROM TblPlnrQDvcAPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDvcAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrQDvcAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDvcAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefPlnrMDesign, x2SrefKKey, refPlnrMFile, Val FROM TblPlnrQDvcAPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDvcAPar::loadRec(
			PGresult* res
			, PlnrQDvcAPar** rec
		) {
	char* ptr;

	PlnrQDvcAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDvcAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefPlnrMDesign = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKKey.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->refPlnrMFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDvcAPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDvcAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmdesign"),
			PQfnumber(res, "x2srefkkey"),
			PQfnumber(res, "refplnrmfile"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQDvcAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefPlnrMDesign = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKKey.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->refPlnrMFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDvcAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDvcAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcAPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcAPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDvcAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQDvcAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDvcAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDvcAPar::insertRec(
			PlnrQDvcAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKKey.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrQDvcAPar_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcAPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDvcAPar::insertRst(
			ListPlnrQDvcAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDvcAPar::updateRec(
			PlnrQDvcAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMDesign = htonl64(rec->x1RefPlnrMDesign);
	ubigint _refPlnrMFile = htonl64(rec->refPlnrMFile);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMDesign,
		rec->x2SrefKKey.c_str(),
		(char*) &_refPlnrMFile,
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		sizeof(ubigint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcAPar_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcAPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDvcAPar::updateRst(
			ListPlnrQDvcAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDvcAPar::removeRecByQref(
			ubigint qref
		) {
	PGresult* res;

	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcAPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDvcAPar::removeRstByJref(
			ubigint jref
		) {
	PGresult* res;

	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrQDvcAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDvcAPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDvcAPar::loadRecByQref(
			ubigint qref
			, PlnrQDvcAPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDvcAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDvcAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDvcAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDvcAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

