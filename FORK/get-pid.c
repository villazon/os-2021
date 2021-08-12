#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
   int pid = getpid();
   printf("my pid:%d\n", pid);
}
