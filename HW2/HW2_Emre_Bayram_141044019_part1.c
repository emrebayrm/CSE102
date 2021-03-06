/*###########################################################################*/
/*HW2_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on February 28, 2015								 */
/*Description																 */
/*-----------------------------												 */
/*This program is a guess game. Computer takes random number into memory and */
/*user makes a guess. User has 2 guess										 */
/*Inputs 																	 */
/*	-user' guess															 */
/*Outputs																	 */
/*	-if the guess true program will finish otherwise computer directs once	 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
/*	generates random integer number											 */
/*																			 */
/*Description																 */
/*--------------															 */
/*	This function generates random number for user 							 */
/*																			 */
/*###########################################################################*/
int RNG(void);
/*###########################################################################*/
/*																			 */
/*void contrl_structure(int rand_num, int guess)							 */
/*--------------															 */
/*	rand_numb - value of random number 										 */
/*	guess	  - user's guess												 */
/*																			 */
/*Return																	 */
/*--------------															 */
/*	nothing returns															 */
/*																			 */
/*Description																 */
/*--------------															 */
/*	This function controls whether the guess is true and informs user about  */
/*	guess																	 */
/*																			 */
/*###########################################################################*/
void contrl_structure(int rand_num, int guess);
/*###########################################################################*/
/*																			 */
/*int guess_fnc(void)														 */
/*--------------															 */
/*	no inputs																 */
/*																			 */
/*Return 																	 */
/*--------------															 */
/*	guess which is entered by user 											 */
/*																			 */
/*Description																 */
/*--------------															 */
/*	This function takes guess from user. 		 							 */
/*																			 */
/*###########################################################################*/
int guess_fnc(void);
int main()
{
	int guess,guess2;	/* variables for user's guess*/
	int random_numb; 	/* variable for random number*/ 

	/*information to user*/
	printf("I kept number from 1 to 10\nmake a guess and make it true\nand " 
			"make us happy!!:)");

	random_numb=RNG()%10+1; 				/*get random number*/
	guess=guess_fnc();						/*first guess*/
	contrl_structure(random_numb,guess);	/*control the guess*/
	guess2=guess_fnc();						/*second guess*/
	contrl_structure(random_numb,guess2);	/*control the guess*/
	
	return 0;
}

int RNG(void)
{
	int rand_num;
	srand((unsigned)time(NULL));
	rand_num=rand();
	return rand_num;
}
void contrl_structure(int rand_num, int guess)
{
	int distance;
	distance=abs(rand_num-guess);
	

	if (guess==rand_num)
	{
		printf("Congratulation you guessed right !!!\n");
	}
	else
	{
		printf("Please try again :( and also\n");
		if (distance >= 5)
			printf("You are too far from the number\n");
		else if (distance >= 3)
			printf("You are far from the number\n");
		else if (distance <= 2)
			printf("You are too close to the number\n");
	}
}

int guess_fnc(void)
{
	int guess;
	printf("enter a guess>");
	scanf("%d",&guess);
	return guess;
}

/*###########################################################################*/
/*                       End of HW2_Emre_Bayram_141044019_part1.c            */
/*###########################################################################*/
