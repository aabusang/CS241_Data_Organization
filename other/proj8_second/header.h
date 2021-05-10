#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Time{
  int hours;
  int minutes;
  int sec;
	
} Time;

typedef struct Patient{
  int id;
  int painLevel;
  int age;
  struct Time waitingTime;
  struct Time arrivalTime;
  struct Patient* next;
} Patient;

typedef struct Queue{
  int pCount;
  struct Patient* start;
  struct Patient* end;
} Queue;


void startTime(Time* t,int h,int m,int s);


void showTime(FILE* out,Time t,int mode);


void showPatientData(Patient* p);


void storePatientData(FILE* out,Patient* p);


void showData(Queue* queue);


void showData2(Patient* patients[],const int size);


Queue* initQueue();



Patient* initPatient(int id,Time time,int age,int painLevel);


void enqueue(Queue* queue, Patient* patient);



void updateTime(Time* time);


void updateWaitingTime(Queue* queue);



void dischargePatient(Queue* queue,Patient* patient);


int tooLate(Patient* patient);


int arriveBefore(Time source,Time target);


Patient* getNext(Queue* queue);



int isArrived(Time arrivalTime,Time currTime);



void processPatients(FILE* out,Queue* source,const int no_patients);



void clear(Queue* queue);
#endif /*HEADER_H*/
