//
// Created by michal on 20/08/17.
//

#ifndef OTHER_BST_H
#define OTHER_BST_H

struct BSTnode
{
    int value;
    BSTnode *left, *right, *parent;
};

BSTnode *create_bst(int n);
void print_bst(BSTnode *root);

void add_node(BSTnode *&root, BSTnode *&new_node);
BSTnode *remove_node(BSTnode *&root, BSTnode *delete_node);

BSTnode *find_min(BSTnode *root);
BSTnode *find_max(BSTnode *root);
BSTnode *find_node(BSTnode *root, int value);
BSTnode *find_predecessor(BSTnode *node);
BSTnode *find_successor(BSTnode *node);

#endif //OTHER_BST_H
