#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  long total = 0;
  if(argc != 2) {
    printf("Usage: %s <n>\n", argv[0]);
    exit(-1);
  }
  int count = atoi(argv[1]);
  for(int i=0; i<=count; i++) {
    total = total + i;
  }

  printf("Total %lu \n", total);
  


}
