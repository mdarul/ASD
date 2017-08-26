//
// Created by michal on 23/08/17.
//

#ifndef GRAPHS_UTILS_H
#define GRAPHS_UTILS_H

#include <iostream>
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

void swap(int &a, int &b);

vertex **create_directed_list(int v, int e); // v - vertices, e - edges
vertex **create_undirected_list(int v, int e);
void display_list(vertex **G, int v);

int **create_directed_matrix(int v, int e);
int **create_undirected_matrix(int v, int e);
int **create_weighted_directed_matrix(int v, int e);
int **create_weighted_undirected_matrix(int v, int e);
void display_matrix(int **G, int v);

void print_stack(std::stack<int> s);

Subset *make_set(int x);
Subset *Find(Subset *s);
void Union(Subset *s1, Subset *s2);

#endif //GRAPHS_UTILS_H
