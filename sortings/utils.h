//
// Created by michal on 19/08/17.
//

#ifndef SORTINGS_UTILS_H
#define SORTINGS_UTILS_H

int partition(int *tab, int l, int r);
void swap(int &a, int &b);
void table_merge(int *tab, int n, int l1, int middle, int r2);
void table_sort_by_position(int *tab, int n, int pos);
int get_digit(int number, int pos);
int table_get_max(int *tab, int n);
int table_get_min(int *tab, int n);

#endif //SORTINGS_UTILS_H
