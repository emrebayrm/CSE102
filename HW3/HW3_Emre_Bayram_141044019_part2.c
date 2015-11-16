/*###########################################################################*/
/*HW3_Emre_Bayram_141044019_part2.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on march 7, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*	This program evaluating the random vertical distance of the bouncing ball*/
/*																			 */
/*Input																		 */
/*	-random first height													 */
/*Output																	 */
/*	-result of evaluation table												 */
/*###########################################################################*/
/*																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
/*---------------------------------------------------------------------------­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                               */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­---------------------------------------------------------------------------*/

/*###########################################################################*/
/*int count_the_number(int count)											 */
/*-------------																 */
/*	count -count number														 */
/*																			 */
/*Return																	 */
/*-------------																 */
/*	result- number of counting												 */
/*																			 */
/*Description																 */
/*-------------																 */
/*	This function counting how much time ball bounced						 */
/*###########################################################################*/
int count_the_number(int count);
/*###########################################################################*/
/*double calculate_the_new_height(double bounce,double ratio)				 */
/*-------------																 */
/*	bounce	- bounce height 												 */
/*	ratio	- rate of lossing feet											 */
/*																			 */
/*Return																	 */
/*-------------				 												 */
/*	result	- new boucing height											 */
/*																			 */
/*Description																 */
/*-------------																 */
/*	This function calculates new height of bouncing							 */
/*###########################################################################*/
double calculate_the_new_height(double bounce,double ratio);
/*###########################################################################*/
/*double calculate_the_vertical_distance(double rebound,int)				 */
/*------------																 */
/*	rebound	- rebound height												 */
/*	result	- before height													 */
/*																			 */
/*Return																	 */
/*------------																 */
/*	-total vertical distance												 */
/*																			 */
/*Description																 */
/*------------																 */
/*	This function calculates total vertical distance						 */
/*###########################################################################*/
double calculate_the_vertical_distance(double rebound,int);

int main()
{
	int first_height;		/*first height of ball*/
	double ratio;			/*loss ratio*/
	double result;			/*variable of total vertical distance*/
	double rebound;			/*variable of rebound height*/
	int count=2;			/*starting count*/

	FILE *outp;				
	outp=fopen("Result_table.txt","w");		/*writing output file */
	/*random ratio value*/
	srand((unsigned)time(NULL));
	ratio=(rand()%40+40)/100.00;
	/*random first height value*/
	first_height=rand()%30+10;
	/*printing result of 1st height*/
	fprintf(outp,"1 %5s"," ");
	fprintf(outp,"%d %12s",first_height," ");
	/*calculeting new height*/
	rebound=(first_height*ratio);
	/*printing*/
	fprintf(outp,"%d\n",first_height);
	result=first_height+rebound*2;
	fprintf(outp,"%d %5s%.3f %6s%.3f\n",count," ",rebound," ",result);
	/*while statement does it until ball under 1 feet */
	while(rebound>2){
		rebound=calculate_the_new_height(rebound,ratio);
		result=calculate_the_vertical_distance(rebound,result);
		count=count_the_number(count);
		fprintf(outp,"%d %5s%.3f %6s%.3f\n",count," ",rebound," ",result);
}	
	fprintf(outp,"The bouncing is stopped and task completed...");

	return 0;
}
double calculate_the_new_height(double bounce,double ratio){
	return bounce*ratio;
}
double calculate_the_vertical_distance(double rebound, int result){
	return (rebound*2)+result;
}
int count_the_number(int count){
	return count+=1;
}
