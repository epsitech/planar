/**
  * \file PlnrQCtpList.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpList (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpList.h"

/******************************************************************************
 class PlnrQCtpList
 ******************************************************************************/

PlnrQCtpList::PlnrQCtpList(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const ubigint supRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->Title = Title;
	this->ixVDim = ixVDim;
	this->srefIxVDim = srefIxVDim;
	this->titIxVDim = titIxVDim;
	this->supRefPlnrMCalc = supRefPlnrMCalc;
	this->stubSupRefPlnrMCalc = stubSupRefPlnrMCalc;
};

void PlnrQCtpList::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpList";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "tit", Title);
		writeString(wr, "dim", srefIxVDim);
		writeString(wr, "dim2", titIxVDim);
		writeString(wr, "sup", stubSupRefPlnrMCalc);
	} else {
		writeString(wr, "Title", Title);
		writeString(wr, "srefIxVDim", srefIxVDim);
		writeString(wr, "titIxVDim", titIxVDim);
		writeString(wr, "stubSupRefPlnrMCalc", stubSupRefPlnrMCalc);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQCtpList
 ******************************************************************************/

ListPlnrQCtpList::ListPlnrQCtpList() {
};

ListPlnrQCtpList::ListPlnrQCtpList(
			const ListPlnrQCtpList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpList(*(src.nodes[i]));
};

ListPlnrQCtpList::~ListPlnrQCtpList() {
	clear();
};

void ListPlnrQCtpList::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpList::size() const {
	return(nodes.size());
};

void ListPlnrQCtpList::append(
			PlnrQCtpList* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpList& ListPlnrQCtpList::operator=(
			const ListPlnrQCtpList& src
		) {
	PlnrQCtpList* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpList(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpList::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpList";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpList
 ******************************************************************************/

TblPlnrQCtpList::TblPlnrQCtpList() {
};

TblPlnrQCtpList::~TblPlnrQCtpList() {
};

bool TblPlnrQCtpList::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpList** rec
		) {
	return false;
};

ubigint TblPlnrQCtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	return 0;
};

void TblPlnrQCtpList::insertRec(
			PlnrQCtpList* rec
		) {
};

ubigint TblPlnrQCtpList::insertNewRec(
			PlnrQCtpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const ubigint supRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
		) {
	ubigint retval = 0;
	PlnrQCtpList* _rec = NULL;

	_rec = new PlnrQCtpList(0, jref, jnum, ref, Title, ixVDim, srefIxVDim, titIxVDim, supRefPlnrMCalc, stubSupRefPlnrMCalc);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpList::appendNewRecToRst(
			ListPlnrQCtpList& rst
			, PlnrQCtpList** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string Title
			, const uint ixVDim
			, const string srefIxVDim
			, const string titIxVDim
			, const ubigint supRefPlnrMCalc
			, const string stubSupRefPlnrMCalc
		) {
	ubigint retval = 0;
	PlnrQCtpList* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, Title, ixVDim, srefIxVDim, titIxVDim, supRefPlnrMCalc, stubSupRefPlnrMCalc);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpList::insertRst(
			ListPlnrQCtpList& rst
		) {
};

void TblPlnrQCtpList::updateRec(
			PlnrQCtpList* rec
		) {
};

void TblPlnrQCtpList::updateRst(
			ListPlnrQCtpList& rst
		) {
};

void TblPlnrQCtpList::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpList::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpList::loadRecByQref(
			ubigint qref
			, PlnrQCtpList** rec
		) {
	return false;
};

ubigint TblPlnrQCtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpList
 ******************************************************************************/

MyTblPlnrQCtpList::MyTblPlnrQCtpList() : TblPlnrQCtpList(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpList::~MyTblPlnrQCtpList() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpList::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpList (jref, jnum, ref, Title, ixVDim, supRefPlnrMCalc) VALUES (?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpList SET jref = ?, jnum = ?, ref = ?, Title = ?, ixVDim = ?, supRefPlnrMCalc = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpList WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpList WHERE jref = ?", false);
};

bool MyTblPlnrQCtpList::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpList** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpList* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpList / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpList();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;
		if (dbrow[4]) _rec->Title.assign(dbrow[4], dblengths[4]); else _rec->Title = "";
		if (dbrow[5]) _rec->ixVDim = atol((char*) dbrow[5]); else _rec->ixVDim = 0;
		if (dbrow[6]) _rec->supRefPlnrMCalc = atoll((char*) dbrow[6]); else _rec->supRefPlnrMCalc = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpList* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpList / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpList();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			if (dbrow[4]) rec->Title.assign(dbrow[4], dblengths[4]); else rec->Title = "";
			if (dbrow[5]) rec->ixVDim = atol((char*) dbrow[5]); else rec->ixVDim = 0;
			if (dbrow[6]) rec->supRefPlnrMCalc = atoll((char*) dbrow[6]); else rec->supRefPlnrMCalc = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCtpList::insertRec(
			PlnrQCtpList* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])),
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixVDim,&(l[4]),&(n[4]),&(e[4])),
		bindUbigint(&rec->supRefPlnrMCalc,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpList / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpList / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpList::insertRst(
			ListPlnrQCtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpList::updateRec(
			PlnrQCtpList* rec
		) {
	unsigned long l[7]; my_bool n[7]; my_bool e[7];

	l[3] = rec->Title.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindCstring((char*) (rec->Title.c_str()),&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixVDim,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->supRefPlnrMCalc,&(l[5]),&(n[5]),&(e[5])), 
		bindUbigint(&rec->qref,&(l[6]),&(n[6]),&(e[6]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpList / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpList / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpList::updateRst(
			ListPlnrQCtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpList::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpList / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpList / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpList::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpList / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpList / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpList::loadRecByQref(
			ubigint qref
			, PlnrQCtpList** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpList WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpList WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpList
 ******************************************************************************/

PgTblPlnrQCtpList::PgTblPlnrQCtpList() : TblPlnrQCtpList(), PgTable() {
};

PgTblPlnrQCtpList::~PgTblPlnrQCtpList() {
};

void PgTblPlnrQCtpList::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpList_insertRec", "INSERT INTO TblPlnrQCtpList (jref, jnum, ref, Title, ixVDim, supRefPlnrMCalc) VALUES ($1,$2,$3,$4,$5,$6) RETURNING qref", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpList_updateRec", "UPDATE TblPlnrQCtpList SET jref = $1, jnum = $2, ref = $3, Title = $4, ixVDim = $5, supRefPlnrMCalc = $6 WHERE qref = $7", 7, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpList_removeRecByQref", "DELETE FROM TblPlnrQCtpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpList_removeRstByJref", "DELETE FROM TblPlnrQCtpList WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpList_loadRecByQref", "SELECT qref, jref, jnum, ref, Title, ixVDim, supRefPlnrMCalc FROM TblPlnrQCtpList WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpList_loadRstByJref", "SELECT qref, jref, jnum, ref, Title, ixVDim, supRefPlnrMCalc FROM TblPlnrQCtpList WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpList::loadRec(
			PGresult* res
			, PlnrQCtpList** rec
		) {
	char* ptr;

	PlnrQCtpList* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpList();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "suprefplnrmcalc")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->Title.assign(ptr, PQgetlength(res, 0, fnum[4]));
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixVDim = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->supRefPlnrMCalc = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCtpList::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpList* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "title"),
			PQfnumber(res, "ixvdim"),
			PQfnumber(res, "suprefplnrmcalc")
		};

		while (numread < numrow) {
			rec = new PlnrQCtpList();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->Title.assign(ptr, PQgetlength(res, numread, fnum[4]));
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixVDim = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->supRefPlnrMCalc = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCtpList::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpList** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpList / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpList::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpList / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpList::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpList** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpList::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpList::insertRec(
			PlnrQCtpList* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVDim = htonl(rec->ixVDim);
	ubigint _supRefPlnrMCalc = htonl64(rec->supRefPlnrMCalc);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_ixVDim,
		(char*) &_supRefPlnrMCalc
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpList_insertRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpList_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpList::insertRst(
			ListPlnrQCtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpList::updateRec(
			PlnrQCtpList* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);
	uint _ixVDim = htonl(rec->ixVDim);
	ubigint _supRefPlnrMCalc = htonl64(rec->supRefPlnrMCalc);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref,
		rec->Title.c_str(),
		(char*) &_ixVDim,
		(char*) &_supRefPlnrMCalc,
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpList_updateRec", 7, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpList_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpList::updateRst(
			ListPlnrQCtpList& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpList::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpList_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpList_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpList::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpList_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpList_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpList::loadRecByQref(
			ubigint qref
			, PlnrQCtpList** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpList_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpList::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpList& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpList_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

