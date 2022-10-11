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

    switch(MathOperation.getTranspose(&A,&C)){
        case ERR_MATRIX_DIMENSION :
            printf("[math_op][transpose] matrix is not symmetric!\n");
            break;

        case OK :
            printf("[math_op][transpose] ans : \n");
            matrix.printMatrix(&C);
            break;

    }

    switch (MathOperation.add(&A,&B,&C)){
        case ERR_MATRIX_SIZE :
            printf("[math_op][add] row/col size doesn't match!");
            break;
        case OK :
            printf("[math_op][add] ans : \n");
            matrix.printMatrix(&C);
            break;
    }

    switch(MathOperation.subtract(&A,&B,&C)){
        case  ERR_MATRIX_SIZE :
            printf("[math_op][subtract] row/col size doesn't match!\n");
        case OK :
            printf("[math_op][subtract] ans :\n");
            matrix.printMatrix(&C);
            break;
    }

    switch(MathOperation.multiply(&A,&B,&C)){
        case  ERR_MATRIX_SIZE :
            printf("[math_op][multiply] row/col size doesn't match!\n");
        case OK :
            printf("[math_op][multiply] ans :\n");
            matrix.printMatrix(&C);
            break;
    }

    switch(MathOperation.getDeterminant(&A,&result)){
        case ERR_MATRIX_DIMENSION :
            printf("[math_op][determinant] matrix is not symmetric!");
        case ERR_CALCULATION :
            printf("[math_op][determinant] diagonal operation error!");
        case OK :
            printf("[math_op][determinant] ans : %0.2f\n",(double)result.determinant);
            break;
    }

    switch(MathOperation.getMinorMatrix(&A,&result)){
        case ERR_MATRIX_SIZE :
            printf("[math_op][minor] row / col is less than 3!");
            break;
        case ERR_MATRIX_DIMENSION :
            printf("[math_op][minor] matrix is not symmetric!");
            break;
        case OK :
            printf("[math_op][minor] ans : \n");
            // MathOperation.printMinorMatrix(&result);
            break;
    }

    return 0;
}