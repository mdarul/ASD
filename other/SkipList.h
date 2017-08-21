//
// Created by michal on 20/08/17.
//

#ifndef OTHER_SKIPLIST_H
#define OTHER_SKIPLIST_H

struct node
{
    int value;
    node **next;
};

struct SkipList
{
    node *first;
    node *last;
    int max_level;
};

SkipList *create_skiplist(int max_level, int n);
void add_node(SkipList *sl, int level, int value);
node *remove_node(SkipList *&sl, node *delete_node);
node *find_node(SkipList *sl, int value);
void print_skiplist(SkipList *sl);
int rand_level(int max_level);

#endif //OTHER_SKIPLIST_H
