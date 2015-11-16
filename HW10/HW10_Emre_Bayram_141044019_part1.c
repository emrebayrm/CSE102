/* 	
	part1.c 
	implemention file
	
						*/
	


#include"HW10_Emre_Bayram_141044019_part1.h"
#define DEBUG
	/*default values of files.*/
	const char *def_records_file_n= "Records.bin";
	const char *def_patients_file_n= "Patients.xml";
	const char *def_delete_file_n= "Delete.txt";
	const char *def_readable_records_file_n= "Records.xml";
	const char *def_accepted_appo_file_n= "Appointments.csv";
	const char *def_parameters_file_n= "Parameters.txt";

Appointment_t* getRequests(const Files_t* files, int* size)
{
	#ifdef DEBUG
	printf("getRequest\n");
	#endif
	Appointment_t temp;
	int i;
	Appointment_t *req;
	FILE *inp;

	inp = fopen(files->records_file_n,"rb");
	if(inp == NULL){
        printf("record file couldn't opened\n");
        exit(1);
	}
	inp = fopen(files->records_file_n,"rb");
	fread(size,sizeof(int),1,inp);
	req = calloc((*size),sizeof(Appointment_t));

	for(i=0; i<(*size); ++i)
	{
		fread(&temp,sizeof(temp),1,inp);
		req[i]=temp;
	}
	fclose(inp);
	return req;
}

void write_appointments(Appointment_t appointments[], int size, const Files_t* files)
{
	#ifdef DEBUG
	printf("write_appointments(appointment,%d,files)\n",size);
	#endif
	int i;
	FILE *outp;

	outp = fopen(files->readable_records_file_n,"w");

	if(outp != NULL){
		fprintf(outp,"<Size>%d</Size>\n",size);
		fprintf(outp,"<Records>\n");
		for(i = 0; i < size; ++i){
			fprintf(outp,"	<Appointment>\n");
			fprintf(outp,"		<app_id>%d</app_id>\n",appointments[i].app_id);
			fprintf(outp,"		<patient>%d</patient_id>\n",appointments[i].patient_id);
			fprintf(outp,"		<hour>%d</hour>\n",appointments[i].hour);
			fprintf(outp,"	</Appointments>\n");
		}
		fprintf(outp,"</Records>");
		fclose(outp);
	}
	else {
		printf("xml file cant opened");
		exit(1);
	}

}

void get_main_arguments(int argc, char *argv[], Working_hours_t* hours, Files_t* files)
{

	int hour;
	char argdesc;
	int i;

	#ifdef DEBUG
	printf("get_main_arguments(%d,",argc);
	for(i = 1 ; i < argc ; i =i + 2)
		printf("%s %s\n			",argv[i],argv[i+1]);
	printf("	,hours,files,)\n");
	#endif
	if((argc % 2 ) == 0 && argc != 1){
		#ifdef DEBUG
		printf("main arguments are wrong pls check them\n");
		#endif
		exit(0);
	}

	/* making default*/
	files->records_file_n = def_records_file_n;
	files->delete_file_n = def_delete_file_n;
	files->readable_records_file_n = def_readable_records_file_n;
	files->accepted_appo_file_n = def_accepted_appo_file_n;
	files->patients_file_n = def_patients_file_n;
	files->parameters_file_n = def_parameters_file_n;
	hours->start = DEF_START_HOUR;
	hours->end	 = DEF_END_HOUR;

	for(i = 1 ; i < argc ;i = i + 2){

		argdesc = argv[i][1];

		switch (argdesc) {
		case 'r' :
			files->records_file_n = argv[i+1];
			break;
		case 'p' :
			files->patients_file_n = argv[i+1];
			break;
		case 'd' :
			files->delete_file_n = argv[i+1];
			break;
		case 'x' :
			files->readable_records_file_n = argv[i+1];
			break;
		case 'c' :
			files->accepted_appo_file_n = argv[i+1];
			break;
		case 't' :
			files->parameters_file_n = argv[i+1];
			break;
		case 's' :
			sscanf(argv[i+1],"%d",&hour);
			hours->start = hour;
			break;
		case 'e' :
			sscanf(argv[i+1],"%d",&hour);
			hours->end = hour;
			break;
		default : printf("You send wrong parameters your options are this :\n -r -p -d -x -c -t -s -e\n");
				printf("pls check and run again \n");
				exit(1);
		}
	}

}

void print_parameters(const Files_t* files, const Working_hours_t* hours)
{
	#ifdef DEBUG
	printf("print_parameters\n");
	#endif

	FILE* param;

	param = fopen(files->parameters_file_n,"w+");
	
	if(param != NULL)
		fprintf(param,"%s %s %s %s %s %s %d %d",files->records_file_n
						  				   ,files->patients_file_n
										   ,files->delete_file_n
 										   ,files->readable_records_file_n
 									 	   ,files->accepted_appo_file_n
 										   ,files->parameters_file_n
 										   ,hours->start
 										   ,hours->end);
 	else {
 		printf("Parameters file couldn't opened \n");
 		exit(1);
	}
	fclose(param);
}

