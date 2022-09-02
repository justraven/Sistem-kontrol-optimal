#define poly_x 3
#define poly_y 3

#define x_index poly_x + 1 //COL
#define y_index poly_y + 1 //ROW

#include "../PRAKTIKUM-1/MatrixLib.h"
#include "CalculusLib.h"

int function_input[y_index][x_index] = {0,0,3,0, // merupakan representasi dari f(poly_x,poly_y) = poly_x^3*poly_y^3 + 3x^2 + poly_y^2
                                        0,0,0,0,
                                        1,0,0,0,
                                        0,0,0,1};

int function_output[y_index][x_index];
// int hessian_matrix[2][2][y_index][x_index];

int main(){
    
    printf("Representasi fungsi polynomial dengan matrix :\n");
    print_function_matrix(y_index,x_index,function_input);
    hessian_matrix(y_index,x_index,function_input,function_output);
    // get_differential_multivar(y_index,x_index,2,0,function_input,function_output);
    // print_function(y_index,x_index,function_output);

    return 0;
}