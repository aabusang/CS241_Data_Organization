#ifndef this_header_file
#define thie_header_file

#define MAX_PATIENTS 100

struct Patient
{
  int hour;
  int minutes;
  int seconds;
  int id;
  int age;
  int pain;
  int wait_time;
};

typedef struct Patient patient;


extern patient patients[MAX_PATIENTS];
extern int patient_count;

void sort();
void swap(int i, int j);
long arrivalTime(int i);
int comeFirst(int i, int j);
#endif
