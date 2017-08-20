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


void create_list(node *&first, int n);
void delete_list(node *first);
void print_list(node *list);

void merge_sort_list(node *&list);
node *quick_sort_list(node *first);


#endif //SORTINGS_LIST_H
