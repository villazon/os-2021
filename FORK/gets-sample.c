#include<stdio.h> 
int main(int argc, char **argv) 
{ 
	char buf[255]; 
	printf ("type something:"); 
	if ( fgets(buf, 255, stdin) != NULL )
		printf ("you typed:%s\n",buf); 
}
