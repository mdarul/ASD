//
// Created by michal on 25/08/17.
//

#include "graph_list.h"

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

/**************************************************************/

void topological_sort_list(vertex **G, int v)
{
    std::stack<int> stack;
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            topological_sort_list_DFSvisit(G, v, i, color, stack);

    print_stack(stack);
}

void topological_sort_list_DFSvisit(vertex **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;
    for(vertex *tmp_ver = G[s]; tmp_ver; tmp_ver = tmp_ver->next)
        if(color[tmp_ver->value] == WHITE)
            topological_sort_list_DFSvisit(G, v, tmp_ver->value, color, stack);
    color[s] = BLACK;
    stack.push(s);
}

/**************************************************************/

void transpose_list(vertex **&G, int v)
{
    vertex **new_G = new vertex*[v];
    for(int i=0; i<v; i++) new_G[i] = NULL;

    for(int i=0; i<v; i++)
    {
        for(vertex *tmp = G[i]; tmp; tmp = tmp->next)
        {
            vertex *new_vertex = new vertex;
            new_vertex->value = i;
            new_vertex->next = new_G[tmp->value];
            new_G[tmp->value] = new_vertex;
        }
    }

    for(int i=0; i<v; i++) free(G[i]);
    G = new_G;
}

void strongly_connected_components_list(vertex **G, int v)
{
    // 1 - get evaluation times with DFS
    std::stack<int> stack; // stack will represent how fast a vertex was evaluated in DFS (top - slowest, bottom - fastest)
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            strongly_connected_components_list_DFSvisit(G, v, i, color, stack);
    // 2 - transpose the graph
    transpose_list(G, v);
    // 3 - run DFS on transposed graph from the highest evaluation time to the lowest
    int s;
    for(int i=0; i<v; i++) color[i] = WHITE;
    while(!stack.empty())
    {
        s = stack.top();
        stack.pop();
        if(color[s] == WHITE)
        {
            strongly_connected_components_list_DFSprint(G, v, s, color);
            std::cout << std::endl;
        }
    }
}

void strongly_connected_components_list_DFSvisit(vertex **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;
    for(vertex *tmp_ver = G[s]; tmp_ver; tmp_ver = tmp_ver->next)
        if(color[tmp_ver->value] == WHITE)
            strongly_connected_components_list_DFSvisit(G, v, tmp_ver->value, color, stack);
    color[s] = BLACK;
    stack.push(s);
}

void strongly_connected_components_list_DFSprint(vertex **G, int v, int s, int *color)
{
    color[s] = GREY;
    for(vertex *tmp_ver = G[s]; tmp_ver; tmp_ver = tmp_ver->next)
        if(color[tmp_ver->value] == WHITE)
            strongly_connected_components_list_DFSprint(G, v, tmp_ver->value, color);
    std::cout << s << " ";
    color[s] = BLACK;
}