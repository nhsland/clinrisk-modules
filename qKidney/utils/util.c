/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QKidney-2010 (http://qkidney.org, http://svn.clinrisk.co.uk/opensource/qkidney).
 * 
 * QKidney-2010 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QKidney-2010 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QKidney-2010.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qkidney, faithfully implements QKidney-2010.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients. 
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qkidney.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q54_kidney_xml_51_neph5_1.xml
 * STATA dta time stamp: 25 Mar 2010 07:28
 * C file create date: Wed Nov 10 14:00:12 GMT 2010
 */

#include <string.h>
#include <irisk/util.h>

int is_boolean(int b) {
	int result=0;
	if (b==1 || b==0) {
		result = 1;
	}
	return result;
}

int d_in_range(double x, double min, double max) {
	return !(x<min || x>max);
}

int i_in_range(int x, int min, int max) {
	return !(x<min || x>max);
}

void strlcat(char *dst, char *src, int n) {
        if (strlen(src) + 1 > n - strlen(dst))
                strcpy(dst, "errorBuf has been truncated");
        (void)strncat(dst, src, n - strlen(dst) - 1);
}
