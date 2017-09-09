//
// Created by michal on 09/09/17.
//

#include "2017utils.h"

void create_list(Node *&first, int n)
{
    first = new Node();
    first->next = NULL;
    std::cin >> first->value;

    int count = n - 1;
    while(count > 0)
    {
        Node *new_node = new Node();
        new_node->next = NULL;
        std::cin >> new_node->value;
        add_node(first, new_node);
        count--;
    }
}

void print_list(Node *first)
{
    while(first)
    {
        std::cout<<first->value<<" ";
        first = first->next;
    }
    std::cout<<"\n";
}

void add_node(Node *&first, Node *new_node)
{
    if(first == NULL)
    {
        first = new_node;
        return;
    }
    else
    {
        Node *guard = first;
        while(first->next) first = first->next;
        first->next = new_node;
        first = guard;
    }
}

int get_interval(double interval_length, double value)
{
    int count = 0;
    while(value > interval_length){
        value -= interval_length;
        count++;
    }
    return count;
}

void add_node_at_beginning(Node *&first, Node *new_node)
{
    new_node->next = first;
    first = new_node;
}

void split_list(Node *list, Node *&list1, Node *&list2)
{
    Node *tmp1 = list;
    Node *tmp2 = list;

    while(tmp1)
    {
        tmp1 = tmp1->next;
        if(tmp1)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    list2 = tmp2;

    list1 = list;
    while(list->next != list2) list = list->next;
    list->next = NULL;
}

Node *list_merge(Node *&list1, Node *&list2)
{
    Node *result = NULL;

    if(list1 == NULL) return list2;
    else if(list2 == NULL) return list1;

    if(list1->value < list2->value)
    {
        result = list1;
        result->next = list_merge(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = list_merge(list1, list2->next);
    }

    return result;
}

void merge_sort_list(Node *&list)
{
    if(list == NULL or list->next == NULL) return;

    Node *list1, *list2;
    split_list(list, list1, list2);
    merge_sort_list(list1);
    merge_sort_list(list2);
    list = list_merge(list1, list2);
}

Node *merge_buckets(Node **bucket, int n)
{
    Node *result = new Node, *guard;
    result->next = NULL;
    guard = result;

    for(int i=0; i<n; i++)
    {
        if(bucket[i])
        {
            result->next = bucket[i];
            while(result->next) result = result->next;
        }
    }

    return guard->next;
}

/****************************************************************************************/

Job *create_jobs(int n)
{
    Job *jobs = new Job[n];
    for(int i=0; i<n; i++) std::cin >> jobs[i].start >> jobs[i].end;
    return jobs;
}

int find_min_impatientBob(Job *jobs, int **tab, int i, int j)
{
    int min = INT_MAX;
    int min_index = INT_MAX;

    for(int x=i-1; x>=1; x--)
    {
        if (jobs[i - 1].start >= jobs[x - 1].end and tab[x][j - 1] != INT_MAX)
        {
            if (min > jobs[i - 1].start - jobs[x - 1].end)
            {
                min = jobs[i - 1].start - jobs[x - 1].end;
                min_index = x;
                std::cout << "minimum i=" << i << ", j=" << j << ":" << min << ", " << jobs[i - 1].start << "-" << jobs[x - 1].end << ", min_index=" << x << "\n";
            }
        }
    }

    return (min == INT_MAX ? INT_MAX : (tab[min_index][j-1] + min));
}