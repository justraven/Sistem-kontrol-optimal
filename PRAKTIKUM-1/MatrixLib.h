#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

void input_matrix(int matrix[ROW][COL]);
void print_matrix(int matrix[ROW][COL]);
void transpose_matrix(int matrix_result[ROW][COL],int matrix_input[ROW][COL]);
void add_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]);
void subtract_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_result_2[ROW][COL]);
void multiply_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]);

void input_matrix(int matrix[ROW][COL]){

    int x,y;

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++){
            printf("matrix[%d][%d] = ",x,y);
            scanf("%d",&matrix[x][y]);
        }
    }
    
    printf("\n");

}

void print_matrix(int matrix[ROW][COL]){

    int x,y;

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++){
            printf("%d ",matrix[x][y]);
            if (y == ROW - 1) printf("\n");
        }
    }
    printf("\n");
}

void transpose_matrix(int matrix_result[ROW][COL],int matrix_input[ROW][COL]){

    int x,y;

    int matrix_tmp[ROW][COL];

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++)
            matrix_tmp[y][x] = matrix_input[x][y];
    }

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++)
            matrix_result[x][y] = matrix_tmp[x][y];
    }
}

void add_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]){

    int x,y;

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++)
            matrix_result[x][y] = matrix_input_1[x][y] + matrix_input_2[x][y];
    }
}

void subtract_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]){

    int x,y;

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++)
            matrix_result[x][y] = matrix_input_1[x][y] - matrix_input_2[x][y];
    }
}

void multiply_matrix(int matrix_result[ROW][COL],int matrix_input_1[ROW][COL],int matrix_input_2[ROW][COL]){

    int x,y,z;

    for (x = 0; x < ROW; x++){
        for (y = 0; y < COL; y++){
            matrix_result[x][y] = 0;
            for (z = 0; z < COL; z++)
                matrix_result[x][y] += matrix_input_1[x][z]*matrix_input_2[z][y];
        }
    }
}

#endif