#include <iostream>
#include "BST.h"
#include "SkipList.h"
#include "Hashtable.h"

int main()
{
    int n;
    std::cin >> n;
    
    HashTable *ht = create_hashtable(n);
    remove_from_hashtable(ht, "test");
    print_hashtable(ht);

    return 0;
}