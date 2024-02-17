/* declare all the functions to be used in main here and other global variables */

#ifndef HEADERFILE_H
#define HEADERFILE_H

extern int **maze;
extern int **path;
extern int **memoized;
extern int N;
extern int last;
extern int numOfCalls;
extern int memo;



int myAtoi(char);
int sqroot(int);
int findPath(int, int);
void printPath();

#endif
