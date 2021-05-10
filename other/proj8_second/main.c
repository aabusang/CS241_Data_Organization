/************************************************************************
 * Fatima Adawee
 * project 8
 * This project organizes how pateints should be seen according to certain 
 * set of rules
************************************************************************/
#include "header.h"

int main(int argc, char *argv[] )
{
  FILE *in,*out;
  Queue* queue;
  Patient* patient;
  int count = 0,temp =0;
  char line[255];
 
  /* if command line arguments aren't passed*/
  if(argc < 2){
    in = fopen("arrivals.log","r");
    out = fopen("output.txt","w");
  }
  else{	
   in = fopen(argv[1], "r");
   out = fopen(argv[2],"w");
  }


  if(in == NULL)
  {
    printf("Error while opening the file.\n");
	exit(0);
  }
  
  queue = initQueue();
  while(fgets(line,255,in) != NULL){
    int id =0;
    Time time;
    int age =0;
    int painLevel = 0;
    int i = 0;
	  
    /* Save ID*/
    while(line[i] != ' '){
      id *= 10;
      id += line[i] - '0';
      i++;
    }
    i++; /* ignore the space*/
    
    /* save hours*/
    temp = 0;
    while(line[i] != ':'){
      temp *= 10;
      temp += line[i] - '0';
      i++;
    }
    i++;	/* ignore ':' */
    time.hours = temp;
	  
    /* save minutes*/
    temp = 0;
    while(line[i] != ':'){
      temp *= 10;
      temp += line[i] - '0';
      i++;
    }
    i++;	/* ignore ':' */
    time.minutes = temp;
	  
    /* save seconds */
    temp = 0;
    while(line[i] != ' '){
      temp *= 10;
      temp += line[i] - '0';
      i++;
    }
    i++;	/* ignore ' ' */
    time.sec = temp;
    
    /* Save Age */
    while(line[i] != ' '){
      age *= 10;
      age += line[i] - '0';
      i++;
    }
    i++; /* ignore space */
	  
    /* Save Pain Level*/
    while(line[i] != '\n'){
      painLevel *= 10;
      painLevel += line[i] - '0';
      i++;
    }
    patient = initPatient(id,time,age,painLevel);
    enqueue(queue,patient);
    count++;
  }
  processPatients(out,queue,count);
  clear(queue);
  
  fclose(out);
  fclose(in);
  return 0;
}
