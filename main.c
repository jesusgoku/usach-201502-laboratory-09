#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <utilities.h>
#include <program.h>

int main (int argc, char *argv[])
{
    int inputOption = 0;

    do {
        printMenu();
        inputOption = readValidOption("Ingresa un opción", 0, 5);

        switch (inputOption) {
            case OPTION_MATRIX_PRODUCT_SCALAR:
                matrixProductScalarOption();
                break;
            case OPTION_MATRIX_PLUS_MATRIX:
                matrixPlusMatrixOption();
                break;
            case OPTION_MATRIX_PRODUCT_MATRIX:
                matrixProductMatrixOption();
                break;
            case OPTION_MATRIX_TRANSPOSE:
                break;
            case OPTION_MATRIX_DETERMINANTE:
                break;
        }
    } while (0 != inputOption);

    return 0;
}
