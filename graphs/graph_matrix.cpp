//
// Created by michal on 23/08/17.
//

#include "graph_matrix.h"

void BFS_matrix(int **G, int v, int s)
{
    int *color = new int[v], *distance = new int[v], *predecessor = new int[v];
    for(int i=0; i<v; i++)
    {
        color[i] = WHITE;
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    std::queue<int> q;
    q.push(s);
    color[s] = GREY;
    distance[s] = 0;
    predecessor[s] = -1;

    int current;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        std::cout << current << " ";
        for(int i=0; i<v; i++)
        {
            if(G[current][i] == 1 and color[i] == WHITE)
            {
                color[i] = GREY;
                distance[i] = distance[current] + 1;
                predecessor[i] = current;
                q.push(i);
            }
        }
        color[current] = BLACK;
    }
    //performing some operation, i'll just print all obtained data
    std::cout << std::endl;
    for(int i=0; i<v; i++)
    {
        std::cout << "index: " << i << ", distance: " << distance[i] << ", predecessor: " << predecessor[i] << std::endl;
    }
}

void DFS_matrix(int **G, int v)
{
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            DFS_visit_matrix(G, v, i, color);
    std::cout << std::endl;
}
void DFS_visit_matrix(int **G, int v, int s, int *color)
{
    color[s] = GREY;
    std::cout << s << " ";
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            DFS_visit_matrix(G, v, i, color);
    color[s] = BLACK;
}

/**************************************************************/

void topological_sort_matrix(int **G, int v)
{
    std::stack<int> stack;
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            topological_sort_matrix_visit(G, v, i, color, stack);

    print_stack(stack);
}
void topological_sort_matrix_visit(int **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            topological_sort_matrix_visit(G, v, i, color, stack);
    color[s] = BLACK;
    stack.push(s);
}