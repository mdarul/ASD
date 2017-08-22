//
// Created by michal on 22/08/17.
//

#include <iostream>
#include "FindUnion.h"

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