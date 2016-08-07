/**
  * \file PlnrQDomList.cpp
  * Dbs and XML wrapper for table TblPlnrQDomList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQDomList.h"

/******************************************************************************
 class PlnrQDomList
 ******************************************************************************/

PlnrQDomList::PlnrQDomList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->sref = sref;
	this->ixVBasetype = ixVBasetype;
	this->srefIxVBasetype = srefIxVBasetype;
	this->titIxVBasetype = titIxVBasetype;
	this->dsnRefPlnrMDesign = dsnRefPlnrMDesign;
	this->stubDsnRefPlnrMDesign = stubDsnRefPlnrMDesign;
};

void PlnrQDomList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQDomList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "srf", sref);
		writeString(wr, "typ", srefIxVBasetype);
		writeString(wr, "typ2", titIxVBasetype);
		writeString(wr, "dsn", stubDsnRefPlnrMDesign);
	} else {
		writeString(wr, "sref", sref);
		writeString(wr, "srefIxVBasetype", srefIxVBasetype);
		writeString(wr, "titIxVBasetype", titIxVBasetype);
		writeString(wr, "stubDsnRefPlnrMDesign", stubDsnRefPlnrMDesign);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQDomList
 ******************************************************************************/

ListPlnrQDomList::ListPlnrQDomList() {
};

ListPlnrQDomList::ListPlnrQDomList(
			const ListPlnrQDomList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQDomList(*(src.nodes[i]));
};

ListPlnrQDomList::~ListPlnrQDomList() {
	clear();
};

void ListPlnrQDomList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQDomList::size() const {
	return(nodes.size());
};

void ListPlnrQDomList::append(
			PlnrQDomList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQDomList& ListPlnrQDomList::operator=(
			const ListPlnrQDomList& src
		) {
	PlnrQDomList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQDomList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQDomList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQDomList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQDomList
 ******************************************************************************/

TblPlnrQDomList::TblPlnrQDomList() {
};

TblPlnrQDomList::~TblPlnrQDomList() {
};

bool TblPlnrQDomList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDomList** rec
		) {
	return false;
};

ubigint TblPlnrQDomList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDomList& rst
		) {
	return 0;
};

void TblPlnrQDomList::insertRec(
			PlnrQDomList* rec
		) {
};

ubigint TblPlnrQDomList::insertNewRec(
			PlnrQDomList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQDomList* _rec = NULL;

	_rec = new PlnrQDomList(0, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQDomList::appendNewRecToRst(
			ListPlnrQDomList& rst
			, PlnrQDomList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string sref
			, const uint ixVBasetype
			, const string srefIxVBasetype
			, const string titIxVBasetype
			, const ubigint dsnRefPlnrMDesign
			, const string stubDsnRefPlnrMDesign
		) {
	ubigint retval = 0;
	PlnrQDomList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, sref, ixVBasetype, srefIxVBasetype, titIxVBasetype, dsnRefPlnrMDesign, stubDsnRefPlnrMDesign);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQDomList::insertRst(
			ListPlnrQDomList& rst
		) {
};

void TblPlnrQDomList::updateRec(
			PlnrQDomList* rec
		) {
};

void TblPlnrQDomList::updateRst(
			ListPlnrQDomList& rst
		) {
};

void TblPlnrQDomList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQDomList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQDomList::loadRecByQref(
			ubigint qref
			, PlnrQDomList** rec
		) {
	return false;
};

ubigint TblPlnrQDomList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDomList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQDomList
 ******************************************************************************/

MyTblPlnrQDomList::MyTblPlnrQDomList() : TblPlnrQDomList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQDomList::~MyTblPlnrQDomList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQDomList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQDomList (jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQDomList SET jref = ?, jnum = ?, ref = ?, sref = ?, ixVBasetype = ?, dsnRefPlnrMDesign = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQDomList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQDomList WHERE jref = ?", false);
};

bool MyTblPlnrQDomList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDomList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQDomList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDomList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQDomList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->sref.assign(dbrow[4], dblengths[4]); else _rec->sref = "";
		if (dbrow[5]) _rec->ixVBasetype = atol((char*) dbrow[5]); else _rec->ixVBasetype = 0;
		if (dbrow[6]) _rec->dsnRefPlnrMDesign = atoll((char*) dbrow[6]); else _rec->dsnRefPlnrMDesign = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQDomList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDomList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQDomList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQDomList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQDomList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->sref.assign(dbrow[4], dblengths[4]); else rec->sref = "";
			if (dbrow[5]) rec->ixVBasetype = atol((char*) dbrow[5]); else rec->ixVBasetype = 0;
			if (dbrow[6]) rec->dsnRefPlnrMDesign = atoll((char*) dbrow[6]); else rec->dsnRefPlnrMDesign = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQDomList::insertRec(
			PlnrQDomList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQDomList::insertRst(
			ListPlnrQDomList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQDomList::updateRec(
			PlnrQDomList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->sref.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->sref.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVBasetype,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->dsnRefPlnrMDesign,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomList / stmtUpdateRec)\n");
};

void MyTblPlnrQDomList::updateRst(
			ListPlnrQDomList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQDomList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQDomList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQDomList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQDomList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQDomList::loadRecByQref(
			ubigint qref
			, PlnrQDomList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQDomList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQDomList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDomList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQDomList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQDomList
 ******************************************************************************/

PgTblPlnrQDomList::PgTblPlnrQDomList() : TblPlnrQDomList(), PgTable() {
};

PgTblPlnrQDomList::~PgTblPlnrQDomList() {
};

void PgTblPlnrQDomList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQDomList_insertRec", "INSERT INTO TblPlnrQDomList (jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomList_updateRec", "UPDATE TblPlnrQDomList SET jref = $1, jnum = $2, ref = $3, sref = $4, ixVBasetype = $5, dsnRefPlnrMDesign = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomList_removeRecByQref", "DELETE FROM TblPlnrQDomList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomList_removeRstByJref", "DELETE FROM TblPlnrQDomList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQDomList_loadRecByQref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign FROM TblPlnrQDomList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQDomList_loadRstByJref", "SELECT qref, jref, jnum, ref, sref, ixVBasetype, dsnRefPlnrMDesign FROM TblPlnrQDomList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQDomList::loadRec(
			PGresult* res
			, PlnrQDomList** rec
		) {
	char* ptr;

	PlnrQDomList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQDomList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->sref.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVBasetype = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->dsnRefPlnrMDesign = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQDomList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQDomList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQDomList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "sref"),
			PQfnumber(res, "ixvbasetype"),
			PQfnumber(res, "dsnrefplnrmdesign")
		};

		while (numread < numrow) {
			rec = new PlnrQDomList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->sref.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVBasetype = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->dsnRefPlnrMDesign = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQDomList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQDomList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDomList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQDomList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQDomList::loadRecBySQL(
			const string& sqlstr
			, PlnrQDomList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQDomList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQDomList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQDomList::insertRec(
			PlnrQDomList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDomList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQDomList::insertRst(
			ListPlnrQDomList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQDomList::updateRec(
			PlnrQDomList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVBasetype = htonl(rec->ixVBasetype);
	ubigint _dsnRefPlnrMDesign = htonl64(rec->dsnRefPlnrMDesign);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->sref.c_str(),
		(char*) &_ixVBasetype,
		(char*) &_dsnRefPlnrMDesign,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 0, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQDomList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQDomList::updateRst(
			ListPlnrQDomList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQDomList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDomList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQDomList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQDomList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQDomList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQDomList::loadRecByQref(
			ubigint qref
			, PlnrQDomList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQDomList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQDomList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQDomList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQDomList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

