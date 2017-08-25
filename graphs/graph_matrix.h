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
void strongly_connected_components_matrix(int **G, int v);
void strongly_connected_components_matrix_DFSvisit(int **G, int v, int s, int *color, std::stack<int> &stack);
void strongly_connected_components_matrix_DFSprint(int **G, int v, int s, int *color);


#endif //GRAPHS_GRAPH_H
