#include <iostream>
#include "List.h"
#include "Table.h"

int main()
{
    int n;
    std::cin >> n;
    node *first = NULL;

    create_list(first, n);
    merge_sort_list(first);
    print_list(first);

    delete_list(first);
    return 0;
}