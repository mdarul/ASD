//
// Created by michal on 28/08/17.
//

#include <iostream>
#include "DynamicGreedy.h"

int max(int a, int b)
{
    return a>b ? a : b;
}

int longest_common_subsequence(char *tab1, char *tab2, int n, int m)
{
    int result[n+1][m+1];
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            result[i][j] = -1;
        }
    }
    for (int i = 0; i < n + 1; i++) result[i][0] = 0;
    for (int j = 0; j < m + 1; j++) result[0][j] = 0;

    for(int i=1; i<n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(tab1[i-1] == tab2[j-1]) result[i][j] = result[i-1][j-1] + 1;
            else result[i][j] = max(result[i-1][j], result[i][j-1]);
        }
    }

    return result[n][m];
}

int knapsack01_problem(Item *items, int n, int W)
{
    int result[n][W+1];
    for(int i=0; i<n+1; i++) result[i][0] = 0;
    for(int j=0; j<W+1; j++) result[0][j] = 0;

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j< W+1; j++)
        {
            if(j < items[i-1].weight) result[i][j] = result[i-1][j];
            else result[i][j] = max(items[i-1].value + result[i-1][j - items[i-1].weight], result[i-1][j]);
        }
    }

    return result[n][W];
}

/*********************************************************************************/

void swap_activities(Activity &a1, Activity &a2)
{
    Activity tmp = a1;
    a1 = a2;
    a2 = tmp;
}

int partition_activity(Activity *&activities, int l, int r)
{
    int x = activities[r].end_time;
    int i, j=l;
    for(i=l; i<r; i++)
    {
        if(activities[i].end_time <= x)
        {
            swap_activities(activities[i], activities[j]);
            j++;
        }
    }
    swap_activities(activities[j], activities[r]);
    return j;
}

void sort_activities(Activity *&activities, int l, int r)
{
    if(l<r)
    {
        int x = partition_activity(activities, l, r);
        sort_activities(activities, l, x-1);
        sort_activities(activities, x+1, r);
    }
}

void activity_selection_problem(Activity *activities, int n)
{
    sort_activities(activities, 0, n-1); // sorting activities by ending time
    int result[n];
    for (int i = 0; i < n; ++i) result[i] = -1;

    result[0] = 0; // starting point is activity that ends first
    int last_index = 0; // index of last activity
    int count = 1; // next index in result table that can serve for writing

    for(int i=1; i<n; i++)
    {
        if(activities[i].start_time > activities[last_index].end_time)
        {
            result[count++] = i;
            last_index = i;
        }
    }

    int i = 0;
    while(result[i] != -1)
    {
        std::cout << "id: " << activities[result[i]].id << ", start_time: " << activities[result[i]].start_time << ", end_time: " << activities[result[i]].end_time << std::endl;
        i++;
    }
}

void swap_items(Item &i1, Item &i2)
{
    Item tmp = i1;
    i1 = i2;
    i2 = tmp;
}

float get_item_ratio(Item item)
{
    return (float) item.value / (float) item.weight;
}

int partition_item(Item *&items, int l, int r)
{
    float x = get_item_ratio(items[r]);
    int i, j=l;
    for(i=l; i<r; i++)
    {
        if(get_item_ratio(items[i]) <= x)
        {
            swap_items(items[i], items[j]);
            j++;
        }
    }
    swap_items(items[j], items[r]);
    return j;
}

void sort_items(Item *&items, int l, int r)
{
    if(l<r)
    {
        int x = partition_item(items, l, r);
        sort_items(items, l, x-1);
        sort_items(items, x+1, r);
    }
}

float continuous_knapsack_problem(Item *items, int n, int W)
{
    sort_items(items, 0, n-1);

    int weight = 0, i = n-1;
    float result = 0;
    while(1)
    {
        if(weight + items[i].weight > W)
        {
            result += ((float)(W-weight)/(float)items[i].weight) * items[i].value;
            std::cout << items[i].value << " " << items[i].weight << " " << result << std::endl;
            break;
        }
        else
        {
            std::cout << items[i].value << " " << items[i].weight << std::endl;
            weight += items[i].weight;
            result += items[i].value;
            i--;
        }
    }

    return result;
}