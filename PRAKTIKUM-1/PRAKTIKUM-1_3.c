#define ROW 3
#define COL 3
#define DIMENSION 3

#include "MatrixLib.h"

int A[ROW][COL] = {1,2,3,4,5,6,7,8,9}; 
int B[ROW-1][COL-1];

int main(){

    input_matrix(A);
    printf("Elemen Matrix A : \n");
    print_matrix(A);
    printf("determinan Matrix A : %0.2f\n\n",determinant_matrix(A));
    minor_matrix(B,A);

    return 0;
}

