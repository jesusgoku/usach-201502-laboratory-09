#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>
#include <utilities.h>
#include <program.h>

#define MENU_OPTIONS 6

int main (int argc, char *argv[])
{
    int inputOption = 0;
    MenuItem menu[MENU_OPTIONS] = {
        {"Multiplicar una matriz por un numero", 1, matrixProductScalarOption},
        {"Sumar dos matrices", 2, matrixPlusMatrixOption},
        {"Multiplicar dos matrices", 3, matrixProductMatrixOption},
        {"Transponer matriz", 4, matrixTransposeOption},
        {"Calcular determinante", 5, matrixDeterminantOption},
        {"Salir", 0, NULL}
    };

    do {
        titlePrint("Operación de matrices");
        printMenuItems(menu, MENU_OPTIONS);
        inputOption = readValidOption("Ingresa un opción", 0, 5);

        if (0 < inputOption && MENU_OPTIONS > inputOption) {
            for (int k = 0; k < MENU_OPTIONS; ++k) {
                if (inputOption == menu[k].option) {
                    menu[k].process();
                }
            }
        }
    } while (0 != inputOption);

    return 0;
}
