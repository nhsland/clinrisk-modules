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
 * XML source: Q54_statins_xml_144_acute_renal_failure_0.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:19 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_acute_renal_failure_0.h>
#include <irisk/util.h>

static double acute_renal_failure_female_raw(
int age,int b_CCF,int b_corticosteroids,int b_neph3,int b_treatedhyp,int b_type1,int b_type2,double bmi,int smoke_cat,int statin_user,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.999967396259308,
		0.999926507472992,
		0.999879777431488,
		0.999834716320038,
		0.999762177467346
	};

	/* The conditional arrays */

	double Ismoke[5] = {
		0,
		0.2091125693262116100000000,
		0.2217756311105605300000000,
		0.3063583410633867700000000,
		0.6030701018857408400000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,-1);
	double age_2 = pow(dage,-.5);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);
	double bmi_2 = pow(dbmi,-2)*log(dbmi);

	/* Centring the continuous variables */

	age_1 = age_1 - 0.196151807904243;
	age_2 = age_2 - 0.442890286445618;
	bmi_1 = bmi_1 - 0.146200999617577;
	bmi_2 = bmi_2 - 0.140555664896965;
	town = town - -0.384868115186691;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 68.9009662894031860000000000;
	a += age_2 * -77.7035621279748630000000000;
	a += bmi_1 * 10.5006955187890460000000000;
	a += bmi_2 * -32.9259694941307120000000000;
	a += town * 0.0474856945272687100000000;

	/* Sum from boolean values */

	a += b_CCF * 0.8336495591192254500000000;
	a += b_corticosteroids * 0.4698349920204774000000000;
	a += b_neph3 * 1.0328011055274569000000000;
	a += b_treatedhyp * 0.3245887691819732700000000;
	a += b_type1 * 1.4409167913337613000000000;
	a += b_type2 * 0.6858303171241980600000000;
	a += statin_user * 0.4437917958179137800000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int acute_renal_failure_female_validation(
int age,int b_CCF,int b_corticosteroids,int b_neph3,int b_treatedhyp,int b_type1,int b_type2,double bmi,int smoke_cat,int statin_user,int surv,double town,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_CCF)) {
		ok=0;
		strlcat(errorBuf,"error: b_CCF must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_corticosteroids)) {
		ok=0;
		strlcat(errorBuf,"error: b_corticosteroids must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_neph3)) {
		ok=0;
		strlcat(errorBuf,"error: b_neph3 must be in range (0,1)\n",errorBufSize);
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
	if (!d_in_range(bmi,20,40)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (20,40)\n",errorBufSize);
	}
	if (!i_in_range(smoke_cat,0,4)) {
		ok=0;
		strlcat(errorBuf,"error: smoke_cat must be in range (0,4)\n",errorBufSize);
	}
	if (!is_boolean(statin_user)) {
		ok=0;
		strlcat(errorBuf,"error: statin_user must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,5)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,5)\n",errorBufSize);
	}
	if (!d_in_range(town,-7,11)) {
		ok=0;
		strlcat(errorBuf,"error: town must be in range (-7,11)\n",errorBufSize);
	}
	return ok;
}

double acute_renal_failure_female(
int age,int b_CCF,int b_corticosteroids,int b_neph3,int b_treatedhyp,int b_type1,int b_type2,double bmi,int smoke_cat,int statin_user,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = acute_renal_failure_female_validation(age,b_CCF,b_corticosteroids,b_neph3,b_treatedhyp,b_type1,b_type2,bmi,smoke_cat,statin_user,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return acute_renal_failure_female_raw(age,b_CCF,b_corticosteroids,b_neph3,b_treatedhyp,b_type1,b_type2,bmi,smoke_cat,statin_user,surv,town);
}
