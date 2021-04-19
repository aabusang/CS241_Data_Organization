#include <stdio.h>

struct Point
{
    int x;
    int y;
}temp;
//struct Point makepoint (int x, int y);

struct Point makepoint (int x, int y)
{
    //struct Point temp;
    temp.x = x;
    temp.y = y;
    return temp; //returning by value
}


int main(void)
{
    struct Point p1 = makepoint(5, 7);
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
}
