#include <iostream>
#include "BST.h"
#include "SkipList.h"
#include "Hashtable.h"
#include "FindUnion.h"

int main()
{
    Subset *set1 = make_set(1);
    Subset *set2 = make_set(2);

    std::cout << set2->rank << " " << set2->parent->rank << std::endl;
    Union(set1, set2);
    std::cout << set2->x << " " << set2->parent->x << std::endl;
    std::cout << set2->rank << " " << set2->parent->rank << std::endl;

    return 0;
}