#include <iostream>
#include <climits>

#include "utils.h"

//egzaminy
Node *sortList(Node *first);
int impatientBob(Job *jobs, int n, int k);
int wayHome(int *P, int *R, int n);
Node *mergeLists(Node *l1, Node *l2);
int countInterval(BSTnode *T, int a, int b);
bool checkHT();
void quick_sort(int *tab, int l, int r);
Node *reverse(Node *l);
int MST(int **G, int n);
int maximum_sum_increasing_subsequence(int *tab, int n);
int find_element_sorted_position_list(Node *list);
//kolokwia
int SumBetween(int T[], int from, int to, int n);

int main()
{
    int n;
    std::cin >> n;
    Node *list;
    create_list(list, n);

    return 0;
}

/*****************************************************************************************************/

Node *sortList(Node *first)
{
    int n = 0;
    Node *guard = first;
    while(first)
    {
        first = first->next;
        n++;
    }
    first = guard;
    if(n == 0) return NULL;

    double interval_length = (double) 4 / n;
    Node **bucket = new Node *[n];
    for(int i=0; i<n; i++)
    {
        bucket[i] = new Node;
        bucket[i] = NULL;
    }

    Node *tmp = NULL;
    while(first)
    {
        tmp = first;
        first = first->next;
        tmp->next = NULL;
        add_node_at_beginning(bucket[get_interval(interval_length, tmp->value)], tmp);
    }

    for(int i=0; i<n; i++) merge_sort_list(bucket[i]);

    first = merge_buckets(bucket, n);

    return first;
}

int wayHome(int *P, int *R, int n)
{
    int tab[n];
    tab[0] = 0;
    for(int i=1; i<n; i++) tab[i] = INT_MAX;

    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--)
            if(R[j] + j >= i and P[j] + tab[j] < tab[i]) {
                tab[i] = tab[j] + P[j];
            }
    }
    // for(int i=0; i<n; i++) std::cout << i << " - " << P[i] << " " << R[i] << " " << tab[i] << std::endl;
    return (tab[n-1] == INT_MAX ? -1 : tab[n-1]);
}

int impatientBob(Job *jobs, int n, int k) // assuming that jobs are sorted by 'end' time
{
    if(n <= k) return -1;

    int **tab = new int*[n+1];
    for(int i=0; i<n+1; i++) tab[i] = new int[k];
    for(int i=1; i<n+1; i++) tab[i][0] = 0;
    for(int i=0; i<k; i++) tab[0][i] = INT_MAX;

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<k; j++) // we start at j=1, because j=0 is already set
        {
            if(i > j) tab[i][j] = find_min_impatientBob(jobs, tab, i, j); // find minimum in previous column if its end time is >= current start time
            else tab[i][j] = INT_MAX;
        }
    }

    for(int i=0; i<n+1; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int min = INT_MAX;
    for(int i=k; i<n+1; i++) if(tab[i][k-1] < min) min = tab[i][k-1];
    return (min == INT_MAX ? -1 : min);
}

Node *mergeLists(Node *l1, Node *l2)
{
    Node *l = new Node;
    Node *guard = l;

    Node *tmp;
    while(l1 != NULL and l2 != NULL)
    {
        if(l1->value > l2->value)
        {
            tmp = l2;
            l2 = l2->next;
            tmp->next = NULL;
            l->next = tmp;
            l = l->next;
        }
        else
        {
            tmp = l1;
            l1 = l1->next;
            tmp->next = NULL;
            l->next = tmp;
            l = l->next;
        }
    }

    while(l1)
    {
        tmp = l1;
        l1 = l1->next;
        tmp->next = NULL;
        l->next = tmp;
        l = l->next;
    }

    while(l2)
    {
        tmp = l2;
        l2 = l2->next;
        tmp->next = NULL;
        l->next = tmp;
        l = l->next;
    }

    return guard->next;
}

int countInterval(BSTnode *T, int a, int b)
{
    int result = 0;
    if(T->left) result += countInterval(T->left, a, b);
    if(T->right) result += countInterval(T->right, a, b);

    if(T->value >= a and T->value <= b) result += T->value;
    return result;
}



void quick_sort(int *tab, int l, int r)
{
    if(r>l)
    {
        int x = partition(tab, l, r);
        quick_sort(tab, l, x - 1);
        quick_sort(tab, x + 1, r);
    }
}

Node *reverse(Node *l)
{
    Node *prev = l, *tmp;
    l = l->next;
    prev->next = NULL;
    while(l)
    {
        tmp = l;
        l = l->next;
        tmp->next = prev;
        prev = tmp;
    }

    return prev;
}

int MST(int **G, int n)
{
    Subset **vertices = new Subset *[n];
    for(int i=0; i<n; i++) vertices[i] = MakeSet(i);

    int edges_amount = 0;

    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            if(G[i][j] != 0)
                edges_amount++;

    Edge *edges = new Edge[edges_amount];
    int edges_count = 0;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
            if(G[i][j] != 0)
            {
                edges[edges_count].v1 = i;
                edges[edges_count].v2 = j;
                edges[edges_count].weight = G[i][j];
                edges_count++;
            }
    sort_edges(edges, edges_amount);

    int sum = 0;
    for(int i=0; i < edges_amount; i++)
    {
        if(Find(vertices[edges[i].v1]) != Find(vertices[edges[i].v2]))
        {
            Union(vertices[edges[i].v1], vertices[edges[i].v2]);
            sum += edges[i].weight;
        }
    }

    return sum;
}

int maximum_sum_increasing_subsequence(int *tab, int n)
{
    int *sum = new int [n], *order = new int [n];
    for(int i=0; i<n; i++)
    {
        sum[i] = tab[i];
        order[i] = i;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(tab[i] > tab[j] and sum[i] < sum[j] + tab[i])
            {
                sum[i] = sum[j] + tab[i];
                order[i] = j;
            }
        }
    }

    int max = INT_MIN;
    for(int i=0; i < n; i++)
    {
        std::cout << sum[i] << " ";
        if(sum[i] > max) max = sum[i];
    }
    std::cout << std::endl;

    for(int i=0; i < n; i++) std::cout << order[i] << " ";
    std::cout << std::endl;

    return max;
}


int find_element_sorted_position_list(Node *list)
{
    if
}

/*****************************************************************************************************/

int SumBetween(int T[], int from, int to, int n)
{
    int left = find_element_sorted_position(T, n, from);
    int right = find_element_sorted_position(T, n, to);

    int sum = 0;
    for(int i=0; i <= right; i++) if(T[i] >= left) sum += T[i];

    return sum;
}
