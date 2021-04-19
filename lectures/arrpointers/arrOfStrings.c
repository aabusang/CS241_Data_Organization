#include <stdio.h>

int main(void)
{
    char *a[2][2]; /*A 2*2 arrays of 4 pointers to strings*/
    char *aa[4];   /*An array of 4 pointers to char **/
    char b[4][20]; /*An array of 4 strings four strings of size 20*/

    int i, j, k;
    for (i = 0; i < 4; i++)
    {
	scanf("%s", b[i]);
	aa[i] = b[i];
    }

    a[0][0] = "hello";
    a[0][1] = "CS";
    a[1][0] = "241";
    a[1][1] = "students";
    /*print all strings that a points to*/
    for (i = 0; i < 2; i++)
    {
	for (j = 0; j < 2; j++)
	{
	    printf("%s ", a[i][j]);
	}
    }
    printf("\n");
    
    /*print first letters of string a points to*/
    for (i = 0; i < 2; i++)
    {
	for (j = 0; j < 2; j++)
	{
	    for (k = 0; k < 1; k++)
	    {
		printf("%c ", a[i][j][k]);
	    }
	}
    }
    printf("\n");

    /*print all strings that aa points to*/
    for (i = 0; i < 4; i++)
    {
	printf("%s ", aa[i]);
    }
    printf("\n");

    /*print all strings that aa points to*/
    for (i = 0; i < 4; i++)
    {
	for (j = 0; j < 1; j++)
	{
	    printf("%c ", aa[i][j]);
	}
    }
    printf("\n");

    /*compare sizes*/

    printf("%lu %lu %lu\n", sizeof(a[0]), sizeof(aa[0]), sizeof(b[0]));
}
