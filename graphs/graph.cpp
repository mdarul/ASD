//
// Created by michal on 23/08/17.
//

#include "graph.h"
#include <climits>
#include <iostream>
#include <stack>
#include <queue>

#define WHITE 0
#define GREY 1
#define BLACK 2

void BFS_list(vertex **G, int v, int s)
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
        for(vertex *tmp_ver = G[current]; tmp_ver; tmp_ver = tmp_ver->next)
        {
            if(color[tmp_ver->value] == WHITE)
            {
                color[tmp_ver->value] = GREY;
                distance[tmp_ver->value] = distance[current] + 1;
                predecessor[tmp_ver->value] = current;
                q.push(tmp_ver->value);
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

void BFS_table(int **G, int v, int s)
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

void DFS_list(vertex **G, int v)
{
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            DFS_visit_list(G, v, i, color);
    std::cout << std::endl;
}
void DFS_visit_list(vertex **G, int v, int s, int *color)
{
    color[s] = GREY;
    std::cout << s << " ";
    for(vertex *tmp_ver = G[s]; tmp_ver; tmp_ver = tmp_ver->next)
        if(color[tmp_ver->value] == WHITE)
            DFS_visit_list(G, v, tmp_ver->value, color);
    color[s] = BLACK;
}

void DFS_table(int **G, int v)
{
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            DFS_visit_table(G, v, i, color);
    std::cout << std::endl;
}
void DFS_visit_table(int **G, int v, int s, int *color)
{
    color[s] = GREY;
    std::cout << s << " ";
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            DFS_visit_table(G, v, i, color);
    color[s] = BLACK;
}