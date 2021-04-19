#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char a[2][4];
  char *aa[4];

  int i;
  for (i = 0; i < 4; i++)
  {
    aa[i] = malloc(10 * sizeof(char));
    scanf("%s", aa[i]);
    /*aa[i] = a[i];*/
  }

  for (i = 0; i < 4; i++)
  {
    printf("%s\n", aa[i]);
  }
}
