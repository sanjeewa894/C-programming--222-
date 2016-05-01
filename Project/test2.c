#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

void allZero(char array[SIZE], char matrix[SIZE][SIZE]);	//function for assign all to zero
void scanPuzzel(char array[SIZE], char inipuzzel[SIZE][SIZE]);	//function for scan the array
void checkingPuzzel(char starpuzzel[SIZE][SIZE]);
void printPuzzel(char puzzel[SIZE][SIZE]);

int main(){

	char puzzel[SIZE][SIZE], Wordpuzzel[SIZE][SIZE], iniarray[SIZE], Warray[SIZE];


	allZero(iniarray, puzzel);	//Assign zero's to all in the arrays and 2d arrays

	allZero(Warray, Wordpuzzel);

	scanPuzzel(iniarray, puzzel);	//calling the scan function

	scanPuzzel(Warray, Wordpuzzel);	//calling the word scaning function

	printPuzzel(puzzel);		//printing the puzzel






	return 0;
}

//----------------------------------------------------------------------------------------------------------------------

void allZero(char array[SIZE], char matrix[SIZE][SIZE]){

	int row, col;

	for(row=0; row<SIZE; row++){
		array[row]='0';

	}

	for(row=0; row<SIZE; row++){
		for(col=0; col<SIZE; col++){
			matrix[row][col]='0';

		}

	}

}

//-----------------------------------------------------------------------------------------------------------------------


void scanPuzzel(char array[SIZE], char inipuzzel[SIZE][SIZE]){

	int length, i, j;

	//scaning the array
	fgets(array,SIZE,stdin);

        length=strlen(array);
        

        for(i=0;i<length;i++){

                inipuzzel[0][i]=array[i];

        }

        while(inipuzzel[i][0]!='\n'){

                fgets(array,SIZE,stdin);
                length=strlen(array);

                for(j=0;j<length;j++){
                        inipuzzel[i+1][j]=array[j];

        	}
                        i++;

	}


}

//------------------------------------------------------------------------------------------------------------------------

void checkingPuzzel(char starPuzzel[SIZE][SIZE]){

	int row, col, rowCount, colCount;

	//loop for count charactors without '*'
	for(row=0; starPuzzel[row][0]!='0'; row++){

		rowCount=0;

		for(col=0; starPuzzel[row][col]!='0'; col++){

			if((starPuzzel[row][col]=='#')||(isalpha(starPuzzel[row][col])))
				rowCount++;

		}

	}


	for(col=0; starPuzzel[0][col]!='0'; col++){

		for(row=0; starPuzzel[row][col]!='0'; row++){

			if((starPuzzel[row][col]=='#')||(isalpha(starPuzzel[row][col])))
				colCount++;

		}

	}




}

//---------------------------------------------------------------------------------------------------------------------

void printPuzzel(char puzzel[SIZE][SIZE]){

	int row, col;

	for(row=0; puzzel[row][0]!='0'; row++){

		for(col=0; puzzel[row][col]!='0'; col++){
			printf("%c", puzzel[row][col]);

		}

		printf("\n");

	}

}
