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
 * XML source: Q54_statins_xml_144_lft4_1.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:26 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_lft4_1.h>
#include <irisk/util.h>

static double lft4_male_raw(
int age,int b_corticosteroids,int b_cvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town
)
{
	double survivor[6] = {
		0,
		0.998742878437042,
		0.997547924518585,
		0.996192097663879,
		0.994791090488434,
		0.993461072444916
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.1521010057956081700000000,
		0.1641618167885764700000000,
		0.2691040539941271200000000,
		0.3560212773938895000000000,
		-0.1470439608962050800000000,
		-0.5827757535961372000000000,
		0.2569620516841580300000000,
		0.1599482106068299500000000
	};
	double Ismoke[5] = {
		0,
		0.1335514106245082300000000,
		0.1936319092827821200000000,
		0.1706679924479792600000000,
		0.2898624661565503100000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,-2);
	double age_2 = pow(dage,3);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);
	double bmi_2 = pow(dbmi,-2)*log(dbmi);

	/* Centring the continuous variables */

	age_1 = age_1 - 0.040477879345417;
	age_2 = age_2 - 122.792930603027340;
	bmi_1 = bmi_1 - 0.141610324382782;
	bmi_2 = bmi_2 - 0.138401165604591;
	town = town - -0.253234475851059;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * -1.8851039846094846000000000;
	a += age_2 * 0.0001745854103130146300000;
	a += bmi_1 * 3.0371443050490132000000000;
	a += bmi_2 * -16.1313538705239590000000000;
	a += town * 0.0067165532791666682000000;

	/* Sum from boolean values */

	a += b_corticosteroids * 0.3673703421745322400000000;
	a += b_cvd * 0.1977170574522422500000000;
	a += b_ra * 0.6430106873237063600000000;
	a += b_treatedhyp * 0.3384825600620055600000000;
	a += b_type1 * 0.4198362521671556400000000;
	a += b_type2 * 0.3689932793420259700000000;
	a += statin_user * 0.4281841215110356300000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int lft4_male_validation(
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

double lft4_male(
int age,int b_corticosteroids,int b_cvd,int b_ra,int b_treatedhyp,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = lft4_male_validation(age,b_corticosteroids,b_cvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return lft4_male_raw(age,b_corticosteroids,b_cvd,b_ra,b_treatedhyp,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,town);
}
