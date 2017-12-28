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
 * XML source: Q54_statins_xml_144_cataract_0.xml
 * STATA dta time stamp: 7 Mar 2010 19:20
 * C file create date: Fri May 21 09:41:22 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_statins_xml_144_cataract_0.h>
#include <irisk/util.h>

static double cataract_female_raw(
int age,int b_AF,int b_corticosteroids,int b_cvd,int b_ra,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv
)
{
	double survivor[6] = {
		0,
		0.999194264411926,
		0.998252272605896,
		0.997191071510315,
		0.996093511581421,
		0.994950473308563
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.9066284381746652100000000,
		0.8179893984303785400000000,
		1.4632263586868848000000000,
		0.7545774776938755100000000,
		0.5868362878030393100000000,
		1.1411646959987036000000000,
		0.9939945716291420700000000,
		0.3370013722723851900000000
	};
	double Ismoke[5] = {
		0,
		0.0832181667711823360000000,
		0.0094771462640953832000000,
		0.0190026773947148810000000,
		0.1026882730886622300000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = log(dbmi);
	double bmi_2 = pow(dbmi,.5);

	/* Centring the continuous variables */

	age_1 = age_1 - 128.796798706054690;
	age_2 = age_2 - 208.575073242187500;
	bmi_1 = bmi_1 - 0.960887134075165;
	bmi_2 = bmi_2 - 1.616791367530823;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0822817792123999440000000;
	a += age_2 * -0.0331236060728777450000000;
	a += bmi_1 * -2.8369276077056234000000000;
	a += bmi_2 * 3.4140856999720501000000000;

	/* Sum from boolean values */

	a += b_AF * 0.1518555285239085500000000;
	a += b_corticosteroids * 0.3880223070618511500000000;
	a += b_cvd * 0.1063008655174649400000000;
	a += b_ra * 0.1514161236906365100000000;
	a += b_type1 * 2.3042652637661116000000000;
	a += b_type2 * 0.7455470569710658200000000;
	a += statin_user * 0.2651037196721354700000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int cataract_female_validation(
int age,int b_AF,int b_corticosteroids,int b_cvd,int b_ra,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,char *errorBuf,int errorBufSize
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
	if (!is_boolean(b_ra)) {
		ok=0;
		strlcat(errorBuf,"error: b_ra must be in range (0,1)\n",errorBufSize);
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
	return ok;
}

double cataract_female(
int age,int b_AF,int b_corticosteroids,int b_cvd,int b_ra,int b_type1,int b_type2,double bmi,int ethrisk,int smoke_cat,int statin_user,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = cataract_female_validation(age,b_AF,b_corticosteroids,b_cvd,b_ra,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return cataract_female_raw(age,b_AF,b_corticosteroids,b_cvd,b_ra,b_type1,b_type2,bmi,ethrisk,smoke_cat,statin_user,surv);
}
