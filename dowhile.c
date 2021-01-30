#include <stdio.h>

int main(void)
{
    int n = 0;
    do
    {
        printf("Hello %d\n", n);
        n++;
    } while (n == 10);
    
    return 0;
}