#include <stdio.h>
// main function -
// where the execution of program begins
int main()
{
  /*PRE
    POST:Stampa il minore tra i due numeri
  */
  int x, y, z;
  
  scanf("%d", &x);
  scanf("%d", &y);
  scanf("%d", &z);
  
  int Max = x;

  if (Max < y)
    Max = y;
    
  if (Max < z)
    Max = z;

  printf("Il Massimo dei tre valori e': %d", Max);
}
