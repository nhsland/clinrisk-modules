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
 * This file has been auto-generated.
 * XML source: Z3_value_predictor_sbp_0.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * This file create date: Tue Apr 27 10:45:27 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Z3_value_predictor_sbp_0.h>
#include <irisk/util.h>

static double sbp_female_raw(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok
)
{
	double survivor[0] = {
		
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		-3.1372986821513531000000000,
		-2.8096588173045363000000000,
		-5.2977085859660846000000000,
		-3.2837794310616761000000000,
		0.5890406593603405600000000,
		0.3741647368200529100000000,
		-5.3948087300620449000000000,
		-1.3608152376825660000000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,-2);
	double age_2 = pow(dage,-1);

	/* Centring the continuous variables */

	age_1 = age_1 - 0.039973739534616;
	age_2 = age_2 - 0.199934333562851;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 402.5034788703453600000000000;
	a += age_2 * -291.5453298040637800000000000;

	/* Sum from boolean values */

	a += b_cvd * -3.2990976705649593000000000;
	a += b_treatedhyp * 6.2902315019787061000000000;
	a += b_type2 * -0.1756970743427888100000000;
	a += smok * 0.6380099362933755500000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = a + 126.5490586921422400000000000;
	return score;
}

static int sbp_female_validation(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_treatedhyp)) {
		ok=0;
		strlcat(errorBuf,"error: b_treatedhyp must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type2)) {
		ok=0;
		strlcat(errorBuf,"error: b_type2 must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
	}
	if (!is_boolean(smok)) {
		ok=0;
		strlcat(errorBuf,"error: smok must be in range (0,1)\n",errorBufSize);
	}
	return ok;
}

double sbp_female(
int age,int b_cvd,int b_treatedhyp,int b_type2,int ethrisk,int smok,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = sbp_female_validation(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return sbp_female_raw(age,b_cvd,b_treatedhyp,b_type2,ethrisk,smok);
}
