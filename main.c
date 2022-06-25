/**
 * @file main.c
 * @author
 * @brief
 * @version 0.1
 * @date 2022-06-25
 */

#include <stdio.h>
#include <unistd.h> // used for the sleep function.
#include "header.h"

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
    printf("SEARCH MENU\n"); // TODO
    sleep(2);
}

int main(void)
{
    int n;
    do
    {
        printf(CLEAR);
        printf("Unnamed Database\n\n");
        // TODO: description for the program.
        printf("[1] Add\n");
        printf("[2] Remove\n");
        printf("[3] Search\n");
        printf("[4] Exit\n\n");
        printf("Option: ");
        scanf("%d", &n);

        switch (n)
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
            printf("ERROR: Type a valid option.");
            sleep(2);
        }
    } while (1337); // infinite loop.
}