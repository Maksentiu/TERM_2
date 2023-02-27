#include "function.h"

int main() {
    int size = 0;
    printf_s("Enter the number of elements you want to create: ");
    size = check_input(size);
    phone* catalog = create_catalog(size);
    initialization(catalog, size, 0);
    menu(catalog, size);
    return 0;
}