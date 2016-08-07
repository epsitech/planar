/**
  * \file PlnrQStkMNStructure.cpp
  * Dbs and XML wrapper for table TblPlnrQStkMNStructure (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQStkMNStructure.h"

/******************************************************************************
 class PlnrQStkMNStructure
 ******************************************************************************/

PlnrQStkMNStructure::PlnrQStkMNStructure(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->fromSrefPlnrMLayer = fromSrefPlnrMLayer;
	this->toSrefPlnrMLayer = toSrefPlnrMLayer;
};

void PlnrQStkMNStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQStkMNStructure";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "frl", fromSrefPlnrMLayer);
		writeString(wr, "tol", toSrefPlnrMLayer);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "fromSrefPlnrMLayer", fromSrefPlnrMLayer);
		writeString(wr, "toSrefPlnrMLayer", toSrefPlnrMLayer);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQStkMNStructure
 ******************************************************************************/

ListPlnrQStkMNStructure::ListPlnrQStkMNStructure() {
};

ListPlnrQStkMNStructure::ListPlnrQStkMNStructure(
			const ListPlnrQStkMNStructure& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQStkMNStructure(*(src.nodes[i]));
};

ListPlnrQStkMNStructure::~ListPlnrQStkMNStructure() {
	clear();
};

void ListPlnrQStkMNStructure::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQStkMNStructure::size() const {
	return(nodes.size());
};

void ListPlnrQStkMNStructure::append(
			PlnrQStkMNStructure* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQStkMNStructure& ListPlnrQStkMNStructure::operator=(
			const ListPlnrQStkMNStructure& src
		) {
	PlnrQStkMNStructure* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQStkMNStructure(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQStkMNStructure::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQStkMNStructure";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQStkMNStructure
 ******************************************************************************/

TblPlnrQStkMNStructure::TblPlnrQStkMNStructure() {
};

TblPlnrQStkMNStructure::~TblPlnrQStkMNStructure() {
};

bool TblPlnrQStkMNStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkMNStructure** rec
		) {
	return false;
};

ubigint TblPlnrQStkMNStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	return 0;
};

void TblPlnrQStkMNStructure::insertRec(
			PlnrQStkMNStructure* rec
		) {
};

ubigint TblPlnrQStkMNStructure::insertNewRec(
			PlnrQStkMNStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrQStkMNStructure* _rec = NULL;

	_rec = new PlnrQStkMNStructure(0, jref, jnum, mref, stubMref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQStkMNStructure::appendNewRecToRst(
			ListPlnrQStkMNStructure& rst
			, PlnrQStkMNStructure** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrQStkMNStructure* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQStkMNStructure::insertRst(
			ListPlnrQStkMNStructure& rst
		) {
};

void TblPlnrQStkMNStructure::updateRec(
			PlnrQStkMNStructure* rec
		) {
};

void TblPlnrQStkMNStructure::updateRst(
			ListPlnrQStkMNStructure& rst
		) {
};

void TblPlnrQStkMNStructure::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQStkMNStructure::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQStkMNStructure::loadRecByQref(
			ubigint qref
			, PlnrQStkMNStructure** rec
		) {
	return false;
};

ubigint TblPlnrQStkMNStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQStkMNStructure
 ******************************************************************************/

MyTblPlnrQStkMNStructure::MyTblPlnrQStkMNStructure() : TblPlnrQStkMNStructure(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQStkMNStructure::~MyTblPlnrQStkMNStructure() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQStkMNStructure::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQStkMNStructure (jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQStkMNStructure SET jref = ?, jnum = ?, mref = ?, ref = ?, fromSrefPlnrMLayer = ?, toSrefPlnrMLayer = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQStkMNStructure WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQStkMNStructure WHERE jref = ?", false);
};

bool MyTblPlnrQStkMNStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkMNStructure** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQStkMNStructure* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkMNStructure / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQStkMNStructure();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->fromSrefPlnrMLayer.assign(dbrow[5], dblengths[5]); else _rec->fromSrefPlnrMLayer = "";
		if (dbrow[6]) _rec->toSrefPlnrMLayer.assign(dbrow[6], dblengths[6]); else _rec->toSrefPlnrMLayer = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQStkMNStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQStkMNStructure* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQStkMNStructure / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQStkMNStructure();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->fromSrefPlnrMLayer.assign(dbrow[5], dblengths[5]); else rec->fromSrefPlnrMLayer = "";
			if (dbrow[6]) rec->toSrefPlnrMLayer.assign(dbrow[6], dblengths[6]); else rec->toSrefPlnrMLayer = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQStkMNStructure::insertRec(
			PlnrQStkMNStructure* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[4] = rec->fromSrefPlnrMLayer.length();
	l[5] = rec->toSrefPlnrMLayer.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindCstring((char*) (rec->fromSrefPlnrMLayer.c_str()),&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->toSrefPlnrMLayer.c_str()),&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkMNStructure / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkMNStructure / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQStkMNStructure::insertRst(
			ListPlnrQStkMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQStkMNStructure::updateRec(
			PlnrQStkMNStructure* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[4] = rec->fromSrefPlnrMLayer.length();
	l[5] = rec->toSrefPlnrMLayer.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindCstring((char*) (rec->fromSrefPlnrMLayer.c_str()),&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->toSrefPlnrMLayer.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkMNStructure / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkMNStructure / stmtUpdateRec)\n");
};

void MyTblPlnrQStkMNStructure::updateRst(
			ListPlnrQStkMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQStkMNStructure::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkMNStructure / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkMNStructure / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQStkMNStructure::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQStkMNStructure / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQStkMNStructure / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQStkMNStructure::loadRecByQref(
			ubigint qref
			, PlnrQStkMNStructure** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQStkMNStructure WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQStkMNStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQStkMNStructure WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQStkMNStructure
 ******************************************************************************/

PgTblPlnrQStkMNStructure::PgTblPlnrQStkMNStructure() : TblPlnrQStkMNStructure(), PgTable() {
};

PgTblPlnrQStkMNStructure::~PgTblPlnrQStkMNStructure() {
};

void PgTblPlnrQStkMNStructure::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQStkMNStructure_insertRec", "INSERT INTO TblPlnrQStkMNStructure (jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkMNStructure_updateRec", "UPDATE TblPlnrQStkMNStructure SET jref = $1, jnum = $2, mref = $3, ref = $4, fromSrefPlnrMLayer = $5, toSrefPlnrMLayer = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkMNStructure_removeRecByQref", "DELETE FROM TblPlnrQStkMNStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkMNStructure_removeRstByJref", "DELETE FROM TblPlnrQStkMNStructure WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQStkMNStructure_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrQStkMNStructure WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQStkMNStructure_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrQStkMNStructure WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQStkMNStructure::loadRec(
			PGresult* res
			, PlnrQStkMNStructure** rec
		) {
	char* ptr;

	PlnrQStkMNStructure* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQStkMNStructure();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fromsrefplnrmlayer"),
			PQfnumber(res, "tosrefplnrmlayer")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->fromSrefPlnrMLayer.assign(ptr, PQgetlength(res, 0, fnum[5]));
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->toSrefPlnrMLayer.assign(ptr, PQgetlength(res, 0, fnum[6]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQStkMNStructure::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQStkMNStructure* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "fromsrefplnrmlayer"),
			PQfnumber(res, "tosrefplnrmlayer")
		};

		while (numread < numrow) {
			rec = new PlnrQStkMNStructure();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->fromSrefPlnrMLayer.assign(ptr, PQgetlength(res, numread, fnum[5]));
			ptr = PQgetvalue(res, numread, fnum[6]); rec->toSrefPlnrMLayer.assign(ptr, PQgetlength(res, numread, fnum[6]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQStkMNStructure::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQStkMNStructure** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkMNStructure / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkMNStructure::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkMNStructure / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQStkMNStructure::loadRecBySQL(
			const string& sqlstr
			, PlnrQStkMNStructure** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQStkMNStructure::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQStkMNStructure::insertRec(
			PlnrQStkMNStructure* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->fromSrefPlnrMLayer.c_str(),
		rec->toSrefPlnrMLayer.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0
	};
	const int f[] = {1, 1, 1, 1, 0, 0};

	res = PQexecPrepared(dbs, "TblPlnrQStkMNStructure_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkMNStructure_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQStkMNStructure::insertRst(
			ListPlnrQStkMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQStkMNStructure::updateRec(
			PlnrQStkMNStructure* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		rec->fromSrefPlnrMLayer.c_str(),
		rec->toSrefPlnrMLayer.c_str(),
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		0,
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 0, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrQStkMNStructure_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkMNStructure_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQStkMNStructure::updateRst(
			ListPlnrQStkMNStructure& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQStkMNStructure::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkMNStructure_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkMNStructure_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQStkMNStructure::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQStkMNStructure_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQStkMNStructure_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQStkMNStructure::loadRecByQref(
			ubigint qref
			, PlnrQStkMNStructure** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQStkMNStructure_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQStkMNStructure::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQStkMNStructure& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQStkMNStructure_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

