#include <iostream>
#include "BST.h"
#include "SkipList.h"

int main()
{
    int n;
    std::cin >> n;

    SkipList *sl = create_skiplist(5, n);
    print_skiplist(sl);
    remove_node(sl, find_node(sl, 5));
    print_skiplist(sl);

    return 0;
}