#include <stdio.h>

int main(void)
{
  int a = 7;
  char b = 'B';
  void *ptr = NULL;

  *ptr = &a;

  printf("A: %d\n", &ptr);
}
