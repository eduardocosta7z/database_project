#ifndef HEADER_H // include guard.
#define HEADER_H

#include <stdio.h>

#define CLEAR "\e[1;1H\e[2J" // regex to clean the terminal.

// function declaration to use in both main.c and function.c
int menu(int num_args, ...);
int y_or_n(char *txt);
int search_database(char wrd[30]);
void add_menu();
void remove_menu();
void edit_menu();
void search_menu();

#endif
