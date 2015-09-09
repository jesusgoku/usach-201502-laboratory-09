#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <utilities.h>
#include <program.h>

void printMenu()
{
    titlePrint("Operación de matrices");

    printf("%d.- Multiplicar una matriz por un numero.\n", OPTION_MATRIX_PRODUCT_SCALAR);
    printf("%d.- Sumar dos matrices.\n", OPTION_MATRIX_PLUS_MATRIX);
    printf("%d.- Multiplicar dos matrices.\n", OPTION_MATRIX_PRODUCT_MATRIX);
    printf("%d.- Transponer matriz.\n", OPTION_MATRIX_TRANSPOSE);
    printf("%d.- Calcular determinante.\n", OPTION_MATRIX_DETERMINANTE);
    printf("%d.- Salir.\n", OPTION_EXIT);
}

void matrixProductScalarOption()
{
    float scalar = 0;
    Matrix matrix, result;

    titlePrint("Matriz por un escalar");

    printf("Ingresa el valor scalar: ");
    scanf("%f", &scalar);

    matrixReadRowsAndColumsSize(
        &matrix,
        MATRIX_MIN_DIMENSION,
        MATRIX_MAX_DIMENSION
    );

    matrixAllocMemory(&matrix);
    
    matrixRead(&matrix);
    
    result = matrixProductByScalar(scalar, &matrix);
    
    matrixPrint(&result);

    matrixFreeMemory(&matrix);
    matrixFreeMemory(&result);
}

void matrixPlusMatrixOption()
{
    Matrix matrix01, matrix02, matrixResult;

    titlePrint("Suma de dos matrices");

    matrixReadRowsAndColumsSize(&matrix01, MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);
    matrix02.rows = matrix01.rows;
    matrix02.columns = matrix01.columns;

    matrixAllocMemory(&matrix01);
    matrixAllocMemory(&matrix02);

    printf("Valores para la primera matriz\n");
    matrixRead(&matrix01);
    printf("Valores para la segunda matriz\n");
    matrixRead(&matrix02);

    matrixResult = matrixPlusMatrix(&matrix01, &matrix02);

    matrixPrint(&matrixResult);

    matrixFreeMemory(&matrix01);
    matrixFreeMemory(&matrix02);
    matrixFreeMemory(&matrixResult);
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
