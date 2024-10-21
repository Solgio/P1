#include <stdio.h>

/*
In questo esercizio andrete ad implementare le funzioni principali per calcolare lo shuffle di due numeri naturali (lo shuffle di due interi non-negativi è dato dalla combinazione "interleaving" della loro rappresentazione come stringhe, nel senso seguente).

1) Date due stringhe s1 ed s2, lo shuffle di s1 ed s2 è la stringa ottenuta prendendo un elemento di s1 seguito da uno di s2, in ordine. Quindi se s1 = "abba" ed s2 = "ciao", lo shuffle di s1 con s2 è la stringa "acbibaao". Nel caso una delle due stringhe sia piu' corta dell'altra, lo shuffle continua con la rimanente parte della stringa piu' lunga. Quindi se s1 = "abba" e s2 = "cd", allora lo shuffle sarà "acbdba".
Scrivete una funzione *RICORSIVA* dalla firma
void shuffle(char* s1, char* s2, char* r)
che salva in r lo shuffle di s1 con s2.
Per fare ciò vi potrebbe servire una funzione
copyString(char* s1, char* s2)
che copia la stringa s1 in s2. Scrivete anche questa funzione RICORSIVAMENTE

2) Dato un intero non-negativo n, la sua rappresentazione come stringa è data da "cn-1 .. c00", dove c0...cn-1 è la rappresentazione decimale dell'intero, con ciascuno ci appartenente a {0, ..., 9} (e cn-1 diverso da 0, se n>0---questo per evirare casi come 019, che invece viene scritto solamente come 19).
Quindi se n = 198, allora la sua rappresentazione come stringa sarà "8910". Notare che lavoriamo con l'inverso dell'usuale rappresentazione decimale (questo semplifica le cose) e che alla fine appendiamo uno zero (anche questo semplifica).
Scrivete una funzione RICORSIVA
void intToString(int n, char* s)
che salva in s la rappresentazione di n come stringa. (Tenete conto della PRE per semplificarvi la vita).

Scrivete PRE e POST di ciascuna funzione.
*/

void intToString(int n, char *s)
{
    if (n == 0)
    {
        *s = '0';
        *(s + 1) = '\0';
    }
    else
    {
        intToString(n / 10, *(s + 1));
        s = n % 10 + '0';
    }
}

void copyString(char *s1, char *r)
{
    int i = 0;
    while (*s1 != '\0')
    {
        *(r + i) = *s1;
    }
}

// Recursive function to interleave characters from s1 and s2 into r
void shuffle(char *s1, char *s2, char *r)
{
    if (s1 == '\0' && s2 == '\0')
    {
        return;
    }
    else if (s1 == '\0' && s2 != '\0')
    {
        copyString(*r, s2);
        return;
    }
    else if (s2 == '\0' && s1 != '\0')
    {
        copyString(*r, s1);
        return;
    }
    else
    {
        *r = *s1;
        shuffle(s2, s1 + 1, r + 1)
    }
}

void main()
{
    int num;
    char digits[20];
    scanf("%d", &num);
    intToString(num, digits);

    char s1[10], s2[10], result[20];
    scanf("%s", s1);
    scanf("%s", s2);
    shuffle(s1, s2, result);

    printf("%s\n", digits);
    printf("%s\n", result);
}
