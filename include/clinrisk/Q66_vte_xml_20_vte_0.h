/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QThrombosis (http://qthrombosis.org, http://svn.clinrisk.co.uk/opensource/qthrombosis).
 * 
 * QThrombosis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QThrombosis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QThrombosis.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qthrombosis, faithfully implements QThrombosis.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qthrombosis.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q66_vte_xml_20_vte_0.xml
 * STATA dta time stamp: 20 Mar 2011 13:10
 * Header file create date: Mon 15 Aug 2011 18:50:57 BST
 */

double vte_female(
int age,int antipsychotics_current,int b_CCF,int b_anycancer,int b_copd,int b_ibd,int b_renal,int b_varicosevein,double bmi,int cop_current,int hrt_current,int smoke_cat,int surv,int tamoxifen_current,int z1_admit,int *error,char *errorBuf,int errorBufSize
);
