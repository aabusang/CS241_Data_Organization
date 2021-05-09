/* The file defines all the functions to be used the program */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"
#include "header.h"

int initialSize = 15;
int maxSize = 0, last = -1;
int position = 0;
int openTime = ((7*60*60) + (30*60));
int period = 15 * 60;
int twoHours;
long currentTime;

patient *next15;
patient *queue;

/**
 * Initialized served and wait_time of patients to 0
 * @returns nothing
 ***/
void initialize()
{
  twoHours = period * 8;
  currentTime = openTime + period;
  
    int i;
    for (i = 0; i < patient_count; i++)
    {
	patients[i].served = 0;
    }
}

void enqueue()
{
    int size = 0, maxSize = 15;
    next15 = NULL;
    int i, j, ready = 0;
    int servedCount = 0;
    for (i = 0; i < patient_count; i++)
    {
	j = servedCount;
	for ( ; j < patient_count; j++)
	{   
	    if (arrivalTime(j) <= currentTime)
	    {
		if (ready == 0)
		{
		    
		    next15 = malloc(maxSize * sizeof(patients));
		}
		if (size++ >= maxSize)
		{
		    maxSize += maxSize/2;
		    patient *tmp = realloc(next15, maxSize*sizeof(patient));
		    if (tmp == NULL) return;
		    next15 = tmp;
		    free(tmp);
		}
		if (patients[j].served == 0)
		{
		    addToNext15(j);
		    /* ready++; */
		}
	    }
	}
	if (ready > 0)
	{
	    /* sortNext15(ready); */
	    next15[0].served = 1;
	    next15[0].waitTime = (currentTime - arrivalTime(next15[0].id));
	    /* addToFinalList(next15[0]); */
	    /* printNext15(ready); */
	    servedCount++;
	    ready = 0, size = 0, last = -1,  maxSize = 15;

	    free(next15);
	}
	currentTime += period;
    }
}

void addToNext15(int patientIndex)
{
    if (last == -1)
    {
	last = 0;
    }
    else
    {
	++last;
    }
    next15[last] = patients[patientIndex];
}

void printNext15(int size)
{

    int i = 0;
    printf("BATCH, size: %d\n", size);
    printf("SERVED: %02d: time: %02d:%02d:%02d: ID: %d Pain: %d Age: %d Served: %d\n",
	   i, next15[i].hour,next15[i].minutes, next15[i].seconds,
	   next15[i].id, next15[i].pain, next15[i].age, next15[i].served);
    
    while(i < size)
    {
	printf("%02d time: %02d:%02d:%02d: Id: %d Pain: %d Age: %d Served: %d\n",
	       i, next15[i].hour,next15[i].minutes, next15[i].seconds,
	       next15[i].id, next15[i].pain, next15[i].age, next15[i].served);
	i++;
    }
    printf("\n");
}

void sortNext15(int numOfPatients)
{
    int i, j;
    int pain1, pain2, age1, age2;
    for (i = 0; i < numOfPatients; i++)
    {
	for (j = 0; j < numOfPatients; j++)
	{
	    pain1 = next15[i].pain;
	    pain2 = next15[j].pain;
	    age1 = next15[i].age;
	    age2 = next15[j].age;

	    if (pain1 > pain2)
	    {
		swap(i, j);
	    }
	    else if ((pain1 == pain2) && (pain1 < 10 && pain2 < 10))
	    {
		/* if (longerThan2Hours(i) */
		if (age1 > age2)
		{
		    swap(i, j);
		}
		if (age1 == age2)
		{
		    /* consider arrival time */
		    if (arrivalTime(i) < arrivalTime(j))
		    {
			swap(i, j);
		    }
		}
	    }
	}
    }
    
}

void addToFinalList(patient next)
{
    queue = malloc(patient_count * sizeof(patient));
    queue[position++] = next;
}

/**
 *This functio checks if a patient have been waiting
 *for more than two hours;
 * @param i: index of the patient;
 ********************************************/
/* int longerThan2H(int i) */
/* { */
/*     int block =  arrivalTime(i) - openTime; */
/*     if ((block > twoHours) && (notYetServed(i) == 1)) */
/*     { */
/* 	return 1; */
/*     } */
/*     /\* if longer than 2 hours we go and look at the last patient *\/ */
/*     /\* with a pain level of 10 who has not been served yet */
/*      *and place this patien behind them *\/ */
/*     return 0; */
/* } */

/**
 *This function returns the arrival;
 * time of a patient in seconds;
 * @param i: index of the patient
 * @return this value of the time in seconds
 ********************************/
long arrivalTime(int id)
{
    int i = 0;
    while (patients[i].id != id)
    {
	i++;
    }
    return ((patients[i].hour * 60 * 60) +
	    (patients[i].minutes * 60) + patients[i].seconds);
}

/**
 *This function swaps the position of two patients;
 *@param i: the index of the first of the two patients being compared;
 *@param j: the index of the second patient being compared;
 *@returns: nothing
 ********************************************************/
void swap(int i, int j)
{
    patient tmp = next15[i];
    next15[i] = next15[j];
    next15[j] = tmp;
}

