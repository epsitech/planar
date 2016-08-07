/**
  * \file PlnrExpDottext.cpp
  * Plnr operation processor -  (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrExpDottext.h"

DpchRetPlnr* PlnrExpDottext::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpDottext* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	ListPlnrMVertex vtxs, vtxs2;
	ListPlnrMLineguide lgs, lgs2;
	ListPlnrMFace fces, fces2;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	string text0 = "test"; string text;
	double h0 = 5.0; double h;

	loadStringDevpar(dbsplnr, refPlnrMDevice, 0, "text", text0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "h", h0);

	// --- expand baseline
	text = text0;
	h = h0;

	dbsplnr->begin();

	vertices(dbsplnr, 0, refPlnrMDevice, false, text, h, vtxs);
	guides(dbsplnr, 0, refPlnrMDevice, text, vtxs, lgs);
	faces(dbsplnr, 0, refPlnrMDevice, text, refSruAll, vtxs, lgs, fces);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		text = text0;
		h = h0;

		modpar = 0;

		if (loadStringDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "text", text)) modpar += _TEXT;
		if (text.length() != text0.length()) modpar += _TEXTLEN;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "h", h)) modpar += _H;

		// dto/dnoto modifications, no arcguides; dto (text) affects faces only if text length remains constant; otherwise affects vertices, lineguides, faces
		dbsplnr->begin();

		if (modpar == 0) {
			// do nothing
		} else if (modpar & _TEXTLEN) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		} else if (modpar & _TEXT) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::FCE);
		} else {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::NOTO);
		};

		if (modpar & _TEXTLEN) {
			vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, false, text, h, vtxs2);
			guides(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, text, vtxs2, lgs2);
			faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, text, refSruAll, vtxs2, lgs2, fces2);

			vtxs2.clear();
			lgs2.clear();
			fces2.clear();

		} else {
			if (modpar & _H) vertices(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, true, text, h, vtxs);

			if (modpar & _TEXT) {
				faces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, text, refSruAll, vtxs, lgs, fces2);
				fces2.clear();
			};
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpDottext::vertices(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const bool xyonly
			, const string& text
			, const double h
			, ListPlnrMVertex& vtxs
		) {
	ostringstream str;

	unsigned int N = text.length();
	double Nd = (double) N;
	double dot = h/7.0;
	double dx = 0.5* ((Nd-1.0)*6.0*dot + 5*dot);
	double dy = 0.5*h;

	// center vertex
	if (!xyonly) addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, "vctr", 0.0, 0.0, vtxs);

	// character loop ; indices start from 1
	for (unsigned int i=1;i<=N;i++) {
		// row loop
		for (unsigned int m=0;m<8;m++) {
			// column loop
			for (unsigned int n=0;n<6;n++) {
				str.str(""); str << "vc" << i << "_" << (m*6+n);
				
				if (!xyonly) {
					addVertex(dbsplnr, x1RefPlnrMDesign, VecPlnrVMVertexHkTbl::DEV, refPlnrMDevice, str.str(), ((double) (i-1))*6.0*dot + ((double) n)*dot -dx, h - ((double) m)*dot -dy, vtxs);
				} else {
					addVertexXYByVsref(dbsplnr, str.str(), x1RefPlnrMDesign, ((double) (i-1))*6.0*dot + ((double) n)*dot -dx, h - ((double) m)*dot -dy, vtxs);
				};
			};
		};
	};
};

void PlnrExpDottext::guides(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const string& text
			, const ListPlnrMVertex& vtxs
			, ListPlnrMLineguide& lgs
		) {
	ostringstream str;

	vector<unsigned int> vics;

	unsigned int N = text.length();

	// -- line guides
	for (unsigned int i=1;i<=N;i++) {
		// - character horizontal line guides
		for (unsigned int m=1;m<7;m++) {
			str.str(""); str << "lhc" << i << "_" << m;

			// line guide comprises six vertices in a row
			vics.resize(0);
			for (unsigned int n=0;n<6;n++) vics.push_back(1 + (i-1)*8*6 + m*6 + n);

			addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vics, vtxs, lgs);
		};

		// - character vertical line guides
		for (unsigned int n=0;n<6;n++) {
			str.str(""); str << "lvc" << i << "_" << n;

			// line guide comprises eight vertices in a column
			vics.resize(0);
			for (unsigned int m=0;m<8;m++) vics.push_back(1 + (i-1)*8*6 + m*6 + n);

			addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, str.str(), vics, vtxs, lgs);
		};
	};

	// - top and bottom horizontal line guides
	vics.resize(0);
	for (unsigned int i=1;i<=N;i++) {
		for (unsigned int n=0;n<6;n++) vics.push_back(1 + (i-1)*8*6 + 0*6 + n);
	};
	addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, "lh0", vics, vtxs, lgs);

	vics.resize(0);
	for (unsigned int i=1;i<=N;i++) {
		for (unsigned int n=0;n<6;n++) vics.push_back(1 + (i-1)*8*6 + 7*6 + n);
	};
	addLineguideByVics(dbsplnr, x1RefPlnrMDesign, VecPlnrVMLineguideHkTbl::DEV, refPlnrMDevice, "lh7", vics, vtxs, lgs);
};

void PlnrExpDottext::faces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const string& text
			, const ubigint refSruAll
			, const ListPlnrMVertex& vtxs
			, const ListPlnrMLineguide& lgs
			, ListPlnrMFace& fces
		) {
	ostringstream str;

	ListPlnrMArcguide ags;

	vector<ubigint> strrefs;
	vector<string> fsrefs;
	vector<string> vsrefsstrs;
	vector<string> rtesstrs;
	vector<string> gsrefsstrs;
	vector<string> dirsstrs;

	unsigned int k, m, n, cdcnt;

	unsigned int N = text.length();

	for (unsigned int i=1;i<=N;i++) {
		cdcnt = 0;

		for (unsigned int j=0;j<(7*5);j++) {
			// check if dot is to be displayed
			if (Dotmatrix::getDot(text[i-1], j)) {
				k = j + floor(((double) j)/5.0) + 6;
				m = (((double) j)/5.0) + 1;
				n = (j%5);

				strrefs.push_back(refSruAll);

				str.str(""); str << "fc" << i << "_" << cdcnt;
				fsrefs.push_back(str.str());

				str.str("");
				str << "vc" << i << "_" << k << ";";
				str << "vc" << i << "_" << (k+1) << ";";
				str << "vc" << i << "_" << (k+1-6) << ";";
				str << "vc" << i << "_" << (k-6);
				vsrefsstrs.push_back(str.str());

				rtesstrs.push_back("lgd;lgd;lgd;lgd");

				str.str("");
				str << "lh"; if (m != 7) str << "c" << i << "_"; str << m << ";";
				str << "lvc" << i << "_" << (n+1) << ";";
				str << "lh"; if (m != 1) str << "c" << i << "_"; str << (m-1) << ";";
				str << "lvc" << i << "_" << n;
				gsrefsstrs.push_back(str.str());

				dirsstrs.push_back("fwd;bwd;bwd;fwd");

				cdcnt++;
			};
		};
	};

	addFaces(dbsplnr, x1RefPlnrMDesign, strrefs, fsrefs, vsrefsstrs, rtesstrs, gsrefsstrs, dirsstrs, vtxs, lgs, ags, fces);
};
// IP cust --- IEND


