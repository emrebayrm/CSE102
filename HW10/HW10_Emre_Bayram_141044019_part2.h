/*############################################################################*/
/*								INCLUDES									  */
/*############################################################################*/
#include"HW10_Emre_Bayram_141044019_part1.h"
#include<stdlib.h>
#include<stdio.h>

#ifndef PART2_H
#define PART2_H

/*############################################################################*/
/*							TYPE DEFINATIONS								  */
/*############################################################################*/
typedef struct list_node_s{	int app_id;
							int patient_id;
							char name[50];
							char *history;
							int hour;
							struct list_node_s *next;
						  }node_t;

typedef enum {TRUE=1 , FALSE=0} BOOL;

/*############################################################################*/
/*							FUNCTION PROTYPES								  */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*	This function bilds link list. Takes an array with size, and working hours*/
/*returns linked list.														  */
extern node_t* build_ll(Appointment_t appointments[], int size, const Working_hours_t* hours);
/*----------------------------------------------------------------------------*/
/*	This function writes to file accepted appointments.It takes head of link  */
/*list and files.															  */
extern void write_accepted_app(node_t* head, const Files_t* files);
/*----------------------------------------------------------------------------*/
/*	This function adds personal data to link list							  */
extern void add_personal_data(node_t* head, const Files_t* files);
/*----------------------------------------------------------------------------*/
/*	This function deletes wrong appointments in link list. Returns deleted 	  */
/*appointments number.														  */
extern int delete_appointments(node_t** head, const Files_t* files);
/*----------------------------------------------------------------------------*/
/*	This function frees list.												  */
extern void free_list(node_t* head);
/*----------------------------------------------------------------------------*/
/*	This function sorts appointments										  */
extern void sort_appo(Appointment_t a[], int array_size);
/*----------------------------------------------------------------------------*/
/*	This function search a value in array.									  */
extern BOOL search_array(const Appointment_t array[], int n, int value);
/*----------------------------------------------------------------------------*/
#endif
