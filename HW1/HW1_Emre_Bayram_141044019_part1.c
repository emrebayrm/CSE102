/*###########################################################################*/
/*HW01_Emre_Bayram_141044019_part1.c										 */
/*-----------------------------												 */
/*Written by Emre Bayram on February 18, 2015								 */
/*Description																 */
/*-----------------------------												 */
/*This program calculates given function F(x) and G(x) transforming to fog(x)*/
/*and gof(x). Also it takes input from a data files and writes an another    */
/*output data file.														     */
/*Inputs 																	 */
/*	-variables of f(x) and g(x) 											 */
/*Outputs																	 */
/*	-displaying f(x) and g(x)												 */
/*	-displaying result of fog(x) and gof(x)									 */
/*Note:																		 */
/*	-You need to create a txt file for input data which is named exactly	 */
/*variables.txt.															 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
/*---------------------------------------------------------------------------*/
/*								#defines									 */
/*---------------------------------------------------------------------------*/
#define Y 8

int main()
{
	double fog,gof,fx,gx;  /*variables to use in calculations*/
	double v1,v2;			   /*variables which is given by a user */

	FILE *inp,
		 *outp;

	/*necessary files to get variables and to write results*/
	inp= fopen("variables.txt","r");	
	outp=fopen("results1.txt","w");

	/*get the variables*/
	fscanf(inp, "%lf%lf",&v1,&v2);

	/*calculations*/
	gx=v1+(1/(v1+(Y/(v1*2))));
	fog=sin(pow((gx+Y)/gx+sqrt(log((pow(3,gx)/(2*gx+1)))),2.5));
	
	fx=sin(pow((v2+Y)/v2+sqrt(log(pow(3,v2)/(2*v2+1))),2.5));
	gof=fx+1/(fx+(Y/(2*fx)));

	/*give information to user in console */
	printf("These are your functions to calculate\n"); 	
	printf("f(x)=sin((((x+y)/x)+log((3^x)/2x+1)^0.5)^2.5)\n");
	printf("g(x)=x+(1/x+(y/2x))\n");
	printf("These are your variables for fog(x) > %f and gof(x) > %f\n", v1,v2);
	
	/*displaying results of fog(x) and gof(x)*/
	printf("\nAnd here is the results of functions:\n");
	printf("fog(x)=%f\n",fog);	
	printf("gof(x)=%f\n",gof);
	printf("g(x)=%f\n",gx);
	printf("f(x)=%f\n",fx);	
	/*writing the results to output file*/
	fprintf(outp,"%f",fog);
	fprintf(outp,"%f",gof);

	/*close files*/
	fclose(inp);
	fclose(outp);

	return 0;
}

/*###########################################################################*/
/*				End of HW1_Emre_Bayram_141044019_part1.c					 */
/*###########################################################################*/
