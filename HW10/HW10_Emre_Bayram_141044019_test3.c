#include<stdio.h>
#include"HW10_Emre_Bayram_141044019_part3.h"

void foo(node_t* head, node_t* copy_head){
	
	node_t *h, *cur;
	int prev=0;
	
	h = head; 
	cur = copy_head;
		
	while(h && !prev && cur){
		
		if((h == cur) || (h->history && (h->history == cur->history))){
			
			puts("Pointerlar aynı yeri gösteriyor. Muhtemelen historyler.");
			prev = 1;
		} 
		else if((h->history && cur->history)?strcmp(h->history, cur->history):0
			|| strcmp(h->name, cur->name) || (h->app_id != cur->app_id) 
			|| (h->patient_id != cur->patient_id) || (h->hour != cur->hour)){
			
			puts("Kopyalamada problem var. Veriler aynı değil.");
			prev = 1;
		} 			
		else{
			h = h->next;
			cur = cur->next;
		}
	}
	
	if((h || cur) && !prev){
		
		if(h)
			puts("Kopya liste daha kısa.");
		else
			puts("Orijinal liste daha kısa.");
	}
	
	else if(!prev)
	
		puts("Sorun yok");
	
		puts("");
 }
 
int main (int argc, char *argv[])
{
	int size;
	Appointment_t *appo;
	Working_hours_t hours;
	Files_t files;	
	node_t *link_appo;
	node_t *copy;
	 
	get_main_arguments(argc,argv,&hours,&files);
	
	appo = getRequests(&files,&size);
	
	link_appo = build_ll(appo,size,&hours);

	add_personal_data(link_appo,&files);

	copy = make_independent_copy_ll(link_appo);
	
	foo(link_appo, copy);
}
