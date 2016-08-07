/**
  * \file PlnrPlot.cpp
  * Plnr operation pack global code (implementation)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifdef PLNRCMBD
	#include <Plnrcmbd.h>
#else
	#include <Plnropd.h>
#endif

#include "PlnrPlot.h"

// IP cust --- IBEGIN
double PlnrPlot::degToRad(
			const double deg
		) {
	return(pi*deg/180.0);
};

double PlnrPlot::radToDeg(
			const double rad
		) {
	return(180.0*rad/pi);
};

void PlnrPlot::preparePng(
			vector<double>& zdat
			, const bool spczlim
			, const bool logscale
			, const bool ctrzero
			, const double altzmin
			, const double altzmax
			, const unsigned int width
			, const unsigned int height
			, unsigned char** imgdat
		) {
	double zmin, zmax, abszmax;

	unsigned char rval, gval, bval;
	double zval;

	// - determine min / max values
	if (spczlim) {
		zmin = altzmin;
		if (logscale && (zmin <= 0.0)) zmin = 1.0e-36;

		zmax = altzmax;
		if (logscale && (zmax <= 0.0)) zmax = 1.0e-36;

		for (unsigned int i=0;i<zdat.size();i++) {
			if (zdat[i] < zmin) zdat[i] = 1.0e-37; // ninf
			if (zdat[i] > zmax) zdat[i] = 1.0e37; // pinf
		};

	} else {
		if (logscale) {
			// skip 0.0 and negative values
			zmin = 1.0e36;
			zmax = 1.0e-36;

			for (unsigned int i=0;i<zdat.size();i++) {
				if (zdat[i] > 0.0) {
					if (zdat[i] < zmin) zmin = zdat[i];
					if (zdat[i] > zmax) zmax = zdat[i];
				};
			};

			// only zero and negative values present
			if ((zmin == 1.0e36) && (zmax == 1.0e-36)) zmin = zmax;

			for (unsigned int i=0;i<zdat.size();i++) {
				if (zdat[i] < zmin) zdat[i] = 1.0e-37;
			};
		
		} else {
			zmin = zdat[0];
			zmax = zmin;

			for (unsigned int i=0;i<zdat.size();i++) {
				if (zdat[i] < zmin) zmin = zdat[i];
				if (zdat[i] > zmax) zmax = zdat[i];
			};

			if (fabs(zmax) > fabs(zmin)) abszmax = fabs(zmax); else abszmax = fabs(zmin);
		};
	};

cout << "abszmax = " << abszmax << endl;

	// - set up PNG data structure
	*imgdat = new unsigned char[4*width*height];

	// - fill PNG data buffer
	for (unsigned int k=0;k<height;k++) {
		for (unsigned int l=0;l<width;l++) {
			if (zmax == zmin) {
				rval = 127;
				gval = 127;
				bval = 127;

			} else {
				zval = zdat[l*height+k];

				if (zval == 1.0e-37) {
					rval = 0;
					gval = 0;
					bval = 0;

				} else if (zval == 1.0e37) {
					rval = 255;
					gval = 255;
					bval = 255;

				} else {
					if (logscale) {
						zval = log(zval/zmin) / log(zmax/zmin);

					} else {
						if (spczlim || !ctrzero) {
							zval = (zval-zmin) / (zmax-zmin);
						} else {
							zval = 0.5 * (1.0 + zval/abszmax);
						};
					};

					// blue -> cyan -> green -> yellow -> red
					if (zval < 0.25) {
						rval = 0;
						gval = (unsigned char) fabs(round(255.0 * 4.0*(zval)));
						bval = 255;
					} else if ((zval >= 0.25) && (zval < 0.5)) {
						rval = 0;
						gval = 255;
						bval = (unsigned char) fabs(round(255.0 * 4.0*(0.5-zval)));
					} else if ((zval >= 0.5) && (zval < 0.75)) {
						rval = (unsigned char) fabs(round(255.0 * 4.0*(zval-0.5)));
						gval = 255;
						bval = 0;
					} else {
						rval = 255;
						gval = (unsigned char) fabs(round(255.0 * 4.0*(1.0-zval)));
						bval = 0;
					};
				};
			};

			setPngPixel(*imgdat, width, height, l, k, rval, gval, bval);
		};
	};
};

string PlnrPlot::writePng(
			const string& tmppath
			, unsigned char* imgdat
			, const unsigned int width
			, const unsigned int height
		) {
	string s;

	string outfile;
	FILE* fp;

	unsigned char** rowptr;

	png_structp png_ptr;
	png_infop info_ptr;

	// create and open file
	outfile = Tmp::newfile(tmppath, "png");
	s = tmppath + "/" + outfile;

	fp = fopen(s.c_str(), "wb");

	// set row pointers
	rowptr = new unsigned char*[height];
	for (unsigned int k=0;k<height;k++) rowptr[k] = &(imgdat[4*width*(height-k-1)]);

	// allocate structures
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);

	// set error handling
	setjmp(png_jmpbuf(png_ptr));

	// set up output control
	png_init_io(png_ptr, fp);

	// set file information
	png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	// write file information
	png_write_info(png_ptr, info_ptr);

	// pack RGB into 3 bytes
	png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);

	// write image
	png_write_image(png_ptr, rowptr);

	// write rest of file
	png_write_end(png_ptr, info_ptr);

	// clean up
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);

	delete[] imgdat;
	delete[] rowptr;

	// close file
	fclose(fp);

	return outfile;
};

void PlnrPlot::addPngDottext(
			unsigned char* imgdat
			, const unsigned int imgw
			, const unsigned int imgh
			, const string& text
			, const string& pos
			, const unsigned int height
			, const string& color
		) {
	string s = text;
	char c;

	unsigned int x0, y0; // lower left corner

	unsigned int x, y, Npix;

	unsigned char cval;

	if (s.length() == 0) return;

	// pixels per dot
	Npix = ((height < 7) ? 1 : (height/7));

	// x position
	if ((pos.compare("nw") == 0) || (pos.compare("w") == 0) || (pos.compare("sw") == 0)) {
		// left
		x0 = height/2;
	} else if ((pos.compare("ne") == 0) || (pos.compare("e") == 0) || (pos.compare("se") == 0)) {
		// right
		x0 = imgw - height/2 - Npix*(s.length()*6-1);
	} else {
		// center (for n, ctr, s)
		x0 = imgw/2 - Npix*(s.length()*6-1)/2;
	};

	// y position
	if ((pos.compare("nw") == 0) || (pos.compare("n") == 0) || (pos.compare("ne") == 0)) {
		// top
		y0 = imgh - height/2 - Npix*7;
	} else if ((pos.compare("sw") == 0) || (pos.compare("s") == 0) || (pos.compare("se") == 0)) {
		// bottom
		y0 = height/2;
	} else {
		// center (for w, ctr, e)
		y0 = imgh/2 - Npix*7/2;
	};

	// color
	if (color.compare("gray") == 0) {
		cval = 127;
	} else if (color.compare("white") == 0) {
		cval = 255;
	} else {
		cval = 0;
	};

	// place dots
	for (unsigned int i=0;i<s.length();i++) {
		c = s[i];

		for (unsigned int j=0;j<7;j++) {
			y = y0 + (7-j-1)*Npix;

			for (unsigned int k=0;k<5;k++) {
				x = x0 + i*6*Npix + k*Npix;

				if (Dotmatrix::getDot(c, j*5+k)) {
					for (unsigned int l=0;l<Npix;l++) {
						for (unsigned int m=0;m<Npix;m++) {
							setPngPixel(imgdat, imgw, imgh, x+m, y+l, cval, cval, cval);
						};
					};
				};
			};
		};
	};
};

inline void PlnrPlot::setPngPixel(
			unsigned char* imgdat
			, const unsigned int width
			, const unsigned int height
			, const unsigned int x
			, const unsigned int y
			, const unsigned char rval
			, const unsigned char gval
			, const unsigned char bval
		) {
	if ((x < width) && (y < height)) {
		imgdat[4*(y*width+x)+1] = rval;
		imgdat[4*(y*width+x)+2] = gval;
		imgdat[4*(y*width+x)+3] = bval;
	};
};

void PlnrPlot::writeSvgHeader(
			fstream& outfile
			, const string& tit
		) {
	outfile << "<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>" << endl;
	outfile << "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN\" \"http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd\">" << endl;
	outfile << "<html xmlns=\"http://www.w3.org/1999/xhtml\" xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\">" << endl;
	outfile << "\t<head>" << endl;

	outfile << "\t\t<title>";
	if (tit.length() == 0) outfile << "View"; else outfile << tit;
	outfile << "</title>" << endl;

	outfile << "\t\t<script type=\"text/javascript\">" << endl;
	outfile << "\t\t/*<![CDATA[*/" << endl;
	outfile << "\t\t\tlyra = true;" << endl;
	outfile << "\t\t\tlyrb = true;" << endl;
	outfile << "\t\t\tlyrc = true;" << endl;
	outfile << "\t\t\tlyrd = true;" << endl;
	outfile << "\t\t\tlyre = true;" << endl;
	outfile << "\t\t\tlyrf = true;" << endl;
	outfile << "\t\t\tlyrg = true;" << endl;
	outfile << "\t\t\tlyrh = true;" << endl;
	outfile << endl;

	outfile << "\t\t\tfunction kpr(ev) {" << endl;
	outfile << "\t\t\t\tif (ev.keyCode == 97) {" << endl;
	outfile << "\t\t\t\t\tif (lyra == true) document.getElementById(\"lyra\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyra\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyra = !lyra;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 98) {" << endl;
	outfile << "\t\t\t\t\tif (lyrb == true) document.getElementById(\"lyrb\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyrb\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyrb = !lyrb;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 99) {" << endl;
	outfile << "\t\t\t\t\tif (lyrc == true) document.getElementById(\"lyrc\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyrc\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyrc = !lyrc;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 100) {" << endl;
	outfile << "\t\t\t\t\tif (lyrd == true) document.getElementById(\"lyrd\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyrd\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyrd = !lyrd;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 101) {" << endl;
	outfile << "\t\t\t\t\tif (lyre == true) document.getElementById(\"lyre\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyre\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyre = !lyre;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 102) {" << endl;
	outfile << "\t\t\t\t\tif (lyrf == true) document.getElementById(\"lyrf\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyrf\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyrf = !lyrf;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 103) {" << endl;
	outfile << "\t\t\t\t\tif (lyrg == true) document.getElementById(\"lyrg\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyrg\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyrg = !lyrg;" << endl;
	outfile << "\t\t\t\t} else if (ev.keyCode == 104) {" << endl;
	outfile << "\t\t\t\t\tif (lyrh == true) document.getElementById(\"lyrh\").setAttribute(\"style\", \"display:none\");" << endl;
	outfile << "\t\t\t\t\telse document.getElementById(\"lyrh\").removeAttribute(\"style\");" << endl;
	outfile << "\t\t\t\t\tlyrh = !lyrh;" << endl;
	outfile << "\t\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\t\treturn false;" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\tfunction mou() {" << endl;
	outfile << "\t\t\t\ttooltip = document.getElementById(\"tooltip\");" << endl;
	outfile << "\t\t\t\ttooltip.style.display = \"none\";" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\tfunction tt(ev, txt, txt2, txt3) {" << endl;
	outfile << "\t\t\t\tvar tooltip;" << endl;
	outfile << endl;

	outfile << "\t\t\t\tif (window.event) ev = window.event;" << endl;
	outfile << endl;

	outfile << "\t\t\t\tif (txt3) {" << endl;
	outfile << "\t\t\t\t\tdocument.getElementById(\"tooltiptxt\").innerHTML = txt + \"<br/>\" + txt2 + \"<br/>\" + txt3;" << endl;
	outfile << "\t\t\t\t} else if (txt2) {" << endl;
	outfile << "\t\t\t\t\tdocument.getElementById(\"tooltiptxt\").innerHTML = txt + \"<br/>\" + txt2;" << endl;
	outfile << "\t\t\t\t} else {" << endl;
	outfile << "\t\t\t\t\tdocument.getElementById(\"tooltiptxt\").innerHTML = txt;" << endl;
	outfile << "\t\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\t\ttooltip = document.getElementById(\"tooltip\");" << endl;
	outfile << endl;

	outfile << "\t\t\t\ttooltip.style.left = ev.clientX + 10 + \"px\";" << endl;
	outfile << "\t\t\t\ttooltip.style.top = ev.clientY - 10 + \"px\";" << endl;
	outfile << "\t\t\t\ttooltip.style.display = \"block\";" << endl;
	outfile << "\t\t\t};" << endl;
	outfile << endl;

	outfile << "\t\t\tdocument.onkeypress = kpr;" << endl;
	outfile << "\t\t\tdocument.onmouseout = mou;" << endl;
	outfile << "\t\t/*]]>*/" << endl;
	outfile << "\t\t</script>" << endl;
	outfile << "\t\t<link href=\"./view.css\" rel=\"styleSheet\" type=\"text/css\"/>" << endl;
	outfile << "\t</head>" << endl;
	outfile << "\t<body marginwidth=\"0\" marginheight=\"0\">" << endl;
	outfile << "\t\t<div id=\"tooltip\" class=\"tooltip\">" << endl;
	outfile << "\t\t\t<table cellspacing=\"0\" border=\"0\" cellpadding=\"1\">" << endl;
	outfile << "\t\t\t\t<tr>" << endl;
	outfile << "\t\t\t\t\t<td id=\"tooltiptxt\">txt</td>" << endl;
	outfile << "\t\t\t\t</tr>" << endl;
	outfile << "\t\t\t</table>" << endl;
	outfile << "\t\t</div>" << endl;
};

void PlnrPlot::writeSvgFooter(
			fstream& outfile
		) {
	outfile << "\t</body>" << endl;
	outfile << "</html>" << endl;
};
// IP cust --- IEND


