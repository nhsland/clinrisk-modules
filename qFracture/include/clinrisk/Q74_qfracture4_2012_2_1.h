/* 
 * Copyright 2012 ClinRisk Ltd.
 * 
 * This file is part of QFracture-2012 (http://qfracture.org, http://svn.clinrisk.co.uk/qfracture).
 * 
 * QFracture-2012 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QFracture-2012 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QFracture-2012.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/qfracture, faithfully implements QFracture-2012.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/qfracture.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q74_qfracture4_2012_2_1.xml
 * STATA dta time stamp: 1 Mar 2012 11:21
 * Header file create date: Mon  5 Mar 2012 11:14:11 GMT
 */

double fracture4_male(
int age,int alcohol_cat6,int b_antidepressant,int b_anycancer,int b_asthmacopd,int b_carehome,int b_corticosteroids,int b_cvd,int b_dementia,int b_epilepsy2,int b_falls,int b_fracture4,int b_liver,int b_malabsorption,int b_parkinsons,int b_ra_sle,int b_renal,int b_type1,int b_type2,double bmi,int ethrisk,int fh_osteoporosis,int smoke_cat,int surv,int *error,char *errorBuf,int errorBufSize
);
