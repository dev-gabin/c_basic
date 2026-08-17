#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int** dynamic_array(int row, int cal)
{ 
    int**arr=malloc(row*sizeof(int*));
    int*data=malloc(row*cal*sizeof(int));     
    
    for(int i=0;i<row;i++){
        arr[i]=data+i*cal;
    }
    return arr;
    

    }
    

int main(void){
    printf("=== Day 10: Dynamic 2D Array Allocation ===\n\n");
    printf("Generated Matrix (3x4):\n");
    
    int row=3, cal=4;
    int** matrix =dynamic_array(3,4);

    int count=1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < cal; j++)
        {
            matrix[i][j] = count++;   // 여기서 값 채우기
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0; j<cal;j++){

            printf("%2d ",matrix[i][j]);
        }
        printf("\n");

    }
    printf("\n\n");
    printf(">> Memory successfully freed.");

    free(matrix[0]);
    free(matrix);

    return 0;


}


