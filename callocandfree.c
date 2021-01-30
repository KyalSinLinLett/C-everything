#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, *ptr, sum=0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) calloc(n, sizeof(int));

    // if cannot allocate memory
    if (ptr == NULL)
    {
        printf("Memory cannot be allocated.");
        exit(0);
    }

    for (i=0; i < n; ++i)
    {
        printf("Enter element[%d/%d]: ", (i+1), n);
        scanf("%d", ptr+i);
        sum += *(ptr+i);
    }

    printf("Sum = %d\n", sum);

    return 0;
}