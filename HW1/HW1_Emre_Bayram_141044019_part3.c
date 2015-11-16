/*###########################################################################*/
/*HW01_Emre_Bayram_141044019_part3.c										 */
/*-----------------------------												 */
/*Written by Emre Bayram on February 17, 2015								 */
/*Description																 */
/*-----------------------------												 */
/*This program calculates how much money spend to cost of fuel in total 	 */
/*kilometers for 3 cars.													 */
/*Inputs 																	 */
/*	-cars information about fuel price, how much cost at one kilometer, total*/
/*kilometers.
/*Outputs																	 */
/*	-total costs for each car		 										 */
/*Note:																		 */
/*	-You need to create a txt file for input data which is named exactly	 */
/*cars.txt.
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>

int main()
{
	double car1_per_kmh, car1_prc_fuel, total_km_car1, car1_sum; /* variables for car 1*/
	double car2_per_kmh, car2_prc_fuel, total_km_car2, car2_sum; /* variables for car 2*/
	double car3_per_kmh, car3_prc_fuel, total_km_car3, car3_sum; /* variables for car 3*/
	int car1_sum_krs, car2_sum_krs, car3_sum_krs;	/*variables for convert to kurus*/	
	int car1, car2, car3; /*integers for all cars */

	FILE *inp,
		 *outp;

	inp= fopen("cars.txt","r"); /*Input file*/
	outp= fopen("total_fuel_costs.txt","w");

	fscanf(inp, "%d%lf%lf%lf%d%lf%lf%lf%d%lf%lf%lf" 
				,&car1, &car1_per_kmh, &car1_prc_fuel, &total_km_car1
		  	    ,&car2, &car2_per_kmh, &car2_prc_fuel, &total_km_car2
	       	    ,&car3, &car3_per_kmh, &car3_prc_fuel, &total_km_car3);
	
	/*compute all costs*/
	car1_sum = car1_per_kmh*car1_prc_fuel*total_km_car1;
	car2_sum = car2_per_kmh*car2_prc_fuel*total_km_car1;
	car3_sum = car3_per_kmh*car3_prc_fuel*total_km_car3;
	
	/*display on console */ 
	printf("The total fuel cost of the car %d is %d TL and %.0f Kurus.\n",car1, (int)car1_sum,(car1_sum-(int)car1_sum)*100);
	printf("The total fuel cost of the car %d is %d TL and %.0f Kurus.\n",car2, (int)car2_sum,(car2_sum-(int)car2_sum)*100);
	printf("The total fuel cost of the car %d is %d TL and %.0f Kurus.\n",car3, (int)car3_sum,(car3_sum-(int)car3_sum)*100);

	/*write in total_fuel_costs.txt file*/
	fprintf(outp, "%f\n", car1_sum);
	fprintf(outp, "%f\n", car2_sum);
	fprintf(outp, "%f\n", car3_sum);
	
	fclose(inp);
	fclose(outp);
	return 0;
}

/*###########################################################################*/
/*				End of HW01_Emre_Bayram_141044019_part3.c					 */
/*###########################################################################*/
