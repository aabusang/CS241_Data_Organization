#include <stdio.h>
#include <stdbool.h>

int numbers[4][4];

bool pathFound(int rowIndex, int colIndex);

int main(void)
{
    numbers[4][4] = {{1, 1, 1, 0},
		       {0, 0, 1, 1},
		       {1, 0, 1, 1},
		       {0, 0, 0, 1}};
    int i, j;
    for (i = 0; i < 4; i++)
    {
	for (j = 0; j < 4; j++)
	{
	    printf("%d ", numbers[i][j]);
	}
	printf("\n");
    }
    /* if (pathFound(0, 0)) */
    /* { */
    /* 	printf("Found\n"); */
    /* } */
    /* else */
    /* { */
    /* 	printf("Not Found\n"); */
    /* } */
}

bool pathFound(int rowIndex, int colIndex)
{
    int i = rowIndex, row;
    int j = colIndex, col;
    if (numbers[i][j] == 0)
    {
	return false;
    }
    else
    {
	if (numbers[i][j + 1] == 1) /*if right neighbor is 1*/
	{
	    /*return a call to pathFound on that index*/
	    row = i;
	    col = j+1;
	    return pathFound(row, col);
	}
	else if (numbers[i + 1][j] == 1)
	{
	    row = i+1;
	    col = j;
	    return pathFound(row, col);
	}
	else
	{
	    return false;
	}
    }
}
