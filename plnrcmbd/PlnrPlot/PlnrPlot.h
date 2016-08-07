/**
  * \file PlnrPlot.h
  * Plnr operation pack global code (declarations)
  * \author Alexander Wirthmueller
  * \date created: 4 Dec 2015
  * \date modified: 4 Dec 2015
  */

#ifndef PLNRPLOT_H
#define PLNRPLOT_H

#include "PlnrPlot_blks.h"

// IP incl --- IBEGIN
#include <png.h>
// IP incl --- IEND

namespace PlnrPlot {
// IP cust --- IBEGIN
	// global constants
	const double pi = 3.141592653589793238462643383279;

	double degToRad(const double deg);
	double radToDeg(const double rad);

	void preparePng(vector<double>& zdat, const bool spczlim, const bool logscale, const bool ctrzero, const double altzmin, const double altzmax, const unsigned int width, const unsigned int height, unsigned char** imgdat);
	string writePng(const string& tmppath, unsigned char* imgdat, const unsigned int width, const unsigned int height);
	void addPngDottext(unsigned char* imgdat, const unsigned int imgw, const unsigned int imgh, const string& text, const string& pos, const unsigned int height, const string& color);
	void setPngPixel(unsigned char* imgdat, const unsigned int width, const unsigned int height, const unsigned int x, const unsigned int y, const unsigned char rval, const unsigned char gval, const unsigned char bval);

	void writeSvgHeader(fstream& outfile, const string& tit = "");
	void writeSvgFooter(fstream& outfile);
// IP cust --- IEND
};

#endif


