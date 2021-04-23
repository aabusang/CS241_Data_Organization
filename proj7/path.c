/* define all functions to be used in main here */

#include <stdio.h>
#include "header.h"


/*************
 *@param row,the row count of the maze
 *@param col, the colum count of the maze
 *@matrixSize, the size of the matrix - same as N
 *************************************************/

int findPath(int row, int col)
{
  if (row ==  last && col == last)
  {
    path[row][col] = 1;
    return 1;
  }
  if (maze[last][last] == 0)
  {
    return 0;
  }
  if (memoized[row][col] == 1)
  {

    return 1;
  }
  memo++;
  /* if I compare maze[row][col] to the integer 1 the program passes all mazes
   *except maze4 with a Sysmalloc: Assertion erro message but when I compare it 
   *to char 1 like '1' it pass only four and fail for the rest of the mazes 
   ************************************************************************/
  
  if (maze[row][col] == 1)
  {
    /*add position as possible valid path to path array*/
    path[row][col] = 1;
    numOfCalls++;
    /* check the right of the current cell if can be visited */
    if (findPath(row, col+1) == 1)
    {
      memoized[row][col] = 1;
      return 1;
    }
    /* check the bottom of the current cell if can be visited */
    if (findPath(row+1, col) == 1)
    {
      memoized[row][col] = 1;
      return 1;
    }
    /* set back to zero cuz no way forward */
    path[row][col] = 0;
  }

  return 0;
}


/* @param ascii is and ascii value to 
 *be converted to decimal int
 * @return the value of @param ascii in to 
 *decimal or as an int 
 ******************************/
int myAtoi(char ascii)
{
  if (ascii == '1')
  {
    return 1;
  }
  else
  {
    return 0;
  }
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
