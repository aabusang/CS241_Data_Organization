#include <stdio.h>

struct Point
{
    int x;
    int y;
};

struct Rect
{
    struct Point p1;
    struct Point p2;
}r;

int main(void)
{
    double area;
    
    r.p1.x = 2;
    r.p1.y = 4;

    r.p2.x = 10;
    r.p2.y = 10;

    area = ((double)r.p2.x - r.p1.x * (double)r.p2.y - r.p1.y);

    printf("(%d, %d)\n(%d, %d)\nArea: %.2f\n",
	   r.p1.x, r.p1.y, r.p2.x, r.p2.y, area);
}
