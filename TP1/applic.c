#include "common.h"
#include <stdio.h>

extern int MAX_USERS;

int main(int argc, char** argv) {
  MAX_USERS= getRandom();
  printf("Max users are %i\n", MAX_USERS);
  printf("Host is %s\n", getNetAddr());
  printf("IP is %s\n", getIPAddr()); 
  return 0;
}
