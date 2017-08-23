//
// Created by michal on 22/08/17.
//

#ifndef OTHER_PRIORITYQUEUE_H
#define OTHER_PRIORITYQUEUE_H

const int M = 100;

struct Data
{
    int value;
    int priority;
};

struct PriorityQueue
{
    int max_size;
    int cur_size;
    Data *queue_array;
};

int Left(int index);
int Right(int index);
int Parent(int index);
void swap(int &a, int &b);
void swap_elements(Data &d1, Data &d2);

PriorityQueue *create_queue(int n);
void insert_element(PriorityQueue *q, int value, int priority);
Data heap_extract_min(PriorityQueue *q);
void heapify(PriorityQueue *q, int index);
void print_queue(PriorityQueue *q); // function is called "print", but it is more like simulating tasks (queue is destroyed in this function)

#endif //OTHER_PRIORITYQUEUE_H
