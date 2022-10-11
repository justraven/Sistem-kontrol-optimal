#ifndef NEWTON_METHOD_H
#define NEWTON_METHOD_H

float turunan_x_2[3][3], turunan_x_y[3][3], turunan_y_x[3][3], turunan_y_2[3][3];
float turunan_x[3][3], turunan_y[3][3];

int getFactorial(int x);

void transferMatrix(int row, int col, float functionOutput[row][col], float functionInput[row][col]);
void getDifferential(int row, int col, int diff_x, int diff_y, float functionInput[row][col], float functionOutput[row][col]);
void getGradient(int row, int col, float functionInput[row][col]);
void getHessian(int row, int col, float functionInput[row][col], float hessian[2][2]);
void printFunction(int row, int col, float functionInput[row][col]);

float absError(int row, int col, float seed[2], float f_x[2], float functionInput[row][col]);
float calcError(int row, int col,int target ,float seedVar[2], float functionInput[row][col]);

int getFactorial(int x){

    int a = 1;

    for(int i = 0; i < x; i++){
        a = a * (i+1);
    }

    return a;
}

void transferMatrix(int row, int col, float functionOutput[row][col], float functionInput[row][col]){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            functionOutput[i][j] = functionInput[i][j];
        }
    }
}

void getDifferential(int row, int col, int diff_x, int diff_y, float functionInput[row][col], float functionOutput[row][col]){

    float functionTemp[row][col];

    if(diff_x != 0){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int x = (diff_x > 1) ? (getFactorial(j)) : j;
                functionTemp[i][j - diff_x] = functionInput[i][j] * (float)x;
            }
        }
    }
    else{
        transferMatrix(row,col,functionTemp,functionInput);
    }

    if(diff_y != 0){
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int y = (diff_y > 1) ? (getFactorial(i)) : i;
                functionOutput[i - diff_y][j] = functionTemp[i][j] * (float)y;
            }
        }
    }
    else{
        transferMatrix(row,col,functionOutput,functionTemp);
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            if(i >= row-diff_y || j >= col-diff_x)
                functionOutput[i][j] = 0;
    }
}

void getGradient(int row, int col, float functionInput[row][col]){
    
    getDifferential(row,col,1,0,functionInput,turunan_x);
    // printFunction(row,col,turunan_x);
    getDifferential(row,col,0,1,functionInput,turunan_y);
    // printFunction(row,col,turunan_y);

}

void getHessian(int row, int col, float functionInput[row][col], float hessian[2][2]){
    
    getDifferential(row,col,2,0,functionInput,turunan_x_2);
    getDifferential(row,col,1,1,functionInput,turunan_x_y);
    getDifferential(row,col,1,1,functionInput,turunan_y_x);
    getDifferential(row,col,0,2,functionInput,turunan_y_2);

    // printFunction(row,col,turunan_x_2);
    // printFunction(row,col,turunan_x_y);
    // printFunction(row,col,turunan_y_x);
    // printFunction(row,col,turunan_y_2);

    for(int i=0; i<row; i++){
        for(int j=0; i<col; i++){
            hessian[0][0] += turunan_x_2[i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; i<col; i++){
            hessian[0][1] += turunan_x_y[i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; i<col; i++){
            hessian[1][0] += turunan_y_x[i][j];
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; i<col; i++){
            hessian[1][1] += turunan_y_2[i][j];
        }
    }
}

float calcError(int row, int col,int target ,float seedVar[2], float functionInput[row][col]){

    float functionTemp[row][col];

    float result = 0.0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int x = (target != 1) ? j : i;
            functionTemp[i][j] = functionInput[i][j] * pow(seedVar[target],x);
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            result += functionTemp[i][j];
        }
    }

    return result;

}

float absError(int row, int col, float seed[2], float f_x[2], float functionInput[row][col]){

    getGradient(row,col,functionInput);

    float valueTemp[2];
    float result;

    valueTemp[0] = calcError(row,col,0,seed,turunan_x);
    valueTemp[1] = calcError(row,col,1,seed,turunan_y);

    result = sqrt(pow(valueTemp[0],2) + pow(valueTemp[1],2));

    f_x[0] = valueTemp[0];
    f_x[1] = valueTemp[1];

    return result;

}

void getDValue(float hessian[2][2], float f_x[2], float DValue[2]){

    float matrixTemp[2][2];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            matrixTemp[1-i][1-j] = hessian[i][j] * -1/(hessian[0][0]*hessian[1][1]);
        }
    }

    printFunction(2,2,matrixTemp);

    for(int i=0; i < 2; i++)
        DValue[i] = matrixTemp[i][i] * f_x[i];

}

void printFunction(int row, int col, float functionInput[row][col]){

    printf("\n");

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%0.3f\t", functionInput[i][j]);
            if(j == row - 1)printf("\n\n");
        }
    }

    printf("\n");

}

#endif