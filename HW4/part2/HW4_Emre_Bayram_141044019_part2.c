/*************************************************************
 *                                                           *
 * HW04 Q2                                                   *
 * Student Name: EMRE BAYRAM                                 *
 * Student ID  : 141044019                                   *
 * Date        : 12/03/2015                                  *
 * Points      : 20										     *
 *                                                           *
 *************************************************************/
/*###########################################################*/
/*							INCLUDES						 */
/*###########################################################*/
#include <stdio.h>
/*###########################################################*/
/*							DEFINES							 */
/*###########################################################*/
#define PLAINTEXTFILE "/home/emre/Desktop/HW4/PlaintextMessage.txt"
#define ENCODEDFILE "/home/emre/Desktop/HW4/EncodedMessages.txt"
#define CRYPTEDINPUT "/home/emre/Desktop/HW4/CryptedMessages.txt"

/*-----------------------------------------------------------*/
/*						FUNCTİON PROTYPE					 */
/*-----------------------------------------------------------*/

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads encrypted text and creates encoded and              *
 * plain text files                                          *
 *************************************************************/
int main(int argc, char* argv[])
{
	FILE *f_plane_ptr, 
		 *f_encoded_ptr, 
		 *f_crypted_ptr;

	f_crypted_ptr=fopen(CRYPTEDINPUT,"r");
	f_encoded_ptr=fopen(ENCODEDFILE,"w");

	/* exit program and print error if encrypted text file could not be opened to read */
	/* exit program and print error if encoded text file could not be opened to write */
	if (f_encoded_ptr==NULL && f_crypted_ptr==NULL){
		printf("Input files couldn't opened.");
		return 1;
	}
	else decrypt_message(f_crypted_ptr, f_encoded_ptr); /* call decrypt_message function*/

	/* close encrypted and encoded files */
	fclose(f_encoded_ptr);
	fclose(f_crypted_ptr);

	f_encoded_ptr=fopen(ENCODEDFILE,"r");
	f_plane_ptr=fopen(PLAINTEXTFILE,"w");

	/* exit program and print error if plain text file could not be opened to write */
	/* exit program and print error if encoded text file could not be opened to read */
	if (f_encoded_ptr==NULL && f_plane_ptr==NULL){
		printf("Input files couldn't opened.");
		return 1;
	}
	else decode_message(f_encoded_ptr, f_plane_ptr);

	/* close encoded and plain files */
	fclose(f_encoded_ptr);
	fclose(f_plane_ptr);

	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{
	/*decoding table */
	switch (number_of_ones){
		case 0 : fprintf(f_out_ptr,"E");
			break;
		case 1 : fprintf(f_out_ptr,"I");
			break;
		case 2 : fprintf(f_out_ptr," ");
			break;
		case 3 : fprintf(f_out_ptr,"T");
			break;
		case 4 : fprintf(f_out_ptr,"C");
			break;
		case 5 : fprintf(f_out_ptr,"N");
			break;
		case 6 : fprintf(f_out_ptr,"A");
			break;
		case 7 : fprintf(f_out_ptr,"G");
			break;
		case 8 : fprintf(f_out_ptr,"B");
			break;
		case 9 : fprintf(f_out_ptr,"Z");
			break;
		case 10 : fprintf(f_out_ptr,"H");
			break;
		case 11 : fprintf(f_out_ptr,"L");
			break;
		case 12 : fprintf(f_out_ptr,"U");
			break;
		case 13 : fprintf(f_out_ptr,"V");
			break;
		case 14 : fprintf(f_out_ptr,"R");
			break;
		case 15 : fprintf(f_out_ptr,"S");
			break;
		case 16 : fprintf(f_out_ptr,"Y");
			break;
		case 17 : fprinrf(f_out_ptr,"W");
			break;
		case 18 : fprinrf(f_out_ptr,"O");
			break;
		case 19 : fprinrf(f_out_ptr,"K");
			break;
	}
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	int a,b,m=0,counter;
	a=fscanf(f_in_ptr,"%1d",&b);
	while (a!=EOF){
		if(b==0){
			printf("%d\n",m);
			decode_and_write_to_file(f_out_ptr,m);
			m=-1;
		}
		++m;
		a=fscanf(f_in_ptr,"%1d",&b);
	}
	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	int a;
	char b;
	int counter = 0;
	a=fscanf(f_in_ptr,"%c",&b);
	while (a!=EOF){
		if (b=='*') fprintf(f_out_ptr,"1");
		else if (b=='_') fprintf(f_out_ptr,"0");
		a=fscanf(f_in_ptr,"%c",&b);
	}
	return counter;
}
