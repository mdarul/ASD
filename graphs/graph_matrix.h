//
// Created by michal on 23/08/17.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include "utils.h"

struct Edge
{
    int vertex1, vertex2;
    int weight;
};

void BFS_matrix(int **G, int v, int s);
void DFS_matrix(int **G, int v);
void DFS_visit_matrix(int **G, int v, int s, int *color);

// assuming that G is DAG
void topological_sort_matrix(int **G, int v);

void transpose_matrix(int **G, int v);
void kosaraju_matrix(int **G, int v); // find strongly connected components

bool check_connectivity_directed_matrix(int **G, int v);
bool check_connectivity_undirected_matrix(int **G, int v);

void find_bridges_undirected_matrix(int **G, int v);
void find_bridges_directed_matrix(int **G, int v);

bool check_eulerian_cycle_undirected_matrix(int **G, int v);
void print_eulerian_cycle_undirected_matrix(int **G, int v);

int kruskal_matrix(int **G, int v, int e);
int prim_matrix(int **G, int v);

#endif //GRAPHS_GRAPH_H
