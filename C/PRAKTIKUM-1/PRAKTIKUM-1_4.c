#include "MatrixLib.h"

static int A[2][2] = {3,0,
                      8,-1};

int main(){

    eigen_val(2,2,A);

    return 0;
}