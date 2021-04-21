#include <stdio.h>
#include <math.h>

#define N 100
struct Point
{
    int x[N];
    int y[N];
}pt;

int main(void)
{
    double distance;

    int a = 0, b = 0;
    int c = 0;
    int d = 0;
    printf("Point 1: ");
    scanf("%d %d", &pt.x[0], &pt.y[0]);
    printf("Point 2: ");
    scanf("%d %d", &pt.x[1], &pt.y[1]);
    
    int xValue = pt.x[1] - pt.x[0];
    int yValue = pt.y[1] - pt.y[0];

    distance = sqrt(pow(xValue, 2) + pow(yValue, 2));
    printf("Point1: (%d, %d)\n", pt.x[0], pt.y[0]);
    printf("Point2: (%d, %d)\n", pt.x[1], pt.y[1]);
    printf("Distance: %.2f\n", distance);
}
