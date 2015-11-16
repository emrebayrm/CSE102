/*###########################################################################*/
/*HW3_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on march 5, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*This program is a guess game. Computer takes random number into memory and */
/*user makes a guess. Program runs until user wants finish or make true guess*/
/*Inputs 																	 */
/*	-user's guess															 */
/*Outputs																	 */
/*	-no outputs
/*###########################################################################*/
/* 																			 */
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
/*																			 */
/*int RNG(void)																 */
/*--------------															 */
/*	no inputs																 */
/*																			 */
/*Return 																	 */
/*--------------															 */
/*	result	- generates random integer number								 */
/*																			 */
/*Description																 */
/*--------------															 */
/*	This function generates random number for user 							 */
/*																			 */
/*###########################################################################*/
int RNG(void);
/*###########################################################################*/
/*int calculate_the_difference(int guess,int number)						 */
/*------------																 */
/*	guess	- user's guess													 */
/*	number	- random number which is taken from computer					 */
/*																			 */
/*Return																	 */
/*------------																 */
/*	result	- result of calculation											 */
/*																			 */
/*Description																 */
/*------------																 */
/*	this funcction calculates differences between user's guess and number	 */
/*																			 */
/*###########################################################################*/
int calculate_the_difference(int guess,int number);
/*###########################################################################*/
/*void warn_the_player(int difference)										 */
/*------------																 */
/*	difference	- difference between two number								 */
/*																			 */
/*Return																	 */
/*	-sends warning message to user											 */
/*																			 */
/*Description																 */
/*	This function warns the player how much far away from true guess 		 */
/*																			 */
/*###########################################################################*/
void warn_the_player(int difference);

int main ()
{
	int guess;				/*variable for user's guess*/
	int number;				/*variable of random number*/
	int absolutevalue;		/*variable of absolute value*/ 
	char answer,answer2;	/*answer variables */

	/*random number*/
	number=RNG()%10+1;
	/*get information about game*/
	printf("Hi do you play a game with me for yes press 'p' or 'P' ");
	printf("\nif you wanna exit any time you want press 'e' or 'E'");
	printf("\nnow make a choose :)  ");

	scanf("%c",&answer);	/*get answer*/
	/*if statement used for user user wants to play or not*/
	if (answer=='p'||answer=='P'){
		printf("Hi, I kept number now make a guess pls> ");
		scanf("%d",&guess);
		/*while statement used for programs runs until user wants to finish or user win*/
		while (number!=guess){
			/*calculates absolute value*/
			absolutevalue=calculate_the_difference(guess,number);
			/*sends wanring message to player*/ 
			warn_the_player(absolutevalue);
			/*giving information to user*/
			printf("Wrongg!! if you wanna exit press 'E' or 'e' \n");
			printf("or you wanna go on press anything you want>");
			scanf(" %c",&answer2);
			/*if statement used for make decision on continue program*/
			if(answer2=='e'||answer2=='E'){
				guess=number;
				printf("See you later...");
				return 0;
			}
			else {printf("OK, then make one more try and don't forget\n");
			warn_the_player(absolutevalue);
			scanf("%d",&guess);
			}
		}
	printf("Conguratulations!!! \n");
	}

	else printf("GOOD BYE...\n");
	
	return 0;
}

int RNG(void)
{
	int rand_num;
	srand((unsigned)time(NULL));
	rand_num=rand();
	return rand_num;
}

int calculate_the_difference(int guess,int number)
{
	int difference;
	difference=abs(guess-number);
	return difference;
}

void warn_the_player(int difference)
{
	if (difference>=5)
		printf("You are too far from the number\n");
	else if (difference>=3)
		printf("You are far from the number\n");
	else if (difference<=2)
		printf("You are close from the number\n");
}
