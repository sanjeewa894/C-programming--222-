#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

int count=0;
char store[11][500]; 			//un-shuffled song names

//.......................................................................

int countf(const char *dir){
	
	DIR *ptr = opendir(dir); // open the directory 
			    
  	struct dirent *ent; 

  	if(ptr == NULL) exit(!printf("Cannot ./%s directory", dir)); 

 
 	 while((ent = readdir(ptr)) != NULL) { 
    	 if(ent -> d_type != DT_DIR) 

		count++;  
  	}

  	closedir(ptr); 
  	return 0;
}

//.......................................................................
	
int readfiles(const char *dir){

	int i=0,j=0,k=0;
	char *temp;
	DIR *ptr = opendir(dir); /* open the directory 
			    * You get a directory discriptor called prt 
			    */
  	struct dirent *ent; 

  	if(ptr == NULL) exit(!printf("Cannot ./%s directory", dir)); 

 
 	 while((ent = readdir(ptr)) != NULL) {
 
    	 if(ent -> d_type != DT_DIR) {

		//make strcpy 
		strcpy(temp,ent->d_name);
		printf("%s\n",temp);


		while(temp[j]='\0'){
			if(temp[j]==' '){

				store[i][k]='\\';
				store[i][k+1]=' ';

				k++;
			}
			else
				store[i][k]=temp[j];

			k++;
			j++;
		
		}
		store[i][k]='\0';
		printf("%s\n", store[i]);
		i++;  
  		}
	}

  	closedir(ptr); 

  	return 0;
}

//..............................................................................

int shuffle(const char *dir){
	
	int r,k=0;
	char com[1000]="mplayer ";
	int pathlen=strlen(dir);

	strncat(com, dir, pathlen);
	strcat(com," ");

	while(k<count){
		r=rand()%count;
		strcat(com, store[k]);
		system(com);
	}

	return 0;
}

//....................................................................

int main(){
	
	char p[500];
	char d[500];
	int j,i=0;
	

	printf("Enter a directory: ");
	fgets(p,500,stdin);


	while(p[i]=='\n'){
		d[i]=p[i];
		i++;
	}

	d[i]='\0';


	countf("./");

	readfiles("./");
	
	return 0;
}
