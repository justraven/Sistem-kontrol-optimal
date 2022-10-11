#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "newton_method.h"

float error = 0.01;
float currentError;
int iteration = 0;

float function[3][3] = {1, -1, 3,
                        -1, 0, 0,
                        7, 0, 0};

float hessian[2][2] = {0,0,
                       0,0};

float seed[2] = {0,0};
float f_x[2] = {0,0};
float DValue[2] = {0,0};

int main(void){

    printf("\n-------------------- ITERIASI %d --------------------\n", iteration);

    printf("\nx[%d] : { %0.3f , %0.3f }\n", iteration, seed[0],seed[1]);
    currentError = absError(3,3,seed,f_x,function);
    printf("f_x[%d] : { %0.3f , %0.3f } error : %0.3f \n",iteration, f_x[0], f_x[1] ,currentError);

    while (currentError > error){

        iteration++;

        printf("\n-------------------- ITERIASI %d --------------------\n", iteration);
        
        getHessian(3,3,function,hessian);
        printf("\n[hessian] ans :\n");
        printFunction(2,2,hessian);

        printf("\n[d]][%d] invers hessian matrix : \n", iteration - 1);
        getDValue(hessian,f_x,DValue);
        printf("[d][%d] * f(x[%d]) : { %0.3f , %0.3f }\n", iteration - 1, iteration - 1, DValue[0], DValue[1]);
        printf("[x][%d] : { %0.3f , %0.3f }\n", iteration - 1, seed[0], seed[1]);

        seed[0] = seed[0] + DValue[0];
        seed[1] = seed[1] + DValue[1];

        printf("x[%d] = x[%d] + d[%d]\n", iteration, iteration-1, iteration-1);
        printf("x[%d] = { %0.3f , %0.3f }\n", iteration, seed[0], seed[1]);

        currentError = absError(3,3,seed,f_x,function);
        printf("f_x[%d] : { %0.3f , %0.3f } error : %0.3f \n",iteration, f_x[0], f_x[1] ,currentError);

    }


    return 0;
}