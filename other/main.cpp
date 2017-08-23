#include <iostream>
#include "BST.h"
#include "SkipList.h"
#include "Hashtable.h"
#include "FindUnion.h"
#include "PriorityQueue.h"

int main()
{
    int n;
    std::cin >> n;

    PriorityQueue *q = create_queue(n);
    print_queue(q);

    return 0;
}