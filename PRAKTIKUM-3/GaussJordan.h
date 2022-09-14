#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "../PRAKTIKUM-2/CalculusLib.h"

int turunan_x_2[3][3], turunan_y_2[3][3], turunan_x_y[3][3], turunan_y_x[3][3];


int uji_definitess(int row,int col, int matrix_input[row][col]){

    int a=0 ,b=0, c=0, d=0;

    get_differential_multivar(3,3,2,0,matrix_input,turunan_x_2);
    get_differential_multivar(3,3,1,1,matrix_input,turunan_x_y);
    get_differential_multivar(3,3,1,1,matrix_input,turunan_y_x);
    get_differential_multivar(3,3,0,2,matrix_input,turunan_y_2);

    print_function_matrix(3,3,turunan_x_y);

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++)
            a += turunan_x_2[x][y];
    }

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++)
            b += turunan_x_y[x][y];
    }

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++)
            c += turunan_y_x[x][y];
    }

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++)
            d += turunan_y_2[x][y];
    }

    printf("a : %d\n b : %d\n c : %d\n d : %d\n",a,b,c,d);

    return (a*d) - (b*c);

}

#endif