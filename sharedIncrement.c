// increment.c using fork and shared memory

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

void inc_n(int *n)
{
   /* increment n to 100 */
   while(++(*n) < 1000000000);
}

//type ints contains 2 integers called x and y
typedef struct { int x, y; } ints;

int main()
{
  // get a shared memory ID
  int shmid = shmget(IPC_PRIVATE, sizeof(ints), IPC_CREAT | 0666);
  // attach the shared memory ID to a pointer
  ints* i = shmat(shmid, 0, 0);
  // initialize x and y to 0 in shared memory pointed at by i
  i->x = 0; i->y = 0;

  printf("x: %d, y: %d\n", i->x, i->y);

  // fork this process
  pid_t pid = fork();

  // child process
  if (pid == 0) {
    inc_n(&i->x);
    printf("x increment finished\n");
    return 0;
  }

  // parent process
  else {
    inc_n(&i->y);
    printf("y increment finished\n");
    // wait for the child process to finish
    wait();
    printf("x: %d, y: %d\n", i->x, i->y);
    return 0;
  }
}
