/**
 * @file main.c
 * @author Placeholder
 * @brief A simple database.
 * @version 0.2
 * @date 2022-06-26
 */

#include <unistd.h> // used for the sleep function.
#include "header.h"

int main(void)
{
    do
    {
        printf(CLEAR);
        printf("Unnamed Database\n\n");

        switch (menu(4, "Add", "Remove", "Search", "Exit"))
        {
        case 1:
            add_menu();
            break;

        case 2:
            remove_menu();
            break;

        case 3:
            search_menu();
            break;

        case 4:
            return 0;

        default:
            printf(CLEAR);
            printf("ERROR: Type a valid option.\n");
            sleep(2);
        }
    } while (1337); // infinite loop.
}

void add_menu()
{
    printf(CLEAR);
    printf("ADD MENU\n"); // TODO
    sleep(2);
}

void remove_menu()
{
    printf(CLEAR);
    printf("REMOVE MENU\n"); // TODO
    sleep(2);
}

void search_menu()
{
    printf(CLEAR);

    char *wrd;

    printf("Search: ");
    scanf("%s", wrd);
    printf("\n");

    printf("\nThe search returned %d result(s).\n", search_database(wrd));
    sleep(2);
}