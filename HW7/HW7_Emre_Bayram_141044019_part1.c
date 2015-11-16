/*###########################################################################*/
/*HW7_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on April 9, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*This program shows that how much time occured a word in given sentences.	 */
/*																			 */
/*Inputs																	 */
/*	-sentence as a string.													 */
/*	-word as string.														 */
/*Output																	 */
/*	-how much time occured.													 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>

/*---------------------------------------------------------------------------*/
/*							Function Protype								 */
/*---------------------------------------------------------------------------*/

/*This function takes 2 char strings source, destination and integer.It copies*/
/*first n integer to destinations from source.								  */
char* strncpyy(char* dest,const char* source, int n);

/*This function takes a string and this function returns its size.			  */
int find_size(const char *string);

/*This function takes 2 string and returns integer. This function searches 	  */
/*second string in the first string and returns how much occured in the first */
/*string.																	  */
int char_number(const char *string, const char *wish_to_find);

int main()
{
	int size;	
	char* str="bir gun bir gun bir cocuk eve de gelmiş kimse yok bir gun daha";
	char* st2="gun";
	
	/*calls char number function */
	size=char_number(str,st2);

	printf("%d times occured\n",size);
	
	return 0;	
}

int find_size(const char* string)
{
	int res;
	
	/*stop condition for recurseive function.*/
	if(string[0]=='\0')
		res=0;
	else {
		res=1+find_size(&string[1]);
	}
	return res;
}

int char_number(const char *string, const char *wish_to_find)
{
	int res=0;
	int lenght;
	char temp[20]; /*tenporary array for searching*/
	
	lenght=find_size(wish_to_find);
	
	/*stop condition for recurseive function.*/
	if (string[0] == '\0'){
		res = 0;
		}
	else{
		/*copying string to temp for comparison*/
		strncpyy(temp,&string[0],lenght);
		if(strcmp(temp,wish_to_find)==0){
			res=1+char_number(&string[1],wish_to_find);
		}
		else {res=char_number(&string[1],wish_to_find);
		}
	}
		
	return res;
}

char* strncpyy(char dest[],const char source[], int n)
{
	int i;
	/*copying process*/
	for(i=0;i<n;++i)
		if(source[i]!='\0')
			dest[i]=source[i];
	dest[i]='\0';
	return dest;	
}
/*############################################################################*/
/*					End of HW7_Emre_Bayram_141044019_part1.c				  */
/*############################################################################*/
