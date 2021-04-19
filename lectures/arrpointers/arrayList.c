#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char *string[1];
    struct Node *next;
}node;

node *head = NULL;

int main(void)
{
    int i;
    int *numbers = malloc(4 * sizeof(int));
    
    for (i = 0; i < 4; i++)
    {
	numbers[i] = i * 3;
    }

    for (i = 0; i < 4; i++)
    {
	printf("%d ", numbers[i]);
    }
    printf("\n");
}

    
