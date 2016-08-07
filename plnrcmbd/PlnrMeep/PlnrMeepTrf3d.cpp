/**
  * \file PlnrMeepTrf3d.cpp
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

#include "PlnrMeepTrf3d.h"

DpchRetPlnr* PlnrMeepTrf3d::run(
			XchgPlnr* xchg
			, DbsPlnr* dbsplnr
			, DpchInvPlnrMeepTrf3d* dpchinv
		) {
	DpchRetPlnr* dpchret = new DpchRetPlnr();

	ubigint refPlnrMCalc = dpchinv->refPlnrMCalc;
	ubigint refPlnrMCalcitem = dpchinv->refPlnrMCalcitem;

// IP run --- IBEGIN
	ostringstream sqlstr;
	ostringstream str, str2;
	str.setf(ios::scientific);

	map<string, string> env;

	PlnrMCalc* cal = NULL;
	PlnrMDesign* basedsn = NULL;

	PlnrMCalcitem* cli = NULL;
	PlnrMDesign* moddsn = NULL;

	ListPlnrRMCalcMFile crfs;
	PlnrRMCalcMFile* crf = NULL;

	bool modlam;
	double lam;
	bool modgeo;
	double geo;

	double tstop;
	double grid;
	bool tm;
	bool track;
	bool sshot;

	string tmpfile;

	ubigint refRastfile;

	unsigned int ixDom, ixExc, ixMon1, ixMon2, ixMon3, ixMon4;

	ubigint refMpafile;

	double meepTstop;

	double x, y, z;
	complex<double> c;

	unsigned int dimX, dimY, dimZ;
	double x0, dx, y0, dy, z0, dz;
	double x1, y1, z1;

	int cdfRoot, cdfDoms;
	int cdfDom, cdfMon3, cdfMon4;
	int cdfDimX, cdfDimY, cdfDimXY, cdfDimZ, cdfDimT;
	int cdfVar, cdfVar2, cdfT;

	int* dims = NULL;

	vector<double> varvec;

	double* var = NULL;
	double* var2 = NULL;

	string s, s2;

	ubigint refResfile;

	double Pmon1, Pmon2;
	double _Sx, _Sy, _Sz;

	ListPlnrAMCalcPar cpas;
	PlnrAMCalcPar* cpa = NULL;

	// initialize MEEP
	int argc = 0;
	char** argv = NULL;
	initialize mpi(argc, argv);

	// load calculation and calculation item
	dbsplnr->tblplnrmcalc->loadRecByRef(refPlnrMCalc, &cal);
	dbsplnr->tblplnrmdesign->loadRecByRef(cal->refPlnrMDesign, &basedsn);

	dbsplnr->tblplnrmcalcitem->loadRecByRef(refPlnrMCalcitem, &cli);
	dbsplnr->tblplnrmdesign->loadRecByRef(cli->refPlnrMDesign, &moddsn);

	// load universal parameters
	Plnr::loadDoubleCpa(dbsplnr, refPlnrMCalc, 0, "phys", "tstop", tstop);
	Plnr::loadDoubleCpa(dbsplnr, refPlnrMCalc, 0, "discr", "grid", grid);
	Plnr::loadBoolCpa(dbsplnr, refPlnrMCalc, 0, "opt", "tm", tm);
	Plnr::loadBoolCpa(dbsplnr, refPlnrMCalc, 0, "opt", "track", track);
	Plnr::loadBoolCpa(dbsplnr, refPlnrMCalc, 0, "opt", "sshot", sshot);

	// find type of variation
	modlam = !Plnr::loadDoubleCpa(dbsplnr, refPlnrMCalc, 0, "phys", "lam", lam);
	modgeo = !Plnr::loadDoubleCpa(dbsplnr, refPlnrMCalc, 0, "geo", "geo", geo);

	// retrieve rasterizer file
	if (modgeo) {
		sqlstr.str(""); sqlstr << "SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " << VecPlnrVMFileRefTbl::CAL << " AND refUref = " << refPlnrMCalc << " AND Filename = 'rast.cdf'";
		dbsplnr->loadUbigintBySQL(sqlstr.str(), refRastfile);
	} else {
		sqlstr.str(""); sqlstr << "SELECT ref FROM TblPlnrMFile WHERE refIxVTbl = " << VecPlnrVMFileRefTbl::CAL << " AND refUref = " << refPlnrMCalc << " AND Filename = '" << cli->Title << "_rast.cdf'";
		dbsplnr->loadUbigintBySQL(sqlstr.str(), refRastfile);
	};

	// -- load wavelength if lam is varied
	if (modlam) Plnr::loadDoubleCpa(dbsplnr, refPlnrMCalc, refPlnrMCalcitem, "phys", "lam", lam);

	CubrastMeep rast(dbsplnr, xchg->acvpath, env, basedsn->ref, moddsn->ref, refRastfile, "dom", lam, true);

	rast.getDomIx("dom", ixDom);
	rast.getDomIx("exc", ixExc);
	rast.getDomIx("mon1", ixMon1);
	rast.getDomIx("mon2", ixMon2);
	rast.getDomIx("mon3", ixMon3);
	rast.getDomIx("mon4", ixMon4);

	// -- output refractive index
	tmpfile = rast.matparCdf(xchg->tmppath, "dom;exc;mon1;mon2;mon3;mon4", "phot", "n");

	// store in archive
	str.str(""); str << xchg->tmppath << "/" << tmpfile;
	str2.str(""); str2 << cli->Title << "_n.cdf";
	refMpafile = Acv::addfile(dbsplnr, xchg->acvpath, str.str(), VecPlnrVMFileRefTbl::CAL, refPlnrMCalc, "dgrid", str2.str(), "nc", "");

	// hook to calculation item
	crf = new PlnrRMCalcMFile(0, refPlnrMCalcitem, refPlnrMCalc, refMpafile, VecPlnrVRMCalcMFileIo::OUT);
	dbsplnr->tblplnrrmcalcmfile->insertRec(crf); crfs.nodes.push_back(crf);

	// -- run FDTD simulation
	x0 = rast.domX0[ixDom]; x1 = rast.domX1[ixDom];
	y0 = rast.domY0[ixDom]; y1 = rast.domY1[ixDom];
	z0 = rast.domZ0[ixDom]; z1 = rast.domZ1[ixDom];

	grid_volume meepVol = vol3d(x1-x0, y1-y0, z1-z0, 1.0/grid);

	structure meepSru(meepVol, rast, pml(0.5));
	fields meepF(&meepSru);

	continuous_src_time meepSrc(complex<double>(1.0/lam, 0), 0.2, 0.0);
	meepTstop = 1.0e-9 * tstop*c0/lam;

	// - as for source, distinguish area from point source
	if (rast.domIxVBasetype[ixExc] == VecPlnrVMDomainBasetype::ZCSBOX_XYZ) {
		// area (sheet) source spans from lower left corner to upper right corner
		x = rast.domA11[ixExc]*rast.domXy0[ixExc] + rast.domB1[ixExc];
		y = rast.domA21[ixExc]*rast.domXy0[ixExc] + rast.domB2[ixExc];
		z = rast.domZ0[ixExc] + rast.domB3[ixExc];
		rast.dsnToMeep(x, y, z, x0, y0, z0);

		x = rast.domA11[ixExc]*rast.domXy1[ixExc] + rast.domB1[ixExc];
		y = rast.domA21[ixExc]*rast.domXy1[ixExc] + rast.domB2[ixExc];
		z = rast.domZ1[ixExc] + rast.domB3[ixExc];
		rast.dsnToMeep(x, y, z, x1, y1, z1);

		if (tm) {
//			meepF.add_volume_source(Ey, meepSrc, volume(vec(x0, y0, z0), vec(x1, y1, z1)));
		} else {
//			meepF.add_volume_source(Ex, meepSrc, volume(vec(x0, y0, z0), vec(x1, y1, z1)));
		};

	} else if (rast.domIxVBasetype[ixExc] == VecPlnrVMDomainBasetype::POINT_XYZ) {
		rast.dsnToMeep(rast.domB1[ixExc], rast.domB2[ixExc], rast.domB3[ixExc], x, y, z);
		if (tm) {
//			meepF.add_point_source(Ey, meepSrc, vec(x, y, z));
		} else {
//			meepF.add_point_source(Ex, meepSrc, vec(x, y, z));
		};
	};

	// - initialize tracking
	if (track) {
		varvec.resize(0);

		// mon3 (x0,y0,z0), mon4 (x1,y1,z1)
		rast.dsnToMeep(rast.domB1[ixMon3], rast.domB2[ixMon3], rast.domB3[ixMon3], x0, y0, z0);
		rast.dsnToMeep(rast.domB1[ixMon4], rast.domB2[ixMon4], rast.domB3[ixMon4], x1, y1, z1);

		// initial fields (should be 0), varvec gets 25 entries per time step
		for (unsigned int j=0;j<25;j++) varvec.push_back(0.0);
	};

	// - iterate FDTD algorithm
	while (meepF.time() < meepTstop) {
		meepF.step();

		if (track) {
			varvec.push_back(meepF.time() * 1.0e9*lam/c0);
			c = meepF.get_field(Ex, vec(x0, y0, z0)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Ey, vec(x0, y0, z0)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Ez, vec(x0, y0, z0)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Hx, vec(x0, y0, z0)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Hy, vec(x0, y0, z0)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Hz, vec(x0, y0, z0)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Ex, vec(x1, y1, z1)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Ey, vec(x1, y1, z1)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Ez, vec(x1, y1, z1)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Hx, vec(x1, y1, z1)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Hy, vec(x1, y1, z1)); varvec.push_back(real(c)); varvec.push_back(imag(c));
			c = meepF.get_field(Hz, vec(x1, y1, z1)); varvec.push_back(real(c)); varvec.push_back(imag(c));
		};
	};

	// - initialize result file
	if (track || sshot) {
		// create and open cdf file
		tmpfile = Tmp::newfile(xchg->tmppath, "cdf");
		str.str(""); str << xchg->tmppath << "/" << tmpfile;

		nc_create(str.str().c_str(), NC_NETCDF4, &cdfRoot);
		nc_def_grp(cdfRoot, "doms", &cdfDoms);

		// set up cdf file
		nc_enddef(cdfRoot);
	};

	// - write tracking information to result file
	if (track) {
		var = new double[varvec.size()/25];

		nc_redef(cdfRoot);

		// time dimension
		nc_def_dim(cdfRoot, "dimT", varvec.size()/25, &cdfDimT);

		dims = new int[1]; dims[0] = cdfDimT;

		// time vector
		nc_def_var(cdfRoot, "t", NC_DOUBLE, 1, dims, &cdfT);

		s = "femtosecond";
		nc_put_att_text(cdfRoot, cdfT, "units", s.length(), s.c_str());
		s = "t [fs]";
		nc_put_att_text(cdfRoot, cdfT, "long_name", s.length(), s.c_str());
		s = "time";
		nc_put_att_text(cdfRoot, cdfT, "title", s.length(), s.c_str());

		nc_enddef(cdfRoot);

		for (unsigned int j=0;j<varvec.size()/25;j++) var[j] = varvec[j*25+0];
		nc_put_var_double(cdfRoot, cdfT, var);

		// generate domain entries for mon3 and mon4
		cdfMon3 = rast.domCdf(ixMon3, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimZ);
		cdfMon4 = rast.domCdf(ixMon4, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimZ);

		// individual field components
		for (unsigned int j=0;j<24;j++) {
			nc_redef(cdfRoot);

			// compose variable name
			str.str("");
			if (((j >= 0) && (j < 6)) || ((j >= 12) && (j < 18))) str << "E"; else str << "H";
			if ( ((j%6) == 0) || ((j%6) == 1) ) str << "x";
			else if ( ((j%6) == 2) || ((j%6) == 3) ) str << "y";
			else if ( ((j%6) == 4) || ((j%6) == 5) ) str << "z";
			if ((j%2) == 0) str << "_re"; else str << "_im";

			if (j < 12) {
				nc_def_var(cdfMon3, str.str().c_str(), NC_DOUBLE, 1, dims, &cdfVar);
			} else {
				nc_def_var(cdfMon4, str.str().c_str(), NC_DOUBLE, 1, dims, &cdfVar);
			};

			// compose long name
			str.str("");
			if ((j%2) == 0) str << "Re("; else str << "Im(";
			if (((j >= 0) && (j < 6)) || ((j >= 12) && (j < 18))) str << "E"; else str << "H";
			if ( ((j%6) == 0) || ((j%6) == 1) ) str << "x(t))";
			else if ( ((j%6) == 2) || ((j%6) == 3) ) str << "y(t))";
			else if ( ((j%6) == 4) || ((j%6) == 5) ) str << "z(t))";
			if (((j >= 0) && (j < 6)) || ((j >= 12) && (j < 18))) str << " [V/m]"; else str << " [A/m]";

			if (j < 12) {
				nc_put_att_text(cdfMon3, cdfVar, "long_name", str.str().length(), str.str().c_str());
			} else {
				nc_put_att_text(cdfMon4, cdfVar, "long_name", str.str().length(), str.str().c_str());
			};

			// compose title
			str.str("");
			if (((j >= 0) && (j < 6)) || ((j >= 12) && (j < 18))) str << "electric"; else str << "magnetic";
			str << " field in monitor point ";
			if (j < 12) str << "3, "; else str << "4, ";
			if ( ((j%6) == 0) || ((j%6) == 1) ) str << "x-component ";
			else if ( ((j%6) == 2) || ((j%6) == 3) ) str << "y-component ";
			else if ( ((j%6) == 4) || ((j%6) == 5) ) str << "z-component ";
			if ((j%2) == 0) str << "real part"; else str << "imaginary part";

			if (j < 12) {
				nc_put_att_text(cdfMon3, cdfVar, "title", str.str().length(), str.str().c_str());
			} else {
				nc_put_att_text(cdfMon4, cdfVar, "title", str.str().length(), str.str().c_str());
			};

			nc_enddef(cdfRoot);

			for (unsigned int k=0;k<varvec.size()/25;k++) var[k] = varvec[k*25+j+1];
			if (j < 12) {
				nc_put_var_double(cdfMon3, cdfVar, var);
			} else {
				nc_put_var_double(cdfMon4, cdfVar, var);
			};
		};

		delete[] var;
		delete[] dims;
	};

	// - write final field snapshot to result file
	if (sshot) {
		dimX = rast.domDimX[ixDom];
		dimY = rast.domDimY[ixDom];
		dimZ = rast.domDimZ[ixDom];

		x0 = rast.domX0[ixDom];
		dx = rast.domDx[ixDom];
		y0 = rast.domY0[ixDom];
		dy = rast.domDy[ixDom];
		z0 = rast.domZ0[ixDom];
		dz = rast.domDz[ixDom];

		cdfDom = rast.domCdf(ixDom, cdfDoms, cdfDimX, cdfDimY, cdfDimXY, cdfDimZ);

		var = new double[dimX*dimY*dimZ];
		var2 = new double[dimX*dimY*dimZ];
		dims = new int[3]; dims[0] = cdfDimX; dims[1] = cdfDimY; dims[2] = cdfDimZ;

		for (unsigned int j=0;j<6;j++) {
			// define and assemble variable
			nc_redef(cdfRoot);

			// set variable names
			if (j == 0) {s = "Ex_re"; s2 = "Ex_im";}
			else if (j == 1) {s = "Ey_re"; s2 = "Ey_im";}
			else if (j == 2) {s = "Ez_re"; s2 = "Ez_im";}
			else if (j == 3) {s = "Hx_re"; s2 = "Hx_im";}
			else if (j == 4) {s = "Hy_re"; s2 = "Hy_im";}
			else if (j == 5) {s = "Hz_re"; s2 = "Hz_im";};

			nc_def_var(cdfDom, s.c_str(), NC_DOUBLE, 3, dims, &cdfVar);
			nc_def_var(cdfDom, s2.c_str(), NC_DOUBLE, 3, dims, &cdfVar2);

			// set long name
			if (j == 0) {s = "Re(Ex(x,y,z,tstop)) [V/m]"; s2 = "Im(Ex(x,y,z,tstop)) [V/m]";}
			else if (j == 1) {s = "Re(Ey(x,y,z,tstop)) [V/m]"; s2 = "Im(Ey(x,y,z,tstop)) [V/m]";}
			else if (j == 2) {s = "Re(Ez(x,y,z,tstop)) [V/m]"; s2 = "Im(Ez(x,y,z,tstop)) [V/m]";}
			else if (j == 3) {s = "Re(Hx(x,y,z,tstop)) [A/m]"; s2 = "Im(Hx(x,y,z,tstop)) [A/m]";}
			else if (j == 4) {s = "Re(Hy(x,y,z,tstop)) [A/m]"; s2 = "Im(Hy(x,y,z,tstop)) [A/m]";}
			else if (j == 5) {s = "Re(Hz(x,y,z,tstop)) [A/m]"; s2 = "Im(Hz(x,y,z,tstop)) [A/m]";};

			nc_put_att_text(cdfDom, cdfVar, "long_name", s.length(), s.c_str());
			nc_put_att_text(cdfDom, cdfVar2, "long_name", s2.length(), s2.c_str());

			// set title
			if (j == 0) {s = "final electric field, x-component real part"; s2 = "final electric field, x-component imaginary part";}
			else if (j == 1) {s = "final electric field, y-component real part"; s2 = "final electric field, y-component imaginary part";}
			else if (j == 2) {s = "final electric field, z-component real part"; s2 = "final electric field, z-component imaginary part";}
			else if (j == 3) {s = "final magnetic field, x-component real part"; s2 = "final magnetic field, x-component imaginary part";}
			else if (j == 4) {s = "final magnetic field, y-component real part"; s2 = "final magnetic field, y-component imaginary part";}
			else if (j == 5) {s = "final magnetic field, z-component real part"; s2 = "final magnetic field, z-component imaginary part";};

			nc_put_att_text(cdfDom, cdfVar, "title", s.length(), s.c_str());
			nc_put_att_text(cdfDom, cdfVar2, "title", s2.length(), s2.c_str());

			nc_enddef(cdfRoot);

			for (unsigned int k=0;k<dimX;k++) {
				x = x0+k*dx+rast.xoff;
				for (unsigned int l=0;l<dimY;l++) {
					y = y0+l*dy+rast.yoff;
					for (unsigned int m=0;m<dimZ;m++) {
						z = z0+m*dz+rast.zoff;

						if (j == 0) c = meepF.get_field(Ex, vec(x, y, z));
						else if (j == 1) c = meepF.get_field(Ey, vec(x, y, z));
						else if (j == 2) c = meepF.get_field(Ez, vec(x, y, z));
						else if (j == 3) c = meepF.get_field(Hx, vec(x, y, z));
						else if (j == 4) c = meepF.get_field(Hy, vec(x, y, z));
						else if (j == 5) c = meepF.get_field(Hz, vec(x, y, z));

						var[k*dimY*dimZ+l*dimZ+m] = real(c);
						var2[k*dimY*dimZ+l*dimZ+m] = imag(c);
					};
				};
			};

			// write variables
			nc_put_var_double(cdfDom, cdfVar, var);
			nc_put_var_double(cdfDom, cdfVar2, var2);
		};

		delete[] var;
		delete[] var2;
		delete[] dims;
	};

	// - close result file
	if (track || sshot) {
		nc_close(cdfRoot);

		// store in archive
		str.str(""); str << xchg->tmppath << "/" << tmpfile;
		str2.str(""); str2 << cli->Title << "_res.cdf";
		refResfile = Acv::addfile(dbsplnr, xchg->acvpath, str.str(), VecPlnrVMFileRefTbl::CAL, refPlnrMCalc, "dgrid", str2.str(), "nc", "");

		crf = new PlnrRMCalcMFile(0, refPlnrMCalcitem, refPlnrMCalc, refResfile, VecPlnrVRMCalcMFileIo::OUT);
		dbsplnr->tblplnrrmcalcmfile->insertRec(crf); crfs.nodes.push_back(crf);
	};

	// - calculate final power transmission through mon1
	_Sx = 0.0; _Sy = 0.0; _Sz = 0.0;

	for (unsigned int k=0;k<rast.domDimXY[ixMon1];k++) {
		x0 = rast.domA11[ixMon1]*(rast.domXy0[ixMon1]+k*rast.domDxy[ixMon1])+rast.domB1[ixMon1];
		y0 = rast.domA21[ixMon1]*(rast.domXy0[ixMon1]+k*rast.domDxy[ixMon1])+rast.domB2[ixMon1];

		for (unsigned int l=0;l<rast.domDimZ[ixMon1];l++) {
			z0 = rast.domZ0[ixMon1]+l*rast.domDz[ixMon1]+rast.domB3[ixMon1];

			rast.dsnToMeep(x0, y0, z0, x, y, z);

			c = meepF.get_field(Sx, vec(x, y, z));
			_Sx += real(c);
			c = meepF.get_field(Sy, vec(x, y, z));
			_Sy += real(c);
			c = meepF.get_field(Sz, vec(x, y, z));
			_Sz += real(c);
		};
	};

	Pmon1 = sqrt(_Sx*_Sx + _Sy*_Sy + _Sz*_Sz) * (rast.domXy1[ixMon1]-rast.domXy0[ixMon1]) * (rast.domZ1[ixMon1]-rast.domZ0[ixMon1]);

	str.str(""); str << Pmon1;
	cpa = new PlnrAMCalcPar(0, refPlnrMCalc, refPlnrMCalcitem, "P_mon1", str.str());
	dbsplnr->tblplnramcalcpar->insertRec(cpa); cpas.nodes.push_back(cpa);

	// - calculate final power transmission through mon2
	_Sx = 0.0; _Sy = 0.0; _Sz = 0.0;

	for (unsigned int k=0;k<rast.domDimXY[ixMon2];k++) {
		x0 = rast.domA11[ixMon2]*(rast.domXy0[ixMon2]+k*rast.domDxy[ixMon2])+rast.domB1[ixMon2];
		y0 = rast.domA21[ixMon2]*(rast.domXy0[ixMon2]+k*rast.domDxy[ixMon2])+rast.domB2[ixMon2];

		for (unsigned int l=0;l<rast.domDimZ[ixMon2];l++) {
			z0 = rast.domZ0[ixMon2]+l*rast.domDz[ixMon2]+rast.domB3[ixMon2];

			rast.dsnToMeep(x0, y0, z0, x, y, z);

			c = meepF.get_field(Sx, vec(x, y, z));
			_Sx += real(c);
			c = meepF.get_field(Sy, vec(x, y, z));
			_Sy += real(c);
			c = meepF.get_field(Sz, vec(x, y, z));
			_Sz += real(c);
		};
	};

	Pmon2 = sqrt(_Sx*_Sx + _Sy*_Sy + _Sz*_Sz) * (rast.domXy1[ixMon2]-rast.domXy0[ixMon2]) * (rast.domZ1[ixMon2]-rast.domZ0[ixMon2]);

	str.str(""); str << Pmon2;
	cpa = new PlnrAMCalcPar(0, refPlnrMCalc, refPlnrMCalcitem, "P_mon2", str.str());
	dbsplnr->tblplnramcalcpar->insertRec(cpa); cpas.nodes.push_back(cpa);

	delete moddsn;

	delete cal;
	delete basedsn;
// IP run --- IEND

	dpchret->success = true;
	return dpchret;
};

// IP cust --- INSERT


