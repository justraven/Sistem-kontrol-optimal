//C program for calculating the Eigenvector of a 3 x 3 Matrix.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define R 3
#define C 3

//arrays using structs
struct MatrixArrayStruct
{
    float value[R][C];
};

struct VectorArrayStruct
{
    float value[C];
};

void printMatrix(struct MatrixArrayStruct matrix)
{
    int i, j;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%f ", matrix.value[i][j]);
        }
        printf("\n");
    }
}

void printVector(struct VectorArrayStruct vector)
{
    printf("(%f, %f, %f)", vector.value[0], vector.value[1], vector.value[2]);
}

struct VectorArrayStruct multiplyMatrixAndVector(struct MatrixArrayStruct matrix, struct VectorArrayStruct vector)
{
    struct VectorArrayStruct result;
    int i;
    for (i = 0; i < C; i++)
    {
        result.value[i] = matrix.value[i][0] * vector.value[0] + matrix.value[i][1] * vector.value[1] + matrix.value[i][2] * vector.value[2];
    }

    return result;
}

struct VectorArrayStruct takeLargestValueCommon(struct VectorArrayStruct vector)
{
    int i;
    float largest = 0;

    if (abs(vector.value[0]) > abs(vector.value[1]))
    {
        if (abs(vector.value[0]) > abs(vector.value[2]))
        {
            largest = vector.value[0];
        }
        else
        {
            largest = vector.value[2];
        }
    }
    else
    {
        if (abs(vector.value[1]) > abs(vector.value[2]))
        {
            largest = vector.value[1];
        }
        else
        {
            largest = vector.value[2];
        }
    }

    for (i = 0; i < C; i++)
    {
        vector.value[i] /= largest;
    }

    return vector;
}

int compareVectors(struct VectorArrayStruct v1, struct VectorArrayStruct v2, int decimalPlaces)
{
    int i;
    float maxAllowedError = pow(10, -1 * decimalPlaces) / 2;

    for (i = 0; i < C; i++)
    {
        if (abs(v1.value[i] - v2.value[i]) >= maxAllowedError)
        {
            return 0;
        }
    }
    return 1;
}

struct VectorArrayStruct EigenVectorOfMatrix(struct MatrixArrayStruct matrix, int decimalPlaces)
{    
    struct MatrixArrayStruct result;
    struct VectorArrayStruct vector, oldVector;
    int comparisonResult = 0;

    result = matrix;

    oldVector.value[0] = 1;
    oldVector.value[1] = 0;
    oldVector.value[2] = 0;

    while (comparisonResult == 0)
    {
        vector = multiplyMatrixAndVector(result, oldVector);
        vector = takeLargestValueCommon(vector);
        comparisonResult = compareVectors(vector, oldVector, decimalPlaces);
        oldVector = vector;
    }

    return vector;
}

int main()
{
    int i, j;
    struct MatrixArrayStruct matrix;
    struct VectorArrayStruct EigenVector;

    system("cls");

    printf("Enter the matrix (3x3 only):-\n");
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("Enter element (%d, %d): ", i + 1, j + 1);
            scanf("%f", &matrix.value[i][j]);
        }
    }
    printMatrix(matrix);

    EigenVector = EigenVectorOfMatrix(matrix, 3);

    printf("\n\nEigen vector of this matrix is: ");
    printVector(EigenVector);

    printf("\n\n");
    system("pause");
    return 0;
}