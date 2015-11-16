#include"HW10_Emre_Bayram_141044019_part2.h"
#define DEBUG
node_t* build_ll(Appointment_t appointments[], int size, const Working_hours_t* hours)
{
	#ifdef DEBUG
	printf("build_ll(appointments,%d,hours)\n",size);
	#endif
	node_t *appo = NULL, *new;
	int i;

	sort_appo(appointments,size);

	for(i=0;i<size;++i)
	{
        if((appointments[i].hour > hours->start) && (appointments[i].hour < hours->end)
           && (search_array(appointments,size,appointments[i].hour) == FALSE))
		{
			#ifdef DEBUG
			printf("appointment_id = %d and hour = %d\n",appointments[i].app_id,appointments[i].hour);
			#endif
            new = malloc(sizeof(node_t));
            new->app_id = appointments[i].app_id;
            new->hour = appointments[i].hour;
            new->patient_id = appointments[i].patient_id;
            new->name[0] = '\0';
            new->history = NULL;
            new->next = appo;
            appo = new;
        }
	}

    return appo;
}
void write_accepted_app(node_t* head, const Files_t* files)
{
	#ifdef DEBUG
	printf("write_Accepted_app(head,files)\n");
	#endif
	int delete;
    FILE *outp;
    outp = fopen(files->accepted_appo_file_n,"w");
    if(outp != NULL){
        delete=delete_appointments(&head,files);
        #ifdef DEBUG
        printf("%d tane list deleted \n",delete);
        #endif
        while(head != NULL){
            fprintf(outp,"%d;%d;%s;%s;%d\n",head->app_id,head->patient_id,head->name,head->history,head->hour);
            head = head->next;
        }
    }
    else {
    	printf("accepted file couldn't opened pls check it !!!\n");
		exit(1);
	}
}
void add_personal_data(node_t* head, const Files_t* files)
{
	int i=0, count=0;
	char dead;
	char name[30];
	char start;
	char *his;
    char *str;
    FILE *inp;
    
    printf("\n\nadd_personel_data function isnot working properly\n\n");
    
	/*
    inp = fopen(files->patients_file_n,"r");
    fseek(inp,10,SEEK_CUR);
	while((head != NULL) && (fscanf(inp,"%c",&start) != EOF))
	{
		if(start == '>' )
			count++;

		switch (count){
			case 4 : fscanf(inp,"%c",&dead);
				while(dead != '<'){
					name[i]=dead;
					fscanf(inp,"%c",&dead);
					++i;
				}
				name[i] = '\0';
				strcpy(head->name,name);
				break;
			case 6 : fscanf(inp,"%c",&dead);
				
				while(dead != '<'){
					his[i]=dead;
					fscanf(inp,"%c",&dead);
					++i;
				}
				his[i] = '\0';
				str = calloc(strlen(his),sizeof(char));
				str = his;
				head->history = str;
				head = head->next;
				break;
		}
		count=count%6;
	}
	*/	
}
int delete_appointments(node_t** head, const Files_t* files)
{
	int count;
	node_t *temp;
	int process = 0;

	int app_id;
	FILE *delete;
	
	delete = fopen(files->delete_file_n,"r");
	temp = (*head);
	if(delete == NULL)
	{
		printf("delete file couldn't opened");
		exit(1);
	}

	while(fscanf(delete,"%d",&app_id) != EOF)
	{
		while((temp != NULL) || (process == 1))
		{
			if(app_id == temp->app_id){
				temp = temp->next;
				free_list((*head));
				++count;
				process = 1;
			}
			else temp = temp->next;
		}
		process = 0;
		temp = (*head);
	}
	
	return count;

}
void free_list(node_t* head)
{
	node_t *prev;

	while(head != NULL)
	{
		free(&head->app_id);
		free(&head->patient_id);
		free(head->name);
		free(head->history);
		free(&head->hour);
		head = head->next;
	}
		free(&head->app_id);
		free(&head->patient_id);
		free(head->name);
		free(head->history);
		free(&head->hour);
}

BOOL search_array(const Appointment_t array[], int n, int value)
{
	int i;
    int count;
	for(i=0;i<n;++i)
		if(value == array[i].hour)
			++count;
    if(count == 2)
        return TRUE;
	return FALSE;
}

void sort_appo(Appointment_t a[], int array_size)
{
	int i, j;
	Appointment_t temp;
    for (i = 0; i < (array_size - 1); ++i)
    {
       	for (j = 0; j < array_size - 1 - i; ++j )
        {
       	    if (a[j].hour > a[j+1].hour)
          	{
                temp = a[j+1];
                a[j+1] = a[j];
     		    a[j] = temp;
       	    }
   		}
	}
}
