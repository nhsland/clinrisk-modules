/* 
 * Copyright 2014 ClinRisk Ltd.
 * 
 * This file is part of QBleed (http://qbleed.org, http://svn.clinrisk.co.uk/opensource/qbleed).
 * 
 * QBleed is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QBleed is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 * 
 * You should have received a copy of the GNU Affero General Public License
 * along with QBleed.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qbleed, faithfully implements QBleed.
 * We have released this code under the GNU Affero General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Affero General Public License is such that we cannot prevent, for example, someone accidentally 
 * altering the coefficients, getting the inputs wrong, or just poor programming.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qbleed.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q81_anticoagbleed_8_27_1_0.xml
 * STATA dta time stamp: 25 Jan 2014 20:52
 * Header file create date: Tue 29 Jul 2014 14:05:50 BST
 */

double Q81_anticoagbleed_8_27_1_female(
int age,int alcohol_cat6,int b_AF,int b_anticonvulsant,int b_antidepressant,int b_antiplat,int b_anycancer,int b_ccf,int b_corticosteroids,int b_liverpancreas,int b_nsaid,int b_platlet,int b_treatedhyp,int b_varices,int b_vte,double bmi,int ethrisk,int exp_anticoagulant,int prior_anybleed,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
);
