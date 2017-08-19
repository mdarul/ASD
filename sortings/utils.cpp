//
// Created by michal on 19/08/17.
//

#include "utils.h"

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int *tab, int l, int r)
{
    int x = tab[r];
    int i, j=l;
    for(i=l; i<r; i++)
    {
        if(tab[i] <= x)
        {
            swap(tab[i], tab[j]);
            j++;
        }
    }
    swap(tab[j], tab[r]);
    return j;
}

void table_merge(int *tab, int n, int l1, int middle, int r2)
{
    int *tmp_tab = new int[n];
    int i = l1, start = l1;

    int r1 = middle;
    int l2 = middle+1;

    while(l1<=r1 and l2<=r2)
        tab[l1] > tab[l2] ? tmp_tab[i++] = tab[l2++] : tmp_tab[i++] = tab[l1++];

    while(l1<=r1)
        tmp_tab[i++] = tab[l1++];
    while(l2<=r2)
        tmp_tab[i++] = tab[l2++];

    for(int j=start; j<=r2; j++) tab[j] = tmp_tab[j];
}

int get_digit(int number, int pos)
{
    int tmp = number;
    return (tmp / pos) % 10;
}

void table_sort_by_position(int *tab, int n, int pos)
{
    int *A = new int[10];
    int *B = new int[n];

    for(int i=0; i<10; i++) A[i] = 0;
    for(int i=0; i<n; i++)A[get_digit(tab[i], pos)]++;

    for(int i=1; i<10; i++) A[i] = A[i] + A[i-1];

    for(int i=0; i<n; i++) B[i] = 0;
    for(int i=n-1; i>=0; i--)
    {
        B[A[get_digit(tab[i], pos)]-1] = tab[i];
        A[get_digit(tab[i], pos)]--;
    }

    for(int i=0; i<n; i++) tab[i] = B[i];
    delete[] A;
    delete[] B;
}

int table_get_max(int *tab, int n)
{
    int max = tab[0];
    for(int i=1; i<n; i++) if(tab[i]>max) max=tab[i];
    return max;
}

int table_get_min(int *tab, int n)
{
    int min = tab[0];
    for(int i=1; i<n; i++) if(tab[i]<min) min=tab[i];
    return min;
}