/**
 * @file main.c
 * @author Placeholder
 * @brief A simple database.
 * @version 0.5
 * @date 2022-06-26
 */

#include <unistd.h> // used for the sleep function.
#include "header.h"

int main(void)
{
    while (1337) // infinite loop.
    {
        printf(CLEAR);
        printf("Hotel Database\n\n");

        switch (menu(6, "List", "Add", "Remove", "Edit", "Search", "Exit"))
        {
        case 1:
            list_menu();
            break;

        case 2:
            add_menu();
            break;

        case 3:
            remove_menu();
            break;

        case 4:
            edit_menu();
            break;

        case 5:
            search_menu();
            break;

        case 6:
            return 0;

        default:
            printf(CLEAR);
            printf("ERROR: Type a valid option.\n");
            sleep(2);
        }
    }
}

void list_menu()
{
    printf(CLEAR);

    printf("\nThe database has %d entrie(s).\nPress enter to exit...\n",
           list_database());
    getchar(); // receives the '\n' from the printf function above
    getchar();
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

    int id;

    printf("Insert the ID to be deleted: ");
    scanf("%d", &id);

    if (y_or_n("Are you sure?"))
        if (remove_database(id))
            printf("Sucessful deleted entry with id %d.\n", id);
        else
            printf("Can't find entry with id %d.\n", id);

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