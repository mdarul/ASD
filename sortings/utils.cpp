//
// Created by michal on 19/08/17.
//
#include <iostream>
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

/*************************************************************************/

void add_node(node *&first, node *new_node)
{
    if(first == NULL)
    {
        first = new_node;
        return;
    }
    else
    {
        node *guard = first;
        while(first->next) first = first->next;
        first->next = new_node;
        first = guard;
    }
}

void split_list(node *list, node *&list1, node *&list2)
{
    node *tmp1 = list;
    node *tmp2 = list;

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

node *list_merge(node *&list1, node *&list2)
{
    node *result = NULL;

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

node *get_head(node *&list)
{
    node *tmp;
    tmp = list;
    list = list->next;
    tmp->next = NULL;
    return tmp;
}

node *concatenate_lists(node *list1, node *list2, node *list3)
{
    node *tmp1=list1, *tmp2=list2;

    if(tmp1) while(tmp1->next) tmp1 = tmp1->next;
    if(tmp2) while(tmp2->next) tmp2 = tmp2->next;

    if(list1!=NULL and list2!=NULL)
    {
        tmp1->next = list2;
        tmp2->next = list3;
        return list1;
    }
    else if(list1==NULL and list2!=NULL)
    {
        tmp2->next = list3;
        return list2;
    }
    else if(list1!=NULL and list2==NULL)
    {
        tmp1->next = list3;
        return list1;
    }
    else if(list1==NULL and list2==NULL)
    {
        return list3;
    }
}
