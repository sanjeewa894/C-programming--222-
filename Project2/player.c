#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h> 
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv) 
{ 
  int count=0,l,i,j,n;
  char dir[]="./";

  if(argc!=1){              // if argc>1 dir will take the argv[1] otherwisw ./
      strcpy(dir,argv[1]);
  }

  l=runsong(dir);     // it counts howmany mp3 files in the given directory
 
  int r[l],w[l];
l=10;
  srand(time(NULL));  // getting a randnumber which varies with the time
  n=(rand()%l)+1;

  for(i=0;i<l;i++){   // storing random number in an arrray 
      int k=0;
      for(j=0;j<i;j++){
	  if(n==r[j]){
	       j=i+1;	
               i--;
               k=1;
          }
      }
      if(k==0){
           r[i]=n;
//printf("%d\n",n);
      }
      n=(rand()%l)+1;
  }

  
return 0;
}

int runsong(char dir[])
{
  DIR *ptr = opendir(dir);
  struct dirent *ent; 

  if(ptr == NULL) exit(!printf("Cannot ./%s directory\n", dir)); 

 
  while((ent = readdir(ptr)) != NULL) { 
    if(ent -> d_type != DT_DIR){ 
      printf("%s\n", ent -> d_name);
      int l=strlen(ent->d_name);
      char s[]=ent->d_name;
      for(i=0;i<l;i++){
          if(s[i]==' '){
	      s[i]='\\';
	      char q=' ';
              strcat(s,q);
	      
          }
      }
    }   
  }

  closedir(ptr); 

return 0;
}
