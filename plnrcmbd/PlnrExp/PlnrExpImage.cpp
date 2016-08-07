/**
  * \file PlnrExpImage.cpp
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

#include "PlnrExpImage.h"

DpchRetPlnr* PlnrExpImage::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrExpImage* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMDevice = dpchinv->refPlnrMDevice;

// IP run --- IBEGIN
	ubigint refSruAll = 0;

	vector<ubigint> refsDsn;
	ubigint x1RefPlnrMDesign;

	unsigned int modpar;

	int rows, cols;
	vector<double> ps;

	// load structure refs
	dbsplnr->tblplnrmstructure->loadRefByHktHkuSrf(VecPlnrVMStructureHkTbl::DEV, refPlnrMDevice, "all", refSruAll);

	// load baseline parameters
	ubigint src0 = 0; ubigint src;
	double pix0 = 20.0; double pix;
	double cd0 = 2.0; double cd;
	bool inv0 = false; bool inv;

	loadReffileDevpar(dbsplnr, refPlnrMDevice, 0, "src", src0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "pix", pix0);
	loadDoubleDevpar(dbsplnr, refPlnrMDevice, 0, "cd", cd0);
	loadBoolDevpar(dbsplnr, refPlnrMDevice, 0, "inv", inv0);

	// --- expand baseline
	src = src0;
	pix = pix0;
	cd = cd0;
	inv = inv0;

	dbsplnr->begin();

	// PNG file to matrix of p values, rows and cols
	loadPng(dbsplnr, xchg->acvpath, src, pix, cd, inv, rows, cols, ps);
	if (rows != 0) vtxlgfces(dbsplnr, 0, refPlnrMDevice, rows, cols, ps, pix, cd, refSruAll);

	dbsplnr->commit();

	// --- expand for modified designs

	// load modified design refs
	dbsplnr->loadRefsBySQL("SELECT DISTINCT x1RefPlnrMDesign FROM TblPlnrAMDevicePar WHERE refPlnrMDevice = " + to_string(refPlnrMDevice) + " AND x1RefPlnrMDesign <> 0", false, refsDsn);

	for (unsigned int i=0;i<refsDsn.size();i++) {
		x1RefPlnrMDesign = refsDsn[i];

		// load modified parameters
		src = src0;
		pix = pix0;
		cd = cd0;
		inv = inv0;

		modpar = 0;

		if (loadReffileDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "src", src)) modpar += _SRC;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "pix", pix)) modpar += _PIX;
		if (loadDoubleDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "cd", cd)) modpar += _CD;
		if (loadBoolDevpar(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, "inv", inv)) modpar += _INV;

		// dto modifications, no arcguides; dto (src, pix, cd, inv) affect vertices, lineguides, faces
		dbsplnr->begin();

		if (modpar != 0) {
			addDevModtype(dbsplnr, refPlnrMDevice, x1RefPlnrMDesign, VecPlnrVMDeviceModtype::VTXGDFCE);
		};

		if (modpar != 0) {
			loadPng(dbsplnr, xchg->acvpath, src, pix, cd, inv, rows, cols, ps);
			if (rows != 0) vtxlgfces(dbsplnr, x1RefPlnrMDesign, refPlnrMDevice, rows, cols, ps, pix, cd, refSruAll);
		};

		dbsplnr->commit();
	};
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- IBEGIN
void PlnrExpImage::loadPng(
			DbsPlnr* dbsplnr
			, const string& acvpath
			, const ubigint src
			, const double pix
			, const double cd
			, const bool inv
			, int& rows
			, int& cols
			, vector<double>& ps
		) {
	ostringstream str;
	
	FILE* fp;

	unsigned char* imgdat;
	unsigned char** rowptr;

	png_structp png_ptr;
	png_infop info_ptr;

	int color_type, bit_depth;

	double pmin;
	double x;

	// retrieve file in archive and open
	PlnrMFile* fil;
	dbsplnr->tblplnrmfile->loadRecByRef(src, &fil);
	
	if (fil) {
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);
		str << "/" << fil->Archivename;

		delete fil;

		fp = fopen(str.str().c_str(), "rb");
	};

	// allocate structures
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);

	// set error handling
//	setjmp(png_ptr->jmpbuf);
	setjmp(png_jmpbuf(png_ptr));

	// set up input control
	png_init_io(png_ptr, fp);

	// read file information
	png_read_info(png_ptr, info_ptr);

	rows = png_get_image_height(png_ptr, info_ptr);
	cols = png_get_image_width(png_ptr, info_ptr);

	// normalize to 8bit grayscale
	color_type = png_get_color_type(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);

	if (color_type == PNG_COLOR_TYPE_GRAY) {
		if (bit_depth < 8) {
			png_set_expand_gray_1_2_4_to_8(png_ptr);
		} else if (bit_depth == 16) {
			png_set_strip_16(png_ptr);
		};

	} else if (color_type == PNG_COLOR_TYPE_RGB) {
		png_set_rgb_to_gray_fixed(png_ptr, 1, -1, -1);

	} else {
		// format not supported: palette or alpha
		rows = 0;
		cols = 0;
	};

	png_read_update_info(png_ptr, info_ptr);

	// allocate memory
	imgdat = new unsigned char[rows*cols];
	rowptr = new unsigned char*[rows];

	for (int i=0;i<rows;i++) rowptr[i] = &(imgdat[i*cols]);

	// read data
	png_read_image(png_ptr, rowptr);

	// translate into values 0..1, considering the CD limit
	pmin = (cd/pix) * (cd/pix);

	ps.resize(rows*cols);
	for (int i=0 ; i<(rows*cols) ; i++) {
		x = ((double) (imgdat[i])) / 255.0;

		if (!inv) x = 1.0 - x;

		if (x < pmin) x = 0.0;
		if (x > (1.0-pmin)) x = 1.0;

		ps[i] = x;
	};

	// clean up
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
//	delete png_ptr;
//	delete info_ptr;

	delete[] imgdat;
	delete[] rowptr;

	// close file
	fclose(fp);
};

void PlnrExpImage::vtxlgfces(
			DbsPlnr* dbsplnr
			, const ubigint x1RefPlnrMDesign
			, const ubigint refPlnrMDevice
			, const int rows
			, const int cols
			, const vector<double>& ps
			, const double pix
			, const double cd
			, const ubigint refSruAll
		) {
	// to deal with the large number of pixels, non-standard expansion methods are employed

	ostringstream str;

	PlnrMVertex vtx;

	PlnrMLineguide lg;
	PlnrLRMLineguideMVertex lrv;
	
	PlnrMFace fce;
	PlnrRMFaceMVertex frv;

	ubigint refLh;
	vector<ubigint> refsLhVtxa;
	uint numLhrv;

	ubigint refLhlast;
	vector<ubigint> refsLhlastVtxa;

	vector<ubigint> refsLv;
	vector<uint> numsLvrv;

	ubigint refVtxa, refVtxb, refVtxc, refVtxd;
	ubigint refLgh, refLgv;

	double x, y;
	double p, d;

	// -- initialization

	// vtx: sref, x and y vary
	vtx.x1RefPlnrMDesign = x1RefPlnrMDesign;
	vtx.hkIxPlnrVLat = VecPlnrVLat::INI;
	vtx.hkIxVTbl = VecPlnrVMVertexHkTbl::DEV;
	vtx.hkUref = refPlnrMDevice;

	// lg: sref varies
	lg.x1RefPlnrMDesign = x1RefPlnrMDesign;
	lg.hkIxPlnrVLat = VecPlnrVLat::INI;
	lg.hkIxVTbl = VecPlnrVMLineguideHkTbl::DEV;
	lg.hkUref = refPlnrMDevice;

	// lrv: lgdRefPlnrMLineguide, lgdNum, refPlnrMVertex vary
	lrv.lgdIxPlnrVLat = VecPlnrVLat::INI;

	// fce: sref varies
	fce.x1RefPlnrMDesign = x1RefPlnrMDesign;
	fce.devRefPlnrMFace = 0;
	fce.sruIxPlnrVLat = VecPlnrVLat::INI;
	fce.sruRefPlnrMStructure = refSruAll;

	// frv: fceRefPlnrMFace, fceNum, refPlnrMVertex, rteUref, ixVDir vary
	frv.rteIxVTbl = VecPlnrVRMFaceMVertexRteTbl::LGD;

	// - top horizontal lineguide plus vertices
	lg.sref = "lh0";
	dbsplnr->tblplnrmlineguide->insertRec(&lg);

	refLh = lg.ref;
	lrv.lgdRefPlnrMLineguide = refLh;

	y = 0.5*((double) rows) * pix;
	for (int j=0;j<=cols;j++) {
		x = ( -0.5*((double) cols) + ((double) j) ) * pix;

		str.str(""); str << "vr0_c" << j << "_a";
		vtx.sref = str.str();
		vtx.x = x;
		vtx.y = y;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);

		lrv.lgdNum = j+1;
		lrv.refPlnrMVertex = vtx.ref;
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		refsLhVtxa.push_back(vtx.ref);
	};

	// - all vertical lineguides plus topmost vertex
	for (int j=0;j<=cols;j++) {
		str.str(""); str << "lv" << j;
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refsLv.push_back(lg.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = refsLhVtxa[j];
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		numsLvrv.push_back(1);
	};

	for (int i=0;i<rows;i++) {
		y = ( -0.5*((double) rows) + ((double) (rows-i)) - 0.5) * pix; // row center

		// -- row initialization
		refLhlast = refLh;
		refsLhlastVtxa = refsLhVtxa;

		refsLhVtxa.resize(0);

		// - horizontal lineguide plus leftmost vertex
		str.str(""); str << "lh" << (i+1);
		lg.sref = str.str();
		dbsplnr->tblplnrmlineguide->insertRec(&lg);
		refLh = lg.ref;

		str.str(""); str << "vr" << (i+1) << "_c0_a";
		vtx.sref = str.str();
		vtx.x = -0.5*((double) cols) * pix;
		vtx.y = y - 0.5*pix;
		dbsplnr->tblplnrmvertex->insertRec(&vtx);

		refsLhVtxa.push_back(vtx.ref);

		lrv.lgdRefPlnrMLineguide = lg.ref;
		lrv.lgdNum = 1;
		lrv.refPlnrMVertex = vtx.ref;
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		numLhrv = 1;

		// - add leftmost vertex to leftmost vertical lineguide
		lrv.lgdRefPlnrMLineguide = refsLv[0];
		// pre-cautionary increment of numsLvrv[0], in case a 'd' vertex will get inserted for the first pixel of the row
		numsLvrv[0]++;
		lrv.lgdNum = ++numsLvrv[0];
		lrv.refPlnrMVertex = vtx.ref;
		dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

		// -- pixel loop
		for (int j=0;j<cols;j++) {
			x = ( -0.5*((double) cols) + ((double) j) + 0.5) * pix; // column center

			p = ps[i*cols + j];

			if ((p != 0.0) && (p != 1.0)) {
				if (p <= 0.5) {
					d = (0.5 - sqrt(p)) * pix;
				} else {
					d = (0.5 - sqrt(1.0-p)) * pix;
				};

				// - 'b', 'c', 'd' vertices
				str.str(""); str << "vr" << (i+1) << "_c" << (j+1) << "_b";
				vtx.sref = str.str();
				vtx.x = x-d;
				vtx.y = y - 0.5*pix;
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refVtxb = vtx.ref;

				lrv.lgdRefPlnrMLineguide = refLh;
				lrv.lgdNum = ++numLhrv;
				lrv.refPlnrMVertex = vtx.ref;
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

				str.str(""); str << "vr" << (i+1) << "_c" << (j+1) << "_c";
				vtx.sref = str.str();
				vtx.x = x-d;
				vtx.y = y-d;
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refVtxc = vtx.ref;

				str.str(""); str << "vr" << (i+1) << "_c" << (j+1) << "_d";
				vtx.sref = str.str();
				vtx.x = x - 0.5*pix;
				vtx.y = y - d;
				dbsplnr->tblplnrmvertex->insertRec(&vtx);
				refVtxd = vtx.ref;
				
				lrv.lgdRefPlnrMLineguide = refsLv[j];
				// insert vertex at space previously left empty
				lrv.lgdNum = numsLvrv[j]-1;
				lrv.refPlnrMVertex = vtx.ref;
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

				numsLvrv[j]++;

				// - 'h', 'v' lineguides
				str.str(""); str << "lhr" << (i+1) << "_c" << (j+1);
				lg.sref = str.str();
				dbsplnr->tblplnrmlineguide->insertRec(&lg);
				refLgh = lg.ref;

				lrv.lgdRefPlnrMLineguide = refLgh;
				lrv.lgdNum = 1;
				lrv.refPlnrMVertex = refVtxd;
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
				lrv.lgdNum = 2;
				lrv.refPlnrMVertex = refVtxc;
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

				str.str(""); str << "lvr" << (i+1) << "_c" << (j+1);
				lg.sref = str.str();
				dbsplnr->tblplnrmlineguide->insertRec(&lg);
				refLgv = lg.ref;

				lrv.lgdRefPlnrMLineguide = refLgv;
				lrv.lgdNum = 1;
				lrv.refPlnrMVertex = refVtxc;
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
				lrv.lgdNum = 2;
				lrv.refPlnrMVertex = refVtxb;
				dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);
			};

			// - 'a' vertex
			str.str(""); str << "vr" << (i+1) << "_c" << (j+1) << "_a";
			vtx.sref = str.str();
			vtx.x = x + 0.5*pix;
			vtx.y = y - 0.5*pix;
			dbsplnr->tblplnrmvertex->insertRec(&vtx);
			refVtxa = vtx.ref;

			refsLhVtxa.push_back(vtx.ref);

			lrv.lgdRefPlnrMLineguide = refLh;
			lrv.lgdNum = ++numLhrv;
			lrv.refPlnrMVertex = vtx.ref;
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			lrv.lgdRefPlnrMLineguide = refsLv[j+1];
			// pre-cautionary increment of numsLvrv[j+1], in case a 'd' vertex will get inserted for the next pixel
			numsLvrv[j+1]++;
			lrv.lgdNum = ++numsLvrv[j+1];
			lrv.refPlnrMVertex = vtx.ref;
			dbsplnr->tblplnrlrmlineguidemvertex->insertRec(&lrv);

			if (p != 0.0) {
				str.str(""); str << "fr" << (i+1) << "_c" << (j+1);
				fce.sref = str.str();
				dbsplnr->tblplnrmface->insertRec(&fce);

				frv.fceRefPlnrMFace = fce.ref;

				if (p == 1.0) {
					// - full pixel a(i+1,j) - a(i+1,j+1) - a(i,j+1) - a(i,j)
					frv.fceNum = 1;
					frv.refPlnrMVertex = refsLhVtxa[j];
					frv.rteUref = refLh;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxa;
					frv.rteUref = refsLv[j+1];
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refsLhlastVtxa[j+1];
					frv.rteUref = refLhlast;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refsLhlastVtxa[j];
					frv.rteUref = refsLv[j];
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				} else if (p <= 0.5) {
					// - square a(i+1,j) - b(i+1,j+1) - c(i+1,j+1) - d(i+1,j+1)
					frv.fceNum = 1;
					frv.refPlnrMVertex = refsLhVtxa[j];
					frv.rteUref = refLh;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxb;
					frv.rteUref = refLgv;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxc;
					frv.rteUref = refLgh;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxd;
					frv.rteUref = refsLv[j];
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

				} else {
					// - pixel minus square b(i+1,j+1) - a(i+1,j+1) - a(i,j+1) - a(i,j) - d(i+1,j+1) - c(i+1,j+1)
					frv.fceNum = 1;
					frv.refPlnrMVertex = refVtxb;
					frv.rteUref = refLh;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxa;
					frv.rteUref = refsLv[j+1];
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refsLhlastVtxa[j+1];
					frv.rteUref = refLhlast;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::BWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refsLhlastVtxa[j];
					frv.rteUref = refsLv[j];
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxd;
					frv.rteUref = refLgh;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);

					frv.fceNum++;
					frv.refPlnrMVertex = refVtxc;
					frv.rteUref = refLgv;
					frv.ixVDir = VecPlnrVRMFaceMVertexDir::FWD;
					dbsplnr->tblplnrrmfacemvertex->insertRec(&frv);
				};
			};
		};
	};
	
	// -- rename center vertex
	dbsplnr->executeQuery("UPDATE TblPlnrMVertex SET sref = 'vctr' WHERE x1RefPlnrMDesign = " + to_string(x1RefPlnrMDesign) + " AND hkIxVTbl = "
				+ to_string(VecPlnrVMVertexHkTbl::DEV) + " AND hkUref = " + to_string(refPlnrMDevice) + " AND sref = 'vr" + to_string(rows/2) + "_c" + to_string(cols/2) + "_a'");
};
// IP cust --- IEND


