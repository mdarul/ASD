//
// Created by michal on 25/08/17.
//

#ifndef GRAPHS_GRAPH_LIST_H
#define GRAPHS_GRAPH_LIST_H

#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include "utils.h"

void BFS_list(vertex **G, int v, int s);
void DFS_list(vertex **G, int v);
void DFS_visit_list(vertex **G, int v, int s, int *color);

void topological_sort_list(vertex **G, int v); // assuming that G is DAG

void transpose_list(vertex **&G, int v);
void kosaraju_list(vertex **G, int v); // find strongly connected components

bool check_connectivity_directed_list(vertex **G, int v);
bool check_connectivity_undirected_list(vertex **G, int v);

#endif //GRAPHS_GRAPH_LIST_H
