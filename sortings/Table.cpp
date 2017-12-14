//
// Created by michal on 17/08/17.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "Table.h"
#include "utils.h"

void Table::fill()
{
    for(int i=0; i<n; i++) std::cin >> tab[i];
}

void Table::print()
{
    for(int i=0; i<n; i++) std::cout << tab[i]<<" ";
    std::cout<<"\n";
}

void Table::bubble_sort()
{
    bool end;
    for(int i=0; i<n; i++)
    {
        end = false;
        for(int j=0; j<n-1; j++)
        {
            if(tab[j] > tab[j+1])
            {
                swap(tab[j], tab[j+1]);
                end = true;
            }
        }
        if(!end) break;
    }
}

void Table::quicksort(int l, int r)
{
    if(l < r)
    {
        int x = partition(tab, l, r);
        quicksort(l, x-1);
        quicksort(x+1, r);
    }
}

void Table::selection_sort()
{
    int min_index;
    for(int i=0; i<n; i++)
    {
        min_index = i;
        for(int j=i; j<n; j++) // looking for minimum
        {
            if(tab[j] < tab[min_index]) min_index = j;
        }
        swap(tab[i], tab[min_index]);
    }
}

void Table::insertion_sort()
{
    for(int i=1; i<n; i++)
    {
        int key = tab[i];
        int j = i-1;
        while(j >= 0 and tab[j] > key)
        {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = key;
    }
}

void Table::merge_sort(int l, int r)
{
    if(l < r)
    {
        int middle = (r+l)/2;
        merge_sort(l, middle);
        merge_sort(middle+1, r);
        table_merge(tab, n, l, middle, r);
    }
}

void Table::bucket_sort()
{
    std::vector<int> bucket[n+1];
    int bucket_number, max , min; // <min, max> will be our range
    max = table_get_max(this->tab, this->n);
    min = table_get_min(this->tab, this->n);
    // put elements to buckets
    for(int i=0; i<n; i++)
    {
        bucket_number = (int) (((float)(tab[i] - min)) / (float)(max - min) * n);
        bucket[bucket_number].push_back(tab[i]);
    }
    // sort every bucket with more than one element
    for(int i=0; i<=n; i++)
        if(bucket[i].size() > 1)
            sort(bucket[i].begin(), bucket[i].end());

    // merge sorted buckets
    int k = 0;
    for(int i=0; i<=n; i++)
    {
        if(!bucket[i].empty())
            for(std::vector<int>::const_iterator j = bucket[i].begin(); j != bucket[i].end(); ++j) tab[k++] = *j;
    }
}

void Table::counting_sort()
{
    int max = table_get_max(tab, n) + 1;
    int *A = new int[max];
    int *B = new int[n];

    for(int i=0; i<max; i++) A[i] = 0;
    for(int i=0; i<n; i++)A[tab[i]]++;
    for(int i=1; i<max; i++) A[i] = A[i] + A[i-1];

    for(int i=0; i<n; i++) B[i] = 0;
    for(int i=n-1; i>=0; i--)
    {
        B[A[tab[i]]-1] = tab[i];
        A[tab[i]]--;
    }
    for(int i=0; i<n; i++) tab[i] = B[i];
    delete[] A;
    delete[] B;
}

void Table::radix_sort()
{
    int max_length=1, tmp;
    tmp = table_get_max(tab, n);

    while(tmp)
    {
        tmp/=10;
        max_length*=10;
    }

    for(int pos=1; pos < max_length; pos*=10) table_sort_by_position(tab, n, pos);
}

void Table::heap_sort()
{
    build_heap(tab, n);
    for(int i=n-1;i>=1;i--)
    {
        swap(tab[i], tab[0]);
        heapify(tab, i, 0);
    }
}