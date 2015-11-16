/*###########################################################################*/
/*HW00_Emre_Bayram_141044019_part2.C										 */
/*-----------------------------												 */
/*Written by Emre Bayram on February 11, 2015								 */
/*Description																 */
/*-----------------------------												 */
/*This program multiplies two 2nd degree polynomial							 */
/*Inputs 																	 */
/*	-getting 1st poly coefficents of 2nd degree polynomial					 */
/*	-getting 2nd poly coefficents of 2nd degree polynomial					 */
/*Outputs																	 */
/*	-displaying result of multiplication polynomial 						 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*							Includes										 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

int 
main(void)
{
	double c2, c1, c0;	 /*1st polynomial coefficents of 2nd degree polynomial*/
	double p2, p1, p0;	 /*2nd polynomial coefficents of 2nd degree polynomial*/
	double r4, r3, r2, r1, r0; /*coefficents of result poly*/ 

	/*get 1st poly*/
	printf("Enter 1st poly of coefficents(from higher to lower order)>");
	scanf("%lf%lf%lf", &c2, &c1, &c0);

	/*get 2nd poly*/
	printf("\nEnter 2nd poly of coefficents(from higher to lower order)>");
	scanf("%lf%lf%lf", &p2, &p1, &p0);
	
	/*calculate polies*/	
	r4=c2*p2;
	r3=(c2*p1)+(c1*p2);
	r2=(c2*p0)+(c1*p1)+(c0*p2);
	r1=(c1*p0)+(c0*p1);
	r0=c0*p0;
	
	/*display results*/
	printf("\nresult of multiplacation>\n%5.3fx^4+%5.3fx^3+%5.3fx^2+%5.3fx^1+%5.3f\n",r4,r3,r2,r1,r0);
	return 0;
}

/*###########################################################################*/
/*					End of HW00_Emre_Bayram_141044019_part2.c 				 */
/*###########################################################################*/
