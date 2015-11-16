/*###########################################################################*/
/*HW5_Emre_Bayram_141044019_part2.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on march 21, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*	This program finds maximum value in array, adds all array, counts a value*/
/*in array, finds second maximum value, search a value in array				 */
/*																			 */
/*Inputs																	 */
/*----------------------------- 											 */
/*	-value for searching													 */
/*	-value for counting														 */
/*																			 */
/*Outputs																	 */
/*----------------------------- 											 */
/*	-prints results															 */
/*																			 */
/*###########################################################################*/

/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

/*---------------------------------------------------------------------------*/
/*								Type Defs									 */
/*---------------------------------------------------------------------------*/
typedef enum {TRUE=1 , FALSE=0} BOOL;
/*---------------------------------------------------------------------------*/
/*							Function Protypes								 */
/*---------------------------------------------------------------------------*/

/*###########################################################################*/
/*int max_array(const int array[], int n)								 	 */
/*------------------														 */
/*	-array	array															 */
/*	-n 		size															 */
/*																			 */
/*Output																	 */
/*------------------														 */
/*	-max value in array														 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	This function finds max value in array									 */
/*																			 */
/*###########################################################################*/
int max_array(const int array[], int n);

/*###########################################################################*/
/*int sum_all_array(const int array[], int n)								 */
/*------------------														 */
/*	-array	array															 */
/*	-n 		size															 */
/*																			 */
/*Output																	 */
/*------------------														 */
/*	-summuary all value of array											 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	returns summuary of array 												 */
/*###########################################################################*/
int sum_all_array(const int array[], int n);

/*###########################################################################*/
/*int count_array(const int array[], int n, int value)						 */
/*------------------														 */
/*	-array	array															 */
/*	-n 		size															 */
/*	-value 	counting value													 */
/*																			 */
/*Output																	 */
/*------------------														 */
/*	-count																	 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	counts how much repeated in array of given value						 */
/*																			 */
/*###########################################################################*/
int count_array(const int array[], int n, int value);

/*###########################################################################*/
/*int second_max_array(const int array[], int n)							 */
/*------------------														 */
/*	-array	array															 */
/*	-n 		size															 */
/*																			 */
/*Output																	 */
/*------------------														 */
/*	-second max																 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	Returns second max value in array.										 */
/*###########################################################################*/
int second_max_array(const int array[], int n);

/*###########################################################################*/
/*BOOL search_array (const int array[], int n, int value)		 			 */
/*------------------														 */
/*	-array	array															 */
/*	-n 		size															 */
/*	-value search value														 */
/*																			 */
/*Output																	 */
/*------------------														 */
/*	-TRUE if it finds														 */
/*	-FALSE if it doesn't find												 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	Searching given value.													 */
/*###########################################################################*/
BOOL search_array (const int array[], int n, int value);

/*###########################################################################*/
/*void print_array(const int array[],int size)								 */
/*------------------														 */
/*	-array	array															 */
/*	-n 		size															 */
/*																			 */
/*Output																	 */
/*------------------														 */
/*	-prints all Array's values												 */
/*																			 */
/*Description																 */
/*------------------														 */
/*	This function prints array's values 									 */
/*																			 */
/*###########################################################################*/
void print_array(const int array[],int size);

int main()
{
	int myarray[9]={6,2,3,15,12,21,3,18,2};	/*array values*/
	int max;								/*variable for max value*/
	int sum;								/*variable for summuary value*/
	int value,count,value2;					/*value for	counting			*
											 *count for result of count func*
											 *value2 for searching			*/
	int second_max;							/*variable for second max*/
	int search;								/*variable for searh func*/

	/*print all array*/
	printf("Here is your array \n");
	print_array(myarray,9);

	/*show max array*/
	max=max_array(myarray,9);
	printf("Maksimum array is %d\n",max);

	/*show second max*/
	second_max=second_max_array(myarray,9);
	printf("Second max array is %d\n",second_max);

	/*show summuary*/
	sum=sum_all_array(myarray,9);
	printf("Sum of all array is %d\n",sum);

	/*show how much counted*/
	printf("What U wanna count>"); 
	scanf("%d",&value);
	count=count_array(myarray,9,value);
	printf("Count of value %d is %d\n",value,count);

	/*show location of searched value*/
	printf("What U wanna Search>");
	scanf("%d",&value2);
	search=search_array(myarray,9,value2);

	/*if it false that means error and here is error message*/
	if (search==FALSE)
		printf("there is no %d in array.\n",value2);

	return 0;
}

int max_array(const int array[], int n)
{
	int i;
	int m=0;
	for(i=0;i<n;++i){
		if(array[i]>m)
			m=array[i];
	}
	return m;
}

int sum_all_array(const int array[], int n)
{
	int i;
	int sum=0;
	for(i=0;i<n;++i){
		sum+=array[i];
	}
	return sum;
}

int count_array(const int array[], int n, int value)
{
	int i;
	int count=0;

	for(i=0;i<n;++i){
		if(value==array[i])
			++count;
	}
	return count;
}

int second_max_array(const int array[], int n)
{
	int max;
	int second_max;
	int i,temp=0;

	max=max_array(array,n);

	for(i=0;i<n;++i){
		second_max=temp;
		if(temp<array[i]){
			temp=array[i];
			if(temp==max)
				temp=second_max	;
		}
	}
	return second_max;
}

BOOL search_array(const int array[], int n, int value)
{
	int i;

	for(i=0;i<n;++i){
		if(value==array[i]){
			printf("%d is at [%d]",value,i+1);
			return TRUE;
		}
	}
	return FALSE;
}

void print_array(const int array[],int size)
{
	int i;
	for(i=0;i<size;++i)
		printf("%d ",array[i]);
	printf("\n");
}
