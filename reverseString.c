#include <stdio.h>
#include <string.h>

void reverse(char name[]);

int main(void)
{
    char name[50];  // declare char array
    int n = 5;
    
    printf("Enter a string: ");    // ask for user input
    fgets(name, sizeof(name), stdin);

    printf("Your name in reverse is: ");
    reverse(name);  // invokes the string reverse function

    printf("%d\n", n / 2);

    return 0;
}

// void reverse(char name[])
// {   
//     for (int i = strlen(name); i >= 0; i--)     // begin iteration from the last index
//     {
//         printf("%c", name[i]);  
//     }
//     printf("\n");
// }

// void reverse(char str[])
// {   
//     int l = 0, r = strlen(str)-1;
    
//     while (l < r)
//     {
//         char temp = str[r];
//         str[r] = str[l];
//         str[l] = temp;

//         ++l; --r;
//     }

//     printf("%s\n", str);
// }

void reverse(char str[])
{   
    int len = strlen(str) - 1;

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    puts(str);
}