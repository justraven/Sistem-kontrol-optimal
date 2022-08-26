#define ROW 3
#define COL 3

#include "MatrixLib.h"

int A[ROW][COL];
int B[ROW-1][COL-1];

int main(){

    input_matrix(A);
    printf("Elemen Matrix A : \n");
    print_matrix(A);
    printf("determinan Matrix A : %0.2f\n",determinant_matrix(A));
    minor_matrix(B,A);
    print_minor_matrix(B);

    return 0;
}

