#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "header.h"


int **maze;
int **path;

int N;
int numOfRecCalls;

int main(void)
{
  int i, j;
  int c;
  int len = 0, k = 0;
  int initSize = 10;
  int maxSize = initSize * sizeof(int);
  int *tmp1 = malloc(maxSize);
  int *tmp2;  
  numOfRecCalls = 0;
  
  while((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      continue;
    }
    if (c == '0' || c == '1')
    {
      if ((len * 4) == maxSize)
      {
	maxSize += initSize * sizeof(int);
	tmp2 = realloc(tmp1, maxSize);
	if (tmp2 == NULL)
	{
	  printf("Computer is out of memory\n");
	  free(tmp1);
	  return 1;
	}
	tmp1 = tmp2;
      }
      tmp1[len++] = c;
    }
  }

  N = sqroot(len);
  maze = malloc(sizeof(int *) * N);
  path = malloc(sizeof(int *) * N);
    
  for(i = 0; i < N; i++)
  {
    maze[i] = malloc(sizeof(int) * N);
    path[i] = malloc(sizeof(int) * N);
    for(j = 0; j < N; j++)
    {
      maze[i][j] = tmp1[k++];
      path[i][j] = 0;
    }
  }
  
  if (findPath(0, 0, N) == 1)
  {
    printf("PATH FOUND!\n");
    printPath();
  }
  else
  {
    printf("no path found.\n");
  }
  
  printf("\nN: %d\nRecursive Calls: %d\n",N, numOfRecCalls);
  
  /* free all allocated memory */
  free(tmp1);
  for (i = 0; i < N; i++)
  {
    free(maze[i]);
    free(path[i]);
    /* free(checked[i]); */
  }
  free(maze);
  free(path);
  /* free(checked); */
  return 0;
}


