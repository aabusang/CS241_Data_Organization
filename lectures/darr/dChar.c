#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    /* char *names[] = {"Adam", "Rasheed", "Hamid", "Iddi"}; */

    int *numbers = malloc(4 * sizeof(numbers));
    for (i = 0; i < 4; i++)
    {
	printf("Number %d: ", (i+1));
	scanf("%d", &numbers[i]);
    }

    printf("You entered: ");
    for (i = 0; i < 4; i++)
    {
	printf("%d ", numbers[i]);
    }
    printf("\n");
    /* char *names[4]; */
    /* for (i = 0; i < 4; i++) */
    /* { */
    /* 	printf("Name %d: ", (i+1)); */
    /* 	scanf("%s", &names[i]); */
    /* 	printf("\n"); */
    /* } */
    /* for (i = 0; i < 4; i++) */
    /* { */
    /* 	printf("%s\n", *(names + i)); */
    /* } */
}
