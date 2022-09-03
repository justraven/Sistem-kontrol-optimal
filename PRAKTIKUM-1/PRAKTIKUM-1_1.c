#define ROW 2
#define COL 2

#include "MatrixLib.h"

struct matrix_t{
    int data[2][2];
};

struct matrix_t A,B,C;

int main(void){
    
    // INPUT MATRIX
    input_matrix(ROW,COL,A.data);
    printf("Print Matrix A : \r\n");
    print_matrix(ROW,COL,A.data);

    input_matrix(ROW,COL,B.data);
    printf("Print Matrix B : \r\n");
    print_matrix(ROW,COL,B.data);

    // ADD MATRIX
    add_matrix(ROW,COL,C.data,A.data,B.data);
    printf("Add Matrix : \r\n");
    print_matrix(ROW,COL,C.data);

    // SUBTRACT MATRIX
    subtract_matrix(ROW,COL,C.data,A.data,B.data);
    printf("Subtract Matrix : \r\n");
    print_matrix(ROW,COL,C.data);

    // MULTIPLY MATRIX
    multiply_matrix(ROW,COL,C.data,A.data,B.data);
    printf("Multiply Matrix : \r\n");
    print_matrix(ROW,COL,C.data);

    //TRANSPOSE MATRIX
    transpose_matrix(ROW,COL,A.data,A.data);
    printf("Transpose Matrix A : \r\n");
    print_matrix(ROW,COL,A.data);

    transpose_matrix(ROW,COL,B.data,B.data);
    printf("Transpose Matrix B : \r\n");
    print_matrix(ROW,COL,B.data);

    return 0;   
}