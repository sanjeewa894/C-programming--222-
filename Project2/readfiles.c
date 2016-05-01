#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h> 
#include <stdio.h>
#include <string.h>

/* sample code 
 * how to read files that are in a directory
 */

char dir[] = "songs"; // list contents in songs directory 

int main() 
{
  DIR *ptr = opendir(dir); /* open the directory 
			    * You get a directory discriptor called prt 
			    */
  struct dirent *ent; 

  if(ptr == NULL) exit(!printf("Cannot ./%s directory", dir)); 

 
  while((ent = readdir(ptr)) != NULL) { 
    if(ent -> d_type != DT_DIR) /* it shows . and .. as well
				 * display on the entries which are not 
				 * directories 
				 */
      printf("%s\n", ent -> d_name);    
  }

  closedir(ptr); 
  return 0;
}
  
