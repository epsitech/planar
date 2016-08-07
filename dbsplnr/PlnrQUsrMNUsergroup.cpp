/**
  * \file PlnrQUsrMNUsergroup.cpp
  * Dbs and XML wrapper for table TblPlnrQUsrMNUsergroup (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQUsrMNUsergroup.h"

/******************************************************************************
 class PlnrQUsrMNUsergroup
 ******************************************************************************/

PlnrQUsrMNUsergroup::PlnrQUsrMNUsergroup(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->mref = mref;
	this->stubMref = stubMref;
	this->ref = ref;
	this->ixPlnrVUserlevel = ixPlnrVUserlevel;
	this->srefIxPlnrVUserlevel = srefIxPlnrVUserlevel;
	this->titIxPlnrVUserlevel = titIxPlnrVUserlevel;
};

void PlnrQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQUsrMNUsergroup";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "mref", stubMref);
		writeString(wr, "ulv", srefIxPlnrVUserlevel);
		writeString(wr, "ulv2", titIxPlnrVUserlevel);
	} else {
		writeString(wr, "stubMref", stubMref);
		writeString(wr, "srefIxPlnrVUserlevel", srefIxPlnrVUserlevel);
		writeString(wr, "titIxPlnrVUserlevel", titIxPlnrVUserlevel);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQUsrMNUsergroup
 ******************************************************************************/

ListPlnrQUsrMNUsergroup::ListPlnrQUsrMNUsergroup() {
};

ListPlnrQUsrMNUsergroup::ListPlnrQUsrMNUsergroup(
			const ListPlnrQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQUsrMNUsergroup(*(src.nodes[i]));
};

ListPlnrQUsrMNUsergroup::~ListPlnrQUsrMNUsergroup() {
	clear();
};

void ListPlnrQUsrMNUsergroup::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQUsrMNUsergroup::size() const {
	return(nodes.size());
};

void ListPlnrQUsrMNUsergroup::append(
			PlnrQUsrMNUsergroup* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQUsrMNUsergroup& ListPlnrQUsrMNUsergroup::operator=(
			const ListPlnrQUsrMNUsergroup& src
		) {
	PlnrQUsrMNUsergroup* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQUsrMNUsergroup(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQUsrMNUsergroup::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQUsrMNUsergroup";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQUsrMNUsergroup
 ******************************************************************************/

TblPlnrQUsrMNUsergroup::TblPlnrQUsrMNUsergroup() {
};

TblPlnrQUsrMNUsergroup::~TblPlnrQUsrMNUsergroup() {
};

bool TblPlnrQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblPlnrQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	return 0;
};

void TblPlnrQUsrMNUsergroup::insertRec(
			PlnrQUsrMNUsergroup* rec
		) {
};

ubigint TblPlnrQUsrMNUsergroup::insertNewRec(
			PlnrQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrQUsrMNUsergroup* _rec = NULL;

	_rec = new PlnrQUsrMNUsergroup(0, jref, jnum, mref, stubMref, ref, ixPlnrVUserlevel, srefIxPlnrVUserlevel, titIxPlnrVUserlevel);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQUsrMNUsergroup::appendNewRecToRst(
			ListPlnrQUsrMNUsergroup& rst
			, PlnrQUsrMNUsergroup** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint mref
			, const string stubMref
			, const ubigint ref
			, const uint ixPlnrVUserlevel
			, const string srefIxPlnrVUserlevel
			, const string titIxPlnrVUserlevel
		) {
	ubigint retval = 0;
	PlnrQUsrMNUsergroup* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, mref, stubMref, ref, ixPlnrVUserlevel, srefIxPlnrVUserlevel, titIxPlnrVUserlevel);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQUsrMNUsergroup::insertRst(
			ListPlnrQUsrMNUsergroup& rst
		) {
};

void TblPlnrQUsrMNUsergroup::updateRec(
			PlnrQUsrMNUsergroup* rec
		) {
};

void TblPlnrQUsrMNUsergroup::updateRst(
			ListPlnrQUsrMNUsergroup& rst
		) {
};

void TblPlnrQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, PlnrQUsrMNUsergroup** rec
		) {
	return false;
};

ubigint TblPlnrQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQUsrMNUsergroup
 ******************************************************************************/

MyTblPlnrQUsrMNUsergroup::MyTblPlnrQUsrMNUsergroup() : TblPlnrQUsrMNUsergroup(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQUsrMNUsergroup::~MyTblPlnrQUsrMNUsergroup() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQUsrMNUsergroup::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQUsrMNUsergroup (jref, jnum, mref, ref, ixPlnrVUserlevel) VALUES (?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQUsrMNUsergroup SET jref = ?, jnum = ?, mref = ?, ref = ?, ixPlnrVUserlevel = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQUsrMNUsergroup WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQUsrMNUsergroup WHERE jref = ?", false);
};

bool MyTblPlnrQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrMNUsergroup** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQUsrMNUsergroup* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsrMNUsergroup / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQUsrMNUsergroup();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->mref = atoll((char*) dbrow[3]); else _rec->mref = 0;
		if (dbrow[4]) _rec->ref = atoll((char*) dbrow[4]); else _rec->ref = 0;
		if (dbrow[5]) _rec->ixPlnrVUserlevel = atol((char*) dbrow[5]); else _rec->ixPlnrVUserlevel = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQUsrMNUsergroup* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQUsrMNUsergroup / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQUsrMNUsergroup();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->mref = atoll((char*) dbrow[3]); else rec->mref = 0;
			if (dbrow[4]) rec->ref = atoll((char*) dbrow[4]); else rec->ref = 0;
			if (dbrow[5]) rec->ixPlnrVUserlevel = atol((char*) dbrow[5]); else rec->ixPlnrVUserlevel = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQUsrMNUsergroup::insertRec(
			PlnrQUsrMNUsergroup* rec
		) {
	unsigned long l[5]; my_bool n[5]; my_bool e[5];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])),
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])),
		bindUint(&rec->ixPlnrVUserlevel,&(l[4]),&(n[4]),&(e[4]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrMNUsergroup / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrMNUsergroup / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQUsrMNUsergroup::insertRst(
			ListPlnrQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQUsrMNUsergroup::updateRec(
			PlnrQUsrMNUsergroup* rec
		) {
	unsigned long l[6]; my_bool n[6]; my_bool e[6];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->mref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->ref,&(l[3]),&(n[3]),&(e[3])), 
		bindUint(&rec->ixPlnrVUserlevel,&(l[4]),&(n[4]),&(e[4])), 
		bindUbigint(&rec->qref,&(l[5]),&(n[5]),&(e[5]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrMNUsergroup / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrMNUsergroup / stmtUpdateRec)\n");
};

void MyTblPlnrQUsrMNUsergroup::updateRst(
			ListPlnrQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQUsrMNUsergroup::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrMNUsergroup / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrMNUsergroup / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQUsrMNUsergroup::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQUsrMNUsergroup / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQUsrMNUsergroup / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, PlnrQUsrMNUsergroup** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQUsrMNUsergroup WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQUsrMNUsergroup WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQUsrMNUsergroup
 ******************************************************************************/

PgTblPlnrQUsrMNUsergroup::PgTblPlnrQUsrMNUsergroup() : TblPlnrQUsrMNUsergroup(), PgTable() {
};

PgTblPlnrQUsrMNUsergroup::~PgTblPlnrQUsrMNUsergroup() {
};

void PgTblPlnrQUsrMNUsergroup::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQUsrMNUsergroup_insertRec", "INSERT INTO TblPlnrQUsrMNUsergroup (jref, jnum, mref, ref, ixPlnrVUserlevel) VALUES ($1,$2,$3,$4,$5) RETURNING qref", 5, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrMNUsergroup_updateRec", "UPDATE TblPlnrQUsrMNUsergroup SET jref = $1, jnum = $2, mref = $3, ref = $4, ixPlnrVUserlevel = $5 WHERE qref = $6", 6, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrMNUsergroup_removeRecByQref", "DELETE FROM TblPlnrQUsrMNUsergroup WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrMNUsergroup_removeRstByJref", "DELETE FROM TblPlnrQUsrMNUsergroup WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQUsrMNUsergroup_loadRecByQref", "SELECT qref, jref, jnum, mref, ref, ixPlnrVUserlevel FROM TblPlnrQUsrMNUsergroup WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQUsrMNUsergroup_loadRstByJref", "SELECT qref, jref, jnum, mref, ref, ixPlnrVUserlevel FROM TblPlnrQUsrMNUsergroup WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQUsrMNUsergroup::loadRec(
			PGresult* res
			, PlnrQUsrMNUsergroup** rec
		) {
	char* ptr;

	PlnrQUsrMNUsergroup* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQUsrMNUsergroup();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "mref"),
			PQfnumber(res, "ref"),
			PQfnumber(res, "ixplnrvuserlevel")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->mref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->ixPlnrVUserlevel = atol(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQUsrMNUsergroup::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQUsrMNUsergroup* rec;

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
			PQfnumber(res, "ixplnrvuserlevel")
		};

		while (numread < numrow) {
			rec = new PlnrQUsrMNUsergroup();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->mref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->ixPlnrVUserlevel = atol(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQUsrMNUsergroup::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrMNUsergroup / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsrMNUsergroup::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrMNUsergroup / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQUsrMNUsergroup::loadRecBySQL(
			const string& sqlstr
			, PlnrQUsrMNUsergroup** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQUsrMNUsergroup::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQUsrMNUsergroup::insertRec(
			PlnrQUsrMNUsergroup* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixPlnrVUserlevel
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint)
	};
	const int f[] = {1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsrMNUsergroup_insertRec", 5, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrMNUsergroup_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQUsrMNUsergroup::insertRst(
			ListPlnrQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQUsrMNUsergroup::updateRec(
			PlnrQUsrMNUsergroup* rec
		) {
	PGresult* res;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _mref = htonl64(rec->mref);
	ubigint _ref = htonl64(rec->ref);
	uint _ixPlnrVUserlevel = htonl(rec->ixPlnrVUserlevel);
	ubigint _qref = htonl64(rec->qref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_mref,
		(char*) &_ref,
		(char*) &_ixPlnrVUserlevel,
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQUsrMNUsergroup_updateRec", 6, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrMNUsergroup_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQUsrMNUsergroup::updateRst(
			ListPlnrQUsrMNUsergroup& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQUsrMNUsergroup::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrMNUsergroup_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrMNUsergroup_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQUsrMNUsergroup::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQUsrMNUsergroup_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQUsrMNUsergroup_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQUsrMNUsergroup::loadRecByQref(
			ubigint qref
			, PlnrQUsrMNUsergroup** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQUsrMNUsergroup_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQUsrMNUsergroup::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQUsrMNUsergroup& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQUsrMNUsergroup_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

