/*############################################################################*/
/*								INCLUDES									  */
/*############################################################################*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef PART1_H
#define PART1_H 1
/*############################################################################*/
/*								DEFINES										  */
/*############################################################################*/
#define DEF_START_HOUR 9
#define DEF_END_HOUR 17

/*############################################################################*/
/*							TYPE DEFINATIONS								  */
/*############################################################################*/
typedef struct{	int app_id;
				int patient_id;
				int hour;
				}Appointment_t;

typedef struct{	int start;
				int end;
				}Working_hours_t;

typedef struct{	const char* records_file_n;
				const char* patients_file_n;
				const char* delete_file_n;
 				const char* readable_records_file_n;
 				const char* accepted_appo_file_n;
 				const char* parameters_file_n;
 				}Files_t;

/*############################################################################*/
/*							FUNCTION PROTYPES								  */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*	This function gets appointment requests from file.						  */
/*Returns appointments array and size of array as output parameter. 		  */
extern Appointment_t* getRequests(const Files_t* files, int* size);
/*----------------------------------------------------------------------------*/
/*	This function takes appoinment array in appointment_t type and size and   */
/*files informations. writes to file information about appointement.		  */
extern void write_appointments(Appointment_t appointments[], int size,
							   const Files_t* files);
/*----------------------------------------------------------------------------*/
/*	This function decides which files going to use written by user with main  */
/*arguments. If user doesn't send any arguments function works default values.*/
extern void get_main_arguments(int argc, char *argv[], Working_hours_t* hours,
							   Files_t* files);
/*----------------------------------------------------------------------------*/
/*	This function writes to file about file information used values.		  */
extern void print_parameters(const Files_t* files,const Working_hours_t* hours);
/*----------------------------------------------------------------------------*/
#endif
