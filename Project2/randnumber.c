#include <stdlib.h>
#include <stdio.h>

#define MAX  10

int main(int argc, char **argv) 
{ 
  int ite; 
  if(argc == 1) ite = MAX; 
  else ite = atoi(argv[1]); // argument tells how many numbers to guess 

  for(; ite > 0; ite --) 
    printf("Random number: %d\n", rand() % ite);

  return 0; 
}
