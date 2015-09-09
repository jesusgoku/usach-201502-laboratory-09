#ifndef __MATRIX_H__
#define __MATRIX_H__

typedef struct Matrix {
    float **matrix;
    int rows;
    int columns;
} Matrix;

void *matrixAllocMemory(Matrix *matrix);
void matrixFreeMemory(Matrix *matrix);
void matrixRead(Matrix *matrix);
void matrixPrint(const Matrix *matrix);
void matrixPrintRowDivider(const int columns, const int columnSize);
void matrixReadRowsAndColumsSize(Matrix *matrix, const int min, const int max);
Matrix matrixProductByScalar(const float scalar, const Matrix *matrix);
Matrix matrixPlusMatrix(const Matrix *matrix01, const Matrix *matrix02);
Matrix matrixProductByMatrix(const Matrix *matrix01, const Matrix *matrix02);


#endif // __MATRIX_H__
