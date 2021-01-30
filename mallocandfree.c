#include <stdio.h>
#include <stdlib.h>

/*
This could be the reference code for creating dynamic arrays
*/

int main(void)
{   
    int n, i, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));

    // if memory cannnot be allocated.
    if (ptr == NULL)
    {
        printf("Error! Memory cannot be allocated.");
        exit(0);
    }

    for (i = 0; i < n; ++i)
    {
        printf("Enter element[%d/%d]: ", (i+1), n);
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    printf("Sum = %d\n", sum);

    // deallocating the memory
    free(ptr);

    return 0;
}