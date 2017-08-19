#include <iostream>
#include "list.h"
#include "Table.h"

int main()
{
    int n;
    std::cin >> n;
    Table *table = new Table(n);

    table->fill();
    table->bucket_sort();
    table->print();

    return 0;
}