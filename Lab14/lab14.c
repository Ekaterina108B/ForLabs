#include <stdio.h>

int main(void){
    int order = 0, line = 0, column = 0;
    scanf("%d", &order);
    int matrix[order][order];
    
    if(order == 0){
        printf("Matrix of order 0\n");
    }
    else if(order == 1){
        scanf("%d", &matrix[0][0]);
        printf("%d\n", matrix[0][0]);
    }
    else{
        for(int i = 0; i < order; i++){
            for (int j = 0; j < order; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        
        for(int circle = 0; circle <= (order + 1)/2 - 1; circle++){
                while(column + circle*2 != order - 1){
                    printf("%d ", matrix[line + circle][column + circle]);
                    column++;
                }
                while(line + circle*2 != order - 1){
                    printf("%d ", matrix[line + circle][column + circle]);
                    line++;
                }
                while(column != 0){
                    printf("%d ", matrix[line + circle][column + circle]);
                    column--;
                }
                while(line != 0){
                    printf("%d ", matrix[line + circle][column + circle]);
                    line--;
                }
            }
            if(order%2==1){
                printf("%d", matrix[order/2][order/2]);
            }
        }
    
    return 0;
}

