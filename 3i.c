#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

  pid_t child_pid;
  printf("-------------- Process tree ------------------\n");
  printf("Main parent -> PID :%d\n", getpid());

  // pid means the current process
  // ppid means who created me (parent process id)

  child_pid = fork();
  // first child after the first fork
  // we have to check whether the child pid is created or not,if zero it is,if
  // not then it is not created
  if (child_pid == 0) {
    printf(
        "The child 1 is created with the PID -> %d from the parent PID ->%d\n",
        getpid(), getppid());
    if (fork() == 0) {
      printf("one grand child is created with the PID -> %d from the parent "
             "PID ->%d\n",
             getpid(), getppid());
    }
    exit(0);
  }
  wait(NULL);

  if (fork() == 0) {
    printf("child is created with the PID -> %d from the parent PID -> %d\n",
           getpid(), getppid());
    exit(0);
  }

  wait(NULL);

  if (fork() == 0) {
    printf("child 3 is created ->PID : %d from the parent id ->PID : %d\n",
           getpid(), getppid());
    exit(0);
  }
  wait(NULL);
  printf("main parent have finished");
  return 0;
}
