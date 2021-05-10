/* The file defines all the functions to be used the program */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "header.h"


int initialSize = 15,  maxSize;

int openTime, period, twoHours;
long currentTime, last, prevID;

patient *next15, *queue;


/**
 * Initialized values needed for the program
 * @returns nothing
 ******************************************/
void initialize()
{
    int i;
    for (i = 0; i < patient_count; i++)
    {
	patients[i].served = 0;
    }
    
    maxSize = 15;
    last = 0;
    period = 15;
    twoHours = period * 8;
    openTime = (7 * 60) + 30;
    currentTime = openTime + period;
    prevID = 0;
    
    queue = malloc(patient_count * sizeof(patient));
}

void enqueue()
{
    int pCount = 0, ready = 0; 
    
    int i, j, k, start, end;
    for (i = 0; i < 10; i++)
    {
	for (j = 0 ; j < 10; j++)
	{
	    if (arrivalTime(patients[j].id) < currentTime)
	    {
		start = j;
		for (k = 0; k < 10; k++)
		{
		    if (arrivalTime(patients[k].id) >= currentTime)
		    {
			end = k;
			break;
		    }
		}
	    }
	}
	currentTime += period;
    }

}


long arrivalTime(int id)
{
    int i = 0, minutes;
    long time;
    while (patients[i].id != id)
    {
	i++;
    }
    minutes = patients[i].minutes + round(((float)patients[i].seconds/60));
    time =  (patients[i].hour * 60) + minutes; 
    return time;
}


void sortNext15(int numOfPatients)
{
    int i, j;
    for (i = 0; i < numOfPatients; i++)
    {
	for (j = 0; j < numOfPatients; j++)
	{
	    if (next15[i].pain > next15[j].pain)
	    {
		swap(i, j);
	    }
	}
    }
}

void reset()
{
    int i;
    for (i = 0; i < 10; i++)
    {
	next15[i].id = 0;
    }
}

void swap(int i, int j)
{
    patient tmp = next15[i];
    next15[i] = next15[j];
    next15[j] = tmp;
}

void printq()
{
    int i = 0;
    printf("QUEUE\n");
    while(i < last)
    {
	i++;
	printf(
	    "%02d:%02d:00 Patient: ID = %d\n",
	    queue[i].hour, queue[i].minutes, queue[i].id);
	/* printf( */
	/*     "%02d:%02d:%02d Patient: ID = %d, Pain Level (1-10) = %d, Age = %d years, Time waiting = %d\n", */
	/*     queue[i].hour, queue[i].minutes, queue[i].seconds, */
	/*     queue[i].id, queue[i].pain, queue[i].age, queue[i].waitTime); */
    }
}

void printp(int id)
{
    int i = 0;
    while (patients[i].id != id)
    {
	i++;
    }

    printf("%-4d%-4d%-4d previd: %ld\n", patients[i].id, patients[i].pain, patients[i].age, prevID);
}

