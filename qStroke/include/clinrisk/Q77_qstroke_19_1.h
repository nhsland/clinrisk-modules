/* 
 * Copyright 2012 ClinRisk Ltd.
 * 
 * This file is part of QStroke (http://qstroke.org, http://svn.clinrisk.co.uk/opensource/qstroke).
 * 
 * QStroke is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QStroke is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QStroke.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qstroke, faithfully implements QStroke.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qstroke.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q77_qstroke_19_1.xml
 * STATA dta time stamp: 9 Mar 2013 15:23
 * Header file create date: Sat  9 Mar 2013 16:20:30 GMT
 */

double stroke_male(
int age,int b_AF,int b_CCF,int b_chd,int b_ra,int b_renal,int b_treatedhyp,int b_type1,int b_type2,int b_valvular,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
);
