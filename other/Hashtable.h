//
// Created by michal on 21/08/17.
//

#ifndef OTHER_HASHTABLE_H
#define OTHER_HASHTABLE_H

#include <string>
const int N = 5;

enum element_state
{
    FREE,
    BOOKED,
    COMPLICATED
};

struct HashElement
{
    element_state state = FREE;
    std::string data = "";
};

struct HashTable
{
    int free_indexes;
    int complicated_indexes;
    HashElement *table;
};

HashTable *create_hashtable(int n);
bool insert_to_hashtable(HashTable *ht, std::string data);
bool remove_from_hashtable(HashTable *ht, std::string data);
int find_element(HashTable *ht, std::string data);

int hash(std::string s);
void print_hashtable(HashTable *table);

#endif //OTHER_HASHTABLE_H
