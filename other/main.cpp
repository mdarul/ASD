#include <iostream>
#include "BST.h"
#include "SkipList.h"
#include "Hashtable.h"
#include "FindUnion.h"
#include "PriorityQueue.h"
#include "DynamicGreedy.h"

int main()
{
    int n, W;
    std::cin >> n >> W;
    Item *items = new Item[n];
    for(int i=0; i<n; i++)
    {
        std::cin >> items[i].value >> items[i].weight;
    }

    std::cout << continuous_knapsack_problem(items, n, W);

    return 0;
}