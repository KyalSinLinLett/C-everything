#include <stdio.h>

int main(void)
{
    int n = 0;
    while (n < 10)
    {
        printf("hello %d\n", n);

        if (n == 3)
        {
            continue;
        }

        n++;
    }


    return 0;
}