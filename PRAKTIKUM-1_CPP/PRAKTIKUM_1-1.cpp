#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "MatrixLib.h"
#include "MatrixMathOp.h"

Matrix_t A,B,C;
Matrix matrix;
MatrixMathOperation MathOperation;
MatrixMathOperation_t result;

float determinant;

int main(){

    matrix.setMatrix(&A,3,3);
    matrix.setMatrix(&B,2,2);
    matrix.setMatrix(&C,2,2);

    printf("[matrix][input] masukkan nilai matrix : \n");
    matrix.inputMatrix(&A);
    matrix.inputMatrix(&B);
    printf("[matrix][print] nilai matrix : \n");
    matrix.printMatrix(&A);
    matrix.printMatrix(&B);

    if(MathOperation.getTranspose(&A,&C) == ERR_MATRIX_DIMENSION)
        printf("[math_op][getTranspose] matrix is not symmetric!\n");
    else{
        printf("[math_op][getTranspose] ans :\n");
        matrix.printMatrix(&C);
    }

    if(MathOperation.add(&A,&B,&C) == ERR_MATRIX_SIZE)
        printf("[math_op][add] row/col size doesn't match!\n");
    else{
        printf("[math_op][add] ans :\n");
        matrix.printMatrix(&C);
    }

    if(MathOperation.subtract(&A,&B,&C) == ERR_MATRIX_SIZE)
        printf("[math_op][subtract] row/col size doesn't match!\n");
    else{
        printf("[math_op][subtract] ans :\n");
        matrix.printMatrix(&C);
    }

    if(MathOperation.multiply(&A,&B,&C) == ERR_MATRIX_SIZE)
        printf("[math_op][multiply] row/col size doesn't match!\n");
    else{
        printf("[math_op][multiply] ans :\n");
        matrix.printMatrix(&C);
    }

    if(MathOperation.getDeterminant(&A,&result) == ERR_MATRIX_DIMENSION)
        printf("[math_op][determinant] matrix is not symmetric!");
    else if(MathOperation.getDeterminant(&A,&result) == ERR_CALCULATION)
        printf("[math_op][determinant] diagonal operation error!");
    else
        printf("Hasil : %0.2f\n",(double)result.determinant);

    return 0;
}