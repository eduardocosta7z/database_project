#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "header.h"

int menu(int num_args, ...) // automatically displays a menu and returns the selected option
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

int y_or_n(char *txt) // printf
{
    char choice;

    printf("%s [y/n]: ", txt);
    scanf(" %c", &choice);

    if (choice == 'y')
        return 1;
    else
        return 0;
}

int search_database(char wrd[30]) // search for a word in the database, print the line that matches and returns the number of results
{
    char line[100];
    int i, num_results = 0;

    FILE *fptr = fopen("database.txt", "r");

    if (fptr == NULL)
    {
        printf("ERROR: Couldn't find database.\n");
        return 0;
    }
    while (fscanf(fptr, "%[^\n]\n", line) != EOF) // search the file line by line
    {
        for (i = 0; wrd[i]; i++) // converts to lowercase
            wrd[i] = tolower(wrd[i]);

        for (i = 0; line[i]; i++)
            line[i] = tolower(line[i]);

        if (strstr(line, wrd) != NULL) // checks if line contains wrd
        {
            num_results++;
            printf("%s\n", line);
        }
    }

    fclose(fptr);

    return num_results;
}

// TODO: space for future functions.