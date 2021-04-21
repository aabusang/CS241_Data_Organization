/* define all functions to be used in main here */

#include <stdio.h>
#include <stdbool.h>
#include "header.h"

/*************
 *@param row,the row count of the maze
 *@param col, the colum count of the maze
 *@matrixSize, the size of the matrix - same as N
 *************************************************/
bool findPath(int row, int col, int matrixSize)
{
  int destination = matrixSize - 1;
  if (row ==  destination && col == destination)
  {
    path[row][col] = 1;
    return true;
  }
  /* if I compare maze[row][col] to the integer 1 the program passes all mazes
   *except maze4 with a Sysmalloc: Assertion erro message but when I compare it 
   *to char 1 like '1' it pass only four and fail for the rest of the mazes 
   ************************************************************************/
  if (maze[row][col] == '1')
  {
    /*add position as possible valid path to path array*/
    path[row][col] = 1;

    /* check the right of the current cell if can be visited */
    if (findPath(row, col+1, matrixSize) == true)
    {
      numOfRecCalls++;
      return true;
    }
    /* check the bottom of the current cell if can be visited */
    if (findPath(row+1, col, matrixSize) == true)
    {
      numOfRecCalls++;
      return true;
    }
    /* set back to zero cuz no way forward */
    path[row][col] = 0;
  }

  return false;
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
