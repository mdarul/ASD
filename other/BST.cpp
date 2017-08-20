//
// Created by michal on 20/08/17.
//
#include <iostream>
#include "BST.h"


void create_bst(BSTnode *&root, int n)
{
    root = new BSTnode();
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

BSTnode *remove_node(BSTnode *&root, BSTnode *node)
{
    BSTnode *x, *y;
    if(node->left == NULL or node->right == NULL) y = node;
    else y = find_successor(node);

    if(y->left != NULL) x = y->left;
    else x = y->right;

    if(x != NULL) x->parent = y->parent;

    if(y->parent == NULL) root = x;
    else if(y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;

    if(y != node) node->value = y->value;
    return y;
}

BSTnode *find_min(BSTnode *root)
{
    while(root->left) root = root->left;
    return root;
}

BSTnode *find_max(BSTnode *root)
{
    while(root->right) root = root->right;
    return root;
}

BSTnode *find_node(BSTnode *root, int value)
{
    while(root)
    {
        if(root->value == value) return root;
        root = (root->value >= value ? root->left : root->right);
    }
    return NULL;
}

BSTnode *find_predecessor(BSTnode *node)
{
    if(node->left) return find_max(node->left);
    else
    {
        BSTnode *x = node->parent;
        while(x and x->left==node)
        {
            node = x;
            x = node->parent;
        }
        return x;
    }
}

BSTnode *find_successor(BSTnode *node)
{
    if(node->left) return find_min(node->right);
    else
    {
        BSTnode *x = node->parent;
        while(x and x->right==node)
        {
            node = x;
            x = node->parent;
        }
        return x;
    }
}