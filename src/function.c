#include "function.h"

int check(int n)
{
    while ((scanf_s("%d", &n)) != 1 || (n != 1 && n != 2) )
    {
        printf("Try again =)");
        rewind(stdin);
    }
    return n;
}

int check_input(int n)
{
    while ((scanf_s("%d", &n)) != 1 || getchar() != '\n')
    {
        printf("Try again =)");
        rewind(stdin);
    }
    return n;
}

int check_key(int n)
{
    while ((scanf_s("%d", &n)) != 1 || (n != 1 && n != 2 && n != 3 && n != 4 && n != 5))
    {
        printf("Try again =)");
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
        gets(catalog[pos].name);

        printf_s("Enter color (Red, Blue, Silver, Purple, Midnight, Black):\n");

        char color[8];
        gets(color);
        for(int j = 0; j < 8; j++) {
             color[j] = little_word(color[j]);
        }
        if (strcmp(color, "red") == 0) catalog[pos].color = Red;
        else if (strcmp(color, "blue") == 0) catalog[pos].color = Blue;
        else if (strcmp(color, "silver") == 0) catalog[pos].color = Silver;
        else if (strcmp(color, "purple") == 0) catalog[pos].color = Purple;
        else if (strcmp(color, "midnight") == 0) catalog[pos].color = Midnight;
        else if (strcmp(color, "black") == 0) catalog[pos].color = Black;
        else {
            printf("Invalid input.Setting up Red by default.");
            catalog[i].color = Red;
        }

        printf("Enter screen size:\n");
         catalog[pos].screen = check_input(catalog[pos].screen);

        printf("Enter the amount of memory:\n");
         catalog[pos].memory = check_input(catalog[pos].memory);

        printf("Enter cost:\n");
         catalog[pos].cost = check_input(catalog[pos].cost);
    }
}

void print_catalog(phone* catalog, int size)
{
    char* colors_string[6] = {"Red", "Blue", "Silver", "Purple", "Midnight", "Black"};
    for (int i = 0; i < size; i++){
        printf("_____________________________________________________________\n%d.\n", (i+1));
        printf("Name:%s\n", catalog[i].name);
        printf("Color: %s\n", colors_string[catalog[i].color]);
        printf("Screen: %.d\n", catalog[i].screen);
        printf("Memory: %d\n", catalog[i].memory);
        printf("Cost: %.d\n", catalog[i].cost);
        printf("_____________________________________________________________\n");
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
    printf("Enter field(name, color, screen, memory, cost):");
    char* field_for_sort = malloc(8 * sizeof(char));
    rewind(stdin);
    gets(field_for_sort);
    for(int i = 0; i < 8; i++) {
        field_for_sort[i] = little_word(field_for_sort[i]);
    }
    return field_for_sort;
}

void sort_catalog(phone* catalog, int size){
    int n = 0;
    do {
        char *choice = choose_field();
        if (strcmp(choice, "name") == 0)
            qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_name);
        else if (strcmp(choice, "color") == 0)
            qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_color);
        else if (strcmp(choice, "screen") == 0)
            qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_screen);
        else if (strcmp(choice, "memory") == 0)
            qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_memory);
        else if (strcmp(choice, "cost") == 0)
            qsort(catalog, size, sizeof(phone), (int (*)(const void *, const void *)) compare_field_cost);
        print_catalog(catalog, size);
        printf("Do you want to sort the catalog by other characteristics?\n1.Yes\t\t\t\t2.No\nYour choice:");
        n = check(n);
            if (n == 1)
                continue;
            else if(n == 2)
                break;
            else
                printf("There is no such answer");
                break;

    }    while(1);
}

void delete_element(phone** catalog, int* size){
    int delete_num = 0;
    int x = 0;
    do{
        printf("Enter the number of element that you want to delete:");
        rewind(stdin);
        scanf_s("%d", &delete_num);
        for (int i = delete_num; i < (*size - 1); i++) {
            catalog[i - 1] = catalog[i];
        }
        *size -= 1;
        *catalog = (phone *) realloc(*catalog, (*size) * sizeof(phone));
        print_catalog(*catalog, *size);

        printf("Do you want to delete another element?\n1.Yes\t\t\t\t2.No\nYour choice:");
        x = check(x);
        if (x == 1)
            continue;
        else if (x == 2)
            break;
        else
            printf("There is no such answer");
        break;
    }while(1);
}

void add_element(phone** catalog, int* size){
    int buf = *size;
    *size = *size + 1;
    *catalog = (phone*) realloc(*catalog, *size * sizeof(phone));
    initialization(*catalog, *size, buf);
    print_catalog(*catalog, *size);
}

void menu(phone* catalog, int size){
    int key = 0;
    while(1)
    {
        printf("What you want to do?\n1.Print the catalog\n2.Sort by feature\n3.Delete element\n4. Add element\n5.Exit\nYour choice:");
        key = check_key(key);
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