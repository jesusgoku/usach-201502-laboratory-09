#ifndef __UTILITIES_H__
#define __UTILITIES_H__

typedef enum { false, true } bool;

int readValidOption(const char *message, const int min, const int max);
bool isValidOption(const int option, const int min, const int max);
void titlePrint(char *title);

#endif // __UTILITIES_H__
