#include <stdio.h>
#include <stdlib.h>

#define OPTION_MATRIX_PRODUCT_SCALAR 1
#define OPTION_MATRIX_PLUS_MATRIX 2
#define OPTION_MATRIX_PRODUCT_MATRIX 3
#define OPTION_MATRIX_TRANSPOSE 4
#define OPTION_MATRIX_DETERMINANTE 5
#define OPTION_EXIT 0

#define MATRIX_MIN_DIMENSION 1
#define MATRIX_MAX_DIMENSION 100

#define MESSAGE_MAX_CHARACTERS 1024

typedef enum { false, true } bool;
typedef struct matrixDimension {
    int rows;
    int columns;
} matrixDimension;

void printMenu();
int readValidOption(const char *message, const int min, const int max);
bool isValidOption(const int option, const int min, const int max);
void readMatrix(float *matrix, const int rows, const int columns);
void printMatrix(const float *matrix, const int rows, const int columns);
void matrixProductScalar();
void productMatrixAndScalar(
    const float scalar,
    float *matrix,
    const int rows,
    const int columns);
void matrixPlusMatrix();
void plusMatrixWithMatrix(
    float *matrixResult,
    const float *matrix01,
    const float *matrix02,
    const int rows,
    const int columns);
void matrixProductMatrix();
void productMatrixWithMatrix(
    float *matrixResult,
    const matrixDimension *dimensionsResult,
    const float *matrix01,
    const matrixDimension *dimensions01,
    const float *matrix02,
    const matrixDimension *dimensions02);
void readRowsAndColumnsSize(int *rows, int *columns);

int main (int argc, char *argv[])
{
    int inputOption = 0;

    do {
        printMenu();
        inputOption = readValidOption("Ingresa un opción", 0, 5);

        switch (inputOption) {
            case OPTION_MATRIX_PRODUCT_SCALAR:
                matrixProductScalar();
                break;
            case OPTION_MATRIX_PLUS_MATRIX:
                matrixPlusMatrix();
                break;
            case OPTION_MATRIX_PRODUCT_MATRIX:
                matrixProductMatrix();
                break;
            case OPTION_MATRIX_TRANSPOSE:
                break;
            case OPTION_MATRIX_DETERMINANTE:
                break;
        }
    } while (0 != inputOption);

    return 0;
}

void printMenu()
{
    printf("%d.- Multiplicar una matriz por un numero.\n", OPTION_MATRIX_PRODUCT_SCALAR);
    printf("%d.- Sumar dos matrices.\n", OPTION_MATRIX_PLUS_MATRIX);
    printf("%d.- Multiplicar dos matrices.\n", OPTION_MATRIX_PRODUCT_MATRIX);
    printf("%d.- Transponer matriz.\n", OPTION_MATRIX_TRANSPOSE);
    printf("%d.- Calcular determinante.\n", OPTION_MATRIX_DETERMINANTE);
    printf("%d.- Salir.\n", OPTION_EXIT);
}

int readValidOption(const char *message, const int min, const int max)
{
    int inputOption = 0;
    bool isValidOptions = false;
    do {
        printf("%s (min: %d, max: %d): ", message, min, max);
        scanf("%d", &inputOption);
        if (!(isValidOptions = isValidOption(inputOption, min, max))) {
            printf("\nError, opcion ingresada no es valida. Solo valores entre: %d <= n <= %d\n", min, max);
        }
    } while (!isValidOptions);

    return inputOption;
}

bool isValidOption(const int option, const int min, const int max)
{
    return option >= min && option <= max;
}

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

void matrixProductScalar()
{
    int rows = 0, columns = 0;
    float scalar = 0;
    float *matrix = NULL;

    readRowsAndColumnsSize(&rows, &columns);

    printf("Ingresa el valor scalar: ");
    scanf("%f", &scalar);

    matrix = (float *) malloc(sizeof(float) * rows * columns);
    readMatrix(matrix, rows, columns);
    productMatrixAndScalar(scalar, matrix, rows, columns);
    printMatrix(matrix, rows, columns);
    free(matrix);
    matrix = NULL;
}

void productMatrixAndScalar(const float scalar, float *matrix, const int rows, const int columns)
{
    for (int j = 0; j < rows; ++j) {
        for (int k = 0; k < columns; ++k) {
            *(matrix + (j * columns) + k) *= scalar;
        }
    }
}

void matrixPlusMatrix()
{
    int rows = 0, columns = 0;
    float *matrix01 = NULL, *matrix02 = NULL, *matrixResult = NULL;

    readRowsAndColumnsSize(&rows, &columns);
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

void matrixProductMatrix()
{
    matrixDimension dimensions01, dimensions02, dimensionsResult;
    float *matrix01 = NULL, *matrix02 = NULL, *matrixResult = NULL;

    printf("Filas y columnas primera matriz\n");
    readRowsAndColumnsSize(&(dimensions01.rows), &(dimensions01.columns));
    printf("Filas y columnas segunda matriz\n");
    readRowsAndColumnsSize(&(dimensions02.rows), &(dimensions02.columns));

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

void readRowsAndColumnsSize(int *rows, int *columns)
{
    *rows = readValidOption(
        "Número de filas",
        MATRIX_MIN_DIMENSION,
        MATRIX_MAX_DIMENSION
    );

    *columns = readValidOption(
        "Número de columnas",
        MATRIX_MIN_DIMENSION,
        MATRIX_MAX_DIMENSION
    );
}