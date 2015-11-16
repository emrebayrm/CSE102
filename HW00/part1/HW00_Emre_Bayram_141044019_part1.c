/*###########################################################################*/
/*HW00_Emre_Bayram_141044019.C												 */
/*-----------------------------												 */
/*Written by Emre Bayram on February 10, 2015								 */
/*Description																 */
/*-----------------------------												 */
/*This program takes Integral of a given 1st degree polynomial				 */
/*Inputs 																	 */
/*	-coefficents of 1st degree polynomial 									 */
/*Outputs																	 */
/*	-displaying 2nd degree polynomial 										 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*							Includes										 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

int 
main(void)
{
	double c1, c0;	 /*coefficents of 1st degree polynomial*/
	double p0;		 /*P(0) value of the resultingpoly*/
	double o1, o0;	 /*coefficents of result polynomial*/
	printf ("\nEnter the coefficient of x^1> "); /* first coefficient */
	scanf("%lf", &c1);
	printf("\nEnter the coefficient of x^0> ");   /* second coeffilicents */
	scanf("%lf", &c0);
	/*get the zero input value of the resulting poly*/
	printf("\nEnter P(0) value of the resulting polynomial>");
	scanf("%lf", &p0);
	/*calculate intgetral of 1st degree polynomial*/
	o1 = c1*0.5;
	o0 = c0;

	/*display the results*/
	printf("\nResult of integral of 1st degree polynomial>\n%5.3fx^2+%5.3fx^1+%5.3f\n",o1,o0,p0);
	return 0;
}

/*###########################################################################*/
/*					End of HW00_Emre_Bayram_141044019_part1.c				 */
/*###########################################################################*/
