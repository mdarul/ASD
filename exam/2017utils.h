//
// Created by michal on 09/09/17.
//

#ifndef INC_2017_2017_H
#define INC_2017_2017_H

#include <iostream>
#include <climits>

struct Node
{
    Node *next;
    double value;
};

struct Job
{
    int start;
    int end;
};

void create_list(Node *&first, int n);
void print_list(Node *first);
void add_node(Node *&first, Node *new_node);
void add_node_at_beginning(Node *&first, Node *new_node);
int get_interval(double interval_length, double value);
void split_list(Node *list, Node *&list1, Node *&list2);
Node *list_merge(Node *&list1, Node *&list2);
void merge_sort_list(Node *&list);
Node *merge_buckets(Node **buckets, int n);

Job *create_jobs(int n);
int find_min_impatientBob(Job *jobs, int **tab, int i, int j);

#endif //INC_2017_2017_H
