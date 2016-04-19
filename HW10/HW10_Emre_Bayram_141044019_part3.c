#include"HW10_Emre_Bayram_141044019_part3.h"
#include<string.h>
node_t* make_independent_copy_ll(node_t* head)
{
	node_t *copy,*new;
	new = head;
	while(new == NULL){
		new = malloc(sizeof(node_t));
       	new->app_id = head->app_id;
        new->hour = head->hour;
        new->patient_id = head->patient_id;
        strcpy(new->name,head->name);
        new->history = head->history;
        new = new->next;
		copy = new;
	}
	
	strcpy(copy->name,"kopyaa");
	
	return copy;
}
