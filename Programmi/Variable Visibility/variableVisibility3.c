#include <stdio.h>

float x = 2.6;
int main(void) {
    int y = 2;
    {
    if (x<2)
        if (y>2)
            printf("%d ", y); 

        else
            printf("%f ", x);

    int y = 4;
    {
        int z = x * 3;  //il c tronca il float
        printf("%d", z);
    }
    }
}