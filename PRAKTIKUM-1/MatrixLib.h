#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

void input_matrix(int matrix[ROW][COL]);
void print_matrix(int matrix[ROW][COL]);
void print_minor_matrix(int matrix[ROW][COL][MINOR_ROW][MINOR_COL]);

void transpose_matrix(int matrix_result[ROW][COL],int matrix_input[ROW][COL]);
void minor_matrix(int matrix_result[ROW][COL][MINOR_ROW][MINOR_COL],int matrix_input[ROW][COL],int dimension);
// void minor_matrix(int matrix_result[MINOR_ROW][MINOR_COL],int matrix_input[ROW][COL]);
void invers_matrix(float matrix_result[ROW][COL],int matrix_input[ROW][COL],float determinant);

void add_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]);
void subtract_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]);
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

void print_minor_matrix(int matrix[ROW][COL][MINOR_ROW][MINOR_COL]){
    
    for(int v = 0; v < ROW; v++){
        for(int w = 0; w < COL; w++){

            printf("Minor matrix [%d][%d] : \n",v,w);

            for (int x = 0; x < MINOR_ROW; x++){
                for (int y = 0; y < MINOR_COL; y++){
                    printf("%d ",matrix[v][w][x][y]);
                    if (y == ROW - 2) printf("\n");
                }
            }
        printf("\n");

        }
    }
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

    float a = 0,b = 0,c = 0;

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

void minor_matrix(int matrix_result[ROW][COL][MINOR_ROW][MINOR_COL],int matrix_input[ROW][COL],int dimension){

    for(int target_row = 0; target_row < ROW; target_row++){
        for(int target_col = 0; target_col < COL; target_col++){

            int minor_row = 0,minor_col = 0;

            for (int x = 0; x < ROW; x++){          // row matrix
                for (int y = 0; y < COL; y++){      // col matrix
                    if(x != target_row && y != target_col)
                        matrix_result[target_row][target_col][minor_row][minor_col++] = matrix_input[x][y];

                    if(minor_col == dimension - 1){ // dimension of matrix
                        minor_col = 0;              // reset col
                        minor_row++;                // add new row
                    }

                }
            }

        }
    }
}

#endif