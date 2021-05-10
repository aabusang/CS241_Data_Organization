/**
 * By: Adam Abusang
 * A program to determine how patients are seen at a hospital
 ******************************************************************/
#include "header.h"

int main(int argc, char *argv[])
{
    
    FILE *inFile, *outFile;
    Queue *queue;
    Patient *patient;
    int count = 0,temp = 0;
    char line[255];

    if (argc == 1)
    {
	inFile = fopen("arrivals.log", "r");
	outFile = fopen("mylist.txt", "w");
    }
    if(argc == 2)
    {
	inFile = fopen(argv[1], "r");
	outFile = fopen("mylist.txt", "w");
    }
    if (argc == 3)
    {
	inFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");
    }

    if(inFile == NULL)
    {
	printf("Could not open %s\n", argv[1]);
	return 2;
    }
  
    queue = initQueue();
    while(fgets(line, 255, inFile))
    {
	int i = 0, id = 0, age = 0;
	int painLevel = 0;
	Time time;
	  
	while(line[i] != ' ')
	{
	    id *= 10;
	    id += line[i] - '0';
	    i++;
	}
	/*increment i to  ignore colons and space*/
	i++; 
	/* hours */
	temp = 0;
	while(line[i] != ':')
	{
	    temp *= 10;
	    temp += line[i] - '0';
	    i++;
	}
	i++;
	time.hours = temp;
	  
	/*minutes*/
	temp = 0;
	while(line[i] != ':')
	{
	    temp *= 10;
	    temp += line[i] - '0';
	    i++;
	}
	i++;
	time.minutes = temp;
	  
	/* seconds */
	temp = 0;
	while(line[i] != ' ')
	{
	    temp *= 10;
	    temp += line[i] - '0';
	    i++;
	}
	i++;
	time.sec = temp;
    
	/* Save Age */
	while(line[i] != ' ')
	{
	    age *= 10;
	    age += line[i] - '0';
	    i++;
	}
	i++;
	  
	/* pain Level*/
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
    
    processPatients(outFile, queue, count);
    clear(queue);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
