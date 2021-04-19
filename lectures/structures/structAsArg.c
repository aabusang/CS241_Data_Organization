#include <stdio.h>

struct Point
{
    int x;
    int y;
}p;

void increamentPointV(struct Point point)
{
    point.x++;
    point.y++;
}

void increamentPointR(struct Point *point)
{
    (*point).x++;
    (*point).y++;
}

int main(void)
{
    struct Point point = {4, 7};
    increamentPointV(point); // no ++ bcos p is passed by value
    printf("p = (%d, %d)\n", point.x, point.y);

    increamentPointR(&point); //R for pass by reference
    printf("p = (%d, %d)\n", point.x, point.y);
}
