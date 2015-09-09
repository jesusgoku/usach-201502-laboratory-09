#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <program.h>

void printMenu()
{
    printf("%d.- Multiplicar una matriz por un numero.\n", OPTION_MATRIX_PRODUCT_SCALAR);
    printf("%d.- Sumar dos matrices.\n", OPTION_MATRIX_PLUS_MATRIX);
    printf("%d.- Multiplicar dos matrices.\n", OPTION_MATRIX_PRODUCT_MATRIX);
    printf("%d.- Transponer matriz.\n", OPTION_MATRIX_TRANSPOSE);
    printf("%d.- Calcular determinante.\n", OPTION_MATRIX_DETERMINANTE);
    printf("%d.- Salir.\n", OPTION_EXIT);
}

void matrixProductScalar()
{
    int rows = 0, columns = 0;
    float scalar = 0;
    float *matrix = NULL;

    readRowsAndColumnsSize(&rows, &columns, MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);

    printf("Ingresa el valor scalar: ");
    scanf("%f", &scalar);

    matrix = (float *) malloc(sizeof(float) * rows * columns);
    readMatrix(matrix, rows, columns);
    productMatrixAndScalar(scalar, matrix, rows, columns);
    printMatrix(matrix, rows, columns);
    free(matrix);
    matrix = NULL;
}

void matrixPlusMatrix()
{
    int rows = 0, columns = 0;
    float *matrix01 = NULL, *matrix02 = NULL, *matrixResult = NULL;

    readRowsAndColumnsSize(&rows, &columns, MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);
    matrix01 = (float *) malloc(sizeof(float) * rows * columns);
    matrix02 = (float *) malloc(sizeof(float) * rows * columns);
    matrixResult = (float *) malloc(sizeof(float) * rows * columns);
    printf("Valores para la primera matriz\n");
    readMatrix(matrix01, rows, columns);
    printf("Valores para la segunda matriz\n");
    readMatrix(matrix02, rows, columns);
    plusMatrixWithMatrix(matrixResult, matrix01, matrix02, rows, columns);
    printMatrix(matrixResult, rows, columns);
    free(matrixResult);
    free(matrix02);
    free(matrix01);
    matrixResult = matrix02 = matrix01 = NULL;
}

void matrixProductMatrix()
{
    matrixDimension dimensions01, dimensions02, dimensionsResult;
    float *matrix01 = NULL, *matrix02 = NULL, *matrixResult = NULL;

    printf("Filas y columnas primera matriz\n");
    readRowsAndColumnsSize(&(dimensions01.rows), &(dimensions01.columns), MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);
    printf("Filas y columnas segunda matriz\n");
    readRowsAndColumnsSize(&(dimensions02.rows), &(dimensions02.columns), MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);

    if (dimensions01.columns != dimensions02.rows) {
        printf("Error: el número de columnas de la primera matriz debe ser el igual al número de filas de la segunda matriz.\n");
        return;
    }

    dimensionsResult.rows = dimensions01.rows;
    dimensionsResult.columns = dimensions02.columns;

    matrix01 = (float *) malloc(sizeof(float) * dimensions01.rows * dimensions01.columns);
    matrix02 = (float *) malloc(sizeof(float) * dimensions02.rows * dimensions02.columns);
    matrixResult = (float *) malloc(sizeof(float) * dimensionsResult.rows * dimensionsResult.columns);
    printf("Valores para la primera matriz\n");
    readMatrix(matrix01, dimensions01.rows, dimensions01.columns);
    printf("Valores para la segunda matriz\n");
    readMatrix(matrix02, dimensions02.rows, dimensions02.columns);
    productMatrixWithMatrix(
        matrixResult,
        &dimensionsResult,
        matrix01,
        &dimensions01,
        matrix02,
        &dimensions02);
    printMatrix(matrixResult, dimensionsResult.rows, dimensionsResult.columns);
    free(matrixResult);
    free(matrix01);
    free(matrix02);
    matrixResult = matrix02 = matrix01 = NULL;
}
