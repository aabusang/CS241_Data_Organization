/* The file defines all the functions to be used the program */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int twoHours = (2 * 60 * 60);
int period = (15 * 60); /*A period if 15 minutes*/

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
	  if (comeFirst(i, j) == 1)
	  {
	    swap(i, j);
	  }
	}
      }
    }
  }
}

int clinicOpenTime()
{
  return ((7 * 60 * 60) + (30 * 60));
}

int notYetServed(int i)
{
  int timePast =  arrivalTime(i) - clinicOpenTime();
  int numOfPeriods = timePast/period;
  /*Current time is the time of the  patient being served right now or 
   *supposed to be served right now, so at index of numOfPeriods;
   *
   **/
  int seconds =  pateints[numOfPeriods].seconds;
  int minutes = patients[numOfPeriods].minutes * 60;
  int hour = patients[numOfperiods].hour * 3600;
  int currentTime = hour + minutes + seconds; /*all are in seconds here*/

  int waitTime = arrivalTime(i) - currentTime; 
  /* patients[i].waitTime = waitTime + (time between the last patient
   *with pain of 10 and this patient)*/
  if ((waitTime > twoHours) && (numOfPeriods < patients[i].id))
  {
    return 1; /* this patient have not been served yet */
  }
  return 0;
}
int longerThan2H(int i)
{
  int block =  arrivalTime(i) - clinicOpenTime();
  if ((block > twoHours) && (notYetServed(i) == 1))
  {
      return 1;      
  }
  /* if longer than 2 hours we go and look at the last patient */
  /* with a pain level of 10 who has not been served yet 
   *and place this patien behind them */
  return 0;
}
long arrivalTime(int i)
{
  return ((patients[i].hour * 60 * 60) +
	  (patients[i].minutes * 60) + patients[i].seconds);
}
int comeFirst(int i, int j)
{
  if (arrivalTime(i) < arrivalTime(j))
  {
    return 1;
  }
  return 0;
}

void swap(int i, int j)
{
  patient tmp[1];
  tmp[0].hour = patients[i].hour;
  tmp[0].minutes = patients[i].minutes;
  tmp[0].seconds = patients[i].seconds;
  tmp[0].id = patients[i].id;
  tmp[0].age = patients[i].age;
  tmp[0].pain = patients[i].pain;
  tmp[0].wait_time = patients[i].wait_time;

  patients[i].hour = patients[j].hour;
  patients[i].minutes = patients[j].minutes;
  patients[i].seconds = patients[j].seconds;
  patients[i].id = patients[j].id;
  patients[i].age = patients[j].age;
  patients[i].pain = patients[j].pain;
  patients[i].wait_time = patients[j].wait_time;

  patients[j].hour = tmp[0].hour;
  patients[j].minutes = tmp[0].minutes;
  patients[j].seconds = tmp[0].seconds;
  patients[j].id = tmp[0].id;
  patients[j].age = tmp[0].age;
  patients[j].pain = tmp[0].pain;
  patients[j].wait_time = tmp[0].wait_time;
}



