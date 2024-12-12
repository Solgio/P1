#include <stdio.h>

int mossa(int campo, int x, int y, int dim_x, int dim_y){
    if(x==0){
        return 1;
    }
    if(x<0 || x>=dim_x ||y<0 || y>=dim_y){
        return 0;
    }
    else{
        return mossa(campo, x-1, y, dim_x, dim_y) + mossa(campo, x, y+1, dim_x, dim_y)
    }
}

#define DIM_X 5
#define DIM_Y 5

int main(void)
{

    int campo[DIM_X][DIM_Y] = {
        {0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 0}};
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Numero di percorsi da %d,%d alla riga 0: %d\n", x, y, mossa(campo, x, y));
}