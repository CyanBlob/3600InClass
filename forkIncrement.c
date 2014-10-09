#include <stdio.h>

void inc_n(int *n)
{
   /* increment n to 100 */
   while(++(*n) < 1000000000);
}

int main()
{

    int x = 0, y = 0;
    printf("x: %d, y: %d\n", x, y);
  if (fork() == 0) {
    inc_n(&x);
    printf("x increment finished\n");
    printf("x: %d, y: %d\n", x, y);
    return 1;
  }
  else {
    inc_n(&y);
    printf("y increment finished\n");
    printf("x: %d, y: %d\n", x, y);
  }
    wait();
    return 1;
}
