
#include <stdio.h>
int x = 12;
int main()
{
    int y = 2;
    int *p;
    {
        int y = 4;
        if (y > 2)
        {
            int x = 2;
            p = &x;
            *p += 8;
            printf("%d\n", x / 4 * 2);
        }
        printf("%d %d\n", x, y);
    }
    printf("%d\n", *p);
}

APPELLO 4 char *rimuovi_doppie(char A[])
{
    int j = 0;
    int i = 0;
    while (A[i + 1] != '\0')
    {
        if (A[i] != A[i + 1])
        {
            A[j] = A[i];
            printf("Diverse %c _ %c\n", A[i], A[i + 1]);
            i = i + 1;
            j = j + 1;
        }
        else
        {
            printf("Uguali %c _ %c\n", A[i], A[i + 1]);
            i = i + 2;
        }
    }
    printf("Fine %c _ %d \n", A[j], j);
    A[j] = A[i];
    A[j + 1] = '\0';
    return &A[0];
}

int main()
{

    unsigned int len;
    scanf("%u", &len);
    char A[len];
    scanf("%s", A);
    char *s;

    for (s = rimuovi_doppie(A); *s != '\0'; s++)
        printf("%c", *s);
    printf("\n");
}
//! Inserisco nella terza lista solo i valori comuni tra le due liste
void intersection(Lista *list1, Lista *list2, Lista **destPtr)
{

    Lista *inizio_list2 = list2;

    while (list2 != NULL)
    {
        list2 = list2->nextPtr;
    }
    Lista *fine_list2 = list2;

    list2 = inizio_list2;

    while (list1 != NULL)
    {
        while (list2 != NULL)
        {
            printf("Dentro list2: 1) %d 2) %d\n", list1->valore, list2->valore);
            if (list2->valore == list1->valore)
            {
                printf("Valore: %d\n", list1->valore);
                suf_insert(destPtr, list1->valore);
                list2 = fine_list2;
            }
            else
            {
                list2 = list2->nextPtr;
            }
        }
        list1 = list1->nextPtr;
        list2 = inizio_list2;
    }
}