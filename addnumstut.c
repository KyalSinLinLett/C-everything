#include <stdio.h>

int main(void)
{
    int num1, num2;

    printf("Enter num1: ");
    scanf("%d", &num1);

    printf("\nEnter num2: ");
    scanf("%d", &num2);

    printf("\nThe result is: %d\n", (num1+num2));
    
    return 0;
}