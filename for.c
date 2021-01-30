#include <stdio.h>

int main(void)
{
    int i;
    int c = 1;
    for (i = 10; (i > 0 || c != 1); i--)
    {
        printf("%s%d\n", "Hello ", i);
    }

    return 0;
}