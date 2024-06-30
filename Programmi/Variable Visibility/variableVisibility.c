#include<stdio.h>

int main()
{
    int a = 10;
    {
       float a=20;
       //int a=20; printf restituisce 10
       // a=20; printf restituisce 20
    }
    
    printf("%d",a);
    return 0;
}