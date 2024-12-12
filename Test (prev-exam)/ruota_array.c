#include <stdio.h>

void ruota_array(int array[], int dim, int rot_index)
{
    int temp[rot_index];

    for (int i = 0; i < rot_index; i++)
    {
        temp[i] = array[i];
    }

    for (int c = 0; c < rot_index; c++)
    {
        printf(" %d ", temp[c]);
    }
    printf("\n");

    for (int j = 0; j < dim; j++)
    {
        if (j < rot_index)
        {
            array[j] = array[j + rot_index];
        }
        else
        {
            array[j] = temp[j];
        }
    }
}

int main()
{
    int dim;
    scanf("%d", &dim);
    int array[dim];
    for (int i = 0; i < dim; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < dim; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");

    int rot_index;
    scanf("%d", &rot_index);
    if (rot_index != 0)
    {
        rot_index = rot_index % dim;
        ruota_array(array, dim, rot_index);
    }

    for (int i = 0; i < dim; i++)
    {
        printf(" %d ", array[i]);
    }
    printf("\n");
}