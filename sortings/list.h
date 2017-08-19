//
// Created by michal on 16/08/17.
//

#ifndef SORTINGS_LIST_H
#define SORTINGS_LIST_H

struct node
{
    int value;
    node *next;
};

node *create_list(int elements_amount);
void add_node(node *first, node *new_node);
void print_list(node *first);

#endif //SORTINGS_LIST_H
