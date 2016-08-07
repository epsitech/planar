/**
  * \file PlnrQCtpAPar.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpAPar (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpAPar.h"

/******************************************************************************
 class PlnrQCtpAPar
 ******************************************************************************/

PlnrQCtpAPar::PlnrQCtpAPar(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
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
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->x2SrefKCat = x2SrefKCat;
	this->titX2SrefKCat = titX2SrefKCat;
	this->x3SrefKProp = x3SrefKProp;
	this->titX3SrefKProp = titX3SrefKProp;
	this->Val = Val;
};

void PlnrQCtpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpAPar";

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
 class ListPlnrQCtpAPar
 ******************************************************************************/

ListPlnrQCtpAPar::ListPlnrQCtpAPar() {
};

ListPlnrQCtpAPar::ListPlnrQCtpAPar(
			const ListPlnrQCtpAPar& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpAPar(*(src.nodes[i]));
};

ListPlnrQCtpAPar::~ListPlnrQCtpAPar() {
	clear();
};

void ListPlnrQCtpAPar::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpAPar::size() const {
	return(nodes.size());
};

void ListPlnrQCtpAPar::append(
			PlnrQCtpAPar* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpAPar& ListPlnrQCtpAPar::operator=(
			const ListPlnrQCtpAPar& src
		) {
	PlnrQCtpAPar* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpAPar(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpAPar::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpAPar";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpAPar
 ******************************************************************************/

TblPlnrQCtpAPar::TblPlnrQCtpAPar() {
};

TblPlnrQCtpAPar::~TblPlnrQCtpAPar() {
};

bool TblPlnrQCtpAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpAPar** rec
		) {
	return false;
};

ubigint TblPlnrQCtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	return 0;
};

void TblPlnrQCtpAPar::insertRec(
			PlnrQCtpAPar* rec
		) {
};

ubigint TblPlnrQCtpAPar::insertNewRec(
			PlnrQCtpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCtpAPar* _rec = NULL;

	_rec = new PlnrQCtpAPar(0, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKCat, titX2SrefKCat, x3SrefKProp, titX3SrefKProp, Val);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpAPar::appendNewRecToRst(
			ListPlnrQCtpAPar& rst
			, PlnrQCtpAPar** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string x2SrefKCat
			, const string titX2SrefKCat
			, const string x3SrefKProp
			, const string titX3SrefKProp
			, const string Val
		) {
	ubigint retval = 0;
	PlnrQCtpAPar* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKCat, titX2SrefKCat, x3SrefKProp, titX3SrefKProp, Val);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpAPar::insertRst(
			ListPlnrQCtpAPar& rst
		) {
};

void TblPlnrQCtpAPar::updateRec(
			PlnrQCtpAPar* rec
		) {
};

void TblPlnrQCtpAPar::updateRst(
			ListPlnrQCtpAPar& rst
		) {
};

void TblPlnrQCtpAPar::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpAPar::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpAPar::loadRecByQref(
			ubigint qref
			, PlnrQCtpAPar** rec
		) {
	return false;
};

ubigint TblPlnrQCtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpAPar
 ******************************************************************************/

MyTblPlnrQCtpAPar::MyTblPlnrQCtpAPar() : TblPlnrQCtpAPar(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpAPar::~MyTblPlnrQCtpAPar() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpAPar::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpAPar (jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val) VALUES (?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpAPar SET jref = ?, jnum = ?, ref = ?, x1RefPlnrMCalcitem = ?, x2SrefKCat = ?, x3SrefKProp = ?, Val = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpAPar WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpAPar WHERE jref = ?", false);
};

bool MyTblPlnrQCtpAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpAPar** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpAPar* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpAPar / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpAPar();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[4]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[5]) _rec->x2SrefKCat.assign(dbrow[5], dblengths[5]); else _rec->x2SrefKCat = "";
		if (dbrow[6]) _rec->x3SrefKProp.assign(dbrow[6], dblengths[6]); else _rec->x3SrefKProp = "";
		if (dbrow[7]) _rec->Val.assign(dbrow[7], dblengths[7]); else _rec->Val = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpAPar* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpAPar / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpAPar();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[4]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[5]) rec->x2SrefKCat.assign(dbrow[5], dblengths[5]); else rec->x2SrefKCat = "";
			if (dbrow[6]) rec->x3SrefKProp.assign(dbrow[6], dblengths[6]); else rec->x3SrefKProp = "";
			if (dbrow[7]) rec->Val.assign(dbrow[7], dblengths[7]); else rec->Val = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCtpAPar::insertRec(
			PlnrQCtpAPar* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->x2SrefKCat.length();
	l[5] = rec->x3SrefKProp.length();
	l[6] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindCstring((char*) (rec->Val.c_str()),&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAPar / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAPar / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpAPar::insertRst(
			ListPlnrQCtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpAPar::updateRec(
			PlnrQCtpAPar* rec
		) {
	unsigned long l[8]; my_bool n[8]; my_bool e[8];

	l[4] = rec->x2SrefKCat.length();
	l[5] = rec->x3SrefKProp.length();
	l[6] = rec->Val.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->x2SrefKCat.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->x3SrefKProp.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindCstring((char*) (rec->Val.c_str()),&(l[6]),&(n[6]),&(e[6])), 
		bindUbigint(&rec->qref,&(l[7]),&(n[7]),&(e[7]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAPar / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAPar / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpAPar::updateRst(
			ListPlnrQCtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpAPar::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAPar / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAPar / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpAPar::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpAPar / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpAPar / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpAPar::loadRecByQref(
			ubigint qref
			, PlnrQCtpAPar** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpAPar WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpAPar WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpAPar
 ******************************************************************************/

PgTblPlnrQCtpAPar::PgTblPlnrQCtpAPar() : TblPlnrQCtpAPar(), PgTable() {
};

PgTblPlnrQCtpAPar::~PgTblPlnrQCtpAPar() {
};

void PgTblPlnrQCtpAPar::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpAPar_insertRec", "INSERT INTO TblPlnrQCtpAPar (jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val) VALUES ($1,$2,$3,$4,$5,$6,$7) RETURNING qref", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAPar_updateRec", "UPDATE TblPlnrQCtpAPar SET jref = $1, jnum = $2, ref = $3, x1RefPlnrMCalcitem = $4, x2SrefKCat = $5, x3SrefKProp = $6, Val = $7 WHERE qref = $8", 8, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAPar_removeRecByQref", "DELETE FROM TblPlnrQCtpAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAPar_removeRstByJref", "DELETE FROM TblPlnrQCtpAPar WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpAPar_loadRecByQref", "SELECT qref, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrQCtpAPar WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpAPar_loadRstByJref", "SELECT qref, jref, jnum, ref, x1RefPlnrMCalcitem, x2SrefKCat, x3SrefKProp, Val FROM TblPlnrQCtpAPar WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpAPar::loadRec(
			PGresult* res
			, PlnrQCtpAPar** rec
		) {
	char* ptr;

	PlnrQCtpAPar* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpAPar();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "val")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x2SrefKCat.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->x3SrefKProp.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Val.assign(ptr, PQgetlength(res, 0, fnum[7]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCtpAPar::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpAPar* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "x2srefkcat"),
			PQfnumber(res, "x3srefkprop"),
			PQfnumber(res, "val")
		};

		while (numread < numrow) {
			rec = new PlnrQCtpAPar();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x2SrefKCat.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->x3SrefKProp.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Val.assign(ptr, PQgetlength(res, numread, fnum[7]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCtpAPar::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpAPar** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAPar / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpAPar::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAPar / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpAPar::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpAPar** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpAPar::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpAPar::insertRec(
			PlnrQCtpAPar* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		rec->Val.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQCtpAPar_insertRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAPar_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpAPar::insertRst(
			ListPlnrQCtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpAPar::updateRec(
			PlnrQCtpAPar* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
		rec->x2SrefKCat.c_str(),
		rec->x3SrefKProp.c_str(),
		rec->Val.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCtpAPar_updateRec", 8, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAPar_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpAPar::updateRst(
			ListPlnrQCtpAPar& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpAPar::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpAPar_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAPar_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpAPar::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpAPar_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpAPar_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpAPar::loadRecByQref(
			ubigint qref
			, PlnrQCtpAPar** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpAPar_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpAPar::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpAPar& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpAPar_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

