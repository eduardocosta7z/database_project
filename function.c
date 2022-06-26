#include <stdarg.h> // used for functions with variable number of args.
#include "header.h"

int menu(int num_args, ...) // automatically displays a menu.
{
    int i;
    va_list args;

    va_start(args, num_args);
    for (i = 1; i <= num_args; i++)
    {
        printf("[%d] - ", i);
        printf(va_arg(args, void *));
        printf("\n");
    }
    va_end(args);

    printf("\nOption: ");
    scanf("%d", &i);

    return i;
}

// TODO: space for future functions.