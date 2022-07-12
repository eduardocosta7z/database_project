#include <stdlib.h>
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

int y_or_n(char *question) // prints the question and ask for yes or no, returns 'true' if yes
{
    char choice;

    printf("%s [y/n]: ", question);
    scanf(" %c", &choice);

    if (choice == 'y')
        return 1;
    else
        return 0;
}

void replace_char(char *str, char find, char replace) // find all the occurrences of a character in a
{                                                     // string and replace it
    char *current_pos = strchr(str, find);
    while (current_pos)
    {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
}

char *lcase(const char *str)
{
    char *str_lc = malloc(sizeof(char) * strlen(str) + 1);

    int i;
    for (i = 0; str[i]; i++)
        str_lc[i] = tolower(str[i]);

    return str_lc;
}

void database_header()
{
    printf(LINE);
    printf("| ID   | Name                     | Document |");
    printf(" COB                  | Room | Check-in   | Check-out  |\n");
    printf(LINE);
}

int list_database() // print all the entries on database and returns the number of entries
{
    FILE *fptr = fopen("database.txt", "r");

    if (fptr == NULL)
    {
        printf("ERROR: Couldn't find database.\n");
        return 0;
    }

    char line[100];
    int num_entries = 0;

    struct database_entry *sptr, list;
    sptr = &list;

    database_header();

    while (fscanf(fptr, "%d %s %s %s %s %s %s",
                  &sptr->id, &sptr->name, &sptr->doc, &sptr->cob,
                  &sptr->room, &sptr->ci, &sptr->co) != EOF)
    {
        num_entries++;

        replace_char(sptr->name, '*', ' ');
        replace_char(sptr->cob, '*', ' ');

        printf("| %.4d | %-24s | %-8s | %-20s | %-4s | %s | %s |\n",
               sptr->id, sptr->name, sptr->doc, sptr->cob,
               sptr->room, sptr->ci, sptr->co);
        printf(LINE);
    }

    fclose(fptr);

    return num_entries;
}

int add_database()
{
    struct database_entry *sptr, guest;
    sptr = &guest;

    FILE *fptr = fopen("database.txt", "r");

    if (fptr == NULL)
        return 0;

    char line[100];
    int last_id;

    while (fscanf(fptr, "%[^\n]\n", line) != EOF)
        sscanf(line, "%d", &last_id);

    sptr->id = last_id + 1;

    fclose(fptr);

    getchar();

    printf("Name (max of 24 char)             | ");
    scanf("%[^\n]%*c", sptr->name);

    printf("Document (8 digits)               | ");
    scanf("%s", sptr->doc);

    getchar();

    printf("Country of birth (max of 20 char) | ");
    scanf("%[^\n]%*c", sptr->cob);

    printf("Room (1 letter + 3 numbers)       | ");
    scanf("%s", sptr->room);

    printf("Check-in date (dd/mm/yyyy)        | ");
    scanf("%s", sptr->ci);

    printf("Check-out date (dd/mm/yyyy)       | ");
    scanf("%s", sptr->co);

    replace_char(sptr->name, ' ', '*');
    replace_char(sptr->cob, ' ', '*');

    if (y_or_n("\nAdd the entry?"))
    {
        FILE *fptr2 = fopen("database.txt", "a");

        fprintf(fptr2, "%d %s %s %s %s %s %s\n",
                sptr->id, sptr->name, sptr->doc, sptr->cob,
                sptr->room, sptr->ci, sptr->co);

        fclose(fptr2);
    }

    return 1;
}

int remove_database(int selected_id)
{
    FILE *fptr, *fptr2;

    fptr = fopen("database.txt", "r");

    if (fptr == NULL)
    {
        printf("\nERROR: Couldn't find database.\n");
        return 0;
    }

    fptr2 = fopen("database2.txt", "w");

    char line[100];
    int id, test_var = 0;

    while (fscanf(fptr, "%[^\n]\n", line) != EOF)
    {
        sscanf(line, "%d", &id);

        if (selected_id == id)
            test_var = 1;
        else
            fprintf(fptr2, "%s\n", line);
    }

    fclose(fptr);
    fclose(fptr2);

    remove("database.txt");
    rename("database2.txt", "database.txt");

    if (test_var == 1)
        return 1;
    else
        return 0;
}

int search_database(char wrd[30]) // search for a word in the database, print the line
{                                 // that matches and returns the number of results
    FILE *fptr = fopen("database.txt", "r");

    if (fptr == NULL)
    {
        printf("ERROR: Couldn't find database.\n");
        return 0;
    }

    char line[100];
    int i, num_results = 0;

    struct database_entry *sptr, list;
    sptr = &list;

    printf(CLEAR);

    database_header();

    while (fscanf(fptr, "%[^\n]\n", line) != EOF) // scan the file line by line
    {
        if (strstr(lcase(line), lcase(wrd)) != NULL) // checks if line contains wrd
        {
            num_results++;

            sscanf(line, "%d %s %s %s %s %s %s",
                   &sptr->id, &sptr->name, &sptr->doc, &sptr->cob,
                   &sptr->room, &sptr->ci, &sptr->co);

            replace_char(sptr->name, '*', ' ');
            replace_char(sptr->cob, '*', ' ');

            printf("| %.4d | %-24s | %-8s | %-20s | %-4s | %-10s | %-10s |\n",
                   sptr->id, sptr->name, sptr->doc, sptr->cob,
                   sptr->room, sptr->ci, sptr->co);
            printf(LINE);
        }
    }

    fclose(fptr);

    return num_results;
}