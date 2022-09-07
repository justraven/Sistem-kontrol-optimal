#define ROW 2
#define COL 2

#include "MatrixLib.h"

struct matrix_t{
    int data[2][2];
};

struct matrix_t A,B,P, C,D,E, F;

int main (){

    // Berapakah hasil dari persamaan berikut:
    // A^T+P*A-B = C+P*A-B
    // Dengan nilai matriks A, P dan B ditentukan oleh kalian sendiri

    printf("Masukkan nilai untuk matriks A : \n");
    input_matrix(ROW,COL,A.data);
    printf("Masukkan nilai untuk matriks B : \n");
    input_matrix(ROW,COL,B.data);
    printf("Masukkan nilai untuk matriks P : \n");
    input_matrix(ROW,COL,P.data);

    printf("Matrix A :\n");
    print_matrix(ROW,COL,A.data);
    printf("Matrix B :\n");
    print_matrix(ROW,COL,B.data);
    printf("Matrix P :\n");
    print_matrix(ROW,COL,P.data);

    multiply_matrix(ROW,COL,C.data,P.data,A.data);
    printf("P * A : \n");
    print_matrix(ROW,COL,C.data);

    transpose_matrix(ROW,COL,A.data,A.data);
    printf("Transpose matrix A : \n");
    print_matrix(ROW,COL,A.data);

    add_matrix(ROW,COL,D.data,A.data,C.data);
    printf("A^T + [P * A] : \n");
    print_matrix(ROW,COL,D.data);

    subtract_matrix(ROW,COL,E.data,D.data,B.data);
    printf("[A^T + [P * A]] - B : \n");
    print_matrix(ROW,COL,E.data);

    return 0;
}