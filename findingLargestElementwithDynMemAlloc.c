#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    float* data;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    // allocate memory for number of elements
    data = (float*) calloc(num, sizeof(float));

    // if cannot allocate memory
    if (data == NULL)
    {
        printf("Memory is not allocated.\n");
        exit(0);
    }

    // inserting the values into the allocated memory
    for (int i = 0; i < num; ++i)
    {
        printf("Enter element[%d/%d]: ", (i+1), num);
        scanf("%f", data+i);
    }

    // finding the largest element
    for (int i = 1; i < num; ++i)
    {
        if (*data < *(data + i))
            *data = *(data + i);
    }

    printf("The largest element is: %.2f\n", *data);

    free(data);

    return 0;
}