#ifndef this_header_file
#define this_header_file

struct Patient
{
    int hour;
    int minutes;
    int seconds;
    int id;
    int age;
    int pain;
    int waitTime;
    int waitingPerBlock;
    int priority;
};

typedef struct Patient patient;


extern int patient_count;
extern patient *patients;

/*Major functions*/
void sort15MinsBlock();
void calcPriority();
patient getNextPatient();
void sort();


/*Helper functions*/
void initialize();
long arrivalTime(int i);
int notYetServed(int i);
int longerThan2Hours(int i);
void swap(int i, int j);
#endif
