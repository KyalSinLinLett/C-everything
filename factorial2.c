#include <stdio.h>

int fibo(int);

int main(void)
{
    int n;
    printf("Enter a num: ");
    scanf("%d", &n);

    printf("the %dth fibo number is %d", n, fibo(n-1));

    return 0;
}

int fibo(int n)
{   
    if (n <= 1)
        return n;
    else
        return (fibo(n-1) + fibo(n-2));  
}
