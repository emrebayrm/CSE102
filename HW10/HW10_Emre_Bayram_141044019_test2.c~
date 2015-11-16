#include<stdio.h>
#include"HW10_Emre_Bayram_141044019_part2.h"

int main(int argc, char *argv[])
{
	int size;
	Appointment_t *appo;
	Working_hours_t hours;
	Files_t files;	
	node_t *link_appo;

	get_main_arguments(argc,argv,&hours,&files);	

	appo = getRequests(&files,&size);

	link_appo = build_ll(appo,size,&hours);

	add_personal_data(link_appo,&files);

	write_accepted_app(link_appo,&files);
	
	delete_appointments(&link_appo,&files);
	
	free_list(link_appo);
	
	return 0;
}
