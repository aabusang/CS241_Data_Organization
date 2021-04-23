#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"


int **maze;
int **path;
int **memoized;

int N;
int last, numOfCalls, memo;

int main(void)
{
  size_t maxSize = 4 * sizeof(int);
  int *buffer = malloc(maxSize);
  int *newBuffer;
  
  size_t length = 0;
  int c, i, j, k = 0;
  numOfCalls = 0;
  memo = 0;
  
  if (buffer == NULL)
  {
    printf("Out of space\n");
    return 1;
  }
  while((c = getchar()) != EOF)
  {
    if (c == '1' || c == '0')
    {
      if ((length*4) == maxSize)
      {
	newBuffer = realloc(buffer, maxSize *=2);
	if (newBuffer == NULL)
	{
	  printf("Computer is out of memory\n");
	  free(buffer);
	  return 1;
	}
	buffer = newBuffer;
      }
      buffer[length] = myAtoi(c);
      length++;
    }
  }
  
  N = sqroot(length);
  
  /* allocated memory for maze path and checked arrays */
  maze = calloc(N, sizeof(int *));
  path = calloc(N, sizeof(int *));
  memoized = calloc(N, sizeof(int *));
  if (maze == NULL || path == NULL || memoized == NULL)
  {
    printf("Out of space\n");
    return 1;
  }

  i = 0, j = 0, k = 0;  
  for(i = 0; i < N; i++)
  {
    maze[i] = calloc(N, sizeof(int *));
    path[i] = calloc(N, sizeof(int *));
    memoized[i] = calloc(N, sizeof(int *));
    for(j = 0; j < N; j++)
    {
      maze[i][j] = buffer[k++];
      path[i][j] = 0;
      memoized[i][j] = 0;
    }
  }

  /* check for path */
  last = N - 1;
  if (findPath(0, 0) == 1)
  {
    printf("PATH FOUND!\n");
    printPath();
  }
  else
  {
    printf("no path found.\n");
  }

  /* printf("Calls: %d Memo: %d\n", numOfCalls, memo); */
  /* free all allocated memory */
  free(buffer);
  for (i = 0; i < N; i++)
  {
    free(maze[i]);
    free(path[i]);
    free(memoized[i]);
  }
  free(maze);
  free(path);
  free(memoized);
  
  return 0;
}
