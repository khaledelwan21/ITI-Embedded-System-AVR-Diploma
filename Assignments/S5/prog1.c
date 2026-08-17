#include <stdio.h>

int main()
{
    int x = 10, y = 20, z = 30;
    int *p = &x, *q = &y, *r = &z;


    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    printf("r = %p\n", r);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);

    printf("\nSwapping pointers.\n\n");


    *r = *p+*q+*r;
    *q = *r-*p-*q;
    *p = *r-*q-*p;
	*r = *r-*q-*p ;

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    printf("r = %p\n", r);
    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);
    printf("*r = %d\n", *r);

    return 0;
}