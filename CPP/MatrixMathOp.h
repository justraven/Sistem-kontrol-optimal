#ifndef MATRIX_MATH_OP_H
#define MATRIX_MATH_OP_H

#include "MatrixLib.h"

typedef enum{

    OK,
    ERR_MATRIX_SIZE,
    ERR_MATRIX_DIMENSION,
    ERR_CALCULATION,
    ERR_FACTORIAL

}MatrixOp;

typedef struct{

    int cols = 0;
    int rows = 0;
    int LRow = 0; //layer row
    int LCol = 0; //layer col

    float determinant;

    float adjoint[4][4][64][64];
    float invers[4][4][64][64];
    float minor[4][4][64][64];

}MatrixMathOperation_t;

class MatrixMathOperation{

    private :

    public :

        void printFloatMatrix(MatrixMathOperation_t *mat);
        void printMinorMatrix(MatrixMathOperation_t *mat);
        void setRowLayer(MatrixMathOperation_t *mat, int rowLayerSize);
        void setColLayer(MatrixMathOperation_t *mat, int colLayerSize);

        int getRowSize(MatrixMathOperation_t *mat);
        int getColoumnSize(MatrixMathOperation_t *mat);

        MatrixOp getTranspose(Matrix_t *mat, Matrix_t *matrixResult);
        MatrixOp add(Matrix_t *matrixInput_1, Matrix_t *matrixInput_2, Matrix_t *matrixResult);
        MatrixOp subtract(Matrix_t *matrixInput_1, Matrix_t *matrixInput_2, Matrix_t *matrixResult);
        MatrixOp multiply(Matrix_t *matrixInput_1, Matrix_t *matrixInput_2, Matrix_t *matrixResult);
        MatrixOp getDeterminant(Matrix_t *mat, MatrixMathOperation_t *result);
        MatrixOp getMinorMatrix(Matrix_t *mat, MatrixMathOperation_t *result);
        MatrixOp getCofactor(Matrix_t *mat, MatrixMathOperation_t *result);
        MatrixOp getInvers(Matrix_t *mat, MatrixMathOperation_t *result);
        
};

int MatrixMathOperation::getRowSize(MatrixMathOperation_t *mat){
    return mat->rows;
}

int MatrixMathOperation::getColoumnSize(MatrixMathOperation_t *mat){
    return mat->cols;
}

void MatrixMathOperation::setRowLayer(MatrixMathOperation_t *mat, int rowLayerSize){
    mat->LRow = rowLayerSize;
}

void MatrixMathOperation::setColLayer(MatrixMathOperation_t *mat, int colLayerSize){
    mat->LCol = colLayerSize;
}

void MatrixMathOperation::printFloatMatrix(MatrixMathOperation_t *mat){

    printf("\n");

    for(int x = 0; x < getRowSize(mat); x++){
        for(int y = 0; y < getColoumnSize(mat); y++){
            printf("%0.2f\t",mat->minor[mat->LRow][mat->LCol][x][y]);
            if(y == getRowSize(mat) - 1) printf("\n\n");
        }
    }

    printf("\n");

}

void MatrixMathOperation::printMinorMatrix(MatrixMathOperation_t *mat){

    for(int x = 0; x < getRowSize(mat); x++){
        for(int y = 0; y < getColoumnSize(mat); y++){
            setRowLayer(mat,x);
            setColLayer(mat,y);

            printFloatMatrix(mat);
        }
    }



}

MatrixOp MatrixMathOperation::getTranspose(Matrix_t *mat, Matrix_t *matrixResult){

    Matrix matrix;

    if(mat->rows != mat->cols)
        return ERR_MATRIX_DIMENSION;

    for(int x = 0; x < matrix.getRowSize(matrixResult); x++){
        for(int y = 0; y < matrix.getColoumnSize(matrixResult); y++)
            matrixResult->data_int[matrixResult->LRow][matrixResult->LCol][x][y] = mat->data_int[mat->LRow][mat->LCol][y][x];
    }
    
    return OK;

}

MatrixOp MatrixMathOperation::add(Matrix_t *matrixInput_1, Matrix_t *matrixInput_2, Matrix_t *matrixResult){

    Matrix matrix;

    if((matrixInput_1->rows != matrixInput_2->rows) || (matrixInput_1->cols != matrixInput_2->cols))
        return ERR_MATRIX_SIZE;

    for(int x = 0; x < matrix.getRowSize(matrixResult); x++){
        for(int y = 0; y < matrix.getColoumnSize(matrixResult); y++)
            matrixResult->data_int[matrixResult->LRow][matrixResult->LCol][x][y] = matrixInput_1->data_int[matrixInput_1->LRow][matrixInput_1->LCol][x][y] + matrixInput_2->data_int[matrixInput_2->LRow][matrixInput_2->LCol][x][y];
    }
    
    return OK;
}

MatrixOp MatrixMathOperation::subtract(Matrix_t *matrixInput_1, Matrix_t *matrixInput_2, Matrix_t *matrixResult){

    Matrix matrix;

    if((matrixInput_1->rows != matrixInput_2->rows) || (matrixInput_1->cols != matrixInput_2->cols))
        return ERR_MATRIX_SIZE;

    for(int x = 0; x < matrix.getRowSize(matrixResult); x++){
        for(int y = 0; y < matrix.getColoumnSize(matrixResult); y++)
            matrixResult->data_int[matrixResult->LRow][matrixResult->LCol][x][y] = matrixInput_1->data_int[matrixInput_1->LRow][matrixInput_1->LCol][x][y] - matrixInput_2->data_int[matrixInput_2->LRow][matrixInput_2->LCol][x][y];
    }
    
    return OK;
}

MatrixOp MatrixMathOperation::multiply(Matrix_t *matrixInput_1, Matrix_t *matrixInput_2, Matrix_t *matrixResult){

    Matrix matrix;

    if((matrixInput_1->rows != matrixInput_2->cols) || (matrixInput_1->rows != matrixInput_2->cols))
        return ERR_MATRIX_SIZE;
    
    for(int x = 0; x < matrix.getRowSize(matrixResult); x++){
        for(int y = 0; y < matrix.getColoumnSize(matrixResult); y++){
            for(int z = 0; z < matrix.getColoumnSize(matrixResult); z++)
                matrixResult->data_int[matrixResult->LRow][matrixResult->LCol][x][y] += matrixInput_1->data_int[matrixInput_1->LRow][matrixInput_1->LCol][x][z] * matrixInput_2->data_int[matrixInput_2->LRow][matrixInput_2->LCol][z][y];
        }
    }

    return OK;

}

MatrixOp MatrixMathOperation::getDeterminant(Matrix_t *mat, MatrixMathOperation_t *result){//calculating determinant using gaussian elimination to make upper triangle matrix

    Matrix matrix;

    float ratio = 0.0;
    float result_tmp = 1.0;

    if(mat->rows != mat->cols)
        return ERR_MATRIX_DIMENSION;
    
    matrix.toFloatMatrix(mat);

    for(int y = 0; y < matrix.getColoumnSize(mat); y++){ //col
        for(int x = y + 1; x < matrix.getRowSize(mat); x++){ //row

            if(mat->data_float[mat->LRow][mat->LCol][y][y] == 0){
                result->determinant = 0;
                return ERR_CALCULATION;
            }

            if(x > y){

                ratio = mat->data_float[mat->LRow][mat->LCol][x][y] / mat->data_float[mat->LRow][mat->LCol][y][y];
                // printf("%f\n",ratio);

                for(int z = 0; z < matrix.getColoumnSize(mat); z++)
                    mat->data_float[mat->LRow][mat->LCol][x][z] = mat->data_float[mat->LRow][mat->LCol][x][z] - ratio * mat->data_float[mat->LRow][mat->LCol][y][z];

            }
        }
    }

    // matrix.printFloatMatrix(mat);

    for(int x = 0; x < matrix.getRowSize(mat); x++){
        result_tmp = result_tmp * mat->data_float[mat->LRow][mat->LCol][x][x];
        // printf("hasil : %0.2f \n",result_tmp);
    }

    result->determinant = result_tmp;

    return OK;

}

MatrixOp MatrixMathOperation::getMinorMatrix(Matrix_t *mat, MatrixMathOperation_t *result){

    Matrix matrix;

    if(mat->rows != mat->cols)
        return ERR_MATRIX_DIMENSION;
    if(mat->rows < 3 || mat->cols < 3)
        return ERR_MATRIX_SIZE;

    result->rows = mat->rows - 1;
    result->cols - mat->cols - 1;

    matrix.toFloatMatrix(mat);

    for(int targetRow = 0; targetRow < matrix.getRowSize(mat); targetRow++){
        for(int targetCol = 0; targetCol < matrix.getColoumnSize(mat); targetCol++){

            setRowLayer(result,targetRow);
            setColLayer(result,targetCol);

            int minorRow = 0, minorCol = 0;

            for(int x; x < matrix.getRowSize(mat); x++){
                for(int y; y < matrix.getColoumnSize(mat); y++){
                    if(x != targetRow && y != targetCol)
                        result->minor[result->LRow][result->LCol][minorRow][minorCol++] = mat->data_float[mat->LRow][mat->LCol][x][y];
                    
                    if(minorRow == matrix.getRowSize(mat) - 1){ // dimensi diwakili oleh row
                        minorCol = 0;
                        minorRow++;
                    }
                }
            }
        }
    }

    printMinorMatrix(result);

    return OK;
}

MatrixOp MatrixMathOperation::getCofactor(Matrix_t *mat, MatrixMathOperation_t *result){

    return OK;
}

MatrixOp MatrixMathOperation::getInvers(Matrix_t *mat, MatrixMathOperation_t *result){


    return OK;
}

#endif