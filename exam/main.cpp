#include <iostream>
#include <climits>

#include "2017utils.h"


Node *sortList(Node *first);
int impatientBob(Job *jobs, int n, int k);
int wayHome(int *P, int *R, int n);

int main()
{
    int n, k;
    std::cin >> n >> k;
    Job *jobs = create_jobs(n);

    std::cout << impatientBob(jobs, n, k);

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