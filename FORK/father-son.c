

#include <unistd.h>
#include <stdio.h>
int main() {
  int parentID = getpid();
  int pid = fork();
  if(pid == 0) { /* I’m the child process */
    int childID = getpid();
    printf("child: pid %d\n", pid);
    printf("child: pid of parent %d\n", parentID);
    printf("child: PID of child %d\n", childID);
  } else { /* I’m the parent process */
    sleep (1); /* Give my child time to start. */
    printf("parent: pid (should be the child) %d\n", pid);
    printf("parent: pid of parent %d\n", parentID);
  }
  printf("Terminating process\n");
  return 0;
}
