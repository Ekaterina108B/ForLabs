#include <stdio.h>

int main(void){
    int order = 0;
    scanf("%d", &order);
    int matrix[order][order];
    int line = 0, column = 0, min_elem = 10000000;
    if(order == 1){
        scanf("%d", &matrix[0][0]);
        printf("%d\n", matrix[0][0]*matrix[0][0]);
    }
    else{
        for(int i = 0; i < order; i++){
            for (int j = 0; j < order; j++){
                scanf("%d", &matrix[i][j]);
            }
        }
        
        printf("\n");
        for(line = 0; line<order; line++){
            for(column = 0; column<order; column++){
                if((line >= column) && (min_elem > matrix[line][column])){
                    min_elem = matrix[line][column];
                }
            }
        }
        
        for(line = 0; line<order; line++){
            for(column = 0; column<order; column++){
                if(line <= column){
                    matrix[line][column]*=min_elem;
                }
            }
        }
        
        for(line = 0; line<order; line++){
            for(column = 0; column<order; column++){
                printf("%d ", matrix[line][column]);
            }
            printf("\n");
        }
    }    
        
    
    return 0;
}
