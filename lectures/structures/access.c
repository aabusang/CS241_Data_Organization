#include <stdio.h>

/*A structure does not reserve storage
 *it only defines the type of storage
*/
//struct Point {int x; int y};

//This reserves storage
//struct Point pt;

//Alternate syntax definition and instantiating a structure

struct Point
{
    int x;
    int y;
}pt;

int main(void)
{
    pt.x = 10;
    pt.y = 5;
    printf("%d, %d\n", pt.x, pt.y);

    return 0;
}
