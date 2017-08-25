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
void topological_sort_list_DFSvisit(vertex **G, int v, int s, int *color, std::stack<int> &stack);

void transpose_list(vertex **&G, int v);
void strongly_connected_components_list(vertex **G, int v);
void strongly_connected_components_list_DFSvisit(vertex **G, int v, int s, int *color, std::stack<int> &stack);
void strongly_connected_components_list_DFSprint(vertex **G, int v, int s, int *color);

bool check_connectivity_directed_list(vertex **G, int v);
bool check_connectivity_undirected_list(vertex **G, int v);
void check_connectivity_list_DFScount(vertex **G, int v, int s, int *color, int &count);

#endif //GRAPHS_GRAPH_LIST_H
