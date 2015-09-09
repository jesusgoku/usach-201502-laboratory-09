#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <utilities.h>

void *matrixAllocMemory(Matrix *matrix)
{
    matrix->matrix = (float **) malloc(sizeof(float *) * matrix->rows);

    if (NULL == matrix->matrix) {
        return NULL;
    }

    for (int k = 0; k < matrix->rows; ++k) {
        *(matrix->matrix + k) = (float *) malloc(sizeof(float) * matrix->columns);

        if (NULL == *(matrix->matrix + k)) {
            return NULL;
        }
    }

    return matrix;
}

void matrixFreeMemory(Matrix *matrix)
{
    for (int k = 0; k < matrix->rows; ++k) {
        free(*(matrix->matrix + k));
        *(matrix->matrix + k) = NULL;
    }

    free(matrix->matrix);

    matrix->matrix = NULL;
}

void matrixRead(Matrix *matrix)
{
    for (int j = 0; j < matrix->rows; ++j) {
        for (int k = 0; k < matrix->columns; ++k) {
            printf("Ingresa valor para la coordenada (%d:%d): ", (j+1), (k+1));
            scanf("%f", &(matrix->matrix[j][k]));
        }
    }
}

void matrixPrint(const Matrix *matrix)
{
    matrixPrintRowDivider(matrix->columns, 9);

    for (int j = 0; j < matrix->rows; ++j) {
        for (int k = 0; k < matrix->columns; ++k) {
            printf("| %6.2f ", matrix->matrix[j][k]);
        }
        printf("|\n");
        matrixPrintRowDivider(matrix->columns, 9);
    }
}

void matrixPrintRowDivider(const int columns, const int columnSize)
{
    for (int k = 0; k < (columns * columnSize); ++k) {
        if (0 == k || 0 == (k % columnSize)) {
            printf("+");
        } else {
            printf("-");
        }
    }
    printf("+\n");
}

void matrixReadRowsAndColumsSize(Matrix *matrix, const int min, const int max)
{
    matrix->rows = readValidOption(
        "Número de filas",
        min,
        max
    );

    matrix->columns = readValidOption(
        "Número de columnas",
        min,
        max
    );
}

Matrix matrixProductByScalar(const float scalar, const Matrix *matrix)
{
    Matrix result;

    result.rows = matrix->rows;
    result.columns = matrix->columns;

    matrixAllocMemory(&result);

    for (int j = 0; j < matrix->rows; ++j) {
        for (int k = 0; k < matrix->columns; ++k) {
            result.matrix[j][k] = (matrix->matrix[j][k]) * scalar;
        }
    }

    return result;
}

Matrix matrixPlusMatrix(const Matrix *matrix01, const Matrix *matrix02)
{
    Matrix matrixResult;

    matrixResult.rows = matrix01->rows;
    matrixResult.columns = matrix01->columns;

    matrixAllocMemory(&matrixResult);

    for (int j = 0; j < matrixResult.rows; ++j) {
        for (int k = 0; k < matrixResult.columns; ++k) {
            matrixResult.matrix[j][k] = matrix01->matrix[j][k] + matrix02->matrix[j][k];
        }
    }

    return matrixResult;
}

Matrix matrixProductByMatrix(const Matrix *matrix01, const Matrix *matrix02)
{
    Matrix matrixResult;

    matrixResult.rows = matrix01->rows;
    matrixResult.columns = matrix02->columns;

    matrixAllocMemory(&matrixResult);

    for (int j = 0; j < matrixResult.rows; ++j) {
        for (int k = 0; k < matrixResult.columns; ++k) {
            matrixResult.matrix[j][k] = 0;
            for (int n = 0; n < matrix01->columns; ++n) {
                matrixResult.matrix[j][k] += matrix01->matrix[j][n] * matrix02->matrix[n][k];
            }
        }
    }

    return matrixResult;
}

Matrix matrixTranspose(const Matrix *matrix)
{
    Matrix transpose;

    transpose.rows = matrix->columns;
    transpose.columns = matrix->rows;

    matrixAllocMemory(&transpose);

    for (int j = 0; j < transpose.rows; ++j) {
        for (int k = 0; k < transpose.columns; ++k) {
            transpose.matrix[j][k] = matrix->matrix[k][j];
        }
    }

    return transpose;
}
