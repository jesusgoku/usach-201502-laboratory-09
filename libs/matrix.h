#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef struct Matrix {
    float **matrix;
    int rows;
    int columns;
} Matrix;

typedef struct matrixDimension {
    int rows;
    int columns;
} matrixDimension;

void *matrixAllocMemory(Matrix *matrix);
void matrixFreeMemory(Matrix *matrix);

// -- OLD VERSION
void readMatrix(float *matrix, const int rows, const int columns);
void printMatrix(const float *matrix, const int rows, const int columns);
void readRowsAndColumnsSize(int *rows, int *columns, const int min, const int max);
void productMatrixAndScalar(
    const float scalar,
    float *matrix,
    const int rows,
    const int columns
);
void plusMatrixWithMatrix(
    float *matrixResult,
    const float *matrix01,
    const float *matrix02,
    const int rows,
    const int columns
);
void productMatrixWithMatrix(
    float *matrixResult,
    const matrixDimension *dimensionsResult,
    const float *matrix01,
    const matrixDimension *dimensions01,
    const float *matrix02,
    const matrixDimension *dimensions02
);


#endif // __MATRIX_H__
