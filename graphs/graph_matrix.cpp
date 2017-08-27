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

void topological_sort_matrix_visit(int **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            topological_sort_matrix_visit(G, v, i, color, stack);
    color[s] = BLACK;
    stack.push(s);
}

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

/**************************************************************/

void transpose_matrix(int **G, int v)
{
    for (int i = 0; i < v; i++)
        for (int j = i; j < v; j++)
            swap(G[i][j], G[j][i]);
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

void kosaraju_matrix_DFSvisit(int **G, int v, int s, int *color, std::stack<int> &stack)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] == 1 and color[i] == WHITE)
            kosaraju_matrix_DFSvisit(G, v, i, color, stack);
    color[s] = BLACK;
    stack.push(s);
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

/**************************************************************/

void check_connectivity_matrix_DFScount(int **G, int v, int s, int *color, int &count)
{
    color[s] = GREY;
    for(int i=0; i<v; i++)
        if(G[s][i] != 0 and color[i] == WHITE)
            check_connectivity_matrix_DFScount(G, v, i, color, count);
    color[s] = BLACK;
    count++;
}

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

bool check_eulerian_cycle_undirected_matrix_connectivity(int **G, int v, int isolated_amount)
{
    int count=0, *color = new int[v];
    for(int i=0; i<v; i++) color[i] = WHITE;
    check_connectivity_matrix_DFScount(G, v, 0, color, count);
    return count == (v - isolated_amount);
}

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

int get_first_non_zero(int **G, int v, int s)
{
    int result = -1;

    for(int i=0; i<v; i++)
    {
        if(G[s][i] == 1)
        {
            result = i;
            break;
        }
    }

    return result;
}

void print_eulerian_cycle_undirected_matrix(int **G, int v)
{
    if(!check_eulerian_cycle_undirected_matrix(G, v)) return;

    int next, current = 0; // assuming that vertex 0 is not isolated
    while((next = get_first_non_zero(G, v, current)) != -1)
    {
        std::cout << current << " ";
        G[current][next] = G[next][current] = 0;
        current = next;
    }
    std::cout << current << std::endl;
}

/**************************************************************/

void sort_edges(Edge *edges, int e)
{
    Edge tmp;
    bool end;
    for(int i=0; i<e; i++)
    {
        end = false;
        for(int j=0; j<e-1; j++)
        {
            if(edges[j].weight > edges[j+1].weight)
            {
                tmp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = tmp;
                end = true;
            }
        }
        if(!end) break;
    }
}

int kruskal_matrix(int **G, int v, int e)
{
    if(!check_connectivity_undirected_matrix(G, v)) return -1;

    Subset **vertices = new Subset*[v];
    for(int i=0; i<v; i++) vertices[i] = make_set(i);

    Edge *edges = new Edge[e];
    int count_edges = 0;
    for(int i=0; i<v; i++)
    {
        for(int j=i; j<v; j++)
        {
            if(G[i][j] != 0)
            {
                edges[count_edges].vertex1 = i;
                edges[count_edges].vertex2 = j;
                edges[count_edges].weight = G[i][j];
                count_edges++;
            }
        }
    }

    sort_edges(edges, e);

    int weight = 0;
    for(int i=0; i<e; i++)
    {
        if(Find(vertices[edges[i].vertex1]) != Find(vertices[edges[i].vertex2]))
        {
            Union(vertices[edges[i].vertex1], vertices[edges[i].vertex2]);
            weight += edges[i].weight;
        }
    }

    return weight;
}

int prim_matrix(int **G, int v)
{
    if(!check_connectivity_undirected_matrix(G, v)) return -1;

    PriorityQueue *Q = new PriorityQueue;
    Q->cur_size = 0;
    Q->max_size = v;
    Q->queue_array = new Data[v];

    int *key = new int[v], *parent = new int[v], *visited = new int[v];
    for(int i=0; i<v; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = 0;
    }
    // we set vertex no. 0 as starting point
    insert_element(Q, 0, 0);
    key[0] = 0;

    Data vertex;
    while(Q->cur_size != 0)
    {
        vertex = heap_extract_min(Q);
        for(int i=0; i<v; i++)
        {
            if(G[vertex.value][i] != 0 and G[vertex.value][i] < key[i]) // for every neighbour X if his edge cost from current position is lower than the previous one
            {
                parent[i] = vertex.value; // save current starting vertex as a parent, update key and insert the vertex into queue
                key[i] = G[vertex.value][i];
                insert_element(Q, i, key[i]);
            }
        }
    }

    int weight = 0;
    for(int i=1; i<v; i++) weight += key[i];

    return weight;
}

void dijkstra_matrix(int **G, int v, int s)
{
    if (!check_connectivity_undirected_matrix(G, v)) return;

    int *d = new int[v], *parent = new int[v];
    for (int i = 0; i < v; i++)
    {
        d[i] = INT_MAX;
        parent[i] = -1;
    }

    PriorityQueue *Q = new PriorityQueue;
    Q->cur_size = 0;
    Q->max_size = v;
    Q->queue_array = new Data[v];

    insert_element(Q, 0, 0);
    d[s] = 0;

    Data vertex;
    while (Q->cur_size != 0)
    {
        vertex = heap_extract_min(Q);
        for (int i = 0; i < v; i++)
        {
            if (G[vertex.value][i] != 0 and (d[vertex.value] + G[vertex.value][i]) < d[i])
            {
                parent[i] = vertex.value; // save current starting vertex as a parent, update distance and insert the vertex into queue
                d[i] = d[vertex.value] + G[vertex.value][i];
                insert_element(Q, i, d[i]);
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        std::cout << i <<" - weight: " << d[i] << ", path: ";

        int j=i;
        while(j != s)
        {
            std::cout << j << " ";
            j = parent[j];
        }

        std::cout << s << std::endl;
    }
}

void bellman_ford_matrix(int **G, int v, int s)
{
    if (!check_connectivity_undirected_matrix(G, v)) return;

    int *d = new int[v], *parent = new int[v];
    for(int i=0; i<v; i++)
    {
        d[i] = 1000000; // let's say that a million is maximum
        parent[i] = -1;
    }

    d[s] = 0;

    for(int k=0; k<(v-1); k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (G[i][j] != 0 and (d[j] > d[i] + G[i][j]))
                {
                    d[j] = d[i] + G[i][j];
                    parent[j] = i;
                }
            }
        }
    }

    // checking if there is any negative cycle
    for (int i=0; i < v; i++) {
        for (int j = 0; j < v; ++j) {
            if (G[i][j] != 0 and (d[j] > d[i] + G[i][j]))
            {
                std::cout << "Negative cycle found!" <<std::endl;
                return;
            }
        }
    }

    for(int i=0; i<v; i++)
    {
        std::cout << i <<" - weight: " << d[i] << ", path: ";

        int j=i;
        while(j != s)
        {
            std::cout << j << " ";
            j = parent[j];
        }

        std::cout << s << std::endl;
    }
}
