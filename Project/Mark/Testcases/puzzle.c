#include <stdio.h>
#include <string.h>
char scanarray(char array[100][100]);
void printarray(char array[100][100],int a,int b);
int fillgrid(char array[100][100],char z[10],int x,int y);
int fillgridcol(char array[100][100],char z[10],int x,int y);
int fact(int n);
int checkgrid(int a,int b);
void sort(char grid[100][100],int rem,int c);
void calcln(char g[100][100],int o[10],int c);
void copyarray(char x[100][100],char y[100][100],int t);

int main(){
  int p1,p2,x=0,l,i,j,y,t,k,z,m,h[10],u[10],check,f=0,rep=0,nn,nm,sum,print=0,qu;
  int r[10][5],c[10][10],s1[10][10],s2[10][10];
  int l1[10],l2[10];
  char p[100][100],cp[100][100];
  char w[100][100],cw[100][100];
              
 // printf("enter the grid\n");                 // used when coding
  p1=scanarray(p);                       // scaning the grid
 // printf("enter the words\n\n");              // used when coding
  p2=scanarray(w);                       // scaning the words

  calcln(p,l1,p1);
  calcln(w,l2,p2);
  
  l=strlen(p[0]);

  for(i=0;i<p1;i++){                  // calculating '#'s in a row and how many connected '#'s
      y=0,t=1,m=0,h[i]=0;
      for(j=0;j<l;j++){
         if(p[i][j]!='*'){
            y++;
            r[i][t]=y;
            s1[i][t]=m;
            z=z+1;
            h[i]=t;
         }
         else if(y>0 && p[i][j]=='*'){
             m=j+1;
             y=0;
             z=0;
             h[i]=t;
             t=t+1;
         }
         else{
             m=j+1;
         }
      }
   /*   for(k=1;k<h[i]+1;k++){                    // use for checking the array initialization while coding
         printf("%d%d\t",r[i][k],s1[i][k]);
      }
      printf("\n");*/
   }
     // printf("%d\n",s1[1][1]);                 // just for checking output of array 's'

   for(i=0;i<l;i++){                           // for columns
      y=0,t=1,m=0,u[i]=0;
      for(j=0;j<p1;j++){
         if(p[j][i]!='*'){
            y++;
            c[i][t]=y;
            s2[i][t]=m;
            z=z+1;
            u[i]=t;
         }
         else if(y>0 && p[j][i]=='*'){
             m=j+1;
             y=0;
             z=0;
             u[i]=t;
             t=t+1;																							
         }
         else{
             m=j+1;
         }
      }
   /*   for(k=1;k<u[i]+1;k++){
         printf("%d%d\t",c[i][k],s2[i][k]);              // to check the array
      }
      printf("\n");*/
   }

   copyarray(cp,p,p1);                  // copying the grid
   copyarray(cw,w,p2);                  // copying the words

  int v; 
  for(v=0;v<(p2);v++){             // here appart from v<p2 it should be v<p2! ,becouse word changing can happen for factorial of p2 times,,,but i got confusion in coding
     copyarray(cp,p,p1);
     rep=0,sum=0,qu=0,f=0;
     for(i=0;i<p1;i++){
        for(j=0;j<h[i];j++){
           k=0,check=0;
           while(1){
              check=checkgrid(r[i][j+1],l2[k]);             // checking the size of the word and the spaces are equal or not
           //   nn=check;
              if(check==2){
                  nn=check;
                  rep=fillgrid(cp,w[k],i,s1[i][j+1]);              // filling the correct word
                  sum=sum+rep;
                  qu++;
                  f++;
               //   printf("%s %d %d\n",w[k],s1[i][j+1],l2[k]);             //just to check what happens in this itteration while coding
                  sort(w,k,p2);                                          // sorting the word order by putting the word used to the end
                  calcln(w,l2,p2);                                     // calculating the length of words again
                  break;
              }
              else{
                   k++;
              }
              if(k>p2){
                 break;
              }
           }
       }
     }
     for(i=0;i<l;i++){
        for(j=0;j<u[i];j++){
           k=0,check=0;                                            // same thing happens lik raws
           while(1){
              check=checkgrid(c[i][j+1],l2[k]);
             // nm=check;
              if(check==2){
                  nm=check;
                  rep=fillgridcol(cp,w[k],s2[i][j+1],i); 
                  sum=rep+sum; 
                  qu++;     
                 // printf("%s %d\n",w[k],s2[i][j+1]);        // used to check the word going to fill and where to put the word while coding
                  sort(w,k,p2);
                  calcln(w,l2,p2);
                  break;
              }
              else{
                   k++;
              }
              if(k>p2-f){
                 break;
              }
           }
       }
     }
     if(rep==2){
         copyarray(w,cw,p2);           // if the filling of word order is incorrect again done it by sorting the words (here sort means putting the 1st word to last)
         sort(w,v,p2);
         calcln(w,l2,p2);
     }
    /* else if(qu==p2){
         v=100;
     }*/
     else{v=100;}
  }
 
 if(sum>0){
       printf("IMPOSSIBLE\n");
       print=1;
  }
  if(nn!=2 && nm!=2){
       printf("IMPOSIBLE\n");
       print=1;
  }
  if(qu!=p2){
       printf("IMPOSSIBLE\n");
       print=1;
  }
  if(print!=1){printarray(cp,p1,l);}
 return 0;

}


  char scanarray(char array[100][100]){      // function for scanning

      char ch;
      int i=0,j=0,b=0;
      
      ch=getchar();

       while(ch!='\n'){
          while(ch!='\n'){
            array[i][j]=ch;
            j=j+1;
            if(j>b){
               b=j;
            }
            ch=getchar();
           }
           ch=getchar();
           i=i+1;
           j=0;
       }
          
     return i;    
   }


    void printarray(char array[100][100],int a,int b){
        int i,j;
          for(i=0;i<a;i++){                                 // printing the puzzle
             // for(j=0;j<b;j++){
                 printf("%s",array[i]);
            //  }
              printf("\n");
          }         
    }
  
    int fact(int n){                  // calculating factorial of words given,,,,
       int fac;
         if(n<2){
            fac=1;
         }
         else{
            fac=n*fact(n-1);
         }
         return fac;
    }

    int checkgrid(int a,int b){        // chaecking whether the length of word == length of given space
        if(a==b){
          return 2;
        }
        else{
          return 3;
        }
    }

   int fillgrid(char array[100][100],char z[10],int x,int y){       // filling a raw according to the give word
         int i,l,we=0;
         l=strlen(z); 
         for(i=0;i<l;i++){
             if(array[x][y]=='#' || array[x][y]==z[i]){
               array[x][y]=z[i];
               y++;
             }
             else{
               we=2;;
             }
         } 
         return we;
        /* if(we==1){return 2;}
         else{return 0;}  */        
    }
      
    int fillgridcol(char array[100][100],char z[10],int x,int y){        // filling a column according to the given word
         int i,l,we=0;
         l=strlen(z); 
         for(i=0;i<l;i++){
            if(array[x][y]=='#' || array[x][y]==z[i]){
               array[x][y]=z[i];
               x++;
             }
            else{
               we=2;;
            }
         } 
         return we;
       /*  if(we==1){return 2;}
         else{return 0;}        */
    }

    void sort(char grid[100][100],int rem,int c){                 // sorting the words by putting the rem to last
         int i;
         char kk[10];
         strcpy(kk,grid[rem]);
         for(i=0;i<(c-rem-1);i++){
             strcpy(grid[rem+i],grid[rem+1+i]);
          //   printf("%s\n",grid[rem+i]) ;              // used to check whether its correct or not while coding
         }
         strcpy(grid[c-1],kk);
        // printf("%s\n",grid[c-1]);
    }
    
    void calcln(char g[100][100],int o[10],int c){              // calculating the length of given words
         int i;
         for(i=0;i<c;i++){
             o[i]=strlen(g[i]);
         }
    } 

    void copyarray(char x[100][100],char y[100][100],int t){       // copying a array to another array
       int i;
       for(i=0;i<t;i++){
           strcpy(x[i],y[i]);
       }   
    }