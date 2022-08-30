#define ROW 3
#define COL 3

#define MINOR_ROW ROW-1
#define MINOR_COL COL-1

#define DIMENSION 3

#include "MatrixLib.h"

int A[ROW][COL] = {1,2,3,0,1,4,5,6,0};
int B[ROW][COL][MINOR_ROW][MINOR_COL];
int C[ROW][COL];
float D[ROW][COL];

int main(){

    // input_matrix(A);
    printf("Elemen Matrix A : \n");
    print_matrix(A);
    printf("determinan Matrix A : %0.2f\n\n",determinant_matrix(A));
    minor_matrix(B,A,DIMENSION);
    print_minor_matrix(B);
    get_cofactor(C,B);
    printf("cofactor matrix :\n");
    print_matrix(C);
    printf("adjoint matrix :\n"); //adjoint is transpose of cofactor matrix
    transpose_matrix(C,C);
    print_matrix(C);
    printf("Invers matrix : \n");
    invers_matrix(D,C,determinant_matrix(A));
    print_float_matrix(D);

    return 0;
}