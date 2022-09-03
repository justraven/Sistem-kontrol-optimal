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

    transpose_matrix(ROW,COL,C.data,A.data);  // C = A^T
    printf("Hasil transpose matriks A : \n");
    print_matrix(ROW,COL,C.data);

    printf("Hasil penjumlahan A^T dengan P : \n");
    add_matrix(ROW,COL,D.data,C.data,P.data);      // D = A^T+P ==> C + P
    print_matrix(ROW,COL,D.data);

    printf("Hasil perkalian [A^T+P] dengan A : \n");
    multiply_matrix(ROW,COL,E.data,D.data,A.data); // E = [A^T+P] * A ==> D * A
    print_matrix(ROW,COL,E.data);

    printf("Hasil pengurangan [A^T+P*A] dengan B : \n");
    subtract_matrix(ROW,COL,F.data,E.data,B.data); // F = [A^T+P*A] - B ==> F - B
    print_matrix(ROW,COL,F.data);

    return 0;
}