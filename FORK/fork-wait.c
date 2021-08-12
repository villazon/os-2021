
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
int main() {
  int parentID = getpid();
  char prgname[1024];
  /* read the name of program we want to start */ gets(prgname);
  int pid = fork();
  if(pid == 0) { /* I’m the child process */
    execlp( prgname, prgname, 0); /* Load the program */
    /* If the OS starts prgname, we never get to this line,
       because the OS replaces the program running in the
       child process by prgname. */
    printf("I didn’t find program %s\n", prgname);
  } else { /* I’m the parent process */
    sleep (1); /* Give my child time to start. */
    /* Wait for my child to terminate. */
    waitpid(pid, 0, 0);
    printf("Program %s finished\n", prgname);
  }
  return 0;
}
