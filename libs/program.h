#ifndef __PROGRAM_H__
#define __PROGRAM_H__

#define OPTION_MATRIX_PRODUCT_SCALAR 1
#define OPTION_MATRIX_PLUS_MATRIX 2
#define OPTION_MATRIX_PRODUCT_MATRIX 3
#define OPTION_MATRIX_TRANSPOSE 4
#define OPTION_MATRIX_DETERMINANT 5
#define OPTION_EXIT 0

#define MATRIX_MIN_DIMENSION 1
#define MATRIX_MAX_DIMENSION 100

typedef struct MenuItem {
    char *name;
    int option;
    void (*process)();
} MenuItem;

void printMenuItems(const MenuItem menuItems[], const int items);
void matrixProductScalarOption();
void matrixPlusMatrixOption();
void matrixProductMatrixOption();
void matrixTransposeOption();
void matrixDeterminantOption();

#endif // __PROGRAM_H__
