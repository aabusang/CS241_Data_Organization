#ifndef header
#define header

struct Patient
{
    int hour;
    int minutes;
    int seconds;
    int id;
    int age;
    int pain;
    int waitTime;
    int served;
};

typedef struct Patient patient;
extern patient *patients;
extern patient *queue;
extern int patient_count;
extern int position;

void initialize();
void enqueue();
long arrivalTime(int id);

void addToNext15(int patientIndex);
void sortNext15(int numOfPatients);
void addToFinalList(patient next);

int longerThan2Hours(int id);
void swap(int i, int j);

void printq();
void printp(int id);
void reset();

extern int openTime;
extern int period;
extern int twoHours;
extern long currentTime;


#endif
