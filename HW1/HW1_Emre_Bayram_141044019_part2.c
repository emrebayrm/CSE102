/*###########################################################################*/
/*HW01_Emre_Bayram_141044019_part2.c										 */
/*-----------------------------												 */
/*Written by Emre Bayram on February 19, 2015								 */
/*Description																 */
/*-----------------------------												 */
/*This program solves two unknown first deggree equations with two equation. */
/*Also this program gets coefficients of equations which is given by a user  */
/*in input file and writes the results into ouput data file. 				 */
/*In addition, calculates F(x,y).Variables of x and y comes from equations.	 */
/*---------------------------------------------------------------------------*/
/*Inputs 																	 */
/*	-first equation's coefficients											 */
/*	-second equation's coefficients										 	 */
/*	-coefficients of F(x,y) 												 */
/*Outputs																	 */
/*	-solving equations and function											 */
/*	-displaying result of x and y											 */
/*	-displaying result of F(x,y)											 */
/*Notes:																  	 */
/*	-You need to create txt file named exactly like that eqcoefficients.txt  */
/*and funccoefficients.txt.
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

int main()
{
	double x1,y1,r1;		/*variables of first equations*/
	double x2,y2,r2;		/*variables of second equations*/
	double x,y;				/*variables for x and y */
	double fc1,fc2;			/*coefficients of F(x,y)*/
	double res;				/*variable for results of F(x,y)*/
	
	FILE *inp,
		 *inp2,
		 *outp;

	inp= fopen("eqcoefficients.txt","r");/*equations' coefficients input file*/
	inp2=fopen("funccoefficients.txt","r");/*function's coefficients input file*/
	outp=fopen("result2.txt","w");	/*result's file */

	/*get all variables from files*/
	fscanf(inp,"%lf%lf%lf", &x1,&y1,&r1); 
	fscanf(inp,"%lf%lf%lf", &x2,&y2,&r2);
	fscanf(inp2,"%lf%lf", &fc1,&fc2);
	
	/*algorithm for how to solve the equaitons*/
	/*y=(dc-af)/(db-ae)*/
	/*x=(ec-bf)/(ea-bd)*/

	/*operations */
	y=(x2*r1-x1*r2)/(x2*y1-x1*y2);
	x=(y2*r1-y1*r2)/(y2*x1-y1*x2);

	/*give information to user and display results*/
	printf("Your equations are :\n");
	printf("%fx+%fy=%f\n%fx+%fy=%f\n",x1,y1,r1,x2,y2,r2);
	printf("and here is x and y :\n x=%f    y=%f\n",x,y);
	

	/*writing to output file */	
	fprintf(outp,"%f",x);
	fprintf(outp,"%f",y);
		
	/*get results of F(x,y)*/
	res=fc1*x+fc2*y;
	
	/*about F(x,y)*/
	printf("\nYour function is F(x,y)=%fx+%fy\n",fc1,fc2);
	printf("F(x,y)=%f",res);

	/*writing results of F(x,y)*/
	fprintf(outp,"%f",res);

	fclose(inp);
	fclose(inp2);
	fclose(outp);

	return 0;
}

/*###########################################################################*/
/*				End of HW1_Emre_Bayram_141044019_part2.c					 */
/*###########################################################################*/
