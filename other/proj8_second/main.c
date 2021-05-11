/****************
 * By: Adam Abusang
 * A program to determine how 
 * patients are attended to at a clinic
 ***************************************/

#include "header.h"

int main(int argc, char *argv[])
{
  FILE *inFile, *outFile;
  Queue *queue;
  Patient *patient;
  int count = 0,temp =0;
  char line[255];
 
  if (argc == 1)
  {
    inFile = fopen("arrivals.log", "r");
    outFile = fopen("mylist.txt", "w");
  }
  else if (argc < 2)
  {
    inFile = fopen(argv[1],"r");
    outFile = fopen("mylist.txt","w");
  }
  else if (argc == 3)
  {	
    inFile = fopen(argv[1], "r");
    outFile = fopen(argv[2],"w");
  }
  else
  {
    printf("Too many arguments");
  }

  if (!inFile) 
  {
    printf("Unable to open input file arrivals.log");
    return 1;
  }
  
  queue = initQueue();
  while(fgets(line, 255, inFile) != NULL)
  {
    Time time;
    int id = 0, age = 0, i = 0;
    int painLevel = 0;
    // i++ to ignore ':' and ' '
    while(line[i] != ' ')
    {
      id *= 10;
      id += line[i] - '0';
      i++;
    }
    i++; 
    
    
    temp = 0;
    while(line[i] != ':')
    {
      temp *= 10;
      temp += line[i] - '0';
      i++;
    }
    i++;
    time.hours = temp;
	  
    
    temp = 0;
    while(line[i] != ':')
    {
      temp *= 10;
      temp += line[i] - '0';
      i++;
    }
    i++;
    time.minutes = temp;
	  
    temp = 0;
    while(line[i] != ' ')
    {
      temp *= 10;
      temp += line[i] - '0';
      i++;
    }
    i++;
    time.sec = temp;
    
    
    while(line[i] != ' ')
    {
      age *= 10;
      age += line[i] - '0';
      i++;
    }
    i++; 
	  
    while(line[i] != '\n')
    {
      painLevel *= 10;
      painLevel += line[i] - '0';
      i++;
    }

    patient = initPatient(id, time, age, painLevel);
    enqueue(queue, patient);
    count++;
  }
  processPatients(outFile,queue,count);
  clear(queue);

  fclose(inFile);
  fclose(outFile);

  return 0;
}
