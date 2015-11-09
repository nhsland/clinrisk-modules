/* 
 * Copyright 2014 ClinRisk Ltd.
 * 
 * This file is part of QDiabetesAmpBlind (http://qdiabetes.org/amputation-blindness, http://svn.clinrisk.co.uk/opensource/qdiabetes).
 * 
 * QDiabetesAmpBlind is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QDiabetesAmpBlind is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with QDiabetesAmpBlind.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qdiabetes, faithfully implements QDiabetesAmpBlind.
 * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally 
 * altering the coefficients, getting the inputs wrong, or just poor programming.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qdiabetes.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q92_blindness_9_0.xml
 * STATA dta time stamp: 16 Jan 2015 13:01
 * Header file create date: Mon  9 Nov 2015 09:52:33 GMT
 */

double blindness_female(
int age,int b_prolif_maculo,int b_renal,int b_type1,int diabetes_years2,double hba1c,double rati,double sbp,int surv,double town,int *error,char *errorBuf,int errorBufSize
);
