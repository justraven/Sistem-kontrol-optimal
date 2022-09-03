#include "MatrixLib.h"
#include "MatrixOp.h"

int main(){

    matrix A(3,3);
    matrix B(3,3);

    A.inputMatrix();
    A.printMatrix();
    A.transpose();
    A.setLayer(1);
    A.printMatrix();

    return 0;
}