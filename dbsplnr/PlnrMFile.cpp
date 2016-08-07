/**
  * \file PlnrMFile.cpp
  * database access for table TblPlnrMFile (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#include "PlnrMFile.h"

/******************************************************************************
 class PlnrMFile
 ******************************************************************************/

PlnrMFile::PlnrMFile(
			const ubigint ref
			, const ubigint grp
			, const ubigint own
			, const ubigint refPlnrCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const uint Size
			, const string Comment
		) {

	this->ref = ref;
	this->grp = grp;
	this->own = own;
	this->refPlnrCFile = refPlnrCFile;
	this->refIxVTbl = refIxVTbl;
	this->refUref = refUref;
	this->osrefKContent = osrefKContent;
	this->Archived = Archived;
	this->Filename = Filename;
	this->Archivename = Archivename;
	this->srefKMimetype = srefKMimetype;
	this->Size = Size;
	this->Comment = Comment;
};

bool PlnrMFile::operator==(
			const PlnrMFile& comp
		) {
	return false;
};

bool PlnrMFile::operator!=(
			const PlnrMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class ListPlnrMFile
 ******************************************************************************/

ListPlnrMFile::ListPlnrMFile() {
};

ListPlnrMFile::ListPlnrMFile(
			const ListPlnrMFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i=0;i<nodes.size();i++) nodes[i] = new PlnrMFile(*(src.nodes[i]));
};

ListPlnrMFile::~ListPlnrMFile() {
	clear();
};

void ListPlnrMFile::clear() {
	for (unsigned int i=0;i<nodes.size();i++) delete nodes[i];
	nodes.resize(0);
};

unsigned int ListPlnrMFile::size() const {
	return(nodes.size());
};

void ListPlnrMFile::append(
			PlnrMFile* rec
		) {
	nodes.push_back(rec);
};

PlnrMFile* ListPlnrMFile::operator[](
			const uint ix
		) {
	PlnrMFile* retval = NULL;

	if (ix < size()) retval = nodes[ix];

	return retval;
};

ListPlnrMFile& ListPlnrMFile::operator=(
			const ListPlnrMFile& src
		) {
	PlnrMFile* rec;

	if (&src != this) {
		clear();
		for (unsigned int i=0;i<src.size();i++) {
			rec = new PlnrMFile(*(src.nodes[i]));
			nodes.push_back(rec);
		};
	};

	return(*this);
};

bool ListPlnrMFile::operator==(
			const ListPlnrMFile& comp
		) {
	bool retval;

	retval = (size() == comp.size());

	if (retval) {
		for (unsigned int i=0;i<size();i++) {
			retval = ( *(nodes[i]) == *(comp.nodes[i]) );

			if (!retval) break;
		};
	};

	return retval;
};

bool ListPlnrMFile::operator!=(
			const ListPlnrMFile& comp
		) {
	return(!operator==(comp));
};

/******************************************************************************
 class TblPlnrMFile
 ******************************************************************************/

TblPlnrMFile::TblPlnrMFile() {
};

TblPlnrMFile::~TblPlnrMFile() {
};

bool TblPlnrMFile::loadRecBySQL(
			const string& sqlstr
			, PlnrMFile** rec
		) {
	return false;
};

ubigint TblPlnrMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMFile& rst
		) {
	return 0;
};

void TblPlnrMFile::insertRec(
			PlnrMFile* rec
		) {
};

ubigint TblPlnrMFile::insertNewRec(
			PlnrMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refPlnrCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const uint Size
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMFile* _rec = NULL;

	_rec = new PlnrMFile(0, grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	insertRec(_rec);

	retval = _rec->ref;

	if (rec == NULL) delete _rec;
	else *rec = _rec;

	return retval;
};

ubigint TblPlnrMFile::appendNewRecToRst(
			ListPlnrMFile& rst
			, PlnrMFile** rec
			, const ubigint grp
			, const ubigint own
			, const ubigint refPlnrCFile
			, const uint refIxVTbl
			, const ubigint refUref
			, const string osrefKContent
			, const uint Archived
			, const string Filename
			, const string Archivename
			, const string srefKMimetype
			, const uint Size
			, const string Comment
		) {
	ubigint retval = 0;
	PlnrMFile* _rec = NULL;

	retval = insertNewRec(&_rec, grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment);
	rst.nodes.push_back(_rec);

	if (rec != NULL) *rec = _rec;

	return retval;
};

void TblPlnrMFile::insertRst(
			ListPlnrMFile& rst
			, bool transact
		) {
};

void TblPlnrMFile::updateRec(
			PlnrMFile* rec
		) {
};

void TblPlnrMFile::updateRst(
			ListPlnrMFile& rst
			, bool transact
		) {
};

void TblPlnrMFile::removeRecByRef(
			ubigint ref
		) {
};

bool TblPlnrMFile::loadRecByRef(
			ubigint ref
			, PlnrMFile** rec
		) {
	return false;
};

bool TblPlnrMFile::loadFnmByRef(
			ubigint ref
			, string& val
		) {
	return false;
};

ubigint TblPlnrMFile::loadRefsByClu(
			ubigint refPlnrCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return 0;
};

ubigint TblPlnrMFile::loadRstByClu(
			ubigint refPlnrCFile
			, const bool append
			, ListPlnrMFile& rst
		) {
	return 0;
};

ubigint TblPlnrMFile::loadRstByRefs(
			vector<ubigint>& refs
			, const bool append
			, ListPlnrMFile& rst
		) {
	ubigint numload = 0;
	PlnrMFile* rec = NULL;

	if (!append) rst.clear();

	for (unsigned int i=0;i<refs.size();i++) if (loadRecByRef(refs[i], &rec)) {
		rst.nodes.push_back(rec);
		numload++;
	};

	return numload;
};

// IP myTbl --- BEGIN
/******************************************************************************
 class MyTblPlnrMFile
 ******************************************************************************/

MyTblPlnrMFile::MyTblPlnrMFile() : TblPlnrMFile(), MyTable() {
	stmtInsertRec = NULL;
	stmtUpdateRec = NULL;
	stmtRemoveRecByRef = NULL;
};

MyTblPlnrMFile::~MyTblPlnrMFile() {
	if (stmtInsertRec) delete(stmtInsertRec);
	if (stmtUpdateRec) delete(stmtUpdateRec);
	if (stmtRemoveRecByRef) delete(stmtRemoveRecByRef);
};

void MyTblPlnrMFile::initStatements() {
	stmtInsertRec = createStatement("INSERT INTO TblPlnrMFile (grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES (?,?,?,?,?,?,?,?,?,?,?,?)", false);
	stmtUpdateRec = createStatement("UPDATE TblPlnrMFile SET grp = ?, own = ?, refPlnrCFile = ?, refIxVTbl = ?, refUref = ?, osrefKContent = ?, Archived = ?, Filename = ?, Archivename = ?, srefKMimetype = ?, Size = ?, Comment = ? WHERE ref = ?", false);
	stmtRemoveRecByRef = createStatement("DELETE FROM TblPlnrMFile WHERE ref = ?", false);
};

bool MyTblPlnrMFile::loadRecBySQL(
			const string& sqlstr
			, PlnrMFile** rec
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths;
	PlnrMFile* _rec = NULL;

	bool retval = false;

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMFile / loadRecBySQL)\n");

	if (mysql_num_rows(dbresult) == 1) {
		dbrow = mysql_fetch_row(dbresult);
		dblengths = mysql_fetch_lengths(dbresult);

		_rec = new PlnrMFile();

		if (dbrow[0]) _rec->ref = atoll((char*) dbrow[0]); else _rec->ref = 0;
		if (dbrow[1]) _rec->grp = atoll((char*) dbrow[1]); else _rec->grp = 0;
		if (dbrow[2]) _rec->own = atoll((char*) dbrow[2]); else _rec->own = 0;
		if (dbrow[3]) _rec->refPlnrCFile = atoll((char*) dbrow[3]); else _rec->refPlnrCFile = 0;
		if (dbrow[4]) _rec->refIxVTbl = atol((char*) dbrow[4]); else _rec->refIxVTbl = 0;
		if (dbrow[5]) _rec->refUref = atoll((char*) dbrow[5]); else _rec->refUref = 0;
		if (dbrow[6]) _rec->osrefKContent.assign(dbrow[6], dblengths[6]); else _rec->osrefKContent = "";
		if (dbrow[7]) _rec->Archived = atol((char*) dbrow[7]); else _rec->Archived = 0;
		if (dbrow[8]) _rec->Filename.assign(dbrow[8], dblengths[8]); else _rec->Filename = "";
		if (dbrow[9]) _rec->Archivename.assign(dbrow[9], dblengths[9]); else _rec->Archivename = "";
		if (dbrow[10]) _rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else _rec->srefKMimetype = "";
		if (dbrow[11]) _rec->Size = atol((char*) dbrow[11]); else _rec->Size = 0;
		if (dbrow[12]) _rec->Comment.assign(dbrow[12], dblengths[12]); else _rec->Comment = "";

		retval = true;
	};

	mysql_free_result(dbresult);

	*rec = _rec;
	return retval;
};

ubigint MyTblPlnrMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMFile& rst
		) {
	MYSQL_RES* dbresult; MYSQL_ROW dbrow; unsigned long* dblengths; ubigint numrow; ubigint numread = 0;
	PlnrMFile* rec;

	if (!append) rst.clear();

	if (mysql_real_query(dbs, sqlstr.c_str(), sqlstr.length())) throw DbsException("DbsException / MySQL: error executing query '" + sqlstr + "'\n");

	dbresult = mysql_store_result(dbs);
	if (!dbresult) throw DbsException("DbsException / MySQL: error storing result! (TblPlnrMFile / loadRstBySQL)\n");

	numrow = mysql_num_rows(dbresult);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		while (numread < numrow) {
			dbrow = mysql_fetch_row(dbresult);
			dblengths = mysql_fetch_lengths(dbresult);

			rec = new PlnrMFile();

			if (dbrow[0]) rec->ref = atoll((char*) dbrow[0]); else rec->ref = 0;
			if (dbrow[1]) rec->grp = atoll((char*) dbrow[1]); else rec->grp = 0;
			if (dbrow[2]) rec->own = atoll((char*) dbrow[2]); else rec->own = 0;
			if (dbrow[3]) rec->refPlnrCFile = atoll((char*) dbrow[3]); else rec->refPlnrCFile = 0;
			if (dbrow[4]) rec->refIxVTbl = atol((char*) dbrow[4]); else rec->refIxVTbl = 0;
			if (dbrow[5]) rec->refUref = atoll((char*) dbrow[5]); else rec->refUref = 0;
			if (dbrow[6]) rec->osrefKContent.assign(dbrow[6], dblengths[6]); else rec->osrefKContent = "";
			if (dbrow[7]) rec->Archived = atol((char*) dbrow[7]); else rec->Archived = 0;
			if (dbrow[8]) rec->Filename.assign(dbrow[8], dblengths[8]); else rec->Filename = "";
			if (dbrow[9]) rec->Archivename.assign(dbrow[9], dblengths[9]); else rec->Archivename = "";
			if (dbrow[10]) rec->srefKMimetype.assign(dbrow[10], dblengths[10]); else rec->srefKMimetype = "";
			if (dbrow[11]) rec->Size = atol((char*) dbrow[11]); else rec->Size = 0;
			if (dbrow[12]) rec->Comment.assign(dbrow[12], dblengths[12]); else rec->Comment = "";
			rst.nodes.push_back(rec);

			numread++;
		};
	};

	mysql_free_result(dbresult);

	return(numread);
};

void MyTblPlnrMFile::insertRec(
			PlnrMFile* rec
		) {
	unsigned long l[12]; my_bool n[12]; my_bool e[12];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])),
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])),
		bindUbigint(&rec->refPlnrCFile,&(l[2]),&(n[2]),&(e[2])),
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])),
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])),
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])),
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])),
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])),
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])),
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])),
		bindUint(&rec->Size,&(l[10]),&(n[10]),&(e[10])),
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11]))
	};

	if (mysql_stmt_bind_param(stmtInsertRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMFile / stmtInsertRec)\n");
// IP myInsertRec.execNounq --- BEGIN
	if (mysql_stmt_execute(stmtInsertRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMFile / stmtInsertRec)\n");
	rec->ref = mysql_stmt_insert_id(stmtInsertRec);
// IP myInsertRec.execNounq --- END
};

void MyTblPlnrMFile::insertRst(
			ListPlnrMFile& rst
			, bool transact
		) {
// IP myInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP myInsertRst.transact --- END
};

void MyTblPlnrMFile::updateRec(
			PlnrMFile* rec
		) {
	unsigned long l[13]; my_bool n[13]; my_bool e[13];

	l[5] = rec->osrefKContent.length();
	l[7] = rec->Filename.length();
	l[8] = rec->Archivename.length();
	l[9] = rec->srefKMimetype.length();
	l[11] = rec->Comment.length();

	MYSQL_BIND bind[] = {
		bindUbigint(&rec->grp,&(l[0]),&(n[0]),&(e[0])), 
		bindUbigint(&rec->own,&(l[1]),&(n[1]),&(e[1])), 
		bindUbigint(&rec->refPlnrCFile,&(l[2]),&(n[2]),&(e[2])), 
		bindUint(&rec->refIxVTbl,&(l[3]),&(n[3]),&(e[3])), 
		bindUbigint(&rec->refUref,&(l[4]),&(n[4]),&(e[4])), 
		bindCstring((char*) (rec->osrefKContent.c_str()),&(l[5]),&(n[5]),&(e[5])), 
		bindUint(&rec->Archived,&(l[6]),&(n[6]),&(e[6])), 
		bindCstring((char*) (rec->Filename.c_str()),&(l[7]),&(n[7]),&(e[7])), 
		bindCstring((char*) (rec->Archivename.c_str()),&(l[8]),&(n[8]),&(e[8])), 
		bindCstring((char*) (rec->srefKMimetype.c_str()),&(l[9]),&(n[9]),&(e[9])), 
		bindUint(&rec->Size,&(l[10]),&(n[10]),&(e[10])), 
		bindCstring((char*) (rec->Comment.c_str()),&(l[11]),&(n[11]),&(e[11])), 
		bindUbigint(&rec->ref,&(l[12]),&(n[12]),&(e[12]))
	};

	if (mysql_stmt_bind_param(stmtUpdateRec, bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMFile / stmtUpdateRec)\n");
	if (mysql_stmt_execute(stmtUpdateRec)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMFile / stmtUpdateRec)\n");
};

void MyTblPlnrMFile::updateRst(
			ListPlnrMFile& rst
			, bool transact
		) {
// IP myUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP myUpdateRst.transact --- END
};

void MyTblPlnrMFile::removeRecByRef(
			ubigint ref
		) {
	unsigned long l; my_bool n; my_bool e;

	MYSQL_BIND bind = bindUbigint(&ref,&l,&n,&e);

	if (mysql_stmt_bind_param(stmtRemoveRecByRef, &bind)) throw DbsException("DbsException / MySQL: error binding to statement! (TblPlnrMFile / stmtRemoveRecByRef)\n");
	if (mysql_stmt_execute(stmtRemoveRecByRef)) throw DbsException("DbsException / MySQL: error executing statement! (TblPlnrMFile / stmtRemoveRecByRef)\n");
};

bool MyTblPlnrMFile::loadRecByRef(
			ubigint ref
			, PlnrMFile** rec
		) {
	return loadRecBySQL("SELECT * FROM TblPlnrMFile WHERE ref = " + to_string(ref), rec);
};

bool MyTblPlnrMFile::loadFnmByRef(
			ubigint ref
			, string& val
		) {
	return loadStringBySQL("SELECT Filename FROM TblPlnrMFile WHERE ref = " + to_string(ref) + "", val);
};

ubigint MyTblPlnrMFile::loadRefsByClu(
			ubigint refPlnrCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	return loadRefsBySQL("SELECT ref FROM TblPlnrMFile WHERE refPlnrCFile = " + to_string(refPlnrCFile) + " ORDER BY Filename ASC", append, refs);
};

ubigint MyTblPlnrMFile::loadRstByClu(
			ubigint refPlnrCFile
			, const bool append
			, ListPlnrMFile& rst
		) {
	return loadRstBySQL("SELECT ref, grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblPlnrMFile WHERE refPlnrCFile = " + to_string(refPlnrCFile) + " ORDER BY Filename ASC", append, rst);
};

// IP myTbl --- END

// IP pgTbl --- BEGIN
/******************************************************************************
 class PgTblPlnrMFile
 ******************************************************************************/

PgTblPlnrMFile::PgTblPlnrMFile() : TblPlnrMFile(), PgTable() {
};

PgTblPlnrMFile::~PgTblPlnrMFile() {
	// TODO: run SQL DEALLOCATE to free prepared statements
};

void PgTblPlnrMFile::initStatements() {
	PGresult* res;

	res = PQprepare(dbs, "TblPlnrMFile_insertRec", "INSERT INTO TblPlnrMFile (grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment) VALUES ($1,$2,$3,$4,$5,$6,$7,$8,$9,$10,$11,$12) RETURNING ref", 12, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFile_updateRec", "UPDATE TblPlnrMFile SET grp = $1, own = $2, refPlnrCFile = $3, refIxVTbl = $4, refUref = $5, osrefKContent = $6, Archived = $7, Filename = $8, Archivename = $9, srefKMimetype = $10, Size = $11, Comment = $12 WHERE ref = $13", 13, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFile_removeRecByRef", "DELETE FROM TblPlnrMFile WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);

	res = PQprepare(dbs, "TblPlnrMFile_loadRecByRef", "SELECT ref, grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblPlnrMFile WHERE ref = $1", 1, NULL);
	res = PQprepare(dbs, "TblPlnrMFile_loadFnmByRef", "SELECT Filename FROM TblPlnrMFile WHERE ref = $1", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFile_loadRefsByClu", "SELECT ref FROM TblPlnrMFile WHERE refPlnrCFile = $1 ORDER BY Filename ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
	res = PQprepare(dbs, "TblPlnrMFile_loadRstByClu", "SELECT ref, grp, own, refPlnrCFile, refIxVTbl, refUref, osrefKContent, Archived, Filename, Archivename, srefKMimetype, Size, Comment FROM TblPlnrMFile WHERE refPlnrCFile = $1 ORDER BY Filename ASC", 1, NULL);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) initStatementsErr(res);
};

bool PgTblPlnrMFile::loadRec(
			PGresult* res
			, PlnrMFile** rec
		) {
	char* ptr;

	PlnrMFile* _rec = NULL;
	bool retval = false;

	if (PQntuples(res) == 1) {
		_rec = new PlnrMFile();

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refplnrcfile"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "archived"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "archivename"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size"),
			PQfnumber(res, "comment")
		};

		ptr = PQgetvalue(res, 0, fnum[0]); _rec->ref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[1]); _rec->grp = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[2]); _rec->own = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[3]); _rec->refPlnrCFile = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[4]); _rec->refIxVTbl = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[5]); _rec->refUref = atoll(ptr);
		ptr = PQgetvalue(res, 0, fnum[6]); _rec->osrefKContent.assign(ptr, PQgetlength(res, 0, fnum[6]));
		ptr = PQgetvalue(res, 0, fnum[7]); _rec->Archived = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[8]); _rec->Filename.assign(ptr, PQgetlength(res, 0, fnum[8]));
		ptr = PQgetvalue(res, 0, fnum[9]); _rec->Archivename.assign(ptr, PQgetlength(res, 0, fnum[9]));
		ptr = PQgetvalue(res, 0, fnum[10]); _rec->srefKMimetype.assign(ptr, PQgetlength(res, 0, fnum[10]));
		ptr = PQgetvalue(res, 0, fnum[11]); _rec->Size = atol(ptr);
		ptr = PQgetvalue(res, 0, fnum[12]); _rec->Comment.assign(ptr, PQgetlength(res, 0, fnum[12]));

		retval = true;
	};

	PQclear(res);

	*rec = _rec;
	return retval;
};

ubigint PgTblPlnrMFile::loadRst(
			PGresult* res
			, const bool append
			, ListPlnrMFile& rst
		) {
	ubigint numrow; ubigint numread = 0; char* ptr;
	PlnrMFile* rec;

	if (!append) rst.clear();

	numrow = PQntuples(res);

	if (numrow > 0) {
		rst.nodes.reserve(rst.nodes.size() + numrow);

		int fnum[] = {
			PQfnumber(res, "ref"),
			PQfnumber(res, "grp"),
			PQfnumber(res, "own"),
			PQfnumber(res, "refplnrcfile"),
			PQfnumber(res, "refixvtbl"),
			PQfnumber(res, "refuref"),
			PQfnumber(res, "osrefkcontent"),
			PQfnumber(res, "archived"),
			PQfnumber(res, "filename"),
			PQfnumber(res, "archivename"),
			PQfnumber(res, "srefkmimetype"),
			PQfnumber(res, "size"),
			PQfnumber(res, "comment")
		};

		while (numread < numrow) {
			rec = new PlnrMFile();

			ptr = PQgetvalue(res, numread, fnum[0]); rec->ref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[1]); rec->grp = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[2]); rec->own = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[3]); rec->refPlnrCFile = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[4]); rec->refIxVTbl = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[5]); rec->refUref = atoll(ptr);
			ptr = PQgetvalue(res, numread, fnum[6]); rec->osrefKContent.assign(ptr, PQgetlength(res, numread, fnum[6]));
			ptr = PQgetvalue(res, numread, fnum[7]); rec->Archived = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[8]); rec->Filename.assign(ptr, PQgetlength(res, numread, fnum[8]));
			ptr = PQgetvalue(res, numread, fnum[9]); rec->Archivename.assign(ptr, PQgetlength(res, numread, fnum[9]));
			ptr = PQgetvalue(res, numread, fnum[10]); rec->srefKMimetype.assign(ptr, PQgetlength(res, numread, fnum[10]));
			ptr = PQgetvalue(res, numread, fnum[11]); rec->Size = atol(ptr);
			ptr = PQgetvalue(res, numread, fnum[12]); rec->Comment.assign(ptr, PQgetlength(res, numread, fnum[12]));

			rst.nodes.push_back(rec);

			numread++;
		};
	};

	PQclear(res);

	return numread;
};

bool PgTblPlnrMFile::loadRecByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, PlnrMFile** rec
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFile / " + srefStmt + ")\n");

	return loadRec(res, rec);
};

// IP pgLoadRstByStmt --- BEGIN
ubigint PgTblPlnrMFile::loadRstByStmt(
			const string& srefStmt
			, const unsigned int N
			, const char** vals
			, const int* l
			, const int* f
			, const bool append
			, ListPlnrMFile& rst
		) {
	PGresult* res;

	res = PQexecPrepared(dbs, srefStmt.c_str(), N, vals, l, f, 0);
	
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFile / " + srefStmt + ")\n");

	return loadRst(res, append, rst);
};
// IP pgLoadRstByStmt --- END

bool PgTblPlnrMFile::loadRecBySQL(
			const string& sqlstr
			, PlnrMFile** rec
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRec(res, rec);
};

ubigint PgTblPlnrMFile::loadRstBySQL(
			const string& sqlstr
			, const bool append
			, ListPlnrMFile& rst
		) {
	PGresult* res;

	res = PQexec(dbs, sqlstr.c_str());

	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing query '" + sqlstr + "'\n");

	return loadRst(res, append, rst);
};

void PgTblPlnrMFile::insertRec(
			PlnrMFile* rec
		) {
	PGresult* res;
	char* ptr;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refPlnrCFile = htonl64(rec->refPlnrCFile);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Archived = htonl(rec->Archived);
	uint _Size = htonl(rec->Size);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refPlnrCFile,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		(char*) &_Archived,
		rec->Filename.c_str(),
		rec->Archivename.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		rec->Comment.c_str()
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		0,
		sizeof(uint),
		0
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0};

	res = PQexecPrepared(dbs, "TblPlnrMFile_insertRec", 12, vals, l, f, 0);

// IP pgInsertRec.execNounq --- BEGIN
	if (PQresultStatus(res) != PGRES_TUPLES_OK) throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFile_insertRec)\n");

	ptr = PQgetvalue(res, 0, 0); rec->ref = atoll(ptr);
// IP pgInsertRec.execNounq --- END

	PQclear(res);
};

void PgTblPlnrMFile::insertRst(
			ListPlnrMFile& rst
			, bool transact
		) {
// IP pgInsertRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) insertRec(rst.nodes[i]);
// IP pgInsertRst.transact --- END
};

void PgTblPlnrMFile::updateRec(
			PlnrMFile* rec
		) {
	PGresult* res;

	ubigint _grp = htonl64(rec->grp);
	ubigint _own = htonl64(rec->own);
	ubigint _refPlnrCFile = htonl64(rec->refPlnrCFile);
	uint _refIxVTbl = htonl(rec->refIxVTbl);
	ubigint _refUref = htonl64(rec->refUref);
	uint _Archived = htonl(rec->Archived);
	uint _Size = htonl(rec->Size);
	ubigint _ref = htonl64(rec->ref);

	const char* vals[] = {
		(char*) &_grp,
		(char*) &_own,
		(char*) &_refPlnrCFile,
		(char*) &_refIxVTbl,
		(char*) &_refUref,
		rec->osrefKContent.c_str(),
		(char*) &_Archived,
		rec->Filename.c_str(),
		rec->Archivename.c_str(),
		rec->srefKMimetype.c_str(),
		(char*) &_Size,
		rec->Comment.c_str(),
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(ubigint),
		sizeof(uint),
		sizeof(ubigint),
		0,
		sizeof(uint),
		0,
		0,
		0,
		sizeof(uint),
		0,
		sizeof(ubigint)
	};
	const int f[] = {1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1};

	res = PQexecPrepared(dbs, "TblPlnrMFile_updateRec", 13, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFile_updateRec)\n");

	PQclear(res);
};

void PgTblPlnrMFile::updateRst(
			ListPlnrMFile& rst
			, bool transact
		) {
// IP pgUpdateRst.transact --- BEGIN
	if (transact) begin();
	for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
	if (transact) if (!commit()) for (unsigned int i=0;i<rst.nodes.size();i++) updateRec(rst.nodes[i]);
// IP pgUpdateRst.transact --- END
};

void PgTblPlnrMFile::removeRecByRef(
			ubigint ref
		) {
	PGresult* res;

	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	res = PQexecPrepared(dbs, "TblPlnrMFile_removeRecByRef", 1, vals, l, f, 0);

	if (PQresultStatus(res) != PGRES_COMMAND_OK)
		throw DbsException("DbsException / PgSQL: error executing statement! (TblPlnrMFile_removeRecByRef)\n");

	PQclear(res);
};

bool PgTblPlnrMFile::loadRecByRef(
			ubigint ref
			, PlnrMFile** rec
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRecByStmt("TblPlnrMFile_loadRecByRef", 1, vals, l, f, rec);
};

bool PgTblPlnrMFile::loadFnmByRef(
			ubigint ref
			, string& val
		) {
	ubigint _ref = htonl64(ref);

	const char* vals[] = {
		(char*) &_ref
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadStringByStmt("TblPlnrMFile_loadFnmByRef", 1, vals, l, f, val);
};

ubigint PgTblPlnrMFile::loadRefsByClu(
			ubigint refPlnrCFile
			, const bool append
			, vector<ubigint>& refs
		) {
	ubigint _refPlnrCFile = htonl64(refPlnrCFile);

	const char* vals[] = {
		(char*) &_refPlnrCFile
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRefsByStmt("TblPlnrMFile_loadRefsByClu", 1, vals, l, f, append, refs);
};

ubigint PgTblPlnrMFile::loadRstByClu(
			ubigint refPlnrCFile
			, const bool append
			, ListPlnrMFile& rst
		) {
	ubigint _refPlnrCFile = htonl64(refPlnrCFile);

	const char* vals[] = {
		(char*) &_refPlnrCFile
	};
	const int l[] = {
		sizeof(ubigint)
	};
	const int f[] = {1};

	return loadRstByStmt("TblPlnrMFile_loadRstByClu", 1, vals, l, f, append, rst);
};

// IP pgTbl --- END

