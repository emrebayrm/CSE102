/*###########################################################################*/
/*HW2_Emre_Bayram_141044019_part2.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on March 1, 2015									 */
/*																			 */
/*Description																 */
/*-----------------------------												 */
/*This program decides grades, calculates conrubution of notes of five		 */
/*students and writes a file of results										 */
/*																			 */
/*Inputs 																	 */
/*	-exams results each students 											 */
/*																			 */
/*Outputs																	 */
/*	-contribution of students 												 */
/*	-grades 																 */
/*																			 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
/*---------------------------------------------------------------------------­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                               */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­---------------------------------------------------------------------------*/

/*###########################################################################*/
/*																			 */
/*int calculation(int mid1,int mid2,int final)								 */
/*-----------------															 */
/*	mid1	- first mid term result											 */
/*	mid2	- second mid term result										 */
/*	final	- final exam result												 */
/*																			 */
/*Return																	 */
/*-----------------															 */
/*	result of calculation													 */
/*																		 	 */ 
/*Description																 */
/*-----------------															 */
/*	This function calculates average note with weight of exams				 */
/*																			 */
/*###########################################################################*/
int calculation(int,int,int);
/*###########################################################################*/
/*																			 */
/*char decide_grade(int result)												 */
/*------------------														 */
/*	result	- Result of calculation of notes								 */
/*																			 */
/*Return																	 */
/*------------------														 */
/*	char	- deggree of notes according to average notes					 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	This function decides which one of deggree A or B or C or D or F. It does*/
/*this with date of result note with if statements.							 */
/*																			 */
/*###########################################################################*/
char decide_grade(int);
/*###########################################################################*/
/*																			 */
/*double contribution(char x)												 */
/*----------------															 */
/*	x	- grade of student note												 */
/*																			 */
/*Return																	 */
/*----------------															 */
/*	double	- contribution 													 */
/*																			 */
/*Desciption																 */
/*----------------															 */
/*	This function helps us to calculates contribution of student for this 	 */
/*lesson with swicht structure.												 */
/*																			 */
/*###########################################################################*/
double contribution(char x);

int main()
{
	/*variables of first student*/
	char first, second;
	int mid1,mid2,final;
	int result;
	/*variables of second student*/
	char first2, second2;
	int mid12,mid22,final2;
	int result2;
	/*variables of third student*/
	char first3, second3;
	int mid13,mid23,final3;
	int result3;
	/*variables of fourth student*/
	char first4, second4;
	int mid14,mid24,final4;
	int result4;
	/*variables of fifth student*/
	char first5, second5;
	int mid15,mid25,final5;
	int result5;

	FILE *inp,
		 *outp;		 
	inp= fopen("Students.txt","r");		/*input file*/
	outp=fopen("Grades.txt","w");		/*output file*/

	/*All vales for 1. student*/
	fscanf(inp,"%c%c %d %d %d\n",&first,&second,&mid1,&mid2,&final);
	result=calculation(mid1,mid2,final);
	fprintf(outp,"%c%c %d\n",first,second,result);
	printf("%c%c %c %.2f\n",first,second,decide_grade(result),contribution(decide_grade(result)));

	/*All vales for 2. student*/
	fscanf(inp,"%c%c %d %d %d\n",&first2,&second2,&mid12,&mid22,&final2);	
	result2=calculation(mid12,mid22,final2);
	fprintf(outp,"%c%c %d\n",first2,second2,result2);
	printf("%c%c %c %.2f\n",first2,second2,decide_grade(result2),contribution(decide_grade(result2)));

	/*All vales for 3. student*/
	fscanf(inp,"%c%c %d %d %d\n",&first3,&second3,&mid13,&mid23,&final3);
	result3=calculation(mid13,mid23,final3);
	fprintf(outp,"%c%c %d\n",first3,second3,result3);
	printf("%c%c %c %.2f\n",first3,second3,decide_grade(result3),contribution(decide_grade(result3)));
	
	/*All vales for 4. student*/
	fscanf(inp,"%c%c %d %d %d\n",&first4,&second4,&mid14,&mid24,&final4);
	result4=calculation(mid14,mid24,final4);
	fprintf(outp,"%c%c %d \n",first4,second4,result4);
	printf("%c%c %c %.2f\n",first4,second4,decide_grade(result4),contribution(decide_grade(result4)));

	/*All vales for 5. student*/
	fscanf(inp,"%c%c %d %d %d\n",&first5,&second5,&mid15,&mid25,&final5);	
	result5=calculation(mid15,mid25,final5);
	fprintf(outp,"%c%c %d",first5,second5,result5);
	printf("%c%c %c %.2f",first5,second5,decide_grade(result5),contribution(decide_grade(result5)));

	fclose(inp);
	fclose(outp);
	return 0;
}

int calculation(int mid1, int mid2, int final)
{
	int result;
	return result=((mid1*30)+(mid2*30)+(final*40))/100;
}

char decide_grade(int result)
{
	int x;
	if (result>=85){		
		x=5;
		return 'A';
}
	if (result>=70){		
		x=4;	
		return 'B';
}
	if (result>=65){		
		x=3;
		return 'C';
}
	if (result>=40){		
		x=2;
		return 'D';
}
	if (result<40){		
		x=1;
		return 'F';
}
}

double contribution(char x)
{
	double cont;
	switch (x){	
	case 'A' :cont=(4*3)/20.0;
		break;
	case 'B' :cont=(3*3)/20.0;
		break;
	case 'C' :cont=(2*3)/20.0;
		break;
	case 'D' :cont=(1*3)/20.0;
		break;
	case 'F' :cont=0;
		break;
	default :
		printf("your grade is invalid");
}
	return cont;
}

/*###########################################################################*/
/*                       End of HW2_Emre_Bayram_141044019_part2.c            */
/*###########################################################################*/
