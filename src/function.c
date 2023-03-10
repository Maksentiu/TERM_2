#include "function.h"


int check_yes_no()
{
    int n = 0;
    while ((scanf_s("%d", &n)) != 1 || (n != 1 && n != 2) || getchar() != '\n')
    {
        fprintf(stderr,"Try again =)\n");
        rewind(stdin);
    }
    return n;
}

int check_input()
{
    int n = 0;
    while ((scanf_s("%d", &n)) != 1 || getchar() != '\n')
    {
        fprintf(stderr,"Try again =)\n");
        rewind(stdin);
    }
    return n;
}

int check_delete_num(int size)
{
    int n = 0;
    while ((scanf_s("%d", &n)) != 1 || n > size || n < 1 || getchar() != '\n')
    {
        fprintf(stderr,"Try again =)\n");
        rewind(stdin);
    }
    return n;
}

int check_key()
{
    int n = 0;
    while ((scanf_s("%d", &n)) != 1 || (n != 1 && n != 2 && n != 3 && n != 4 && n != 5))
    {
        fprintf(stderr,"Try again =)\n");
        rewind(stdin);
    }
    return n;
}

phone* create_catalog( int size){
    return (phone*) calloc(size, sizeof(phone));
}

void initialization(phone* catalog, int size, int i) {
     for (int pos = i; pos < size; pos++) {
        rewind(stdin);
        printf("Enter name:\n");
        fgets(catalog[pos].name, 100, stdin);

        printf("Enter color (Red, Blue, Silver, Purple, Midnight, Black):\n");

        char* color = malloc(1000 * sizeof(char));
        rewind(stdin);
        fgets(color, 1000, stdin);
        printf("%s", color);
        for (int j = 0; j < 20; j++) {
            color[j] = little_word(color[j]);
        }
         puts(color);
        if (strcmp(color, "red\n") == 0) {
            catalog[pos].color = Red;
            free(color);
        }
        else if (strcmp(color, "blue\n") == 0){
            catalog[pos].color = Blue;
            free(color);
        }
        else if (strcmp(color, "silver\n") == 0){
            catalog[pos].color = Silver;
            free(color);
        }
        else if (strcmp(color, "purple\n") == 0) {
            catalog[pos].color = Purple;
            free(color);
        }
        else if (strcmp(color, "midnight\n") == 0){
            catalog[pos].color = Midnight;
            free(color);
        }
        else if (strcmp(color, "black\n") == 0) {
            catalog[pos].color = Black;
            free(color);
        }
        else {
            printf("Invalid input. Set up Red by default.\n");
            catalog[pos].color = Red;
            free(color);
        }


        printf("Enter screen size:\n");
        catalog[pos].screen = check_input();

        printf("Enter the amount of memory:\n");
        catalog[pos].memory = check_input();

        printf("Enter cost:\n");
        catalog[pos].cost = check_input();
    }
}

void print_catalog(phone* catalog, int size)
{
    char* colors_string[6] = {"Red", "Blue", "Silver", "Purple", "Midnight", "Black"};
    for (int i = 0; i < size; i++){
        printf("________________________________________________________\n%d.\n", (i+1));
        printf("Name:%s\n", catalog[i].name);
        printf("Color: %s\n", colors_string[catalog[i].color]);
        printf("Screen: %.d\n", catalog[i].screen);
        printf("Memory: %d\n", catalog[i].memory);
        printf("Cost: %.d\n", catalog[i].cost);
        printf("________________________________________________________\n");
    }
}

int compare_field_name(const phone* a , const phone* b){
    return strcmp(a -> name, b -> name);
}

int compare_field_color(const phone* a , const phone* b) {
    if (a->color > b->color) {
        return 1;
    }
    else if (a->color < b->color) {
        return -1;
    }
    else {
        return (a->color > b->color) - (a->color < b->color);
    }
}

int compare_field_screen(const phone* a , const phone* b){
    return a -> screen - b -> screen;
}

int compare_field_memory(const phone* a , const phone* b){
    return a -> memory - b -> memory;
}

int compare_field_cost(const phone* a , const phone* b){
    return a -> screen - b -> screen;
}

char little_word(char ch){
    if(ch >= 'A' && ch <= 'Z')
        return (char)(ch - ('Z' - 'z'));
    return ch;
}

char* choose_field(){
    printf("Enter field(name, color, screen, memory, cost):\n");
    char* field_for_sort = malloc(9 * sizeof(char));
    rewind(stdin);
    fgets(field_for_sort, 9, stdin);
    for(int i = 0; i < 9; i++) {
        field_for_sort[i] = little_word(field_for_sort[i]);
        if (field_for_sort[i] == '\n') {
            field_for_sort[i] = '\0';
            break;
        }
    }
    return field_for_sort;
}

void sort_catalog(phone* catalog, int size){
    int k = 1;
    do {
        while(k == 1){
            char* choice = choose_field();
            if (strcmp(choice, "name") == 0) {
                qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_name);
                free(choice);
                k = 0;
            }
            else if (strcmp(choice, "color") == 0) {
                qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_color);
                free(choice);
                k = 0;
            }
            else if (strcmp(choice, "screen") == 0) {
                qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_screen);
                free(choice);
                k = 0;
            }
            else if (strcmp(choice, "memory") == 0) {
                qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_memory);
                free(choice);
                k = 0;
            }
            else if (strcmp(choice, "cost") == 0) {
                qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_cost);
                free(choice);
                k = 0;
            }
            else {
                fprintf(stderr,"There is no such answer.Try again\n");
                free(choice);

            }
        }

        print_catalog(catalog, size);

        printf("Do you want to sort the catalog by other characteristics?\n1.Yes\t\t\t\t2.No\nYour choice:");
        int n = check_yes_no();
            if (n == 1)
                continue;
            else if(n == 2)
                break;


    }    while(1);
}

void delete_element(phone** catalog, int* size){

    do{
        printf("Enter the number of element that you want to delete:");
        for (int i = check_delete_num(*size) - 1; i < *size - 1; i++) {
            catalog[i] = catalog[i + 1];
        }
        (*size)--;
        *catalog = (phone *) realloc(*catalog, (*size) * sizeof(phone));
        print_catalog(*catalog, *size);

        printf("Do you want to delete another element?\n1.Yes\t\t\t\t2.No\nYour choice:");
        int x = check_yes_no();
        if (x == 1)
            continue;
        else if (x == 2)
            break;
    }while(1);
}

void add_element(phone** catalog, int* size){
    while(1)
    {
        int buf = *size;
        (*size)++;
        *catalog = (phone *) realloc(*catalog, *size * sizeof(phone));
        initialization(*catalog, *size, buf);
        print_catalog(*catalog, *size);
        printf("Do you want to add another element?\n1.Yes\t\t\t\t2.No\nYour choice:\n");
        int k = check_yes_no();
        if(k == 1)
            continue;
        else if(k == 2)
            break;
    }
}

void menu(phone* catalog, int size){
    while(1)
    {
        printf("What you want to do?\n1.Print the catalog\n2.Sort by feature\n3.Delete element\n4. Add element\n5.Exit\nYour choice:");
        int key = check_key();
        switch (key) {
            case 1:
                print_catalog(catalog, size);
                break;
            case 2:
                sort_catalog(catalog, size);
                break;
            case 3:
                delete_element(&catalog, &size);
                break;
            case 4:
                add_element(&catalog, &size);
                break;
            case 5:
                free(catalog);
                exit(EXIT_SUCCESS);
            default:
                printf("There is no such answer");
                break;
        }
    }
}
