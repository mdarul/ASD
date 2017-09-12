//
// Created by michal on 21/08/17.
//

#include <iostream>
#include "Hashtable.h"

HashTable *create_hashtable(int n)
{
    HashTable *ht = new HashTable;
    ht->free_indexes = N;
    ht->complicated_indexes = 0;
    ht->table = new HashElement[N];

    std::string data;
    for(int i=0; i<n; i++)
    {
        std::cin >> data;
        insert_to_hashtable(ht, data);
    }

    return ht;
}

bool insert_to_hashtable(HashTable *ht, std::string data)
{
    HashTable *p = ht;
    if(p->free_indexes == 0 and p->complicated_indexes == 0) return false;

    int index = hash(data);
    while(1)
    {
        if(p->table[index].state==FREE)
        {
            p->free_indexes--;
            p->table[index].state = BOOKED;
            p->table[index].data = data;
            return true;
        }
        else if((p->table[index].state==COMPLICATED and p->free_indexes == 0))  // insert to "complicated" ones only when there are no free left
        {
            p->complicated_indexes--;
            p->table[index].state = BOOKED;
            p->table[index].data = data;
            return true;
        }
        else index = (index+1) % N;
    }
}

bool remove_from_hashtable(HashTable *ht, std::string data)
{
    int index = find_element(ht, data);
    std::cout << "found index: " << index << std::endl;
    if(index == -1) return false;

    ht->complicated_indexes++;
    ht->table[index].data = "";
    ht->table[index].state = COMPLICATED;
    return true;
}

int find_element(HashTable *ht, std::string data)
{
    HashTable *p = ht;
    int index = hash(data);
    int guard = index;

    do
    {
        if(p->table[index].state==BOOKED and p->table[index].data == data) return index;
        else index = (index+1) % N;
    }
    while(index != guard);

    return -1;
}

void print_hashtable(HashTable *ht)
{
    HashElement p;
    for(int i=0; i<N; i++)
    {

        p = ht->table[i];
        std::cout << "index: " << i << ", state: ";
        if(p.state == FREE) std::cout << "FREE" << std::endl;
        else if(p.state == COMPLICATED) std::cout << "COMPLICATED" << std::endl;
        else if(p.state == BOOKED) std::cout << "BOOKED, data: " << p.data << std::endl;
    }
}

int hash(std::string s)
{
    int result = 0;
    for(int i=0; s[i]!='\0'; i++) result +=(int)s[i];
    return result % N;
}

