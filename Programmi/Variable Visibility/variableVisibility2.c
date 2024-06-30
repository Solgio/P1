#include <stdio.h>

int x = 10;

int main() {
  int y = 2;
  {
    int y = 4;
    if (y>2)
    {
      int x = 2;
      x=x+3;
    }
    printf("%d\n", x/y*2);
  }
}