#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef enum color_s {
    Red, Blue, Silver, Purple, Midnight, Black
}colors;

typedef struct {
    char name[100];
    colors color;
    int screen;
    int memory;
    int cost;
}phone;

void menu(phone* catalog, int size);

phone* create_catalog(int size);

int check_input();

int check_yes_no();

int check_delete_num(int size);

int check_key();

int compare_field_name(const phone* a , const phone* b);

int compare_field_color(const phone* a , const phone* b);

int compare_field_screen(const phone* a , const phone* b);

int compare_field_memory(const phone* a , const phone* b);

int compare_field_cost(const phone* a , const phone* b);

char little_word(char ch);

char* choose_field();

void sort_catalog(phone* catalog, int size);

void initialization(phone* catalog, int size, int i);

void add_element(phone** catalog, int* size);

void print_catalog(phone* catalog, int size);



#ifndef LAB4_FUNCTION_H
#define LAB4_FUNCTION_H

#endif //LAB4_FUNCTION_H
