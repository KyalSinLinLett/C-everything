#include <stdio.h>

void addOne(int* ptr);

int main(void)
{
    int* p, i = 10;
    p = &i;
    addOne(p);
    printf("%d\n", *p);
    printf("%d\n", i);
    printf("&i: %p &p: %p\n", &i, &p);

    return 0;
}

void addOne(int* ptr)
{
    (*ptr)++; 
}