#include "GaussJordan.h"

int input_function[3][3] = {0,    3,  7,
                            -3,   0,  0,
                            7,    0,  0};

int output_x[3][3];
int output_y[3][3];

float nilai_x = 0.0;
float nilai_y = 0.0;

int turunan_x2[3][3];
int turunan_y2[3][3];

int main(void){

    printf("Input fungsi : \n");
    print_function_matrix(3,3,input_function);

    // printf("turunan fungsi terhadap x : \n");
    // get_differential_multivar(3,3,1,0,input_function,output_x);
    // print_function_matrix(3,3,output_x);
    // printf("turunan fungsi terhadap y : \n");
    // get_differential_multivar(3,3,0,1,input_function,output_y);
    // print_function_matrix(3,3,output_y);

    // nilai_x = ((float)output_x[0][0] / (float)output_x[0][1]) * -1 ;
    // nilai_y = ((float)output_y[0][0] / (float)output_y[1][0]) * -1 ;

    // printf("Nilai critical point x: %0.2f\n",nilai_x);
    // printf("Nilai critical point y: %0.2f\n",nilai_y);

    int out = uji_definitess(3,3,input_function);

    if(out > 0 ) printf("Determinan = %d .Merupakan definit positif, nilai minimum\n",out);
    else if(out < 0) printf("Determinan = %d .Merupakan definit negatif, nilai maksimum\n",out);

    return 0;
}