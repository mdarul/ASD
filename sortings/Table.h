//
// Created by michal on 17/08/17.
//
#ifndef SORTINGS_TABLE_SORTINGS_H
#define SORTINGS_TABLE_SORTINGS_H

class Table
{
    int n;
    int *tab;
public:
    Table(int n1)
    {
        n = n1;
        tab = new int[n];
    }
    //~Table();

    void fill();
    void print();

    void bubble_sort();
    void quicksort(int l, int r);
    void selection_sort();
    void insertion_sort();
    void merge_sort(int l, int r);
    void bucket_sort();
    void counting_sort();
    void radix_sort();
    void heap_sort();

};

#endif //SORTINGS_TABLE_SORTINGS_H
