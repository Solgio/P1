#include <stdio.h>

//
// PRE:
// POST:
void swap_eq(int *a, int dim, int i, int n, int j)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        swap_eq(a, dim, i + 1, n - 1, j + 1);
    }
}

// PRE:
// POST:
void swap(int *a, int dim, int m, int n, int p)
{
    int dim1 = n - m;
    int dim2 = p - 1;
    if (dim1 == dim2)
    {
        swap_eq(a, dim, m, dim1, p);
    }
    else if (dim1 > dim2)
    {
        swap_eq(a, dim, m, dim2, n);
        swap(a, dim, m + dim2, n, p);
    }
    else if (dim1 < dim2)
    {
        swap_eq(a, dim, m, dim1, n);
        swap(a, dim, n, n + dim1, p);
    }
}

void print_array(int *a, int d)
{
    for (int i = 0; i < d; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void)
{
    int dim;
    int m;
    int n;
    int p;

    scanf("%d", &dim);
    int arr[dim];
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", arr + i);
    }

    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);

    swap_eq(arr, dim, m, n, p);
    print_array(arr, dim);
}