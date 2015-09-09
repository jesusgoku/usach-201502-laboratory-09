#include <stdio.h>
#include <string.h>

#include <utilities.h>

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

void titlePrint(char *title)
{
    int titleLength = strlen(title);

    printf("\n\n");

    for (int k = 0; k < titleLength; ++k) {
        printf("=");
    }
    
    printf("\n%s\n", title);

    for (int k = 0; k < titleLength; ++k) {
        printf("=");
    }

    printf("\n\n");
}
