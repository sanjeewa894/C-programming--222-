#include <stdio.h>

#define SIZE 10

int scanPuzzel(char inimatrix[SIZE][SIZE], int ROW, int COL);	//function for scan the array
//int Assign()

int main(){

	char inipuzzel[SIZE][SIZE];
	int row, col;

	scanPuzzel(inipuzzel, row, col);	//calling the scan function

 	char puzzel[row][col];

	
	
printf("%d %d\n", row, col);
//	scanf





	return 0;
}

int scanPuzzel(char inimatrix[SIZE][SIZE], int ROW, int COL){

	int row, col, mark=0, tcol=0;

	//loop for scan the array row by row
	for(row=0; row<SIZE; row++){

		for(col=0; col<SIZE; col++){

			scanf("%c",&inimatrix[row][col]);

		}

	}
	//loop for check number of rows in the matrix
	for(row=0; row<SIZE; row++){
		for(col=0; col<SIZE; col++){
			if((inimatrix[row][0]=='*')||(inimatrix[row][0]=='#'))
				mark++;
		}

	}

	switch(mark){
		case 4:
			ROW=2; COL=2;
			break;

		case 6:
			ROW=3; COL=2;
			break;

		case 8:
                        ROW=4; COL=2;
                        break;

		case 9:
                        ROW=3; COL=3;
                        break;

		case 12:
                        ROW=4; COL=3;
                        break;

		case 15:
                        ROW=5; COL=3;
                        break;

		case 16:
                        ROW=4; COL=4;
                        break;

		case 20:
                        ROW=5; COL=4;
                        break;

		case 24:
                        ROW=6; COL=4;
                        break;

		case 25:
                        ROW=5; COL=5;
                        break;

		case 36:
                        ROW=6; COL=6;
                        break;

		case 49:
                        ROW=7; COL=7;
                        break;

		case 64:
                        ROW=8; COL=8;
                        break;

		case 81:
                        ROW=9; COL=9;
                        break;

		case 100:
                        ROW=10; COL=10;
                        break;
		}
			

}

/*
	//loop to check the # marks in the puzzel
	for(row=0; row<SIZE; row++){

		for(col=0; col<SIZE; col++){
			if(matrix[row][col]='#'){
				marks++;
			}

		}



	}
	return marks;

}
*/
