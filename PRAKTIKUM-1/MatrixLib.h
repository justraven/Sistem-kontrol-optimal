#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

void input_matrix(int matrix[ROW][COL]);
void print_matrix(int matrix[ROW][COL]);
void print_minor_matrix(int matrix[ROW-1][COL-1]);

void transpose_matrix(int matrix_result[ROW][COL],int matrix_input[ROW][COL]);
void get_cofactor(int matrix_result[ROW-1][COL-1],int matrix_input[ROW][COL],int n,int target_row,int target_col);
void minor_matrix(int matrix_result[ROW-1][COL-1],int matrix_input[ROW][COL]);
void invers_matrix(float matrix_result[ROW][COL],int matrix_input[ROW][COL],float determinant);

void add_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]);
void subtract_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_result_2[ROW][COL]);
void multiply_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]);

float determinant_matrix(int matrix[ROW][COL]);

void input_matrix(int matrix[ROW][COL]){

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++){
            printf("matrix[%d][%d] = ",x,y);
            scanf("%d",&matrix[x][y]);
        }
    }
    
    printf("\n");

}

void print_matrix(int matrix[ROW][COL]){

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++){
            printf("%d ",matrix[x][y]);
            if (y == ROW - 1) printf("\n");
        }
    }
    printf("\n");
}

void print_minor_matrix(int matrix[ROW-1][COL-1]){
    
    for (int x = 0; x < ROW-1; x++){
        for (int y = 0; y < COL-1; y++){
            printf("%d ",matrix[x][y]);
            if (y == ROW - 2) printf("\n");
        }
    }
    printf("\n");
}

void transpose_matrix(int matrix_result[ROW][COL],int matrix_input[ROW][COL]){

    int matrix_tmp[ROW][COL];

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++)
            matrix_tmp[y][x] = matrix_input[x][y];
    }

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++)
            matrix_result[x][y] = matrix_tmp[x][y];
    }
}

void add_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]){

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++)
            matrix_result[x][y] = matrix_input_1[x][y] + matrix_input_2[x][y];
    }
}

void subtract_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]){

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++)
            matrix_result[x][y] = matrix_input_1[x][y] - matrix_input_2[x][y];
    }
}

void multiply_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]){

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++){
            matrix_result[x][y] = 0;
            for (int z = 0; z < COL; z++)
                matrix_result[x][y] += matrix_input_1[x][z]*matrix_input_2[z][y];
        }
    }
}

float determinant_matrix(int matrix[ROW][COL]){

    float a=0,b=0,c=0;

    if (ROW == 3 && COL == 3) {

        a = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]);
        b = matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]);
        c = matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);

        return a-b+c;
    }

    else if (ROW == 2 && COL == 2) {

        a = matrix[0][0]*matrix[1][1];
        b = matrix[0][1]*matrix[1][0];

        return a-b;

    }

}

void get_cofactor(int matrix_result[ROW-1][COL-1],int matrix_input[ROW][COL],int dimension,int target_row,int target_col){

    int minor_row=0,minor_col=0;

    for (int x = 0; x < ROW; x++){
        for (int y = 0; y < COL; y++){
            if(x != target_row && y != target_col)
                matrix_result[minor_row][minor_col++] = matrix_input[x][y];

                if(minor_col == dimension - 1){ // dimension of matrix
                    minor_col = 0;              // reset col
                    minor_row++;                // add new row
                }
        }
    }
}

void minor_matrix(int matrix_result[ROW-1][COL-1],int matrix_input[ROW][COL]){

    for (int x = 0; x < ROW; x++){
        for(int y = 0; y < COL; y++){
            get_cofactor(matrix_result,matrix_input,3,x,y);
            printf("minor matrix [%d][%d] : \n",x,y);
            print_minor_matrix(matrix_result);
        }
    }
}

#endif