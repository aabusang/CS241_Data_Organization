/********************
 *Shapes program by Adam Abusang
 *This program prints out 3 different shapes
 *using different special or ASCII characters
 *******************/
#include <stdio.h>

#define SHIFT 9
int main(void)
{
  char m = '-' - SHIFT, us = '_' - SHIFT;
  char bs = '/' - SHIFT, fs = '\\' - SHIFT;
  char cl = ':' - SHIFT, pl = '+' - SHIFT, st = '*' - SHIFT;

  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c            %c\n",
	 m,m,m,m,m,m,m,m,m,m,m,m,m,m,st,st,st,st,pl);
  printf("%c            %c   %c%c%c%c  %c%c%c%c        %c %c\n",
	 cl,cl,st,st,st,st,st,st,st,st,bs,fs);
  printf("%c            %c  %c%c%c%c    %c%c%c%c      %c   %c\n",
	 cl,cl,st,st,st,st,st,st,st,st,bs,fs);
  printf("%c            %c %c%c%c%c      %c%c%c%c    %c     %c\n",
	 cl,cl,st,st,st,st,st,st,st,st,bs,fs);
  printf("%c            %c %c%c%c%c      %c%c%c%c   %c       %c\n",
	 cl,cl,st,st,st,st,st,st,st,st,bs,fs);
  printf("%c            %c  %c%c%c%c    %c%c%c%c   %c         %c\n",
	 cl,cl,st,st,st,st,st,st,st,st,bs,fs);
  printf("%c            %c   %c%c%c%c  %c%c%c%c   %c           %c\n",
	 cl,cl,st,st,st,st,st,st,st,st,bs,fs);
  printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c     %c%c%c%c%c%c%c%c"
	 "%c%c%c%c%c%c%c\n",m,m,m,m,m,m,m,m,m,m,m,m,m,m,st,st,st,st,
	 bs,us,us,us,us,us,us,us,us,us,us,us,us,us,fs);
  return 0;
}
