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

    if (NULL == matrixAllocMemory(&matrix)) {
        printf("Error, imposible conseguir espacio.\n");
        return;
    }
    
    matrixRead(&matrix);
    
    result = matrixProductByScalar(scalar, &matrix);
    
    printf("Resultado:\n");
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

    if (NULL == matrixAllocMemory(&matrix01) || NULL == matrixAllocMemory(&matrix02)) {
        printf("Error, imposible conseguir espacio.\n");
        return;
    }

    printf("Valores para la primera matriz\n");
    matrixRead(&matrix01);
    printf("Valores para la segunda matriz\n");
    matrixRead(&matrix02);

    matrixResult = matrixPlusMatrix(&matrix01, &matrix02);

    printf("Resultado:\n");
    matrixPrint(&matrixResult);

    matrixFreeMemory(&matrix01);
    matrixFreeMemory(&matrix02);
    matrixFreeMemory(&matrixResult);
}

void matrixProductMatrixOption()
{
    Matrix matrix01, matrix02, matrixResult;

    titlePrint("Producto matriz por matriz");

    printf("Filas y columnas primera matriz\n");
    matrixReadRowsAndColumsSize(&matrix01, MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);
    printf("Filas y columnas segunda matriz\n");
    matrixReadRowsAndColumsSize(&matrix02, MATRIX_MIN_DIMENSION, MATRIX_MAX_DIMENSION);

    if (matrix01.columns != matrix02.rows) {
        printf("Error: el número de columnas de la primera matriz debe ser el igual al número de filas de la segunda matriz.\n");
        return;
    }

    if (NULL == matrixAllocMemory(&matrix01) || NULL == matrixAllocMemory(&matrix02)) {
        printf("Error, imposible conseguir espacio.\n");
        return;
    }

    printf("Valores para la primera matriz\n");
    matrixRead(&matrix01);
    printf("Valores para la segunda matriz\n");
    matrixRead(&matrix02);

    matrixResult = matrixProductByMatrix(&matrix01, &matrix02);

    printf("Resultado:\n");
    matrixPrint(&matrixResult);

    matrixFreeMemory(&matrixResult);
    matrixFreeMemory(&matrix01);
    matrixFreeMemory(&matrix02);
}
