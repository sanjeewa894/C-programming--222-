#include<stdio.h>
#include<stdlib.h>

#define size 128
//******func**************************
void getin(char arr[size][size]);
void set_zero(char arr[size][size]);
void chck_words(int count,int row,int col,char arr_words[size][size],char arr_puz[size][size],int type);
void change_in_puzzle(char arr_words[size][size],char arr_puz[size][size]);
void prnt(char arr_puz[size][size]);
void chek_possiblity(char arr_puz[size][size]);
//************************************


int main(){
	
	
	
		char puzz[size][size],words[size][size];
		
		//set zeros to array=========================================
						set_zero(puzz);
						set_zero(words);
		//get puzzle=================================================
						getin(puzz);
		//get words==================================================
						getin(words);	
		//check for spaces and fill==================================
						change_in_puzzle(words,puzz);
		//check whether possible or not==============================
						chek_possiblity(puzz);
		//	print final output=======================================
						prnt(puzz);
							
		return 0;
}				
//********************************************************************************
void set_zero(char arr[size][size]){//set all elements in array to 0
	int row,col;
	for(row=0;row<size;row++){
		
		
					for(col=0;col<size;col++){
			
							arr[row][col]='0';
			
		}	
	}
	
	
}
//*********************************************************************************
void getin(char arr[size][size]){//get user inputs and save in 2d array
	
	int row=0,col=0,ch;
	
	for(row=0;((ch=getchar())!='\n');row++){
		
				for(col=0;(ch!='\n');col++){
					
					arr[row][col]=ch;
					
					ch=getchar();
				}
		
		
	}
	
	
	
}
//***********************************************************************************
void change_in_puzzle(char arr_words[size][size],char arr_puz[size][size]){//check space in puzzle and ask for word to fill it
		
			int row,col,count,letters;
//=================================LOOK FOR SPACE IN ROWS====================================================================================
			for(row=0;arr_puz[row][0]!='0';row++){
				
				count=0;
				
				for(col=0;arr_puz[row][col]!='0';col++ ){
					
							if(isalpha(arr_puz[row][col])||(arr_puz[row][col]=='#')){
										count++;
							}else{
										count=0;
							}	
							
					
			//------------------------------------------------------------------------------------------------------	
							if((count>1)&&((arr_puz[row][col+1]=='*')||(arr_puz[row][col+1]=='0'))){
								
										chck_words(count,row,(col-count+1),arr_words,arr_puz,0);
										count =0;
										break ;
							
							}
			//------------------------------------------------------------------------------------------------------				
				}
						
				
			}
//========================================spaces in cols====================================================================================================	
			for(col=0;arr_puz[0][col]!='0';col++){
				
				count=0;
				
				for(row=0;arr_puz[row][col]!='0';row++ ){
					
							if(isalpha(arr_puz[row][col])||(arr_puz[row][col]=='#')){
										count++;
							}else{
										count=0;
							}	
							
			//------------------------------------------------------------------------------------------------------	
							if((count>1)&&((arr_puz[row+1][col]=='*')||(arr_puz[row+1][col]=='0'))){
								
										chck_words(count,(row-count+1),col,arr_words,arr_puz,1);
										
										count =0;
										break ;
							}		
			//------------------------------------------------------------------------------------------------------				
				}
						
				
			}
		
	
	
}
//*****************************************chck_words***************************************************************************************************
void chck_words(int count,int row_argumnt,int col_argumnt,char arr_words[size][size],char arr_puz[size][size],int type){//check words that matches with puzzle
	
					int row_words,col_words,col_puz,row_puz,goOn;
					
					for(row_words=0;arr_words[row_words][0]!='0';row_words++){
						
								if(arr_words[row_words][0]=='1')continue;//check whether word is already used
								
								for(col_words=0;arr_words[row_words][col_words]!='0';col_words++);//counting letters in the word
									
									
									if(col_words==count){
											
											if(type==0){//changing row in puzzle
												
													
												goOn=0;//for check is it okay to change array 
												for(col_words=0,col_puz=col_argumnt;col_words<count;col_words++,col_puz++){
													
													if((arr_puz[row_argumnt][col_puz]==arr_words[row_words][col_words])||(arr_puz[row_argumnt][col_puz]=='#')){
																goOn++;
													}
													
												}
											
												if(goOn==count){//check is it okay to change array 
													for(col_words=0,col_puz=col_argumnt;col_words<count;col_words++,col_puz++){
														
															arr_puz[row_argumnt][col_puz]=arr_words[row_words][col_words];
															arr_words[row_words][col_words]='1';//to inform this word is used
														
													}
													
												}
											}else{//changing columns in puzzle
												
												
												goOn=0;//for check is it okay to change array 
												for(col_words=0,row_puz=row_argumnt;col_words<count;col_words++,row_puz++){
													
													if((arr_puz[row_puz][col_argumnt]==arr_words[row_words][col_words])||(arr_puz[row_puz][col_argumnt]=='#')){
																goOn++;
													}
													
												}
											
												if(goOn==count){//check is it okay to change array 
													for(col_words=0,row_puz=row_argumnt;col_words<count;col_words++,row_puz++){
														
															arr_puz[row_puz][col_argumnt]=arr_words[row_words][col_words];
															arr_words[row_words][col_words]='1';//to inform this word is used
														
													}
													
												}
												
											}
											
											break;
									
									}
									//check whether puzzle can be solved or not :is there  enough matching words???? 
									if((col_words!=count)&&(arr_words[row_words+1][0]=='0')){
										
										printf("IMPOSSIBLE \n");
										exit(-1);
									}
									
										
						
						
					}
	
//========================================================================================================================================	
					
}
//========================================================================================================================================	
void prnt(char arr_puz[size][size]){//print a 2d array
	
	int row,col;
	for(row=0;arr_puz[row][0]!='0';row++){
		
		for(col=0;arr_puz[row][col]!='0';col++){
			
			printf("%c",arr_puz[row][col]);
		}
		printf("\n");
		
	}
	
}
//=============================================================================================================================================
void chek_possiblity(char arr_puz[size][size]){
	int row,col;
	for(row=0;arr_puz[row][0]!='0';row++){
		
		for(col=0;arr_puz[row][col]!='0';col++){
			
			if(arr_puz[row][col]=='#'){
					printf("IMPOSSIBLE");
					exit(-1);
					
				
			}
		}
		
		
	}
	
}
