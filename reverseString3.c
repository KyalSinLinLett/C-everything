#include <stdio.h>
#include <string.h>

void reverse(char str[]);

int main(void)
{
    return 0;
}

void reverse(char str[])
{   
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i];
        str[len - i] = temp;
    }
    printf("%s\n", str);
}