//
// Created by michal on 09/09/17.
//

#include "utils.h"

void create_list(Node *&first, int n)
{
    first = new Node();
    first->next = NULL;
    std::cin >> first->value;

    int count = n - 1;
    while(count > 0)
    {
        Node *new_node = new Node();
        new_node->next = NULL;
        std::cin >> new_node->value;
        add_node(first, new_node);
        count--;
    }
}

void print_list(Node *first)
{
    while(first)
    {
        std::cout<<first->value<<" ";
        first = first->next;
    }
    std::cout<<"\n";
}

void add_node(Node *&first, Node *new_node)
{
    if(first == NULL)
    {
        first = new_node;
        return;
    }
    else
    {
        Node *guard = first;
        while(first->next) first = first->next;
        first->next = new_node;
        first = guard;
    }
}

int get_interval(int n, double value)
{
    return (int)((value / 4)*n);
}

void add_node_at_beginning(Node *&first, Node *new_node)
{
    new_node->next = first;
    first = new_node;
}

void split_list(Node *list, Node *&list1, Node *&list2)
{
    Node *tmp1 = list;
    Node *tmp2 = list;

    while(tmp1)
    {
        tmp1 = tmp1->next;
        if(tmp1)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
    }
    list2 = tmp2;

    list1 = list;
    while(list->next != list2) list = list->next;
    list->next = NULL;
}

Node *list_merge(Node *&list1, Node *&list2)
{
    Node *result = NULL;

    if(list1 == NULL) return list2;
    else if(list2 == NULL) return list1;

    if(list1->value < list2->value)
    {
        result = list1;
        result->next = list_merge(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = list_merge(list1, list2->next);
    }

    return result;
}

void merge_sort_list(Node *&list)
{
    if(list == NULL or list->next == NULL) return;

    Node *list1, *list2;
    split_list(list, list1, list2);
    merge_sort_list(list1);
    merge_sort_list(list2);
    list = list_merge(list1, list2);
}

Node *merge_buckets(Node **bucket, int n)
{
    Node *result = new Node, *guard;
    result->next = NULL;
    guard = result;

    for(int i=0; i<n; i++)
    {
        if(bucket[i])
        {
            result->next = bucket[i];
            while(result->next) result = result->next;
        }
    }

    return guard->next;
}

/****************************************************************************************/

Job *create_jobs(int n)
{
    Job *jobs = new Job[n];
    for(int i=0; i<n; i++) std::cin >> jobs[i].start >> jobs[i].end;
    return jobs;
}

int find_min_impatientBob(Job *jobs, int **tab, int i, int j)
{
    int min = INT_MAX;
    int min_index = INT_MAX;

    for(int x=i-1; x>=1; x--)
    {
        if (jobs[i - 1].start >= jobs[x - 1].end and tab[x][j - 1] != INT_MAX)
        {
            if (min > jobs[i - 1].start - jobs[x - 1].end)
            {
                min = jobs[i - 1].start - jobs[x - 1].end;
                min_index = x;
                std::cout << "minimum i=" << i << ", j=" << j << ":" << min << ", " << jobs[i - 1].start << "-" << jobs[x - 1].end << ", min_index=" << x << "\n";
            }
        }
    }

    return (min == INT_MAX ? INT_MAX : (tab[min_index][j-1] + min));
}

/****************************************************************************************/

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int *tab, int l, int r)
{
    int x = tab[r];
    int i, j=l;
    for(i=l; i<r; i++)
    {
        if(tab[i] <= x)
        {
            swap(tab[i], tab[j]);
            j++;
        }
    }
    swap(tab[j], tab[r]);
    return j;
}

int find_element_sorted_position(int *tab, int n, int k)
{
    if(n == 1) return tab[0];
    int q = partition(tab, 0, n-1);
    if(q == k) return tab[q];
    else if(k < q) return find_element_sorted_position(tab, q, k);
    else return find_element_sorted_position(tab + q + 1, n - (q + 1), k - (q + 1));
}

/****************************************************************************************/

BSTnode *create_bst(int n)
{
    BSTnode *root = new BSTnode();
    root->left = root->right = root->parent = NULL;
    std::cin >> root->value;

    BSTnode *tmp;
    int count = n-1;
    while(count > 0)
    {
        tmp = new BSTnode();
        tmp->left = tmp->right = tmp->parent = NULL;
        std::cin >> tmp->value;
        add_node(root, tmp);
        count--;
    }

    return root;
}

void print_bst(BSTnode *root)
{
    if(root)
    {
        print_bst(root->left);
        std::cout << root->value << " ";
        print_bst(root->right);
    }
}

void add_node(BSTnode *&root, BSTnode *&new_node)
{
    BSTnode *x=root, *y=NULL;

    while(x)
    {
        y = x;
        if(new_node->value >= x->value) x = x->right;
        else x = x->left;
        new_node->parent = y;
    }

    if(y == NULL) root = new_node; // if tree is empty
    else
    {
        if(new_node->value >= y->value) y->right = new_node;
        else y->left = new_node;
    }
}

/****************************************************************************************/

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

Subset *MakeSet(int x)
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

void display_matrix(int **G, int v)
{
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++) std::cout << G[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/****************************************************************************************/

int max(int a, int b)
{
    return a > b ? a : b;
}

int longest_increasing_subsequence(int *tab, int n)
{
    int *t = new int [n];
    for(int i=0; i<n; i++) t[i] = 1;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(tab[i] > tab[j]) t[i] = max(t[i], t[j] + 1);
        }
    }

    int max = INT_MIN;
    for(int i=0; i < n; i++)
    {
        std::cout << t[i] << " ";
        if(t[i] > max) max = t[i];
    }
    std::cout << std::endl;

    return max;
}