//
// Created by michal on 28/08/17.
//

#ifndef OTHER_DYNAMIC_H
#define OTHER_DYNAMIC_H

struct Activity
{
    int id; // assuming that id != -1
    int start_time, end_time;
};

struct Item
{
    int value;
    int weight;
};

// dynamic
int longest_common_subsequence(char *tab1, char *tab2, int n, int m);
int knapsack01_problem(Item *items, int n, int W); // W - knapsack capacity
// greedy
void activity_selection_problem(Activity *activities, int n);
float continuous_knapsack_problem(Item *items, int n, int W);

#endif //OTHER_DYNAMIC_H
