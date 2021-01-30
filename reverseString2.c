#include <stdio.h>
#include <string.h>

void reverse(char str[]);

int main(void)
{
    char str[50];  // declare char array
    
    printf("Enter a string: ");    // ask for user input
    fgets(str, sizeof(str), stdin);

    printf("Your name in reverse is: ");
    reverse(str);

    return 0;
}

void reverse(char str[])
{   
    int l = 0, r = strlen(str)-1;
    
    while (l < r)
    {
        char temp = str[r];
        str[r] = str[l];
        str[l] = temp;

        ++l; --r;
    }

    printf("%s\n", str);
}


