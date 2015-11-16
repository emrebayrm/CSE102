/*###########################################################################*/
/*HW9_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on march 23, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*	This program calculates salary rise according to people					 */
/*Inputs																	 */
/*	-informaion about people in the text file								 */
/*Outputs																	 */
/*	-writes to binary file with updates										 */
/*###########################################################################*/

/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*---------------------------------------------------------------------------*/
/*								Defines										 */
/*---------------------------------------------------------------------------*/
#define INSTRCTR_FRST_HLF 5
#define INSTRCTR_SECND_HLF 5.3
#define DEGREE_A 17.5
#define DEGREE_B 12
#define DEGREE_C 9

/*---------------------------------------------------------------------------*/
/*							Type definations								 */
/*---------------------------------------------------------------------------*/
typedef struct { char name[30];
				 char surname[30];
				 char dep[30];
				 char class1[10];
				 char class2[10];
				 double salary;
			   } type_I;

typedef struct { char name[30];
				 char surname[30];
				 double salary;
				 char degree;
			   } type_E;

typedef union {	type_I ins;
				type_E emp;
			  } combine_type;

/*---------------------------------------------------------------------------*/
/*							Function Protypes								 */
/*---------------------------------------------------------------------------*/
double calculate_annual_salary(double salary, char type);
void write_to_bin(char *inp_file, char *outp_bin_file);
combine_type get_params(FILE* inp);
combine_type salary_rise(combine_type person_info);

int main()
{
	/*Process... :)*/
	write_to_bin("input.txt","bin_file.bin");	

	return 0;
}

/*This function calulates annual salary according to person*/
double calculate_annual_salary(double salary, char type)
{
	double res;
	switch(type){
		case 'a' : res = ((salary*DEGREE_A)/100) + salary;
			break;
		case 'b' : res = ((salary*DEGREE_B)/100) + salary;
			break;
		case 'c' : res = ((salary*DEGREE_C)/100) + salary;
			break;
		case 'i'  : res = ((salary*INSTRCTR_FRST_HLF)/100) + salary;
			res += ((res*INSTRCTR_SECND_HLF)/100) + res;
	}
	
	return res;
}

/*This function takes two char * for name of text file and binary file.		  */
/*In return fills to binary file with updated values						  */
void write_to_bin(char *inp_file, char *outp_bin_file)
{
	combine_type temp;	/*temporary variable*/
	FILE *inp_text,		/*file pointers text and*/ 
		 *outp_bin;		/*binary file			*/
	
	/*opening files*/
	inp_text = fopen(inp_file,"r");
	outp_bin = fopen(outp_bin_file,"wb");
	
	/*Process updates and writes updated values in same time */
	while(!feof(inp_text)){
		
		temp=salary_rise(get_params(inp_text));
		fwrite(&temp,sizeof(temp),1,outp_bin);
	}
	
	fclose(inp_text);
	fclose(outp_bin);
}

/*This function gets parameters into text file*/
combine_type get_params(FILE *inp)
{
	combine_type type;
	char first_value[15];
	char dead;
	char c;
	int flag=1;
	int i=0;

	/*first read*/
	fscanf(inp,"%s",first_value);

	/*processing according to first value*/	
	if(strcmp(first_value,"Instructor,") == 0)
		{
		fscanf(inp,"%s %s",type.ins.name,type.ins.surname);
		/*algorithm for more than 2 word and seperated by white spaces*/
		while(flag)
		{
			fscanf(inp,"%c",&c);
			if(c == 44)
				flag=0;
			else type.ins.dep[i]=c;
			
			i++;
		}
		/*convert to string*/
		type.ins.dep[i]='\0';
		
		/*other read actions*/
		fscanf(inp,"%s%s%lf",type.ins.class1,type.ins.class2,&type.ins.salary);
		}
	else if(strcmp(first_value,"Employee,") == 0)
		fscanf(inp,"%s%s%lf%c %c",type.emp.name,type.emp.surname,&type.emp.salary
								 ,&dead,&type.emp.degree);
		
	return type;
}

/*returns updated value*/
combine_type salary_rise(combine_type person_info)
{	
	if(person_info.ins.salary != 0)
		person_info.ins.salary=calculate_annual_salary(person_info.ins.salary,'i');
	else person_info.emp.salary=calculate_annual_salary(person_info.emp.salary,person_info.emp.degree);
	
	return person_info;
}

/*########################################################################### */
/*                    End of  HW09_Emre_Bayram_141044019_part1.c	          */
/*########################################################################### */
