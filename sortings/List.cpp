//
// Created by michal on 16/08/17.
//
#include <iostream>
#include "List.h"
#include "utils.h"

void create_list(node *&first, int n)
{
    first = new node();
    first->next = NULL;
    std::cin >> first->value;

    int count = n - 1;
    while(count > 0)
    {
        node *new_node = new node();
        new_node->next = NULL;
        std::cin >> new_node->value;
        add_node(first, new_node);
        count--;
    }
}

void delete_list(node *first)
{
    std::cout << "Deleting list...\n";
    node *tmp;
    while(first)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
}

void print_list(node *first)
{
    node *guard = first;
    while(first)
    {
        std::cout<<first->value<<" ";
        first = first->next;
    }
    std::cout<<"\n";
}

void merge_sort_list(node *&list)
{
    if(list == NULL or list->next == NULL) return;

    node *list1, *list2;
    split_list(list, list1, list2);
    merge_sort_list(list1);
    merge_sort_list(list2);
    list = list_merge(list1, list2);
}

node *quick_sort_list(node *first)
{
    if(first == NULL) return NULL;

    node *list1=NULL, *list2=NULL, *list3=NULL, *tmp=NULL;
    node *pivot = get_head(first);
    add_node(list2, pivot);

    while(first)
    {
        tmp = get_head(first);
        if(tmp->value < pivot->value) add_node(list1, tmp);
        else if(tmp->value > pivot->value) add_node(list3, tmp);
        else add_node(list2, tmp);
    }

    return concatenate_lists(quick_sort_list(list1), list2, quick_sort_list(list3));
}