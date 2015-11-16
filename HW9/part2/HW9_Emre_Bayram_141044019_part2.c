/*############################################################################*/
/*HW9_Emre_Bayram_141044019_part2.c											  */
/*------------------------------											  */
/*Written by Emre Bayram on 26 april, 2015 									  */
/*Description																  */
/*------------------------------											  */
/*calculation about complex numbers 										  */
/*Inputs																	  */
/*	-2 complex number														  */
/*Output																	  */
/*	-result of calculation													  */
/*############################################################################*/

/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include"HW9_Emre_Bayram_141044019_complex.h"

int main()
{
	complex_t res;			/*result complex variable*/
	complex_t comp1,comp2;	/*complex number variables*/

	/*Fun with the complex numbers.*/
	printf("Now You Can add complex numbers\n");
	comp1 = get_complex();
	comp2 = get_complex();
	
	res = summary_two_complex(comp1,comp2);
	show_complex_number(res);

	printf("Now You Can substract complex numbers\n");
	comp1 = get_complex();
	comp2 = get_complex();

	res = extraction_two_complex(comp1,comp2);
	show_complex_number(res);
	
	printf("Now You Can multiply complex numbers\n");
	comp1 = get_complex();
	comp2 = get_complex();

	res = multipyly_two_complex(comp1,comp2);
	show_complex_number(res);
	
	printf("Now You Can divide complex numbers\n");
	comp1 = get_complex();
	comp2 = get_complex();

	res = divide_two_complex(comp1,comp2);
	show_complex_number(res);

	printf("Now You Can calculate norm of complex number\n");
	comp1 = get_complex();

	printf("%.2f is norm of ",norm_of_complex(comp1));
	show_complex_number(comp1);
	
	return 0;
}
