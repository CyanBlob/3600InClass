#include <pthread.h>
#include <stdio.h>

void* inc_n(void *n)
{
   /* increment n to 100 */

   int *count;
   count = (int *) n;

   while(++*count < 1000000000);
   pthread_exit(NULL);
}

int main()
{
    pthread_t tid[2];

    int x = 0, y = 0;
    printf("x: %d, y: %d\n", x, y);
    pthread_create(&tid[0], NULL, inc_n, &x);
    pthread_create(&tid[1], NULL, inc_n, &y);
    pthread_join(tid[0], NULL);
    printf("x increment finished\n");
    pthread_join(tid[1], NULL);
    printf("y increment finished\n");
    printf("x: %d, y: %d\n", x, y);
    return 1;
}
