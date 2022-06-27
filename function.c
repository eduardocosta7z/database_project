#include <string.h>
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

int search_database(char *wrd)
{
    char line[100];
    int num_results = 0;

    FILE *fptr = fopen("database.txt", "r");

    if (fptr == NULL)
    {
        printf("ERROR: Couldn't find database.\n");
        return 0;
    }
    while (fscanf(fptr, "%[^\n]\n", line) != EOF)
    {
        if (strstr(line, wrd) != NULL)
        {
            num_results++;
            printf("%s\n", line);
        }
    }

    fclose(fptr);

    return num_results;
}

// TODO: space for future functions.