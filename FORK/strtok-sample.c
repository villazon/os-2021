#include <string.h>
#include <stdio.h>

char str[] = "this # is a simple # test for # stdtok"; 
char delims[] = "#"; 
char *result = NULL; 

int main() {
  result = strtok( str, delims ); 
  while( result != NULL ) { 
    printf( "result is \"%s\"\n", result ); 
    result = strtok( NULL, delims );
  }
}
