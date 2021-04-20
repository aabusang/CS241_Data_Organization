/* define all functions to be used in main here */

#include <stdio.h>
#include "header.h"

/*************
 *@param row,the row count of the maze
 *@param col, the colum count of the maze
 *@matrixSize, the size of the matrix - same as N
 *************************************************/
int findPath(int row, int col, int matrixSize)
{
  int destination = matrixSize - 1;
  if (row ==  destination && col == destination)
  {
    path[row][col] = 1;
    return 1;
  }

  if (maze[row][col] == 1)
  {
    /* add position as valid path to path array*/
    path[row][col] = 1;

    /* check the right of the current cell if can be visited */
    if (findPath(row, col+1, matrixSize) == 1)
    {
      numOfRecCalls++;
      return 1;
    }
    /* check the bottom of the current cell if can be visited */
    if (findPath(row+1, col, matrixSize) == 1)
    {
      numOfRecCalls++;
      return 1;
    }
    /* set back to zero cuz failed */
    path[row][col] = 0;
  }

  return 0;
}

/******************
 *@param a number to find the square root of
 *@return the square root of number
 *******************************************/
int sqroot(int number)
{
  int i;
  for (i = 0; i < number; i++)
  {
    if ((i * i) == number)
    {
      break;
    }
  }
  return i;
}

/******************
 *@param none
 *@return void
 *prints the values of a maze
 *******************************************/
void printPath()
{
  int i, j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      printf("%d", path[i][j]);
    }
    printf("\n");
  }
}
