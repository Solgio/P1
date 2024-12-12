#include <stdio.h>

void minimi_termini(int *n, int *d)
{
    if (*d == 0 || *n == 0)
    {
        return;
    }
    int i = 2;
    int min = (*n < *d ? *n : *d);
    while (i < min)
    {
        min = (*n < *d ? *n : *d);
        if (*d % i == 0 && *n % i == 0)
        {
            *d /= i;
            *n /= i;
        }
        else
            i++;
    }
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    minimi_termini(a, b);
    return 0;
}
