/************************************************************************                                                                   
 * Fatima Adawee                                                                                                                            
 * project 8                                                                                                                                
 * This project organizes how pateints should be seen according to certain                                                                  
 * set of rules                                                                                                                              ************************************************************************/


#include "header.h"


/*****************************************
* struct t, int h, int m, and int s
* This function does not return any value (void)
* This function initializes time
*****************************************/

void startTime(Time* t,int h,int m,int s){
  t->hours = h;
  t->minutes = m;
  t->sec = s;
}


/**************************************************                                                          
* struct out, struct t, int mode                                                                 
* This function does not return any value (void)                                                    
* This function takes time and print it on the file 
* with requested format. There are two modes :: and hms.                                                                    
******************************************************/

void showTime(FILE* out,Time t,int mode){
  if(t.hours<10 && t.minutes < 10 && t.sec < 10){
    if(mode == 0){
      fprintf(out,"0%d:0%d:0%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"0%dh0%dm0%ds\n",t.hours,t.minutes,t.sec);
    }
  }
  else if(t.hours<10 && t.minutes < 10){
    if(mode == 0){
      fprintf(out,"0%d:0%d:%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"0%dh0%dm%ds\n",t.hours,t.minutes,t.sec);
    }
		
  }
  else if(t.hours<10 && t.sec < 10){
    if(mode == 0){
      fprintf(out,"0%d:%d:0%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"0%dh%dm0%ds\n",t.hours,t.minutes,t.sec);
    }
  }
  else if(t.minutes<10 && t.sec < 10){
    if(mode == 0){
      fprintf(out,"%d:0%d:0%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"%dh0%dm0%ds\n",t.hours,t.minutes,t.sec);
    }
  }
  else if(t.hours<10){
    if(mode == 0){
      fprintf(out,"0%d:%d:%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"0%dh%dm%ds\n",t.hours,t.minutes,t.sec);
    }
  }
  else if(t.minutes<10){
    if(mode == 0){
      fprintf(out,"%d:0%d:%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"%dh0%dm%ds\n",t.hours,t.minutes,t.sec);
    }
  }
  else if(t.sec < 10){
    if(mode == 0){
      fprintf(out,"%d:%d:0%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"%dh%dm0%ds\n",t.hours,t.minutes,t.sec);
    }
  }
  else{
    if(mode == 0){
      fprintf(out,"%d:%d:%d",t.hours,t.minutes,t.sec);
    }else{
      fprintf(out,"%dh%dm%ds\n",t.hours,t.minutes,t.sec);
    }
  }
}




/**************************************************                                                                                 
* struct Patient p                                                                                                  
* This function does not return any value (void)                                                                                    
* This function prints patient data (function for debugging)                                                                            
*                                                                                                                                   
******************************************************/
void showPatientData(Patient* p){
  if(p == NULL) return;
  printf(" Patient: ID = %2d,  Pain Level (1-10) = %2d, Age = %2d years, Time waiting = ",
	 p->id,p->painLevel,p->age);
  showTime(stdout,p->waitingTime,1);
}



/*********************************************************************                                                                                                         
* struct Patient p, struct out                                                                                                                                                 
* This function does not return any value (void)                                                                                                                               
* This function stores patient data in the file, it also calls the showTime function                                                              
****************************************************************************/
void storePatientData(FILE* out,Patient* p){
  if(p == NULL) return;
  fprintf(out," Patient: ID = %d, Pain Level (1-10) = %d, Age = %d years, Time waiting = ",
	  p->id,p->painLevel,p->age);
  showTime(out,p->waitingTime,1);
}



/*********************************************************************                                                                                                         
* Queue queue                                                                                                                                     
* This function does not return any value (void)                                                                                                  
* This function  prints patients in the Queue, (function for debugging)
                                                                                                                                                                              
****************************************************************************/
void showData(Queue* queue){
  Patient* cursor = queue->start;
  while(cursor != NULL){
    showPatientData(cursor);
    cursor = cursor->next;
  }
}



/*********************************************************************                                                                                                         
* Queue queue                                                                                                                                     
* This function does not return any value (void)                                                                                                  * This funtion prints all patients using showPatientData function                                                                                                                                                                                                                                                                                          
****************************************************************************/

void showData2(Patient* patients[],const int size){
  int i;
  for( i =0; i<size; i++){
    showPatientData(patients[i]);
  }
}


/***********************************************
 * This function returns a queue 
 * This function is an extra funtion to initialize Queue
 *********************************************/

Queue* initQueue(){
  Queue* queue = (Queue*) malloc(sizeof(Queue));
  if(queue == NULL) return NULL;
  
  queue->start = NULL;
  queue->end = NULL;
  queue->pCount = 0;
  
  return queue;
}



/***************************************************
 * int id, struct time, int age, int painLevel
 * This funtion returns a sturct type, patient
 * This funtion is an extra function to initialize the patient.
 **********************************************************/

Patient* initPatient(int id,Time time,int age,int painLevel){
  Patient* patient = (Patient*) malloc(sizeof(Patient));
  patient->id = id;
  patient->painLevel = painLevel;
  patient->age = age;
  
  startTime(&patient->arrivalTime, time.hours,time.minutes,time.sec);
  startTime(&patient->waitingTime,0,0,0);
  
  patient->next = NULL;
  
  return patient;
}



/**********************************************************************
 * Queue queue, struct pateint 
 * This function does not return anything (void)
 * This function is an extra funtion to add the patient in the ready Queue.
 **************************************************************/

void enqueue(Queue* queue, Patient* patient){
  /*printf("********** Adding the patient*******\n")*/;
  if(queue->start == NULL){
    queue->start = patient;
    queue->end = patient;
    queue->pCount++;
  }
  else if(queue->start->id == queue->end->id){
    queue->start->next = patient;
    queue->end = patient;
    queue->pCount++;
  }
  else{
    queue->end->next = patient;
    queue->end = patient;
    queue->pCount++;
  }
}


/***************************************************************                                                                                  
 * Struct time                                                                                                                                    
 * This function does not return anything (void)
 * This function is an extra function to update time
 **********************************************************/

void updateTime(Time* time){
  time->sec++;
  if(time->sec >= 60){
    time->sec = time->sec%60;
    time->minutes++;	/* minute is added*/
    
    if(time->minutes >= 60){
      time->minutes = time->minutes%60;
      time->hours++; /* hour is added*/
    }
  }
}





/**********************************************************************************
 * Queue queue
 * This function does not return anything (void)
 * This function  updates the time for all the patients in the ready Queue. It call updateTime function
 **************************************************************************************/

void updateWaitingTime(Queue* queue){
  Patient* patient;
  if(queue == NULL) return;
	
  patient = queue->start;
	
  while(patient != NULL){
    updateTime(&patient->waitingTime);
    patient = patient->next;
  }
}



/*********************************************************************************
 * Queue queue, struct patient
 * This function does not return anything (void)
 * This function removes the patient from the ready Queue. It is called in the getNext function. 
 *********************************************************************************/

void dischargePatient(Queue* queue,Patient* patient){
  /*printf("************** Discharge Patient************\n");*/
  Patient* cursor;
  Patient* prev;
  if(patient == NULL || queue == NULL) return;
  
  cursor = queue->start;
  prev = NULL;
  /* traverse and find the patient*/
  while(cursor != NULL && cursor->id != patient->id){
    prev = cursor;
    cursor = cursor->next;
  }
  if(cursor == queue->start && cursor != NULL){
    queue->start = cursor->next;
    cursor->next = NULL; /*cursor is selected, break the connection with the its next node*/
  }
  else if( cursor != NULL && cursor->id == queue->end->id){
    queue->end = prev;	/* move end to backward*/
    prev->next = NULL; /* assign NULL to next of this*/
  }
  else if(cursor != NULL){ /* found the patient*/
    prev->next = cursor->next;
    cursor->next = NULL; /*cursor is selected, break the connection with the its next node*/
  }
}



/*****************************************************************************
 * struct patient
 * This function returns an int value
 * This function Return 1 of waiting time is more than 2 hours, 0 otherwise.
 *****************************************************************************/

int tooLate(Patient* patient){
  /*printf("********* To Late ************\n");*/
  int flag = 0;
  if(patient->waitingTime.hours > 2){
    flag = 1;
  }
  else if(patient->waitingTime.hours == 2 &&
	  patient->waitingTime.minutes > 0 ){
    flag = 1;
  }
  else if(patient->waitingTime.hours == 2 &&
	  patient->waitingTime.minutes == 0 &&
	  patient->waitingTime.sec >0 ){
    flag = 1;
  }
  
  return flag;
}



/***********************************************************************************
 * struct source, struct target
 * This function returns an int value
 * This function return 1 if source has arrived first, 0 otherwise.
 **********************************************************************************/

int arriveBefore(Time source,Time target){
  /*printf("**************Arrived Before **********\n");*/
  int flag = 1;
	
  if(target.hours < source.hours){	/* if hours are less*/
    flag  = 0;
  }
  else if(target.hours == source.hours &&
	  target.minutes < source.minutes){	/* if hours are equal but minutes are less*/
    flag  = 0;
  }
  else if(target.hours == source.hours &&
	  target.minutes == source.minutes &&
	  target.sec < source.sec){	/* if hours and minutes are equal but sec are less*/
    flag  = 0;
  }
  else if(target.hours == source.hours &&
	  target.minutes == source.minutes &&
	  target.sec == source.sec){	/* if arrival time is same*/
    flag  = 0;
  }
			
  return flag;
}




/************************************************************
 * Queue queue
 * This function returns a struct type
 * This function Traverse the ready queue and find the patient using the  rules.
 ******************************************************************/

Patient* getNext(Queue* queue){
  /*printf("************ getNext **************\n");*/
  Patient* myTurn = queue->start;			/* to save reference of requested patient*/
  Patient* cursor = queue->start;			/* to traverse the list*/
	
  while( cursor!= NULL ){
    if(cursor->painLevel == 10){
      myTurn = cursor;
      break;
    }
    else if((!tooLate(myTurn)) && tooLate(cursor)){	/* waited more than 2 hours*/
      myTurn = cursor;
    }
    else if((!tooLate(myTurn)) && (cursor->painLevel > myTurn->painLevel)){
      
      myTurn = cursor;
    }
    else if((!tooLate(myTurn)) && cursor->painLevel == myTurn->painLevel &&
	    cursor->age > myTurn->age)
    {
      
      myTurn = cursor;
    }
    else if((!tooLate(myTurn)) && cursor->painLevel == myTurn->painLevel &&
	    cursor->age == myTurn->age &&
	    arriveBefore(cursor->arrivalTime,myTurn->arrivalTime)) /*means cursor arrived first*/
    {
      myTurn = cursor;
				}
    cursor = cursor->next;	
  }

  
  dischargePatient(queue,myTurn);	/* remove the patient from the ready queue*/
  return myTurn;
}




/*******************************************************************
 * struct arrivaltime, struct currentTime
 * This function returns an int value
 * This function checks if arrival time is less than the current time.
 ***************************************************************/

int isArrived(Time arrivalTime,Time currTime){
  /*printf("*********** Is Arrived ************\n");*/
	
  if(arriveBefore(arrivalTime,currTime)){
    return 1;
  }
  else return 0;
}



/****************************************************************************************
 * struct out, Queue source, constant int no_patients
 * This function does not return anything (void)
 * This function manages the scheduling of all the patients until all patients are processed.
 * We create readyQueue and add all the patients which has arrived right now (clock time).
 * Request the patient when the check up time arrives.
 * remove the patient and deallocate the memory.
******************************************************************************************/

void processPatients(FILE* out,Queue* source,const int no_patients){
  /*printf("************ Process Patients ****************\n");*/
  Queue* readyQueue = initQueue();
  Time clock;
  Time nextTurn;
  int processed = 0;
  
  startTime(&clock,7,30,0);
  startTime(&nextTurn,7,45,0);
	
		
  do{
    updateTime(&clock);
    updateWaitingTime(readyQueue);
		
    /* Oppoint time arrived*/
    if(clock.hours == nextTurn.hours && clock.minutes == nextTurn.minutes && clock.sec == nextTurn.sec){
      Patient* patient = getNext(readyQueue);	/* get the patient*/			
			
      
      /*Have patient to process*/
      if(patient){
	
	/*store data in the file*/
	showTime(out,clock,0);	/* 0 means h:m:s formate*/
	storePatientData(out,patient);
	processed++;
				
	free(patient);	/* free the memory*/
      }
      
      nextTurn.minutes +=15;  /* next check up time*/
      if(nextTurn.minutes >= 60){
	nextTurn.minutes = nextTurn.minutes % 60;
	nextTurn.hours++;
      }
    }
		
    /* check if any patient has arrived then add it into the readyQueue, remove it from source.*/
    
    while(source->start != NULL && isArrived(source->start->arrivalTime,clock)){
      enqueue(readyQueue,source->start);
      updateTime(&source->start->waitingTime);
      dischargePatient(source,source->start);
    }
  }while(processed < no_patients);	/* until all patients have been processed*/
  free(readyQueue);
}

/*******************************************************************************
 * Queue queue
 * This function does not return anything (void)
 * This function free the memory from queue
 *****************************************************************************/

void clear(Queue* queue){
  if(queue){
    Patient* cursor;
    cursor = queue->start;
    while(cursor!= NULL){
      Patient* delMe = cursor;
      cursor = cursor->next;
      
      free(delMe);
    }
    free(queue);
  }
}

