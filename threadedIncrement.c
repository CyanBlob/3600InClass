/*
 Group:   16
 Members: George Davis
          Shashi Dongur
          Gary Johnson
          Andrew Thomas
 Class:   CSCE3600
 Session: Fall 2014
 Section: T/Th 10:00am
 Project: In-Class Assignment -- Concurrency
 Compile: gcc threadedIncrement.c -lpthread
 Note:    Performance of this code on the CSE machines is unpredictable;
          Sometimes this runs fast, sometimes it runs slow.
*/

#include <pthread.h>
#include <stdio.h>

void inc_n(int* n)
{
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

    // create threads with function pointer cast
    pthread_create(&xtid, NULL, (void* (*)(void*)) inc_n, &x);
    pthread_create(&ytid, NULL, (void* (*)(void*)) inc_n, &y);

    // wait for threads to finish
    pthread_join(xtid, (void**) &retval);
    printf("x increment finished\n");
    pthread_join(ytid, (void**) &retval);
    printf("y increment finished\n");

    printf("x: %d, y: %d\n", x, y);
    return 0;
}
