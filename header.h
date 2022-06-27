#ifndef HEADER_H // include guard.
#define HEADER_H

#include <stdio.h>

#define CLEAR "\e[1;1H\e[2J" // regex to clean the terminal.

int menu(int num_args, ...);
int search_database(char *wrd);
void add_menu();
void remove_menu();
void search_menu();

#endif
