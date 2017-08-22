#include <iostream>
#include "List.h"
#include "Table.h"

int main()
{
    int n;
    std::cin >> n;
    Table *tab = new Table(n);

    tab->fill();
    tab->print();
    tab->heap_sort();
    tab->print();

    return 0;
}