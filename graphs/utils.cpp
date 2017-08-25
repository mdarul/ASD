//
// Created by michal on 23/08/17.
//

#include "utils.h"

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

vertex **create_directed_list(int v, int e)
{
    vertex **G = new vertex *[v];
    for(int i=0; i<v; i++) G[i] = NULL;

    int val1, val2;
    for(int i=0; i<e; i++)
    {
        std::cin >> val1 >> val2;

        vertex *new_vertex = new vertex;
        new_vertex->value = val2;
        new_vertex->next = G[val1];
        G[val1] = new_vertex;
    }

    return G;
}

vertex **create_undirected_list(int v, int e)
{
    vertex **G = new vertex *[v];
    for(int i=0; i<v; i++) G[i] = NULL;

    int val1, val2;
    for(int i=0; i<e; i++)
    {
        std::cin >> val1 >> val2;

        vertex *new_vertex1 = new vertex;
        new_vertex1->value = val2;
        new_vertex1->next = G[val1];
        G[val1] = new_vertex1;

        vertex *new_vertex2 = new vertex;
        new_vertex2->value = val1;
        new_vertex2->next = G[val2];
        G[val2] = new_vertex2;
    }

    return G;
}

int **create_directed_matrix(int v, int e)
{
    int **G = new int *[v];
    for(int i=0; i<v; i++) G[i] = new int[v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            G[i][j] = 0;

    int val1, val2;
    for(int i=0; i<e; i++)
    {
        std::cin >> val1 >> val2;
        G[val1][val2] = 1;
    }

    return G;
}

int **create_undirected_matrix(int v, int e)
{
    int **G = new int *[v];
    for(int i=0; i<v; i++) G[i] = new int[v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            G[i][j] = 0;

    int val1, val2;
    for(int i=0; i<e; i++)
    {
        std::cin >> val1 >> val2;
        G[val1][val2] = G[val2][val1] = 1;
    }

    return G;
}

void display_list(vertex **G, int v)
{
    vertex *tmp;
    for(int i=0; i<v; i++)
    {
        tmp = G[i];
        std::cout << i <<": ";
        while(tmp)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void display_matrix(int **G, int v)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++) std::cout << G[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_stack(std::stack<int> s)
{
    while(!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

