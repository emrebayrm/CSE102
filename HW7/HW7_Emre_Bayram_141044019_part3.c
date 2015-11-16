/*###########################################################################*/
/*HW7_Emre_Bayram_141044019_part1.c 										 */
/*-----------------------------												 */
/*Written by Emre Bayram on April 13, 2015									 */
/*Description																 */
/*-----------------------------												 */
/*This program solves a maze. finds true way in the given matrix			 */
/*Input																		 */
/*	-a map created with number instructions.								 */
/*Output																	 */
/*	-a path which shows true path											 */
/*###########################################################################*/
/* 																			 */
/*---------------------------------------------------------------------------*/
/*								Includes									 */
/*---------------------------------------------------------------------------*/
#include<stdio.h>
#define COL_SIZE 5

/*---------------------------------------------------------------------------*/
/*								Typedefs								 	 */
/*---------------------------------------------------------------------------*/
typedef enum {TRUE=1, FALSE=0} bool;
typedef enum {notavailable,available,right_down} Grid_t;

/*---------------------------------------------------------------------------*/
/*							Function Protype								 */
/*---------------------------------------------------------------------------*/

/*This function read table in text file and fills a table in grid_t type 	 */
/*returns a number the read row.											 */
int read_table(FILE *input_file, Grid_t table[][COL_SIZE]);

/*This function prints a matrix in this program prints true road.			 */
void print_path(char path[][COL_SIZE], int n);

/*This function finds true way in given matrix and fills with '*' character  */
/*in a character matrix if it finds way returns true if it doesn't false.	 */
bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
			   int size, int location_x, int location_y);
			   
int main()
{
	int i,j;					/*counter variables*/
	FILE *inp;					/*table variable*/
	int size;					/*size value*/
	bool status;				/*True or False*/
	Grid_t table[10][COL_SIZE];	/*table matrix*/
	char path[10][COL_SIZE];	/*path matrix*/
	
	/*input file*/
	inp=fopen("table.txt","r");	
	
	/*get size information and get table information*/
	size=read_table(inp,table);
	
	printf(">>>>>>>>>>>This is your maze<<<<<<<<\n");
	
	/*give information to user about its maze*/
	for(i=0;i<size;++i){
		for(j=0;j<COL_SIZE;++j)
			printf("%d ",(int)table[i][j]);
		printf("\n");
	}

	/*make default path matrix*/
	for(i=0;i<size;++i)
		for(j=0;j<COL_SIZE;++j)
			path[i][j]='-';
			
	path[0][0]='*';/*initial position*/
	
	/*finding path*/
	status=find_path(table,path,size,0,0);
	if(status == FALSE){
		printf("There is no exit in this maze :(\n");
		printf("Now you can look where you are > \n");
	}
	else printf("Yeppp There is an exit look !!!\n");
	
	/*print found road*/
	print_path(path,size);
	
	/*printing bottom dead end*/
	for(i=0;i<=2*COL_SIZE;++i)
		printf("-");
	printf("\n");
	
	return 0;
}

int read_table(FILE *input_file, Grid_t table[][COL_SIZE])
{
	int status,i=0,j;

	/*scanning each row and coloumn*/
	do{
		for(j=0;j<COL_SIZE;++j)
			status=fscanf(input_file,"%u",&table[i][j]);
		++i;
	}
	while(status != EOF);

	return i-1;
}

void print_path(char path[][COL_SIZE], int n)
{
	int i,j;
	
	/*printing process*/
	for(i=0;i<n;++i){
		for(j=0;j<COL_SIZE;++j)
			printf("%c ",path[i][j]);
		printf("|\n");
	}
}

bool find_path(Grid_t table[][COL_SIZE], char path[][COL_SIZE],
			   int size, int location_x, int location_y)
{
	
	bool flag=FALSE;
	if(location_x == (COL_SIZE - 1) || location_y == (size - 1))
		flag=TRUE;
	else
	{
		if(location_x == COL_SIZE)
			flag=find_path(table,path,size,location_x+1,location_y);
		if(location_y == size)
			flag=find_path(table,path,size,location_x,location_y+1);
		if(table[location_y][location_x+1] != notavailable)
		{
			path[location_y][location_x+1]='*';
			switch (table[location_y][location_x+1])
				{
				case available : 
					flag=find_path(table,path,size,location_x+1,location_y);
					if(flag == TRUE)
						path[location_y][location_x+1]='*';
					break;
				case right_down : 
					flag=find_path(table,path,size,location_x+1,location_y+1);
					if(flag == TRUE)
						path[location_y][location_x+1]='*';
					break;
				}
		}
		else if(table[location_y+1][location_x] != notavailable)
			{
			path[location_y+1][location_x]='*';
			switch (table[location_y+1][location_x])
				{
				case available : 
					flag=find_path(table,path,size,location_x,location_y+1);
					if(flag == TRUE)
						path[location_y+1][location_x]='*';
					break;
				case right_down : 
					flag=find_path(table,path,size,location_x+1,location_y+1);
					if(flag == TRUE)
						path[location_y+1][location_x]='*';
					break;
				}
			}
	}
	return flag;
}

/*############################################################################*/
/*					End of HW7_Emre_Bayram_141044019_part3.c				  */
/*############################################################################*/
