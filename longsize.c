#include <stdio.h>

int main(void)
{   
    short shortType;
    int intType;
    unsigned long long int longType;
    printf("short: %zu bytes\n", sizeof(shortType));
    printf("int: %zu bytes\n", sizeof(intType));
    printf("long: %zu bytes\n", sizeof(longType));

    return 0;
}
