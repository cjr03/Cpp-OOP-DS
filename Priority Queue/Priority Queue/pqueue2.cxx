
// FILE: pqueue2.cxx
// IMPLEMENTS: PriorityQueue (See pqueue2.h for documentation.)
// IMPLEMENTED BY: (name and email address)
//
// NOTE: You will need -lm at the end of your compile line to pick up
// the math library!

// INVARIANT for the PriorityQueue Class:
//   1. The member variable many_items is the number of items in the
//      PriorityQueue.
//   2. The items themselves are stored in the member variable heap,
//      which is a partially filled array organized to follow the usual
//      heap storage rules from Chapter 11 of the class notes.
// NOTE: Private helper functions are implemented at the bottom of this
// file along with their precondition/postcondition contracts.
 
#include <cassert>    // Provides assert function
#include <iomanip>    // Provides setw
#include <iostream>   // Provides cin, cout
#include <cmath>      // Provides log2
#include "pqueue2.h"
using namespace std;

PriorityQueue::PriorityQueue( ) {
    many_items = 0;
    return;
}

void PriorityQueue::insert(const Item& entry, unsigned int priority) {
    assert(many_items < CAPACITY);
    size_t nindex = many_items;
    heap[nindex].data = entry;
    heap[nindex].priority = priority;
    ++many_items;
    while(nindex > 0 and parent_priority(nindex) < priority) {
        swap_with_parent(nindex);
        nindex = parent_index(nindex);
    }
    return;
}

PriorityQueue::Item PriorityQueue::get_front( ) {
    assert(is_empty());
    Item r = heap[0].data;
    heap[0] = heap [--many_items];
    size_t t = 0;
    while(!is_leaf(t)){
        size_t bc = big_child_index(t);
        if(!(heap[t].priority < heap[bc].priority)) break;
        swap_with_parent(bc);
        t = bc;
    }
    return r;
}

bool PriorityQueue::is_leaf(size_t i) const {
    if(i < many_items) return ((2 * i) + 1 > many_items - 1);
    return false;
}

size_t PriorityQueue::parent_index(size_t i) const {
    if ((i > 0) and (i < many_items)) return (i - 1) / 2;
    return size_t (NULL);
}

unsigned int PriorityQueue::parent_priority(size_t i) const{
    if ((i > 0) and (i < many_items)) return heap[parent_index(i)].priority;
    return unsigned (NULL);
}

size_t PriorityQueue::big_child_index(size_t i) const {
    size_t j = 2 * i + 1, k = heap[j].priority, h = heap[j+1].priority;
    return (j + 1 >= many_items or k > h) ? j : j+1;
    return size_t (NULL);
}

unsigned int PriorityQueue::big_child_priority(size_t i) const {
    size_t j = 2 * i + 1;
    unsigned int k = heap[j].priority, h = heap[j+1].priority;
    return (j + 1 >= many_items or k > h) ? k : h;
    return unsigned (NULL);
}

void PriorityQueue::swap_with_parent(size_t i) {
    std::swap(heap[parent_index(i)], heap[i]);
    return;
}

void PriorityQueue::print_tree(const char message[ ], size_t i) const {
    const char NO_MESSAGE[ ] = "";
    size_t depth;
    if (message[0] != '\0') cout << message << endl;
    if (i >= many_items) cout << "NO NODES." << endl;
    else {
        depth = int(log(double(i+1))/log(2.0));
        cout << setw(static_cast<int>(depth)*4) << "";
        cout << heap[i].data;
        cout << " (priority " << heap[i].priority << ")" << endl;
        if (2*i + 1 < many_items) print_tree(NO_MESSAGE, 2*i + 1);
        if (2*i + 2 < many_items) print_tree(NO_MESSAGE, 2*i + 2);
    }
}

