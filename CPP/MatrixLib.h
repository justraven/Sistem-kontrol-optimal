#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

typedef struct{

    int cols = 0;
    int rows = 0;
    int LRow = 0; //layer row
    int LCol = 0; //layer col

    int data_int[4][4][64][64];
    float data_float[4][4][64][64];

}Matrix_t;

class Matrix{

    public :

        void setMatrix(Matrix_t *matrix, int row, int col);

        void inputMatrix(Matrix_t *matrix);
        void printMatrix(Matrix_t *matrix);
        void printSubMatrix(Matrix_t *matrix);

        void toFloatMatrix(Matrix_t *matrix);
        void printFloatMatrix(Matrix_t *matrix);

        int getColoumnSize(Matrix_t *matrix){return matrix->cols;}
        int getRowSize(Matrix_t *matrix){return matrix->rows;}

        void setValue(Matrix_t *matrix, int row, int col, int value);
        int getValue(Matrix_t *matrix, int row, int col);

        void setRowLayer(Matrix_t *matrix, int rowLayerSize);
        void setColLayer(Matrix_t *matrix, int colLayerSize);

        int getRowLayer(Matrix_t *matrix);
        int getColLayer(Matrix_t *matrix);
        
};

void Matrix::setMatrix(Matrix_t *matrix, int row, int col){
    matrix->rows = row;
    matrix->cols = col;
}

void Matrix::setValue(Matrix_t *matrix, int row, int col, int value){
    matrix->data_int[matrix->LRow][matrix->LCol][row][col] = value;
}

void Matrix::setRowLayer(Matrix_t *matrix, int rowLayerSize){
    matrix->LRow = rowLayerSize;
}
void Matrix::setColLayer(Matrix_t *matrix, int colLayerSize){
    matrix->LCol = colLayerSize;
}

int Matrix::getValue(Matrix_t *matrix, int row, int col){
    return matrix->data_int[matrix->LRow][matrix->LCol][row][col];
}

int Matrix::getRowLayer(Matrix_t *matrix){
    return matrix->LRow;
}

int Matrix::getColLayer(Matrix_t *matrix){
    return matrix->LCol;
}

void Matrix::inputMatrix(Matrix_t *matrix){

    printf("\n");

    for(int x = 0; x < getRowSize(matrix); x++){
        for(int y = 0; y < getColoumnSize(matrix); y++){
            printf("matrix[%d][%d] : ",x,y);
            scanf("%d",&matrix->data_int[matrix->LRow][matrix->LCol][x][y]);
        }
    }

    printf("\n");

}

void Matrix::printMatrix(Matrix_t *matrix){

    printf("\n");

    for(int x = 0; x < getRowSize(matrix); x++){
        for(int y = 0; y < getColoumnSize(matrix); y++){
            printf("%d\t",matrix->data_int[matrix->LRow][matrix->LCol][x][y]);
            if(y == getRowSize(matrix) - 1) printf("\n\n");
        }
    }

    printf("\n");

}

void Matrix::printFloatMatrix(Matrix_t *matrix){

    printf("\n");

    for(int x = 0; x < getRowSize(matrix); x++){
        for(int y = 0; y < getColoumnSize(matrix); y++){
            printf("%0.2f\t",matrix->data_float[matrix->LRow][matrix->LCol][x][y]);
            if(y == getRowSize(matrix) - 1) printf("\n\n");
        }
    }

    printf("\n");

}

void Matrix::toFloatMatrix(Matrix_t *matrix){

    for(int x = 0; x < getRowSize(matrix); x++){
        for(int y = 0; y < getColoumnSize(matrix); y++)
            matrix->data_float[matrix->LRow][matrix->LCol][x][y] = (float)matrix->data_int[matrix->LRow][matrix->LCol][x][y];
    }
}

void Matrix::printSubMatrix(Matrix_t *matrix){

    for(int x = 0; x < getRowSize(matrix); x++){
        for(int y = 0; y < getColoumnSize(matrix); y++){
            
            setRowLayer(matrix,x);
            setColLayer(matrix,y);

            printFloatMatrix(matrix);

        }
    }
}



#endif