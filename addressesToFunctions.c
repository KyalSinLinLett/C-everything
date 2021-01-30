#include <stdio.h>

void swap(int* n1, int *n2);

int main(void)
{
    int num1 = 5, num2 = 10;

    swap(&num1, &num2); // pass in the addresses of num1 and num2

    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    
    return 0;
}

void swap(int* n1, int* n2)
{
    /*
        int* n1 = &num1 -> int* n1; n1 = &num1;
        so the n1 stores the address of the variable num1
        so when * is used on n1, that is *n1, it points to the value of num1
        then the swapping process is initiated 
        with the actual values of the num1 and num2 swapped.
    */

    int temp = *n2;
    *n2 = *n1;
    *n1 = temp;
}

