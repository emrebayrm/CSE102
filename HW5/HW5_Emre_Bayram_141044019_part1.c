/*###########################################################################*/
/*HW5_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on march 23, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*This program is car crash simulator.										 */
/*Inputs 																	 */
/*	-cars characters.														 */
/*	-cars speeds.															 */
/*	-cars weights.															 */
/*	-cars positions.														 */
/*Outputs																	 */
/*	-diagram of accident.													 */
/*###########################################################################*/

/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

/*---------------------------------------------------------------------------*/
/*								Defines										 */
/*---------------------------------------------------------------------------*/
#define ROAD_LENGHT 50.0

/*---------------------------------------------------------------------------*/
/*								Type Defs									 */
/*---------------------------------------------------------------------------*/
typedef enum {PLAY, CRASH, END} object_state;

/*---------------------------------------------------------------------------*/
/*							Function Protypes								 */
/*---------------------------------------------------------------------------*/

/*###########################################################################*/
/*																			 */
/*void make_move(char *object1,double *position1,double *speed1,int weight1, */
/*			   char *object2, double *position2, double *speed2,int weight2, */
/*			   object_state *game_state)									 */
/*--------------------														 */
/*	-object1,object2		car1 and car2 characters.						 */
/*	-position1, position2	car1's position and car2's position.			 */
/*	-speed1, speed2			car1's speed and car2's position.				 */
/*	-weight1, weight2		car1's weight and car2's weight.				 */
/*	-game_state				controls car status.							 */
/*																			 */
/*Output																	 */
/*--------------------														 */
/*	calls print_game_stats and prints diagram								 */
/*																			 */
/*Description																 */
/*-------------------														 */
/*	Cars runs in this function.												 */
/*																			 */
/*###########################################################################*/
void make_move(char *object1, double *position1, double *speed1, int weight1, 
			   char *object2, double *position2, double *speed2, int weight2, 
			   object_state *game_state);

/*###########################################################################*/
/*																			 */
/*double car_crash_time(double position1, double position2, 				 */
/*					  double speed1, double speed2)							 */
/*-------------------														 */
/*	-position1, position2	car1's position and car2's position.			 */
/*	-speed1, speed2			car1's speed and car2's position.				 */
/*																			 */
/*Output																	 */
/*-------------------														 */
/*	crash time																 */
/*																			 */
/*Description																 */
/*-------------------														 */
/*	This function calculetes crash time and returns as value.				 */
/*																			 */
/*###########################################################################*/
double car_crash_time(double position1, double position2, 
					  double speed1, double speed2);

/*###########################################################################*/
/*void print_game_state(char object1, double position1, 					 */
/*					  char object2, double position2,						 */ 
/*					  object_state game_state)							 	 */
/*------------------														 */
/*	-object1,object2		car1 and car2 characters.						 */
/*	-position1, position2	car1's position and car2's position.			 */
/*	-game_state				cars status.									 */
/*																			 */
/*Output																	 */
/*-----------------															 */
/*	-prints according to values of cars information							 */
/*																			 */
/*Description																 */
/*---------------															 */
/*	This function prints according to cars position and status.				 */
/*																			 */
/*###########################################################################*/
void print_game_state(char object1, double position1, 
					  char object2, double position2, 
					  object_state game_state);


int main()
{
	char object1,object2;						/*variables for cars*/
	int weight1,weight2;						/*weights of cars*/
	double position1,position2,speed1,speed2;	/*positions and speeds*/	
	object_state d=PLAY;						/*simulator status*/

	/*get characters values*/
	printf("Enter CAR1 character and CAR2 character>");
	scanf("%c %c",&object1,&object2);			
	/*get weights values*/
	printf("\nEnter CAR1 weight and CAR2 weight>");
	scanf("%d%d",&weight1,&weight2);
	/*get speed values*/
	printf("\nEnter CAR1 speed AND CAR2 speed>");
	scanf("%lf%lf",&speed1,&speed2);
	/*get positions of cars*/
	printf("\nEnter CAR1 position and CAR2 position(Road lenght is 50)>");
	scanf("%lf%lf",&position1,&position2);
	/*call make move function*/
	make_move(&object1,&position1,&speed1,weight1,&object2,&position2,&speed2,weight2,&d);

	return 0;
}

void make_move(char *object1, double *position1, double *speed1, int weight1,
			   char *object2, double *position2, double *speed2, int weight2,
			   object_state *game_state)
{
	double crash_time;
	int i;
	double total_speed;
	/*make function needs crash time so call crash time function.*/
	crash_time=car_crash_time(*position1,*position2,*speed1,*speed2);

	do{
	//	print_game_state(*object1,*position1,*object2,*position2,*game_state);
		/*printing for play status*/
		for(i=0;i<crash_time;++i){
			print_game_state(*object1,*position1,*object2,*position2,*game_state);
			*position1+=*speed1;
			*position2+=*speed2;
			if (*position1>=*position2){
					*game_state=CRASH;
					/*momentum calculation.*/
					total_speed=((*speed1 * weight1)+(*speed2 * weight2))/(weight1+weight2);
					/*After crash Sybomls turns X characters*/
					*object1='X';
					*object2='X';
			}
		}
	
		while(*position1>0 && *position1 < ROAD_LENGHT){
			*position1+=total_speed;
			print_game_state(*object1,*position1,*object2,*position2,*game_state);
		}
		*game_state=END;
		/*printing end status.*/
		print_game_state(*object1,*position1,*object2,*position2,*game_state);	
	}
	while(*game_state!=END);
}
double car_crash_time(double position1, double position2, double speed1, double speed2)
{
	double crash_time;
	crash_time=(position1 - position2)/(speed2 - speed1);
	return crash_time;
}
void print_game_state(char object1, double position1, 
					  char object2, double position2, 
					  object_state game_state)
{
	int i,m;
	if(game_state==PLAY){
		for(i=0;i<position1;++i)
			printf("_");
		printf("%c",object1);
		for(i=0;i<position2-position1;++i)
			printf("_");
		printf("%c",object2);
		for(i=0;i<ROAD_LENGHT-position2;++i)
			printf("_");
		printf("\n");
		for(i=0;i<=5;++i){
			for(m=0;m<=9;++m)
				printf("%d",m);
		}
		printf("\n");
	}
	
	if (game_state==CRASH){
		for(i=0;i<position1;++i)
			printf("_");
		printf("%c",object1);
		for(i=0;i<=ROAD_LENGHT-position1;++i)
			printf("_");
		printf("\n");
		for(i=0;i<=5;++i){
			for(m=0;m<=9;++m)
				printf("%d",m);
		}
		printf("\n");
	}
	if (game_state==END)
		printf("Diagram finished succesfully\n");
}
