/**
 * @file main.c
 * @author Placeholder
 * @brief A simple database.
 * @version 0.3
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

        switch (menu(5, "Add", "Remove", "Edit", "Search", "Exit"))
        {
        case 1:
            add_menu();
            break;

        case 2:
            remove_menu();
            break;

        case 3:
            edit_menu();
            break;

        case 4:
            search_menu();
            break;

        case 5:
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
    printf("ADD MENU\nWork in progress...\n"); // TODO
    sleep(2);
}

void remove_menu()
{
    printf(CLEAR);
    printf("REMOVE MENU\nWork in progress...\n"); // TODO
    sleep(2);
}

void edit_menu()
{
    printf(CLEAR);
    printf("EDIT MENU\nWork in progress...\n"); // TODO
    sleep(2);
}

void search_menu()
{
    printf(CLEAR);

    char wrd[30];

    printf("Search: ");
    scanf("%s", wrd);
    printf("\n");

    printf("\nThe search returned %d result(s).\n", search_database(wrd));
    if (y_or_n("New search?"))
        search_menu();
}