//
// Created by michal on 20/08/17.
//

#include <iostream>
#include <climits>
#include <stdlib.h>
#include <time.h>

#include "SkipList.h"

SkipList *create_skiplist(int max_level, int n)
{
    SkipList *sl = new SkipList;
    sl->max_level = max_level;

    sl->first = new node;
    sl->first->value = INT_MIN;
    sl->first->next = new node *[max_level];

    sl->last = new node;
    sl->last->value = INT_MAX;
    sl->last->next =new node *[max_level];

    for(int i=0; i<max_level; i++) sl->first->next[i] = sl->last;
    for(int i=0; i<max_level; i++) sl->last->next[i] = NULL;

    for(int i=0; i<n; i++)
    {
        int value, level = rand_level(sl->max_level);
        std::cin >> value;
        add_node(sl, level, value);
    }

    return sl;
}

void add_node(SkipList *sl, int level, int value)
{
    node *new_node = new node;
    new_node->value = value;
    new_node->next = new node *[level];

    node *prev[level];
    node *p = sl->first;
    for(int i=level-1; i>=0; i--)
    {
        while(p->next[i]->value < value) p = p->next[i];
        prev[i] = p;
    }
    if(p->next[0]->value == value) return; // element already exists

    for(int i=level-1; i>=0; i--)
    {
        new_node->next[i] = prev[i]->next[i];
        prev[i]->next[i] = new_node;
    }
}

node *remove_node(SkipList *&sl, node *delete_node)
{
    node *prev[sl->max_level];
    node *p = sl->first;
    for(int i=sl->max_level-1; i>=0; i--)
    {
        while(p->next[i]->value < delete_node->value) p = p->next[i];
        prev[i] = p;
    }
    if(p->next[0]->value != delete_node->value) return NULL; // element doesn't exists

    for(int i=sl->max_level-1; i>=0; i--)
    {
        if(prev[i]->next[i]->value == delete_node->value)
        {
            prev[i]->next[i] = prev[i]->next[i]->next[i];
            delete_node->next[i] = NULL;

        }
    }
    return delete_node;
}

node *find_node(SkipList *sl, int value)
{
    node *v = sl->first;
    for(int i=sl->max_level-1; i>=0; i--)
        while(v->next[i]->value < value and v->next[i] != NULL)
            v = v->next[i];
    v = v->next[0];
    return v->value == value ? v : NULL;
}

void print_skiplist(SkipList *sl)
{
    for(int i=sl->max_level-1; i>=0; i--)
    {
        node *p = sl->first->next[i];
        std::cout << "Level " << i << ": ";
        while(p->value != INT_MAX)
        {
            std::cout << p->value << " ";
            p = p->next[i];
        }
        std::cout << std::endl;
    }
}

int rand_level(int max_level)
{
    srand((unsigned int)time(NULL));
    int level = 1;
    while(level < max_level and ((double)rand()/RAND_MAX < 0.5)) level++;
    return level;
}
