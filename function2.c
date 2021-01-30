#include <stdio.h>
#define NUM 30

void printstr(int);

int main(void)
{
    printstr(NUM);

    printf("\n\nHello world\n\n");

    printstr(NUM);

    return 0;
}

void printstr(int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("X");
    }
}