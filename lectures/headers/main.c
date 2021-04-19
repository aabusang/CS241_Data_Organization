#include <stdio.h>
#include "header.h"

int a = 4;

int main(void)
{
    printf("a = %d\n", a);
    for (a = 0; a < 3; a++)
    {
	static int b = 1;
	b = foo(b);
	printf("a = %d, b = %d\n", a , b);
    }
    return 0;
}
