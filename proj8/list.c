/* The file defines all the functions to be used the program */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int openTime = ((7 * 60 * 60) + (30 * 60));
int twoHours = (2 * 60 * 60);
int period = (15 * 60); /*A period if 15 minutes*/
long currentTime = openTime + period;

int recentCount = 0, recentSize = 15;
patient *recent = malloc(recentSize * sizeof(patient));

void sort15MinsBlock()
{
    /* for each 15 minutes block, who was here first? */
    int i;
    int startTime = currentTime - period;
    int endTime = currentTime;
    
    
}
patient getNextPatient(int startTime, int endTime)
{
    patient next;
    
    return next;
}
void calcPriority()
{
    int i, j;
    for (i = 0; i < patient_count; i++)
    {
	for (j = 0; j < patient_count; j++)
	{
	    if (arrivalTime(i) < arrivalTime(j))
	    {
		patients[i].priority++;
	    }
	    if (patients[i].age > patients[j].age)
	    {
		patients[i].priority++;
	    }
	    if (patients[i].pain > patients[j].pain)
	    {
		patients[i].priority += 5;
	    }
	    if (patients[i].waitTime > patients[j].waitTime)
	    {
		patients[i].priority += 5;
	    }
	}
    }
}

void sort2()
{
    int i, j;
    for (i = 0; i < patient_count; i++)
    {
	for (j = 0; j < patient_count; j++)
	{
	    if (patients[i].priority > patients[j].priority)
	    {
		swap(i, j);
	    }
	}
    }
}
void sort()
{
  int i, j;
  int pain1, pain2;
  int age1, age2;
  for (i = 0; i < patient_count; i++)
  {
    for (j = 0; j < patient_count; j++)
    {
      pain1 = patients[i].pain;
      pain2 = patients[j].pain;

      if (pain1 > pain2)
      {
	swap(i, j);
      }
      age1 = patients[i].age;
      age2 = patients[j].age;
      if ((pain1 == pain2) && (pain1 < 10 && pain2 < 10))
      {
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

/**
 *This function checks whether 
 *a patient have been served yet or not;
 * @param i: index of the patient;
 * @returns 1 for served, 0 for not served;
 ****************************************/
int notYetServed(int i)
{
  int timePast =  arrivalTime(i) - openTime;
  int numOfPeriods = timePast/period;
  
  int seconds =  patients[numOfPeriods].seconds;
  int minutes = patients[numOfPeriods].minutes * 60;
  int hour = patients[numOfPeriods].hour * 3600;
  int currentTime = hour + minutes + seconds; 

  int waitTime = arrivalTime(i) - currentTime; 

  if ((waitTime > twoHours) && (numOfPeriods < patients[i].id))
  {
    return 1;  
  }
  return 0;
}

/**
 *This functio checks if a patient have been waiting
 *for more than two hours;
 * @param i: index of the patient;
 ********************************************/
int longerThan2H(int i)
{
  int block =  arrivalTime(i) - openTime;
  if ((block > twoHours) && (notYetServed(i) == 1))
  {
      return 1;      
  }
  /* if longer than 2 hours we go and look at the last patient */
  /* with a pain level of 10 who has not been served yet 
   *and place this patien behind them */
  return 0;
}

/**
 *This function returns the arrival;
 * time of a patient in seconds;
 * @param i: index of the patient
 * @return this value of the time in seconds
 ********************************/
long arrivalTime(int i)
{
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
  patient tmp[1];
  tmp[0].hour = patients[i].hour;
  tmp[0].minutes = patients[i].minutes;
  tmp[0].seconds = patients[i].seconds;
  tmp[0].id = patients[i].id;
  tmp[0].age = patients[i].age;
  tmp[0].pain = patients[i].pain;
  tmp[0].waitTime = patients[i].waitTime;
  tmp[0].priority = patients[i].priority;
  
  patients[i].hour = patients[j].hour;
  patients[i].minutes = patients[j].minutes;
  patients[i].seconds = patients[j].seconds;
  patients[i].id = patients[j].id;
  patients[i].age = patients[j].age;
  patients[i].pain = patients[j].pain;
  patients[i].waitTime = patients[j].waitTime;
  patients[i].priority = patients[j].priority;
  
  patients[j].hour = tmp[0].hour;
  patients[j].minutes = tmp[0].minutes;
  patients[j].seconds = tmp[0].seconds;
  patients[j].id = tmp[0].id;
  patients[j].age = tmp[0].age;
  patients[j].pain = tmp[0].pain;
  patients[j].waitTime = tmp[0].waitTime;
  patients[j].priority = tmp[0].priority;
}

/**
 * Initialized priority and wait_time of patients to 0
 * @returns nothing
 ***/
void initialize()
{
    int i;
    for (i = 0; i < patient_count; i++)
    {
	patients[i].waitTime = 0;
	patients[i].priority = 0;
    }
}


