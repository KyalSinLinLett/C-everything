#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float* ptr;
    ptr = (float*)malloc(100 * sizeof(float));

    printf("%f", *ptr);

    return 0;
}