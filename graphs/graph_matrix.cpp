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

/**************************************************************/

void transpose_matrix(int **G, int v)
{
    for (int i = 0; i < v; i++)
        for (int j = i; j < v; j++)
            swap(G[i][j], G[j][i]);
}

void kosaraju_matrix(int **G, int v)
{
    // 1 - get evaluation times with DFS
    std::stack<int> stack; // stack will represent how fast a vertex was evaluated in DFS (top - slowest, bottom - fastest)
    int color[v];
    for(int i=0; i<v; i++) color[i] = WHITE;

    for(int i=0; i<v; i++)
        if(color[i] == WHITE)
            kosaraju_matrix_DFSvisit(G, v, i, color, stack);
    // 2 - transpose the graph
    transpose_matrix(G, v);
    // 3 - run DFS on transposed graph from the highest evaluation time to the lowest
    int s;
    for(int i=0; i<v; i++) color[i] = WHITE;
    while(!stack.empty())
    {
        s = stack.top();
        stack.pop();
        if(color[s] == WHITE)
        {
            kosaraju_matrix_DFSprint(G, v, s, color);
            std::cout << std::endl;
        }
    }
}

void kosaraju_matrix_DFSvisit(int **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            kosaraju_matrix_DFSvisit(G, v, i, color, stack);
    color[s] = BLACK;
    stack.push(s);
}

void kosaraju_matrix_DFSprint(int **G, int v, int s, int *color)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            kosaraju_matrix_DFSprint(G, v, i, color);
    std::cout << s << " ";
    color[s] = BLACK;
}

/**************************************************************/

bool check_connectivity_directed_matrix(int **G, int v)
{
    int count=0, *color = new int[v];

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++) color[j] = WHITE;
        count = 0;
        check_connectivity_matrix_DFScount(G, v, i, color, count);
        if(count != v) return false;
    }

    return true;
}

bool check_connectivity_undirected_matrix(int **G, int v)
{
    int count=0, *color = new int[v];
    for(int i=0; i<v; i++) color[i] = WHITE;
    check_connectivity_matrix_DFScount(G, v, 0, color, count);
    return count == v;
}

void check_connectivity_matrix_DFScount(int **G, int v, int s, int *color, int &count)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            check_connectivity_matrix_DFScount(G, v, i, color, count);
    color[s] = BLACK;
    count++;
}

/**************************************************************/

void find_bridges_undirected_matrix(int **G, int v)
{
    if(!check_connectivity_undirected_matrix(G, v)) return; // if graph is not connected there are no bridges

    for(int i=0; i<v; i++)
    {
        for(int j=i; j<v; j++)
        {
            if(G[i][j] == 1)
            {
                G[i][j] = G[j][i] = 0;
                if(!check_connectivity_undirected_matrix(G, v)) std::cout << i << "-" << j << ", ";
                G[i][j] = G[j][i] = 1;
            }
        }
    }
}

void find_bridges_directed_matrix(int **G, int v)
{
    if(!check_connectivity_directed_matrix(G, v)) return; // if graph is not connected there are no bridges

    for(int i=0; i<v; i++)
    {
        for(int j=i; j<v; j++)
        {
            if(G[i][j] == 1)
            {
                G[i][j] = 0;
                if(!check_connectivity_directed_matrix(G, v)) std::cout << i << "-" << j << ", ";
                G[i][j] = 1;
            }
        }
    }
}

/**************************************************************/

bool check_eulerian_cycle_undirected_matrix(int **G, int v)
{
    int degrees[v];
    for(int i=0; i<v; i++) degrees[i] = 0;
    //count degrees
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            if(G[i][j] == 1)degrees[i]++;
    for(int i=0; i<v; i++) std::cout << degrees[i] <<" ";
    std::cout<<std::endl;
    // checking, if all vertices have even degree
    int isolated_amount = 0;
    for(int i=0; i<v; i++)
    {
        if(degrees[i]%2 != 0) return false;
        if(degrees[i] == 0) isolated_amount++;
    }
    // check wheter all non-zero vertices are connected
    return check_eulerian_cycle_undirected_matrix_connectivity(G, v, isolated_amount);
}

bool check_eulerian_cycle_undirected_matrix_connectivity(int **G, int v, int isolated_amount)
{
    int count=0, *color = new int[v];
    for(int i=0; i<v; i++) color[i] = WHITE;
    check_connectivity_matrix_DFScount(G, v, 0, color, count);
    return count == (v - isolated_amount);
}