/*
Amazon EU interview
March 5th, 2019

Given a matrix, with 
0 -> obstacle 
1 -> available spot 
9 -> terminal

Is there a path from the left top to terminal?
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

int isPath(int ** mat, int row, int column){
	int ** mat_result = (int **) malloc(sizeof(int *) * row);
	for ( int k = 0; k < row; k++) { mat_result[k] = (int *) malloc(sizeof(int) * column); } 
	int i, j; 
	int x = 0, y = 0;
        int flag; 

	for(i = 0; i < row ; i++){
		for ( j = 0 ; j < column ; j++){
			mat_result[i][j] = 0;
		}	
	}
        printf("hi");
        mat_result[0][0] = mat[0][0];	
	
	for(i = 0; i < row ; i++){
		for ( j = 0 ; j < column ; j++){
			if (mat[i][j] == 0){
				mat_result[i][j] = 0;
				continue; 
			}		
 			if ( i-1 > 0 ){
				if (mat_result[i-1][j] > 0){
					mat_result[i][j] = 1; 	
				}
				continue; 
			}
			if ( j-1 > 0 ){
				if (mat_result[i][j-1] > 0){
					mat_result[i][j] = 1; 	
				}
				continue; 
			}
			if ( i+1 < row ){
				if (mat_result[i+1][j] > 0){
					mat_result[i][j] = 1; 	
	  			}
				continue; 
			}
			if ( j+1 > column ){
				if (mat_result[i][j+1] > 0){
					mat_result[i][j+1] = 1 ; 	
				}
				continue; 
			}


		} 
	}

	for(i = 0;  i < row; i++){
		for ( j = 0; j < column; j++){
                        printf( "%d", mat_result[i][j]);
			if (mat[i][j] == 9){
				x = i;
				y = j;
			}			 
		}			
	}
	
	if(mat_result[x][y]){
		flag = 1; 	
	}else{
		flag = 0;
	}	

        //free(mat_result); 
	return flag; 	
}

int main(){
        int row = 3 ;
        int column = 4; 
	static int mat[3][4] = {{1 ,1, 1, 0},
				{0, 1, 0, 1},
				{0, 9, 1, 1}};

	int result = isPath( (int **) mat, row, column);
	printf("%d", result); 
        return 0; 
}	
