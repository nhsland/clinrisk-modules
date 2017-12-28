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
 * XML source: Q54_statins_xml_144_cataract_1.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:24 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_cataract_1.h>
#include <irisk/util.h>

static double cataract_male_raw(
int age,int b_AF,int b_corticosteroids,int b_cvd,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.999409258365631,
		0.998752713203430,
		0.998029172420502,
		0.997216939926147,
		0.996319770812988
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.9533459990046975200000000,
		0.8754017354360694700000000,
		1.0181501309332672000000000,
		1.0012013126963741000000000,
		0.7418151220331233900000000,
		1.2589853493146372000000000,
		0.7276346484255293800000000,
		0.2543982475330598400000000
	};
	double Ismoke[5] = {
		0,
		0.0818923447349175220000000,
		0.0104713975111031550000000,
		0.0480257714817434110000000,
		0.1428229387994026400000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);
	double bmi_2 = pow(dbmi,-1);

	/* Centring the continuous variables */

	age_1 = age_1 - 120.612480163574220;
	age_2 = age_2 - 192.681762695312500;
	bmi_1 = bmi_1 - 0.141526758670807;
	bmi_2 = bmi_2 - 0.376200407743454;
	town = town - -0.251169085502625;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0687666384631458600000000;
	a += age_2 * -0.0271059895523744350000000;
	a += bmi_1 * 7.4700578442862735000000000;
	a += bmi_2 * -5.4560741569711073000000000;
	a += town * 0.0095142056288391869000000;

	/* Sum from boolean values */

	a += b_AF * 0.2085547368900831900000000;
	a += b_corticosteroids * 0.4571038963759790900000000;
	a += b_cvd * 0.1199049485051929800000000;
	a += b_type1 * 2.2790947705803819000000000;
	a += b_type2 * 0.8920929446617084100000000;
	a += statin_user * 0.2743156996979210800000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int cataract_male_validation(
int age,int b_AF,int b_corticosteroids,int b_cvd,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_AF)) {
		ok=0;
		strlcat(errorBuf,"error: b_AF must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_corticosteroids)) {
		ok=0;
		strlcat(errorBuf,"error: b_corticosteroids must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
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

double cataract_male(
int age,int b_AF,int b_corticosteroids,int b_cvd,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = cataract_male_validation(age,b_AF,b_corticosteroids,b_cvd,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return cataract_male_raw(age,b_AF,b_corticosteroids,b_cvd,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,town);
}
