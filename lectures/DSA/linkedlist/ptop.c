#include <stdio.h>

int main(void)
{
    int a = 100;
    int *pa = &a;
    int **ppa = &pa;

    printf("a: %d *pa: %d **ppa: %d\n", a, *pa, **ppa);
    printf("&a: %p pa: %p *ppa: %p\n", &a, pa, *ppa);
    printf("&pa: %p ppa: %p\n", &pa, ppa);
    printf("&ppa: %p\n", &ppa);
}
