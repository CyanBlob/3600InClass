/*
 Group:   16
 Members: George Davis
          Shashi Dongu
          Gary Johnson
          Andrew Thomas
 Class:   CSCE3600
 Session: Fall 2014
 Section: T/Th 10:00am
 Project: In-Class Assignment -- Concurrency
 Compile: gcc forkedIncrement.c
*/

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
  printf("x: %d, y: %d\n", x, y);

  pid_t pid = fork();

  //child process
  if (pid == 0) {
    inc_n(&x);
    printf("x increment finished\n");
    printf("x: %d, y: %d\n", x, y);
    return 0;
  }
  //parent process
  else {
    inc_n(&y);
    printf("y increment finished\n");
    printf("x: %d, y: %d\n", x, y);
    wait();
    return 0;
  }
}
