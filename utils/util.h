/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of sbpPredictor (http://svn.clinrisk.co.uk/opensource/sbpPredictor).
 * 
 * sbpPredictor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * sbpPredictor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with sbpPredictor.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Additional disclaimer of warranty.
 *
 * Our intention in releasing this code is to enable others to implement the sbpPredictor algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent others altering the value of the coefficients if they should so wish, thus, in effect, actually creating a different algorithm which has not been subject to scrutiny and peer review, and is no longer sbpPredictor.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/sbpPredictor.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 *
 */

int is_boolean(int b) ;
int d_in_range(double x, double min, double max) ;
int i_in_range(int x, int min, int max) ;
void strlcat(char *dst, char *src, int n) ;

