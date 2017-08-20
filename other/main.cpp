#include <iostream>
#include "BST.h"

int main()
{
    int n;
    std::cin >> n;
    BSTnode *root;

    create_bst(root, n);
    print_bst(root);

    BSTnode *find = find_node(root, 5);
    std::cout << find->value;

    return 0;
}