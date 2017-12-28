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
 * XML source: Q54_statins_xml_144_lft4_0.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:25 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_lft4_0.h>
#include <irisk/util.h>

static double lft4_female_raw(
int age,int b_corticosteroids,int b_cvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.998845934867859,
		0.997668147087097,
		0.996383368968964,
		0.994977593421936,
		0.993566155433655
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		-0.0584310899843162660000000,
		0.3716376768684049300000000,
		0.3459879570147443300000000,
		0.4854560245253029000000000,
		-0.6735702519171833400000000,
		-0.2967003179691417000000000,
		0.3395245492182992200000000,
		-0.0597260279626853280000000
	};
	double Ismoke[5] = {
		0,
		0.0629349020103527470000000,
		0.1156875746195378900000000,
		0.2068683341952261300000000,
		0.3100444188687350200000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,2);
	double age_2 = pow(dage,2)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,3);
	double bmi_2 = pow(dbmi,3)*log(dbmi);

	/* Centring the continuous variables */

	age_1 = age_1 - 25.978204727172852;
	age_2 = age_2 - 42.308856964111328;
	bmi_1 = bmi_1 - 17.874906539916992;
	bmi_2 = bmi_2 - 17.180156707763672;
	town = town - -0.384074360132217;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.1675292532483730900000000;
	a += age_2 * -0.0682843677885724280000000;
	a += bmi_1 * 0.1086586459232109100000000;
	a += bmi_2 * -0.0646171322794301390000000;
	a += town * -0.0133119909807650600000000;

	/* Sum from boolean values */

	a += b_corticosteroids * 0.3859997685633566000000000;
	a += b_cvd * 0.1312970299865925100000000;
	a += b_ra * 0.8856368880971882100000000;
	a += b_treatedhyp * 0.2082559389557860100000000;
	a += b_type1 * 0.7652541078829184800000000;
	a += b_type2 * 0.1180231972888050600000000;
	a += statin_user * 0.4273835229262920000000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int lft4_female_validation(
int age,int b_corticosteroids,int b_cvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town,char *errorBuf,int errorBufSize
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
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_ra)) {
		ok=0;
		strlcat(errorBuf,"error: b_ra must be in range (0,1)\n",errorBufSize);
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
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
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

double lft4_female(
int age,int b_corticosteroids,int b_cvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = lft4_female_validation(age,b_corticosteroids,b_cvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return lft4_female_raw(age,b_corticosteroids,b_cvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,town);
}
