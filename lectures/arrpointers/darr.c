#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
  char *darray;
  int i = 1;
  while (i < argc)
  {
    printf("%d, %s\n", i, argv[i]);
    i++;
  }

  i = 0;
  while(i < argc)
  {
    strcpy(darray, argv[i]);
    printf("%s ", darray);
    i++;
  }

  printf("\n");

  return 0;
}
