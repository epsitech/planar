/**
  * \file PlnrQSruMNStack.cpp
  * Dbs and XML wrapper for table TblPlnrQSruMNStack (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQSruMNStack.h"

/******************************************************************************
 class PlnrQSruMNStack
 ******************************************************************************/

PlnrQSruMNStack::PlnrQSruMNStack(
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

void PlnrQSruMNStack::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQSruMNStack";

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
 class ListPlnrQSruMNStack
 ******************************************************************************/

ListPlnrQSruMNStack::ListPlnrQSruMNStack() {
};

ListPlnrQSruMNStack::ListPlnrQSruMNStack(
			const ListPlnrQSruMNStack& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQSruMNStack(*(src.nodes[i]));
};

ListPlnrQSruMNStack::~ListPlnrQSruMNStack() {
	clear();
};

void ListPlnrQSruMNStack::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQSruMNStack::size() const {
	return(nodes.size());
};

void ListPlnrQSruMNStack::append(
			PlnrQSruMNStack* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQSruMNStack& ListPlnrQSruMNStack::operator=(
			const ListPlnrQSruMNStack& src
		) {
	PlnrQSruMNStack* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQSruMNStack(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQSruMNStack::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQSruMNStack";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQSruMNStack
 ******************************************************************************/

TblPlnrQSruMNStack::TblPlnrQSruMNStack() {
};

TblPlnrQSruMNStack::~TblPlnrQSruMNStack() {
};

bool TblPlnrQSruMNStack::loadRecBySQL(
			const string& sqlstr
			, PlnrQSruMNStack** rec
		) {
	return false;
};

ubigint TblPlnrQSruMNStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	return 0;
};

void TblPlnrQSruMNStack::insertRec(
			PlnrQSruMNStack* rec
		) {
};

ubigint TblPlnrQSruMNStack::insertNewRec(
			PlnrQSruMNStack** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrQSruMNStack* _rec = NULL;

	_rec = new PlnrQSruMNStack(0, jref, jnum, mref, stubMref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQSruMNStack::appendNewRecToRst(
			ListPlnrQSruMNStack& rst
			, PlnrQSruMNStack** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const string fromSrefPlnrMLayer
			, const string toSrefPlnrMLayer
		) {
	ubigint retval = 0;
	PlnrQSruMNStack* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQSruMNStack::insertRst(
			ListPlnrQSruMNStack& rst
		) {
};

void TblPlnrQSruMNStack::updateRec(
			PlnrQSruMNStack* rec
		) {
};

void TblPlnrQSruMNStack::updateRst(
			ListPlnrQSruMNStack& rst
		) {
};

void TblPlnrQSruMNStack::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQSruMNStack::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQSruMNStack::loadRecByQref(
			ubigint qref
			, PlnrQSruMNStack** rec
		) {
	return false;
};

ubigint TblPlnrQSruMNStack::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQSruMNStack
 ******************************************************************************/

MyTblPlnrQSruMNStack::MyTblPlnrQSruMNStack() : TblPlnrQSruMNStack(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQSruMNStack::~MyTblPlnrQSruMNStack() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQSruMNStack::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQSruMNStack (jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQSruMNStack SET jref = ?, jnum = ?, mref = ?, ref = ?, fromSrefPlnrMLayer = ?, toSrefPlnrMLayer = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQSruMNStack WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQSruMNStack WHERE jref = ?", false);
};

bool MyTblPlnrQSruMNStack::loadRecBySQL(
			const string& sqlstr
			, PlnrQSruMNStack** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQSruMNStack* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQSruMNStack / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQSruMNStack();

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

ubigint MyTblPlnrQSruMNStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQSruMNStack* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQSruMNStack / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQSruMNStack();

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

void MyTblPlnrQSruMNStack::insertRec(
			PlnrQSruMNStack* rec
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

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruMNStack / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruMNStack / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQSruMNStack::insertRst(
			ListPlnrQSruMNStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQSruMNStack::updateRec(
			PlnrQSruMNStack* rec
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

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruMNStack / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruMNStack / stmtUpdateRec)\n");
};

void MyTblPlnrQSruMNStack::updateRst(
			ListPlnrQSruMNStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQSruMNStack::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruMNStack / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruMNStack / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQSruMNStack::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQSruMNStack / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQSruMNStack / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQSruMNStack::loadRecByQref(
			ubigint qref
			, PlnrQSruMNStack** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQSruMNStack WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQSruMNStack::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQSruMNStack WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQSruMNStack
 ******************************************************************************/

PgTblPlnrQSruMNStack::PgTblPlnrQSruMNStack() : TblPlnrQSruMNStack(), PgTable() {
};

PgTblPlnrQSruMNStack::~PgTblPlnrQSruMNStack() {
};

void PgTblPlnrQSruMNStack::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQSruMNStack_insertRec", "INSERT INTO TblPlnrQSruMNStack (jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruMNStack_updateRec", "UPDATE TblPlnrQSruMNStack SET jref = $1, jnum = $2, mref = $3, ref = $4, fromSrefPlnrMLayer = $5, toSrefPlnrMLayer = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruMNStack_removeRecByQref", "DELETE FROM TblPlnrQSruMNStack WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruMNStack_removeRstByJref", "DELETE FROM TblPlnrQSruMNStack WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQSruMNStack_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrQSruMNStack WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQSruMNStack_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, fromSrefPlnrMLayer, toSrefPlnrMLayer FROM TblPlnrQSruMNStack WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQSruMNStack::loadRec(
			PGresult* res
			, PlnrQSruMNStack** rec
		) {
	char* ptr;

	PlnrQSruMNStack* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQSruMNStack();

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

ubigint PgTblPlnrQSruMNStack::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQSruMNStack* rec;

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
			rec = new PlnrQSruMNStack();

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

bool PgTblPlnrQSruMNStack::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQSruMNStack** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruMNStack / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQSruMNStack::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruMNStack / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQSruMNStack::loadRecBySQL(
			const string& sqlstr
			, PlnrQSruMNStack** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQSruMNStack::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQSruMNStack::insertRec(
			PlnrQSruMNStack* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQSruMNStack_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruMNStack_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQSruMNStack::insertRst(
			ListPlnrQSruMNStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQSruMNStack::updateRec(
			PlnrQSruMNStack* rec
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

	res = PQexecPrepared(dbs, "TblPlnrQSruMNStack_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruMNStack_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQSruMNStack::updateRst(
			ListPlnrQSruMNStack& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQSruMNStack::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQSruMNStack_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruMNStack_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQSruMNStack::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQSruMNStack_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQSruMNStack_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQSruMNStack::loadRecByQref(
			ubigint qref
			, PlnrQSruMNStack** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQSruMNStack_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQSruMNStack::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQSruMNStack& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQSruMNStack_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

