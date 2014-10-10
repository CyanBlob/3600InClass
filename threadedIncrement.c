// compile with: gcc threadedIncrement.c -lpthread
#include <pthread.h>
#include <stdio.h>

void* inc_n(void* v)
{
   int* n = (int*) v;
   /* increment n to 100 */
   while(++(*n) < 1000000000);
   pthread_exit(0);
}

int main()
{
    int x = 0, y = 0;
    pthread_t xtid, ytid;
    int* retval;

    printf("x: %d, y: %d\n", x, y);

    // create threads
    pthread_create(&xtid, NULL, inc_n, &x);
    pthread_create(&ytid, NULL, inc_n, &y);

    // wait for threads to finish
    pthread_join(xtid, (void**) &retval);
    printf("x increment finished\n");
    pthread_join(ytid, (void**) &retval);
    printf("y increment finished\n");

    printf("x: %d, y: %d\n", x, y);
    return 0;
}
