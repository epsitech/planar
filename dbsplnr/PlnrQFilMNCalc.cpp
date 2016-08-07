/**
  * \file PlnrQFilMNCalc.cpp
  * Dbs and XML wrapper for table TblPlnrQFilMNCalc (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQFilMNCalc.h"

/******************************************************************************
 class PlnrQFilMNCalc
 ******************************************************************************/

PlnrQFilMNCalc::PlnrQFilMNCalc(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string stubX1RefPlnrMCalcitem
			, const uint ixVIo
			, const string srefIxVIo
			, const string titIxVIo
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->x1RefPlnrMCalcitem = x1RefPlnrMCalcitem;
	this->stubX1RefPlnrMCalcitem = stubX1RefPlnrMCalcitem;
	this->ixVIo = ixVIo;
	this->srefIxVIo = srefIxVIo;
	this->titIxVIo = titIxVIo;
};

void PlnrQFilMNCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQFilMNCalc";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "cli", stubX1RefPlnrMCalcitem);
		writeString(wr, "io", srefIxVIo);
		writeString(wr, "io2", titIxVIo);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "stubX1RefPlnrMCalcitem", stubX1RefPlnrMCalcitem);
		writeString(wr, "srefIxVIo", srefIxVIo);
		writeString(wr, "titIxVIo", titIxVIo);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQFilMNCalc
 ******************************************************************************/

ListPlnrQFilMNCalc::ListPlnrQFilMNCalc() {
};

ListPlnrQFilMNCalc::ListPlnrQFilMNCalc(
			const ListPlnrQFilMNCalc& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQFilMNCalc(*(src.nodes[i]));
};

ListPlnrQFilMNCalc::~ListPlnrQFilMNCalc() {
	clear();
};

void ListPlnrQFilMNCalc::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQFilMNCalc::size() const {
	return(nodes.size());
};

void ListPlnrQFilMNCalc::append(
			PlnrQFilMNCalc* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQFilMNCalc& ListPlnrQFilMNCalc::operator=(
			const ListPlnrQFilMNCalc& src
		) {
	PlnrQFilMNCalc* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQFilMNCalc(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQFilMNCalc::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQFilMNCalc";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQFilMNCalc
 ******************************************************************************/

TblPlnrQFilMNCalc::TblPlnrQFilMNCalc() {
};

TblPlnrQFilMNCalc::~TblPlnrQFilMNCalc() {
};

bool TblPlnrQFilMNCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQFilMNCalc** rec
		) {
	return false;
};

ubigint TblPlnrQFilMNCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	return 0;
};

void TblPlnrQFilMNCalc::insertRec(
			PlnrQFilMNCalc* rec
		) {
};

ubigint TblPlnrQFilMNCalc::insertNewRec(
			PlnrQFilMNCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string stubX1RefPlnrMCalcitem
			, const uint ixVIo
			, const string srefIxVIo
			, const string titIxVIo
		) {
	ubigint retval = 0;
	PlnrQFilMNCalc* _rec = NULL;

	_rec = new PlnrQFilMNCalc(0, jref, jnum, mref, stubMref, ref, x1RefPlnrMCalcitem, stubX1RefPlnrMCalcitem, ixVIo, srefIxVIo, titIxVIo);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQFilMNCalc::appendNewRecToRst(
			ListPlnrQFilMNCalc& rst
			, PlnrQFilMNCalc** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const ubigint x1RefPlnrMCalcitem
			, const string stubX1RefPlnrMCalcitem
			, const uint ixVIo
			, const string srefIxVIo
			, const string titIxVIo
		) {
	ubigint retval = 0;
	PlnrQFilMNCalc* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, x1RefPlnrMCalcitem, stubX1RefPlnrMCalcitem, ixVIo, srefIxVIo, titIxVIo);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQFilMNCalc::insertRst(
			ListPlnrQFilMNCalc& rst
		) {
};

void TblPlnrQFilMNCalc::updateRec(
			PlnrQFilMNCalc* rec
		) {
};

void TblPlnrQFilMNCalc::updateRst(
			ListPlnrQFilMNCalc& rst
		) {
};

void TblPlnrQFilMNCalc::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQFilMNCalc::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQFilMNCalc::loadRecByQref(
			ubigint qref
			, PlnrQFilMNCalc** rec
		) {
	return false;
};

ubigint TblPlnrQFilMNCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQFilMNCalc
 ******************************************************************************/

MyTblPlnrQFilMNCalc::MyTblPlnrQFilMNCalc() : TblPlnrQFilMNCalc(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQFilMNCalc::~MyTblPlnrQFilMNCalc() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQFilMNCalc::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQFilMNCalc (jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQFilMNCalc SET jref = ?, jnum = ?, mref = ?, ref = ?, x1RefPlnrMCalcitem = ?, ixVIo = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQFilMNCalc WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQFilMNCalc WHERE jref = ?", false);
};

bool MyTblPlnrQFilMNCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQFilMNCalc** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQFilMNCalc* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQFilMNCalc / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQFilMNCalc();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[5]); else _rec->x1RefPlnrMCalcitem = 0;
		if (dbrow[6]) _rec->ixVIo = atol((char*) dbrow[6]); else _rec->ixVIo = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQFilMNCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQFilMNCalc* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQFilMNCalc / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQFilMNCalc();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->x1RefPlnrMCalcitem = atoll((char*) dbrow[5]); else rec->x1RefPlnrMCalcitem = 0;
			if (dbrow[6]) rec->ixVIo = atol((char*) dbrow[6]); else rec->ixVIo = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQFilMNCalc::insertRec(
			PlnrQFilMNCalc* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[4]),&(n[4]),&(e[4])),
		bindUint(&rec->ixVIo,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilMNCalc / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilMNCalc / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQFilMNCalc::insertRst(
			ListPlnrQFilMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQFilMNCalc::updateRec(
			PlnrQFilMNCalc* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->x1RefPlnrMCalcitem,&(l[4]),&(n[4]),&(e[4])), 
		bindUint(&rec->ixVIo,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilMNCalc / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilMNCalc / stmtUpdateRec)\n");
};

void MyTblPlnrQFilMNCalc::updateRst(
			ListPlnrQFilMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQFilMNCalc::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilMNCalc / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilMNCalc / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQFilMNCalc::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQFilMNCalc / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQFilMNCalc / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQFilMNCalc::loadRecByQref(
			ubigint qref
			, PlnrQFilMNCalc** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQFilMNCalc WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQFilMNCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQFilMNCalc WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQFilMNCalc
 ******************************************************************************/

PgTblPlnrQFilMNCalc::PgTblPlnrQFilMNCalc() : TblPlnrQFilMNCalc(), PgTable() {
};

PgTblPlnrQFilMNCalc::~PgTblPlnrQFilMNCalc() {
};

void PgTblPlnrQFilMNCalc::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQFilMNCalc_insertRec", "INSERT INTO TblPlnrQFilMNCalc (jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilMNCalc_updateRec", "UPDATE TblPlnrQFilMNCalc SET jref = $1, jnum = $2, mref = $3, ref = $4, x1RefPlnrMCalcitem = $5, ixVIo = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilMNCalc_removeRecByQref", "DELETE FROM TblPlnrQFilMNCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilMNCalc_removeRstByJref", "DELETE FROM TblPlnrQFilMNCalc WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQFilMNCalc_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo FROM TblPlnrQFilMNCalc WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQFilMNCalc_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, x1RefPlnrMCalcitem, ixVIo FROM TblPlnrQFilMNCalc WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQFilMNCalc::loadRec(
			PGresult* res
			, PlnrQFilMNCalc** rec
		) {
	char* ptr;

	PlnrQFilMNCalc* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQFilMNCalc();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "ixvio")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->x1RefPlnrMCalcitem = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->ixVIo = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQFilMNCalc::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQFilMNCalc* rec;

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
			PQfnumber(res, "x1refplnrmcalcitem"),
			PQfnumber(res, "ixvio")
		};

		while (numread < numrow) {
			rec = new PlnrQFilMNCalc();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->x1RefPlnrMCalcitem = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->ixVIo = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQFilMNCalc::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQFilMNCalc** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilMNCalc / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQFilMNCalc::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilMNCalc / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQFilMNCalc::loadRecBySQL(
			const string& sqlstr
			, PlnrQFilMNCalc** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQFilMNCalc::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQFilMNCalc::insertRec(
			PlnrQFilMNCalc* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	uint _ixVIo = htonl(rec->ixVIo);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
		(char*) &_ixVIo
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQFilMNCalc_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilMNCalc_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQFilMNCalc::insertRst(
			ListPlnrQFilMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQFilMNCalc::updateRec(
			PlnrQFilMNCalc* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	ubigint _x1RefPlnrMCalcitem = htonl64(rec->x1RefPlnrMCalcitem);
	uint _ixVIo = htonl(rec->ixVIo);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_x1RefPlnrMCalcitem,
		(char*) &_ixVIo,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQFilMNCalc_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilMNCalc_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQFilMNCalc::updateRst(
			ListPlnrQFilMNCalc& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQFilMNCalc::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQFilMNCalc_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilMNCalc_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQFilMNCalc::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQFilMNCalc_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQFilMNCalc_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQFilMNCalc::loadRecByQref(
			ubigint qref
			, PlnrQFilMNCalc** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQFilMNCalc_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQFilMNCalc::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQFilMNCalc& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQFilMNCalc_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

