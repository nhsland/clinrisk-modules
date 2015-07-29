/*
 * Copyright 2013 ClinRisk Ltd.
 *
 * This file is part of QCancer-2013 (http://qcancer.org, http://svn.clinrisk.co.uk/opensource/qcancer).
 *
 * QCancer-2013 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCancer-2013 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with QCancer-2013.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Additional terms
 *
 * The following disclaimer must be displayed alongside any risk score generated by this code.
 *   The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qcancer, faithfully implements QCancer-2013.
 *   We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.
 *   However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally 
 *   altering the coefficients, getting the inputs wrong, or just poor programming.
 *   We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qcancer.
 *   Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q76_cancer2_15_1.xml
 * STATA dta time stamp: 27 Aug 2012 13:27
 * This file was created on: Thu 27 Jun 2013 09:04:34 BST
 */

#include <string.h>
#include "utils.h"

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

#ifndef __APPLE__
void strlcat(char *dst, char *src, int n) {
        if (strlen(src) + 1 > n - strlen(dst))
                strcpy(dst, "errorBuf has been truncated");
        (void)strncat(dst, src, n - strlen(dst) - 1);
}
#endif
