#include <stdio.h>
#include <math.h>

int main(void)
{
    int time = 465;
    int hour = time/60;
    int minutes = time%60;

    printf("Time: %d hour: %d minutes: %d\n", time, hour, minutes);
}
