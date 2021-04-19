#include <stdio.h>


int main(int argc, char *argv[])
{
  char *argvs;
  int i = 0;
  while(i < argc)
  {
    int len = strlen(argv[i]);
    char first = argv[i][0];
    char last = argv[i][len - 1];

    printf("%d %c %c\n", len, first, last);
  }
  printf("Hello world\n");
  printf("argc: %d\n", argc);
}
