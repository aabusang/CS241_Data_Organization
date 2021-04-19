#include <stdio.h>
#include <stdlib.h>


#define N 11

int main(void)
{
    char *strings[5];

    for (int i = 0; i < 5; i++)
    {
	strings[i] = malloc(N * sizeof(char));
	scanf("%s", strings[i]);
	printf("%s\n", strings[i]);
    }
}
