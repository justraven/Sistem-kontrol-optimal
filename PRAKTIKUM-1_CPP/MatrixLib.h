#ifndef MATRIX_LIB_H
#define MATRIX_LIB_H

#define getVarName(VariableName)

#include <cstdio>
#include <cstdlib>

class matrix{

    private :

        int rows = 0;
        int cols = 0;
        int layer = 0;
        int data[4][64][64];
    
    public :

        matrix(int rows_,int cols_){
            cols = cols_;
            rows = rows_;
        }

        void setValue(int rows, int cols, int value);
        void setLayer(int layer);

        int getColsSize(void){return cols;};
        int getRowsSize(void){return rows;};
        int getValue(int rows, int cols);
        int getLayer(void);

        void inputMatrix(void);
        void printMatrix(void);

        float determinant(void);

        void invers(void);
        void transpose(void);
        void minor(void);
        void cofactor(void);

};

void matrix::setValue(int rows,int cols, int value){data[layer][rows][cols] = value;}
void matrix::setLayer(int layerSize){layer = layerSize;}

int matrix::getValue(int rows, int cols){return data[layer][rows][cols];}
int matrix::getLayer(void){return layer;}

void matrix::inputMatrix(void){

    int i = 0;

    printf("\n");

    for(int x = 0; x < getRowsSize(); x++){
        for(int y=0; y < getColsSize(); y++){
            printf("matrix[%d][%d] : ",x,y);
            scanf("%d",&data[layer][x][y]);
        }
    }
    printf("\n");
}

void matrix::printMatrix(){

    printf("\n");

    for(int x = 0; x < getRowsSize(); x++){
        for(int y=0; y < getColsSize(); y++){
            printf("%d\t",data[layer][x][y]);
            if(y == getRowsSize() - 1) printf("\n\n");
        }
    }
    printf("\n");
}

void matrix::transpose(void){

    printf("\n");

    for(int x = 0; x < getRowsSize(); x++){
        for(int y = 0; y < getColsSize(); y++)
            data[layer + 1][y][x] = data[layer][x][y];
    }

}

#endif