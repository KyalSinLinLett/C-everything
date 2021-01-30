/*
Assignment 2 - Day 2 - 10/1/2021
Datatypes and operators lesson 
Extra assignment
*/

#include <stdio.h>

int main(void)
{
    int operand1, operand2;
    char operator;

    printf("Pick an operator[+ - * / %%]: ");
    scanf("%c", &operator);

    printf("\nEnter num1 and num2[i.e 10 5]: ");
    scanf("%d %d", &operand1, &operand2);

    if (operator == '+')
        printf("\nThe result is: %d\n", operand1 + operand2);
    else if (operator == '-')
        printf("\nThe result is: %d\n", operand1 - operand2);
    else if (operator == '*')
        printf("\nThe result is: %d\n", operand1 * operand2);
    else if (operator == '/')
        printf("\nThe result is: %d\n", operand1 /  operand2);
    else if (operator == '%')
        printf("\nThe result is: %d\n", operand1 % operand2);
    else
        printf("\nInvalid operator!\n");

    return 0;
}