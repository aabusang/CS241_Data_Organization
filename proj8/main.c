/*
 * By: Adam Abusang
 * A program to queue patients in a clinic
 * considering patients pain level, age, arrival time and wait time
 ******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header.h"

int patient_count = 0;
patient *patients;

int main(int argc, char *argv[])
{
    FILE *inFile, *outFile;
    int i, lineLen = 255;
    int initialSize = 10, currentSize = 0;
    int maxSize = initialSize;
    char line[lineLen];
    patient *tmp;
    patients = malloc(maxSize * sizeof(patient));    
    if (argc != 3)
    {
	printf("Usage: ./main input_file output_file\n");
	return 1;
    }

    inFile = fopen(argv[1], "r");
    if (!inFile)
    {
	printf("File [%s] could not be read in\n", argv[1]);
	return 1;
    }
    

    patient_count = 0;

    while(fgets(line, lineLen, inFile))
    {
	if (currentSize++ >= maxSize)
	{
	    maxSize += (maxSize/2);
	    tmp = realloc(patients, maxSize * sizeof(patient));
	    if (tmp == NULL)
	    {
		printf("Out of memory");
		return 3;
	    }
	    patients = tmp;
	    free(tmp);
	}
	sscanf(line,"%d%d:%d:%d%d%d",&patients[i].id, &patients[i].hour,
	       &patients[i].minutes,&patients[i].seconds,
	       &patients[i].age, &patients[i].pain);
	patient_count++;
	i++;
    }

    /* printf("patient_count: %d\n", patient_count); */
    /* initialize(); */
    /* enqueue(); */

    outFile = fopen(argv[2], "w");
    for (i = 0; i < patient_count; i++)
    {
    	/* fprintf(outFile, */
    	/* 	"%02d:%02d:%02d Patient: ID = %d, Pain Level (1-10) = %d, Age = %d years, Time waiting = %d\n", */
    	/* 	patients[i].hour, patients[i].minutes, patients[i].seconds, */
    	/* 	patients[i].id, patients[i].pain, patients[i].age, patients[i].waitTime); */
    	/* fprintf(outFile, */
    	/* 	"%02d:%02d:%02d Patient: ID = %d, Pain Level (1-10) = %d, Age = %d years, Time waiting = %d\n", */
    	/* 	queue[i].hour, queue[i].minutes, queue[i].seconds, */
    	/* 	queue[i].id, queue[i].pain, queue[i].age, queue[i].waitTime); */
    }

    /* free(patients); */
    fclose(inFile);
    fclose(outFile);

    return 0;
}
