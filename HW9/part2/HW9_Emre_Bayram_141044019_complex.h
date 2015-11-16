/*	complex.h
 *
 *	abstract data type complex numbers
 *
 *	Type complex_t has these components
 *		real part and imaginary part
 *
 *	operations:
 *		gets complex number
 *		sum two complex number
 *		extract two complex number
 *		multiply two complex number
 *		divide two complex number
 *		norm of complex number 	
 */

typedef struct {double real;
				double imaginary;
				} complex_t;

/*show complex number */
extern void show_complex_number(complex_t comp);

/*gets complex numbers values on the console*/
extern complex_t get_complex(void);
				
/*takes 2 complex number and sums two these numbers*/
extern complex_t summary_two_complex(complex_t complex1, complex_t complex2);

/*takes 2 complex number and extracts these two numbers*/
extern complex_t extraction_two_complex(complex_t complex1, complex_t complex2);

/*takes 2 complex number and multiplies these two numbers*/
extern complex_t multipyly_two_complex(complex_t complex1, complex_t complex2);

/*takes 2 complex number and divides these two numbers*/
extern complex_t divide_two_complex(complex_t complex1, complex_t complex2);

/*takes 1 complex number and calculates norm of this number*/
extern double norm_of_complex(complex_t complex);

