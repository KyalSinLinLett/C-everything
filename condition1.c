/*
1. Ask integer input
2. check condition
    -> if 40 pass
    -> if 80 distinction
*/

#include <stdio.h>

int main(void)
{
    int mark;

    printf("Enter a mark: ");
    scanf("%d", &mark);

    if (mark == 40)
        printf("Pass\n");
    else if (mark == 80)
        printf("Distinction\n");
    else
        printf("Bye\n");
      
    return 0;
}
