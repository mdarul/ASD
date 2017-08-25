//
// Created by michal on 23/08/17.
//

#ifndef GRAPHS_UTILS_H
#define GRAPHS_UTILS_H

#include <iostream>
#include <stack>

struct vertex
{
    int value;
    vertex *next;
};

vertex **create_directed_list(int v, int e); // v - vertices, e - edges
vertex **create_undirected_list(int v, int e);
int **create_directed_matrix(int v, int e);
int **create_undirected_matrix(int v, int e);
void display_list(vertex **G, int v);
void display_matrix(int **G, int v);

void print_stack(std::stack<int> s);

#endif //GRAPHS_UTILS_H
