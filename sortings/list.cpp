//
// Created by michal on 16/08/17.
//
#include <iostream>
#include "list.h"
using namespace std;

node *create_list(int elements_amount)
{
    if(elements_amount <= 0)
    {
        cout<<"Incorrect amount of elements!\n";
        return NULL;
    }

    node *first = new node();
    first->next = NULL;
    cin >> first->value;

    int count = elements_amount - 1;
    while(count > 0)
    {
        node *new_node = new node();
        new_node->next = NULL;
        cin >> new_node->value;
        add_node(first, new_node);
        count--;
    }

    return first;
}

void add_node(node *first, node *new_node)
{
    while(first->next) first = first->next;
    first->next = new_node;
}

void print_list(node *first)
{
    while(first)
    {
        cout<<first->value<<" ";
        first = first->next;
    }
    cout<<"\n";
}