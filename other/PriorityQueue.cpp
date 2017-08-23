//
// Created by michal on 22/08/17.
//

#include <iostream>
#include <climits>
#include "PriorityQueue.h"

int Left(int index)
{
    return index*2 + 1;
}

int Right(int index)
{
    return index*2 + 2;
}

int Parent(int index)
{
    return (index-1) / 2;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_elements(Data &d1, Data &d2)
{
    Data tmp_data = d1;
    d1 = d2;
    d2 = tmp_data;
}

PriorityQueue *create_queue(int n)
{
    PriorityQueue *q = new PriorityQueue;
    q->max_size = M;
    q->cur_size = 0;
    q->queue_array = new Data[q->max_size];

    int value, priority;
    for(int i=0; i<n; i++)
    {
        std::cin >> value >> priority;
        insert_element(q, value, priority);
    }

    return q;
}

void insert_element(PriorityQueue *q, int value, int priority)
{
    if(q->cur_size == q->max_size) return;
    q->queue_array[q->cur_size].value = value;
    q->queue_array[q->cur_size].priority = priority;

    int index = q->cur_size;
    while(index > 0 and q->queue_array[Parent(index)].priority > q->queue_array[index].priority)
    {
        swap_elements(q->queue_array[Parent(index)], q->queue_array[index]);
        index = Parent(index);
    }

    q->cur_size++;
}

Data heap_extract_min(PriorityQueue *q)
{
    if(q->cur_size == 0) // error, cannot remove from empty queue
    {
        Data error_data = {.value = INT_MAX, .priority=INT_MAX};
        return error_data;
    }

    Data min = q->queue_array[0];
    q->cur_size--;
    q->queue_array[0] = q->queue_array[q->cur_size];
    heapify(q, 0);

    return min;
}

void heapify(PriorityQueue *q, int index)
{
    int left = Left(index);
    int right = Right(index);
    int min = index;

    if(left < q->cur_size and q->queue_array[left].priority < q->queue_array[index].priority) min = left;
    if(right < q->cur_size and q->queue_array[right].priority < q->queue_array[min].priority) min = right;

    if(min != index)
    {
        swap_elements(q->queue_array[index], q->queue_array[min]);
        heapify(q, min);
    }
}

void print_queue(PriorityQueue *q)
{
    Data data;
    while((data=heap_extract_min(q)).priority != INT_MAX and data.value != INT_MAX) // while not empty
    {
        std::cout << "Priority: " << data.priority << ", value: " << data.value << std::endl;
    }
}