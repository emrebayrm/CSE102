/*###########################################################################*/
/*HW7_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on April 10, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*This program calculates calculate in how many distinct ways you can climb  */
/*to the top and to print it on the screen. 								 */
/*Inputs																	 */
/*	-how many stairs are there.												 */
/*Outputs																	 */
/*	-different ways types and total different ways number 					 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

/*---------------------------------------------------------------------------*/
/*							Function Protype								 */
/*---------------------------------------------------------------------------*/

/*This program returns combination processing.								 */
int combination (int n , int k);

/*This program calls ways_rec function */
int ways (int n);

/*This program shows us to different way types.								 */
int ways_rec(int n, int k);

int main()
{
	int i;
	
	printf("Hi, Do you wanna know how much different\nway that you can climb\n");
	printf("Enter stair numbers>>");
	scanf("%d",&i);
	printf("In Total => you have %d different ways.\n",ways(i));
	
	return 0;
}

int combination (int n , int k)
{
	int res;
	/*combination's start condition*/
	if(n<=0)
		res=0;
	/*End condition*/
	else if(k<=0 || k==n)
		res=1;
	else 
		res=combination(n-1,k-1)+combination(n-1,k);
	return res;
}

int ways (int n)
{
	int res,k=0;
	res=ways_rec(n,k); /*calls ways_rec function*/
	return res;
}

int ways_rec(int n, int k)
{
	int res;

	/*end condition for ways_rec function*/	
	if(k>n)
		res=0;
	else 
	{
		printf("%d one stairs %d two stairs",n-k,k);
		res=combination(n,k);
		printf("=>%d different way \nOR\n",res);
		res+=ways_rec(n-1,k+1);
	}
	return res;
}

/*############################################################################*/
/*					End of HW7_Emre_Bayram_141044019_part2.c				  */
/*############################################################################*/
