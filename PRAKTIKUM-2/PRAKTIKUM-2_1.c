#define poly_x 3
#define poly_y 3

#define x_index poly_x + 1 //COL
#define y_index poly_y + 1 //ROW

#include "CalculusLib.h"

static int function_input[4][4] = {0,   0,  3,  0, // f(x,y) = x^3*y^3 + 3x^2 + y^2
                                   0,   0,  0,  0,
                                   1,   0,  0,  0,
                                   0,   0,  0,  1};

int function_output[4][4];

float function_exp[4] = {0,0,0,3}; // 3X^3
float function_out[4];

int main(){
    
    printf("Representasi fungsi polynomial dengan matrix :\n");
    print_function_matrix(y_index,x_index,function_input);
    printf("Hessian matrix : \n");
    hessian_matrix(y_index,x_index,function_input,2,-1);

    return 0;

}