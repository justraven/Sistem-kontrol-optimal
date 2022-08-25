#define ROW 2
#define COL 2

#include "MatrixLib.h"

int A[ROW][COL],B[ROW][COL],P[ROW][COL],    C[ROW][COL],D[ROW][COL],E[ROW][COL],F[ROW][COL];

int main (){

    // Berapakah hasil dari persamaan berikut:
    // A^T+P*A-B = C+P*A-B
    // Dengan nilai matriks A, P dan B ditentukan oleh kalian sendiri

    printf("Masukkan nilai untuk matriks A : \n");
    input_matrix(A);
    printf("Masukkan nilai untuk matriks B : \n");
    input_matrix(B);
    printf("Masukkan nilai untuk matriks P : \n");
    input_matrix(P);

    transpose_matrix(C,A);  // C = A^T
    printf("Hasil transpose matriks A : \n");
    print_matrix(C);

    printf("Hasil penjumlahan A^T dengan P : \n");
    add_matrix(D,C,P);      // D = A^T+P ==> C + P
    print_matrix(D);

    printf("Hasil perkalian [A^T+P] dengan A : \n");
    multiply_matrix(E,D,A); // E = [A^T+P] * A ==> D * A
    print_matrix(E);

    printf("Hasil pengurangan [A^T+P*A] dengan B : \n");
    subtract_matrix(F,E,B); // F = [A^T+P*A] - B ==> F - B
    print_matrix(F);

    return 0;
}