//
// Created by michal on 22/08/17.
//

#ifndef OTHER_FINDUNION_H
#define OTHER_FINDUNION_H

struct Subset
{
    int x;
    int rank; // rank stands for a size of a tree
    Subset *parent;
};

Subset *make_set(int x);
Subset *Find(Subset *s); // we set pointer of every met subset in set at 'root' subset and return pointer to this root
void Union(Subset *s1, Subset *s2);

#endif //OTHER_FINDUNION_H
