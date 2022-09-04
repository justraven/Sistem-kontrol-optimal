#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <math.h>

static int I[2][2] = {1,0,0,1};

static void input_matrix(int row, int col, int matrix[row][col]);
static void transfer_matrix(int row, int col, int matrix_output[row][col], int matrix_input[row][col]);
static void print_matrix(int row, int col, int matrix[row][col]);
static void print_float_matrix(int row, int col, float matrix[row][col]);
static void print_minor_matrix(int row, int col, int matrix[row][col][row - 1][col- 1]);
static void print_sub_matrix(int row_1, int col_1,int row_2, int col_2, int matrix[row_1][col_1][row_2][col_2]);

static void transpose_matrix(int row, int col, int matrix_result[row][col],int matrix_input[row][col]);
static void minor_matrix(int row, int col, int matrix_result[row][col][row - 1][col- 1],int matrix_input[row][col],int dimension);
static void get_cofactor(int row, int col, int matrix_result[row][col],int matrix_input[row][col][row - 1][col- 1]);
static void invers_matrix(int row, int col, float matrix_result[row][col],int matrix_input[row][col],float determinant);

static void add_matrix(int row, int col, int matrix_result[row][col],int matrix_input_1[row][col],int matrix_input_2[row][col]);
static void subtract_matrix(int row, int col, int matrix_result[row][col],int matrix_input_1[row][col],int matrix_input_2[row][col]);
static void multiply_matrix(int row, int col, int matrix_result[row][col],int matrix_input_1[row][col],int matrix_input_2[row][col]);

static float determinant_matrix(int row, int col, int matrix[row][col]);

static void input_matrix(int row, int col, int matrix[row][col]){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            printf("matrix[%d][%d] = ",x,y);
            scanf("%d",&matrix[x][y]);
        }
    }
    printf("\n");
}

static void print_matrix(int row, int col, int matrix[row][col]){

    printf("\n");
    
    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            printf("%d\t",matrix[x][y]);
            if (y == row - 1) printf("\n\n");
        }
    }
    printf("\n");
}

static void print_float_matrix(int row, int col, float matrix[row][col]){

    printf("\n");

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            printf("%0.2f\t",matrix[x][y]);
            if (y == row - 1) printf("\n\n");
        }
    }
    printf("\n");
}

static void print_minor_matrix(int row, int col, int matrix[row][col][row - 1][col- 1]){
    
    for(int v = 0; v < row; v++){
        for(int w = 0; w < col; w++){

            printf("Minor matrix [%d][%d] : \n",v,w);

            for (int x = 0; x < row - 1; x++){
                for (int y = 0; y < col- 1; y++){
                    printf("%d ",matrix[v][w][x][y]);
                    if (y == row - 2) printf("\n");
                }
            }
        printf("\n");

        }
    }
}

static void print_sub_matrix(int row_1, int col_1,int row_2, int col_2, int matrix[row_1][col_1][row_2][col_2]){
    
    for(int v = 0; v < row_1; v++){
        for(int w = 0; w < col_1; w++){

            printf("Matrix [%d][%d] : \n",v,w);

            for (int x = 0; x < row_2; x++){
                for (int y = 0; y < col_2; y++){
                    printf("%d ",matrix[v][w][x][y]);
                    if (y == row_2 - 1) printf("\n");
                }
            }
        printf("\n");

        }
    }
}

static void transpose_matrix(int row, int col, int matrix_result[row][col],int matrix_input[row][col]){

    int matrix_tmp[row][col];

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++)
            matrix_tmp[y][x] = matrix_input[x][y];
    }

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++)
            matrix_result[x][y] = matrix_tmp[x][y];
    }
}

static void add_matrix(int row, int col, int matrix_result[row][col],int matrix_input_1[row][col],int matrix_input_2[row][col]){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++)
            matrix_result[x][y] = matrix_input_1[x][y] + matrix_input_2[x][y];
    }
}

static void subtract_matrix(int row, int col, int matrix_result[row][col],int matrix_input_1[row][col],int matrix_input_2[row][col]){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++)
            matrix_result[x][y] = matrix_input_1[x][y] - matrix_input_2[x][y];
    }
}

static void multiply_matrix(int row, int col, int matrix_result[row][col],int matrix_input_1[row][col],int matrix_input_2[row][col]){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            matrix_result[x][y] = 0;
            for (int z = 0; z < col; z++)
                matrix_result[x][y] += matrix_input_1[x][z]*matrix_input_2[z][y];
        }
    }
}

static float determinant_matrix(int row, int col, int matrix[row][col]){

    float a = 0,b = 0,c = 0;

    if (row == 3 && col == 3) {

        a = matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]);
        b = matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0]);
        c = matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);

        return a-b+c;
    }

    else if (row == 2 && col == 2) {

        a = matrix[0][0]*matrix[1][1];
        b = matrix[0][1]*matrix[1][0];

        return a-b;

    }
}

static void minor_matrix(int row, int col, int matrix_result[row][col][row - 1][col- 1],int matrix_input[row][col],int dimension){

    for(int target_row = 0; target_row < row; target_row++){
        for(int target_col = 0; target_col < col; target_col++){

            int minor_row = 0,minor_col = 0;

            for (int x = 0; x < row; x++){          // row matrix
                for (int y = 0; y < col; y++){      // col matrix
                    if(x != target_row && y != target_col)
                        matrix_result[target_row][target_col][minor_row][minor_col++] = matrix_input[x][y];

                    if(minor_col == dimension - 1){ // dimension of minor matrix
                        minor_col = 0;              // reset minor col
                        minor_row++;                // add new minor row
                    }
                }
            }
        }
    }
}

static void get_cofactor(int row, int col, int matrix_result[row][col],int matrix_input[row][col][row - 1][col- 1]){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            matrix_result[x][y] = (matrix_input[x][y][0][0]*matrix_input[x][y][1][1]) - (matrix_input[x][y][0][1]*matrix_input[x][y][1][0]);
        }
    }
}

static void invers_matrix(int row, int col, float matrix_result[row][col],int matrix_input[row][col],float determinant){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            matrix_result[x][y] = matrix_input[x][y] / fabs(determinant);
        }
    }
}

static void transfer_matrix(int row, int col, int matrix_result[row][col], int matrix_input[row][col]){

    for (int x = 0; x < row; x++){
        for (int y = 0; y < col; y++){
            matrix_result[x][y] = matrix_input[x][y];
        }
    }

}

#endif