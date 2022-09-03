#ifndef CALCULUS_LIB_H
#define CALCULUS_LIB_H

#define print_function_matrix(row,col,matrix) print_matrix(row,col,matrix)
#define print_hessian(row_1,col_1,row_2,col_2,matrix) print_sub_matrix(row_1,col_1,row_2,col_2,matrix)

#include <stdio.h>
#include <stdlib.h>

struct matrix_t{
    int row;
    int col;
    int data[4][4];
};

static int step [4][2] = {2,0,
                          1,1,
                          1,1,
                          0,2};

static struct matrix_t matrix[2][2];

static int get_factorial(int x);

void get_integral(int poly_index,float function_input[poly_index],float function_output[poly_index + 1]);
void get_differential(int poly_index,float function_input[poly_index],float function_output[poly_index - 1]);

void get_differential_multivar(int row,int col, int diff_x, int diff_y, int function_input[row][col], int function_output[row][col]);
void hessian_matrix(int row, int col,int function_input[row][col]);

void print_function(int poly_index,float function[poly_index]);

int get_factorial(int x){

    int a = 1;

    for(int i = 0; i < x; i++){
        a = a*(i+1);
    }
    return a;
}

void get_integral(int poly_index,float function_input[poly_index],float function_output[poly_index + 1]){

    for (int i = 0; i < poly_index; i++){
        function_output[i+1] = function_input[i] / (i+1);
    }
}

void get_differential(int poly_index,float function_input[poly_index],float function_output[poly_index - 1]){

    for (int i = 0; i < poly_index; i++){
        function_output[i-1] = function_input[i] * i;
    }
}

void get_differential_multivar(int row,int col, int diff_x, int diff_y, int function_input[row][col], int function_output[row][col]){

    int function_temp[row][col];

    if(diff_x != 0){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                int x = (diff_x != diff_y) ? (get_factorial(j)) : (j * diff_x);
                function_temp[i][j - diff_x] = function_input[i][j] * x;
            }
        }
    }
    else
        transfer_matrix(row,col,function_temp,function_input);

    if(diff_y != 0){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                int x = (diff_x != diff_y) ? (get_factorial(i)) : (i * diff_y);
                function_output[i - diff_y][j] = function_temp[i][j] * x;
            }
        }
    }
    else
        transfer_matrix(row,col,function_output,function_temp);

    for(int i = 0; i < row; i++){ // clean error value
        for(int j = 0; j < col; j++)
            if(i >= row - diff_y || j >= col - diff_x)
                function_output[i][j] = 0;
    }
}

void print_function(int poly_index,float function[poly_index]){

    printf("output function = [ ");
    
    for(int i = 0; i < poly_index; i++){
        printf("%0.2f ",function[i]);
    }
    printf("]\n");
}

void hessian_matrix(int row, int col,int function_input[row][col]){

    int x = 0;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){   
            printf("Matrix hessian [%d][%d] : \n",i,j);
            get_differential_multivar(row,col,step[x][0],step[x][1],function_input,matrix[i][j].data);
            print_function_matrix(row,col,matrix[i][j].data);
            x++;
        }
    }
}

#endif