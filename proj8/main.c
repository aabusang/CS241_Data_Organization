#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "header.h"


FILE *inFile, *outFile;
patient patients[MAX_PATIENTS];
int patient_count;

int main(int argc, char *argv[])
{
  int lineLen = 255;
  patient_count = 0;
  int i = 0;    

  char line[lineLen];

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
  /* read input file into struct */
  while(fgets(line, lineLen, inFile))
  {
    sscanf(line,"%d%d:%d:%d%d%d",&patients[i].id, &patients[i].hour,
	   &patients[i].minutes,&patients[i].seconds,
	   &patients[i].age, &patients[i].pain);
    patient_count++;
    i++;
  }

  /* sort the patients according hospital rules */
  sort();

  /* write the final queue to the output file */
  outFile = fopen(argv[2], "w");
  for (i = 0; i < patient_count; i++)
  {
    fprintf(outFile,
	    "%02d:%02d:%02d Patient: ID = %d, Pain Level (1-10) = %d, Age = %d years, Time waiting = %d\n",
	    patients[i].hour, patients[i].minutes, patients[i].seconds,
	    patients[i].id, patients[i].pain, patients[i].age, patients[i].wait_time);
  }

  /* close opened files */
  fclose(inFile);
  fclose(outFile);

  return 0;
}
