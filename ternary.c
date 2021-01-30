#include <stdio.h>

int main(void)
{
    char ch;
    int i, j, min;

    do
    {
        // ask for input
        printf("\nEnter a number: ");
        scanf("%d", &i);

        printf("Enter another number: ");
        scanf("%d", &j);

        // using ternary operator to find minimun number
        min = (i < j) ? i : j;

        printf("The minimum is: %d\n", min);

        // prompt to try again. terminates if 'n'
        printf("Try again?(y/n): ");
        scanf('%c', &ch);

    } while (ch != 'n');
    
    return 0;
}