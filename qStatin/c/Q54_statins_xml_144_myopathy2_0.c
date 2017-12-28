/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QStatin (http://svn.clinrisk.co.uk/opensource/qstatin).
 * 
 * QStatin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QStatin is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QStatin.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qstatin, faithfully implements QStatin.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qstatin.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q54_statins_xml_144_myopathy2_0.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:28 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_myopathy2_0.h>
#include <irisk/util.h>

static double myopathy2_female_raw(
int age,int b_corticosteroids,int b_hypothyroidism,int b_liver,int b_treatedhyp,int b_type1,int b_type2,int ethrisk,int statin_user,int surv
)
{
	double survivor[6] = {
		0,
		0.999934375286102,
		0.999878466129303,
		0.999820828437805,
		0.999758899211884,
		0.999691903591156
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.3498122627927876500000000,
		0.3445188949159614900000000,
		-44.1704082645860720000000000,
		-44.2076463285290090000000000,
		1.3720875166848694000000000,
		1.4974545068042142000000000,
		0.3674596468617653000000000,
		0.9309185501791547000000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);

	/* Centring the continuous variables */

	age_1 = age_1 - 132.533569335937500;
	age_2 = age_2 - 215.889923095703120;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 0.0361431760343712270000000;
	a += age_2 * -0.0156927340079190470000000;

	/* Sum from boolean values */

	a += b_corticosteroids * 1.1077975820756212000000000;
	a += b_hypothyroidism * 0.6326254060843546900000000;
	a += b_liver * 1.2439116116743703000000000;
	a += b_treatedhyp * 0.4840760933610547800000000;
	a += b_type1 * 1.5642559417928421000000000;
	a += b_type2 * 0.6091775202201523700000000;
	a += statin_user * 1.0889205681870988000000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int myopathy2_female_validation(
int age,int b_corticosteroids,int b_hypothyroidism,int b_liver,int b_treatedhyp,int b_type1,int b_type2,int ethrisk,int statin_user,int surv,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_corticosteroids)) {
		ok=0;
		strlcat(errorBuf,"error: b_corticosteroids must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_hypothyroidism)) {
		ok=0;
		strlcat(errorBuf,"error: b_hypothyroidism must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_liver)) {
		ok=0;
		strlcat(errorBuf,"error: b_liver must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_treatedhyp)) {
		ok=0;
		strlcat(errorBuf,"error: b_treatedhyp must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type1)) {
		ok=0;
		strlcat(errorBuf,"error: b_type1 must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type2)) {
		ok=0;
		strlcat(errorBuf,"error: b_type2 must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
	}
	if (!is_boolean(statin_user)) {
		ok=0;
		strlcat(errorBuf,"error: statin_user must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,5)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,5)\n",errorBufSize);
	}
	return ok;
}

double myopathy2_female(
int age,int b_corticosteroids,int b_hypothyroidism,int b_liver,int b_treatedhyp,int b_type1,int b_type2,int ethrisk,int statin_user,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = myopathy2_female_validation(age,b_corticosteroids,b_hypothyroidism,b_liver,b_treatedhyp,b_type1,b_type2,ethrisk,statin_user,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return myopathy2_female_raw(age,b_corticosteroids,b_hypothyroidism,b_liver,b_treatedhyp,b_type1,b_type2,ethrisk,statin_user,surv);
}
