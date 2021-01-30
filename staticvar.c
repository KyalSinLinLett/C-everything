#include <stdio.h>

void display();

int main(void)
{
    display(); // 6
    display(); //11
    return 0;
}

void display()
{
    static int c = 1;
    c += 5;
    printf("%d\n", c);
}