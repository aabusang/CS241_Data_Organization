#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int data;
}node;

int main(int argc, char *argv[])
{
    node *foo = malloc(sizeof(node));
    
    foo->data = 10;
    printf("%d\n", foo->data);
    
    while (argc-->0)
    {
	printf("%d, %s\n",argc, *argv++);
    }
}
