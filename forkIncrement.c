#include <stdio.h>
#include <stdlib.h>

void inc_n(int *n)
{
   /* increment n to 100 */
   while(++(*n) < 1000000000);
}

int main()
{

    int x = 0, y = 0;
    pid_t pid;
    printf("x: %d, y: %d\n", x, y);
  
    pid = fork();

    if( pid == 0)
    {
    	inc_n(&x);
	printf("x increment finished\n");
	return 0;
    }

    if( pid > 0)
    {
	inc_n(&y);
	printf("y increment finished\n");
    }
    wait();
    printf("x: %d, y: %d\n", x, y);
    return 1;
}
