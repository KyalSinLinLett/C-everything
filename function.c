#include <stdio.h>
#define PRINTSQR(N) (N)*(N)

void printsqr(int);

int main(void)
{
    int n = 5.0;

    printf("The square of %d is %d.\n", n, PRINTSQR(n));

    return 0;
}

void printsqr(int n)
{
    printf("The square of %d is: %d\n", n, (n*n));
}