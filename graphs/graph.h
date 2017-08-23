//
// Created by michal on 23/08/17.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include "utils.h"

void BFS_list(vertex **G, int v, int s);
void BFS_table(int **G, int v, int s);
void DFS_list(vertex **G, int v);
void DFS_visit_list(vertex **G, int v, int s, int *color);
void DFS_table(int **G, int v);
void DFS_visit_table(int **G, int v, int s, int *color);

#endif //GRAPHS_GRAPH_H
