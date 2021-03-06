/**
  * \file PlnrQCtpRef1NFile.cpp
  * Dbs and XML wrapper for table TblPlnrQCtpRef1NFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrQCtpRef1NFile.h"

/******************************************************************************
 class PlnrQCtpRef1NFile
 ******************************************************************************/

PlnrQCtpRef1NFile::PlnrQCtpRef1NFile(
			const ubigint qref
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	this->qref = qref;
	this->jref = jref;
	this->jnum = jnum;
	this->ref = ref;
	this->stubRef = stubRef;
};

void PlnrQCtpRef1NFile::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool jnumattr
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "PlnrQCtpRef1NFile";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
	if (jnumattr) xmlTextWriterWriteAttribute(wr, BAD_CAST "jnum", BAD_CAST to_string(jnum).c_str());
	if (shorttags) {
		writeString(wr, "ref", stubRef);
	} else {
		writeString(wr, "stubRef", stubRef);
	};
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class ListPlnrQCtpRef1NFile
 ******************************************************************************/

ListPlnrQCtpRef1NFile::ListPlnrQCtpRef1NFile() {
};

ListPlnrQCtpRef1NFile::ListPlnrQCtpRef1NFile(
			const ListPlnrQCtpRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrQCtpRef1NFile(*(src.nodes[i]));
};

ListPlnrQCtpRef1NFile::~ListPlnrQCtpRef1NFile() {
	clear();
};

void ListPlnrQCtpRef1NFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrQCtpRef1NFile::size() const {
	return(nodes.size());
};

void ListPlnrQCtpRef1NFile::append(
			PlnrQCtpRef1NFile* rec
		) {
	nodes.push_back(rec);
};

ListPlnrQCtpRef1NFile& ListPlnrQCtpRef1NFile::operator=(
			const ListPlnrQCtpRef1NFile& src
		) {
	PlnrQCtpRef1NFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrQCtpRef1NFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

// IP listWriteXML --- BEGIN
void ListPlnrQCtpRef1NFile::writeXML(
			xmlTextWriter* wr
			, string difftag
		) {
	// generate top XML tag
	if (difftag.length() == 0) difftag = "ListPlnrQCtpRef1NFile";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		for (unsigned int i=0;i<nodes.size();i++) nodes[i]->writeXML(wr, "row", true, true);
	xmlTextWriterEndElement(wr);
};
// IP listWriteXML --- END

/******************************************************************************
 class TblPlnrQCtpRef1NFile
 ******************************************************************************/

TblPlnrQCtpRef1NFile::TblPlnrQCtpRef1NFile() {
};

TblPlnrQCtpRef1NFile::~TblPlnrQCtpRef1NFile() {
};

bool TblPlnrQCtpRef1NFile::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpRef1NFile** rec
		) {
	return false;
};

ubigint TblPlnrQCtpRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	return 0;
};

void TblPlnrQCtpRef1NFile::insertRec(
			PlnrQCtpRef1NFile* rec
		) {
};

ubigint TblPlnrQCtpRef1NFile::insertNewRec(
			PlnrQCtpRef1NFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQCtpRef1NFile* _rec = NULL;

	_rec = new PlnrQCtpRef1NFile(0, jref, jnum, ref, stubRef);
	insertRec(_rec);

	retval = _rec->qref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrQCtpRef1NFile::appendNewRecToRst(
			ListPlnrQCtpRef1NFile& rst
			, PlnrQCtpRef1NFile** rec
			, const ubigint jref
			, const uint jnum
			, const ubigint ref
			, const string stubRef
		) {
	ubigint retval = 0;
	PlnrQCtpRef1NFile* _rec = NULL;

	retval = insertNewRec(&_rec, jref, jnum, ref, stubRef);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrQCtpRef1NFile::insertRst(
			ListPlnrQCtpRef1NFile& rst
		) {
};

void TblPlnrQCtpRef1NFile::updateRec(
			PlnrQCtpRef1NFile* rec
		) {
};

void TblPlnrQCtpRef1NFile::updateRst(
			ListPlnrQCtpRef1NFile& rst
		) {
};

void TblPlnrQCtpRef1NFile::removeRecByQref(
			ubigint qref
		) {
};

void TblPlnrQCtpRef1NFile::removeRstByJref(
			ubigint jref
		) {
};

bool TblPlnrQCtpRef1NFile::loadRecByQref(
			ubigint qref
			, PlnrQCtpRef1NFile** rec
		) {
	return false;
};

ubigint TblPlnrQCtpRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	return 0;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrQCtpRef1NFile
 ******************************************************************************/

MyTblPlnrQCtpRef1NFile::MyTblPlnrQCtpRef1NFile() : TblPlnrQCtpRef1NFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByQref = NULL;
	stmtRemoveRstByJref = NULL;
};

MyTblPlnrQCtpRef1NFile::~MyTblPlnrQCtpRef1NFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByQref) delete(stmtRemoveRecByQref);
	if (stmtRemoveRstByJref) delete(stmtRemoveRstByJref);
};

void MyTblPlnrQCtpRef1NFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrQCtpRef1NFile (jref, jnum, ref) VALUES (?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrQCtpRef1NFile SET jref = ?, jnum = ?, ref = ? WHERE qref = ?", false);
	stmtRemoveRecByQref = createStatement("DELETE FROM TblPlnrQCtpRef1NFile WHERE qref = ?", false);
	stmtRemoveRstByJref = createStatement("DELETE FROM TblPlnrQCtpRef1NFile WHERE jref = ?", false);
};

bool MyTblPlnrQCtpRef1NFile::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpRef1NFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrQCtpRef1NFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpRef1NFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrQCtpRef1NFile();

		if (dbrow[0]) _rec->qref = atoll((char*) dbrow[0]); else _rec->qref = 0;
		if (dbrow[1]) _rec->jref = atoll((char*) dbrow[1]); else _rec->jref = 0;
		if (dbrow[2]) _rec->jnum = atol((char*) dbrow[2]); else _rec->jnum = 0;
		if (dbrow[3]) _rec->ref = atoll((char*) dbrow[3]); else _rec->ref = 0;

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrQCtpRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrQCtpRef1NFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrQCtpRef1NFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrQCtpRef1NFile();

			if (dbrow[0]) rec->qref = atoll((char*) dbrow[0]); else rec->qref = 0;
			if (dbrow[1]) rec->jref = atoll((char*) dbrow[1]); else rec->jref = 0;
			if (dbrow[2]) rec->jnum = atol((char*) dbrow[2]); else rec->jnum = 0;
			if (dbrow[3]) rec->ref = atoll((char*) dbrow[3]); else rec->ref = 0;
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrQCtpRef1NFile::insertRec(
			PlnrQCtpRef1NFile* rec
		) {
	unsigned long l[3]; my_bool n[3]; my_bool e[3];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])),
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpRef1NFile / stmtInsertRec)\n");
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpRef1NFile / stmtInsertRec)\n");
	rec->qref = mysql_stmt_insert_id(stmtInsertRec);
};

void MyTblPlnrQCtpRef1NFile::insertRst(
			ListPlnrQCtpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void MyTblPlnrQCtpRef1NFile::updateRec(
			PlnrQCtpRef1NFile* rec
		) {
	unsigned long l[4]; my_bool n[4]; my_bool e[4];

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->jref,&(l[0]),&(n[0]),&(e[0])), 
		bindUint(&rec->jnum,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->ref,&(l[2]),&(n[2]),&(e[2])), 
		bindUbigint(&rec->qref,&(l[3]),&(n[3]),&(e[3]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpRef1NFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpRef1NFile / stmtUpdateRec)\n");
};

void MyTblPlnrQCtpRef1NFile::updateRst(
			ListPlnrQCtpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void MyTblPlnrQCtpRef1NFile::removeRecByQref(
			ubigint qref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&qref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByQref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpRef1NFile / stmtRemoveRecByQref)\n");
	if (mysql_stmt_execute(stmtRemoveRecByQref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpRef1NFile / stmtRemoveRecByQref)\n");
};

void MyTblPlnrQCtpRef1NFile::removeRstByJref(
			ubigint jref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&jref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRstByJref, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrQCtpRef1NFile / stmtRemoveRstByJref)\n");
	if (mysql_stmt_execute(stmtRemoveRstByJref)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrQCtpRef1NFile / stmtRemoveRstByJref)\n");
};

bool MyTblPlnrQCtpRef1NFile::loadRecByQref(
			ubigint qref
			, PlnrQCtpRef1NFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrQCtpRef1NFile WHERE qref = " + to_string(qref), rec);
};

ubigint MyTblPlnrQCtpRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	return loadRstBySQL("SELECT * FROM TblPlnrQCtpRef1NFile WHERE jref = " + to_string(jref) + " ORDER BY jnum ASC", append, rst);
};
// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrQCtpRef1NFile
 ******************************************************************************/

PgTblPlnrQCtpRef1NFile::PgTblPlnrQCtpRef1NFile() : TblPlnrQCtpRef1NFile(), PgTable() {
};

PgTblPlnrQCtpRef1NFile::~PgTblPlnrQCtpRef1NFile() {
};

void PgTblPlnrQCtpRef1NFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrQCtpRef1NFile_insertRec", "INSERT INTO TblPlnrQCtpRef1NFile (jref, jnum, ref) VALUES ($1,$2,$3) RETURNING qref", 3, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpRef1NFile_updateRec", "UPDATE TblPlnrQCtpRef1NFile SET jref = $1, jnum = $2, ref = $3 WHERE qref = $4", 4, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpRef1NFile_removeRecByQref", "DELETE FROM TblPlnrQCtpRef1NFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpRef1NFile_removeRstByJref", "DELETE FROM TblPlnrQCtpRef1NFile WHERE jref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrQCtpRef1NFile_loadRecByQref", "SELECT qref, jref, jnum, ref FROM TblPlnrQCtpRef1NFile WHERE qref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrQCtpRef1NFile_loadRstByJref", "SELECT qref, jref, jnum, ref FROM TblPlnrQCtpRef1NFile WHERE jref = $1 ORDER BY jnum ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrQCtpRef1NFile::loadRec(
			PGresult* res
			, PlnrQCtpRef1NFile** rec
		) {
	char* ptr;

	PlnrQCtpRef1NFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrQCtpRef1NFile();

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->qref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->jref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->jnum = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->ref = atoll(ptr);

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrQCtpRef1NFile::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrQCtpRef1NFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "qref"),
			PQfnumber(res, "jref"),
			PQfnumber(res, "jnum"),
			PQfnumber(res, "ref")
		};

		while (numread < numrow) {
			rec = new PlnrQCtpRef1NFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->qref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->jref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->jnum = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->ref = atoll(ptr);

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrQCtpRef1NFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrQCtpRef1NFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpRef1NFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpRef1NFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpRef1NFile / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};

bool PgTblPlnrQCtpRef1NFile::loadRecBySQL(
			const string& sqlstr
			, PlnrQCtpRef1NFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrQCtpRef1NFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrQCtpRef1NFile::insertRec(
			PlnrQCtpRef1NFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _jref = htonl64(rec->jref);
	uint _jnum = htonl(rec->jnum);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_jref,
		(char*) &_jnum,
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCtpRef1NFile_insertRec", 3, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpRef1NFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, PQfnumber(res, "qref")); rec->qref = atoll(ptr);

	PQclear(res);
};

void PgTblPlnrQCtpRef1NFile::insertRst(
			ListPlnrQCtpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
};

void PgTblPlnrQCtpRef1NFile::updateRec(
			PlnrQCtpRef1NFile* rec
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
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1};

	res = PQexecPrepared(dbs, "TblPlnrQCtpRef1NFile_updateRec", 4, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpRef1NFile_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrQCtpRef1NFile::updateRst(
			ListPlnrQCtpRef1NFile& rst
		) {
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
};

void PgTblPlnrQCtpRef1NFile::removeRecByQref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpRef1NFile_removeRecByQref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpRef1NFile_removeRecByQref)\n");

	PQclear(res);
};

void PgTblPlnrQCtpRef1NFile::removeRstByJref(
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

	res = PQexecPrepared(dbs, "TblPlnrQCtpRef1NFile_removeRstByJref", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrQCtpRef1NFile_removeRstByJref)\n");

	PQclear(res);
};

bool PgTblPlnrQCtpRef1NFile::loadRecByQref(
			ubigint qref
			, PlnrQCtpRef1NFile** rec
		) {
	ubigint _qref = htonl64(qref);

	const char* vals[] = {
		(char*) &_qref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrQCtpRef1NFile_loadRecByQref", 1, vals, l, f, rec);
};

ubigint PgTblPlnrQCtpRef1NFile::loadRstByJref(
			ubigint jref
			, const bool append
			, ListPlnrQCtpRef1NFile& rst
		) {
	ubigint _jref = htonl64(jref);

	const char* vals[] = {
		(char*) &_jref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrQCtpRef1NFile_loadRstByJref", 1, vals, l, f, append, rst);
};
// IP pgTbl --- END

