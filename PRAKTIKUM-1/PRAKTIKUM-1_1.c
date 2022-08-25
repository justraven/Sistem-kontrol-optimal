#define ROW 2
#define COL 2

#include "MatrixLib.h"


int main(void){
    
    int A[ROW][COL],    B[ROW][COL],    C[ROW][COL];

    // INPUT MATRIX
    input_matrix(A);
    printf("Print Matrix A : \r\n");
    print_matrix(A);

    input_matrix(B);
    printf("Print Matrix B : \r\n");
    print_matrix(B);

    // ADD MATRIX
    add_matrix(C,A,B);
    printf("Add Matrix : \r\n");
    print_matrix(C);

    // SUBTRACT MATRIX
    subtract_matrix(C,A,B);
    printf("Subtract Matrix : \r\n");
    print_matrix(C);

    // MULTIPLY MATRIX
    multiply_matrix(C,A,B);
    printf("Multiply Matrix : \r\n");
    print_matrix(C);

    //TRANSPOSE MATRIX
    transpose_matrix(A,A);
    printf("Transpose Matrix A : \r\n");
    print_matrix(A);

    transpose_matrix(B,B);
    printf("Transpose Matrix B : \r\n");
    print_matrix(B);

    return 0;   
}