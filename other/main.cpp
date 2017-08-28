#include <iostream>
#include "BST.h"
#include "SkipList.h"
#include "Hashtable.h"
#include "FindUnion.h"
#include "PriorityQueue.h"
#include "DynamicGreedy.h"

int main()
{
    int n;
    std::cin >> n;
    Activity *activities = new Activity[n];
    for(int i=0; i<n; i++)
    {
        activities[i].id = i;
        std::cin >> activities[i].start_time >> activities[i].end_time;
    }

    activity_selection_problem(activities, n);

    return 0;
}