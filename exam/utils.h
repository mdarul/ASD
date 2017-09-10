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

struct BSTnode
{
    int value;
    BSTnode *left, *right, *parent;
};

struct Edge
{
    int v1, v2;
    int weight;
};

struct Subset
{
    int x;
    int rank;
    Subset *parent;
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

void swap(int &a, int &b);
int partition(int *tab, int l, int r);
int find_element_sorted_position(int *tab, int n, int k);

BSTnode *create_bst(int n);
void print_bst(BSTnode *root);
void add_node(BSTnode *&root, BSTnode *&new_node);

void sort_edges(Edge *edges, int e);
Subset *MakeSet(int x);
Subset *Find(Subset *s);
void Union(Subset *s1, Subset *s2);
int **create_weighted_undirected_matrix(int v, int e);
void display_matrix(int **G, int v);

int max(int a, int b);
int longest_increasing_subsequence(int *tab, int n);

#endif //INC_2017_2017_H
