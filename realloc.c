#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, *ptr, n1, n2;

    printf("Enter size: ");
    scanf("%d", &n1);

    ptr = (int*) malloc(n1 * sizeof(int));

    // addresses of initial allocated memory
    printf("Addresses of previously allocated memory.\n");
    for (i=0; i < n1; ++i)
        printf("%p\n", ptr+i);

    printf("Enter new size: ");
    scanf("%d", &n2);

    // reallocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));

    // addresses of initial allocated memory
    printf("Addresses of reallocated memory.\n");
    for (i=0; i < n2; ++i)
        printf("%p\n", ptr+i);

    free(ptr);

    return 0;
}