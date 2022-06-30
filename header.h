#ifndef HEADER_H // include guard.
#define HEADER_H

#include <stdio.h>

#define CLEAR "\e[1;1H\e[2J" // regex to clean the terminal.
#define LINE "------------------------------------------------------------------------------------------------------\n"

// start: function declaration for use in both main.c and function.c
int menu(int num_args, ...);
int y_or_n(char *txt);
void replace_char(char *str, char find, char replace);
char *lcase(const char *str);
void database_header();

int list_database();
int search_database(char wrd[30]);

void list_menu();
void add_menu();
void remove_menu();
void edit_menu();
void search_menu();
// end

struct database_entry // general format of the entries
{
    int id;        // unique value for every entry
    char name[30]; //
    int doc;       // document with 8 digits
    char cob[25];  // country of birth
    char room[10]; // letter + 3 digits number
    char ci[15];   // check-in date
    char co[15];   // check-out date
};

#endif
