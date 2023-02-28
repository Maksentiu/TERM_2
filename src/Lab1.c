#include "function.h"

int main() {

    printf_s("Enter the number of elements you want to create: ");
    int size = check_input();
    phone* catalog = create_catalog(size);
    initialization(catalog, size, 0);
    menu(catalog, size);
    return 0;
}