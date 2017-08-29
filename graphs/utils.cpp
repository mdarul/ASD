//
// Created by michal on 23/08/17.
//

#include "utils.h"

void print_stack(std::stack<int> s)
{
    while(!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// GRAPH UTILS

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

int **create_weighted_directed_matrix(int v, int e)
{
    int **G = new int *[v];
    for(int i=0; i<v; i++) G[i] = new int[v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            G[i][j] = 0;

    int val1, val2, weight;
    for(int i=0; i<e; i++)
    {
        std::cin >> val1 >> val2 >> weight;
        G[val1][val2] = weight;
    }

    return G;
}

int **create_weighted_undirected_matrix(int v, int e)
{
    int **G = new int *[v];
    for(int i=0; i<v; i++) G[i] = new int[v];
    for(int i=0; i<v; i++)
        for(int j=0; j<v; j++)
            G[i][j] = 0;

    int val1, val2, weight;
    for(int i=0; i<e; i++)
    {
        std::cin >> val1 >> val2 >> weight;
        G[val1][val2] = G[val2][val1] = weight;
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


// FIND & UNION

Subset *make_set(int x)
{
    Subset *subset = new Subset;
    subset->x = x;
    subset->rank = 0;
    subset->parent = subset;
    return subset;
}

Subset *Find(Subset *s)
{
    if(s->parent != s) s->parent = Find(s->parent);
    return s->parent;
}

void Union(Subset *s1, Subset *s2)
{
    s1 = Find(s1);
    s2 = Find(s2);

    if(s1->rank > s2->rank) s2->parent = s1;
    else if (s2->rank < s1->rank) s1->parent = s2;
    else
    {
        s2->parent = s1;
        s1->rank++;
    }
}

// PRIORITY QUEUE

int Left(int index)
{
    return index*2 + 1;
}

int Right(int index)
{
    return index*2 + 2;
}

int Parent(int index)
{
    return (index-1) / 2;
}

void swap_data(Data &d1, Data &d2)
{
    Data tmp_data = d1;
    d1 = d2;
    d2 = tmp_data;
}

void insert_element(PriorityQueue *q, int value, int priority)
{
    if(q->cur_size == q->max_size) return;
    q->queue_array[q->cur_size].value = value;
    q->queue_array[q->cur_size].priority = priority;

    int index = q->cur_size;
    while(index > 0 and q->queue_array[Parent(index)].priority > q->queue_array[index].priority)
    {
        swap_data(q->queue_array[Parent(index)], q->queue_array[index]);
        index = Parent(index);
    }

    q->cur_size++;
}

Data heap_extract_min(PriorityQueue *q)
{
    if(q->cur_size == 0) // error, cannot remove from empty queue
    {
        Data error_data = {.value = INT_MAX, .priority=INT_MAX};
        return error_data;
    }

    Data min = q->queue_array[0];
    q->cur_size--;
    q->queue_array[0] = q->queue_array[q->cur_size];
    heapify(q, 0);

    return min;
}

void heapify(PriorityQueue *q, int index)
{
    int left = Left(index);
    int right = Right(index);
    int min = index;

    if(left < q->cur_size and q->queue_array[left].priority < q->queue_array[index].priority) min = left;
    if(right < q->cur_size and q->queue_array[right].priority < q->queue_array[min].priority) min = right;

    if(min != index)
    {
        swap_data(q->queue_array[index], q->queue_array[min]);
        heapify(q, min);
    }
}
