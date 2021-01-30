#include <stdio.h>

int main(void)
{
    int a = 0; 
    scanf("%i", &a); // input is 017 (octal of 15 ) 
    printf("%d\n", a); 
    scanf("%i", &a); // input is 0xf (hexadecimal of 15 ) 
    printf("%d\n", a); 

    return 0;
}