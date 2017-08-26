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

void BFS_matrix(int **G, int v, int s);
void DFS_matrix(int **G, int v);
void DFS_visit_matrix(int **G, int v, int s, int *color);
// assuming that G is DAG
void topological_sort_matrix(int **G, int v);
void topological_sort_matrix_visit(int **G, int v, int s, int *color, std::stack<int> &stack);

void transpose_matrix(int **G, int v);
void kosaraju_matrix(int **G, int v); // find strongly connected components
void kosaraju_matrix_DFSvisit(int **G, int v, int s, int *color, std::stack<int> &stack);
void kosaraju_matrix_DFSprint(int **G, int v, int s, int *color);

bool check_connectivity_directed_matrix(int **G, int v);
bool check_connectivity_undirected_matrix(int **G, int v);
void check_connectivity_matrix_DFScount(int **G, int v, int s, int *color, int &count);

void find_bridges_undirected_matrix(int **G, int v);
void find_bridges_directed_matrix(int **G, int v);

bool check_eulerian_cycle_undirected_matrix(int **G, int v);
bool check_eulerian_cycle_undirected_matrix_connectivity(int **G, int v, int isolated_amount);

#endif //GRAPHS_GRAPH_H
