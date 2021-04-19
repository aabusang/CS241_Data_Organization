#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char *string, *endPtr;
    long n;

    string = "a1234a";

    n = strtol(string, &endPtr, 10);

    printf("String: %s \nN: %ld \nendPtr_C: %c \nendPtr_S: %s\n", string, n, *endPtr, endPtr);
}
