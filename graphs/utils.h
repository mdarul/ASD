//
// Created by michal on 23/08/17.
//

#ifndef GRAPHS_UTILS_H
#define GRAPHS_UTILS_H

#include <iostream>
#include <climits>
#include <stack>

#define WHITE 0
#define GREY 1
#define BLACK 2

struct vertex
{
    int value;
    vertex *next;
};

struct Subset
{
    int x;
    int rank;
    Subset *parent;
};

struct Data
{
    int value;
    int priority;
};

struct PriorityQueue
{
    int max_size;
    int cur_size;
    Data *queue_array;
};


void swap(int &a, int &b);
void print_stack(std::stack<int> s);

vertex **create_directed_list(int v, int e); // v - vertices, e - edges
vertex **create_undirected_list(int v, int e);
void display_list(vertex **G, int v);

int **create_directed_matrix(int v, int e);
int **create_undirected_matrix(int v, int e);
int **create_weighted_directed_matrix(int v, int e);
int **create_weighted_undirected_matrix(int v, int e);
void display_matrix(int **G, int v);

Subset *make_set(int x);
Subset *Find(Subset *s);

void Union(Subset *s1, Subset *s2);
int Left(int index);
int Right(int index);
int Parent(int index);
void swap_data(Data &d1, Data &d2);

void insert_element(PriorityQueue *q, int value, int priority);
Data heap_extract_min(PriorityQueue *q);
void heapify(PriorityQueue *q, int index);

#endif //GRAPHS_UTILS_H
