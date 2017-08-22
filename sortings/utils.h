//
// Created by michal on 19/08/17.
//

#ifndef SORTINGS_UTILS_H
#define SORTINGS_UTILS_H

#include "List.h"

int partition(int *tab, int l, int r);
void swap(int &a, int &b);
void table_merge(int *tab, int n, int l1, int middle, int r2);
void table_sort_by_position(int *tab, int n, int pos);
int get_digit(int number, int pos);
int table_get_max(int *tab, int n);
int table_get_min(int *tab, int n);
int Left(int index);
int Right(int index);
int Parent(int index);
void heapify(int *tab, int size, int index);
void build_heap(int *tab, int size);

void add_node(node *&first, node *new_node);
void split_list(node *list, node *&list1, node *&list2);
node *list_merge(node *&list1, node *&list2);
node *get_head(node *&list);
node *concatenate_lists(node *list1, node *list2, node *list3);


#endif //SORTINGS_UTILS_H
