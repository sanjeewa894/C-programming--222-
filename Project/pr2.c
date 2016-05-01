#include<stdio.h>
#define SIZE 100
#include<string.h>

int main(){
        char plz[100][100], H[100];
	int s[100],s1[100], i,j,a=0,k=0,m,n,l=0;




        fgets(H,100,stdin);
        a=strlen(H);
        m=a;
        for(i=0;i<a;i++){

                plz[0][i]=H[i];
                                }

        while( plz[i][0]!='\n'){
                fgets(H,100,stdin);
                a=strlen(H);

                for(j=0;j<a;j++){
                        plz[i+1][j]=H[j];
                                        }
                        i++;
                                                }
/*
	for(i=0;i<a;i++){

		s[i]=strlen(plz[i]);
			l=s[i];
		printf("%d",l);
					}

*/


        for(i=0;i<a;i++){
                for(k=0;k<m;k++){

                        printf("%c",plz[i][k]);

                                       }
                                                }

	return 0;
}

