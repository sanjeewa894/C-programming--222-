#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h> 
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) 
{ 

  if(argc == 1) { 
    printf("Syntax: run <command> <arguments>\n");
    return 0; 
  }

  int i; 
  /* from man system, 
   * it takes one string as argument 
   * join all the strings into a one
   */ 
  
  /* first length of all strings 
   */ 
  int length_of_all= argc; // need spaces and one for termination
  for(i=1; i < argc; i++) 
    length_of_all += strlen(argv[i]); 

  /* one string 
   */
  char *command = malloc(length_of_all * sizeof(char)); 
  command[0] = '\0'; 
  char *space = " " ; 
  for(i=1; i < argc; i++) { 
    strncat(command, argv[i], strlen(argv[i])); 
    strcat(command, space);
  }

  return system(command);  

}
