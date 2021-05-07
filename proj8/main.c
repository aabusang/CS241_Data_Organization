/*
 * By: Adam Abusang
 * A program to queue patients in a clinic 
 * considering patients pain level, age, arrival time and wait time
 ******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header.h"

patient *patients;
int patient_count;

int main(int argc, char *argv[])
{
    FILE *inFile, *outFile;
    int i, lineLen = 255;
    int initialSize = 10, currentSize = 0;
    int maxSize = initialSize;
    char line[lineLen];

    patients = malloc(maxSize * sizeof(patient));

    /* int *nums = malloc(10 * sizeof(int)) */
    patient *tmp;
    patient_count = 0;

    /* check for the right number of command line arguments */
    if (argc != 3)
    {
	printf("Usage: ./main input_file output_file\n");
	return 1;
    }
    /* open input file for reading */
    inFile = fopen(argv[1], "r");
    if (!inFile)
    {
	printf("File [%s] could not be read in\n", argv[1]);
	return 1;
    }
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
	}
	sscanf(line,"%d%d:%d:%d%d%d",&patients[i].id, &patients[i].hour,
	       &patients[i].minutes,&patients[i].seconds,
	       &patients[i].age, &patients[i].pain);
	patient_count++;
	i++;
    }

    /*initial all 0 starting incremental data of patients*/
    initialize();
    /* sort the patients according hospital rules */
    sort();

    /* write the final queue to the output file */
    outFile = fopen(argv[2], "w");
    for (i = 0; i < patient_count; i++)
    {
	fprintf(outFile,
		"%02d:%02d:%02d Patient: ID = %d, Pain Level (1-10) = %d, Age = %d years, Time waiting = %d\n",
		patients[i].hour, patients[i].minutes, patients[i].seconds,
		patients[i].id, patients[i].pain, patients[i].age, patients[i].waitTime);
    }

    /* close opened files */
    fclose(inFile);
    fclose(outFile);

    return 0;
}
