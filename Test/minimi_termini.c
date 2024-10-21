#include <stdio.h>

int minimi_termini(int num, int den)
{
    if (num == 0 || den == 0)
    {
        printf("Errore: divisione di zero o per zero\n");
        return 0;
    }

    if (num == 1 || den == 1)
    {
        printf("%d/%d\n", num, den);
    }

    if (num % den == 0)
    {
        printf("%d\n", num / den);
    }

    if (num == den)
    {
        printf("1\n");
        return 1;
    }

    int minimo = num < den ? num : den;
    int i = minimo;
    while (i > 1)
    {
        if (num % i == 0 && den % i == 0)
        {
            num /= i;
            den /= i;
            minimo = num < den ? num/i : den/i;
            i = minimo;
        }
        else
        {
            i--;
        }
    }

    printf("%d/%d\n", num, den);
}

int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    minimi_termini(a, b);
    return 0;
}
