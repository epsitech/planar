/**
  * \file PlnrQCliAAMCalcPar.cpp
  * Dbs and XML wrapper for table TblPlnrQCliAAMCalcPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCliAAMCalcPar.h"

/******************************************************************************
 class PlnrQCliAAMCalcPar
 ******************************************************************************/

PlnrQCliAAMCalcPar::PlnrQCliAAMCalcPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string Val
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->x2SrefKCat = x2SrefKCat;
	this->titX2SrefKCat = titX2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->titX3SrefKProp = titX3SrefKProp;
	this->Val = Val;
};

void PlnrQCliAAMCalcPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCliAAMCalcPar";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "cat", x2SrefKCat);
		writeString(wr, "cat2", titX2SrefKCat);
		writeString(wr, "prp", x3SrefKProp);
		writeString(wr, "prp2", titX3SrefKProp);
		writeString(wr, "val", Val);
	} else {
		writeString(wr, "x2SrefKCat", x2SrefKCat);
		writeString(wr, "titX2SrefKCat", titX2SrefKCat);
		writeString(wr, "x3SrefKProp", x3SrefKProp);
		writeString(wr, "titX3SrefKProp", titX3SrefKProp);
		writeString(wr, "Val", Val);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQCliAAMCalcPar
 ******************************************************************************/

ListPlnrQCliAAMCalcPar::ListPlnrQCliAAMCalcPar() {
};

ListPlnrQCliAAMCalcPar::ListPlnrQCliAAMCalcPar(
			const ListPlnrQCliAAMCalcPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCliAAMCalcPar(*(src.nodes[i]));
};

ListPlnrQCliAAMCalcPar::~ListPlnrQCliAAMCalcPar() {
	clear();
};

void ListPlnrQCliAAMCalcPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCliAAMCalcPar::size() const {
	return(nodes.size());
};

void ListPlnrQCliAAMCalcPar::append(
			PlnrQCliAAMCalcPar* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCliAAMCalcPar& ListPlnrQCliAAMCalcPar::operator=(
			const ListPlnrQCliAAMCalcPar& src
		) {
	PlnrQCliAAMCalcPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCliAAMCalcPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCliAAMCalcPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCliAAMCalcPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCliAAMCalcPar
 ******************************************************************************/

TblPlnrQCliAAMCalcPar::TblPlnrQCliAAMCalcPar() {
};

TblPlnrQCliAAMCalcPar::~TblPlnrQCliAAMCalcPar() {
};

bool TblPlnrQCliAAMCalcPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliAAMCalcPar** rec
		) {
	return false;
};

ubigint TblPlnrQCliAAMCalcPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	return 0;
};

void TblPlnrQCliAAMCalcPar::insertRec(
			PlnrQCliAAMCalcPar* rec
		) {
};

ubigint TblPlnrQCliAAMCalcPar::insertNewRec(
			PlnrQCliAAMCalcPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCliAAMCalcPar* _rec = NULL;

	_rec = new PlnrQCliAAMCalcPar(0, jref, jnum, ref, x2SrefKCat, titX2SrefKCat, x3SrefKProp, titX3SrefKProp, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCliAAMCalcPar::appendNewRecToRst(
			ListPlnrQCliAAMCalcPar& rst
			, PlnrQCliAAMCalcPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCliAAMCalcPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x2SrefKCat, titX2SrefKCat, x3SrefKProp, titX3SrefKProp, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCliAAMCalcPar::insertRst(
			ListPlnrQCliAAMCalcPar& rst
		) {
};

void TblPlnrQCliAAMCalcPar::updateRec(
			PlnrQCliAAMCalcPar* rec
		) {
};

void TblPlnrQCliAAMCalcPar::updateRst(
			ListPlnrQCliAAMCalcPar& rst
		) {
};

void TblPlnrQCliAAMCalcPar::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCliAAMCalcPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCliAAMCalcPar::loadRecByQref(
			ubigint qref
			, PlnrQCliAAMCalcPar** rec
		) {
	return false;
};

ubigint TblPlnrQCliAAMCalcPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCliAAMCalcPar
 ******************************************************************************/

MyTblPlnrQCliAAMCalcPar::MyTblPlnrQCliAAMCalcPar() : TblPlnrQCliAAMCalcPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCliAAMCalcPar::~MyTblPlnrQCliAAMCalcPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCliAAMCalcPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCliAAMCalcPar (jref, jnum, ref, x2SrefKCat, x3SrefKProp, Val) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCliAAMCalcPar SET jref = ?, jnum = ?, ref = ?, x2SrefKCat = ?, x3SrefKProp = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCliAAMCalcPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCliAAMCalcPar WHERE jref = ?", false);
};

bool MyTblPlnrQCliAAMCalcPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliAAMCalcPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCliAAMCalcPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCliAAMCalcPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCliAAMCalcPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x2SrefKCat.assign(dbrow[4], dblengths[4]); else _rec->x2SrefKCat = "";
		if (dbrow[5]) _rec->x3SrefKProp.assign(dbrow[5], dblengths[5]); else _rec->x3SrefKProp = "";
		if (dbrow[6]) _rec->Val.assign(dbrow[6], dblengths[6]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCliAAMCalcPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCliAAMCalcPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCliAAMCalcPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCliAAMCalcPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x2SrefKCat.assign(dbrow[4], dblengths[4]); else rec->x2SrefKCat = "";
			if (dbrow[5]) rec->x3SrefKProp.assign(dbrow[5], dblengths[5]); else rec->x3SrefKProp = "";
			if (dbrow[6]) rec->Val.assign(dbrow[6], dblengths[6]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCliAAMCalcPar::insertRec(
			PlnrQCliAAMCalcPar* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->x2SrefKCat.length();
	l[4] = rec->x3SrefKProp.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCliAAMCalcPar::insertRst(
			ListPlnrQCliAAMCalcPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCliAAMCalcPar::updateRec(
			PlnrQCliAAMCalcPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->x2SrefKCat.length();
	l[4] = rec->x3SrefKProp.length();
	l[5] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcPar / stmtUpdateRec)\n");
};

void MyTblPlnrQCliAAMCalcPar::updateRst(
			ListPlnrQCliAAMCalcPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCliAAMCalcPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcPar / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCliAAMCalcPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCliAAMCalcPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCliAAMCalcPar / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCliAAMCalcPar::loadRecByQref(
			ubigint qref
			, PlnrQCliAAMCalcPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCliAAMCalcPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCliAAMCalcPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCliAAMCalcPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCliAAMCalcPar
 ******************************************************************************/

PgTblPlnrQCliAAMCalcPar::PgTblPlnrQCliAAMCalcPar() : TblPlnrQCliAAMCalcPar(), PgTable() {
};

PgTblPlnrQCliAAMCalcPar::~PgTblPlnrQCliAAMCalcPar() {
};

void PgTblPlnrQCliAAMCalcPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCliAAMCalcPar_insertRec", "INSERT INTO TblPlnrQCliAAMCalcPar (jref, jnum, ref, x2SrefKCat, x3SrefKProp, Val) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcPar_updateRec", "UPDATE TblPlnrQCliAAMCalcPar SET jref = $1, jnum = $2, ref = $3, x2SrefKCat = $4, x3SrefKProp = $5, Val = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcPar_removeRecByQref", "DELETE FROM TblPlnrQCliAAMCalcPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcPar_removeRstByJref", "DELETE FROM TblPlnrQCliAAMCalcPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCliAAMCalcPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrQCliAAMCalcPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCliAAMCalcPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrQCliAAMCalcPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCliAAMCalcPar::loadRec(
			PGresult* res
			, PlnrQCliAAMCalcPar** rec
		) {
	char* ptr;

	PlnrQCliAAMCalcPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCliAAMCalcPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x2SrefKCat.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x3SrefKProp.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCliAAMCalcPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCliAAMCalcPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQCliAAMCalcPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x2SrefKCat.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x3SrefKProp.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCliAAMCalcPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCliAAMCalcPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCliAAMCalcPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCliAAMCalcPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQCliAAMCalcPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCliAAMCalcPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCliAAMCalcPar::insertRec(
			PlnrQCliAAMCalcPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcPar_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCliAAMCalcPar::insertRst(
			ListPlnrQCliAAMCalcPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCliAAMCalcPar::updateRec(
			PlnrQCliAAMCalcPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcPar_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCliAAMCalcPar::updateRst(
			ListPlnrQCliAAMCalcPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCliAAMCalcPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCliAAMCalcPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCliAAMCalcPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCliAAMCalcPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCliAAMCalcPar::loadRecByQref(
			ubigint qref
			, PlnrQCliAAMCalcPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCliAAMCalcPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCliAAMCalcPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCliAAMCalcPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCliAAMCalcPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

