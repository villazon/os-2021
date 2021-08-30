#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

volatile long int total = 0;

void threadFunc(void *arg) {
  for(int i=0; i < 500000000; i++) {
    total = total + i;
  }
}

void threadFunc2(void *arg) {
  for(int i = 500000000; i <= 1000000000; i++) {
    total = total + i;
  }
}

int main(int argc, char *argv[]) {

  if(argc != 2) {
    printf("Usage: %s <n>\n", argv[0]);
    exit(-1);
  }
  int count = atoi(argv[1]);

  pthread_t one, two;
  total = 0;

  pthread_create(&one, NULL, (void *)&threadFunc, NULL);
  pthread_create(&two, NULL, (void *)&threadFunc2, NULL);

  pthread_join(one, NULL);
  pthread_join(two, NULL);


  printf("Total %lu \n", total);
  


}
