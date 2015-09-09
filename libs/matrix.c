#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <utilities.h>

void *matrixAllocMemory(Matrix *matrix)
{
    matrix->matrix = (float **) malloc(sizeof(float) * matrix->rows);

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
    for (int j = 0; j < matrix->rows; ++j) {
        for (int k = 0; k < matrix->columns; ++k) {
            printf("| %.2f ", matrix->matrix[j][k]);
        }
        printf("|\n");
    }
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

// -- OLD VERSION
void readMatrix(float *matrix, const int rows, const int columns)
{
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < columns; ++k) {
            printf("Ingresa valor para la coordenada (%d:%d): ", (j+1), (k+1));
            scanf("%f", (matrix + (j * columns) + k));
        }
    }
}

void printMatrix(const float *matrix, const int rows, const int columns)
{
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < columns; ++k) {
            printf(" %.2f |", *(matrix + (j * columns) + k));
        }
        printf("\n");
    }
}

void readRowsAndColumnsSize(int *rows, int *columns, const int min, const int max)
{
    *rows = readValidOption(
        "Número de filas",
        min,
        max
    );

    *columns = readValidOption(
        "Número de columnas",
        min,
        max
    );
}

void productMatrixAndScalar(const float scalar, float *matrix, const int rows, const int columns)
{
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < columns; ++k) {
            *(matrix + (j * columns) + k) *= scalar;
        }
    }
}

void plusMatrixWithMatrix(
    float *matrixResult,
    const float *matrix01,
    const float *matrix02,
    const int rows,
    const int columns)
{
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < columns; ++k) {
            *(matrixResult + (j * columns) + k) =
                *(matrix01 + (j * columns) + k)
                + *(matrix02 + (j * columns) + k);
        }
    }
}

void productMatrixWithMatrix(
    float *matrixResult,
    const matrixDimension *dimensionsResult,
    const float *matrix01,
    const matrixDimension *dimensions01,
    const float *matrix02,
    const matrixDimension *dimensions02)
{
    for (int j = 0; j < dimensionsResult->rows; ++j) {
        for (int k = 0; k < dimensionsResult->columns; ++k) {
            *(matrixResult + (j * dimensionsResult->columns) + k) = 0;
            for (int i = 0; i < dimensions01->columns; ++i) {
                *(matrixResult + (j * dimensionsResult->columns) + k) +=
                    *(matrix01 + (j * dimensions01->columns) + i)
                    * *(matrix02 + (i * dimensions02->columns) + k);
            }
        }
    }
}
